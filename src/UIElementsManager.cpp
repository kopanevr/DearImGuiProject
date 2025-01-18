#include "UIElementsManager.hpp"

#include <assert.h>

#include <iostream>

#include "debug.hpp"

UIElementsManager::~UIElementsManager()
{
    for (UIElement* element : m_UIElements)
    {
        delete element;
    }
}

UIElementsManager* UIElementsManager::getInstance()
{
    static UIElementsManager sInstance;

    return &sInstance;
}

// ЗАПУСК МЕНЕДЖЕРА
void UIElementsManager::startUp()
{
    if (m_StartUpState == false) // ПРОВЕРКА СОСТОЯНИЯ ЗАПУСКА МЕНЕДЖЕРА
    {
        // УСТАНОВКА СОСТОЯНИЯ ЗАПУСКА МЕНЕДЖЕРА
        m_StartUpState = true;

        DEBUG_PRINT("Manager UIElementsManager has started");
    }
}

// ОСТАНОВКА МЕНЕДЖЕРА
void UIElementsManager::shutDown()
{
    if (m_StartUpState == true) // ПРОВЕРКА СОСТОЯНИЯ ЗАПУСКА МЕНЕДЖЕРА
    {
        // СБРОС СОСТОЯНИЯ ЗАПУСКА МЕНЕДЖЕРА
        m_StartUpState = false;

        DEBUG_PRINT("Manager UIElementsManager has stopped");
    }
}

void UIElementsManager::run()
{
    if (m_StartUpState == true) // ПРОВЕРКА СОСТОЯНИЯ ЗАПУСКА МЕНЕДЖЕРА
    {
    }
}

// ИНИЦИАЛИЗАЦИЯ
void UIElementsManager::init()
{
}

// ДЕИНИЦИАЛИЗАЦИЯ
void UIElementsManager::deinit()
{
}

void UIElementsManager::addElement(UIElement* pElement)
{
    assert(pElement != nullptr);

    if (pElement == nullptr)
    {
        return;
    }

    // ДОБАВЛЕНИЕ ЭЛЕМЕНТА ИНТЕРФЕЙСА
    m_UIElements.push_back(pElement);
}

// ОТРИСОВКА ВСЕХ ЭЛЕМЕНТОВ ИНТЕРФЕЙСА
void UIElementsManager::drawAllElements()
{
    if (m_StartUpState == true) // ПРОВЕРКА СОСТОЯНИЯ ЗАПУСКА МЕНЕДЖЕРА
    {
        for (UIElement* element : m_UIElements)
        {
            // ОТРИСОВКА ЭЛЕМЕНТА ИНТЕРФЕЙСА
            element->draw();
        }
    }
}
