#pragma once

#include <imgui.h>

#include "UIElement.hpp"

// ПАРАМЕТРЫ ЦВЕТОВОГО РЕДАКТОРА
struct ColorEditParameters final
{
    const char* label = "Label";

    [[maybe_unused]]
    float col[4]
    = {
        1.0F,
        0.0F,
        0.0F,
        1.0F};

    ImGuiColorEditFlags flags = ImGuiColorEditFlags_None;
};

class ColorEdit : public UIElement
{
private:
    ColorEditParameters m_colorEditParameters;
public:
    ColorEdit();
    ~ColorEdit() = default;

    ColorEditParameters* getColorEditParametrs() noexcept
    {
        return &m_colorEditParameters;
    }

    void draw() override;
};
