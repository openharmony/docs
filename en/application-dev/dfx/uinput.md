# uinput


**uinput** provides commands to simulate user operations on devices, which can be especially useful for stability testing and other pressure tests.


## Prerequisites

- The [environment setup](hdc.md#environment-setup) is complete.

- The devices are properly connected.


## Features

| Command| Description|
| -------- | -------- |
| -K  --keyboard | Injects a key event.|
| -T  --touch | Injects a touch event.|
| -M  --mouse | Injects a mouse event.|
| -k --knuckle | Injects a knuckle event.|
| -?  --help | Shows help information. |


## Examples

1. Run uinput -K -d 18 -u 18 to press and release the Power button. For details about the keycode values, see [KeyCode](../reference/apis-input-kit/js-apis-keycode.md).

2. Run **uinput -T -m 100 200 500 800 1000**. It takes 1 second to move the finger from 100 200 to 500 800.  
