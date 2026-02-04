#include "mainwindow.h"
#include "databaseCommunicator.h"
#include "welcomePage.h"

#include <QApplication>
#include <QLayout>
#include <QTableView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow main;

    // DatabaseCommunicator db_communicator;
    // db_communicator.openConnection();

    WelcomePage *wpage = new WelcomePage;
    wpage->show();
    
    //main.show();
    return a.exec();
}
