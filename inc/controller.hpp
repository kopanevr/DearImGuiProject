#pragma once

#include "model.hpp"
#include "view.hpp"

class Controller final
{
private:
    Model* m_pModel;
    View* m_pView;
public:
    Controller(Model* pModel, View* pView);
    ~Controller();

    void update();
};
