# Vibrator Error Codes

## 14600101 Device operation failed.

**Error Message**

Device operation failed.

**Description**

This error code is reported if the HDI service is abnormal or the device is occupied when the **startVibration** interface of the vibrator module is called.

**Possible Causes**

1. The HDI service is abnormal.
2. The device is occupied.

**Procedure**

1. Retry the operation at a specified interval or at an exponential increase interval. If the operation fails for three consecutive times, stop the retry. You can also obtain the vibrator list to check for device availability.
2. Set a higher priority for the vibrator.
