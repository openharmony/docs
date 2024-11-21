# 窗口错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

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
当窗口状态异常，如未创建或已被销毁时，操作该窗口，会报此错误码。

**可能原因**<br>
操作窗口时，该窗口未创建或已被销毁。

**处理步骤**<br>
在对窗口进行操作前，检查该窗口是否存在，确保其已创建且未被销毁，再进行相关操作。

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

## 1300007 WindowExtension拉起应用失败

**错误信息**<br>
Failed to start the ability.

**错误描述**<br>
WindowExtension拉起应用失败。

**可能原因**<br>
WindowExtension拉起应用的参数异常。

**处理步骤**<br>
检查WindowExtension参数是否被异常修改，确保其参数合法，再进行相关操作。

## 1300008 显示设备异常

**错误信息**<br>The display device is abnormal.

**错误描述**<br>显示设备异常。

**可能原因**<br>
1. 显示设备没有准备好。<br>
2. 显示设备被移除。<br>
3. 显示设备被损坏。

**处理步骤**<br>确保显示设备正常，再进行相关开发。

## 1300009 父窗口无效

**错误信息**<br>The parent window is invalid.

**错误描述**<br>父窗口无效。

**可能原因**<br>
1. 子窗口没有绑定父窗口。<br>
2. 子窗口绑定的父窗口异常，如父窗口已被销毁等。

**处理步骤**<br>
1. 检查确保子窗口成功绑定父窗口。<br>
2. 检查子窗口绑定的父窗口状态，确保父窗口状态正常。

## 1300010 当前窗口模式不支持该操作

**错误信息**<br>The operation in the current window status is invalid.

**错误描述**<br>当前窗口模式不支持该操作。

**可能原因**<br>
1. 对全屏或分屏窗口进行move操作。<br>
2. 对全屏或分屏窗口进行resize操作。

**处理步骤**<br>
1. 不要对全屏或分屏窗口进行move操作。<br>
2. 不要对全屏或分屏窗口进行resize操作。

## 1300011 销毁画中画窗口失败

**错误信息**<br>Failed to destroy the PiP window.

**错误描述**<br>销毁画中画窗口失败。

**可能原因**<br>
画中画窗口空指针。<br>

**处理步骤**<br>
无需处理。

## 1300012 画中画窗口状态异常

**错误信息**<br>The PiP window state is abnormal.

**错误描述**<br>画中画窗口状态异常。

**可能原因**<br>
画中画窗口状态异常。

**处理步骤**<br>
无需处理。

## 1300013 创建画中画窗口失败

**错误信息**<br>Failed to create the PiP window.

**错误描述**<br>创建画中画窗口失败。

**可能原因**<br>
1. 启动画中画时传入参数有误。<br>
2. 在非全屏窗口下启动画中画。

**处理步骤**<br>
1. 检查启动画中画参数。<br>
2. 不要在非全屏窗口下启动画中画。

## 1300014 画中画内部错误

**错误信息**<br>PiP internal error.

**错误描述**<br>画中画内部错误。

**可能原因**<br>
内部错误。

**处理步骤**<br>
无需处理。

## 1300015 重复操作画中画

**错误信息**<br>Repeated PiP operation.

**错误描述**<br>重复操作画中画。

**可能原因**<br>
重复启动/停止画中画。<br>

**处理步骤**<br>
不要重复启动/停止画中画。<br>

## 1001 窗口空指针异常<sup>(deprecated)</sup>
**错误信息**<br>
A window null pointer occurs.

**错误描述**<br>
窗口空指针异常，如出现空指针时，操作该窗口，会报此错误码。

**可能原因**<br>
操作窗口时，出现空指针。

**处理步骤**<br>
在对窗口进行操作前，检查该窗口是否存在空指针，确保其不存在空指针，再进行相关操作。

## 1002 无效的窗口类型<sup>(deprecated)</sup>
**错误信息**<br>
This window type is invalid.

**错误描述**<br>
窗口类型无效。

**可能原因**<br>
使用了无效的窗口类型，有效的窗口类型见[WindowType](js-apis-window.md#windowtype7)。

**处理步骤**<br>
请使用WindowType支持的窗口类型，再进行相关操作。

## 1003 无效的窗口参数<sup>(deprecated)</sup>
**错误信息**<br>
This window parameter is invalid.

**错误描述**<br>
当窗口参数无效时，操作该窗口，会报此错误码。

**可能原因**<br>
操作窗口时，该窗口参数无效。

**处理步骤**<br>
在对窗口进行操作前，检查该窗口参数是否有效，确保其参数有效，再进行相关操作。

## 1004 元能力服务异常<sup>(deprecated)</sup>
**错误信息**<br>
This system ability service works abnormally.

**错误描述**<br>
当元能力服务工作异常时，会报此错误码。

**可能原因**<br>
当销毁窗口时，如初始化proxy失败。

**处理步骤**<br>
元能力服务异常，重启设备尝试。

## 1005 IPC通信失败<sup>(deprecated)</sup>
**错误信息**<br>
This window IPC failed.

**错误描述**<br>
当IPC通信失败时，会报此错误码。

**可能原因**<br>
操作窗口时，该窗口参数IPC传输失败。

**处理步骤**<br>
在对窗口进行操作前，检查该窗口客户端和服务端服务正常，再进行相关操作。

## 1007 WindowExtension拉起应用失败<sup>(deprecated)</sup>
**错误信息**<br>
Failed to start the ability.

**错误描述**<br>
WindowExtension拉起应用失败。

**可能原因**<br>
WindowExtension拉起应用的参数异常。

**处理步骤**<br>
检查WindowExtension参数是否被异常修改，确保其参数合法，再进行相关操作。