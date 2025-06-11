# Screen Hopping Error Codes (To Be Deprecated)

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

<!--Del-->
## 4400001 Incorrect Target Device Descriptor

**Error Message**

Incorrect descriptor for the target device.

**Description**

This error code is reported if an invalid device descriptor is passed to the screen hopping API.

**Possible Causes**

1. The target device does not exist, or the device is not networked.
2. The target device descriptor is empty.

**Solution**

1. Check whether the target device for screen hopping is correctly networked with the local device.
2. Set the target device descriptor correctly.<!--DelEnd-->

<!--Del-->
## 4400002 Input Device Operation Failed

**Error Message**

Screen hop failed.

**Description**

This error code is reported if the screen hopping status is abnormal when the screen hopping API is called.

**Possible Causes**

1. When screen hopping is initiated, the local device is in the hopped state.
2. When screen hopping is disabled, the local device is in the free state.
3. When screen hopping is disabled, the local device is in the hopping state.

**Solution**

1. When initiating screen hopping, make sure that the local device is not in the hopped state.
2. When disabling screen hopping, make sure that the local device is not in the free state.
3. When disabling screen hopping, make sure that the local device is not in the hopping state.<!--DelEnd-->
