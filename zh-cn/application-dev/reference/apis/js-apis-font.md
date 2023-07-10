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
import font from '@ohos.font'
```

## font.registerFont

registerFont(options: FontOptions): void

在字体管理中注册自定义字体。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名     | 类型                          | 必填   | 说明          |
| ------- | --------------------------- | ---- | ----------- |
| options | [FontOptions](#fontoptions) | 是    | 注册的自定义字体信息。 |

## FontOptions

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称         | 类型     | 必填   | 说明           |
| ---------- | ------ | ---- | ------------ |
| familyName | string\| [Resource](../arkui-ts/ts-types.md#resource)<sup>10+</sup> | 是    | 设置注册的字体名称。   |
| familySrc  | string\| [Resource](../arkui-ts/ts-types.md#resource)<sup>10+</sup> | 是    | 设置注册字体文件的路径。 |

**示例：**

```ts
// xxx.ets
import font from '@ohos.font';

@Entry
@Component
struct FontExample {
  @State message: string = '你好，世界'

  aboutToAppear() {
    // familyName和familySrc都支持string
    font.registerFont({
      familyName: 'medium',
      familySrc: '/font/medium.ttf'
    })

    // familyName和familySrc都支持系统Resource
    font.registerFont({
      familyName: $r('app.string.mediumFamilyName'),
      familySrc: $r('app.string.mediumFamilySrc')
    })

    // familySrc支持RawFile
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
        .fontFamily('medium') // medium：注册自定义字体的名字（$r('app.string.mediumFamilyName')、'mediumRawFile'等已注册字体也能正常使用）
        .height('100%')
    }.width('100%')
  }
}
```
## font.getSystemFontList<sup>10+</sup>

getSystemFontList(): Array\<string>

获取系统支持的字体名称列表。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                 | 说明               |
| -------------------- | ----------------- |
| Array\<string>       | 系统的字体名列表。  |

**示例：**

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

## font.getFontByName<sup>10+</sup>

getFontByName(fontName: string): FontInfo;

根据传入的系统字体名称获取系统字体的相关信息。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名      | 类型      | 必填    | 说明          |
| ---------- | --------- | ------- | ------------ |
| fontName   | string    | 是      | 系统的字体名。 |

**返回值：**

| 类型             | 说明                          |
| ---------------- | ---------------------------- |
| FontInfo         | 字体的详细信息                 |

## FontInfo

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称            | 类型    | 必填  | 说明                       |
| -------------- | ------- | ------------------------- | ------------------------- |
| path           | string  | 是 | 系统字体的文件路径。        |
| postScriptName | string  | 是 | 系统字体的postScript名称。 |
| fullName       | string  | 是 | 系统字体的名称。           |
| family         | string  | 是 | 系统字体的字体家族。       |
| subfamily      | string  | 是 | 系统字体的子字体家族。      |
| weight         | number  | 是 | 系统字体的粗细程度。        |
| width          | number  | 是 | 系统字体的宽窄风格属性。    |
| italic         | boolean | 是 | 系统字体是否倾斜。          |
| monoSpace      | boolean | 是 | 系统字体是否紧凑。         |
| symbolic       | boolean | 是 | 系统字体是否支持符号字体。  |

**示例：**

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