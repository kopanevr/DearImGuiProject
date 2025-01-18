#pragma once

#include <vector>

#include "Manager.hpp"
#include "UIElement.hpp"

class UIElementsManager final : Manager
{
private:
    // ЭЛЕМЕНТЫ ИНТЕРФЕЙСА
    std::vector<UIElement*> m_UIElements;

    UIElementsManager() = default;

    UIElementsManager(const UIElementsManager&) = delete;
    UIElementsManager& operator=(const UIElementsManager&) = delete;
public:
    ~UIElementsManager();

    static UIElementsManager* getInstance();

    std::vector<UIElement*>* getUIElements() noexcept
    {
        return &m_UIElements;
    }

    // ЗАПУСК МЕНЕДЖЕРА
    virtual void startUp() override;
    // ОСТАНОВКА МЕНЕДЖЕРА
    virtual void shutDown() override;

    virtual void run() override;

    // ИНИЦИАЛИЗАЦИЯ
    virtual void init() override;
    // ДЕИНИЦИАЛИЗАЦИЯ
    virtual void deinit() override;

    void addElement(UIElement* pElement);

    // ОТРИСОВКА ВСЕХ ЭЛЕМЕНТОВ ИНТЕРФЕЙСА
    void drawAllElements();
};
