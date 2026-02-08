#ifndef TASKSMANAGEMENTPAGE_H
#define TASKSMANAGEMENTPAGE_H

#include <QWidget>

#include <QDebug>

#include <QTextEdit>
#include <QPlainTextEdit>
#include <QLineEdit>
#include <QDateTimeEdit>

#include <QPushButton>
#include <QLabel>

#include <QTableView>
#include <QListView>

#include <QHeaderView>

#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QSqlTableModel>

#include <QSortFilterProxyModel>

#include <QDataWidgetMapper>

#include <QDialog>

#include "tasksObserver.h"

class TasksManagementPage : public QWidget
{
    Q_OBJECT
    
private:
    QVBoxLayout *m_mainLayout = nullptr;
    
    QPushButton *m_backHomeButton = nullptr;
    QPushButton *m_createTaskButton = nullptr;    
    
    QTableView *m_assignedTasksView = nullptr;

    QSqlTableModel *m_Sourcemodel = nullptr;

    QSortFilterProxyModel *m_assignedTasksModel = nullptr;

    QDialog *m_viewItemsObserver = nullptr;
    QPlainTextEdit *task_edit;
    QDateTimeEdit *creationDate_edit;
    QDateTimeEdit *deadlineDate_edit;

    TasksObserver *m_tasksObserver = nullptr;
    
public:
    explicit TasksManagementPage(QWidget *parent = nullptr, QSqlTableModel *model = nullptr);

    void setModel(QSqlTableModel *model);
    
private:
    void configureStyle();
    void configureStructure();
    void configureFunctionality();

public slots:
    void onUpdateView();
    void onInteractViewItem(const QModelIndex&);
    void onInteractViewItem(int id);
    void onDeleteViewItem();
    
signals:
    void createTaskButtonClicked(bool);
    void backHomeButtonClicked(bool);
    void taskFieldsUpdated(int id, QString title, QString description, QString deadline);
    void taskDeletionRequested(int id);
};

#endif // TASKSMANAGEMENTPAGE_H
