# ArkUI子系统Changelog


## cl.arkui.1 width和height支持的matchParent接口规格变更

**访问级别**

公开接口

**变更原因**

修正接口规格，保证接口与竞品保持一致。

**变更影响**

此变更不涉及应用适配。

变更前：线性容器子组件matchParent时，会将其大小设置为父组件包含padding、border以及safeAreaPadding后的大小。

变更后：线性容器子组件matchParent时，会将其大小设置为父组件不包含padding、border以及safeAreaPadding后的大小，即与父组件内容区大小保持一致。

eg. 运行下面的Demo示例，进入页面后，观察matchParent的最终结果。

```ts
@Entry
@Component
struct Demo {
  build() {
    Column(){
      Row().width(LayoutPolicy.matchParent).height(LayoutPolicy.matchParent).backgroundColor(Color.Blue)
    }.width(200).height(200).padding(20).backgroundColor(Color.Yellow)
  }
}
```

变更前后效果如下:

|变更前|变更后|
|--|--|
|![变更前效果](figures/match_parent_before.png)|![变更后效果](figures/match_parent_after.png)|

**起始API Level**

API 15

**变更发生版本**

从OpenHarmony SDK 6.0.0.32开始

**变更的接口/组件**

width(widthValue: Length | LayoutPolicy): T
height(heightValue: Length | LayoutPolicy): T

**适配指导**

默认行为变更，无需适配。