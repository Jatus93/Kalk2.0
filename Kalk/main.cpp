#include <iostream>
#include <Model/model.h>
#include <Controller/controller.h>
#include <View/Console/consoleview.h>
#include <View/Gui/mainwindow.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model* mainModel = new Model();
    View* mainView;
    if((argv[1])&& strcmp(argv[1],"-c"))
        mainView = new ConsoleView();
    else
        mainView = new MainWindow();
    Controller* mainController=new Controller(mainModel,mainView);

    mainView->show();

    return a.exec();
}
