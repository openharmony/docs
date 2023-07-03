# arkui子系统ChangeLog

## cl.arkui.1 stack组件alignContent属性和通用属性align生效顺序

**说明**
属性之间的处理原则：如果功能相同，属性按覆盖处理即后设置的生效。alignContent和align功能相同，都是子组件在stack容器组件的对齐方式。

**示例：**
```ts
// xxx.ets
@Entry
@Component
struct StackExample {
  build() {
    Stack({alignContent:Alignment.Start}){
      Text("Stack's child").backgroundColor(Color.Brown).height("100").width(100)
    }
    .width(300).height(300)
    .backgroundColor(Color.Pink)
    .align(Alignment.Center)
    .alignContent(Alignment.TopEnd)
  }
}
```

API version 9：子组件按照通用属性align布局

![stack](figures/api9.png)


API version 10及以后：子组件按照后设置的alignContent布局

![stack](figures/api10_and_later.png)

**变更影响**

alignContent和align都设置时，API version 9及以前是align生效，API version 10及以后是后设置的生效。

## cl.arkui.2 canvas组件onReady事件行为变更

**说明**
onReady事件在组件创建完成后或组件大小发生变化时触发，并清空画布。

**示例：**
```ts
@Entry
@Component
struct OnReadyDiff {
  @State message: string = 'init '
  @State isShow: boolean = false
  @State myHeight: number = 300
  private settings: RenderingContextSettings = new RenderingContextSettings(true);
  private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings);

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
        Button('ChangePosition')
          .onClick(()=>{
            this.isShow = !this.isShow
          })
        if (this.isShow) {
          Button('new button')
            .height(200)
        }
        Button('ChangeHeight')
          .onClick(()=>{
            this.myHeight = this.myHeight==300?500:300
          })

        Canvas(this.context)
          .width(300)
          .height(this.myHeight)
          .backgroundColor('#ffff00')
          .onReady(() =>{
            this.context.fillRect(0, 0, 100, 100)
            this.message += 'a '
          })
        Button('draw another')
          .onClick(()=>{
            this.context.fillRect(100, 100, 100, 100)
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

API version 9：onReady在组件创建完成时触发，位置变化时会触发，组件大小变化时也会触发。

![stack](figures/api9onReady.gif)

API version 10及以后：onReady在组件创建完成时触发，在组件位置变化时不会触发，组件大小变化时会触发。

![stack](figures/api10onReady.gif)

**变更影响**

onReady事件在组件位置发生变化时行为变更，API version 9及以前会触发，API version 10及以后不会触发。

## cl.arkui.3 canvas组件fillText接口和strokeText接口行为变更

**说明**
fillText和strokeText接口在绘制文字时，不会换行。

**示例：**
```ts
// xxx.ets
@Entry
@Component
struct FillText {
  private settings: RenderingContextSettings = new RenderingContextSettings(true)
  private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Canvas(this.context)
        .width('100%')
        .height('100%')
        .backgroundColor('#ffff00')
        .onReady(() =>{
          this.context.font = '50px sans-serif'
          this.context.fillText("Hello World!", 0, 100)
          this.context.fillText("Hello World! This is a long string to fully show", 0, 150)
          this.context.strokeText("Hello World!", 0, 250)
          this.context.strokeText("Hello World! This is a long string to fully show", 0, 300)
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

API version 9：fillText和strokeText接口在绘制文字时，会根据组件宽度换行。

![stack](figures/api9filltext.jpeg)

API version 10及以后：fillText和strokeText接口在绘制文字时，不会换行。

![stack](figures/api10filltext.jpeg)

**变更影响**

fillText和strokeText接口在绘制文字时，API version 9及以前是根据组件宽度换行，API version 10及以后是不会换行。