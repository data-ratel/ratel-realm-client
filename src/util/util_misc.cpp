#include "util_misc.h"
#include <dwmapi.h>
#include <windowsx.h>

namespace Util {

enum class Style : DWORD
{
  windowed = ( WS_OVERLAPPEDWINDOW | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_THICKFRAME | WS_CLIPCHILDREN | WS_SYSMENU  ),
  aero_borderless = ( WS_POPUP | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_THICKFRAME | WS_CLIPCHILDREN )
};

void Misc::enableWindowBorderless(qulonglong winId)
{
    HWND hWnd = (HWND)winId;
    SetWindowLongPtr(hWnd, GWL_STYLE, static_cast<LONG>(Style::aero_borderless));

    // enable shadow
    const MARGINS shadow_on = { 1, 1, 1, 1 };
    /*const MARGINS shadow_off = { 0, 0, 0, 0 };*/
    DwmExtendFrameIntoClientArea(hWnd, &shadow_on);

    //redraw frame
    SetWindowPos(hWnd, Q_NULLPTR, 0, 0, 0, 0, SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE);
    ShowWindow(hWnd, SW_SHOW);
}

}
