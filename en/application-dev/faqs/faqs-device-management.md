# Device Management Development



## How do I obtain the DPI of a device?

Applicable to: OpenHarmony SDK 3.2.2.5, stage model of API version 9

Import the **@ohos.display** module and call the **getDefaultDisplay** API.

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
});https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-device-info.md)
```
