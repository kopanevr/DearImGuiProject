#include "SystemUIManager.hpp"

// ОСНОВНОЙ ЦИКЛ
static void loop();

SystemUIManager* gpSystemUIManager = SystemUIManager::getInstance();

int main([[maybe_unused]] int argc, [[maybe_unused]] const char** argv)
{
    // ЗАПУСК МЕНЕДЖЕРА
    gpSystemUIManager->startUp();

    loop();

    // ОСТАНОВКА МЕНЕДЖЕРА
    gpSystemUIManager->shutDown();

    return 0;
}

// ОСНОВНОЙ ЦИКЛ
void loop()
{
    while (glfwWindowShouldClose(gpSystemUIManager->getWindowManager()->getWindow()) != GLFW_TRUE)
    {
        gpSystemUIManager->run();
    }
}
