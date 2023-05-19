# Bundle Management Development

## How do I determine whether an application is a system application?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Solution**

Use **bundleManager.getApplicationInfo** (available only for system applications) to obtain application information, and check the value of **systemApp** in the information. The application is a system application if the value is **true**.

**Reference**

[bundleManager](../reference/apis/js-apis-bundleManager.md)

## How do I obtain the version code and version name of an application?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Solution**

Use **bundleManager.getBundleInfoForSelf\(\)** to obtain the bundle information, which contains the version code (specified by **BundleInfo.versionCode**) and version name (specified by **BundleInfo.versionName**) .

**Example**

```
import bundleManager from '@ohos.bundle.bundleManager';
import hilog from '@ohos.hilog';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;
try {
  bundleManager.getBundleInfoForSelf(bundleFlags).then((data) => {
    const versionCode = data.versionCode;
    const versionName = data.versionName;
    hilog.info(0x0000, 'testTag', `successfully. versionCode: ${versionCode}, versionName: ${versionName}`);    
  }).catch(err => {
    hilog.error(0x0000, 'testTag', 'failed. Cause: %{public}s', err.message);
  });
} catch (err) {
  hilog.error(0x0000, 'testTag', 'failed: %{public}s', err.message);
}
```

**Reference**

[getBundleInfoForSelf](../reference/apis/js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)

## How do I obtain the bundle name of the current application?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9)

**Solution**

Obtain the bundle name from **UIAbilityContext.abilityInfo.bundleName**.

**Example**

```
import common from '@ohos.app.ability.common';
const context = getContext(this) as common.UIAbilityContext
console.log(`bundleName: ${context.abilityInfo.bundleName}`)
```

**Reference**

[UIAbilityContext](../reference/apis/js-apis-inner-application-uiAbilityContext.md#uiabilitycontext) and [AbilityInfo](../reference/apis/js-apis-bundleManager-abilityInfo.md#abilityinfo)

## How do I obtain the application version number, version name, and screen resolution?

Applicable to: OpenHarmony 3.2 Beta5

**Solution**

1.  Obtain the bundle information from the **@ohos.bundle.bundleManager** module.

    The bundle information contains the application version number and version name.

    ```
    import bundleManager from '@ohos.bundle.bundleManager';
    ...
    bundleManager.getBundleInfoForSelf(bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION).then((bundleInfo)=>{
      let versionName = bundleInfo.versionName; // Application version name.
      let versionNo = bundleInfo.versionCode; // Application version number.
    }).catch((error)=>{
      console.error("get bundleInfo failed,error is "+error)
    })
    ```

2.  Obtain **screenDensity** from the **@ohos.app.ability.Configuration** module. **screenDensity** contains the screen resolution information.

    ```
    import common from '@ohos.app.ability.common';
    ...
    let context = getContext(this) as common.UIAbilityContext;
    let screenDensity = context.config.screenDensity;
    ```


## How do I obtain the source file path of the current application?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Solution**

-   Method 1: Use the application context to obtain the source file path.

    ```
    this.uiAbilityContext.abilityInfo.applicationInfo.codePath
    ```

-   Method 2: Use **@ohos.bundle.bundleManager** to obtain the source file path.

    1.  Import the **@ohos.bundle.bundleManager** module and use **bundleManager.getBundleInfoForSelf\(\)** to obtain the bundle information.
    2.  Obtain the source file path from **bundleInfo.appInfo.codePath**.

    ```
    import bundleManager from '@ohos.bundle.bundleManager';
    bundleManager.getBundleInfoForSelf(bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION).then((bundleInfo)=>{
      this.sourcePath = bundleInfo.appInfo.codePath;
    })
    ```


## Can I obtain the HAP information of other applications from the current application?

Applicable to: OpenHarmony 3.2 Beta (API version 9)

According to the OpenHarmony security design specifications, the SDK does not provide APIs for third-party applications to obtain bundle information (including but not limited to the application name and version number) of other applications.
