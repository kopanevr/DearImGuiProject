#include "controller.hpp"

Controller::Controller(Model* pModel, View* pView)
    :   m_pModel(pModel),
        m_pView(pView)
{
}

Controller::~Controller()
{
}

void Controller::update()
{
    m_pView->display(m_pModel);
}
