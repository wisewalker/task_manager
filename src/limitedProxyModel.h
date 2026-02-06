#ifndef LIMITEDPROXYMODEL_H
#define LIMITEDPROXYMODEL_H

#include <QSortFilterProxyModel>

//Define class that will limit the output tuples in the (table)-view
class LimitedProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
    
private:
    int m_maxRowsNumber = 10;
    
public:
    explicit LimitedProxyModel(QObject *parent = nullptr, int maxRows = 10);
    
    //Each time the max number of output rows changes,
    //the proxymodel notifies view about it (to init repaint process)
    void setMaxRowsNumber(int enteredMaxRowsNumber);

    int maxRowsNumber() const;
    
private:
    //Return min rows number in order to output top-requested tuples
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
};

#endif // LIMITEDPROXYMODEL_H
