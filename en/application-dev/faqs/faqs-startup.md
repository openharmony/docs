# Startup Development


## How do I obtain the system version of a device? (API 9)

**Solution**

You can obtain the system version of a device through the **osFullName** attribute of the [deviceInfo](../reference/apis-basic-services-kit/js-apis-device-info.md) object.

**Sample Code**

```
import deviceInfo from '@ohos.deviceInfo'
let v = deviceInfo.osFullName
```


## How do I obtain the UDID of a device? (API 9)

**Solution**

- Method 1: Run the **hdc shell bm get --udid** command.

- Method 2: Obtain the UDID from the code. For details, see [udid](../reference/apis-basic-services-kit/js-apis-device-info.md).


##  How do I obtain device information? (API 9)

You can call **deviceInfo** to obtain device information, such as the device model.

**Reference**

[Device Information](../reference/apis-basic-services-kit/js-apis-device-info.md)


## How do I prevent application development from being interrupted by screen saving? (API 9)

**Solution**

Run the **hdc shell "power-shell setmode 602"** command to turn off screen saving.
