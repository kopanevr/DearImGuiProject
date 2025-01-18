cmake_minimum_required(VERSION 3.12)
project(DearImGuiIProject)

set(CMAKE_CXX_STANDARD 17)

# IMGUI_STYLE_COLOR – определяет цветовой стиль ImGui (1, 2 или 3)
set(IMGUI_STYLE_COLOR_VALUE 1)
# IMGUI_USE_DEMO – включает или отключает демонстрационное окно ImGui (0 – отключено, 1 – включено)
set(IMGUI_USE_DEMO_VALUE 1)

set(GLFW_DIR lib/glfw)
set(IMGUI_DIR lib/imgui)
set(SRC_DIR src)

find_package(OpenGL REQUIRED)

add_subdirectory(${GLFW_DIR})

set(IMGUI_SOURCES
    "${IMGUI_DIR}/imgui.cpp"
    "${IMGUI_DIR}/imgui_demo.cpp"
    "${IMGUI_DIR}/imgui_draw.cpp"
    "${IMGUI_DIR}/imgui_tables.cpp"
    "${IMGUI_DIR}/imgui_widgets.cpp"
    "${IMGUI_DIR}/backends/imgui_impl_glfw.cpp"
    "${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp")

add_library(ImGui STATIC ${IMGUI_SOURCES})

target_compile_definitions(ImGui PUBLIC IMGUI_STYLE_COLOR=${IMGUI_STYLE_COLOR_VALUE})
target_compile_definitions(ImGui PUBLIC IMGUI_USE_DEMO=${IMGUI_USE_DEMO_VALUE})

file(GLOB SOURCE_FILES
    "${SRC_DIR}/*.c"
    "${SRC_DIR}/*.cpp")

add_executable(DearImGuiIProject ${SOURCE_FILES})

target_include_directories(DearImGuiIProject PUBLIC
    ${GLFW_DIR}/include
    inc)

target_include_directories(ImGui PUBLIC
    ${IMGUI_DIR}
    ${IMGUI_DIR}/backends
    ${GLFW_DIR}/include)

target_link_libraries(DearImGuiIProject OpenGL::GL)

target_link_libraries(DearImGuiIProject ImGui glfw)
