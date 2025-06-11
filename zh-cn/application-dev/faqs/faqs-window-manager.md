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

[窗口基础能力文档](../reference/apis-arkui/arkts-apis-window-Window.md)

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

[window.Orientation](../reference/apis-arkui/arkts-apis-window-e.md#orientation9)

## 调用Window实例的setWindowSystemBarProperties接口设置窗口状态栏和导航栏的高亮属性时不生效(API 9)

适用于Stage模型。

**解决措施**

状态栏字体高亮属性的本质就只是让字体变成白色。调用window实例的setWindowSystemBarProperties接口时，如果设置了状态栏内容颜色statusBarContentColor，就以开发者设置的颜色为准，isStatusBarLightIcon状态栏字体高亮属性就不生效；同理，如果设置了导航栏内容颜色navigationBarContentColor，isNavigationBarLightIcon导航栏字体高亮属性就不生效。

**参考链接**

[window.SystemBarProperties](../reference/apis-arkui/arkts-apis-window-i.md#systembarproperties)


## 如何保持屏幕常亮(API 9)

**解决措施**

设置屏幕常亮，不熄屏。

获取窗口实例对象后，调用[setWindowKeepScreenOn方法](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowkeepscreenon9)可设置屏幕是否常亮。

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

获取窗口实例对象后，可以通过[window.on('windowSizeChange')](../reference/apis-arkui/arkts-apis-window-Window.md#onwindowsizechange7)方法实现对窗口尺寸大小变化的监听。

需要注意的是，在window侧如果窗口大小没发生变化，此监听不会被触发。如直接旋转180度的情况下，窗口大小并没有改变，此时不会通知回调。在这种情况下，应用可以通过监听[display.on('change')](../reference/apis-arkui/js-apis-display.md#displayonaddremovechange)事件，在callback中通过display接口来获取窗口尺寸大小。

```
try {
    windowClass.on('windowSizeChange', (data) => {
        console.info('Succeeded in enabling the listener for window size changes. Data: ' + JSON.stringify(data)); 
   });
} catch (exception) {
    console.error('Failed to enable the listener for window size changes. Cause: ' + JSON.stringify(exception));
}
```

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
      window.getLastWindow(this.getUIContext().getHostContext(), (err, data) => { // 获取window实例
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

[设置窗口的显示方向属性](../reference/apis-arkui/arkts-apis-window-Window.md#setpreferredorientation9)  
[开启显示设备变化的监听](../reference/apis-arkui/js-apis-display.md#displayonaddremovechange)

## 在display.on('change')监听回调中，无法使用Window实例获取更新后的窗口大小(API 10)

**解决措施**

旋转涉及[@ohos.window](../reference/apis-arkui/arkts-apis-window.md)和[@ohos.display](../reference/apis-arkui/js-apis-display.md)两个模块，处于不同进程。由于旋转完后display的更新时间早于window的更新时间（display旋转时直接宽高互换，提前可预知；window要等ArkUI布局完成才能确定窗口大小，耗时长），故在display触发变化时获取窗口信息会存在时序问题（窗口信息还未更新完成，此时使用Window实例获取到的还是原来的宽高）。应用可以通过display.on('change')接口监听显示设备变化，在callback中通过Display实例获取屏幕的width、height、orientation等信息。
 
**错误示例**

```ts
// display先更新
display.on('change', async (data) => {
  let newDisplay: display.Display = display.getDefaultDisplaySync();
  console.info('Orientation: ' + newDisplay.orientation);
  let windowClass: window.Window = await window.getLastWindow(this.context);
  // window后更新，获取到的还是原来的宽高
  let windowProperties = windowClass.getWindowProperties();
  console.info('Width: ' + windowProperties.windowRect.width +
    ', height: ' + windowProperties.windowRect.height);
  // 请确保已获取到相关Window实例，即windowClass
  windowClass.getWindowAvoidArea(window.AvoidAreaType.TYPE_CUTOUT);
});
```

**正确示例**

```ts
display.on('change', (data) => {
  console.info('Succeeded in enabling the listener for display changes. Data: ' +
  JSON.stringify(data));
  let newDisplay: display.Display = display.getDefaultDisplaySync();
  console.info('Orientation: ' + newDisplay.orientation + 'width: ' +
  newDisplay.width + ', height: ' + newDisplay.height);
});
```

**参考链接**

[display.on('change')](../reference/apis-arkui/js-apis-display.md#displayonaddremovechange)

## 如何同时获取屏幕方向orientation和系统规避区avoidAreaChange信息(API 10)

可以通过[on('avoidAreaChange')](../reference/apis-arkui/arkts-apis-window-Window.md#onavoidareachange9)接口监听窗口系统规避区域的变化，在callback中获取avoidAreaChange信息，并通过Display实例获取屏幕方向orientation等信息。

```ts
// 请确保已获取到相关Window实例，即windowClass
windowClass.on('avoidAreaChange', async (data) => {
  console.info('Succeeded in enabling the listener for avoid area changes. Type: ' +
    JSON.stringify(data.type) + ', area ' + JSON.stringify(data.area));
  let newDisplay: display.Display = display.getDefaultDisplaySync();
  console.info('Orientation: ' + newDisplay.orientation);
  let windowClass: window.Window = await window.getLastWindow(this.context);
  windowClass.getWindowAvoidArea(window.AvoidAreaType.TYPE_CUTOUT);
});
```

## 在display.on('foldDisplayModeChange')监听回调中，使用display.getDefaultDisplaySync获取当前屏幕宽高错误(API10)

**解决措施**

对于强制横屏应用，在设备发生折叠开合动作时，会触发foldDisplayModeChange，此时Display里对应旋转属性还未更新，导致通过getDefaultDisplaySync获取到的宽高为设备竖屏的宽高。应用可以通过display.on('change')接口监听显示设备变化，在回调函数中通过Display实例获取屏幕的宽高等信息。

**代码示例**

```ts
display.on('change', (data) => {
  console.info('Succeeded in enabling the listener for display changes. Data: ' +
  JSON.stringify(data));
  let newDisplay: display.Display = display.getDefaultDisplaySync();
  console.info('width: ' + newDisplay.width + ', height: ' + newDisplay.height);
});
```

**参考链接**

[display.on('change')](../reference/apis-arkui/js-apis-display.md#displayonaddremovechange)

## 窗口Orientation枚举值8\~10或12和枚举值13\~16的区别(API9)

1. 窗口设置8\~10或12，会跟随传感器自动旋转，且受控制中心的旋转开关控制。
2. 窗口设置13\~16，会临时旋转到指定方向（如：13会临时旋转到竖屏），之后跟随传感器自动旋转，受控制中心的旋转开关控制，且可旋转方向受系统判定。

两者的区别是，调用13\~16时会临时旋转到指定方向，且前后台切换时窗口方向保持，而调用8\~10或12前后台切换时窗口方向不会保持。

**场景举例：**
1. 竖持手机，关闭旋转锁定开关 -> 应用设置方向为AUTO_ROTATION_RESTRICTED -> 将手机旋转为横屏（**应用方向为横屏**） -> 应用退出后台进入桌面，竖持手机（方向为竖屏） -> 应用切换至前台（**应用方向为竖屏**） 
2. 竖持手机，关闭旋转锁定开关 -> 应用设置方向为USER_ROTATION_PORTRAIT（**应用方向为竖屏**） -> 将手机旋转为横屏（**应用方向为横屏**） -> 应用退出后台进入桌面，竖持手机（方向为竖屏） -> 应用切换至前台（**应用方向为横屏**） 

| 名称                               | 值  | 可旋转方向           | 是否跟随传感器自动旋转 | 是否受旋转开关控制 |
|----------------------------------|----|-----------------|-------------|-----------|
| AUTO_ROTATION_RESTRICTED         | 8  | 横屏、竖屏、反向竖屏、反向横屏 | 是           | 是         |
| AUTO_ROTATION_PORTRAIT_RESTRICTED         | 9  | 竖屏、反向竖屏 | 是           | 是         |
| AUTO_ROTATION_LANDSCAPE_RESTRICTED         | 10 | 横屏、反向横屏 | 是           | 是         |
| AUTO_ROTATION_UNSPECIFIED         | 12  | 受系统判定 | 是           | 是         |
| USER_ROTATION_PORTRAIT           | 13 | 受系统判定           | 是           | 是         |
| USER_ROTATION_LANDSCAPE          | 14 | 受系统判定           | 是           | 是         |
| USER_ROTATION_PORTRAIT_INVERTED  | 15 | 受系统判定           | 是           | 是         |
| USER_ROTATION_LANDSCAPE_INVERTED | 16 | 受系统判定           | 是           | 是         |

<!--no_check-->