QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/Database/databaseCommunicator.cpp \
    src/MainWindowPages/tasksObserver.cpp \
    src/MainWindowPages/tasksTableDelegate.cpp \
    src/globalConstants.cpp \
    src/MainWindowPages/limitedProxyModel.cpp \
    src/App/main.cpp \
    src/AppMainWindow/mainwindow.cpp \
    src/TaskForm/taskForm.cpp \
    src/MainWindowPages/tasksManagementPage.cpp \
    src/MainWindowPages/welcomePage.cpp \
    src/taskData.cpp

HEADERS += \
    src/Database/databaseCommunicator.h \
    src/App/globalConstants.h \
    src/MainWindowPages/limitedProxyModel.h \
    src/AppMainWindow/mainwindow.h \
    src/MainWindowPages/tasksObserver.h \
    src/MainWindowPages/tasksTableDelegate.h \
    src/TaskForm/taskForm.h \
    src/MainWindowPages/tasksManagementPage.h \
    src/MainWindowPages/welcomePage.h \
    src/taskData.h

INCLUDEPATH += \
    src/Database/ \
    src/App/ \ 
    src/MainWindowPages/ \ 
    src/AppMainWindow/ \ 
    src/TaskForm/ \ 
    src/

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
