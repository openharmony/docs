# 手势公共接口
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

为开发者提供手势相关的公共接口。

>  **说明：**
>
>  本模块首批接口从API version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## GestureInterface\<T><sup>11+</sup>

定义Gesture接口。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### tag<sup>11+</sup>

tag(tag: string): T

设置手势的标志。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                        |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| tag  |  string | 是   | 手势的标志。 |

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| T | 返回当前组件。 |

### allowedTypes<sup>14+</sup>

allowedTypes(types: Array\<SourceTool>): T

设置手势响应的输入类型。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                        |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| types  |  Array\<[SourceTool](ts-gesture-settings.md#sourcetool枚举说明9)> | 是   | 手势响应的输入类型。 |

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| T | 返回当前组件。 |

## ScrollableTargetInfo<sup>12+</sup> 

手势识别器对应的滚动类容器组件的信息，继承于[EventTargetInfo](#eventtargetinfo12)。

### isBegin<sup>12+</sup> 

isBegin(): boolean

返回当前滚动类容器组件是否在顶部，如果为Swiper组件且在循环模式下返回false。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| boolean | 当前滚动类容器组件是否在顶部。true表示组件在顶部，false表示组件不在顶部。 |

### isEnd<sup>12+</sup> 

isEnd(): boolean

返回当前滚动类容器组件是否在底部，如果为Swiper组件且在循环模式下返回false。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| boolean | 当前滚动类容器组件是否在底部。true表示组件在底部，false表示组件不在底部。 |

## EventTargetInfo<sup>12+</sup> 

手势识别器对应组件的信息。

### getId<sup>12+</sup> 

getId(): string

返回当前组件的组件标识。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| string | 当前组件的[组件标识](./ts-universal-attributes-component-id.md#id)。 |

## TouchRecognizer<sup>20+</sup> 

触摸识别器对象。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### getEventTargetInfo<sup>20+</sup>

getEventTargetInfo(): EventTargetInfo

返回当前手势识别器对应组件的信息。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| [EventTargetInfo](#eventtargetinfo12) | 当前手势识别器对应组件的信息。 |

### cancelTouch<sup>20+</sup>

cancelTouch(): void

向当前手势识别器发送触摸取消事件的信息。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

## GestureRecognizer<sup>12+</sup> 

手势识别器对象。

### getTag<sup>12+</sup> 

getTag(): string

返回当前手势识别器的tag。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| string | 当前手势识别器的标志。 |

### getType<sup>12+</sup> 

getType(): GestureControl.GestureType

返回当前手势识别器的类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| [GestureControl.GestureType](#gesturetype11) | 当前手势识别器的类型。 |

### isBuiltIn<sup>12+</sup> 

isBuiltIn(): boolean

返回当前手势识别器是否为系统内置手势。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| boolean | 当前手势识别器是否为系统内置手势。true表示手势识别器为系统内置手势，false表示非系统内置手势。 |

### setEnabled<sup>12+</sup> 

setEnabled(isEnabled: boolean): void

设置当前手势识别器的使能状态。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                           | 必填   | 说明  |
| ------- | ---------------------------------- | ---- | ----- |
| isEnabled   | boolean         | 是    | 手势识别器的使能状态。true表示当前手势识别器能够回调应用事件，false表示当前手势识别器不回调应用事件。 |

### isEnabled<sup>12+</sup> 

isEnabled(): boolean

返回当前手势识别器的使能状态。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| boolean | 当前手势识别器的使能状态。true表示当前手势识别器能够回调应用事件，false表示当前手势识别器不回调应用事件。 |

### getState<sup>12+</sup> 

getState(): GestureRecognizerState

返回当前手势识别器的状态。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| [GestureRecognizerState](#gesturerecognizerstate12) | 当前手势识别器的状态。 |

### getEventTargetInfo<sup>12+</sup> 

getEventTargetInfo(): EventTargetInfo

返回当前手势识别器对应组件的信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| [EventTargetInfo](#eventtargetinfo12) | 当前手势识别器对应组件的信息。 |

### isValid<sup>12+</sup> 

isValid(): boolean;

返回当前手势识别器是否有效。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| boolean | 当前手势识别器是否有效。<br/>当该识别器绑定的组件被析构或该识别器不在响应链上时返回false。<br/>当该识别器绑定的组件未被析构且该识别器在响应链上时返回true。 |

### getFingerCount<sup>18+</sup>

getFingerCount(): number

返回预设手指识别数阈值。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| number | 预设手指识别数阈值。<br/>取值范围：[1, 10], 整数。 |

### isFingerCountLimit<sup>18+</sup>

isFingerCountLimit(): boolean

返回预设手势是否会检测触摸屏幕上手指识别数量。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| boolean | 预设手势是否会检测触摸屏幕上手指识别数量。当绑定手势事件且会检测触摸屏幕上手指的数量时，返回true。当绑定手势事件且不会检测触摸屏幕上手指的数量时，返回false。 |

### preventBegin<sup>20+</sup>

preventBegin(): void

在手指全部抬起前阻止手势识别器参与当前手势识别。如果系统已确定该手势识别器的结果（无论成功与否），调用此接口将无效。此方法与GestureRecognizer.[setEnabled](#setenabled12)(isEnabled: boolean)不同，[setEnabled](#setenabled12)并不会阻止手势识别器对象参与手势识别过程，而只会影响手势对应的回调函数是否执行。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

## TapRecognizer<sup>18+</sup>

点击手势识别器对象，继承自[GestureRecognizer](#gesturerecognizer12)。

### getTapCount<sup>18+</sup>

getTapCount(): number

返回预设点击手势识别器连续点击次数阈值。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| number | 预设点击手势识别器连续点击次数阈值。<br/>取值范围：[0, +∞) |

## LongPressRecognizer<sup>18+</sup>

长按手势识别器对象，继承于[GestureRecognizer](#gesturerecognizer12)。

### isRepeat<sup>18+</sup>

isRepeat(): boolean

返回预设长按手势识别器是否连续触发事件回调。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| boolean | 预设长按手势识别器是否连续触发事件回调。当绑定长按手势且不会连续触发回调时，返回false。当绑定长按手势且会连续触发回调时，返回true。 |

### getDuration<sup>18+</sup>

getDuration(): number

返回预设长按手势识别器触发长按最短时间阈值。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| number | 返回预设长按手势识别器触发长按最短时间阈值，单位为ms。<br/>取值范围：[0, +∞) |

## SwipeRecognizer<sup>18+</sup>

滑动手势识别器对象，继承于[GestureRecognizer](#gesturerecognizer12)。

### getVelocityThreshold<sup>18+</sup>

getVelocityThreshold(): number

返回预设滑动手势识别器识别滑动最小速度阈值。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| number | 预设滑动手势识别器识别滑动最小速度阈值，单位为vp/s。<br/>取值范围：[0, +∞) |

### getDirection<sup>18+</sup>

getDirection(): SwipeDirection

返回预设滑动手势识别器触发滑动手势滑动方向。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| [SwipeDirection](./ts-basic-gestures-swipegesture.md#swipedirection枚举说明) | 预设滑动手势识别器触发滑动手势滑动方向。 |

## PinchRecognizer<sup>18+</sup>

捏合手势识别器对象，继承于[GestureRecognizer](#gesturerecognizer12)。

### getDistance<sup>18+</sup>

getDistance(): number

返回预设捏合手势识别器最小识别距离阈值。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| number | 预设捏合手势识别器最小识别距离阈值，单位为vp。<br/>取值范围：[0, +∞) |

## RotationRecognizer<sup>18+</sup>

旋转手势识别器对象，继承于[GestureRecognizer](#gesturerecognizer12)。

### getAngle<sup>18+</sup>

getAngle(): number

返回预设旋转手势识别器触发旋转手势最小改变度数阈值。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| number | 预设旋转手势识别器触发旋转手势最小改变度数阈值，单位为deg。<br/>取值范围：[0, +∞)<br/>**说明：** <br/>当输入的改变度数的值小于等于0或大于360时，会被转化为默认值，默认值为1。 |

## PanRecognizer<sup>12+</sup> 

拖动手势识别器对象，继承于[GestureRecognizer](#gesturerecognizer12)。

### getPanGestureOptions<sup>12+</sup> 

getPanGestureOptions(): PanGestureOptions

返回当前拖动手势识别器的属性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| [PanGestureOptions](./ts-basic-gestures-pangesture.md#pangestureoptions) | 当前拖动手势识别器的属性。 |

### getDirection<sup>19+</sup>

getDirection(): PanDirection

返回当前拖动手势识别器的识别方向。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| [PanDirection](./ts-basic-gestures-pangesture.md#pandirection枚举说明) | 当前拖动手势识别器的识别方向。 |

### getDistance<sup>19+</sup>

getDistance(): number

返回当前拖动手势识别器触发的最小滑动距离。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| number | 当前拖动手势识别器触发的最小滑动距离。单位：vp |

### getDistanceMap<sup>19+</sup>

getDistanceMap(): Map\<SourceTool, number\>

返回拖动手势识别器在不同输入源的情况下触发的最小滑动距离。

>  **说明：**
>
>  仅支持对通过Pan手势初始化配置修改的设备类型进行阈值查询。对于默认滑动阈值，可通过查询[SourceTool](ts-gesture-settings.md#sourcetool枚举说明9).Unknown类型获取。其他未主动设置的类型则无法获取。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| Map<[SourceTool](ts-gesture-settings.md#sourcetool枚举说明9), number> | 不同输入源的拖动手势识别器触发的最小滑动距离。滑动距离的单位：vp |

## GestureRecognizerState<sup>12+</sup> 

定义手势识别器状态。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 值   | 说明                           |
| ------- | ---- | ---------------------------------- |
| READY | 0    | 准备状态。 |
| DETECTING    | 1    | 检测状态。 |
| PENDING    | 2    | 等待状态。 |
| BLOCKED    | 3    | 阻塞状态。 |
| SUCCESSFUL    | 4    | 成功状态。 |
| FAILED    | 5    | 失败状态。 |

## GestureEvent对象说明

定义手势的事件信息。继承自[BaseEvent](ts-gesture-customize-judge.md#baseevent8)。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型  |   只读  | 可选    |  说明 |
| -------- | -------- | ---- | ---- |-------- |
| repeat | boolean | 否 |  否  |是否为重复触发事件，用于LongPressGesture手势触发场景。true表示重复触发事件，false表示非重复触发事件。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| offsetX | number | 否 | 否  |手势事件相对于手指按下时的偏移量X，单位为vp，用于PanGesture手势触发场景，从左向右滑动offsetX为正，反之为负。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。<br/>取值范围：(-∞, +∞) |
| offsetY | number | 否 | 否  |手势事件相对于手指按下时的偏移量Y，单位为vp，用于PanGesture手势触发场景，从上向下滑动offsetY为正，反之为负。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。<br/>取值范围：(-∞, +∞)  |
| angle | number | 否 | 否  |用于RotationGesture手势触发场景时，表示旋转角度。<br/>用于SwipeGesture手势触发场景时，表示滑动手势的角度，即两根手指间的线段与水平方向的夹角变化的度数。<br/>**说明：**<br/>角度计算方式：滑动手势被识别到后，连接两根手指之间的线被识别为起始线条，随着手指的滑动，手指之间的线条会发生旋转，根据起始线条两端点和当前线条两端点的坐标，使用反正切函数分别计算其相对于水平方向的夹角，最后arctan2(cy2-cy1,cx2-cx1)-arctan2(y2-y1,x2-x1)为旋转的角度。以起始线条为坐标系，顺时针旋转为0到180度，逆时针旋转为-180到0度。<br/>取值范围：[-180,  +180]<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| scale | number |否 | 否  |缩放比例，用于PinchGesture手势触发场景。<br/>取值范围：[0, +∞)<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| pinchCenterX | number | 否 | 否  |捏合手势中心点的x轴坐标，单位为vp，用于PinchGesture手势触发场景。<br/>取值范围：[0, +∞)<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| pinchCenterY | number | 否 | 否  |捏合手势中心点的y轴坐标，单位为vp，用于PinchGesture手势触发场景。<br/>取值范围：[0, +∞)<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| speed<sup>8+</sup> | number | 否 | 否  |滑动手势速度，即所有手指相对当前组件元素原始区域滑动的平均速度，单位为vp/s，用于SwipeGesture手势触发场景。<br/>取值范围：[0, +∞)<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| fingerList<sup>8+</sup> | [FingerInfo](./ts-gesture-common.md#fingerinfo8对象说明)[] | 否 | 否  |输入源为触屏产生的手势，fingerList中会包含触发事件的所有触点信息；由鼠标发起的手势，fingerList中只会有一条记录；触摸板的事件大类与鼠标一致，所以由触摸板发起的手势，fingerList只会携带一条记录。<br/>**说明：**<br/>手指索引编号与位置对应，即fingerList[index]的id为index。先按下且未参与当前手势触发的手指在fingerList中对应位置为空。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| fingerInfos<sup>20+</sup> | [FingerInfo](./ts-gesture-common.md#fingerinfo8对象说明)[] | 否 | 是  |由触屏产生的手势，fingerInfos中会包含触发事件的所有触点信息；由鼠标发起的手势，fingerInfos中只会有一条记录；触摸板的事件大类与鼠标一致，所以由触摸板发起的手势，fingerInfos只会携带一条记录。<br/> **说明：**<br/>fingerInfos只会记录参与触摸的有效手指信息，先按下但未参与当前手势触发的手指在fingerInfos中不会显示。默认值为空数组[]，返回空数组时，表示当前无有效触点信息。<br/>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。|
| velocityX<sup>10+</sup> | number | 否 | 否  |用于[PanGesture](ts-basic-gestures-pangesture.md)手势中，获取当前手势的x轴方向速度。坐标轴原点为屏幕左上角，分正负方向速度，从左往右为正，反之为负。单位为vp/s。<br/>取值范围：(-∞,  +∞) <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| velocityY<sup>10+</sup> | number | 否 | 否  |用于[PanGesture](ts-basic-gestures-pangesture.md)手势中，获取当前手势的y轴方向速度。坐标轴原点为屏幕左上角，分正负方向速度，从上往下为正，反之为负。单位为vp/s。<br/>取值范围：(-∞,  +∞) <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| velocity<sup>10+</sup> | number | 否 | 否  |用于[PanGesture](ts-basic-gestures-pangesture.md)手势中，获取当前手势的主方向速度。为xy轴方向速度的平方和的算术平方根。单位为vp/s。<br/>取值范围：[0,  +∞) <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| tapLocation<sup>20+</sup> | [EventLocationInfo](ts-basic-gestures-tapgesture.md#eventlocationinfo20) | 否 | 是  |用于点击手势中，获取当前手势的坐标信息。<br/> **原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。|

## GestureMask<sup>11+</sup>枚举说明

定义是否屏蔽子组件手势。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 |值| 说明 |
| -------- | ---- |-------- |
| Normal | - |不屏蔽子组件的手势，按照默认手势识别顺序进行识别。 |
| IgnoreInternal | - | 屏蔽子组件的手势，包括子组件上系统内置的手势，如子组件为List组件时，内置的滑动手势同样会被屏蔽。 若父子组件区域存在部分重叠，则只会屏蔽父子组件重叠的部分。|

## GestureJudgeResult<sup>12+</sup>

定义手势竞争结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称  | 值 | 说明                               |
| ----- | -------- | ----------------------- |
| CONTINUE  | 0 | 不影响系统手势判定流程。|
| REJECT  | 1 | 手势判定结果为失败。|

## GestureType<sup>11+</sup>

定义手势类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称  | 值 | 说明                                   |
| ----- | -------- | ------------------------------- |
| TAP_GESTURE   | 0 | 点击手势。|
| LONG_PRESS_GESTURE  | 1 | 长按手势。|
| PAN_GESTURE    | 2 | 拖动手势。|
| PINCH_GESTURE   | 3 | 捏合手势。|
| SWIPE_GESTURE    | 4 | 滑动手势。|
| ROTATION_GESTURE   | 5 | 旋转手势。|
| DRAG    | 6 | 拖拽。|
| CLICK   | 7 | 点击。|

## GestureInfo<sup>11+</sup>对象说明

手势信息类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称            | 类型                  | 只读 | 可选 | 说明         |
| ---------------  | ---------------------|----|------| -----------|
| tag              | string                | 否 | 是 | 手势标志。<br/>**说明：**<br/>未设置事件标志tag属性时，tag不返回或返回undefined。      |
| type             | [GestureControl.GestureType](./ts-gesture-common.md#gesturetype11) | 否 | 否 | 手势类型。<br/>**说明：**<br/> 当手势为未暴露类型的系统内置手势事件时，type的值为-1。 |
| isSystemGesture  | boolean                 | 否 | 否 | 当前手势是否为组件自带手势。true表示是，false表示否。<br/>默认值：false |

## FingerInfo<sup>8+</sup>对象说明

手指信息类型。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选| 说明 |
| -------- | -------- |  -------- |--------- |-------- |
| id | number | 否  | 否     |手指的索引编号，由按下手指的数量决定，按下一根手指为0，之后每按下1根手指索引编号加一。<br/>**说明：**<br/> 鼠标（索引编号为1001）、手写笔（索引编号为102）、鼠标滚轮（索引编号为0）、触摸板双指滑动（索引编号为0）的索引编号也会被转化为手指的索引编号。<br/>取值范围：[0, 9)<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| globalX | number | 否  |  否     |相对于应用窗口左上角的x轴坐标，单位为vp。<br/>取值范围：[0, +∞)<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| globalY | number | 否  |  否     |相对于应用窗口左上角的y轴坐标，单位为vp。<br/>取值范围：[0, +∞)<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| localX | number | 否  |  否     |相对于当前组件元素原始区域左上角的x轴坐标，单位为vp。<br/>取值范围：[0, +∞)<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| localY | number | 否  |  否     |相对于当前组件元素原始区域左上角的y轴坐标，单位为vp。<br/>取值范围：[0, +∞)<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| displayX<sup>12+</sup> | number | 否  | 否     | 相对于屏幕左上角的x轴坐标，单位为vp。<br/>取值范围：[0, +∞)<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| displayY<sup>12+</sup> | number | 否  |  否     |相对于屏幕左上角的y轴坐标，单位为vp。<br/>取值范围：[0, +∞)<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| hand<sup>15+</sup> | [InteractionHand](./ts-appendix-enums.md#interactionhand15) | 否  |  是     |表示事件是由左手点击还是右手点击触发。<br/>**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。 |
| globalDisplayX<sup>20+</sup> | number | 否  |  是     |相对于全局屏幕的左上角的X坐标，单位为vp。<br/>取值范围：[0, +∞)<br/>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |
| globalDisplayY<sup>20+</sup> | number | 否  |  是     |相对于全局屏幕的左上角的Y坐标，单位为vp。<br/>取值范围：[0, +∞)<br/>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |

## GestureType<sup>11+</sup>

declare type GestureType = TapGesture | LongPressGesture | PanGesture | PinchGesture | SwipeGesture | RotationGesture | GestureGroup

定义手势类型。取值类型为下表类型中的并集。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型 | 说明 |
| -------- | -------- |
| [TapGesture](ts-basic-gestures-tapgesture.md) | 点击手势，支持单次点击、多次点击识别。 |
| [LongPressGesture](ts-basic-gestures-longpressgesture.md) | 长按手势。 |
| [PanGesture](ts-basic-gestures-pangesture.md) | 平移手势，当滑动的距离达到最小阈值时触发滑动手势事件，默认滑动阈值为5vp。 |
| [PinchGesture](ts-basic-gestures-pinchgesture.md) | 捏合手势。 |
| [RotationGesture](ts-basic-gestures-rotationgesture.md) | 旋转手势。 |
| [SwipeGesture](ts-basic-gestures-swipegesture.md) | 滑动手势，滑动速度大于等于速度阈值时可识别成功，默认最小速度为100vp/s。 |
| [GestureGroup](ts-combined-gestures.md) | 手势识别组，多种手势组合为复合手势，支持连续识别、并行识别和互斥识别。 |

## BaseGestureEvent<sup>11+</sup>对象说明

基础手势事件类型。继承自[BaseEvent](./ts-gesture-customize-judge.md#baseevent8)。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称      | 类型                                  | 只读   |    可选   | 说明        |
| ---------  | -------------------------------------|-------| -----------|  -----------|
| fingerList | [FingerInfo[]](./ts-gesture-common.md#fingerinfo8对象说明) | 否 | 否 | 触发事件的所有手指信息。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| fingerInfos<sup>20+</sup> | [FingerInfo[]](./ts-gesture-common.md#fingerinfo8对象说明)  | 否 | 是 | 参与触发事件的所有有效触点信息。默认值为空数组[]，返回空数组时，表示当前无有效触点信息。<br/>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。|

## TapGestureEvent<sup>11+</sup>对象说明

继承自[BaseGestureEvent](#basegestureevent11对象说明)。可将该对象作为[onGestureJudgeBegin](./ts-gesture-customize-judge.md#ongesturejudgebegin)的event参数来传递。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称      | 类型   | 只读 | 可选                                | 说明         |
| ---------  | --- | ------|-------------------------------  | -----------|
| tapLocation<sup>20+</sup>  | [EventLocationInfo](ts-basic-gestures-tapgesture.md#eventlocationinfo20)| 否 | 是 | 获取点击手势的坐标信息。 <br/>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。|

## LongPressGestureEvent<sup>11+</sup>对象说明

继承自[BaseGestureEvent](#basegestureevent11对象说明)。可将该对象作为[onGestureJudgeBegin](./ts-gesture-customize-judge.md#ongesturejudgebegin)的event参数来传递。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称      | 类型                               | 只读 | 可选       | 说明         |
| ---------  | ----------------------------------|-----| ----------|----------|
| repeat     | boolean                           | 否  | 否    | 是否为重复触发事件。true表示为重复触发事件，false表示非重复触发事件。  |

## PanGestureEvent<sup>11+</sup>对象说明

继承自[BaseGestureEvent](#basegestureevent11对象说明)。可将该对象作为[onGestureJudgeBegin](./ts-gesture-customize-judge.md#ongesturejudgebegin)的event参数来传递。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称      | 类型       | 只读    | 可选     | 说明         |
| ---------  | ---------|-----  | ----------|--------------|
| offsetX    | number | 否 | 否 | 手势事件x轴相对当前组件元素原始区域的偏移量，单位为vp，从左向右滑动offsetX为正，反之为负。  |
| offsetY    | number | 否 | 否 | 手势事件y轴相对当前组件元素原始区域的偏移量，单位为vp，从上向下滑动offsetY为正，反之为负。  |
| velocityX  | number | 否 | 否 | 获取当前手势的x轴方向速度。坐标轴原点为屏幕左上角，分正负方向速度，从左往右为正，反之为负。单位为vp/s。  |
| velocityY  | number | 否 | 否 | 获取当前手势的y轴方向速度。坐标轴原点为屏幕左上角，分正负方向速度，从上往下为正，反之为负。单位为vp/s。|
| velocity   | number | 否 | 否 | 获取当前的主方向速度。为xy轴方向速度的平方和的算术平方根。单位为vp/s。  |

## PinchGestureEvent<sup>11+</sup>对象说明

继承自[BaseGestureEvent](#basegestureevent11对象说明)。可将该对象作为[onGestureJudgeBegin](./ts-gesture-customize-judge.md#ongesturejudgebegin)的event参数来传递。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称         | 类型     | 只读 | 可选 | 说明         |
| ------------  | --------|-----------|---------------------  | -----------|
| scale         | number | 否 | 否 | 缩放比例。  |
| pinchCenterX  | number | 否 | 否 | 捏合手势中心点相对于当前组件元素原始区域左上角x轴坐标，单位为vp。  |
| pinchCenterY  | number | 否 | 否 | 捏合手势中心点相对于当前组件元素原始区域左上角y轴坐标，单位为vp。  |

## RotationGestureEvent<sup>11+</sup>对象说明

继承自[BaseGestureEvent](#basegestureevent11对象说明)。可将该对象作为[onGestureJudgeBegin](./ts-gesture-customize-judge.md#ongesturejudgebegin)的event参数来传递。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称         | 类型                              |只读 | 可选        | 说明         |
| ------------  | ---------------------------------|----|--------------| -----------|
| angle         | number | 否 | 否 |   表示旋转角度，单位为deg。<br/>**说明：**<br/>角度计算方式：当滑动手势被识别后，连接两根手指之间的线被识别为起始线条。随着手指的滑动，手指之间的线条会发生旋转。根据起始线条和当前线条两端点的坐标，使用反正切函数分别计算其相对于水平方向的夹角。<br/>最终的旋转角度为：arctan2(cy2-cy1, cx2-cx1) - arctan2(y2-y1, x2-x1) <br/>在起始线条为坐标系的情况下，顺时针旋转为0到180度，逆时针旋转为-180到0度。  |

## SwipeGestureEvent<sup>11+</sup>对象说明

继承自[BaseGestureEvent](#basegestureevent11对象说明)。可将该对象作为[onGestureJudgeBegin](./ts-gesture-customize-judge.md#ongesturejudgebegin)的event参数来传递。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称         | 类型                         | 只读 | 可选             | 说明         |
| ------------  | ----------------------------|------|------  | -----------|
| angle         | number | 否 | 否 | 表示滑动手势的角度，即两根手指间的线段与水平方向的夹角变化的度数，单位为deg。<br/>**说明：**<br/>角度计算方式：当滑动手势被识别后，连接两根手指之间的线被识别为起始线条。随着手指的滑动，手指之间的线条会发生旋转。根据起始线条和当前线条两端点的坐标，使用反正切函数分别计算其相对于水平方向的夹角。<br/>最终的旋转角度为：arctan2(cy2-cy1, cx2-cx1) - arctan2(y2-y1, x2-x1) <br/>在起始线条为坐标系的情况下，顺时针旋转为0到180度，逆时针旋转为-180到0度。|
| speed         | number | 否 | 否 | 滑动手势速度，即所有手指相对当前组件元素原始区域滑动的平均速度，单位为vp/s。  |