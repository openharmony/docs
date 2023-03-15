# USB Error Codes

## 14400001 USB Device Connection Denied

**Error Message**

Permission denied. Need call requestRight to get permission.

**Description**

This error code is reported if a certain API of the USB module is called but the required permission is not granted.

**Possible Causes**

The permission to access the USB device is not granted.

**Solution**

Call **requestRight** to request for the permission to access the USB device.
