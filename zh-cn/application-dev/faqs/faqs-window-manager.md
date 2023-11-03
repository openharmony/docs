# 窗口管理开发常见问题

## 如何获取状态栏和导航栏高度

适用于OpenHarmony 3.2 Beta5  API 9

**解决措施**

在加载窗口内容之前，采用systemAvoidAreaChange事件监听。

**代码示例**

```
// MainAbility.ts
import window from '@ohos.window';

/**
 * 设置沉浸式窗口，并获取状态栏和导航栏高度
 * @param mainWindow 主窗口对象
 */
async function enterImmersion(mainWindow: window.Window) { 
  window.on("systemBarTintChange", (data) => {
    let avoidAreaRect = data.regionTint[0].region; //data.regionTint是个数组，包含状态栏、导航栏的矩形区域坐标。
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
  // do something
  async onWindowStageCreate(windowStage: window.WindowStage) {
    let mainWindow = await windowStage.getMainWindow()
    await enterImmersion(mainWindow)
    windowStage.loadContent('pages/index')
  }
  // do something
}
```

## 应用如何设置隐藏顶部的状态栏

适用于OpenHarmony 3.2 Beta5  API 9

**解决措施**

在UIAbility的onWindowStageCreate的生命周期中设置setWindowSystemBarEnable接口即可。

**代码示例**

```
onWindowStageCreate(windowStage){
  windowStage.getMainWindowSync().setWindowSystemBarEnable([])
  ......
}
```

**参考链接**

[窗口基础能力文档](../reference/apis/js-apis-window.md)

## 如何锁定设备竖屏，使得窗口不随屏幕旋转

适用于：OpenHarmony SDK 3.2 Beta5 API 9 Stage模型  

**解决措施**

采用窗口的setPreferredOrientation方法可以实现该效果，将orientation参数设置为window.Orientation.PORTRAIT时，可锁定屏幕为竖屏。

**代码示例**

```
import window from "@ohos.window";
//1.获取窗口实例对象，新建窗口使用createWindow方法，获取已有的窗口使用findWindow方法
let windowClass = null;
let config = {name: "alertWindow", windowType: window.WindowType.TYPE_SYSTEM_ALERT, ctx: this.context};
try {
    let promise = window.createWindow(config);
    promise.then((data)=> {
        windowClass = data;
        console.info('Succeeded in creating the window. Data:' + JSON.stringify(data));
    }).catch((err)=>{
        console.error('Failed to create the Window. Cause:' + JSON.stringify(err));
    });} catch (exception) {
    console.error('Failed to create the window. Cause: ' + JSON.stringify(exception));
}
//2.窗口实例使用setPreferredOrientation方法，设置窗口的显示方向，PROTRAIT为固定竖屏，其他方向可参照参考链接
let orientation = window.Orientation.PORTRAIT;
if (windowClass) {
    windowClass.setPreferredOrientation(orientation, (err) => {
        if (err.code) {
            console.error('Failed to set window orientation. Cause: ' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in setting window orientation.');
}
```

**参考链接**

[window.Orientation](../reference/apis/js-apis-window.md#orientation9)

## 调用Window实例的setWindowSystemBarProperties接口设置窗口状态栏和导航栏的高亮属性时不生效

适用于：OpenHarmony SDK 3.2 Beta5 API9 Stage模型

**解决措施**

状态栏字体高亮属性的本质就只是让字体变成白色。调用window实例的setWindowSystemBarProperties接口时，如果设置了状态栏内容颜色statusBarContentColor，就以开发者设置的颜色为准，isStatusBarLightIcon状态栏字体高亮属性就不生效；同理，如果设置了导航栏内容颜色navigationBarContentColor，isNavigationBarLightIcon导航栏字体高亮属性就不生效。

**参考链接**

[window.SystemBarProperties](../reference/apis/js-apis-window.md#systembarproperties)

## 如何保持屏幕常亮

适用于：OpenHarmony 3.2 Beta5 API9  

**解决措施**

设置屏幕常亮，不熄屏。

获取窗口实例对象后，调用[setWindowKeepScreenOn方法](../reference/apis/js-apis-window.md#setwindowkeepscreenon9)可设置屏幕是否常亮。

```
let isKeepScreenOn = true;
try {
    windowClass.setWindowKeepScreenOn(isKeepScreenOn, (err) => {
        if (err.code) {
            console.error('Failed to set the screen to be always on. Cause: ' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in setting the screen to be always on.');
    });
} catch (exception) {
    console.error('Failed to set the screen to be always on. Cause: ' + JSON.stringify(exception));
}
```

## 如何监听窗口大小的变化

适用于：OpenHarmony 3.2 Beta5 API9

**解决措施**

获取窗口实例对象后，可以通过窗口的on\('windowSizeChange'\)方法实现对窗口尺寸大小变化的监听

```
try {
    windowClass.on('windowSizeChange', (data) => {
        console.info('Succeeded in enabling the listener for window size changes. Data: ' + JSON.stringify(data)); 
   });
} catch (exception) {
    console.error('Failed to enable the listener for window size changes. Cause: ' + JSON.stringify(exception));
}
```

**参考链接**

[window.on\("windowSizeChange"\)](../reference/apis/js-apis-window.md#onwindowsizechange7)

