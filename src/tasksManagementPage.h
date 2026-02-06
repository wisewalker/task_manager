#ifndef TASKSMANAGEMENTPAGE_H
#define TASKSMANAGEMENTPAGE_H

#include <QWidget>

#include <QDebug>

#include <QPushButton>
#include <QLabel>

#include <QTableView>
#include <QListView>

#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QSqlTableModel>

class TasksManagementPage : public QWidget
{
    Q_OBJECT
    
private:
    QVBoxLayout *m_mainLayout = nullptr;
    
    QPushButton *m_backHomeButton = nullptr;
    QPushButton *m_createTaskButton = nullptr;    
    
    QTableView *m_assignedTasksView = nullptr;
    
    QSqlTableModel *m_model = nullptr;
    
public:
    explicit TasksManagementPage(QWidget *parent = nullptr, QSqlTableModel *model = nullptr);
    
    QPushButton *createTaskButton() const;
    QPushButton *backHomeButton() const;
    
    void setModel(QSqlTableModel *model);
    
private:
    void configureStyle();
    void configureStructure();
    void configureFunctionality();
    
signals:
};

#endif // TASKSMANAGEMENTPAGE_H
