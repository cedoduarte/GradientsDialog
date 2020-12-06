#ifndef COLORDELEGATE_H
#define COLORDELEGATE_H

#include <QItemDelegate>

class ColorDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    /** constructor */
    ColorDelegate(QObject *parent = nullptr);

    /** destructor */
    virtual ~ColorDelegate();
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

#endif // COLORDELEGATE_H
