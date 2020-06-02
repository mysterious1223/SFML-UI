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
    
    this->callbckPtr = nullptr;
    
    this->setOrigin(this->getLocalBounds().width/2, this->getLocalBounds().height/2);
    
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

SFML_GUI::Layout::Layout (const sf::Vector2f &pos) : sf::Transformable (){
    
    //this->layoutComponents = new GUI_Component[size];
    
    this->setPosition(pos);
    
    
}

SFML_GUI::UI_Layouts::MainMenuFlowLayout::MainMenuFlowLayout(const int size, const sf::Vector2f &pos) : Layout(pos)
{
    this->menuItemsArray = new GUI_items::MenuItem * [size];
    this->sizeOfItemArray = size;
}

bool SFML_GUI::UI_Layouts::MainMenuFlowLayout::init (){
    
    
    
    return true;
    
}
    
void SFML_GUI::UI_Layouts::MainMenuFlowLayout::update (float&){
    
}
    
void SFML_GUI::UI_Layouts::MainMenuFlowLayout::render (sf::RenderTarget* target)
{
    
    
    
    if (this->menuItemsArray != nullptr)
    {
        for (int i = 0; i < this->sizeOfItemArray; i ++)
        {
            target->draw(*this->menuItemsArray[i]);
        }
        
        
    }
}

void SFML_GUI::UI_Layouts::MainMenuFlowLayout::updateInput(float &dt, sf::Event *event){
    if (this->menuItemsArray != nullptr)
    {
        for (int i = 0; i < this->sizeOfItemArray; i ++)
        {
            this->menuItemsArray[i]->updateInput(dt, event);
        }
        
        
    }
}
bool SFML_GUI::UI_Layouts::MainMenuFlowLayout::AddItem (GUI_Component* item){
    
    
    if (this->currIncrement == this->sizeOfItemArray)
    {
        
        printf ("Size of array is at LIMIT. MainMenuFlowLayout\n");
        return false;
    }
    
    
    // a cast to the GUI Comp to make it a menuitem
    this->menuItemsArray [this->currIncrement] = (GUI_items::MenuItem *) item;
    this->currIncrement ++;
    
    //We can Position items here
    // todo
    
    // re position other elements to move up
    this->rePositionElements();
    // We will position in the center then we will add the relative path to the current position
    
    
    item->setPosition(this->getPosition().x,this->getPosition().y + this->offset);
    
    this->offset += item->getTextureRect().height;
    
    //printf ("component added at x = %f, y = %f\n", item->getPosition().x, item->getPosition().y);
    
    return true;
}
void SFML_GUI::UI_Layouts::MainMenuFlowLayout::rePositionElements ()
{
    
    // make sure there are elements contained
    if (this->currIncrement > 0)
    {
        
        for (int i = 0; i < this->sizeOfItemArray - 1; i ++)
        {
            // this isn't working properly we should fix
            
            //this->menuItemsArray[i]->setPosition(this->menuItemsArray[i]->getPosition().x, this->menuItemsArray[i]->getPosition().y - offset);
            
        }
        
    }
    
    
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
