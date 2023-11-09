# 提升应用冷启动速度

应用启动时延是影响用户体验的关键要素。当应用启动时，后台没有该应用的进程，这时系统会重新创建一个新的进程分配给该应用， 这个启动方式就叫做冷启动。

## 分析应用冷启动耗时

应用冷启动过程大致可分成以下四个阶段：应用进程创建&初始化、Application&Ability初始化、Ability生命周期、加载绘制首页，如下图：

![输入图片说明](figures/application-cold-start.png)

## 1、缩短应用进程创建&初始化阶段耗时

该阶段主要是系统完成应用进程的创建以及初始化的过程，包含了启动页图标(startWindowIcon)的解码。

### 设置合适分辨率的startWindowIcon

如果启动页图标分辨率过大，解码耗时会影响应用的启动速度，建议启动页图标分辨率不超过256像素*256像素，如下所示：

```json
    "abilities": [
      {
        "name": "EntryAbility",
        "srcEntrance": "./ets/entryability/EntryAbility.ts",
        "description": "$string:EntryAbility_desc",
        "icon": "$media:icon",
        "label": "$string:EntryAbility_label",
        "startWindowIcon": "$media:startWindowIcon",  // 在这里修改启动页图标，建议不要超过256像素x256像素
        "startWindowBackground": "$color:start_window_background",
        "visible": true,
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

## 2、缩短Application&Ability初始化阶段耗时

该阶段主要是资源加载、虚拟机创建、Application&Ability相关对象的创建与初始化、依赖模块的加载等。

### 减少import的模块

应用代码执行前，应用程序必须找到并加载import的所有模块，应用程序加载的每个额外的第三方框架或者模块都会增加启动时间，耗时长短取决于加载的第三方框架或者模块的数量和大小。推荐开发者尽可能使用系统提供的模块，按需加载，来缩短应用程序的启动耗时。

## 3、缩短Ability生命周期阶段耗时

该阶段主要是Ability的启动生命周期，执行相应的生命周期回调。

### 避免在Ability生命周期回调接口进行耗时操作

在应用启动流程中，系统会执行Ability的生命周期回调函数。因此，不建议在这些回调函数中执行耗时过长的操作，耗时操作建议通过异步任务延迟处理或者放到其他线程执行。

在这些生命周期回调里，推荐开发者只做必要的操作，详情可以参考：[UIAbility组件生命周期](../application-models/uiability-lifecycle.md)

## 4、缩短加载绘制首页阶段耗时

该阶段主要是加载首页内容、测量布局、刷新组件并绘制。

### 自定义组件生命周期回调接口里避免耗时操作

自定义组件的生命周期变更会调用相应的回调函数。

aboutToAppear函数会在创建自定义组件实例后，页面绘制之前执行，以下代码在aboutToAppear中对耗时长的计算任务进行了异步处理，避免在该接口执行该耗时操作，不阻塞页面绘制。

```typescript
@Entry
@Component
struct Index {
  @State private text: string = "";
  private count: number = 0;

  aboutToAppear() {
    this.computeTaskAsync(); // 异步任务
    this.text = "hello world";
  }

  build() {
    Column({space: 10}) {
      Text(this.text).fontSize(50)
    }
    .width('100%')
    .height('100%')
    .padding(10)
  }

   computeTask() {
    this.count = 0;
    while (this.count < 10000000) {
      this.count++;
    }
    this.text = 'task complete';
  }

  // 运算任务异步处理
  private computeTaskAsync() {
    setTimeout(() => { // 这里使用setTimeout来实现异步延迟运行
      this.computeTask();
    }, 1000)
  }
}
```