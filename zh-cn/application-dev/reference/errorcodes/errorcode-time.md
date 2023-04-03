# 时间时区服务错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](errorcode-universal.md)。

## -1 锁屏服务异常

**错误信息** 

  The parameter check failed or permission denied or system error.

**错误描述**

参数校验失败、权限校验失败或者时间时区服务异常。

**可能原因**

该错误码代表一种通用错误码，可根据错误信息判断具体异常，可能原因如下：
1. 参数校验失败，传入参数无效。
2. 权限校验失败，权限未配置。应用设置时间未配置ohos.permission.SET_TIME或者设置时区未配置ohos.permission.SET_TIME_ZONE。
3. 系统运行异常。内存申请、多线程处理等内核通用错误。

**处理步骤**

1. 参数校验失败，传入参数无效。检查参数是否按照要求传入。
2. 权限校验失败，应用设置时间配置ohos.permission.SET_TIME或者设置时区配置ohos.permission.SET_TIME_ZONE。
3. 系统运行异常。确认内存是否足够。
