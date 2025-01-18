#include "ButtonUI.hpp"

Button::Button()
    :   m_buttonParameters(ButtonParameters())
{
}

void Button::draw()
{
    ImGui::Button(
        m_buttonParameters.label,
        ImVec2(m_buttonParameters.sizeX, m_buttonParameters.sizeY)
    );
}
