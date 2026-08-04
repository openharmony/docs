# Developing a Fun-based Widget

<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @Qian-Win-->
<!--Designer: @cx983299475-->
<!--Tester: @mahailong123456-->
<!--Adviser: @HelloShuo-->
<!-- md-trans-meta sourceCommit=a08d450b4f575e3d4749ddeef9dd32275ec0a19e translatedAt=2026-08-03T02:23:30.820Z pushedAt=2026-08-03T02:46:53.138Z -->

Currently, fun-based widgets support mini-games developed with quick games. This kind of widget is in the inactive state by default. When a user taps the widget, it switches to the active state and the game begins. During the game, users can tap the pause icon to pause the game. In the paused state, users can resume the game by tapping the resume icon or end the game by tapping the stop icon.

## Basic Concepts

Fun-based widgets can be in one of the following states: active (game running), paused (game paused), and inactive (game ended).

### Active State

In this state, the widget UI is carried by the mini-game page developed by the widget provider using quick games. The system supports an "overflow" effect, allowing game content to render beyond the widget rendering area.

**Figure 1** Fun-based widget in the active state

![live-form-running-game.gif](figures/live-form-running-game.gif)

### Paused State

In this state, the widget UI is carried by the content in the card provider's `widgetCard.ets`. The system also displays the buttons for continuing and stopping the game on the widget by default.

**Figure 2** Fun-based widget in the paused state

![live-form-pause-game.jpg](figures/live-form-pause-game.jpg)

### Inactive State

In this state, the widget behaves like a common widget, complying with the existing widget development specifications. The widget UI is carried by the content in **widgetCard.ets**.

**Figure 3** Fun-based widget in the inactive state

![live-form-stop-game.jpg](figures/live-form-stop-game.jpg)

## Constraints

1. When a user interacts with the widget, such as tapping, long pressing, or dragging, the interactive response hot zone of the widget is always the same size as the widget's own rendering area. Even if the animation rendering area is larger than the widget's own rendering area, the excess portion only presents UI and does not respond to interaction events.

2. In the active state, interactive events within the widget's rendering area are responded to by the mini-game page developed by the widget provider. In other states, interactive events are responded to by the common widget developed by the widget provider.

3. At a time, only one widget can be in the active or paused state for fun-based interactions. When a user taps a widget to activate it, all other fun-based widgets are automatically switched to the inactive state.

4. For details about other design specifications and restrictions, refer to how to develop a creative widget.

## How to Develop

For details about how to develop game content, refer to how to develop a game widget.

For details about on-device widget configuration and development, see [the configuration of fun-based widgets](arkts-ui-widget-configuration.md#funinteractionparams-field).