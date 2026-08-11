# 路径动画 (motionPath)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

设置组件进行路径动画时的运动路径。

>  **说明：**
>
> 从API version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## motionPath
motionPath(value: MotionPathOptions): T

设置组件进行路径动画时的运动路径。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名    | 类型                                | 必填 | 说明                                    |
| ----- | --------------------------------- | ---- | ------------------------------------- |
| value | [MotionPathOptions](#motionpathoptions) | 是    | 设置组件进行路径动画时的运动路径。             |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回当前组件，用于链式调用。 |

## MotionPathOptions

路径动画的运动路径参数选项。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | ---- | ---- | -------- |
| path | string | 否 | 否 | 位移动画的运动路径，使用[svg路径](ts-drawing-components-path.md#svg路径描述规范)。path中支持使用start和end进行起点和终点的替代，如：'Mstart.x&nbsp;start.y&nbsp;L50&nbsp;50&nbsp;Lend.x&nbsp;end.y&nbsp;Z'，更多说明请参考[绘制路径](../../../ui/ui-js-components-svg-path.md)。<br>设置为空字符串时相当于不设置路径动画，传入不符合SVG路径规范的字符串时路径动画不生效。 |
| from | number | 否 | 是 | 运动路径的起点位置比例。<br>默认值：0.0<br>取值范围：[0.0, 1.0]<br>设置小于0.0或大于1.0的值时，按默认值0.0处理。<br>from的处理值会约束to的取值，需满足to值 >= from的处理值。当from等于to时（无论是开发者主动设置还是因超出范围被修正），组件在路径上不产生位移。 |
| to | number | 否 | 是 | 运动路径的终止位置比例。<br>取值原则：数值表示路径上的比例位置，0.0为路径起点，1.0为路径终点，中间值为路径上的对应比例位置。<br>默认值：1.0<br>取值范围：[0.0, 1.0]<br>设置小于0.0或大于1.0的值时，按默认值1.0处理，且满足to值 >= 异常值处理后的from值。当处理后的to值小于异常值处理后的from值时，to值会被修正为等于异常值处理后的from值，即to被向上修正至与from相同。当from等于to时（无论是开发者主动设置还是因超出范围被修正），组件在路径上不产生位移。 |
| rotatable | boolean | 否 | 是 | 是否跟随路径进行旋转。true代表组件沿运动方向自动旋转（旋转角度由路径切线方向决定），false代表不跟随路径进行旋转。<br>默认值：false |


## 示例

该示例主要演示如何设置组件进行位移动画时的运动路径。此方法仅配置运动路径参数，需配合animateTo等动画触发方法及组件属性状态变化才能产生实际的位移动画效果，单独设置motionPath不会触发动画。

```ts
// xxx.ets
@Entry
@Component
struct MotionPathExample {
  @State toggle: boolean = true;

  build() {
    Column() {
      Button('click me').margin(50)
        .motionPath({
          path: 'Mstart.x start.y L300 200 L300 500 Lend.x end.y',
          from: 0.0,
          to: 1.0,
          rotatable: true
        }) // 设置运动路径：从起点经(300,200)、(300,500)到终点
        .onClick(() => {
          this.getUIContext()?.animateTo({ duration: 4000, curve: Curve.Linear }, () => {
            this.toggle = !this.toggle; // 通过this.toggle变化组件的位置
          });
        })
    }.width('100%').height('100%').alignItems(this.toggle ? HorizontalAlign.Start : HorizontalAlign.Center)
  }
}
```

![motionPath](figures/motionPath.gif)
