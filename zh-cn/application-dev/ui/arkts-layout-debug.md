# UI显示异常调试

本章节主要介绍UI显示异常问题的调试方法，并结合案例讲解具体的解决步骤。

## 定位UI显示异常问题

UI显示异常问题主要是通过分析UI布局信息来定位。当前分析UI布局主要通过getInspectorTree接口获取组件树信息，或者通过getRectangleById接口获取单个节点的信息。

**组件树**

从API version 9开始，可以使用[getInspectorTree](../reference/apis-arkui/arkui-ts/ts-universal-attributes-component-id.md#getinspectortree9)接口获取组件树及其属性。

**单个节点**

从API version 10开始，可以使用[getRectangleById](../reference/apis-arkui/arkts-apis-uicontext-componentutils.md#getrectanglebyid)接口获取组件的大小、位置、平移、缩放、旋转及仿射矩阵等属性信息。

## 解决UI显示异常问题

下面通过具体案例，介绍如何解决UI显示异常问题。

### 通过ComponentUtils.getRectangleById获取的tabBar组件坐标尺寸异常

**问题现象**

在动态控制tabBar显示或隐藏的场景下，通过`ComponentUtils.getRectangleById`获取的tabBar组件坐标或尺寸可能与预期不符。例如，当tabBar隐藏时（宽度设为0），获取的坐标位于屏幕中央，恢复显示后，该错误坐标仍被沿用。

**可能原因**

- 使用同步接口查询布局信息时，目标节点的宽度临时设置为0，节点布局默认居中显示，导致获取的坐标位于屏幕中央。
- 调用接口时，如果当前布局尚未完成渲染（例如，组件刚被隐藏或显示，布局计算未结束），查询到的将是未更新的旧布局信息。

**解决措施**

- 选择合适的调用时机：在组件完成布局渲染后调用接口。例如，tabBar恢复显示后，使用延迟函数等待布局更新完成，再获取坐标。
- 监听布局变化事件：利用组件的`onAreaChange`回调，在布局变化并稳定后，触发坐标获取逻辑。
- 增加有效性校验：获取坐标后，校验组件尺寸，过滤无效数据。宽度或高度为0的组件被视为无效。


**代码示例**

```ts
import { ComponentUtils } from '@kit.ArkUI';

@Entry
@Component
struct Page {
  @State currentIndex: number = 0;
  @State msg: string = 'info';
  @State pivotX: number = 0;
  @State pivotY: number = 0;
  @State pivotShow: boolean = false;
  @State tabBarShow: boolean = true;

  private controller : TabsController = new TabsController();
  private uiContext : UIContext | undefined = undefined;
  private componentUtils : ComponentUtils | undefined = undefined;
  private componentId : string = 'tab-pink';
  private flag : boolean = false;
  private baseX : number = 0;
  private baseY : number = 0;

  @Builder
  tabBuilder(index: number, name: string) {
    Column() {
      Text(name)
        .fontSize(16)
        .fontWeight(this.currentIndex === index ? 500 : 400)
        .fontColor(this.currentIndex === index ? '#007DFF': '#182431')
        .lineHeight(22)
    }
    .id(`tab-${name}`)
    .width('100%')
    .height('100%')
    .borderStyle(BorderStyle.Solid)
    .borderWidth(1)
  }

  aboutToAppear(): void {
    this.uiContext = this.getUIContext();
    this.componentUtils = this.getUIContext().getComponentUtils();
  }

  getRectInfo(id?: string) : string {
    let componentId : string = id??this.componentId;
    let info = this.componentUtils?.getRectangleById(componentId);
    let infoStr : string = '';
    if (info) {
      infoStr = 'Size: ' + JSON.stringify(info.size) + ', WindowOffset: ' + JSON.stringify(info.windowOffset);
    }
    return infoStr;
  }

  getBasePosition() : void {
    if (this.flag) {
      return;
    }
    let info = this.componentUtils?.getRectangleById('root-stack');
    if (info) {
      this.baseX = info.windowOffset.x;
      this.baseY = info.windowOffset.y;
      this.msg = `${this.componentId}: ` + this.getRectInfo(this.componentId) + `, pivot: {x: ${this.pivotX}, y: ${this.pivotY}}`;
      this.flag = true;
    }
  }

  onDidBuild(): void {
  }

  build() {
    Stack() {
      Column() {
        Text(this.msg)
          .fontSize(20)
          .border({ width: 5, color: Color.Brown })
          .width('100%')
          .height('30%')
          .margin({ top: 50 })
        Row() {
          Button('Rect')
            .onClick(() => {
              this.msg = JSON.stringify(this.componentUtils?.getRectangleById('tab-pink'))
            })
            .width('33%')
          Button('replay')
            .onClick(() => {
              this.pivotShow = false;
              this.tabBarShow = false;
              this.pivotShow = true;
              setTimeout(() => {
                this.tabBarShow = true
              }, 100)
            })
            .width('33%')
          Button('pivot')
            .onClick(() => {
              this.pivotShow = !this.pivotShow;
            })
            .width('33%')
        }
        .width('100%')
        .height('10%')
        .justifyContent(FlexAlign.SpaceEvenly)
        Tabs({ barPosition: BarPosition.End, index: this.currentIndex, controller: this.controller }) {
          TabContent() {
            Column()
              .width('100%')
              .height('100%')
              .backgroundColor('#00CB87')
          }
          .tabBar(this.tabBuilder(0, 'green'))
          TabContent() {
            Column()
              .width('100%')
              .height('100%')
              .backgroundColor('#007DFF')
          }
          .tabBar(this.tabBuilder(1, 'blue'))
          TabContent() {
            Column()
              .width('100%')
              .height('100%')
              .backgroundColor('#FFBF00')
          }
          .tabBar(this.tabBuilder(2, 'yellow'))
          .width('25%')
          TabContent() {
            Column()
              .width('100%')
              .height('100%')
              .backgroundColor('#E67C92')
          }
          .tabBar(this.tabBuilder(3, 'pink'))
        }
        .expandSafeArea([SafeAreaType.CUTOUT, SafeAreaType.SYSTEM, SafeAreaType.KEYBOARD],
          [SafeAreaEdge.TOP, SafeAreaEdge.BOTTOM])
        .barWidth(this.tabBarShow ? '100%' : 0)
        .width('100%')
        .height('40%')
        .barHeight(44)
        .vertical(false)
        .barMode(BarMode.Fixed)
        .backgroundColor('#F1F2F3')
        .onChange((index: number) => {
          this.currentIndex = index;
          if (index == 3) {
            this.pivotShow = false;
          }
        })
        .animation({ duration: 100, curve: Curve.Linear })
      }
      .id('col')
      .width('100%')
      .height('100%')
      .justifyContent(FlexAlign.SpaceBetween)
      if (this.pivotShow) {
        Text('X')
          .width(18)
          .height(18)
          .textAlign(TextAlign.Center)
          .borderRadius(9)
          .fontColor(Color.White)
          .backgroundColor(Color.Red)
          .position({ x: this.uiContext?.px2vp(this.pivotX), y: this.uiContext?.px2vp(this.pivotY) })
          .onAreaChange(() => {
            let info = this.componentUtils?.getRectangleById(this.componentId);
            if (info) {
              this.getBasePosition();
              this.pivotX = info.windowOffset.x - this.baseX;
              this.pivotY = info.windowOffset.y - this.baseY;
              this.msg = `${this.componentId}: ` + this.getRectInfo(this.componentId) + `, pivot: {x: ${this.pivotX}, y: ${this.pivotY}}`;
            }
          })
      }
    }
    .id('root-stack')
  }
}
```