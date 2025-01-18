#include "WindowUI.hpp"

#include <assert.h>

#include <imgui.h>

WindowUI::WindowUI(const char* pTitle)
    :   m_pTitle(pTitle),
        m_windowParameters(WindowParametrs())
{
}

WindowUI::~WindowUI()
{
    m_pTitle = nullptr;

    for (UIElement* element : m_UIElements)
    {
        delete element;
    }
}

void WindowUI::draw()
{
    // УСТАНОВКА ПОЗИЦИИ
    ImGui::SetNextWindowPos(ImVec2(m_windowParameters.windowPosX, m_windowParameters.windowPosY));

    // УСТАНОВКА РАЗМЕРА
    ImGui::SetNextWindowSize(ImVec2(m_windowParameters.windowSizeX, m_windowParameters.windowSizeY));

    // НАЧАЛО ОКНА
    ImGui::Begin(m_pTitle, nullptr, m_windowParameters.flags);

    if (m_windowParameters.menuBarFlag == true)
    {
        if (ImGui::BeginMenuBar() == true)
        {
            if (ImGui::BeginMenu("Label", false) == true)
            {

                
                ImGui::EndMenu();
            }

            ImGui::EndMenuBar();
        }
    }

    this->addWindowContent();

    // КОНЕЦ ОКНА
    ImGui::End();
}

// ДОБАВЛЕНИЕ КОНТЕНТА
void WindowUI::addWindowContent()
{
    for (UIElement* element : m_UIElements)
    {
        element->draw();
    }
}

// ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ
void WindowUI::addWindowElement(UIElement* pElement)
{
    assert(pElement != nullptr);

    if (pElement != nullptr)
    {
        m_UIElements.push_back(pElement);
    }
}
