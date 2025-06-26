# 锁屏敏感数据管理错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。
<!--Del-->
## 29300001 入参错误

**错误信息**

Invalid DataType.

**可能原因**

该错误码表示参数校验出现错误，传入的dataType不为MEDIA_DATA或ALL_DATA。

**处理步骤**

检查入参，修正参数值为合法值。
<!--DelEnd-->

## 29300002 系统服务工作异常

**错误信息**

The system ability work abnormally.

**可能原因**

该错误码表示系统服务工作异常。
1. 锁屏敏感数据管理服务无法正常启动。
2. IPC数据读取写入失败。

**处理步骤**

系统服务内部工作异常，请稍后重试，或者重启设备。


## 29300003 应用未开启锁屏敏感数据保护功能

**错误信息**

The application has not enabled the data protection under lock screen.

**可能原因**

1. 应用未在[requestpermissions](../../security/AccessToken/declare-permissions.md#在配置文件中声明权限)配置权限ohos.permission.PROTECT_SCREEN_LOCK_DATA开启应用锁屏敏感数据保护功能。
2. 当前硬件不支持锁屏敏感数据保护功能。

**处理步骤**

在[requestpermissions](../../security/AccessToken/declare-permissions.md#在配置文件中声明权限)中配置权限ohos.permission.PROTECT_SCREEN_LOCK_DATA开启应用锁屏敏感数据保护功能。


## 29300004 锁屏敏感数据访问权限已释放

**错误信息**

File access is denied.

**可能原因**

锁屏敏感数据访问权限已释放。

**处理步骤**

锁屏下无法访问敏感数据，如有需要，请提示用户重新解锁屏幕，解锁后敏感数据恢复方可使用。


## 29300005 未申请锁屏敏感数据访问权限

**错误信息**

File access was not acquired.

**可能原因**

该错误码表示释放前，未申请锁屏敏感数据访问权限。

**处理步骤**

检查当前接口是否有配套使用，请在释放前先申请锁屏敏感数据访问权限。