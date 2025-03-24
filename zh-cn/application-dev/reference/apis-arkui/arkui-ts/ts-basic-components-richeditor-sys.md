# RichEditor (系统接口)

支持图文混排和文本交互式编辑的组件。

>  **说明：**
>
>  该组件从API Version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
> 
## RichEditorBuilderSpanOptions<sup>11+</sup>

添加builder的偏移位置和builder样式信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称     | 类型     | 必填   | 说明                                    |
| ------ | ------ | ---- | ------------------------------------- |
| offset | number | 否    | 添加builder的位置。省略或者为异常值时，添加到所有内容的最后。 |
| dragBackgroundColor<sup>18+</sup> | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12) | 否    | 添加builder单独拖拽时的背板背景颜色。不配置或者异常值时，颜色按系统默认配置。  <br/>**系统能力：** 此接口为系统接口。 |
| isDragShadowNeeded<sup>18+</sup> | boolean | 否    | 添加builder单独拖拽时是否需要投影。不配置或者异常值时，默认需要投影。  <br/>**系统能力：** 此接口为系统接口。|

## RichEditorGesture<sup>11+</sup>

用户行为回调。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称          | 类型         | 必填   | 说明            |
| ----------- | ---------- | ---- | ------------- |
| onClick    | Callback\<[ClickEvent](ts-universal-events-click.md#clickevent对象说明)\> | 否    | [ClickEvent](ts-universal-events-click.md#clickevent对象说明)为用户点击事件。<br/>点击完成时回调事件。<br/>双击时，第一次点击触发回调事件。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| onLongPress | Callback\<[GestureEvent](ts-gesture-settings.md#gestureevent对象说明)\>  | 否    | [GestureEvent](ts-gesture-settings.md#gestureevent对象说明)为用户长按事件。<br/>长按完成时回调事件。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| onDoubleClick | Callback\<[GestureEvent](ts-gesture-settings.md#gestureevent对象说明)\>  | 否    | [GestureEvent](ts-gesture-settings.md#gestureevent对象说明)为用户双击事件。<br/>长按完成时回调事件。<br/>**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。<br/>**系统能力：** 此接口为系统接口。|