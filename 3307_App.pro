QT       += core gui charts network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DailyStock.cpp \
    DailyWeather.cpp \
    Date.cpp \
    NewsCategory.cpp \
    NewsRecord.cpp \
    StockCategory.cpp \
    StockRecord.cpp \
    WeatherCategory.cpp \
    WeatherRecord.cpp \
    errorbox.cpp \
    main.cpp \
    mainwindow.cpp \
    newswindow.cpp \
    stockchart.cpp \
    stockwindow.cpp \
    weatherwindow.cpp

HEADERS += \
    CategoryADT.h \
    DailyStock.h \
    DailyWeather.h \
    Date.h \
    NewsCategory.h \
    NewsRecord.h \
    Record.h \
    StockCategory.h \
    StockRecord.h \
    WeatherCategory.h \
    WeatherRecord.h \
    errorbox.h \
    mainwindow.h \
    newswindow.h \
    stockchart.h \
    stockwindow.h \
    weatherwindow.h

FORMS += \
    errorbox.ui \
    mainwindow.ui \
    newswindow.ui \
    stockchart.ui \
    stockwindow.ui \
    weatherwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../.gitignore \
    ../.vscode/settings.json \
    .gitignore

RESOURCES += \
    fonts.qrc
