# Hidebug错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 11400101 系统服务获取失败

**错误信息**

ServiceId is invalid, systemAbility is not exist.

**错误描述**
当前serviceId未查询到对应的系统服务。

**可能原因**

当前serviceId未查询到对应的系统服务。

**处理步骤**

传入正确的系统服务id。

## 11400102 开启trace采集失败

**错误信息**

Have already capture trace.

**错误描述**
当前进程已经开启了capture trace采集,重复采集。

**可能原因**

上次开启的trace并未关闭。

**处理步骤**

关闭上一次开启的trace。

## 11400103 开启trace采集失败

**错误信息**

Without write permission on the file.

**错误描述**
当前没有权限写trcae文件。

**可能原因**

没有开启对应的权限。

**处理步骤**

申请权限后再此处理。

## 11400104 开启trace采集失败

**错误信息**

The status of the trace is abnormal.

**错误描述**
当前trace的状态是非正常的

**可能原因**

可能由多种原因导致。

**处理步骤**

重启系统。

## 11400105 暂停trace采集失败

**错误信息**

No capture trace running。

**错误描述**
当前没有trace正在采集

**可能原因**

可能没有开启trace采集。

**处理步骤**

先开启trace采集再停止。