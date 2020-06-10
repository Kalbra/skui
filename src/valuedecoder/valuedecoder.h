#ifndef VALUEDECODER_H
#define VALUEDECODER_H
#include <QString>

class ValueDecoder
{
public:
    ValueDecoder();

    static QString Decode(QString str, int value);
};

#endif // VALUEDECODER_H
