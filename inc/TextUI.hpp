#pragma once

#include <stdarg.h>

#include "UIElement.hpp"

class TextUI : public UIElement
{
private:
    const char* m_pFmt;

    char m_buffer[32];
public:
    TextUI(const char* pFmt = "fmt", ...);
    ~TextUI();

    void draw() override;
};
