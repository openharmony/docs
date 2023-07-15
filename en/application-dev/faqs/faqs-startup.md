# Startup Development

## How do I obtain the system version of a device?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Solution**

You can obtain the system version of a device through the **osFullName** attribute of the [deviceInfo](../reference/apis/js-apis-device-info.md) object.

**Sample Code**

```
import deviceInfo from '@ohos.deviceInfo'
let v = deviceInfo.osFullName
```

## How do I obtain the UDID of a device?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Solution**

-   Method 1: Run the **hdc shell bm get --udid** command.
-   Method 2: Obtain the value from the code. For details, see [udid](../reference/apis/js-apis-device-info.md).

## How do I obtain device information?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

You can call **deviceInfo** to obtain device information, such as the device model.

**Reference**

[Device Information](../reference/apis/js-apis-device-info.md)

## How do I prevent application development from being interrupted by screen saving?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Solution**

Run the **hdc shell "power-shell setmode 602"** command to turn off screen saving.
