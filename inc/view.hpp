#pragma once

#include "model.hpp"

class View final
{
private:

public:
    View();
    ~View();

    void display(Model* pModel);
};
