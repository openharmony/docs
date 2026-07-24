# 窗口开发常见问题
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @JUGaaab-->
<!--Designer: @ki_ja-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

## 如何在应用A启动过程中拉起另一个应用B

**解决措施**

应用A调用[on('windowStageEvent')](../reference/apis-arkui/arkts-apis-window-WindowStage.md#onwindowstageevent9)接口监听[WindowStageEvent.ACTIVE](../reference/apis-arkui/arkts-apis-window-e.md#windowstageeventtype9)事件后调用[startAbility](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#startability)接口拉起应用B。

**代码示例**

```ts
// applicationA EntryAbility.ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';
import { Want, StartOptions } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage): void {
        let want: Want = {
            deviceId: '',
            bundleName: 'com.example.applicationB',
            abilityName: 'EntryAbility'
        };

        let options: StartOptions = {
            displayId: 0
        };

        windowStage.on('windowStageEvent', (data) => {
            let eventType: window.WindowStageEventType = data;
            // 监听应用A切换到ACTIVE状态
            if (eventType === window.WindowStageEventType.ACTIVE) {
                try {
                    // 拉起应用B
                    this.context.startAbility(want, options, (err: BusinessError) => {
                        if (err.code) {
                            // 处理业务逻辑错误
                            console.error(`Failed to start ability, code is ${err.code}, message is ${err.message}.`);
                            return;
                        }
                        // 执行正常业务
                        console.info('Succeeded in starting Ability.');
                    });
                } catch (err) {
                    // 处理入参错误异常
                    let code = (err as BusinessError).code;
                    let message = (err as BusinessError).message;
                    console.error(`Failed to start ability, code is ${code}, message is ${message}.`);
                }
            }
        });
    }
}
```

## 如何动态获取窗口宽高

在应用开发中，动态获取窗口宽高主要用于实现响应式布局，以适应不同尺寸的设备或窗口状态变化（如分屏、最大化恢复、拖拽缩放等）。

推荐使用[getMainWindowSync()](../reference/apis-arkui/arkts-apis-window-WindowStage.md#getmainwindowsync9)、[getMainWindow()](../reference/apis-arkui/arkts-apis-window-WindowStage.md#getmainwindow9-1)、[getSubWindow()](../reference/apis-arkui/arkts-apis-window-WindowStage.md#getsubwindow9-1)中的任一方法获取到Window实例（windowClass），再通过此实例调用[getWindowProperties()](../reference/apis-arkui//arkts-apis-window-Window.md#getwindowproperties9)接口得到其属性WindowProperties，通过属性获取窗口宽高即可。示例代码如下：

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    let windowClass: window.Window = windowStage.getMainWindowSync(); // 获取应用主窗口
    if (!windowClass) {
      console.info('windowClass is null');
    }
    try {
      let properties = windowClass.getWindowProperties();
      let rect = properties.windowRect;
      let windowWidth = rect.width;  // 窗口宽度，单位px
      let windowHeight = rect.height; // 窗口高度，单位px
      console.info(`Window Size: ${windowWidth} x ${windowHeight}`);
    } catch (exception) {
      console.error('Failed to obtain the window properties. Cause: ' + JSON.stringify(exception));
    }
  }
}
```


## 如何获取软键盘高度

固定态软键盘为一种特定的避让区域类型，[AvoidAreaType](../reference/apis-arkui/arkts-apis-window-e.md#avoidareatype7)中对应为固定态软键盘（TYPE_KEYBOARD）类型，可以通过[getWindowAvoidArea()](../reference/apis-arkui/arkts-apis-window-Window.md#getwindowavoidarea9)和[on('avoidAreaChange')](../reference/apis-arkui/arkts-apis-window-Window.md#onavoidareachange9)动态监听软键盘避让区高度的变化。

另外，开发者也可以通过[on('keyboardHeightChange')](../reference/apis-arkui/arkts-apis-window-Window.md#onkeyboardheightchange7)接口监听软键盘的占用高度。与避让区域不同的是，此接口回调仅返回软键盘的高度数值（number），而[on('avoidAreaChange')](../reference/apis-arkui/arkts-apis-window-Window.md#onavoidareachange9)回调会返回整个软键盘区域（[Rect](../reference/apis-arkui/arkts-apis-window-i.md#rect7)）。

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    // 获取应用主窗口
    let windowClass: window.Window = windowStage.getMainWindowSync();
    if (!windowClass) {
      console.info('windowClass is null');
    }
    try {
      // 获取软键盘避让区高度
      let keyboardHeight = windowClass.getWindowAvoidArea(window.AvoidAreaType.TYPE_KEYBOARD).bottomRect.height;
      // 动态监听软键盘避让区高度
      windowClass.on('avoidAreaChange', (data) => {
        if (data.type == window.AvoidAreaType.TYPE_KEYBOARD) {
          keyboardHeight = data.area.bottomRect.height;
        }
      });
    } catch (exception) {
      console.error(`Failed to enable the listener for system avoid area changes. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```


## 如何获取PC设备顶部系统默认标题栏的高度

通过调用[getWindowDecorHeight()](../reference/apis-arkui/arkts-apis-window-Window.md#getwindowdecorheight11)获取窗口的标题栏高度。

示例代码如下所示：

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    // 获取应用主窗口
    let windowClass: window.Window = windowStage.getMainWindowSync();
    if (!windowClass) {
      console.info('windowClass is null');
    }
    windowClass.setUIContent('pages/WindowPage').then(() => {
      try {
        let height = windowClass?.getWindowDecorHeight();
        console.info(`Succeeded in getting the height of window decor: ${height}`);
      } catch (exception) {
        console.error(`Failed to get the height of window decor. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    })
  }
}
```


## 如何实现或判断窗口沉浸式布局

[沉浸式布局](immersive-window-feature.md#沉浸式布局)是一种让应用可布局区域拓展至整个窗口显示区域的状态。

非[自由窗口](window-terminology.md#freeform-window自由窗口)可以通过调用[setWindowLayoutFullScreen()](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowlayoutfullscreen9)设置沉浸式布局；自由窗口可以通过[setWindowDecorVisible()](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowdecorvisible11)接口控制窗口标题栏显隐，当标题栏隐藏时，窗口处于沉浸式布局。

可以通过[isImmersiveLayout()](../reference/apis-arkui/arkts-apis-window-Window.md#isimmersivelayout20)判断当前窗口是否处于沉浸式布局。

示例代码如下所示：

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    // 获取应用主窗口
    let windowClass: window.Window = windowStage.getMainWindowSync(); 
    if (!windowClass) {
      console.info('windowClass is null');
    }
    try {
      // 设置沉浸式布局
      let promise = windowClass.setWindowLayoutFullScreen(true); 
      // 判断当前窗口是否处于沉浸式布局
      let isImmersiveLayout = windowClass.isImmersiveLayout();
      console.info(`isImmersiveLayout: ${isImmersiveLayout}`);
    } catch (exception) {
      console.error('Failed to obtain isImmersiveLayout. Cause: ' + JSON.stringify(exception));
    }
  }
}
```


## 如何隐藏状态栏和底部导航区域

可以调用[setSpecificSystemBarEnabled()](../reference/apis-arkui/arkts-apis-window-Window.md#setspecificsystembarenabled11)隐藏状态栏和底部导航区域。

示例代码如下所示：

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    // 获取应用主窗口
    let windowClass: window.Window = windowStage.getMainWindowSync();
    if (!windowClass) {
      console.info('windowClass is null');
    }
    try {
      // 隐藏状态栏
      windowClass.setSpecificSystemBarEnabled('status', false);
      // 隐藏底部导航区域
      windowClass.setSpecificSystemBarEnabled('navigationIndicator', false);
    } catch (exception) {
      console.error('Failed to set status bar or navigation indicator bar invisible. Cause: ' + JSON.stringify(exception));
    }
  }
}
```


## 如何获取状态栏高度

状态栏为一种特定的避让区域类型，[AvoidAreaType](../reference/apis-arkui/arkts-apis-window-e.md#avoidareatype7)中对应为系统栏（TYPE_SYSTEM）类型。

主窗口全屏时，可以通过[getWindowAvoidArea()](../reference/apis-arkui/arkts-apis-window-Window.md#getwindowavoidarea9)获取到包含状态栏的避让区域[AvoidArea](../reference/apis-arkui/arkts-apis-window-i.md#avoidarea7)，间接获取到状态栏的高度。

示例代码如下所示：

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    let windowClass: window.Window = windowStage.getMainWindowSync(); // 获取应用主窗口
    if (!windowClass) {
      console.info('windowClass is null');
    }
    try {
      // 获取状态栏避让区高度
      let statusBarHeight = windowClass.getWindowAvoidArea(window.AvoidAreaType.TYPE_SYSTEM).topRect.height;
    } catch (exception) {
      console.error(`Failed to get window avoid area. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

## 如何设置窗口背景透明

可以通过调用[setWindowBackgroundColor](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowbackgroundcolor9)接口，传入'\#00XXXXXX'（其中X代表任意十六进制数字）或者透明的[ColorMetrics](../reference/apis-arkui/js-apis-arkui-graphics.md#colormetrics12)实现窗口背景透明。

> **说明：**
> 
> - 在支持[自由多窗](window-terminology.md#free-multi-window-mode自由多窗模式)的设备上，存在窗口容器，窗口容器背景色覆盖整个窗口区域，包括标题栏和内容区域。调用[setWindowBackgroundColor](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowbackgroundcolor9)接口仅可设置应用内容背景色，此时会透出窗口容器背景色。
> 
> - 在PC/2in1和Tablet设备上可以调用[setWindowContainerColor()](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowcontainercolor20)接口设置容器透明，在其他设备上暂不支持设置容器背景色。

示例代码如下所示：

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { ColorMetrics } from '@kit.ArkUI';
import { window } from '@kit.ArkUI';

let storage: LocalStorage = new LocalStorage();
storage.setOrCreate('storageSimpleProp', 121);
windowClass.loadContent("pages/page2", storage, (err: BusinessError) => {
  let errCode: number = err.code;
  if (errCode) {
  console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
  return;
  }
  console.info('Succeeded in loading the content.');
  // 采用ARGB方式
  let color1: string = '#0000FF33'; 
  // 采用ColorMetrics方式
  let color2: ColorMetrics = ColorMetrics.numeric(0x00112233);  
  try {
    windowClass?.setWindowBackgroundColor(color1);
    windowClass?.setWindowBackgroundColor(color2);
  } catch (exception) {
    console.error(`Failed to set the background color. Cause code: ${exception.code}, message: ${exception.message}`);
  };
});
```

## 如何实现横竖屏切换

需要先获取到主窗实例，然后调用[setPreferredOrientation()](../reference/apis-arkui/arkts-apis-window-Window.md#setpreferredorientation9-1)接口设置窗口方向。更多详细信息请参考[窗口旋转](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/window-rotation)。

示例代码如下所示：

```ts
import { BusinessError } from '@kit.BasicServicesKit'
import { common } from '@kit.AbilityKit'
import { window } from '@kit.ArkUI'

@Entry
@Component
struct OrientationTestView {
  private orientation: number =  1;
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  private windowClass = (this.context as common.UIAbilityContext).windowStage.getMainWindowSync();
  setOrientation(orientation: number) {
    this.windowClass.setPreferredOrientation(orientation).then(() => {
      console.info('setWindowOrientation: ' + orientation + ' Succeeded.');
    }).catch((err: BusinessError) => {
      console.error('setWindowOrientation: ' + orientation + ' Failed. Cause: ' + JSON.stringify(err));
    })
  }
  build() {
    Column() {
      Button('changeOrientation')
        .onClick(() => {
          this.setOrientation(this.orientation++ % 4 + 1)
        })
    }
    .height('100%')
    .width('100%')
    .margin({'top' : 100})
  }
}
```

更多内容请参考：

- [最佳实践：横竖屏切换](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-landscape-and-portrait-development)

- [Orientation](../reference/apis-arkui/arkts-apis-window-e.md#orientation9)

## 如何保持屏幕为横屏/竖屏，不随传感器旋转

通过[setPreferredOrientation()](../reference/apis-arkui/arkts-apis-window-Window.md#setpreferredorientation9-1)接口设置应用的旋转策略为LANDSCAPE，则应用保持在横屏；设置为PORTRAIT，则应用保持在竖屏；设置为LOCKED时，可以锁定当前应用方向，不随屏幕旋转（不建议使用LOCKED，可能会发生非预期的方向改变）。

对于单一页面（Navigation）的禁用旋转，可以通过设置组件的[preferredOrientation](../reference/apis-arkui/arkui-ts/ts-basic-components-navdestination.md#preferredorientation19)属性来实现，如果设置为横屏、竖屏、反向横屏或反向竖屏中某一方向，则该页面无法旋转到其他方向，从而实现页面级的旋转禁用。

## 如何获取设备的横竖屏状态

先通过[display.getDefaultDisplaySync()](../reference/apis-arkui/js-apis-display.md#displaygetdefaultdisplaysync9)获取当前默认的Display实例对象。

再通过该实例对象获取对应的[Orientation](../reference/apis-arkui/js-apis-display.md#orientation10)属性，以判断当前设备的横竖屏状态。

Orientation是显示设备当前显示的方向枚举，具体包括以下四种类型：

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| PORTRAIT | 0 | 表示设备当前以竖屏方式显示。 |
| LANDSCAPE | 1 | 表示设备当前以横屏方式显示。 |
| PORTRAIT_INVERTED | 2 | 表示设备当前以反向竖屏方式显示。 |
| LANDSCAPE_INVERTED | 3 | 表示设备当前以反向横屏方式显示。 |

> **说明：**
> 
> 通过[setPreferredOrientation](../reference/apis-arkui/arkts-apis-window-Window.md#setpreferredorientation9-1)接口设置旋转策略为LANDSCAPE，此时通过以上步骤获取到的[Orientation](../reference/apis-arkui/js-apis-display.md#orientation10)属性为反向横屏（即LANDSCAPE_INVERTED），这是因为窗口的方向与屏幕的方向定义不一致。开发者也可以通过[convertOrientationAndRotation()](../reference/apis-arkui/arkts-apis-window-Window.md#convertorientationandrotation23)来获取转换结果。

示例代码如下所示：

```ts
import { display } from '@kit.ArkUI';

let displayClass: display.Display | null = null;
try {
  displayClass = display.getDefaultDisplaySync();
  let orientation = displayClass.Orientation;
} catch (exception) {
  console.error(`Failed to get default display. Code: ${exception.code}, message: ${exception.message}`);
}
```

## 如何设置应用默认横屏宽高比例

应用开发中，推荐使用[setContentAspectRatio()](../reference/apis-arkui/arkts-apis-window-Window.md#setcontentaspectratio21)设置窗口内容布局的比例。

> **说明：**
> 
> - 根据相同的ratio参数调整窗口宽高时，窗口宽高会跟随窗口边框装饰尺寸或可见性变化而调整。
> 
> - 通过[setWindowDecorVisible](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowdecorvisible11)将窗口标题栏设置为不可见时，窗口内容区域将占据原本标题栏的高度空间。
> 
> - 通过其他接口如[resize](../reference/apis-arkui/arkts-apis-window-Window.md#resize9-1)、[resizeAsync](../reference/apis-arkui/arkts-apis-window-Window.md#resizeasync12)设置窗口大小时，不受ratio约束。
> 
> - 仅主窗可设置，且仅在自由悬浮窗口模式（即窗口模式为window.WindowStatusType.FLOATING）下生效。
> 
> - API version 21以前的版本，请使用[setAspectRatio()](../reference/apis-arkui/arkts-apis-window-Window.md#setaspectratio10)设置窗口内容布局。

示例代码如下：

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    try {
      let windowClass = windowStage.getMainWindowSync();
      let ratio = 1.0;
      let promise = windowClass.setContentAspectRatio(ratio, true, true);
      promise.then(() => {
        console.info('Succeeded in setting aspect ratio of window.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to set the aspect ratio of window. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      console.error(`Failed to set the aspect ratio of window. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

## 如何设置窗口支持的显示模式supportWindowMode

在应用开发中， 推荐通过[module.json5](../quick-start/module-configuration-file.md)配置文件中的[abilities标签](../quick-start/module-configuration-file.md#abilities标签)的supportWindowMode字段设置窗口支持的显示模式。

supportWindowMode支持的取值如下：

| 配置值 | 模式 |
| -------- | -------- |
| "fullscreen" | 全屏模式 |
| "split" | 分屏模式 |
| "floating" | 自由悬浮窗口模式 |

> **说明：**
> 
> - supportWindowMode字段类型为字符串数组，可缺省，缺省值为["fullscreen", "split", "floating"]。
> 
> - 在[自由窗口](window-terminology.md#freeform-window自由窗口)状态下同时配置fullscreen和split时，如果应用的[targetAPIVersion](../quick-start/app-configuration-file.md#配置文件标签)小于15，窗口将以自由悬浮窗口模式启动；如果应用的[targetAPIVersion](../quick-start/app-configuration-file.md#配置文件标签)大于等于15，窗口将以全屏模式启动。

module.json5配置示例如下：

```json5
{
  "module": {
    "abilities": [
      {
        "name": "EntryAbility",
        "srcEntry": "./ets/entryability/EntryAbility.ets",
        "description": "$string:EntryAbility_desc",
        "displayName": "$string:EntryAbility_displayName",
        "windowSize": {
          "minWidth": 320,
          "minHeight": 240
        },
        // 控制支持的窗口模式
        "supportWindowMode": ["fullscreen", "split", "floating"],
        "launchType": "standard",
        "excludeFromMissions": false
      }
    ]
  }
}
```

除以上配置方式外，应用可参考以下几种方式配置窗口支持的模式：

- 使用[metadata](window-config-m.md)标签配置，name为'ohos.ability.window.supportWindowModeInFreeMultiWindow'，该字段配置仅在自由多窗下生效。

- 在启动UIAbility时，通过[StartOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md#startoptions)中的supportWindowModes字段指定窗口是否显示最大化/窗口化/分屏按键。

- 在启动后，可通过调用[setSupportedWindowModes()](../reference/apis-arkui/arkts-apis-window-WindowStage.md#setsupportedwindowmodes15)接口动态修改当前主窗口支持的窗口模式。

> **说明：**
> 
> 自由多窗下的可支持窗口模式可以采用多种方法进行配置，配置优先级为：
>
> 通过[setSupportedWindowModes](../reference/apis-arkui/arkts-apis-window-WindowStage.md#setsupportedwindowmodes15)接口配置 &gt; 通过StartAbility配置[StartOption](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md#startoptions)中的SupportWindowMode &gt; 使用metadata配置 &gt; 配置module.json5中[abilities](../quick-start/module-configuration-file.md#abilities标签)标签下的SupportWindowMode属性。

## 如何判断当前窗口是否为自由悬浮窗口模式

在应用开发中，有以下两种方式可判断应用是否处于自由悬浮窗口模式。

- 可通过[getWindowStatus()](../reference/apis-arkui/arkts-apis-window-Window.md#getwindowstatus12)直接查询当前的窗口模式。当WindowStatusType为FLOATING时，表示应用处于自由悬浮窗口模式。

  不同返回值及对应的窗口模式如下表所示：

  | 名称 | 值 | 说明 |
  | -------- | -------- | -------- |
  | UNDEFINED | 0 | 表示APP未定义窗口模式。 |
  | FULL_SCREEN | 1 | 表示APP全屏模式。<br>[自由窗口](window-terminology.md#freeform-window自由窗口)状态下，窗口铺满整个屏幕，默认无dock栏、标题栏和状态栏显示。<br>可通过[maximize()](../reference/apis-arkui/arkts-apis-window-Window.md#maximize12)和[setTitleAndDockHoverShown()](../reference/apis-arkui/arkts-apis-window-Window.md#settitleanddockhovershown14)配置，当hover到热区时是否显示标题栏和dock栏。<br>当maximize()和setTitleAndDockHoverShown()接口都调用时，以最后调用设置的效果为准。<br>非[自由窗口](window-terminology.md#freeform-window自由窗口)状态下，窗口铺满整个屏幕，无标题栏和dock栏显示。可通过[setSpecificSystemBarEnabled()](../reference/apis-arkui/arkts-apis-window-Window.md#setspecificsystembarenabled11)配置是否显示状态栏。 |
  | MAXIMIZE | 2 | 表示APP窗口最大化模式，在PC/2in1设备中，窗口铺满整个屏幕，有dock栏和状态栏。 |
  | MINIMIZE | 3 | 表示APP窗口最小化模式。 |
  | FLOATING | 4 | 表示APP自由悬浮窗口模式。 |
  | SPLIT_SCREEN | 5 | 表示APP分屏模式。 |

- 可通过[on('windowStatusChange')](../reference/apis-arkui/arkts-apis-window-Window.md#onwindowstatuschange11)接口监听窗口模式变化。

  如果应用需要在窗口模式发生变化时（例如从全屏切换到自由悬浮窗口模式）立即做出响应，可以使用此接口监听窗口模式变化，以实现对应业务适配。

  ```ts
  import { UIAbility } from '@kit.AbilityKit';
  import { window } from '@kit.ArkUI';
  
  export default class EntryAbility extends UIAbility {
    // ...
    onWindowStageCreate(windowStage: window.WindowStage) {
      console.info('onWindowStageCreate');
      let windowClass: window.Window = windowStage.getMainWindowSync(); // 获取应用主窗口
      if (!windowClass) {
        console.info('windowClass is null');
      }
      try {
        // 注册窗口状态变化监听
        windowClass.on('windowStatusChange', (windowStatusType: window.WindowStatusType) => {
          console.info(`status change, new status: ${windowStatusType}`);
        });
      } catch (error) {
        console.error(`status listen err: ${JSON.stringify(error)}`);
      }
      // 注意：在合适的时机，例如组件销毁时，记得取消监听
      // windowClass.off('windowStatusChange');
    }
  }
  ```

- 可通过[on('windowStatusDidChange')](../reference/apis-arkui/arkts-apis-window-Window.md#onwindowstatusdidchange20)接口监听窗口模式变化。

  使用此接口开启窗口模式变化的监听后，当窗口windowStatus发生变化后进行通知（此时窗口[Rect](../reference/apis-arkui/arkts-apis-window-i.md#rect7)属性已经完成更新）。

  ```ts
  import { window } from '@kit.ArkUI';
  
  try {
    // 请先获取Window实例
    windowClass.on('windowStatusDidChange', (WindowStatusType) => {
      console.info(`Succeeded in enabling the listener for window status changes. Data: ${JSON.stringify(WindowStatusType)}`);
    });
  } catch (exception) {
    console.error(`Failed to unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
  }
  ```

> **说明：**
> 
> [on('windowStatusChange')](../reference/apis-arkui/arkts-apis-window-Window.md#onwindowstatuschange11)和[on('windowStatusDidChange')](../reference/apis-arkui/arkts-apis-window-Window.md#onwindowstatusdidchange20)均在窗口windowStatus发生变化时进行通知，[on('windowStatusChange')](../reference/apis-arkui/arkts-apis-window-Window.md#onwindowstatuschange11)不保证回调发生时窗口属性更新完成，应用若需要在收到windowStatus变化通知时能够立即获取到变化后的窗口大小、位置，建议使用[on('windowStatusDidChange')](../reference/apis-arkui/arkts-apis-window-Window.md#onwindowstatusdidchange20)。

## 如何设置全局悬浮窗背景色为透明

可以通过调用[setWindowBackgroundColor](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowbackgroundcolor9)接口，传入'\#00XXXXXX'（其中X代表任意十六进制数字）或者透明的[ColorMetrics](../reference/apis-arkui/js-apis-arkui-graphics.md#colormetrics12)实现窗口背景透明。

## 如何判断应用被部分遮挡或完全遮挡

目前要判断当前窗口是否被遮挡有两个接口：

- [on('windowVisibilityChange')](../reference/apis-arkui/arkts-apis-window-Window.md#onwindowvisibilitychange11)：监听窗口可见性，当回调为false时，表示当前窗口不可见，完全被遮挡；当回调返回true时，表示当前窗口可见，但不能区分是部分遮挡还是无遮挡。

- [on('occlusionStateChanged')](../reference/apis-arkui/arkts-apis-window-Window.md#onocclusionstatechanged22)：监听窗口可见性，返回三种可见状态：无遮挡（表示完全可见，值为0）、部分遮挡（表示部分可见，值为1）、完全遮挡（表示不可见，值为2）。

## 如何判断设备是否开启了自由多窗

可通过[isInFreeWindowMode()](../reference/apis-arkui/arkts-apis-window-Window.md#isinfreewindowmode22)接口查询是否处于自由窗口状态。返回值为true时，表示当前窗口在自由窗口模式，返回值为false时，表示在非自由窗口模式。

可通过[on('freeWindowModeChange')](../reference/apis-arkui/arkts-apis-window-Window.md#onfreewindowmodechange22)接口监听自由窗口模式变化。

## 如何设置隐私窗口

可通过[setWindowPrivacyMode](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowprivacymode9-1)接口设置窗口为隐私模式，设置为隐私模式的窗口，窗口内容将无法被截屏或录屏。

对于画中画和闪控球窗口，其隐私模式跟随父窗口。

若需要对隐私窗口进行截图，可使用[snapshotIgnorePrivacy()](../reference/apis-arkui/arkts-apis-window-Window.md#snapshotignoreprivacy18)接口。

## APP退后台在多任务窗口展示时，如何实现模糊效果
APP可以通过监听主窗口生命周期状态，并用[AppStorage]( ../ui/state-management/arkts-appstorage.md)存储该状态，当状态为前台不可交互状态或后台状态时，设置组件[foregroundBlurStyle](../reference/apis-arkui/arkui-ts/ts-universal-attributes-foreground-blur-style.md#foregroundblurstyle)。

示例代码如下所示：

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
    windowStage.loadContent('pages/Index', (err) => {
      if (err.code) {
        console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      console.info('Succeeded in loading the content.');
    });
    AppStorage.setOrCreate('windowStage', windowStage);
    windowStage.on('windowStageEvent', (data) => {
      console.info('Succeeded in enabling the listener for window stage event changes. Data : ' +
        JSON.stringify(data));
      // 根据事件状态类型选择进行相应的处理
      if (data == window.WindowStageEventType.SHOWN) {
        console.info('current window stage event is SHOWN');
        AppStorage.setOrCreate('interact', true);
        // 应用进入前台为前台状态时，默认为可交互状态
        // ...
      } else if (data == window.WindowStageEventType.HIDDEN) {
        console.info('current window stage event is HIDDEN');
        AppStorage.setOrCreate('interact', false);
        // 应用进入后台为后台状态时，默认为不可交互状态
        // ...
      } else if (data == window.WindowStageEventType.PAUSED) {
        console.info('current window stage event is PAUSED');
        AppStorage.setOrCreate('interact', false);
        // 前台应用进入多任务为前台不可交互状态时，转为不可交互状态
        // ...
      } else if (data == window.WindowStageEventType.RESUMED) {
        console.info('current window stage event is RESUMED');
        AppStorage.setOrCreate('interact', true);
        // 应用进入多任务后又继续返回前台为前台可交互状态时，恢复可交互状态
        // ...
      }
    });
  }
}
```

```ts
// ets/pages/Index.ets
@Entry
@Component
struct Index {
  @StorageLink('interact') interact: boolean = true;
  build() {
    Column() {
      Text('文本文本')
        .fontSize(60)
    }
    .foregroundBlurStyle(this.interact ? BlurStyle.NONE : BlurStyle.COMPONENT_ULTRA_THICK) // 可自定义模糊程度
  }
}
```

## resize、moveWindowTo等接口有什么位置/大小限制

当调用[resize()](../reference/apis-arkui/arkts-apis-window-Window.md#resize9-1)接口调整窗口大小时，窗口尺寸大小范围会受到[WindowLimits](../reference/apis-arkui/arkts-apis-window-i.md#windowlimits11)限制，具体尺寸限制范围可以通过[getWindowLimits](https://developer.huawei.com/consumer/cn/doc/harmonyos-references/arkts-apis-window-window#getwindowlimits11)接口进行查询。

调用[moveWindowTo()](../reference/apis-arkui/arkts-apis-window-Window.md#movewindowto9-1)接口调整窗口位置对窗口位置无限制。

> **说明：**
> 
> **resize接口其他限制：**
> 
> - 在[自由窗口](window-terminology.md#freeform-window自由窗口)状态下，窗口为自由悬浮窗口模式（即窗口模式为window.WindowStatusType.FLOATING，WindowStatusType可通过[getWindowStatus()](../reference/apis-arkui/arkts-apis-window-Window.md#getwindowstatus12)获取）时调用生效，否则抛出错误码1300002。
> 
> - 在非[自由窗口](window-terminology.md#freeform-window自由窗口)状态下，主窗口调用不生效。
> 
> **moveWindowTo接口其他限制：**
> 
> - 不建议在除自由悬浮窗口模式（即窗口模式为window.WindowStatusType.FLOATING，WindowStatusType可通过[getWindowStatus()](../reference/apis-arkui/arkts-apis-window-Window.md#getwindowstatus12)获取）外的其他窗口模式下使用。
> 
> - 在[自由窗口](window-terminology.md#freeform-window自由窗口)状态下，窗口相对于屏幕移动；在非自由窗口状态下，窗口相对于父窗口移动。
> 
> - 若需在非自由窗口状态下实现相对于屏幕的移动，请使用[moveWindowToGlobal()](../reference/apis-arkui/arkts-apis-window-Window.md#movewindowtoglobal15)。
> 
> - 在非[自由窗口](window-terminology.md#freeform-window自由窗口)状态下，主窗口调用不生效。

## 如何设置或取消水印

<!--Del-->
水印按照作用范围可分为如下3类：

- 窗口级水印：可通过[setWaterMarkFlag()](../reference/apis-arkui/js-apis-window-sys.md#setwatermarkflag10)为当前窗口添加或删除安全水印标志。
<!--DelEnd-->

- 进程级水印：可通过[setWatermarkImageForAppWindows()](../reference/apis-arkui/arkts-apis-window-f.md#windowsetwatermarkimageforappwindows21)设置或取消应用进程级水印，针对当前应用进程的窗口生效，包括后续该进程新创建的窗口。

<!--Del-->
- 屏幕级水印：可通过[window.setWaterMarkImage](../reference/apis-arkui/js-apis-window-sys.md#windowsetwatermarkimage10)设置和取消屏幕级水印。
<!--DelEnd-->

## 如何将创建的窗口移动到扩展屏

- 应用可通过主动调用[moveWindowToGlobal()](../reference/apis-arkui/arkts-apis-window-Window.md#movewindowtoglobal15)接口将当前窗口移动到扩展屏幕，通过配置接口参数中的[MoveConfiguration](../reference/apis-arkui/arkts-apis-window-i.md#moveconfiguration15)指定当前窗口期望移动的目标屏幕。

- 应用也可调用[startMoving()](../reference/apis-arkui/arkts-apis-window-Window.md#startmoving14)接口通过鼠标或触摸点拖拽将当前窗口移动到目标屏幕上。该接口仅在[onTouch](../reference/apis-arkui/arkui-ts/ts-universal-events-touch.md#ontouch)事件（其中，事件类型必须为TouchType.Down）的回调方法中调用才会有移动效果，成功调用此接口后，窗口将跟随鼠标或触摸点移动。

## 子窗口背景如何实现半透明效果

子窗口可以调用[setWindowBackgroundColor](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowbackgroundcolor9)接口，传入'\#XXYYYYYY'（其中XX代表任意十六进制且不为0数值，Y表示任意十六进制数字）或者半透明的[ColorMetrics](../reference/apis-arkui/js-apis-arkui-graphics.md#colormetrics12)。

示例代码如下所示：

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { ColorMetrics } from '@kit.ArkUI';
import { window } from '@kit.ArkUI';

let storage: LocalStorage = new LocalStorage();
storage.setOrCreate('storageSimpleProp', 121);
windowClass.loadContent("pages/page2", storage, (err: BusinessError) => {
  let errCode: number = err.code;
  if (errCode) {
  console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
  return;
  }
  console.info('Succeeded in loading the content.');
  let color1: string = '#8800FF33'; // 采用ARGB方式
  let color2: ColorMetrics = ColorMetrics.numeric(0x88112233);  // 采用ColorMetrics方式
  try {
    windowClass?.setWindowBackgroundColor(color1);
    windowClass?.setWindowBackgroundColor(color2);
  } catch (exception) {
    console.error(`Failed to set the background color. Cause code: ${exception.code}, message: ${exception.message}`);
  };
});
```

## 如何设置页面级亮度

当前不支持设置页面级亮度，仅支持设置窗口级亮度。

应用若想实现页面级亮度调整，可以在进入特定页面时在主窗调用[setWindowBrightness()](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowbrightness9-1)调整亮度，在退出特定页面时，在主窗调用[setWindowBrightness()](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowbrightness9-1)传入-1，恢复为系统屏幕亮度。

## 如何恢复系统屏幕亮度

针对Phone、Tablet设备，应用可以调用[setWindowBrightness()](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowbrightness9-1)传入-1，即可恢复为系统屏幕亮度。

针对PC/2in1设备，由于窗口亮度和系统亮度已实现归一化，故调用[setWindowBrightness()](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowbrightness9-1)接口后将直接改变系统亮度，目前尚无恢复至调用前窗口亮度的方法。

## 如何正常获取顶层窗口

**问题现象**

当使用[getLastWindow()](../reference/apis-arkui/arkts-apis-window-f.md#windowgetlastwindow9)获取应用最顶层窗口时，获取到了正在销毁的子窗。

**产生原因**

当使用[destroyWindow()](../reference/apis-arkui/arkts-apis-window-Window.md#destroywindow9)销毁子窗时，未等待其销毁完成即调用[getLastWindow()](../reference/apis-arkui/arkts-apis-window-f.md#windowgetlastwindow9)，导致获取到了正在销毁的子窗。

**解决措施**

在使用[getLastWindow()](../reference/apis-arkui/arkts-apis-window-f.md#windowgetlastwindow9)获取应用最顶层窗口前，应确保子窗销毁、窗口创建等操作已完成。

**示例代码**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

let lastWindow: window.Window | undefined = undefined;
// 不建议写法
try {
  // 请先获取window实例
  windowClass.destroyWindow();
  try {
    window.getLastWindow(this.context).then((topWindow) => {
      lastWindow = topWindow;
    }).catch((err: BusinessError) => {
      console.error(`Failed to obtain the last window. Cause code: ${err.code}, message: ${err.message}`);
    });
  } catch (exception) {
    console.error(`Failed to obtain the last window. Cause code: ${exception.code}, message: ${exception.message}`);
  }
} catch (exception) {
  console.error(`Failed to destroy. Cause code: ${exception.code}, message: ${exception.message}`);
};

// 建议写法
try {
  // 请先获取window实例
  windowClass.destroyWindow().then(() => {
    try {
      window.getLastWindow(this.context).then((topWindow) => {
        lastWindow = topWindow;
      }).catch((err: BusinessError) => {
        console.error(`Failed to obtain the last window. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      console.error(`Failed to obtain the last window. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to destroy the window. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to destroy. Cause code: ${exception.code}, message: ${exception.message}`);
};
```

## getWindowProperties接口返回值中的窗口类型（type字段）不符合预期

**问题现象**

因为历史问题，主窗场景调用[getWindowProperties()](../reference/apis-arkui/arkts-apis-window-Window.md#getwindowproperties9)获取到的窗口类型即[WindowType](../reference/apis-arkui/arkts-apis-window-e.md#windowtype7)为TYPE_SYSTEM_ALERT而不是TYPE_MAIN。

**解决措施**

系统的后续API版本中将提供新的字段修正。

应用内创建窗口时需要指明窗口类型，开发者可以直接感知窗口类型，不必要通过此接口主动获取。

## on('windowSizeChange')等监听回调中通过getWindowAvoidArea()接口获取到的避让区域数据不是最新的

**问题现象**

在[on('windowSizeChange')](../reference/apis-arkui/arkts-apis-window-Window.md#onwindowsizechange7)、[on('windowRectChange')](../reference/apis-arkui/arkts-apis-window-Window.md#onwindowrectchange12)等窗口属性变化监听回调中，通过[getWindowAvoidArea()](../reference/apis-arkui/arkts-apis-window-Window.md#getwindowavoidarea9)接口获取到的避让区域数据不准确。

**产生原因**

避让区域更新同时依赖窗口位置/尺寸属性的更新和系统界面元素（如状态栏）的位置/尺寸更新，在窗口属性更新回调触发时系统界面元素不一定已完成更新，这个时候通过getWindowAvoidArea()接口不能拿到准确的避让区域。

**解决措施**

通过避让区域专有的监听接口[on('avoidAreaChange')](../reference/apis-arkui/arkts-apis-window-Window.md#onavoidareachange9)监听避让区域变化，避免在其他窗口属性变化事件回调中通过getWindowAvoidArea()接口主动获取避让区域。

**示例代码**

```ts
import { window } from '@kit.ArkUI';

// 代码中假设windowClass为已获取的Window实例

// 错误写法：监听windowSizeChange事件主动获取避让区域
windowClass.on('windowSizeChange', () => {
  try {
    const systemAvoidArea = windowClass.getWindowAvoidArea(window.AvoidAreaType.TYPE_SYSTEM);  // 获取到的避让区域不准确
  } catch (exception) {
    console.error(`Failed to get window avoid area. Cause code: ${exception.code}, message: ${exception.message}`);
  }
});

// 正确写法：监听avoidAreaChange事件
windowClass.on('avoidAreaChange', (data) => {
  if (data.type === window.AvoidAreaType.TYPE_SYSTEM) {
    const systemAvoidArea = data.area;  // 回调中的数据总是准确的避让区域
  }
});
```
