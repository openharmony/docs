# @system.package (Bundle Management)


> **NOTE**
>
> - This module is deprecated since API version 9. You are advised to use [@ohos.bundle.bundleManager](js-apis-bundleManager.md) instead.
>
> - The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```
import package from '@system.package';
```


## package.hasInstalled<sup>(deprecated)</sup>
> This API is deprecated since API version 9. You are advised to use [@ohos.bundle.bundleManager](js-apis-bundleManager.md) instead.

hasInstalled(Object): void

Checks whether an application exists, or whether a native application has been installed.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
|options | [CheckPackageHasInstalledOptions](#checkpackagehasinstalledoptions) | Yes| Options.|

**Return value**

| Name| Type| Description|
| -------- | -------- | -------- |
| result | boolean | The value **true** means that the application exists or the native application has been installed, and **false** means the opposite.|

**Example**

``` ts
export default {
  hasInstalled() {
    package.hasInstalled({
      bundleName: 'com.example.bundlename',
      success: function(data) {
        console.log('package has installed: ' + data);
      },
      fail: function(data, code) {
        console.log('query package fail, code: ' + code + ', data: ' + data);
      },
    });
  },
}
```

## CheckPackageHasInstalledResponse

> This API is deprecated since API version 9.

Checks whether a bundle has been installed.

**System capability**: SystemCapability.BundleManager.BundleFramework

| Name| Type| Description|
| --- | --- | ---- |
| result | boolean | The value **true** means that the bundle has been installed, and **false** means the opposite.|

## CheckPackageHasInstalledOptions

> This API is deprecated since API version 9.

Defines the options used for checking whether a bundle has been installed.

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| bundleName | string | Yes| Bundle name.|
| success | Function | No| Called when API call is successful.|
| fail | Function | No| Called when API call has failed.|
| complete | Function | No| Called when API call is complete.|
