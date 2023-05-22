# Window Management Development

## How do I obtain the height of the status bar and navigation bar?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

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
  mainWindow.on("systemBarTintChange", (data) => {
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

## How do I hide the status bar on the top of an application?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Solution**

Use **setWindowSystemBarEnable** in the **onWindowStageCreate** lifecycle callback of UIAbility.

**Example**

```
onWindowStageCreate(windowStage){
  windowStage.getMainWindowSync().setWindowSystemBarEnable([])
  ......
}
```

**Reference**

[Window](../reference/apis/js-apis-window.md)
