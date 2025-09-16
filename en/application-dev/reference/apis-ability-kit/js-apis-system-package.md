# @system.package (Bundle Management)
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->


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

hasInstalled(options: CheckPackageHasInstalledOptions): void

Checks whether an application exists, or whether a native application has been installed.

**System capability**: SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
|options | [CheckPackageHasInstalledOptions](#checkpackagehasinstalledoptions) | Yes| Options.|

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

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
|result | boolean | Yes| Check result for whether the bundle has been installed. **true** if installed, **false** otherwise.|

## CheckPackageHasInstalledOptions

> This API is deprecated since API version 9.

Defines the options used for checking whether a bundle has been installed.

**System capability**: SystemCapability.BundleManager.BundleFramework

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| bundleName | string | Yes| Bundle name.|
| success | Function | No| Called when API call is successful.|
| fail | Function | No| Called when API call has failed.|
| complete | Function | No| Called when API call is complete.|
