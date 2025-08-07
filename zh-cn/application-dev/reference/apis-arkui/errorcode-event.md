# 交互事件错误码
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--SE: @piggyguy-->
<!--TSE: @songyanhong-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码](../errorcode-universal.md)。

## 100017 组件不支持阻止默认事件

**错误信息**

Component does not support prevent function.

**错误描述**

组件不支持阻止默认事件。

**可能原因**

使用的组件不支持preventDefault方法。

**处理步骤**

NA

## 106102 组件不支持特定的属性或者事件

**错误信息**

The component does not support specific properties or events.

**错误描述**

组件不支持特定的属性或者事件。

**可能原因**

组件不支持当前设定的属性或事件。

**处理步骤**

使用支持的组件设定属性或事件。

## 180001 非滚动类容器

**错误信息**

Component is not a scroll container.

**错误描述**

非滚动类容器。

**可能原因**

使用的组件非滚动类容器。

**处理步骤**

NA

## 180002 存储区大小不足

**错误信息**

Buffer is not large enough.

**错误描述**

存储区大小不足。

**可能原因**

数组的长度过小。

**处理步骤**

对传入数组进行扩容。

## 180003 该事件不是克隆事件

**错误信息**

The input event pointer is not a cloned event pointer.

**错误描述**

该事件不是克隆事件。

**处理步骤**

NA

## 180004 组件状态异常

**错误信息**

The component status is abnormal.

**错误描述**

组件状态异常。

**处理步骤**

NA

## 180005 未命中可响应事件的组件

**错误信息**

No component hit to response to the event.

**错误描述**

未命中可响应事件的组件。

**处理步骤**

NA

## 180102 不支持手势识别器类型

**错误信息**

The gesture recognizer type is not supported.

**错误描述**

不支持手势识别器类型。

**处理步骤**

NA