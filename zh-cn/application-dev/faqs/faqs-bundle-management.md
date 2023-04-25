# 包管理开发常见问题

## 如何判断某个应用是否为系统应用

适用于OpenHarmony 3.2 Beta5  API 9

**解决措施**

使用bundleManager模块的getApplicationInfo接口（仅系统应用可以使用）获取待检验应用的ApplicaitonInfo，根据ApplicaitonInfo中systemApp字段判断，若为true，则是系统应用，否则为非系统应用。

**参考链接**

[bundleManager模块](../reference/apis/js-apis-bundleManager.md)

## 如何获取应用配置的versionCode和versionName

适用于：Openharmony 3.2 Beta5 API 9

**解决措施**

首先通过@ohos.bundle.bundleManager模块bundleManager.getBundleInfoForSelf\(\)接口获取包信息BundleInfo，然后分别通过BundleInfo.versionCode、BundleInfo.versionName获取所需信息。

**代码示例**

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

**参考链接**

[getBundleInfoForSelf](../reference/apis/js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)

## 如何获取应用自身的bundleName

适用于：Openharmony 3.2 Beta5 API9

**解决措施**

可以通过UIAbilityContext.abilityInfo.bundleName获取。

**代码示例**

```
import common from '@ohos.app.ability.common';
const context = getContext(this) as common.UIAbilityContext
console.log(`bundleName: ${context.abilityInfo.bundleName}`)
```

**参考链接**

[UIAbilityContext](../reference/apis/js-apis-inner-application-uiAbilityContext.md#uiabilitycontext)、[AbilityInfo](../reference/apis/js-apis-bundleManager-abilityInfo.md#abilityinfo)

## 如何获取App版本号，版本名，屏幕分辨率等信息

适用于：OpenHarmony 3.2 Beta5 

**解决措施**

1.  通过@ohos.bundle.bundleManager模块中的bundleManager查询bundleInfo。

    在bundleInfo中包含App版本号、版本名信息。

    ```
    import bundleManager from '@ohos.bundle.bundleManager';
    ...
    bundleManager.getBundleInfoForSelf(bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION).then((bundleInfo)=>{
      let versionName = bundleInfo.versionName;//应用版本名
      let versionNo = bundleInfo.versionCode;//应用版本号
    }).catch((error)=>{
      console.error("get bundleInfo failed,error is "+error)
    })
    ```

2.  在模块@ohos.app.ability.Configuration中获取screenDensity，其中包含屏幕分辨率信息。

    ```
    import common from '@ohos.app.ability.common';
    ...
    let context = getContext(this) as common.UIAbilityContext;
    let screenDensity = context.config.screenDensity;
    ```


## 如何获取应用自身的源文件路径

适用于：OpenHarmony 3.2 Beta5 API 9

**解决措施**

-   方式一：使用应用上下文context获取。

    ```
    this.uiAbilityContext.abilityInfo.applicationInfo.codePath
    ```

-   方式二：使用@ohos.bundle.bundleManager获取。

    1.  导入@ohos.bundle.bundleManager模块，使用bundleManager.getBundleInfoForSelf\(\)获取bundleInfo信息。
    2.  使用bundleInfo.appInfo.codePath获取应用源文件路径。

    ```
    import bundleManager from '@ohos.bundle.bundleManager';
    bundleManager.getBundleInfoForSelf(bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION).then((bundleInfo)=>{
      this.sourcePath = bundleInfo.appInfo.codePath;
    })
    ```


## 能否在本应用中获取到其他应用的HAP包信息

适用于：OpenHarmony 3.2 Beta API 9

根据OpenHarmony的安全设计规范，SDK不提供接口能力给三方应用查询其他应用的包信息（包括但不限于应用名称、版本号等）。
