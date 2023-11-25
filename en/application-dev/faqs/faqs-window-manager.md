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

[Window](../reference/apis/js-apis-window.md)

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

[window.Orientation](../reference/apis/js-apis-window.md#orientation9)

## Why do the isStatusBarLightIcon and isNavigationBarLightIcon attributes set by calling setWindowSystemBarProperties not take effect? (API version 9)

Applicable to: stage model

**Solution**

In effect, the **isStatusBarLightIcon** and **isNavigationBarLightIcon** attributes turn the font white when set to **true**. If **statusBarContentColor** is also set in **setWindowSystemBarProperties**, the **isStatusBarLightIcon** attribute does not take effect. Similarly, if **navigationBarContentColor** is set, the **isNavigationBarLightIcon** attribute does not take effect.

**References**

[window.SystemBarProperties](../reference/apis/js-apis-window.md#systembarproperties)


## How do I keep the screen always on? (API version 9)

**Solution**

 

Obtain a **Window** instance, and call [setWindowKeepScreenOn](../reference/apis/js-apis-window.md#setwindowkeepscreenon9) to keep the screen always on.

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

[window.on\("windowSizeChange"\)](../reference/apis/js-apis-window.md#onwindowsizechange7)
