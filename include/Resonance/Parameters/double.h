#pragma once

#include "parameter.h"

namespace Resonance {
namespace Parameters {

class RESONANCE_API Double: public Parameter
{
    Q_OBJECT
    Q_PROPERTY(double value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(double minimum READ minimum WRITE setMinimum NOTIFY minimumChanged)
    Q_PROPERTY(double maximum READ maximum WRITE setMaximum NOTIFY maximumChanged)
    Q_PROPERTY(double stepSize READ stepSize WRITE setStepSize NOTIFY stepSizeChanged)
    Q_PROPERTY(int decimals READ decimals WRITE setDecimals NOTIFY decimalsChanged)
public:
    Double();
    Double(QString name, QString group, int index=0);

    double value();

    bool setJSON(QJsonValue value);
    QJsonValue JSON();
    QJsonValue JSONattributes();

    double minimum() const;
    double maximum() const;
    double stepSize() const;
    int decimals() const;

public slots:
    void setValue(double value);
    void setMinimum(double minimum);
    void setMaximum(double maximum);
    void setStepSize(double stepSize);
    void setDecimals(int decimals);

signals:
    void valueChanged();
    void minimumChanged(double minimum);
    void maximumChanged(double maximum);
    void stepSizeChanged(double stepSize);

    void decimalsChanged(int decimals);

private:
    double m_value;
    double m_minimum;
    double m_maximum;
    double m_stepSize;
    int m_decimals;
};

}
}

