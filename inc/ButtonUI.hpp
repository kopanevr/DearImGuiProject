#pragma once

#include <imgui.h>

#include "UIElement.hpp"

// ПАРАМЕТРЫ КНОПКИ
struct ButtonParameters final
{
    const char* label = "Label";

    float sizeX = 0.0F;
    float sizeY = 0.0F;
};

class Button : public UIElement
{
private:
    ButtonParameters m_buttonParameters;
public:
    Button();
    ~Button() = default;

    ButtonParameters* getButtonParameters() noexcept
    {
        return &m_buttonParameters;
    }

    void draw() override;
};
