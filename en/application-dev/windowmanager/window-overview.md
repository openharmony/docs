# Window Overview

<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @Pakoo007-->
<!--Designer: @ki_ja-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=60de8413603f482ca3f2f3e5e2f5d285ba767ebe translatedAt=2026-08-11T10:12:47.846Z pushedAt=2026-08-12T02:23:51.805Z -->

## Introduction

The Window module provides a mechanism for displaying multiple application UIs and allowing the end user to interact with them on the same physical screen.

- For application developers, the Window module provides APIs for UI display and user interaction.

- For end users, the Window module provides a way to control application UIs.

- For the entire operating system, the Window module provides logic for application UI management.

## Features

The Window module has the following features:

- **Provides a window object to hold app and system UIs.** You can load your app UIs through the window to display them to the end user.

- **Maintains the window relationship (overlay layers and positions).** Apps and system windows come in multiple types, each with different default positions and overlay layers (z-index). End users can also adjust the window position and overlay layers within a certain range.

- **Provides window decoration.** Window decoration refers to the title bar and border of a window. The title bar usually provides the **Maximize**, **Minimize**, and **Close** buttons and has the default click behavior for user convenience. The border allows the user to drag to resize the window. Window decoration is the default system behavior. You can choose to enable or disable it without concerning yourself with the UI code implementation.

- **Provides window animations.** When a window is displayed, hidden, or switched, the window module usually adds animation effects to smooth the interaction process. In OpenHarmony, window animations for apps are the default behavior, and no setup or modification is required.

- **Provides guidance for input event distribution.** Events are distributed based on the current window status or focus. Touch and mouse events are distributed based on the window position and size, while keyboard events are distributed to the focused window. You can use the APIs provided by the window module to set whether a window is touchable and whether it can receive focus.

## Working Principles

The window implementation and development vary according to the application development model, which can be FA model or stage model.

For details about the overall architecture and design philosophy of the two models, see [Application Model](../application-models/stage-model-development-overview.md).

You are advised to use the stage model for window development.

## Constraints

-  You cannot develop system windows in the FA model.

-  The window size is restricted by [WindowLimits](../reference/apis-arkui/arkts-apis-window-i.md#windowlimits11), determined by product configurations. If [setWindowLimits](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowlimits11) has not been called, you can use [getWindowLimits](../reference/apis-arkui/arkts-apis-window-Window.md#getwindowlimits11) to obtain the system's default limits, measured in px.