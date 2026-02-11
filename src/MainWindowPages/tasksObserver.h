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
    
public:
    explicit TasksObserver(QWidget *parent = nullptr);

    void setData(const QString &taskContents,
                 const QString &deadlineDate,
                 const QString &creationDate);
    QString getTitle() const;
    QString getDescription() const;
    QString getDeadlineDate() const;
    QString getCreationDate() const;

private:
    void configureInterfaceStructure();
    void configureInterfaceStyle();
    void configureFunctionality();
    
signals:
    void deleteButtonClicked();
};

#endif // TASKSOBSERVER_H
