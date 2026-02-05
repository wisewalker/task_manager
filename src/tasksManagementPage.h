#ifndef TASKSMANAGEMENTPAGE_H
#define TASKSMANAGEMENTPAGE_H

#include <QWidget>

#include <QPushButton>
#include <QLabel>

#include <QTableView>
#include <QListView>

#include <QVBoxLayout>
#include <QHBoxLayout>

class TasksManagementPage : public QWidget
{
    Q_OBJECT
    
private:
    QVBoxLayout *m_mainLayout = nullptr;
    
    QPushButton *m_backHomeButton = nullptr;
    QPushButton *m_createTaskButton = nullptr;    
    
    QTableView *m_assignedTasksView = nullptr;
    
public:
    explicit TasksManagementPage(QWidget *parent = nullptr);
    
private:
    void configureStyle();
    void configureStructure();
    void configureFunctionality();
    
signals:
};

#endif // TASKSMANAGEMENTPAGE_H
