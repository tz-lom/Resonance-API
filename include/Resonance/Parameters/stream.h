#pragma once

#include "parameter.h"
#include <Resonance/inputstream.h>

namespace Resonance {
namespace Parameters {

class RESONANCE_API Stream: public Parameter
{
    Q_OBJECT
    Q_PROPERTY(StreamInfo value READ value NOTIFY valueChanged)
    Q_PROPERTY(InputStream* stream READ stream NOTIFY streamChanged)
public:
    Stream();
    Stream(QString name, QString group, int index=0);

    StreamInfo value();

    bool setJSON(QJsonValue value);
    QJsonValue JSON();

    Resonance::InputStream* stream();

signals:
    void valueChanged(StreamInfo value);
    void streamChanged(InputStream* stream);

private slots:
    void streamClosed();

private:
    StreamInfo m_info;
    InputStream *m_stream;
};

}
}

