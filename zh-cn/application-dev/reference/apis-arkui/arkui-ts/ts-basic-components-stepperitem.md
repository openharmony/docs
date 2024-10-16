# StepperItem

用作[Stepper](ts-basic-components-stepper.md)组件的页面子组件。


>  **说明：**
>
>  该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件

支持单个子组件。


## 接口

StepperItem()

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

## 属性

### prevLabel

prevLabel(value: string)

设置左侧文本按钮内容，第一页没有左侧文本按钮，当步骤导航器大于一页时，除第一页外默认值都为“返回”。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | string | 是 | 左侧文本按钮内容。 |

### nextLabel

nextLabel(value: string)

设置右侧文本按钮内容，最后一页默认值为“开始”，其余页默认值为“下一步”。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                            | 必填 | 说明                                                         |
| ------ | ------------------------------- | ---- | ------------------------------------------------------------ |
| value  | string                          | 是   | 右侧文本按钮内容。                                           |

### status

status(value?: ItemState)

设置步骤导航器nextLabel的显示状态。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                            | 必填 | 说明                                                         |
| ------ | ------------------------------- | ---- | ------------------------------------------------------------ |
| value  | [ItemState](#itemstate枚举说明) | 否   | 步骤导航器nextLabel的显示状态。<br/>默认值：ItemState.Normal |

>  **说明：**
>
>  - StepperItem组件不支持设置通用宽度属性，其宽度默认撑满Stepper父组件。
>  - StepperItem组件不支持设置通用高度属性，其高度由Stepper父组件高度减去label按钮组件高度。
>  - StepperItem组件不支持设置aspectRadio/constrainSize影响长宽的属性。
## ItemState枚举说明

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

|   名称    | 说明 |
| -------- |-------- |
| Normal |正常状态，右侧文本按钮正常显示，可点击进入下一个StepperItem。 |
| Disabled |不可用状态，右侧文本按钮灰度显示，不可点击进入下一个StepperItem。 |
| Waiting | 等待状态，右侧文本按钮不显示，显示等待进度条，不可点击进入下一个StepperItem。 |
| Skip |跳过状态，右侧文本按钮默认显示“跳过”，此时可在Stepper的onSkip回调中自定义相关逻辑。 |


## 示例

见[Stepper](ts-basic-components-stepper.md)。

