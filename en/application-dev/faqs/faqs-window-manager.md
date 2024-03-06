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

[Window](../reference/apis-arkui/js-apis-window.md)

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

[window.Orientation](../reference/apis-arkui/js-apis-window.md#orientation9)

## Why do the isStatusBarLightIcon and isNavigationBarLightIcon attributes set by calling setWindowSystemBarProperties not take effect? (API version 9)

Applicable to: stage model

**Solution**

In effect, the **isStatusBarLightIcon** and **isNavigationBarLightIcon** attributes turn the font white when set to **true**. If **statusBarContentColor** is also set in **setWindowSystemBarProperties**, the **isStatusBarLightIcon** attribute does not take effect. Similarly, if **navigationBarContentColor** is set, the **isNavigationBarLightIcon** attribute does not take effect.

**References**

[window.SystemBarProperties](../reference/apis-arkui/js-apis-window.md#systembarproperties)


## How do I keep the device screen always on? (API version 9)

**Solution**

Obtain a **Window** instance, and call [setWindowKeepScreenOn](../reference/apis-arkui/js-apis-window.md#setwindowkeepscreenon9) to keep the device screen always on.

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

**Solution**

Obtain a **Window** instance, and call **on('windowSizeChange')** to listen for window size changes.

```
try {
    windowClass.on('windowSizeChange', (data) => {
        console.info('Succeeded in enabling the listener for window size changes. Data: ' + JSON.stringify(data)); 
   });
} catch (exception) {
    console.error('Failed to enable the listener for window size changes. Cause: ' + JSON.stringify(exception));
}
```

**References**

[window.on\("windowSizeChange"\)](../reference/apis-arkui/js-apis-window.md#onwindowsizechange7)

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
      let d = await display.getDefaultDisplaySync()
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
      window.getLastWindow(getContext(this), (err, data) => { // Obtain a Window instance.
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

[Setting the Window Orientation](../reference/apis-arkui/js-apis-window.md#setpreferredorientation9) 

[Subscribing to Display Changes](../reference/apis-arkui/js-apis-display.md#displayonaddremovechange)

<!--no_check-->
