cmake_minimum_required(VERSION 3.10.0)
project(world VERSION 0.1.0 LANGUAGES C CXX)

add_executable(world Confederation.cpp main.cpp MemberOfMonarchFamily.cpp Minister.cpp Monarchy.cpp Parlamentman.cpp Person.cpp President.cpp PresidentRepublic.cpp RandomGenerator.cpp Republic.cpp State.cpp World.cpp)

