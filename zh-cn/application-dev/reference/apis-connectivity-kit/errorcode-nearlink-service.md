# NearLink错误码
<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @CCCZKing-->
<!--Designer: @lilong32; @CCCZKing-->
<!--Tester: @zhangjiaji111-->
<!--Adviser: @zhang_yixin13-->


> **说明：**
> 
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。


## 36100003 星闪关闭

**错误信息**

NearLink disabled.

**错误描述**

当星闪开关未打开时调用接口，将返回该错误码。

**可能原因**

星闪开关未打开。

**处理步骤**

在设备的设置界面打开星闪后重试（通常路径为“设置 &gt; 星闪和蓝牙 &gt; 星闪”，不同产品或系统版本可能为“设置 &gt; 多设备协同 &gt; 星闪”），或请通过[在线提单](https://developer.huawei.com/consumer/cn/support/feedback/#/)提交问题。


## 36100020 端口重复注册

**错误信息**

The UUID is already registered.

**错误描述**

对应UUID的端口已经被注册。

**可能原因**

使用同一个UUID重复创建端口。

**处理步骤**

调用[dataTransfer.destroyPort](js-apis-nearlink-data-transfer-api.md#datatransferdestroyport)接口销毁对应UUID的端口通道，或请通过[在线提单](https://developer.huawei.com/consumer/cn/support/feedback/#/)提交问题。


## 36100021 端口注册数量超出上限

**错误信息**

Port exceeds the upper limit.

**错误描述**

端口注册数量超出上限。

**可能原因**

数据传输业务通道分配达到上限。

**处理步骤**

调用[dataTransfer.destroyPort](js-apis-nearlink-data-transfer-api.md#datatransferdestroyport)接口销毁其他已注册的端口通道，或请通过[在线提单](https://developer.huawei.com/consumer/cn/support/feedback/#/)提交问题。


## 36100022 端口未注册

**错误信息**

The UUID is not registered.

**错误描述**

没有注册对应UUID的端口。

**可能原因**

尝试销毁一个未注册的端口。

**处理步骤**

确认要销毁的端口已注册，或请通过[在线提单](https://developer.huawei.com/consumer/cn/support/feedback/#/)提交问题。


## 36100023 数据传输拥塞

**错误信息**

Write data congestion.

**错误描述**

数据传输拥塞导致发送数据失败。

**可能原因**

协议层或芯片处理数据拥塞，导致可靠传输模式下发送数据失败。

**处理步骤**

控制数据写入流量，或请通过[在线提单](https://developer.huawei.com/consumer/cn/support/feedback/#/)提交问题。


## 36100040 整数超出范围

**错误信息**

Integer out of range.

**错误描述**

整数超出范围。

**可能原因**

传入的整数参数超出接口定义的取值范围。

**处理步骤**

修改整数参数值到接口定义的有效取值范围内（具体取值范围请参见对应接口的参数说明），或请通过[在线提单](https://developer.huawei.com/consumer/cn/support/feedback/#/)提交问题。


## 36100041 无效地址

**错误信息**

Invalid address.

**错误描述**

无效地址。

**可能原因**

传入的地址参数格式不正确，如长度不符、包含非法字符。

**处理步骤**

修改地址参数为正确格式，或请通过[在线提单](https://developer.huawei.com/consumer/cn/support/feedback/#/)提交问题。

正确的地址格式形如“11:22:33:AA:BB:FF”，由十六进制数字字符和冒号共17个字符组成。


## 36100042 数组为空

**错误信息**

Empty array.

**错误描述**

数组为空。

**可能原因**

传入的数组参数为空，或数组中未包含有效的元素。

**处理步骤**

正确填充数组内容，或请通过[在线提单](https://developer.huawei.com/consumer/cn/support/feedback/#/)提交问题。


## 36100043 无效UUID

**错误信息**

Invalid UUID.

**错误描述**

无效UUID。

**可能原因**

传入的UUID参数格式不正确，如长度不符、包含非法字符。

**处理步骤**

修改UUID参数为正确格式，或请通过[在线提单](https://developer.huawei.com/consumer/cn/support/feedback/#/)提交问题。

正确的UUID格式形如“FFFFFFFF-1234-5678-ABCD-000000001234”，由十六进制数字字符和连字符共36个字符组成，代表128比特标识。


## 36100044 禁止使用星闪标准服务UUID

**错误信息**

NearLink standard UUID not allowed.

**错误描述**

禁止使用星闪标准服务UUID。

**可能原因**

接口参数中禁止使用星闪标准服务UUID。限制场景包括：

1. 禁止直接将星闪标准服务UUID作为参数传入；

2. 禁止在自定义服务、属性、方法等服务结构中包含星闪标准服务UUID。

**处理步骤**

将接口参数中的标准服务UUID更换为自定义服务UUID，或请通过[在线提单](https://developer.huawei.com/consumer/cn/support/feedback/#/)提交问题。

标准服务UUID由星闪联盟官方定义的基础标识（37BEA880-FC70-11EA-B720-000000000000）与16比特通用唯一标识组成。自定义服务UUID的前112比特需要避免和基础标识一致。


## 36100050 不支持合作设备集合管理功能

**错误信息**

Coordinated Devices Set Management not supported.

**错误描述**

本设备不支持合作设备集合管理功能。

**可能原因**

当前设备硬件不支持合作设备集合管理功能。

**处理步骤**

如需使用合作设备集合管理功能，请使用支持星闪合作设备集合管理特性的设备，例如支持星闪音频的部分手机、平板等。也可通过查询设备能力接口确认设备是否支持该特性，或请通过[在线提单](https://developer.huawei.com/consumer/cn/support/feedback/#/)提交问题。


## 36100099 操作失败

**错误信息**

Operation failed.

**错误描述**

系统处理过程中遇到未预期的内部错误。

**可能原因**

其他未知错误。

在设备已配对的情况下再调用[startPairing](js-apis-nearlink-remote-device.md#startpairing)发起配对，会返回该错误码。

**处理步骤**

请重试操作；若问题持续存在，请通过[在线提单](https://developer.huawei.com/consumer/cn/support/feedback/#/)提交问题。
