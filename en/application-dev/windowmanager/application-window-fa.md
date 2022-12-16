# Application Window Development (FA Model)

## Basic Concepts

Immersive window: System windows such as the status bar and navigation bar are controlled in such a way that they are unobtrusive and natural looking in the entire screen, thereby engaging users more deeply with the content displayed.
The immersive window feature is valid only when the main window of an application is displayed in full-screen mode. It does not apply to a main window in free window mode or a subwindow (for example, a dialog box or a floating window).

## When to Use

In the FA model, you can perform the following operations during application window development:

- Setting the properties and content of the subwindow of an application

- Experiencing the immersive window feature


## Available APIs

The table below lists the common APIs used for application window development. For details about more APIs, see [Window](../reference/apis/js-apis-window.md).

| Instance| API| Description|
| -------- | -------- | -------- |
| Window static method| createWindow(config: Configuration, callback: AsyncCallback\<Window>): void | Creates a subwindow.<br>**config** specifies the parameters used for creating the window.|
| Window static method| findWindow(id: string, callback: AsyncCallback&lt;Window&gt;): void | Finds a window based on the ID.|
| Window | SetUIContent(path: string, callback: AsyncCallback&lt;void&gt;): void | Loads the page content to this window.|
| Window | moveWindowTo(x: number, y: number, callback: AsyncCallback&lt;void&gt;): void | Moves this window.|
| Window | setWindowBackgroundColor(color: string, callback: AsyncCallback&lt;void&gt;): void | Sets the background color for this window.|
| Window | setWindowBrightness(brightness: number, callback: AsyncCallback&lt;void&gt;): void | Sets the brightness for this window.|
| Window | resize(width: number, height: number, callback: AsyncCallback&lt;void&gt;): void | Changes the window size.|
| Window | setWindowLayoutFullScreen(isLayoutFullScreen: boolean, callback: AsyncCallback&lt;void&gt;): void | Sets whether to enable the full-screen mode for the window layout. |
| Window | setWindowSystemBarEnable(names: Array&lt;'status'\|'navigation'&gt;): Promise&lt;void&gt; | Sets whether to display the status bar and navigation bar in this window.|
| Window | setWindowSystemBarProperties(systemBarProperties: SystemBarProperties, callback: AsyncCallback&lt;void&gt;): void | Sets the properties of the status bar and navigation bar in this window.<br>**systemBarProperties**: properties of the status bar and navigation bar.|
| Window | showWindow(callback: AsyncCallback\<void>): void | Shows this window.|
| Window | on(type: 'touchOutside', callback: Callback&lt;void&gt;): void | Enables listening for click events outside this window.|
| Window | destroyWindow(callback: AsyncCallback&lt;void&gt;): void | Destroys this window.|


## Setting the Subwindow of an Application

You can create a subwindow, such as a dialog box, and set its properties.


### How to Develop

1. Create or obtain a subwindow.

   - Call **window.createWindow** to create a subwindow.
   - Call **window.findWindow** to find an available subwindow.
   
```js
   import window from '@ohos.window';
   
   let windowClass = null;
   // Method 1: Create a subwindow.
   let config = {name: "subWindow", windowType: window.WindowType.TYPE_APP, ctx: this.context};
   window.createWindow(config, (err, data) => {
       if (err.code) {
           console.error('Failed to create the subWindow. Cause: ' + JSON.stringify(err));
           return;
       }
       console.info('Succeeded in creating subWindow. Data: ' + JSON.stringify(data));
       windowClass = data;
   });
   // Method 2: Find a subwindow.
   window.findWindow("subWindow", (err, data) => {
       if (err.code) {
           console.error('Failed to find the subWindow. Cause: ' + JSON.stringify(err));
           return;
       }
       console.info('Succeeded in finding subWindow. Data: ' + JSON.stringify(data));
       windowClass = data;
   });
```

2. Set the properties of the subwindow.

   After the subwindow is created, you can set its properties, such as the size, position, background color, and brightness.
   
   ```js
   // Move the subwindow.
   windowClass.moveWindowTo(300, 300, (err) => {
     if (err.code) {
       console.error('Failed to move the window. Cause:' + JSON.stringify(err));
       return;
     }
     console.info('Succeeded in moving the window.');
   });
   // Change the size of the subwindow.
   windowClass.resize(500, 500, (err) => {
     if (err.code) {
       console.error('Failed to change the window size. Cause:' + JSON.stringify(err));
       return;
     }
     console.info('Succeeded in changing the window size.');
   });
   ```

3. Load content for the subwindow and show it.

   Call **SetUIContent** and **showWindow** to load and display the content in the subwindow.
   
   ```js
   // Load the page content to the subwindow.
   windowClass.SetUIContent("pages/page2", (err) => {
       if (err.code) {
           console.error('Failed to load the content. Cause: ' + JSON.stringify(err));
           return;
       }
       console.info('Succeeded in loading the content.');
       // Show the subwindow.
       windowClass.showWindow((err) => {
        if (err.code) {
               console.error('Failed to show the window. Cause: ' + JSON.stringify(err));
               return;
           }
           console.info('Succeeded in showing the window.');
       });
   });
   ```
   
4. Destroy the subwindow.

   When the subwindow is no longer needed, you can call **destroyWindow** to destroy it.
   
   ```js
   // Call destroy() to destroy the subwindow when it is no longer needed.
   windowClass.destroyWindow((err) => {
       if (err.code) {
           console.error('Failed to destroy the subwindow. Cause:' + JSON.stringify(err));
           return;
       }
       console.info('Succeeded in destroying the subwindow.');
   });
   ```


## Experiencing the Immersive Window Feature

To create a better video watching and gaming experience, you can use the immersive window feature to hide the system windows, including the status bar and navigation bar. To achieve this effect, you can use the immersive window feature, which is available only for the main window of an application.


### How to Develop

1. Obtain the main window.

   > **NOTE**
   >
   > The immersive window feature can be implemented only after the main window is obtained.
   >
   > Ensure that the top window of the application is the main window. You can use **window.getLastWindow** to obtain the main window.
   
   ```js
   import window from '@ohos.window';
   
   let mainWindowClass = null;
   // Obtain the main window.
   window.getLastWindow((err, data) => {
     if (err.code) {
       console.error('Failed to get the subWindow. Cause: ' + JSON.stringify(err));
       return;
     }
     console.info('Succeeded in getting subWindow. Data: ' + JSON.stringify(data));
     mainWindowClass = data;
   });
   ```

2. Implement the immersive effect. You can use any of the following methods:

   - Method 1: Call **setWindowSystemBarEnable** to hide the navigation bar and status bar.
   - Method 2: Call **setWindowLayoutFullScreen** to enable the full-screen mode for the main window layout. Call **setSystemProperties** to set the opacity, background color, text color, and highlighted icon of the navigation bar and status bar to ensure that their display effect is consistent with that of the main window.

   ```js
   
   // Use method 1 to implement the immersive effect.
   let names = [];
   mainWindowClass.setWindowSystemBarEnable(names, (err) => {
     if (err.code) {
       console.error('Failed to set the system bar to be visible. Cause:' + JSON.stringify(err));
       return;
     }
     console.info('Succeeded in setting the system bar to be visible.');
   });
   // Use method 2 to implement the immersive effect. 
   let isLayoutFullScreen = true;
   mainWindowClass.setWindowLayoutFullScreen(isLayoutFullScreen, (err) => {
     if (err.code) {
       console.error('Failed to set the window layout to full-screen mode. Cause:' + JSON.stringify(err));
       return;
     }
     console.info('Succeeded in setting the window layout to full-screen mode.');
   });
   let sysBarProps = {
     statusBarColor: '#ff00ff',
     navigationBarColor: '#00ff00',
     // The following properties are supported since API version 8.
     statusBarContentColor: '#ffffff',
     navigationBarContentColor: '#ffffff'
   };
   mainWindowClass.setWindowSystemBarProperties(sysBarProps, (err) => {
     if (err.code) {
       console.error('Failed to set the system bar properties. Cause: ' + JSON.stringify(err));
       return;
     }
     console.info('Succeeded in setting the system bar properties.');
   });
   ```
   
3. Load content for the immersive window and show it.

   Call **SetUIContent** and **showWindow** to load and display the content in the immersive window.
   
   ```js
   // Load the page content to the immersive window.
   mainWindowClass.SetUIContent("pages/page3", (err) => {
       if (err.code) {
           console.error('Failed to load the content. Cause: ' + JSON.stringify(err));
           return;
       }
       console.info('Succeeded in loading the content.');
       // Show the immersive window.
       mainWindowClass.showWindow((err) => {
           if (err.code) {
               console.error('Failed to show the window. Cause: ' + JSON.stringify(err));
               return;
           }
           console.info('Succeeded in showing the window.');
       });
   });
   ```
