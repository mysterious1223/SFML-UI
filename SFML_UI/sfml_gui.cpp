#include "sfml_gui.h"


using namespace SFML_GUI;
//using namespace SFML_GUI::GUI_items;
/*
foo::foo ()
{
    
    printf ("test\n");
}


void hello () {printf ("hello\n");}
 
 */

// CONSTRUCT BASE CLASS TO POINT THE TEXTURE CORRECTLY

GUI_Component::GUI_Component (sf::Texture* texture) : sf::Sprite (*texture)
{
    
}
void GUI_Component::setCallBackFunction (void (*cb)()){
    
    this->callBackFunc = cb;
    
}

// MENU BUTTON DEF

SFML_GUI::GUI_items::MenuItem::MenuItem (sf::Texture* texture) : GUI_Component (texture)
{
    if (!this->init ())
    {
        
    }
}
    

bool SFML_GUI::GUI_items::MenuItem::init ()
{
    this->isClicked = false;
    return true;
}

// update
void SFML_GUI::GUI_items::MenuItem::update (float&)
{
    
}

// render
void SFML_GUI::GUI_items::MenuItem::render(sf::RenderTarget* target)
{
    target->draw(*this);
}

// update input
void SFML_GUI::GUI_items::MenuItem::updateInput (float&, sf::Event * event)
{
    if (event->type == sf::Event::MouseButtonPressed)
    {
        float mX = event->mouseButton.x;
        float mY = event->mouseButton.y;
        
        if (this->getGlobalBounds().contains(mX, mY))
        {
            this->isClicked = true;
            // we will need to eventually handle reseting
            if (this->callBackFunc != nullptr)
                this->callBackFunc();
            
        }
        
        
    }
}
