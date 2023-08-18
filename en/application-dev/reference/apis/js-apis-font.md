# @ohos.font (Custom Font Registration)

The **font** module provides APIs for registering custom fonts.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>

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
| familyName | string | Yes   | Name of the custom font to register.  |
| familySrc  | string | Yes   | Path of the custom font to register.|

**Example**

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
      familySrc: '/font/medium.ttf' // The font file is at the same level as the pages directory.
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
