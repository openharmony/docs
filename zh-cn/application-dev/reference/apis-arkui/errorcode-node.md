# 自定义节点错误码
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wangchensu1-->
<!--SE: @xiang-shouxing-->
<!--TSE: @sally__-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 100021 FrameNode节点不可修改

**错误信息**

The FrameNode is not modifiable.

**错误描述**

当前FrameNode节点不可修改，无法对其进行当前的操作。可能触发的操作有设置属性、增删子节点、绑定控制器。

**可能原因**

开发者尝试对声明式节点进行修改性操作，例如，设置属性、增删子节点、绑定控制器。

**处理步骤**

避免对不可修改的节点进行修改性操作。可通过try catch捕捉并处理错误，避免影响其他逻辑。

## 100022 FrameNode节点的组件类型不支持调整跨语言的属性设置权限

**错误信息**

The FrameNode cannot be set whether to support cross-language common attribute setting.

**错误描述**

当前FrameNode节点不支持跨语言属性设置，无法调整其跨语言的属性设置权限。

**可能原因**

开发者尝试调整目标FrameNode节点的跨语言属性设置权限。

**处理步骤**

NA

## 100023 参数错误

**错误信息**

Parameter error. Possible causes: 1. The component type of the node is incorrect. 2. The node is null or undefined. 3. The controller is null or undefined.

**错误描述**

当前接口传入的参数错误。

**可能原因**

1. 传入的节点参数的组件类型不正确。
2. 传入的节点参数为null或undefined。
3. 传入的控制器参数为null或undefined。

**处理步骤**

调整传入的参数值，或是提前进行判断。

## 106103 对应的操作不支持ArkTS创建的节点

**错误信息**

The corresponding operation does not support nodes created by ArkTS.

**错误描述**

对应的操作不支持ArkTS创建的节点。

**可能原因**

当前操作不支持ArkTS创建的节点。

**处理步骤**

传入非ArkTS创建的节点。

## 106203 传入的节点未挂载到组件树上

**错误信息**

**错误描述**

传入的节点未挂载到组件树上。

**可能原因**

当前传入的节点未挂载到组件树上。

**处理步骤**

调整函数调用时机，确保传入的节点已挂载到组件树上。

## 106204 不支持在非UI线程操作传入的节点

**错误信息**

Operation on passed in nodes in non UI threads is not supported.

**错误描述**

不支持在非UI线程操作传入的节点。

**可能原因**

1. 接口只支持在UI线程调用。
2. 接口支持多线程调用，但是传入的节点已挂载到UI主树上。
3. 接口支持多线程调用，但是传入的节点不是通过支持多线程的[createNode](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#createnode)接口创建的。

**处理步骤**

1. 调整函数调用时机，确保接口在UI线程调用。
2. 将传入的节点从UI主树上卸载后再调用接口。
3. 使用支持多线程调用[createNode](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#createnode)接口创建节点后再调用接口。