#pragma once

#include "common.h"
#include <QObject>
#include "datablock.h"

namespace Resonance {

class RESONANCE_API AbstractStream: public QObject{
	Q_OBJECT
public:
	AbstractStream(QObject *parent);

	virtual StreamInfo info() = 0;
	
signals:
	void sendBlock(DataBlock block);
    void blockReceived(DataBlock block);
};

}
