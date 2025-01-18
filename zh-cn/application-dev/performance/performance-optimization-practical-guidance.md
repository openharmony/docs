# 应用性能优化常见问题解决指导

## 概述

本文总结了实际开发应用时常见的性能优化规范，配合举例实际开发中常见的正反例代码，帮助开发者解决大部分性能问题。

### 性能规范总览目录
| &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;  &emsp;&emsp;  &emsp;&emsp; <br />分类<br />&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp; &emsp;&emsp;&emsp;&emsp;  &emsp;&emsp;   |<br />高频程度 (5满分)<br />&emsp;&emsp;&emsp;&emsp;   | 规范（检查项）       | 实操方法                |            <br />代码示例<br />&emsp;&emsp;&emsp;&emsp;                 |
|:-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|:---------------------------------------------------:|:---------------------------------------------------|:------------------------------------------------------------------------------------------------------------------------------------------------------------------------|:-------------------------------------------------------------------:|
| 响应时延&nbsp;/&nbsp;完成时延                                                                                                                                                    |                          5                          | 不建议在aboutToAppear(),aboutToDisappear()等生命周期中执行耗时操作 | 排查所有的aboutToAppear和aboutToDisappear函数(或者通过Trace查看)，查看是否有耗时操作，改为setTimeOut或者在TaskPool中执行。                                          |       [代码示例](#不建议在abouttoappearabouttodisappear等生命周期中执行耗时操作)        |
| 响应时延&nbsp;/&nbsp;完成时延                                                                                                                                                    |                          5                          | 不要在回调函数中执行耗时操作(ArkUI接口回调、网络访问回调、await等)            | 排查所有的回调函数(或者通过Trace查看)，尤其是ArkUI接口，网络回调函数，查看是否有耗时操作，是否使用了await操作，改为setTimeOut或者在TaskPool中执行。                      |            [代码示例](#不要在回调函数中执行耗时操作arkui接口回调网络访问回调await等)             |
| 响应时延&nbsp;/&nbsp;完成时延&nbsp;/&nbsp;帧率                                                                                                                                     |                          5                          | 列表场景未使用LazyForEach+组件复用+缓存列表项            | 排查使用LazyForEach的代码，确认是否有使用组件复用(@Reusable)+缓存列表项(cachedCount)。                                                                                                           |                [代码示例](#列表场景未使用lazyforeach组件复用缓存列表项)                 |
| 完成时延                                                                                                                                                                     |                          5                          | Web未使用预连接，未提前初始化引擎    | 在应用创建Ability的时候，在OnCreate阶段预先初始化内核，建议把引擎的初始化放在setTimeOut中。                                                                                                              |                     [代码示例](#web未使用预连接未提前初始化引擎)                      |
| 响应时延&nbsp;/&nbsp;完成时延                                                                                                                                                    |                          5                          | 高频接口中不要打印Trace和日志    | 排查接口onTouch、onItemDragMove、onDragMove、onDidScroll、onMouse、onVisibleAreaChange、OnAreaChange、onActionUpdate、animator的onFrame、组件复用场景下的aboutToReuse，不建议在里面打印trace和日志。          |                     [代码示例](#高频接口中不要打印trace和日志)                      |
| 完成时延&nbsp;/&nbsp;帧率                                                                                                                                                      |                          4                          | 组件复用里面有if语句，但是未使用reuseId            | 排查使用了@Reusable的自定义组件，查看build中给是否使用了if/else或ForEach等条件渲染语句，如果使用了，需要配合reuseId一起使用。                                                                                        |                  [代码示例](#组件复用里面有if语句但是未使用reuseid)                   |
| 响应时延&nbsp;/&nbsp;完成时延                                                                                                                                                    |                          4                          | 不建议使用@Prop装饰器           | 全局搜索@Prop并且替换                                                                                                                                           |                        [代码示例](#不建议使用prop装饰器)                        |
| 响应时延&nbsp;/&nbsp;完成时延                                                                                                                                                    |                          3                          | 避免在ResourceManager的getXXXSync接口入参中直接使用资源信息           | 排查ResourceManager.getXXXSync接口，查看入参时需要使用getStringSync($r('app.media.icon').id)的形式，如果未使用需要整改。                                                 | [代码示例](#避免在resourcemanager的getxxxsync接口入参中直接使用资源信息) |
| 响应时延&nbsp;/&nbsp;完成时延                                                                                                                                                    |                          3                          | 展示用的自定义组件（数据从父组件中获取，无独立数据处理）使用@Builder替换           | 审视@Component标记的自定义组件，如果里面没有独立的生命周期处理逻辑，数据由父组件传递，建议@Builder替代。                                                           |            [代码示例](#展示用的自定义组件数据从父组件中获取无独立数据处理使用builder替换)            |
| 响应时延&nbsp;/&nbsp;完成时延&nbsp;/&nbsp;帧率                                                                                                                                     |                          3                          | 删除无具体逻辑的生命周期，ArkUI的函数回调等，删除冗余堵塞日志打印           | 排查所有的aboutToAppear、aboutToDisappear等生命周期函数，排查ArkUI的回调函数，如果函数中无具体业务逻辑，例如只打印了日志，删除函数回调。                                        |             [代码示例](#删除无具体逻辑的生命周期arkui的函数回调等删除冗余堵塞日志打印)              |
| 响应时延&nbsp;/&nbsp;完成时延                                                                                                                                                    |                          3                          | 删除未关联组件的状态变量装饰器           | 排查全局的状态变量装饰器，如果变量未关联组件，删除装饰器。             |                      [代码示例](#删除未关联组件的状态变量装饰器)                       |
| 帧率                                                                                                                                                                       |                          2                          | 	crypto-js性能差           | 排查buffer.from关键字，加密建议使用原生的cryptoFramework，然后将buffer替换为base64helper，性能提升10倍以上， 且数据量越大越明显。             |                        [代码示例](#crypto-js性能差)                        |
| 响应时延&nbsp;/&nbsp;完成时延                                                                                                                                                    |                          1                          | 	不建议使用Marquee组件           | 排查Marquee关键字，使用Text的跑马灯模式(TextOverflow.MARQUEE)替代。             |                       [代码示例](#不建议使用marquee组件)                       |
| 完成时延                                                                                                                                                                     |                          1                          | 	不能使用函数作为ArkUI组件的属性和组件复用的自定义组件的入参           | 查看属性是否有xx()函数写法，确认函数/方法中是否有耗时操作，替换成变量。            |              [代码示例](#不能使用函数作为arkui组件的属性和组件复用的自定义组件的入参)              |
| 完成时延                                                                                                                                                                     |                          1                          | 	不建议使用.linearGradient颜色渐变属性           | 排查linearGradient关键字，可以使用图片代替。            |                 [代码示例](#不建议使用lineargradient颜色渐变属性)                  |
| 完成时延&nbsp;/&nbsp;帧率                                                                                                                                                      |                          1                          | 	不要在for/while循环中执行耗时操作           | 排查for/while循环，查看里面是否有打印日志或者Trace。            |                    [代码示例](#不要在forwhile循环中执行耗时操作)                    |
| 完成时延&nbsp;/&nbsp;帧率                                                                                                                                                      |                          1                          | 	变量初值不建议设置为undefined，需进行默认初始化           | 例如number设置为0，string设置为空字符串等，这样在使用过程中更不需要增加额外判空。排查类中的变量，看看是否有初始化为undefined。            |                [代码示例](#变量初值不建议设置为undefined需进行默认初始化)                 |

## 性能优化规范

### 不建议在aboutToAppear()、aboutToDisappear()等生命周期中执行耗时操作
#### 类型
响应时延/完成时延
#### 解决方法
排查所有的aboutToAppear和aboutToDisappear函数(或者通过Trace查看)，查看是否有耗时操作，改为setTimeOut或者在TaskPool中执行。

#### 反例
```typescript
@Entry
@Component
struct ViewA {
  @State private text: string = "";
  private count: number = 0;
  // 反例：在aboutToAppear接口中执行耗时操作，阻塞页面绘制。
  aboutToAppear() {
    // 耗时操作
    this.computeTask();
    let context = context.resourceManager.getStringSync($r('app.string.startup_text'));
  }

  computeTask(): void {
    this.count = 0;
    while (this.count < LARGE_NUMBER) {
    this.count++;
  }
  let context = getContext(this) as Context;
  this.text = context.resourceManager.getStringSync($r('app.string.task_text'));
}
}
```
#### 正例
```typescript
@Entry
@Component
struct ViewB {
  @State private text: string = "";
  private count: number = 0;
  private readonly DELAYED_TIME: number = 2000; // 定时器设置延时2s

  // 正例：在aboutToAppear接口中对耗时间的计算任务进行了异步处理。
  aboutToAppear() {
    // 耗时操作
    this.computeTaskAsync(); // 异步任务
    let context = getContext(this) as Context;
    this.text = context.resourceManager.getStringSync($r('app.string.startup_text'));
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
  setTimeout(() => {
  // 这里使用setTimeout来实现异步延迟运行
  this.computeTask();
  }, DELAYED_TIME)
}
}
```
#### 高频程度&收益（5满分）
5

### 不要在回调函数中执行耗时操作（ArkUI接口回调、网络访问回调、await等）
#### 类型
响应时延/完成时延
#### 解决方法
排查所有的回调函数(或者通过Trace查看)，尤其是ArkUI接口，网络回调函数，查看是否有耗时操作，是否使用了await操作，改为setTimeOut或者在TaskPool中执行。
#### 反例
```typescript
import http from '@ohos.net.http';

async aboutToAppear() {
  // ...
  const b = await http.createHttp();
}
```
#### 正例
```typescript
aboutToAppear() {
  // ...
  // 在生命周期中，使用TaskPool加载和解析网络数据
  this.requestByTaskPool();
}

@Concurrent
getInfoFromHttp(): string[] {
  // 从网络加载数据
  return http.request();
}

requestByTaskPool(): void {
  // 创建任务项
  let task: taskpool.Task = new taskpool.Task(this.getInfoFromHttp);
  try {
  // 执行网络加载函数
  taskpool.execute(task, taskpool.Priority.HIGH).then((res: string[]) => {
});
} catch (err) {
  logger.error(TAG, "failed, " + (err as BusinessError).toString());
}
}
```
#### 高频程度&收益（5满分）
5

### 列表场景未使用LazyForEach+组件复用+缓存列表项
#### 类型
响应时延/完成时延/帧率
#### 解决方法
排查使用LazyForEach的代码，确认是否有使用组件复用(@Reusable)+缓存列表项(cachedCount)。
#### 反例
```typescript
struct GoodView {
  build() {
    Grid() {
      // 未使用LazyForEach+组件复用+缓存列表项
      ForEach(this.GoodDataOne, (item, index) => {
        GridItem() {
          Column() {
            Image(item.img)
              .height(item.hei)
              .width('100%')
              .objectFit(ImageFit.Fill)

            Text(item.introduce)
              .fontSize(14)
              .padding({ left: 5, right: 5 })
              .margin({ top: 5 })
            Row() {
              Row() {
                Text('￥')
                  .fontSize(10)
                  .fontColor(Color.Red)
                  .baselineOffset(-4)
                Text(item.price)
                  .fontSize(16)
                  .fontColor(Color.Red)
                Text(item.numb)
                  .fontSize(10)
                  .fontColor(Color.Gray)
                  .baselineOffset(-4)
                  .margin({ left: 5 })
              }

              Image($r('app.media.photo63'))
                .width(20)
                .height(10)
                .margin({ bottom: -8 })
            }
            .width('100%')
              .justifyContent(FlexAlign.SpaceBetween)
              .padding({ left: 5, right: 5 })
              .margin({ top: 15 })
          }
          .borderRadius(10)
            .backgroundColor(Color.White)
            .clip(true)
            .width('100%')
            .height(290)
        }
      }, (item) => JSON.stringify(item))
    }
  }
}
```
#### 正例
```typescript
// 组件复用
@Reusable
@Component
struct GoodItems {
  @State img: Resource = $r("app.media.photo61");
  @State webImg?: string = '';
  @State hei: number = 0;
  @State introduce: string = '';
  @State price: string = '';
  @State numb: string = '';
  @LocalStorageLink('storageSimpleProp') simpleVarName: string = '';
  isOnclick: boolean = true;
  index: number = 0;
  controllerVideo: VideoController = new VideoController();

  aboutToReuse(params)
  {
    this.webImg = params.webImg;
    this.img = params.img;
    this.hei = params.hei;
    this.introduce = params.introduce;
    this.price = params.price;
    this.numb = params.numb;
  }

  build() {
    Grid(){
      // 懒加载
      LazyForEach(this.GoodDataOne, (item, index) => {
        GridItem() {
          GoodItems({
            isOnclick:item.data.isOnclick,
            img:item.data.img,
            webImg:item.data.webImg,
            hei:item.data.hei,
            introduce:item.data.introduce,
            price:item.data.price,
            numb:item.data.numb,
            index:index
          })
            .reuseId(this.CombineStr(item.type))
        }
      }, (item) => JSON.stringify(item))
    }.cachedCount(2) // 缓存列表项
  }
}
```
#### 高频程度&收益（5满分）
5

### Web未使用预连接，未提前初始化引擎
#### 类型
完成时延
#### 解决方法
在应用创建Ability的时候，在OnCreate阶段预先初始化内核，建议把引擎的初始化放在setTimeOut中。
#### 反例
```typescript
// Web组件引擎没有初始化，且沒有使用预连接
export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
  }
}
controller: webview.WebviewController = new webview.WebviewController();
// ...
Web({ src: 'https://www.example.com', controller: this.controller })

```
#### 正例
```typescript
export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    console.info("EntryAbility onCreate")
    // 在 Web 组件初始化之前，通过此接口加载 Web 引擎的动态库文件，以提高启动性能。
    setTimeout(() => {
      // 这里使用setTimeout来实现延迟运行
      web_webview.WebviewController.initializeWebEngine()
    }, 200)
    console.info("EntryAbility onCreate done");
  }
}

controller: webview.WebviewController = new webview.WebviewController();
// ...
Web({ src: 'https://www.example.com', controller: this.controller })

```
#### 高频程度&收益（5满分）
5

### 高频接口中不要打印Trace和日志
#### 类型
响应时延/完成时延
#### 解决方法
排查接口onTouch、onItemDragMove、onDragMove、onDidScroll、onMouse、onVisibleAreaChange、OnAreaChange、
onActionUpdate、animator的onFrame、组件复用场景下的aboutToReuse，不建议在里面打印trace和日志。
#### 反例
```typescript
import { hiTraceMeter } from '@kit.PerformanceAnalysisKit';

@Component
struct CounterOfOnDidScroll {
  private arr: number[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

  build() {
    Scroll() {
      ForEach(this.arr, (item: number) => {
        Text("ListItem" + item)
          .width("100%")
          .height("100%")
      }, (item: number) => item.toString())
    }
    .width('100%')
    .height('100%')
    .onDidScroll(() => {
      hiTraceMeter.startTrace("ScrollSlide", 1002);
      // 业务逻辑
      // ...
      // 在高频接口中不建议打印Trace和日志
      hiTraceMeter.finishTrace("ScrollSlide", 1002);
    })
  }
```
#### 正例
```typescript
@Component
struct PositiveOfOnDidScroll {
  private arr: number[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

  build() {
    Scroll() {
      List() {
        ForEach(this.arr, (item: number) => {
          ListItem() {
            Text("TextItem" + item)
          }.width("100%")
           .height(100)
        }, (item: number) => item.toString())
      }
      .divider({ strokeWidth: 3, color: Color.Gray })
    }
    .width('100%')
    .height('100%')
    .onDidScroll(() => {
      // 业务逻辑
      // ...
    })
  }
}
```
#### 高频程度&收益（5满分）
4

### 组件复用里面有if语句，但是未使用reuseId
#### 类型
完成时延/帧率
#### 解决方法
排查使用了@Reusable的自定义组件，查看build中给是否使用了if/else或ForEach等条件渲染语句，如果使用了，需要配合reuseId一起使用。
#### 反例
```typescript
@Component
@Reusable
export struct MockComplexSubBranch {
  @State alignStyle: FlexAlign = FlexAlign.Center;

  aboutToReuse(params: Record<string, number>): void { // 缓存复用组件，更新组件的状态变量
    this.alignStyle = params.alignStyle;
  }

  build() {
    Column() {
      Column({ space: 5 }) {
        Text('ComplexSubBranch not reusable')
          .fontSize($r('app.integer.font_size_9'))
          .fontColor($r('app.color.hint_txt_color'))
          .width($r('app.string.layout_90_percent'))
      }
    }
  }
}

import { MockComplexSubBranch } from './MockComplexSubBranch';

@Component
export struct WithoutReuseId {
  @State isAlignStyleStart: boolean = true;

  build() {
    Column() {
      Button("Change FlexAlign")
        .onClick(() => {
          this.isAlignStyleStart = !this.isAlignStyleStart;
        })
      Stack() {
        if (this.isAlignStyleStart) {
          MockComplexSubBranch({ alignStyle: FlexAlign.Start }); // 未使用reuseId
        } else {
          MockComplexSubBranch({ alignStyle: FlexAlign.End });
        }
      }
    }
  }
}
```
#### 正例
```typescript
@Component
@Reusable
// 添加Reusable装饰器，声明组件具备可复用的能力
export struct MockComplexSubBranch {
  @State alignStyle: FlexAlign = FlexAlign.Center;

  aboutToReuse(params: Record<string, number>): void {
    this.alignStyle = params.alignStyle;
  }

  build() {
    Column() {
      Column({ space: 5 }) {
        Text('ComplexSubBranch reusable')
          .fontSize($r('app.integer.font_size_9'))
          .fontColor($r('app.color.hint_txt_color'))
          .width($r('app.string.layout_90_percent'))
      }
    }
  }
}

import { MockComplexReusableSubBranch } from './MockComplexReusableSubBranch';

@Component
export struct WithReuseId {
  @State isAlignStyleStart: boolean = true;

  build() {
    Column() {
      Button("Change FlexAlign")
        .onClick(() => {
          this.isAlignStyleStart = !this.isAlignStyleStart;
        })
      Stack() {
        if (this.isAlignStyleStart) {
          MockComplexSubBranch({ alignStyle: FlexAlign.Start }).reuseId("MockComplexSubBranchStart"); // 使用reuseId标识
        } else {
          MockComplexSubBranch({ alignStyle: FlexAlign.End }).reuseId("MockComplexSubBranchEnd");
        }
      }
    }
  }
}
```

#### 高频程度&收益（5满分）
4

### 不建议使用@Prop装饰器
#### 类型
响应时延/完成时延
#### 解决方法
全局搜索@Prop并且替换。
#### 反例
```typescript
@Observed
class Book {
  public c: number = 0;

  constructor(c: number) {
    this.c = c;
  }
}

@Component
struct PropChild {
  @Prop testNum: Book; // @Prop装饰状态变量会深拷贝

  build() {
    Text(`PropChild testNum ${this.testNum.c}`)
  }
}

@Entry
@Component
struct Parent1 {
  @State testNum: Book[] = [new Book(1)];

  build() {
    Column() {
      Text(`Parent testNum ${this.testNum[0].c}`)
        .onClick(() => {
          this.testNum[0].c += 1;
        })
      // PropChild没有改变@Prop testNum: Book的值，所以这时最优的选择是使用@ObjectLink
      PropChild({ testNum: this.testNum[0] })
    }
  }
}
```
#### 正例
```typescript
@Observed
class Book {
  public c: number = 0;

  constructor(c: number) {
    this.c = c;
  }
}

@Component
struct PropChild {
  @ObjectLink testNum: Book; // @ObjectLink装饰状态变量不会深拷贝

  build() {
    Text(`PropChild testNum ${this.testNum.c}`)
  }
}

@Entry
@Component
struct Parent2 {
  @State testNum: Book[] = [new Book(1)];

  build() {
    Column() {
      Text(`Parent testNum ${this.testNum[0].c}`)
        .onClick(() => {
          this.testNum[0].c += 1;
        })
      // 当子组件不需要发生本地改变时，优先使用 @ObjectLink，因为@Prop是会深拷贝数据，具有拷贝的性能开销，所以这个时候@ObjectLink是比@Link和 @Prop更优的选择
      PropChild({ testNum: this.testNum[0] })
    }
  }
}
```
#### 高频程度&收益（5满分）
4

### 避免在ResourceManager的getXXXSync接口入参中直接使用资源信息
#### 类型
响应时延/完成时延
#### 解决方法
排查ResourceManager.getXXXSync接口，查看入参时需要使用getStringSync($r('app.media.icon').id)的形式，
如果未使用需要整改。

#### 反例
```typescript
this.context.resourceManager.getStringSync($r('app.string.test'));
```
#### 正例
```typescript
this.context.resourceManager.getStringSync($r('app.string.test').id);
```
#### 高频程度&收益（5满分）
3

### 展示用的自定义组件（数据从父组件中获取，无独立数据处理）使用@Builder替换
#### 类型
响应时延/完成时延
#### 解决方法
审视@Component标记的自定义组件，如果里面没有独立的生命周期处理逻辑，数据由父组件传递，建议@Builder替代。
#### 反例
```typescript
@Entry
@Component
struct CEMineButtomView {
  build() {
    View();
  }
}

@Component
export struct ViewA {
  build() {
    Row() {
      Text('- 到底了 -')
        .fontSize(12)
        .fontColor($r("app.color.color_1"))
    }.justifyContent(FlexAlign.Center)
     .width('100%')
     .height(51)
     .padding({ bottom: 21 })
  }
}
```
#### 正例
```typescript
@Builder
function viewB() {
  Row() {
    Text('- 到底了 -').fontSize(12)
      .fontColor($r("app.color.color_1"))
  }
  .justifyContent(FlexAlign.Center)
    .width('100%')
    .height(51)
    .padding({ bottom: 21 })
}

@Entry
@Component
struct CEMineButtomView {
  build() {
    Column(){
      viewB()
    }.width('100%')
  }
}
```
#### 高频程度&收益（5满分）
3

### 删除无具体逻辑的生命周期，ArkUI的函数回调等，删除冗余堵塞日志打印
#### 类型
响应时延/完成时延/帧率
#### 解决方法
排查所有的aboutToAppear、aboutToDisappear等生命周期函数，排查ArkUI的回调函数，如果函数中无具体业务逻辑，
例如只打印了日志，删除函数回调。
#### 反例
```typescript
import promptAction from '@ohos.promptAction';

@Entry
@Component
struct ViewA {
  aboutToAppear(): void {
    hilog.info('Index.ets aboutToAppear')  // 无具体业务逻辑的日志
  }

  aboutToDisappear(): void{
    hilog.info('Index.ets aboutToDisappear') // 无具体业务逻辑的日志
  }

  /**
   * 弹窗函数
   */
  showToast() {
    promptAction.showToast({
      message: $r('app.string.water_mark_toast_message')
    })
  }

  build() {
    Column(){
      Text('测试一下')
        .onClick(() => {
          this.showToast(); // 有业务逻辑的方法
        })
    }.width('100%')
  }
}
```
#### 正例
```typescript
import promptAction from '@ohos.promptAction';

@Entry
@Component
struct ViewB {
  /**
   * 弹窗函数
   */
  showToast() {
    promptAction.showToast({
      message: $r('app.string.water_mark_toast_message')
    })
  }

  build() {
    Column(){
      Text('测试一下')
        .onClick(() => {
          this.showToast(); // 有业务逻辑的方法
        })
    }.width('100%')
  }
}
```
#### 高频程度&收益（5满分）
3

### 删除未关联组件的状态变量装饰器
#### 类型
响应时延/完成时延
#### 解决方法
排查全局的状态变量装饰器，如果变量未关联组件，删除装饰器。
#### 反例
```typescript
@Component
struct ComponentA {
  @State message: string = 'Hello World';
  @State textColor: string | Color = '#007DFF';
  @State bgcolor: string | Color = '#ffffff'; // 变量bgcolor是没有关联组件的
  @State selectColor: string | Color = '#007DFF'; // 变量selectColor是没有关联组件的

  build() {
    Column(){
      Text(this.message)
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .fontColor(this.textColor)
    }
  }
}
```
#### 正例
```typescript
@Component
struct ComponentB {
  @State message: string = 'Hello World';
  @State textColor: string | Color = '#007DFF';
  bgcolor: string | Color = '#ffffff'; // 变量bgcolor是有关联组件的
  selectColor: string | Color = '#007DFF'; // 变量selectColor是有关联组件的

  build() {
    Column(){
      Text(this.message)
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .fontColor(this.selectColor)
        .backgroundColor(this.bgcolor)
    }
  }
}
```
#### 高频程度&收益（5满分）
2

### crypto-js性能差
#### 类型
帧率
#### 解决方法
排查buffer.from关键字，加密建议使用原生的cryptoFramework，然后将buffer替换为base64helper，性能提升10倍以上，
且数据量越大越明显。
#### 反例
```typescript
new Uint8Array(buffer.from(str,'base64').buffer);
```
#### 正例
```typescript
let that = new util.Base64Helper();
let result = that.decodeSync(str);
```
#### 高频程度&收益（5满分）
2

### 不建议使用Marquee组件
#### 类型
响应时延/完成时延
#### 解决方法
排查Marquee关键字，使用Text的跑马灯模式(TextOverflow.MARQUEE)替代。
#### 反例
```typescript
struct ViewA {
  build() {
    Column() {
      Marquee({
        start: this.start,
        step: this.step,
        loop: this.loop,
        fromStart: this.fromStart,
        src: this.src
      })
        .width(360)
        .height(80)
        .fontColor('#FFFFFF')
        .fontSize(48)
        .fontWeight(700)
        .backgroundColor('#182431')
        .margin({ bottom: 40 })
        .onStart(() => {
          console.info('Marquee animation complete onStart')
        })
        .onBounce(() => {
          console.info('Marquee animation complete onBounce')
        })
        .onFinish(() => {
          console.info('Marquee animation complete onFinish')
        })
    }.width("100%")
  }
}
```
#### 正例
```typescript
struct ViewB {
  build(){
    Column(){
      Text(reply.user)
        .maxLines(1)
        .textOverflow({ overflow: TextOverflow.MARQUEE }) // 跑马灯模式
        .width("30%")
    }.width("100%")
  }
}
```
#### 高频程度&收益（5满分）
1

### 不能使用函数作为ArkUI组件的属性和组件复用的自定义组件的入参
#### 类型
完成时延
#### 解决方法
查看属性是否有xx()函数写法，确认函数/方法中是否有耗时操作，替换成变量。
#### 反例
```typescript
struct ViewA {
  build() {
    Column() {
      List() {
        LazyForEach(this.data, (item: string) => {
          ListItem() {
            // 此处sum参数是函数获取的，每次组件复用都会重复触发此函数的调用
            ChildComponent({ desc: item, sum: this.count() })
          }.width('100%').height(100)
        }, (item: string) => item)
      }
    }
  }
}
```
#### 正例
```typescript
struct ViewB {
  @State sum: number = 0;

  aboutToAppear(): void {
    this.sum = this.count();
  }

  build() {
    Column() {
      List() {
        LazyForEach(this.data, (item: string) => {
          ListItem() {
            ChildComponent({ desc: item, sum: this.sum })
          }.width('100%').height(100)
        }, (item: string) => item)
      }
    }
  }
}

```
#### 高频程度&收益（5满分）
1

### 不建议使用.linearGradient颜色渐变属性
#### 类型
完成时延
#### 解决方法
排查linearGradient关键字，可以使用图片代替。
#### 反例
```typescript
Row()
  .linearGradient({
    angle: 90,
    colors: [[0xff0000, 0.0], [0x0000ff, 0.3], [0xffff00, 1.0]]
  })
```
#### 正例
```typescript
Image($r('app.media.gradient_color'))
```
#### 高频程度&收益（5满分）
1

### 不要在for/while循环中执行耗时操作
#### 类型
完成时延/帧率
#### 解决方法
排查for/while循环，查看里面是否有打印日志或者Trace。
#### 反例
```typescript
@Component
struct ViewA {
  @State message: string = "";

  build() {
    Column() {
      Button('点击打印日志').onClick(() => {
        for (let i = 0; i < 10; i++) {
          console.info(this.message);
        }
      })
    }
  }
}
```
#### 正例
```typescript
@Component
struct ViewB {
  @State message: string = "";

  build() {
    Column() {
      Button('点击打印日志').onClick(() => {
        let logMessage: string = this.message;
        for (let i = 0; i < 10; i++) {
          console.info(logMessage); // 状态变量需先赋值，再调用会优化性能
        }
      })
    }
  }
}
```
#### 高频程度&收益（5满分）
1

### 变量初值不建议设置为undefined，需进行默认初始化
#### 类型
完成时延
#### 解决方法
例如number设置为0，string设置为空字符串等，这样在使用过程中更不需要增加额外判空。
排查类中的变量，看看是否有初始化为undefined。
#### 反例
```typescript
@State channels?: Channels[] = undefined;
```
#### 正例
```typescript
@State channels?: Channels[] = [];
```
#### 高频程度&收益（5满分）
1

<!--no_check-->


