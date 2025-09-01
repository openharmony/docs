# ArkUI子系统Changelog

## cl.arkui.1 文本与输入、信息展示、按钮与选择、滚动与滑动、图形绘制组件接口支持Resource类型

**访问级别**

公开接口

**变更原因**

基础能力增强，文本与输入、信息展示、按钮与选择、滚动与滑动、图形绘制组件的接口支持Resource类型，可以使用资源对象设置默认选项的值。

**变更影响**

此变更涉及应用适配。

- 变更前：TextPickerOptions、Progress、QRCode、TextClock、TextTimer、Badge、Circle、Text、TextArea、TextInput、Search、Span、RichEditor、Rating、Rect、Ellipse、Line、Polyline、Path、Polygon、ProgressButton、SubHeader、SubHeaderV2、Shape、SwipeRefresher中部分接口不支持Resource类型。

- 变更后：TextPickerOptions、Progress、QRCode、TextClock、TextTimer、Badge、Circle、Text、TextArea、TextInput、Search、Span、RichEditor、Rating、Rect、Ellipse、Line、Polyline、Path、Polygon、ProgressButton、SubHeader、SubHeaderV2、Shape、SwipeRefresher中部分接口支持Resource类型。


**起始API Level**

11

**变更发生版本**

从OpenHarmony SDK 6.0.0.32开始。

**变更的接口/组件**

|组件名称|接口名称|参数名称|
|--|--|--|
|TextPicker|TextPickerOptions|value|
|Progress|CapsuleStyleOptions|content|
|TextPicker|TextPickerOptions|value|
|QRCode|QRCodeInterface|value|
|TextClock|format|value|
|TextTimer|fontWeight|value|
|Badge|BadgeStyle|fontSize、badgeSize、fontWeight|
|Badge|BadgeParamWithString|value|
|Circle|CircleOptions|width、height|
|Text|fontWeight|value、weight|
|Text|letterSpacing|value|
|Text|baselineOffset|value|
|TextArea|fontWeight|value|
|TextInput|fontWeight|value|
|Search|SearchOptions|value|
|Search|searchButton|value|
|Span|fontWeight|value|
|Span|letterSpacing|value|
|RichEditor|RichEditorController.addTextSpan|content|
|Rating|StarStyleOptions|backgroundUri、foregroundUri、secondaryUri|
|Rect|RectOptions|width、height、radius|
|Rect|RoundedRectOptions|width、height、radiusWidth、radiusHeight|
|Rect|radiusWidth|value|
|Rect|radiusHeight|value|
|Rect|radius|value|
|Ellipse|EllipseOptions|width、height|
|Line|LineOptions|width、height|
|Polyline|PolylineOptions|width、height|
|Path|PathOptions|width、height、commands|
|Path|commands|value|
|Polygon|PolygonOptions|width、height|
|ProgressButton|-|content|
|SubHeader|SelectOptions|value|
|SubHeaderV2|SubHeaderV2SelectOptions|selectedContent|
|SubHeaderV2|SubHeaderV2Select|selectedContent|
|Shape|ViewportRect|x、y、width、height|
|Shape|strokeDashOffset|value|
|Shape|strokeMiterLimit|value|
|Shape|strokeWidth|value|
|SwipeRefresher|-|content|

**适配指导**

若有继承派生或者读取赋值则需要在定义处增加Resource类型支持，否则无需适配。

```ts
@Entry
@Component
struct Index {
  searchOptions: SearchOptions = { value: '123456'}
  // @State text: string = this.searchOptions.value; //原定义
  @State text: ResourceStr | undefined = this.searchOptions.value; //适配定义
  build() {
    Column() {
      Scroll() {
        Column({ space: 20 }) {
          Search(this.searchOptions)
          Text(this.text)
        }.alignItems(HorizontalAlign.Center).width('100%').margin({ top: 20 })
      }
    }
  }
}
```

## cl.arkui.2 width和height支持的matchParent接口规格变更

**访问级别**

公开接口

**变更原因**

接口能力增强，使能Row和Column在设置matchParent时仅适应父组件内容区大小并且调整constraintSize和matchParent的优先级。

**变更影响**

变更前：Row和Column的子组件matchParent时，会将其大小设置为父组件包含padding、border以及safeAreaPadding后的大小并且不受自身constraintSize的约束。

变更后：Row和Column的子组件matchParent时，会将其大小设置为父组件不包含padding、border以及safeAreaPadding后的大小，即与父组件内容区大小保持一致并且会受到自身constraintSize的约束。

例如：运行以下示例，进入页面后，观察Row组件matchParent的最终结果为父组件内容区大小。

```ts
@Entry
@Component
struct Demo {
  build() {
    Column() {
      Row().width(LayoutPolicy.matchParent).height(LayoutPolicy.matchParent).backgroundColor('rgb(0, 74, 175)')
    }.width(200).height(200).padding(20).backgroundColor('rgb(39, 135, 217)')
  }
}
```

变更前后效果如下:

|变更前|变更后|
|--|--|
|![变更前效果](figures/match_parent_before.jpeg)|![变更后效果](figures/match_parent_after.jpeg)|

再例如：运行以下示例，进入页面后，观察Row组件的子组件matchParent的最终结果会受自身constraintSize约束。

```ts
@Entry
@Component
struct Demo {
  build() {
    Column({ space: 100 }) {
      Row() {
        Stack()
          .width(LayoutPolicy.matchParent)
          .height(LayoutPolicy.matchParent)
          .constraintSize({ maxWidth: 50, maxHeight: 50 })
          .backgroundColor('rgb(0, 74, 175)')
      }.width(200).height(200).backgroundColor('rgb(39, 135, 217)')

      Row() {
        Stack()
          .width(LayoutPolicy.matchParent)
          .height(LayoutPolicy.matchParent)
          .constraintSize({ minWidth: 100, minHeight: 100 })
          .backgroundColor('rgb(0, 74, 175)')
      }.width(50).height(50).backgroundColor('rgb(39, 135, 217)')
    }.width('100%').height('100%')
  }
}
```

变更前后效果如下:

|变更前|变更后|
|--|--|
|![变更前效果](figures/constraintBefore.jpeg)|![变更后效果](figures/constraintAfter.jpeg)|

**起始API Level**

15

**变更发生版本**

从OpenHarmony SDK 6.0.0.32开始。

**变更的接口/组件**

width(widthValue: Length | LayoutPolicy): T

height(heightValue: Length | LayoutPolicy): T

**适配指导**

默认行为变更，若子组件设置matchParent时不需要考虑父组件的padding、border以及safeAreaPadding，建议父组件不设置padding、border以及safeAreaPadding。

## cl.arkui.3 GridRow组件columns参数和GridCol组件span参数默认值变更

**访问级别**

公开接口

**变更原因**

栅格组件默认值原规格容易引发页面压缩问题，变更后提升组件易用性。

**变更影响**

该变更不涉及应用适配。

|               变更前                |              变更后               |
| :---------------------------------: | :-------------------------------: |
|GridRow中columns不配置时，默认值为12。 |GridRow中columns不配置时，columns使用默认值：{ xs: 2, sm: 4, md: 8, lg: 12, xl: 12, xxl: 12 }|
|GridRow中columns配置部分断点时，取已配置的更小断点的columns列数补全未配置的列数。若未配置更小断点的columns列数，取默认值12。 </br> `columns: {xs:2, md:4, lg:8} 等于配置 columns: {xs:2, sm:2, md:4, lg:8, xl:8, xxl:8}` </br> `columns: {md:4, lg:8} 等于配置 columns: {xs:12, sm:12, md:4, lg:8, xl:8, xxl:8}`|GridRow中columns配置部分断点时，取已配置的更小断点的columns列数补全未配置的列数。若未配置更小断点的columns列数，取已配置的更大断点的columns列数补全未配置的列数。</br>`columns: {xs:2, md:4, lg:8} 等于配置 columns: {xs:2, sm:2, md:4, lg:8, xl:8, xxl:8}` </br> `columns: {md:4, lg:8} 等于配置 columns: {xs:4, sm:4, md:4, lg:8, xl:8, xxl:8}`|
|GridCol中span配置部分断点时，取已配置的更小断点的span列数补全未配置的列数。若未配置更小断点的span列数，取默认值1。</br> `span: {xs:2, md:4, lg:8} 等于配置 span: {xs:2, sm:2, md:4, lg:8, xl:8, xxl:8}` </br> `span: {md:4, lg:8} 等于配置 span: {xs:1, sm:1, md:4, lg:8, xl:8, xxl:8}`|GridCol中span配置部分断点时，取已配置的更小断点的span列数补全未配置的列数。若未配置更小断点的span列数，取已配置的更大断点的span列数补全未配置的列数。</br> `span: {xs:2, md:4, lg:8} 等于配置 span: {xs:2, sm:2, md:4, lg:8, xl:8, xxl:8}` </br> `span: {md:4, lg:8} 等于配置 span: {xs:4, sm:4, md:4, lg:8, xl:8, xxl:8}`|

**起始API Level**

9

**变更发生版本**

从OpenHarmony SDK 6.0.0.32开始。

**变更的接口/组件**

GridRow组件、GridCol组件。

**适配指导**

默认行为变更，无需适配，但应注意变更后的默认效果是否符合开发者预期，可手动配置所有不同宽度设备下GridRow组件的栅格列数和GridCol组件所占列数，避免使用默认值或默认补全的布局效果不符合预期。

```ts
@Entry
@Component
struct Example {
  @State bgColors: ResourceColor[] =
    ['rgb(213,213,213)', 'rgb(150,150,150)', 'rgb(0,74,175)', 'rgb(39,135,217)', 'rgb(61,157,180)', 'rgb(23,169,141)',
      'rgb(255,192,0)', 'rgb(170,10,33)'];
  @State currentBp: string = "unknown"

  build() {
    Column() {
      Column() {
        Text(this.currentBp)
        GridRow({
          columns: {
            xs: 2, // 窗口宽度落入xs断点上，栅格栅格容器每一行分为2列。
            sm: 4, // 窗口宽度落入sm断点上，栅格栅格容器每一行分为4列。
            md: 8, // 窗口宽度落入md断点上，栅格栅格容器每一行分为8列。
            lg: 12, // 窗口宽度落入lg断点上，栅格栅格容器每一行分为12列。
            xl: 12, // 窗口宽度落入xl断点上，栅格栅格容器每一行分为12列。
            xxl: 12 // 窗口宽度落入xxl断点上，栅格栅格容器每一行分为12列。
          },
          breakpoints: {
            value: ['320vp', '600vp', '840vp', '1440vp', '1600vp'],
            reference: BreakpointsReference.WindowSize
          }
        }) {
          ForEach(this.bgColors, (color: ResourceColor, index?: number | undefined) => {
            GridCol({
              span: {
                xs: 1, // 窗口宽度落入xs断点上，栅格子容器宽度占1列。
                sm: 2, // 窗口宽度落入sm断点上，栅格子容器宽度占2列。
                md: 4, // 窗口宽度落入md断点上，栅格子容器宽度占4列。
                lg: 6, // 窗口宽度落入lg断点上，栅格子容器宽度占6列。
                xl: 6, // 窗口宽度落入xl断点上，栅格子容器宽度占6列。
                xxl: 6 // 窗口宽度落入xxl断点上，栅格子容器宽度占6列。
              }
            }) {
              Row() {
                Text(`${index}`)
              }.width("100%").height('50vp')
            }.backgroundColor(color)
          })
        }
        .onBreakpointChange((breakpoint) => {
          this.currentBp = breakpoint
        })
      }.width('90%')
    }.width('100%')
  }
}
```
## cl.arkui.4 UI Input相关NDK接口行为变更

**访问级别**

公开接口

**变更原因**

修复相关接口在如下场景下的返回值异常问题，以确保开发者能够获取正确的结果：

- 鼠标滚轮或触控板双指滑动；
- 通过Enter键触发点击或单指轻触手势；
- 使用外设键盘等设备与焦点窗口交互；
- 组件节点接收按键事件；
- 为XComponent组件注册自定义事件拦截回调后进行触摸测试；
- 绑定组件接收轴事件；
- 为XComponent组件注册UI输入事件回调后接收UI输入事件。

**变更影响**

此变更涉及应用适配。

变更前与变更后的变化说明：
| 接口名称                                                      | 起始版本 | 说明                                                     | 变更原因                                                     | 变更影响                                                     |
| ------------------------------------------------------------- | -------- | -------------------------------------------------------- | ------------------------------------------------------ | ------------------------------------------------------------ |
| int32_t<br> OH_ArkUI_UIInputEvent_GetType(const ArkUI_UIInputEvent* event); | 12        | 获取该裸事件对应的枚举类型ArkUI_UIInputEvent_Type，变更前包括触控、轴、鼠标这几种裸事件 | 遗漏支持key事件类型                                          | 当传入的参数为key事件时，获取的类型为0，修复后可获取正确值(ARKUI_UIINPUTEVENT_TYPE_KEY)。 |
| int32_t<br> OH_ArkUI_UIInputEvent_GetAction(const ArkUI_UIInputEvent* event); | 12        | 获取裸事件对应的事件action类型，例如，如果裸事件为触控事件，则获取到的事件action类型为DOWN、MOVE、UP、CANCEL之一；若裸事件类型为鼠标事件，则为PRESS、RELEASE、MOVE、CANCEL之一；若为轴事件，则为BEGIN、UPDATE、END、CANCEL之一。因此，action类型的定义和含义存在差异，但在接口设计上，将返回值统一为int类型，以消除这些差异。 | 遗漏支持axis事件类型                                          | 当传入的参数为axis事件时，获取的类型为0，修复后可获取正确值（BEGIN/UPDATE/END/CANCEL）。 |
| int32_t<br> OH_ArkUI_UIInputEvent_GetDeviceId(const ArkUI_UIInputEvent* event); | 14        | 获取当前输入事件的触发设备ID                                 |  实现遗漏通过键盘Enter键触发的click事件场景。 | 1. 仅TAB键走焦场景有可能触发该场景；<br>2.变更前应用无法获取正确的当前输入事件的触发设备ID，修复后可获取正确的当前输入事件的触发设备ID。 |

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony 6.0.0.32版本开始。

**变更的接口/组件**

int32_t OH_ArkUI_UIInputEvent_GetType(const ArkUI_UIInputEvent* event);<br>
int32_t OH_ArkUI_UIInputEvent_GetAction(const ArkUI_UIInputEvent* event);<br>
int32_t OH_ArkUI_UIInputEvent_GetDeviceId(const ArkUI_UIInputEvent* event);<br>

**适配指导**

变更前的接口遗漏对部分事件的支持，导致输入这些事件时会返回默认值，与预期不符；修复后的接口已支持这些遗漏的事件，调用时可获取正确的返回值。应用如果使用接口的返回值，需做出相应的适配。

## cl.arkui.5 使用字面量初始化CustomDialogController类实例导致的编译行为变更

**访问级别**

公开接口

**变更原因**

在类CustomDialogController中新增接口getState()获取对应弹窗的状态。当原先使用字面量的方式初始化CustomDialogController实例时，会编译报错。字面量的初始化方式是指采用"{}"直接初始化类的实例，例如：
```typescript
let controller: CustomDialogController = { open() {}, close() {} }
```

**变更影响**

此变更涉及应用适配，使用字面量初始化CustomDialogController类实例时涉及。
变更前：开发者可以通过字面量的方式初始化CustomDialogController，如：

```typescript
let controller: CustomDialogController = { open() {}, close() {} }
```

变更后：由于在CustomDialogController中新增了getState()方法，变更前的上述写法未初始化新增的getState()方法，会编译报错。

**起始API Level**

不涉及

**变更发生版本**

从OpenHarmony 6.0.0.32版本开始。

**变更的接口/组件**

编译行为，不涉及接口

**适配指导**

开发者应修改为使用new的方式创建类的实例，如：

```typescript
let controller: CustomDialogController = new CustomDialogController()
```

