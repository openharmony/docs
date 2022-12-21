# AbilityInfo

> **说明：**
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

Ability信息，系统应用可以通过[getBundleInfo](js-apis-bundleManager.md#bundlemanagergetbundleinfo)获取自身或其他应用的Ability信息，三方应用可以通过[getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)获取自身的Ability信息，其中入参[BundleFlag](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-bundleManager.md#bundleflag)需要使用GET_BUNDLE_INFO_WITH_ABILITY。

## AbilityInfo

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework.Core。

| 名称                  | 类型                                                     | 可读 | 可写 | 说明                                      |
| --------------------- | -------------------------------------------------------- | ---- | ---- | ----------------------------------------- |
| bundleName            | string                                                   | 是   | 否   | 应用包名                                  |
| moduleName            | string                                                   | 是   | 否   | Ability所属的HAP包的名称                  |
| name                  | string                                                   | 是   | 否   | Ability名称                               |
| label                 | string                                                   | 是   | 否   | Ability对用户显示的名称                   |
| labelId               | number                                                   | 是   | 否   | Ability的标签资源id                      |
| description           | string                                                   | 是   | 否   | Ability的描述                             |
| descriptionId         | number                                                   | 是   | 否   | Ability的描述资源id                       |
| icon                  | string                                                   | 是   | 否   | Ability的图标资源文件索引                 |
| iconId                | number                                                   | 是   | 否   | Ability的图标资源id                       |
| process               | string                                                   | 是   | 否   | Ability的进程，如果不设置，默认为包的名称 |
| isVisible             | boolean                                                  | 是   | 否   | 判断Ability是否可以被其他应用调用         |
| type                  | [AbilityType](js-apis-bundleManager.md#abilitytype)      | 是   | 否   | Ability类型<br />此属性仅可在FA模型下使用            |
| orientation           | [DisplayOrientation](js-apis-bundleManager.md#displayorientation)  | 是   | 否   | Ability的显示模式                         |
| launchType            | [LaunchType](js-apis-bundleManager.md#launchtype)        | 是   | 否   | Ability的启动模式                         |
| permissions           | Array\<string>                                           | 是   | 否   | 被其他应用Ability调用时需要申请的权限集合，通过传入GET_ABILITY_INFO_WITH_PERMISSION获取 |
| readPermission        | string                                                   | 是   | 否   | 读取Ability数据所需的权限<br />此属性仅可在FA模型下使用 |
| writePermission       | string                                                   | 是   | 否   | 向Ability写数据所需的权限<br />此属性仅可在FA模型下使用 |
| uri                   | string                                                   | 是   | 否   | 获取Ability的统一资源标识符（URI）<br />此属性仅可在FA模型下使用 |
| deviceTypes           | Array\<string>                                           | 是   | 否   | Ability支持的设备类型                     |
| applicationInfo       | [ApplicationInfo](js-apis-bundleManager-applicationInfo.md)     | 是   | 否   | 应用程序的配置信息，通过传入GET_ABILITY_INFO_WITH_APPLICATION获取 |
| metadata              | Array\<[Metadata](js-apis-bundleManager-metadata.md)>           | 是   | 否   | ability的元信息，通过传入GET_ABILITY_INFO_WITH_METADATA获取 |
| enabled               | boolean                                                  | 是   | 否   | ability是否可用                           |
| supportWindowModes    | Array\<[SupportWindowMode](js-apis-bundleManager.md#supportwindowmode)> | 是   | 否   | ability支持的窗口模式                      |
| windowSize|[WindowSize](#windowsize)                                            |    是   | 否   | 表示窗口尺寸|

## WindowSize

描述窗口尺寸。

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework.Core。

| 名称               | 类型    | 可读 | 可写 | 说明                               |
| -------------------| ------- | ---- | ---- | ---------------------------------- |
| maxWindowRatio     | number  | 是   | 否   | 表示自由窗口状态下窗口的最大宽高比；取值范围0-1 |
| minWindowRatio     | number  | 是   | 否   | 表示自由窗口状态下窗口的最小宽高比；取值范围0-1 |
| maxWindowWidth     | number  | 是   | 否   | 表示自由窗口状态下窗口的最大宽度，宽度单位为vp |
| minWindowWidth     | number  | 是   | 否   | 表示自由窗口状态下窗口的最小宽度，宽度单位为vp |
| maxWindowHeight    | number  | 是   | 否   | 表示自由窗口状态下窗口的最大高度，宽度单位为vp |
| minWindowHeight    | number  | 是   | 否   | 表示自由窗口状态下窗口的最小高度，宽度单位为vp |