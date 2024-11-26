# cub3D - Ray-Casting Game Project

## Project Purpose
The `cub3D` project is inspired by the iconic first-person shooter **Wolfenstein 3D**, the first FPS game ever developed. This project aims to introduce and explore **ray-casting** principles by building a dynamic first-person view inside a maze, where the player navigates through walls and avoids obstacles.

## What is Ray-Casting?
Ray-casting is a rendering technique used in early 3D games to create a pseudo-3D perspective. It involves casting rays from the player's viewpoint and calculating intersections with walls to determine their position and render them accordingly.


## Project Requirements and Conditions
The project requirements are as follows:

- Implement a first-person perspective rendering using **miniLibX** library.
- Display different wall textures depending on wall direction.
- Set distinct colors for floor and ceiling.
- Take a **.cub** file as input to configure the map layout, wall textures, and colors.
- The program should run smoothly and handle window management seamlessly (minimizing, closing, etc.).
- Use specific controls for player movement and interactions.

![Intro](https://github.com/roma-sh/Cub3D/blob/master/textures/intro.png)

## Development Steps

### 1. Validate the Map
Check if the map meets all requirements:
- Must be fully enclosed by walls.
- Only specific characters allowed: `0` for empty space, `1` for walls, and `N`, `S`, `E`, `W` for player start positions with orientation.

### 2. Initialize miniLibX Library
Set up **miniLibX** for window creation, graphics rendering, and handling keyboard events.

### 3. Parse Information from the Map File
Parse map information from the **.cub** file to extract wall textures, floor and ceiling colors, and map layout.

### 4. Divide the Window into Blocks
Render each section of the window as a block based on the map structure and set the player's initial position.

![Blocks](https://github.com/roma-sh/Cub3D/blob/master/images/block.png)

### 5. Calculate Ray Distances
Calculate ray distances for vertical and horizontal lines, determining where rays intersect with walls and selecting the shortest distance.

![Rays](https://github.com/roma-sh/Cub3D/blob/master/images/raycasting.png)

### 6. Render Walls
Render the walls wherever a ray hits by calculating the wall height and applying the appropriate texture based on the wall's direction.

![Game](https://github.com/roma-sh/Cub3D/blob/master/images/game.png)

### 7. Draw the Minimap
Render a minimap in the upper left corner of the screen, showing the player's position within the map.

### 8. Additional Details
Add extra UI elements like a crosshair, weapon graphics, and a health bar for a more immersive experience.

## Game Controls
- **Move Forward**: `W`
- **Move Backward**: `S`
- **Move Left**: `A`
- **Move Right**: `D`
- **Rotate Left**: Left Arrow
- **Rotate Right**: Right Arrow
- **Sprint**: Shift
- **Exit Game**: ESC

## Fire Hazard Feature
Avoid stepping into the fire area! If the player enters a fire zone, they will lose health, and a red flash will blink on the screen as a warning.

## Running the Game
To compile and run the game:

1. Compile the project with:
   ```bash
   make
   ```
2. Run the game:
   ```bash
   ./cub3D map.cub
   ```
