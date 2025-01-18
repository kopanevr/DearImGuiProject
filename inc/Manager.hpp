#pragma once

class Manager
{
protected:
    // СОСТОЯНИЕ ЗАПУСКА МЕНЕДЖЕРА
    bool m_StartUpState = false;
private:

public:
    Manager() = default;
    ~Manager() = default;

    // ЗАПУСК МЕНЕДЖЕРА
    virtual void startUp() = 0;
    // ОСТАНОВКА МЕНЕДЖЕРА
    virtual void shutDown() = 0;

    virtual void run() = 0;

    // ИНИЦИАЛИЗАЦИЯ
    virtual void init() = 0;
    // ДЕИНИЦИАЛИЗАЦИЯ
    virtual void deinit() = 0;
};
