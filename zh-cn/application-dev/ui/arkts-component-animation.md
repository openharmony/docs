# 组件动画
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @CCFFWW-->
<!--Designer: @CCFFWW-->
<!--Tester: @lxl007-->
<!--Adviser: @HelloCrease-->


ArkUI为组件提供了通用的属性动画和转场动画能力的同时，还为一些组件提供了默认的动画效果。例如，[List](../reference/apis-arkui/arkui-ts/ts-container-list.md)的滑动动效、[Button](../reference/apis-arkui/arkui-ts/ts-basic-components-button.md)的点击动效，是组件自带的默认动画效果。在组件默认动画效果的基础上，开发者还可以通过属性动画和转场动画对容器组件内的子组件动效进行定制。


## 使用组件默认动画

组件默认动效具备以下功能：

- 提示用户当前状态，例如用户点击Button组件时，Button组件默认变灰，用户即确定完成选中操作。

- 提升界面精致程度和生动性。

- 减少开发者工作量，例如列表滑动组件自带滑动动效，开发者直接调用即可。

更多效果，可以参考[组件说明](../reference/apis-arkui/arkui-ts/ts-container-flex.md)。

示例代码和效果如下。


```ts
@Entry
@Component
struct ComponentDemo {
  build() {
    Row() {
      Checkbox({ name: 'checkbox1', group: 'checkboxGroup' })
        .select(true)
        .shape(CheckBoxShape.CIRCLE)
        .size({ width: 50, height: 50 })
    }
    .width('100%')
    .height('100%')
    .justifyContent(FlexAlign.Center)
  }
}
```

![zh-cn_image_0000001649338585](figures/zh-cn_image_0000001649338585.gif)



## 打造组件定制化动效

部分组件支持通过[属性动画](arkts-attribute-animation-overview.md)和[转场动画](arkts-transition-overview.md)自定义组件子Item的动效，实现定制化动画效果。例如，[Scroll](../reference/apis-arkui/arkui-ts/ts-container-scroll.md)组件中可对各个子组件在滑动时的动画效果进行定制。

- 在滑动或者点击操作时通过改变各个Scroll子组件的仿射属性来实现各种效果。

- 如果要在滑动过程中定制动效，可在滑动回调onScroll中监控滑动距离，并计算每个组件的仿射属性。也可以自己定义手势，通过手势监控位置，手动调用ScrollTo改变滑动位置。

- 在滑动回调onScrollStop或手势结束回调中对滑动的最终位置进行微调。

定制Scroll组件滑动动效示例代码和效果如下。

```ts
import { curves, window, display, mediaquery, UIContext } from '@kit.ArkUI';
import { UIAbility } from '@kit.AbilityKit';

export default class GlobalContext extends AppStorage {
  static mainWin: window.Window | undefined = undefined;
  static mainWindowSize: window.Size | undefined = undefined;
}
/**
 * 窗口、屏幕相关信息管理类
 */
export class WindowManager {
  private static instance: WindowManager | null = null;
  private displayInfo: display.Display | null = null;
  private uiContext: UIContext;
  private orientationListener: mediaquery.MediaQueryListener;

  constructor(uiContext: UIContext) {
    this.uiContext = uiContext
    this.orientationListener = this.uiContext.getMediaQuery().matchMediaSync('(orientation: landscape)');
    this.orientationListener.on('change', (mediaQueryResult: mediaquery.MediaQueryResult) => {
      this.onPortrait(mediaQueryResult)
    })
    this.loadDisplayInfo()
  }

  /**
   * 设置主window窗口
   * @param win 当前app窗口
   */
  setMainWin(win: window.Window) {
    if (win == null) {
      return
    }
    GlobalContext.mainWin = win;
    win.on("windowSizeChange", (data: window.Size) => {
      if (GlobalContext.mainWindowSize == undefined || GlobalContext.mainWindowSize == null) {
        GlobalContext.mainWindowSize = data;
      } else {
        if (GlobalContext.mainWindowSize.width == data.width && GlobalContext.mainWindowSize.height == data.height) {
          return
        }
        GlobalContext.mainWindowSize = data;
      }

      let winWidth = this.getMainWindowWidth();
      AppStorage.setOrCreate<number>('mainWinWidth', winWidth)
      let winHeight = this.getMainWindowHeight();
      AppStorage.setOrCreate<number>('mainWinHeight', winHeight)
      let context: UIAbility = new UIAbility()
      context.context.eventHub.emit("windowSizeChange", winWidth, winHeight)
    })
  }

  static getInstance(uiContext: UIContext): WindowManager {
    if (WindowManager.instance == null) {
      WindowManager.instance = new WindowManager(uiContext);
    }
    return WindowManager.instance
  }

  private onPortrait(mediaQueryResult: mediaquery.MediaQueryResult) {
    if (mediaQueryResult.matches == AppStorage.get<boolean>('isLandscape')) {
      return
    }
    AppStorage.setOrCreate<boolean>('isLandscape', mediaQueryResult.matches)
    this.loadDisplayInfo()
  }

  /**
   * 切换屏幕方向
   * @param ori 常量枚举值：window.Orientation
   */
  changeOrientation(ori: window.Orientation) {
    if (GlobalContext.mainWin != null) {
      GlobalContext.mainWin.setPreferredOrientation(ori)
    }
  }

  private loadDisplayInfo() {
    this.displayInfo = display.getDefaultDisplaySync()
    AppStorage.setOrCreate<number>('displayWidth', this.getDisplayWidth())
    AppStorage.setOrCreate<number>('displayHeight', this.getDisplayHeight())
  }

  /**
   * 获取main窗口宽度，单位vp
   */
  getMainWindowWidth(): number {
    return GlobalContext.mainWindowSize != null ? this.uiContext.px2vp(GlobalContext.mainWindowSize.width) : 0
  }

  /**
   * 获取main窗口高度，单位vp
   */
  getMainWindowHeight(): number {
    return GlobalContext.mainWindowSize != null ? this.uiContext.px2vp(GlobalContext.mainWindowSize.height) : 0
  }

  /**
   * 获取屏幕宽度，单位vp
   */
  getDisplayWidth(): number {
    return this.displayInfo != null ? this.uiContext.px2vp(this.displayInfo.width) : 0
  }

  /**
   * 获取屏幕高度，单位vp
   */
  getDisplayHeight(): number {
    return this.displayInfo != null ? this.uiContext.px2vp(this.displayInfo.height) : 0
  }

  /**
   * 释放资源
   */
  release() {
    if (this.orientationListener) {
      this.orientationListener.off('change', (mediaQueryResult: mediaquery.MediaQueryResult) => {
        this.onPortrait(mediaQueryResult)
      })
    }
    if (GlobalContext.mainWin != null) {
      GlobalContext.mainWin.off('windowSizeChange')
    }
    WindowManager.instance = null;
  }
}

/**
 * 封装任务卡片信息数据类
 */
export class TaskData {
  bgColor: Color | string | Resource = Color.White;
  index: number = 0;
  taskInfo: string = 'music';

  constructor(bgColor: Color | string | Resource, index: number, taskInfo: string) {
    this.bgColor = bgColor;
    this.index = index;
    this.taskInfo = taskInfo;
  }
}

export const taskDataArr: Array<TaskData> =
  [
    new TaskData('#317AF7', 0, 'music'),
    new TaskData('#D94838', 1, 'mall'),
    new TaskData('#DB6B42', 2, 'photos'),
    new TaskData('#5BA854', 3, 'setting'),
    new TaskData('#317AF7', 4, 'call'),
    new TaskData('#D94838', 5, 'music'),
    new TaskData('#DB6B42', 6, 'mall'),
    new TaskData('#5BA854', 7, 'photos'),
    new TaskData('#D94838', 8, 'setting'),
    new TaskData('#DB6B42', 9, 'call'),
    new TaskData('#5BA854', 10, 'music')

  ];

@Entry
@Component
export struct TaskSwitchMainPage {
  displayWidth: number = WindowManager.getInstance(this.getUIContext()).getDisplayWidth();
  scroller: Scroller = new Scroller();
  cardSpace: number = 0; // 卡片间距
  cardWidth: number = this.displayWidth / 2 - this.cardSpace / 2; // 卡片宽度
  cardHeight: number = 400; // 卡片高度
  cardPosition: Array<number> = []; // 卡片初始位置
  clickIndex: boolean = false;
  @State taskViewOffsetX: number = 0;
  @State cardOffset: number = this.displayWidth / 4;
  lastCardOffset: number = this.cardOffset;
  startTime: number | undefined = undefined

  // 每个卡片初始位置
  aboutToAppear() {
    for (let i = 0; i < taskDataArr.length; i++) {
      this.cardPosition[i] = i * (this.cardWidth + this.cardSpace);
    }
  }

  // 每个卡片位置
  getProgress(index: number): number {
    let progress = (this.cardOffset + this.cardPosition[index] - this.taskViewOffsetX + this.cardWidth / 2) / this.displayWidth;
    return progress
  }

  build() {
    Stack({ alignContent: Alignment.Bottom }) {
      // 背景
      Column()
        .width('100%')
        .height('100%')
        .backgroundColor(0xF0F0F0)

      // 滑动组件
      Scroll(this.scroller) {
        Row({ space: this.cardSpace }) {
          ForEach(taskDataArr, (item: TaskData, index) => {
            Column()
              .width(this.cardWidth)
              .height(this.cardHeight)
              .backgroundColor(item.bgColor)
              .borderStyle(BorderStyle.Solid)
              .borderWidth(1)
              .borderColor(0xAFEEEE)
              .borderRadius(15)
                // 计算子组件的仿射属性
              .scale((this.getProgress(index) >= 0.4 && this.getProgress(index) <= 0.6) ?
                {
                  x: 1.1 - Math.abs(0.5 - this.getProgress(index)),
                  y: 1.1 - Math.abs(0.5 - this.getProgress(index))
                } :
                { x: 1, y: 1 })
              .animation({ curve: Curve.Smooth })
                // 滑动动画
              .translate({ x: this.cardOffset })
              .animation({ curve: curves.springMotion() })
              .zIndex((this.getProgress(index) >= 0.4 && this.getProgress(index) <= 0.6) ? 2 : 1)
          }, (item: TaskData) => item.toString())
        }
        .width((this.cardWidth + this.cardSpace) * (taskDataArr.length + 1))
        .height('100%')
      }
      .gesture(
        GestureGroup(GestureMode.Parallel,
          PanGesture({ direction: PanDirection.Horizontal, distance: 5 })
            .onActionStart((event: GestureEvent | undefined) => {
              if (event) {
                this.startTime = event.timestamp;
              }
            })
            .onActionUpdate((event: GestureEvent | undefined) => {
              if (event) {
                this.cardOffset = this.lastCardOffset + event.offsetX;
              }
            })
            .onActionEnd((event: GestureEvent | undefined) => {
              if (event) {
                let time = 0
                if (this.startTime) {
                  time = event.timestamp - this.startTime;
                }
                let speed = event.offsetX / (time / 1000000000);
                let moveX = Math.pow(speed, 2) / 7000 * (speed > 0 ? 1 : -1);

                this.cardOffset += moveX;
                // 左滑大于最右侧位置
                let cardOffsetMax = -(taskDataArr.length - 1) * (this.displayWidth / 2);
                if (this.cardOffset < cardOffsetMax) {
                  this.cardOffset = cardOffsetMax;
                }
                // 右滑大于最左侧位置
                if (this.cardOffset > this.displayWidth / 4) {
                  this.cardOffset = this.displayWidth / 4;
                }

                // 左右滑动距离不满足/满足切换关系时，补位/退回
                let remainMargin = this.cardOffset % (this.displayWidth / 2);
                if (remainMargin < 0) {
                  remainMargin = this.cardOffset % (this.displayWidth / 2) + this.displayWidth / 2;
                }
                if (remainMargin <= this.displayWidth / 4) {
                  this.cardOffset += this.displayWidth / 4 - remainMargin;
                } else {
                  this.cardOffset -= this.displayWidth / 4 - (this.displayWidth / 2 - remainMargin);
                }

                // 记录本次滑动偏移量
                this.lastCardOffset = this.cardOffset;
              }
            })
        ), GestureMask.IgnoreInternal)
      .scrollable(ScrollDirection.Horizontal)
      .scrollBar(BarState.Off)

      // 滑动到首尾位置
      Button('Move to first/last')
        .backgroundColor(0x888888)
        .margin({ bottom: 30 })
        .onClick(() => {
          this.clickIndex = !this.clickIndex;

          if (this.clickIndex) {
            this.cardOffset = this.displayWidth / 4;
          } else {
            this.cardOffset = this.displayWidth / 4 - (taskDataArr.length - 1) * this.displayWidth / 2;
          }
          this.lastCardOffset = this.cardOffset;
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

![zh-cn_image_0000001599808406](figures/zh-cn_image_0000001599808406.gif)

通过animateTo可以实现将List中指定的Item替换到首位，List中其余Item依次向下排列。定制List组件动态替换动效的示例代码和效果如下。

```ts
import { curves, AnimatorResult } from '@kit.ArkUI';

// 该接口控制列表项视觉属性，动态调整scale/offsetY实现拖拽位移和缩放效果，阴影效果提升拖拽项视觉层级（zIndex:1）
class ListItemModify implements AttributeModifier<ListItemAttribute> {
  public hasShadow: boolean = false;
  public scale: number = 1;
  public offsetY: number = 0;
  private scroll: ListScroller = new ListScroller();
  public color: string = '#00000000';

  applyNormalAttribute(instance: ListItemAttribute): void {
    if (this.hasShadow) {
      instance.shadow({
        radius: 70, // 拖拽时阴影层级提升
        color: this.color,
        offsetX: 0,
        offsetY: 0
      })
      instance.zIndex(1)
    }
    instance.scale({ x: this.scale, y: this.scale }) // 缩放控制
    instance.translate({ y: this.offsetY }) // Y轴位移
  }
}

enum DragSortState {
  IDLE,
  PRESSING,
  MOVING,
  DROPPING,
}

@Observed
class DragSortCtrl<T> {
  private arr: Array<T>
  private modify: Array<ListItemModify>
  private uiContext: UIContext; // 新增UIContext成员
  private dragRefOffset: number = 0
  offsetY: number = 0
  state: DragSortState = DragSortState.IDLE
  private ITEM_INTV: number = 120

  constructor(arr: Array<T>, intv: number, uiContext: UIContext) {
    this.arr = arr;
    this.uiContext = uiContext;
    this.modify = new Array<ListItemModify>()
    this.ITEM_INTV = intv
    arr.forEach(() => {
      this.modify.push(new ListItemModify())
    })
  }

  itemMove(index: number, newIndex: number): void {
    let tmp = this.arr.splice(index, 1)
    this.arr.splice(newIndex, 0, tmp[0])
    let tmp2 = this.modify.splice(index, 1)
    this.modify.splice(newIndex, 0, tmp2[0])
  }

  onLongPress(item: T): void {
    this.dragRefOffset = 0
  }

  onMove(item: T, offset: number) {
    this.state = DragSortState.MOVING
    this.offsetY = offset - this.dragRefOffset
    let index = this.arr.indexOf(item)
    this.modify[index].offsetY = this.offsetY
    if (this.offsetY > this.ITEM_INTV / 2) {
      // 使用interpolatingSpring曲线生成弹簧动画
      this.uiContext.animateTo({ curve: curves.interpolatingSpring(0, 1, 400, 38) }, () => {
        this.offsetY -= this.ITEM_INTV
        this.dragRefOffset += this.ITEM_INTV
        this.modify[index].offsetY = this.offsetY
        this.itemMove(index, index + 1) // 执行列表项位置交换
      })
    } else if (this.offsetY < -this.ITEM_INTV / 2) {
      // 使用interpolatingSpring曲线生成弹簧动画
      this.uiContext.animateTo({ curve: curves.interpolatingSpring(0, 1, 400, 38) }, () => {
        this.offsetY += this.ITEM_INTV // 调整偏移量实现平滑移动
        this.dragRefOffset -= this.ITEM_INTV
        this.modify[index].offsetY = this.offsetY
        this.itemMove(index, index - 1) // 执行列表项位置交换
      })
    }
  }

  getModify(item: T): ListItemModify {
    let index = this.arr.indexOf(item)
    return this.modify[index]
  }
}

@Entry
@Component
struct ListAutoSortExample {
  @State private arr: Array<number> = [0, 1, 2, 3, 4, 5]
  @State dragSortCtrl: DragSortCtrl<number> = new DragSortCtrl<number>(this.arr, 120, this.getUIContext())
  @State firstListItemGroupCount: number = 3
  private listScroll: ListScroller = new ListScroller()
  private backAnimator: AnimatorResult | null = null
  private dropFlag: Boolean = true

  @Builder
  itemEnd(item: number, index: number) {
    Row() {
      Button("To TOP").margin("4vp").onClick(() => {
        console.log(`item number item ${item} index ${index}`);
        this.listScroll.closeAllSwipeActions({
          onFinish: () => {
            this.dropFlag = true
            this.dragSortCtrl.onLongPress(item)
            let length = 120 * (this.arr.indexOf(item))
            this.backAnimator = this.getUIContext()?.createAnimator({ // 创建弹簧动画
              duration: 1000,
              easing: "interpolating-spring(0, 1, 150, 24)",
              delay: 0,
              fill: "none",
              direction: "normal",
              iterations: 1,
              begin: 0,
              end: -length
            })
            this.backAnimator.onFrame = (value) => { // 逐帧回调更新位置
              this.dragSortCtrl.onMove(item, value) // 处理list的移动替换动效
            }
            this.backAnimator.onFinish = () => {
              this.dropFlag = true
            }
            this.backAnimator.play() // 启动动画
          }
        })
      })
    }.padding("4vp").justifyContent(FlexAlign.SpaceEvenly)
  }

  @Builder
  header(title: string) {
    Row() {
      Text(title)
    }
  }

  build() {
    Row() {
      Column() {
        List({ space: 20, scroller: this.listScroll }) {
          ListItemGroup({ header: this.header('first ListItemGroup'), space: 20 }) {
            ForEach(this.arr, (item: number, index) => {
              if (index < this.firstListItemGroupCount) {
                ListItem() {
                  Text('' + item)
                    .width('100%')
                    .height(100)
                    .fontSize(16)
                    .borderRadius(10)
                    .textAlign(TextAlign.Center)
                    .backgroundColor(0xFFFFFF)
                }
                .swipeAction({
                  end: this.itemEnd(item, index)
                })
                .clip(true)
                .attributeModifier(this.dragSortCtrl.getModify(item))
                .borderRadius(10)
                .margin({ left: 20, right: 20 })
              }
            })
          }
          ListItemGroup({ header: this.header('second ListItemGroup'), space: 20 }) {
            ForEach(this.arr, (item: number, index) => {
              if (index > this.firstListItemGroupCount - 1) {
                ListItem() {
                  Text('' + item)
                    .width('100%')
                    .height(100)
                    .fontSize(16)
                    .borderRadius(10)
                    .textAlign(TextAlign.Center)
                    .backgroundColor(0xFFFFFF)
                }
                .swipeAction({
                  end: this.itemEnd(item, index)
                })
                .clip(true)
                .attributeModifier(this.dragSortCtrl.getModify(item))
                .borderRadius(10)
                .margin({ left: 20, right: 20 })
              }
            })
          }
        }
        .padding({ top: 20 })
        .height("100%")
      }
    }.backgroundColor(0xDCDCDC)
  }
}
```

![listAnimateDemo](figures/listAnimateDemo.gif)
<!--RP1--><!--RP1End-->