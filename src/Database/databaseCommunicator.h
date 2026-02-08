#ifndef DATABASECOMMUNICATOR_H
#define DATABASECOMMUNICATOR_H

#include <QObject>

#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlRecord>

#include <QModelIndex>

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

public slots:
    void onCreateNewTask(QString title, QString description, QString deadline);
    void onUpdateTask(int id, QString title, QString description, QString deadline);
    void onDeleteTask(int id);
        
signals:
    void databaseContentsChanged();
};

#endif // DATABASECOMMUNICATOR_H
