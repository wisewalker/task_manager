#include "mainwindow.h"
#include "databaseCommunicator.h"

#include <QApplication>
#include <QLayout>
#include <QTableView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow main;
    
    DatabaseCommunicator db_communicator;
    db_communicator.openConnection();

    QTableView* view = new QTableView;
    view->setModel(db_communicator.model());
    view->hideColumn(0);
    main.layout()->addWidget(view);
    
    main.show();
    return a.exec();
}
