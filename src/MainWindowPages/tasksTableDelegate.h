#ifndef TASKSTABLEDELEGATE_H
#define TASKSTABLEDELEGATE_H

#include <QObject>

#include <QStyledItemDelegate>

#include <QString>

#include <QLineEdit>
#include <QPlainTextEdit>
#include <QVBoxLayout>

#include <QPainter>
#include <QTextOption>

#include <QJsonDocument>
#include <QJsonObject>

#include <QDebug>

class TasksTableDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit TasksTableDelegate(QObject *parent = nullptr);

    void paint(QPainter *painter,
               const QStyleOptionViewItem &option,
               const QModelIndex &index) const override;
    
signals:
};

#endif // TASKSTABLEDELEGATE_H
