# backgroundTaskManager错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 9800001 内存操作失败

**错误信息**

Memory operation failed.

**错误描述**

内存操作失败。

**可能原因**

1. 系统内存泄漏。
2. 系统内存不足。

**处理步骤**

1. 内存不足，请释放内存。
2. 请检查是否内存泄漏。

## 9800002 Parcel读写操作失败

**错误信息**

Parcel operation failed.

**错误描述**

进程间通信，读写操作失败。

**可能原因**

调用MessageParcel对象读取或写入对象异常。

**处理步骤**

系统内部工作异常，请稍候重试，或者重启设备尝试。

## 9800003 IPC通信失败

**错误信息**

Internal transaction failed.

**错误描述**

进程间通信，IPC通信失败。

**可能原因**

IPC通信失败。

**处理步骤**

系统内部工作异常，请稍候重试，或者重启设备尝试。

## 9800004 系统服务失败

**错误信息**

System service operation failed.

**错误描述**

客户端进程请求系统服务进程，获取系统服务操作失败。

**可能原因**

1. 系统服务还未启动。
2. 系统服务异常。

**处理步骤**

系统服务内部工作异常，请稍候重试，或者重启设备尝试。

## 9800005 长时任务校验失败

**错误信息**

Continuous task verification failed.

**错误描述**

长时任务校验失败。

**可能原因**

1. 应用重复申请长时任务。
2. 应用重复取消长时任务。
3. bgMode无效，应用配置文件属性backgroundModes没有配置任何长时任务类型。
4. 只有<!--RP1-->特定设备<!--RP1End-->才能申请长时任务KEEPING_TASK。

**处理步骤**

1. 请检查应用代码。
2. 请检查应用是否拥有系统权限。
3. 请检查应用所在设备类型。
4. 请检查应用配置属性backgroundModes。

## 9800006 长时任务通知信息校验失败

**错误信息**

Notification verification failed for a continuous task.

**错误描述**

长时任务发送通知信息校验失败。

**可能原因**

1. 缓存在资源子系统的长时任务通知信息资源加载失败。
2. 通知子系统服务异常。

**处理步骤**

1. 请检查系统长时任务资源"ohos.backgroundtaskmgr.resources"是否存在。
2. 系统服务内部工作异常，请稍候重试，或者重启设备尝试。

## 9800007 长时任务信息存储失败

**错误信息**

Continuous task storage failed.

**错误描述**

长时任务信息存储失败。

**可能原因**

1. 创建存储任务文件失败。
2. 获取真实文件路径失败。
3. 打开存储任务文件失败。

**处理步骤**

1. 请检查文件/data/service/el1/public/background_task_mgr/running_task。
2. 系统内部工作异常，请稍候重试，或者重启设备尝试。

## 9900001 短时任务调用方信息校验失败

**错误信息**

Caller information verification failed for a transient task.

**错误描述**

短时任务调用方信息校验失败。

**可能原因**

1. 获取调用方的uid或pid错误。
2. 获取调用方的bundleName错误。
3. 取消短时任务时传入的requestId无效，在申请短时任务的列表中找不到对应的requestId。

**处理步骤**

1. 请检查应用uid是否存在。
2. 请检查应用是否申请了短时任务。
3. 系统服务内部工作异常，请稍候重试，或者重启设备尝试。

## 9900002 短时任务校验失败

**错误信息**

Transient task verification failed.

**错误描述**

短时任务校验失败。

**可能原因**

1. requestSuspendDelay()方法传递的callback对象已存在。
2. cancelSuspendDelay()方法传递的callback对象不存在。
3. 应用退入后台后5s内允许申请短时任务。
4. 应用申请短时任务数量不能超过3个。
5. 应用申请短时任务每日剩余配额不足。

**处理步骤**

1. 请检查应用自身代码逻辑。
2. 应用运行短时任务完毕及时释放。

## 18700001 资源申请接口信息校验失败

**错误信息**

Caller information verification failed for an energy resource request.

**错误描述**

资源申请接口信息校验失败。

**可能原因**

1. 获取调用方的uid或pid错误。
2. 申请资源的resourceTypes超过上限。

**处理步骤**

请检查输入的参数。