# 包管理子系统变更说明

## cl.bundlemanager.1 zlib.unzipFile和zlib.decompressFile解压文件接口变更

**访问级别**

公开接口

**变更原因**

解压文件时，针对格式有误的压缩包进行拦截，避免解压之后的文件不符合预期。


**变更影响**

此变更涉及应用适配。

变更前，对于格式有误的压缩包能够正常解压成功，但解压出来的内容不符合预期。

变更后，对于格式有误的压缩包会解压失败，抛出文件格式有误的错误码。

**起始 API Level**

9

**变更发生版本**

从OpenHarmony SDK 6.0.0.39版本开始。

**变更的接口/组件**

[zlib.unzipFile](../../../application-dev/reference/apis-basic-services-kit/js-apis-zlib.md#zlibunzipfiledeprecated)和[zlib.decompressFile](../../../application-dev/reference/apis-basic-services-kit/js-apis-zlib.md#zlibdecompressfile10)。


**适配指导**

调用zlib.unzipFile和zlib.decompressFile接口时，需要捕获接口异常，根据返回的错误码进行处理，检查传入的压缩包是否有误。


## cl.bundlemanager.2 接口getDeveloperIds和sharedBundleDirPaths参数类型变更

**访问级别**

系统接口

**变更原因**

接口[getDeveloperIds](../../../application-dev/reference/apis-ability-kit/js-apis-bundleManager-sys.md#bundlemanagergetdeveloperids12)的返回值类型和[sharedBundleDirPaths](../../../application-dev/reference/apis-ability-kit/js-apis-installer-sys.md#installparam)参数类型实际为Array\<string>类型，但接口声明为Array\<String>，与实际不符需要修改。


**变更影响**

此变更涉及应用适配。

变更前，接口[getDeveloperIds](../../../application-dev/reference/apis-ability-kit/js-apis-bundleManager-sys.md#bundlemanagergetdeveloperids12)的返回值类型和[sharedBundleDirPaths](../../../application-dev/reference/apis-ability-kit/js-apis-installer-sys.md#installparam)参数类型为Array\<String>类型，应用以Array\<String>类型调用，编译可以通过，实际运行时会抛出异常。

变更后，接口[getDeveloperIds](../../../application-dev/reference/apis-ability-kit/js-apis-bundleManager-sys.md#bundlemanagergetdeveloperids12)的返回值类型和[sharedBundleDirPaths](../../../application-dev/reference/apis-ability-kit/js-apis-installer-sys.md#installparam)参数类型为Array\<string>类型，应用只能以Array\<string>类型调用，编译和运行时均能够正常执行。

**起始 API Level**

10

**变更发生版本**

从OpenHarmony SDK 6.0.0.39版本开始。

**变更的接口/组件**

| 接口名称 | 变更前 | 变更后|
| -------- | -------- | ---|
| [getDeveloperIds](../../../application-dev/reference/apis-ability-kit/js-apis-bundleManager-sys.md#bundlemanagergetdeveloperids12) | function getDeveloperIds(appDistributionType?: number): Array\<String> | function getDeveloperIds(appDistributionType?: number): Array\<string> |
| [InstallParam.sharedBundleDirPaths](../../../application-dev/reference/apis-ability-kit/js-apis-installer-sys.md#installparam) | sharedBundleDirPaths?: Array\<String> | sharedBundleDirPaths?: Array\<string> |


**适配指导**

1. 应用如果将[getDeveloperIds](../../../application-dev/reference/apis-ability-kit/js-apis-bundleManager-sys.md#bundlemanagergetdeveloperids12)函数返回值作为Array\<String>对象来使用，需要修改为Array\<string>方式使用。
2. 应用如果将[InstallParam.sharedBundleDirPaths](../../../application-dev/reference/apis-ability-kit/js-apis-installer-sys.md#installparam)参数作为Array\<String>对象来使用，需要修改为Array\<string>方式使用。


## cl.bundlemanager.3 使能动态图标enableDynamicIcon接口变更

**访问级别**

系统接口

**变更原因**

为了保证自定义主题应用图标优先级高于动态图标，变更后，如果应用存在自定义主题图标，调用使能动态图标接口会失败，桌面上的应用图标不会切换为动态图标。


**变更影响**

此变更涉及应用适配。

变更前，存在自定义主题应用图标资源时，应用调用enableDynamicIcon接口能够成功。

变更后，存在自定义主题应用图标资源时，应用调用enableDynamicIcon接口会失败返回错误码17700307。


**起始 API Level**

12

**变更发生版本**

从OpenHarmony SDK 6.0.0.39版本开始。

**变更的接口/组件**

[enableDynamicIcon](../../../application-dev/reference/apis-ability-kit/js-apis-bundleManager-sys.md#bundlemanagerenabledynamicicon12)


**适配指导**

应用需要捕获新增的错误码17700307并进行处理。


## cl.bundlemanager.4 Ability Kit相关公共事件行为变更，增加管控

**访问级别**

公开接口

**变更原因**

Ability Kit部分公共事件中包含应用信息，存在信息泄露的安全风险，需要增加管控。

**变更影响**

此变更涉及应用适配。

对于公共事件[COMMON_EVENT_PACKAGE_ADDED](../../../application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_package_added)、[COMMON_EVENT_PACKAGE_REMOVED](../../../application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_package_removed)、[COMMON_EVENT_PACKAGE_CHANGED](../../../application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_package_changed)、[COMMON_EVENT_PACKAGE_RESTARTED](../../../application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_package_restarted)、[COMMON_EVENT_PACKAGE_DATA_CLEARED](../../../application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_package_data_cleared)、[COMMON_EVENT_PACKAGE_CACHE_CLEARED](../../../application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_package_cache_cleared)、[COMMON_EVENT_QUICK_FIX_APPLY_RESULT](../../../application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_quick_fix_apply_result)的订阅方增加了管控。

变更前，系统应用和三方应用都可以监听到相关事件。

变更后，系统应用可以监听自身应用和其他应用的相关事件，而三方应用只能监听到自身应用的相关事件。

**起始 API Level**

9

**变更发生版本**

从OpenHarmony SDK 6.0.0.39版本开始。

**变更的接口/组件**

变更的公共事件列表：
| 事件名称 | 描述 |
| -------- | -------- |
| [COMMON_EVENT_PACKAGE_ADDED](../../../application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_package_added) | 应用安装完成的事件。 |
| [COMMON_EVENT_PACKAGE_REMOVED](../../../application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_package_removed) | 应用卸载完成的事件。 |
| [COMMON_EVENT_PACKAGE_CHANGED](../../../application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_package_changed) | 应用更新完成的事件。 |
| [COMMON_EVENT_PACKAGE_RESTARTED](../../../application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_package_restarted) | 应用重新启动的事件。 |
| [COMMON_EVENT_PACKAGE_DATA_CLEARED](../../../application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_package_data_cleared) | 应用数据清理完成的事件。 |
| [COMMON_EVENT_PACKAGE_CACHE_CLEARED](../../../application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_package_cache_cleared) | 应用缓存数据清理完成的事件。 |
| [COMMON_EVENT_QUICK_FIX_APPLY_RESULT](../../../application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_quick_fix_apply_result) | 应用使能快速修复包完成的事件。 |


**适配指导**

如果使用上述公共事件判断应用是否安装，请改用[canOpenLink](../../../application-dev/reference/apis-ability-kit/js-apis-bundleManager.md#bundlemanagercanopenlink12)接口来查询应用是否存在。
