#pragma once

#include "parameter.h"

namespace Resonance {
namespace Parameters {

class RESONANCE_API Integer: public Parameter
{
    Q_OBJECT
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(int minimum READ minimum WRITE setMinimum NOTIFY minimumChanged)
    Q_PROPERTY(int maximum READ maximum WRITE setMaximum NOTIFY maximumChanged)
    Q_PROPERTY(int stepSize READ stepSize WRITE setStepSize NOTIFY stepSizeChanged)
public:
    Integer();
    Integer(QString name, QString group, int index=0);

    int value();

    bool setJSON(QJsonValue value);
    QJsonValue JSON();
    QJsonValue JSONattributes();

    int minimum() const;
    int maximum() const;
    int stepSize() const;

public slots:
    void setValue(int value);
    void setMinimum(int minimum);
    void setMaximum(int maximum);
    void setStepSize(int stepSize);

signals:
    void valueChanged(int);
    void minimumChanged(int minimum);
    void maximumChanged(int maximum);
    void stepSizeChanged(int stepSize);

private:
    int m_value;
    int m_minimum;
    int m_maximum;
    int m_stepSize;
};

}
}

