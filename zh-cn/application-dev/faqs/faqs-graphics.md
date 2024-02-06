# 图形图像开发常见问题


## 如何获取设备的dpi值(API 9)

**解决措施**

导入\@ohos.display包，通过getDefaultDisplaySync()方法获取。

**代码示例**

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


## 如何获取窗口的宽高信息(API 9)

**解决措施**

引入窗口模块\@ohos.window，获取指定窗口对象Window后，在该对象上使用getWindowProperties()获取窗口各个属性，在属性windowRect中获取窗口宽高信息。

**代码示例**

```
import window from '@ohos.window';
let windowClass = null;
try {    
    let promise = window.getLastWindow(this.context);
    promise.then((data)=> {
        //获取窗口对象
        windowClass = data;
        try {
            //获取窗口属性
            let properties = windowClass.getWindowProperties();
            let rect = properties.windowRect;
            //rect.width: 窗口宽度；rect.height: 窗口高度
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


## 如何对图片进行高斯模糊处理(API 9)

**解决措施**

导入图像处理（\@ohos.multimedia.image）和图像效果（\@ohos.effectKit）模块，对图像进行处理并添加模糊效果。

**代码示例**

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
**参考链接：**

[图片添加模糊效果](../reference/apis-arkgraphics2d/js-apis-effectKit.md#blur)


## EGL绘制操作是否只能在主线程，可以放子线程中执行吗(API 10)

**解决措施**

EGL操作可以在子线程中操作，可以通过创建SharedContext，实现EGL在子线程中操作。创建SharedContext示例代码如下。

**代码示例**
```cpp
void CreateShareEglContext()
{
  if (renderContext == nullptr) { // renderContext是主线程context
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

## 如何使用EGL绘制自定义动画(API 10)

**解决措施**

自定义动画需要开发者自主实现，可以采用OpenGL进行绘制。  
关于动画的实现主要是业务方的逻辑，首先业务方需要识别动画触发事件，根据业务诉求获取动画的起点和终点。  
然后根据时间轴和动画曲线计算每一帧的绘制内容。最后调用OpenGL的接口绘制这部分内容。

**参考链接：**  

[Native XComponent组件的使用（ArkTS）](https://gitee.com/openharmony/codelabs/tree/master/NativeAPI/XComponent)

## 如何在EGL多线程绘制的场景下同时操作一块buffer进行图形绘制(API 10)

**解决措施**

可以通过每个线程各自产生一块纹理，再将这些纹理合成到一块buffer。
可以使用sharedContext，实现EGL在子线程中操作。另外绘制操作可通过调用OpenGL实现。

**代码示例**
```cpp
void CreateShareEglContext()
{
  if (renderContext == nullptr) { // renderContext是主线程context
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
## 从一个Ability跳转到另外一个Ability时，是否支持自定义转场动画的设置，如何实现(API 10)

**解决措施**

不支持，UIAbility会在多任务界面只显示一个卡片，为了动效一致性，不开放给开发者定制。  
UIAbility不能用来组合应用内界面，用应用内导航组件Navigation来实现应用内的跳转。

**参考链接：**

[Navigation的使用](../ui/arkts-navigation-navigation.md)




