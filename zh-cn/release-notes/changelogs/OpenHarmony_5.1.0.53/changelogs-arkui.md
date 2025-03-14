# ArkUI子系统Changelog

## cl.arkui.1 Progress组件动态改变宽高时，内容区宽高变更

**访问级别**

公开接口

**变更原因**

容器宽高改变，Progress组件内容区未能实时触发刷新，需要更新别的属性后宽高才会改变。

**变更影响**

此变更无需应用适配。

| 变更前                                                                                                                                                        | 变更后                                                                                                                |
| ------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------- |
| 当容器的宽度或高度发生变化时，Progress组件的内容区域未能实时更新。需要更改其他属性后，其尺寸才会相应调整。<br>![progress_before](figures/progress_before.png) | 当容器的宽高发生变化时，Progress组件的内容区域宽高也会随之相应调整。<br>![progress_after](figures/progress_after.png) |

**起始API Level**

9

**变更发生版本**

从OpenHarmony 5.1.0.53 版本开始。

**变更的接口/组件**

Progress。

**适配指导**

展示效果变更，无需适配，但应注意变更后的效果是否符合开发者预期。

## cl.arkui.2 无障碍绿框绘制区域和聚焦区域修改为组件触摸热区

**访问级别**

公开接口

**变更原因**

无论是否开启无障碍，触碰操作控件的范围都应保持一致，无需为无障碍单独定义操控范围。

**变更影响**

此变更不涉及应用适配。

- 变更前：无障碍绿框绘制区域、聚焦区域为组件区域。

- 变更后：无障碍绿框绘制区域、聚焦区域为组件触摸热区。

**起始API Level**

16

**变更发生版本**

从OpenHarmony SDK 5.1.0.53开始。

**变更的接口/组件**

arkui无障碍

**适配指导**

此处无需应用适配，热区显示大小的调整，无论是否配置热区，均为内部逻辑调整绿框显示位置或大小。

## cl.arkui.3 拖拽缩放比例UX规则变更

**访问级别**

公开接口

**变更原因**

UX规范变更。

**变更影响**

此变更不涉及应用适配。

变更前：通过设备栅格数来设置跟手图的大小。

  | 设备大小 | 跟手图大小 |
  | :------- | :--------- |
  | 4栅格    | 2栅格      |
  | 8栅格    | 3栅格      |
  | 12栅格   | 4栅格      |

变更后：根据不同类型设备的最短边来设置缩放规则。

| 拖拽对象         | 判断规则                          | 缩放规则                                                                                                                               |
| :--------------- | :-------------------------------- | :------------------------------------------------------------------------------------------------------------------------------------- |
| 图文选择跟随文本 | 设备最短边小于600vp。             | 跟手图最大高度不超过屏幕短边长度的1/2且最大宽度不超过屏幕短边长度，跟手图在超出限制时需按比例缩小，同时满足高度和宽度的限制条件。      |
| 图文选择跟随文本 | 设备最短边大于600vp，小于840vp。  | 跟手图最大高度不超过屏幕短边长度的1/4且最大宽度不超过屏幕短边长度的1/2，跟手图在超出限制时需按比例缩小，同时满足高度和宽度的限制条件。 |
| 图文选择跟随文本 | 设备最短边大于840vp，小于1440vp。 | 跟手图最大高度不超过屏幕短边长度的1/3且最大宽度不超过屏幕短边长度的2/3，跟手图在超出限制时需按比例缩小，同时满足高度和宽度的限制条件。 |
| 图文选择跟随文本 | 设备最短边大于1440vp。            | 跟手图最大高度不超过屏幕短边长度的1/3且最大宽度不超过屏幕短边长度的2/3，跟手图在超出限制时需按比例缩小，同时满足高度和宽度的限制条件。 |
| 图片拖拽缩放     | 设备最短边小于600vp。             | 跟手图最大高度不超过屏幕短边长度的1/2且最大宽度不超过屏幕短边长度的1/2，跟手图在超出限制时需按比例缩小，同时满足高度和宽度的限制条件。 |
| 图片拖拽缩放     | 设备最短边大于600vp，小于840vp。  | 跟手图最大高度不超过屏幕短边长度的1/4且最大宽度不超过屏幕短边长度的1/4，跟手图在超出限制时需按比例缩小，同时满足高度和宽度的限制条件。 |
| 图片拖拽缩放     | 设备最短边大于840vp，小于1440vp。 | 跟手图最大高度不超过屏幕短边长度的1/3且最大宽度不超过屏幕短边长度的1/3，跟手图在超出限制时需按比例缩小，同时满足高度和宽度的限制条件。 |
| 图片拖拽缩放     | 设备最短边大于1440vp。            | 跟手图最大高度不超过屏幕短边长度的1/3且最大宽度不超过屏幕短边长度的1/3，跟手图在超出限制时需按比例缩小，同时满足高度和宽度的限制条件。 |

**起始API Level**

13

**变更发生版本**

从OpenHarmony SDK 5.1.0.53开始。

**变更的接口/组件**

UX规格变更，不涉及接口和组件。

**适配指导**

默认行为变更，无需适配。

## cl.arkui.4 在使用手写笔操作时，应用从onTouch回调中获取到的TouchEvent，其中touches数组内的TouchObject的id值发生变更。

**访问级别**

公开接口

**变更原因**

在手写笔场景下，TouchEvent中changedTouches数组内的TouchObject的id，与touches数组内的TouchObject的id不一致。

**变更影响**

此变更不涉及应用适配。

- 变更前：在使用手写笔操作时，应用在onTouch回调中获取到的TouchEvent中，touches数组中TouchObject的id和changedTouches中的TouchObject的id不一致。
  
- 变更后：在使用手写笔操作时，应用在onTouch回调中获取到的TouchEvent中，touches数组中TouchObject的id和changedTouches中的TouchObject的id保持一致。

**起始API Level**

7

**变更发生版本**

从OpenHarmony SDK 5.1.0.53开始。

**变更的接口/组件**

| 文件               | 接口                                       |
| ------------------ | ------------------------------------------ |
| common.d.ts        | onTouch回调中的TouchEvent                  |
| common.d.ts        | onTouchIntercept回调中的TouchEvent         |

**适配指导**

默认行为变更，应用无需适配。

## cl.arkui.5 tablet和2in1设备的onPageHide和onHidden生命周期函数变更

**访问级别**

公开接口

**变更原因**

优化tablet和2in1设备的onPageHide和onHidden生命周期函数，确保函数内部修改状态变量时能够触发页面刷新，也能够触发状态变量的监听函数。

**变更影响**

此变更涉及应用适配。

- 变更前：
  1. 在onPageHide/onHidden中修改状态变量可能不会触发对应的监听函数，示例如下：
     ```ts
     @Component
     struct TestComponent {
       @Prop @Watch('onPageVisibilityChange') isPageShow: boolean;
       onPageVisibilityChange(): void {
         // 期望状态变量的修改会触发当前函数，实际不一定会触发。
         console.log(`onPageVisibilityChange ${this.isPageShow}`)
       }
       build() {
         Text('test')
       }
     }
     @Component
     struct DestA {
       @State isPageShow: boolean = false;
       build() {
         NavDestination() {
           Stack() {
             TestComponent({isPageShow: this.isPageShow})
           }
         }.onShown(() => {
           this.isPageShow = true;
         })
         .onHidden(() => {
           // 退后台时会触发该生命周期，进一步改变状态变量
           this.isPageShow = false;
         })
       }
     }
     @Entry
     @Component
     struct TestPage {
       private stack: NavPathStack = new NavPathStack();
       aboutToAppear(): void {
         this.stack.pushPath({name: 'page'})
       }
       @Builder
       MyPageMap(name: string) {
         DestA()
       }
       build() {
         Navigation(this.stack) {
         }.hideNavBar(true)
         .navDestination(this.MyPageMap)
       }
     }
     ```
  2. 在onPageHide/onHidden中修改状态变量可能不会刷新页面，示例如下：
     ```ts
     @Component
     struct TestComponent {
       build() {
         Text('test1')
       }
       aboutToDisappear(): void {
         console.log(`TestComponent aboutToDisappear`)
       }
     }
     @Entry
     @Component
     struct TestPage {
       @State isPageShow: boolean = true;
       build() {
         // 期望状态变量的修改会导致TestComponent会被销毁，实际不一定会被销毁。
         if (this.isPageShow) {
           TestComponent()
         } else {
           Text('test2')
         }
       }
       onPageShow(): void {
         this.isPageShow = true;
       }
       onPageHide(): void {
         // 退后台时会触发该生命周期，进一步改变状态变量
         this.isPageShow = false;
       }
     }
     ```

- 变更后：
  1. 在onPageHide/onHidden中修改状态变量能够触发对应的监听函数；
  2. 在onPageHide/onHidden中修改状态变量能够刷新页面。

**起始API Level**

onPageHide：API version 7，onHidden：API version 10

**变更发生版本**

从OpenHarmony SDK 5.1.0.53开始。

**变更发生的接口/组件**

[onPageHide](../../../application-dev/reference/apis-arkui/arkui-ts/ts-custom-component-lifecycle.md#onpagehide)，所在文件：api/@internal/component/ets/common.d.ts；[onHidden](../../../application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-navdestination.md#onhidden10)，所在文件：api/@internal/component/ets/nav_destination.d.ts。

**适配指导**

仅**tablet**和**2ni1**设备需要做以下适配：
检查是否在onPageHide/onHidden生命周期函数中修改状态变量，本次变更之后能够保证触发页面刷新，触发监听函数。

## cl.arkui.7 TEXTURE模式XComponent的本地窗口缓冲区支持设置旋转变换

**访问级别**

公开接口

**变更原因**

TEXTURE模式XComponent的本地窗口缓冲区旋转变换在设置后不生效，导致开发者无法通过设置缓冲区旋转变换来调整显示画面的旋转方向。

**变更影响**

此变更涉及应用适配。

变更前：
设置TEXTURE模式XComponent的本地窗口缓冲区旋转变换后，旋转变换在实际显示的画面中不生效。

变更后：
设置TEXTURE模式XComponent的本地窗口缓冲区旋转变换后，旋转变换在实际显示的画面中生效。

| 写入缓冲区的原始图像 | 变更前设置了缓冲区逆时针旋转90度后的实际显示画面 | 变更后设置了缓冲区逆时针旋转90度后的实际显示画面 |
| --------- | --------- | --------- |
|![原始图片](figures/XComponentBufferImage.PNG)|![变更前](figures/XComponentBufferTransform_before.PNG)       |![变更后](figures/XComponentBufferTransform_after.PNG)  |

**起始API Level**

API 10

**变更发生版本**

从OpenHarmony SDK 5.1.0.53开始。

**变更的接口/组件**

ArkUI 内置组件XComponent。

**适配指导**

变更后，设置TEXTURE模式XComponent的本地窗口缓冲区旋转变换后，XComponent显示的内容将根据设置进行旋转。
如开发者原先设置过TEXTURE模式XComponent的本地窗口缓冲区旋转变换，为避免显示内容旋转，
应将原先设置本地窗口缓冲区旋转变换的相关调用语句去除。
```
OHNativeWindow* window;
// 利用XComponent的surfaceId获取本地窗口
OH_NativeWindow_CreateNativeWindowFromSurfaceId(surfaceId, &window);

// ......

// 应去除此处设置本地窗口缓冲区逆时针旋转90度的调用
OH_NativeWindow_NativeWindowHandleOpt(nativeWindow, SET_TRANSFORM, NATIVEBUFFER_ROTATE_90);

// ......
```

## cl.arkui.8 Toast和Popup/Menu同时存在时，点击Toast子窗不再关闭Popup/Menu

**访问级别**

公开接口

**变更原因**

子窗口中显示Popup/Menu，弹出与其有相同父窗口的Toast时，Toast窗口上的点击事件会关闭Popup/Menu。

**变更影响**

此变更不涉及应用适配。

变更前：点击Toast窗口时，会主动关闭与其有相同父窗口的Popup/Menu。

变更后：点击Toast窗口时，不再主动关闭与其有相同父窗口的Popup/Menu。


**起始API Level**

API 9

**变更发生版本**

从OpenHarmony SDK 5.1.0.53开始。

**变更的接口/组件**

不涉及。

**适配指导**

默认行为变更，无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响。

## cl.arkui.9 按钮默认值变更为新增圆角矩形类型

**访问级别**

公开接口

**变更原因**

原有默认类型按钮是胶囊按钮，在适老化场景下字体过大，在多行等场景下胶囊按钮文字易超出其圆角范围。不符合简单易用及高端精致原则，因此新增圆角矩形类型按钮，默认值变为新增的圆角矩形类型。

**变更影响**

此变更不涉及应用适配。

变更前：ButtonOptions中type的默认值为ButtonType.Capsule。

变更后：ButtonOptions中type的默认值为ButtonType.ROUNDED_RECTANGLE

![roundedRectButton](figures/roundedRectButton.PNG)

**起始API Level**

API 9

**变更发生版本**

从OpenHarmony SDK 5.1.0.53开始。

**变更的接口/组件**

Button组件中ButtonOptions对象的type属性默认值。

**适配指导**

开发者在使用Button组件，创建默认类型的Button按钮时，Button按钮为ROUNDED_RECTANGLE类型。

```ts

@Entry
@Component
struct ButtonExample {
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceBetween }) {
      Text('Capsule button with rounded corners by default.').fontSize(9).fontColor(0xCCCCCC)
      Flex({ alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
        Button('Capsule')
          .type(ButtonType.Capsule)
          .backgroundColor(0x317aff)
          .height(60)
          .controlSize(ControlSize.NORMAL)
          .width(180)
      }
      Text('Rounded rectangle button with rounded corners by default.').fontSize(9).fontColor(0xCCCCCC)
      Flex({ alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
        Button('Rounded rectangle')
          .type(ButtonType.ROUNDED_RECTANGLE)
          .backgroundColor(0x317aff)
          .controlSize(ControlSize.NORMAL)
          .height(60)
          .width(180)
      }
    }.height(400).padding({ left: 35, right: 35, top: 35 })
  }
}

```

## cl.arkui.10 enabled属性UX样式变更

**访问级别**

公开接口

**变更原因**

Rating组件与Slider组件enabled属性UX样式不符合规范

**变更影响**

此变更不涉及应用适配。

Rating组件变更场景：

| 变更前 | 变更后 |
|------ |--------|
|Rating组件设置enable为false时，未叠加40%透明度。</br>![rating_enable](figures/rating_enable.PNG)|Rating组件设置enable为false时，叠加40%透明度。</br>![rating_enable_opacity](figures/rating_enable_opacity.PNG)|

Slider组件变更场景：

| 变更前 | 变更后 |
|------ |--------|
|Slider组件设置enable为false时，未叠加40%透明度。</br>![slider_enable](figures/slider_enable.PNG)|Slider组件设置enable为false时，叠加40%透明度。</br>![slider_enable_opacity](figures/slider_enable_opacity.PNG)|

**起始API Level**

7

**变更发生版本**

从OpenHarmony 5.1.0.53 版本开始。

**变更的接口/组件**

通用属性enabled属性。

**适配指导**

默认行为变更，无需适配。

## cl.arkui.11 修复Popup高级组件宽度限制计算错误的问题

**访问级别**

公开接口

**变更原因**

目前宽度最大限制不符合ux规范，在手机屏幕场景下，会出现Popup高级组件无法撑满屏幕的情况，影响体验。

**变更影响**

此变更不涉及应用适配。

变更前：屏幕宽度小于400vp时，Popup高级组件最大宽度为当前屏幕宽度-80vp。

变更后：屏幕宽度小于400vp时，Popup高级组件最大宽度为当前屏幕宽度。

| 变更前                                   | 变更后                                   |
| ---------------------------------------- | ---------------------------------------- |
| ![popup_before](figures/popup_before.png) | ![popup_after](figures/popup_after.png) |

**起始API Level**

11

**变更发生版本**

从OpenHarmony 5.1.0.53 版本开始。

**变更的接口/组件**

Popup高级组件。

**适配指导**

如果用户原来没有自定义Popup高级组件的宽度，且内容宽度大于320vp，变更前按320vp显示，变更后，Popup高级组件会变宽；如不符合预期，可以手动修改为想要的宽度。
