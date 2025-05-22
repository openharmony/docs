# ArkUI_NativeGestureAPI_1


## 概述

手势模块接口集合。

**起始版本：** 12

**相关模块：**[ArkUI_NativeModule](_ark_u_i___native_module.md)

**所在头文件：** [native_gesture.h](native__gesture_8h.md)

## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [version](#version) | 结构版本号 = 1。  | 
| ArkUI_GestureRecognizer \*(\* [createTapGesture](#createtapgesture) )(int32_t countNum, int32_t fingersNum) | 创建敲击手势。  | 
| ArkUI_GestureRecognizer \*(\* [createTapGestureWithDistanceThreshold](#createtapgesturewithdistancethreshold) )(int32_t countNum, int32_t fingersNum, int32_t distanceThreshold) | 创建带移动范围限制的敲击手势。  | 
| ArkUI_GestureRecognizer \*(\* [createLongPressGesture](#createlongpressgesture) )(int32_t fingersNum, bool repeatResult, int32_t durationNum) | 创建长按手势。  | 
| ArkUI_GestureRecognizer \*(\* [createPanGesture](#createpangesture) )(int32_t fingersNum, [ArkUI_GestureDirectionMask](_ark_u_i___native_module.md#arkui_gesturedirectionmask) directions, double distanceNum) | 创建拖动手势。directions默认值为NONE。  | 
| ArkUI_GestureRecognizer \*(\* [createPinchGesture](#createpinchgesture) )(int32_t fingersNum, double distanceNum) | 创建捏合手势。  | 
| ArkUI_GestureRecognizer \*(\* [createRotationGesture](#createrotationgesture) )(int32_t fingersNum, double angleNum) | 创建旋转手势。  | 
| ArkUI_GestureRecognizer \*(\* [createSwipeGesture](#createswipegesture) )(int32_t fingersNum, [ArkUI_GestureDirectionMask](_ark_u_i___native_module.md#arkui_gesturedirectionmask) directions, double speedNum) | 创建滑动手势。  | 
| ArkUI_GestureRecognizer \*(\* [createGroupGesture](#creategroupgesture) )([ArkUI_GroupGestureMode](_ark_u_i___native_module.md#arkui_groupgesturemode) gestureMode) | 创建手势组。  | 
| void(\* [dispose](#dispose) )(ArkUI_GestureRecognizer \*recognizer) | 销毁手势，释放资源。  | 
| int32_t(\* [addChildGesture](#addchildgesture) )(ArkUI_GestureRecognizer \*group, ArkUI_GestureRecognizer \*child) | 手势组增加子手势。  | 
| int32_t(\* [removeChildGesture](#removechildgesture) )(ArkUI_GestureRecognizer \*group, ArkUI_GestureRecognizer \*child) | 删除子手势。  | 
| int32_t(\* [setGestureEventTarget](#setgestureeventtarget) )(ArkUI_GestureRecognizer \*recognizer, [ArkUI_GestureEventActionTypeMask](_ark_u_i___native_module.md#arkui_gestureeventactiontypemask) actionTypeMask, void \*extraParams, void(\*targetReceiver)(ArkUI_GestureEvent \*event, void \*extraParams)) | 创建手势关联回调方法。  | 
| int32_t(\* [addGestureToNode](#addgesturetonode) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, ArkUI_GestureRecognizer \*recognizer, [ArkUI_GesturePriority](_ark_u_i___native_module.md#arkui_gesturepriority) mode, [ArkUI_GestureMask](_ark_u_i___native_module.md#arkui_gesturemask) mask) | 将手势添加到UI组件。  | 
| int32_t(\* [removeGestureFromNode](#removegesturefromnode) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, ArkUI_GestureRecognizer \*recognizer) | 在节点中移除手势。  | 
| int32_t(\* [setGestureInterrupterToNode](#setgestureinterruptertonode) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_GestureInterruptResult](_ark_u_i___native_module.md#arkui_gestureinterruptresult)(\*interrupter)(ArkUI_GestureInterruptInfo \*info)) | 设置节点手势打断回调。  | 
| [ArkUI_GestureRecognizerType](_ark_u_i___native_module.md#arkui_gesturerecognizertype)(\* [getGestureType](#getgesturetype) )(ArkUI_GestureRecognizer \*recognizer) | 获取手势类别。  | 
| int32_t(\* [setInnerGestureParallelTo](#setinnergestureparallelto) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, void \*userData, ArkUI_GestureRecognizer \*(\*parallelInnerGesture)([ArkUI_ParallelInnerGestureEvent](_ark_u_i___native_module.md#arkui_parallelinnergestureevent) \*event)) | 设置并行内部手势事件回调。  | 


## 结构体成员变量说明


### addChildGesture

```
int32_t(* ArkUI_NativeGestureAPI_1::addChildGesture) (ArkUI_GestureRecognizer *group, ArkUI_GestureRecognizer *child)
```
**描述：**

手势组增加子手势。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| group | 需要被关联子手势的手势组。  | 
| child | 子手势。  | 

**返回：**

0 - 成功。 401 - 参数错误。比如添加手势到非手势组对象内。


### addGestureToNode

```
int32_t(* ArkUI_NativeGestureAPI_1::addGestureToNode) (ArkUI_NodeHandle node, ArkUI_GestureRecognizer *recognizer, ArkUI_GesturePriority mode, ArkUI_GestureMask mask)
```
**描述：**

将手势添加到UI组件。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| node | 需要被绑定手势的ARKUI组件。  | 
| recognizer | 绑定此节点的手势。  | 
| mode | 标识此手势的模式（NORMAL_GESTURE， PARALLEL_GESTURE， PRIORITY_GESTURE）。  | 
| mask | 手势屏蔽模式。  | 

**返回：**

0 - 成功。 401 - 参数错误。


### createGroupGesture

```
ArkUI_GestureRecognizer*(* ArkUI_NativeGestureAPI_1::createGroupGesture) (ArkUI_GroupGestureMode gestureMode)
```
**描述：**

创建手势组。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| gestureMode | 手势组模式。  | 

**返回：**

返回创建的手势组指针。


### createLongPressGesture

```
ArkUI_GestureRecognizer*(* ArkUI_NativeGestureAPI_1::createLongPressGesture) (int32_t fingersNum, bool repeatResult, int32_t durationNum)
```
**描述：**

创建长按手势。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| fingersNum | 触发长按的最少手指数，最小为1指， 最大取值为10指。  | 
| repeatResult | 是否连续触发事件回调。  | 
| durationNum | 触发长按的最短时间，单位为毫秒（ms）。设置小于等于0时，按照默认值500处理。  | 

**返回：**

返回创建的敲击手势指针。


### createPanGesture

```
ArkUI_GestureRecognizer*(* ArkUI_NativeGestureAPI_1::createPanGesture) (int32_t fingersNum, ArkUI_GestureDirectionMask directions, double distanceNum)
```
**描述：**

创建拖动手势。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| fingersNum | 用于指定触发拖动的最少手指数，最小为1指，最大取值为10指。当设置的值小于1或不设置时，会被转化为默认值 1。  | 
| directions | 用于指定触发拖动的手势方向，此枚举值支持逻辑与(&amp;)和逻辑或（\|）运算。  | 
| distanceNum | 用于指定触发拖动手势事件的最小拖动距离，单位为px。当设定的值小于等于0时，按默认值5px处理。  | 

**返回：**

返回创建的拖动手势指针。


### createPinchGesture

```
ArkUI_GestureRecognizer*(* ArkUI_NativeGestureAPI_1::createPinchGesture) (int32_t fingersNum, double distanceNum)
```
**描述：**

创建捏合手势。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| fingersNum | 触发捏合的最少手指数, 最小为2指，最大为5指。默认值：2。  | 
| distanceNum | 最小识别距离，单位为px。当设置识别距离的值小于等于0时，会被转化为默认值5px处理。  | 

**返回：**

返回创建的手势指针。


### createRotationGesture

```
ArkUI_GestureRecognizer*(* ArkUI_NativeGestureAPI_1::createRotationGesture) (int32_t fingersNum, double angleNum)
```
**描述：**

创建旋转手势。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| fingersNum | 触发旋转的最少手指数, 最小为2指，最大为5指。默认值：2。  | 
| angleNum | 触发旋转手势的最小改变度数，单位为deg。默认值：1。当改变度数的值小于等于0或大于360时，会被转化为默认值 1。  | 

**返回：**

返回创建的手势指针。


### createSwipeGesture

```
ArkUI_GestureRecognizer*(* ArkUI_NativeGestureAPI_1::createSwipeGesture) (int32_t fingersNum, ArkUI_GestureDirectionMask directions, double speedNum)
```
**描述：**

创建滑动手势。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| fingersNum | 触发滑动的最少手指数，默认为1，最小为1指，最大为10指。  | 
| directions | 触发滑动手势的滑动方向。  | 
| speedNum | 识别滑动的最小速度，单位 px/s。当设置滑动速度的值小于等于0时，会被转化为默认值100px/s。  | 

**返回：**

返回创建的手势指针。


### createTapGesture

```
ArkUI_GestureRecognizer*(* ArkUI_NativeGestureAPI_1::createTapGesture) (int32_t countNum, int32_t fingersNum)
```
**描述：**

创建敲击手势。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| countNum | 识别的连续点击次数。当设置的值小于1或不设置时，会被转化为默认值 1。  | 
| fingersNum | 触发点击的手指数，最小为1指， 最大为10指。当设置小于1的值或不设置时，会被转化为默认值 1。  | 

**返回：**

返回创建的敲击手势指针。


### createTapGestureWithDistanceThreshold

```
ArkUI_GestureRecognizer*(* ArkUI_NativeGestureAPI_1::createTapGestureWithDistanceThreshold) (int32_t countNum, int32_t fingersNum, int32_t distanceThreshold)
```
**描述：**

创建带移动范围限制的敲击手势。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| countNum | 识别的连续点击次数。当设置的值小于1或不设置时，会被转化为默认值 1。  | 
| fingersNum | 触发点击的手指数，最小为1指， 最大为10指。当设置小于1的值或不设置时，会被转化为默认值 1。  | 
| distanceThreshold | 手指允许的移动距离范围。当设置的值小于0或者不设置时，会被转化为默认值无穷大。  | 

**返回：**

返回创建的敲击手势指针。


### dispose

```
void(* ArkUI_NativeGestureAPI_1::dispose) (ArkUI_GestureRecognizer *recognizer)
```
**描述：**

销毁手势，释放资源。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| recognizer | 需要被销毁的手势。  | 


### getGestureType

```
ArkUI_GestureRecognizerType(* ArkUI_NativeGestureAPI_1::getGestureType) (ArkUI_GestureRecognizer *recognizer)
```
**描述：**

获取手势类别。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| recognizer | 手势指针。  | 

**返回：**

手势类型。


### removeChildGesture

```
int32_t(* ArkUI_NativeGestureAPI_1::removeChildGesture) (ArkUI_GestureRecognizer *group, ArkUI_GestureRecognizer *child)
```
**描述：**

删除子手势。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| group | 需要被删除子手势的手势组。  | 
| child | 子手势。  | 

**返回：**

0 - 成功。 401 - 参数错误。


### removeGestureFromNode

```
int32_t(* ArkUI_NativeGestureAPI_1::removeGestureFromNode) (ArkUI_NodeHandle node, ArkUI_GestureRecognizer *recognizer)
```
**描述：**

在节点中移除手势。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| node | 需要被移除手势的节点。  | 
| recognizer | 需要被移除的手势。  | 

**返回：**

0 - 成功。 401 - 参数错误。


### setGestureEventTarget

```
int32_t(* ArkUI_NativeGestureAPI_1::setGestureEventTarget) (ArkUI_GestureRecognizer *recognizer, ArkUI_GestureEventActionTypeMask actionTypeMask, void *extraParams, void(*targetReceiver)(ArkUI_GestureEvent *event, void *extraParams))
```
**描述：**

创建手势关联回调方法。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| recognizer | 需要被绑定回调事件的各类手势指针。  | 
| actionTypeMask | 需要相应的手势事件类型集合，一次性可以注册多个回调，在回调中区分回调事件类型。 例：actionTypeMask = GESTURE_EVENT_ACTION_ACCEPT \| GESTURE_EVENT_ACTION_UPDATE;  | 
| extraParams | targetReceiver 回调时传入的上下文数据。  | 
| targetReceiver | 对应注册手势类型的事件回调处理， event 返回手势回调数据。  | 

**返回：**

0 - 成功。 401 - 参数错误。


### setGestureInterrupterToNode

```
int32_t(* ArkUI_NativeGestureAPI_1::setGestureInterrupterToNode) (ArkUI_NodeHandle node, ArkUI_GestureInterruptResult(*interrupter)(ArkUI_GestureInterruptInfo *info))
```
**描述：**

设置节点手势打断回调。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| node | 需要被设置手势打断回调的ARKUI节点。  | 
| interrupter | 打断回调, info 返回手势打断数据。 interrupter 返回 GESTURE_INTERRUPT_RESULT_CONTINUE, 手势正常进行； 返回 GESTURE_INTERRUPT_RESULT_REJECT 手势打断。  | 

**返回：**

0 - 成功。 401 - 参数错误。


### setInnerGestureParallelTo

```
int32_t(* ArkUI_NativeGestureAPI_1::setInnerGestureParallelTo) (ArkUI_NodeHandle node, void *userData, ArkUI_GestureRecognizer *(*parallelInnerGesture)(ArkUI_ParallelInnerGestureEvent *event))
```
**描述：**

设置并行内部手势事件回调。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| node | 需要被设置并行内部手势事件回调的ARKUI节点。  | 
| userData | 用户自定义数据。  | 
| parallelInnerGesture | 并行内部手势事件，event 返回并行内部手势事件数据。 parallelInnerGesture 返回 需要并行的手势识别器指针。  | 

**返回：**

0 - 成功。 401 - 参数错误。


### version

```
int32_t ArkUI_NativeGestureAPI_1::version
```
**描述：**

结构版本号 = 1。
