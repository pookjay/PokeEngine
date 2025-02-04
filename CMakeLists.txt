cmake_minimum_required(VERSION 3.15)
project(ToyEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include(FetchContent)

# --- Force static build for GLEW ---
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build static libraries" FORCE)

# --- GLFW ---
FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG 3.3.8
)
FetchContent_MakeAvailable(glfw)

# --- GLEW (Use a fork that builds "glew" target) ---
FetchContent_Declare(
  glew
  GIT_REPOSITORY https://github.com/Perlmint/glew-cmake.git
  GIT_TAG glew-cmake-2.2.0
)
FetchContent_MakeAvailable(glew)

# --- GLM ---
FetchContent_Declare(
  glm
  GIT_REPOSITORY https://github.com/g-truc/glm.git
  GIT_TAG 0.9.9.8
)
FetchContent_MakeAvailable(glm)

# --- stb_image ---
FetchContent_Declare(
  stb
  GIT_REPOSITORY https://github.com/nothings/stb.git
  GIT_TAG 5736b15
)
FetchContent_MakeAvailable(stb)

# --- Engine Executable ---
add_executable(ToyEngine src/main.cpp)

# For Debug builds
target_link_directories(ToyEngine PRIVATE
  ${glew_BINARY_DIR}/lib/Debug
)

# For Release builds
target_link_directories(ToyEngine PRIVATE
  ${glew_BINARY_DIR}/lib/Release
)

# Include directories
target_include_directories(ToyEngine PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${glm_SOURCE_DIR}
  ${stb_SOURCE_DIR}
  ${glew_SOURCE_DIR}/include
  ${glfw_SOURCE_DIR}/include
)

# Link libraries (FIXED: Use "glew" target)
target_link_libraries(ToyEngine PRIVATE
  glfw
  glewd
  $<$<PLATFORM_ID:Linux>:GL>
  $<$<PLATFORM_ID:Windows>:opengl32>
  $<$<PLATFORM_ID:Darwin>:-framework OpenGL -framework Cocoa>
)

# Define GLEW_STATIC on Windows
if(WIN32)
  target_compile_definitions(ToyEngine PRIVATE GLEW_STATIC)
endif()