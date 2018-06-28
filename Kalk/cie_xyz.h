#ifndef CIE_XYZ_H
#define CIE_XYZ_H
#include "colour.h"

class CIExyz : public Colour{
public:
    CIExyz(double _x=0, double _y=0, double _z=0);
    ~CIExyz();
    //void show_rap();
    //void show_desc();
    //Colour* convert(Colour* from);
    //Colour* negate() const;
    //Colour* mix(Colour* c)const;
    //CIExyz* getCIE() const;

private:
  float x;
  float y;
  float z;
  static int upper_limit;
  static int lower_limit;
};

#endif // CIE_XYZ_H
