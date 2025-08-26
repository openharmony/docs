# Driver Error Codes
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @lixinsheng2-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @w_Machine_cc-->

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 22900001 ExternalDeviceManager Service Exception or busType Parameter Error

**Error Message**

ExternalDeviceManager service exception or busType parameter error.

**Description**

This error code is reported if the ExternalDeviceManager service is abnormal or the **busType** parameter is invalid.

**Possible Causes**

1. The product type is incorrect. Only 2-in-1 and tablet products are supported.
2. An internal communication error occurs in the ExternalDeviceManager service.
3. The **busType** parameter is not properly set.

**Solution**

1. Change the product type.
2. Restart the device<!--RP1-->. You can also submit an [issue](https://gitee.com/openharmony/drivers_external_device_manager/issues/new) online.<!--RP1End-->
3. Query the supported bus types using [deviceManager.BusType](js-apis-driver-deviceManager.md#bustype).

## 26300001 ExternalDeviceManager Service Exception

**Error Message**

ExternalDeviceManager service exception.

**Description**

This error code is reported if the ExternalDeviceManager service is abnormal.

**Possible Causes**

1. The product type is incorrect. Only 2-in-1 and tablet products are supported.
2. An internal communication error occurs in the ExternalDeviceManager service.

**Solution**

1. Change the product type.
2. Restart the device<!--RP1-->. You can also submit an [issue](https://gitee.com/openharmony/drivers_external_device_manager/issues/new) online.<!--RP1End-->

## 26300002 Binding Driver Client to Driver Server Failed

**Error Message**

The driver service does not allow any client to bind.

**Description**

This error code is reported if a driver client is prohibited from binding a driver server.

**Possible Causes**

An incorrect value is set for `ohos.permission.ACCESS_DDK_ALLOWED` in the `metadata` attribute of the `extensionAbilities` structure whose `type` is `driver`.

**Solution**

In the source code project of the non-standard peripheral driver, open the `entry/src/main/module.json5` file, and assign the value `true` to `ohos.permission.ACCESS_DDK_ALLOWED` in the `metadata` attribute of the `extensionAbilities` structure whose `type` is `driver`.

## 26300003 Driver Client Not Bound to Any Driver Server

**Error Message**

There is no binding relationship.

**Description**

This error code is reported if a driver client is not bound to any driver server.

**Possible Causes**

`unbindDriverWithDeviceId` is called when `bindDriverWithDeviceId` is not called or fails to be called.

**Solution**

Call `unbindDriverWithDeviceId` only after `bindDriverWithDeviceId` is called successfully.
