# Hover Effect


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Attributes

  | Name | Type | Default&nbsp;Value | Description | 
| -------- | -------- | -------- | -------- |
| hoverEffect | HoverEffect | HoverEffect.Auto | Hover&nbsp;effect&nbsp;of&nbsp;the&nbsp;component&nbsp;in&nbsp;hover&nbsp;state. | 

- HoverEffect enums
    | Name | Description | 
  | -------- | -------- |
  | Auto | Default&nbsp;hover&nbsp;effect. | 
  | Scale | Scale&nbsp;effect. | 
  | Board | Fade-in&nbsp;and&nbsp;fade-out&nbsp;effect. | 
  | None | No&nbsp;effect. | 


## Example

  
```
@Entry
@Component
struct HoverExample {
  @State isHoverVal: boolean = false

  build() {
    Column({ space: 5 }) {
      Column({ space: 5 }) {
        Text('Scale').fontSize(20).fontColor(Color.Gray).width('90%').position({ x: 0, y: 80 })
        Column()
          .width('80%').height(200).backgroundColor(Color.Gray)
          .position({ x: 40, y: 120 })
          .hoverEffect(HoverEffect.Scale)
          .onHover((isHover: boolean) => {
            console.info('Scale' + isHover)
            this.isHoverVal = isHover
          })

        Text('Board').fontSize(20).fontColor(Color.Gray).width('90%').position({ x: 0, y: 380 })
        Column()
          .width('80%').height(200).backgroundColor(Color.Gray)
          .hoverEffect(HoverEffect.Board)
          .position({ x: 40, y: 420 })
          .onHover((isHover: boolean) => {
            console.info('HoverEffect.Board')
            this.isHoverVal = isHover
          })
      }
      .hoverEffect(HoverEffect.None)
      .width('100%').height('100%').border({ width: 1 })
      .onHover((isHover: boolean) => {
        console.info('HoverEffect.None')
        this.isHoverVal = isHover
      })
    }
  }
}
```
