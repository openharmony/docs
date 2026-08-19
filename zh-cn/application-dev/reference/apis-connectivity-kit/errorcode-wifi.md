# Wi-Fi错误码

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @qq_43802146-->
<!--Designer: @qq_43802146-->
<!--Tester: @furryfurry123-->
<!--Adviser: @zhang_yixin13-->
> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 2401000 STA内部异常

**错误信息**

Operation failed.

**错误描述**

调用SysCap为SystemCapability.Communication.WiFi.Core的接口时，Wi-Fi服务内部出现未知错误。

**可能原因**

1. 和Wi-Fi服务建立通信异常。
2. Wi-Fi芯片通信异常。

**处理步骤**

1. 重新执行关闭及打开Wi-Fi开关的操作。
2. 如果步骤1无效，请尝试重启设备。

## 2501000 STA内部异常

根据实际错误原因的不同，系统会上报不同的错误信息，具体如下。

### Operation failed

**错误信息**

Operation failed.

**错误描述**

与Wi-Fi服务建立通信异常，Wi-Fi芯片通信异常。

**可能原因**

1. startScan接口报错。系统级Wi-Fi扫描服务处于不可用状态，可能由服务进程异常、驱动状态异常或接口调用过于频繁（两分钟内扫描超过四次）引起。

2. getScanInfoList接口报错。系统内部状态异常导致无法返回扫描结果列表，通常为Wi-Fi服务或驱动层临时故障。

3. addCandidateConfig接口报错。
   - 当前已添加的候选配置数量超过系统允许的最大值（16个）。
   - 系统内部异常，可能为Wi-Fi服务状态异常或配置格式错误。
   - 当前系统或固件不支持WEP加密类型的候选配置。

**处理步骤**

1. 查看系统服务状态日志，确认Wi-Fi扫描服务是否正常运行；关闭后重新开启Wi-Fi功能，若无效，请重启设备以恢复扫描服务。

2. 关闭后重新开启Wi-Fi功能，若无效，请重启设备以恢复扫描结果查询服务。

3. addCandidateConfig接口报错。
   - 减少传入的配置数量，确保不超过上限；若需更新配置，请先移除旧配置再添加新配置。
   - 若系统内部异常，请关闭后重新开启Wi-Fi功能；若无效，请重启设备以恢复服务。
   - 若候选配置使用WEP加密类型，请改用系统支持的加密类型后重新添加。

### Flight mode is enabled

**错误信息**

Flight mode is enabled.

**错误描述**

飞行模式开启导致功能异常。

**可能原因**

系统服务异常，飞行模式切换相关系统服务出现异常，未正确响应Wi-Fi请求。

**处理步骤**

1. 关闭设备的飞行模式，然后重新执行关闭及打开Wi-Fi开关的操作。
2. 如果步骤1无效，请尝试重启设备。

### Operation failed because the service is being closed

**错误信息**

Operation failed because the service is being closed.

**错误描述**

Wi-Fi服务包括P2P或热点正在关闭导致功能异常。

**可能原因**

p2p或热点服务正在停止，Wi-Fi服务正在被关闭或重启过程中。系统资源不足，内存或CPU资源紧张，系统回收Wi-Fi服务进程。

**处理步骤**

1. 重新执行关闭及打开Wi-Fi开关的操作。
2. 如果步骤1无效，请尝试重启设备。

### Scanning service is not enabled

**错误信息**

Scanning service is not enabled.

**错误描述**

扫描服务未开启导致功能异常。

**可能原因**

扫描功能未初始化。Wi-Fi扫描模块未正确初始化或启动。

**处理步骤**

1. 重新执行关闭及打开Wi-Fi开关的操作。
2. 如果步骤1无效，请尝试重启设备。

### AP service is not enabled

**错误信息**

AP service is not enabled.

**错误描述**

AP服务未开启导致功能异常。

**可能原因**

热点功能未开启，Wi-Fi热点开关未打开，AP服务不可用。飞行模式限制，飞行模式开启时AP功能被禁用。

**处理步骤**

1. 重新执行关闭及打开Wi-Fi开关的操作。
2. 如果步骤1无效，请尝试重启设备。

### Configuration is invalid

**错误信息**

Configuration is invalid.

**错误描述**

获取或删除候选网络时，传入的netid无效，导致查询失败或删除失败。

**可能原因**

配置参数为空，传入的配置参数为空指针或空字符串。

**处理步骤**

1. 检查传入的netId，确保其有效且对应已存在的候选网络配置。
2. 修正参数后重新调用接口。

### P2P MAC address not found

**错误信息**

P2P MAC address not found.

**错误描述**

P2P MAC地址未找到导致功能异常。

**可能原因**

P2P功能未启用或P2P未初始化。

**处理步骤**

1. 重新执行关闭及打开Wi-Fi开关的操作。
2. 如果步骤1无效，请尝试重启设备。

### P2P MAC address format error

**错误信息**

P2P MAC address format error.

**错误描述**

P2P MAC地址格式错误导致功能异常。

**可能原因**

MAC地址为空。

**处理步骤**

1. 检查传入的P2P MAC地址，确保地址不为空且格式正确。
2. 修正参数后重新调用接口。

### P2P internal service exception

**错误信息**

P2P internal service exception.

**错误描述**

P2P内部服务异常导致功能异常。

**可能原因**

P2P服务异常，Wi-Fi P2P内部服务进程崩溃或无响应。

**处理步骤**

1. 重新执行关闭及打开Wi-Fi开关的操作。
2. 如果步骤1无效，请尝试重启设备。

### P2P wrong parameter size

**错误信息**

P2P wrong parameter size.

**错误描述**

P2P参数大小错误导致功能异常。

**可能原因**

网络名称超长，SSID长度超过最大限制。

**处理步骤**

1. 检查传入的网络名称，确保SSID长度不超过系统允许的最大限制。
2. 修正参数后重新调用接口。

### moving freeze scanning control

**错误信息**

moving freeze scanning control.

**错误描述**

静止状态下，Wi-Fi扫描被管控。

**可能原因**

设备处于静止状态下，自动禁用Wi-Fi扫描以节省电量。

**处理步骤**

1. 移动设备位置，使设备脱离静止状态后重新尝试扫描。

## 2501001 STA功能未打开

**错误信息**

Wi-Fi STA disabled.

**错误描述**

Wi-Fi STA功能被关闭。

**可能原因**

Wi-Fi功能被关闭。

**处理步骤**

打开Wi-Fi功能。

## 2501005 用户未响应连接请求

**错误信息**

The user does not respond.

**错误描述**

应用连接候选网络，提示是否信任并建立连接，用户未响应此连接请求。

**可能原因**

1. 用户通过上滑操作关闭提示对话框。
2. 10s内，用户未点击连接或者取消。

**处理步骤**

应用连接候选网络的请求，需要用户同意。

## 2501006 用户拒绝连接请求

**错误信息**

The user refused the action.

**错误描述**

应用连接候选网络，提示是否信任并建立连接，用户取消此连接请求。

**可能原因**

用户点击取消，拒绝连接。

**处理步骤**

应用连接候选网络的请求，需要用户同意。

## 2501007 参数校验失败

**错误信息**

Parameter validation failed.

**错误描述**

参数检查失败。

**可能原因**

参数值范围错误。

**处理步骤**

阅读接口入参约束，进行排查。

## 2601000 Hotspot模块异常

**错误信息**

Operation failed.

**错误描述**

Wi-Fi服务内部执行Hotspot相关操作时出现未知错误。

**可能原因**

1. 和Wi-Fi服务建立通信异常。
2. Wi-Fi芯片通信异常。

**处理步骤**

1. 重新执行关闭及打开Hotspot开关的操作。
2. 如果步骤1无效，请尝试重启设备。

## 2701000 AP扩展模块异常

**错误信息**

Operation failed.

**错误描述**

Wi-Fi服务内部执行AP扩展相关操作时出现未知错误。

**可能原因**

1. 和Wi-Fi服务建立通信异常。
2. Wi-Fi芯片通信异常。

**处理步骤**

1. 重新执行关闭及打开AP扩展开关的操作。
2. 如果步骤1无效，请尝试重启设备。

## 2801000 P2P模块异常

**错误信息**

Operation failed.

**错误描述**

Wi-Fi服务内部执行P2P相关操作时出现未知错误。

**可能原因**

1. 和Wi-Fi服务建立通信异常。
2. Wi-Fi芯片通信异常。

**处理步骤**

1. 重新执行关闭及打开Wi-Fi开关的操作。
2. 如果步骤1无效，请尝试重启设备。

## 2801001 P2P功能未打开

**错误信息**

Wi-Fi P2P disabled.

**错误描述**

Wi-Fi服务内部执行P2P相关操作时出现错误。

**可能原因**

1. 和Wi-Fi服务建立通信异常。
2. 打开P2P服务失败。

**处理步骤**

1. 重新执行关闭及打开Wi-Fi开关的操作。
2. 如果步骤1无效，请尝试重启设备。

## 2501003 服务打开失败

**错误信息**

Operation failed because the service is being closed.

**错误描述**

打开服务操作失败，服务正在关闭。

**可能原因**

服务功能正在关闭。

**处理步骤**

重新执行打开服务操作。

## 2501004 服务关闭失败

**错误信息**

Operation failed because the service is being opened.

**错误描述**

关闭服务操作失败，服务正在打开。

**可能原因**

服务功能正在打开。

**处理步骤**

重新执行关闭服务操作。
