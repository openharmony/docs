# Device Information

> ![icon-note.gif](public_sys-resources/icon-note.gif) **Note：**
> - The APIs of this module are no longer maintained since API version 6. It is recommended that you use [`@ohos.deviceInfo`](js-apis-device-info.md) instead.
> 
> - The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```
import device from '@system.device';
```


## device.getInfo

getInfo(Object): void

Obtains the device information.

> ![icon-note.gif](public_sys-resources/icon-note.gif) **Note：**
> Do not call **device.getInfo** before the **onShow** event of the home page.

**System capability**: SystemCapability.Startup.SysInfo

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| success | Function | No | Called&nbsp;when&nbsp;the&nbsp;device&nbsp;information&nbsp;is&nbsp;obtained |
| fail | Function | No | Called&nbsp;when&nbsp;the&nbsp;device&nbsp;information&nbsp;fails&nbsp;to&nbsp;be&nbsp;obtained |
| complete | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;complete |

The following values will be returned when the device information is obtained.

| Name | Type | Description |
| -------- | -------- | -------- |
| brand | string | Brand |
| manufacturer | string | Manufacturer |
| model | string | Model |
| product | string | Product&nbsp;number |
| language<sup>4+</sup> | string | System&nbsp;language |
| region<sup>4+</sup> | string | System&nbsp;region |
| windowWidth | number | Window&nbsp;width |
| windowHeight | number | Window&nbsp;height |
| screenDensity<sup>4+</sup> | number | Screen&nbsp;density |
| screenShape<sup>4+</sup> | string | Screen&nbsp;shape.&nbsp;The&nbsp;options&nbsp;are&nbsp;as&nbsp;follows:<br/>-&nbsp;rect:&nbsp;rectangle&nbsp;screen<br/>-&nbsp;circle:&nbsp;circle&nbsp;screen |
| apiVersion<sup>4+</sup> | number | API&nbsp;version |
| releaseType<sup>4+</sup> | string | Release&nbsp;type.&nbsp;The&nbsp;value&nbsp;includes&nbsp;both&nbsp;the&nbsp;release&nbsp;type&nbsp;and&nbsp;the&nbsp;API&nbsp;version,&nbsp;for&nbsp;example,&nbsp;Beta1.<br/>Available&nbsp;release&nbsp;types&nbsp;are&nbsp;as&nbsp;follows:<br/>-&nbsp;**Canary**:&nbsp;For&nbsp;the&nbsp;same&nbsp;API&nbsp;version,&nbsp;different&nbsp;canary&nbsp;releases&nbsp;are&nbsp;compatible&nbsp;with&nbsp;each&nbsp;other,&nbsp;but&nbsp;not&nbsp;compatible&nbsp;with&nbsp;those&nbsp;of&nbsp;the&nbsp;**beta**&nbsp;and&nbsp;**release**&nbsp;type.<br/>-&nbsp;**Beta**:&nbsp;For&nbsp;the&nbsp;same&nbsp;API&nbsp;version,&nbsp;different&nbsp;beta&nbsp;releases&nbsp;are&nbsp;compatible&nbsp;with&nbsp;each&nbsp;other,&nbsp;but&nbsp;not&nbsp;compatible&nbsp;with&nbsp;those&nbsp;of&nbsp;the&nbsp;**release**&nbsp;type.<br/>-&nbsp;**Release**:&nbsp;Releases&nbsp;of&nbsp;this&nbsp;type&nbsp;are&nbsp;compatible&nbsp;with&nbsp;the&nbsp;latest&nbsp;five&nbsp;API&nbsp;versions. |
| deviceType<sup>4+</sup> | string | Device type |

The following error code will be returned if the device information fails to be obtained.

| Error&nbsp;Code | Description |
| -------- | -------- |
| 200 | The&nbsp;returned&nbsp;result&nbsp;contains&nbsp;information&nbsp;that&nbsp;cannot&nbsp;be&nbsp;obtained. |

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