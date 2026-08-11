# Component Animation

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=5c418d4bf2581cd8ca625b8865e73773ebc27789 translatedAt=2026-07-29T12:49:52.109Z pushedAt=2026-07-30T11:21:27.186Z -->

In addition to universal property animation and transition animation APIs, ArkUI provides default animation effects for certain components, for example, the swipe effect for the [List](../reference/apis-arkui/arkui-ts/ts-container-list.md) component and the click effect of the [Button](../reference/apis-arkui/arkui-ts/ts-basic-components-button.md) component. Based on these default animation effects, you can apply custom animations to the child components through the property animation and transition animation APIs.

## Using Default Component Animation

The default animation of a component exhibits the following features:

- Indicate the current state of the component. For example, after the user clicks a **Button** component, the component turns gray, indicating that it is selected.

- Enhance UI refinement and vividness.

- Reduce development workload, as the APIs are readily available.

The following provides an example and effect of the default animation of a **Checkbox** component. For more effects, see the corresponding component description.

Below is the sample code and effect:

<!-- @[component_demo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Animation/entry/src/main/ets/pages/component/template1/Index.ets) -->

``` TypeScript
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

![animation-default](figures/animation-default.gif)

## Customizing Component Animation

Some components allow for animation customization for their child components through the [property animation](arkts-attribute-animation-overview.md) and [transition animation](arkts-transition-overview.md) APIs. For example, you can customize the swipe animation for child components of [Scroll](../reference/apis-arkui/arkui-ts/ts-container-scroll.md).

- For a scroll or click gesture, you can implement various effects by changing affine properties of the child component.

- If you want to customize the animation effect during the scrolling, you can monitor the scrolling distance in the [onDidScroll](../reference/apis-arkui/arkui-ts/ts-container-scrollable-common.md#ondidscroll12) callback and calculate the affine properties of each component. You can also define gestures, monitor positions through the gestures, and manually call **ScrollTo** to change the target scroll position.

- In the scroll callback [onScrollStop](../reference/apis-arkui/arkui-ts/ts-container-scrollable-common.md#onscrollstop11) or the gesture end callback, fine-tune the final target scroll position.

The following is an example of customizing the scroll animation for the **Scroll** component:

<!-- @[Component_Scroll](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Animation/entry/src/main/ets/pages/component/template2/Index.ets) -->

``` TypeScript
import { curves, window, display, mediaquery, UIContext } from '@kit.ArkUI';
import { UIAbility } from '@kit.AbilityKit';

export default class GlobalContext extends AppStorage {
  static mainWin: window.Window | undefined = undefined;
  static mainWindowSize: window.Size | undefined = undefined;
}

/**
 * Encapsulates the WindowManager class.
 */
export class WindowManager {
  private static instance: WindowManager | null = null;
  private displayInfo: display.Display | null = null;
  private uiContext: UIContext;
  private orientationListener: mediaquery.MediaQueryListener;

  constructor(uiContext: UIContext) {
    this.uiContext = uiContext;
    this.orientationListener = this.uiContext.getMediaQuery().matchMediaSync('(orientation: landscape)');
    this.orientationListener.on('change', (mediaQueryResult: mediaquery.MediaQueryResult) => {
      this.onPortrait(mediaQueryResult);
    });
    this.loadDisplayInfo();
  }

  /**
   * Sets the main window.
   * @param win Indicates the current application window.
   */
  setMainWin(win: window.Window) {
    if (win == null) {
      return;
    }
    GlobalContext.mainWin = win;
    win.on('windowSizeChange', (data: window.Size) => {
      if (GlobalContext.mainWindowSize == undefined || GlobalContext.mainWindowSize == null) {
        GlobalContext.mainWindowSize = data;
      } else {
        if (GlobalContext.mainWindowSize.width == data.width && GlobalContext.mainWindowSize.height == data.height) {
          return;
        }
        GlobalContext.mainWindowSize = data;
      }

      let winWidth = this.getMainWindowWidth();
      AppStorage.setOrCreate<number>('mainWinWidth', winWidth);
      let winHeight = this.getMainWindowHeight();
      AppStorage.setOrCreate<number>('mainWinHeight', winHeight);
      let context: UIAbility = new UIAbility();
      context.context.eventHub.emit('windowSizeChange', winWidth, winHeight);
    });
  }

  static getInstance(uiContext: UIContext): WindowManager {
    if (WindowManager.instance == null) {
      WindowManager.instance = new WindowManager(uiContext);
    }
    return WindowManager.instance;
  }

  private onPortrait(mediaQueryResult: mediaquery.MediaQueryResult) {
    if (mediaQueryResult.matches == AppStorage.get<boolean>('isLandscape')) {
      return;
    }
    AppStorage.setOrCreate<boolean>('isLandscape', mediaQueryResult.matches);
    this.loadDisplayInfo();
  }

  /**
   * Changes the screen orientation.
   * @param ori Orientation, specified using the enumerated values of window.Orientation.
   */
  changeOrientation(ori: window.Orientation) {
    if (GlobalContext.mainWin != null) {
      GlobalContext.mainWin.setPreferredOrientation(ori);
    }
  }

  private loadDisplayInfo() {
    this.displayInfo = display.getDefaultDisplaySync();
    AppStorage.setOrCreate<number>('displayWidth', this.getDisplayWidth());
    AppStorage.setOrCreate<number>('displayHeight', this.getDisplayHeight());
  }

  /**
   * Obtains the width of the main window, in vp.
   */
  getMainWindowWidth(): number {
    return GlobalContext.mainWindowSize != null ? this.uiContext.px2vp(GlobalContext.mainWindowSize.width) : 0;
  }

  /**
   * Obtains the height of the main window, in vp.
   */
  getMainWindowHeight(): number {
    return GlobalContext.mainWindowSize != null ? this.uiContext.px2vp(GlobalContext.mainWindowSize.height) : 0;
  }

  /**
   * Obtains the screen width, in vp.
   */
  getDisplayWidth(): number {
    return this.displayInfo != null ? this.uiContext.px2vp(this.displayInfo.width) : 0;
  }

  /**
   * Obtains the screen height, in vp.
   */
  getDisplayHeight(): number {
    return this.displayInfo != null ? this.uiContext.px2vp(this.displayInfo.height) : 0;
  }

  /**
   * Releases resources.
   */
  release() {
    if (this.orientationListener) {
      this.orientationListener.off('change', (mediaQueryResult: mediaquery.MediaQueryResult) => {
        this.onPortrait(mediaQueryResult);
      });
    }
    if (GlobalContext.mainWin != null) {
      GlobalContext.mainWin.off('windowSizeChange');
    }
    WindowManager.instance = null;
  }
}

/**
 * Encapsulates the TaskData class.
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
  cardSpace: number = 0; // Widget spacing
  cardWidth: number = this.displayWidth / 2 - this.cardSpace / 2; // Widget width
  cardHeight: number = 400; // Widget height
  cardPosition: Array<number> = []; // Initial position of the widget
  clickIndex: boolean = false;
  @State taskViewOffsetX: number = 0;
  @State cardOffset: number = this.displayWidth / 4;
  lastCardOffset: number = this.cardOffset;
  startTime: number | undefined = undefined;

  // Initial position of each widget
  aboutToAppear() {
    for (let i = 0; i < taskDataArr.length; i++) {
      this.cardPosition[i] = i * (this.cardWidth + this.cardSpace);
    }
  }

  // Position of each widget
  getProgress(index: number): number {
    let progress = (this.cardOffset + this.cardPosition[index] - this.taskViewOffsetX +
      this.cardWidth / 2) / this.displayWidth;
    return progress;
  }

  build() {
    Stack({ alignContent: Alignment.Bottom }) {
      // Background
      Column()
        .width('100%')
        .height('100%')
        .backgroundColor(0xF0F0F0)

      // <Scroll> component
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
              // Calculate the affine properties of child components.
              .scale((this.getProgress(index) >= 0.4 && this.getProgress(index) <= 0.6) ?
                {
                  x: 1.1 - Math.abs(0.5 - this.getProgress(index)),
                  y: 1.1 - Math.abs(0.5 - this.getProgress(index))
                } :
                { x: 1, y: 1 })
              .animation({ curve: Curve.Smooth })
              // Apply a pan animation.
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
                let time = 0;
                if (this.startTime) {
                  time = event.timestamp - this.startTime;
                }
                let speed = event.offsetX / (time / 1000000000);
                let moveX = Math.pow(speed, 2) / 7000 * (speed > 0 ? 1 : -1);

                this.cardOffset += moveX;
                // When panning left to a position beyond the rightmost position
                let cardOffsetMax = -(taskDataArr.length - 1) * (this.displayWidth / 2);
                if (this.cardOffset < cardOffsetMax) {
                  this.cardOffset = cardOffsetMax;
                }
                // When panning right to a position beyond the leftmost position
                if (this.cardOffset > this.displayWidth / 4) {
                  this.cardOffset = this.displayWidth / 4;
                }

                // Processing when the pan distance is less than the minimum distance
                let remainMargin = this.cardOffset % (this.displayWidth / 2);
                if (remainMargin < 0) {
                  remainMargin = this.cardOffset % (this.displayWidth / 2) + this.displayWidth / 2;
                }
                if (remainMargin <= this.displayWidth / 4) {
                  this.cardOffset += this.displayWidth / 4 - remainMargin;
                } else {
                  this.cardOffset -= this.displayWidth / 4 - (this.displayWidth / 2 - remainMargin);
                }

                // Record the pan offset.
                this.lastCardOffset = this.cardOffset;
              }
            })
        ), GestureMask.IgnoreInternal)
      .scrollable(ScrollDirection.Horizontal)
      .scrollBar(BarState.Off)

      // Move to the beginning and end positions.
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

![animation-custom](figures/animation-custom.gif)

You can use the **animateTo** API to move a specified item to the top of the list, while other items in the list are rearranged sequentially. Below is the sample code and animation effect demonstrating a custom dynamic replacement animation for the **List** component.

<!-- @[Component_List](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Animation/entry/src/main/ets/pages/component/template3/Index.ets) -->

``` TypeScript
import { curves, AnimatorResult } from '@kit.ArkUI';

// This API controls the visual attributes of list items.
class ListItemModify implements AttributeModifier<ListItemAttribute> {
  public offsetY: number = 0; // Y-axis offset.

  applyNormalAttribute(instance: ListItemAttribute): void {
    instance.translate({ y: this.offsetY }); // Y-axis translation.
  }
}

@Observed
class DragSortCtrl<T> {
  private arr: Array<T>; // Data array.
  private modify: Array<ListItemModify>; // Attribute modifier array.
  private uiContext: UIContext; // Add a UIContext member.
  private dragRefOffset: number = 0; // Drag reference offset.
  offsetY: number = 0; // Current Y-axis offset.
  private ITEM_INTV: number = 0; // List item interval.

  constructor(arr: Array<T>, intv: number, uiContext: UIContext) {
    this.arr = arr;
    this.uiContext = uiContext;
    this.modify = [];
    this.ITEM_INTV = intv;
    arr.forEach(() => {
      this.modify.push(new ListItemModify());
    });
  }

  itemMove(index: number, newIndex: number): void {
    let tmp = this.arr.splice(index, 1); // Remove the item at the current index.
    this.arr.splice(newIndex, 0, tmp[0]); // Insert the removed item at the previous position.
    let tmp2 = this.modify.splice(index, 1);
    this.modify.splice(newIndex, 0, tmp2[0]);
  }

  setDragRef(item: T): void {
    this.dragRefOffset = 0;
  }

  onMove(item: T, offset: number) {
    this.offsetY = offset - this.dragRefOffset; // Calculate the incoming offset frame by frame. When the accumulated offset reaches the height of one item, enter the if block below and update the value of dragRefOffset.
    let index = this.arr.indexOf(item); // Search for the input item in the array.
    this.modify[index].offsetY = this.offsetY;
    if (this.offsetY < -this.ITEM_INTV / 2) { // Move the specified item to the top, one position at a time.
      // Use the interpolatingSpring curve to generate a spring animation.
      this.uiContext.animateTo({ curve: curves.interpolatingSpring(0, 1, 400, 38) }, () => { // 400: spring stiffness, 38: spring damping.
        this.offsetY += this.ITEM_INTV; // Adjust the offset for smooth movement.
        this.dragRefOffset -= this.ITEM_INTV; // Total offset moved.
        console.info(`item offsetY ${this.offsetY} dragRefOffset ${this.dragRefOffset}`);
        this.itemMove(index, index - 1); // Swap the positions of the list items.
      });
    }
  }

  getModify(item: T): ListItemModify {
    let index = this.arr.indexOf(item);
    return this.modify[index];
  }
}

@Entry
@Component
struct ListAutoSortExample {
  @State private arr: Array<number> = [0, 1, 2, 3, 4, 5]; // List data array.
  @State dragSortCtrl: DragSortCtrl<number> =
    new DragSortCtrl<number>(this.arr, 120, this.getUIContext()); // 120: list item height interval.
  @State firstListItemGroupCount: number = 3; // Number of items in the first list item group.
  private listScroll: ListScroller = new ListScroller(); // List scroll controller.
  private backAnimator: AnimatorResult | null = null; // Animation controller.

  @Builder
  itemEnd(item: number, index: number) {
    Row() {
      Button('To TOP').margin('4vp').onClick(() => { // 4vp: button margin.
        console.info(`item number item ${item} index ${index}`);
        this.listScroll.closeAllSwipeActions({
          onFinish: () => {
            this.dragSortCtrl.setDragRef(item);
            let length = 120 * (this.arr.indexOf(item)); // 120: list item height interval.
            this.backAnimator = this.getUIContext()?.createAnimator({
              // Create a spring animation.
              duration: 1000, // Animation duration, in milliseconds.
              easing: 'interpolating-spring(0, 1, 150, 24)', // 150: spring stiffness; 24: spring damping.
              delay: 0, // Animation delay.
              fill: 'none',
              direction: 'normal',
              iterations: 1, // Animation iteration count.
              begin: 0, // Animation start value.
              end: -length
            });
            this.backAnimator.onFrame = (value) => { // Frame-by-frame callback to update the position.
              this.dragSortCtrl.onMove(item, value); // Handle the list movement and replacement animation.
            };
            this.backAnimator.onFinish = () => {
            };
            this.backAnimator.play(); // Start the animation.
          }
        });
      })
    }
    .padding('4vp').justifyContent(FlexAlign.SpaceEvenly) // 4vp: padding.
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
        List({ space: 20, scroller: this.listScroll }) { // 20: list item spacing.
          ListItemGroup({ header: this.header('first ListItemGroup'), space: 20 }) { // 20: spacing within the list item group.
            ForEach(this.arr, (item: number, index) => {
              if (index < this.firstListItemGroupCount) {
                ListItem() {
                  Text('' + item)
                    .width('100%')
                    .height(100) // 100: list item height.
                    .fontSize(16) // 16: font size.
                    .borderRadius(10) // 10: border radius.
                    .textAlign(TextAlign.Center)
                    .backgroundColor(0xFFFFFF) // 0xFFFFFF: white background.
                }
                .swipeAction({
                  end: this.itemEnd(item, index)
                })
                .clip(true)
                .attributeModifier(this.dragSortCtrl.getModify(item)) // Dynamically set attributes.
                .borderRadius(10) // 10: border radius.
                .margin({ left: 20, right: 20 }) // 20: left and right margins.
              }
            })
          }

          ListItemGroup({ header: this.header('second ListItemGroup'), space: 20 }) { // 20: spacing within the list item group.
            ForEach(this.arr, (item: number, index) => {
              if (index > this.firstListItemGroupCount - 1) { // 1: index offset.
                ListItem() {
                  Text('' + item)
                    .width('100%')
                    .height(100) // 100: list item height.
                    .fontSize(16) // 16: font size.
                    .borderRadius(10) // 10: border radius.
                    .textAlign(TextAlign.Center)
                    .backgroundColor(0xFFFFFF) // 0xFFFFFF: white background.
                }
                .swipeAction({
                  end: this.itemEnd(item, index)
                })
                .clip(true)
                .attributeModifier(this.dragSortCtrl.getModify(item))
                .borderRadius(10) // 10: border radius.
                .margin({ left: 20, right: 20 }) // 20: left and right margins.
              }
            })
          }
        }
        .padding({ top: 20 }) // 20: top padding.
        .height('100%')
      }
    }
    .backgroundColor(0xDCDCDC) // 0xDCDCDC: light gray background.
  }
}
```

![listAnimateDemo](figures/listAnimateDemo.gif)

<!--RP1--><!--RP1End-->