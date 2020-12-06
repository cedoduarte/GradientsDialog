#include "stopdelegate.h"

#include <QDoubleSpinBox>
#include <QLocale>

StopDelegate::StopDelegate(QObject *parent)
    : QItemDelegate(parent)
{
    // nothing to do here
}

StopDelegate::~StopDelegate()
{
    // nothing to do here
}

QWidget *StopDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    (void) index;
    (void) option;
    QDoubleSpinBox *spinner = new QDoubleSpinBox(parent);
    spinner->setLocale(QLocale(QLocale::English));
    spinner->setRange(0.0, 1.0);
    return spinner;
}

void StopDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QDoubleSpinBox *spinner = static_cast<QDoubleSpinBox *>(editor);
    spinner->setValue(index.data().toDouble());
}

void StopDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QDoubleSpinBox *spinner = static_cast<QDoubleSpinBox *>(editor);
    model->setData(index, spinner->value());
}

void StopDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    (void) index;
    editor->setGeometry(option.rect);
}
