# @system.device

The **device** module provides APIs for checking information about the current device.

> **NOTE**
> - The APIs of this module are no longer maintained since API version 6. It is recommended that you use [@ohos.deviceInfo](js-apis-device-info.md) instead.
> 
> - The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```
import device from '@system.device';
```

## device.getInfo

getInfo(Object): void

Obtains the device information.

> **NOTE**
>
> Do not call **device.getInfo** before the **onShow** event of the home page.

**System capability**: SystemCapability.Startup.SystemInfo

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| success | Function | No| Called when API call is successful.|
| fail | Function | No| Called when API call has failed.|
| complete | Function | No| Called when API call is complete.|

**Return value of success()**

| Name| Type| Description|
| -------- | -------- | -------- |
| brand | string | Brand.|
| manufacturer | string | Manufacturer.|
| model | string | Model. |
| product | string | Product number.|
| language<sup>4+</sup> | string | System language.|
| region<sup>4+</sup> | string | System region.|
| windowWidth | number | Window width.|
| windowHeight | number | Window height.|
| screenDensity<sup>4+</sup> | number | Screen density.|
| screenShape<sup>4+</sup> | string | Screen shape. The options are as follows:<br>- **rect**: rectangle screen<br>- **circle**: circle screen|
| apiVersion<sup>4+</sup> | number | API version.|
| releaseType<sup>4+</sup> | string | Release type. The value includes both the release type and the API version, for example, Beta1.<br>Available release types are as follows:<br>- **Canary**: For the same API version, different canary releases are compatible with each other, but not compatible with those of the **beta** and **release** type.<br>- **Beta**: For the same API version, different beta releases are compatible with each other, but not compatible with those of the **release** type.<br>- **Release**: Releases of this type are compatible with the latest five API versions.|
| deviceType<sup>4+</sup> | string | Device type.|

**Return value of fail()**

| Error Code| Description|
| -------- | -------- |
| 200 | The returned result contains information that cannot be obtained.|

**Example**

```
export default {    
  getInfo() {        
    device.getInfo({            
      success: function(data) {                
        console.log('Device information obtained successfully. Device brand:' + data.brand);            
      },            
      fail: function(data, code) {                
        console.log('Failed to obtain device information. Error code:'+ code + '; Error information: ' + data);            
      },        
    });    
  },
}
```
