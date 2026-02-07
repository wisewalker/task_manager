#ifndef TASKFORM_H
#define TASKFORM_H

#include <QDialog>

#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QDateTimeEdit>

#include <QPushButton>

#include <QCheckBox>

#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QDebug>

#include <QString>

class TaskForm : public QDialog
{
    Q_OBJECT

private:
    QVBoxLayout *m_mainLayout = nullptr;

    QLineEdit *m_titleEdit = nullptr;
    QTextEdit *m_descriptionEdit = nullptr;
    QCheckBox *m_deadlineSetButton = nullptr;
    QDateTimeEdit *m_deadlineEdit = nullptr;
    
    QPushButton *m_applyButton = nullptr;
    QPushButton *m_cancelButton = nullptr;

public:
    explicit TaskForm(QWidget *parent = nullptr);

private:
    void configureInterfaceStructure();
    void configureFunctionality();

private slots:
    void onCancelTaskCreation();
    void onApplyConfiguredTask();

signals:
    void applyButtonClicked();
    void taskFormApplied(QString title, QString description, QString deadline);
    void cancelButtonClicked();
};

#endif // TASKFORM_H
