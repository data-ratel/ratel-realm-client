#ifndef UTIL_MISC_H
#define UTIL_MISC_H

#include <QtGlobal>
#include <QObject>
#include <Windows.h>
#include <QAbstractNativeEventFilter>
namespace Util {

enum class Style : DWORD
{
  windowed = (WS_OVERLAPPEDWINDOW | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_THICKFRAME | WS_CLIPCHILDREN),
  aero_borderless = (WS_POPUP | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_THICKFRAME | WS_CLIPCHILDREN)
};

class Misc
{
public:
    static void enableWindowBorderless(qulonglong wId);
};

}

#endif // UTIL_MISC_H
