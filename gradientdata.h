#ifndef GRADIENTDATA_H
#define GRADIENTDATA_H

#include <QColor>

class GradientData
{
public:
    /** constructor */
    GradientData();

    /** destructor */
    virtual ~GradientData();

    /** asigna stop */
    void setStop(double s)
    {
        m_stop = s;
    }

    /** obtiene stop */
    double stop() const
    {
        return m_stop;
    }

    /** asigna color */
    void setColor(const QColor &c)
    {
        *m_color = c;
    }

    /** obtiene color */
    QColor color() const
    {
        return *m_color;
    }
private:
    double m_stop; //!< stop
    QColor *m_color; //!< color
};

#endif // GRADIENTDATA_H
