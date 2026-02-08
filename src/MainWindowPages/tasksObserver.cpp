#include "tasksObserver.h"

TasksObserver::TasksObserver(QWidget *parent)
    : QDialog{parent}
{
    this->setObjectName("taskObserver");
    
    configureInterfaceStructure();
    configureFunctionality();
}

void TasksObserver::configureInterfaceStructure()
{
    m_mainLayout = new QVBoxLayout;
    this->setLayout(m_mainLayout);
    
    m_titleEdit = new QLineEdit(this);
    m_descriptionEdit = new QPlainTextEdit(this);
    m_deadlineEdit = new QDateTimeEdit(this);
    m_creationDateEdit = new QDateTimeEdit(this);
    m_creationDateEdit->setEnabled(false);
    m_deleteButton = new QPushButton("Delete");
    
    m_mainLayout->addWidget(new QLabel("Title:", this));
    m_mainLayout->addWidget(m_titleEdit);
    m_mainLayout->addWidget(new QLabel("Description:", this));
    m_mainLayout->addWidget(m_descriptionEdit);
    m_mainLayout->addWidget(new QLabel("Deadline Date:", this));
    m_mainLayout->addWidget(m_deadlineEdit);
    m_mainLayout->addWidget(new QLabel("Creation Date:", this));
    m_mainLayout->addWidget(m_creationDateEdit);
    
    m_buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                                           | QDialogButtonBox::Cancel,
                                                       this);
    
    m_mainLayout->addWidget(m_buttonBox);
    m_mainLayout->addWidget(m_deleteButton);
}

void TasksObserver::configureFunctionality()
{
    QObject::connect(m_buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    QObject::connect(m_buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
    QObject::connect(m_deleteButton, &QPushButton::clicked, this, [this](bool){
        qDebug() << "[!]Delete task button was clicked!";
        emit deleteButtonClicked();});
}

void TasksObserver::setData(const QString &taskContents,
                            const QString &deadlineDate,
                            const QString &creationDate)
{
    QString titleText;
    QString descriptionText;

    QJsonDocument doc = QJsonDocument::fromJson(taskContents.toUtf8());
    if (!doc.isNull() && doc.isObject()) {
        QJsonObject obj = doc.object();
        if (obj.contains("title")) {
            titleText = obj["title"].toString();
        }
        if (obj.contains("description")) {
            descriptionText = obj["description"].toString();
        }
    }

    m_titleEdit->setText(titleText);
    m_descriptionEdit->setPlainText(descriptionText);
    m_deadlineEdit->setDateTime(QDateTime::fromString(deadlineDate));
    m_creationDateEdit->setDateTime(QDateTime::fromString(creationDate));
}

QString TasksObserver::getTitle() const
{
    return m_titleEdit->text();
}

QString TasksObserver::getDescription() const
{
    return m_descriptionEdit->toPlainText();
}

QString TasksObserver::getDeadlineDate() const
{
    return m_deadlineEdit->text();
}

QString TasksObserver::getCreationDate() const
{
    return m_creationDateEdit->text();
}
