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