# Interfaces (其他)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92; @liyi0903; @mayaolll-->
<!--Designer: @piggyguy; @liyi0903; @jiangdayuan-->
<!--Tester: @fredyuan912-->
<!--Adviser: @HelloCrease-->

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## TargetInfo<sup>18+</sup>

指定组件绑定的目标节点。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| id | string&nbsp;\|&nbsp;number | 否 | 否 | 指定popup或menu绑定的目标节点。<br/>**说明：** <br/>1. 当id是number时，对应组件实例的UniqueID，此id由系统保证唯一性。<br/>2. 当id是string时，对应[通用属性id](arkui-ts/ts-universal-attributes-component-id.md#id)所指定的组件，此id的唯一性需由开发者确保，但实际可能会有多个。 |
| componentId | number | 否 | 是 | 目标节点所在的自定义组件的UniqueID。当上述id指定为string类型时，可通过此属性圈定范围。方便开发者在一定范围内保证id: string的唯一性。 |

## PageInfo<sup>12+</sup>

Router和NavDestination等页面信息，若无对应的Router或NavDestination页面信息，则对应属性为undefined。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- |-------- | -------- |
| routerPageInfo | observer.[RouterPageInfo](js-apis-arkui-observer.md#routerpageinfo) | 否 |是 | Router信息。 |
| navDestinationInfo | observer.[NavDestinationInfo](js-apis-arkui-observer.md#navdestinationinfo) | 否 |是| NavDestination信息。 |

## OverlayManagerOptions<sup>15+</sup>

初始化[OverlayManager](arkts-apis-uicontext-overlaymanager.md)时所用参数。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称             | 类型                | 只读 | 可选   | 说明                     |
| --------------- | ---------------------- | ------------ | --------------------- | --------------------- |
| renderRootOverlay   | boolean | 否 | 是 | 是否渲染overlay根节点，true表示渲染overlay根节点，false表示不渲染overlay根节点，默认值为true。<br/>**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。|
| enableBackPressedEvent<sup>19+</sup>   | boolean | 否 | 是 | 是否支持通过侧滑手势关闭OverlayManager下的ComponentContent，true表示可以通过侧滑关闭，false表示不可以通过侧滑关闭，默认值为false。 <br/>**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。|

## GestureTriggerInfo<sup>20+</sup>

特定手势回调函数触发时的信息。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型   | 必填       |说明       |
| ------ | ---- | ---------- |---------- |
| event | [GestureEvent](../apis-arkui/arkui-ts/ts-gesture-common.md#gestureevent对象说明)   |是       |手势事件对象。 |
| current | [GestureRecognizer](arkui-ts/ts-gesture-common.md#gesturerecognizer12)    |是      |手势识别器对象。可从中获取手势的详细信息，但请勿在本地保留此对象，因为当节点释放后该对象可能失效。 |
| currentPhase  | [GestureActionPhase](arkts-apis-uicontext-e.md#gestureactionphase20) |是      | 手势动作回调阶段。|
| node  | [FrameNode](js-apis-arkui-frameNode.md) |否      |触发手势的节点。默认值为null，表示没有触发手势的节点。 |

## GestureObserverConfigs<sup>20+</sup>

该参数用于指定需要监听的手势回调阶段（传入空数组将无效），仅当手势触发指定阶段时才会发送通知。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型   | 必填       |说明       |
| ------ | ---- | ---------- |---------- |
|  actionPhases | Array\<[GestureActionPhase](arkts-apis-uicontext-e.md#gestureactionphase20)\>    |是       |手势事件对象。 |