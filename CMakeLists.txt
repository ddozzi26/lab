cmake_minimum_required(VERSION 3.25)
project(lab1 CXX)              # ← 프로젝트 이름 변경
set(CMAKE_CXX_STANDARD 17)

find_package(glfw3 CONFIG REQUIRED)
find_package(gl3w  CONFIG REQUIRED)
find_package(glm   CONFIG REQUIRED)

add_executable(lab1             # ← 실행 파일/타깃 이름 변경
  source/main.cpp
)

# ✅ gl3w는 반드시 임포트 타깃으로 링크
if(TARGET gl3w::gl3w)
  target_link_libraries(lab1 PRIVATE gl3w::gl3w)
elseif(TARGET unofficial::gl3w::gl3w)
  target_link_libraries(lab1 PRIVATE unofficial::gl3w::gl3w)
else()
  message(FATAL_ERROR "No imported target for gl3w found. Is gl3w installed via vcpkg?")
endif()

# 나머지도 임포트/공식 타깃으로
target_link_libraries(lab1 PRIVATE glfw glm::glm)

# Windows OpenGL 시스템 라이브러리
if(WIN32)
  target_link_libraries(lab1 PRIVATE opengl32)
endif()
