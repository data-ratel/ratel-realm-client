#ifndef UTIL_MISC_H
#define UTIL_MISC_H

#include <QtGlobal>
#include <Windows.h>

namespace Util {

class Misc
{
public:
    static void enableWindowBorderless(qulonglong winId);

private:
    static LRESULT CALLBACK WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam );
};

}

#endif // UTIL_MISC_H
