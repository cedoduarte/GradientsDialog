#ifndef GRADIENTSCENE_H
#define GRADIENTSCENE_H

#include <QGraphicsScene>

class GradientModel;
class QComboBox;

class GradientScene : public QGraphicsScene
{
    Q_OBJECT
public:
    GradientScene(QObject *parent = nullptr);    
    void setGradientModel(GradientModel *model);
    void setResolutionComboBox(QComboBox *combo);
private slots:
    void paintGradient();
private:
    GradientModel *m_gradientModel;
    QComboBox *m_resolutionComboBox;
};

#endif // GRADIENTSCENE_H
