#include "gradientmodel.h"

GradientModel::GradientModel(QObject *parent)
    : QAbstractItemModel(parent)
{
    // nothing to do here
}

GradientModel::~GradientModel()
{
    qDeleteAll(m_data);
}

void GradientModel::addStop(GradientData *data)
{
    if (data)
    {
        const int nrows = rowCount();
        beginInsertRows(QModelIndex(), nrows, nrows);
        m_data.append(data);
        endInsertRows();
    }
}

void GradientModel::addStop(double stop, const QColor &color)
{
    GradientData *s = new GradientData;
    s->setStop(stop);
    s->setColor(color);
    addStop(s);
}

void GradientModel::removeStop(int row)
{
    if (row >= 0)
    {
        beginRemoveRows(QModelIndex(), row, row);
        delete m_data.takeAt(row);
        endRemoveRows();
    }
}

QLinearGradient GradientModel::gradient(double w, double h) const
{
    QLinearGradient g(0.0, 0.0, w, h);
    g.setSpread(QLinearGradient::PadSpread);
    std::for_each(m_data.begin(), m_data.end(), [&](GradientData *gdata)
    {
        g.setColorAt(gdata->stop(), gdata->color());
    });
    return g;
}

QLinearGradient GradientModel::gradient(const QSize &size) const
{
    return gradient(size.width(), size.height());
}

QVariant GradientModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal)
    {
        if (role == Qt::DisplayRole)
        {
            if (section == GradientColumn::Stop)
            {
                return tr("Stop");
            }
            else if (section == GradientColumn::Color)
            {
                return tr("Color");
            }
        }
    }
    return QVariant();
}

QModelIndex GradientModel::index(int row, int column, const QModelIndex &parent) const
{
    (void) parent;
    if (m_data.size() == 0)
    {
        return QModelIndex();
    }
    return createIndex(row, column, m_data.at(row));
}

QModelIndex GradientModel::parent(const QModelIndex &index) const
{
    (void) index;
    return QModelIndex();
}

int GradientModel::rowCount(const QModelIndex &parent) const
{
    (void) parent;
    return m_data.size();
}

int GradientModel::columnCount(const QModelIndex &parent) const
{
    (void) parent;
    return 2;
}

QVariant GradientModel::data(const QModelIndex &index, int role) const
{
    if (m_data.size() > 0)
    {
        if (!index.isValid())
        {
            return QVariant();
        }
        if (role == Qt::DisplayRole)
        {
            if (index.column() == GradientColumn::Stop)
            {
                return m_data.at(index.row())->stop();
            }
            else if (index.column() == GradientColumn::Color)
            {
                return m_data.at(index.row())->color();
            }
        }
    }
    return QVariant();
}

bool GradientModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (m_data.size() > 0)
    {
        if (data(index, role) != value)
        {
            if (role == Qt::EditRole)
            {
                if (index.column() == GradientColumn::Stop)
                {
                    m_data.at(index.row())->setStop(value.toDouble());
                }
                else if (index.column() == GradientColumn::Color)
                {
                    m_data.at(index.row())->setColor(value.value<QColor>());
                }
                emit dataChanged(index, index, QVector<int>() << role);
                return true;
            }
        }
    }
    return false;
}

Qt::ItemFlags GradientModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
    {
        return Qt::NoItemFlags;
    }
    return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}
