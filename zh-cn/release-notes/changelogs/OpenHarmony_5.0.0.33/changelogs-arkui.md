# ArkUI子系统Changelog

## cl.arkui.1 Navigation分割线触摸直接响应

**访问级别**

公开接口

**变更原因**

手指触摸Navigation分割线后可立即响应分割线的滑动。

**变更影响**

该变更为不兼容性变更。

API version 11及以前：手指需长按500ms，Navigation的分割线才可响应滑动。

API version 12及以后：手指触摸Navigation的分割线可立即响应滑动。

**起始API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.0.0.33开始。

**适配指导**

默认行为变更，无需适配。

## cl.arkui.2 RichEditor的lineHeight、letterSpacing、lineSpacing属性返回值单位变更

**访问级别**

公开接口

**变更原因**

文本字体相关属性的返回值单位应默认使用fp类型。

**变更影响**

该变更为不兼容变更。

API version 11及以前：lineHeight、letterSpacing、 lineSpacing属性的返回值单位是vp。

API version 12及以后：lineHeight、letterSpacing、 lineSpacing属性的返回值单位从vp变更为fp，若开发者原来将返回值按vp单位处理，变更后该处理逻辑会导致数据错误。

**起始 API Level**

10

**变更发生版本**

从OpenHarmony SDK 5.0.0.33 版本开始。

**变更的接口/组件**

RichEditor组件，lineHeight、letterSpacing、lineSpacing属性。

**适配指导**

默认效果变更，开发者需通过[像素单位转换接口](../../../application-dev/reference/apis-arkui/arkui-ts/ts-pixel-units.md#像素单位转换)，对返回值进行正确处理。

## cl.arkui.3 RichEditor的fontSize属性的返回值单位变更

**访问级别**

公开接口

**变更原因**

文本字体相关属性的返回值单位应默认使用fp类型。

**变更影响**

该变更为不兼容变更。 

API version 11及以前：fontSize属性的返回值单位是vp。

API version 12及以后：fontSize属性的返回值单位从vp变更为fp，若开发者原来将返回值按vp单位处理，变更后该处理逻辑会导致数据错误。

**起始 API Level**

10

**变更发生版本**

从OpenHarmony SDK 5.0.0.33 版本开始。

**变更的接口/组件**

RichEditor组件，fontSize属性。

**适配指导**

默认效果变更，开发者需通过[像素单位转换接口](../../../application-dev/reference/apis-arkui/arkui-ts/ts-pixel-units.md#像素单位转换)，对返回值进行正确处理。

## cl.arkui.4 BindContextMenu上下文菜单内容可滚动时快滑不再关闭菜单

**访问级别**

公开接口

**变更原因**

上下文菜单内容可滚动时，快滑关闭菜单与快滑滚动内容交互冲突，影响用户体验。

**变更影响**

该变更为不兼容变更。

变更前：上下文菜单内容可滚动时，快滑时关闭菜单。

变更后：上下文菜单内容可滚动时，快滑时不再关闭菜单。

**起始API Level**

8

**变更发生版本**

从OpenHarmony SDK 5.0.0.33开始。

**变更的接口/组件**

Menu组件的BindContextMenu接口

**适配指导**

默认行为变更，无需适配。

## cl.arkui.5 Repeat接口RepeatItem参数index可选改为必选

**访问级别**

公开接口

**变更原因**

为了提升Repeat使用的易用性，在该组件的实现上，进行了优化处理。对其接口RepeatItem所需要的index参数从非必填优化为了必填，这样开发者在使用index参数的时候，无需对index参数进行判空处理。

**变更影响**

该变更为兼容性变更。兼容应用已写代码，无需应用修改代码。

**起始API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.33开始。

**变更的接口/组件**

Repeat组件，RepeatItem接口的index参数。

**适配指导**

适配已开发的代码，新开发的代码无需对index做判空处理。

变更前：

```ts
@Entry
@ComponentV2
struct RepeatTest {
  @Local arr: Array<number> = [0, 1, 2, 3]

  build() {
    List({ space: 3 }) {
      Repeat(this.arr)
        .virtualScroll()
        .key((item) => item.toString())
        .each((repeatItem) => {
          ListItem() {
            Text(`${repeatItem.index! + 1}. Item ${repeatItem.item}`) // repeatItem.index需做判空处理
              .height(50).backgroundColor(Color.Blue)
          }.backgroundColor(Color.Green)
        })

    }.height(200).backgroundColor(Color.Red)
  }
}
```

变更后：

```ts
@Entry
@ComponentV2
struct RepeatTest {
  @Local arr: Array<number> = [0, 1, 2, 3]

  build() {
    List({ space: 3 }) {
      Repeat(this.arr)
        .virtualScroll()
        .key((item) => item.toString())
        .each((repeatItem) => {
          ListItem() {
            Text(`${repeatItem.index + 1}. Item ${repeatItem.item}`) // repeatItem.index可不做判空处理
              .height(50).backgroundColor(Color.Blue)
          }.backgroundColor(Color.Green)
        })

    }.height(200).backgroundColor(Color.Red)
  }
}
```