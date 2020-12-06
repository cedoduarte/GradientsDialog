#ifndef STOPDELEGATE_H
#define STOPDELEGATE_H

#include <QItemDelegate>

class StopDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    /** constructor */
    StopDelegate(QObject *parent = nullptr);

    /** destructor */
    virtual ~StopDelegate();
protected:
    /** crea editor */
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;

    /** asigna data al editor */
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;

    /** asigna data al modelo */
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;

    /** asigna geometry al editor */
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                              const QModelIndex &index) const override;
};

#endif // STOPDELEGATE_H
