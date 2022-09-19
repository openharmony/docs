# PatternLock

图案密码锁组件，以宫格图案的方式输入密码，用于密码验证。手指触碰图案密码锁时开始进入输入状态，手指离开屏幕时结束输入状态并向应用返回输入的密码。

>  **说明：** 
>
> 该组件从API Version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 子组件

无

##  接口

PatternLock(controller?: PatternLockController)

**参数:**

| 参数名     | 参数类型                                        | 必填 | 描述                                                         |
| ---------- | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| controller | [PatternLockController](#patternlockcontroller) | 否   | 给组件绑定一个控制器，用来控制组件状态重置。<br/>默认值：null |

## 属性

不支持`backgroundColor`以外的通用属性设置。

| 名称            | 参数类型                              | 描述                                                         |
| --------------- | ------------------------------------- | ------------------------------------------------------------ |
| sideLength      | [Length](ts-types.md)        | 设置组件的宽度和高度（相同值）。最小可以设置为0。<br/>默认值：300vp |
| circleRadius    | [Length](ts-types.md)        | 设置宫格圆点的半径。<br/>默认值：14vp                        |
| regularColor    | [ResourceColor](ts-types.md) | 设置宫格圆点在“未选中”状态的填充颜色。<br/>默认值：Color.Black |
| selectedColor   | [ResourceColor](ts-types.md) | 设置宫格圆点在“选中”状态的填充颜色。<br/>默认值：Color.Black |
| activeColor     | [ResourceColor](ts-types.md) | 设置宫格圆点在“激活”状态的填充颜色。<br/>默认值：Color.Black |
| pathColor       | [ResourceColor](ts-types.md) | 设置连线的颜色。<br/>默认值：Color.Blue                      |
| pathStrokeWidth | number&nbsp;\|&nbsp;string            | 设置连线的宽度。最小可以设置为0。<br/>默认值：34vp           |
| autoReset       | boolean                               | 设置是否支持用户在完成输入后再次触屏重置组件状态。如果设置为true，用户可以通过触摸图案密码锁重置组件状态（清除之前的输入效果）；如果设置为false，用户手指离开屏幕完成输入后，再次触摸图案密码锁（包括圆点）不能改变之前的输入状态。<br/>默认值：true |

## 事件

除支持[通用事件](ts-universal-events-click.md)外，还支持以下事件：

| 名称                                       | 描述                                       |
| ---------------------------------------- | ---------------------------------------- |
| onPatternComplete(callback: (input: Array\<number\>) => void) | 密码输入结束时被调用的回调函数。<br />input: 与选中宫格圆点顺序一致的数字数组，数字为选中宫格的索引（0到8）。 |

## PatternLockController

PatternLock组件的控制器，可以将此对象绑定至PatternLock组件，然后通过它进行状态重置。

### 导入对象

```typescript
patternLockController: PatternLockController = new PatternLockController()
```

### reset

reset(): void

重置组件状态。

##  示例

```ts
// xxx.ets
@Entry
@Component
struct PatternLockExample {
  @State passwords: Number[] = []
  @State message: string = 'please input password'
  private patternLockController: PatternLockController = new PatternLockController()
  
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Text(this.message).textAlign(TextAlign.Center)
      PatternLock(this.patternLockController)
        .sideLength(150)
        .circleRadius(7)
        .pathStrokeWidth(17)
        .backgroundColor(Color.White)
        .autoReset(true)
        .onPatternComplete((input: Array<number>) => {
          if (input == null || input == undefined || input.length < 5) {
            this.message = 'The password length needs to be greater than 5.'
            return
          }
          if (this.passwords.length > 0) {
            if (this.passwords.toString() == input.toString()) {
              this.passwords = input
              this.message = 'Set password successfully: ' + this.passwords.toString()
            } else {
              this.message = 'Inconsistent passwords, please enter again.'
            }
          } else {
            this.passwords = input
            this.message = "Please enter again."
          }
        })
      Button('reset button').margin(30).onClick(() => {
        this.patternLockController.reset()
        this.passwords = []
        this.message = 'Please input password'
      })
    }.width('100%').height('100%')
  }
}
```

![patternlock](figures/patternlock.gif)

