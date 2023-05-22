cmake_minimum_required(VERSION 3.20)
project(Assignment_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Assignment_1 main.cpp CTIS.cpp CTIS.h User.cpp User.h Patient.cpp Patient.h CentreOfficer.cpp CentreOfficer.h CovidTest.cpp CovidTest.h TestCentre.cpp TestCentre.h TestKit.cpp TestKit.h main.h)
