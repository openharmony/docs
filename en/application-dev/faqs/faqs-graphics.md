# Graphics Development

## How do I obtain the DPI of a device?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9, stage model)

**Solution**

Import the **@ohos.display** module and call the **getDefaultDisplaySync\(\)** API.

**Example**

```
import display from '@ohos.display'; 
let displayClass = null;
try {
  displayClass = display.getDefaultDisplaySync();
  console.info('Test densityDPI:' + JSON.stringify(displayClass.densityDPI));
} catch (exception) {
  console.error('Failed to obtain the default display object. Code: ' + JSON.stringify(exception));
}
```

## How do I hide the status bar to get the immersive effect?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9, stage model) 

**Solution**

1.  Use **onWindowStageCreate** to obtain a **windowClass** object.

    ```
    onWindowStageCreate(windowStage) {
      // When the main window is created, set the main page for this ability.
      console.log("[Demo] MainAbility onWindowStageCreate")
      windowStage.getMainWindow((err, data) => {
        if (err.code) {
          console.error('Failed to obtain the main window.')
          return;
        }
        // Obtain a windowClass object.
        globalThis.windowClass = data; 
      })
    }
    ```

2.  Enable the full-screen mode for the window and hide the status bar.

    ```
     globalThis.windowClass.setFullScreen(isFullScreen, (err, data) => {
      if (err.code) {
        console.error('Failed to enable the full-screen mode. Cause:' + JSON.stringify(err));
        return;
      }
        console.info('Succeeded in enabling the full-screen mode. Data: ' + JSON.stringify(data));
      });
    ```


## How do I obtain the window width and height?

Applicable to: OpenHarmony SDK 3.2 Beta5 (API version 9, stage model) 

**Solution**

Import the **@ohos.window** module, obtain a **Window** object, and use **getWindowProperties\(\)** of the object to obtain the window properties. The **windowRect** field in the properties specifies the window width and height.

**Example**

```
import window from '@ohos.window';
let windowClass = null;
try {    
    let promise = window.getLastWindow(this.context);
    promise.then((data)=> {
        // Obtain a Window object.
        windowClass = data;
        try {
            // Obtain the window properties.
            let properties = windowClass.getWindowProperties();
            let rect = properties.windowRect;
            // rect.width: window width; rect.height: window height.
        } catch (exception) {
             console.error('Failed to obtain the window properties. Cause: ' + JSON.stringify(exception));
        }
        console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data));
    }).catch((err)=>{
        console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(err));
    });} catch (exception) {
    console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(exception));
}
```
