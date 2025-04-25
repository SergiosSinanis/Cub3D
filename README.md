# Cub3D

Cub3D is a custom implementation of a raycasting engine inspired by the iconic Wolfenstein 3D game. This project demonstrates fundamental concepts of computer graphics, including raycasting techniques, texture mapping, and game development principles.

## Authors
Cub3D is developed as a team with [Nadia Galleze](https://github.com/Nadzg) as part of the 42 School curriculum, designed to dive into graphics programming, mathematical concepts in 3D rendering, and game engine design.

## Requirements
This project requires the MiniLibX library (Linux) to compile correctly. You must download and place the library in the root directory of the project:
git clone https://github.com/42Paris/minilibx-linux

Note: This project is compatible with Linux systems only.

## Key Features

### Graphics Engine

Raycasting technique for 3D perspective
Textured walls based on orientation
Distance-based shading effects
Floor and ceiling rendering

### Game Controls

Keyboard-based movement (WASD)
Camera rotation using arrow keys
Clean exit on ESC or window close

### Map Parsing & Validation

Custom map format (.cub) support
Texture path configuration
Color definition for floor and ceiling
Map integrity validation

### Visual Elements

Different wall textures for each direction (N, S, E, W)
Dynamic field of view
Collision detection
Consistent frame rate handling

## Usage Examples

### Running the game with a map
./cub3D maps/example.cub

### Map file example

NO ./tiles/NO.xpm
SO ./tiles/SO.xpm
WE ./tiles/WE.xpm
EA ./tiles/EA.xpm

F 139,69,19
C 135,206,250

1111111111111111111111111
1000000000110000000000001
1011000001110000000000001
1001000000000000000000001
100000000000000000000N001
1000000000000000001000001
1111111111111111111111111

## Implementation Notes
This project adheres to strict memory management practices and follows standard graphics programming conventions. The implementation focuses on performance optimization and visual fidelity while maintaining a clean codebase.
