#include "colorcombobox.h"
#include <QStylePainter>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMouseEvent>
#include <QVBoxLayout>
#include <QPaintEvent>
#include <QListWidget>
#include <QJsonArray>
#include <QFile>
#include <QMenu>

ColorComboBox::ColorComboBox(QWidget *parent)
    : QWidget(parent)
{
    m_listWidget = makeListWidget();
    m_menu = makeMenu();
    setCurrentColor(Qt::color0);
}

ColorComboBox::~ColorComboBox()
{
    // nothing to do here
}

void ColorComboBox::setCurrentColor(const QColor &color)
{
    if (m_currentColor != color)
    {
        m_currentColor = color;
        update();
        emit currentColorChanged(m_currentColor);
    }
}

void ColorComboBox::onListWidgetItemClicked(QListWidgetItem *item)
{
    setCurrentColor(item->background().color());
    update();
    m_menu->hide();
}

QRect ColorComboBox::makeColorRect() const
{
    QRect colorRect;
    QPoint center = rect().center();
    colorRect.setWidth(int(width() * 2.0/3.0));
    colorRect.setHeight(int(height() * 2.0/3.0));
    colorRect.setX(center.x() - colorRect.width()/2);
    colorRect.setY(center.y() - colorRect.height()/4);
    return colorRect;
}

QStyleOptionComboBox ColorComboBox::makeComboBoxStyle()
{
    QStyleOptionComboBox option;
    option.initFrom(this);
    return option;
}

void ColorComboBox::paintEvent(QPaintEvent *e)
{
    QStylePainter painter(this);
    painter.drawComplexControl(QStyle::CC_ComboBox, makeComboBoxStyle());
    painter.fillRect(makeColorRect(), m_currentColor);
    QWidget::paintEvent(e);
}

void ColorComboBox::mousePressEvent(QMouseEvent *e)
{
    m_listWidget->setMinimumWidth(width());
    QPoint p = parentWidget()->mapToGlobal(pos());
    p.setY(p.y() + height());
    m_menu->popup(p);
    QWidget::mousePressEvent(e);
}

QListWidget *ColorComboBox::makeListWidget()
{
    QListWidget *listWidget = new QListWidget(this);
    listWidget->setMinimumSize(width(), 250);
    assignColors(listWidget);
    connect(listWidget, &QListWidget::itemClicked, this, &ColorComboBox::onListWidgetItemClicked);
    return listWidget;
}

QMenu *ColorComboBox::makeMenu()
{
    QMenu *menu = new QMenu(this);
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(m_listWidget);
    vbox->setContentsMargins(0, 0, 0, 0);
    vbox->setSpacing(0);
    menu->setLayout(vbox);
    return menu;
}

void ColorComboBox::assignColors(QListWidget *listWidget)
{
    QFile F(":/colors.json");
    if (F.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QJsonDocument doc = QJsonDocument::fromJson(F.readAll());
        F.close();
        QJsonArray colorsArray = doc.array();
        if (colorsArray.size() > 0)
        {
            listWidget->clear();
            std::for_each(colorsArray.begin(), colorsArray.end(), [&](const QJsonValue &v)
            {
                QJsonObject colorObj = v.toObject();
                QListWidgetItem *colorItem = new QListWidgetItem;
                colorItem->setText(colorObj["name"].toString());
                colorItem->setBackground(QColor(colorObj["hexvalue"].toString()));
                colorItem->setForeground(Qt::white);
                listWidget->addItem(colorItem);
            });
        }
    }
}
