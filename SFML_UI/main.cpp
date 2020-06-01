
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// In order to load the resources like cute_image.png, you have to set up
// your target scheme:
//
// - Select "Edit Scheme…" in the "Product" menu;
// - Check the box "use custom working directory";
// - Fill the text field with the folder path containing your resources;
//        (e.g. your project folder)
// - Click OK.
//

#include "sfml_gui.h"

void print ()
{
    
    printf ("TESTING CB\n");
}


int main(int argc, char const** argv)
{
    
    ///SFML_GUI::foo f;
    
    
    sf::Texture myTexture;
    myTexture.loadFromFile("/Volumes/Andromeda/Programming Projects/Current Working Projects/SFML/SFML_UI/SFML_UI/Assets/icon.png");
    
    SFML_GUI::GUI_items::MenuItem *button1 = new SFML_GUI::GUI_items::MenuItem(&myTexture);
    SFML_GUI::GUI_items::MenuItem *button2 = new SFML_GUI::GUI_items::MenuItem(&myTexture);
    
    SFML_GUI::GUI_items::MenuItem *button3 = new SFML_GUI::GUI_items::MenuItem(&myTexture);
    
    button1->setCallBackFunction(print);
    
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1280, 760), "SFML window");


    button1->setPosition(100, 100);
    button2->setPosition(300, 300);
    
    
    SFML_GUI::UI_Layouts::MainMenuFlowLayout * myLayout = new SFML_GUI::UI_Layouts::MainMenuFlowLayout (2);
    
    
    myLayout->AddItem(button1);
    myLayout->AddItem(button2);
    //myLayout->AddItem(button3);
    /*
    for (int i = 0; i < myLayout->getItemCount(); i ++)
    {
        printf ("%s\n", myLayout->getItems()[i]->test_string.c_str());
    }
    */
    sf::Clock clock;
    
    // Start the game loop
    while (window.isOpen())
    {
        sf::Time time = clock.restart();
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            float dt = time.asSeconds();
            button1->updateInput(dt, &event);
            
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        // Clear screen
        window.clear(sf::Color::Red);

        button1->render(&window);
        button2->render(&window);
        // Draw UI stuff here?
      
        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
