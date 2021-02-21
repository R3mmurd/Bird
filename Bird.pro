QMAKE_CXX=clang++

CONFIG += c++14

QT += core widgets multimedia

SOURCES += \
    audio.C \
    bird.C \
    font.C \
    gamemain.C \
    gamemode.C \
    global.C \
    main.C \
    pipe.C \
    pipepair.C \
    states.C \
    world.C

HEADERS += \
    audio.H \
    bird.H \
    font.H \
    gamemain.H \
    gamemode.H \
    global.H \
    pipe.H \
    pipepair.H \
    states.H \
    world.H \
    statemachine.H \
    singleton.H

RESOURCES += \
    multimedia.qrc

DISTFILES += \
    README.md
