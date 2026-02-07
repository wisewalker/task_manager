#ifndef TASKSMANAGEMENTPAGE_H
#define TASKSMANAGEMENTPAGE_H

#include <QWidget>

#include <QDebug>

#include <QTextEdit>
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

    QDataWidgetMapper *m_mapper = nullptr;
    
public:
    explicit TasksManagementPage(QWidget *parent = nullptr, QSqlTableModel *model = nullptr);

    void setModel(QSqlTableModel *model);
    
private:
    void configureStyle();
    void configureStructure();
    void configureFunctionality();

public slots:
    void onUpdateView();
    
signals:
    void createTaskButtonClicked(bool);
    void backHomeButtonClicked(bool);
    
};

#endif // TASKSMANAGEMENTPAGE_H
