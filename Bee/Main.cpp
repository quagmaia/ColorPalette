#include <SFML/Graphics.hpp>
#include <iostream>

//header
int main();
sf::Color genRandomColor();
void setUpTextures(sf::Texture textures[]);
int setUpSprites(sf::Sprite sprites[], sf::Texture textures[]);
void recolorSprites(sf::Sprite sprites[]);
void recolorSprite(sf::Sprite sprite);

//source

const int palSize = 5;

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 600), "Press Any Key To Generate New Palette");

  sf::Texture textures[palSize];

  setUpTextures(textures);

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
        for (int i = 0; i <= palSize; i++)
        {
          sprites[i].setColor(genRandomColor());
        }
      }
    }
    
//recolorSprites(sprites);

    window.clear(sf::Color::Black);

    for (int i = 0; i < palSize; i++) {
      window.draw(sprites[i]); 
    }
    
    window.display();

  }

  return 0;
}

//helpers

sf::Color genRandomColor()
{
  auto r = rand() % 255;
  auto g = rand() % 255;
  auto b = rand() % 255;
  std::cout << "New color: " << r << " " << g << " " << b << "\n";
  return sf::Color(r, g, b);
}

void setUpTextures(sf::Texture textures[])
{
  for (int i = 0; i < palSize; i++)
  {
    if (!textures[i].loadFromFile("..\\ant.png"))
    {
      //error
    }
  }
  std::cout << "Textures setup complete.\n";
}

int setUpSprites(sf::Sprite sprites[], sf::Texture textures[])
{
  for (int i = 0; i < palSize; i++)
  {
    sprites[i].setTexture(textures[i]);
    sprites[i].setScale(160, 600);
    sprites[i].setPosition(sf::Vector2f(i * 160, 0));
  }
  std::cout << "Sprites setup complete.\n";
  return 0;
}