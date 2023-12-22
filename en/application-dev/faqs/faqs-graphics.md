# Graphics Development


## How do I obtain the DPI of a device? (API version 9)

**Solution**

Import the **\@ohos.display** module and call the **getDefaultDisplaySync()** API.

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


## How do I obtain the window width and height? (API version 9)

**Solution**

Import the **\@ohos.window** module, obtain a **Window** object, and use **getWindowProperties()** of the object to obtain the window properties. The **windowRect** field in the properties specifies the window width and height.

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


## How do I perform Gaussian blurring on images? (API version 9)

**Solution**

Import the **\@ohos.multimedia.image** and **\@ohos.effectKit** modules to process the image and add the blur effect.

**Example**

```
import image from "@ohos.multimedia.image";
import effectKit from "@ohos.effectKit";

  const color = new ArrayBuffer(96);
  let opts = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } };
  image.createPixelMap(color, opts).then((pixelMap) => {
    let radius = 5;  
    let headFilter = effectKit.createEffect(pixelMap);  
    if (headFilter != null) {
      headFilter.blur(radius);
    }
  })
```

**References**

[blur](../reference/apis/js-apis-effectKit.md#blur)
