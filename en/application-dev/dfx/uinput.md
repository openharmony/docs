# uinput

<!--Kit: Input Kit-->
<!--Subsystem: MultimodalInput-->
<!--Owner: @zhaoxueyuan-->
<!--Designer: @hanruofei-->
<!--Tester: @Lyuxin-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=120b60d9b776e943724c636f3e7aa06338260cf8 translatedAt=2026-07-31T01:36:09.847Z pushedAt=2026-07-31T08:34:12.415Z -->

uinput can simulate operations on devices such as the mouse, keyboard, and touchpad for pressure tests like stability tests.

## Environment Setup

- The [environment setup](hdc.md#environment-setup) is complete.

- The devices are properly connected and **hdc shell** is executed.

## Features

**Usage**

```bash
uinput <option> <command> <arg> ...
```

**Available Commands**

| Abbreviation | Full Command  | Description       | 
| -------- | --------   | --------       |
| -M       | --mouse    | Injects a mouse event. | 
| -K       | --keyboard | Injects a keyboard event. |
| -S       | --stylus   | Injects a stylus event.| 
| -T       | --touch    | Injects a touch event. |
| -P       | --touchpad | Injects a touchpad event.|
| -?       | --help     | Displays the help information.     | 
| enable_key_status | enable_key_status | [Controls the injected modifier key status](#controlling-the-injected-modifier-key-status).| 

> **NOTE**
>
> All coordinate-related parameters in commands use px as the unit. For details, see [Pixel Units](../reference/apis-arkui/arkui-ts/ts-pixel-units.md).

## Help Command

Displays the commands supported by uinput.

**Command**

```bash
uinput -? 
uinput --help
```

**Example**

```bash
# Display the help information.
uinput -? 

# Execution result.
Usage: uinput <option> <command> <arg>...
The options are:
-K  --keyboard
commands for keyboard:
-d <key>                   --down   <key>     -press down a key
-u <key>                   --up     <key>     -release a key
-l <key> [long press time] --long_press <key> [long press time] -press and hold the key
-r <key> [repeat output time] --repeat output <key> [repeat output time] -press and hold the key
-i <time>                  --interval <time>  -the program interval for the (time) milliseconds

...

```

## Mouse Events

Simulates mouse move and click events.

### Mouse Move Event

Simulates a mouse movement to the coordinates (dx, dy) in a relative coordinate system whose origin is the upper left corner of the specified screen.

**Command**

```bash
uinput -M -m <dx> <dy>
uinput --mouse --move <dx> <dy>

# <dx> and <dy> are coordinates in the relative coordinate system with the upper-left corner of the screen as the origin.
```

**Example**

```bash
# Simulate a mouse movement to the coordinates (100, 100) in a relative coordinate system whose origin is the upper left corner of the specified screen.
uinput -M -m 100 100
```

**Extended Commands**

```bash
uinput -M -m <dx1> <dy1> <dx2> <dy2> [smooth time] --trace
uinput --mouse --move <dx1> <dy1> <dx2> <dy2> [smooth time] --trace

# <dx1> and <dy1> are coordinates of the start point in the relative coordinate system with the upper left corner of the screen as the origin.
# <dx2> and <dy2> are coordinates of the end point in the relative coordinate system with the upper left corner of the screen as the origin.
# The --trace option can be used to simulate the movement position and trace of the mouse to the coordinates in a relative coordinate system whose origin is the upper left corner of the specified screen.
# [smooth time] specifies the moving time, in milliseconds. The default value is 1000. The value range is [1,15000]. The value must be an integer.
```

**Example**

```bash
# Move a mouse pointer from (100, 100) to (200, 200) for 1500 ms.
uinput -M -m 100 100 200 200 1500 --trace
```

### Mouse Down Event

Simulates a mouse button press. You are advised to use this event together with the mouse up event to close the event. For details about values of **buttonId**, see [Mouse Buttons](#mouse-buttons).

**Command**

```bash
uinput -M -d <buttonId>
uinput --mouse --down <buttonId>
```

### Mouse Up Event

Simulates a mouse button release. You are advised to use this event together with the mouse down event to close the event. For details about values of **buttonId**, see [Mouse Buttons](#mouse-buttons).

**Command**

```bash
uinput -M -u <buttonId>
uinput --mouse --up <buttonId>
```

**Example**

```bash
# Simulate pressing and releasing the left mouse button.
uinput -M -d 0 -u 0
```

### Click Event

Simulates a mouse click. For details about values of **buttonId**, see [Mouse Buttons](#mouse-buttons).

**Command**

```bash
uinput -M -c <buttonId>
uinput --mouse --click <buttonId>
```

**Example**

```bash
# Simulate clicking the left mouse button.
uinput -M -c 0
```

### Double-Click Event

Simulates a double-click on the mouse button. For details about values of **buttonId**, see [Mouse Buttons](#mouse-buttons).

**Command**

```bash
uinput -M -b <dx> <dy> <buttonId> [press time] [click interval time]
uinput --mouse --double_click <dx> <dy> <buttonId> [press time] [click interval time]

# <dx> and <dy> are coordinates in the relative coordinate system with the upper-left corner of the screen as the origin.
# [press time] specifies the initial press time, in milliseconds. The default value is 50. The value is an integer between 1 and 300. This parameter is optional.
# [click interval time] specifies the click interval, in milliseconds. The default value is 300. The value is an integer between 1 and 450. This parameter is optional.
```

**Example**

```bash
# Simulate a double-click on the left mouse button at (100, 150).
uinput -M -b 100 150 0 10 10
```

### Mouse Scroll Event

Simulates a forward or backward scrolling of the mouse wheel. This event must be used together with the mouse move event.

**Command**

```bash
uinput -M -m <dx1> <dy1> -s <number>
uinput --mouse --move <dx1> <dy1> --scroll <number>

# <dx1> and <dy1> are coordinates in the relative coordinate system with the upper-left corner of the screen as the origin.
# <number> specifies the number of scrolling notches. A positive value indicates scrolling backward, and a negative value indicates scrolling forward. One notch is 15.
```

**Example**

```bash
# Simulate a mouse movement to the coordinates (100, 200) in a relative coordinate system with the upper-left corner of the specified screen as the origin. Then, scroll the mouse wheel backward for three notches.
uinput -M -m 100 200 -s 45
```

### Mouse Drag Event

Simulates a mouse dragging.

**Command**

```bash
uinput -M -g <dx1> <dy1> <dx2> <dy2> [total time]
uinput --mouse --drag <dx1> <dy1> <dx2> <dy2> [total time]

# <dx1> and <dy1> are coordinates of the start point in the relative coordinate system with the upper left corner of the screen as the origin.
# <dx2> and <dy2> are coordinates of the end point in the relative coordinate system with the upper left corner of the screen as the origin.
# [total time] specifies the total drag time, in milliseconds. The default value is 1000. The value must be an integer between 1 and 15000. This parameter is optional.
```

**Example**

```bash
# Simulate clicking the left mouse button and dragging from (200, 650) to (500, 300) over 15000 ms, and then releasing the button.
uinput -M -g 200 650 500 300 15000
```

### Mouse Event Interval

Sets the interval between mouse events, in milliseconds. This command must be used with other mouse event commands. Otherwise, this command is invalid.

**Command**

```bash
uinput -M -i <time>
uinput --mouse --interval <time>

# <time> specifies the mouse event interval, in milliseconds. The value must be an integer between 1 and 15000.
```

**Example**

```bash
# Set the interval between two simulated click events to 500 ms.
uinput -M -c 0 -i 500 -c 0
```

### Mouse Buttons

| buttonId |  Description|
| -------- | -------- |
| 0  | Left mouse button.  |
| 1  | Right mouse button.  |
| 2  | Middle mouse button.  |
| 3  | Side mouse button.|
| 4  | Extended mouse button.|
| 5  | Mouse forward button.|
| 6  | Mouse back button.|
| 7  | Mouse task button.|

### Querying Mouse Pointer Information

Queries the current mouse pointer information.

If the mouse cursor is visible, the cursor display state and [PointerStyle](../reference/apis-input-kit/js-apis-pointer.md#pointerstyle) are output. If the `filePath` parameter is passed and the mouse cursor uses an app-defined custom style (style enumeration value -100), the cursor style image is saved to the specified file in binary format. You must create the `filePath` file beforehand. If the `filePath` parameter is not passed, the style image is not saved. When the mouse cursor is hidden, no style information is output and no style image is saved.

**Command**

```bash
uinput -M -q [filePath]

# [filePath] specifies the path for saving the pointer style image file. This parameter is optional. The current version supports only the file save path in the /data/local/tmp/ directory, for example, /data/local/tmp/testfile.
```

**Example**

```bash
# Query the visible status and style ID of the current mouse pointer.
uinput -M -q

# Query the visible status and style ID of the current mouse pointer, and write the mouse pointer style image in binary format to the /data/local/tmp/testfile file.
touch /data/local/tmp/testfile
uinput -M -q /data/local/tmp/testfile
```

## Keyboard Events

Simulates a keyboard input event.

### Key Down Event

Simulates a key press on the keyboard. It is recommended to use this together with the key up event to ensure event closure. For keyCode, see [@ohos.multimodalInput.keyCode (Keycode)](../reference/apis-input-kit/js-apis-keycode.md).

**Command**

```bash
uinput -K -d <keyCode>
uinput --keyboard --down <keyCode>
```

### Key Up Event

Simulates a key release on the keyboard. This must be used together with the key down event to ensure event closure. For keyCode, see [@ohos.multimodalInput.keyCode (Keycode)](../reference/apis-input-kit/js-apis-keycode.md).

**Command**

```bash
uinput -K -u <keyCode>
uinput --keyboard --up <keyCode>
```

**Example**

```bash
# Simulate pressing and releasing the A key.
uinput -K -d 2017 -u 2017
```

### Long-Press Key Event

Simulates pressing a key on the keyboard and releasing it after a specified duration, without needing to inject a key up event again. During the long press, press events are not repeatedly injected. For keyCode, see [@ohos.multimodalInput.keyCode (Keycode)](../reference/apis-input-kit/js-apis-keycode.md).

**Command**

```bash
uinput -K -l <keyCode> [long press time]
uinput --keyboard --long_press <keyCode> [long press time]

# [long press time] specifies the long press duration, in milliseconds. The default value is 3000. The value must be an integer between 3000 and 15000. This parameter is optional.
```

**Example**

```bash
# Simulate pressing and holding the A key for 6000 ms, and then releasing the key.
uinput -K -l 2017 6000
```

### Repeat Key Event

Simulates pressing a key on the keyboard, continuously injecting press events for a specified duration, and then releasing the key, without needing to inject a key up event again. During the long press, press events are repeatedly injected. For keyCode, see [@ohos.multimodalInput.keyCode (Keycode)](../reference/apis-input-kit/js-apis-keycode.md).

**Command**

```bash
uinput -K -r <keyCode> [repeat output time]
uinput --keyboard --repeat <keyCode> [repeat output time]

# [repeat output time] specifies the duration during which key press events are repeatedly reported, in milliseconds. The value must be an integer ranging from 3000 to 15000. The default value is 3000. This parameter is optional.
```

**Example**

```bash
# Simulate pressing the A key and repeating the press within 4000 ms.
uinput -K -r 2017 4000
```

### Keyboard Event Interval

Sets the interval between keyboard events, in milliseconds. This command must be used with other keyboard event commands. Otherwise, this command is invalid.

**Command**

```bash
uinput -K -i <time>
uinput --keyboard --interval <time>

# <time> specifies the keyboard event interval, in milliseconds. The value must be an integer between 1 and 15000.
```

**Example**

```bash
# Simulate pressing and holding the A key for 500 ms and then releasing the key.
uinput -K -d 2017 -i 500 -u 2017
```

### Keyboard Text Event

Simulates text input using the keyboard. This command cannot be used together with other commands. Only a maximum of 2000 ASCII characters are supported.

**Command**

```bash
uinput -K -t <text>
uinput --keyboard --text <text>
```

**Example**

```bash
# Simulate inputting a text "Hello, World!".
uinput -K -t Hello,World!
```

## Controlling the Injected Modifier Key Status

Starting from API version 22, you can enable or disable the capability of controlling the injected modifier key status. The supported modifier keys include: KEYCODE_ALT_LEFT, KEYCODE_ALT_RIGHT, KEYCODE_SHIFT_LEFT, KEYCODE_SHIFT_RIGHT, KEYCODE_CTRL_LEFT, KEYCODE_CTRL_RIGHT, KEYCODE_META_LEFT, and KEYCODE_META_RIGHT. For details, see [@ohos.multimodalInput.keyCode (Keycode)](../reference/apis-input-kit/js-apis-keycode.md).

### Enabling the Capability of Controlling the Injected Modifier Key Status

You can enable the capability of controlling the injected modifier key status and set the duration. This command must be used together with the key down event. After the capability of controlling the injected modifier key status is enabled, you can specify the duration of the key down event. After the duration ends, the key up event is automatically triggered.

**Command**

```bash
uinput enable_key_status <enable> [duration]

# <enable> specifies whether to enable the capability of controlling the injected modifier key status. The value can be 1 or 0. The value 1 means to enable the capability, and 0 means the opposite.
# [duration] specifies the duration of the injected modifier key status, in seconds. The default value is 10. The value must be an integer ranging from [1,10].
```

**Example**

```bash
# Enable the capability of controlling the injected modifier key status and do not set the duration of the injected modifier key status. The injected **KEYCODE_SHIFT_LEFT** key (value: **2047**) press event can be maintained for 10s.
uinput enable_key_status 1
uinput -K -d 2047

# Enable the capability of controlling the injected modifier key status and set the duration of the injected modifier key status to 5s. The injected **KEYCODE_SHIFT_LEFT** key (value: **2047**) press event can be maintained for 5s.
uinput enable_key_status 1 5
uinput -K -d 2047
```

### Disabling the Capability of Controlling the Injected Modifier Key Status

Disable the capability of controlling the injected modifier key status. The capability can be enabled again next time.

**Command**

```bash
# <enable> specifies whether to enable the capability of controlling the injected modifier key status. The value can be 1 or 0. The value 1 means to enable the capability, and 0 means the opposite.
uinput enable_key_status <enable>
```

**Example**

```bash
# Disable the capability of controlling the injected modifier key status.
uinput enable_key_status 0
```

## Stylus Events

Simulates stylus click and move events. The actual event injection effect is the same as that of [touch events](#touch-events). You are advised to use the touch event command.

### Stylus Down Event

Simulates a stylus press at (dx, dy). You are advised to use this event together with the stylus up event to close the event.

**Command**

```bash
uinput -S -d <dx> <dy>
uinput --stylus --down <dx> <dy>

# <dx> and <dy> are coordinates in the relative coordinate system with the upper-left corner of the screen as the origin.
```

### Stylus Up Event

Simulates a stylus up at (dx, dy). You are advised to use this event together with the stylus down event to close the event.

**Command**

```bash
uinput -S -u <dx> <dy>
uinput --stylus --up <dx> <dy>

# <dx> and <dy> are coordinates in the relative coordinate system with the upper-left corner of the screen as the origin.
```

**Example**

```bash
# Simulate pressing and releasing the stylus at (100, 100).
uinput -S -d 100 100 -u 100 100
```

### Stylus Move Event

Simulates moving a stylus from coordinates (dx1, dy1) to coordinates (dx2, dy2) within a specified time and then releasing the stylus.

**Command**

```bash
uinput -S -m <dx1> <dy1> <dx2> <dy2> [smooth time] [-k keep time]
uinput --stylus --move <dx1> <dy1> <dx2> <dy2> [smooth time] [-k keep time]

# <dx1> and <dy1> are coordinates of the start point in the relative coordinate system with the upper left corner of the screen as the origin.
# <dx2> and <dy2> are coordinates of the end point in the relative coordinate system with the upper left corner of the screen as the origin.
# [smooth time] specifies the moving time, in milliseconds. The value must be an integer between 1 and 15000. The default value is 1000. This parameter is optional.
# [-k keep time] specifies the duration before releasing after the stylus moves to the target position, in milliseconds. The value must be an integer between 0 and 60000. The default value is 0. This parameter is optional.
```

**Example**

```bash
# Simulate pressing the stylus at (100, 1000), moving to (100, 2000) over 1000 ms, holding for 1000 ms and then releasing it.
uinput -S -m 100 1000 100 2000 1000 -k 1000
```

### Stylus Click Event

Simulates a stylus click at (dx, dy).

**Command**

```bash
uinput -S -c <dx> <dy> [click interval]
uinput --stylus --click <dx> <dy> [click interval]

# <dx> and <dy> are coordinates in the relative coordinate system with the upper-left corner of the screen as the origin.
# [click interval time] specifies the click interval, in milliseconds. The value is an integer between 1 and 450. The default value is 100. This parameter is optional.
```

**Example**

```bash
# Simulate a stylus click at (100, 100).
uinput -S -c 100 100
```

### Stylus Drag Event

Simulates a stylus drag event.

**Command**

```bash
uinput -S -g <dx1> <dy1> <dx2> <dy2> [press time] [total time] 
uinput --stylus --drag <dx1> <dy1> <dx2> <dy2> [press time] [total time] 

# <dx1> and <dy1> are coordinates of the start point in the relative coordinate system with the upper left corner of the screen as the origin.
# <dx2> and <dy2> are coordinates of the end point in the relative coordinate system with the upper left corner of the screen as the origin.
# [press time] specifies the press time, in milliseconds. The value is an integer between 500 and 14500. The default value is 500. This parameter is optional and must be used together with the total time parameter. If either of the parameters is not specified, the command does not take effect. If both parameters are not specified, the command takes effect.
# [total time] specifies the drag time, in milliseconds. The value is an integer between 1000 and 15000. The default value is 1000. This parameter is optional and must be used together with the press time parameter. If either of the two parameters is not specified, the command does not take effect. If both parameters are not specified, the command takes effect. The value of [total time] minus [press time] must be greater than or equal to 500.
```

**Example**

```bash
# Simulate pressing the stylus at (100, 150) for 500 ms and dragging it to (500, 300) after 1100 ms.
uinput -S -g 100 150 500 300 500 1100
```

### Interval of Stylus Events

Sets the interval between stylus events, in milliseconds. This command must be used with other stylus event commands. Otherwise, this command is invalid.

**Command**

```bash
uinput -S -i <time>
uinput --stylus --interval <time>

# <time> specifies the interval, in milliseconds. The value must be an integer between 1 and 15000.
```

**Example**

```bash
# Simulate pressing the stylus at (100, 100) and releasing it after 500 ms.
uinput -S -d 100 100 -i 500 -u 100 100
```

## Touch Events

Simulates touch events such as finger click and move events.

### Touch Down Event

Simulates touching at (dx, dy). You are advised to use this event together with the touch up event to close the event.

**Command**

```bash
uinput -T -d <dx> <dy>
uinput --touch --down <dx> <dy>

# <dx> and <dy> are coordinates in the relative coordinate system with the upper-left corner of the screen as the origin.
```

### Touch Up Event

Simulates lifting the finger at (dx, dy). You are advised to use this event together with the touch down event to close the event.

**Command**

```bash
uinput -T -u <dx> <dy>
uinput --touch --up <dx> <dy>

# <dx> and <dy> are coordinates in the relative coordinate system with the upper-left corner of the screen as the origin.
```

**Example**

```bash
# Simulate touching at (100, 100) and then lifting the finger.
uinput -T -d 100 100 -u 100 100
```

### Touch Move Event

Simulate touching at (dx1, dy1), moving the finger to (dx2, dy2) within a specified time, and then lifting the finger. Up to three fingers can be used at the same time.

**Command**

```bash
uinput -T -m <dx1> <dy1> <dx2> <dy2> [-k keep time] [smooth time]
uinput --touch --move <dx1> <dy1> <dx2> <dy2> [-k keep time] [smooth time]

# <dx1> and <dy1> are coordinates of the start point in the relative coordinate system with the upper left corner of the screen as the origin.
# <dx2> and <dy2> are coordinates of the end point in the relative coordinate system with the upper left corner of the screen as the origin.
# [-k keep time] specifies the hold time, in milliseconds. The value must be an integer between 0 and 60000. The default value is 0. This parameter is optional.
# [smooth time] specifies the moving time, in milliseconds. The value must be an integer between 1 and 15000. The default value is 1000. This parameter is optional.
```

**Example**

```bash
# Simulate touching at (100, 1000), moving to (100, 2000) over 1000 ms, holding for 1000 ms and then lifting the finger.
uinput -T -m 100 1000 100 2000 -k 1000 1000

# Simulate a three-finger swipe. The first finger presses at (300, 900) and moves to (300, 2000), the second finger presses at (600, 900) and moves to (600, 2000), and the third finger presses at (900, 900) and moves to (900, 2000). The total movement duration is 200 ms. After the movement ends, the fingers pause on the screen for 1000 ms before lifting.
uinput -T -m 300 900 300 2000 600 900 600 2000 900 900 900 2000 -k 1000 200
```

### Touch Click Event

Simulates a finger click at coordinates (dx, dy).

**Command**

```bash
uinput -T -c <dx> <dy> [click interval]
uinput --touch --click <dx> <dy> [click interval]

# <dx> and <dy> are coordinates in the relative coordinate system with the upper-left corner of the screen as the origin.
# [click interval time] specifies the click interval, in milliseconds. The value is an integer between 1 and 450. The default value is 100. This parameter is optional.
```

**Example**

```bash
# Simulate a finger click at (100, 100).
uinput -T -c 100 100
```

### Touch Drag Event

Simulates a finger drag.

**Command**

```bash
uinput -T -g <dx1> <dy1> <dx2> <dy2> [press time] [total time] 
uinput --touch --drag <dx1> <dy1> <dx2> <dy2> [press time] [total time] 

# <dx1> and <dy1> are coordinates of the start point in the relative coordinate system with the upper left corner of the screen as the origin.
# <dx2> and <dy2> are coordinates of the end point in the relative coordinate system with the upper left corner of the screen as the origin.
# [press time] specifies the press time, in milliseconds. The value is an integer between 500 and 14500. The default value is 500. This parameter is optional and must be used together with the total time parameter. If either of the parameters is not specified, the command does not take effect. If both parameters are not specified, the command takes effect.
# [total time] specifies the drag time, in milliseconds. The value is an integer between 1000 and 15000. The default value is 1000. This parameter is optional and must be used together with the press time parameter. If either of the two parameters is not specified, the command does not take effect. If both parameters are not specified, the command takes effect. The value of [total time] minus [press time] must be greater than or equal to 500.
```

**Example**

```bash
# Touch at (100, 150), drag to (500, 300) over 1100 ms, then lift the finger.
uinput -T -g 100 150 500 300 500 1100
```

### Interval of Touch Events

Sets the interval between touch events, in milliseconds. This command must be used with other touch event commands. Otherwise, this command is invalid.

**Command**

```bash
uinput -T -i <time>
uinput --touch --interval <time>

# <time> specifies the interval, in milliseconds. The value must be an integer between 1 and 15000.
```

**Example**

```bash
# Simulate touching at (100, 100) and releasing the finger after 500 ms.
uinput -T -d 100 100 -i 500 -u 100 100
```

### Single-Knuckle Double-Tap

Simulates a single-knuckle double-tap on the touchscreen.

**Command**

```bash
uinput -T -k -s <dx1> <dy1> <dx2> <dy2> [interval time]
uinput --touch --knuckle --single <dx1> <dy1> <dx2> <dy2> [interval time]

# <dx1> and <dy1> are coordinates of the first tap in the relative coordinate system with the upper left corner of the screen as the origin.
# <dx2> and <dy2> are coordinates of the second tap in the relative coordinate system with the upper left corner of the screen as the origin.
# [interval time] specifies the interval, in milliseconds. The value must be an integer between 1 and 250. The default value is 200. This parameter is optional.
```

**Example**

```bash
# Simulate a single-finger knuckle tap at (100, 100) and (100, 130) at an interval of 200 ms.
uinput -T -k -s 100 100 100 130
```

### Two-Knuckle Double-Tap

Simulates a two-knuckle double-tap on the touchscreen.

**Command**

```bash
uinput -T -k -d <dx1> <dy1> <dx2> <dy2> [interval time]
uinput --touch --knuckle --double <dx1> <dy1> <dx2> <dy2> [interval time]

# <dx1> and <dy1> are coordinates of the first knuckle in the relative coordinate system with the upper left corner of the screen as the origin.
# <dx2> and <dy2> are coordinates of the second knuckle in the relative coordinate system with the upper left corner of the screen as the origin.
# [interval time] specifies the interval, in milliseconds. The value must be an integer between 1 and 250. The default value is 200. This parameter is optional.
```

**Example**

```bash
# Simulate a two-knuckle double-tap at (100, 100) and (100, 130) at an interval of 200 ms.
uinput -T -k -d 100 100 100 130
```

## Touchpad Events

### Touchpad Pinch Event

Simulates a finger pinch on the touchpad.

**Command**

```bash
uinput -P -p <dx> <dy> scalePercent
uinput --touchpad --pinch <dx> <dy> scalePercent

# <dx> and <dy> are coordinates in the relative coordinate system with the upper-left corner of the screen as the origin.
# scalePercent specifies the scale percent. The value range is [1, 500]. If the value is less than 100, the image is zoomed out. If the value is greater than 100, the image is zoomed in. The value of dx must be greater than 0, and the value of dy must be greater than or equal to 200. In this scenario, only image zooming is supported. Ensure that there is an image on the screen when this command is executed.
```

**Example**

```bash
# Simulate a finger pinch on the touchpad.
uinput -P -p 100 300 89
```

### Touchpad Swipe Event

Simulates a swipe on the touchpad.

**Command**

```bash
uinput -P -s <startX> <startY> <endX> <endY>
uinput --touchpad --swipe <startX> <startY> <endX> <endY>

# <startX> and <startY> are coordinates of the start point of the touchpad swipe event in the relative coordinate system with the upper left corner of the screen as the origin.
# <endX> and <endY> are coordinates of the end point of the touchpad swipe event in the relative coordinate system with the upper left corner of the screen as the origin.
```

**Example**

```bash
# Simulate the three-finger swipe gesture on the touchpad.
uinput -P -s 100 1100 100 300
```

### Touchpad Rotate Event

Simulates a rotation on the touchpad.

Currently, the touchpad rotate event does not take effect.

**Command**

```bash
uinput -P -r <rotateValue>
uinput --touchpad --rotate <rotateValue>

# <rotateValue> specifies the rotation value, in degrees. The value must be an integer between –359 and 359. A positive value indicates clockwise rotation, and a negative value indicates counterclockwise rotation.
```

**Example**

```bash
# Simulate a two-finger rotation of 180 degrees on the touchpad.
uinput -P -r 180
```