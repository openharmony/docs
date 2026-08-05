# 交互事件错误码
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @yihao-lin-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @Brilliantry_Rui-->

> **说明：**
>
> 交互事件错误码用于定位组件事件处理、事件分发、滚动容器、手势识别器和事件数据操作中的异常，帮助开发者根据错误原因快速选择正确的组件、事件或接口参数并完成问题处理。以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码](../errorcode-universal.md)。

## 100017 组件不支持阻止默认事件

**错误信息**

Component does not support prevent function.

**错误描述**

组件不支持阻止默认事件。

**可能原因**

所使用的组件不支持[preventDefault](./arkui-ts/ts-universal-events-touch.md#touchevent对象说明)方法。

**处理步骤**

使用支持preventDefault方法的组件。

## 106102 组件不支持特定的属性或者事件

**错误信息**

The component does not support specific properties or events.

**错误描述**

组件不支持特定的属性或者事件。

**可能原因**

组件不支持当前设定的属性或事件。

**处理步骤**

使用支持当前属性或事件的组件。

## 180001 非滚动类容器

**错误信息**

Component is not a scroll container.

**错误描述**

非滚动类容器。

**可能原因**

使用的组件非滚动类容器。

**处理步骤**

使用滚动类容器。

## 180002 存储区大小不足

**错误信息**

Buffer is not large enough.

**错误描述**

存储区大小不足。

**可能原因**

传入数组的长度小于接口要求的长度。

**处理步骤**

对传入数组进行扩容。

## 180003 该事件不是克隆事件

**错误信息**

The input event pointer is not a cloned event pointer.

**错误描述**

该事件不是克隆事件。

**可能原因**

调用克隆事件接口时，必须传入通过克隆事件接口生成的克隆事件指针。

**处理步骤**

使用克隆事件指针作为接口参数。

## 180004 组件状态异常

**错误信息**

The component status is abnormal.

**错误描述**

组件状态异常。

**可能原因**

克隆事件分发到组件时组件状态异常。

**处理步骤**

使用已挂树且未销毁的组件。

## 180005 未命中可响应事件的组件

**错误信息**

No component hit to response to the event.

**错误描述**

未命中可响应事件的组件。

**可能原因**

克隆事件分发时未命中可响应事件的组件。

**处理步骤**

为组件添加该事件的监听，或使用支持响应该事件的组件。

## 180102 不支持手势识别器类型

**错误信息**

The gesture recognizer type is not supported.

**错误描述**

不支持手势识别器类型。

**可能原因**

调用手势接口时传入了不支持的手势识别器类型。

**处理步骤**

调用接口支持的手势识别器类型。
