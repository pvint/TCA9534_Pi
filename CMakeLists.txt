cmake_minimum_required(VERSION 3.0)
project(TCA9534)

# add flags
#set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -D_BSD_SOURCE -std=c11 -Wall -pedantic -Wextra")
set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -D_BSD_SOURCE -std=c11 -pedantic -lm -lpigpio")



# build
include_directories ("${PROJECT_SOURCE_DIR}/src")
add_executable (tca9534 src/tca9534.c)
target_link_libraries(tca9534)

# install
install(TARGETS tca9534 DESTINATION bin)
