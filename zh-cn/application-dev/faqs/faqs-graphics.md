# 图形图像开发常见问题

## 调用window实例的setSystemBarProperties接口时，设置isStatusBarLightIcon和isNavigationBarLightIcon属性不生效 

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

状态栏字体高亮属性的本质就只是让字体变成白色。调用window实例的setSystemBarProperties接口时，如果设置了状态栏内容颜色statusBarContentColor，就以开发者设置的颜色为准，isStatusBarLightIcon状态栏字体高亮属性就不生效；同理，如果设置了导航栏内容颜色navigationBarContentColor，isNavigationBarLightIcon导航栏字体高亮属性就不生效。

## 如何设置系统状态栏样式

适用于：OpenHarmony SDK 3.2.3.5版本，API9 Stage模型

导入\@ohos.window模块，开发者可以使用window.setSystemBarProperties()接口设置状态栏样式属性，达到自定义样式的效果。

## 如何隐藏状态栏，实现沉浸式效果。

适用于：OpenHarmony SDK 3.2.6.3版本，API9 Stage模型

1. 可以在onWindowStageCreate方法获取windowClass对象。
     
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

2. 设置窗口全屏，隐藏状态栏。
     
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

适用于：OpenHarmony SDK 3.2.3.5版本，API9 Stage模型

通过\@ohos.window模块，可以使用getProperties()接口获取窗口属性，然后通过窗口属性的windowRect获取窗口宽高信息

示例：

  
```
let promise = windowClass.getProperties();
promise.then((data)=> {
  console.info('Succeeded in obtaining the window properties. Data: ' + JSON.stringify(data.windowRect));
}).catch((err)=>{
  console.error('Failed to obtain the window properties. Cause: ' + JSON.stringify(err));
});
```

## 如何设置系统状态栏颜色

适用于：OpenHarmony SDK 3.2.5.5版本，API9 Stage模型

参考如下方式实现，示例：

  
```
window.getTopWindow(globalThis.mainContext).then(win => {
  var systemBarProperties = {
    statusBarColor: '#19B6FF', // 状态栏背景颜色
    navigationBarColor: '#19B6FF', // 导航栏背景颜色
    isStatusBarLightIcon: false, // 状态栏图标是否为高亮状态。
    isNavigationBarLightIcon: true, // 导航栏图标是否为高亮状态。
    statusBarContentColor: '#0D0500', // 状态栏文字颜色
    navigationBarContentColor: '#FFA500' // 导航栏文字颜色
  };
  win.setSystemBarProperties(systemBarProperties).catch(err => {
    INDEX_LOGGER.info(`set System Bar Properties failed:${err}`)
  })
})
.catch(err => {
  INDEX_LOGGER.info(`get top window failed:${err}`)
})
```
