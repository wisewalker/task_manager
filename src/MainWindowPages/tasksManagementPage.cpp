#include "tasksManagementPage.h"

TasksManagementPage::TasksManagementPage(QWidget *parent, QSqlTableModel *model)
    : QWidget{parent}
    , m_Sourcemodel{model}
{
    this->setObjectName("tasksManagementPage");

    configureStructure();
    configureStyle();
    configureFunctionality();
}

void TasksManagementPage::setModel(QSqlTableModel *model)
{
    if (!m_Sourcemodel) {
        qDebug() << "[!]Model is already set!";
    } else {
        m_Sourcemodel = model;
        qDebug() << "[!]Model is successfully set!";
        configureFunctionality();
    }
}

void TasksManagementPage::configureStructure()
{
    QLabel *topSign = new QLabel;
    topSign->setObjectName("topSign");
    topSign->setText("Your tasks");
    topSign->setFrameStyle(QFrame::NoFrame);
    topSign->setContentsMargins(2, 2, 2, 2);
    topSign->setAlignment(Qt::AlignCenter);
    topSign->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    m_createTaskButton = new QPushButton;
    m_createTaskButton->setObjectName("createTaskButton");
    m_createTaskButton->setText("Create new task");
    m_createTaskButton->setContentsMargins(5, 1, 5, 1);
    m_createTaskButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    m_backHomeButton = new QPushButton;
    m_backHomeButton->setObjectName("backToMenuButton");
    m_backHomeButton->setText("Back to Menu");
    m_backHomeButton->setContentsMargins(5, 1, 5, 1);
    m_backHomeButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    m_assignedTasksView = new QTableView(this);
    m_assignedTasksView->setObjectName("assignedTasksView");
    m_assignedTasksView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    //Set left layout and fill it with according widgets
    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->setObjectName("bottomLayout");
    bottomLayout->setContentsMargins(5, 0, 5, 20);

    bottomLayout->addSpacing(10);
    bottomLayout->addWidget(m_backHomeButton);
    bottomLayout->addSpacing(30);
    bottomLayout->addStretch(2);
    bottomLayout->addWidget(m_createTaskButton, 1);
    bottomLayout->addSpacing(10);

    //Create, configure and fill layout
    m_mainLayout = new QVBoxLayout(this);
    this->setLayout(m_mainLayout);

    m_mainLayout->addStretch(1);
    m_mainLayout->addSpacing(10);

    m_mainLayout->addWidget(topSign);
    m_mainLayout->addSpacing(20);
    m_mainLayout->addWidget(m_assignedTasksView, 5);
    m_mainLayout->addSpacing(10);
    m_mainLayout->addLayout(bottomLayout, 1);
    m_mainLayout->addStretch(1);
}

void TasksManagementPage::configureStyle() {}

void TasksManagementPage::configureFunctionality()
{
    if (!m_Sourcemodel) {
        qDebug() << "[!]Missing model component!";
        return;
    }
    
    m_assignedTasksModel = new QSortFilterProxyModel(this);
    m_assignedTasksModel->setSourceModel(m_Sourcemodel);
    m_assignedTasksModel->sort(2, Qt::AscendingOrder);

    m_assignedTasksView->setModel(m_assignedTasksModel);

    m_assignedTasksView->setColumnHidden(0, true);
    m_assignedTasksView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    m_assignedTasksView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    m_assignedTasksView->verticalHeader()->hide();
    
    //Connect inner buttons signals for public use
    QObject::connect(m_createTaskButton,
                     &QPushButton::clicked,
                     this,
                     &TasksManagementPage::createTaskButtonClicked);

    QObject::connect(m_backHomeButton,
                     &QPushButton::clicked,
                     this,
                     &TasksManagementPage::backHomeButtonClicked);
}

void TasksManagementPage::onUpdateView()
{
    qDebug() << "[!]Tasks management page view is updated!";
    m_assignedTasksView->scrollToTop();
}
