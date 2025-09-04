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
| fingerList<sup>8+</sup> | [FingerInfo](ts-gesture-settings.md#fingerinfo对象说明8)[] | 否 | 否  |输入源为触屏产生的手势，fingerList中会包含触发事件的所有触点信息；由鼠标发起的手势，fingerList中只会有一条记录；触摸板的事件大类与鼠标一致，所以由触摸板发起的手势，fingerList只会携带一条记录。<br/>**说明：**<br/>手指索引编号与位置对应，即fingerList[index]的id为index。先按下且未参与当前手势触发的手指在fingerList中对应位置为空。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| fingerInfos<sup>20+</sup> | [FingerInfo](ts-gesture-settings.md#fingerinfo对象说明8)[] | 否 | 是  |由触屏产生的手势，fingerInfos中会包含触发事件的所有触点信息；由鼠标发起的手势，fingerInfos中只会有一条记录；触摸板的事件大类与鼠标一致，所以由触摸板发起的手势，fingerInfos只会携带一条记录。<br/> **说明：**<br/>fingerInfos只会记录参与触摸的有效手指信息，先按下但未参与当前手势触发的手指在fingerInfos中不会显示。默认值为空数组[]，返回空数组时，表示当前无有效触点信息。<br/>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。|
| velocityX<sup>10+</sup> | number | 否 | 否  |用于[PanGesture](ts-basic-gestures-pangesture.md)手势中，获取当前手势的x轴方向速度。坐标轴原点为屏幕左上角，分正负方向速度，从左往右为正，反之为负。单位为vp/s。<br/>取值范围：(-∞,  +∞) <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| velocityY<sup>10+</sup> | number | 否 | 否  |用于[PanGesture](ts-basic-gestures-pangesture.md)手势中，获取当前手势的y轴方向速度。坐标轴原点为屏幕左上角，分正负方向速度，从上往下为正，反之为负。单位为vp/s。<br/>取值范围：(-∞,  +∞) <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| velocity<sup>10+</sup> | number | 否 | 否  |用于[PanGesture](ts-basic-gestures-pangesture.md)手势中，获取当前手势的主方向速度。为xy轴方向速度的平方和的算术平方根。单位为vp/s。<br/>取值范围：[0,  +∞) <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| tapLocation<sup>20+</sup> | [EventLocationInfo](ts-basic-gestures-tapgesture.md#eventlocationinfo20对象说明) | 否 | 是  |用于点击手势中，获取当前手势的坐标信息。<br/> **原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。|