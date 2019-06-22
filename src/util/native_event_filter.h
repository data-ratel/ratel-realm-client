#ifndef NATIVE_EVENT_FILTER_H
#define NATIVE_EVENT_FILTER_H

#include <QAbstractNativeEventFilter>

class NativeEventFilter : public QAbstractNativeEventFilter
{
public:
    bool nativeEventFilter(const QByteArray &eventType, void *message, long *) override;
};

#endif // NATIVE_EVENT_FILTER_H
