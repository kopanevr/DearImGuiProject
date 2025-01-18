#include "CheckBoxUI.hpp"

CheckBox::CheckBox()
    :   m_checkBoxParameters(CheckBoxParameters())
{
}

void CheckBox::draw()
{
    ImGui::Checkbox(
        m_checkBoxParameters.label,
        &m_checkBoxParameters.v
    );
}
