# 管理应用窗口（FA模型）

## 基本概念

窗口沉浸式能力：指对状态栏、导航栏等系统窗口进行控制，减少状态栏导航栏等系统界面的突兀感，从而使用户获得最佳体验的能力。
沉浸式能力只在应用主窗口作为全屏窗口时生效。通常情况下，应用子窗口（弹窗、悬浮窗口等辅助窗口）和处于自由窗口下的应用主窗口无法使用沉浸式能力。

## 场景介绍

在FA模型下，管理应用窗口的典型场景有：

- 设置应用子窗口属性及目标页面

- 体验窗口沉浸式能力

以下分别介绍具体开发方式。


## 接口说明

上述场景涉及的常用接口如下表所示。更多API说明请参见[API参考](../reference/apis/js-apis-window.md)。

| 实例名 | 接口名 | 描述 |
| -------- | -------- | -------- |
| window静态方法 | createWindow(config: Configuration, callback: AsyncCallback<Window>): void | 创建子窗口。<br/>-`config`：创建窗口时的参数。 |
| window静态方法 | findWindow(id: string, callback: AsyncCallback&lt;Window&gt;): void | 查找`id`所对应的窗口。 |
| Window | SetUIContent(path: string, callback: AsyncCallback&lt;void&gt;): void | 为当前窗口加载具体页面内容。 |
| Window | moveWindowTo(x: number, y: number, callback: AsyncCallback&lt;void&gt;): void | 移动当前窗口。 |
| Window | setWindowBackgroundColor(color: string, callback: AsyncCallback&lt;void&gt;): void | 设置窗口的背景色。 |
| Window | setWindowBrightness(brightness: number, callback: AsyncCallback&lt;void&gt;): void | 设置屏幕亮度值。 |
| Window | resize(width: number, height: number, callback: AsyncCallback&lt;void&gt;): void | 改变当前窗口大小。 |
| Window | setWindowLayoutFullScreen(isLayoutFullScreen: boolean, callback: AsyncCallback&lt;void&gt;): void | 设置窗口布局是否为全屏布局。 |
| Window | setWindowSystemBarEnable(names: Array&lt;'status'\|'navigation'&gt;): Promise&lt;void&gt; | 设置导航栏、状态栏是否显示。 |
| Window | setWindowSystemBarProperties(systemBarProperties: SystemBarProperties, callback: AsyncCallback&lt;void&gt;): void | 设置窗口内导航栏、状态栏属性。<br/>`systemBarProperties`：导航栏、状态栏的属性集合。 |
| Window | showWindow(callback: AsyncCallback\<void>): void | 显示当前窗口。 |
| Window | on(type: 'touchOutside', callback: Callback&lt;void&gt;): void | 开启本窗口区域外的点击事件的监听。 |
| Window | destroyWindow(callback: AsyncCallback&lt;void&gt;): void | 销毁当前窗口。 |


## 设置应用子窗口

开发者可以按需创建应用子窗口，如弹窗等，并对其进行属性设置等操作。


### 开发步骤

1. 创建/获取子窗口对象。

   - 可以通过`window.createWindow`接口创建子窗口。
   - 也可以通过`window.findWindow`接口来查找已经创建的窗口从而得到子窗口。
   
```js
   import window from '@ohos.window';
   
   let windowClass = null;
   // 方式一：创建子窗口。
   let config = {name: "subWindow", windowType: window.WindowType.TYPE_APP, ctx: this.context};
   window.createWindow(config, (err, data) => {
       if (err.code) {
           console.error('Failed to create the subWindow. Cause: ' + JSON.stringify(err));
           return;
       }
       console.info('Succeeded in creating subWindow. Data: ' + JSON.stringify(data));
       windowClass = data;
   });
   // 方式二：查找得到子窗口。
   window.findWindow("subWindow", (err, data) => {
       if (err.code) {
           console.error('Failed to find the subWindow. Cause: ' + JSON.stringify(err));
           return;
       }
       console.info('Succeeded in finding subWindow. Data: ' + JSON.stringify(data));
       windowClass = data;
   });
   ```
   
2. 设置子窗口属性。

   子窗口创建成功后，可以改变其大小、位置等，还可以根据应用需要设置窗口背景色、亮度等属性。
   
   ```js
   // 移动子窗口位置。
   windowClass.moveWindowTo(300, 300, (err) => {
     if (err.code) {
       console.error('Failed to move the window. Cause:' + JSON.stringify(err));
       return;
     }
     console.info('Succeeded in moving the window.');
   });
   // 改变子窗口大小。
   windowClass.resize(500, 500, (err) => {
     if (err.code) {
       console.error('Failed to change the window size. Cause:' + JSON.stringify(err));
       return;
     }
     console.info('Succeeded in changing the window size.');
   });
   ```

3. 加载显示子窗口的具体内容。

   使用`SetUIContent`和`showWindow`接口加载显示子窗口的具体内容。
   
   ```js
   // 为子窗口加载对应的目标页面。
   windowClass.SetUIContent("pages/page2", (err) => {
       if (err.code) {
           console.error('Failed to load the content. Cause: ' + JSON.stringify(err));
           return;
       }
       console.info('Succeeded in loading the content.');
       // 显示子窗口。
       windowClass.showWindow((err) => {
        if (err.code) {
               console.error('Failed to show the window. Cause: ' + JSON.stringify(err));
               return;
           }
           console.info('Succeeded in showing the window.');
       });
   });
   ```
   
4. 销毁子窗口。

   当不再需要某些子窗口时，可根据场景的具体实现逻辑，使用`destroyWindow`接口销毁子窗口。
   
   ```js
   // 销毁子窗口。当不再需要某些子窗口时，可根据场景的具体实现逻辑，使用destroy接口销毁子窗口。
   windowClass.destroyWindow((err) => {
       if (err.code) {
           console.error('Failed to destroy the subwindow. Cause:' + JSON.stringify(err));
           return;
       }
       console.info('Succeeded in destroying the subwindow.');
   });
   ```


## 体验窗口沉浸式能力

在看视频、玩游戏等场景下，用户往往希望隐藏状态栏、导航栏等不必要的系统窗口，从而获得更佳的沉浸式体验。此时可以借助窗口沉浸式能力（窗口沉浸式能力都是针对应用主窗口而言的），达到预期效果。


### 开发步骤

1. 获取主窗口对象。

   > **说明：** 
   >
   > 沉浸式能力需要在成功获取应用主窗口对象的前提下进行。
   >
   > 确保应用内最后显示的窗口为主窗口，然后再使用`window.getLastWindow`接口来获取得到主窗口。
   
   ```js
   import window from '@ohos.window';
   
   let mainWindowClass = null;
   // 获取主窗口。
   window.getLastWindow((err, data) => {
     if (err.code) {
       console.error('Failed to get the subWindow. Cause: ' + JSON.stringify(err));
       return;
     }
     console.info('Succeeded in getting subWindow. Data: ' + JSON.stringify(data));
     mainWindowClass = data;
   });
   ```

2. 实现沉浸式效果。有以下三种方式：

   - 方式一：调用`setWindowSystemBarEnable`接口，设置导航栏、状态栏不显示，从而达到沉浸式效果。
   - 方式二：调用`setWindowLayoutFullScreen`接口，设置应用主窗口为全屏布局；然后调用`setSystemProperties`接口，设置导航栏、状态栏的透明度、背景/文字颜色以及高亮图标等属性，使之保持与主窗口显示协调一致，从而达到沉浸式效果。

   ```js
   
   // 实现沉浸式效果。方式一：设置导航栏、状态栏不显示。
   let names = [];
   mainWindowClass.setWindowSystemBarEnable(names, (err) => {
     if (err.code) {
       console.error('Failed to set the system bar to be visible. Cause:' + JSON.stringify(err));
       return;
     }
     console.info('Succeeded in setting the system bar to be visible.');
   });
   // 实现沉浸式效果。
   // 方式二：设置窗口为全屏布局，配合设置状态栏、导航栏的透明度、背景/文字颜色及高亮图标等属性，与主窗口显示保持协调一致。
   let isLayoutFullScreen = true;
   mainWindowClass.setWindowLayoutFullScreen(isLayoutFullScreen, (err) => {
     if (err.code) {
       console.error('Failed to set the window layout to full-screen mode. Cause:' + JSON.stringify(err));
       return;
     }
     console.info('Succeeded in setting the window layout to full-screen mode.');
   });
   let sysBarProps = {
     statusBarColor: '#ff00ff',
     navigationBarColor: '#00ff00',
     // 以下两个属性从API Version8开始支持。
     statusBarContentColor: '#ffffff',
     navigationBarContentColor: '#ffffff'
   };
   mainWindowClass.setWindowSystemBarProperties(sysBarProps, (err) => {
     if (err.code) {
       console.error('Failed to set the system bar properties. Cause: ' + JSON.stringify(err));
       return;
     }
     console.info('Succeeded in setting the system bar properties.');
   });
   ```

3. 加载显示沉浸式窗口的具体内容。

   使用`SetUIContent`和`showWindow`接口加载显示沉浸式窗口的具体内容。
   
   ```js
   // 为沉浸式窗口加载对应的目标页面。
   mainWindowClass.SetUIContent("pages/page3", (err) => {
       if (err.code) {
           console.error('Failed to load the content. Cause: ' + JSON.stringify(err));
           return;
       }
       console.info('Succeeded in loading the content.');
       // 显示沉浸式窗口。
       mainWindowClass.showWindow((err) => {
           if (err.code) {
               console.error('Failed to show the window. Cause: ' + JSON.stringify(err));
               return;
           }
           console.info('Succeeded in showing the window.');
       });
   });
   ```