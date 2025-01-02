# @ohos.font (注册自定义字体)

本模块提供注册自定义字体。

> **说明**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块功能依赖UI的执行上下文，不可在UI上下文不明确的地方使用，参见[UIContext](./js-apis-arkui-UIContext.md#uicontext)说明。
>
> 从API version 10开始，可以通过使用[UIContext](./js-apis-arkui-UIContext.md#uicontext)中的[getFont](./js-apis-arkui-UIContext.md#getfont)方法获取当前UI上下文关联的[Font](./js-apis-arkui-UIContext.md#font)对象。

## 导入模块

```ts
import { font } from '@kit.ArkUI'
```

## font.registerFont

registerFont(options: FontOptions): void

在字体管理中注册自定义字体。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                          | 必填   | 说明          |
| ------- | --------------------------- | ---- | ----------- |
| options | [FontOptions](#fontoptions) | 是    | 注册的自定义字体信息。 |

## FontOptions

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称         | 类型     | 必填   | 说明           |
| ---------- | ------ | ---- | ------------ |
| familyName | string\| [Resource](arkui-ts/ts-types.md#resource)<sup>10+</sup> | 是    | 设置注册的字体名称。   |
| familySrc  | string\| [Resource](arkui-ts/ts-types.md#resource)<sup>10+</sup> | 是    | 设置注册字体文件的路径。 |

**示例：**

> **说明**
>
> 推荐通过使用[UIContext](./js-apis-arkui-UIContext.md#uicontext)中的[getFont](./js-apis-arkui-UIContext.md#getfont)方法获取当前UI上下文关联的[Font](./js-apis-arkui-UIContext.md#font)对象。

```ts
// xxx.ets
import { font } from '@kit.ArkUI';

@Entry
@Component
struct FontExample {
  @State message: string = 'Hello World'

  // iconFont示例，假设0000为指定icon的Unicode，实际需要开发者从注册的iconFont的ttf文件里面获取Unicode
  @State unicode: string = '\u0000'
  @State codePoint: string = String.fromCharCode(0x0000)

  aboutToAppear() {
    // familyName和familySrc都支持系统Resource
    font.registerFont({ // 建议使用 this.getUIContext().getFont().registerFont()接口
      familyName: $r('app.string.font_name'),
      familySrc: $r('app.string.font_src')
    })

    // familySrc支持RawFile
    font.registerFont({
      familyName: 'mediumRawFile',
      familySrc: $rawfile('font/medium.ttf')
    })

    // 注册iconFont
    font.registerFont({
      familyName: 'iconFont',
      familySrc: '/font/iconFont.ttf'
    })

    // familyName和familySrc都支持string
    font.registerFont({
      familyName: 'medium',
      familySrc: '/font/medium.ttf' // font文件夹与pages目录同级
    })
  }

  build() {
    Column() {
      Text(this.message)
        .align(Alignment.Center)
        .fontSize(20)
        .fontFamily('medium') // medium：注册自定义字体的名字（$r('app.string.mediumFamilyName')、'mediumRawFile'等已注册字体也能正常使用）

      // 使用iconFont的两种方式
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
> **说明：**
>
> 应用若需全局使用自定义字体，请在EntryAbility.ets文件的[onWindowStageCreate](../apis-ability-kit/js-apis-app-ability-uiAbility.md#uiabilityonwindowstagecreate)生命周期中，通过[windowStage.loadContent](js-apis-window.md#loadcontent9)回调注册。
>
> 在HSP工程中，不推荐采用相对路径的方式注册自定义字体，详见[HSP资源引用](../../quick-start/in-app-hsp.md#通过$r访问hsp中的资源)。

## font.getSystemFontList<sup>10+</sup>

getSystemFontList(): Array\<string>

获取风格字体列表。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                 | 说明               |
| -------------------- | ----------------- |
| Array\<string>       | 系统的字体名列表。  |

>  **说明：**
>
>  该接口仅在2in1和移动设备上生效。

**示例：**

> **说明**
>
> 推荐通过使用[UIContext](./js-apis-arkui-UIContext.md#uicontext)中的[getFont](./js-apis-arkui-UIContext.md#getfont)方法获取当前UI上下文关联的[Font](./js-apis-arkui-UIContext.md#font)对象。

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
        .onClick(()=>{
          this.fontList = font.getSystemFontList() // 建议使用 this.getUIContext().getFont().getSystemFontList()接口
        })
    }.width('100%')
  }
}
```

## font.getFontByName<sup>10+</sup>

getFontByName(fontName: string): FontInfo

根据传入的系统字体名称获取系统字体的相关信息。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型      | 必填    | 说明          |
| ---------- | --------- | ------- | ------------ |
| fontName   | string    | 是      | 系统的字体名。 |

**返回值：**

| 类型             | 说明                          |
| ---------------- | ---------------------------- |
| FontInfo         | 字体的详细信息。     |

## FontInfo<sup>10+</sup>

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称            | 类型    | 必填  | 说明                       |
| -------------- | ------- | ------------------------- | ------------------------- |
| path           | string  | 是 | 系统字体的文件路径。        |
| postScriptName | string  | 是 | 系统字体的postScript名称。 |
| fullName       | string  | 是 | 系统字体的名称。           |
| family         | string  | 是 | 系统字体的字体家族。       |
| subfamily      | string  | 是 | 系统字体的子字体家族。      |
| weight         | number  | 是 | 系统字体的粗细程度，单位px。        |
| width          | number  | 是 | 系统字体的宽窄风格属性，单位px。    |
| italic         | boolean | 是 | 系统字体是否倾斜。          |
| monoSpace      | boolean | 是 | 系统字体是否紧凑。         |
| symbolic       | boolean | 是 | 系统字体是否支持符号字体。  |

**示例：**

> **说明**
>
> 推荐通过使用[UIContext](./js-apis-arkui-UIContext.md#uicontext)中的[getFont](./js-apis-arkui-UIContext.md#getfont)方法获取当前UI上下文关联的[Font](./js-apis-arkui-UIContext.md#font)对象。

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
          this.fontInfo = font.getFontByName('HarmonyOS Sans Italic') // 建议使用 this.getUIContext().getFont().getFontByName()接口
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

获取系统的UI字体配置。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**
| 类型             | 说明                          |
| ---------------- | ---------------------------- |
| [UIFontConfig](#uifontconfig11)     | 系统的UI字体配置信息。          |

## UIFontConfig<sup>11+</sup>

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full
| 名称            | 类型    | 必填  | 说明                       |
| -------------- | ------- | ------------------------- | ------------------------- |
| fontDir        | Array\<string>  | 是 | 系统字体文件所在的路径。      |
| generic | Array\<[UIFontGenericInfo](#uifontgenericinfo11)>  | 是 | 系统所支持的通用字体集列表。 |
| fallbackGroups       | Array\<[UIFontFallbackGroupInfo](#uifontfallbackgroupinfo11)>  | 是 | 备用字体集。           |

## UIFontGenericInfo<sup>11+</sup>

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full
| 名称            | 类型    | 必填  | 说明                       |
| -------------- | ------- | ------------------------- | ------------------------- |
| family        | string | 是 | 字体集名，字体文件中指定的"family"值。      |
| alias        | Array\<[UIFontAliasInfo](#uifontaliasinfo11)>  | 是 | 别名列表。 |
| adjust       | Array\<[UIFontAdjustInfo](#uifontadjustinfo11)>  | 是 | 字体原本的weight值对应需显示的值。 |

## UIFontFallbackGroupInfo<sup>11+</sup>

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full
| 名称            | 类型    | 必填  | 说明                       |
| -------------- | ------- | ------------------------- | ------------------------- |
| fontSetName  | string | 是 | 备用字体集所对应的字体集名称。      |
| fallback        | Array\<[UIFontFallbackInfo](#uifontfallbackinfo11)>  | 是 | 表示以下列表为该字体集的备用字体，如果fontSetName为""，表示可以作为所有字体集的备用字体。 |

## UIFontAliasInfo<sup>11+</sup>

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full
| 名称            | 类型    | 必填  | 说明                       |
| -------------- | ------- | ------------------------- | ------------------------- |
| name          | string  | 是 | 别名名称。      |
| weight        | number  | 是 | 当weight>0时表示此字体集只包含所指定weight的字体，当weight=0时，表示此字体集包含所有字体。 |

## UIFontAdjustInfo<sup>11+</sup>

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full
| 名称            | 类型    | 必填  | 说明                       |
| -------------- | ------- | ------------------------- | ------------------------- |
| weight        | number  | 是 | 字体原本的weight值。      |
| to            | number  | 是 | 字体在应用中显示的weight值。 |

## UIFontFallbackInfo<sup>11+</sup>

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full
| 名称            | 类型    | 必填  | 说明                       |
| -------------- | ------- | ------------------------- | ------------------------- |
| language       | string  | 是 | 字体集所支持的语言类型，语言格式为bcp47。    |
| family         | string  | 是 | 字体集名，字体文件中指定的"family"值。 |

**示例：**

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
        .onClick(()=>{
          let fontConfig = font.getUIFontConfig();
          console.log("font-dir -----------" + String(fontConfig.fontDir.length));
          for (let i = 0; i < fontConfig.fontDir.length; i ++) {
            console.log(fontConfig.fontDir[i]);
          }
          console.log("generic-------------" + String(fontConfig.generic.length));
          for (let i = 0; i < fontConfig.generic.length; i ++){
            console.log("family:" + fontConfig.generic[i].family);
            for (let j = 0; j < fontConfig.generic[i].alias.length; j ++){
              console.log(fontConfig.generic[i].alias[j].name + " " + fontConfig.generic[i].alias[j].weight);
            }
            for (let j = 0; j < fontConfig.generic[i].adjust.length; j ++){
              console.log(fontConfig.generic[i].adjust[j].weight + " " + fontConfig.generic[i].adjust[j].to);
            }
          }
          console.log("fallback------------" + String(fontConfig.fallbackGroups.length));
          for (let i = 0; i < fontConfig.fallbackGroups.length; i ++){
            console.log("fontSetName:" + fontConfig.fallbackGroups[i].fontSetName);
            for (let j = 0; j < fontConfig.fallbackGroups[i].fallback.length; j ++){
              console.log("language:" + fontConfig.fallbackGroups[i].fallback[j].language + " family:" + fontConfig.fallbackGroups[i].fallback[j].family);
            }
          }
        })
    }.width('100%')
  }
}
```
