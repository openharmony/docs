# ArkUI子系统Changelog

## cl.arkui.1 TextPicker、Progress、QRCode、TextClock、TextTimer接口支持Resource类型

**访问级别**

公开接口

**变更原因**

基础能力增强，TextPicker、Progress、QRCode、TextClock、TextTimer接口支持Resource类型，可以使用资源对象设置默认选项的值。

**变更影响**

此变更不涉及应用适配。

- 变更前：TextPickerOptions、Progress、QRCode、TextClock、TextTimer中部分接口不支持Resource类型。

- 变更后：TextPickerOptions、Progress、QRCode、TextClock、TextTimer中部分接口支持Resource类型。


**起始API Level**

11

**变更发生版本**

从OpenHarmony SDK 6.0.0.32开始。

**变更的接口/组件**

TextPicker.TextPickerOptions.value、Progress.CapsuleStyleOptions.content、QRCode.value、TextClock.format、TextTimer.fontWeight

**适配指导**

默认行为变更，无需适配。

## cl.arkui.2 width和height支持的matchParent接口规格变更

**访问级别**

公开接口

**变更原因**

接口能力增强，使能Row和Column在设置matchParent时仅适应父组件内容区大小。

**变更影响**

此变更不涉及应用适配。

变更前：Row和Column的子组件matchParent时，会将其大小设置为父组件包含padding、border以及safeAreaPadding后的大小。

变更后：Row和Column的子组件matchParent时，会将其大小设置为父组件不包含padding、border以及safeAreaPadding后的大小，即与父组件内容区大小保持一致。

例如：运行以下示例，进入页面后，观察matchParent的最终结果。

```ts
@Entry
@Component
struct Demo {
  build() {
    Column(){
      Row().width(LayoutPolicy.matchParent).height(LayoutPolicy.matchParent).backgroundColor('rgb(0, 74, 175)')
    }.width(200).height(200).padding(20).backgroundColor('rgb(39, 135, 217)')
  }
}
```

变更前后效果如下:

|变更前|变更后|
|--|--|
|![变更前效果](figures/match_parent_before.jpeg)|![变更后效果](figures/match_parent_after.jpeg)|

**起始API Level**

15

**变更发生版本**

从OpenHarmony SDK 6.0.0.32开始。

**变更的接口/组件**

width(widthValue: Length | LayoutPolicy): T

height(heightValue: Length | LayoutPolicy): T

**适配指导**

默认行为变更，无需适配。

## cl.arkui.3 Badge、Circle、Text、TextArea、TextInput、Search、Span、RichEditor、Rating、Rect、Ellipse、Line、Polyline、Path、Polygon、ProgressButton、SubHeader、SubHeaderV2、Shape、SwipeRefresher接口支持Resource类型

**访问级别**

公开接口

**变更原因**

基础能力增强，Badge、Circle、Text、TextArea、TextInput、Search、Span、RichEditor、Rating、Rect、Ellipse、Line、Polyline、Path、Polygon、ProgressButton、SubHeader、SubHeaderV2、Shape、SwipeRefresher接口支持Resource类型，可以使用资源对象设置默认选项的值。

**变更影响**

- 变更前：Badge、Circle、Text、TextArea、TextInput、Search、Span、RichEditor、Rating、Rect、Ellipse、Line、Polyline、Path、Polygon、ProgressButton、SubHeader、SubHeaderV2、Shape、SwipeRefresher中部分接口不支持Resource类型。

- 变更后：Badge、Circle、Text、TextArea、TextInput、Search、Span、RichEditor、Rating、Rect、Ellipse、Line、Polyline、Path、Polygon、ProgressButton、SubHeader、SubHeaderV2、Shape、SwipeRefresher中部分接口支持Resource类型。


**起始API Level**

11

**变更发生版本**

从OpenHarmony SDK 6.0.0.32开始。

**变更的接口/组件**

Badge.BadgeStyle.fontSize、Badge.BadgeStyle.badgeSize、Badge.BadgeStyle.fontWeight、Badge.BadgeParamWithString.value、Circle.CircleOptions.width、Circle.CircleOptions.height、Text.fontWeight、Text.letterSpacing、Text.baselineOffset、TextArea.fontWeight、TextInput.fontWeight、Search.SearchOptions.value、Search.searchButton、Span.fontWeight、Span.letterSpacing、RichEditor.RichEditorController.addTextSpan.content、Rating.StarStyleOptions.backgroundUri、Rating.StarStyleOptions.foregroundUri、Rating.StarStyleOptions.secondaryUri、Rect.RectOptions.width、Rect.RectOptions.height、Rect.RectOptions.radius、Rect.RoundedRectOptions.width、Rect.RoundedRectOptions.height、Rect.RoundedRectOptions.radiusWidth、Rect.RoundedRectOptions.radiusHeight、Rect.radiusWidth、Rect.radiusHeight、Rect.radius、Ellipse.EllipseOptions.width、Ellipse.EllipseOptions.height、Line.LineOptions.width、Line.LineOptions.height、Polyline.PolylineOptions.width、Polyline.PolylineOptions.height、Path.PathOptions.width、Path.PathOptions.height、Path.PathOptions.commands、Path.commands、Polygon.PolygonOptions.width、Polygon.PolygonOptions.height、ProgressButton.content、SubHeader.SelectOptions.value、SubHeaderV2.SubHeaderV2SelectOptions.selectedContent、SubHeaderV2.SubHeaderV2Select.selectedContent、Shape.ViewportRect.x、Shape.ViewportRect.y、Shape.ViewportRect.width、Shape.ViewportRect.height、Shape.strokeDashOffset、Shape.strokeMiterLimit、Shape.strokeWidth、SwipeRefresher.content

**适配指导**

若有继承派生则需要在继承派生定义处增加Resource类型支持，否则无需适配。