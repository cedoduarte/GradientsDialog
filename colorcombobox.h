#ifndef COLORCOMBOBOX_H
#define COLORCOMBOBOX_H

#include <QWidget>
#include <QStyleOptionComboBox>

class QMenu;
class QListWidget;
class QListWidgetItem;

class ColorComboBox : public QWidget
{
    Q_OBJECT
public:
    /** constructor */
    ColorComboBox(QWidget *parent = nullptr);

    /** destructor */
    virtual ~ColorComboBox();

    /** asigna color */
    void setCurrentColor(const QColor &color);

    /** obtiene color */
    QColor currentColor() const
    {
        return m_currentColor;
    }
signals:
    /** color cambió */
    void currentColorChanged(const QColor &color);
private slots:
    /** color seleccionado */
    void onListWidgetItemClicked(QListWidgetItem *item);
protected:
    /** se pinta el widget */
    void paintEvent(QPaintEvent *e) override;

    /** click del mouse */
    void mousePressEvent(QMouseEvent *e) override;
private:
    /** crea menú */
    QMenu *makeMenu();

    /** crea lista de colores */
    QListWidget *makeListWidget();

    /** crea rect de color */
    QRect makeColorRect() const;

    /** asigna colores */
    void assignColors(QListWidget *listWidget);

    /** crea estilo de combobox */
    QStyleOptionComboBox makeComboBoxStyle();

    QMenu *m_menu; //!< menú
    QColor m_currentColor; //!< color
    QListWidget *m_listWidget; //!< lista de colores
};

#endif // COLORCOMBOBOX_H
