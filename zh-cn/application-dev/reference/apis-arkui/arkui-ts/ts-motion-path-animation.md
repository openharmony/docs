# 路径动画 (motionPath) 

设置组件进行位移动画时的运动路径。

>  **说明：**
>
> 从API version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## motionPath
motionPath(value: MotionPathOptions): T

设置组件的路径动画。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名    | 类型                                | 必填 | 说明                                    |
| ----- | --------------------------------- | ---- | ------------------------------------- |
| value | [MotionPathOptions](#motionpathoptions) | 是    | 设置组件的运动路径。             |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回当前组件。 |

## MotionPathOptions

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | ---- | ---- | -------- |
| path                         | string                     | 否 | 否  | 位移动画的运动路径，使用svg路径字符串。path中支持使用start和end进行起点和终点的替代，如：'Mstart.x&nbsp;start.y&nbsp;L50&nbsp;50&nbsp;Lend.x&nbsp;end.y&nbsp;Z'，更多说明请参考[绘制路径](../../../ui/ui-js-components-svg-path.md)。<br/>设置为空字符串时相当于不设置路径动画。       |
| from                         | number                     | 否 | 是   | 运动路径的起点。<br/>默认值：0.0<br/>取值范围：[0, 1]<br/>设置小于0或大于1的值时，按默认值0处理。   |
| to                           | number                     | 否 |  是  | 运动路径的终点。<br/>默认值：1.0<br/>取值范围：[0, 1]<br/>设置小于0或大于1的值时，按默认值1处理，且满足to值 >= 异常值处理后的from值。   |
| rotatable                     | boolean                    | 否 | 是   | 是否跟随路径进行旋转。true代表跟随路径进行旋转，false代表不跟随路径进行旋转。<br/>默认值：false   |


## 示例

该示例主要演示如何设置组件进行位移动画时的运动路径。

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
        }) // 执行动画：从起点移动到(300,200)，再到(300,500)，再到终点
        .onClick(() => {
          this.getUIContext()?.animateTo({ duration: 4000, curve: Curve.Linear }, () => {
            this.toggle = !this.toggle; // 通过this.toggle变化组件的位置
          });
        })
    }.width('100%').height('100%').alignItems(this.toggle ? HorizontalAlign.Start : HorizontalAlign.Center)
  }
}
```

![zh-cn_image_0000001174104400](figures/zh-cn_image_0000001174104400.gif)
