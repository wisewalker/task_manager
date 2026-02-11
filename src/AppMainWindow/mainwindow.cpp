#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setObjectName("mainWindow");
    
    this->setWindowTitle("Task Manager");
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
    m_tabs->setObjectName("tabs");
    
    m_welcomePage = new WelcomePage(m_tabs, m_db_communicator->model());
    m_tasksPage = new TasksManagementPage(m_tabs, m_db_communicator->model());
    m_newTaskForm = new TaskForm(this);
    
    m_tabs->addTab(m_welcomePage, "&Home");
    m_tabs->addTab(m_tasksPage, "&Tasks");

    this->setCentralWidget(m_tabs);
}

void MainWindow::configureInterfaceStyle()
{
    QFile styleFile(":/resources/ui_style.qss");
    if (!styleFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Style file CANNOT be read!";
        return;
    } else {
        QTextStream in(&styleFile);
        this->setStyleSheet(in.readAll());
    }
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

    QObject::connect(m_welcomePage,
                     &WelcomePage::tasksViewItemInteracted,
                     this,
                     [this](const QModelIndex &index) {
                         int id = index.siblingAtColumn(0).data().toInt();
                         this->onMoveToTasksPage(true);
                         m_tasksPage->onInteractViewItem(id);
                     });

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
                     &DatabaseCommunicator::databaseContentsChanged,
                     m_tasksPage,
                     &TasksManagementPage::onUpdateView);
    
    QObject::connect(m_db_communicator,
                     &DatabaseCommunicator::databaseContentsChanged,
                     m_welcomePage,
                     &WelcomePage::onUpdateViews);
    
    //Set connection for task observer form dialog window (used inside tasks management page)
    QObject::connect(m_tasksPage,
                     &TasksManagementPage::taskFieldsUpdated,
                     m_db_communicator,
                     &DatabaseCommunicator::onUpdateTask);
    
    QObject::connect(m_tasksPage,
                     &TasksManagementPage::taskDeletionRequested,
                     m_db_communicator,
                     &DatabaseCommunicator::onDeleteTask);
    
}

MainWindow::~MainWindow()
{
    
}
