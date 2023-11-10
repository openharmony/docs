# Animation Smoothing


When running animations, the UI is also interacting with users in real time. It must respond immediately to changes in user behavior. For example, if the user swipes up to exit in the midst of an application launch process, the UI should immediately transit from the startup animation to the exit animation, rather than finishing the startup animation before exiting. In the scenario where the animation triggered when the user lifts their fingers off the screen, the initial velocity of the animation must inherit the gesture speed, so as to avoid pauses caused by speed disconnection. For the preceding and similar scenarios, OpenHarmony provides efficient APIs for smoothing between animations and between animations and gestures.

Assume that there is a running animation for an animatable attribute. If the end value of the attribute changes due to an operation on the UI, just change the attribute value in the **animateTo** closure or change the input parameter value of the **animation** API to create an animation. OpenHarmony then automatically connects the previous animation with the current animation – the created animation.


```ts
import curves from '@ohos.curves'
class SetSlt{
  scaleToggle:boolean = true
  set():void{
    this.scaleToggle = !this.scaleToggle;
  }
}
let CurAn:Record<string,curves> = {'curve':curves.springMotion()}
// Step 1: Declare the related state variable.
@state scaleToggle: boolean = true;

...
Column() {
  Button()
    // Step 2: Set the declared state variable to the related animatable attribute API.
    .scale(this.scaleToggle ? 1 : 0.5)
    // Step 3: Change the state variable value through the click event, which then changes the attribute value.
    .onclick(() => {
      let sets = new SetSlt()
      sets.set()
    })
    // Step 4: Enable the implicit animation. When the end value of the animation changes, the system automatically adds the smoothing animation.
    .animation(CurAn)
}
...
```

A complete example is as follows: By clicking **click**, you change the **scale** attribute of the red square. When you click **click** repeatedly, the end value of the **scale** attribute changes continuously, and the current animation smoothly moves towards the new end value of the **scale** attribute.


```ts
import curves from '@ohos.curves';
class SetSlt{
  isAnimation:boolean = true
  set():void{
    this.isAnimation = !this.isAnimation;
  }
}
@Entry
@Component
struct AnimationToAnimationDemo {
  @State SetAnimation: SetSlt = new SetSlt();

  build() {
    Column() {
      Text('ArkUI')
        .fontWeight(FontWeight.Bold)
        .fontSize(12)
        .fontColor(Color.White)
        .textAlign(TextAlign.Center)
        .borderRadius(10)
        .backgroundColor(0xf56c6c)
        .width(100)
        .height(100)
        .scale({ x: this.SetAnimation.isAnimation ? 2 : 1, y: this.SetAnimation.isAnimation ? 2 : 1 })
        .animation({ curve: curves.springMotion(0.4, 0.8) })

      Button('Click')
        .margin({ top: 200 })
        .onClick(() => {
          this.SetAnimation.set()
        })
    }
    .width('100%')
    .height('100%')
    .justifyContent(FlexAlign.Center)
  }
}
```

![en-us_image_0000001599971890](figures/en-us_image_0000001599971890.gif)



## Smoothing Between Gestures and Animations

In scenarios where gestures are used, an attribute change is generally triggered when the user places or moves their finger (or fingers) on the screen, and continues after the user lifts their finger (or fingers) off the screen until the end value of the attributes is reached.

The initial velocity of the attribute change after the user lifts their finger (or fingers) should be consistent with the velocity of the attribute change at the moment before the user lifts their finger (or fingers). If the former is **0**, it feels like a running car stops suddenly, an unusual abrupt change not welcomed by users.

In cases where smoothing between gestures and animations is required, for example, when scrolling a list, you can apply a responsive spring curve for the attribute animation running when the user places or moves their finger (or fingers) on the screen; and apply a spring curve for the attribute animation running after the user lifts their finger (or fingers) off the screen. For the animation that uses the [springMotion](../reference/apis/js-apis-curve.md#curvesspringmotion9) curve, the attribute animation running when the user places or moves their finger (or fingers) on the screen automatically inherits the previous velocity and starts from where the previous animation leaves off.


```ts
import curves from '@ohos.curves'
class SetOffset{
  offsetX:number = 0;
  offsetY:number = 0;
  set(x:number,y:number):void{
    this.offsetX = x;
    this.offsetY = y;
  }
}
// Step 1: Declare related state variables.
@state offsetX: number = 0;
@State offsetY: number = 0;
targetOffsetX: number = 100;
targetOffsetY: number = 100;
...
Column() 
  // Step 2: Set the declared state variables to the related animatable attribute APIs.
  .translate({ x: this.offsetX, y: this.offsetY})
  .gesture(
    PanGesture({})
      .onActionUpdate((event?: GestureEvent) => {
        // Step 3: Change the state variable value for the time when the user places or moves their finger (or fingers) on the screen and use reponsiveSpringMotion for movement toward the new value.
        animateTo({
          curve: curves.responsiveSpringMotion()
        }, () => {
          if(event){
            let setxy = new SetOffset();
            setxy.set(event.offsetX,event.offsetY)
          }
        })
      })
      .onActionEnd(() => {
        // Step 4: Set the end value of the state variable for after the user lifts their finger (or fingers), and use springMotion for movement toward the new value. The springMotion animation inherits the previous velocity.
        animateTo({
          curve: curves.SpringMotion()
        }, () => {
          let setxy = new SetOffset();
          setxy.set(targetOffsetX,targetOffsetY)
        })
      })
  )
...
```

Below is the complete sample code and effect.


```ts
import curves from '@ohos.curves';

@Entry
@Component
struct SpringMotionDemo {
  @State positionX: number = 100;
  @State positionY: number = 100;
  diameter: number = 50;

  build() {
    Column() {
      Row() {
        Circle({ width: this.diameter, height: this.diameter })
          .fill(Color.Blue)
          .position({ x: this.positionX, y: this.positionY })
          .onTouch((event?: TouchEvent) => {
            if(event){
              if (event.type === TouchType.Move) {
                // When the user places or moves their finger on the screen, use the responsiveSpringMotion curve.
                animateTo({ curve: curves.responsiveSpringMotion() }, () => {
                  // Subtract the radius so that the center of the ball moves to where the finger is placed.
                  this.positionX = event.touches[0].screenX - this.diameter / 2;
                  this.positionY = event.touches[0].screenY - this.diameter / 2;
                  console.info(`move, animateTo x:${this.positionX}, y:${this.positionY}`);
                })
              } else if (event.type === TouchType.Up) {
                // After the user lifts their finger off the screen, use the springMotion curve.
                animateTo({ curve: curves.springMotion() }, () => {
                  this.positionX = 100;
                  this.positionY = 100;
                  console.info(`touchUp, animateTo x:100, y:100`);
                })
              }
            }
          })
      }
      .width("100%").height("80%")
      .clip(true) // If the ball moves beyond the parent component, it is invisible.
      .backgroundColor(Color.Orange)

      Flex({ direction: FlexDirection.Row, alignItems: ItemAlign.Start, justifyContent: FlexAlign.Center }) {
        Text("Drag the ball").fontSize(16)
      }
      .width("100%")

      Row() {
        Text('Click position: [x: ' + Math.round(this.positionX) + ', y:' + Math.round(this.positionY) + ']').fontSize(16)
      }
      .padding(10)
      .width("100%")
    }.height('100%').width('100%')
  }
}
```

![en-us_image_0000001647027001](figures/en-us_image_0000001647027001.gif)
