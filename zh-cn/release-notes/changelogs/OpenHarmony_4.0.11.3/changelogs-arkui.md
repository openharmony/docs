# arkui子系统ChangeLog

## cl.arkui.1 button组件对fontSize设置为负数（即异常值）时的处理规则进行细化，保证取值合理性。

**变更影响**

变更前，开发者设置负数时，fontSize为开发者设置的负数值，即最终效果与fontSize=0的效果一致，文字内容不显示<br>
变更后，开发者设置负数时，fontSize为默认值16fp。<br>
说明：fontSize=0的效果未变更，都是文字不显示的效果，以上变更仅涉及开发者设置fontSize<0的异常场景

## cl.arkui.2 Search组件动态改变属性时，输入框内容变化情况变更，保证输入框内容的正确性。

**变更影响**

变更前，开发者在Search组件接口中只设置placeholder不设置value时，动态改变Search的属性，Search中的内容会被清空。<br>
变更后，开发者在Search组件接口中只设置placeholder不设置value时，动态改变Search的属性，Search中的内容会保持不变。
说明：变更后为正常使用search的期望行为。

## cl.arkui.3 Menu组件宽度规格变更

[Menu](../../../application-dev/reference/arkui-ts/ts-basic-components-menu.md)宽度规格变更，未设置宽度时，按默认2栅格显示；设置宽度时，Menu内容根据设置的宽度进行自适应布局。Menu组件自带默认64vp的最小宽度。

**变更影响**

1. Menu宽度默认2栅格显示，若菜单项[MenuItem](../../../application-dev/reference/arkui-ts/ts-basic-components-menuitem.md)内容区比2栅格宽，则会自适应撑开。
2. 最小宽度64vp。开发者可通过[constraintSize](../../../application-dev/reference/arkui-ts/ts-universal-attributes-size.md)属性修改最小宽度限制。

**关键接口/组件变更**

- [Menu组件](../../../application-dev/reference/arkui-ts/ts-basic-components-menu.md)

**适配指导**

若开发者期望菜单显示宽度小于64vp或无最小宽度限制，修改constraintSize覆盖默认的最小宽度。

**示例：**
```ts
@Entry
@Component
struct Index {
  @Builder
  MyMenu(){
    Menu() {
      MenuItem({ startIcon: $r("app.media.icon"), content: "菜单选项" })
    }
    .width(30)
    .constraintSize({minWidth: 0})  // 覆盖系统默认的64vp最小宽度
  }

  build() {
    Row() {
      Column() {
        Text('click to show menu')
      }
      .bindMenu(this.MyMenu)
      .width('100%')
    }
    .height('100%')
  }
}
```

## cl.arkui.4 springCurve速度方向规格变更

**变更影响**

在API version 9，[springCurve](../../../application-dev/reference/apis/js-apis-curve.md#curvesspringcurve9)的[interpolate](../../../application-dev/reference/apis/js-apis-curve.md#interpolate9)方法在计算时，springCurve的初速度>0为逆着终点方向，初速度<0为顺着终点方向。<br/>
从API version 10起，springCurve的interpolate方法在计算时，springCurve的初速度>0为顺着终点方向，初速度<0为逆着终点方向。会导致初速度不为0时springCurve的interpolate方法和API version 10之前的计算结果不一致。

## cl.arkui.5 springCurve实际曲线时间估算阈值规格变更

**变更影响**

在API version 9，[springCurve](../../../application-dev/reference/apis/js-apis-curve.md#curvesspringcurve9)的[interpolate](../../../application-dev/reference/apis/js-apis-curve.md#interpolate9)方法对springCurve实际曲线时长的最长估算时间为1秒，当物理曲线时长超过1秒时，按1秒估算，导致超过1秒的springCurve的动画时间归一化不正确，插值结果在t=1时会跳变。<br/>
从API version 10起，springCurve的interpolate方法对springCurve的最长估算时间为1000秒，对于绝大多数正常springCurve曲线均能正确估算动画时长。会导致物理曲线本身时长超过1秒的springCurve的interpolate方法和API version 10之前的计算结果不一致。
