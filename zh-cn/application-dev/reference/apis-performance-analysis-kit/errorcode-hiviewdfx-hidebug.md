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

## 11400106 接口调用配额已超出

**错误信息**

Quota exceeded.

**错误描述**
接口调用配额已超出。

**可能原因**

1、进程调用次数超出配额(1次/天)。

2、整机调用次数超出配额(5次/周)。

**处理步骤**

等待进程或整机的调用配额刷新。

## 11400107 dump子进程fork失败

**错误信息**

Fork operation failed.

**错误描述**
dump子进程fork失败。

**可能原因**

系统资源不足。

**处理步骤**

建议开发者重试。若重试后依然失败，请通过[日志分析](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/ide-setup-hilog-V5#section2114542680)过滤error级别日志辅助问题定位。若依然无法解决，<!--RP1-->可向官方反馈。<!--RP1End-->

## 11400108 等待dump子进程结束失败

**错误信息**

Failed to wait for the child process to finish.

**错误描述**
等待dump子进程结束失败。

**可能原因**

系统资源不足。

**处理步骤**

建议开发者重试。若重试后依然失败，请通过[日志分析](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/ide-setup-hilog-V5#section2114542680)过滤error级别日志辅助问题定位。若依然无法解决，<!--RP1-->可向官方反馈。<!--RP1End-->

## 11400109 等待dump子进程超时

**错误信息**

Timeout while waiting for the child process to finish.

**错误描述**
等待dump子进程结束超时。

**可能原因**

整机负载高，dump过程耗时长。

**处理步骤**

建议开发者重试。若重试后依然失败，请通过[日志分析](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/ide-setup-hilog-V5#section2114542680)过滤error级别日志辅助问题定位。若依然无法解决，<!--RP1-->可向官方反馈。<!--RP1End-->

## 11400110 磁盘空间不足

**错误信息**

Failed to create dump file.

**错误描述**
磁盘空间不足。

**可能原因**

磁盘空闲存储空间少于30GB。

**处理步骤**

释放磁盘空间，满足空闲空间大于30GB。

## 11400111 Napi接口调用失败

**错误信息**

Napi interface call exception.

**错误描述**
Napi接口调用失败。

**可能原因**

javascript虚拟机异常。

**处理步骤**

建议开发者重试。若重试后依然失败，请通过[日志分析](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/ide-setup-hilog-V5#section2114542680)过滤error级别日志辅助问题定位。若依然无法解决，<!--RP1-->可向官方反馈。<!--RP1End-->

## 11400112 重复Dump采集

**错误信息**

Repeated data dump.

**错误描述**
重复Dump采集。

**可能原因**

该接口已经被调用，在调用未结束时发生了重复调用。

**处理步骤**

建议开发者优化代码逻辑，保证上次dump完成后，再开启新的dump。

## 11400113 创建dump文件失败

**错误信息**

Failed to create dump file.
**错误描述**

创建dump文件失败。

**可能原因**

1、进程目录下存在同名文件。

2、系统资源不足。

**处理步骤**

建议开发者重试。若重试后依然失败，请通过[日志分析](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/ide-setup-hilog-V5#section2114542680)过滤error级别日志辅助问题定位。若依然无法解决，<!--RP1-->可向官方反馈。<!--RP1End-->