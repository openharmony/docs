# @ohos.font (Custom Font Registration)

The **font** module provides APIs for registering custom fonts.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import font from '@ohos.font'
```

## font.registerFont

registerFont(options: FontOptions): void

Registers a custom font with the font manager.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                         | Mandatory  | Description         |
| ------- | --------------------------- | ---- | ----------- |
| options | [FontOptions](#fontoptions) | Yes   | Information about the custom font to register.|

## FontOptions

| Name        | Type    | Mandatory  | Description          |
| ---------- | ------ | ---- | ------------ |
| familyName | string | Yes   | Name of the custom font to register.  |
| familySrc  | string | Yes   | Path of the custom font to register.|

## Example

```ts
// xxx.ets
import font from '@ohos.font';

@Entry
@Component
struct FontExample {
  @State message: string =' Hello, World'

  aboutToAppear() {
    font.registerFont({
      familyName: 'medium',
      familySrc: '/font/medium.ttf'
    })
  }

  build() {
    Column() {
      Text(this.message)
        .align(Alignment.Center)
        .fontSize(20)
        .fontFamily('medium') // medium: name of the custom font to register.
        .height('100%')
    }.width('100%')
  }
}
```
## font.getSystemFontList

getSystemFontList(): Array\<string>

Obtains the list of supported fonts.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                | Description              |
| -------------------- | ----------------- |
| Array\<string>       | List of supported fonts. |

## Example

```ts
// xxx.ets
import font from '@ohos.font';

@Entry
@Component
struct FontExample {
  fontList: Array<string>;
  build() {
    Column() {
      Button("getSystemFontList")
        .width('60%')
        .height('6%')
        .onClick(()=>{
          this.fontList = font.getSystemFontList()
        })
    }.width('100%')
  }
}
```

## font.getFontByName

getFontByName(fontName: string): FontInfo;

Obtains information about a system font based on the font name.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type     | Mandatory   | Description         |
| ---------- | --------- | ------- | ------------ |
| fontName   | string    | Yes     | System font name.|

**Return value**

| Type            | Description                         |
| ---------------- | ---------------------------- |
| FontInfo         | Information about the system font.                |

## FontInfo

| Name           | Type   | Description                      |
| -------------- | ------- | ------------------------- |
| path           | string  | File path of the system font.       |
| postScriptName | string  | PostScript name of the system font.|
| fullName       | string  | Name of the system font.          |
| family         | string  | Family of the system font.      |
| subfamily      | string  | Subfamily of the system font.     |
| weight         | number  | Weight of the system font.       |
| width          | number  | Width of the system font.   |
| italic         | boolean | Whether the system font is italic.         |
| monoSpace      | boolean | Whether the system font is monospaced.        |
| symbolic       | boolean | Whether the system font supports symbols. |

```ts
// xxx.ets
import font from '@ohos.font';

@Entry
@Component
struct FontExample {
  fontList: Array<string>;
  fontInfo: font.FontInfo;
  build() {
    Column() {
      Button("getFontByName")
        .onClick(() => {
          this.fontInfo = font.getFontByName('HarmonyOS Sans Italic')
          console.log("getFontByName(): path = " + this.fontInfo.path)
          console.log("getFontByName(): postScriptName = " + this.fontInfo.postScriptName)
          console.log("getFontByName(): fullName = " + this.fontInfo.fullName)
          console.log("getFontByName(): Family = " + this.fontInfo.family)
          console.log("getFontByName(): Subfamily = " + this.fontInfo.subfamily)
          console.log("getFontByName(): weight = " + this.fontInfo.weight)
          console.log("getFontByName(): width = " + this.fontInfo.width)
          console.log("getFontByName(): italic = " + this.fontInfo.italic)
          console.log("getFontByName(): monoSpace = " + this.fontInfo.monoSpace)
          console.log("getFontByName(): symbolic = " + this.fontInfo.symbolic)
        })
    }.width('100%')
  }
}
```
