#include "gradientdata.h"

GradientData::GradientData()
{
    m_stop = 0.0;
    m_color = new QColor;
}

GradientData::~GradientData()
{
    delete m_color;
}
