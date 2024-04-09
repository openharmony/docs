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

[blur](../reference/apis-arkgraphics2d/js-apis-effectKit.md#blur)


## Can EGL operations be performed in subthreads? (API version 10)

**Solution**

Yes. You can create **SharedContext** to implement EGL operations in subthreads.  

**Example**
```cpp
void CreateShareEglContext()
{
  if (renderContext == nullptr) { // renderContext is the context of the main thread.
      RS_LOGE("renderContext_ is nullptr");
      return;
  }
  eglShareContext = renderContext->CreateShareContext();
  if (eglShareContext == EGL_NO_CONTEXT) {
      RS_LOGE("eglShareContext is EGL_NO_CONTEXT");
      return;
  }
  if (!eglMakeCurrent(renderContext->GetEGLDisplay(), EGL_NO_SURFACE, EGL_NO_SURFACE, eglShareContext)) {
      RS_LOGE("eglMakeCurrent failed");
      return;
  }
}
```

## How do I draw a custom animation using EGL? (API version 10)

**Solution**

Use OpenGL APIs to draw a custom animation.

To implement a custom animation, code the logic of the service party so that the service party can identify animation trigger events, obtain the start and end of the animation based on the service requirements, and calculate the content of each frame to draw based on the time axis and animation curve. After that, you can draw the content by calling the OpenGL APIs.

**References** 

[Native XComponent Usage (ArkTS)](https://gitee.com/openharmony/codelabs/tree/master/NativeAPI/XComponent)

## How do I operate a buffer to draw graphics in the EGL multithreaded drawing scenario? (API version 10)

**Solution**

You can generate a texture through each thread, and then combine the textures into a buffer.

You can use **SharedContext** to implement EGL operations in subthreads. You can call OpenGL APIs for the drawing operation.

**Example**
```cpp
void CreateShareEglContext()
{
  if (renderContext == nullptr) { // renderContext is the context of the main thread.
      RS_LOGE("renderContext_ is nullptr");
      return;
  }
  eglShareContext = renderContext->CreateShareContext();
  if (eglShareContext == EGL_NO_CONTEXT) {
      RS_LOGE("eglShareContext is EGL_NO_CONTEXT");
      return;
  }
  if (!eglMakeCurrent(renderContext->GetEGLDisplay(), EGL_NO_SURFACE, EGL_NO_SURFACE, eglShareContext)) {
      RS_LOGE("eglMakeCurrent failed");
      return;
  }
}
```
## Can a custom transition animation be used during an ability migration? If yes, how can I implement it? (API version 10)

**Solution**

No, a custom transition animation cannot be used. The UIAbility displays only one widget on the Recents screen. No customization is allowed for consistency purposes.

The UIAbility cannot be used to combine in-app screens. Instead, use the **\<Navigation>** component to implement in-app redirection.

**References**

[Navigation](../ui/arkts-navigation-navigation.md)
