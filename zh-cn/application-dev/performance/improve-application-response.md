# 提升应用响应速度

应用对用户的输入需要快速反馈，以提升交互体验，因此本文提供了以下方法来提升应用响应速度。

- 避免主线程被非UI任务阻塞
- 减少组件刷新的数量
- 合理使用缓存提升响应速度
- 合理使用预加载提升响应速度

## 避免主线程被非UI任务阻塞

在应用响应用户输入期间，应用主线程应尽可能只执行UI任务（待显示数据的准备、可见视图组件的更新等），非UI的耗时任务（长时间加载的内容等）建议通过异步任务延迟处理或者分配到其他线程处理。

### 使用组件异步加载特性

当前系统提供的Image组件默认生效异步加载特性，当应用在页面上展示一批本地图片的时候，会先显示空白占位块，当图片在其他线程加载完毕后，再替换占位块。这样图片加载就可以不阻塞页面的显示，给用户带来良好的交互体验。因此，只在加载图片耗时比较短的情况下建议下述代码。 

```typescript
@Entry
@Component
struct ImageExample1 {
  build() {
    Column() {
      Row() {
        Image('resources/base/media/sss001.jpg')
          .border({ width: 1 }).borderStyle(BorderStyle.Dashed).aspectRatio(1).width('25%').height('12.5%')
        Image('resources/base/media/sss002.jpg')
          .border({ width: 1 }).borderStyle(BorderStyle.Dashed).aspectRatio(1).width('25%').height('12.5%')
        Image('resources/base/media/sss003.jpg')
          .border({ width: 1 }).borderStyle(BorderStyle.Dashed).aspectRatio(1).width('25%').height('12.5%')
        Image('resources/base/media/sss004.jpg')
          .border({ width: 1 }).borderStyle(BorderStyle.Dashed).aspectRatio(1).width('25%').height('12.5%')
      }
    // 此处省略若干个Row容器，每个容器内都包含如上的若干Image组件
    }
  }
}
```

建议：在加载图片的耗时比较短的时候，通过异步加载的效果会大打折扣，建议配置Image的syncLoad属性。

```typescript
@Entry
@Component
struct ImageExample2 {
  build() {
    Column() {
      Row() {
        Image('resources/base/media/sss001.jpg')
          .border({ width: 1 }).borderStyle(BorderStyle.Dashed).aspectRatio(1).width('25%').height('12.5%').syncLoad(true)
        Image('resources/base/media/sss002.jpg')
          .border({ width: 1 }).borderStyle(BorderStyle.Dashed).aspectRatio(1).width('25%').height('12.5%').syncLoad(true)
        Image('resources/base/media/sss003.jpg')
          .border({ width: 1 }).borderStyle(BorderStyle.Dashed).aspectRatio(1).width('25%').height('12.5%').syncLoad(true)
        Image('resources/base/media/sss004.jpg')
          .border({ width: 1 }).borderStyle(BorderStyle.Dashed).aspectRatio(1).width('25%').height('12.5%').syncLoad(true)
      }
    // 此处省略若干个Row容器，每个容器内都包含如上的若干Image组件
    }
  }
}
```

### 使用TaskPool线程池异步处理

当前系统提供了[TaskPool线程池](https://docs.openharmony.cn/pages/v4.1/zh-cn/application-dev/reference/apis-arkts/js-apis-taskpool.md)，相比worker线程，TaskPool提供了任务优先级设置、线程池自动管理机制，示例如下：

```typescript
import taskpool from '@ohos.taskpool';

@Concurrent
function computeTask(arr: string[]): string[] {
  // 模拟一个计算密集型任务
  let count = 0;
  while (count < 100000000) {
    count++;
  }
  return arr.reverse();
}

@Entry
@Component
struct AspectRatioExample3 {
  @State children: string[] = ['1', '2', '3', '4', '5', '6'];

  aboutToAppear() {
    this.computeTaskInTaskPool();
  }

  async computeTaskInTaskPool() {
    const param = this.children.slice();
    let task = new taskpool.Task(computeTask, param);
    await taskpool.execute(task);
  }

  build() {
    // 组件布局
  }
}
```

### 创建异步任务

反例：将非UI的耗时任务通过Promise进行Async异步执行。虽然执行了异步操作，但只是将顺序移到了下一个执行的任务位置，还是会影响页面响应速度。

```typescript
@Entry
@Component
struct Index {
  @State private text: string = "hello world";
  private count: number = 0;

  aboutToAppear() {
    const result: Promise<void> = new Promise(() => {
      this.computeTask();
    });
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
  }
}
```

建议：将一个长时间执行的非UI任务通过setTimeout改造成异步任务，主线程可以先绘制初始页面。等主线程空闲时，再执行异步任务。

```typescript
@Entry
@Component
struct Index {
  @State private text: string = "Hello World";
  private count: number = 0;

  aboutToAppear() {
    setTimeout(() => {
      this.computeTask();
    }, 1000)
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
  }
}
```

通过SmartPerf-Host工具对trace进行抓取，可从应用启动阶段分析响应速度。


如下图所示，反例中启动时总耗时为457ms。

![反例总时长](./figures/improve-application-response-promise-all-duration.png)

反例中启动时aboutToAppear阶段耗时为295ms。

![反例时长](./figures/improve-application-response-promise-duration.png)

正例中启动时总耗时为169ms。

![正例总时长](./figures/improve-application-response-settimeout-all-duration.png)

正例中启动时aboutToAppear阶段耗时为167us。

![正例时长](./figures/improve-application-response-settimeout-duration.png)

其中setTimeout真正的耗时为308ms。

![正例时长](./figures/improve-application-response-settimeout-real-duration.png)

异步运行机制如图所示。

![异步运行机制](./figures/improve-application-response-async.png)

## 减少刷新的组件数量

应用刷新页面时需要尽可能减少刷新的组件数量，如果数量过多会导致主线程执行测量、布局的耗时过长，还会在自定义组件新建和销毁过程中，多次调用aboutToAppear()、aboutToDisappear()方法，增加主线程负载。

### 使用容器限制刷新范围

反例：如果容器内有组件被if条件包含，if条件结果变更会触发创建和销毁该组件，如果此时影响到容器的布局，该容器内所有组件都会刷新，导致主线程UI刷新耗时过长。

以下代码的Text('New Page')组件被状态变量isVisible控制，isVisible为true时创建，false时销毁。当isVisible发生变化时，Stack容器内的所有组件都会刷新：

```typescript
@Entry
@Component
struct StackExample5 {
  @State isVisible : boolean = false;

  build() {
    Column() {
      Stack({alignContent: Alignment.Top}) {
        Text().width('100%').height('70%').backgroundColor(0xd2cab3)
          .align(Alignment.Center).textAlign(TextAlign.Center);

        // 此处省略100个相同的背景Text组件

        if (this.isVisible) {
          Text('New Page').height("100%").height("70%").backgroundColor(0xd2cab3)
            .align(Alignment.Center).textAlign(TextAlign.Center);
        }
      }
      Button("press").onClick(() => {
        this.isVisible = !(this.isVisible);
      })
    }
  }
}
```

建议：对于这种受状态变量控制的组件，在if外套一层容器，减少刷新范围。

```typescript
@Entry
@Component
struct StackExample6 {
  @State isVisible : boolean = false;

  build() {
    Column() {
      Stack({alignContent: Alignment.Top}) {
        Text().width('100%').height('70%').backgroundColor(0xd2cab3)
          .align(Alignment.Center).textAlign(TextAlign.Center);

        // 此处省略100个相同的背景Text组件

        Stack() {
          if (this.isVisible) {
            Text('New Page').height("100%").height("70%").backgroundColor(0xd2cab3)
              .align(Alignment.Center).textAlign(TextAlign.Center);
          }
        }.width('100%').height('70%')
      }
      Button("press").onClick(() => {
        this.isVisible = !(this.isVisible);
      })
    }
  }
}
```

### 按需加载列表组件的元素

反例：this.arr中的每一项元素都被初始化和加载，数组中的元素有10000个，主线程执行耗时长。

```typescript
@Entry
@Component
struct MyComponent7 {
  @State arr: number[] = Array.from(Array<number>(10000), (v,k) =>k); 
  build() {
    List() {
      ForEach(this.arr, (item: number) => {
        ListItem() {
          Text(`item value: ${item}`)
        }
      }, (item: number) => item.toString())
    }
  }
}
```

建议：这种情况下用LazyForEach替换ForEach，LazyForEach一般只加载可见的元素，避免一次性初始化和加载所有元素。

```typescript
class BasicDataSource implements IDataSource {
  private listeners: DataChangeListener[] = []

  public totalCount(): number {
    return 0
  }

  public getData(index: number): string {
    return ''
  }

  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      console.info('add listener')
      this.listeners.push(listener)
    }
  }

  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      console.info('remove listener')
      this.listeners.splice(pos, 1)
    }
  }

  notifyDataReload(): void {
    this.listeners.forEach(listener => {
      listener.onDataReloaded()
    })
  }

  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index)
    })
  }

  notifyDataChange(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataChange(index)
    })
  }

  notifyDataDelete(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataDelete(index)
    })
  }

  notifyDataMove(from: number, to: number): void {
    this.listeners.forEach(listener => {
      listener.onDataMove(from, to)
    })
  }
}

class MyDataSource extends BasicDataSource {
  private dataArray: string[] = Array.from(Array<number>(10000), (v, k) => k.toString());

  public totalCount(): number {
    return this.dataArray.length
  }

  public getData(index: number): string  {
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
struct MyComponent {
  private data: MyDataSource = new MyDataSource()

  build() {
    List() {
      LazyForEach(this.data, (item: string) => {
        ListItem() {
            Text(item).fontSize(20).margin({ left: 10 })
        }
      }, (item:string) => item)
    }
  }
}
```
## 合理使用缓存提升响应速度
缓存可以存储经常访问的数据或资源，当下次需要访问相同数据时，可以直接从缓存中获取，避免了重复的计算或请求，从而加快了响应速度。
### 使用AVPlayer实例缓存提升视频加载速度
AVPlayer实例的创建与销毁都很消耗性能，针对这个问题可以使用实例缓存进行优化，首次加载页面时创建两个实例，在打开新页面时切换空闲实例，通过reset方法重置实例到初始化状态。优化点在于不需要频繁创建销毁实例，且reset方法性能优于release方法。下面以AVPlayer为例列出正反例对比供参考。

反例：打开新页面时创建实例，离开页面时使用release方法销毁实例。
```typescript
import media from '@ohos.multimedia.media';

@Entry
@Component
struct Index {
  private avPlayer: media.AVPlayer | undefined = undefined;
  
  aboutToAppear(): void {
    // 页面创建时初始化AVPlayer实例
    media.createAVPlayer().then((ret) => {
      this.avPlayer = ret;
    });
  }
  
  aboutToDisappear(): void {
    // 离开页面时销毁AVPlayer实例
    if (this.avPlayer) {
      this.avPlayer.release();
    }
    this.avPlayer = undefined;
  }
  
  build() {
    // 组件布局
  }
}
```

正例：首次加载页面时维护两个实例，在切换页面时切换实例，并将之前的实例通过reset方法重置。
```typescript
import media from '@ohos.multimedia.media';

@Entry
@Component
struct Index {
  private avPlayer: media.AVPlayer | undefined = undefined;
  private avPlayerManager: AVPlayerManager = AVPlayerManager.getInstance();

  aboutToAppear(): void {
    this.avPlayerManager.switchPlayer();
    this.avPlayer = this.avPlayerManager.getCurrentPlayer();
  }

  aboutToDisappear(): void {
    this.avPlayerManager.resetCurrentPlayer();
    this.avPlayer = undefined;
  }

  build() {
    // 组件布局
  }
}

class AVPlayerManager {
  private static instance?: AVPlayerManager;

  private player1?: media.AVPlayer;
  private player2?: media.AVPlayer;
  private currentPlayer?: media.AVPlayer;

  public static getInstance(): AVPlayerManager {
    if (!AVPlayerManager.instance) {
      AVPlayerManager.instance = new AVPlayerManager();
    }
    return AVPlayerManager.instance;
  }

  async AVPlayerManager() {
    this.player1 = await media.createAVPlayer();
    this.player2 = await media.createAVPlayer();
  }

  /**
   * 切换页面时切换AVPlayer实例
   */
  switchPlayer(): void {
    if (this.currentPlayer === this.player1) {
      this.currentPlayer = this.player2;
    } else {
      this.currentPlayer = this.player1;
    }
  }

  getCurrentPlayer(): media.AVPlayer | undefined {
    return this.currentPlayer;
  }

  /**
   * 使用reset方法重置AVPlayer实例
   */
  resetCurrentPlayer(): void {
    this.currentPlayer?.pause(() => {
      this.currentPlayer?.reset();
    });
  }
}
```
## 合理使用预加载提升响应速度

### 使用NodeContainer提前渲染降低响应时延

应用启动时有广告页的场景下。如果先渲染广告页而后再渲染首页，很可能造成首页响应时延较长，影响用户体验。针对此类问题可以使用NodeContainer在广告页渲染时同步渲染首页，等到跳转到首页时直接送显，提高响应速度。

反例：按次序依次渲染送显

主要代码逻辑如下：

1、模拟广告页，通过点击不同按钮分别进入普通页面和预加载页面
```typescript
// Index.ets

import router from '@ohos.router';

@Entry
@Component
struct Index {
  build() {
    Column({ space: 5 }) {
      // 进入普通页面
      Button("普通页面")
        .type(ButtonType.Capsule)
        .onClick(() => {
          router.pushUrl({ url: 'pages/CommonPage' })
        })
      // 进入预加载页面
      Button("预加载页面")
        .type(ButtonType.Capsule)
        .onClick(() => {
          router.pushUrl({ url: 'pages/PreloadedPage' })
        })
    }.height('100%')
    .width('100%')
    .justifyContent(FlexAlign.Center)
  }
}
```

2、普通首页，也即按顺序普通渲染的页面
```typescript
// CommonPage.ets

import { MyBuilder, getNumbers } from '../builder/CustomerBuilder';

@Entry
@Component
struct CommonPage {
  build() {
    Row() {
      MyBuilder(getNumbers())
    }
  }
}
```
3、自定义builder，用来定制页面结构
```typescript
// CustomerBuilder.ets

@Builder
export function MyBuilder(numbers: string[]) {
  Column() {
    List({ space: 20, initialIndex: 0 }) {
      ForEach(numbers, (item: string) => {
        ListItem() {
          Text('' + item)
            .width('100%')
            .height(50)
            .fontSize(16)
            .textAlign(TextAlign.Center)
            .borderRadius(10)
            .backgroundColor(0xFFFFFF)
        }
      }, (day: string) => day)
    }
    .listDirection(Axis.Vertical) // 排列方向
    .scrollBar(BarState.Off)
    .friction(0.6)
    .divider({ strokeWidth: 2, color: 0xFFFFFF, startMargin: 20, endMargin: 20 }) // 每行之间的分界线
    .edgeEffect(EdgeEffect.Spring) // 边缘效果设置为Spring
    .width('90%')
    .height('100%')
  }
  .width('100%')
  .height('100%')
  .backgroundColor(0xDCDCDC)
  .padding({ top: 5 })
}

export const getNumbers = (): string[] => {
  const numbers: string[] = [];
  for (let i = 0; i < 100; i++) {
    numbers.push('' + i)
  }
  return numbers;
}
```

正例：在启动时预加载首页

主要代码逻辑如下：

1、应用启动时提前创建首页
```typescript
// EntryAbility.ets  

import { ControllerManager } from '../builder/CustomerController';
import { getNumbers } from '../builder/CustomerBuilder';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
    // Main window is created, set main page for this ability
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');

    windowStage.loadContent('pages/Index', (err, data) => {
      if (err.code) {
        hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
        return;
      }
      hilog.info(0x0000, 'testTag', 'Succeeded in loading the content. Data: %{public}s', JSON.stringify(data) ?? '');
    });
    window.getLastWindow(this.context, (err: BusinessError, data) => {
      if (err.code) {
        console.error('Failed to obtain top window. Cause:' + JSON.stringify(err));
        return;
      }
      // 提前创建
      ControllerManager.getInstance().createNode(data.getUIContext(), getNumbers());
    })
  }

  onWindowStageDestroy(): void {
    // Main window is destroyed, release UI related resources
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageDestroy');
    // 清空组件，防止内存泄漏
    ControllerManager.getInstance().clearNode();
  }
}
```

2、预加载的首页，使用NodeContainer进行占位，当跳转到本页时直接将提前创建完成的首页填充
```typescript
// PreloadedPage.ets

import { ControllerManager } from '../builder/CustomerController';

@Entry
@Component
struct PreloadedPage {
  build() {
    Row() {
      NodeContainer(ControllerManager.getInstance().getNode())
    }
  }
}
```

3、自定义NodeController，并提供提前创建首页的能力
```typescript
// CustomerController.ets

import { UIContext } from '@ohos.arkui.UIContext';
import { NodeController, BuilderNode, FrameNode } from "@ohos.arkui.node";
import { MyBuilder } from './CustomerBuilder';

export class MyNodeController extends NodeController {
  private rootNode: BuilderNode<[string[]]> | null = null;
  private wrapBuilder: WrappedBuilder<[string[]]> = wrapBuilder(MyBuilder);
  private numbers: string[] | null = null;

  constructor(numbers: string[]) {
    super();
    this.numbers = numbers;
  }

  makeNode(uiContext: UIContext): FrameNode | null {
    if (this.rootNode != null) {
      // 返回FrameNode节点
      return this.rootNode.getFrameNode();
    }
    // 返回null控制动态组件脱离绑定节点
    return null;
  }

  // 通过UIContext初始化BuilderNode，再通过BuilderNode中的build接口初始化@Builder中的内容
  initNode(uiContext: UIContext) {
    if (this.rootNode != null) {
      return;
    }
    // 创建节点，需要uiContext
    this.rootNode = new BuilderNode(uiContext)
    // 创建组件
    this.rootNode.build(this.wrapBuilder, this.numbers)
  }
}

export class ControllerManager {
  private static instance?: ControllerManager;
  private myNodeController?: MyNodeController;

  static getInstance(): ControllerManager {
    if (!ControllerManager.instance) {
      ControllerManager.instance = new ControllerManager();
    }
    return ControllerManager.instance;
  }

  /**
   * 初始化需要UIContext 需在Ability获取
   * @param uiContext
   * @param numbers
   */
  createNode(uiContext: UIContext, numbers: string[]) {
    // 创建NodeController
    this.myNodeController = new MyNodeController(numbers);
    this.myNodeController.initNode(uiContext);
  }

  /**
   * 自定义获取NodeController实例接口
   * @returns MyNodeController
   */
  getNode(): MyNodeController | undefined {
    return this.myNodeController;
  }

  /**
   * 解除占用，防止内存泄漏
   */
  clearNode(): void {
    this.myNodeController = undefined;
  }
}
```

通过SmartPerf-Host工具抓取相关trace进行分析首页响应时延，其中主要关注两个trace tag分别是DispatchTouchEvent代表点击事件和MarshRSTransactionData代表响应,如下图所示：

反例响应时延：18.1ms

![反例响应时延](./figures/preload_counter_example_delay.png)

正例响应时延：9.4ms

![正例响应时延](./figures/preload_positive_example_delay.png)

由上述对比数据即可得出结论，预加载首页能优化首页响应时延。

### 使用条件渲染实现预加载

当页面较为复杂时，跳转至该页面的响应时长较高。可通过条件渲染的方式，使用**骨架图**作为默认展示，等数据加载完再显示最终布局，从而加快响应速度。

```typescript
@Entry
@Component
struct Index {
  @State simpleList: Array<number> = [1, 2, 3, 4, 5];
  @State isInitialized: boolean = false; // 是否已获取数据进行初始化
  @State isClicked: boolean = false;

  build() {
    Column() {
      Button('点击加载')
        .onClick(() => {
          this.isClicked = !this.isClicked;
          setTimeout(() => {
            this.isInitialized = !this.isInitialized;
          }, 300);
        })
      if (this.isClicked) {
        ForEach(this.simpleList, (item: number) => {
          if (!this.isInitialized) {
            // 未获取数据前使用骨架图
            ArticleSkeletonView()
              .margin({ top: 20 })
          } else {
            // 获取数据后再刷新显示内容
            Text('OK')
            // ...
          }
        }, (item: number) => item.toString())
      }
    }
    .padding(20)
    .width('100%')
    .height('100%')
  }
}

@Builder
function textArea(width: number | Resource | string = '100%', height: number | Resource | string = '100%') {
  Row()
    .width(width)
    .height(height)
    .backgroundColor('#FFF2F3F4')
}

@Component
struct ArticleSkeletonView { // 自定义骨架图
  build() {
    Row() {
      Column() {
        textArea(80, 80)
      }
      .margin({ right: 20 })

      Column() {
        textArea('60%', 20)
        textArea('50%', 20)
      }
      .alignItems(HorizontalAlign.Start)
      .justifyContent(FlexAlign.SpaceAround)
      .height('100%')
    }
    .padding(20)
    .borderRadius(12)
    .backgroundColor('#FFECECEC')
    .height(120)
    .width('100%')
    .justifyContent(FlexAlign.SpaceBetween)
  }
}
```

效果如下图：

![骨架图占位](./figures/improve-application-response-skeleton.png)

将使用和未使用骨架图的组件通过SmartPerf-Host工具抓取trace后对比可得：

未使用骨架图时，响应时间约为321.5ms。(其中包含setTimeout的300ms)

![骨架图占位](./figures/improve-application-response-no-skeleton-duration.png)

使用了骨架图后，响应时间变为10.3ms。

![骨架图占位](./figures/improve-application-response-skeleton-duration.png)
