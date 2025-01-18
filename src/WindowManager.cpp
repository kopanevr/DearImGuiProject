#include "WindowManager.hpp"

#include <stdlib.h>
#include <assert.h>

#include <iostream>

#include "WindowManagerConfig.hpp"

#include "debug.hpp"

WindowManager::WindowManager()
    :   m_pWindow(nullptr),
        m_gpUIManager(UIManager::getInstance())
{
}

WindowManager::~WindowManager()
{
    m_pWindow = nullptr;

    m_gpUIManager = nullptr;
}

WindowManager* WindowManager::getInstance()
{
    static WindowManager sInstance;

    return &sInstance;
}

// ЗАПУСК МЕНЕДЖЕРА
void WindowManager::startUp()
{
    if (m_StartUpState == false) // ПРОВЕРКА СОСТОЯНИЯ ЗАПУСКА МЕНЕДЖЕРА
    {
        // ИНИЦИАЛИЗАЦИЯ
        this->init();

        assert(m_pWindow != nullptr);

        if (m_pWindow != nullptr)
        {
            // ЗАПУСК МЕНЕДЖЕРА UIMANAGER
            m_gpUIManager->startUp(m_pWindow);
        }
        else
        {
            // УНИЧТОЖЕНИЕ ОКНА И КОНТЕКСТА
            glfwDestroyWindow(m_pWindow);

            // ЗАВЕРШЕНИЕ GLFW
            glfwTerminate();

            // ЗАВЕРШЕНИЕ РАБОТЫ ПРОГРАММЫ С СОСТОЯНИЕМ EXIT_FAILURE
            exit(EXIT_FAILURE);
        }

        // УСТАНОВКА СОСТОЯНИЯ ЗАПУСКА МЕНЕДЖЕРА
        m_StartUpState = true;

        DEBUG_PRINT("Manager WindowManager has started");
    }
}

// ОСТАНОВКА МЕНЕДЖЕРА
void WindowManager::shutDown()
{
    if (m_StartUpState == true) // ПРОВЕРКА СОСТОЯНИЯ ЗАПУСКА МЕНЕДЖЕРА
    {
        // ОСТАНОВКА МЕНЕДЖЕРА UIMANAGER
        m_gpUIManager->shutDown();

        // ДЕИНИЦИАЛИЗАЦИЯ МЕНЕДЖЕРА
        this->deinit();

        // СБРОС СОСТОЯНИЯ ЗАПУСКА МЕНЕДЖЕРА
        m_StartUpState == false;

        DEBUG_PRINT("Manager WindowManager has stopped");
    }
}

void WindowManager::run()
{
    if (m_StartUpState == true)
    {
        // ОЧИСТКА БУФЕРА
        glClear(GL_COLOR_BUFFER_BIT);

        m_gpUIManager->run();

        // ЗАМЕНА БУФЕРОВ
        glfwSwapBuffers(m_pWindow);

        // ОПРОС И ОБРАБОТКА СОБЫТИЙ
        glfwPollEvents();
    }
}

// ИНИЦИАЛИЗАЦИЯ
void WindowManager::init()
{
    // УСТАНОВКА ФУНКЦИИ ОБРАТНОГО ВЫЗОВА ОШИБКИ
    glfwSetErrorCallback(error_callback);

    assert(glfwInit() == GLFW_TRUE);

    if (glfwInit() != GLFW_TRUE) // ПРОВЕРКА РЕЗУЛЬТАТА ИНИЦИАЛИЗАЦИИ GLFW
    {
        // ЗАВЕРШЕНИЕ РАБОТЫ ПРОГРАММЫ С СОСТОЯНИЕМ EXIT_FAILURE
        exit(EXIT_FAILURE);
    }

    // ЗАПРЕЩЕНИЕ ИЗМЕНЕНИЯ РАЗМЕРА ОКНА
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    // СОЗДАНИЕ ОКНА И КОНТЕСТА
    m_pWindow
    =
    glfwCreateWindow(
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        WINDOW_TITLE,
        nullptr,
        nullptr);

    assert(m_pWindow != nullptr);

    if (m_pWindow == nullptr) // ПРОВЕРКА РЕЗУЛЬТАТА СОЗДАНИЯ ОКНА И КОНТЕКСТА
    {
        // ЗАВЕРШЕНИЕ GLFW
        glfwTerminate();

        // ЗАВЕРШЕНИЕ РАБОТЫ ПРОГРАММЫ С СОСТОЯНИЕМ EXIT_FAILURE
        exit(EXIT_FAILURE);
    }

    // СОЗДАНИЕ ТЕКУЩЕГО КОНТЕКСТА OPENGL
    glfwMakeContextCurrent(m_pWindow);
}

// ДЕИНИЦИАЛИЗАЦИЯ
void WindowManager::deinit()
{
    assert(m_pWindow);

    if (m_pWindow == nullptr)
    {
        // ЗАВЕРШЕНИЕ GLFW
        glfwTerminate();

        // ЗАВЕРШЕНИЕ РАБОТЫ ПРОГРАММЫ С СОСТОЯНИЕМ EXIT_FAILURE
        exit(EXIT_FAILURE);
    }

    // УНИЧТОЖЕНИЕ ОКНА И КОНТЕКСТА
    glfwDestroyWindow(m_pWindow);

    // ЗАВЕРШЕНИЕ GLFW
    glfwTerminate();
}

void WindowManager::error_callback(int error_code, const char* pDescription)
{
    std::cerr << error_code << " " << pDescription << "\n";
}
