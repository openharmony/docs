# 管理应用窗口（Stage模型）


## 基本概念

- 窗口沉浸式能力：指对状态栏、导航栏等系统窗口进行控制，减少状态栏导航栏等系统界面的突兀感，从而使用户获得最佳体验的能力。
  沉浸式能力只在应用主窗口作为全屏窗口时生效。通常情况下，应用子窗口（弹窗、悬浮窗口等辅助窗口）和处于自由窗口下的应用主窗口无法使用沉浸式能力。

- 悬浮窗：全局悬浮窗口是一种特殊的应用窗口，具备在应用主窗口和对应Ability退至后台后仍然可以在前台显示的能力。
  悬浮窗口可以用于应用退至后台后，使用小窗继续播放视频，或者为特定的应用创建悬浮球等快速入口。应用在创建悬浮窗口前，需要申请对应的权限。


## 场景介绍

在`Stage`模型下，管理应用窗口的典型场景有：

- 设置应用主窗口属性及目标页面

- 设置应用子窗口属性及目标页面

- 体验窗口沉浸式能力

- 设置悬浮窗

以下分别介绍具体开发方式。


## 接口说明

上述场景涉及的常用接口如下表所示。更多API说明请参见[API参考](../reference/apis/js-apis-window.md)。

| 实例名 | 接口名 | 描述 |
| -------- | -------- | -------- |
| WindowStage | getMainWindow(callback: AsyncCallback&lt;Window&gt;): void | 获取`WindowStage`实例下的主窗口。<br/>此接口仅可在`Stage`模型下使用。 |
| WindowStage | loadContent(path: string, callback: AsyncCallback&lt;void&gt;): void | 为当前`WindowStage`的主窗口加载具体页面。<br/>此接口仅可在`Stage`模型下使用。 |
| WindowStage | createSubWindow(name: string, callback: AsyncCallback&lt;Window&gt;): void | 创建子窗口。<br/>此接口仅可在`Stage`模型下使用。 |
| window静态方法 | createWindow(config: Configuration, callback: AsyncCallback\<Window>): void | 创建系统窗口。<br/>-`config`：创建窗口时的参数。 |
| Window | setUIContent(path: string, callback: AsyncCallback&lt;void&gt;): void | 为当前窗口加载具体页面。 |
| Window | setWindowBackgroundColor(color: string, callback: AsyncCallback&lt;void&gt;): void | 设置窗口的背景色。 |
| Window | setWindowBrightness(brightness: number, callback: AsyncCallback&lt;void&gt;): void | 设置屏幕亮度值。 |
| Window | setWindowTouchable(isTouchable: boolean, callback: AsyncCallback&lt;void&gt;): void | 设置窗口是否为可触状态。 |
| Window | moveWindowTo(x: number, y: number, callback: AsyncCallback&lt;void&gt;): void | 移动当前窗口位置。 |
| Window | resize(width: number, height: number, callback: AsyncCallback&lt;void&gt;): void | 改变当前窗口大小。 |
| Window | setWindowLayoutFullScreen(isLayoutFullScreen: boolean, callback: AsyncCallback&lt;void&gt;): void | 设置窗口布局是否为全屏布局。 |
| Window | setWindowSystemBarEnable(names: Array&lt;'status'\|'navigation'&gt;): Promise&lt;void&gt; | 设置导航栏、状态栏是否显示。 |
| Window | setWindowSystemBarProperties(systemBarProperties: SystemBarProperties, callback: AsyncCallback&lt;void&gt;): void | 设置窗口内导航栏、状态栏属性。<br/>`systemBarProperties`：导航栏、状态栏的属性集合。 |
| Window | showWindow(callback: AsyncCallback\<void>): void | 显示当前窗口。 |
| Window | on(type: 'touchOutside', callback: Callback&lt;void&gt;): void | 开启本窗口区域外的点击事件的监听。 |
| Window | destroyWindow(callback: AsyncCallback&lt;void&gt;): void | 销毁当前窗口。 |


## 设置应用主窗口

在`Stage`模型下，应用主窗口由`Ability`创建并维护生命周期。在`Ability`的`onWindowStageCreate`回调中，通过`WindowStage`获取应用主窗口，即可对其进行属性设置等操作。


### 开发步骤

1. 获取应用主窗口。
   通过`getMainWindow`接口获取应用主窗口。

2. 设置主窗口属性。
   可设置主窗口的背景色、亮度值、是否可触等多个属性，开发者可根据需要选择对应的接口。本示例以设置“是否可触”属性为例。

3. 为主窗口加载对应的目标页面。
   通过`loadContent`接口加载主窗口的目标页面。

```ts
import Ability from '@ohos.application.Ability'

class MainAbility extends Ability {
    onWindowStageCreate(windowStage) {
        // 1.获取应用主窗口。
        let windowClass = null;
        windowStage.getMainWindow((err, data) => {
            if (err.code) {
                console.error('Failed to obtain the main window. Cause: ' + JSON.stringify(err));
                return;
            }
            windowClass = data;
            console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));
            // 2.设置主窗口属性。以设置"是否可触"属性为例。
            let isTouchable = true;
            windowClass.setWindowTouchable(isTouchable, (err) => {
                if (err.code) {
                    console.error('Failed to set the window to be touchable. Cause:' + JSON.stringify(err));
                    return;
                }
                console.info('Succeeded in setting the window to be touchable.');
            })
        })
        // 3.为主窗口加载对应的目标页面。
        windowStage.loadContent("pages/page2", (err) => {
            if (err.code) {
                console.error('Failed to load the content. Cause:' + JSON.stringify(err));
                return;
            }
            console.info('Succeeded in loading the content.');
        });
    }
};
```


## 设置应用子窗口

开发者可以按需创建应用子窗口，如弹窗等，并对其进行属性设置等操作。


### 开发步骤

1. 创建应用子窗口。
   通过`createSubWindow`接口创建应用子窗口。

2. 设置子窗口属性。
   子窗口创建成功后，可以改变其大小、位置等，还可以根据应用需要设置窗口背景色、亮度等属性。

3. 加载显示子窗口的具体内容。
   通过`setUIContent`和`showWindow`接口加载显示子窗口的具体内容。

4. 销毁子窗口。
   当不再需要某些子窗口时，可根据具体实现逻辑，使用`destroyWindow`接口销毁子窗口。
   
   ```ts
   import Ability from '@ohos.application.Ability'
   
   let windowStage_ = null;
   let sub_windowClass = null;
   class MainAbility extends Ability {
       showSubWindow() {
           // 1.创建应用子窗口。
           windowStage_.createSubWindow("mySubWindow", (err, data) => {
               if (err.code) {
                   console.error('Failed to create the subwindow. Cause: ' + JSON.stringify(err));
                   return;
               }
               sub_windowClass = data;
               console.info('Succeeded in creating the subwindow. Data: ' + JSON.stringify(data));
               // 2.子窗口创建成功后，设置子窗口的位置、大小及相关属性等。
               sub_windowClass.moveWindowTo(300, 300, (err) => {
                   if (err.code) {
                       console.error('Failed to move the window. Cause:' + JSON.stringify(err));
                       return;
                   }
                   console.info('Succeeded in moving the window.');
               });
               sub_windowClass.resize(500, 500, (err) => {
                   if (err.code) {
                       console.error('Failed to change the window size. Cause:' + JSON.stringify(err));
                       return;
                   }
                   console.info('Succeeded in changing the window size.');
               });
               // 3.为子窗口加载对应的目标页面。
               sub_windowClass.setUIContent("pages/page3", (err) => {
                   if (err.code) {
                       console.error('Failed to load the content. Cause:' + JSON.stringify(err));
                       return;
                   }
                   console.info('Succeeded in loading the content.');
                   // 3.显示子窗口。
                   sub_windowClass.showWindow((err) => {
                       if (err.code) {
                           console.error('Failed to show the window. Cause: ' + JSON.stringify(err));
                           return;
                       }
                       console.info('Succeeded in showing the window.');
                   });
               });
           })
       }
   
       destroySubWindow() {
           // 4.销毁子窗口。当不再需要子窗口时，可根据具体实现逻辑，使用destroy对其进行销毁。
           sub_windowClass.destroyWindow((err) => {
               if (err.code) {
                   console.error('Failed to destroy the window. Cause: ' + JSON.stringify(err));
                   return;
               }
               console.info('Succeeded in destroying the window.');
           });
       }
   
       onWindowStageCreate(windowStage) {
           windowStage_ = windowStage;
           // 开发者可以在适当的时机，如主窗口上按钮点击事件等，创建子窗口。并不一定需要在onWindowStageCreate调用，这里仅作展示
           this.showSubWindow();
       }
   
       onWindowStageDestroy() {
           // 开发者可以在适当的时机，如子窗口上点击关闭按钮等，销毁子窗口。并不一定需要在onWindowStageDestroy调用，这里仅作展示
           this.destroySubWindow();
       }
   };
   ```


## 体验窗口沉浸式能力

在看视频、玩游戏等场景下，用户往往希望隐藏状态栏、导航栏等不必要的系统窗口，从而获得更佳的沉浸式体验。此时可以借助窗口沉浸式能力（窗口沉浸式能力都是针对应用主窗口而言的），达到预期效果。


### 开发步骤

1. 获取应用主窗口。
   通过`getMainWindow`接口获取应用主窗口。

2. 实现沉浸式效果。有以下三种方式：
   - 方式一：调用`setWindowSystemBarEnable`接口，设置导航栏、状态栏不显示，从而达到沉浸式效果。
   - 方式二：调用`setWindowLayoutFullScreen`接口，设置应用主窗口为全屏布局；然后调用`setWindowSystemBarProperties`接口，设置导航栏、状态栏的透明度、背景/文字颜色以及高亮图标等属性，使之保持与主窗口显示协调一致，从而达到沉浸式效果。

3. 加载显示沉浸式窗口的具体内容。
   通过`loadContent`接口加载沉浸式窗口的具体内容。
   
   ```ts
   import Ability from '@ohos.application.Ability'
   
   class MainAbility extends Ability {
       onWindowStageCreate(windowStage) {
           // 1.获取应用主窗口。
           let windowClass = null;
           windowStage.getMainWindow((err, data) => {
               if (err.code) {
                   console.error('Failed to obtain the main window. Cause: ' + JSON.stringify(err));
                   return;
               }
               windowClass = data;
               console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));
   
               // 2.实现沉浸式效果。方式一：设置导航栏、状态栏不显示。
               let names = [];
               windowClass.setWindowSystemBarEnable(names, (err) => {
                   if (err.code) {
                       console.error('Failed to set the system bar to be visible. Cause:' + JSON.stringify(err));
                       return;
                   }
                   console.info('Succeeded in setting the system bar to be visible.');
               });
               // 2.实现沉浸式效果。方式二：设置窗口为全屏布局，配合设置导航栏、状态栏的透明度、背景/文字颜色及高亮图标等属性，与主窗口显示保持协调一致。
               let isLayoutFullScreen = true;
               windowClass.setWindowLayoutFullScreen(isLayoutFullScreen, (err) => {
                   if (err.code) {
                       console.error('Failed to set the window layout to full-screen mode. Cause:' + JSON.stringify(err));
                       return;
                   }
                   console.info('Succeeded in setting the window layout to full-screen mode.');
               });
               let sysBarProps = {
                   statusBarColor: '#ff00ff',
                   navigationBarColor: '#00ff00',
                   // 以下两个属性从API Version 8开始支持
                   statusBarContentColor: '#ffffff',
                   navigationBarContentColor: '#ffffff'
               };
               windowClass.setWindowSystemBarProperties(sysBarProps, (err) => {
                   if (err.code) {
                       console.error('Failed to set the system bar properties. Cause: ' + JSON.stringify(err));
                       return;
                   }
                   console.info('Succeeded in setting the system bar properties.');
               });
           })
           // 3.为沉浸式窗口加载对应的目标页面。
           windowStage.loadContent("pages/page2", (err) => {
               if (err.code) {
                   console.error('Failed to load the content. Cause:' + JSON.stringify(err));
                   return;
               }
               console.info('Succeeded in loading the content.');
           });
       }
   };
   ```


## 设置悬浮窗

悬浮窗可以在已有的任务基础上，创建一个始终在前台显示的窗口。即使创建悬浮窗的任务退至后台，悬浮窗仍然可以在前台显示。开发者可以创建悬浮窗，并对悬浮窗进行属性设置等操作。


### 开发步骤

1. 申请权限。
   创建`WindowType.TYPE_FLOAT`即悬浮窗类型的窗口，需要在`module.json5`文件的`requestPermissions`对象中配置`ohos.permission.SYSTEM_FLOAT_WINDOW`权限。更多配置信息详见[module.json5配置文件](../quick-start/module-configuration-file.md)。

   > **说明：**
   >
   > 虽然悬浮窗具备始终在前台显示的能力，但如果创建悬浮窗的应用任务被系统回收，仍然会导致悬浮窗从界面移除。如果想要保持悬浮窗口始终在前台显示，请申请[长时任务](../task-management/background-task-overview.md)。
   
   ```json
   {
     "module": {
       "requestPermissions":[
         {
           "name" : "ohos.permission.SYSTEM_FLOAT_WINDOW",
           "usedScene": {
             "abilities": [
               "MainAbility"
             ],
             "when":"inuse"
           }
         }
       ]
     }
   }
   ```

2. 创建悬浮窗。
   通过`window.createWindow`接口创建悬浮窗类型的窗口。

3. 对悬浮窗进行属性设置等操作。
   悬浮窗窗口创建成功后，可以改变其大小、位置等，还可以根据应用需要设置悬浮窗背景色、亮度等属性。

4. 加载显示悬浮窗的具体内容。
   通过`setUIContent`和`showWindow`接口加载显示悬浮窗的具体内容。

5. 销毁悬浮窗。

   当不再需要悬浮窗时，可根据具体实现逻辑，使用`destroyWindow`接口销毁悬浮窗。

   ```ts
   import Ability from '@ohos.application.Ability'
   import ExtensionContext from '@ohos.application.ServiceExtensionAbility';
   import window from '@ohos.window';
   
   class MainAbility extends Ability {
       onWindowStageCreate(windowStage) {
           // 2. 创建悬浮窗。
           let windowClass = null;
           let config = {name: "floatWindow", windowType: window.WindowType.TYPE_FLOAT, ctx: this.context};
           window.createWindow(config, (err, data) => {
               if (err.code) {
                   console.error('Failed to create the floatWindow. Cause: ' + JSON.stringify(err));
                   return;
               }
               console.info('Succeeded in creating the floatWindow. Data: ' + JSON.stringify(data));
               windowClass = data;
               // 3.悬浮窗窗口创建成功后，设置悬浮窗的位置、大小及相关属性等。
               windowClass.moveWindowTo(300, 300, (err) => {
                   if (err.code) {
                       console.error('Failed to move the window. Cause:' + JSON.stringify(err));
                       return;
                   }
                   console.info('Succeeded in moving the window.');
               });
               windowClass.resize(500, 500, (err) => {
                   if (err.code) {
                       console.error('Failed to change the window size. Cause:' + JSON.stringify(err));
                       return;
                   }
                   console.info('Succeeded in changing the window size.');
               });
               // 4.为悬浮窗加载对应的目标页面。
               windowClass.setUIContent("pages/page4", (err) => {
                   if (err.code) {
                       console.error('Failed to load the content. Cause:' + JSON.stringify(err));
                       return;
                   }
                   console.info('Succeeded in loading the content.');
                   // 4.显示悬浮窗。
                   windowClass.showWindow((err) => {
                       if (err.code) {
                           console.error('Failed to show the window. Cause: ' + JSON.stringify(err));
                           return;
                       }
                       console.info('Succeeded in showing the window.');
                   });
               });
               //5.销毁悬浮窗。当不再需要悬浮窗时，可根据具体实现逻辑，使用destroy对其进行销毁。
               windowClass.destroyWindow((err) => {
                   if (err.code) {
                       console.error('Failed to destroy the window. Cause: ' + JSON.stringify(err));
                       return;
                   }
                   console.info('Succeeded in destroying the window.');
               });
           });
       }
   };
   ```
## 相关实例

针对window开发（Stage模型），有以下相关实例可供参考：

- [`Window`：窗口（ArkTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/master/Graphics/Window)