#include <QSqlError>
#include <QSqlQuery>

#include <QDebug>

#include <QJsonDocument>
#include <QJsonObject>

#include <QDateTime>

#include "databaseCommunicator.h"
#include "globalConstants.h"

DatabaseCommunicator::DatabaseCommunicator(QObject *parent)
    : QObject{parent}
{
    //Prepare error message box for possible error-cases
    m_errorMessageBox = new QErrorMessage;
    m_errorMessageBox->setObjectName("errorBox");

    //Create and configure database connection object
    m_databaseConnection = QSqlDatabase::addDatabase("QPSQL", "defaultConnection");
    m_databaseConnection.setDatabaseName(GlobalConstants::db_database_name);
    m_databaseConnection.setHostName(GlobalConstants::db_host_name);
    m_databaseConnection.setUserName(GlobalConstants::db_user_name);
    m_databaseConnection.setPassword(GlobalConstants::db_user_password);
}

void DatabaseCommunicator::prepareTable()
{
    QSqlQuery query(m_databaseConnection);
    //id of task will auto-generated
    query.exec("CREATE TABLE IF NOT EXISTS tasks ("
                "id SERIAL NOT NULL PRIMARY KEY,"
                "task_contents jsonb NOT NULL,"
                "creation_date TIMESTAMP NOT NULL,"
                "deadline_date TIMESTAMP);");

    if (query.isActive()) {
        qDebug() << "[!]Main table" << m_databaseConnection.tables() << "was successfully created!";
    } else {
        qDebug() << query.lastError();
    }
    
    //(For testing purposes...)
    //createDefaultTask();
}

void DatabaseCommunicator::createDefaultTask()
{
    QSqlQuery query(m_databaseConnection);
    
    //INSERT SOME DEFAULT DATA
    query.prepare("INSERT INTO tasks (id, task_contents, creation_date, deadline_date) VALUES "
                   "(DEFAULT, :task_contents, CURRENT_TIMESTAMP, :deadline_date);");
    
    //Create JSON-object for task-data (and fill it)
    QJsonObject task_contents;
    task_contents["title"] = "Default Task-0";
    task_contents["description"] = "This is a test task. Please, type your task details here!";
    //Create complete JSON-document
    QJsonDocument doc(task_contents);
    //Transform JSON-document to QString, not to raw bytes sequence
    //(therefore, postgres could retreive and process data appropriately)
    QString jsonString = doc.toJson(QJsonDocument::Compact);
    query.bindValue(":task_contents", jsonString);
    
    QDateTime deadlineDate;
    deadlineDate.setDate(QDate(2026, 2, 23));
    deadlineDate.setTime(QTime(15, 30, 0));
    query.bindValue(":deadline_date", deadlineDate.toString());
    
    query.exec();
    if (query.isActive()) {
        qDebug() << "Data was successfully transfered to db";
    } else {
        qDebug() << query.lastError();
    }
}

void DatabaseCommunicator::openConnection()
{
    //Initialize connection to DB
    bool state = m_databaseConnection.open();
    if (!state) {
        qDebug() << m_databaseConnection.lastError();
    } else {
        qDebug() << "[!]Database was successfully opened!";
    }

    prepareTable();
    
    //Create and configure table model (interface object for data source - db table 'tasks')
    m_tableModel = new QSqlTableModel(this, m_databaseConnection);
    m_tableModel->setTable("tasks");
    m_tableModel->setEditStrategy(QSqlTableModel::OnRowChange);
    m_tableModel->select();
    
    m_tableModel->setHeaderData(0, Qt::Horizontal, "ID");
    m_tableModel->setHeaderData(1, Qt::Horizontal, "Task");
    m_tableModel->setHeaderData(2, Qt::Horizontal, "Created");
    m_tableModel->setHeaderData(3, Qt::Horizontal, "Deadline");
}

void DatabaseCommunicator::createNewTask()
{
    
}
