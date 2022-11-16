# Pan-Sensor Error Codes

## 14500101 Service exception.

### Error information

Service exception.

### Description

This error code is reported if the HDI service is abnormal when the **on**, **once**, or **off** interface of the sensor module is called.

### Possible Causes

The HDI service is abnormal.

### Procedure

1. Retry the operation at a specified interval (for example, 1s) or at an exponential increase interval.
2. If the operation fails for three consecutive times, stop the attempt. You can also attempt to obtain the sensor list to check for device availability.

## 14600101 Device operation failed.

### Error Message

Device operation failed.

### Description

This error code is reported if the HDI service is abnormal or the device is occupied when the **startVibration** interface of the vibrator module is called.

### Possible Causes

1. The HDI service is abnormal.
2. The device is occupied.

### Procedure

1. Retry the operation at a specified interval or at an exponential increase interval. If the operation fails for three consecutive times, stop the retry. You can also obtain the vibrator list to check for device availability.
2. Set a higher priority for the vibrator.
