#include "yuv.h"
const double YUV::YUV_RGB[3][3]={{0.299,0.587,0.114},
                                 {-0.14713,-0.28886,0.436},
                                 {0.615,-0.51499,-0.10001}};

const double YUV::RGB_YUV[3][3]={{1.0,0.0,1.13983},
                                 {1.0,-0.39465,-0.58060},
                                 {1.0,2.03211,0.0}};
/**
 * @brief YUV::YUV Constructor for YUV color rappresentation from double precision numbers
 * @param _y
 * @param _u
 * @param _v
 */
YUV::YUV(double _y, double _u, double _v) : RGB(getRGB(_y, _u, _v)){
    y=_y;
    u=_u;
    v=_v;
}

/**
 * @brief YUV::YUV Constructor for YUV color rappresentation from Color pointer
 * @param from
 */
YUV::YUV(const Color* from) : RGB(from){
    RGB* tmpRGB = new RGB(from);
    QVector<double> toSet = RGB2YUV(tmpRGB->getComponents());
    if(toSet[1]>max_uv || toSet[2]>max_uv || toSet[1]<low_uv || toSet[2]<low_uv || toSet[0]>max_y ||toSet[0]<low_y)
        throw IllegalColorException("il colore non rientra nei parametri");
    y=toSet[0];
    u=toSet[1];
    v=toSet[2];
}

/**
 * @brief YUV::YUV copy constructor
 * @param from
 */
YUV::YUV(const YUV& from) : RGB(from){
    y=from.y;
    u=from.u;
    v=from.v;
}

/**
 * @brief YUV::getRappresentation
 * @return QString that contains the meaning of the values contained in getComponents()
 */
QString YUV::getRappresentation() const{
    return QString("YUV");
}

/**
 * @brief YUV::negate
 * @return Color pointer with a new color with the complementar values
 */
Color* YUV::negate() const{
    return new YUV(RGB::negate());
}

/**
 * @brief YUV::mix
 * @param a
 * @return Color pointer with a new Object color mixed
 */
Color* YUV::mix(const Color* a)const{
    return new YUV(RGB::mix(a));
}

/**
 * @brief YUV::getRGB
 * @param _y
 * @param _u
 * @param _v
 * @return Color pointer with a clone of *this in the RGB format
 */
Color* YUV::getRGB(double _y, double _u, double _v){
    QVector<double> rgb = YUV2RGB({_y,_u,_v});
    return new RGB(static_cast<int>(rgb[0]),static_cast<int>(rgb[1]),static_cast<int>(rgb[2]));
}

/**
 * @brief YUV::getCIE
 * @param y
 * @param u
 * @param v
 * @return Color pointer with a clone of *this in the CIExyz format
 */
Color* YUV::getCIE(double y, double u, double v){
    QVector<double> rgb = YUV2RGB({y,u,v});
    return RGB::getCIE(static_cast<int>(rgb[0]),static_cast<int>(rgb[1]),static_cast<int>(rgb[2]));
}

/**
 * @brief YUV::getComponent
 * @return QVector<double> with the y, u, v component of the color in YUV
 */
QVector<double> YUV::getComponents() const{
    QVector<double> to_return={y,u,v};
    return to_return;
}

/**
 * @brief YUV::getNumberOfComponets
 * @return int componets number
 */
int YUV::getNumberOfComponets() const{
    return YUV::componets;
}

/**
 * @brief YUV::setComponents set the components inside the object
 * @param componets
 */
void YUV::setComponents(QVector<double> componets){
    y=componets[0];
    u=componets[1];
    v=componets[2];
    RGB::setComponents(YUV2RGB(componets));
}

/**
 * @brief YUV::operator /
 * @param div
 * @return Color pointer with a new Object color
 */
Color* YUV::operator/(const int &div) const{
    return new YUV(RGB::operator/(div));
}

QVector<double> YUV::YUV2RGB(QVector<double> components){
    QVector<double> rgbrap={0,0,0};
    rgbrap[0]=(components[2]+0.877*components[0])/0.877;
    rgbrap[2]=(components[1]+0.493*components[0])/0.493;
    rgbrap[1]=(-rgbrap[0]*0.299-rgbrap[2]*0.144+components[0])/0.587;
    for(int i=0; i<3; i++)
    {
        if(rgbrap[i]>1)
            throw IllegalColorException("out of bounds color");
        else
            rgbrap[i]=rgbrap[i]*255;
    }
    return rgbrap;
}


QVector<double> YUV::RGB2YUV(QVector<double> components){
    QVector<double> yuvrap={0,0,0};
    yuvrap[0] = 0.299*(components[0]/255.0)+0.587*(components[1]/255.0)+0.114*(components[2]/255.0);
    yuvrap[1] = 0.493*((components[2]/255.0)-yuvrap[0]);
    yuvrap[2] = 0.877*((components[0]/255.0)-yuvrap[0]);
    return yuvrap;
}

QVector<QString> YUV::getLimits() const{
    return {"Y",QString::number(low_y),QString::number(max_y),
            "U",QString::number(low_uv),QString::number(max_uv),
            "V",QString::number(low_uv),QString::number(max_uv)};
}
