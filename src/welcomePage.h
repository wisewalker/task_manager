#ifndef WELCOMEPAGE_H
#define WELCOMEPAGE_H

#include "limitedProxyModel.h"

#include <QWidget>

#include <QDebug>

#include <QPushButton>
#include <QLabel>

#include <QTableView>
#include <QListView>

#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QSqlTableModel>
#include <QSortFilterProxyModel>

class WelcomePage : public QWidget
{
    Q_OBJECT

private:
    QHBoxLayout *m_mainLayout = nullptr;

    QPushButton *m_createTaskButton = nullptr;
    QPushButton *m_listTasksButton = nullptr;

    QTableView *m_recentlyCreatedTasksView = nullptr;
    QTableView *m_reachingDeadlineTasksView = nullptr;

    QSqlTableModel *m_sourceModel = nullptr;
    LimitedProxyModel *m_recentlyCreatedTasksModel = nullptr;
    LimitedProxyModel *m_reachingDeadlineTasksModel = nullptr;

    const int topRecentlyCreated_Number = 5;
    const int topReachingDeadline_Number = 5;
    
public:
    explicit WelcomePage(QWidget *parent = nullptr, QSqlTableModel *model = nullptr);

    QPushButton *createTaskButton() const;
    QPushButton *listTasksButton() const;

    void setModel(QSqlTableModel *model);

private:
    void configureStyle();
    void configureStructure();
    void configureFunctionality();

signals:
};

#endif // WELCOMEPAGE_H
