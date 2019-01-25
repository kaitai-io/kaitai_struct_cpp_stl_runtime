TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

DEFINES += KS_STR_ENCODING_NONE

HEADERS += $$files(*.h)
SOURCES += $$files(*.cpp)
OTHER_FILES += $$files(*.ksy)

INCLUDEPATH += $$PWD/../../
HEADERS += $$files(../../kaitai/*.h)
SOURCES += $$files(../../kaitai/*.cpp)
