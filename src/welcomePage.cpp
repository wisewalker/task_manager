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

    m_recentlyCreatedTasksView = new QTableView(this);
    m_recentlyCreatedTasksView->setObjectName("recentlyCreatedTasksView");
    m_recentlyCreatedTasksView->setColumnHidden(0, true);
    m_recentlyCreatedTasksView->setColumnHidden(3, true);
    
    QLabel *reachingDeadlineLabel = new QLabel;
    reachingDeadlineLabel->setObjectName("reachingDeadlineLabel");
    reachingDeadlineLabel->setText("Reaching assigned deadlines");
    reachingDeadlineLabel->setFrameStyle(QFrame::NoFrame);
    reachingDeadlineLabel->setContentsMargins(2, 2, 2, 2);
    reachingDeadlineLabel->setAlignment(Qt::AlignCenter);
    reachingDeadlineLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    
    m_reachingDeadlineTasksView = new QTableView(this);
    m_reachingDeadlineTasksView->setObjectName("reachingDeadlineTasksView");
    m_reachingDeadlineTasksView->setColumnHidden(0, true);
    m_reachingDeadlineTasksView->setColumnHidden(3, true);
    
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
    
}
