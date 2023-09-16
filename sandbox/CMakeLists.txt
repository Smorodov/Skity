project(sandbox)

include_directories(${CMAKE_CURRENT_LIST_DIR})
# glad
include_directories(../third_party/glad/include)
include_directories(../third_party/glfw/include)

set (UTILS 
../third_party/glad/src/glad.c
gl/gl_app.cc
gl/gl_app.hpp
)

set (SRCS
perf.cc perf.hpp
main.cc
widgets.cc
)

add_executable(sandbox 
${UTILS}
${SRCS}
)
target_link_libraries(sandbox
 skity skity-codec
 glfw 
${CMAKE_DL_LIBS}
)

