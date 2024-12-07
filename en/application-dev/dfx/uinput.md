# uinput

uinput can simulate users to operate devices such as the mouse, keyboard, and touchpad for pressure tests like stability tests.

## Environment Setup

- The [environment setup](hdc.md#environment-setup) is complete.

- The devices are properly connected.

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

Displays the commands supported by the uinput tool.

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
sage: uinput <option> <command> <arg>...
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
Moves a mouse pointer to a relative position (dx, dy).

**Command**
```bash
uinput -M -m <dx> <dy>
uinput --mouse --move <dx> <dy>
```

**Example**
```bash
# Move a mouse pointer to the relative position (100, 100).
uinput -M -m 100 100
```

**Extended Commands**
```bash
uinput -M -m <dx1> <dy1> <dx2> <dy2> [smooth time] --trace
uinput --mouse --move <dx1> <dy1> <dx2> <dy2> [smooth time] --trace

The trace option can be added to simulate the relative position and process of a mouse move event.
[smooth time] specifies the moving time, whose default value is 1000 ms. The value can be set between 1 and 15000 ms.
```

**Example**
```bash
# Move a mouse pointer from (100, 100) to (200, 200) for 1500 ms.
uinput -M -m 100 100 200 200 1500 --trace
```

### Mouse Down Event
Presses a mouse button. This command is used with the mouse up command. For details about key values, see [Mouse Buttons](#mouse-buttons)

**Command**
```bash
uinput -M -d <key>
uinput --mouse --down <key>
```

### Mouse Up Event
Releases a mouse button. This command is used with the mouse down command. For details about key values, see [Mouse Buttons](#mouse-buttons)

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
Clicks a mouse button. For details about key values, see [Mouse Buttons](#mouse-buttons)

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
Double-clicks a mouse button. For details about key values, see [Mouse Buttons](#mouse-buttons)

**Command**
```bash
uinput -M -b <dx> <dy> <id> [press time] [click interval time]
uinput --mouse --double_click <dx> <dy> <id> [press time] [click interval time]

The value of [press time] can be set between 1 and 300 ms.
The value of [click interval time] can be set between 1 and 450 ms.
The interval time must be within the value range. Otherwise, an error or invalid operation may occur.
```

**Example**
```bash
# Double-click the coordinates (100, 150).
uinput -M -b 100 150 0 10 10
```

### Mouse Scroll Event
Scrolls a mouse wheel backwards.

**Command**
```bash
uinput -M -s <number>
uinput --mouse --scroll <number>

number indicates the amount of the mouse scrolling notches. One notch is 15.
```

**Example**
```bash
# Scroll the mouse wheel backwards for three notches.
uinput -M -s 45
```

### Mouse Drag Event
Drags a mouse.

**Command**
```bash
uinput -M -g <dx1> <dy1> <dx2> <dy2> [total time]
uinput --mouse --drag <dx1> <dy1> <dx2> <dy2> [total time]

The [total time] parameter is optional, whose default value is 3000 ms. The value can be set between 3000 and 15000 ms.
```

**Example**
```bash
# Click and drag a mouse from coordinates (100, 150) to (500, 300) at a specified time, and then release the mouse.
uinput -M -g 100 150 500 300
```

### Mouse Event Interval
Sets the interval of mouse events, in milliseconds.

**Command**
```bash
uinput -M -i <time>
uinput --mouse --interval <time>
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

Simulates the keyboard input events in the edit box.

### Key Down Event
Presses a key. This command is used with the key up command. For details about the keycode values, see [KeyCode](../reference/apis-input-kit/js-apis-keycode.md).

**Command**
```bash
uinput -K -d <key>
uinput --keyboard --down <key>
```

### Key Up Event
Releases a key. This command is used with the key down command. For details about the keycode values, see [KeyCode](../reference/apis-input-kit/js-apis-keycode.md).

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
Presses a key for a specified duration. For details about the keycode values, see [KeyCode](../reference/apis-input-kit/js-apis-keycode.md).

**Command**
```bash
uinput -K -l <key> [long press time]
uinput --keyboard --long_press <key> [long press time]
```

**Example**
```bash
# Press and hold the A key for 100 ms, and then release the key.
uinput -K -l 2017 100
```

### Repeat Key Event
Press a key and repeat the pressing for a specified time. For details about the keycode values, see [KeyCode](../reference/apis-input-kit/js-apis-keycode.md).

**Command**
```bash
uinput -K -r <key> [repeat output time]
uinput --keyboard --repeat <key> [repeat output time]
```

**Example**
```bash
# Press the A key and repeat the pressing within 100 ms.
uinput -K -r 2017 100
```

### Keyboard Event Interval
Sets the interval of keyboard events, in milliseconds.

**Command**
```bash
uinput -K -i <time>
uinput --keyboard --interval <time>
```

**Example**
```bash
# Set the interval between pressing and releasing the A key to 500 ms.
uinput -K -d 2017 -i 500 -u 2017
```

### Keyboard Text Event
Enters text using the keyboard. This command cannot be used together with other commands. Only a maximum of 2000 ASCLL characters are supported.

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
Press a stylus at coordinates (dx, dy). This command is used together with the stylus up command.

**Command**
```bash
uinput -S -d <dx> <dy>
uinput --stylus --down <dx> <dy>
```

### Stylus Up Event
Lifts a stylus at coordinates (dx, dy). This command is used together with the stylus down command.

**Command**
```bash
uinput -S -u <dx> <dy>
uinput --stylus --up <dx> <dy>
```

**Example**
```bash
# Press and lift a stylus at coordinates (100, 100).
uinput -S -d 100 100 -u 100 100
```

### Stylus Move Event
Moves a stylus from coordinates (dx1, dy1) to coordinates (dx2, dy2) after smooth time (ms) and then lifts the stylus.

**Command**
```bash
uinput -S -m <dx1> <dy1> <dx2> <dy2> [smooth time] [-k keep time]
uinput --stylus --move <dx1> <dy1> <dx2> <dy2> [smooth time] [-k keep time]

The [smooth time] parameter is optional, whose default value is 1000 ms. The value can be set between 1 and 15000 ms.
The [-k keep time] parameter is optional, whose default value is 0 ms. The value can be set between 0 and 60000 ms.
```

**Example**
```bash
# Move a stylus from coordinates (100, 100) to coordinates (200, 200) for 1000 ms and then lift the stylus.
uinput -S -m 100 100 200 200 1000 -k 1000
```

### Stylus Click Event
Clicks a stylus at coordinates (dx, dy).

**Command**
```bash
uinput -S -c <dx> <dy> [click interval]
uinput --stylus --click <dx> <dy> [click interval]

The value of [click interval] can be set between 1 and 450 ms.
```

**Example**
```bash
# Click a stylus at coordinates (100, 100).
uinput -S -c 100 100
```

### Stylus Drag Event
Drags a stylus.

**Command**
```bash
uinput -S -g <dx1> <dy1> <dx2> <dy2> [press time] [total time] 
uinput --stylus --drag <dx1> <dy1> <dx2> <dy2> [press time] [total time] 

The value of [Press time] cannot be less than 500 ms.
[total time] specifies the total time of the drag operation. The value of [total time] and [Press time] cannot be less than 500 ms. Otherwise, an error or invalid operation may occur.
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
```

**Example**
```bash
# Set the interval between the two click events at coordinates (100,100) to 500 ms.
uinput -S -c 100 100  -i 500 -c 100 100
```

## Touch Events

Simulates touch events such as touch click and move events.

### Touch Down Event
Simulates a finger touch at coordinates (dx, dy). This command is used together with the touch up command.

**Command**
```bash
uinput -T -d <dx> <dy>
uinput --touch --down <dx> <dy>
```

### Touch Up Event
Lifts a finger off the coordinates (dx, dy). This command is used together with the touch down command.

**Command**
```bash
uinput -T -u <dx> <dy>
uinput --touch --up <dx> <dy>
```

**Example**
```bash
# Touch coordinates (100, 100) and lift the finger off.
uinput -T -d 100 100 -u 100 100
```

### Touch Move Event
Moves the finger from coordinates (dx1, dy1) to coordinates (dx2, dy2) after smooth time (ms). A maximum of three fingers can be moved at the same time.

**Command**
```bash
uinput -T -m <dx1> <dy1> <dx2> <dy2> [-k keep time] [smooth time]
uinput --touch --move <dx1> <dy1> <dx2> <dy2> [-k keep time] [smooth time]

The [-k keep time] parameter is optional, whose default value is 0 ms. The value can be set between 0 and 60000 ms.
The [smooth time] parameter is optional, whose default value is 1000 ms. The value can be set between 1 and 15000 ms.
```

**Example**
```bash
# Move the finger from coordinates (100, 100) to coordinates (200, 200) for 1000 ms and then lift the finger.
uinput -T -m 100 100 200 200 1000 -k 1000

# Move three fingers for 200 ms, with the first finger moving from (300, 900) to (300,2000), the second finger moving from (600,900) to (600,2000), and the third finger moving from (900,900) to (900,2000). After the movement, hold the screen for 1000 ms and then lift the finger.
uinput -T -m 300 900 300 2000 600 900 600 2000 900 900 900 2000 200 -k 1000
```

### Touch Click Event
Simulates a finger click at coordinates (dx, dy).

**Command**
```bash
uinput -T -c <dx> <dy> [click interval]
uinput --touch --click <dx> <dy> [click interval]

The value of [click interval] can be set between 1 and 450 ms.
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

The value of [Press time] cannot be less than 500 ms.
[total time] specifies the total time of the drag operation. The value of [total time] and [Press time] cannot be less than 500 ms. Otherwise, an error or invalid operation may occur.
```

**Example**
```bash
# Use a finger to drag from coordinates (100, 150) to coordinates (500, 300) after 1100 ms.
uinput -T -g 100 150 500 300 500 1100
```

### Interval of Touch Events
Sets the interval of touch events, in milliseconds.

**Command**
```bash
uinput -T -i <time>
uinput --touch --interval <time>
```

**Example**
```bash
# Set the interval between the two touch events at coordinates (100,100) to 500 ms.
uinput -S -c 100 100  -i 500 -c 100 100
```

### Knuckle Touch Event
Touches a screen with a single knuckle.

**Command**
```bash
uinput -T -k -s <dx1> <dy1> <dx2> <dy2> [interval time]
uinput --touch --knuckle --single <dx1> <dy1> <dx2> <dy2> [interval time]

The value of [interval time] can be set between 1 ms and 250 ms. The default value is 200 ms.
```

**Example**
```bash
# Set the interval between the knuckle touch events at coordinates (100, 100) and (100, 130) to 200 ms.
uinput -T -k -s 100 100 100 130
```

### Double-Knuckle Touch Event
Touches a screen with two knuckles.

**Command**
```bash
uinput -T -k -d <dx1> <dy1> <dx2> <dy2> [interval time]
uinput --touch --knuckle --double <dx1> <dy1> <dx2> <dy2> [interval time]

The value of [interval time] can be set between 1 ms and 250 ms. The default value is 200 ms.
```

**Example**
```bash
# Set the interval between the double-knuckle touch events at coordinates (100, 100) and (100, 130) to 200 ms.
uinput -T -k -d 100 100 100 130
```

## Touchpad Events

### Touchpad Pinch Event
Simulates finger pinching on the touchpad.

**Command**
```bash
uinput -P -p <dx> <dy> scalePercent
uinput --touchpad --pinch <dx> <dy> scalePercent

The value of scalePercent can be set between 0 and 500. If the value is less than 100, the image is zoomed out. If the value is greater than 100, the image is zoomed in. The value of dx must be greater than 0 and the value of dy must be greater than 200. In this case, only image zooming is supported. Before running this command, ensure that there is an image on the screen.
```

**Example**
```bash
# Pinch the image.
uinput -P -p 100 300 89
```

### Touchpad Swipe Event
Simulates the swiping and pinching on the touchpad.

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
