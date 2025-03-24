# RichEditor (系统接口)

支持图文混排和文本交互式编辑的组件。

>  **说明：**
>
>  该组件从API Version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
> 

## RichEditorGesture<sup>11+</sup>

用户行为回调。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称          | 类型         | 必填   | 说明            |
| ----------- | ---------- | ---- | ------------- |
| onDoubleClick<sup>14+</sup> | Callback\<[GestureEvent](ts-gesture-settings.md#gestureevent对象说明)\>  | 否    | [GestureEvent](ts-gesture-settings.md#gestureevent对象说明)为用户双击事件。<br/>长按完成时回调事件。<br/>**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。<br/>**系统能力：** 此接口为系统接口。|