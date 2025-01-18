#pragma once

#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include "Manager.hpp"
#include "UIElementsManager.hpp"

class UIManager final : public Manager
{
private:
    UIElementsManager* m_gpUIElementsManager;

    UIManager();

    UIManager(const UIManager&) = delete;
    UIManager& operator=(const UIManager&) = delete;

    void beginFrame();
    void endFrame();

    void addAllElements();

#if (IMGUI_USE_DEMO == 1)
    void addAllElementsDemo();
#endif

    void setupStyle();
public:
    ~UIManager();

    static UIManager* getInstance();

    // ЗАПУСК МЕНЕДЖЕРА
    void startUp() override;
    void startUp(GLFWwindow* pWindow);
    // ОСТАНОВКА МЕНЕДЖЕРА
    void shutDown() override;

    void run() override;

    // ИНИЦИАЛИЗАЦИЯ
    void init() override;
    void init(GLFWwindow* pWindow);
    // ДЕИНИЦИАЛИЗАЦИЯ
    void deinit() override;
};
