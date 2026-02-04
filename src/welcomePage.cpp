#include "welcomePage.h"

WelcomePage::WelcomePage(QWidget *parent)
    : QWidget{parent}
{
    this->setObjectName("welcomePage");

    configureStructure();
    configureStyle();
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

    m_recentlyCreatedTasks = new QTableView(this);
    m_recentlyCreatedTasks->setObjectName("recentlyCreatedTasks");
    m_recentlyCreatedTasks->setColumnHidden(0, true);
    m_recentlyCreatedTasks->setColumnHidden(3, true);
    
    QLabel *reachingDeadlineLabel = new QLabel;
    reachingDeadlineLabel->setObjectName("reachingDeadlineLabel");
    reachingDeadlineLabel->setText("Reaching assigned deadlines");
    reachingDeadlineLabel->setFrameStyle(QFrame::NoFrame);
    reachingDeadlineLabel->setContentsMargins(2, 2, 2, 2);
    reachingDeadlineLabel->setAlignment(Qt::AlignCenter);
    reachingDeadlineLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    
    m_reachingDeadlineTasks = new QTableView(this);
    m_reachingDeadlineTasks->setObjectName("reachingDeadlineTasks");
    m_reachingDeadlineTasks->setColumnHidden(0, true);
    m_reachingDeadlineTasks->setColumnHidden(3, true);
    
    //Set left layout and fill it with according widgets
    QVBoxLayout *leftVLayout = new QVBoxLayout;
    leftVLayout->setObjectName("leftVLayout");
    leftVLayout->setContentsMargins(20, 0, 20, 0);
    
    leftVLayout->addSpacing(15);
    leftVLayout->addStretch(0);
    leftVLayout->addWidget(welcomeSign);
    leftVLayout->addStretch(2);
    leftVLayout->addSpacing(30);
    leftVLayout->addWidget(appSign);
    leftVLayout->addStretch(0);
    leftVLayout->addSpacing(30);
    leftVLayout->addWidget(m_createTaskButton);
    leftVLayout->addStretch(0);
    leftVLayout->addSpacing(5);
    leftVLayout->addStretch(0);
    leftVLayout->addWidget(m_listTasksButton);
    leftVLayout->addStretch(4);
    
    //Set right layout and fill it with according widgets
    QVBoxLayout *rightVLayout = new QVBoxLayout;
    rightVLayout->setObjectName("rightVLayout");
    rightVLayout->setContentsMargins(20, 0, 20, 0);
    
    rightVLayout->addSpacing(15);
    rightVLayout->addStretch(2);
    rightVLayout->addWidget(recentlyCreatedLabel);
    rightVLayout->addStretch(0);
    rightVLayout->addSpacing(2);
    rightVLayout->addWidget(m_recentlyCreatedTasks);
    rightVLayout->addStretch(1);
    rightVLayout->addSpacing(10);
    rightVLayout->addWidget(reachingDeadlineLabel);
    rightVLayout->addStretch(0);
    rightVLayout->addSpacing(2);
    rightVLayout->addWidget(m_reachingDeadlineTasks);
    rightVLayout->addSpacing(10);
    rightVLayout->addStretch(5);

    //Create, configure and fill layout
    m_mainLayout = new QHBoxLayout(this);
    this->setLayout(m_mainLayout);
    
    rightVLayout->addSpacing(1);
    m_mainLayout->addLayout(leftVLayout);
    rightVLayout->addSpacing(2);
    m_mainLayout->addLayout(rightVLayout);
    
}

void WelcomePage::configureStyle()
{
    
}

void WelcomePage::configureFunctionality()
{
    
}
