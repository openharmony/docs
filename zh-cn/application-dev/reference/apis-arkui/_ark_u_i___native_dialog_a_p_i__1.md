# ArkUI_NativeDialogAPI_1


## 概述

ArkUI提供的Native侧自定义弹窗接口集合。

**起始版本：** 12

**相关模块：**[ArkUI_NativeModule](_ark_u_i___native_module.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle)(\* [create](#create) )() | 创建自定义弹窗并返回指向自定义弹窗的指针。  | 
| void(\* [dispose](#dispose) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle) | 销毁自定义弹窗。  | 
| int32_t(\* [setContent](#setcontent) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) content) | 挂载自定义弹窗内容。  | 
| int32_t(\* [removeContent](#removecontent) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle) | 卸载自定义弹窗内容。  | 
| int32_t(\* [setContentAlignment](#setcontentalignment) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, int32_t alignment, float offsetX, float offsetY) | 为自定义弹窗设置对齐方式。  | 
| int32_t(\* [resetContentAlignment](#resetcontentalignment) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle) | 重置setContentAlignment方法设置的属性，使用系统默认的对齐方式。  | 
| int32_t(\* [setModalMode](#setmodalmode) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, bool isModal) | 设置自定义弹窗是否开启模态样式的弹窗。  | 
| int32_t(\* [setAutoCancel](#setautocancel) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, bool autoCancel) | 设置自定义弹窗是否允许点击遮罩层退出。  | 
| int32_t(\* [setMask](#setmask) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, uint32_t maskColor, const [ArkUI_Rect](_ark_u_i___rect.md) \*maskRect) | 设置自定义弹窗遮罩属性。  | 
| int32_t(\* [setBackgroundColor](#setbackgroundcolor) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, uint32_t backgroundColor) | 设置弹窗背景色。  | 
| int32_t(\* [setCornerRadius](#setcornerradius) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, float topLeft, float topRight, float bottomLeft, float bottomRight) | 设置弹窗背板圆角半径。  | 
| int32_t(\* [setGridColumnCount](#setgridcolumncount) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, int32_t gridCount) | 弹窗宽度占栅格宽度的个数。  | 
| int32_t(\* [enableCustomStyle](#enablecustomstyle) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, bool enableCustomStyle) | 弹窗容器样式是否自定义。  | 
| int32_t(\* [enableCustomAnimation](#enablecustomanimation) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, bool enableCustomAnimation) | 弹窗容器是否使用自定义弹窗动画。  | 
| int32_t(\* [registerOnWillDismiss](#registeronwilldismiss) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, [ArkUI_OnWillDismissEvent](_ark_u_i___native_module.md#arkui_onwilldismissevent) eventHandler) | 当触发系统定义的返回操作、键盘ESC关闭交互操作时，如果注册该回调函数，则不会立刻关闭弹窗，是否关闭由用户自行决定。  | 
| int32_t(\* [show](#show) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, bool showInSubWindow) | 显示自定义弹窗。  | 
| int32_t(\* [close](#close) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle) | 关闭自定义弹窗，如已关闭，则不生效。  | 
| int32_t(\* [registerOnWillDismissWithUserData](#registeronwilldismisswithuserdata) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, void \*userData, void(\*callback)([ArkUI_DialogDismissEvent](_ark_u_i___native_module.md#arkui_dialogdismissevent) \*event)) | 注册系统关闭自定义弹窗的监听事件。  | 


## 结构体成员变量说明


### close

```
int32_t(* ArkUI_NativeDialogAPI_1::close) (ArkUI_NativeDialogHandle handle)
```
**描述：**

关闭自定义弹窗，如已关闭，则不生效。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。


### create

```
ArkUI_NativeDialogHandle(* ArkUI_NativeDialogAPI_1::create) ()
```
**描述：**

创建自定义弹窗并返回指向自定义弹窗的指针。

**注解：**

create方法需要在调用show方法之前调用。

**返回：**

返回指向自定义弹窗的指针，如创建失败，返回空指针。


### dispose

```
void(* ArkUI_NativeDialogAPI_1::dispose) (ArkUI_NativeDialogHandle handle)
```
**描述：**

销毁自定义弹窗。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 


### enableCustomAnimation

```
int32_t(* ArkUI_NativeDialogAPI_1::enableCustomAnimation) (ArkUI_NativeDialogHandle handle, bool enableCustomAnimation)
```
**描述：**

弹窗容器是否使用自定义弹窗动画。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 
| enableCustomAnimation | true:使用自定义动画，关闭系统默认动画；false:使用系统默认动画。  | 

**注解：**

enableCustomAnimation方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。


### enableCustomStyle

```
int32_t(* ArkUI_NativeDialogAPI_1::enableCustomStyle) (ArkUI_NativeDialogHandle handle, bool enableCustomStyle)
```
**描述：**

弹窗容器样式是否自定义。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 
| enableCustomStyle | true:宽度自适应子节点，圆角为0，弹窗背景色透明；false:高度自适应子节点，宽度由栅格系统定义, 圆角半径24vp。  | 

**注解：**

enableCustomStyle方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。


### registerOnWillDismiss

```
int32_t(* ArkUI_NativeDialogAPI_1::registerOnWillDismiss) (ArkUI_NativeDialogHandle handle, ArkUI_OnWillDismissEvent eventHandler)
```
**描述：**

当触发系统定义的返回操作、键盘ESC关闭交互操作时，如果注册该回调函数，则不会立刻关闭弹窗，是否关闭由用户自行决定。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 
| eventHandler | 弹窗关闭的回调函数 参数类型{\@Link OnWillDismissEvent}。  | 

**注解：**

registerOnWillDismiss方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。


### registerOnWillDismissWithUserData

```
int32_t(* ArkUI_NativeDialogAPI_1::registerOnWillDismissWithUserData) (ArkUI_NativeDialogHandle handle, void *userData, void(*callback)(ArkUI_DialogDismissEvent *event))
```
**描述：**

注册系统关闭自定义弹窗的监听事件。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 
| userData | 用户自定义数据指针。  | 
| callback | 监听自定义弹窗关闭的回调事件。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。


### removeContent

```
int32_t(* ArkUI_NativeDialogAPI_1::removeContent) (ArkUI_NativeDialogHandle handle)
```
**描述：**

卸载自定义弹窗内容。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 

**注解：**

removeContent方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。


### resetContentAlignment

```
int32_t(* ArkUI_NativeDialogAPI_1::resetContentAlignment) (ArkUI_NativeDialogHandle handle)
```
**描述：**

重置setContentAlignment方法设置的属性，使用系统默认的对齐方式。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 

**注解：**

resetContentAlignment方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。


### setAutoCancel

```
int32_t(* ArkUI_NativeDialogAPI_1::setAutoCancel) (ArkUI_NativeDialogHandle handle, bool autoCancel)
```
**描述：**

设置自定义弹窗是否允许点击遮罩层退出。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 
| autoCancel | 设置是否允许点击遮罩层退出，true表示关闭弹窗，false表示不关闭弹窗。  | 

**注解：**

setAutoCancel方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。


### setBackgroundColor

```
int32_t(* ArkUI_NativeDialogAPI_1::setBackgroundColor) (ArkUI_NativeDialogHandle handle, uint32_t backgroundColor)
```
**描述：**

设置弹窗背景色。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 
| backgroundColor | 设置弹窗背景颜色，0xargb格式。  | 

**注解：**

setBackgroundColor方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。


### setContent

```
int32_t(* ArkUI_NativeDialogAPI_1::setContent) (ArkUI_NativeDialogHandle handle, ArkUI_NodeHandle content)
```
**描述：**

挂载自定义弹窗内容。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 
| content | 弹窗内容根节点指针。  | 

**注解：**

setContent方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。


### setContentAlignment

```
int32_t(* ArkUI_NativeDialogAPI_1::setContentAlignment) (ArkUI_NativeDialogHandle handle, int32_t alignment, float offsetX, float offsetY)
```
**描述：**

为自定义弹窗设置对齐方式。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 
| alignment | 对齐方式，参数类型{\@Link ArkUI_Alignment}。  | 
| offsetX | 弹窗的水平偏移量，浮点型。  | 
| offsetY | 弹窗的垂直偏移量，浮点型。  | 

**注解：**

setContentAlignment方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。


### setCornerRadius

```
int32_t(* ArkUI_NativeDialogAPI_1::setCornerRadius) (ArkUI_NativeDialogHandle handle, float topLeft, float topRight, float bottomLeft, float bottomRight)
```
**描述：**

设置弹窗背板圆角半径。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 
| topLeft | 设置弹窗背板左上角圆角半径。  | 
| topRight | 设置弹窗背板右上角圆角半径。  | 
| bottomLeft | 设置弹窗背板左下圆角半径。  | 
| bottomRight | 设置弹窗背板右下角圆角半径。  | 

**注解：**

setCornerRadius方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。


### setGridColumnCount

```
int32_t(* ArkUI_NativeDialogAPI_1::setGridColumnCount) (ArkUI_NativeDialogHandle handle, int32_t gridCount)
```
**描述：**

弹窗宽度占栅格宽度的个数。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 
| gridCount | 默认为按照窗口大小自适应，最大栅格数为系统最大栅格数。  | 

**注解：**

setGridColumnCount方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。


### setMask

```
int32_t(* ArkUI_NativeDialogAPI_1::setMask) (ArkUI_NativeDialogHandle handle, uint32_t maskColor, const ArkUI_Rect *maskRect)
```
**描述：**

设置自定义弹窗遮罩属性。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 
| maskColor | 设置遮罩颜色，0xargb格式。  | 
| maskRect | 遮蔽层区域范围的指针，遮蔽层区域内的事件不透传，在遮蔽层区域外的事件透传。参数类型{\@Link [ArkUI_Rect](_ark_u_i___rect.md)}。  | 

**注解：**

setMask方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。


### setModalMode

```
int32_t(* ArkUI_NativeDialogAPI_1::setModalMode) (ArkUI_NativeDialogHandle handle, bool isModal)
```
**描述：**

设置自定义弹窗是否开启模态样式的弹窗。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 
| isModal | 设置是否开启模态窗口，模态窗口有蒙层，非模态窗口无蒙层，为true时开启模态窗口。  | 

**注解：**

setModalMode方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。


### show

```
int32_t(* ArkUI_NativeDialogAPI_1::show) (ArkUI_NativeDialogHandle handle, bool showInSubWindow)
```
**描述：**

显示自定义弹窗。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 
| showInSubWindow | 是否在子窗口显示弹窗。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。
