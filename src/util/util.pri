win{
include($$PWD/multiscreen_helper/multiscreen_helper.pri)
}

HEADERS += \
    $$PWD/native_event_filter.h \
    $$PWD/util_misc.h \
    $$PWD/util_misc_mac.h \
    $$PWD/util_misc_win.h

SOURCES += \
    $$PWD/native_event_filter.cpp \
    $$PWD/util_misc.cpp \
    $$PWD/util_misc_mac.mm \
    $$PWD/util_misc_win.cpp
