# StepperItem

用作[Stepper](ts-basic-components-stepper.md)组件的页面子组件。


>  **说明：**
> 该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 权限列表

无


## 子组件

支持单个子组件。


## 接口

StepperItem()


## 属性

| 参数名 | 参数类型 | 默认值 | 参数描述 |
| -------- | -------- | -------- | -------- |
| prevLabel | string | - | 当步骤导航器大于一页，除第一页默认值都为"返回"。 |
| nextLabel | string | - | 步骤导航器大于一页时，最后一页默认值为"开始"，其余页默认值为"下一步"。 |
| status | ItemState | ItemState.Normal | 步骤导航器元素的状态。 |

- ItemState枚举说明
    | 名称 | 描述 |
  | -------- | -------- |
  | Normal | 正常状态，右侧文本按钮正常显示，可点击进入下一个StepperItem。 |
  | Disabled | 不可用状态，右侧文本按钮灰度显示，不可点击进入下一个StepperItem。 |
  | Waiting | 等待状态，右侧文本按钮不显示，使用等待进度条，不可点击进入下一个StepperItem。 |
  | Skip | 跳过状态，表示跳过当前步骤,&nbsp;进入下一个StepperItem。 |


## 示例

见[Stepper](ts-basic-components-stepper.md)。

