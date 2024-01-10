# Gesture Animations


Gesture animations provide responses to user gestures on an input device, such as a device screen or a touchpad. Typical gestures include swiping, touching, dragging, and pinching. Example gesture animations include the animations that display when you swipe up a page and pinch a picture. The system adopts a seamless animation design. The animation physical engine is used to apply natural phenomena, such as friction, elasticity, and collision effect, to the animation design.


## Overview

Gesture animations are designed to provide a smooth operation feedback between the interaction object and the user's interaction gestures and make the gesture experience more real and feasible by using physical models such as a spring curve. Common gestures are as follows:

- Touch

- Swipe

- Flip

- Pinch

- Drag


## Touch

**Touch** refers to the act of touching on the screen and lifting the finger off the screen. The average duration for touching on the screen is 100 ms to 130 ms. During this period, there is no feedback from the interaction object. To improve the response speed, the **Touch** gesture animation is designed to respond to the touching immediately. This touch response mechanism enhances the visual feedback of interface elements and provides more clues for users to understand the interface.

![4-1-1_touch-(abstract-demo)](figures/4-1-1_touch-(abstract-demo).gif)


## Swipe

**Swipe** refers to the act with a direction and a speed when you slide one or more fingers across a screen. Taking the list view scenario as an example, it consists of the phase of touching the screen, the moment of lifting fingers off the screen, and the phase after lifting fingers off the screen. The phase of touching the screen focuses on the response between the fingers and the object. At the moment of lifting fingers off the screen, the object needs to keep the hand speed to provide animation feedback. The key to the animation design of the **Swipe** gesture is to ensure the consistency between the object's animation feedback and the gesture.

![4-2-1_swipe-(abstract-demo)](figures/4-2-1_swipe-(abstract-demo).gif)


## Flip

**Flip** refers to the acts of flicking and dragging, which are used in the page flipping scenario. Page flipping is to switch object content based on a specified area. After users lift their fingers off the screen, the object is not positioned in a random coordinate and has obvious limit attributes. The page is equivalent to the specified area. If the page flipping failed, the current content will stay. If the page flipping succeeds, the content of the next page or several pages is displayed. Sometimes, out-of-page dragging is used to for prompting in the page flipping scenario.

![4-3-1_flip-(abstract-demo)_4](figures/4-3-1_flip-(abstract-demo)_4.gif)


## Pinch

**Pinch** refers to the act of closing or separating two or more fingers. It is an important manifestation of natural gestures and consists of the phase of touching the screen, the moment of lifting fingers off the screen, and the phase after lifting fingers off the screen. The phase of touching the screen focuses on the response between the fingers and the object. The object needs to provide feedback on gestures such as zooming, rotating, and moving. At the moment of lifting fingers off the screen, the object needs to keep the hand speed to provide animation feedback.

![4-4-1_pinch-(abstract-demo)_2](figures/4-4-1_pinch-(abstract-demo)_2.gif)


## Drag

**Drag** refers to the act of pressing and moving a finger at the same time. The animations design the entire process of state transition of an object by dragging it, including the display-control ratio design during the phase of touching the screen, and object motion curve and attribute change design during the phase after lifting fingers off the screen.

- Title linkage

- Horizontal swiping linkage

- Pull to return


### Title Linkage

The main content area of the object has a linkage design with the title area. When the main content area reaches the top boundary, the drag operation continues. In addition to the damping effect of the main content area due to the out-of-page display and control ratio design, the upper title area and the title area have a linkage design with different damping sensations, making the out-of-page dragging experience more flexible and hierarchical.

![4-5-1_drag-title-linkage-(abstract-demo)_1](figures/4-5-1_drag-title-linkage-(abstract-demo)_1.gif)


### Horizontally Swiping a Widget

Horizontally swiping a widget can expand more functions. The display and control ratio design enables the horizontal dragging gesture to generate a damping effect after a certain distance, which prompts and guides users for subsequent operations.

![4-5-2_drag-widget-horizontal-swipe-(abstract-demo)_1](figures/4-5-2_drag-widget-horizontal-swipe-(abstract-demo)_1.gif)


### Pull to Return

The progressive display and control design is added in the pull-down process, and the increasing damping effect provides users with better experience when dragging an object. The object needs to keep the hand speed to provide animation feedback after users lift their fingers off the screen.

![4-5-3_drag-pull-to-return-(abstract-demo)_1](figures/4-5-3_drag-pull-to-return-(abstract-demo).gif)

 <!--no_check--> 