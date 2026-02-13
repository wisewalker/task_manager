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
    , m_creationDate{creationDate}
    , m_deadlineDate{deadlineDate}
{
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

void TaskData::setCreationDate(const QString &creationDate)
{
    m_creationDate = creationDate;
}

void TaskData::setDeadlineDate(const QString &deadlineDate)
{
    m_deadlineDate = deadlineDate;
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

QString TaskData::deadlineDate() const
{
    return m_deadlineDate;
}
