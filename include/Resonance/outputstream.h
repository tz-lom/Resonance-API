#pragma once

#include "common.h"
#include <QObject>
#include "streaminfo.h"
#include "datablock.h"
#include "abstractstream.h"

namespace Resonance {

class OutputStreamPrivate;
class RESONANCE_API OutputStream: public AbstractStream
{
    Q_OBJECT
public:
    explicit OutputStream(StreamInfo info, QObject *parent = 0);
    ~OutputStream();

    StreamInfo info();

protected:
    OutputStreamPrivate * const d_ptr;
    Q_DECLARE_PRIVATE(OutputStream)
};

}

