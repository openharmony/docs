# Input Monitor Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

<!--Del-->
## 4100001 Event Listening Not Supported for the Key

**Error Message**

Event listening not supported for the key.

**Description**

This error code is reported if event listening is not supported for this key.

**Possible Causes**

The current API does not support the key for which event listening is to be enabled.

**Solution**

Check whether event listening is supported for the input key. Currently, event listening is supported only for the **META_LEFT**, **META_RIGHT**, power, and volume keys.<!--DelEnd-->
