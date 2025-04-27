# HiDebug错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 11400101 系统服务获取失败

**错误信息**

ServiceId invalid. The system ability does not exist.

**错误描述**
当前serviceId未查询到对应的系统服务。

**可能原因**

serviceId参数无效，或对应的服务未启动。

**处理步骤**

确保传入正确的系统服务serviceId。

## 11400102 重复采集

**错误信息**

Capture trace already enabled.

**错误描述**
进程已开启trace采集。

**可能原因**

进程正在进行trace采集。

**处理步骤**

等待trace采集结束或调用OH_HiDebug_StopAppTraceCapture关闭正在运行的trace采集。

## 11400103 权限校验失败

**错误信息**

No write permission on the file.

**错误描述**
当前目录没有权限写trace文件。

**可能原因**

目录不存在或被误删。

**处理步骤**

重新运行采集接口，再次生成正确的目录文件。

## 11400104 内部异常

**错误信息**

Abnormal trace status.

**错误描述**
当前trace采集内部状态异常。

**可能原因**

系统内核崩溃或应用进程卡死。

**处理步骤**

建议重启应用或系统。

## 11400105 未开启trace采集

**错误信息**

No capture trace running.

**错误描述**
当前没有trace正在采集。

**可能原因**

未开启trace采集。

**处理步骤**

开启trace采集，然后停止。