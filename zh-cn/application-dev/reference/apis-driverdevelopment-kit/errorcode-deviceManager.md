# 驱动错误码
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @lixinsheng2-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @w_Machine_cc-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 22900001 扩展外设驱动服务异常或busType参数错误

**错误信息**

ExternalDeviceManager service exception or busType parameter error.

**错误描述**

扩展外设驱动服务异常或busType参数错误。

**可能原因**

1. 产品形态不正确，仅支持2in1和tablet。
2. 服务内部遇到通信输入输出异常。
3. 若接口存在busType参数，请检查参数是否错误。

**处理步骤**

1. 请更换目标产品形态。
2. 请尝试重启设备，<!--RP1-->或通过[在线提交issue](https://gitee.com/openharmony/drivers_external_device_manager/issues/new)来反映问题。<!--RP1End-->
3. 通过[deviceManager.BusType](js-apis-driver-deviceManager.md#bustype)查询支持的枚举值。

## 26300001 扩展外设驱动服务异常

**错误信息**

ExternalDeviceManager service exception.

**错误描述**

扩展外设驱动服务异常。

**可能原因**

1. 产品形态不正确，仅支持2in1和tablet。
2. 服务内部遇到通信输入输出异常。

**处理步骤**

1. 请更换目标产品形态。
2. 请尝试重启设备，<!--RP1-->或通过[在线提交issue](https://gitee.com/openharmony/drivers_external_device_manager/issues/new)来反映问题。<!--RP1End-->

## 26300002 驱动服务端不允许驱动客户端绑定

**错误信息**

The driver service does not allow any client to bind.

**错误描述**

驱动服务端不允许驱动客户端绑定。

**可能原因**

非标外设驱动源码工程目录下的 `entry/src/main/module.json5` 文件下，类型`type`为"driver"的`extensionAbilities`结构中，`metadata`属性下，`name`为"ohos.permission.ACCESS_DDK_ALLOWED"的`value`值配置错误。

**处理步骤**

打开非标外设源码工程，找到`entry/src/main/module.json5`文件，将类型`type`为"driver"的`extensionAbilities`结构中`metadata`属性下，`name`为"ohos.permission.ACCESS_DDK_ALLOWED"的`value`值修改为"true"。

## 26300003 驱动客户端未绑定任何驱动服务端

**错误信息**

There is no binding relationship.

**错误描述**

驱动客户端未绑定任何驱动服务端。

**可能原因**

在未调用或调用 `bindDriverWithDeviceId` 接口失败的情况下，调用 `unbindDriverWithDeviceId` 接口。

**处理步骤**

请按照接口调用顺序，先调用 `bindDriverWithDeviceId` 接口，并确认调用成功的情况下，调用 `unbindDriverWithDeviceId` 接口。