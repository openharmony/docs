# 设置组件绑定的手势

用于设置组件绑定的手势。可以通过UIGestureEvent对象调用其接口添加或删除手势。

>**说明：**
>
>本模块首批接口从API version 12开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。

## UIGestureEvent

用于设置组件绑定的手势。

### addGesture

addGesture(gesture: GestureHandler\<T>, priority?: GesturePriority, mask?: GestureMask): void

添加手势。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| gesture  |  [GestureHandler\<T>](#gesturehandlert) | 是   | 手势处理器对象。 |
| priority  |  [GesturePriority](#gesturepriority枚举说明) | 否   | 绑定手势的优先级。 |
| mask  |  [GestureMask](./ts-gesture-settings.md#gesturemask枚举说明) | 否   | 事件响应设置。 |

### addParallelGesture

addParallelGesture(gesture: GestureHandler\<T>, mask?: GestureMask): void

绑定可与子组件手势同时触发的手势。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| gesture  |  [GestureHandler\<T>](#gesturehandlert) | 是   | 手势处理器对象。 |
| mask  |  [GestureMask](./ts-gesture-settings.md#gesturemask枚举说明) | 否   | 事件响应设置。 |

### removeGestureByTag

removeGestureByTag(tag: string): void

移除该组件上通过modifier绑定的设置为指定标志的手势。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| tag  |  string | 是   | 手势处理器标志。 |

### clearGestures

clearGestures(): void

清除该组件上通过modifier绑定的所有手势。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

## GestureHandler\<T>

手势对象的基础类型。

### tag

tag(tag: string): T

设置手势处理器的标志。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 名称 | 类型 | 必填 |描述                                        |
| ----  | ------  | ------|---------------------------------- |
| tag   | string  | 是 |设置手势处理器标志。|

### allowedTypes<sup>14+</sup>

allowedTypes(types: Array\<SourceTool>): T

设置手势处理器所支持的事件输入源。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 名称 | 类型 | 必填 |描述                                        |
| ----  | ------  | ------|---------------------------------- |
| types   | Array\<[SourceTool](ts-gesture-settings.md#sourcetool枚举说明9)>  | 是 |设置手势处理器所支持的事件输入源。|

## TapGestureHandler

点击手势处理器对象类型。

### constructor

constructor(options?: TapGestureHandlerOptions)

构造函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名  | 类型                                                         | 必填 | 说明               |
| ------- | ------------------------------------------------------------ | ---- | ------------------ |
| options | [TapGestureHandlerOptions](#tapgesturehandleroptions) | 否   | 点击手势处理器配置参数。 |

### onAction

onAction(event: Callback\<GestureEvent>): TapGestureHandler

Tap手势识别成功回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                              | 必填 | 说明                 |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent](ts-gesture-settings.md#gestureevent对象说明)> | 是 | Tap手势识别成功回调。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| TapGestureHandler | 返回当前点击手势处理器对象。 |

## TapGestureHandlerOptions

点击手势处理器配置参数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 属性         | 类型                                   | 必填 | 描述                 |
| ------------ | -------------------------------------- | ---- | -------------------- |
| count | number | 否 | 识别的连续点击次数。当设置的值小于1或不设置时，会被转化为默认值。<br/>默认值：1<br/>**说明：**<br/>1. 当配置多击时，上一次的最后一根手指抬起和下一次的第一根手指按下的超时时间为300毫秒。<br/>2. 当上次点击的位置与当前点击的位置距离超过60vp时，手势识别失败。|
| fingers | number | 否 | 触发点击的手指数，最小为1指，&nbsp;最大为10指。当设置小于1的值或不设置时，会被转化为默认值。<br/>默认值：1<br/>**说明：**<br/>1. 当配置多指时，第一根手指按下后300毫秒内未有足够的手指数按下，手势识别失败，第一根手指抬起后300毫秒内未有足够的手指抬起，手势识别失败。<br/>2. 实际点击手指数超过配置值，手势识别成功。 |
| isFingerCountLimited<sup>16+</sup> | boolean | 否 | 是否检查触摸屏幕的手指数量。如果触摸手指的数量不等于设置的触发点击的手指数（即上述fingers参数），那么该手势识别失败。<br>在多击事件中（上述count参数大于1），需要每一次点击的手指数都等于设置的触发点击的手指数，否则该手势识别失败。<br>默认值：false。|

## LongPressGestureHandler

长按手势处理器对象类型。

### constructor

constructor(options?: LongPressGestureHandlerOptions)

构造函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**


| 参数名  | 类型                                                         | 必填 | 说明               |
| ------- | ------------------------------------------------------------ | ---- | ------------------ |
| options | [LongPressGestureHandlerOptions](#longpressgesturehandleroptions) | 否   | 长按手势处理器配置参数。 |

### onAction

onAction(event: Callback\<GestureEvent>): LongPressGestureHandler

LongPress手势识别成功回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                              | 必填 | 说明                 |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent](ts-gesture-settings.md#gestureevent对象说明)> | 是 | LongPress手势识别成功回调。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| LongPressGestureHandler | 返回当前长按手势处理器对象。 |

### onActionEnd

onActionEnd(event: Callback\<GestureEvent>): LongPressGestureHandler

LongPress手势识别成功，最后一根手指抬起后触发回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                              | 必填 | 说明                 |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent](ts-gesture-settings.md#gestureevent对象说明)> | 是 | LongPress手势识别成功，最后一根手指抬起后触发回调。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| LongPressGestureHandler | 返回当前长按手势处理器对象。 |

### onActionCancel

onActionCancel(event: Callback\<void>): LongPressGestureHandler

LongPress手势识别成功，接收到触摸取消事件触发回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                              | 必填 | 说明                 |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)\<void> | 是 | LongPress手势识别成功，接收到触摸取消事件触发回调。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| LongPressGestureHandler | 返回当前长按手势处理器对象。 |

## LongPressGestureHandlerOptions

长按手势处理器配置参数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 属性         | 类型                                   | 必填 | 描述                 |
| ------------ | -------------------------------------- | ---- | -------------------- |
| fingers | number | 否 | 触发长按的最少手指数，最小为1指，&nbsp;最大取值为10指。<br/>默认值：1 <br/> **说明：** <br/>手指按下后若发生超过15px的移动，则判定当前长按手势识别失败。|
| repeat | boolean | 否 | 是否连续触发事件回调。<br/>默认值：false |
| duration | number | 否 | 触发长按的最短时间，单位为毫秒（ms）。<br/>默认值：500 <br/>**说明：** <br/>设置小于等于0时，按照默认值500处理。|
| isFingerCountLimited<sup>16+</sup> | boolean | 否 | 是否检查触摸屏幕的手指数量。若触摸屏幕的手指的数量不等于设置的触发长按的最少手指数（即上述fingers参数），手势识别将失败。<br>对于已成功识别的手势，后续触摸屏幕的手指数变化，将不触发repeat事件（若触摸屏幕的手指数恢复到设置的触发长按的最少手指数时，可以触发[onAction](ts-basic-gestures-longpressgesture.md#事件)事件），但可以触发[onActionEnd](ts-basic-gestures-longpressgesture.md#事件)事件。<br>默认值：false。|

## PanGestureHandler

拖动手势处理器对象类型。

### constructor

constructor(options?: PanGestureHandlerOptions)

构造函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**


| 参数名  | 类型                                                         | 必填 | 说明               |
| ------- | ------------------------------------------------------------ | ---- | ------------------ |
| options | [PanGestureHandlerOptions](#pangesturehandleroptions) | 否   | 拖动手势处理器配置参数。 |

### onActionStart

onActionStart(event: Callback\<GestureEvent>): PanGestureHandler

Pan手势识别成功回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                              | 必填 | 说明                 |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent](ts-gesture-settings.md#gestureevent对象说明)> | 是 | Pan手势识别成功回调。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| PanGestureHandler | 返回当前拖动手势处理器对象。 |

### onActionUpdate

onActionUpdate(event: Callback\<GestureEvent>): PanGestureHandler

Pan手势移动过程中回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                              | 必填 | 说明                 |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent](ts-gesture-settings.md#gestureevent对象说明)> | 是 | Pan手势移动过程中回调。<br/>fingerList为多根手指时，该回调监听每次只会更新一根手指的位置信息。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| PanGestureHandler | 返回当前拖动手势处理器对象。 |

### onActionEnd

onActionEnd(event: Callback\<GestureEvent>): PanGestureHandler

Pan手势识别成功，手指抬起后触发回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                              | 必填 | 说明                 |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent](ts-gesture-settings.md#gestureevent对象说明)> | 是 | Pan手势识别成功，手指抬起后触发回调。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| PanGestureHandler | 返回当前拖动手势处理器对象。 |

### onActionCancel

onActionCancel(event: Callback\<void>): PanGestureHandler

Pan手势识别成功，接收到触摸取消事件触发回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                              | 必填 | 说明                 |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)\<void> | 是 | Pan手势识别成功，接收到触摸取消事件触发回调。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| PanGestureHandler | 返回当前拖动手势处理器对象。 |

## PanGestureHandlerOptions

拖动手势处理器配置参数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 属性         | 类型                                   | 必填 | 描述                 |
| ------------ | -------------------------------------- | ---- | -------------------- |
| fingers | number | 否 | 用于指定触发拖动的最少手指数，最小为1指，&nbsp;最大取值为10指。<br/>默认值：1<br/>取值范围：[1,10]<br/>**说明：** <br/>当设置的值小于1或不设置时，会被转化为默认值。 |
| direction | [PanDirection](./ts-basic-gestures-pangesture.md#pandirection枚举说明) | 否 | 用于指定触发拖动的手势方向，此枚举值支持逻辑与(&amp;)和逻辑或（\|）运算。<br/>默认值：PanDirection.All |
| distance | number | 否 | 用于指定触发拖动手势事件的最小拖动距离，单位为vp。<br/>默认值：5<br/>**说明：**<br/>[Tabs组件](ts-container-tabs.md)滑动与该拖动手势事件同时存在时，可将distance值设为1，使拖动更灵敏，避免造成事件错乱。<br/>当设定的值小于0时，按默认值5处理。 |
| isFingerCountLimited<sup>16+</sup> | boolean | 否 | 是否检查触摸屏幕的手指数量。若触摸屏幕的手指数量不等于设置的触发滑动的最少手指数（即上述fingers参数），手势将不会被识别。只有当触摸屏幕的手指数等于设置的触发滑动的最少手指数，并且滑动距离达到阈值时，手势才能被成功识别。<br>对于已成功识别的手势，后续改变触摸屏幕的手指数量不会引发[onActionUpdate](ts-basic-gestures-pangesture.md#事件)事件，但可以触发[onActionEnd](ts-basic-gestures-pangesture.md#事件)事件。<br>默认值：false。|

## SwipeGestureHandler

滑动手势处理器对象类型。

### constructor

constructor(options?: SwipeGestureHandlerOptions)

构造函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名  | 类型                                                         | 必填 | 说明               |
| ------- | ------------------------------------------------------------ | ---- | ------------------ |
| options | [SwipeGestureHandlerOptions](#swipegesturehandleroptions) | 否   | 滑动手势处理器配置参数。 |

### onAction

onAction(event: Callback\<GestureEvent>): SwipeGestureHandlerOptions

Swipe手势识别成功回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                              | 必填 | 说明                 |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent](ts-gesture-settings.md#gestureevent对象说明)> | 是 | Swipe手势识别成功回调。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| SwipeGestureHandler | 返回当前滑动手势处理器对象。 |

## SwipeGestureHandlerOptions

滑动事件处理器配置参数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 属性         | 类型                                   | 必填 | 描述                 |
| ------------ | -------------------------------------- | ---- | -------------------- |
| fingers | number | 否 | 触发滑动的最少手指数，默认为1，最小为1指，最大为10指。<br/>默认值：1 |
| direction | [SwipeDirection](./ts-basic-gestures-swipegesture.md#swipedirection枚举说明) | 否 | 触发滑动手势的滑动方向。<br/>默认值：SwipeDirection.All |
| speed | number | 否 | 识别滑动的最小速度。<br/>默认值：100VP/s <br/>**说明：** <br/>当滑动速度的值小于等于0时，会被转化为默认值。 |
| isFingerCountLimited<sup>16+</sup> | boolean | 否 | 是否检查触摸屏幕的手指数量。如果触摸手指的数量不等于设置的触发滑动的最少手指数（即上述fingers参数），手势识别将失败。<br>默认值：false。|

## PinchGestureHandler

捏合手势处理器对象类型。

### constructor

constructor(options?: PinchGestureHandlerOptions)

构造函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**


| 参数名  | 类型                                                         | 必填 | 说明               |
| ------- | ------------------------------------------------------------ | ---- | ------------------ |
| options | [PinchGestureHandlerOptions](#pinchgesturehandleroptions) | 否   | 捏合手势处理器配置参数。 |

### onActionStart

onActionStart(event: Callback\<GestureEvent>): PinchGestureHandler

Pinch手势识别成功回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                              | 必填 | 说明                 |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent](ts-gesture-settings.md#gestureevent对象说明)> | 是 | Pinch手势识别成功回调。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| PinchGestureHandler | 返回当前拖动手势处理器对象。 |

### onActionUpdate

onActionUpdate(event: Callback\<GestureEvent>): PinchGestureHandler

Pinch手势移动过程中回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                              | 必填 | 说明                 |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent](ts-gesture-settings.md#gestureevent对象说明)> | 是 | Pinch手势移动过程中回调。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| PinchGestureHandler | 返回当前拖动手势处理器对象。 |

### onActionEnd

onActionEnd(event: Callback\<GestureEvent>): PinchGestureHandler

Pinch手势识别成功，手指抬起后触发回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                              | 必填 | 说明                 |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent](ts-gesture-settings.md#gestureevent对象说明)> | 是 | Pinch手势识别成功，手指抬起后触发回调。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| PinchGestureHandler | 返回当前拖动手势处理器对象。 |

### onActionCancel

onActionCancel(event: Callback\<void>): PinchGestureHandler

Pinch手势识别成功，接收到触摸取消事件触发回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                              | 必填 | 说明                 |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)\<void> | 是 | Pinch手势识别成功，接收到触摸取消事件触发回调。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| PinchGestureHandler | 返回当前拖动手势处理器对象。 |

## PinchGestureHandlerOptions

捏合手势处理器配置参数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 属性         | 类型                                   | 必填 | 描述                 |
| ------------ | -------------------------------------- | ---- | -------------------- |
| fingers | number | 否 | 触发捏合的最少手指数,&nbsp;最小为2指，最大为5指。<br/>默认值：2 <br/>触发手势手指可以多于fingers数目，但只有先落下的与fingers相同数目的手指参与手势计算。 |
| distance | number | 否 | 最小识别距离，单位为vp。<br/>默认值：5 <br/>**说明：** <br/> 当识别距离的值小于等于0时，会被转化为默认值。|
| isFingerCountLimited<sup>16+</sup> | boolean | 否 | 是否检查触摸屏幕的手指数量。若触摸屏幕的手指数量不等于设置的触发捏合的最少手指数（即上述fingers参数），手势将不会被识别。只有当触摸屏幕的手指数等于设置的触发捏合手势的最小手指数，并且滑动距离满足阈值要求时，手势才能被成功识别。对于已经成功识别的手势，后续改变触摸屏幕的手指数量，将不会触发[onActionUpdate](ts-basic-gestures-pinchgesture.md#事件)事件，但可以触发[onActionEnd](ts-basic-gestures-pinchgesture.md#事件)事件。<br>默认值：false。|

## RotationGestureHandler

旋转手势处理器对象类型。

### constructor

constructor(options?: RotationGestureHandlerOptions)

构造函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**


| 参数名  | 类型                                                         | 必填 | 说明               |
| ------- | ------------------------------------------------------------ | ---- | ------------------ |
| options | [RotationGestureHandlerOptions](#rotationgesturehandleroptions) | 否   | 旋转手势处理器配置参数。 |

### onActionStart

onActionStart(event: Callback\<GestureEvent>): RotationGestureHandler

Rotation手势识别成功回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                              | 必填 | 说明                 |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent](ts-gesture-settings.md#gestureevent对象说明)> | 是 | Rotation手势识别成功回调。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| RotationGestureHandler | 返回当前拖动手势处理器对象。 |

### onActionUpdate

onActionUpdate(event: Callback\<GestureEvent>): RotationGestureHandler

Rotation手势移动过程中回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                              | 必填 | 说明                 |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent](ts-gesture-settings.md#gestureevent对象说明)> | 是 | Rotation手势移动过程中回调。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| RotationGestureHandler | 返回当前拖动手势处理器对象。 |

### onActionEnd

onActionEnd(event: Callback\<GestureEvent>): RotationGestureHandler

Rotation手势识别成功，手指抬起后触发回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                              | 必填 | 说明                 |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent](ts-gesture-settings.md#gestureevent对象说明)> | 是 | Rotation手势识别成功，手指抬起后触发回调。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| RotationGestureHandler | 返回当前拖动手势处理器对象。 |

### onActionCancel

onActionCancel(event: Callback\<void>): RotationGestureHandler

Rotation手势识别成功，接收到触摸取消事件触发回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                              | 必填 | 说明                 |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)\<void> | 是 | Rotation手势识别成功，接收到触摸取消事件触发回调。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| RotationGestureHandler | 返回当前拖动手势处理器对象。 |

## RotationGestureHandlerOptions

旋转手势处理器配置参数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 属性         | 类型                                   | 必填 | 描述                 |
| ------------ | -------------------------------------- | ---- | -------------------- |
| fingers | number | 否 | 触发旋转的最少手指数,&nbsp;最小为2指，最大为5指。<br/>默认值：2 <br/>触发手势手指可以多于fingers数目，但只有先落下的两指参与手势计算。|
| angle | number | 否 | 触发旋转手势的最小改变度数，单位为deg。<br/>默认值：1 <br/>**说明：** <br/>当改变度数的值小于等于0或大于360时，会被转化为默认值。|
| isFingerCountLimited<sup>16+</sup> | boolean | 否 | 是否检查触摸屏幕的手指数量。若触摸屏幕的手指数量不等于设置的触发旋转的最少手指数（即上述fingers参数），手势将不会被识别。只有当触摸屏幕的手指数等于设置的触发旋转的最少手指数，并且滑动距离达到阈值时，手势才能被成功识别。<br>对于已成功识别的手势，后续改变触摸屏幕的手指数量，不会触发[onActionUpdate](ts-basic-gestures-rotationgesture.md#事件)事件，但可以触发[onActionEnd](ts-basic-gestures-rotationgesture.md#事件)事件。<br>默认值：false。|

## GestureGroupHandler

手势组处理器对象类型。

### constructor

constructor(options?: GestureGroupGestureHandlerOptions)

构造函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名  | 类型                                                         | 必填 | 说明               |
| ------- | ------------------------------------------------------------ | ---- | ------------------ |
| options | [GestureGroupGestureHandlerOptions](#gesturegroupgesturehandleroptions) | 否   | 手势组处理器配置参数。 |

### onCancel

onCancel(event: Callback\<void>): GestureGroupHandler

Rotation手势识别成功，接收到触摸取消事件触发回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                              | 必填 | 说明                 |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)\<void> | 是 | 顺序组合手势（GestureMode.Sequence）取消后触发回调。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| GestureGroupHandler | 返回当前手势组处理器对象。 |

## GestureGroupGestureHandlerOptions

手势组处理器配置参数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 属性         | 类型                                   | 必填 | 描述                 |
| ------------ | -------------------------------------- | ---- | -------------------- |
| mode    | [GestureMode](./ts-combined-gestures.md#gesturemode枚举说明)                          | 是   | 设置组合手势识别模式。<br/>默认值：GestureMode.Sequence      |
| gestures | [GestureHandler](#gesturehandlert)\<[TapGestureHandler](#tapgesturehandler) \| [LongPressGestureHandler](#longpressgesturehandler) \| [PanGestureHandler](#pangesturehandler) \| [SwipeGestureHandler](#swipegesturehandler) \| [PinchGestureHandler](#pinchgesturehandler) \| [RotationGestureHandler](#rotationgesturehandler) \| [GestureGroupHandler](#gesturegrouphandler)>[] | 是   | 手势组下需要包含的手势。<br/>**说明：**  <br/>当需要为一个组件同时添加单击和双击手势时，可在组合手势中添加两个TapGesture，需要双击手势在前，单击手势在后，否则不生效。 |

## GesturePriority枚举说明

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| 名称 | 描述 |
| -------- | -------- |
| NORMAL | 普通优先级手势。 |
| PRIORITY | 高优先级手势。|

## 示例

见[动态手势设置](./ts-universal-attributes-gesture-modifier.md#动态手势设置)。
