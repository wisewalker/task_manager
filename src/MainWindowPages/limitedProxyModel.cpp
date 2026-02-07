#include "limitedProxyModel.h"

LimitedProxyModel::LimitedProxyModel(QObject *parent, int maxRows)
    : QSortFilterProxyModel(parent), m_maxRowsNumber(maxRows)
{
    
}

void LimitedProxyModel::setMaxRowsNumber(int enteredMaxRowsNumber)
{
    if (m_maxRowsNumber != enteredMaxRowsNumber)
    {
        m_maxRowsNumber = enteredMaxRowsNumber;
        invalidate();
    }
}

int LimitedProxyModel::maxRowsNumber() const
{
    return m_maxRowsNumber;
}

int LimitedProxyModel::rowCount(const QModelIndex &parent) const {
    if (parent.isValid())
        return 0;
    
    int sourceRowsNumber = QSortFilterProxyModel::rowCount(parent);
    return qMin(sourceRowsNumber, m_maxRowsNumber);
}
