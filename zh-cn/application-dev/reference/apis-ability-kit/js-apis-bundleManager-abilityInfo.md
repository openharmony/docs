# AbilityInfo

Ability信息，三方应用可以通过[bundleManager.getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)获取Ability信息,其中入参[bundleFlags](js-apis-bundleManager.md#bundleflag)至少包含GET_BUNDLE_INFO_WITH_HAP_MODULE和GET_BUNDLE_INFO_WITH_ABILITY。

> **说明：**
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## AbilityInfo

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework.Core。

| 名称                  | 类型                                                     | 只读 | 可选 | 说明                                      |
| --------------------- | -------------------------------------------------------- | ---- | ---- | ------------------------------------------ |
| bundleName            | string                                                   | 是   | 否   | 应用Bundle名称。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| moduleName            | string                                                   | 是   | 否   | Ability所属的HAP的名称。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| name                  | string                                                   | 是   | 否   | Ability名称。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| label                 | string                                                   | 是   | 否   | Ability对用户显示的名称的资源描述符，如："label": "$string: mainability_description"。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| labelId               | number                                                   | 是   | 否   | Ability的标签资源id。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| description           | string                                                   | 是   | 否   | Ability的描述。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| descriptionId         | number                                                   | 是   | 否   | Ability的描述资源id。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| icon                  | string                                                   | 是   | 否   | Ability的图标资源描述符，如"icon": "$media:icon"。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| iconId                | number                                                   | 是   | 否   | Ability的图标资源id。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| process               | string                                                   | 是   | 否   | Ability的进程，如果不设置，默认为包的名称。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| exported             | boolean                                                  | 是   | 否   | 判断Ability是否可以被其他应用调用。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| type                  | [bundleManager.AbilityType](js-apis-bundleManager.md#abilitytype)      | 是   | 否   | Ability类型<br />**模型约束：** 此接口仅可在FA模型下使用。 |
| orientation           | [bundleManager.DisplayOrientation](js-apis-bundleManager.md#displayorientation)  | 是   | 否   | Ability的显示模式。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| launchType            | [bundleManager.LaunchType](js-apis-bundleManager.md#launchtype)        | 是   | 否   | Ability的启动模式。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| permissions           | Array\<string>                                           | 是   | 否   | 被其他应用Ability调用时需要申请的权限集合。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| readPermission        | string                                                   | 是   | 否   | 读取Ability数据所需的权限<br />**模型约束：** 此接口仅可在FA模型下使用。 |
| writePermission       | string                                                   | 是   | 否   | 向Ability写数据所需的权限<br />**模型约束：** 此接口仅可在FA模型下使用。 |
| uri                   | string                                                   | 是   | 否   | 获取Ability的统一资源标识符（URI）<br />**模型约束：** 此接口仅可在FA模型下使用。 |
| deviceTypes           | Array\<string>                                           | 是   | 否   | Ability支持的设备类型。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| applicationInfo       | [ApplicationInfo](js-apis-bundleManager-applicationInfo.md)     | 是   | 否   | 应用程序的配置信息，通过调用[getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)接口，bundleFlags参数传入GET_BUNDLE_INFO_WITH_HAP_MODULE、GET_BUNDLE_INFO_WITH_ABILITY和GET_BUNDLE_INFO_WITH_APPLICATION获取。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| metadata              | Array\<[Metadata](js-apis-bundleManager-metadata.md)>           | 是   | 否   | Ability的元信息，通过调用[getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)接口，bundleFlags参数传入GET_BUNDLE_INFO_WITH_HAP_MODULE、GET_BUNDLE_INFO_WITH_ABILITY和GET_BUNDLE_INFO_WITH_METADATA获取。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| enabled               | boolean                                                  | 是   | 否   | Ability是否可用。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| supportWindowModes    | Array\<[bundleManager.SupportWindowMode](js-apis-bundleManager.md#supportwindowmode)> | 是   | 否   | Ability支持的窗口模式。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| windowSize|[WindowSize](#windowsize)                                            |    是   | 否   | Ability窗口尺寸。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| excludeFromDock<sup>12+</sup>             | boolean                                                  | 是   | 否   | 判断Ability是否可以在dock区域隐藏图标。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| skills<sup>12+</sup>             | Array\<[Skill](js-apis-bundleManager-skill.md)>                                                 | 是   | 否   | Ability的Skills信息。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。   |
| appIndex<sup>12+</sup>    | number    | 是   | 否   | 应用包的分身索引标识，仅在分身应用中生效。 |
| orientationId<sup>13+</sup>    | number      | 是   | 否   | Ability的显示模式资源id。当orientationId不为0时表示当前显示模式为自定义配置，需要使用orientationId去资源管理获取对应的资源。 |

## WindowSize

描述窗口尺寸。

 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework.Core。

| 名称               | 类型    | 只读 | 可选 | 说明                               |
| -------------------| ------- | ---- | ---- | ---------------------------------- |
| maxWindowRatio     | number  | 是   | 否   | 表示自由窗口状态下窗口的最大宽高比；取值范围0-1。 |
| minWindowRatio     | number  | 是   | 否   | 表示自由窗口状态下窗口的最小宽高比；取值范围0-1。 |
| maxWindowWidth     | number  | 是   | 否   | 表示自由窗口状态下窗口的最大宽度，宽度单位为vp。 |
| minWindowWidth     | number  | 是   | 否   | 表示自由窗口状态下窗口的最小宽度，宽度单位为vp。 |
| maxWindowHeight    | number  | 是   | 否   | 表示自由窗口状态下窗口的最大高度，宽度单位为vp。 |
| minWindowHeight    | number  | 是   | 否   | 表示自由窗口状态下窗口的最小高度，宽度单位为vp。 |