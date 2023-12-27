# 减少首帧绘制时的冗余操作

------

## 应用冷启动与加载绘制首页

应用冷启动即当启动应用时，后台没有该应用的进程，这时系统会重新创建一个新的进程分配给该应用。

应用冷启动过程大致可分成以下四个阶段：应用进程创建&初始化、Application&Ability初始化、Ability生命周期、**加载绘制首页**。

![](figures/ColdStart.png)

**加载绘制首页**不仅是应用冷启动的四个阶段之一，还是首帧绘制最重要的阶段。而它可以分为三个阶段：加载页面、测量和布局、渲染。本文从这三个阶段入手，分成下面三个场景进行案例优化。

![](figures/Render-FirstFrame.png)

## 减少加载页面时间

减少加载页面时间可以通过按需加载、减少自定义组件生命周期耗时两种方法来实现。

#### 按需加载

按需加载可以避免一次性初始化和加载所有元素，从而使首帧绘制时加载页面阶段的创建列表元素时间大大减少，从而提升性能表现。

**案例：每一个列表元素都被初始化和加载，为了突出效果，方便观察，设定数组中的元素有10000个，使其在加载页面阶段创建列表内元素耗时大大增加。**

```ts
@Entry
@Component
struct AllLoad {
  @State arr: String[] = Array.from(Array<string>(10000), (val,i) =>i.toString());
  build() {
    List() {
      ForEach(this.arr, (item: string) => {
        ListItem() {
          Text(`item value: ${item}`)
            .fontSize(20)
            .margin({ left: 10 })
        }
      }, (item: string) => item.toString())
    }
  }
}
```

**优化：LazyForEach替换ForEach，避免一次性初始化和加载所有元素。**

```ts
class BasicDataSource implements IDataSource {
  private listeners: DataChangeListener[] = [];
  private originDataArray: string[] = [];

  public totalCount(): number {
    return 0;
  }

  public getData(index: number): string {
    return this.originDataArray[index]
  }

  // 注册数据改变的监听器
  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      console.info('add listener')
      this.listeners.push(listener)
    }
  }

  // 注销数据改变的监听器
  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      console.info('remove listener')
      this.listeners.splice(pos, 1)
    }
  }

  // 通知组件重新加载所有数据
  notifyDataReload(): void {
    this.listeners.forEach(listener => {
      listener.onDataReloaded()
    })
  }

  // 通知组件index的位置有数据添加
  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index)
    })
  }

  // 通知组件index的位置有数据有变化
  notifyDataChange(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataChange(index)
    })
  }

  // 通知组件删除index位置的数据并刷新LazyForEach的展示内容
  notifyDataDelete(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataDelete(index)
    })
  }

  // 通知组件数据有移动
  notifyDataMove(from: number, to: number): void {
    this.listeners.forEach(listener => {
      listener.onDataMove(from, to)
    })
  }
}

class MyDataSource extends BasicDataSource {
  private dataArray: string[] = Array.from(Array<string>(10000), (val, i) => i.toString());

  public totalCount(): number {
    return this.dataArray.length
  }

  public getData(index: number): string {
    return this.dataArray[index]
  }

  public addData(index: number, data: string): void {
    this.dataArray.splice(index, 0, data)
    this.notifyDataAdd(index)
  }

  public pushData(data: string): void {
    this.dataArray.push(data)
    this.notifyDataAdd(this.dataArray.length - 1)
  }
}

@Entry
@Component
struct SmartLoad {
  private data: MyDataSource = new MyDataSource()

  build() {
    List() {
      LazyForEach(this.data, (item: string) => {
        ListItem() {
          Text(`item value: ${item}`)
            .fontSize(20)
            .margin({ left: 10 })
        }
      }, (item:string) => item)
    }
  }
}
```



#### 减少自定义组件生命周期时间

LoadPage阶段需要等待自定义组件生命周期aboutToAppear的高耗时任务完成， 导致LoadPage时间大量增加，阻塞主线程后续的布局渲染，所以自定义组件生命周期的耗时任务应当转为Worker线程任务，优先绘制页面，避免启动时阻塞在startWindowIcon页面。

**案例：自定义组件生命周期存在高耗时任务，阻塞主线程布局渲染。**

```ts
@Entry
@Component
struct TaskSync {
  @State private text: string = "";
  private count: number = 0;

  aboutToAppear() {
    this.text = 'hello world';
    this.computeTask(); // 同步任务
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
    while (this.count < 100000000) {
      this.count++;
    }
    this.text = 'task complete';
  }
}
```

**优化：自定义组件生命周期的耗时任务转为Worker线程任务，优先绘制页面，再将Worker子线程结果发送到主线程并更新到页面。**

```ts
// TaskAsync.ets
import worker from '@ohos.worker';

@Entry
@Component
struct TaskAsync {
  @State private text: string = "";
  private workerInstance:worker.ThreadWorker = new worker.ThreadWorker("entry/ets/workers/worker.ts");

  aboutToAppear() {
    // 处理来自子线程的消息
    this.workerInstance.onmessage = (message)=> {
      console.info('message from worker: ' + JSON.stringify(message))
      this.text = JSON.parse(JSON.stringify(message)).data
      this.workerInstance.terminate()
    }
    this.text = 'hello world';
    // 执行Worker线程任务
    this.computeTaskAsync();
  }

  build() {
    Column({space: 10}) {
      Text(this.text).fontSize(50)
    }
    .width('100%')
    .height('100%')
    .padding(10)
  }
  private async computeTaskAsync(){
    // 发送消息到子线程
    this.workerInstance.postMessage('hello world')
  }
}
```

```ts
// worker.ts
import worker from '@ohos.worker';

let parentPort = worker.workerPort;

function computeTask(count: number) {
  while (count < 100000000) {
    count++;
  }
  return 'task complete'
}
// 处理来自主线程的消息
parentPort.onmessage = (message) => {
  console.info("onmessage: " + JSON.stringify(message));
  // 发送消息到主线程
  parentPort.postMessage(computeTask(0));
}
```



## 减少布局时间

减少布局时间可以通过异步加载和减少视图嵌套层次两种方法来实现。

#### 异步加载

同步加载的操作，使创建图像任务需要在主线程完成，页面布局Layout需要等待创建图像makePixelMap任务的执行，导致布局时间延长。相反，异步加载的操作，在其他线程完成，和页面布局Layout同时开始，且没有阻碍页面布局，所以页面布局更快，性能更好。但是，并不是所有的加载都必须使用异步加载，建议加载尺寸较小的本地图片时将syncLoad设为true，因为耗时较短，在主线程上执行即可。

**案例：使用Image组件同步加载高分辨率图片，阻塞UI线程，增加了页面布局总时间。**

```ts
@Entry
@Component
struct SyncLoadImage {
  @State arr: String[] = Array.from(Array<string>(100), (val,i) =>i.toString());
  build() {
    Column() {
      Row() {
        List() {
          ForEach(this.arr, (item: string) => {
            ListItem() {
              Image($r('app.media.4k'))
                .border({ width: 1 })
                .borderStyle(BorderStyle.Dashed)
                .height(100)
                .width(100)
                .syncLoad(true)
            }
          }, (item: string) => item.toString())
        }
      }
    }
  }
}
```

**优化：使用Image组件默认的异步加载方式加载图片，不阻塞UI线程，降低页面布局时间。**

```ts
@Entry
@Component
struct AsyncLoadImage {
  @State arr: String[] = Array.from(Array<string>(100), (val,i) =>i.toString());
    build() {
      Column() {
        Row() {
          List() {
            ForEach(this.arr, (item: string) => {
              ListItem() {
                Image($r('app.media.4k'))
                  .border({ width: 1 })
                  .borderStyle(BorderStyle.Dashed)
                  .height(100)
                  .width(100)
              }
            }, (item: string) => item.toString())
          }
        }
      }
  }
}
```



#### 减少视图嵌套层次

视图的嵌套层次会影响应用的性能。通过减少不合理的容器组件，可以使布局深度降低，布局时间减少，优化布局性能，提升用户体验。

**案例：通过Grid网格容器一次性加载1000个网格，并且额外使用3层Flex容器模拟不合理的深嵌套场景使布局时间增加。**

```ts
@Entry
@Component
struct Depth1 {
  @State number: Number[] = Array.from(Array<number>(1000), (val, i) => i);
  scroller: Scroller = new Scroller()

  build() {
    Column() {
      Grid(this.scroller) {
        ForEach(this.number, (item: number) => {
          GridItem() {
            Flex() {
              Flex() {
                Flex() {
                  Text(item.toString())
                    .fontSize(16)
                    .backgroundColor(0xF9CF93)
                    .width('100%')
                    .height(80)
                    .textAlign(TextAlign.Center)
                    .border({width:1})
                }
              }
            }
          }
        }, (item:string) => item)
      }
      .columnsTemplate('1fr 1fr 1fr 1fr 1fr')
      .columnsGap(0)
      .rowsGap(0)
      .size({ width: "100%", height: "100%" })
    }
  }
}
```

**优化：通过Grid网格容器一次性加载1000个网格，去除额外的不合理的布局容器，降低布局时间。**

```ts
@Entry
@Component
struct Depth2 {
  @State number: Number[] = Array.from(Array<number>(1000), (val, i) => i);
  scroller: Scroller = new Scroller()

  build() {
    Column() {
      Grid(this.scroller) {
        ForEach(this.number, (item: number) => {
          GridItem() {
                  Text(item.toString())
                    .fontSize(16)
                    .backgroundColor(0xF9CF93)
                    .width('100%')
                    .height(80)
                    .textAlign(TextAlign.Center)
                    .border({width:1})
          }
        }, (item:string) => item)
      }
      .columnsTemplate('1fr 1fr 1fr 1fr 1fr')
      .columnsGap(0)
      .rowsGap(0)
      .size({ width: "100%", height: "100%" })
    }
  }
}
```



## 减少渲染时间

减少渲染时间可以通过条件渲染替代显隐控制的方法来实现。

#### 条件渲染

通过条件渲染替代显隐控制，首帧绘制时的渲染时间明显降低，从而提升性能表现。另外，即使组件处于隐藏状态，在页面刷新时仍存在重新创建过程，因此当对性能有严格要求时建议使用条件渲染代替。

**案例：通过visibility属性控制当前组件显示或隐藏。**

```ts
@Entry
@Component
struct VisibilityExample {
  build() {
    Column() {
      Column() {
        // 隐藏不参与占位
        Text('None').fontSize(9).width('90%').fontColor(0xCCCCCC)
        Row().visibility(Visibility.None).width('90%').height(80).backgroundColor(0xAFEEEE)

        // 隐藏参与占位
        Text('Hidden').fontSize(9).width('90%').fontColor(0xCCCCCC)
        Row().visibility(Visibility.Hidden).width('90%').height(80).backgroundColor(0xAFEEEE)

        // 正常显示，组件默认的显示模式
        Text('Visible').fontSize(9).width('90%').fontColor(0xCCCCCC)
        Row().visibility(Visibility.Visible).width('90%').height(80).backgroundColor(0xAFEEEE)
      }.width('90%').border({ width: 1 })
    }.width('100%').margin({ top: 5 })
  }
}
```

**优化：通过条件渲染替代显隐控制。**

```ts
@Entry
@Component
struct IsVisibleExample {
  @State isVisible : boolean = true;

  build() {
    Column(){
      Column() {
        //不渲染即达到隐藏不参与占位
        Text('None').fontSize(9).width('90%').fontColor(0xCCCCCC)
        if (!this.isVisible) {
          Row().width('90%').height(80).backgroundColor(0xAFEEEE)
        }
        
        // 隐藏参与占位无法通过条件渲染实现
        
        // 渲染即正常占位显示
        Text('Visible').fontSize(9).width('90%').fontColor(0xCCCCCC)
        if (this.isVisible){
          Row().width('90%').height(80).backgroundColor(0xAFEEEE)
        }
      }.width('90%').border({ width: 1 })
    }.width('100%').margin({ top: 5 })
  }
}
```
