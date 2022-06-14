# Window Development

## When to Use
The interface layer of the window runs in the application process. It loads the page layout and provides APIs.
By calling these APIs, you can create and destroy a window, set the position and size of a window, and enter the immersive mode (full-screen mode).

## Available APIs
For details about the APIs, see [Window](../reference/apis/js-apis-window.md).

**Table 1** Main window APIs

| API                                                      | Description                                          |
| :----------------------------------------------------------- | :--------------------------------------------- |
| create(id: string, type: WindowType, callback: AsyncCallback\<Window>): void | Creates a subwindow.                                  |
| moveTo(x: number, y: number): Promise\<void>                 | Moves the window. A positive value of **x** indicates that the window moves to the right, and a positive value of **y** indicates that the window moves downwards.|
| resetSize(width: number, height: number): Promise\<void>     | Changes the window size.                            |
| hide(): Promise\<void>                                       | Hides the window.                                |
| destroy(): Promise\<void>                                    | Destroys the window.                                |

## How to Develop

### Creating a Main Window

Currently, the main window is automatically created when the application is started. The declaration period, hiding, and destruction of the main window are managed by the application.
### Creating a Subwindow
You can call **create** to create a subwindow. The sample code is as follows:

```js
 import window from '@ohos.window';
 var windowClass = null;
 let promise = window.create("subWindow", window.WindowType.TYPE_APP);
 promise.then((data)=> {
 	windowClass = data;
    console.info('SubWindow created. Data: ' + JSON.stringify(data))
 }).catch((err)=>{
    console.error('Failed to create the subWindow. Cause: ' + JSON.stringify(err));
 });
```

### Obtaining a Window Object

- Call **getTopWindow** to obtain the top window of the application. The sample code is as follows:

```js
 var windowClass = null;
 let promise = window.getTopWindow();
 promise.then((data)=> {
 	windowClass = data;
    console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data))
 }).catch((err)=>{
    console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(err));
 })
```

- You can also call **find** to obtain created subwindows in the application. The sample code is as follows:

```js
 var windowClass = null;
 let promise = window.find("subWindow");
 promise.then((data)=> {
 	windowClass = data;
    console.info('window found. Data: ' + JSON.stringify(data))
 }).catch((err)=>{
    console.error('Failed to find the Window. Cause: ' + JSON.stringify(err));
 });
```

### Hiding and Destroying a Window

After a window object is obtained, you can call **hide** and **destroy** to hide and destroy the window object, respectively. The sample code is as follows:

```js
 let promise = windowClass.hide();
 promise.then((data)=> {
    console.info('window hidden. Data: ' + JSON.stringify(data))
    windowClass.destroy((err, data) => {
        if (err.code) {
            console.error('Failed to destroy the window. Cause:' + JSON.stringify(err));
            return;
        }
    	console.info('Succeeded in destroying the window. Data: ' + JSON.stringify(data))
	})
 }).catch((err)=>{
    console.error('Failed to hide the window. Cause: ' + JSON.stringify(err));
 })
```

### Enabling the Full-Screen Mode

After a window object is obtained, you can call **setFullScreen** to enable the full-screen mode for the window.

The sample code is as follows:

```js
import window from '@ohos.window';
try {
  const win = await window.getTopWindow()
  await win.setFullScreen(true)
} catch (err) {
  console.log(`setFullScreen fail, code = ${err.code}`)
}
```

