#pragma once

#include "common.h"
#include <QObject>
#include "streaminfo.h"
#include "datablock.h"
#include "abstractstream.h"

namespace Resonance {

class InputStreamPrivate;
class RESONANCE_API InputStream : public AbstractStream
{
    Q_OBJECT
public:
    explicit InputStream(StreamInfo info, QObject *parent=0);
    ~InputStream();

    StreamInfo info();

    bool isReady();

signals:
    void ready();

private slots:
    void streamReady();
    void streamFailed();
    void tryOpen();
    void discovered(QUrl url);

protected:
    InputStreamPrivate * const d_ptr;
    Q_DECLARE_PRIVATE(InputStream)
};

}

