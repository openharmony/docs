# Log

The Log module provides basic log printing capabilities and supports log printing by log level.

If you want to use more advanced log printing services, for example, filtering logs by the specified ID, you are advised to use [`@ohos.hilog`](js-apis-hilog.md).

> **NOTE**<br>
> The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## console.log

log(message: string): void

Prints logs.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| message | string | Yes   | Text to print.|


## console.debug

debug(message: string): void

Prints debug-level logs.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| message | string | Yes   | Text to print.|


## console.info

info(message: string): void

Prints info-level logs.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| message | string | Yes   | Text to print.|


## console.warn

warn(message: string): void

Prints warn-level logs.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| message | string | Yes   | Text to print.|


## console.error

error(message: string): void

Prints error-level logs.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| message | string | Yes   | Text to print.|


## Example

```
export default {    
  clickConsole(){        
    var versionCode = 1;        
    console.info('Hello World. The current version code is ' + versionCode);        
    console.log(`versionCode: ${versionCode}`);        
    / / The following is supported since API version 6: console.log('versionCode:%d.', versionCode);   
  }
}
```

Switch to the HiLog window at the bottom of HUAWEI DevEco Studio. Specifically, select the current device and process, set the log level to Info, and enter Hello World in the search box. Logs that meet the search criteria are displayed, as shown in the following figure.

![en-us_image_0000001200913929](figures/en-us_image_0000001200913929.png)
