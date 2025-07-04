# @system.device (Device Information)

The **device** module provides APIs for checking information about the current device.

> **NOTE**
>
> - The APIs of this module are no longer maintained since API version 6. It is recommended that you use [`@ohos.deviceInfo`](js-apis-device-info.md).
>
> - The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```typescript
import device from '@system.device';
```

## device.getInfo<sup>(deprecated)</sup>

getInfo(options?: GetDeviceOptions): void

Obtains the device information.

> **NOTE**<br>
> Do not call **device.getInfo** before the **onShow** event of the home page.

**System capability**: SystemCapability.Startup.SystemInfo.Lite

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| options | [GetDeviceOptions](#getdeviceoptionsdeprecated) | No| Parameters for obtaining the device information.|

## GetDeviceOptions<sup>(deprecated)</sup>

Defines the parameters for obtaining the device information.

**System capability**: SystemCapability.Startup.SystemInfo.Lite

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| success | (data: DeviceResponse) => void | No| Called when an API call is successful. **data** indicates the returned device information. For details, see [DeviceResponse](#deviceresponsedeprecated).|
| fail | (data: any,code:number)=> void| No| Called when an API call has failed. **code** indicates the error code returned upon a failure.<br>**code:200**: Certain information could not be obtained.|
| complete | () => void| No| Called when an API call is complete.|

## DeviceResponse<sup>(deprecated)</sup>

Defines the device information.

**System capability**: SystemCapability.Startup.SystemInfo.Lite

| Name| Type| Description|
| -------- | -------- | -------- |
| brand | string | Brand.|
| manufacturer | string | Manufacturer.|
| model | string | Model.|
| product | string | Product number.|
| language<sup>4+</sup> | string | System language.|
| region<sup>4+</sup> | string | System region.|
| windowWidth | number | Window width.|
| windowHeight | number | Window height.|
| screenDensity<sup>4+</sup> | number | Screen density.|
| screenShape<sup>4+</sup> | string | Screen shape. The options are as follows:<br>- **rect**: rectangular screen<br>- **circle**: round screen|
| apiVersion<sup>4+</sup> | number | API version.|
| deviceType<sup>4+</sup> | string | Device type.|


**Example**

```typescript
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
