# Window Manager Overview

The Window Manager subsystem provides basic capabilities of window management. It is the basis for UI display.
The Window Manager subsystem enables multiple applications to simultaneously display on the same screen and interact with users. For each application, you need to design the interaction interface in the fixed window area. A window acts as a display container of the application UI, and the Window Manager subsystem organizes the interaction UIs into a form visible to end users.

## Basic Concepts


**Immersive**: The colors of the application UI, status bar, and navigation bar are the same to achieve the visual integrity.

## Working Principles

To display a UI on a screen, the application and system need to request a window object from the Window Manager subsystem. This object generally represents a rectangular area on the screen and has attributes such as the position, width, height, and overlay layer. The object also loads the root node of the UI framework, through which the application UI is loaded and displayed in the window.
