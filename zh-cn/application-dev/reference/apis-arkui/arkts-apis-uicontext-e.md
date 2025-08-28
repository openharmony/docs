# Enums

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @piggyguy; @xiang-shouxing; @yangfan229-->
<!--Designer: @piggyguy; @xiang-shouxing; @yangfan229-->
<!--Tester: @fredyuan912-->
<!--Adviser: @HelloCrease-->

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## KeyboardAvoidMode<sup>11+</sup>

配置键盘避让时页面的避让模式。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 值   | 说明       |
| ------ | ---- | ---------- |
| OFFSET | 0    | 上抬模式。 <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| RESIZE | 1    | 压缩模式。 <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| OFFSET_WITH_CARET<sup>14+</sup>  | 2 | 上抬模式，输入框光标位置发生变化时候也会触发避让。<br/>**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。|
| RESIZE_WITH_CARET<sup>14+</sup>  | 3 | 压缩模式，输入框光标位置发生变化时候也会触发避让。<br/>**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。|
| NONE<sup>14+</sup>  | 4 | 不避让键盘。<br/>**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。|

## SwiperDynamicSyncSceneType<sup>12+</sup>

枚举值，表示动态帧率场景的类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

| 名称     | 值   | 说明                   |
| -------- | ---- | ---------------------- |
| GESTURE | 0   | 手势操作场景。 |
| ANIMATION | 1   | 动画过渡场景。 |

## MarqueeDynamicSyncSceneType<sup>14+</sup>

枚举值，表示Marquee的动态帧率场景的类型。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

| 名称     | 值   | 说明                   |
| -------- | ---- | ---------------------- |
| ANIMATION | 1   | 动画过渡场景。 |

## NodeRenderState<sup>20+</sup>

组件的渲染状态。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值 |说明 |
| -------- | ------- | -------- |
| ABOUT_TO_RENDER_IN | 0 | 该节点已挂载到渲染树上，一般将会在下一帧被渲染。一般情况下可被看见，但会被渲染并不等同于一定可见。 |
| ABOUT_TO_RENDER_OUT | 1 | 该节点已从渲染树中删除，一般下一帧不会被渲染，用户将不会看到此节点。 |

## GestureActionPhase<sup>20+</sup>

此枚举类型表示手势回调触发阶段，对应gesture.d.ts中定义的动作回调，但不同手势类型支持的阶段不同（如SwipeGesture仅包含WILL_START枚举值）。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 值   | 说明       |
| ------ | ---- | ---------- |
| WILL_START | 0 | 手势已被系统成功识别，将立即触发onActionStart或onAction回调。若手势绑定了onActionStart，则在onActionStart处触发；若手势绑定了onAction，则在onAction处触发；若两者同时绑定，则优先在onActionStart处触发；若两者均未绑定，则不会触发任何回调。某些容器有内置手势绑定了回调（如滚动类容器），默认支持上述回调触发机制，无需显式绑定即可触发回调。 |
|  WILL_END | 1 | 表示手势已被判定为结束状态（通常发生在用户抬起手指终止交互时）。onActionEnd回调将立即触发，但手势必须显式绑定onActionEnd。某些容器有内置手势绑定了回调（如滚动类容器），默认支持该结束状态判定，无需显式绑定即可触发onActionEnd回调。|

## GestureListenerType<sup>20+</sup>

此枚举类型用于指定需要监控的手势类型。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 值   | 说明       |
| ------ | ---- | ---------- |
| TAP | 0 | 点击手势。 |
| LONG_PRESS | 1 | 长按手势。 |
| PAN  | 2 | 平移手势。 |
| PINCH | 3 | 捏合手势。 |
| SWIPE | 4| 滑动手势。 |
| ROTATION| 5 | 旋转手势。 |