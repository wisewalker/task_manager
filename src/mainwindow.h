#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>

#include <QMainWindow>

#include <QPushButton>

#include "welcomePage.h"
#include "tasksManagementPage.h"
#include "databaseCommunicator.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
private:
    QTabWidget *m_tabs = nullptr;
    
    WelcomePage *m_welcomePage = nullptr;
    TasksManagementPage *m_tasksPage = nullptr;
    DatabaseCommunicator *m_db_communicator = nullptr;
    
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    void configureInterfaceStructure();
    void configureInterfaceStyle();
    void configureFunctionality();

private slots:
    void onCreateNewTask(bool);
    void onMoveToTasksPage(bool);
    void onMoveToWelcomePage(bool);
};
#endif // MAINWINDOW_H
