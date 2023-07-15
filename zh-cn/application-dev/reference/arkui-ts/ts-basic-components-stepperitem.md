# StepperItem

用作[Stepper](ts-basic-components-stepper.md)组件的页面子组件。


>  **说明：**
>
>  该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件

支持单个子组件。


## 接口

StepperItem()


## 属性

| 参数名 | 参数类型 | 参数描述 |
| -------- | -------- | -------- |
| prevLabel | string | 设置左侧文本按钮内容，第一页没有左侧文本按钮，当步骤导航器大于一页时，除第一页外默认值都为“返回”。 |
| nextLabel | string | 设置右侧文本按钮内容，最后一页默认值为“开始”，其余页默认值为“下一步”。 |
| status | [ItemState](#itemstate枚举说明) | 步骤导航器nextLabel的显示状态，参数可选。<br/>默认值：ItemState.Normal |

## ItemState枚举说明

|   名称    | 描述 |
| -------- |-------- |
| Normal |正常状态，右侧文本按钮正常显示，可点击进入下一个StepperItem。 |
| Disabled |不可用状态，右侧文本按钮灰度显示，不可点击进入下一个StepperItem。 |
| Waiting | 等待状态，右侧文本按钮不显示，显示等待进度条，不可点击进入下一个StepperItem。 |
| Skip |跳过状态，右侧文本按钮默认显示“跳过”，此时可在Stepper的onSkip回调中自定义相关逻辑。 |


## 示例

见[Stepper](ts-basic-components-stepper.md)。

