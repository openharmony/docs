# @ohos.font (注册自定义字体)

本模块提供注册自定义字体。

> **说明**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>

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
| familyName | string | 是    | 设置注册的字体名称。   |
| familySrc  | string | 是    | 设置注册字体文件的路径。 |

**示例：**

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
      familySrc: '/font/medium.ttf' // font文件与pages目录同级
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
