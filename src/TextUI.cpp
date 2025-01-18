#include "TextUI.hpp"

#include <stdarg.h>
#include <stdio.h>
#include <assert.h>

#include <vector>

#include <imgui.h>

TextUI::TextUI(const char* pFmt, ...)
    :   m_pFmt(pFmt)
{
    va_list args;
    va_start(args, pFmt);

    vsnprintf(m_buffer, sizeof(m_buffer), pFmt, args);

    m_pFmt = m_buffer;

    va_end(args);
}

TextUI::~TextUI()
{
    m_pFmt = nullptr;
}

void TextUI::draw()
{
    ImGui::Text(m_pFmt);
}
