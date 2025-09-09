# Types
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## CustomBuilderWithId<sup>18+</sup>

type CustomBuilderWithId = (id: number)&nbsp;=&gt;&nbsp;void

组件属性、方法参数可使用CustomBuilderWithId类型来自定义UI描述，并且可以指定组件ID生成用户自定义组件。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| id | number | 是 | 组件ID。 |

## ClickEventListenerCallback<sup>12+</sup>

type ClickEventListenerCallback = (event: ClickEvent, node?: FrameNode) => void

ArkTS GestureEvent事件监听函数类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型   | 必填 | 说明                          |
| ------- | ------ | ---- | --------------------------- |
| event | [ClickEvent](../apis-arkui/arkui-ts/ts-universal-events-click.md#clickevent) | 是 | 触发事件监听的点击事件的相关信息。 |
| node | [FrameNode](js-apis-arkui-frameNode.md) | 否 | 触发事件监听的点击事件所绑定的组件。 |

## PanListenerCallback<sup>19+</sup>

type PanListenerCallback = (event: GestureEvent, current: GestureRecognizer, node?: FrameNode) => void

Pan手势事件监听函数类型。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型              | 必填 | 说明                                |
| ------- | ----------------- | ---- | --------------------------------- |
| event   | [GestureEvent](../apis-arkui/arkui-ts/ts-gesture-common.md#gestureevent对象说明)      | 是   | 触发事件监听的手势事件的相关信息。   |
| current | [GestureRecognizer](arkui-ts/ts-gesture-common.md#gesturerecognizer12) | 是   | 触发事件监听的手势识别器的相关信息。  |
| node    | [FrameNode](js-apis-arkui-frameNode.md)         | 否   | 触发事件监听的手势事件所绑定的组件。 |

## GestureEventListenerCallback<sup>12+</sup>

type GestureEventListenerCallback = (event: GestureEvent, node?: FrameNode) => void

ArkTS GestureEvent事件监听函数类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型   | 必填 | 说明                          |
| ------- | ------ | ---- | --------------------------- |
| event | [GestureEvent](../apis-arkui/arkui-ts/ts-gesture-common.md#gestureevent对象说明) | 是 | 触发事件监听的手势事件的相关信息。 |
| node | [FrameNode](js-apis-arkui-frameNode.md) | 否 | 触发事件监听的手势事件所绑定的组件。 |

## NodeIdentity<sup>20+</sup>

type NodeIdentity = string | number

组件标识。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型              | 说明                                |
| ----------------- | --------------------------------- |
| string      | 指定组件id，该id通过通用属性[id](./arkui-ts/ts-universal-attributes-component-id.md#id)设置。   |
| number | 系统分配的唯一标识的节点UniqueID，可通过[getUniqueId](js-apis-arkui-frameNode.md#getuniqueid12)获取。  |

## NodeRenderStateChangeCallback<sup>20+</sup>

type NodeRenderStateChangeCallback = (state: NodeRenderState, node?: FrameNode) => void

定义了用于在UIObserver中监控某个特定节点渲染状态的回调类型。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型              | 必填 | 说明                                |
| ------- | ----------------- | ---- | --------------------------------- |
| state   | [NodeRenderState](arkts-apis-uicontext-e.md#noderenderstate20)     | 是   | 触发事件监听的手势事件的相关信息。   |
| node    | [FrameNode](js-apis-arkui-frameNode.md)         | 否   | 触发事件监听的手势事件所绑定的组件，如果组件被释放将返回null。 |

## GestureListenerCallback<sup>20+</sup>

type GestureListenerCallback = (info: GestureTriggerInfo) => void

定义了用于在UIObserver中监控特定手势触发信息的回调类型。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型              | 必填 | 说明                                |
| ------- | ----------------- | ---- | --------------------------------- |
| info   | [GestureTriggerInfo](arkts-apis-uicontext-i.md#gesturetriggerinfo20)     | 是   |  交互触发的手势详情。 |

## PointerStyle<sup>12+</sup>

type PointerStyle = pointer.PointerStyle

光标样式。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MultimodalInput.Input.Pointer

|类型|说明|
| -- | -- |
|[pointer.PointerStyle](../apis-input-kit/js-apis-pointer.md#pointerstyle) |光标样式。|

## Context<sup>12+</sup>

type Context = common.Context

当前组件所在Ability的上下文。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**模型约束：** 此接口仅可在Stage模型下使用。

| 类型 |说明   |
| ------ | ------------------- |
| [common.Context](../apis-ability-kit/js-apis-app-ability-common.md#context) |Context的具体类型为当前Ability关联的Context对象。|