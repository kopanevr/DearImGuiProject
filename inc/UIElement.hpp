#pragma once

class UIElement
{
private:

public:
    UIElement() = default;
    virtual ~UIElement() = default;

    virtual void draw() = 0;
};
