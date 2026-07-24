# ExtensionAbilityInfo
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @memghaiyang-->
<!--Adviser: @HelloCrease-->

ExtensionAbility信息，可以通过[bundleManager.getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)获取自身的ExtensionAbility信息，其中参数[bundleFlags](js-apis-bundleManager.md#bundleflag)至少包含GET_BUNDLE_INFO_WITH_HAP_MODULE和GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY。

> **说明：**
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { bundleManager } from '@kit.AbilityKit';
```

## ExtensionAbilityInfo

**系统能力**: SystemCapability.BundleManager.BundleFramework.Core

<!--Table: 20%; 20%; 8%; 8%; 44%-->
| 名称                 | 类型                                                         | 只读 | 可选 | 说明                                                 |
| -------------------- | ------------------------------------------------------------ | ---- | ---- | ---------------------------------------------------- |
| bundleName           | string                                                       | 是   | 否   | 应用Bundle名称。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| moduleName           | string                                                       | 是   | 否   | ExtensionAbility所属的HAP的名称。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| name                 | string                                                       | 是   | 否   | ExtensionAbility名称。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| labelId              | number                                                       | 是   | 否   | ExtensionAbility的标签资源ID。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| descriptionId        | number                                                       | 是   | 否   | ExtensionAbility的描述资源ID。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| iconId               | number                                                       | 是   | 否   | ExtensionAbility的图标资源ID。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| exported            | boolean                                                      | 是   | 否   | 判断ExtensionAbility是否可以被其他应用调用，取值为true表示ExtensionAbility可以被其他应用调用，取值为false表示ExtensionAbility不可以被其他应用调用。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| extensionAbilityType | [bundleManager.ExtensionAbilityType](js-apis-bundleManager.md#extensionabilitytype) | 是   | 否   | ExtensionAbility类型。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| permissions          | Array\<string>                                               | 是   | 否   | 被其他应用ExtensionAbility调用时需要申请的权限集合。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| applicationInfo      | [ApplicationInfo](js-apis-bundleManager-applicationInfo.md)  | 是   | 否   | 应用程序的配置信息<!--Del-->，可以通过调用[queryExtensionAbilityInfo](js-apis-bundleManager-sys.md#bundlemanagerqueryextensionabilityinfo)接口，extensionAbilityFlags参数传入GET_EXTENSION_ABILITY_INFO_WITH_APPLICATION获取<!--DelEnd-->。<br/>[getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)或者[getBundleInfo](js-apis-bundleManager.md#bundlemanagergetbundleinfo14)接口获取ExtensionAbilityInfo信息时不会返回该字段内容，可以通过获取[bundleInfo](js-apis-bundleManager-bundleInfo.md#bundleinfo-1).appInfo对象来获取相关信息。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| metadata             | Array\<[Metadata](js-apis-bundleManager-metadata.md)>        | 是   | 否   | ExtensionAbility的元信息。通过调用[getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)接口，bundleFlags参数传入GET_BUNDLE_INFO_WITH_HAP_MODULE、GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY和GET_BUNDLE_INFO_WITH_METADATA获取。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。  |
| enabled              | boolean                                                      | 是   | 否   | ExtensionAbility是否可用，取值为true表示ExtensionAbility可用，取值为false表示ExtensionAbility不可用。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| readPermission       | string                                                       | 是   | 否   | 读取ExtensionAbility数据所需的权限。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| writePermission      | string                                                       | 是   | 否   | 向ExtensionAbility写数据所需的权限。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| extensionAbilityTypeName<sup>11+</sup>      | string                                 | 是   | 否   | ExtensionAbility的类型名称，取值请参考[extensionabilities标签下的type字段](../../quick-start/module-configuration-file.md#extensionabilities标签)。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| skills<sup>12+</sup>             | Array\<[Skill](js-apis-bundleManager-skill.md)>                                                 | 是   | 否   | ExtensionAbility的Skills信息。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。        |
| appIndex<sup>12+</sup>    | number    | 是   | 否   | 应用包的分身索引标识，仅在分身应用中生效。 |