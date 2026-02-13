#ifndef TASKDATA_H
#define TASKDATA_H

#include <QObject>
#include <QString>
#include <QDebug>

#include <QJsonDocument>
#include <QJsonObject>

class TaskData : public QObject
{
    Q_OBJECT

private:
    int m_id = 0;
    QString m_title = "";
    QString m_description = "";
    QString m_creationDate = "";
    bool m_isDeadlineSet = false;
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
    void setDeadlineActive(bool isDeadlineSet);
    void setDeadlineDate(const QString &deadlineDate);
    void setContents(const QString &contents);

    int id() const;
    QString title() const;
    QString description() const;
    QString creationDate() const;
    bool isDeadlineSet() const;
    QString deadlineDate() const;

    ~TaskData();
    
signals:
};

#endif // TASKDATA_H
