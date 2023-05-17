# 图形图像开发常见问题

## 如何获取设备的dpi值

适用于：OpenHarmony 3.2 Beta5，API 9 Stage模型

**解决措施**

导入@ohos.display包，通过getDefaultDisplaySync\(\)方法获取。

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

## 如何隐藏状态栏实现沉浸式效果

适用于：OpenHarmony 3.2 Beta5，API 9 Stage模型  

**解决措施**

1.  可以在onWindowStageCreate方法获取windowClass对象。

    ```
    onWindowStageCreate(windowStage) {
      // Main window is created, set main page for this ability
      console.log("[Demo] MainAbility onWindowStageCreate")
      windowStage.getMainWindow((err, data) => {
        if (err.code) {
          console.error('Failed to obtain the main window.')
          return;
        }
        // 获取到窗口对象
        globalThis.windowClass = data; 
      })
    }
    ```

2.  设置窗口全屏，隐藏状态栏。

    ```
     globalThis.windowClass.setFullScreen(isFullScreen, (err, data) => {
      if (err.code) {
        console.error('Failed to enable the full-screen mode. Cause:' + JSON.stringify(err));
        return;
      }
        console.info('Succeeded in enabling the full-screen mode. Data: ' + JSON.stringify(data));
      });
    ```


## 如何获取窗口的宽高信息

适用于：OpenHarmony SDK 3.2 Beta5，API 9 Stage模型  

**解决措施**

引入窗口模块@ohos.window，获取指定窗口对象Window后，在该对象上使用getWindowProperties\(\)获取窗口各个属性，在属性windowRect中获取窗口宽高信息。

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

