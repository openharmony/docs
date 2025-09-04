# Window Management Development


## How do I obtain the height of the status bar and navigation bar? (API version 9)

**Solution**

Before the window content is loaded, enable listening for the **systemAvoidAreaChange** event.

**Example**

```
// MainAbility.ts
import window from '@ohos.window';

/**
 * Set the immersive window and obtain the height of the status bar and navigation bar.
 * @param mainWindow Indicates the main window.
 */
async function enterImmersion(mainWindow: window.Window) { 
  window.on("systemBarTintChange", (data) => {
    let avoidAreaRect = data.regionTint[0].region; // data.regionTint is an array that contains the rectangle coordinates of the status bar and navigation bar.
  })
  await mainWindow.setFullScreen(true)
  await mainWindow.setSystemBarEnable(["status", "navigation"])
  await mainWindow.systemBarProperties({
    navigationBarColor: "#00000000",
    statusBarColor: "#00000000",
    navigationBarContentColor: "#FF0000",
    statusBarContentColor: "#FF0000"
  })
}
export default class MainAbility extends Ability {
  // Do something.
  async onWindowStageCreate(windowStage: window.WindowStage) {
    let mainWindow = await windowStage.getMainWindow()
    await enterImmersion(mainWindow)
    windowStage.loadContent('pages/index')
  }
  // Do something.
}
```


## How do I hide the status bar on the top of an application? (API version 9)

**Solution**

Use **setWindowSystemBarEnable** in the **onWindowStageCreate** lifecycle callback of UIAbility.

**Example**

```
onWindowStageCreate(windowStage){
  windowStage.getMainWindowSync().setWindowSystemBarEnable([])
  ......
}
```

**References**

[Window](../reference/apis-arkui/arkts-apis-window-Window.md)

## How do I lock the window in portrait mode so that it does not rotate with the device? (API version 9)

Applicable to: stage model

**Solution**

To lock the window in portrait mode, call **setPreferredOrientation** of the window module, with **orientation** set to **window.Orientation.PORTRAIT**.

**Example**

```
import window from "@ohos.window";
// 1. Obtain a Window instance. Specifically, you can call createWindow to create a window or findWindow to obtain an existing window.
let windowClass = null;
let config = {name: "alertWindow", windowType: window.WindowType.TYPE_SYSTEM_ALERT, ctx: this.context};
try {
    let promise = window.createWindow(config);
    promise.then((data)=> {
        windowClass = data;
        console.info('Succeeded in creating the window. Data:' + JSON.stringify(data));
    }).catch((err)=>{
        console.error('Failed to create the Window. Cause:' + JSON.stringify(err));
    });} catch (exception) {
    console.error('Failed to create the window. Cause: ' + JSON.stringify(exception));
}
// 2. Call setPreferredOrientation to set the window orientation. The value PORTRAIT indicates that the window is displayed in portrait mode.
let orientation = window.Orientation.PORTRAIT;
if (windowClass) {
    windowClass.setPreferredOrientation(orientation, (err) => {
        if (err.code) {
            console.error('Failed to set window orientation. Cause: ' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in setting window orientation.');
}
```

**References**

[window.Orientation](../reference/apis-arkui/arkts-apis-window-e.md#orientation9)

## Why do the isStatusBarLightIcon and isNavigationBarLightIcon attributes set by calling setWindowSystemBarProperties not take effect? (API version 9)

Applicable to: stage model

**Solution**

In effect, the **isStatusBarLightIcon** and **isNavigationBarLightIcon** attributes turn the font white when set to **true**. If **statusBarContentColor** is also set in **setWindowSystemBarProperties**, the **isStatusBarLightIcon** attribute does not take effect. Similarly, if **navigationBarContentColor** is set, the **isNavigationBarLightIcon** attribute does not take effect.

**References**

[window.SystemBarProperties](../reference/apis-arkui/arkts-apis-window-i.md#systembarproperties)


## How do I keep the device screen always on? (API version 9)

**Solution**

Obtain a **Window** instance, and call [setWindowKeepScreenOn](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowkeepscreenon9) to keep the device screen always on.

**Example**

```
let isKeepScreenOn = true;
try {
    windowClass.setWindowKeepScreenOn(isKeepScreenOn, (err) => {
        if (err.code) {
            console.error('Failed to set the screen to be always on. Cause: ' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in setting the screen to be always on.');
    });
} catch (exception) {
    console.error('Failed to set the screen to be always on. Cause: ' + JSON.stringify(exception));
}
```


## How do I listen for window size changes? (API version 9)

After obtaining a **Window** instance, you can call [window.on('windowSizeChange')](../reference/apis-arkui/arkts-apis-window-Window.md#onwindowsizechange7) to listen for window size changes.

Note that this event is not triggered if the window size does not change. For example, if the window is rotated by 180 degrees without any size change, the callback is not invoked. In this case, listen for the [display.on('change')](../reference/apis-arkui/js-apis-display.md#displayonaddremovechange) event and obtain the window size through the **display** interface within the callback.

```
try {
    windowClass.on('windowSizeChange', (data) => {
        console.info('Succeeded in enabling the listener for window size changes. Data: ' + JSON.stringify(data)); 
   });
} catch (exception) {
    console.error('Failed to enable the listener for window size changes. Cause: ' + JSON.stringify(exception));
}
```

## How do I listen for orientation status changes of the device screen? (API version 10)

**Solution**

Use **display.on** to listen for the orientation status changes. 

**References**

[Subscribing to Display Changes](../reference/apis-arkui/js-apis-display.md#displayonaddremovechange)

## How do I enable the window to rotate with the device? (API version 10)

**Solution**

- Abilty-level configuration: Set **EntryAbility** to **orientation** in the **module.json5** file. 
- Dynamic setting: Use **window.setPreferredOrientation** to set the window orientation.

**Example**
```ts
import window from '@ohos.window';
import display from '@ohos.display';

const TAG = 'foo'
const ORIENTATION: Array<string> = ['Portrait', 'Landscape','Reverse portrait','Reverse landscape']

@Entry
@Component
struct ScreenTest {
  @State rotation: number = 0
  @State message: string = ORIENTATION[this.rotation]

  aboutToAppear() {
    this.setOrientation()

    let callback = async () => {
      let d = display.getDefaultDisplaySync()
      this.rotation = d.rotation
      this.message = ORIENTATION[this.rotation]
      console.info(TAG, JSON.stringify(d))
    }
    try {
      display.on("change", callback); // Listen for device screen status changes.
    } catch (exception) {
      console.error(TAG, 'Failed to register callback. Code: ' + JSON.stringify(exception));
    }
  }

  setOrientation() {
    try {
      window.getLastWindow(this.getUIContext().getHostContext(), (err, data) => { // Obtain a Window instance.
        if (err.code) {
          console.error(TAG, 'Failed to obtain the top window. Cause: ' + JSON.stringify(err));
          return;
        }
        let windowClass = data;
        console.info(TAG, 'Succeeded in obtaining the top window. Data: ' + JSON.stringify(data));

        let orientation = window.Orientation.AUTO_ROTATION; // Set the window orientation to AUTO_ROTATION.
        try {
          windowClass.setPreferredOrientation(orientation, (err) => {
            if (err.code) {
              console.error(TAG, 'Failed to set window orientation. Cause: ' + JSON.stringify(err));
              return;
            }
            console.info(TAG, 'Succeeded in setting window orientation.');
          });
        } catch (exception) {
          console.error(TAG, 'Failed to set window orientation. Cause: ' + JSON.stringify(exception));
        }
        ;
      });
    } catch (exception) {
      console.error(TAG, 'Failed to obtain the top window. Cause: ' + JSON.stringify(exception));
    }
    ;
  }

  build() {
    Row() {
      Column() {
        Text(`${this.rotation}`).fontSize(25)
        Text(`${this.message}`).fontSize(25)
      }
      .width("100%")
    }
    .height("100%")
  }
}
```
**References**

[Setting the Window Orientation](../reference/apis-arkui/arkts-apis-window-Window.md#setpreferredorientation9)

[Subscribing to Display Changes](../reference/apis-arkui/js-apis-display.md#displayonaddremovechange)

## Why a window instance cannot be used to obtain the updated window size in the display.on('change') callback? (API version 10)

**Solution**

The rotation action involves two modules, [@ohos.window](../reference/apis-arkui/arkts-apis-window.md) and [@ohos.display](../reference/apis-arkui/js-apis-display.md), which are running in separate processes. The sequence of updates following a rotation results in a temporal discrepancy: the display module updates by simply swapping width and height values, whereas the window module requires the completion of the ArkUI layout to determine the window size, which is a more time-consuming process. Consequently, attempting to retrieve the window information via the **Window** instance within the display change event will reflect outdated dimensions. As such, applications should register for the **display.on('change')** event and obtain screen dimensions such as width, height, and orientation from the **Display** instance within the callback.
 
**Example (incorrect)**

```ts
// The display module updates first.
display.on('change', async (data) => {
  let newDisplay: display.Display = display.getDefaultDisplaySync();
  console.info('Orientation: ' + newDisplay.orientation);
  let windowClass: window.Window = await window.getLastWindow(this.context);
  // The window module updates later. The original width and height are obtained.
  let windowProperties = windowClass.getWindowProperties();
  console.info('Width: ' + windowProperties.windowRect.width +
    ', height: ' + windowProperties.windowRect.height);
  // Ensure that the related Window instance, that is, windowClass, has been obtained.
  windowClass.getWindowAvoidArea(window.AvoidAreaType.TYPE_CUTOUT);
});
```

**Correct example**

```ts
display.on('change', (data) => {
  console.info('Succeeded in enabling the listener for display changes. Data: ' +
  JSON.stringify(data));
  let newDisplay: display.Display = display.getDefaultDisplaySync();
  console.info('Orientation: ' + newDisplay.orientation + 'width: ' +
  newDisplay.width + ', height: ' + newDisplay.height);
});
```

**References**

[display.on('change')](../reference/apis-arkui/js-apis-display.md#displayonaddremovechange)

## How do I obtain the screen orientation and avoidAreaChange information at the same time? (API version 10)

You can use [on('avoidAreaChange')](../reference/apis-arkui/arkts-apis-window-Window.md#onavoidareachange9) to listen for avoidance area changes and obtain **avoidAreaChange** from the callback. You can obtain the screen orientation information through the **Display** instance.

```ts
// Ensure that the related Window instance, that is, windowClass, has been obtained.
windowClass.on('avoidAreaChange', async (data) => {
  console.info('Succeeded in enabling the listener for avoid area changes. Type: ' +
    JSON.stringify(data.type) + ', area ' + JSON.stringify(data.area));
  let newDisplay: display.Display = display.getDefaultDisplaySync();
  console.info('Orientation: ' + newDisplay.orientation);
  let windowClass: window.Window = await window.getLastWindow(this.context);
  windowClass.getWindowAvoidArea(window.AvoidAreaType.TYPE_CUTOUT);
});
```

## The screen dimensions obtained by calling display.getDefaultDisplaySync in the display.on('foldDisplayModeChange') callback are incorrect. What should I do? (API version 10)

**Solution**

For applications locked in landscape orientation, the **foldDisplayModeChange** event is triggered during device folding or unfolding. However, the **rotation** attribute of the Display instance has not been refreshed yet. The width and height retrieved via **getDefaultDisplaySync** correspond to the device's portrait orientation. To address this, you can use the **display.on('change')** API to track display device alterations and subsequently obtain the screen width and height through a Display instance within the callback function.

**Example**

```ts
display.on('change', (data) => {
  console.info('Succeeded in enabling the listener for display changes. Data: ' +
  JSON.stringify(data));
  let newDisplay: display.Display = display.getDefaultDisplaySync();
  console.info('width: ' + newDisplay.width + ', height: ' + newDisplay.height);
});
```

**References**

[display.on('change')](../reference/apis-arkui/js-apis-display.md#displayonaddremovechange)

## What is the difference between orientation values 8 to 10 or 12 and values 13 to 16? (API version 9)

1. Windows with the orientation set to values 8 to 10 or 12 automatically rotate based on the sensor and are controlled by the rotation switch in Control Panel.
2. Windows with the orientation set to values 13 to 16 temporarily rotate to the specified direction (for example, temporarily rotate to portrait in the case of value 13), then automatically rotate based on the sensor. They are controlled by the rotation switch in Control Panel, and the rotatable directions are determined by the system.

The main difference is that for values 13 to 16, the window temporarily rotates to the specified direction, and the window orientation is maintained when switching between the foreground and background. However, for values 8 to 10 or 12, the window orientation is not maintained when switching between the foreground and background.

**Example scenarios**:
1. Holding the phone vertically with the rotation lock switch turned off -> The application orientation is set to AUTO_ROTATION_RESTRICTED -> Rotating the phone to landscape (**the application orientation is landscape**) -> The application exits to the background and goes to the home screen, holding the phone vertically (the orientation is portrait) -> The application switches to the foreground (**the application orientation is portrait**).
2. Holding the phone vertically with the rotation lock switch turned off -> The application orientation is set to USER_ROTATION_PORTRAIT (the application orientation is portrait) -> Rotating the phone to landscape (**the application orientation is landscape**) -> The application exits to the background and goes to the home screen, holding the phone vertically (the orientation is portrait) -> The application switches to the foreground (**the application orientation is landscape**).

| Name                              | Value | Rotatable Direction          | Automatic Rotation Based on Sensor| Rotation Switch Control|
|----------------------------------|----|-----------------|-------------|-----------|
| AUTO_ROTATION_RESTRICTED         | 8  | Landscape, portrait, reverse portrait, reverse landscape| Yes          | Yes        |
| AUTO_ROTATION_PORTRAIT_RESTRICTED         | 9  | Portrait, reverse portrait| Yes          | Yes        |
| AUTO_ROTATION_LANDSCAPE_RESTRICTED         | 10 | Landscape, reverse landscape| Yes          | Yes        |
| AUTO_ROTATION_UNSPECIFIED         | 12  | Determined by the system| Yes          | Yes        |
| USER_ROTATION_PORTRAIT           | 13 | Determined by the system          | Yes          | Yes        |
| USER_ROTATION_LANDSCAPE          | 14 | Determined by the system          | Yes          | Yes        |
| USER_ROTATION_PORTRAIT_INVERTED  | 15 | Determined by the system          | Yes          | Yes        |
| USER_ROTATION_LANDSCAPE_INVERTED | 16 | Determined by the system          | Yes          | Yes        |

<!--no_check-->
