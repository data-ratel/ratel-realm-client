#include "native_event_filter.h"
#include <Windows.h>
#include <windowsx.h>
#include <QByteArray>

#include <QDebug>

bool NativeEventFilter::nativeEventFilter(const QByteArray &eventType, void *message, long *result)
{
    if (eventType == "windows_generic_MSG") {
        MSG* msg = static_cast<MSG *>(message);

        switch(msg->message) {
        case WM_COMMAND: {
          SendMessage( msg->hwnd, WM_SYSCOMMAND, msg->wParam, msg->lParam );
          *result = DefWindowProc( msg->hwnd, msg->message, msg->wParam, msg->lParam );
          return true;
        }
        case WM_NCCALCSIZE:{
            NCCALCSIZE_PARAMS& params = *reinterpret_cast<NCCALCSIZE_PARAMS*>(msg->lParam);
            if (params.rgrc[0].top != 0)
                params.rgrc[0].top -= 1;

            //this kills the window frame and title bar we added with WS_THICKFRAME and WS_CAPTION
            *result = WVR_REDRAW;
            return true;
        }
        case WM_NCHITTEST: {
            const LONG borderWidth = 8; //in pixels
            RECT winrect;
            GetWindowRect(msg->hwnd, &winrect);
            long x = GET_X_LPARAM(msg->lParam);
            long y = GET_Y_LPARAM(msg->lParam);

            if (x >= winrect.left && x < winrect.right - 120 &&
                    y > winrect.top + borderWidth && y < winrect.top + 40) {
                *result = HTCAPTION;
                return true;
            }
            //bottom left corner
            if (x >= winrect.left && x < winrect.left + borderWidth &&
                y < winrect.bottom && y >= winrect.bottom - borderWidth) {
                *result = HTBOTTOMLEFT;
                return true;
            }
            //bottom right corner
            if (x < winrect.right && x >= winrect.right - borderWidth &&
                y < winrect.bottom && y >= winrect.bottom - borderWidth) {
                *result = HTBOTTOMRIGHT;
                return true;
            }
            //top left corner
            if (x >= winrect.left && x < winrect.left + borderWidth &&
                y >= winrect.top && y < winrect.top + borderWidth) {
                *result = HTTOPLEFT;
                return true;
            }
            //top right corner
            if (x < winrect.right && x >= winrect.right - borderWidth &&
                y >= winrect.top && y < winrect.top + borderWidth) {
                *result = HTTOPRIGHT;
                return true;
            }
            //left border
            if (x >= winrect.left && x < winrect.left + borderWidth) {
                *result = HTLEFT;
                return true;
            }
            //right border
            if (x < winrect.right && x >= winrect.right - borderWidth) {
                *result = HTRIGHT;
                return true;
            }
            //bottom border
            if (y < winrect.bottom && y >= winrect.bottom - borderWidth) {
                *result = HTBOTTOM;
                return true;
            }
            //top border
            if (y >= winrect.top && y < winrect.top + borderWidth) {
                *result = HTTOP;
                return true;
            }
            return false;
        }
        default:
            break;
        }
    }

    return false;
}
