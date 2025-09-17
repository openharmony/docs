# AIP Error Codes
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @my-2024-->
<!--Designer: @cuile44; @fysun17; @AnruiWang-->
<!--Tester: @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

> NOTE
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 31300000 Internal Error

**Error Message**

Inner error.

**Description**

An internal service error occurs when an ArkData Intelligence Platform (AIP) interface is called.

**Possible Causes**

The internal service is in abnormal status. For example, the application calls **getEmbedding()** without loading the embedding model.

**Solution**

1. Check whether the APIs are called correctly. If not, apply necessary corrections.
2. Try again at specific intervals, for example, at 1s intervals or at exponentially increasing intervals. If the problem persists, ask the user to restart or update the application or update the device.
