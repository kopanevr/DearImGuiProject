#pragma once

#include "UIElement.hpp"

// ПАРАМЕТРЫ ПОЛЗУНКА
struct SliderParameters final
{
    const char* label = "Label";

    float sliderV = 0.0F;

    float sliderVMin = 0.0F;
    float sliderVMax = 0.0F;
};

class SliderUI : public UIElement
{
private:
    SliderParameters m_sliderParametrs;
public:
    SliderUI();
    ~SliderUI() = default;

    SliderParameters* getSliderParametrs() noexcept
    {
        return &m_sliderParametrs;
    }

    void draw() override;
};
