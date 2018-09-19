#pragma once

#include "common.h"
#include "resonancetransition.h"
#include <functional>

namespace Resonance {

class RESONANCE_API ResonanceTransitionGuarded: public ResonanceTransition
{
    Q_OBJECT
public:
    ResonanceTransitionGuarded(QString name, QState *sourceState, std::function<bool()> guard);

protected:
    bool eventTest(QEvent *e) override;

protected:
	std::function<bool()> m_guard;
};

}
