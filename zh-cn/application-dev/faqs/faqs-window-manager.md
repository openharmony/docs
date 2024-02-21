# 窗口管理开发常见问题


## 如何获取状态栏和导航栏高度(API 9)

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


## 应用如何设置隐藏顶部的状态栏(API 9)

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

[窗口基础能力文档](../reference/apis-arkui/js-apis-window.md)

## 如何锁定设备竖屏，使得窗口不随屏幕旋转(API 9)

适用于Stage模型。

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
//2.窗口实例使用setPreferredOrientation方法，设置窗口的显示方向，PORTRAIT为固定竖屏，其他方向可参照参考链接
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

[window.Orientation](../reference/apis-arkui/js-apis-window.md#orientation9)

## 调用Window实例的setWindowSystemBarProperties接口设置窗口状态栏和导航栏的高亮属性时不生效(API 9)

适用于Stage模型。

**解决措施**

状态栏字体高亮属性的本质就只是让字体变成白色。调用window实例的setWindowSystemBarProperties接口时，如果设置了状态栏内容颜色statusBarContentColor，就以开发者设置的颜色为准，isStatusBarLightIcon状态栏字体高亮属性就不生效；同理，如果设置了导航栏内容颜色navigationBarContentColor，isNavigationBarLightIcon导航栏字体高亮属性就不生效。

**参考链接**

[window.SystemBarProperties](../reference/apis-arkui/js-apis-window.md#systembarproperties)


## 如何保持屏幕常亮(API 9)

**解决措施**

设置屏幕常亮，不熄屏。

获取窗口实例对象后，调用[setWindowKeepScreenOn方法](../reference/apis-arkui/js-apis-window.md#setwindowkeepscreenon9)可设置屏幕是否常亮。

**代码示例**

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


## 如何监听窗口大小的变化(API 9)

**解决措施**

获取窗口实例对象后，可以通过窗口的on('windowSizeChange')方法实现对窗口尺寸大小变化的监听

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

[window.on\("windowSizeChange"\)](../reference/apis-arkui/js-apis-window.md#onwindowsizechange7)

## 如何监听当前屏幕的横竖屏状态(API 10)

**解决措施**

应用可以通过display.on监听屏幕状态改变。  

**参考链接**

[开启显示设备变化的监听](../reference/apis-arkui/js-apis-display.md#displayonaddremovechange)

## 如何实现页面跟随屏幕横竖屏自动旋转(API 10)

**解决措施**

1.Abilty级别配置：在模块配置文件module.json5中将EntryAbility设置为"orientation"。  
2.动态设置：使用window.setPreferredOrientation设置窗口方向。

**代码示例**
```ts
import window from '@ohos.window';
import display from '@ohos.display';

const TAG = 'foo'
const ORIENTATION: Array<string> = ['垂直', '水平', '反向垂直', '反向水平']

@Entry
@Component
struct ScreenTest {
  @State rotation: number = 0
  @State message: string = ORIENTATION[this.rotation]

  aboutToAppear() {
    this.setOrientation()

    let callback = async () => {
      let d = await display.getDefaultDisplaySync()
      this.rotation = d.rotation
      this.message = ORIENTATION[this.rotation]
      console.info(TAG, JSON.stringify(d))
    }
    try {
      display.on("change", callback); // 监听屏幕状态改变
    } catch (exception) {
      console.error(TAG, 'Failed to register callback. Code: ' + JSON.stringify(exception));
    }
  }

  setOrientation() {
    try {
      window.getLastWindow(getContext(this), (err, data) => { // 获取window实例
        if (err.code) {
          console.error(TAG, 'Failed to obtain the top window. Cause: ' + JSON.stringify(err));
          return;
        }
        let windowClass = data;
        console.info(TAG, 'Succeeded in obtaining the top window. Data: ' + JSON.stringify(data));

        let orientation = window.Orientation.AUTO_ROTATION; // 设置窗口方向为传感器自动旋转模式。
        try {
          windowClass.setPreferredOrientation(orientation, (err) => {
            if (err.code) {
              console.error(TAG, 'Failed to set window orientation. Cause: ' + JSON.stringify(err));
              return;
            }
            console.info(TAG, 'Succeeded in setting window orientation.');
          });
        } catch (exception) {
          console.error(TAG, 'Failed to set window orientation. Cause: ' + JSON.stringify(exception));
        }
        ;
      });
    } catch (exception) {
      console.error(TAG, 'Failed to obtain the top window. Cause: ' + JSON.stringify(exception));
    }
    ;
  }

  build() {
    Row() {
      Column() {
        Text(`${this.rotation}`).fontSize(25)
        Text(`${this.message}`).fontSize(25)
      }
      .width("100%")
    }
    .height("100%")
  }
}
```
**参考链接**

[设置窗口的显示方向属性](../reference/apis-arkui/js-apis-window.md#setpreferredorientation9)  
[开启显示设备变化的监听](../reference/apis-arkui/js-apis-display.md#displayonaddremovechange)

<!--no_check-->



