# 状态管理错误码
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @liwenzhen3-->
<!--SE: @s10021109-->
<!--TSE: @TerryTsao-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码](../errorcode-universal.md)。

## 130000 addMonitor/clearMonitor非法目标对象

**错误信息**

The target is not a custom component instance or V2 class instance.

**错误描述**

[addMonitor](./js-apis-StateManagement.md#addmonitor20)/[clearMonitor](./js-apis-StateManagement.md#clearmonitor20)的目标对象参数不合法。

**可能原因**

目标对象不满足以下情况：
- [\@ObservedV2](../../ui/state-management/arkts-new-observedV2-and-trace.md)装饰的class(至少有一个[\@Trace](../../ui/state-management/arkts-new-observedV2-and-trace.md)装饰的变量)。
- [\@ComponentV2](../../ui/state-management/arkts-new-componentV2.md)装饰的自定义组件的实例。

**处理步骤**

确保addMonitor/clearMonitor的目标对象合法，详情请参见[addMonitor/clearMonitor开发指南](../../ui/state-management/arkts-new-addMonitor-clearMonitor.md#限制条件)。

## 130001 addMonitor/clearMonitor非法路径

**错误信息**

The path is invalid.

**错误描述**

addMonitor/clearMonitor的路径参数不合法。

**可能原因**

路径不是string或者不是数组类型。

**处理步骤**

确保addMonitor/clearMonitor的路径合法，详情可见[addMonitor/clearMonitor开发指南](../../ui/state-management/arkts-new-addMonitor-clearMonitor.md#限制条件)。

## 130002 addMonitor/clearMonitor非法回调方法

**错误信息**

monitorCallback is not a function or an anonymous function.

**错误描述**

addMonitor/clearMonitor的回调方法参数不合法。

**可能原因**

回调方法不是function类型，或者是匿名function。

**处理步骤**

确保addMonitor/clearMonitor的回调方法合法，详情可见[addMonitor/clearMonitor开发指南](../../ui/state-management/arkts-new-addMonitor-clearMonitor.md#限制条件)。