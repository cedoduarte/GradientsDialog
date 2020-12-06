#include "colordelegate.h"
#include "colorcombobox.h"

ColorDelegate::ColorDelegate(QObject *parent)
    : QItemDelegate(parent)
{
    // nothing to do here
}

ColorDelegate::~ColorDelegate()
{
    // nothing to do here
}

QWidget *ColorDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                                     const QModelIndex &index) const
{
    (void) index;
    (void) option;
    ColorComboBox *colorCombobox = new ColorComboBox(parent);
    return colorCombobox;
}

void ColorDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    ColorComboBox *colorCombobox = static_cast<ColorComboBox *>(editor);
    colorCombobox->setCurrentColor(index.data().value<QColor>());
}

void ColorDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    ColorComboBox *colorCombobox = static_cast<ColorComboBox *>(editor);
    model->setData(index, colorCombobox->currentColor());
}

void ColorDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                                         const QModelIndex &index) const
{
    (void) index;
    editor->setGeometry(option.rect);
}
