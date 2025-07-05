# UI显示异常问题案例

## 案例一：通过ComponentUtils.getRectangleById获取的tabBar组件坐标尺寸异常

**问题现象**

在动态控制 tabBar 显示 / 隐藏的场景下，通过ComponentUtils.getRectangleById获取的 tabBar 组件坐标或尺寸与开发者预期不符。例如：tabBar 隐藏时（宽度设为 0）获取的坐标位于屏幕中央，而恢复显示后，该错误坐标仍被沿用。

**可能原因**

- 使用同步接口查询布局信息时，目标节点的宽度被临时设置为 0，此时节点布局默认居中显示，导致获取的坐标为屏幕中央位置。
- 调用接口时，当前布局尚未完成渲染（如组件刚被隐藏 / 显示，布局计算未结束），同步查询到的是未更新的旧布局信息。

**解决措施**

- 选择合适的调用时机：在组件确定完成布局渲染后调用接口。例如，在 tabBar 恢复显示后，通过延迟函数等待布局更新完成，再获取坐标。
- 监听布局变化事件：利用组件的onAreaChange回调，在布局发生变化并稳定后，自动触发坐标获取逻辑。
- 增加有效性校验：获取坐标后，校验组件尺寸（如宽度 / 高度是否为 0），过滤无效数据。


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