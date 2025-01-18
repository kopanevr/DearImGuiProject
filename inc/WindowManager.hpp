#pragma once

#include <GLFW/glfw3.h>

#include "Manager.hpp"
#include "UIManager.hpp"

class WindowManager final : public Manager
{
private:
    GLFWwindow* m_pWindow;

    UIManager* m_gpUIManager;

    WindowManager();

    WindowManager(const WindowManager&) = delete;
    WindowManager& operator=(const WindowManager&) = delete;

    // ФУНКЦИЯ-ЧЛЕН ОБРАТНОГО ВЫЗОВА ОШИБКИ
    static void error_callback(int error_code, const char* pDescription);
public:
    ~WindowManager();

    static WindowManager* getInstance();

    GLFWwindow* getWindow() noexcept
    {
        return m_pWindow;
    }

    // ЗАПУСК МЕНЕДЖЕРА
    void startUp() override;
    // ОСТАНОВКА МЕНЕДЖЕРА
    void shutDown() override;

    void run() override;

    // ИНИЦИАЛИЗАЦИЯ
    void init() override;
    // ДЕИНИЦИАЛИЗАЦИЯ
    void deinit() override;
};
