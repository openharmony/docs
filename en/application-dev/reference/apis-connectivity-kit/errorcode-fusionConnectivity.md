# Error Codes of the Converged Short-Range Service Subsystem

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @chengguohong; @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=f27c946fc782ac1d031692b6ff0d2063a86e9e01 translatedAt=2026-08-03T02:10:40.717Z pushedAt=2026-08-03T07:53:29.581Z -->

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 34900001 Device Not Registered

**Error Message**

The device is not bound.

**Description**

The device is not registered.

**Possible Causes**

The application does not call [bindDevice](js-apis-fusionConnectivity-partnerAgent.md#partneragentbinddevice) to register the device.

**Solution**

Call [bindDevice](js-apis-fusionConnectivity-partnerAgent.md#partneragentbinddevice) to register the device.

## 34900003 Device Not Paired

**Error Message**

The device is not paired.

**Description**

The device is not paired.

**Possible Causes**

The device registered by the application is not paired via Bluetooth.

**Solution**

Perform the Bluetooth pairing process.

## 34900004 Device Address Registered

**Error Message**

The device address has already been bound with PartnerAgentExtensionAbility.

**Description**

The device address has been registered with [PartnerAgentExtensionAbility](js-apis-fusionConnectivity-partnerAgentExtensionAbility.md).

**Possible Causes**

The application registers the same address again.

**Solution**

Call [unbindDevice](js-apis-fusionConnectivity-partnerAgent.md#partneragentunbinddevice) to deregister the current device and then registers the new ability of [bindDevice](js-apis-fusionConnectivity-partnerAgent.md#partneragentbinddevice).

## 34900005 Bluetooth Disabled

**Error Message**

Bluetooth disabled.

**Description**

Bluetooth is disabled.

**Possible Causes**

Bluetooth is disabled.

**Solution**

Enable Bluetooth.

## 34900050 Device Has Not Initiated Ranging

**Error Message**

The device has not initiated ranging.

**Description**

The device has not initiated ranging.

**Possible causes**

The device has not initiated ranging. For example, [stopRanging](js-apis-fusionConnectivity-ranging.md#rangingstopranging) is called without [startRanging](js-apis-fusionConnectivity-ranging.md#rangingstartranging) being called first.

**Solution**

You are advised to call [startRanging](js-apis-fusionConnectivity-ranging.md#rangingstartranging) to start ranging before performing subsequent operations.

## 34900051 Device Has Initiated Ranging

**Error Message**

The device has already initiated ranging.

**Description**

The device has initiated ranging.

**Possible causes**

The device has initiated ranging. For example, [startRanging](js-apis-fusionConnectivity-ranging.md#rangingstartranging) is called repeatedly for the same device without calling [stopRanging](js-apis-fusionConnectivity-ranging.md#rangingstopranging) to stop the previous ranging first.

**Solution**

You are advised not to initiate ranging repeatedly. You can call [stopRanging](js-apis-fusionConnectivity-ranging.md#rangingstopranging) to stop the ranging and then call [startRanging](js-apis-fusionConnectivity-ranging.md#rangingstartranging) again to initiate ranging.

## 34900052 Specified Ranging Service Unsupported

**Error Message**

The specified ranging service is not supported.

**Description**

The specified type of ranging service is not supported.

**Possible causes**

The specified ranging service is not supported. For example, the input ranging type is not within the specified range, or the specified ranging type is not supported on the device.

**Solution**

This type of service does not support ranging. Use a valid ranging type by referring to [RangingTypes](js-apis-fusionConnectivity-ranging.md#rangingtypes).

## 34900053 Ranging Service Disabled

**Error Message**

The ranging service is disabled.

**Description**

The ranging service is disabled.

**Possible causes**

The ranging service is disabled. For example, the ranging service is not enabled or has been disabled, and the ranging operation cannot be started.

**Solution**

It is recommended that the user enable the service before starting ranging.

## 34900054 Invalid Parameters

**Error Message**

The parameter value does not meet specifications.

**Description**

The parameters do not meet the service specifications.

**Possible causes**

The parameters do not meet the service specifications. For example, the device ID is not in the format of xx:xx:xx:xx:xx:xx (hexadecimal).

**Solution**

Check whether the input parameters meet the service requirements.

## 34900099 Operation Failed

**Error Message**

Operation failed.

**Description**

The operation fails.

**Possible Causes**

The current operation fails due to system reasons.

**Solution**

Retry the operation.