#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QObject>
#include <QApplication>
#include <QComboBox>
#include <QVector>
#include <QButtonGroup>
#include <QPushButton>
#include <QLayout>
#include <QLineEdit>
#include <QMessageBox>
#include "../view.h"

class MainWindow : public View
{
    Q_OBJECT

private:
    int numopertion;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    //void leftTypeIsSet(QString type);
    //void rightTypeIsSet(QString type);
    //void leftValuesAreSet(QVector<QString> values);
    //void rightValuesAreSet(QVector<QString> values);
    //void operationIsSet(QString type);
    //void reset();
    //void getResult();
    //void lastOperation();
    //Non serve ridefinire i segnali che vengono derivati da View

public slots:
    void setLeftTypes(const QVector<QString> types);
    void setRightTypes(const QVector<QString> types);
    void setAvailableOperations(const QVector<QString> operations);
    void setPermittedOperations(const QVector<QString> operations);
    void setResult(const QVector<QString> result);
    void ansIsSet(const QVector<QString> values);
    void setNumPad();

private slots:
    void updateInputLineL(const QString type);
    void updateInputLineR(const QString type);
    void updateResultLine(const QString type);
    void numPadButton();
    void delButton();
    void resetButton();
    void ansButton();
    void oldButton();
    void operationPadButton();
    void resultButton();

};

#endif // MAINWINDOW_H
