#ifndef GRADIENTMODEL_H
#define GRADIENTMODEL_H

#include "gradientdata.h"
#include <QColor>
#include <QLinearGradient>
#include <QAbstractItemModel>

namespace GradientColumn
{
    enum
    {
        Stop,
        Color
    };
}

class GradientModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit GradientModel(QObject *parent = nullptr);
    virtual ~GradientModel();
    void addStop(GradientData *data);
    void addStop(double stop, const QColor &color);
    void removeStop(int row);
    QLinearGradient gradient(double w = 100.0, double h = 100.0) const;
    QLinearGradient gradient(const QSize &size) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
private:
    QList<GradientData *> m_data;
};

#endif // GRADIENTMODEL_H
