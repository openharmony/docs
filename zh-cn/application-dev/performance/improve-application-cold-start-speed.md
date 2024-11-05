# 提升应用冷启动速度

应用启动时延是影响用户体验的关键要素。当应用启动时，后台没有该应用的进程，这时系统会重新创建一个新的进程分配给该应用， 这个启动方式就叫做冷启动。

## 分析应用冷启动耗时

应用冷启动过程大致可分成以下四个阶段：应用进程创建&初始化、Application&Ability初始化、Ability/AbilityStage生命周期、加载绘制首页，如下图：

![输入图片说明](figures/application-cold-start.png)

>**说明：**
>
>关于本文中示例，可参考：[提升应用冷启动速度示例](https://gitee.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Ability/Performance/Startup)。

## 1、缩短应用进程创建&初始化阶段耗时

该阶段主要是系统完成应用进程的创建以及初始化的过程，包含了启动页图标(startWindowIcon)的解码。

### 设置合适分辨率的startWindowIcon

该优化场景仅支持rk3568开发板。如果启动页图标分辨率过大，解码耗时会影响应用的启动速度，建议启动页图标分辨率不超过256像素*256像素，如下所示：

```json
    "abilities": [
      {
        "name": "EntryAbility",
        "srcEntry": "./ets/entryability/EntryAbility.ets",
        "description": "$string:EntryAbility_desc",
        "icon": "$media:icon",
        "label": "$string:EntryAbility_label",
        "startWindowIcon": "$media:startIcon", // 在这里修改启动页图标，建议不要超过256像素x256像素
        "startWindowBackground": "$color:start_window_background",
        "exported": true,
        "skills": [
          {
            "entities": [
              "entity.system.home"
            ],
            "actions": [
              "action.system.home"
            ]
          }
        ]
      }
    ]
```

下面使用[SmartPerf](https://gitee.com/openharmony/developtools_smartperf_host)工具，对使用优化前的启动页图标（4096像素\*4096像素）及使用优化后的启动页图标（144像素\*144像素）的启动性能进行对比分析。分析阶段的起点为点击应用图标打开应用时触发的触摸事件（即`ProcessTouchEvent`的结束点），阶段终点为应用第一次接到vsync（即`H:ReceiveVsync dataCount:24Bytes now:timestamp expectedEnd:timestamp vsyncId:int`的开始点）。

对比数据如下（性能耗时数据因设备版本而异，以实测为准）：

|                        | 阶段时长（ms） |
| ---------------------- | -------------- |
| 使用优化前的启动页图标 |      998.6     |
| 使用优化后的启动页图标 |      722.5     |

可见阶段时长已缩短，故设置合适分辨率的startWindowIcon对缩短应用进程创建&初始化阶段耗时是有效的。

## 2、缩短Application&Ability初始化阶段耗时

该阶段主要是资源加载、虚拟机创建、Application&Ability相关对象的创建与初始化、依赖模块的加载等。

### 减少import的模块

应用代码执行前，应用程序必须找到并加载import的所有模块。应用程序启动时会因加载并使用的每个额外第三方框架或模块而增加启动耗时，耗时长短取决于加载的第三方框架或者模块的数量和大小。推荐开发者尽可能使用系统提供的模块，按需加载，来缩短应用程序的启动耗时。

以下为示例代码：

```ts
// 优化减少import的模块
// import { particleAbility, featureAbility, wantConstant } from '@kit.AbilityKit';
// import { FormExtensionAbility } from '@kit.FormKit';
// import { GesturePath, GesturePoint } from '@kit.AccessibilityKit';
// import { distributedAccount, BusinessError, osAccount } from '@kit.BasicServicesKit';
// import { webview } from '@kit.ArkWeb';

import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    ...
    // webview.WebviewController.initializeWebEngine();
    ...
  }
  ...
}
```

需要说明，这里为了方便对比该阶段导入模块和不导入模块的性能差异，用一个@ohos.web.webview模块进行对比，这里假设@ohos.web.webview模块并非该阶段必须导入的模块。而在实际业务场景中，由于webview初始化时间较长，如果放到页面跳转时再导入该模块进行使用，有可能会劣化页面跳转的完成时延。因此，模块是否能在该阶段进行优化还需要结合具体业务场景进行评估。

下面使用DevEco Studio内置的Profiler中的启动分析工具Launch，对优化import的模块前（导入@ohos.web.webview模块）及优化import的模块后（不导入@ohos.web.webview模块）的启动性能进行对比分析。下面是Launch工具抓取的UI Ability Launching（加载UI Ability）和UI Ability OnForeground（应用进入前台）耗时，对比数据如下（性能耗时数据因设备型号版本而异，以实测为准）：

|                    | UI Ability Launching阶段时长（ms）   | UI Ability OnForeground阶段时长（ms）   |
| ------------------ | ------------------------------------ | --------------------------------------- |
| 优化import的模块前 |                   26                 |                  277                    |
| 优化import的模块后 |                   10                 |                  53                     |

可见阶段时长已缩短，故减少import的模块对缩短Application&Ability初始化阶段耗时是有效的。这里建议该阶段应减少应用启动时非必要的import模块，按需加载模块，缩短应用程序的启动耗时。

## 3、缩短AbilityStage生命周期阶段耗时

该阶段主要是AbilityStage的启动生命周期，执行相应的生命周期回调。

### 避免在AbilityStage生命周期回调接口进行耗时操作

在应用启动流程中，系统会执行AbilityStage的生命周期回调函数。因此，不建议在这些回调函数中执行耗时过长的操作，耗时操作建议通过异步任务延迟处理或者放到其他线程执行。

在这些生命周期回调里，推荐开发者只做必要的操作，详情可以参考：[AbilityStage组件容器](../application-models/abilitystage.md)。

以下为示例代码：

```ts
const LARGE_NUMBER = 10000000;
const DELAYED_TIME = 1000;

export default class MyAbilityStage extends AbilityStage {
  onCreate(): void {
    // 耗时操作
    // this.computeTask();
    this.computeTaskAsync(); // 异步任务
  }

  onAcceptWant(want: Want): string {
    // 仅specified模式下触发
    return 'MyAbilityStage';
  }

  computeTask(): void {
    let count = 0;
    while (count < LARGE_NUMBER) {
      count++;
    }
  }

  private computeTaskAsync(): void {
    setTimeout(() => { // 这里使用setTimeout来实现异步延迟运行
      this.computeTask();
    }, DELAYED_TIME);
  }
}
```

下面使用[SmartPerf](https://gitee.com/openharmony/developtools_smartperf_host)工具，对优化前同步执行耗时操作及优化后异步执行耗时操作的启动性能进行对比分析。分析阶段的起点为启动Ability（即`H:void OHOS::AppExecFwk::MainThread::HandleLaunchAbility`的开始点），阶段终点为应用第一次接到vsync（即`H:ReceiveVsync dataCount:24Bytes now:timestamp expectedEnd:timestamp vsyncId:int`的开始点）。

对比数据如下：

|                        | 阶段开始(秒)   | 阶段结束(秒)   | 阶段时长(秒) |
| ---------------------- | -------------- | -------------- | ------------ |
| 优化前同步执行耗时操作 | 2124.915558194 | 2127.041354575 | 2.125796381  |
| 优化后异步执行耗时操作 | 4186.436835246 | 4186.908777335 | 0.471942089  |

可见阶段时长已缩短，故避免在AbilityStage生命周期回调接口进行耗时操作对缩短AbilityStage生命周期阶段耗时是有效的。

## 4、缩短Ability生命周期阶段耗时

该阶段主要是Ability的启动生命周期，执行相应的生命周期回调。

### 避免在Ability生命周期回调接口进行耗时操作

在应用启动流程中，系统会执行Ability的生命周期回调函数。因此，不建议在这些回调函数中执行耗时过长的操作，耗时操作建议通过异步任务延迟处理或者放到其他线程执行。

在这些生命周期回调里，推荐开发者只做必要的操作，下面以UIAbility为例进行说明。关于UIAbility组件生命周期的详细说明，参见[UIAbility组件生命周期](../application-models/uiability-lifecycle.md)。

```ts
const LARGE_NUMBER = 10000000;
const DELAYED_TIME = 1000;

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    hilog.info(0x0000, 'testTag', 'Ability onCreate');
    // 耗时操作
    // this.computeTask();
    this.computeTaskAsync(); // 异步任务
  }

  onDestroy(): void {
    hilog.info(0x0000, 'testTag', 'Ability onDestroy');
  }

  onWindowStageCreate(windowStage: window.WindowStage): void {
    hilog.info(0x0000, 'testTag', 'Ability onWindowStageCreate');

    windowStage.loadContent('pages/Index', (err, data) => {
      if (err.code) {
        hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: ' + JSON.stringify(err) ?? '');
        return;
      }
      hilog.info(0x0000, 'testTag', 'Succeeded in loading the content. Data: ' + JSON.stringify(data) ?? '');
    });

    // 耗时操作
    // this.computeTask();
    this.computeTaskAsync(); // 异步任务
  }

  onWindowStageDestroy(): void {
    hilog.info(0x0000, 'testTag', 'Ability onWindowStageDestroy');
  }

  onForeground(): void {
    hilog.info(0x0000, 'testTag', 'Ability onForeground');
    // 耗时操作
    // this.computeTask();
    this.computeTaskAsync(); // 异步任务
  }

  onBackground(): void {
    hilog.info(0x0000, 'testTag', 'Ability onBackground');
  }

  computeTask(): void {
    let count = 0;
    while (count < LARGE_NUMBER) {
      count++;
    }
  }

  private computeTaskAsync(): void {
    setTimeout(() => { // 这里使用setTimeout来实现异步延迟运行
      this.computeTask();
    }, DELAYED_TIME);
  }
}
```

下面使用[SmartPerf](https://gitee.com/openharmony/developtools_smartperf_host)工具，对优化前同步执行耗时操作及优化后异步执行耗时操作的启动性能进行对比分析。分析阶段的起点为启动Ability（即`H:void OHOS::AppExecFwk::MainThread::HandleLaunchAbility`的开始点），阶段终点为应用第一次接到vsync（即`H:ReceiveVsync dataCount:24Bytes now:timestamp expectedEnd:timestamp vsyncId:int`的开始点）。

对比数据如下：

|                        | 阶段开始(秒)   | 阶段结束(秒)   | 阶段时长(秒) |
| ---------------------- | -------------- | -------------- | ------------ |
| 优化前同步执行耗时操作 | 1954.987630036 | 1957.565964504 | 2.578334468  |
| 优化后异步执行耗时操作 | 4186.436835246 | 4186.908777335 | 0.471942089  |

可见阶段时长已缩短，故避免在Ability生命周期回调接口进行耗时操作对缩短Ability生命周期阶段耗时是有效的。

## 5、缩短加载绘制首页阶段耗时

该阶段主要是加载首页内容、测量布局、刷新组件并绘制。

### 自定义组件生命周期回调接口里避免耗时操作

自定义组件的生命周期变更会调用相应的回调函数。

aboutToAppear函数会在创建自定义组件实例后，页面绘制之前执行，以下代码在aboutToAppear中对耗时间的计算任务进行了异步处理，避免在该接口执行该耗时操作，不阻塞页面绘制。

以下为示例代码：

```ts
const LARGE_NUMBER = 10000000;
const DELAYED_TIME = 1000;

@Entry
@Component
struct Index {
  @State private text: string = "";
  private count: number = 0;

  aboutToAppear() {
    // 耗时操作
    // this.computeTask();
    this.computeTaskAsync(); // 异步任务
    let context = getContext(this) as Context;
    this.text = context.resourceManager.getStringSync($r('app.string.startup_text'));
  }

  build() {
    Column({ space: 10 }) {
      Text(this.text).fontSize(50)
    }
    .width('100%')
    .height('100%')
    .padding(10)
  }

  computeTask(): void {
    this.count = 0;
    while (this.count < LARGE_NUMBER) {
      this.count++;
    }
    let context = getContext(this) as Context;
    this.text = context.resourceManager.getStringSync($r('app.string.task_text'));
  }

  // 运算任务异步处理
  private computeTaskAsync(): void {
    setTimeout(() => { // 这里使用setTimeout来实现异步延迟运行
      this.computeTask();
    }, DELAYED_TIME);
  }
}
```

下面使用[SmartPerf](https://gitee.com/openharmony/developtools_smartperf_host)工具，对优化前同步执行耗时操作及优化后异步执行耗时操作的启动性能进行对比分析。分析阶段的起点为启动Ability（即`H:void OHOS::AppExecFwk::MainThread::HandleLaunchAbility`的开始点），阶段终点为应用第一次接到vsync（即`H:ReceiveVsync dataCount:24Bytes now:timestamp expectedEnd:timestamp vsyncId:int`的开始点）。

对比数据如下：

|                        | 阶段开始(秒)   | 阶段结束(秒)   | 阶段时长(秒) |
| ---------------------- | -------------- | -------------- | ------------ |
| 优化前同步执行耗时操作 | 3426.272974492 | 3431.785898837 | 5.512924345  |
| 优化后异步执行耗时操作 | 4186.436835246 | 4186.908777335 | 0.471942089  |

可见阶段时长已缩短，故自定义组件生命周期回调接口里避免耗时操作对缩短加载绘制首页阶段耗时是有效的。