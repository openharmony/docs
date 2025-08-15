# 感知组件可见性
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

## 概述
组件可见性是指组件在屏幕上的显示状态，通过感知可见性，应用能够实现以下典型场景：
- 组件曝光统计与分析（例如，统计广告组件在屏幕上的显示时长）；
- 资源按需加载与释放（例如，组件不可见时，释放组件使用的图片、视频等资源）；
- 感知复杂视图切换（例如，在多层视图嵌套情况下，依据组件的显示状态，处理相关逻辑）。

针对上述场景，建议按照以下策略进行选择：

|场景描述 	|推荐接口 	|说明 |
|----- 	|---- 	|--- |
|[组件曝光统计与分析](#组件曝光统计与分析)  	| onVisibleAreaApproximateChange	|要监控的组件数量多，需要低频计算降低开销。 |
|[资源按需加载与释放](#资源按需加载与释放) |	onVisibleAreaChange	|要监控的组件数量少，希望每帧检测确保状态及时更新。 |
|[感知复杂视图切换](#感知复杂视图切换) |	nodeRenderState监听 |	适合感知页面或页切换导致的可见性变化。 |

应用也可自行遍历计算组件可见性，但由于组件存在复杂的层次关系，自行计算涉及大量运算，通常不被推荐。

## 组件曝光统计与分析

使用[onVisibleAreaApproximateChange](../reference/apis-arkui/arkui-ts/ts-universal-component-visible-area-change-event.md#onvisibleareaapproximatechange17)监控关键组件（如广告、商品卡片）的曝光时长，用于用户行为分析和运营统计。

该接口比onVisibleAreaChange性能更优，支持通过设置计算周期减少检测频率，适用于组件数量多、层级深的场景，可显著降低性能消耗。

> **说明：**
> 
> 该能力从API version 17开始支持。

```typescript
class ListDataSource implements IDataSource {
  private list: number[] = [];
  private listeners: DataChangeListener[] = [];

  constructor(list: number[]) {
    this.list = list;
  }

  totalCount(): number {
    return this.list.length;
  }

  getData(index: number): number {
    return this.list[index];
  }

  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      this.listeners.push(listener);
    }
  }

  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      this.listeners.splice(pos, 1);
    }
  }

  notifyDataDelete(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataDelete(index);
    });
  }

  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index);
    });
  }

  public deleteItem(index: number): void {
    this.list.splice(index, 1);
    this.notifyDataDelete(index);
  }

  public insertItem(index: number, data: number): void {
    this.list.splice(index, 0, data);
    this.notifyDataAdd(index);
  }
}

class ExposureTrackingData {
  // 使用一个map记录当前正在展示的广告位，以及它开始被展示的时间戳，以便在它不可见时可以计算在屏幕上的展示时长
  private visibleAdvertisingInfos = new Map<string, number>();
  // 使用一个map记录每个广告位的展示总时长
  private exposureData = new Map<string, number>();

  constructor() {
  }

  notifyAdvertisingSlotIsAppearing(slot: string): void {
    // 广告位开始展示，记录起始时间戳
    let startTimestamp = Date.now()
    this.visibleAdvertisingInfos.set(slot, startTimestamp)
  }

  notifyAdvertisingSlotIsDisappearing(slot: string): void {
    // 广告位开始消失，计算本次展示时长，并累加到总时长数据中
    let endTimestamp: number = Date.now()
    let advertisingInfo = this.visibleAdvertisingInfos.get(slot)
    let duration: number = 0
    if (advertisingInfo) {
      duration = endTimestamp - advertisingInfo.valueOf()
    }
    // 刷新展示总时长
    this.updateExposureData(slot, duration)
    // 从当前可见的map中删除这个广告位信息
    this.visibleAdvertisingInfos.delete(slot)
  }

  notifyPageHiding(): void {
    // 页面正在退出，上报统计数据
    this.reportData()
  }

  updateExposureData(slot: string, duration: number) {
    if (duration <= 0) {
      return
    }
    let oldDuration = 0
    let dataItem = this.exposureData.get(slot)
    if (dataItem) {
      oldDuration = dataItem.valueOf()
    }
    this.exposureData.set(slot, oldDuration + duration)
  }

  consumeAllCurrentVisibleSlots(): void {
    this.visibleAdvertisingInfos.forEach((value: number, key: string) => {
      this.notifyAdvertisingSlotIsDisappearing(key)
    });
    this.visibleAdvertisingInfos.clear()
  }

  reportData(): void {
    // 上报之前先将当前正在展示的广告位统计信息刷新到总时长
    this.consumeAllCurrentVisibleSlots()
    // 发送数据到分析平台
    console.info(`曝光数据上报: ` + Array.from(this.exposureData))
    // 上报后清空
    this.exposureData.clear()
  }
}

@Entry
@ComponentV2
struct ExposureTrackingPage {
  private data: ListDataSource =
    new ListDataSource([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]);
  private exposureData = new ExposureTrackingData()

  onPageHide(): void {
    // 在页面退出时，上报统计数据到分析平台
    this.exposureData.notifyPageHiding()
  }

  build() {
    Column() {
      List({ space: 20, initialIndex: 0 }) {
        LazyForEach(this.data, (item: number) => {
          ListItem() {
            Text(this.getAdvertisingSlotInfo(item))
              .width('100%')
              .height(100)
              .fontSize(20)
              .fontColor(Color.White)
              .textAlign(TextAlign.Center)
              .borderRadius(10)
              .backgroundColor(this.calculateItemBackgroundColor(item))
          }
          // 为每一个列表条目都增加一个可见性监听回调，给定阈值0.5，即如果广告位在屏幕上显示超过自身一半，就认为已经曝光；
          // 尽管这里代码只写了一行，但实际会为每个显示出来的列表项都绑定一个回调，因此这里我们使用可控制计算频率的回调接口。
          .onVisibleAreaApproximateChange({ ratios: [0.5], expectedUpdateInterval: 500 },
            (isExpanding: boolean, currentRatio: number) => {
              this.handleExposureTracking(item, isExpanding, currentRatio)
            })
        }, (item: number) => item.toString())
      }
      .listDirection(Axis.Vertical)
      .scrollBar(BarState.Off)
      .edgeEffect(EdgeEffect.Spring)
      .width('90%')
      .margin(5)
    }
    .width('100%')
    .height('100%')
    .backgroundColor(0xDCDCDC)
    .padding({ top: 5 })
  }

  private isAdvertisingSlot(index: number): boolean {
    // 假设每隔5个组件就是一个广告位
    return (index % 5 == 0)
  }

  private calculateAdvertisingSlot(index: number): number | null {
    if (this.isAdvertisingSlot(index)) {
      return (index / 5)
    }
    return null
  }

  private calculateItemBackgroundColor(index: number): Color {
    if (this.isAdvertisingSlot(index)) {
      return Color.Green
    }

    return Color.Gray
  }

  private getAdvertisingSlotInfo(index: number): string {
    let advertisingSlot = this.calculateAdvertisingSlot(index)
    if (advertisingSlot) {
      return advertisingSlot + " 号广告位"
    }
    return '普通内容 ' + index
  }

  private handleExposureTracking(index: number, isExpanding: boolean, currentRatio: number): void {
    if (!this.isAdvertisingSlot(index)) {
      // 不处理非广告位
      return
    }
    let slot = this.getAdvertisingSlotInfo(index)
    if (isExpanding) {
      // 可见比例正在增大，说明组件正在出现
      this.exposureData.notifyAdvertisingSlotIsAppearing(slot)
      return
    }
    // 可见比例正在减小，说明组件正在消失
    this.exposureData.notifyAdvertisingSlotIsDisappearing(slot)
  }
}
```

## 资源按需加载与释放

使用[onVisibleAreaChange](../reference/apis-arkui/arkui-ts/ts-universal-component-visible-area-change-event.md#onvisibleareachange)监听组件可见面积占比的精细变化，当可见比例接近预设阈值时触发回调，根据可见比例的变化加载或释放资源。

> **说明：**
> 
> 该能力从API version 9开始支持。
> - 可见面积以父组件边界为限，超出父组件的部分不会被计入可见面积比值计算;
> - 由于存在浮点数比较，系统会在计算结果接近所设置的阈值时触发回调；
> - 为确保可见性变化通知的及时性，系统在每帧进行计算可见比例的变化检测，为了减小系统负载，应尽可能少的使用这个接口。

```typescript
import { image } from '@kit.ImageKit';

class ListDataSource implements IDataSource {
  private list: number[] = [];
  private listeners: DataChangeListener[] = [];

  constructor(list: number[]) {
    this.list = list;
  }

  totalCount(): number {
    return this.list.length;
  }

  getData(index: number): number {
    return this.list[index];
  }

  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      this.listeners.push(listener);
    }
  }

  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      this.listeners.splice(pos, 1);
    }
  }

  notifyDataDelete(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataDelete(index);
    });
  }

  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index);
    });
  }

  public deleteItem(index: number): void {
    this.list.splice(index, 1);
    this.notifyDataDelete(index);
  }

  public insertItem(index: number, data: number): void {
    this.list.splice(index, 0, data);
    this.notifyDataAdd(index);
  }
}

@Entry
@ComponentV2
struct Index {
  @Local headerImage: PixelMap | null = null
  private data: ListDataSource =
    new ListDataSource([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]);

  build() {
    Column() {
      List({ space: 20, initialIndex: 0 }) {
        ListItem() {
          Image(this.headerImage)
            .width('100%')
            .height(300)
            // 整个页面上只有这一个组件需要监听可见性，并且需要及时感知状态进行资源的及时加载
            .onVisibleAreaChange([0.1], (isExpanding: boolean, currentRatio: number) => {
              this.loadOrReleaseHeaderImage(isExpanding)
            })
        }

        LazyForEach(this.data, (item: number) => {
          ListItem() {
            Text('' + item)
              .width('100%')
              .height(50)
              .fontSize(20)
              .fontColor(Color.White)
              .textAlign(TextAlign.Center)
              .borderRadius(10)
              .backgroundColor(Color.Grey)
          }
        }, (item: number) => item.toString())
      }
      .listDirection(Axis.Vertical)
      .scrollBar(BarState.Off)
      .edgeEffect(EdgeEffect.Spring)
      .width('90%')
      .margin(5)
    }
    .width('100%')
    .height('100%')
    .backgroundColor(0xDCDCDC)
    .padding({ top: 5 })
  }

  private loadOrReleaseHeaderImage(isExpanding: boolean): void {
    if (!isExpanding) {
      // 马上就不可见了，释放掉图片
      this.headerImage = null
      console.info('图片释放完成')
      return
    }

    try {
      this.getUIContext().getHostContext()!.resourceManager.getMediaContent($r('app.media.startIcon').id,
        (error, value: ArrayBuffer) => {
          let opts: image.InitializationOptions = {
            editable: true,
            pixelFormat: 3,
            size: { height: 4, width: 6 }
          };
          let uint8Array: Uint8Array = new Uint8Array(value);
          let buffer: ArrayBuffer = uint8Array.buffer.slice(0);

          image.createPixelMap(buffer, opts).then((pixelMap) => {
            this.headerImage = pixelMap
            console.info('图片加载完成')
          })
        });
    } catch (error) {
      console.error(`callback getMediaContent failed, error code: ${error.code}, message: ${error.message}.`)
    }
  }
}
```

## 感知复杂视图切换

通过UIObserver提供的[on('nodeRenderState')](../reference/apis-arkui/arkts-apis-uicontext-uiobserver.md#onnoderenderstate20)方法，可以监听指定组件的渲染状态。此接口需要传入一个组件标识，以指定需要观察的组件，因此不适用于组件频繁创建和销毁的场景，适用于因页面变化导致的组件显隐变化，例如页面跳转、组件所在页面被压栈，如Swiper/Tabs组件当前显示页被划出的场景。

渲染状态有两种：
- ABOUT_TO_RENDER_IN：组件已挂载到渲染树，下一帧将被渲染；
- ABOUT_TO_RENDER_OUT：组件已从渲染树移除，下一帧不再渲染。

> **说明：**
> 
> 该能力从API version 20开始支持。

需要注意的是，ABOUT_TO_RENDER_IN仅表示组件进入渲染流程，下一帧将由系统送显到屏幕上，但组件可能因被其他组件遮挡而无法被看到，因此渲染状态并不完全等同于可见性。

以下示例将一个被观测的Column组件置于Tabs、Navigation和Swiper的嵌套布局中，无论切换Tab页、页面跳转或Swiper页，均能准确感知组件是否显示于屏幕上。

> **说明：**
> 鉴于on('nodeRenderState')接口的特点，不建议将其用于列表项这种划出屏幕区域外节点就会被回收下树的场景。


```typescript
// Index.ets
import { NodeRenderState } from '@kit.ArkUI';

@Entry
@ComponentV2
struct Index {
  private childNavStack: NavPathStack = new NavPathStack();
  private tabController: TabsController = new TabsController();

  build() {
    Tabs({ barPosition: BarPosition.End, controller: this.tabController }) {
      TabContent() {
        Navigation() {
          Stack({ alignContent: Alignment.Center }) {
            Swiper() {
              // swiper 第一页为一个子navigation
              Navigation(this.childNavStack) {
                Column() {
                  Text('被监听的组件')
                    .width('100%')
                    .height('100%')
                    .fontSize(26)
                    .fontColor(Color.White)
                    .textAlign(TextAlign.Center)
                }
                .width('90%')
                .height(300)
                .backgroundColor(Color.Blue)
                .id('component_to_be_monitor')
                .onAttach(() => {
                  // 10ms后再注册监听回调，避免挂载还未完全完成
                  setTimeout(()=>{
                    // 在被监听的组件挂载的时候开启对该组件的状态监听
                    this.getUIContext()
                      .getUIObserver()
                      .on('nodeRenderState', 'component_to_be_monitor', (state: NodeRenderState, node?: FrameNode) => {
                        if (state == NodeRenderState.ABOUT_TO_RENDER_IN) {
                          console.info('组件将显示')
                        } else {
                          console.info('组件将消失')
                        }
                      })
                  }, 10)
                })
                .onDetach(() => {
                  // 在被监听的组件从组件树上下树时取消监听
                  this.getUIContext().getUIObserver().off('nodeRenderState', 'component_to_be_monitor')
                })

                Button('跳转下一页', { stateEffect: true, type: ButtonType.Capsule })
                  .width('80%')
                  .height(40)
                  .margin(20)
                  .onClick(() => {
                    let parentStack = this.childNavStack.getParent();
                    parentStack?.pushPath({ name: "pageTwo" });
                  })
              }
              .clip(true)
              .backgroundColor(Color.Orange)
              .width('90%')
              .height('90%')
              .title('ChildNavigation')

              // swiper 第二页
              Text('swiper 第二页')
                .width('90%')
                .height('90%')
                .fontSize(20)
                .fontColor(Color.Black)
                .backgroundColor(Color.Orange)
                .textAlign(TextAlign.Center)
              // swiper 第三页
              Text('swiper 第三页')
                .width('90%')
                .height('90%')
                .fontSize(20)
                .fontColor(Color.Black)
                .backgroundColor(Color.Orange)
                .textAlign(TextAlign.Center)
            }
            .itemSpace(10)
          }
          .width('100%')
          .height('100%')
        }
        .backgroundColor(Color.Green)
        .width('100%')
        .height('100%')
        .title('ParentNavigation')
      }.tabBar('首页')

      TabContent() {
        Text('推荐')
          .width('100%')
          .height('100%')
          .fontSize(20)
          .fontColor(Color.Black)
          .backgroundColor(Color.Pink)
          .textAlign(TextAlign.Center)
      }.tabBar('推荐')

      TabContent() {
        Text('我的')
          .width('100%')
          .height('100%')
          .fontSize(20)
          .fontColor(Color.Black)
          .backgroundColor(Color.Yellow)
          .textAlign(TextAlign.Center)
      }.tabBar('我的')
    }
    .backgroundColor(Color.Gray)
  }
}
```

```typescript
// PageTwo.ets
@Builder
export function PageTwoBuilder(name: string) {
  NavDestination() {
    Text("this is " + name)
      .width('100%')
      .height('100%')
      .textAlign(TextAlign.Center)
      .fontSize(20)
      .fontColor(Color.White)
      .backgroundColor(Color.Red)
  }
  .title(name)
}
```

在resources/base/profile中创建route_map.json文件，并添加以下配置信息。

```json
{
  "routerMap": [
    {
      "name": "pageTwo",
      "pageSourceFile": "src/main/ets/pages/PageTwo.ets",
      "buildFunction": "PageTwoBuilder",
      "data": {
        "description": "this is pageTwo"
      }
    }
  ]
}
```

在module.json5配置文件的module标签中定义routerMap字段，指向路由表配置文件route_map.json。

```json
"routerMap": "$profile:route_map"
```

## 常见问题

### 可见性计算与实际视觉不符

**问题现象**

组件已进入屏幕但回调未触发，或可见比例与视觉感知不一致。

**解决措施**
- 检查父组件是否设置clip属性，裁剪可能导致可见面积计算偏差。
- 考虑组件透明度影响，即使 opacity为0也会被计入可见面积。
- 结合nodeRenderState监听交叉验证。

### 高频回调导致性能下降

**问题现象**

滚动时界面卡顿，日志显示可见性回调频繁执行。

**解决措施**
- 切换到onVisibleAreaApproximateChange并将expectedUpdateInterval设置为一个更大的值。
- 减少注册可见性回调的组件数量。

### RenderState监听数量超限
**问题现象**

nodeRenderState监听失败，日志提示超出最大监听数量。

**解决措施**
- 替换为使用局部监听接口onVisibleAreaApproximateChange。
- 替换为对显示范围较大的父容器组件进行监听。
- 及时移除不再需要的监听off方法。
