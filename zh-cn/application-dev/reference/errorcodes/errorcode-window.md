# 窗口错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](errorcode-universal.md)。

## 1300001 重复操作
**错误信息**<br>
Repeated operation.

**错误描述**<br>
当进行某些重复操作时，系统会报此错误码。

**可能原因**<br>
创建的窗口已经存在时，再次创建该窗口会报错。

**处理步骤**<br>
在创建窗口前，检查该窗口是否已经存在，确保为首次创建该窗口。

## 1300002 窗口状态异常
**错误信息**<br>
This window state is abnormal.

**错误描述**<br>
当窗口状态异常，如已被销毁时，操作该窗口，会报此错误码。

**可能原因**<br>
操作窗口时，该窗口已被销毁。

**处理步骤**<br>
在对窗口进行操作前，检查该窗口是否存在，确保其未被销毁，再进行相关操作。

## 1300003 系统服务工作异常
**错误信息**<br>
This window manager service works abnormally.

**错误描述**<br>
当系统服务工作异常时，会报此错误码。

**可能原因**<br>
窗口内部服务没有正常启动。

**处理步骤**<br>
系统服务内部工作异常，请稍候重试，或者重启设备尝试。

## 1300004 无权限操作
**错误信息**<br>
Unauthorized operation.

**错误描述**<br>
当对无操作权限的对象进行操作时，会报此错误码。

**可能原因**<br>
操作了其它进程的窗口对象。

**处理步骤**<br>
请检查是否非法操作了别的进程的对象，删除相关操作。

## 1300005 WindowStage异常
**错误信息**<br>
This window stage is abnormal.

**错误描述**<br>
当WindowStage异常，如已被销毁时，操作该WindowStage，会报此错误码。

**可能原因**<br>
操作WindowStage时，该WindowStage已被销毁。

**处理步骤**<br>
在对WindowStage进行操作前，检查该WindowStage是否存在，若已被销毁，请释放该WindowStage下的窗口。

## 1300006 窗口上下文异常
**错误信息**<br>
This window context is abnormal.

**错误描述**<br>
当窗口上下文异常，如已被销毁时，操作该窗口上下文，会报此错误码。

**可能原因**<br>
操作窗口上下文时，该窗口上下文已被销毁。

**处理步骤**<br>
在对窗口上下文进行操作前，检查该窗口上下文是否存在，确保其未被销毁，再进行相关操作。

1001 窗口空指针异常(deprecated)
错误信息
This window nullptr occurs.

错误描述
窗口空指针异常，如出现空指针时，操作该窗口，会报此错误码。

可能原因
操作窗口时，出现空指针。

处理步骤
在对窗口进行操作前，检查该窗口是否存在空指针，确保其不存在空指针，再进行相关操作。

1002 无效的窗口类型(deprecated)
错误信息
This window type is invalid.

错误描述
窗口类型无效。

可能原因
使用了无效的窗口类型，有效的窗口类型见WindowType。

处理步骤
请使用WindowType支持的窗口类型，再进行相关操作。

1003 无效的窗口参数(deprecated)
错误信息
This window parameter is invalid.

错误描述
当窗口参数无效时，操作该窗口，会报此错误码。

可能原因
操作窗口时，该窗口参数无效。

处理步骤
在对窗口进行操作前，检查该窗口参数是否有效，确保其参数有效，再进行相关操作。

1004 元能力服务异常(deprecated)
错误信息
This system ability service works abnormally.

错误描述
当元能力服务工作异常时，会报此错误码。

可能原因
当销毁窗口时，如初始化proxy失败。

处理步骤
元能力服务异常，重启设备尝试。

1005 IPC通信失败(deprecated)
错误信息
This window IPC failed.

错误描述
当IPC通信失败时，会报此错误码。

可能原因
操作窗口时，该窗口参数IPC传输失败。

处理步骤
在对窗口进行操作前，检查该窗口客户端和服务端服务正常，再进行相关操作。

1007 WindowExtension拉起应用失败(deprecated)
错误信息
Start ability failed.

错误描述
WindowExtension拉起应用失败。

可能原因
WindowExtension拉起应用的参数异常。

处理步骤
检查WindowExtension参数是否被异常修改，确保其参数合法，再进行相关操作
