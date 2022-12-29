# @ohos.app.ability.quickFixManager

The **quickFixManager** module provides APIs for quick fix. With quick fix, you can fix bugs in your application by applying patches, which is more efficient than by updating the entire application.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import quickFixManager from '@ohos.app.ability.quickFixManager';
```

## HapModuleQuickFixInfo

Defines the quick fix information at the HAP file level.

**System capability**: SystemCapability.Ability.AbilityRuntime.QuickFix

**System API**: This is a system API and cannot be called by third-party applications.

| Name       | Type                | Mandatory| Description                                                        |
| ----------- | -------------------- | ---- | ------------------------------------------------------------ |
| moduleName    | string               | Yes  | Name of the HAP file.                              |
| originHapHash    | string               | Yes  | Hash value of the HAP file.                              |
| quickFixFilePath    | string               | Yes  | Installation path of the quick fix file.                              |

## ApplicationQuickFixInfo

Defines the quick fix information at the application level.

**System capability**: SystemCapability.Ability.AbilityRuntime.QuickFix

**System API**: This is a system API and cannot be called by third-party applications.

| Name       | Type                | Mandatory| Description                                                        |
| ----------- | -------------------- | ---- | ------------------------------------------------------------ |
| bundleName    | string               | Yes  | Bundle name of the application.                              |
| bundleVersionCode    | number               | Yes  | Internal version number of the application.                              |
| bundleVersionName    | string               | Yes  | Version number of the application that is shown to users.                              |
| quickFixVersionCode    | number               | Yes  | Version code of the quick fix patch package.                              |
| quickFixVersionName    | string               | Yes  | Text description of the version number of the quick fix patch package.                              |
| hapModuleQuickFixInfo    | Array\<[HapModuleQuickFixInfo](#hapmodulequickfixinfo)>      | Yes  | Quick fix information at the HAP file level.    |

## quickFixManager.applyQuickFix

applyQuickFix(hapModuleQuickFixFiles: Array\<string>, callback: AsyncCallback\<void>): void;

Applies a quick fix patch. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INSTALL_BUNDLE

**System capability**: SystemCapability.Ability.AbilityRuntime.QuickFix

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Parameter| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | hapModuleQuickFixFiles | Array\<string> | Yes| Quick fix files, each of which must contain a valid file path.| 
  | callback | AsyncCallback\<void> | Yes| Callback used to return the result.| 

**Example**
    
```ts
  import quickFixManager from '@ohos.app.ability.quickFixManager'

  try {
    let hapModuleQuickFixFiles = ["/data/storage/el2/base/entry.hqf"]
    quickFixManager.applyQuickFix(hapModuleQuickFixFiles, (error) => {
      if (error) {
          console.info( `applyQuickFix failed with error + ${error}`)
      } else {
          console.info( 'applyQuickFix success')
      }
    })
  } catch (paramError) {
    console.log("error: " + paramError.code + ", " + paramError.message);
  }
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
  | hapModuleQuickFixFiles | Array\<string> | Yes| Quick fix files, each of which must contain a valid file path.| 

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | Promise\<void> | Promise used to return the result.| 

**Example**
    
```ts
  import quickFixManager from '@ohos.app.ability.quickFixManager'

  let hapModuleQuickFixFiles = ["/data/storage/el2/base/entry.hqf"]
  try {
    quickFixManager.applyQuickFix(hapModuleQuickFixFiles).then(() => {
      console.info('applyQuickFix success')
    }).catch((error) => {
      console.info(`applyQuickFix err: + ${error}`)
    })
  } catch (paramError) {
    console.log("error: " + paramError.code + ", " + paramError.message);
  }
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
  | bundleName | string | Yes|Bundle name of the application. | 
  | callback | AsyncCallback\<[ApplicationQuickFixInfo](#applicationquickfixinfo)> | Yes| Callback used to return the quick fix information.| 

**Example**
    
```ts
  import quickFixManager from '@ohos.app.ability.quickFixManager'

  try {
    let bundleName = "bundleName"
    quickFixManager.getApplicationQuickFixInfo(bundleName, (error, data) => {
      if (error) {
        console.info(`getApplicationQuickFixInfo error: + ${error}`)
      } else {
        console.info(`getApplicationQuickFixInfo success: + ${data}`)
      }
    })
  } catch (paramError) {
    console.log("error: " + paramError.code + ", " + paramError.message);
  }  
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
  | bundleName | string | Yes| Bundle name of the application. | 

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | Promise\<[ApplicationQuickFixInfo](#applicationquickfixinfo)> | Promise used to return the quick fix information.| 

**Example**
    
  ```ts 
  import quickFixManager from '@ohos.app.ability.quickFixManager'

  try {
    let bundleName = "bundleName"
    quickFixManager.getApplicationQuickFixInfo(bundleName).then((data) => {
      console.info(`getApplicationQuickFixInfo success: + ${data}`)
    }).catch((error) => {
      console.info(`getApplicationQuickFixInfo err: + ${error}`)
    })
  } catch (paramError) {
    console.log("error: " + paramError.code + ", " + paramError.message);
  }
```
