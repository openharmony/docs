# 截图错误码
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 100001 内部错误

**错误信息**

Internal error.

**错误描述**

该错误码在内部运行时状态出现异常时被触发。

**可能原因**

无法获取正确的UI实例、空指针异常、UI实例内部状态校验异常、组件未上树无法查询到节点、截图尺寸超过硬件限制（硬件限制可能根据不同硬件平台有所不同）等。

**处理步骤**

NA

## 160001 图像加载错误

**错误信息**

ComponentSnapshot error.

**错误描述**

图像加载错误。

**可能原因**

在进行截图操作前，若Image组件解码检查失败或节点图像加载失败。此时，调用截图接口，将可能触发相应的错误码。

**处理步骤**

NA

## 160002 截图超时

**错误信息**

ComponentSnapshot timeout.

**错误描述**

图像加载超时。

**可能原因**

系统任务未执行。

**处理步骤**

NA