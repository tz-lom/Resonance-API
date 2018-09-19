#pragma once

#include "common.h"
#include <QState>

namespace Resonance {
	
class RESONANCE_API ResonanceState: public QState
{
    Q_OBJECT
public:
    ResonanceState(QString name, QState *parent = Q_NULLPTR);
    QString name();

protected:
    QString m_name;

    void onEntry(QEvent *event) override;
};
	
}
