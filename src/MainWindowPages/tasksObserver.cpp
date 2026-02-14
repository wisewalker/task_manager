#include "tasksObserver.h"

TasksObserver::TasksObserver(QWidget *parent)
    : QDialog{parent}
{
    this->setObjectName("tasksObserver");
    
    this->setWindowTitle("Task Observer");
    
    configureInterfaceStructure();
    configureFunctionality();
}

void TasksObserver::configureInterfaceStructure()
{
    m_mainLayout = new QVBoxLayout;
    this->setLayout(m_mainLayout);
    
    m_titleEdit = new QLineEdit(this);
    m_descriptionEdit = new QPlainTextEdit(this);
    m_setDeadlineButton = new QCheckBox("Set Deadline", this);
    m_setDeadlineButton->setObjectName("setDeadlineButton");
    m_deadlineEdit = new QDateTimeEdit(this);
    m_creationDateEdit = new QDateTimeEdit(this);
    m_creationDateEdit->setObjectName("creationDateEdit");
    m_creationDateEdit->setEnabled(false);
    m_updateButton = new QPushButton(QIcon(QPixmap("://resources/update_icon_2.png")), "Update", this);
    m_updateButton->setObjectName("updateButton");
    m_cancelButton = new QPushButton("Cancel", this);
    m_cancelButton->setObjectName("cancelButton");
    m_deleteButton = new QPushButton(QIcon(QPixmap("://resources/delete_icon_4.png")), "Delete", this);
    m_deleteButton->setObjectName("deleteButton");
    
    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(m_updateButton);
    buttonsLayout->addWidget(m_cancelButton);
    buttonsLayout->addWidget(m_deleteButton);
    
    m_mainLayout->addWidget(new QLabel("Title:", this));
    m_mainLayout->addWidget(m_titleEdit);
    m_mainLayout->addWidget(new QLabel("Description:", this));
    m_mainLayout->addWidget(m_descriptionEdit);
    m_mainLayout->addWidget(m_setDeadlineButton);
    m_mainLayout->addWidget(new QLabel("Deadline Date:", this));
    m_mainLayout->addWidget(m_deadlineEdit);
    m_mainLayout->addWidget(new QLabel("Creation Date:", this));
    m_mainLayout->addWidget(m_creationDateEdit);
    m_mainLayout->addLayout(buttonsLayout);
}

void TasksObserver::configureInterfaceStyle()
{
    
}

void TasksObserver::configureFunctionality()
{
    QObject::connect(m_setDeadlineButton, &QCheckBox::toggled, this, [this](bool checked) {
        m_deadlineEdit->setEnabled(checked ? true : false);
    });
    QObject::connect(m_updateButton, &QPushButton::clicked, this, &TasksObserver::onUpdateButton);
    QObject::connect(m_cancelButton, &QPushButton::clicked, this, &TasksObserver::onCancelButton);
    QObject::connect(m_deleteButton, &QPushButton::clicked, this, &TasksObserver::onDeleteButton);
}

void TasksObserver::setCurrentTaskID(int id)
{
    m_currentTaskID = id;
}

void TasksObserver::setEditorsData(const TaskData& sourceTaskData)
{
    m_titleEdit->setText(sourceTaskData.title());
    m_descriptionEdit->setPlainText(sourceTaskData.description());
    
    m_setDeadlineButton->setChecked(sourceTaskData.isDeadlineSet());
    m_deadlineEdit->setDateTime(QDateTime::fromString((sourceTaskData.deadlineDate())));
    
    m_creationDateEdit->setDateTime(QDateTime::fromString((sourceTaskData.creationDate())));
}

int TasksObserver::getCurrentTaskID()
{
    return m_currentTaskID;
}

QString TasksObserver::getEditorTitle() const
{
    return m_titleEdit->text();
}

QString TasksObserver::getEditorDescription() const
{
    return m_descriptionEdit->toPlainText();
}

QString TasksObserver::getEditorDeadlineDate() const
{
    return m_setDeadlineButton->isChecked() ? m_deadlineEdit->text() : "";
}

QString TasksObserver::getEditorCreationDate() const
{
    return m_creationDateEdit->text();
}

void TasksObserver::onUpdateButton(bool)
{
    QString deadlineString = m_setDeadlineButton->isChecked()
                                 ? m_deadlineEdit->dateTime().toString()
                                 : "";
    qDebug()
        << "[!]Updated task button was clicked! Edit fields are cleared!";
    emit updateTaskRequested();

    m_titleEdit->clear();
    m_descriptionEdit->clear();
    m_deadlineEdit->clear();
    m_creationDateEdit->clear();

    m_currentTaskID = -1;
}

void TasksObserver::onCancelButton(bool)
{
    this->close();
    m_titleEdit->clear();
    m_descriptionEdit->clear();
    m_deadlineEdit->clear();
    m_creationDateEdit->clear();
}

void TasksObserver::onDeleteButton(bool)
{
    qDebug()
        << "[!]Delete task button was clicked! Edit fields are cleared! Tasks observer is closed!";
    emit deleteTaskRequested();
    
    m_titleEdit->clear();
    m_descriptionEdit->clear();
    m_deadlineEdit->clear();
    m_creationDateEdit->clear();
}
