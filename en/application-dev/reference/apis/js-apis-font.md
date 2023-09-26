# @ohos.font (Custom Font Registration)

The **font** module provides APIs for registering custom fonts.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The functionality of this module depends on UI context. This means that the APIs of this module cannot be used where the UI context is unclear. For details, see [UIContext](./js-apis-arkui-UIContext.md#uicontext).
>
> Since API version 10, you can use the [getFont](./js-apis-arkui-UIContext.md#getfont) API in [UIContext](./js-apis-arkui-UIContext.md#uicontext) to obtain the [Font](./js-apis-arkui-UIContext.md#font) object associated with the current UI context.

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

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type    | Mandatory  | Description          |
| ---------- | ------ | ---- | ------------ |
| familyName | string \| [Resource](../arkui-ts/ts-types.md#resource)<sup>10+</sup> | Yes   | Name of the custom font to register.  |
| familySrc  | string \| [Resource](../arkui-ts/ts-types.md#resource)<sup>10+</sup> | Yes   | Path of the custom font to register.|

**Example**

```ts
// xxx.ets
import font from '@ohos.font';

@Entry
@Component
struct FontExample {
  @State message: string =' Hello, World'

  aboutToAppear() {
    // Both familyName and familySrc support the string type.
    font.registerFont({
      familyName: 'medium',
      familySrc: '/font/medium.ttf' // The font file is at the same level as the pages directory.
    })

    // Both familyName and familySrc support the Resource type.
    font.registerFont({
      familyName: $r('app.string.mediumFamilyName'),
      familySrc: $r('app.string.mediumFamilySrc')
    })

    // familySrc supports the $rawfile type.
    font.registerFont({
      familyName: 'mediumRawFile',
      familySrc: $rawfile('font/medium.ttf')
    })
  }

  build() {
    Column() {
      Text(this.message)
        .align(Alignment.Center)
        .fontSize(20)
        .fontFamily('medium') // medium: name of the custom font to register. (Registered fonts such as $r('app.string.mediumFamilyName') and 'mediumRawFile' can also be used.)
        .height('100%')
    }.width('100%')
  }
}
```
## font.getSystemFontList<sup>10+</sup>

getSystemFontList(): Array\<string>

Obtains the list of supported fonts.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                | Description              |
| -------------------- | ----------------- |
| Array\<string>       | List of supported fonts. |

**Example**

```ts
// xxx.ets
import font from '@ohos.font';

@Entry
@Component
struct FontExample {
  fontList: Array<string> = new Array<string>();
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

## font.getFontByName<sup>10+</sup>

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

## FontInfo<sup>10+</sup>

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name           | Type   | Mandatory | Description                      |
| -------------- | ------- | ------------------------- | ------------------------- |
| path           | string  | Yes| File path of the system font.       |
| postScriptName | string  | Yes| PostScript name of the system font.|
| fullName       | string  | Yes| Name of the system font.          |
| family         | string  | Yes| Family of the system font.      |
| subfamily      | string  | Yes| Subfamily of the system font.     |
| weight         | number  | Yes| Weight of the system font.       |
| width          | number  | Yes| Width of the system font.   |
| italic         | boolean | Yes| Whether the system font is italic.         |
| monoSpace      | boolean | Yes| Whether the system font is monospaced.        |
| symbolic       | boolean | Yes| Whether the system font supports symbols. |

**Example**

```ts
// xxx.ets
import font from '@ohos.font';

@Entry
@Component
struct FontExample {
  fontList: Array<string> = new Array<string>();
  fontInfo: font.FontInfo = font.getFontByName('');
  build() {
    Column() {
      Button("getFontByName")
        .onClick(() => {
          this.fontInfo = font.getFontByName('Sans Italic')
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
