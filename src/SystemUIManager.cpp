#include "SystemUIManager.hpp"

#include <stdlib.h>
#include <assert.h>

#include <iostream>

#include "debug.hpp"

SystemUIManager::SystemUIManager()
    :   m_gpWindowManager(m_gpWindowManager->getInstance())
{
}

SystemUIManager::~SystemUIManager()
{
    m_gpWindowManager = nullptr;
}

SystemUIManager* SystemUIManager::getInstance()
{
    static SystemUIManager sInstance;

    return &sInstance;
}

// ЗАПУСК МЕНЕДЖЕРА
void SystemUIManager::startUp()
{
    if (m_StartUpState == false) // ПРОВЕРКА СОСТОЯНИЯ ЗАПУСКА МЕНЕДЖЕРА
    {
        // ЗАПУСК МЕНЕДЖЕРА WINDOWMANAGER
        m_gpWindowManager->startUp();

        // УСТАНОВКА СОСТОЯНИЯ ЗАПУСКА МЕНЕДЖЕРА
        m_StartUpState = true;

        DEBUG_PRINT("Manager SystemUIManager has started");
    }
}

// ОСТАНОВКА МЕНЕДЖЕРА
void SystemUIManager::shutDown()
{
    if (m_StartUpState == true) // ПРОВЕРКА СОСТОЯНИЯ ЗАПУСКА МЕНЕДЖЕРА
    {
        // ОСТАНОВКА МЕНЕДЖЕРА WINDOWMANAGER
        m_gpWindowManager->shutDown();

        // СБРОС СОСТОЯНИЯ ЗАПУСКА МЕНЕДЖЕРА
        m_StartUpState = false;

        DEBUG_PRINT("Manager SystemUIManager has stopped");

        std::cin.get();
    }
}

void SystemUIManager::run()
{
    if (m_StartUpState == true) // ПРОВЕРКА СОСТОЯНИЯ ЗАПУСКА МЕНЕДЖЕРА
    {
        m_gpWindowManager->run();
    }
}

// ИНИЦИАЛИЗАЦИЯ
void SystemUIManager::init()
{
}

// ДЕИНИЦИАЛИЗАЦИЯ
void SystemUIManager::deinit()
{
}

void SystemUIManager::checkStateManagers()
{
}
