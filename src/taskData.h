#ifndef TASKDATA_H
#define TASKDATA_H

#include <QObject>
#include <QString>
#include <QDebug>

class TaskData : public QObject
{
    Q_OBJECT

private:
    int m_id = 0;
    QString m_title = "";
    QString m_description = "";
    QString m_creationDate = "";
    QString m_deadlineDate = "";

public:
    explicit TaskData(QObject *parent = nullptr,
                      int id = 0,
                      QString title = "",
                      QString description = "",
                      QString creationDate = "",
                      QString deadlineDate = "");

    void setId(int id);
    void setTitle(const QString &title);
    void setDescription(const QString &description);
    void setCreationDate(const QString &creationDate);
    void setDeadlineDate(const QString &deadlineDate);

    int id() const;
    QString title() const;
    QString description() const;
    QString creationDate() const;
    QString deadlineDate() const;
    
signals:
};

#endif // TASKDATA_H
