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

    m_tabs->addTab(m_welcomePage, "Home");
    m_tabs->addTab(m_tasksPage, "Tasks");

    this->setCentralWidget(m_tabs);
}

void MainWindow::configureInterfaceStyle()
{
    
}

void MainWindow::onCreateNewTask(bool)
{
    qDebug() << "New task has been created!\n";
}

void MainWindow::onMoveToTasksPage(bool)
{
    qDebug() << "Moved to tasks management page!\n";
    m_tabs->setCurrentWidget(m_tasksPage);
}

void MainWindow::onMoveToWelcomePage(bool)
{
    qDebug() << "Moved to welcome page!\n";
    m_tabs->setCurrentWidget(m_welcomePage);
}

void MainWindow::configureFunctionality()
{
    //Set connections for welcome page
    QObject::connect(m_welcomePage->createTaskButton(),
                     &QPushButton::clicked,
                     this,
                     &MainWindow::onCreateNewTask);

    QObject::connect(m_welcomePage->listTasksButton(),
                     &QPushButton::clicked,
                     this,
                     &MainWindow::onMoveToTasksPage);

    //Set connections for tasks management page
    QObject::connect(m_tasksPage->createTaskButton(),
                     &QPushButton::clicked,
                     this,
                     &MainWindow::onCreateNewTask);

    QObject::connect(m_tasksPage->backHomeButton(),
                     &QPushButton::clicked,
                     this,
                     &MainWindow::onMoveToWelcomePage);
}

MainWindow::~MainWindow()
{
    
}
