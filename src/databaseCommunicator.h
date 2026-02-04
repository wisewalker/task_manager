#ifndef DATABASECOMMUNICATOR_H
#define DATABASECOMMUNICATOR_H

#include <QObject>

#include <QSqlDatabase>
#include <QSqlTableModel>

#include <QErrorMessage>

class DatabaseCommunicator : public QObject
{
    Q_OBJECT

private:
    QSqlDatabase m_databaseConnection;
    QSqlTableModel *m_tableModel = nullptr;
    QErrorMessage *m_errorMessageBox= nullptr;
    
public:
    explicit DatabaseCommunicator(QObject *parent = nullptr);

    QSqlTableModel *model() { return m_tableModel; }

    void openConnection();

private:
    void prepareTable();
    void createDefaultTask();

private slots:
    void createNewTask();
        
signals:
};

#endif // DATABASECOMMUNICATOR_H
