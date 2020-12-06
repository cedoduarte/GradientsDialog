#include "gradientscene.h"
#include "gradientmodel.h"
#include <QComboBox>

GradientScene::GradientScene(QObject *parent)
    : QGraphicsScene(parent)
{
    m_gradientModel = nullptr;
    m_resolutionComboBox = nullptr;
}

void GradientScene::setGradientModel(GradientModel *model)
{
    if (model)
    {
        m_gradientModel = model;
        connect(m_gradientModel, &GradientModel::rowsInserted, this, &GradientScene::paintGradient);
        connect(m_gradientModel, &GradientModel::rowsRemoved, this, &GradientScene::paintGradient);
        connect(m_gradientModel, &GradientModel::dataChanged, this, &GradientScene::paintGradient);
    }
    else
    {
        if (m_gradientModel)
        {
            disconnect(m_gradientModel, &GradientModel::rowsInserted, this, &GradientScene::paintGradient);
            disconnect(m_gradientModel, &GradientModel::rowsRemoved, this, &GradientScene::paintGradient);
            disconnect(m_gradientModel, &GradientModel::dataChanged, this, &GradientScene::paintGradient);
            m_gradientModel = nullptr;
        }
    }
}

void GradientScene::setResolutionComboBox(QComboBox *combo)
{
    if (combo)
    {
        m_resolutionComboBox = combo;
        connect(m_resolutionComboBox, &QComboBox::currentIndexChanged, this, &GradientScene::paintGradient);
    }
    else
    {
        if (m_resolutionComboBox)
        {
            disconnect(m_resolutionComboBox, &QComboBox::currentIndexChanged, this, &GradientScene::paintGradient);
            m_resolutionComboBox = combo;
        }
    }
}

void GradientScene::paintGradient()
{
    if (!m_resolutionComboBox)
    {
        return;
    }
    if (!m_gradientModel)
    {
        return;
    }
    QSize resolution = m_resolutionComboBox->currentData().toSize();
    QLinearGradient g = m_gradientModel->gradient(resolution);
    setBackgroundBrush(QBrush(g));
}
