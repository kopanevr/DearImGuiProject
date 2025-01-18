#include "PlotLinesUI.hpp"

#include <math.h>

PlotLines::PlotLines()
    :   m_plotLinesParameters(PlotLinesParameters())
{
}

void PlotLines::draw()
{
    //

    for (int i = 0; i < m_plotLinesParameters.valuesCount; i++)
    {
        m_plotLinesParameters.values[i] = 1.0F * std::sin(i * 0.2F + static_cast<float>(ImGui::GetTime()) * 1.5F);
    }

    //

    ImGui::PlotLines(
        m_plotLinesParameters.label,
        m_plotLinesParameters.values,
        m_plotLinesParameters.valuesCount
    );
}
