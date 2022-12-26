# ExtensionAbilityInfo

> **说明：**
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

ExtensionAbility信息，系统应用可以通过[bundleManager.getBundleInfo](js-apis-bundleManager.md#bundlemanagergetbundleinfo)获取自身或其他应用的ExtensionAbility信息，三方应用可以通过[getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)获取自身的ExtensionAbility信息，其中入参[bundleFlags](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-bundleManager.md#bundleflag)需要使用 GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY。

## ExtensionAbilityInfo

**系统能力**: SystemCapability.BundleManager.BundleFramework.Core

| 名称                 | 类型                                                         | 可读 | 可写 | 说明                                                 |
| -------------------- | ------------------------------------------------------------ | ---- | ---- | ---------------------------------------------------- |
| bundleName           | string                                                       | 是   | 否   | 应用Bundle名称。                                     |
| moduleName           | string                                                       | 是   | 否   | ExtensionAbility所属的HAP的名称。                    |
| name                 | string                                                       | 是   | 否   | ExtensionAbility名称。                               |
| labelId              | number                                                       | 是   | 否   | ExtensionAbility的标签资源ID。                       |
| descriptionId        | number                                                       | 是   | 否   | ExtensionAbility的描述资源ID。                       |
| iconId               | number                                                       | 是   | 否   | ExtensionAbility的图标资源ID。                       |
| isVisible            | boolean                                                      | 是   | 否   | 判断ExtensionAbility是否可以被其他应用调用。         |
| extensionAbilityType | [ExtensionAbilityType](js-apis-bundleManager.md#extensionabilitytype) | 是   | 否   | ExtensionAbility类型。                               |
| permissions          | Array\<string>                                               | 是   | 否   | 被其他应用ExtensionAbility调用时需要申请的权限集合。 |
| applicationInfo      | [ApplicationInfo](js-apis-bundleManager-applicationInfo.md)  | 是   | 否   | 应用程序的配置信息。                                 |
| metadata             | Array\<[Metadata](js-apis-bundleManager-metadata.md)>        | 是   | 否   | ExtensionAbility的元信息。                           |
| enabled              | boolean                                                      | 是   | 否   | ExtensionAbility是否可用。                           |
| readPermission       | string                                                       | 是   | 否   | 读取ExtensionAbility数据所需的权限。                 |
| writePermission      | string                                                       | 是   | 否   | 向ExtensionAbility写数据所需的权限。                 |