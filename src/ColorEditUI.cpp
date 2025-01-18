#include "ColorEditUI.hpp"

ColorEdit::ColorEdit()
    :   m_colorEditParameters(ColorEditParameters())
{
}

void ColorEdit::draw()
{
    ImGui::ColorEdit4(
        m_colorEditParameters.label,
        m_colorEditParameters.col,
        m_colorEditParameters.flags
    );
}
