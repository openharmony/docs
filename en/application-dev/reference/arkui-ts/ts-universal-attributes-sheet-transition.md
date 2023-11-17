# Sheet Transition

You can bind a sheet to a component through the **bindSheet** attribute. You can also set the sheet to the preset or custom height for when the component is inserted.

>  **NOTE**
>
>  The APIs of this module are supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.
>
>  Switching between landscape and portrait modes is not supported.
>
>  Route hopping is not supported.

## Attributes

| Name       | Parameter                                      | Description                                    |
| --------- | ---------------------------------------- | ---------------------------------------- |
| bindSheet | isShow: boolean,<br>builder: [CustomBuilder](ts-types.md#custombuilder8),<br>options?: [SheetOptions](#sheetoptions) | Binds a sheet to the component, which can be displayed when the component is touched.<br>**isShow**: whether to display the sheet.<br>Since API version 10, this parameter supports two-way binding through [$$](../../quick-start/arkts-two-way-sync.md).<br>**builder**: content of the sheet.<br> **options**: optional attributes of the sheet.|
> **NOTE**
>
> When no two-way binding is set up for the **isShow** parameter, closing the sheet by dragging does not change the parameter value.
>
> To synchronize the value of **isShow** with the actual state of the sheet, it is recommended that you use the [$$](../../quick-start/arkts-two-way-sync.md) to set up two-way binding for **isShow**.
## SheetOptions

| Name             | Type                                      | Mandatory  | Description             |
| --------------- | ---------------------------------------- | ---- | --------------- |
| height          | [SheetSize](#sheetsize) \| [Length](ts-types.md#length) | No   | Height of the sheet.<br>Default value: **LARGE**|
| dragBar         | boolean                                  | No   | Whether to display the drag bar. By default, the drag bar is displayed .  |
| backgroundColor | [ResourceColor](ts-types.md#resourcecolor) | No   | Background color of the sheet.    |
| maskColor | [ResourceColor](ts-types.md#resourcecolor) | No| Mask color of the sheet.|
| onAppear        | () => void                               | No   | Callback invoked when the sheet is displayed.   |
| onDisappear     | () => void                               | No   | Callback invoked when the sheet is hidden.   |

## SheetSize

| Name    | Description           |
| ------ | --------------- |
| MEDIUM | The sheet height is half of the screen height.|
| LARGE  | The sheet height is almost the screen height.|

## Example

```ts
// xxx.ets
@Entry
@Component
struct SheetTransitionExample {
  @State isShow:boolean = false
  @State isShow2:boolean = false
  @State sheetHeight:number = 300;
  @State showDragBar:boolean = true;

  @Builder myBuilder() {
    Column() {
      Button("change height")
        .margin(10)
        .fontSize(20)
        .onClick(()=>{
          this.sheetHeight = 500;
        })

      Button("Set Illegal height")
        .margin(10)
        .fontSize(20)
        .onClick(()=>{
          this.sheetHeight = -1;
        })

      Button("close dragBar")
        .margin(10)
        .fontSize(20)
        .onClick(()=>{
          this.showDragBar = false;
        })

      Button("close modal 1")
        .margin(10)
        .fontSize(20)
        .onClick(()=>{
          this.isShow = false;
        })
    }
    .width('100%')
    .height('100%')
  }

  build() {
    Column() {
      Button("transition modal 1")
        .onClick(() => {
          this.isShow = true
        })
        .fontSize(20)
        .margin(10)
        .bindSheet($$this.isShow, this.myBuilder(), {height: this.sheetHeight, dragBar: this.showDragBar, backgroundColor: Color.Green, onAppear: () => {console.log("BindSheet onAppear.")}, onDisappear: () => {console.log("BindSheet onDisappear.")}})
    }
    .justifyContent(FlexAlign.Center)
    .width('100%')
    .height('100%')
  }
}
```

![en-us_sheet](figures/en-us_sheet.gif)
