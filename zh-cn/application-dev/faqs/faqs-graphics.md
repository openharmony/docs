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

[图片添加模糊效果](../reference/apis/js-apis-effectKit.md#blur)

