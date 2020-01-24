// HelloSFML.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<SFML/Graphics.hpp>

using namespace sf;

//  MAIN
int main()
{
    // video mode object
    VideoMode vm(1900,1000);

    // create and open window for game
    RenderWindow window(vm, "Timber!!!");

    // Create Texture on GPU
    Texture textureBackground;

    // Load background img
    if (!textureBackground.loadFromFile("graphics/background.png"))
    {
        // error
        std::cout << "Did not LOAD" << std::endl;
    }
    std::cout << "wtf is my background!" << std::endl;

    // Create Sprite
    Sprite spriteBackground;

    // attach texture to sprite
    spriteBackground.setTexture(textureBackground);

    // cover the screen
    spriteBackground.setPosition(0, 0);

    // Tree Sprite
    Texture textureTree;
    textureTree.loadFromFile("graphics/tree.png");
    Sprite spriteTree;
    spriteTree.setTexture(textureTree);
    spriteTree.setPosition(810, 0);

    // Bees Buzz
    Texture textureBee;
    textureBee.loadFromFile("graphics/insect.png");
    Sprite spriteBee;
    spriteBee.setTexture(textureBee);
    spriteBee.setPosition(0, 800);
    bool beeActive = false;

    // Bees fly fast
    float beeSpeed = 0.0f;

    // Clouds... 3 from one texture
    Texture textureCloud;
    textureCloud.loadFromFile("graphics/cloud.png");

    Sprite spriteCloud1;
    Sprite spriteCloud2;
    Sprite spriteCloud3;
    spriteCloud1.setTexture(textureCloud);
    spriteCloud2.setTexture(textureCloud);
    spriteCloud3.setTexture(textureCloud);

    // cloud position
    spriteCloud1.setPosition(0,0);
    spriteCloud2.setPosition(0,250);
    spriteCloud3.setPosition(0,500);

    // clouds on screen?
    bool cloud1Active = false;
    bool cloud2Active = false;
    bool cloud3Active = false;

    // cloud speed
    float cloud1Speed = 0.0f;
    float cloud2Speed = 0.0f;
    float cloud3Speed = 0.0f;

    // time lord
    Clock clock;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            // Handle input
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }
        

        /*
        **************************************
        Update Scene
        **************************************
        */

        // measure wibbly wobbly timey wimey
        Time dt = clock.restart();

        // set up bee
        if (!beeActive)
        {
            // how fast is the bee
            srand((int)time(0));
            beeSpeed = (rand() % 200) + 200;

            // how high is the bee
            srand((int)time(0) * 10);
            float height = (rand() % 400) + 500;
            spriteBee.setPosition(-100, height);
            beeActive = true;
        }
        else
        // move the bee
        {
            spriteBee.setPosition(
                spriteBee.getPosition().x +
                (beeSpeed * dt.asSeconds()),
                spriteBee.getPosition().y);

            // has the bee reached the right side of screen
            if (spriteBee.getPosition().x > 2000)
            {
                beeActive = false;
            }
        }

        // set up clouds
        if (!cloud1Active)
        {

            // How fast is the cloud 
            srand((int)time(0) * 10);
            cloud1Speed = (rand() % 200);

            // How high is the cloud 
            srand((int)time(0) * 10);
            float height = (rand() % 150);
            spriteCloud1.setPosition(-200, height);
            cloud1Active = true;


        }
        else
        {
            spriteCloud1.setPosition(
                spriteCloud1.getPosition().x +
                (cloud1Speed * dt.asSeconds()),
                spriteCloud1.getPosition().y);

            // Has the cloud reached the right hand edge of the screen?   
            if (spriteCloud1.getPosition().x > 1920)
            {
                // Set it up ready to be a whole new cloud next frame     
                cloud1Active = false;
            }
        }

            // Cloud 2
            if (!cloud2Active)
            {
                // How fast is the cloud   
                srand((int)time(0) * 20);
                cloud2Speed = (rand() % 200);
                // How high is the cloud   
                srand((int)time(0) * 20);
                float height = (rand() % 300) - 150;
                spriteCloud2.setPosition(-200, height);
                cloud2Active = true;
            }
            else
            {
                spriteCloud2.setPosition(
                    spriteCloud2.getPosition().x +
                    (cloud2Speed * dt.asSeconds()),
                    spriteCloud2.getPosition().y);
                // Has the cloud reached the right hand edge of the screen?   
                if (spriteCloud2.getPosition().x > 1920)
                {
                    // Set it up ready to be a whole new cloud next frame     
                    cloud2Active = false;
                }
            }
        if (!cloud3Active)
        {
            // How fast is the cloud   
            srand((int)time(0) * 30);
            cloud3Speed = (rand() % 200);
            // How high is the cloud   
            srand((int)time(0) * 30);
            float height = (rand() % 450) - 150;
            spriteCloud3.setPosition(-200, height);
            cloud3Active = true;
        }
        else
        {
            spriteCloud3.setPosition(
                spriteCloud3.getPosition().x +
                (cloud3Speed * dt.asSeconds()),
                spriteCloud3.getPosition().y);

            // Has the cloud reached the right hand edge of the screen?   
            if (spriteCloud3.getPosition().x > 1920)
            {
                // Set it up ready to be a whole new cloud next frame     
                cloud3Active = false;
            }
        }

        /*
        *************************************
        Draw Scene
        *************************************
        */

        // Clear last frame
        window.clear();

        // draw scene
        window.draw(spriteBackground);

        // clouds
        window.draw(spriteCloud1);
        window.draw(spriteCloud2);
        window.draw(spriteCloud3);

        // tree
        window.draw(spriteTree);

        // bee
        window.draw(spriteBee);

        // Render screen
        window.display();
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
