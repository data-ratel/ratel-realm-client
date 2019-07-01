#include "util_misc.h"
#include <dwmapi.h>
#include <Windows.h>
#include <windowsx.h>
#include <QByteArray>
#include <QGuiApplication>

namespace Util {

void Misc::enableWindowBorderless(qulonglong wId)
{
    HWND wnd = (HWND)wId;
    // enable borderless and keep aero effects.
    SetWindowLongPtr(wnd, GWL_STYLE, static_cast<LONG>(Style::aero_borderless));

    // enable shadow
    const MARGINS shadow_on = { 1, 1, 1, 1 };
    /*const MARGINS shadow_off = { 0, 0, 0, 0 };*/
    DwmExtendFrameIntoClientArea(wnd, &shadow_on);

    //redraw frame
    SetWindowPos(wnd, Q_NULLPTR, 0, 0, 0, 0, SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE);
    ShowWindow(wnd, SW_SHOW);
}

}
