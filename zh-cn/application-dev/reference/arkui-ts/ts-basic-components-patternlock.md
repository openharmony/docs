# PatternLock<font color=ff0000><sup>8+</sup></font>

图案密码锁组件，以宫格图案的方式输入密码，用于密码验证。

## 子组件

无。

##  接口

PatternLock(controller?: PatternLockController)

- 参数

  | 参数名     | 参数类型              | 必填 | 默认值 | 参数描述                                     |
  | ---------- | --------------------- | ---- | ------ | -------------------------------------------- |
  | controller | PatternLockController | 否   | null   | 给组件绑定一个控制器，用来控制组件状态重置。 |

- PatternLockController

  PatternLock组件的控制器，可以将此对象绑定至PatternLock组件，然后通过它进行状态重置。

  | 接口名称      | 功能描述       |
  | ------------- | -------------- |
  | reset():void; | 重置组件状态。 |

## 属性方法

不支持*`backgroundColor`*以外的通用属性设置。

| 名称            | 参数类型         | 默认值      | 描述                                                         |
| --------------- | ---------------- | ----------- | ------------------------------------------------------------ |
| sideLength      | Length           | 300dp       | 设置组件的宽度和高度（相同值）。最小可以设置为0。            |
| circleRadius    | Length           | 14dp        | 设置宫格圆点的半径。                                         |
| backgroundColor | ResourceColor    | 无          | 设置组件的背景色。                                           |
| regularColor    | ResourceColor    | Color.Black | 设置宫格圆点在“未选中”状态的填充颜色。                       |
| selectedColor   | ResourceColor    | Color.Black | 设置宫格圆点在“选中”状态的填充颜色。                         |
| activeColor     | ResourceColor    | Color.Black | 设置宫格圆点在“激活”状态的填充颜色。                         |
| pathColor       | ResourceColor    | Color.Blue  | 设置线段的颜色。                                             |
| pathStrokeWidth | number or string | 34dp        | 设置连线的宽度。最小可以设置为0。                            |
| autoReset       | boolean          | true        | 设置是否支持用户在完成输入后再次触屏重置组件状态。如果设置为true，用户可以通过触摸图案密码锁重置组件状态（清除之前的输入效果）；如果设置为false，用户手指离开屏幕完成输入后，再次触摸图案密码锁（包括圆点）不能改变之前的输入状态。 |

## 事件方法

| 事件名            | 参数类型      | 默认值 | 描述                                                         |
| -------------------------------------------------------- | ------------- | ------ | ------------------------------------------------------------ |
| onPatternComplete | Array<number> | 无     | 指定输入状态结束时被调用的回调函数，参数是和输入顺序一致的数字数组。 |

##  示例

```typescript
@Entry
@Component
struct SwiperExample {
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
        .regularColor(Color.Black)
        .selectedColor(Color.Black)
        .activeColor(Color.Black)
        .pathColor(Color.Blue)
        .backgroundColor(Color.White)
        .autoReset(true)
        .onPatternComplete((input: Array<number>) => {
          if (input == null || input == undefined || input.length < 5) {
            this.message = 'The password length needs to be greater than 5.';
            return;
          }
          if (this.passwords.length > 0) {
            if (this.passwords.toString() == input.toString()) {
              this.passwords = input;
              this.message = 'Set password successfully: ' + this.passwords.toString();
            } else {
              this.message = 'Inconsistent passwords, please enter again.';
            }
          } else {
            this.passwords = input;
            this.message = "Please enter again.";
          }
        })
      Button('reset button').margin(30).onClick(() => {
        this.patternLockController.reset();
        this.passwords = [];
        this.message = 'Please input password';
      })
    }.width('100%').height('100%')
  }
}
```

![](.\figures\patternlock.gif)

