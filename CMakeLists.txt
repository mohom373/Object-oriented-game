# CMakeList.txt : CMake project for Ballgame, include source and define
# project specific logic here.
#
cmake_minimum_required(VERSION 3.10.2)
project(Ballgame)
# Använd C++ 17.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
# Välj vilka delar av SFML som ska användas.
set(SFML_MODULES network graphics window system)
# Lägg till lämpliga bibliotek till kompileringen. Man kan använda 'find_package ',
# men det kräver att SFML är installerat på ett annat sätt.
foreach(i ${SFML_MODULES})
    list(APPEND SFML_LIBRARIES "sfml-${i}")
endforeach(i)
# Ange källfiler , lägg till de filer som ni behöver!
set(SOURCE_FILES main.cpp
        State.cpp State.h
        Play_State.cpp Play_State.h
        Entity.cpp Entity.h
        Movable.cpp Movable.h
        Stationary.cpp Stationary.h
        Ball.cpp Ball.h
        Player.cpp Player.h
        Point_Zone.cpp Point_Zone.h
        Dead_Zone.cpp Dead_Zone.h
        Power_Up.cpp Power_Up.h
        Triple_Ball.cpp Triple_Ball.h Constants.h Physics_Object.cpp Physics_Object.h)
# Säg till CMake att skapa en körbar fil som heter 'sfml '.
add_executable(ballgame "${SOURCE_FILES}")
# Länka med biblioteken som vi hittade tidigare.
target_link_libraries(ballgame "${SFML_LIBRARIES}" "${SFML_DEPENDENCIES}")