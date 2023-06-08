# Console

> **NOTE**<br>
> The APIs of this module are no longer maintained since API version 7. You are advised to use ['@ohos.hilog](js-apis-hilog.md)' instead.

## console.debug

debug(message: string): void

Prints debug logs.

- Parameters
  | Name    | Type    | Mandatory  | Description         |
  | ------- | ------ | ---- | ----------- |
  | message | string | Yes   | Text to print.|


## console.log

log(message: string): void

Prints debug logs.

- Parameters
  | Name    | Type    | Mandatory  | Description         |
  | ------- | ------ | ---- | ----------- |
  | message | string | Yes   | Text to print.|


## console.info

info(message: string): void

Prints info-level logs.

- Parameters
  | Name    | Type    | Mandatory  | Description         |
  | ------- | ------ | ---- | ----------- |
  | message | string | Yes   | Text to print.|


## console.warn

warn(message: string): void

Prints warn-level logs.

- Parameters
  | Name    | Type    | Mandatory  | Description         |
  | ------- | ------ | ---- | ----------- |
  | message | string | Yes   | Text to print.|


## console.error

error(message: string): void

Prints error-level logs.

- Parameters
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
