#include "proofarea.h"

ProofArea::ProofArea(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant ProofArea::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex ProofArea::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex ProofArea::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int ProofArea::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int ProofArea::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant ProofArea::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
