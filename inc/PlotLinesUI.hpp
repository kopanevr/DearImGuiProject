#pragma once

#include <imgui.h>

#include "UIElement.hpp"

// ПАРАМЕТРЫ ГРАФИКА
struct PlotLinesParameters final
{
    const char* label = "Label";

    float values[256] = {0.0F};

    int valuesCount = 256;
};

class PlotLines : public UIElement
{
private:
    PlotLinesParameters m_plotLinesParameters;
public:
    PlotLines();
    virtual ~PlotLines() = default;

    PlotLinesParameters* getPlotLinesParameters() noexcept
    {
        return &m_plotLinesParameters;
    }

    virtual void draw() override;
};
