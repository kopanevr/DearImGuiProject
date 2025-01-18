#pragma once

#include <vector>

#include <imgui.h>

#include "UIElement.hpp"

// ПАРАМЕТРЫ ОКНА
struct WindowParametrs final
{
    float windowPosX = 0.0F;
    float windowPosY = 0.0F;

    float windowSizeX = 0.0F;
    float windowSizeY = 0.0F;

    ImGuiWindowFlags flags = ImGuiWindowFlags_None;

    bool menuBarFlag = false;
};

class WindowUI : public UIElement
{
private:
    const char* m_pTitle;

    WindowParametrs m_windowParameters;

    // ЭЛЕМЕНТЫ
    std::vector<UIElement*> m_UIElements;
public:
    WindowUI(const char* pTitle = "Title");
    ~WindowUI();

    WindowParametrs* getWindowParameters() noexcept
    {
        return &m_windowParameters;
    }

    void draw() override;

    // ДОБАВЛЕНИЕ КОНТЕНТА
    void addWindowContent();

    // ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ
    void addWindowElement(UIElement* pElement);
};
