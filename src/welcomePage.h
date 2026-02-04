#ifndef WELCOMEPAGE_H
#define WELCOMEPAGE_H

#include <QWidget>

#include <QPushButton>
#include <QLabel>

#include <QTableView>
#include <QListView>

#include <QVBoxLayout>
#include <QHBoxLayout>

class WelcomePage : public QWidget
{
    Q_OBJECT

private:
    QHBoxLayout *m_mainLayout = nullptr;

    QPushButton *m_createTaskButton = nullptr;
    QPushButton *m_listTasksButton = nullptr;    
    
    QTableView *m_recentlyCreatedTasks = nullptr;
    QTableView *m_reachingDeadlineTasks = nullptr;
    
public:
    explicit WelcomePage(QWidget *parent = nullptr);

private:
    void configureStyle();
    void configureStructure();
    void configureFunctionality();

signals:
};

#endif // WELCOMEPAGE_H
