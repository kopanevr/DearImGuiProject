#include "UIManager.hpp"

#include <assert.h>

#include <iostream>

#include "TextUI.hpp"
#include "SliderUI.hpp"
#include "CheckBoxUI.hpp"
#include "ButtonUI.hpp"
#include "ColorEditUI.hpp"
#include "PlotLinesUI.hpp"
#include "WindowUI.hpp"

#include "debug.hpp"

UIManager::UIManager()
    :   m_gpUIElementsManager(UIElementsManager::getInstance())
{
}

UIManager::~UIManager()
{
    m_gpUIElementsManager = nullptr;
}

UIManager* UIManager::getInstance()
{
    static UIManager sInstance;

    return &sInstance;
}

// ЗАПУСК МЕНЕДЖЕРА
void UIManager::startUp()
{
}

// ЗАПУСК МЕНЕДЖЕРА
void UIManager::startUp(GLFWwindow* pWindow)
{
    assert(pWindow != nullptr);

    if (m_StartUpState == false) // ПРОВЕРКА СОСТОЯНИЯ ЗАПУСКА МЕНЕДЖЕРА
    {
        // ИНИЦИАЛИЗАЦИЯ
        this->init(pWindow);

        // ЗАПУСК МЕНЕДЖЕРА UIELEMETSMANAGER
        m_gpUIElementsManager->startUp();

        // УСТАНОВКА СОСТОЯНИЯ ЗАПУСКА МЕНЕДЖЕРА
        m_StartUpState = true;

        DEBUG_PRINT("Manager UIManager has started");
    }
}

// ОСТАНОВКА МЕНЕДЖЕРА
void UIManager::shutDown()
{
    if (m_StartUpState == true) // ПРОВЕРКА СОСТОЯНИЯ ЗАПУСКА МЕНЕДЖЕРА
    {
        // ОСТАНОВКА МЕНЕДЖЕРА UIELEMETSMANAGER
        m_gpUIElementsManager->shutDown();

        // ДЕИНИЦИАЛИЗАЦИЯ
        this->deinit();

        // СБРОС СОСТОЯНИЯ ЗАПУСКА МЕНЕДЖЕРА
        m_StartUpState = false;

        DEBUG_PRINT("Manager UIManager has stopped");
    }
}

void UIManager::run()
{
    if (m_StartUpState == true) // ПРОВЕРКА СОСТОЯНИЯ ЗАПУСКА МЕНЕДЖЕРА
    {
        this->beginFrame();

        // ОТРИСОВКА ВСЕХ ЭЛЕМЕНТОВ ИНТЕРФЕЙСА
        m_gpUIElementsManager->drawAllElements();

        // USER CODE


        this->endFrame();
    }
}

// ИНИЦИАЛИЗАЦИЯ
void UIManager::init()
{}

// ИНИЦИАЛИЗАЦИЯ
void UIManager::init(GLFWwindow* pWindow)
{
    assert(pWindow != nullptr);

    IMGUI_CHECKVERSION();

    ImGui::CreateContext();

    ImGui_ImplGlfw_InitForOpenGL(pWindow, true);

    ImGui_ImplOpenGL3_Init();

    // НАСТРОЙКА СТИЛЯ
    this->setupStyle();

    // ДОБАВЛЕНИЕ ВСЕХ ЭЛЕМЕНТОВ ИНТЕРФЕЙСА
    this->addAllElements();
}

// ДЕИНИЦИАЛИЗАЦИЯ
void UIManager::deinit()
{
    ImGui_ImplOpenGL3_Shutdown();

    ImGui_ImplGlfw_Shutdown();

    ImGui::DestroyContext();
}

void UIManager::beginFrame()
{
    ImGui_ImplOpenGL3_NewFrame();

    ImGui_ImplGlfw_NewFrame();

    ImGui::NewFrame();
}

void UIManager::endFrame()
{
    ImGui::Render();

    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void UIManager::addAllElements()
{
#if (IMGUI_USE_DEMO == 1)
    this->addAllElementsDemo();
#elif (IMGUI_USE_DEMO == 0)

    // USER CODE


#else
    this->addAllElementsDemo();
#endif
}

#if (IMGUI_USE_DEMO == 1)
void UIManager::addAllElementsDemo()
{
    // ЭЛЕМЕНТ WINDOW ИНТЕРФЕЙСА
    WindowUI* pWindowUI_0 = new WindowUI("Title 0");

    *pWindowUI_0->getWindowParameters()
    = {
        .windowPosX = 20.0F,
        .windowPosY = 20.0F,

        .windowSizeX = 150.0F,
        .windowSizeY = 120.0F,

        .flags
        = 
        ImGuiWindowFlags_NoResize   |
        ImGuiWindowFlags_MenuBar,

        .menuBarFlag = true,
        };

    // ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ ОКНА
    pWindowUI_0->addWindowElement(new TextUI("%d Text 0", 0));

    // ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ ОКНА
    pWindowUI_0->addWindowElement(new TextUI("%d Text 1", 0));


    // ЭЛЕМЕНТ WINDOW ИНТЕРФЕЙСА
    WindowUI* pWindowUI_1 = new WindowUI("Title 1");

    *pWindowUI_1->getWindowParameters()
    = {
        .windowPosX = 410.0F,
        .windowPosY = 20.0F,

        .windowSizeX = 210.0F,
        .windowSizeY = 440.0F,

        .flags = ImGuiWindowFlags_NoResize};

    // ЭЛЕМЕНТ ПОЛЗУНОК ИНТЕРФЕЙСА
    SliderUI* pSliderUI_0 = new SliderUI();

    *pSliderUI_0->getSliderParametrs()
    = {
        .label = "Slider 0",
        .sliderV = 0.5F,
        .sliderVMin = 0.0F,
        .sliderVMax = 1.0F};

    // ЭЛЕМЕНТ ПОЛЗУНОК ИНТЕРФЕЙСА
    SliderUI* pSliderUI_1 = new SliderUI();

    *pSliderUI_1->getSliderParametrs()
    = {
        .label = "Slider 1",
        .sliderV = 0.5F,
        .sliderVMin = 0.0F,
        .sliderVMax = 1.0F};

    // ЭЛЕМЕНТ ПОЛЗУНОК ИНТЕРФЕЙСА
    SliderUI* pSliderUI_2 = new SliderUI();

    *pSliderUI_2->getSliderParametrs()
    = {
        .label = "Slider 2",
        .sliderV = 0.5F,
        .sliderVMin = 0.0F,
        .sliderVMax = 1.0F};

    // ЭЛЕМЕНТ ПОЛЗУНОК ИНТЕРФЕЙСА
    SliderUI* pSliderUI_3 = new SliderUI();

    *pSliderUI_3->getSliderParametrs()
    = {
        .label = "Slider 3",
        .sliderV = 0.5F,
        .sliderVMin = 0.0F,
        .sliderVMax = 1.0F};

    // ЭЛЕМЕНТ ПОЛЗУНОК ИНТЕРФЕЙСА
    SliderUI* pSliderUI_4 = new SliderUI();

    *pSliderUI_4->getSliderParametrs()
    = {
        .label = "Slider 4",
        .sliderV = 0.5F,
        .sliderVMin = 0.0F,
        .sliderVMax = 1.0F};

    // ЭЛЕМЕНТ ПОЛЗУНОК ИНТЕРФЕЙСА
    SliderUI* pSliderUI_5 = new SliderUI();

    *pSliderUI_5->getSliderParametrs()
    = {
        .label = "Slider 5",
        .sliderV = 0.5F,
        .sliderVMin = 0.0F,
        .sliderVMax = 1.0F};

    // ЭЛЕМЕНТ ПОЛЗУНОК ИНТЕРФЕЙСА
    SliderUI* pSliderUI_6 = new SliderUI();

    *pSliderUI_6->getSliderParametrs()
    = {
        .label = "Slider 6",
        .sliderV = 0.5F,
        .sliderVMin = 0.0F,
        .sliderVMax = 1.0F};

    // ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ ОКНА
    pWindowUI_1->addWindowElement(new TextUI("%d Text 0", 0));

    // ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ ОКНА
    pWindowUI_1->addWindowElement(new TextUI("%d Text 1", 0));

    // ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ ОКНА
    pWindowUI_1->addWindowElement(pSliderUI_0);

    // ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ ОКНА
    pWindowUI_1->addWindowElement(new TextUI("%d Text 2", 0));

    // ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ ОКНА
    pWindowUI_1->addWindowElement(new TextUI("%d Text 3", 0));

    // ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ ОКНА
    pWindowUI_1->addWindowElement(pSliderUI_1);

    // ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ ОКНА
    pWindowUI_1->addWindowElement(new TextUI("%d Text 4", 0));

    // ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ ОКНА
    pWindowUI_1->addWindowElement(new TextUI("%d Text 5", 0));

    // ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ ОКНА
    pWindowUI_1->addWindowElement(pSliderUI_2);

    // ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ ОКНА
    pWindowUI_1->addWindowElement(new TextUI("%d Text 6", 0));

    // ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ ОКНА
    pWindowUI_1->addWindowElement(new TextUI("%d Text 7", 0));

    // ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ ОКНА
    pWindowUI_1->addWindowElement(pSliderUI_3);

    // ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ ОКНА
    pWindowUI_1->addWindowElement(new TextUI("%d Text 8", 0));

    // ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ ОКНА
    pWindowUI_1->addWindowElement(new TextUI("%d Text 9", 0));

    // ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ ОКНА
    pWindowUI_1->addWindowElement(pSliderUI_4);

    // ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ ОКНА
    pWindowUI_1->addWindowElement(new TextUI("%d Text 10", 0));

    // ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ ОКНА
    pWindowUI_1->addWindowElement(new TextUI("%d Text 11", 0));

    // ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ ОКНА
    pWindowUI_1->addWindowElement(pSliderUI_5);

    // ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ ОКНА
    pWindowUI_1->addWindowElement(new TextUI("%d Text 12", 0));

    // ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ ОКНА
    pWindowUI_1->addWindowElement(new TextUI("%d Text 13", 0));

    // ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ ОКНА
    pWindowUI_1->addWindowElement(pSliderUI_6);


    // ЭЛЕМЕНТ WINDOW ИНТЕРФЕЙСА
    WindowUI* pWindowUI_2 = new WindowUI("Title 2");

    *pWindowUI_2->getWindowParameters()
    = {
        .windowPosX = 20.0F,
        .windowPosY = 160.0F,

        .windowSizeX = 370.0F,
        .windowSizeY = 300.0F,

        .flags = ImGuiWindowFlags_NoResize};

    // ЭЛЕМЕНТ ЦВЕТОВОЙ РЕДАКТОР ИНТЕРФЕЙСА
    ColorEdit* pColorEdit_0 = new ColorEdit();

    *pColorEdit_0->getColorEditParametrs()
    = {
        .label = "ColorEdit 0"
    };

    // ЭЛЕМЕНТ ФЛАЖОК ИНТЕРФЕЙСА
    CheckBox* pCheckBox_0 = new CheckBox();

    *pCheckBox_0->getCheckBoxParameters()
    = {
        .label = "CheckBox 0"
    };

    // ЭЛЕМЕНТ КНОПКА ИНТЕРФЕЙСА
    Button* pButton_0 = new Button();

    *pButton_0->getButtonParameters()
    = {
        .label = "Button 0"
    };

    // ЭЛЕМЕНТ КНОПКА ИНТЕРФЕЙСА
    Button* pButton_1 = new Button();

    *pButton_1->getButtonParameters()
    = {
        .label = "Button 1"
    };

    // ЭЛЕМЕНТ ГРАФИК ИНТЕРФЕЙСА
    PlotLines* pPlotLines = new PlotLines();

    *pPlotLines->getPlotLinesParameters()
    = {
        .label = "PlotLines 0"
    };

    // ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ ОКНА
    pWindowUI_2->addWindowElement(new TextUI("%d Text 0", 0));

    // ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ ОКНА
    pWindowUI_2->addWindowElement(new TextUI("%d Text 1", 0));

    // ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ ОКНА
    pWindowUI_2->addWindowElement(pColorEdit_0);

    // ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ ОКНА
    pWindowUI_2->addWindowElement(pCheckBox_0);

    // ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ ОКНА
    pWindowUI_2->addWindowElement(pButton_0);

    // ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ ОКНА
    pWindowUI_2->addWindowElement(pButton_1);

    // ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ ОКНА
    pWindowUI_2->addWindowElement(new TextUI("%d Text 2", 0));

    // ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ ОКНА
    pWindowUI_2->addWindowElement(new TextUI("%d Text 3", 0));

    // ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ ОКНА
    pWindowUI_2->addWindowElement(pPlotLines);


    // ДОБАВЛЕНИЕ ЭЛЕМЕНТА WINDOW ИНТЕРФЕЙСА
    m_gpUIElementsManager->addElement(pWindowUI_0);

    // ДОБАВЛЕНИЕ ЭЛЕМЕНТА WINDOW ИНТЕРФЕЙСА
    m_gpUIElementsManager->addElement(pWindowUI_1);

    // ДОБАВЛЕНИЕ ЭЛЕМЕНТА WINDOW ИНТЕРФЕЙСА
    m_gpUIElementsManager->addElement(pWindowUI_2);
}
#endif

void UIManager::setupStyle()
{
    ImGuiStyle& style = ImGui::GetStyle();

    style.WindowRounding = 3.0F;
    style.FrameRounding = 1.0F;
    style.ScrollbarRounding = 1.0F;
    style.GrabRounding = 1.0F;

#if (IMGUI_STYLE_COLOR == 1)
    ImGui::StyleColorsClassic();
#elif (IMGUI_STYLE_COLOR == 2)
    ImGui::StyleColorsLight();
#elif (IMGUI_STYLE_COLOR == 3)
    ImGui::StyleColorsDark();
#else
    ImGui::StyleColorsDark();
#endif
}
