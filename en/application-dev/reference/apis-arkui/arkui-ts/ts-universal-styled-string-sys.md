# Styled String (System API)

Styled strings are string objects that facilitate the flexible use of text styles. They can be bound to the **Text** component using the [setStyledString](./ts-basic-components-text.md#setstyledstring12) API in **TextController**, and to the **RichEditor** component using the [setStyledString](ts-basic-components-richeditor.md#setstyledstring12) API in **RichEditorStyledStringController**.

>  **NOTE**
>
>  This component is supported since API version 13. Updates will be marked with a superscript to indicate their earliest API version.
>
>  This topic describes only system APIs provided by the module. For details about its public APIs, see [Styled String](ts-universal-styled-string.md).

## StyledString

### marshalling

marshalling(styledString: StyledString): ArrayBuffer

Serializes a styled string.

**Atomic service API**: This API can be used in atomic services since API version 13.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| ----- | ----- | ---- | ---- |
| styledString | [StyledString](ts-universal-styled-string.md) | Yes | Styled string to serialize.|

**Return value**

| Type             |Description      |
| ------- | --------------------------------- | 
| ArrayBuffer | Buffer information after serialization.<br>**NOTE**<br>Currently, text and images are supported.|


### unmarshalling

unmarshalling(buffer: ArrayBuffer): Promise\<StyledString>

Deserializes a buffer to obtain a styled string.

**Atomic service API**: This API can be used in atomic services since API version 13.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| ----- | ----- | ---- | ---- |
| buffer | ArrayBuffer | Yes | Data serialized from a styled string.|

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| Promise\<[StyledString](ts-universal-styled-string.md)> |Promise used to return the result.|

## Example

This example demonstrates the serialization and deserialization of styled strings using the **marshalling** and **unmarshalling** properties.

```ts
// xxx.ets
import { LengthMetrics } from '@kit.ArkUI'

@Entry
@Component
struct Index {
  @State textTitle: string = "Serialization and deserialization APIs"
  @State textResult: string = "Hello world"
  @State serializeStr: string = "Serialization"
  @State flag: boolean = false
  private textAreaController: TextAreaController = new TextAreaController()
  private buff: Uint8Array = new Uint8Array()

  fontStyle: TextStyle = new TextStyle({
    fontWeight: FontWeight.Lighter,
    fontFamily: 'HarmonyOS Sans',
    fontColor: Color.Green,
    fontSize: LengthMetrics.vp(30),
    fontStyle: FontStyle.Normal
  })
  // Create a styled string object.
  styledString: StyledString = new StyledString("Hello world",
    [{ start: 0, length: 11, styledKey: StyledStringKey.FONT, styledValue: this.fontStyle }]);

  @Builder
  controllableBuild() {
    Column(){
      TextArea({
        text: this.textResult,
        controller: this.textAreaController
      }).width('95%').height('40%').enableKeyboardOnFocus(false)

      Button(this.serializeStr)
        .margin(5)
        .onClick(async ()=>{
          this.flag = !this.flag
          if (!this.flag) {
            console.info("Debug: Deserialization")
            let styles: StyledString = await StyledString.unmarshalling(this.buff.buffer)
            this.textTitle = "After calling decodeTlv, the result of deserialization is:"
            if (styles == undefined) {
              console.error("Debug: Failed to obtain the styled string.")
              return
            }
            this.textResult =  styles.getString()
            console.info("Debug: this.textResult = " + this.textResult)
            let stylesArr = styles.getStyles(0, this.textResult.length, StyledStringKey.FONT)
            console.info("Debug: stylesArr.length = " + stylesArr.length)
            for (let i = 0; i < stylesArr.length; ++i) {
              console.info("Debug: style.start = " + stylesArr[i].start)
              console.info("Debug: style.length = " + stylesArr[i].length)
              console.info("Debug: style.styledKey = " + stylesArr[i].styledKey)
              let font = stylesArr[i].styledValue as TextStyle
              console.info("Debug: style.fontColor = " + font.fontColor)
              console.info("Debug: style.fontSize = " + font.fontSize)
              console.info("Debug: style.fontFamily = " + font.fontFamily)
              console.info("Debug: style.fontStyle = " + font.fontStyle)
            }
            let subStr = styles.subStyledString(0, 2)
            console.info("Debug: subStr = " + subStr.getString())
            this.serializeStr = "Marshalling"
          } else {
            console.info("Debug: Serialization")
            let resultBuffer = StyledString.marshalling(this.styledString)
            this.buff = new Uint8Array(resultBuffer)
            this.textTitle = "After calling encodeTlv, the result of serialization is:"
            this.textResult = this.buff.toString()
            console.info("Debug: buff = " + this.buff.toString())
            this.serializeStr = "Deserialization"
          }
        })
    }.margin(10)
  }

  build() {
    Column() {
      Blank().margin(30)
      Text(this.textTitle)
      this.controllableBuild()
    }
  }
}
```
