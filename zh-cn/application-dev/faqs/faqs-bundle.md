# 应用程序包管理开发常见问题

## 如何获取应用配置的versionCode和versionName

适用于：OpenHarmony SDK 3.2.3.5版本，API9 Stage模型

通过\@ohos.bundle模块buniple.getBundleInfo()接口获取包信息bundleInfo，然后分别通过bundleInfo.versionCode、bundleInfo.versionName

参考文档：[Bundle模块](../reference/apis/js-apis-Bundle.md#bundlegetbundleinfo)

## 如何获取应用自身的bundleName

适用于：OpenHarmony SDK 3.2.3.5版本，API9 Stage模型

通过可以context.abilityInfo.bundleName获取。

参考文档：[AbilityContext](../reference/apis/js-apis-ability-context.md#%E5%B1%9E%E6%80%A7)、[AbilityInfo](../reference/apis/js-apis-bundle-AbilityInfo.md)

## 如何获取应用图标

适用于：OpenHarmony SDK 3.2.3.5版本，API9 Stage模型

通过\@ohos.bundle模块 getAbilityIcon 接口获取，需要配置权限：ohos.permission.GET_BUNDLE_INFO。

参考文档：[Bundle模块](../reference/apis/js-apis-Bundle.md#bundlegetbundleinfo)

## 如何判断某个应用是否为系统应用

使用于：OpenHarmony SDK 3.2.5.5版本，API9 Stage模型

使用bundle模块的getApplicationInfo接口获取待检验的应用的ApplicaitonInfo，根据ApplicaitonInfo中systemApp字段判断，若为true，则是系统应用，否则为非系统应用。
