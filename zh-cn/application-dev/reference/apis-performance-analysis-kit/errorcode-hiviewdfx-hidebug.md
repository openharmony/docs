# Hidebug错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 11400101 系统服务获取失败

**错误信息**

ServiceId invalid. The system ability does not exist.

**错误描述**
当前serviceId未查询到对应的系统服务。

**可能原因**

当前serviceId未查询到对应的系统服务。

**处理步骤**

传入正确的系统服务id。

## 11400102 重复采集

**错误信息**

Capture trace already enabled.

**错误描述**
当前进程已经开启了capture trace采集，重复采集。

**可能原因**

上次开启的trace并未关闭。

**处理步骤**

关闭上一次开启的trace。

## 11400103 权限校验失败

**错误信息**

No write permission on the file.

**错误描述**
当前目录没有权限写trace文件。

**可能原因**

当前目录可能不存在或者被误删。

**处理步骤**

重新运行采集接口，再次生成正确目录文件。

## 11400104 内部异常

**错误信息**

Abnormal trace status.

**错误描述**
当前trace采集内部状态异常。

**可能原因**

可能由于系统内核崩溃、应用进程卡死等导致，难以定位，建议开发者重启应用或者重启系统。

**处理步骤**

建议开发者重启应用或者重启系统。

## 11400105 没有开启trace

**错误信息**

No capture trace running.

**错误描述**
当前没有trace正在采集。

**可能原因**

没有开启trace采集。

**处理步骤**

先开启trace采集再停止。