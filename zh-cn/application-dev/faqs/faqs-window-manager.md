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
  mainWindow.on("systemBarTintChange", (data) => {
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

