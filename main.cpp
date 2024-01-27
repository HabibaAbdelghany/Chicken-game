#include <SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#include <time.h>
using namespace sf;
using namespace std;

int main()
{
    // Create the main window
sf::RenderWindow app(sf::VideoMode(1200, 800), "Shooter");
app.setFramerateLimit(60);
srand(time(0));
 int counter =0;
	CircleShape projectile;
	projectile.setFillColor(Color::Red);
	projectile.setRadius(5.f);
//chicken
	RectangleShape enemy;
    enemy.setSize(Vector2f(50.f, 50.f));
//SHOOTER
	CircleShape player;
	player.setRadius(50.f);
	player.setPosition(app.getSize().x / 2 - player.getRadius(), app.getSize().y - player.getRadius() * 2 - 10.f);
	Vector2f playerCenter;
	//int shootTimer = 0;

     vector<CircleShape> projectiles;
	projectiles.push_back(CircleShape(projectile));


	vector<RectangleShape> enemies;
	enemies.push_back(RectangleShape(enemy));
	int enemyTimer = 0;


Texture background ,shooter,chicken;
//background
background.loadFromFile("background.jpg");

shooter.loadFromFile("spaceshooter.jpg");
chicken.loadFromFile("chicken.jpg");

player.setTexture(&shooter);//shooter
enemy.setTexture(&chicken);//enemy chicken
Sprite sb(background);

// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event ev;
        while (app.pollEvent(ev))
        {



            // Close window : exit

            switch(ev.type){
        case Event::Closed:
            {
               app.close();
            }
break;
        case Event::Resized:
            {
                //resize window
                  cout<<" width: " <<ev.size.width <<" height: " <<ev.size.height <<endl;}
break;





    }
            }
//variable to position
 playerCenter = Vector2f(player.getPosition().x+player.getRadius(), player.getPosition().y + player.getRadius());


//di 7aRKA MOUSE
player.setPosition(Mouse::getPosition(app).x, player.getPosition().y);

    //PROJECTILES
    //SHOOTIN SPACE

if(Keyboard::isKeyPressed(Keyboard::Space))

		{
			projectile.setPosition(playerCenter);
		projectiles.push_back(CircleShape(projectile));


		}
    //SHOOT IN MOUSE
if (Mouse::isButtonPressed(Mouse::Left))
		{
			projectile.setPosition(playerCenter);
		projectiles.push_back(CircleShape(projectile));
		}

for (int  i = 0; i < projectiles.size(); i++)
		{
			projectiles[i].move(0.f, -9.f);


		}


		if(enemyTimer < 10)
		enemyTimer++;

		if (enemyTimer >= 10)
		{
			enemy.setPosition((rand() % int(app.getSize().x - enemy.getSize().x)), 0.f);
			enemies.push_back(RectangleShape(enemy));

			enemyTimer = 0;
		}

		for (int i = 0; i < enemies.size(); i++)
	{
			enemies[i].move(0.f, 5.f);


		}





		if (!enemies.empty() && !projectiles.empty())
		{
			for (int i = 0; i < projectiles.size(); i++)
			{
			for (int k = 0; k < enemies.size(); k++)
				{
					if (projectiles[i].getGlobalBounds().intersects(enemies[k].getGlobalBounds()))
				{
						//projectiles.erase(projectiles.begin() + i);
						enemies.erase(enemies.begin() + k);
						 counter++;
					break;
					}
				}
			}
		}


  app.clear();
  app.draw(sb);
  //app.draw(enemy);
   app.draw(player);

    for(int i =0;i<enemies.size();i++){
        app.draw(enemies[i]);
    }
      for(int i=0 ;i<projectiles.size();i++){
        app.draw(projectiles[i]);
    }
    app.display();



    }

    cout<<"score is :"<<counter <<endl;
    return EXIT_SUCCESS;
}
