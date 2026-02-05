#include "mainwindow.h"
#include "databaseCommunicator.h"
#include "welcomePage.h"
#include "tasksManagementPage.h"


#include <QApplication>
#include <QLayout>
#include <QTableView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow mainWindow;

    // DatabaseCommunicator db_communicator;
    // db_communicator.openConnection();

    mainWindow.show();
    return a.exec();
}
