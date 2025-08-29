# uinput

<!--Kit: Input Kit-->
<!--Subsystem: MultimodalInput-->
<!--Owner: @zhaoxueyuan-->
<!--Designer: @hanruofei-->
<!--Tester: @Lyuxin-->
<!--Adviser: @Brilliantry_Rui-->

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

> **NOTE**
>
> The unit of the coordinate-related parameters in the command is [px (pixel units)](../reference/apis-arkui/arkui-ts/ts-pixel-units.md).

## Help Command

Displays the commands supported by uinput.

**Command**
```bash
uinput -? 
uinput --help
```

**Example**
```bash
# Displays the help information.
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
```

**Example**
```bash
# Simulates a mouse movement to the coordinates (100, 100) in a relative coordinate system whose origin is the upper left corner of the specified screen.
uinput -M -m 100 100
```

**Extended Commands**
```bash
uinput -M -m <dx1> <dy1> <dx2> <dy2> [smooth time] --trace
uinput --mouse --move <dx1> <dy1> <dx2> <dy2> [smooth time] --trace

# The --trace option can be used to simulate the movement position and trace of the mouse to the coordinates in a relative coordinate system whose origin is the upper left corner of the specified screen.
# [smooth time] specifies the moving time, whose default value is 1000 ms. The value range is 1 to 15000 ms.
```

**Example**
```bash
# Move a mouse pointer from (100, 100) to (200, 200) for 1500 ms.
uinput -M -m 100 100 200 200 1500 --trace
```

### Mouse Down Event
Simulates a mouse button press. This command is used together with the mouse up event. For details about key values, see [Mouse Buttons](#mouse-buttons).

**Command**
```bash
uinput -M -d <key>
uinput --mouse --down <key>
```

### Mouse Up Event
Simulates a mouse button release. This command is used together with the mouse down event. For details about key values, see [Mouse Buttons](#mouse-buttons).

**Command**
```bash
uinput -M -u <key>
uinput --mouse --up <key>
```

**Example**
```bash
# Press down the left mouse button and release it.
uinput -M -d 0 -u 0
```

### Click Event
Simulates a mouse click. For details about key values, see [Mouse Buttons](#mouse-buttons).

**Command**
```bash
uinput -M -c <key>
uinput --mouse --click <key>
```

**Example**
```bash
# Click the left mouse button.
uinput -M -c 0
```

### Double-Click Event
Simulates a double-click on the mouse button. For details about values of **id**, see [Mouse Buttons](#mouse-buttons).

**Command**
```bash
uinput -M -b <dx> <dy> <id> [press time] [click interval time]
uinput --mouse --double_click <dx> <dy> <id> [press time] [click interval time]

# [press time]: press time. This parameter is optional. The default value is 50 ms. The value ranges from 1 ms to 300 ms.
# [click interval time]: click interval time, in ms. The value ranges from 1 to 450, and the default value is 300. This parameter is optional.
The interval time must be within the value range. Otherwise, an error or invalid operation may occur.
```

**Example**
```bash
# Double-click the coordinates (100, 150).
uinput -M -b 100 150 0 10 10
```

### Mouse Scroll Event
Simulates a forward or backward scrolling of the mouse wheel.

**Command**
```bash
uinput -M -s <number>
uinput --mouse --scroll <number>

# number indicates the number of scrolling notches. A positive value indicates scrolling backward, and a negative value indicates scrolling forward. One notch is 15.
```

**Example**
```bash
# Simulate a mouse movement to the coordinates (100, 200) in a relative coordinate system whose origin is the upper left corner of the specified screen. Then, scroll the mouse wheel backward for three notches.
uinput -M -m 100 200 -s 45
```

### Mouse Drag Event
Simulates a mouse dragging.

**Command**
```bash
uinput -M -g <dx1> <dy1> <dx2> <dy2> [total time]
uinput --mouse --drag <dx1> <dy1> <dx2> <dy2> [total time]

# [total time]: total drag duration. This parameter is optional. The default value is 1000 ms. The value ranges from 1 ms to 15000 ms.
```

**Example**
```bash
# Click and drag a mouse from coordinates (100, 150) to (500, 300) at a specified time, and then release the mouse.
uinput -M -g 100 150 500 300
```

### Mouse Event Interval
Sets the interval between mouse events, in ms.

**Command**
```bash
uinput -M -i <time>
uinput --mouse --interval <time>

# time: interval between mouse events, in milliseconds. The value ranges from 1 to 15000.
```

**Example**
```bash
# Set the interval between two click events to 500 ms.
uinput -M -c 0 -i 500 -c 0
```

### Mouse Buttons
| key |  Description|
| -------- | -------- |
| 0  | Left mouse button.  |
| 1  | Right mouse button.  |
| 2  | Middle mouse button.  |
| 3  | Side mouse button.|
| 4  | Extended mouse button.|
| 5  | Mouse forward button.|
| 6  | Mouse back button.|
| 7  | Mouse task button.|

## Keyboard Events

Simulates a keyboard input event in the edit box.

### Key Down Event
Simulates a key press. This command is used together with the key up event. For details about the keycode values, see [KeyCode](../reference/apis-input-kit/js-apis-keycode.md).

**Command**
```bash
uinput -K -d <key>
uinput --keyboard --down <key>
```

### Key Up Event
Simulates a key release. This command is used with the key down command. For details about the keycode values, see [KeyCode](../reference/apis-input-kit/js-apis-keycode.md).

**Command**
```bash
uinput -K -u <key>
uinput --keyboard --up <key>
```

**Example**
```bash
# Press the A key and release it.
uinput -K -d 2017 -u 2017
```

### Long-Press Key Event
Simulates a long press for a specified duration. For details about the keycode values, see [KeyCode](../reference/apis-input-kit/js-apis-keycode.md).

**Command**
```bash
uinput -K -l <key> [long press time]
uinput --keyboard --long_press <key> [long press time]

# [long press time]: key press duration, in ms. The value ranges from 3000 to 15000, and the default value is 3000. This parameter is optional.
```

**Example**
```bash
# Press and hold the A key for 6000 ms, and then release the key.
uinput -K -l 2017 6000
```

### Repeat Key Event
Simulates pressing a key and repeating the pressing for a specified time. For details about the keycode values, see [KeyCode](../reference/apis-input-kit/js-apis-keycode.md).

**Command**
```bash
uinput -K -r <key> [repeat output time]
uinput --keyboard --repeat <key> [repeat output time]

# [repeat output time]: repeat output time, in ms. The value ranges from 3000 to 15000, and the default value is 3000. This parameter is optional.
```

**Example**
```bash
# Press the A key and press it again within 4000 ms.
uinput -K -r 2017 4000
```

### Keyboard Event Interval
Sets the interval of keyboard events, in milliseconds.

**Command**
```bash
uinput -K -i <time>
uinput --keyboard --interval <time>

# time: interval between key events, in ms. The value ranges from 1 to 15000.
```

**Example**
```bash
# Press and hold A for 500 ms and then release it.
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
# Input 123 in the text box.
uinput -K -t 123
```

## Stylus Events

Simulates stylus click and move events.

### Stylus Down Event
Simulates a stylus press at (dx, dy). This command is used together with the stylus up event.

**Command**
```bash
uinput -S -d <dx> <dy>
uinput --stylus --down <dx> <dy>
```

### Stylus Up Event
Simulates a stylus release at (dx, dy). This command is used together with the stylus down event.

**Command**
```bash
uinput -S -u <dx> <dy>
uinput --stylus --up <dx> <dy>
```

**Example**
```bash
# Press the stylus at coordinates (100, 100) and release it.
uinput -S -d 100 100 -u 100 100
```

### Stylus Move Event
Simulates moving a stylus from coordinates (dx1, dy1) to coordinates (dx2, dy2) after smooth time (ms) and then lifting the stylus.

**Command**
```bash
uinput -S -m <dx1> <dy1> <dx2> <dy2> [smooth time] [-k keep time]
uinput --stylus --move <dx1> <dy1> <dx2> <dy2> [smooth time] [-k keep time]

# [smooth time]: moving time, in ms. The value ranges from 1 to 15000, and the default value is 1000. This parameter is optional.
# [-k keep time]: hold time, in ms. The value ranges from 0 to 60000, and the default value is 0. This parameter is optional.
```

**Example**
```bash
# Press the stylus at (100, 1000), move the stylus to (100, 2000) for 1000 ms, press the stylus for 1000 ms and then release it.
uinput -S -m 100 1000 100 2000 1000 -k 1000
```

### Stylus Click Event
Simulates a stylus click at (dx, dy).

**Command**
```bash
uinput -S -c <dx> <dy> [click interval]
uinput --stylus --click <dx> <dy> [click interval]

# [click interval]: click interval, in ms. The value ranges from 1 to 450, and the default value is 100. This parameter is optional.
```

**Example**
```bash
# Click a stylus at coordinates (100, 100).
uinput -S -c 100 100
```

### Stylus Drag Event
Simulates a stylus drag event.

**Command**
```bash
uinput -S -g <dx1> <dy1> <dx2> <dy2> [press time] [total time] 
uinput --stylus --drag <dx1> <dy1> <dx2> <dy2> [press time] [total time] 

# [Press time]: press time, in ms. The value ranges from 500 to 14500, and the default value is 500. This parameter is optional.
# [total time]: drag time, in ms. The value ranges from 1000 to 15000, and the default value is 1000. This parameter is optional. [total time] must be at least 500 greater than [press time]. Otherwise, an error or invalid operation may occur.
```

**Example**
```bash
# Drag a stylus from coordinates (100, 150) to coordinates (500, 300) for 1100 ms.
uinput -S -g 100 150 500 300 500 1100
```

### Interval of Stylus Events
Sets the interval of stylus events, in milliseconds.

**Command**
```bash
uinput -S -i <time>
uinput --stylus --interval <time>

# time: interval between stylus events, in ms. The value ranges from 1 to 15000.
```

**Example**
```bash
# Press the stylus at (100, 100) and lift it after 500 ms.
uinput -S -d 100 100  -i 500 -u 100 100
```

## Touch Events

Simulates touch events such as touch click and move events.

### Touch Down Event
Simulates a finger touch at (dx, dy). This command is used together with the touch up event.

**Command**
```bash
uinput -T -d <dx> <dy>
uinput --touch --down <dx> <dy>
```

### Touch Up Event
Simulates lifting the finger at (dx, dy). This command is used together with the touch down event.

**Command**
```bash
uinput -T -u <dx> <dy>
uinput --touch --up <dx> <dy>
```

**Example**
```bash
# Touch coordinates (100, 100) and lift the finger.
uinput -T -d 100 100 -u 100 100
```

### Touch Move Event
Simulates a finger touch at (dx1, dy1), a movement to (dx2, dy2) within **smooth time** (ms), and a finger lift. Up to three fingers can be moved at the same time.

**Command**
```bash
uinput -T -m <dx1> <dy1> <dx2> <dy2> [-k keep time] [smooth time]
uinput --touch --move <dx1> <dy1> <dx2> <dy2> [-k keep time] [smooth time]

# [-k keep time]: hold time, in ms. The value ranges from 0 to 60000, and the default value is 0. This parameter is optional.
# [smooth time]: moving time, in ms. The value ranges from 1 to 15000, and the default value is 1000. This parameter is optional.
```

**Example**
```bash
# Touch at (100, 1000), move to (100, 2000) over 1000 ms, hold for another 1000 ms, then lift the finger.
uinput -T -m 100 1000 100 2000 -k 1000 1000

# Move three fingers for 200 ms, with the first finger moving from (300, 900) to (300,2000), the second finger moving from (600,900) to (600,2000), and the third finger moving from (900,900) to (900,2000). After the movement, hold the screen for 1000 ms and then lift the finger.
uinput -T -m 300 900 300 2000 600 900 600 2000 900 900 900 2000 -k 1000 200
```

### Touch Click Event
Simulates a finger click at coordinates (dx, dy).

**Command**
```bash
uinput -T -c <dx> <dy> [click interval]
uinput --touch --click <dx> <dy> [click interval]

# [click interval]: click interval, in ms. The value ranges from 1 to 450, and the default value is 100. This parameter is optional.
```

**Example**
```bash
# Click at the coordinates (100, 100) using a finger.
uinput -T -c 100 100
```

### Touch Drag Event
Simulates a finger touch drag event.

**Command**
```bash
uinput -T -g <dx1> <dy1> <dx2> <dy2> [press time] [total time] 
uinput --touch --drag <dx1> <dy1> <dx2> <dy2> [press time] [total time] 

# [Press time]: press time, in ms. The value ranges from 500 to 14500, and the default value is 500. This parameter is optional.
# [total time]: drag time, in ms. The value ranges from 1000 to 15000, and the default value is 1000. This parameter is optional. [total time] must be at least 500 greater than [press time]. Otherwise, an error or invalid operation may occur.
```

**Example**
```bash
# Touch at (100, 150), drag to (500, 300) over 1100 ms, then lift the finger.
uinput -T -g 100 150 500 300 500 1100
```

### Interval of Touch Events
Sets the interval of touch events, in milliseconds.

**Command**
```bash
uinput -T -i <time>
uinput --touch --interval <time>

# time: interval between stylus events, in ms. The value ranges from 1 to 15000.
```

**Example**
```bash
# Touch at (100, 100) and lift the finger after 500 ms.
uinput -T -d 100 100  -i 500 -u 100 100
```

### Single-Finger Double-Knuckle Tap
Simulates a single-finger double-knuckle tap on the touchscreen.

**Command**
```bash
uinput -T -k -s <dx1> <dy1> <dx2> <dy2> [interval time]
uinput --touch --knuckle --single <dx1> <dy1> <dx2> <dy2> [interval time]

# [interval time]: interval time, in ms. The value ranges from 1 to 250 and the default value is 200. This parameter is optional.
```

**Example**
```bash
# Set the interval between the knuckle touch events at coordinates (100, 100) and (100, 130) to 200 ms.
uinput -T -k -s 100 100 100 130
```

### Two-Finger Double-Knuckle Tap
Simulates a two-finger double-knuckle tap on the touchscreen.

**Command**
```bash
uinput -T -k -d <dx1> <dy1> <dx2> <dy2> [interval time]
uinput --touch --knuckle --double <dx1> <dy1> <dx2> <dy2> [interval time]

# [interval time]: interval time, in ms. The value ranges from 1 to 250 and the default value is 200. This parameter is optional.
```

**Example**
```bash
# Use two knuckles to tap at (100, 100) and (100, 130) at an interval of 200 ms.
uinput -T -k -d 100 100 100 130
```

## Touchpad Events

### Touchpad Pinch Event
Simulates a finger pinch on the touchpad.

**Command**
```bash
uinput -P -p <dx> <dy> scalePercent
uinput --touchpad --pinch <dx> <dy> scalePercent

# scalePercent: scale percent. The value is greater than 0 and less than or equal to 500. If the value is less than 100, the image is zoomed out. If the value is greater than 100, the image is zoomed in. The value of dx must be greater than 0, and the value of dy must be greater than or equal to 200. In this scenario, only image zooming is supported. Ensure that there is an image on the screen when this command is executed.
```

**Example**
```bash
# Pinch the image.
uinput -P -p 100 300 89
```

### Touchpad Swipe Event
Simulates a swipe on the touchpad.

**Command**
```bash
uinput -P -s <startX> <startY> <endX> <endY>
uinput --touchpad --swipe <startX> <startY> <endX> <endY>
```

**Example**
```bash
# Swipe on the touchpad to view the Task View.
uinput -P -s 100 1100 100 300
```

### Touchpad Rotate Event
Simulates a rotation on the touchpad.

**Command**
```bash
uinput -P -r <rotateValue>
uinput --touchpad --rotate <rotateValue>

# rotateValue: rotation value, in degrees. The value ranges from -360 to 360. A positive value indicates clockwise rotation, and a negative value indicates counterclockwise rotation.
```

**Example**
```bash
# Perform a clockwise rotation of 180 degrees on the touchpad.
uinput -P -r 180
```
