#pragma once

#include <GLFW/glfw3.h>

#include <stdint.h>

#include "Manager.hpp"
#include "WindowManager.hpp"
#include "UIManager.hpp"

class SystemUIManager final : public Manager
{
private:
    WindowManager* m_gpWindowManager;

    struct 
    {
        uint8_t b1 :   1;
        uint8_t    :   7;
    }
    m_statesManager
    = {
        0b0U};

    SystemUIManager();

    SystemUIManager(const SystemUIManager&) = delete;
	SystemUIManager& operator=(const SystemUIManager&) = delete;
public:
    ~SystemUIManager();

    static SystemUIManager* getInstance();

    WindowManager* getWindowManager() noexcept
    {
        return m_gpWindowManager;
    }

    // ЗАПУСК МЕНЕДЖЕРА
    void startUp() override;
    // ДЕИНИЦИАЛИЗАЦИЯ
    void shutDown() override;

    void run() override;

    // ИНИЦИАЛИЗАЦИЯ
    void init() override;
    // ДЕИНИЦИАЛИЗАЦИЯ
    void deinit() override;

    // ПРОВЕРКА СОСТОЯНИЙ ЗАПУСКА МЕНЕДЖЕРОВ
    void checkStateManagers();
};
