# Device Management Development

## How do I obtain the DPI of a device?

Applicable to: OpenHarmony SDK 3.2.2.5, stage model of API version 9

Import the **\@ohos.display** module and call the **getDefaultDisplay** API.

Example:


```
import display from '@ohos.display'; 
display.getDefaultDisplay((err, data) => { 
  if (err.code) { 
    console.error('Test Failed to obtain the default display object. Code: ' + JSON.stringify(err)); 
    return; 
  } 
  console.info('Test Succeeded in obtaining the default display object. Data:' + JSON.stringify(data)); 
  console.info('Test densityDPI:' + JSON.stringify(data.densityDPI)); 
});
```

## How do I obtain the type of the device where the application is running?

Applicable to: OpenHarmony SDK 3.2.2.5, stage model of API version 9

Import the **\@ohos.deviceInfo** module and call the **deviceInfo.deviceType** API.

For details, see [Device Information](../reference/apis/js-apis-device-info.md).

## How do I obtain the system version of a device?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

Use the **osFullName** attribute of the [deviceInfo](../reference/apis/js-apis-device-info.md) object.

## How do I obtain the UDID of an OpenHarmony device?

Applicable to: OpenHarmony SDK3.0, stage model of API version 9

- To obtain the UDID of the connected device, run the **hdc shell bm get --udid** command.

- For details about how to obtain the UDID from code, see [udid](../reference/apis/js-apis-device-info.md).

## How do I develop a shortcut key function?

Applicable to: OpenHarmony SDK 3.2.6.5, stage model of API version 9

To develop a shortcut key function, use the APIs in [Input Consumer](../reference/apis/js-apis-inputconsumer.md).
