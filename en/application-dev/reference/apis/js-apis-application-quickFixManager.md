# quickFixManager

The **quickFixManager** module provides APIs for quick fix. With quick fix, you can fix bugs in your application by applying patches, which is more efficient than by updating the entire application.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```
import quickFixManager from '@ohos.application.quickFixManager';
```

## HapModuleQuickFixInfo

Defines the quick fix information at the HAP file level.

**System capability**: SystemCapability.Ability.AbilityRuntime.QuickFix

**System API**: This is a system API and cannot be called by third-party applications.

| Name       | Readable/Writable| Type                | Mandatory| Description                                                        |
| ----------- | -------- | -------------------- | ---- | ------------------------------------------------------------ |
| moduleName    | Read only    | string               | Yes  | Name of the HAP file.                              |
| originHapHash    | Read only    | string               | Yes  | Hash value of the HAP file.                              |
| quickFixFilePath    | Read only    | string               | Yes  | Installation path of the quick fix file.                              |

## ApplicationQuickFixInfo

Defines the quick fix information at the application level.

**System capability**: SystemCapability.Ability.AbilityRuntime.QuickFix

**System API**: This is a system API and cannot be called by third-party applications.

| Name       | Readable/Writable| Type                | Mandatory| Description                                                        |
| ----------- | -------- | -------------------- | ---- | ------------------------------------------------------------ |
| bundleName    | Read only    | string               | Yes  | Bundle name of the application.                              |
| bundleVersionCode    | Read only    | number               | Yes  | Internal version number of the application.                              |
| bundleVersionName    | Read only    | string               | Yes  | Version number of the application that is shown to users.                              |
| quickFixVersionCode    | Read only    | number               | Yes  | Version code of the quick fix patch package.                              |
| quickFixVersionName    | Read only    | string               | Yes  | Text description of the version number of the quick fix patch package.                              |
| hapModuleQuickFixInfo    | Read only    | Array\<[HapModuleQuickFixInfo](#hapmodulequickfixinfo)>      | Yes  | Quick fix information at the HAP file level.    |

## quickFixManager.applyQuickFix

applyQuickFix(hapModuleQuickFixFiles: Array\<string>, callback: AsyncCallback\<void>): void;

Applies a quick fix patch. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INSTALL_BUNDLE

**System capability**: SystemCapability.Ability.AbilityRuntime.QuickFix

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Parameter| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | hapModuleQuickFixFiles | Array\<string> | No| Quick fix files, each of which must contain a valid file path.| 
  | callback | AsyncCallback\<void> | No| Callback used to return the result.| 

**Example**
    
```js
  import quickFixManager from '@ohos.application.quickFixManager'

  let hapModuleQuickFixFiles = ["/data/storage/el2/base/entry.hqf"]
  quickFixManager.applyQuickFix(hapModuleQuickFixFiles, (error) => {
      if (error) {
          console.info( `applyQuickFix failed with error + ${error}`)
      } else {
          console.info( 'applyQuickFix success')
      }
  })
```

## quickFixManager.applyQuickFix

applyQuickFix(hapModuleQuickFixFiles: Array\<string>): Promise\<void>;

Applies a quick fix patch. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INSTALL_BUNDLE

**System capability**: SystemCapability.Ability.AbilityRuntime.QuickFix

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Parameter| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | hapModuleQuickFixFiles | Array\<string> | No| Quick fix files, each of which must contain a valid file path.| 

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | Promise\<void> | Promise used to return the result.| 

**Example**
    
```js
  import quickFixManager from '@ohos.application.quickFixManager'

  let hapModuleQuickFixFiles = ["/data/storage/el2/base/entry.hqf"]
  quickFixManager.applyQuickFix(hapModuleQuickFixFiles).then(() => {
    console.info('applyQuickFix success')
  }).catch((error) => {
    console.info(`applyQuickFix err: + ${error}`)
  })
```

## quickFixManager.getApplicationQuickFixInfo

getApplicationQuickFixInfo(bundleName: string, callback: AsyncCallback\<ApplicationQuickFixInfo>): void;

Obtains the quick fix information of the application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.AbilityRuntime.QuickFix

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Parameter| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | bundleName | string | No|Bundle name of the application. | 
  | callback | AsyncCallback\<[ApplicationQuickFixInfo](#applicationquickfixinfo)> | No| Callback used to return the quick fix information.| 

**Example**
    
```js
  import quickFixManager from '@ohos.application.quickFixManager'

  let bundleName = "bundleName"
  quickFixManager.getApplicationQuickFixInfo(bundleName, (error, data) => {
    if (error) {
      console.info(`getApplicationQuickFixInfo error: + ${error}`)
    } else {
      console.info(`getApplicationQuickFixInfo success: + ${data}`)
    }
  })  
```

## quickFixManager.getApplicationQuickFixInfo

getApplicationQuickFixInfo(bundleName: string): Promise\<ApplicationQuickFixInfo>;

Obtains the quick fix information of the application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.AbilityRuntime.QuickFix

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Parameter| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | bundleName | string | No| Bundle name of the application. | 

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | Promise\<[ApplicationQuickFixInfo](#applicationquickfixinfo)> | Promise used to return the quick fix information.| 

**Example**
    
  ```js 
  import quickFixManager from '@ohos.application.quickFixManager'

  let bundleName = "bundleName"
  quickFixManager.getApplicationQuickFixInfo(bundleName).then((data) => {
    console.info(`getApplicationQuickFixInfo success: + ${data}`)
  }).catch((error) => {
    console.info(`getApplicationQuickFixInfo err: + ${error}`)
  })
```
