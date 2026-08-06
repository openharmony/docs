# Glossary

<!--Kit: Game Controller Kit-->
<!--Subsystem: Game-->
<!--Owner: @weixin_42784160-->
<!--Designer: @wudejun2025-->
<!--Tester: @fei_0805-->
<!--Adviser: @luwy2025-->
<!-- md-trans-meta sourceCommit=e5bc67b4e035fae4d3debdff78f31873a4466939 translatedAt=2026-08-03T10:58:41.523Z pushedAt=2026-08-03T10:59:58.274Z -->

## A

### Axis Event

An event type for analog input on a game controller, covering the actions of physical axes such as thumbsticks (LeftThumbstick, RightThumbstick), the D-pad (DPAD), and triggers (LeftTrigger, RightTrigger). Axis events provide continuously varying values to express precise directional and intensity control.

## B

### Button Event

An event type for digital input on a game controller, including the A, B, X, and Y buttons, D-pad (`DPAD`), shoulder buttons (`LeftShoulder`, `RightShoulder`), and trigger buttons (`LeftTrigger`, `RightTrigger`). A button event indicates only two states — press and release — and is used to express discrete control intents.

## D

### Device Monitor

A device status monitoring capability provided by Game Controller Kit. By registering a device monitor callback, you can receive real-time event notifications for device connection (online) and device removal (offline), and query detailed information about all currently online devices.

## G

### Game Device

A peripheral device managed by the game controller service. Each game device has a unique identifier (deviceId), device name, product information, version number, and other properties. Game devices include game controllers and other types.

### Gamepad

A dedicated peripheral input device for gaming that connects to a host device via wired or wireless connections. It includes various physical axes (thumbsticks, triggers) and digital buttons (D-pad, function keys), and is used to send user control commands to the game.