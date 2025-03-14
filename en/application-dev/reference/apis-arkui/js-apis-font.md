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
import { font } from '@kit.ArkUI'
```

## font.registerFont

registerFont(options: FontOptions): void

Registers a custom font with the font manager.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                         | Mandatory  | Description         |
| ------- | --------------------------- | ---- | ----------- |
| options | [FontOptions](#fontoptions) | Yes   | Information about the custom font to register.|

## FontOptions

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type    | Mandatory  | Description          |
| ---------- | ------ | ---- | ------------ |
| familyName | string\| [Resource](arkui-ts/ts-types.md#resource)<sup>10+</sup> | Yes   | Name of the custom font to register.  |
| familySrc  | string\| [Resource](arkui-ts/ts-types.md#resource)<sup>10+</sup> | Yes   | Path of the custom font to register.|

**Example**

> **NOTE**
>
> You are advised to use the [getFont](./js-apis-arkui-UIContext.md#getfont) API in [UIContext](./js-apis-arkui-UIContext.md#uicontext) to obtain the [Font](./js-apis-arkui-UIContext.md#font) object associated with the current UI context.

```ts
// xxx.ets
import { font } from '@kit.ArkUI';

@Entry
@Component
struct FontExample {
  @State message: string = 'Hello World';
  // iconFont example, where 0000 is the Unicode character of the specified icon. You need to obtain the Unicode character from the TTF file of the registered iconFont.
  @State unicode: string = '\u0000';
  @State codePoint: string = String.fromCharCode(0x0000);

  aboutToAppear() {
    // Both familyName and familySrc support the Resource type.
    font.registerFont({
      // You are advised to use this.getUIContext().getFont().registerFont().
      familyName: $r('app.string.font_name'),
      familySrc: $r('app.string.font_src')
    })

    // familySrc supports the $rawfile type.
    font.registerFont({
      familyName: 'mediumRawFile',
      familySrc: $rawfile('font/medium.ttf')
    })

    // Register iconFont.
    font.registerFont({
      familyName: 'iconFont',
      familySrc: '/font/iconFont.ttf'
    })

    // Both familyName and familySrc support the string type.
    font.registerFont({
      familyName: 'medium',
      familySrc: '/font/medium.ttf' // The font folder is at the same level as the pages folder.
    })
  }

  build() {
    Column() {
      Text(this.message)
        .align(Alignment.Center)
        .fontSize(20)
        .fontFamily('medium') // medium: name of the custom font to register. (Registered fonts such as $r('app.string.mediumFamilyName') and 'mediumRawFile' can also be used.)

      // Two methods of using iconFont
      Text(this.unicode)
        .align(Alignment.Center)
        .fontSize(20)
        .fontFamily('iconFont')
      Text(this.codePoint)
        .align(Alignment.Center)
        .fontSize(20)
        .fontFamily('iconFont')
    }.width('100%')
  }
}
```
> **NOTE**
>
> To use custom fonts globally in an application, register the fonts through the [windowStage.loadContent](js-apis-window.md#loadcontent9) API in the [onWindowStageCreate](../apis-ability-kit/js-apis-app-ability-uiAbility.md#uiabilityonwindowstagecreate) lifecycle callback in the **EntryAbility.ets** file.
>
> In HSP projects, avoid using relative paths to register custom fonts. For details, see [Accessing Resources in an HSP Through $r](../../quick-start/in-app-hsp.md).

## font.getSystemFontList<sup>10+</sup>

getSystemFontList(): Array\<string>

Obtains the system font list.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                | Description              |
| -------------------- | ----------------- |
| Array\<string>       | List of supported fonts. |

>  **NOTE**
>
>  This API takes effect only on 2-in-1 devices.

**Example**

> **NOTE**
>
> You are advised to use the [getFont](./js-apis-arkui-UIContext.md#getfont) API in [UIContext](./js-apis-arkui-UIContext.md#uicontext) to obtain the [Font](./js-apis-arkui-UIContext.md#font) object associated with the current UI context.

```ts
// xxx.ets
import { font } from '@kit.ArkUI';

@Entry
@Component
struct FontExample {
  fontList: Array<string> = new Array<string>();

  build() {
    Column() {
      Button("getSystemFontList")
        .width('60%')
        .height('6%')
        .onClick(() => {
          this.fontList = font.getSystemFontList() // You are advised to use the this.getUIContext().getFont().getSystemFontList() API.
        })
    }.width('100%')
  }
}
```

## font.getFontByName<sup>10+</sup>

getFontByName(fontName: string): FontInfo

Obtains information about a system font based on the font name.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type     | Mandatory   | Description         |
| ---------- | --------- | ------- | ------------ |
| fontName   | string    | Yes     | System font name.|

**Return value**

| Type            | Description                         |
| ---------------- | ---------------------------- |
| FontInfo         | Information about the system font.    |

## FontInfo<sup>10+</sup>

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name           | Type   | Mandatory | Description                      |
| -------------- | ------- | ------------------------- | ------------------------- |
| path           | string  | Yes| File path of the system font.       |
| postScriptName | string  | Yes| PostScript name of the system font.|
| fullName       | string  | Yes| Name of the system font.          |
| family         | string  | Yes| Family of the system font.      |
| subfamily      | string  | Yes| Subfamily of the system font.     |
| weight         | number  | Yes| Weight of the system font, in px.       |
| width          | number  | Yes| Width of the system font, in px.   |
| italic         | boolean | Yes| Whether the system font is italic.         |
| monoSpace      | boolean | Yes| Whether the system font is monospaced.        |
| symbolic       | boolean | Yes| Whether the system font supports symbols. |

**Example**

> **NOTE**
>
> You are advised to use the [getFont](./js-apis-arkui-UIContext.md#getfont) API in [UIContext](./js-apis-arkui-UIContext.md#uicontext) to obtain the [Font](./js-apis-arkui-UIContext.md#font) object associated with the current UI context.

```ts
// xxx.ets
import { font } from '@kit.ArkUI';

@Entry
@Component
struct FontExample {
  fontList: Array<string> = new Array<string>();
  fontInfo: font.FontInfo = font.getFontByName('');

  build() {
    Column() {
      Button("getFontByName")
        .onClick(() => {
          this.fontInfo =
            font.getFontByName('HarmonyOS Sans Italic') // You are advised to use this.getUIContext().getFont().getFontByName().
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

## font.getUIFontConfig<sup>11+</sup>
getUIFontConfig() : UIFontConfig

Obtains the UI font configuration of the system.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**
| Type            | Description                         |
| ---------------- | ---------------------------- |
| [UIFontConfig](#uifontconfig11)     | UI font configuration of the system.         |

## UIFontConfig<sup>11+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full
| Name           | Type   | Mandatory | Description                      |
| -------------- | ------- | ------------------------- | ------------------------- |
| fontDir        | Array\<string>  | Yes| Path to the system font file.     |
| generic | Array\<[UIFontGenericInfo](#uifontgenericinfo11)>  | Yes| List of supported generic font families.|
| fallbackGroups       | Array\<[UIFontFallbackGroupInfo](#uifontfallbackgroupinfo11)>  | Yes| List of alternate generic font families.          |

## UIFontGenericInfo<sup>11+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full
| Name           | Type   | Mandatory | Description                      |
| -------------- | ------- | ------------------------- | ------------------------- |
| family        | string | Yes| Font family name, which is the value of **family** specified in the font file.     |
| alias        | Array\<[UIFontAliasInfo](#uifontaliasinfo11)>  | Yes| Alias list.|
| adjust       | Array\<[UIFontAdjustInfo](#uifontadjustinfo11)>  | Yes| Weight of the font when displayed, which corresponds to the original weight.|

## UIFontFallbackGroupInfo<sup>11+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full
| Name           | Type   | Mandatory | Description                      |
| -------------- | ------- | ------------------------- | ------------------------- |
| fontSetName  | string | Yes| Name of the font family corresponding to the alternate fonts.     |
| fallback        | Array\<[UIFontFallbackInfo](#uifontfallbackinfo11)>  | Yes| Alternate fonts for the font family. If **fontSetName** is **""**, it indicates that the fonts can be used as alternate fonts for all font families.|

## UIFontAliasInfo<sup>11+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full
| Name           | Type   | Mandatory | Description                      |
| -------------- | ------- | ------------------------- | ------------------------- |
| name          | string  | Yes| Alias name.     |
| weight        | number  | Yes| Weight of the fonts included in the font family. If the value is greater than 0, the font family contains only the fonts with the specified weight. If the value is 0, the font family contains all fonts.|

## UIFontAdjustInfo<sup>11+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full
| Name           | Type   | Mandatory | Description                      |
| -------------- | ------- | ------------------------- | ------------------------- |
| weight        | number  | Yes| Original weight of the font.     |
| to            | number  | Yes| Weight of the font displayed in the application.|

## UIFontFallbackInfo<sup>11+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full
| Name           | Type   | Mandatory | Description                      |
| -------------- | ------- | ------------------------- | ------------------------- |
| language       | string  | Yes| Language supported by the font family. The language format is BCP 47.   |
| family         | string  | Yes| Font family name, which is the value of **family** specified in the font file.|

**Example**

```ts
// xxx.ets
import { font } from '@kit.ArkUI';

@Entry
@Component
struct FontExample {
  build() {
    Column() {
      Button("getUIFontConfig")
        .width('60%')
        .height('6%')
        .margin(50)
        .onClick(() => {
          let fontConfig = font.getUIFontConfig();
          console.log("font-dir -----------" + String(fontConfig.fontDir.length));
          for (let i = 0; i < fontConfig.fontDir.length; i++) {
            console.log(fontConfig.fontDir[i]);
          }
          console.log("generic-------------" + String(fontConfig.generic.length));
          for (let i = 0; i < fontConfig.generic.length; i++) {
            console.log("family:" + fontConfig.generic[i].family);
            for (let j = 0; j < fontConfig.generic[i].alias.length; j++) {
              console.log(fontConfig.generic[i].alias[j].name + " " + fontConfig.generic[i].alias[j].weight);
            }
            for (let j = 0; j < fontConfig.generic[i].adjust.length; j++) {
              console.log(fontConfig.generic[i].adjust[j].weight + " " + fontConfig.generic[i].adjust[j].to);
            }
          }
          console.log("fallback------------" + String(fontConfig.fallbackGroups.length));
          for (let i = 0; i < fontConfig.fallbackGroups.length; i++) {
            console.log("fontSetName:" + fontConfig.fallbackGroups[i].fontSetName);
            for (let j = 0; j < fontConfig.fallbackGroups[i].fallback.length; j++) {
              console.log("language:" + fontConfig.fallbackGroups[i].fallback[j].language + " family:" +
              fontConfig.fallbackGroups[i].fallback[j].family);
            }
          }
        })
    }.width('100%')
  }
}
```
