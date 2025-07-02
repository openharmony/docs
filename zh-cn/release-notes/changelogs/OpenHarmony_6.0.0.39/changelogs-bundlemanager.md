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
