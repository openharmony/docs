# Graphics and Image Development

## Why do the isStatusBarLightIcon and isNavigationBarLightIcon attributes not take effect when window.setSystemBarProperties() is called?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

In effect, the **isStatusBarLightIcon** and **isNavigationBarLightIcon** attributes turn the font white when set to **true**. If **statusBarContentColor** is also set in **window.setSystemBarProperties()**, the **isStatusBarLightIcon** attribute does not take effect. Similarly, if **navigationBarContentColor** is set, the **isNavigationBarLightIcon** attribute does not take effect.

## How do I set the style of the system bar?

Applicable to: OpenHarmony SDK 3.2.3.5, stage model of API version 9

Import the **\@ohos.window** module, and call **window.setSystemBarProperties()**.

## How do I hide the status bar to get the immersive effect?

Applicable to: OpenHarmony SDK 3.2.6.3, stage model of API version 9

1. Use the **onWindowStageCreate** to obtain a **windowClass** object.
   
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

2. Enable the full-screen mode for the window and hide the status bar.
   
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

Applicable to: OpenHarmony SDK 3.2.3.5, stage model of API version 9

Use **window.getProperties()** to obtain the window properties. The **windowRect** field in the properties specifies the window width and height.

Example:


```
let promise = windowClass.getProperties();
promise.then((data)=> {
  console.info('Succeeded in obtaining the window properties. Data: ' + JSON.stringify(data.windowRect));
}).catch((err)=>{
  console.error('Failed to obtain the window properties. Cause: ' + JSON.stringify(err));
});
```

## How do I set the color of the system bar?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

Refer to the following code:


```
window.getTopWindow(globalThis.mainContext).then(win => {
  var systemBarProperties = {
    statusBarColor: '#19B6FF', // Set the background color of the status bar.
    navigationBarColor: '#19B6FF', // Set the background color of the navigation bar.
    isStatusBarLightIcon: false, // Set the icon on the status bar not to be highlighted.
    isNavigationBarLightIcon: true, // Set the icon on the navigation bar to be highlighted.
    statusBarContentColor: '#0D0500', // Set the text color of the status bar.
    navigationBarContentColor: '#FFA500' // Set the text color of the navigation bar.
  };
  win.setSystemBarProperties(systemBarProperties).catch(err => {
    INDEX_LOGGER.info(`set System Bar Properties failed:${err}`)
  })
})
.catch(err => {
  INDEX_LOGGER.info(`get top window failed:${err}`)
})
```
