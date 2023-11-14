# Reducing Animation Frame Loss

Frame loss in the animation arena is a phenomenon where the frame rate of an animation drops when it is running or being created.

When playing an animation, the system needs to calculate the animation curve and draw the component layout within a refresh period. You are advised to use the system-provided animation APIs. With these APIs, setting the curve type, end point position, and duration is enough for meeting common animation needs, thereby reducing the load of the UI main thread.

Negative example: The application uses a custom animation, which involves animation curve calculation. This calculation process may cause high load of the UI thread and frame loss.

```typescript
@Entry
@Component
struct AttrAnimationExample0 {
  @State widthSize: number = 200
  @State heightSize: number = 100
  @State flag: boolean = true

  computeSize() {
    let duration = 2000
    let period = 16
    let widthSizeEnd = 0
    let heightSizeEnd = 0
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

## Using System-Provided Attribute Animation APIs

The following uses the system-provided attribute animation APIs to implement the preceding animation features:

```typescript
@Entry
@Component
struct AttrAnimationExample1 {
  @State widthSize: number = 200
  @State heightSize: number = 100
  @State flag: boolean = true

  build() {
    Column() {
      Button('click me')
        .onClick((event?: ClickEvent | undefined) => {
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
          duration: 2000, // Animation duration.
          curve: Curve.Linear, // Animation curve.
          delay: 500, // Animation delay.
          iterations: 1, // Number of playback times.
          playMode: PlayMode.Normal // Animation playback mode.
        }) // Animation configuration for the width and height attributes of the <Button> component.
    }.width('100%').margin({ top: 5 })
  }
}
```

For more details, see [Property Animation](../reference/arkui-ts/ts-animatorproperty.md).

## Using System-Provided Explicit Animation APIs

The following uses the system-provided explicit animation APIs to implement the preceding animation features:

```typescript
@Entry
@Component
struct AnimateToExample2 {
  @State widthSize: number = 200;
  @State heightSize: number = 100;
  @State flag: boolean = true;

  build() {
    Column() {
      Button('click me')
        .onClick((event?: ClickEvent | undefined) => {
          if (this.flag) {
            animateTo({
              duration: 2000, // Animation duration.
              curve: Curve.Linear, // Animation curve.
              delay: 500, // Animation delay.
              iterations: 1, // Number of playback times.
              playMode: PlayMode.Normal // Animation playback mode.
            }, () => {
              this.widthSize = 100;
              this.heightSize = 50;
            })
          } else {
            animateTo({
              duration: 2000, // Animation duration.
              curve: Curve.Linear, // Animation curve.
              delay: 500, // Animation delay.
              iterations: 1, // Number of playback times.
              playMode: PlayMode.Normal // Animation playback mode.
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

For more details, see [Explicit Animation](../reference/arkui-ts/ts-explicit-animation.md).
