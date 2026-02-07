#include "mainwindow.h"
#include "databaseCommunicator.h"
#include "welcomePage.h"
#include "tasksManagementPage.h"

#include "limitedProxyModel.h"

#include "taskForm.h"

#include <QApplication>
#include <QLayout>
#include <QTableView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow mainWindow;

    mainWindow.show();
    return a.exec();
}
