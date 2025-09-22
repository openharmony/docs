# UDMF Error Codes
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @jcwen-->
<!--Designer: @junathuawei1; @zph000-->
<!--Tester: @lj_liujing; @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 20400001 Settings Already Exist

**Error Message**

Settings already exist. To reconfigure, remove the existing sharing options.

**Description**

The data to be set by **setAppShareOptions()** already exists.

**Possible Causes**

This error is reported when [setAppShareOptions](js-apis-data-unifiedDataChannel.md#unifieddatachannelsetappshareoptions14) is called repeatedly to set **ShareOptions** of the drag-and-drop channel data.

**Solution**

Call [removeAppShareOptions](js-apis-data-unifiedDataChannel.md#unifieddatachannelremoveappshareoptions14) to clear the **ShareOptions** of the current drag-and-drop channel data, and then call [setAppShareOptions](js-apis-data-unifiedDataChannel.md#unifieddatachannelsetappshareoptions14) to set **ShareOptions**.
