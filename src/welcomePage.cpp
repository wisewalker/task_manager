#include "welcomePage.h"

WelcomePage::WelcomePage(QWidget *parent, QSqlTableModel *model)
    : QWidget{parent}, m_sourceModel{model}
{
    this->setObjectName("welcomePage");

    configureStructure();
    configureStyle();
    configureFunctionality();
}

QPushButton *WelcomePage::createTaskButton() const
{
    return m_createTaskButton;
}

QPushButton *WelcomePage::listTasksButton() const
{
    return m_listTasksButton;
}

void WelcomePage::setModel(QSqlTableModel *model)
{
    if (!m_sourceModel) {
        qDebug() << "[!]Model is already set!";
    } else {
        m_sourceModel = model;
        qDebug() << "[!]Model is successfully set!";
    }
}

void WelcomePage::configureStructure()
{
    //Create and configure welcome_page UI elements
    QLabel *welcomeSign = new QLabel;
    welcomeSign->setObjectName("welcomeSign");
    welcomeSign->setText("Welcome back \nto your favorite");
    welcomeSign->setFrameStyle(QFrame::NoFrame);
    welcomeSign->setContentsMargins(2, 2, 2, 2);
    welcomeSign->setAlignment(Qt::AlignCenter);
    welcomeSign->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    QLabel *appSign = new QLabel;
    appSign->setObjectName("appSign");
    appSign->setText("Task manager");
    appSign->setFrameStyle(QFrame::NoFrame);
    appSign->setContentsMargins(2, 2, 2, 2);
    appSign->setAlignment(Qt::AlignCenter);
    appSign->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    m_createTaskButton = new QPushButton;
    m_createTaskButton->setObjectName("createTaskButton");
    m_createTaskButton->setText("Create new task");
    m_createTaskButton->setContentsMargins(5, 1, 5, 1);
    m_createTaskButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    m_listTasksButton = new QPushButton;
    m_listTasksButton->setObjectName("listTasksButton");
    m_listTasksButton->setText("List current tasks");
    m_listTasksButton->setContentsMargins(5, 1, 5, 1);
    m_listTasksButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    QLabel *recentlyCreatedLabel = new QLabel;
    recentlyCreatedLabel->setObjectName("recentlyCreatedLabel");
    recentlyCreatedLabel->setText("Recently created");
    recentlyCreatedLabel->setFrameStyle(QFrame::NoFrame);
    recentlyCreatedLabel->setContentsMargins(2, 2, 2, 2);
    recentlyCreatedLabel->setAlignment(Qt::AlignCenter);
    recentlyCreatedLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    m_recentlyCreatedTasksView = new QTableView(this);
    m_recentlyCreatedTasksView->setObjectName("recentlyCreatedTasksView");
    
    QLabel *reachingDeadlineLabel = new QLabel;
    reachingDeadlineLabel->setObjectName("reachingDeadlineLabel");
    reachingDeadlineLabel->setText("Reaching assigned deadlines");
    reachingDeadlineLabel->setFrameStyle(QFrame::NoFrame);
    reachingDeadlineLabel->setContentsMargins(2, 2, 2, 2);
    reachingDeadlineLabel->setAlignment(Qt::AlignCenter);
    reachingDeadlineLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    
    m_reachingDeadlineTasksView = new QTableView(this);
    m_reachingDeadlineTasksView->setObjectName("reachingDeadlineTasksView");
    
    //Set left layout and fill it with according widgets
    QVBoxLayout *leftVLayout = new QVBoxLayout;
    leftVLayout->setObjectName("leftVLayout");
    leftVLayout->setContentsMargins(20, 0, 20, 0);
    
    leftVLayout->addSpacing(15);
    leftVLayout->addWidget(welcomeSign, 1);
    leftVLayout->addSpacing(5);
    leftVLayout->addStretch(2);
    leftVLayout->addWidget(appSign, 2);
    leftVLayout->addWidget(m_createTaskButton, 1);
    leftVLayout->addSpacing(5);
    leftVLayout->addWidget(m_listTasksButton, 1);
    leftVLayout->addStretch(4);
    
    //Set right layout and fill it with according widgets
    QVBoxLayout *rightVLayout = new QVBoxLayout;
    rightVLayout->setObjectName("rightVLayout");
    rightVLayout->setContentsMargins(20, 0, 20, 0);
    
    rightVLayout->addSpacing(15);
    rightVLayout->addWidget(recentlyCreatedLabel);
    rightVLayout->addSpacing(2);
    rightVLayout->addWidget(m_recentlyCreatedTasksView, 1);
    rightVLayout->addSpacing(10);
    rightVLayout->addWidget(reachingDeadlineLabel);
    rightVLayout->addSpacing(2);
    rightVLayout->addWidget(m_reachingDeadlineTasksView, 1);
    rightVLayout->addSpacing(10);

    //Create, configure and fill layout
    m_mainLayout = new QHBoxLayout(this);
    this->setLayout(m_mainLayout);
    
    rightVLayout->addSpacing(1);
    m_mainLayout->addLayout(leftVLayout, 1);
    rightVLayout->addSpacing(2);
    m_mainLayout->addLayout(rightVLayout, 5);
    
}

void WelcomePage::configureStyle()
{
    
}

void WelcomePage::configureFunctionality()
{
    //Define medium models (which contents will be based on source model) 
    m_recentlyCreatedTasksModel = new LimitedProxyModel(this, topRecentlyCreated_Number);
    m_recentlyCreatedTasksModel->setObjectName("recentlyCreatedTasksMediumModel");
    m_reachingDeadlineTasksModel = new LimitedProxyModel(this, topReachingDeadline_Number);
    m_reachingDeadlineTasksModel->setObjectName("reachingDeadlineTasksMediumModel");
    
    //Forbid editing tasks from welcome page (read-only mode)
    m_recentlyCreatedTasksView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_reachingDeadlineTasksView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    
    if (!m_sourceModel) {
        qDebug() << "[!]Missing model component!";
    } else {
        //Configure view of recently created tasks
        m_recentlyCreatedTasksModel->setSourceModel(m_sourceModel);
        m_recentlyCreatedTasksModel->sort(2, Qt::DescendingOrder);
        
        m_recentlyCreatedTasksView->setModel(m_recentlyCreatedTasksModel);

        m_recentlyCreatedTasksView->setColumnHidden(0, true);
        m_recentlyCreatedTasksView->setColumnHidden(3, true);

        m_recentlyCreatedTasksView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        m_recentlyCreatedTasksView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        m_recentlyCreatedTasksView->verticalHeader()->hide();
        
        //Configure view of reaching deadline tasks
        m_reachingDeadlineTasksModel->setSourceModel(m_sourceModel);
        m_reachingDeadlineTasksModel->sort(3, Qt::AscendingOrder);
        
        m_reachingDeadlineTasksView->setModel(m_reachingDeadlineTasksModel);
        
        m_reachingDeadlineTasksView->setColumnHidden(0, true);
        m_reachingDeadlineTasksView->setColumnHidden(2, true);
        
        m_reachingDeadlineTasksView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        m_reachingDeadlineTasksView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        m_reachingDeadlineTasksView->verticalHeader()->hide();
    }    
}
