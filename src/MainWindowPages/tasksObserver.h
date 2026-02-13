#ifndef TASKSOBSERVER_H
#define TASKSOBSERVER_H

#include <QWidget>

#include <QLabel>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QDateTimeEdit>
#include <QPushButton>

#include <QString>
#include <QJsonDocument>
#include <QJsonObject>

#include <QDialog>
#include <QDialogButtonBox>
#include <QVBoxLayout>

#include "taskData.h"

class TasksObserver : public QDialog
{
    Q_OBJECT

private:
    QVBoxLayout *m_mainLayout = nullptr;
    
    QLineEdit *m_titleEdit = nullptr;
    QPlainTextEdit *m_descriptionEdit = nullptr;
    QDateTimeEdit *m_deadlineEdit = nullptr;
    QDateTimeEdit *m_creationDateEdit = nullptr;

    QPushButton *m_okButton = nullptr;
    QPushButton *m_cancelButton = nullptr;
    QPushButton *m_deleteButton = nullptr;

    TaskData *m_taskData = nullptr;
    
public:
    explicit TasksObserver(QWidget *parent = nullptr);

    void setEditorsData(const QString &taskContents,
                 const QString &creationDate,
                 const QString &deadlineDate);
    QString getEditorTitle() const;
    QString getEditorDescription() const;
    QString getEditorDeadlineDate() const;
    QString getEditorCreationDate() const;

    TaskData &sourceTaskData();

private:
    void configureInterfaceStructure();
    void configureInterfaceStyle();
    void configureFunctionality();
    
signals:
    void deleteButtonClicked();
};

#endif // TASKSOBSERVER_H
