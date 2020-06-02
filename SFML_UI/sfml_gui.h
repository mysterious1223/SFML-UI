/*
 Author: Kevin Singh
 Date: 2020 - 05 - 31
 
 
 */

#pragma once
#ifndef SFML_GUI_H
#define SFML_GUI_H


#include <array>

#include <SFML/Graphics.hpp>


//we should specify function pointers here
typedef void (*callBackFunc)();



// we will place GUI items in here
namespace SFML_GUI {


    



    

    // a base class for all GUI components
    class GUI_Component : public sf::Sprite // ? maybe something else?
    {
        public:
        
            GUI_Component (sf::Texture*);
        
            // init
            virtual bool init () = 0;
            
            // update
            virtual void update (float&) = 0;
            
            // render
            virtual void render(sf::RenderTarget* target) = 0;
            
            // update input
            virtual void updateInput (float&, sf::Event *) = 0;
        
        
            // the code that the component will run
            // function pointer?
            // we can use typedef also with this
            void setCallBackFunction (callBackFunc);
        
        
            ~GUI_Component ();
        
        
        protected:
            bool isClicked;
            //void (*callBackFunc)();
            callBackFunc callbckPtr;
    };


    

    // GUI items
    namespace GUI_items{

    
        // Menu Button inherits traits from GUI comp
        class MenuItem : public GUI_Component
        {
            public:
                MenuItem (sf::Texture*);
                
                    
                bool init ();
                
                // update
                void update (float&);
                
                // render
                void render(sf::RenderTarget* target);
                
                // update input
                // if clicked on it will call the call back function that was specified
                void updateInput (float&, sf::Event *);
        
            
                ~MenuItem(){};
        
            
            
        };
    
    

    }

    // base class for UI Layouts
    // maybe transformable?
    class Layout : public sf::Transformable{
        public:
        
        
        // position
        Layout (const sf::Vector2f &);
            
            // initial
        virtual bool init () = 0;
            
            // Update
        virtual void update (float&) = 0;
        
        // Render
        virtual void render (sf::RenderTarget*) = 0;
        
        // update input
        virtual void updateInput (float&, sf::Event*) = 0;
        
        // add a components (initialize in this class)
        virtual bool AddItem (GUI_Component*) = 0;
        
        protected:
            //GUI_Component layoutComponents [];
            
            
    };

    // Create layouts to hold these components
    namespace UI_Layouts
    {
    
        // we should probably define a base class for this
        class MainMenuFlowLayout : public Layout{
            public:
                // size of layout and position?
                MainMenuFlowLayout (const int,const sf::Vector2f &);
            
                bool init ();
                
                void update (float&);
                
                void render (sf::RenderTarget*);
            
                void updateInput(float &, sf::Event *);
            
                bool AddItem (GUI_Component*);
            
                GUI_items::MenuItem ** getItems () const {return menuItemsArray;}
                int getItemCount () const {return sizeOfItemArray;}
            
                ~MainMenuFlowLayout();
            private:
                // move other elements up
                void rePositionElements ();
            
                // each layout will have an array of types the will hold
                //Stock* stockArrayPointer=new Stock[4]{Stock(args),Stock (args)};
                GUI_items::MenuItem ** menuItemsArray = nullptr;
                int sizeOfItemArray;
                int currIncrement = 0;
                // set the margins for the spacing between each elements
                unsigned margins = 0;
            
                // current offset
                unsigned offset = 0;
            
                
        };
        
    
    
        

    }




}









//void hello (); //{printf ("hello\n");}

#endif // SFML_GUI_H
