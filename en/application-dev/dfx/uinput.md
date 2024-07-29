# uinput


**uinput** provides commands to simulate user operations on devices. It can be used in stability test and other pressure tests.


## Prerequisites

- The [environment setup](hdc.md#environment-setup) is complete.

- The devices are properly connected.


## Features

| Command| Description| 
| -------- | -------- |
| -K&nbsp;&nbsp;--keyboard | Injects a key event.| 
| -T&nbsp;&nbsp;--touch | Injects a touch event.| 
| -M&nbsp;&nbsp;--mouse | Injects a mouse event.| 
| -k --knuckle | Injects a knuckle event.| 
| -?&nbsp;&nbsp;--help | Displays help information.| 


## Example

1. Run **uinput -K -d 18 -u 18** to press and release the **Power** button. For details about the keycode values, see [KeyCode](../reference/apis-input-kit/js-apis-keycode.md).

2. Run **uinput -T -m 100 200 500 800 1000** to move finger from coordinate (100, 200) to (500, 800) in 1 second.  
