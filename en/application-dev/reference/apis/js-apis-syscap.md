# SysCap

SystemCapability (SysCap) refers to a standalone feature in the operating system. Different devices support different SysCap sets. Each SysCap corresponds to one or more APIs. You can determine whether an API can be used by checking SysCap support.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## canIUse

canIUse(syscap: string): boolean

Checks whether a SysCap is supported.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| syscap | string | Yes| Name of the SysCap to check.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Check result. The value **true** means that the SysCap is supported, and **false** means the opposite.|

**Example**

  ```js
import geolocation from '@ohos.geolocation'

const isLocationAvailable = canIUse('SystemCapability.Location.Location');
if (isLocationAvailable) {
    geolocation.getCurrentLocation((location) => {
        console.log(location.latitude, location.longitue);
    });
} else {
    console.log('Location not by this device.');
}
  ```
