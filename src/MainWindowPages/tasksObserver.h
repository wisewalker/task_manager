#ifndef TASKSOBSERVER_H
#define TASKSOBSERVER_H

#include <QWidget>

#include <QLabel>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QCheckBox>
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
    QCheckBox *m_setDeadlineButton = nullptr;
    QDateTimeEdit *m_creationDateEdit = nullptr;

    QPushButton *m_updateButton = nullptr;
    QPushButton *m_cancelButton = nullptr;
    QPushButton *m_deleteButton = nullptr;

    int m_currentTaskID = -1;

public:
    explicit TasksObserver(QWidget *parent = nullptr);
    void setCurrentTaskID(int id);

    void setEditorsData(const TaskData &sourceTaskData);
    int getCurrentTaskID();
    QString getEditorTitle() const;
    QString getEditorDescription() const;
    QString getEditorDeadlineDate() const;
    QString getEditorCreationDate() const;

    
private:
    void configureInterfaceStructure();
    void configureInterfaceStyle();
    void configureFunctionality();

private slots:
    void onDeleteButton(bool);
    void onUpdateButton(bool);
    void onCancelButton(bool);

signals:
    void deleteTaskRequested();
    void updateTaskRequested();
};

#endif // TASKSOBSERVER_H
