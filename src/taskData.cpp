#include "taskData.h"

TaskData::TaskData(QObject *parent,
                   int id,
                   QString title,
                   QString description,
                   QString creationDate,
                   QString deadlineDate)
    : QObject(parent)
    , m_id{id}
    , m_title{title}
    , m_description{description}
    , m_deadlineDate{deadlineDate}
    , m_creationDate{creationDate}
{
    m_isDeadlineSet = deadlineDate == "" ? false : true;
    qDebug() << "Task data object created!";
}

void TaskData::setId(int id)
{
    m_id = id;
}

void TaskData::setTitle(const QString &title)
{
    m_title = title;
}

void TaskData::setDescription(const QString &description)
{
    m_description = description;
}

void TaskData::setContents(const QString &contents)
{
    QJsonDocument doc = QJsonDocument::fromJson(contents.toUtf8());
    if (!doc.isNull() && doc.isObject()) {
        QJsonObject obj = doc.object();
        if (obj.contains("title")) {
            m_title = obj["title"].toString();
        }
        if (obj.contains("description")) {
            m_description = obj["description"].toString();
        }
    }
}

void TaskData::setCreationDate(const QString &creationDate)
{
    m_creationDate = creationDate;
}

void TaskData::setDeadlineActive(bool isDeadlineSet)
{
    m_isDeadlineSet = isDeadlineSet;
    m_deadlineDate = m_isDeadlineSet ? m_deadlineDate : "";
}

void TaskData::setDeadlineDate(const QString &deadlineDate)
{
    m_deadlineDate = deadlineDate;
    m_isDeadlineSet = m_deadlineDate == "" ? false : true;
}

int TaskData::id() const
{
    return m_id;
}

QString TaskData::title() const
{
    return m_title;
}

QString TaskData::description() const
{
    return m_description;
}

QString TaskData::creationDate() const
{
    return m_creationDate;
}

bool TaskData::isDeadlineSet() const
{
    return m_isDeadlineSet;
}

QString TaskData::deadlineDate() const
{
    return m_deadlineDate;
}

TaskData::~TaskData()
{
    qDebug() << "Task data object destroyed!";
}
