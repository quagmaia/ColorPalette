#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>

//header
int main();
sf::Color genRandomColor();
int setUpSprites(sf::Sprite sprites[], sf::Texture textures[]);
void recolorSprites(sf::Sprite sprites[]);
void recolorSprite(sf::Sprite sprite);

//source

const int palSize = 5;

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 600), "Press Any Key To Generate New Palette");

  sf::Texture textures[palSize];
  sf::Sprite sprites[palSize];

  setUpSprites(sprites, textures);


  while (window.isOpen())
  {
    
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
      if (event.type == sf::Event::KeyPressed)
      {
        recolorSprites(sprites);
      }
    }
    
    window.clear(sf::Color::Black);

    for (int i = 0; i < palSize; i++)
    {
      
    }
    
    window.display();

  }

  return 0;
}

sf::Color genRandomColor()
{
  auto r = rand() % 255;
  auto g = rand() % 255;
  auto b = rand() % 255;
  return sf::Color(r, g, b);
}

int setUpSprites(sf::Sprite sprites[], sf::Texture textures[])
{
  for (int i = 0; i < palSize; i++)
  {
    if (!textures[i].create(160, 600)) { return -1; }
    sprites[i].setTexture(textures[i]);
    sprites[i].setPosition(sf::Vector2f(i * 160, 0));
  }
  return 0;
}

void recolorSprites(sf::Sprite sprites[])
{
  for (int i = 0; i < palSize; i++)
  {
    recolorSprite(sprites[i]);
  }
}

void recolorSprite(sf::Sprite sprite)
{
  sprite.setColor(genRandomColor());
}
