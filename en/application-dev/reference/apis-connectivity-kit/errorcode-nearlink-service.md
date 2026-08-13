# NearLink Error Codes

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @CCCZKing-->
<!--Designer: @lilong32; @CCCZKing-->
<!--Tester: @zhangjiaji111-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=8a03c39231c24a89e7d2329d21e5c175c46ce77e translatedAt=2026-08-12T11:15:45.226Z pushedAt=2026-08-13T08:52:25.150Z -->

> **NOTE**
> 
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 36100003 NearLink Disabled

**Error Message**

NearLink disabled.

**Description**

This error code is returned if a relevant API is called when NearLink is off.

**Possible Causes**

NearLink is turned off.

**Solution**

On the settings screen of the device, go to **Settings** &gt; **NearLink &amp; Bluetooth** &gt; **NearLink** (or **Settings** &gt; **More connectivity options** &gt; **NearLink** for different products or system versions) to turn on NearLink, and try again. Alternatively, [submit a ticket online](https://developer.huawei.com/consumer/en/support/feedback/#/).

## 36100020 Duplicate Port Registration

**Error Message**

The UUID is already registered.

**Description**

A port with the UUID has been registered.

**Possible Causes**

The same UUID is used to create a port repeatedly.

**Solution**

Call the [dataTransfer.destroyPort](js-apis-nearlink-data-transfer-api.md#datatransferdestroyport) API to destroy the port with the UUID, or [submit a ticket online](https://developer.huawei.com/consumer/en/support/feedback/#/).

## 36100021 Number of Registered Ports Exceeds the Upper Limit

**Error Message**

Port exceeds the upper limit.

**Description**

The number of registered ports exceeds the upper limit.

**Possible Causes**

The number of ports allocated for data transfer reaches the upper limit.

**Solution**

Call [dataTransfer.destroyPort](js-apis-nearlink-data-transfer-api.md#datatransferdestroyport) to destroy other registered ports, or [submit a ticket online](https://developer.huawei.com/consumer/en/support/feedback/#/).

## 36100022 Port Not Registered

**Error Message**

The UUID is not registered.

**Description**

No port with the UUID is registered.

**Possible Causes**

An attempt is made to destroy an unregistered port.

**Solution**

Ensure that the port to be destroyed has been registered, or [submit a ticket online](https://developer.huawei.com/consumer/en/support/feedback/#/).

## 36100023 Data Transmission Congestion

**Error Message**

Write data congestion.

**Description**

Data transmission fails due to congestion.

**Possible Causes**

Data transmission in reliable transmission mode fails due to congestion at the protocol layer or on the chip.

**Solution**

Control data write traffic, or [submit a ticket online](https://developer.huawei.com/consumer/en/support/feedback/#/).

## 36100040 Integer Out of Range

**Error Message**

Integer out of range.

**Description**

The integer is out of range.

**Possible Causes**

The integer is out of range.

**Solution**

Change the parameter value and set it to an integer within the allowed range, or [submit a ticket online](https://developer.huawei.com/consumer/en/support/feedback/#/).

## 36100041 Invalid URL

**Error Message**

Invalid address.

**Description**

The URL is invalid.

**Possible Causes**

The URL is invalid.

**Solution**

Change the URL to a correct format, or [submit a ticket online](https://developer.huawei.com/consumer/en/support/feedback/#/).

A correct URL is in the format similar to **11:22:33:AA:BB:FF**, which consists of 17 characters, including hexadecimal digits and colons (:).

## 36100042 Empty Array

**Error Message**

Empty array.

**Description**

The array is empty.

**Possible Causes**

The array is empty.

**Solution**

Fill in the array correctly, or [submit a ticket online](https://developer.huawei.com/consumer/en/support/feedback/#/).

## 36100043 Invalid UUID

**Error Message**

Invalid UUID.

**Description**

The UUID is invalid.

**Possible Causes**

The UUID is invalid.

**Solution**

Change the UUID to a correct format, or [submit a ticket online](https://developer.huawei.com/consumer/en/support/feedback/#/).

A correct UUID is in the format similar to **FFFFFFFF-1234-5678-ABCD-000000001234**, which consists of 36 characters, including hexadecimal digits and hyphens (-), representing a 128-bit ID.

## 36100044 Standard NearLink Service UUID Not Allowed

**Error Message**

NearLink standard UUID not allowed.

**Description**

The standard NearLink service UUID is not allowed.

**Possible Causes**

The standard service UUID is not allowed in the API parameters. It is not allowed in the following scenarios:

1. The standard service UUID cannot be directly passed as a parameter.

2. The standard service UUID cannot be included in service structures such as custom services, attributes, and methods.

**Solution**

Replace the standard service UUID in the API parameters with a custom service UUID, or [submit a ticket online](https://developer.huawei.com/consumer/en/support/feedback/#/).

The standard service UUID consists of **37BEA880-FC70-11EA-B720-000000000000** officially defined by the NearLink Alliance and a 16-bit UUID. The first 112 bits of the custom service UUID must be different from the basic ID.

## 36100050 Cooperative Device Set Management Not Supported

**Error Message**

Coordinated Devices Set Management not supported.

**Description**

The device does not support cooperative device set management.

**Possible Causes**

The device does not support cooperative device set management.

**Solution**

To use the cooperative device set function, use a device that supports NearLink cooperative device set management, such as the phones and tablets that support NearLink audio. Alternatively, [submit a ticket online](https://developer.huawei.com/consumer/en/support/feedback/#/).

## 36100099 Operation Failed

**Error Message**

Operation failed.

**Description**

An unexpected internal error occurred during system processing.

**Possible Causes**

An unknown error occurred.

If the device has been paired, this error code will be returned when you call [startPairing](js-apis-nearlink-remote-device.md#startpairing) to initiate pairing.

**Solution**

Try again or [submit a ticket online](https://developer.huawei.com/consumer/en/support/feedback/#/).