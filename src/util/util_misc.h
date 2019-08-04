#ifndef UTIL_MISC_H
#define UTIL_MISC_H

#include <QtGlobal>
#include <QObject>
#include <QAbstractNativeEventFilter>

#ifdef Q_OS_WIN
#include "multiscreen_helper/multiscreen_helper.h"
#endif

namespace Util {

#ifdef Q_OS_WIN
enum class Style : DWORD
{
  windowed = (WS_OVERLAPPEDWINDOW | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_THICKFRAME | WS_CLIPCHILDREN),
  aero_borderless = (WS_POPUP | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_THICKFRAME | WS_CLIPCHILDREN)
};
#endif

class Misc
{
public:
    static void enableWindowBorderless(qulonglong wId);

    static void enableHighDpiSupport();

#ifdef Q_OS_WIN
    static QVector<MultiScreenHelper::ScreenInfo> getAllScreenInfo();

    static MultiScreenHelper::ScreenInfo getPrimaryScreenInfo();
#endif
};

}

#endif // UTIL_MISC_H
