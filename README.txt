OOP2 Project: - Geometry Dash (using SFML, Box2D and STL containers)
====================================================================
Programmers: David Weschler & Ron Avital

-----------
Description:
------------ 
In this OOP exercise, we developed a game called "Geometry Dash".
The game is built using C++, SFML, and Box2D.
The objective of the game is to control the movement of an icon through music-based levels, 
navigating while avoiding obstacles such as Spikes and Robots, and sometimes using jump-boosters. 
To win, you must reach the large portal at the end of each level. 
Try to complete as many levels as possible and enjoy the challenge!

-----
Files:
-----
main.cpp: Activates the program

Animations:
Animation(.h + .cpp): Manages and updates the animation of a Robot object based on direction and elapsed time.
AnimationData.h: Stores animation frames for different directions using a map from direction to a list of texture rectangles.
Direction.h Represents the direction for animations, either Right or Left.

Button Command:
Button(.h +.cpp): Represents a clickable button in the UI, with functionality to execute commands, manage appearance, and handle events.
ButtonCommand.h: Abstract base class for defining commands associated with UI buttons.
ChoosePlayerCommand(.h + .cpp): Command class to choose a player in a menu, updating game state accordingly.
ExitCommand(.h + .cpp): Command class to exit the application when associated with a button click.
HowToPlayCommand(.h + .cpp): Command class to navigate through explanations or instructions in a tutorial or help section.
MusicCommand(.h + .cpp): Command class to control background music playback and mute state within a game or application.
NextStateCommand(.h + .cpp): Command class to transition to the next game state within a controller.
UrlCommand(.h + .cpp): Command class to open a specified URL or file using the default program associated with its file type.

Game Object (Folder):
Object(.h + .cpp): Represents a drawable object in the game world with various properties and methods for manipulation and rendering.

	Movables Object (Folder):
	Movable(.h + .cpp): Represents a movable object in the game world with physics properties and methods for manipulation and destruction handling.
	Enemy(.h + .cpp): Represents an enemy object in the game world inheriting from Movable, providing movement functionality specific to enemies.
	Robot(.h + .cpp): Represents a robot enemy in the game world inheriting from Enemy, with movement and animation functionality specific to robots.
	Bullet(.h + .cpp): Represents a bullet object in the game world inheriting from Movable, with movement and destruction handling specific to bullets.
	Player(.h + .cpp): Represents a player object in the game world inheriting from Movable, with various movement states and game mechanics.

	static Object (Folder):
	Static(.h + .cpp): Represents a static object inheriting from Object, initialized with a box-shaped body in the physics world based on specified parameters.
	AirJump(.h + .cpp): Represents an air jump object derived from Static, initialized with specific size and texture settings in the game world.
	AirSpike(.h + .cpp): Represents an airborne spike object derived from Static, with customized size, color, and rotation animation in the game world.
	Arrow(.h + .cpp): Represents an arrow object derived from Static, initialized with a specific texture in the game world.
	Block(.h + .cpp): Represents a block object derived from Static, with multiple color variants registering specific textures in the game world.
	GroundJump(.h + .cpp): Represents ground jump objects derived from Static, with variants distinguished by color registering specific textures and dimensions in the game world.
	LongSpike(.h + .cpp): Represents long spike objects derived from Static, with variants registering specific textures and dimensions in the game world.
	Spike(.h + .cpp): Represents spike objects derived from Static, with variants registering specific textures in the game world based on color.

		Portals (Folder):
		Portal(.h + .cpp): Represents portal objects derived from Static, initializing with specific box dimensions in the game world.
		FinishPortal(.h + .cpp): Represents a finish portal object derived from Portal, specialized for ending game levels with specific dimensions and textures.
		ForwardPortal(.h + .cpp): Represents a forward portal object derived from Portal, specializing in teleportation mechanics with a specific texture.
		GravityPortal(.h + .cpp): Represents a gravity portal object derived from Portal, specializing in altering gravitational mechanics with a specific texture.
		SpaceShipPortal(.h + .cpp): Represents a spaceship portal object derived from Portal, specializing in spaceship teleportation mechanics with a specific texture.
		UpsideSpaceshipPortal(.h + .cpp): Represents an upside-down spaceship portal derived from Portal, specializing in teleportation mechanics with a specific texture.


Moving States (Folder):
MoveState(.h + .cpp): Represents a base class defining movement states for a player object, including methods for movement, rotation, handling spikes, jumps, and kicks.
FlyState(.h + .cpp): Implements flying behavior for a player, including movement and rotation functionalities.
ForwardState(.h + .cpp): Implements forward movement and rotation for a player, including jumping and kicking actions based on game logic.
UpsideDownState: Manages player movement and rotation when upside-down, including jumping and kicking actions based on game mechanics and orientation.
UpsideSpaceshipState(.h + .cpp): Manages player movement and rotation as if upside down, resembling spaceship dynamics.


Screen States (Folder):
ChoosePlayer(.h + .cpp): Manages the state where players choose their character sets from buttons displayed on a menu screen.
Controller(.h + .cpp): Manages the game's main control flow, including handling events, updating game states, and rendering the current state on the screen. It allows switching between different game states such as menu, gameplay, player selection, and statistics display.
Game(.h + .cpp): Manages gameplay mechanics, including player movement, enemy behaviors, bullet firing, and game events like restarts and winning conditions. Uses Box2D for physics and SFML for rendering and audio.
GameState (.h + .cpp): Manages game state abstraction for event handling, updating, rendering, music control, and view management.
HowToPlayState (.h + .cpp): Manages how-to-play instructions with button interactions for navigation and displaying backgrounds and slides.
Menu (.h + .cpp): Manages the main menu interface, including button interactions for game navigation, music control, and external links.
NextLevelWindow: Manages inter-level display, showing stats and options to return to menu or proceed.
Statistics(.h + .cpp): Manages and displays game and player statistics, including attempts, time played, jumps, bullets shot, robots killed, shot accuracy, portals used, and deaths.


Singletones (Folder):
GameEnityFactory.h: A template factory for creating game entities based on colors, utilizing a map of color-to-creation-function mappings for dynamic entity generation.
GlobalConsts.h: Some consts that are being used throughout the program.
MusicManager(.h + .cpp): Manages background music tracks and a shoot sound effect, allowing playback control, track selection, and mute toggling.
TexturesManger(.h + .cpp): Manages loading and access to textures and images for game elements such as buttons, backgrounds, players, objects, bullets, prompts, and animations.


CollisionHandler(.h + .cpp): Handles collisions between game objects using a map-based dispatch system, facilitating interaction logic for players, blocks, spikes, portals, jumps, robots, bullets, and finish portals.
ContactListener(.h + .cpp): Listens for collisions using Box2D physics engine callbacks and triggers collision processing between game objects such as players and blocks.
WorldMap(.h + .cpp): Handles game world setup from an image grid, placing players and various objects using a factory pattern for both movable and fixed entities.

------------------------
Dominant Data Structures:
------------------------ 
In this program, we utilized STL containers and iterators such as vectors, maps, and queues. 
We store the game data in a PNG file, and we implemented a template factory class.

------------------
Notable Algorithms:
------------------
We used many STL algorithms such as remove_if, find, erase, and more.
Additionally, we implemented a shuffle algorithm to randomly display levels using an STL queue.

----------------
Design Overview:
----------------
Design Patterns we implemented: 
-State Pattern: 
	*We used a State pattern in the 'Controller' class to simplify the transition between the different window states (menu, game, help...)
	*We used a state pattern for the players different types of movements (forward state, fly state, upside-down state and upside-down-fly state)
-Singleton: We have a few singleton classes: one for handeling the textures, another for handeling the music.
-Template Factory class: one factory for creating all objects in the game
-Command Pattern: We used a command pattern for the buttons in the game (one button class, each button contains a command)
-Multimethods for handling collisions

Overview:
The Controller class contains an object for each screen state: Menu, Game, ChoosePlayer, HowToPlay, NextLevelWindow, and Statistics. These states inherit from the GameState abstract class.
Object is a base class for all SFML objects in the game. Static and Movable inherit from Object; they serve as base classes for fixed and moving objects in the game, respectively. 
Most fixed objects inherit directly from Static, except for portals, which inherit from a portal base class that, in turn, inherits from Static.

Player and Bullet inherit from Movable, as does Enemy, which is a base class for enemies in the game. Robot inherits from Enemy and contains an Animation object that handles its animation.
Animation utilizes AnimationData and Direction (an enum) to manage the sprite animation.

The Button class contains a ButtonCommand. ButtonCommand is an abstract base class for various button commands (ChoosePlayerCommand, ExitCommand, HowToPlayCommand, NextStateCommand, MusicCommand, URLCommand).
ContactListener inherits from the Box2D class b2ContactListener.
UnknownCollision is a struct that inherits from std::runtime_error.
HandleCollision is a namespace responsible for managing collisions, while WorldMap holds and loads the game map.

Link To game video demo:
https://www.youtube.com/watch?v=Pa6xTSWr5qo&t=3s&ab_channel=DavidWeschler

Known Bugs:

Notes:

Have Fun!
