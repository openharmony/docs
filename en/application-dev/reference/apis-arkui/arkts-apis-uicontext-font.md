# Class (Font)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hddgzw-->
<!--Designer: @pssea-->
<!--Tester: @jiaoaozihao-->
<!--Adviser: @HelloCrease-->

Provides APIs for registering custom fonts.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 10.
>
> - In the following API examples, you must first use [getFont()](./arkts-apis-uicontext-uicontext.md#getfont) in **UIContext** to obtain a **Font** instance, and then call the APIs using the obtained instance.
>
> - You are advised to use the [loadFontSync](../apis-arkgraphics2d/js-apis-graphics-text.md#loadfontsync) API of the font engine to register custom fonts.

## registerFont

registerFont(options: font.FontOptions): void

Registers a custom font with the font manager.

This API is asynchronous and does not support concurrent calls.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                      | Mandatory  | Description         |
| ------- | ---------------------------------------- | ---- | ----------- |
| options | [font.FontOptions](js-apis-font.md#fontoptions) | Yes   | Information about the custom font to register.<br>**NOTE**<br>When setting the path to the font file, you are advised to use a string with the **file://** path prefix for resources within the system sandbox path. Ensure that the file exists in the sandbox directory path and has read permissions.|

**Example**

<!--code_no_check-->
```ts
// xxx.ets
import { Font } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';
  private uiContext: UIContext = this.getUIContext();
  private font: Font = this.uiContext.getFont();

  aboutToAppear() {
    this.font.registerFont({
      familyName: 'medium',
      familySrc: '/font/medium.ttf' // The font folder is at the same level as the pages folder.
    })
  }

  build() {
    Column() {
      Text(this.message)
        .align(Alignment.Center)
        .fontSize(20)
        .fontFamily('medium') // medium: name of the registered custom font. (Registered fonts such as $r('app.string.mediumFamilyName') and 'mediumRawFile' can also be used.)
    }.width('100%')
  }
}
```
## getSystemFontList

getSystemFontList(): Array\<string> 

Obtains the list of supported fonts.

This API only takes effect on PCs/2-in-1 devices and returns an empty array on other devices.

You are advised to use the [getSystemFontFullNamesByType](../apis-arkgraphics2d/js-apis-graphics-text.md#textgetsystemfontfullnamesbytype14) API to obtain the latest system-supported font list data.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type            | Description       |
| -------------- | --------- |
| Array\<string> | List of supported fonts.|


**Example**

<!--code_no_check-->
```ts
// xxx.ets
import { Font } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  private uiContext: UIContext = this.getUIContext();
  private font: Font = this.uiContext.getFont();
  fontList: Array<string> = new Array<string>();

  build() {
    Column() {
      Button("getSystemFontList")
        .width('60%')
        .height('6%')
        .onClick(() => {
          this.fontList = this.font.getSystemFontList();
          console.info('getSystemFontList', JSON.stringify(this.fontList))
        })
    }.width('100%')
  }
}
```

## getFontByName

getFontByName(fontName: string): font.FontInfo

Obtains information about a system font based on the font name.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description     |
| -------- | ------ | ---- | ------- |
| fontName | string | Yes   | System font name.|

**Return value**

| Type                                     | Description          |
| ----------------------------------------- | -------------- |
| [font.FontInfo](js-apis-font.md#fontinfo10) | Detailed information of the font.|

**Example**

<!--code_no_check-->
```ts
// xxx.ets
import { Font, font } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  private uiContext: UIContext = this.getUIContext();
  private font: Font = this.uiContext.getFont();
  fontInfo: font.FontInfo = this.font.getFontByName('');

  build() {
    Column() {
      Button("getFontByName")
        .width('60%')
        .height('6%')
        .onClick(() => {
          this.fontInfo = this.font.getFontByName('HarmonyOS Sans Italic');
          console.info("getFontByName(): path = " + this.fontInfo.path);
          console.info("getFontByName(): postScriptName = " + this.fontInfo.postScriptName);
          console.info("getFontByName(): fullName = " + this.fontInfo.fullName);
          console.info("getFontByName(): family = " + this.fontInfo.family);
          console.info("getFontByName(): subfamily = " + this.fontInfo.subfamily);
          console.info("getFontByName(): weight = " + this.fontInfo.weight);
          console.info("getFontByName(): width = " + this.fontInfo.width);
          console.info("getFontByName(): italic = " + this.fontInfo.italic);
          console.info("getFontByName(): monoSpace = " + this.fontInfo.monoSpace);
          console.info("getFontByName(): symbolic = " + this.fontInfo.symbolic);
        })
    }.width('100%')
  }
}
```
