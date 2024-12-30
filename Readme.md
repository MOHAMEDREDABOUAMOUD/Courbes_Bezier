# Bézier Curve Font Project

## Overview
This project is an implementation of Bézier curve-based font rendering using SDL. The program showcases three distinct font styles created with Bézier curves and allows users to interactively explore the results. It uses the SDL library to display letters in multiple windows, either simultaneously or sequentially.

The project is written in C++ and adheres to structured coding practices with Doxygen-compatible comments.

---

## Features

1. **Font Styles**:
   - **Contour**: Displays the glyph describing the contour of the letter in black.
   - **Solid Black**: Fills the inside of the letter with black in addition to the contour.
   - **Red Outline**: Adds a two-pixel red outline around the letter for enhanced visibility.

2. **Display Modes**:
   - **Parallel Mode**: Draws the letter in three separate windows, each showcasing one of the font styles, simultaneously.
   - **Sequential Mode**: Displays all the letters from A to Z in one window, transitioning between them every two seconds.

---

# Usage 
## Run the application:

1. Ensure you have SDL2 installed on your system.
2. Compile the code using the following command:
   ```
   g++ -g -Wall -Wextra -o prog *.cpp $(pkg-config --cflags --libs sdl2) 
   ```
3. run the .exe
    ```
    ./prog
    ```


# Choose Display Mode:

* Parallel Mode:  
---
Uncomment the following line in the source code to render a specific letter (e.g., Q) in three separate windows:
```
lettreSDL.Draw('Q', 40, 50);
```

* Sequential Mode: 
---
Uncomment this line to display all letters sequentially in one window:

```
lettreSDL.Draw2(40, 50);
```
**Note:** Only one mode should be active at a time to avoid conflicts.


