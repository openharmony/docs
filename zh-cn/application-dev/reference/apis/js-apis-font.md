# @ohos.font (注册自定义字体)

本模块提供注册自定义字体。

> **说明**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口为系统接口。

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

| 名称         | 类型     | 必填   | 说明           |
| ---------- | ------ | ---- | ------------ |
| familyName | string | 是    | 设置注册的字体名称。   |
| familySrc  | string | 是    | 设置注册字体文件的路径。 |

## 示例

```ts
// xxx.ets
import font from '@ohos.font';

@Entry
@Component
struct FontExample {
  @State message: string = '你好，世界'

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
        .fontFamily('medium') // medium：注册自定义字体的名字
        .height('100%')
    }.width('100%')
  }
}
```
## font.getSystemFontList

getSystemFontList(): Array\<string>

获取系统支持的字体名称列表。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                 | 说明               |
| -------------------- | ----------------- |
| Array\<string>       | 系统的字体名列表。  |

## 示例

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

| 名称            | 类型    | 说明                       |
| -------------- | ------- | ------------------------- |
| path           | string  | 系统字体的文件路径。        |
| postScriptName | string  | 系统字体的postScript名称。 |
| fullName       | string  | 系统字体的名称。           |
| family         | string  | 系统字体的字体家族。       |
| subfamily      | string  | 系统字体的子字体家族。      |
| weight         | number  | 系统字体的粗细程度。        |
| width          | number  | 系统字体的宽窄风格属性。    |
| italic         | boolean | 系统字体是否倾斜。          |
| monoSpace      | boolean | 系统字体是否紧凑。         |
| symbolic       | boolean | 系统字体是否支持符号字体。  |

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