# 管理应用窗口（FA模型）

## 基本概念

窗口沉浸式能力：指对状态栏、导航栏等系统窗口进行控制，减少状态栏导航栏等系统界面的突兀感，从而使用户获得最佳体验的能力。
沉浸式能力只在应用主窗口作为全屏窗口时生效。通常情况下，应用子窗口（弹窗、悬浮窗口等辅助窗口）和处于自由窗口下的应用主窗口无法使用沉浸式能力。

> **说明：**
>
> 当前沉浸式界面开发仅支持window级别的配置，暂不支持Page级别的配置。若有Page级别切换的需要，可以在页面生命周期开始，例如onPageShow中设置沉浸模式，然后在页面退出，例如onPageHide中恢复默认设置来实现。

## 场景介绍

在FA模型下，管理应用窗口的典型场景有：

- 设置应用子窗口属性及目标页面

- 体验窗口沉浸式能力

以下分别介绍具体开发方式。


## 接口说明

上述场景涉及的常用接口如下表所示。更多API说明请参见[API参考](../reference/apis-arkui/js-apis-window.md)。

| 实例名         | 接口名                                                       | 描述                                                         |
| -------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| window静态方法 | createWindow(config: Configuration, callback: AsyncCallback\<Window>): void | 创建子窗口。<br/>-`config`：创建窗口时的参数。               |
| window静态方法 | findWindow(name: string): Window                             | 查找`name`所对应的窗口。                                     |
| Window         | setUIContent(path: string, callback: AsyncCallback&lt;void&gt;): void | 根据当前工程中某个页面的路径为窗口加载具体的页面内容。<br>其中path为要加载到窗口中的页面内容的路径，在FA模型下该路径需添加到工程的config.json文件中。                                 |
| Window         | moveWindowTo(x: number, y: number, callback: AsyncCallback&lt;void&gt;): void | 移动当前窗口。                                               |
| Window         | setWindowBrightness(brightness: number, callback: AsyncCallback&lt;void&gt;): void | 设置屏幕亮度值。                                             |
| Window         | resize(width: number, height: number, callback: AsyncCallback&lt;void&gt;): void | 改变当前窗口大小。                                           |
| Window         | setWindowLayoutFullScreen(isLayoutFullScreen: boolean): Promise&lt;void&gt; | 设置窗口布局是否为全屏布局。                                 |
| Window         | setWindowSystemBarEnable(names: Array&lt;'status'\|'navigation'&gt;): Promise&lt;void&gt; | 设置导航栏、状态栏是否显示。                                 |
| Window         | setWindowSystemBarProperties(systemBarProperties: SystemBarProperties): Promise&lt;void&gt; | 设置窗口内导航栏、状态栏属性。<br/>`systemBarProperties`：导航栏、状态栏的属性集合。 |
| Window         | showWindow(callback: AsyncCallback\<void>): void             | 显示当前窗口。                                               |
| Window         | on(type: 'touchOutside', callback: Callback&lt;void&gt;): void | 开启本窗口区域外的点击事件的监听。                           |
| Window         | destroyWindow(callback: AsyncCallback&lt;void&gt;): void     | 销毁当前窗口。                                               |


## 设置应用子窗口

开发者可以按需创建应用子窗口，如弹窗等，并对其进行属性设置等操作。

> **说明：**  
> 由于以下几种情况，移动设备场景下不推荐使用子窗口，优先推荐使用控件[overlay](../reference/apis-arkui/arkui-ts/ts-universal-attributes-overlay.md)能力实现。  
> - 移动设备场景下子窗不能超出主窗口范围，与控件一致。  
> - 分屏窗口与自由窗口模式下，主窗口位置大小发生改变时控件实时跟随变化能力优于子窗。  
> - 部分设备平台下根据实际的系统配置限制，子窗只有系统默认的动效和圆角阴影，应用无法设置，自由度低。

### 开发步骤

1. 创建/获取子窗口对象。

   - 可以通过`window.createWindow`接口创建子窗口。
   - 也可以通过`window.findWindow`接口来查找已经创建的窗口从而得到子窗口。

   ```ts
   import { window } from '@kit.ArkUI';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   let windowClass: window.Window | null = null;
   // 方式一：创建子窗口。
   let config: window.Configuration = { name: "subWindow", windowType: window.WindowType.TYPE_APP };
   window.createWindow(config, (err: BusinessError, data) => {
     let errCode: number = err.code;
     if (errCode) {
       console.error('Failed to create the subWindow. Cause: ' + JSON.stringify(err));
       return;
     }
     console.info('Succeeded in creating subWindow. Data: ' + JSON.stringify(data));
     windowClass = data;
   });
   // 方式二：查找得到子窗口。
   try {
     windowClass = window.findWindow('subWindow');
   } catch (exception) {
     console.error('Failed to find the Window. Cause: ' + JSON.stringify(exception));
   }
   ```

2. 设置子窗口属性。

   子窗口创建成功后，可以改变其大小、位置等，还可以根据应用需要设置窗口背景色、亮度等属性。

   ```ts
   // 移动子窗口位置。
   let windowClass: window.Window = window.findWindow("test");
   windowClass.moveWindowTo(300, 300, (err: BusinessError) => {
     let errCode: number = err.code;
     if (errCode) {
       console.error('Failed to move the window. Cause:' + JSON.stringify(err));
       return;
     }
     console.info('Succeeded in moving the window.');
   });
   // 改变子窗口大小。
   windowClass.resize(500, 500, (err: BusinessError) => {
     let errCode: number = err.code;
     if (errCode) {
       console.error('Failed to change the window size. Cause:' + JSON.stringify(err));
       return;
     }
     console.info('Succeeded in changing the window size.');
   });
   ```

3. 加载显示子窗口的具体内容。

   使用`setUIContent`和`showWindow`接口加载显示子窗口的具体内容。

   ```ts
   // 为子窗口加载对应的目标页面。
   let windowClass: window.Window = window.findWindow("test");
   windowClass.setUIContent("pages/page2", (err: BusinessError) => {
     let errCode: number = err.code;
     if (errCode) {
       console.error('Failed to load the content. Cause: ' + JSON.stringify(err));
       return;
     }
     console.info('Succeeded in loading the content.');
     // 显示子窗口。
     windowClass.showWindow((err: BusinessError) => {
       let errCode: number = err.code;
       if (errCode) {
         console.error('Failed to show the window. Cause: ' + JSON.stringify(err));
         return;
       }
       console.info('Succeeded in showing the window.');
     });
   });
   ```

4. 销毁子窗口。

   当不再需要某些子窗口时，可根据场景的具体实现逻辑，使用`destroyWindow`接口销毁子窗口。

   ```ts
   // 销毁子窗口。当不再需要某些子窗口时，可根据场景的具体实现逻辑，使用destroy接口销毁子窗口。
   let windowClass: window.Window = window.findWindow("test");
   windowClass.destroyWindow((err: BusinessError) => {
     let errCode: number = err.code;
     if (errCode) {
       console.error('Failed to destroy the subwindow. Cause:' + JSON.stringify(err));
       return;
     }
     console.info('Succeeded in destroying the subwindow.');
   });
   ```

## 体验窗口沉浸式能力

在看视频、玩游戏等场景下，用户往往希望隐藏状态栏、导航栏等不必要的系统窗口，从而获得更佳的沉浸式体验。此时可以借助窗口沉浸式能力（窗口沉浸式能力都是针对应用主窗口而言的），达到预期效果。从API version 10开始，沉浸式窗口默认配置为全屏大小并由组件模块控制布局，状态栏、导航栏背景颜色为透明，文字颜色为黑色；应用窗口调用`setWindowLayoutFullScreen`接口，设置为true表示由组件模块控制忽略状态栏、导航栏的沉浸式全屏布局，设置为false表示由组件模块控制避让状态栏、导航栏的非沉浸式全屏布局。


### 开发步骤

1. 获取主窗口对象。

   > **说明：** 
   >
   > 沉浸式能力需要在成功获取应用主窗口对象的前提下进行。
   >
   > 确保应用内最后显示的窗口为主窗口，然后再使用`window.getLastWindow`接口来获取得到主窗口。

   ```ts
   import { window } from '@kit.ArkUI';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   let mainWindowClass: window.Window | null = null;
   
   // 获取主窗口。
   class BaseContext {
     stageMode: boolean = false;
   }
   
   let context: BaseContext = { stageMode: false };
   window.getLastWindow(context, (err: BusinessError, data) => {
     let errCode: number = err.code;
     if (errCode) {
       console.error('Failed to get the subWindow. Cause: ' + JSON.stringify(err));
       return;
     }
     console.info('Succeeded in getting subWindow. Data: ' + JSON.stringify(data));
     mainWindowClass = data;
   });
   ```

2. 实现沉浸式效果。有以下两种方式：

   - 方式一：应用主窗口为全屏窗口时，调用`setWindowSystemBarEnable`接口，设置导航栏、状态栏不显示，从而达到沉浸式效果。
   - 方式二：调用`setWindowLayoutFullScreen`接口，设置应用主窗口为全屏布局；然后调用`setWindowSystemBarProperties`接口，设置导航栏、状态栏的透明度、背景/文字颜色以及高亮图标等属性，使之保持与主窗口显示协调一致，从而达到沉浸式效果。

   ```ts
   // 实现沉浸式效果。方式一：设置导航栏、状态栏不显示。
   let names: Array<'status' | 'navigation'> = [];
   let mainWindowClass: window.Window = window.findWindow("test");
   mainWindowClass.setWindowSystemBarEnable(names)
    .then(() => {
      console.info('Succeeded in setting the system bar to be visible.');
    })
    .catch((err: BusinessError) => {
      console.error('Failed to set the system bar to be visible. Cause:' + JSON.stringify(err));
    });
   // 实现沉浸式效果。
   // 方式二：设置窗口为全屏布局，配合设置状态栏、导航栏的透明度、背景/文字颜色及高亮图标等属性，与主窗口显示保持协调一致。
   let isLayoutFullScreen: boolean = true;
   mainWindowClass.setWindowLayoutFullScreen(isLayoutFullScreen)
    .then(() => {
      console.info('Succeeded in setting the window layout to full-screen mode.');
    })
    .catch((err: BusinessError) => {
      console.error('Failed to set the window layout to full-screen mode. Cause:' + JSON.stringify(err));
    });
   let sysBarProps: window.SystemBarProperties = {
     statusBarColor: '#ff00ff',
     navigationBarColor: '#00ff00',
     // 以下两个属性从API Version8开始支持。
     statusBarContentColor: '#ffffff',
     navigationBarContentColor: '#ffffff'
   };
   mainWindowClass.setWindowSystemBarProperties(sysBarProps)
    .then(() => {
      console.info('Succeeded in setting the system bar properties.');
    })
    .catch((err: BusinessError) => {
      console.error('Failed to set the system bar properties. Cause: ' + JSON.stringify(err));
    });
   ```

3. 加载显示沉浸式窗口的具体内容。

   使用`setUIContent`和`showWindow`接口加载显示沉浸式窗口的具体内容。

   ```ts
   // 为沉浸式窗口加载对应的目标页面。
   let mainWindowClass: window.Window = window.findWindow("test");
   mainWindowClass.setUIContent("pages/page3", (err: BusinessError) => {
     let errCode: number = err.code;
     if (errCode) {
       console.error('Failed to load the content. Cause: ' + JSON.stringify(err));
       return;
     }
     console.info('Succeeded in loading the content.');
     // 显示沉浸式窗口。
     mainWindowClass.showWindow((err: BusinessError) => {
       let errCode: number = err.code;
       if (errCode) {
         console.error('Failed to show the window. Cause: ' + JSON.stringify(err));
         return;
       }
       console.info('Succeeded in showing the window.');
     });
   });
   ```