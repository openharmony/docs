#  @ohos.arkui.advanced.ExceptionPrompt（异常提示组件）

ExceptionPrompt适用于有离线内容可显示的情况。

**说明：**

该组件从API Version 11开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 导入模块

```ts
import {
     ExceptionPrompt,
     PromptOptions,
     MarginType
} from '@ohos.arkui.advanced.ExceptionPrompt';
```

##  子组件

无

## 接口

```
ExceptionPrompt ({ options: this.options })
```

从API version 11开始，该接口支持在ArkTS卡片中使用。

##  Component

**装饰器类型：**@Component

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

## 参数

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称        | 类型 | 必填        | 说明                            |
| ----------- | ---------- | --------------------------------- | --------------------------------- |
| options | PromptOptions | 是 | 指定当前ExceptionPrompt的配置信息 |

##  OptionType

PromptOptions定义options的类型。

| 名称        | 类型        | 必填 | 说明                                            |
| ----------- | ----------- | ---- | ----------------------------------------------- |
| icon        | ResourceStr | 否   | 指定当前ExceptionPrompt的异常图标式样           |
| tip         | ResourceStr | 否   | 指定当前ExceptionPrompt的文字提示内容           |
| marginState | MarginType  | 是   | 指定当前ExceptionPrompt的边距样式               |
| touchText   | ResourceStr | 否   | 指定当前ExceptionPrompt的右侧图标按钮的文字内容 |
| isTouchShow | boolean     | 否   | 指定当前ExceptionPrompt的右侧图标按钮的显隐状态 |
| positionTop | number      | 是   | 指定当前ExceptionPrompt的距离顶部的位置         |
| isShow      | boolean     | 否   | 指定当前ExceptionPrompt的显隐状态               |

## marginState

MarginType定义marginState的类型

| 类型           | 说明                                                         |
| :------------- | :----------------------------------------------------------- |
| DEFAULT_MARGIN | 默认边距：边距1：引用ohos_id_card_margin_start，边距2：引用ohos_id_card_margin_end |
| FIT_MARGIN     | 可适配边距： 边距1：引用ohos_id_max_padding_start，边距2：引用ohos_id_max_padding_end |

## 事件

| 名称                       | 功能描述                   |
| -------------------------- | -------------------------- |
| onTextClick: () => void    | 点击左侧提示文本的回调函数 |
| onConfigure: () =&gt; void | 点击右侧图标按钮的回调函数 |

## 示例 

```ts
import {
  ExceptionPrompt,
  PromptOptions,
  MarginType
} from '@ohos.arkui.advanced.ExceptionPrompt'

@Entry
@Component
struct Index {
  @State options: PromptOptions = {
    icon: '',
    tip: '',
    marginState: MarginType.DEFAULT_MARGIN
    touchText: '',
    isTouchShow: false,
    positionTop: 80,
    isShow:true
  }

  build() {
    Column() {
      ExceptionPrompt({
        options: this.options,
        onTextClick: () => {
            // Click the text on the left to change into the connecting state
        },
        onConfigure: () => {
            // Click Set Network to open the Set network pop-up interface
        },
      })

```

## 图例

![ExceptionPrompt](figures/ExceptionPrompt.png)

