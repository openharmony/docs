# Window Overview


## Introduction

The **Window** module provides a mechanism for displaying multiple application UIs and interacting with end users on the same physical screen.

- For application developers, the **Window** module provides APIs for UI display and user interaction.

- For end users, the **Window** module provides a way to control application UIs.

- For the entire operating system, the **Window** module provides logic for application UI management.


## Features

In OpenHarmony, the **Window** module has the following features:

-  **Provides a `Window` object to hold application and system UIs.** You can load the UIs through the window to implement UI display.

-  **Maintains the window relationship (overlay layers and positions).** Different types of application and system windows have different default positions and overlay layers (z-index). End user can adjust the position and overlay layer of a window within a certain range.

-  **Provides window decoration.** Window decoration refers to the title bar and border of a window. The title bar usually provides the Maximize, Minimize, and Close buttons and has the default click behavior. The border enables users to make the window larger or smaller by dragging. Window decoration is the default behavior of OpenHarmony. You can enable or disable window decoration without paying attention to the implementation at the UI code layer.

-  **Provides window animations.** When a window is displayed, hidden, or switched, an animation is usually used to smooth the interaction process. In OpenHarmony, the animation is the default behavior for application windows. You do not need to set or modify the code.

-  **Provides guidance for input event distribution.** Events are distributed based on the window status and focus. Touch and mouse events are distributed based on the window position and size, and keyboard events are distributed to the focused window. You can call APIs provided by the **Window** module to set whether a window is touchable and can gain focus.


## Basic Concepts


### Window Type

In OpenHarmony, the **Window** module provides system windows and application windows.
- A **system window** implements specific functionalities of the system, such as the volume bar, wallpaper, notification panel, status bar, and navigation bar.
- An **application window** is related to the application display. Based on the displayed content, application windows are further classified into main windows and subwindows.
  - A main window shows the application UI and appears on the **Recent tasks** page.
  - A subwindow shows auxiliary windows such as dialog boxes and floating windows of an application. It is not displayed on the **Task Management** page.


### Application Window Mode

The application window mode refers to the display mode of the main window when it is started. Currently, OpenHarmony supports three application window modes: full-screen, split-screen, and free window. This is the multi-window capability.


-  In **full-screen** mode, the main window is displayed on the entire screen when it is started.
-  In **split-screen** mode, the main window occupies part of the screen when it is started, and the other part of the screen is occupied by another window. You can resize the two windows by dragging the split line between them.
-  In **free window** mode, the size and position of the main window can be changed as needed. Multiple free windows can be simultaneously displayed on the screen. These free windows are arranged on the z-axis in the sequence that they are opened or gain the focus. When a free window is clicked or touched, its z-index is incremented and it gains the focus.


![windowMode](figures/windowMode.png)


## Working Principles

The window implementation and development vary according to the application development model, that is, FA model and stage model.

For details about the overall architecture and design ideas of the two models, see [FA Model Overview](../ability/fa-brief.md) and [Stage Model Overview](../ability/stage-brief.md).

You are advised to use the stage model for window development.


## Constraints

-  You cannot develop system windows in the FA model.

-  The main window and subwindow have the following size limits: [320, 2560] in width and [240, 2560] in height, both in units of vp.

-  The system window has the following size limits: [0, 2560] in width and [0, 2560] in height, both in units of vp.
