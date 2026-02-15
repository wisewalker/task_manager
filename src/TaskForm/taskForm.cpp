#include "taskForm.h"

TaskForm::TaskForm(QWidget *parent)
    : QDialog{parent}
{
    this->setObjectName("taskForm");
    
    this->setWindowTitle("New Task Form");
    
    configureInterfaceStructure();
    configureFunctionality();
}

void TaskForm::configureInterfaceStructure()
{
    m_mainLayout = new QVBoxLayout(this);

    m_titleEdit = new QLineEdit(this);
    m_titleEdit->setObjectName("titleEdit");
    m_descriptionEdit = new QPlainTextEdit(this);
    m_descriptionEdit->setObjectName("descriptionEdit");
    m_deadlineSetButton = new QCheckBox("Set Deadline", this);
    m_deadlineSetButton->setObjectName("deadlineCheckBox");
    m_deadlineEdit = new QDateTimeEdit(this);
    m_deadlineEdit->setObjectName("deadlineEdit");

    m_applyButton = new QPushButton(QIcon(QPixmap("://resources/save_icon_3.png")), "Apply", this);
    m_cancelButton = new QPushButton("Cancel", this);
    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->addWidget(m_applyButton);
    bottomLayout->addWidget(m_cancelButton);

    m_mainLayout->addWidget(new QLabel("Title", this), 0);
    m_mainLayout->addSpacing(5);
    m_mainLayout->addWidget(m_titleEdit);
    m_mainLayout->addWidget(new QLabel("Description", this), 0);
    m_mainLayout->addSpacing(5);
    m_mainLayout->addWidget(m_descriptionEdit);
    m_mainLayout->addWidget(new QLabel("Deadline", this), 0);
    m_mainLayout->addWidget(m_deadlineSetButton);
    m_mainLayout->addSpacing(5);
    m_mainLayout->addWidget(m_deadlineEdit);
    m_mainLayout->addSpacing(10);
    m_mainLayout->addLayout(bottomLayout);
}

void TaskForm::configureFunctionality()
{
    //By default, user can set deadline date
    m_deadlineSetButton->setCheckState(Qt::Checked);
    m_deadlineEdit->setDateTime(QDateTime::currentDateTime());
    QObject::connect(m_deadlineSetButton, &QCheckBox::toggled, this, [this](bool checked) {
        m_deadlineEdit->setEnabled(checked ? true : false);
    });

    //Form connections to supply opportunity to cancel/apply task creation
    QObject::connect(m_cancelButton, &QPushButton::clicked, this, &TaskForm::onCancelTaskCreation);

    QObject::connect(m_applyButton, &QPushButton::clicked, this, &TaskForm::onApplyConfiguredTask);
    
}

void TaskForm::onApplyConfiguredTask()
{
    QString deadlineString = m_deadlineSetButton->isChecked()
                                 ? m_deadlineEdit->dateTime().toString()
                                 : "";
    
    
    qDebug() << "[!]New task data is transfered to receiver-s(DB-object)! Edit fields are cleared! New task form is closed!";
    emit taskFormApplied(m_titleEdit->text(), m_descriptionEdit->toPlainText(), deadlineString);
    
    this->close();
    m_titleEdit->clear();
    m_descriptionEdit->clear();
    m_deadlineEdit->clear();

}

void TaskForm::onCancelTaskCreation()
{
    this->close();
    m_titleEdit->clear();
    m_descriptionEdit->clear();
    m_deadlineEdit->clear();

    qDebug() << "[!]Input fields are cleared! New task form is closed!";
}
