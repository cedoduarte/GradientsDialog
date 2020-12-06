#ifndef GRADIENTDIALOG_H
#define GRADIENTDIALOG_H

#include <QDialog>
#include <QLinearGradient>

class GradientScene;
class GradientModel;
class ColorDelegate;
class StopDelegate;

namespace Ui
{
class GradientDialog;
}

class GradientDialog : public QDialog
{
    Q_OBJECT
public:
    /** constructor */
    explicit GradientDialog(QWidget *parent = nullptr);

    /** destructor */
    virtual ~GradientDialog();

    QLinearGradient gradient(double w = 100.0, double h = 100.0) const;
private slots:
    /** agrega stop */
    void on_add_pushButton_clicked();

    /** elimina stop */
    void on_remove_pushButton_clicked();

    /** aceptar diálogo */
    void on_buttonBox_accepted();

    /** cancelar diálogo */
    void on_buttonBox_rejected();
private:
    void init();
    void setup();
    void exampleGradient();

    Ui::GradientDialog *ui; //!< gui
    GradientScene *m_gradientScene; //!< escena de gradiente
    GradientModel *m_gradientModel; //!< modelo de gradiente
    ColorDelegate *m_colorDelegate; //!< delegate de color
    StopDelegate *m_stopDelegate; //!< delegate de stop
};

#endif // GRADIENTDIALOG_H
