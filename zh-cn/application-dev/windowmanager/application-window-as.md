# 管理应用窗口（原子化服务）

## 场景介绍

管理应用窗口的典型场景有：

- 设置应用主窗口属性及目标页面

- 设置应用子窗口属性及目标页面

- 监听窗口不可交互与可交互事件

以下分别介绍具体开发方式。

## 接口说明

上述场景涉及的常用接口如下表所示。更多API说明请参见[@ohos.window (窗口)](../reference/apis-arkui/arkts-apis-window.md)。

| 实例名         | 接口名                                                       | 描述                                                         |
| -------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| WindowStage    | getMainWindow(callback: AsyncCallback&lt;Window&gt;): void   | 获取`WindowStage`实例下的主窗口。<br/>此接口仅可在`Stage`模型下使用。 |
| WindowStage    | loadContent(path: string, callback: AsyncCallback&lt;void&gt;): void | 为当前`WindowStage`的主窗口加载具体页面。<br>其中path为要加载到窗口中的页面内容的路径，该路径需添加到工程的main_pages.json文件中。<br/>此接口仅可在`Stage`模型下使用。 |
| WindowStage    | createSubWindow(name: string, callback: AsyncCallback&lt;Window&gt;): void | 创建子窗口。<br/>此接口仅可在`Stage`模型下使用。             |
| WindowStage    | on(type: 'windowStageEvent', callback: Callback&lt;WindowStageEventType&gt;): void | 开启WindowStage生命周期变化的监听。<br/>此接口仅可在`Stage`模型下使用。 |
| Window         | setUIContent(path: string, callback: AsyncCallback&lt;void&gt;): void | 根据当前工程中某个页面的路径为窗口加载具体的页面内容。<br>其中path为要加载到窗口中的页面内容的路径，在Stage模型下该路径需添加到工程的main_pages.json文件中。                                     |
| Window         | setWindowPrivacyMode(isPrivacyMode: boolean, callback: AsyncCallback&lt;void&gt;): void | 设置窗口是否为隐私模式。                                             |
| Window         | moveWindowTo(x: number, y: number, callback: AsyncCallback&lt;void&gt;): void | 移动当前窗口位置。                                           |
| Window         | resize(width: number, height: number, callback: AsyncCallback&lt;void&gt;): void | 改变当前窗口大小。                                           |
| Window         | showWindow(callback: AsyncCallback\<void>): void             | 显示当前窗口。                                               |
| Window         | destroyWindow(callback: AsyncCallback&lt;void&gt;): void     | 销毁当前窗口。                                               |


## 设置应用主窗口

应用主窗口由`UIAbility`创建并维护生命周期。在`UIAbility`的`onWindowStageCreate`回调中，通过`WindowStage`获取应用主窗口，即可对其进行属性设置等操作。还可以在应用配置文件中设置应用主窗口的属性，如最大窗口宽度maxWindowWidth等，详见[module.json5配置文件](../quick-start/module-configuration-file.md#abilities标签)。

### 开发步骤

**前提条件：** `setWindowPrivacyMode` 即设置窗口隐私模式，适用于禁止截屏/录屏的场景。该接口使用时需要申请`ohos.permission.PRIVACY_WINDOW`权限，配置方式请参见[配置文件](../quick-start/module-configuration-file.md#配置文件标签)中requestPermissions字段。

1. 获取应用主窗口。

   通过`getMainWindow`接口获取应用主窗口。

2. 设置窗口隐私模式属性。

   通过`setWindowPrivacyMode`接口设置主窗口为隐私模式的窗口，窗口内容将无法被截屏或录屏。此接口可用于禁止截屏/录屏的场景。

3. 为主窗口加载对应的目标页面。

   通过`loadContent`接口加载主窗口的目标页面。

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    // 1.获取应用主窗口。
    let windowClass: window.Window | null = null;
    windowStage.getMainWindow((err: BusinessError, data) => {
      let errCode: number = err.code;
      if (errCode) {
        console.error('Failed to obtain the main window. Cause: ' + JSON.stringify(err));
        return;
      }
      windowClass = data;
      console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));
      // 2.设置为隐私模式的窗口
      let isPrivacyMode: boolean = true;
      try {
        windowClass.setWindowPrivacyMode(isPrivacyMode, (err: BusinessError) => {
          const errCode: number = err.code;
          if(errCode) {
            console.error('Failed to set the window to privacy mode. Cause:' +
          JSON.stringify(err));
            return;
          }
          console.info('Succeeded in setting the window to privacy mode.');
        });
      } catch (exception) {
        console.error('Failed to set the window to privacy mode. Cause:' +
      JSON.stringify(exception));
      }
    })
    // 3.为主窗口加载对应的目标页面。
    windowStage.loadContent("pages/page2", (err: BusinessError) => {
      let errCode: number = err.code;
      if (errCode) {
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

> **说明：**  
> 由于以下几种情况，移动设备场景下不推荐使用子窗口，优先推荐使用控件[overlay](../reference/apis-arkui/arkui-ts/ts-universal-attributes-overlay.md)能力实现。  
> - 移动设备场景下子窗不能超出主窗口范围，与控件一致。  
> - 分屏窗口与自由窗口模式下，主窗口位置大小发生改变时控件实时跟随变化能力优于子窗。  
> - 部分设备平台下根据实际的系统配置限制，子窗只有系统默认的动效和圆角阴影，应用无法设置，自由度低。

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
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let windowStage_: window.WindowStage | null = null;
let sub_windowClass: window.Window | null = null;

export default class EntryAbility extends UIAbility {
  showSubWindow() {
    // 1.创建应用子窗口。
    if (windowStage_ == null) {
      console.error('Failed to create the subwindow. Cause: windowStage_ is null');
    }
    else {
      windowStage_.createSubWindow("mySubWindow", (err: BusinessError, data) => {
        let errCode: number = err.code;
        if (errCode) {
          console.error('Failed to create the subwindow. Cause: ' + JSON.stringify(err));
          return;
        }
        sub_windowClass = data;
        console.info('Succeeded in creating the subwindow. Data: ' + JSON.stringify(data));
        // 2.子窗口创建成功后，设置子窗口的位置、大小及相关属性等。
        sub_windowClass.moveWindowTo(300, 300, (err: BusinessError) => {
          let errCode: number = err.code;
          if (errCode) {
            console.error('Failed to move the window. Cause:' + JSON.stringify(err));
            return;
          }
          console.info('Succeeded in moving the window.');
        });
        sub_windowClass.resize(500, 500, (err: BusinessError) => {
          let errCode: number = err.code;
          if (errCode) {
            console.error('Failed to change the window size. Cause:' + JSON.stringify(err));
            return;
          }
          console.info('Succeeded in changing the window size.');
        });
        // 3.为子窗口加载对应的目标页面。
        sub_windowClass.setUIContent("pages/page3", (err: BusinessError) => {
          let errCode: number = err.code;
          if (errCode) {
            console.error('Failed to load the content. Cause:' + JSON.stringify(err));
            return;
          }
          console.info('Succeeded in loading the content.');
          // 3.显示子窗口。
          (sub_windowClass as window.Window).showWindow((err: BusinessError) => {
            let errCode: number = err.code;
            if (errCode) {
              console.error('Failed to show the window. Cause: ' + JSON.stringify(err));
              return;
            }
            console.info('Succeeded in showing the window.');
          });
        });
      })
    }
  }

  destroySubWindow() {
    // 4.销毁子窗口。当不再需要子窗口时，可根据具体实现逻辑，使用destroy对其进行销毁。
    (sub_windowClass as window.Window).destroyWindow((err: BusinessError) => {
      let errCode: number = err.code;
      if (errCode) {
        console.error('Failed to destroy the window. Cause: ' + JSON.stringify(err));
        return;
      }
      console.info('Succeeded in destroying the window.');
    });
  }

  onWindowStageCreate(windowStage: window.WindowStage) {
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

## 监听窗口不可交互与可交互事件

应用在前台显示过程中可能会进入某些不可交互的场景，比较典型的是进入多任务界面。此时，对于一些应用可能需要选择暂停某个与用户正在交互的业务，如视频类应用暂停正在播放的视频或者相机暂停预览流等。而当该应用从多任务又切回前台时，又变成了可交互的状态，此时需要恢复被暂停中断的业务，如恢复视频播放或相机预览流等。

### 开发步骤

在创建WindowStage对象后可通过监听`'windowStageEvent'`事件类型，监听到窗口进入前台、后台、前台可交互、前台不可交互等事件，应用可根据这些上报的事件状态进行相应的业务处理。

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    try {
      windowStage.on('windowStageEvent', (data) => {
        console.info('Succeeded in enabling the listener for window stage event changes. Data: ' +
          JSON.stringify(data));

        // 根据事件状态类型选择进行相应的处理
        if (data == window.WindowStageEventType.SHOWN) {
          console.info('current window stage event is SHOWN');
          // 应用进入前台，默认为可交互状态
          // ...
        } else if (data == window.WindowStageEventType.HIDDEN) {
          console.info('current window stage event is HIDDEN');
          // 应用进入后台，默认为不可交互状态
          // ...
        } else if (data == window.WindowStageEventType.PAUSED) {
          console.info('current window stage event is PAUSED');
          // 前台应用进入多任务，转为不可交互状态
          // ...
        } else if (data == window.WindowStageEventType.RESUMED) {
          console.info('current window stage event is RESUMED');
          // 进入多任务后又继续返回前台时，恢复可交互状态
          // ...
        }

        // ...
      });
    } catch (exception) {
      console.error('Failed to enable the listener for window stage event changes. Cause:' +
        JSON.stringify(exception));
    }
  }
}
```