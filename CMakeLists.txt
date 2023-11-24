cmake_minimum_required(VERSION 2.8)
project(3DEDGE_NANO)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -pthread ")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread ")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
endif()

set(CMAKE_CXX_FLAGS "${C_CXX_FLAGS_DEFAULT} ${CMAKE_CXX_FLAGS} --std=c++17 ")



#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

find_package(Eigen3 REQUIRED)
include_directories( SYSTEM
  	${CMAKE_CURRENT_SOURCE_DIR}
  	${EIGEN3_INCLUDE_DIR}
  	${PROJECT_SOURCE_DIR}/include
  	${GTKMM_INCLUDE_DIRS}

)


#configuration for openCV
find_package( OpenCV REQUIRED )

find_package (PkgConfig REQUIRED)
find_package(Threads)
pkg_search_module(GTKMM REQUIRED gtkmm-3.0)

include_directories(SYSTEM
  ${GTKMM_INCLUDE_DIRS}
  ${SIGCPP_INCLUDE_DIRS}
  ${X11_INCLUDE_DIRS})

add_executable( app 
		src/app.cpp
		src/parameters.cpp
		src/drone.cpp
		src/gui.cpp
		src/joystick.cpp
		src/joystick_linux.cpp
		src/video_widget.cpp
		src/status_button.cpp
		src/axis_widget.cpp
		src/LRFB_widget.cpp
		src/rotate_widget.cpp
		src/throttle_widget.cpp
		
		) 

target_link_libraries(app ${OpenCV_LIBS}  ${GTKMM_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})



