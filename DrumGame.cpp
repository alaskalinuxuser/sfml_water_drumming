#include <SFML/Graphics.hpp>
#include <sstream>
#include <SFML/Audio.hpp>

// Declare the functions....
using namespace sf;

// The main process....
int main()
{
	
	
	// What is the game state?
	enum class State {
		FREESTYLE, MEMORY, DEMO
	};
	
	// We will start with the game over state.
	State state = State::FREESTYLE;
	
	// Find the screen resolution
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	
	// And use it to create an SFML window
	RenderWindow window(VideoMode(resolution.x, resolution.y), 
		"Water Drumming!", Style::Fullscreen);
		
	// Create a an SFML View for the main action
	View mainView(FloatRect(0, 0, resolution.x, resolution.y));

	// Time control
	Clock clock;

	// Total runtime of Playing state.
	Time gameTimeTotal;
	
	// Where is the mouse in relation to the virtual world
	Vector2f mouseWorldPosition;
	// Where is the mouse in relation to the real screen
	Vector2i mouseScreenPosition;
	
	// Hide the mouse pointer and replace it with drum hand
	window.setMouseCursorVisible(false);
	Texture textureDrumHand;
	textureDrumHand.loadFromFile("graphics/hand.png");
	Sprite spriteDrumHand;
	spriteDrumHand.setTexture(textureDrumHand);
	spriteDrumHand.setOrigin(100, 100);
	spriteDrumHand.setScale(200/(resolution.x/4),200/(resolution.x/4));
    
    // Create a texture for our background and load it.
    Texture textureBackground;
    textureBackground.loadFromFile("graphics/background.png");
    Sprite spriteBackground;
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setScale(resolution.x/640, resolution.y/480);
    spriteBackground.setPosition(0,0);
    
    // Add our water drum texture.
    Texture textureWaterDrum_still;
    textureWaterDrum_still.loadFromFile("graphics/waterdrum_still.png");
    
    // And the water drums themselves.
    Sprite spriteWD1;
    spriteWD1.setTexture(textureWaterDrum_still);
    spriteWD1.setPosition(resolution.x/15*2,resolution.y/7*2);
    spriteWD1.setScale(.5,.5);
    
    Sprite spriteWD2;
    spriteWD2.setTexture(textureWaterDrum_still);
    spriteWD2.setPosition(resolution.x/15*4,resolution.y/7*4);
    spriteWD2.setScale(.5,.5);
    
    Sprite spriteWD3;
    spriteWD3.setTexture(textureWaterDrum_still);
    spriteWD3.setPosition(resolution.x/15*6,resolution.y/7*2);
    spriteWD3.setScale(.5,.5);
    
    Sprite spriteWD4;
    spriteWD4.setTexture(textureWaterDrum_still);
    spriteWD4.setPosition(resolution.x/15*8,resolution.y/7*4);
    spriteWD4.setScale(.5,.5);
    
    Sprite spriteWD5;
    spriteWD5.setTexture(textureWaterDrum_still);
    spriteWD5.setPosition(resolution.x/15*10,resolution.y/7*2);
    spriteWD5.setScale(.5,.5);
    
    // Add a font.
    Font font;
    font.loadFromFile("fonts/FogSans.ttf");
    
    // Add startText
    Text startText;
    startText.setString("Right click to exit!");
    startText.setCharacterSize(40);
    startText.setColor(Color::White);
    startText.setFont(font);
    // Set position based on center
    FloatRect textRect = startText.getLocalBounds();
    startText.setOrigin(textRect.left + textRect.width / 2.0f,
    textRect.top + textRect.height / 2.0f);
    startText.setPosition(resolution.x / 2.0f,resolution.y / 2.0f);
    
    // Add scoreText
    int scoreInt = 0;
    Text scoreText;
    scoreText.setString("Score = 0");
    scoreText.setCharacterSize(40);
    scoreText.setColor(Color::White);
    scoreText.setFont(font);
    scoreText.setPosition(10,10);    
    
    // Accept keyboard input.
    bool acceptInput = false;    
    
	// Prepare the sounds
	SoundBuffer waterDrumOne;
	waterDrumOne.loadFromFile("sound/waterdrumone.wav");
	Sound drumOne;
	drumOne.setBuffer(waterDrumOne);
	
	SoundBuffer waterDrumTwo;
	waterDrumTwo.loadFromFile("sound/waterdrumtwo.wav");
	Sound drumTwo;
	drumTwo.setBuffer(waterDrumTwo);
	
	SoundBuffer waterDrumThree;
	waterDrumThree.loadFromFile("sound/waterdrumthree.wav");
	Sound drumThree;
	drumThree.setBuffer(waterDrumThree);
	
	SoundBuffer waterDrumFour;
	waterDrumFour.loadFromFile("sound/waterdrumfour.wav");
	Sound drumFour;
	drumFour.setBuffer(waterDrumFour);
	
	SoundBuffer waterDrumFive;
	waterDrumFive.loadFromFile("sound/waterdrumfive.wav");
	Sound drumFive;
	drumFive.setBuffer(waterDrumFive);
	

    while (window.isOpen()) {
		
		
		/* 
		 * 
		 *  Detect input.
		 * 
		 */
		 
			if (Keyboard::isKeyPressed(Keyboard::Escape)) {
				// Escape key is pressed: Exit the window.
				window.close();
			}

			if (acceptInput) {
				
				if (Keyboard::isKeyPressed(Keyboard::Left)) {
					
					acceptInput = false;

				}
				
				
			}
			
			if (Mouse::isButtonPressed(Mouse::Right)) {
				// right mouse button is pressed: exit
				window.close();
			}
			
			Event event;
			while (window.pollEvent(event)) {
				
			}
        
        /* 
		 * 
		 *  Updating the scene.
		 * 
		 */
        
			Time dt = clock.restart();
		
			// Where is the mouse pointer
			mouseScreenPosition = Mouse::getPosition();

			// Convert mouse position to world coordinates of mainView
			mouseWorldPosition = window.mapPixelToCoords(
				Mouse::getPosition(), mainView);
				
			// Set the crosshair to the mouse world location
			spriteDrumHand.setPosition(mouseWorldPosition);
			
		
		/* 
		 * 
		 *  Draw the scene.
		 * 
		 */		
		
			window.clear();
			window.draw(spriteBackground);
			window.draw(spriteWD1);
			window.draw(spriteWD2);
			window.draw(spriteWD3);
			window.draw(spriteWD4);
			window.draw(spriteWD5);
			window.draw(startText);
			window.draw(spriteDrumHand);
			window.display();
		
    }

    return 0;
}
