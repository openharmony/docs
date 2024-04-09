# Screen Hopping Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 20900001 Input Device Operation Failed

**Error Message**

Failed to operate the input device.

**Description**

This error code is reported if the screen hopping status is abnormal when the screen hopping API is called.

**Possible Causes**

1. When screen hopping is initiated, the local device is in the hopped state.
2. When screen hopping is disabled, the local device is in the free state.
3. When screen hopping is disabled, the local device is in the hopping state.

**Solution**

1. When initiating screen hopping, make sure that the local device is not in the hopped state.
2. When disabling screen hopping, make sure that the local device is not in the free state.
3. When disabling screen hopping, make sure that the local device is not in the hopping state.
