# Input Devices and Events
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

Different input devices generate distinct types of basic events, which are triggered only when users interact with specific hardware or tools. These events can be categorized based on the source device and the tool used to initiate the interaction.

- Input device (source type): hardware that produces low-level input events, such as a touchscreen, mouse, touchpad, keyboard, or joystick.
- Input tool (source tool): physical tool used to interact with the input device. For example, a finger or stylus can generate touch events on a touchscreen.
 
In many cases, the input device and tool may be the same. For example, the mouse and keyboard serve as both the device and the tool.

>  **NOTE**
>
> For most interaction scenarios, it is recommended that you use the gesture system rather than handling raw input events directly. Gestures abstract away device-specific differences and provide a unified interaction model.


[Touchscreen input events](./arkts-interaction-development-guide-touch-screen.md): covers touch interactions from touchscreen devices.

[Mouse input events](./arkts-interaction-development-guide-mouse.md): explains mouse-generated events and usage patterns.

[Touchpad input events](./arkts-interaction-development-guide-touchpad.md): explains touchpad-generated events and usage patterns.

[Keyboard input events](./arkts-interaction-development-guide-keyboard.md): explains keyboard-generated events and usage patterns.

[Crown input events](./arkts-common-events-crown-event.md): explains watch crown-generated events and usage patterns.
