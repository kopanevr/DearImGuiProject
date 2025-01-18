#pragma once

#include <imgui.h>

#include "UIElement.hpp"

// ПАРАМЕТРЫ ФЛАЖКИ
struct CheckBoxParameters final
{
    const char* label = "Label";

    bool v = false;
};

class CheckBox : public UIElement
{
private:
    CheckBoxParameters m_checkBoxParameters;
public:
    CheckBox();
    ~CheckBox() = default;

    CheckBoxParameters* getCheckBoxParameters() noexcept
    {
        return &m_checkBoxParameters;
    }

    void draw() override;
};
