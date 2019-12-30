project(oop_exercise_08)

set( CMAKE_CXX_FLAGS "-pthread -g " )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

set(sub_proc_head 
  include/processor.hpp
  include/subscriber.hpp
  )

add_library(sub_proc STATIC
  include/processor.cpp
  include/subscriber.cpp
  )

set(figure_head
  include/figure.hpp
  include/point.hpp
  include/square.hpp
  include/rectangle.hpp
  include/triangle.hpp
  )

add_library(figure STATIC
  include/figure.cpp
  include/point.cpp
  include/square.cpp
  include/rectangle.cpp
  include/triangle.cpp
  )


add_executable(main
  src/main.cpp
  )

target_link_libraries(main sub_proc)
target_link_libraries(main figure)
