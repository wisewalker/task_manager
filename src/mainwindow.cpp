#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setObjectName("mainWindow");
    //Cover 65% of desktop space
    this->resize(QDesktopWidget().availableGeometry(this).size() * 0.65);
    
    m_db_communicator = new DatabaseCommunicator(this);
    m_db_communicator->setObjectName("db_communicator");
    m_db_communicator->openConnection();

    configureInterfaceStructure();
    configureInterfaceStyle();
    configureFunctionality();
}

void MainWindow::configureInterfaceStructure()
{
    m_tabs = new QTabWidget(this);

    m_welcomePage = new WelcomePage(m_tabs, m_db_communicator->model());
    m_tasksPage = new TasksManagementPage(m_tabs, m_db_communicator->model());
    m_newTaskForm = new TaskForm(this);

    m_tabs->addTab(m_welcomePage, "Home");
    m_tabs->addTab(m_tasksPage, "Tasks");

    this->setCentralWidget(m_tabs);
}

void MainWindow::configureInterfaceStyle()
{
    
}

void MainWindow::onCreateNewTask(bool)
{
    qDebug() << "[!]New task form is opened!";
    m_newTaskForm->open();
}

void MainWindow::onMoveToTasksPage(bool)
{
    qDebug() << "[!]Moved to tasks management page!";
    m_tabs->setCurrentWidget(m_tasksPage);
}

void MainWindow::onMoveToWelcomePage(bool)
{
    qDebug() << "[!]Moved to welcome page!";
    m_tabs->setCurrentWidget(m_welcomePage);
}

void MainWindow::configureFunctionality()
{
    //Set connections for welcome page
    QObject::connect(m_welcomePage,
                     &WelcomePage::createTaskButtonClicked,
                     this,
                     &MainWindow::onCreateNewTask);
    
    QObject::connect(m_welcomePage,
                     &WelcomePage::listTasksButtonClicked,
                     this,
                     &MainWindow::onMoveToTasksPage);
    
    //Set connections for tasks management page
    QObject::connect(m_tasksPage,
                     &TasksManagementPage::createTaskButtonClicked,
                     this,
                     &MainWindow::onCreateNewTask);

    QObject::connect(m_tasksPage,
                     &TasksManagementPage::backHomeButtonClicked,
                     this,
                     &MainWindow::onMoveToWelcomePage);
    
    //Set connection for task form dialog window
    QObject::connect(m_newTaskForm,
                     &TaskForm::taskFormApplied,
                     m_db_communicator,
                     &DatabaseCommunicator::onCreateNewTask);

    //Set connection to react for DB change
    QObject::connect(m_db_communicator,
                     &DatabaseCommunicator::recordSavedInDatabase,
                     m_tasksPage,
                     &TasksManagementPage::onUpdateView);
    
    QObject::connect(m_db_communicator,
                     &DatabaseCommunicator::recordSavedInDatabase,
                     m_welcomePage,
                     &WelcomePage::onUpdateViews);
    
}

MainWindow::~MainWindow()
{
    
}
