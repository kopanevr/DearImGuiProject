#include "SliderUI.hpp"

#include <imgui.h>

SliderUI::SliderUI()
    :   m_sliderParametrs(SliderParameters())
{
}

void SliderUI::draw()
{
    ImGui::SliderFloat(
        m_sliderParametrs.label,
        &m_sliderParametrs.sliderV,
        m_sliderParametrs.sliderVMin,
        m_sliderParametrs.sliderVMax);
}
