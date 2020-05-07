cmake_minimum_required(VERSION 3.15)


project(CVector)



set(CMAKE_CXX_STANDARD 14)



add_executable(CVector main.cpp CVector.cpp CVector0.cpp CVector1.cpp CVector.hpp CVector0.hpp CVector1.hpp CVectorfactory.hpp CVector0factory.cpp CVector1factory.cpp CVector0factory.hpp CVector1factory.hpp functions.cpp functions.hpp autotests.cpp autotests.hpp)