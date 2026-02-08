#include "tasksTableDelegate.h"

TasksTableDelegate::TasksTableDelegate(QObject *parent)
    : QStyledItemDelegate{parent}
{}

void TasksTableDelegate::paint(QPainter *painter,
                               const QStyleOptionViewItem &option,
                               const QModelIndex &index) const
{
    if (index.column() == 1) {
        painter->save();
        
        //Retrieve text
        QString text = index.data(Qt::DisplayRole).toString();
        
        //Retrieve 'title' contents
        if (text.contains("\"title\"")) {
            QJsonDocument doc = QJsonDocument::fromJson(text.toUtf8());
            if (!doc.isNull() && doc.isObject()) {
                QJsonObject obj = doc.object();
                if (obj.contains("title")) {
                    text = obj["title"].toString();
                }
            }
        }
        
        //Apply default colors
        if (option.state & QStyle::State_Selected) {
            painter->setPen(option.palette.color(QPalette::HighlightedText));
        } else {
            painter->setPen(option.palette.color(QPalette::Text));
        }

        QTextOption textOption;
        textOption.setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        
        painter->drawText(option.rect, text, textOption);
        
        painter->restore();
    } else {
        QStyledItemDelegate::paint(painter, option, index);
    }
}
