#include "mymodel.h"

MyModel::MyModel(QObject *parent)
            :QAbstractTableModel(parent)
{

}

int MyModel::rowCount(const QModelIndex & /*parent*/) const
{
    return 5;

}

int MyModel::columnCount(const QModelIndex & /*parent*/) const
{
    return 8;
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if(role == Qt::DisplayRole)
    {
        return QString("%1, %2")
                    .arg(index.row()+1)
                    .arg(index.column()+1);
    }

    if(role == Qt::ToolTipRole)
    {
        return QString("Number of row and column");

    }
    return QVariant();
}
