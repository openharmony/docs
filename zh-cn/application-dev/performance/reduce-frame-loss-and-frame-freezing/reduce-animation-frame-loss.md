# 减少动画丢帧

在播放动画或者生成动画时，画面产生停滞而导致帧率过低的现象，称为动画丢帧。

播放动画时，系统需要在一个刷新周期内完成动画变化曲线的计算，完成组件布局绘制等操作。建议使用系统提供的动画接口，只需设置曲线类型、终点位置、时长等信息，就能够满足常用的动画功能，减少UI主线程的负载。

反例：应用使用了自定义动画，动画曲线计算过程很容易引起UI线程高负载，易导致丢帧。

```javascript
@Entry
@Component
struct AttrAnimationExample {
  @State widthSize: number = 200
  @State heightSize: number = 100
  @State flag: boolean = true

  computeSize() {
    let duration = 2000
    let period = 16
    let widthSizeEnd = undefined
    let heightSizeEnd = undefined
    if (this.flag) {
      widthSizeEnd = 100
      heightSizeEnd = 50
    } else {
      widthSizeEnd = 200
      heightSizeEnd = 100
    }
    let doTimes = duration / period
    let deltaHeight = (heightSizeEnd - this.heightSize) / doTimes
    let deltaWeight = (widthSizeEnd - this.widthSize) / doTimes
    for (let i = 1; i <= doTimes; i++) {
      let t = period * (i);
      setTimeout(() => {
        this.heightSize = this.heightSize + deltaHeight
        this.widthSize = this.widthSize + deltaWeight
      }, t)
    }
    this.flag = !this.flag
  }

  build() {
    Column() {
      Button('click me')
        .onClick(() => {
          let delay = 500
          setTimeout(() => { this.computeSize() }, delay)
        })
        .width(this.widthSize).height(this.heightSize).backgroundColor(0x317aff)
    }.width('100%').margin({ top: 5 })
  }
}
```

## 使用系统提供的属性动效API

建议：通过系统提供的属性动效API实现上述动效功能。

```javascript
@Entry
@Component
struct AttrAnimationExample {
  @State widthSize: number = 200
  @State heightSize: number = 100
  @State flag: boolean = true

  build() {
    Column() {
      Button('click me')
        .onClick((event: ClickEvent) => {
          if (this.flag) {
            this.widthSize = 100
            this.heightSize = 50
          } else {
            this.widthSize = 200
            this.heightSize = 100
          }
          this.flag = !this.flag
        })
        .width(this.widthSize).height(this.heightSize).backgroundColor(0x317aff)
        .animation({
          duration: 2000, // 动画时长
          curve: Curve.Linear, // 动画曲线
          delay: 500, // 动画延迟
          iterations: 1, // 播放次数
          playMode: PlayMode.Normal // 动画模式
        }) // 对Button组件的宽高属性进行动画配置
    }.width('100%').margin({ top: 5 })
  }
}
```

更详细的API文档请参考：https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/arkui-ts/ts-animatorproperty.md

## 使用系统提供的显式动效API

建议：通过系统提供的显式动效API实现上述动效功能。

```javascript
@Entry
@Component
struct AnimateToExample {
  @State widthSize: number = 200;
  @State heightSize: number = 100;
  @State flag: boolean = true;

  build() {
    Column() {
      Button('click me')
        .onClick((event: ClickEvent) => {
          if (this.flag) {
            animateTo({
              duration: 2000, // 动画时长
              curve: Curve.Linear, // 动画曲线
              delay: 500, // 动画延迟
              iterations: 1, // 播放次数
              playMode: PlayMode.Normal // 动画模式
            }, () => {
              this.widthSize = 100;
              this.heightSize = 50;
            })
          } else {
            animateTo({
              duration: 2000, // 动画时长
              curve: Curve.Linear, // 动画曲线
              delay: 500, // 动画延迟
              iterations: 1, // 播放次数
              playMode: PlayMode.Normal // 动画模式
            }, () => {
              this.widthSize = 200;
              this.heightSize = 100;
            })
          }
          this.flag = !this.flag;
        })
        .width(this.widthSize).height(this.heightSize).backgroundColor(0x317aff)
    }.width('100%').margin({ top: 5 })
  }
}
```

更详细的API文档请参考：https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/arkui-ts/ts-explicit-animation.md