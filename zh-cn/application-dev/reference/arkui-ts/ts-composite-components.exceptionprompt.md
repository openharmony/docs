#  @ohos.arkui.advanced.ExceptionPrompt（异常提示组件）

ExceptionPrompt适用于有离线内容可显示的情况。

**说明：**

该组件从API Version 11开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 导入模块

```ts
import {
     ExceptionPrompt,
     PromptOptions,
     PromptType,
     HardwareStatus
} from '@ohos.arkui.advanced.ExceptionPrompt';
```

##  子组件

无

## 接口

```
ExceptionPrompt ({ type: this.type,options: $options })
```

从API version 11开始，该接口支持在ArkTS卡片中使用。

##  Component

**装饰器类型：**@Component

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

## 参数

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称        | 类型 | 必填        | 说明                            |
| ----------- | ---------- | --------------------------------- | --------------------------------- |
| type | PromptType | 是   | 指定当前ExceptionPrompt的类型。对应不同显示状态 |
| options | PromptOptions | 是 | 指定当前ExceptionPrompt的配置信息 |

##  OptionType

PromptOptions定义options的类型。

| 名称           | 类型           | 必填 | 说明                                                         |
| -------------- | -------------- | ---- | ------------------------------------------------------------ |
| icon           | ResourceStr    | 否   | 指定当前ExceptionPrompt的异常图标式样                        |
| tip            | ResourceStr    | 否   | 指定当前ExceptionPrompt的文字提示式样                        |
| networkTip     | ResourceStr    | 否   | 指定当前ExceptionPrompt有网但是获取不到内容XX，XX包含但不限于“信息”，“资料”，“图片”等 |
| hardwareStatus | HardwareStatus | 否   | 指定当前网络硬件开关状态。默认hardwareStatus.ON：打开状态；HardwareStatus.OFF：关闭状态 |
| marginState    | MarginType     | 是   | 指定当前ExceptionPrompt的边距样式                            |

## type

PromptType定义type的类型。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                       | 说明                     |
| :------------------------- | :----------------------- |
| DEFAULT_HIDE               | 默认状态不显示           |
| NETWORK_NOT_CONNECTED      | 网络未连接状态           |
| NETWORK_CONNECTED_UNSTABLE | 网络连接不稳定状态       |
| UNSTABLE_CONNECT_SERVER    | 连不上服务器状态         |
| CUSTOM_NETWORK_TIPS        | 有网但是获取不到内容状态 |
| CUSTOM_TIPS                | 自定义提示内容状态       |
## hardwareStatus

HardwareStatus定义HardwareStatus的类型

| 类型 | 说明       |
| :--- | :--------- |
| ON   | 网络硬件开 |
| OFF  | 网络硬件关 |

## marginState

MarginType定义marginState的类型

| 类型           | 说明                                                         |
| :------------- | :----------------------------------------------------------- |
| DEFAULT_MARGIN | 默认边距：边距1：引用ohos_id_card_margin_start，边距2：引用ohos_id_card_margin_end |
| FIT_MARGIN     | 可适配边距： 边距1：引用ohos_id_max_padding_start，边距2：引用ohos_id_max_padding_end |

## 事件

| 名称                               | 功能描述                             |
| ---------------------------------- | ------------------------------------ |
| onReconnectionCallback: () => void | 点击左侧文本，变为正在连接状态       |
| onConfigureCallback: () =&gt; void | 点击设置网络跳转到设置网络弹出框界面 |

## 示例 

```ts
import {
  ExceptionPrompt,
  PromptOptions,
  PromptType,
  HardwareStatus
} from '@ohos.arkui.advanced.ExceptionPrompt'

@Entry
@Component
struct Index {
  @State type: PromptType = PromptType.DEFAULT_HIDE
  @State options: PromptOptions = {
    hardwareStatus: HardwareStatus.ON,
    icon: '',
    networkTip: '',
    tip: '',
    marginState: MarginType.DEFAULT_MARGIN
  }

  build() {
    Column() {
      ExceptionPrompt({
        type: this.type,
        options: this.options,
        onReconnectionCallback: () => {
        },
        onConfigureCallback: () => {
        },
      })

```

## 图例

![ExceptionPrompt](figures/ExceptionPrompt.png)

