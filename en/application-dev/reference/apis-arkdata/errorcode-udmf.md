# UDMF Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 20400001 Settings Already Exist

**Error Message**

Settings already exist.

**Description**

The data to be set by **setAppShareOptions()** already exists.

**Possible Causes**

This error is reported when duplicate data is found.

**Solution**

To remove the existing settings, use [removeAppShareOptions](js-apis-data-unifiedDataChannel-sys.md#unifieddatachannelremoveappshareoptions12).
