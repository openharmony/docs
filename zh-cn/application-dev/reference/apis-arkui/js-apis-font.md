# @ohos.font (注册自定义字体)

本模块提供注册自定义字体。

> **说明**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块功能依赖UI的执行上下文，不可在[UI上下文不明确](../../ui/arkts-global-interface.md#ui上下文不明确)的地方使用，参见[UIContext](./arkts-apis-uicontext-uicontext.md)说明。

## 导入模块

```ts
import { font } from '@kit.ArkUI';
```

## font.registerFont<sup>(deprecated)</sup>

registerFont(options: FontOptions): void

在字体管理中注册自定义字体。

该接口为异步接口，不支持并发调用。

> **说明：**
>
> 从API version 18开始废弃，建议使用[UIContext](arkts-apis-uicontext-uicontext.md)中的[getFont](arkts-apis-uicontext-uicontext.md#getfont)获取[Font](arkts-apis-uicontext-font.md)实例，再通过此实例调用替代方法[registerFont](arkts-apis-uicontext-font.md#registerfont)。
>
> 从API version 10开始，可以通过使用[UIContext](arkts-apis-uicontext-uicontext.md)中的[getFont](arkts-apis-uicontext-uicontext.md#getfont)方法获取当前UI上下文关联的[Font](arkts-apis-uicontext-font.md)对象。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                          | 必填   | 说明          |
| ------- | --------------------------- | ---- | ----------- |
| options | [FontOptions](#fontoptions) | 是    | 注册的自定义字体信息。 |

## FontOptions

注册的自定义字体信息。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称         | 类型     | 必填   | 说明           |
| ---------- | ------ | ---- | ------------ |
| familyName | string \| [Resource](arkui-ts/ts-types.md#resource)<sup>10+</sup> | 是    | 设置注册的字体名称。   |
| familySrc  | string \| [Resource](arkui-ts/ts-types.md#resource)<sup>10+</sup> | 是    | 设置注册字体文件的路径。 |

**示例：**

> **说明**
>
> 直接使用font可能导致[UI上下文不明确](../../ui/arkts-global-interface.md#ui上下文不明确)的问题，推荐通过使用[UIContext](./arkts-apis-uicontext-uicontext.md)中的[getFont](./arkts-apis-uicontext-uicontext.md#getfont)方法获取当前UI上下文关联的[Font](arkts-apis-uicontext-font.md)对象。

```ts
// xxx.ets
@Entry
@Component
struct FontExample {
  @State message: string = 'Hello World';
  // iconFont示例，假设0000为指定icon的Unicode，实际需要开发者从注册的iconFont的ttf文件里面获取Unicode
  @State unicode: string = '\u0000';
  @State codePoint: string = String.fromCharCode(0x0000);
  private uiContext: UIContext = this.getUIContext();

  aboutToAppear() {
    // familyName和familySrc都支持系统Resource
    this.uiContext.getFont().registerFont({
      // 建议使用 this.getUIContext().getFont().registerFont()接口
      // 'app.string.font_name'和'app.string.font_src'仅作示例，请替换为实际使用资源字符串
      familyName: $r('app.string.font_name'),
      familySrc: $r('app.string.font_src')
    })

    // familySrc支持RawFile
    this.uiContext.getFont().registerFont({
      familyName: 'mediumRawFile',
      familySrc: $rawfile('font/medium.ttf')// 'font/medium.ttf'仅作示例，请替换为实际使用资源字体文件
    })

    // 注册iconFont
    this.uiContext.getFont().registerFont({
      familyName: 'iconFont',
      familySrc: '/font/iconFont.ttf'
    })

    // familyName和familySrc都支持string
    this.uiContext.getFont().registerFont({
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
> 应用若需全局使用自定义字体，请在EntryAbility.ets文件的[onWindowStageCreate](../apis-ability-kit/js-apis-app-ability-uiAbility.md#onwindowstagecreate)生命周期中，通过[windowStage.loadContent](arkts-apis-window-Window.md#loadcontent9)回调注册。
>
> 在HSP工程中，不推荐采用相对路径的方式注册自定义字体，详见[通过$r访问HSP中的资源](../../quick-start/in-app-hsp.md)。

## font.getSystemFontList<sup>(deprecated)</sup>

getSystemFontList(): Array\<string>

获取风格字体列表。

> **说明：**
>
> 从API version 10开始支持，从API version 18开始废弃，建议使用[UIContext](arkts-apis-uicontext-uicontext.md)中的[getFont](arkts-apis-uicontext-uicontext.md#getfont)获取[Font](arkts-apis-uicontext-font.md)实例，再通过此实例调用替代方法[getSystemFontList](arkts-apis-uicontext-font.md#getsystemfontlist)。
>
> 从API version 10开始，可以通过使用[UIContext](arkts-apis-uicontext-uicontext.md)中的[getFont](arkts-apis-uicontext-uicontext.md#getfont)方法获取当前UI上下文关联的[Font](arkts-apis-uicontext-font.md)对象。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                 | 说明               |
| -------------------- | ----------------- |
| Array\<string>       | 系统的字体名列表。  |

>  **说明：**
>
>  该接口仅在2in1和移动设备上生效。<br/>为获取系统最新支持字体列表数据，推荐使用[getSystemFontFullNamesByType](../apis-arkgraphics2d/js-apis-graphics-text.md#textgetsystemfontfullnamesbytype14)接口。

**示例：**

> **说明**
>
> 直接使用font可能导致[UI上下文不明确](../../ui/arkts-global-interface.md#ui上下文不明确)的问题，推荐通过使用[UIContext](arkts-apis-uicontext-uicontext.md)中的[getFont](arkts-apis-uicontext-uicontext.md#getfont)方法获取当前UI上下文关联的[Font](arkts-apis-uicontext-font.md)对象。

<!--deprecated_code_no_check-->

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
          this.fontList = font.getSystemFontList(); // 建议使用 this.getUIContext().getFont().getSystemFontList()接口
        })
    }.width('100%')
  }
}
```

## font.getFontByName<sup>(deprecated)</sup>

getFontByName(fontName: string): FontInfo

根据传入的系统字体名称获取系统字体的相关信息。

> **说明：**
>
> 从API version 10开始支持，从API version 18开始废弃，建议使用[UIContext](arkts-apis-uicontext-uicontext.md)中的[getFont](arkts-apis-uicontext-uicontext.md#getfont)获取[Font](arkts-apis-uicontext-font.md)实例，再通过此实例调用替代方法[getFontByName](arkts-apis-uicontext-font.md#getfontbyname)。
>
> 从API version 10开始，可以通过使用[UIContext](arkts-apis-uicontext-uicontext.md)中的[getFont](arkts-apis-uicontext-uicontext.md#getfont)方法获取当前UI上下文关联的[Font](arkts-apis-uicontext-font.md)对象。

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

字体的详细信息。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称            | 类型    | 必填  | 说明                       |
| -------------- | ------- | ------------------------- | ------------------------- |
| path           | string  | 是 | 系统字体的文件路径。        |
| postScriptName | string  | 是 | 系统字体的postScript名称。 |
| fullName       | string  | 是 | 系统字体的名称。           |
| family         | string  | 是 | 系统字体的字体家族。       |
| subfamily      | string  | 是 | 系统字体的子字体家族。      |
| weight         | number  | 是 | 系统字体的字重。<br/>取值范围：[0,8]，取值间隔为1，分别对应[FontWeight](../apis-arkgraphics2d/js-apis-graphics-text.md#fontweight)枚举中的值。<br/>默认值：0        |
| width          | number  | 是 | 系统字体的宽度。<br/>取值范围：[1,9]，取值间隔为1，分别对应[FontWidth](../apis-arkgraphics2d/js-apis-graphics-text.md#fontwidth)枚举中的值。    |
| italic         | boolean | 是 | 系统字体是否倾斜。<br/>默认值：false<br/>值为true，表示斜体字体，值为false，表示非斜体字体。          |
| monoSpace      | boolean | 是 | 系统字体是否紧凑。<br/>默认值：false<br/>值为true，表示等宽字体，值为false，表示非等宽字体。         |
| symbolic       | boolean | 是 | 系统字体是否支持符号字体。<br/>默认值：false<br/>值为true，表示支持符号字体，值为false，表示不支持符号字体。  |

**示例：**

> **说明**
>
> 直接使用font可能导致实例不明确的问题，推荐通过使用[UIContext](./arkts-apis-uicontext-uicontext.md)中的[getFont](./arkts-apis-uicontext-uicontext.md#getfont)方法获取当前UI上下文关联的[Font](arkts-apis-uicontext-font.md)对象。

```ts
// xxx.ets
import { font } from '@kit.ArkUI';

@Entry
@Component
struct FontExample {
  fontList: Array<string> = new Array<string>();
  uiFont = this.getUIContext().getFont();
  fontInfo: font.FontInfo = this.uiFont.getFontByName(''); // 建议使用 this.getUIContext().getFont().getFontByName()接口

  build() {
    Column() {
      Button("getFontByName")
        .onClick(() => {
          this.fontInfo =
            this.uiFont.getFontByName('HarmonyOS Sans Italic');
          console.info("getFontByName(): path = " + this.fontInfo.path);
          console.info("getFontByName(): postScriptName = " + this.fontInfo.postScriptName);
          console.info("getFontByName(): fullName = " + this.fontInfo.fullName);
          console.info("getFontByName(): Family = " + this.fontInfo.family);
          console.info("getFontByName(): Subfamily = " + this.fontInfo.subfamily);
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

系统的UI字体配置信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full
| 名称            | 类型    | 必填  | 说明                       |
| -------------- | ------- | ------------------------- | ------------------------- |
| fontDir        | Array\<string>  | 是 | 系统字体文件所在的路径。      |
| generic | Array\<[UIFontGenericInfo](#uifontgenericinfo11)>  | 是 | 系统所支持的通用字体集列表。 |
| fallbackGroups       | Array\<[UIFontFallbackGroupInfo](#uifontfallbackgroupinfo11)>  | 是 | 备用字体集。           |

## UIFontGenericInfo<sup>11+</sup>

系统所支持的通用字体集列表。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full
| 名称            | 类型    | 必填  | 说明                       |
| -------------- | ------- | ------------------------- | ------------------------- |
| family        | string | 是 | 字体集名，字体文件中指定的"family"值。      |
| alias        | Array\<[UIFontAliasInfo](#uifontaliasinfo11)>  | 是 | 别名列表。 |
| adjust       | Array\<[UIFontAdjustInfo](#uifontadjustinfo11)>  | 是 | 字体原本的weight值对应需显示的值。 |

## UIFontFallbackGroupInfo<sup>11+</sup>

备用字体集。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full
| 名称            | 类型    | 必填  | 说明                       |
| -------------- | ------- | ------------------------- | ------------------------- |
| fontSetName  | string | 是 | 备用字体集所对应的字体集名称。      |
| fallback        | Array\<[UIFontFallbackInfo](#uifontfallbackinfo11)>  | 是 | 表示以下列表为该字体集的备用字体，如果fontSetName为""，表示可以作为所有字体集的备用字体。 |

## UIFontAliasInfo<sup>11+</sup>

别名列表。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full
| 名称            | 类型    | 必填  | 说明                       |
| -------------- | ------- | ------------------------- | ------------------------- |
| name          | string  | 是 | 别名名称。      |
| weight        | number  | 是 | 当weight>0时表示此字体集只包含所指定weight的字体，当weight=0时，表示此字体集包含所有字体。<br/>可返回的值有0、100、400、700、900。 |

## UIFontAdjustInfo<sup>11+</sup>

字体原本的weight值和显示实际值的映射列表。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full
| 名称            | 类型    | 必填  | 说明                       |
| -------------- | ------- | ------------------------- | ------------------------- |
| weight        | number  | 是 | 字体原本的weight值。<br/>可返回的值有50、80、100、200。      |
| to            | number  | 是 | 字体在应用中显示的weight值。<br/>可返回的值有100、400、700、900。 |

## UIFontFallbackInfo<sup>11+</sup>

该字体集的备用字体。

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
        .onClick(() => {
          let fontConfig = font.getUIFontConfig();
          console.info("font-dir -----------" + String(fontConfig.fontDir.length));
          for (let i = 0; i < fontConfig.fontDir.length; i++) {
            console.info(fontConfig.fontDir[i]);
          }
          console.info("generic-------------" + String(fontConfig.generic.length));
          for (let i = 0; i < fontConfig.generic.length; i++) {
            console.info("family:" + fontConfig.generic[i].family);
            for (let j = 0; j < fontConfig.generic[i].alias.length; j++) {
              console.info(fontConfig.generic[i].alias[j].name + " " + fontConfig.generic[i].alias[j].weight);
            }
            for (let j = 0; j < fontConfig.generic[i].adjust.length; j++) {
              console.info(fontConfig.generic[i].adjust[j].weight + " " + fontConfig.generic[i].adjust[j].to);
            }
          }
          console.info("fallback------------" + String(fontConfig.fallbackGroups.length));
          for (let i = 0; i < fontConfig.fallbackGroups.length; i++) {
            console.info("fontSetName:" + fontConfig.fallbackGroups[i].fontSetName);
            for (let j = 0; j < fontConfig.fallbackGroups[i].fallback.length; j++) {
              console.info("language:" + fontConfig.fallbackGroups[i].fallback[j].language + " family:" +
              fontConfig.fallbackGroups[i].fallback[j].family);
            }
          }
        })
    }.width('100%')
  }
}
```
