#include "sfml_gui.h"


using namespace SFML_GUI;
//using namespace SFML_GUI::GUI_items;


// CONSTRUCT BASE CLASS TO POINT THE TEXTURE CORRECTLY

GUI_Component::GUI_Component (sf::Texture* texture) : sf::Sprite (*texture)
{
    
}
void GUI_Component::setCallBackFunction (void (*cb)()){
    
    this->callbckPtr = cb;
    
}

GUI_Component::~GUI_Component (){
    // no need to delete function pointer
    //https://bytes.com/topic/c/answers/504956-do-you-have-delete-function-pointer
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
            if (this->callbckPtr != nullptr)
                this->callbckPtr();
            
        }
        
        
    }
}

SFML_GUI::Layout::Layout () : sf::Transformable (){
    
    //this->layoutComponents = new GUI_Component[size];
    
    
    
    
}

SFML_GUI::UI_Layouts::MainMenuFlowLayout::MainMenuFlowLayout(int size) : Layout() 
{
    this->menuItemsArray = new GUI_items::MenuItem * [size];
    this->sizeOfItemArray = size;
}

bool SFML_GUI::UI_Layouts::MainMenuFlowLayout::init (){
    
    
    
    return true;
    
}
    
void SFML_GUI::UI_Layouts::MainMenuFlowLayout::update (float&){
    
}
    
void SFML_GUI::UI_Layouts::MainMenuFlowLayout::render (sf::RenderTarget*){
    
}

void SFML_GUI::UI_Layouts::MainMenuFlowLayout::updateInput(float &, sf::Event *){
    
}
bool SFML_GUI::UI_Layouts::MainMenuFlowLayout::AddItem (GUI_Component* item){
    
    
    if (this->currIncrement == this->sizeOfItemArray)
    {
        
        printf ("Size of array is at LIMIT. MainMenuFlowLayout\n");
        return false;
    }
    
    
    
    this->menuItemsArray [this->currIncrement] = (GUI_items::MenuItem *) item;
    this->currIncrement ++;
    
    //We can Position items here
    
    
    return true;
}



SFML_GUI::UI_Layouts::MainMenuFlowLayout::~MainMenuFlowLayout(){
    // delete mah pointers
    
    if (this->menuItemsArray != nullptr)
    {
        for (int i = 0; i < this->sizeOfItemArray; i ++)
        {
            delete this->menuItemsArray [i];
        }
        
        delete this->menuItemsArray;
    }
    
}
