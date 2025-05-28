# ApplicationInfo

应用程序信息，可以通过[bundleManager.getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)获取自身的应用程序信息，其中参数[bundleFlags](js-apis-bundleManager.md#bundleflag)至少包含GET_BUNDLE_INFO_WITH_APPLICATION。

> **说明：**
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## ApplicationInfo

**系统能力**: SystemCapability.BundleManager.BundleFramework.Core

| 名称                       | 类型                                                         | 只读 | 可选 | 说明                                                         |
| -------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| name                       | string                                                       | 是   | 否   | 应用程序的名称。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                 |
| description                | string                                                       | 是   | 否   | 标识应用的描述信息，使用示例："description": $string: mainability_description"。关于description的详细信息可参见descriptionResource字段说明。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| descriptionId              | number                                                       | 是   | 否   | 标识应用的描述信息的资源id。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| enabled                    | boolean                                                      | 是   | 否   | 判断应用程序是否可以使用，取值为true表示可以使用，取值为false表示不可使用。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| label                      | string                                                       | 是   | 否   | 标识应用的名称，使用示例："label": "$string: mainability_description"。关于label的详细信息可参见labelResource字段说明。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| labelId                    | number                                                       | 是   | 否   | 标识应用名称的资源id。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| icon                       | string                                                       | 是   | 否   | 应用程序的图标，使用示例："icon": "$media:icon"。关于icon的详细信息可参见iconResource字段说明。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| iconId                     | number                                                       | 是   | 否   | 应用程序图标的资源id。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| process                    | string                                                       | 是   | 否   | 应用程序的进程名称。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| permissions                | Array\<string>                                               | 是   | 否   | 访问应用程序所需的权限，通过调用[getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)接口，bundleFlags参数传入GET_BUNDLE_INFO_WITH_APPLICATION和GET_BUNDLE_INFO_WITH_REQUESTED_PERMISSION获取。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| codePath                   | string                                                       | 是   | 否   | 应用程序的安装目录。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| metadata<sup>(deprecated)<sup>  | Map\<string, Array\<[Metadata](js-apis-bundleManager-metadata.md)>> | 是   | 否   | 应用程序的元信息，通过调用[getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)接口，bundleFlags参数传入GET_BUNDLE_INFO_WITH_APPLICATION和GET_BUNDLE_INFO_WITH_METADATA获取。<br/>**说明：** 从API version 10开始不再维护，建议使用metadataArray替代。 |
| metadataArray<sup>10+</sup>              | Array\<[ModuleMetadata](#modulemetadata10)> | 是   | 否   | 应用程序的元信息，通过调用[getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)接口，bundleFlags参数传入GET_BUNDLE_INFO_WITH_APPLICATION和GET_BUNDLE_INFO_WITH_METADATA获取。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| removable                  | boolean                                                      | 是   | 否   | 应用程序是否可以被移除，取值为true表示可以被移除，取值为false表示不可以被移除。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| accessTokenId             | number                                                       | 是   | 否   | 应用程序的accessTokenId，应用的身份标识，在[程序访问控制校验接口](js-apis-abilityAccessCtrl.md#checkaccesstoken9)中使用。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| uid                       | number                                                       | 是   | 否   | 应用程序的UID。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| iconResource              | [Resource](../apis-localization-kit/js-apis-resource-manager.md#resource9) | 是 | 否 | 应用程序的图标资源信息，包含了该资源的信息的bundleName、moduleName 和 id，可以调用全球化的接口[getMediaContent](../apis-localization-kit/js-apis-resource-manager.md#getmediacontent9)来获取详细的资源数据信息。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| labelResource             | [Resource](../apis-localization-kit/js-apis-resource-manager.md#resource9) | 是 | 否 | 应用程序的标签资源信息，包含了该资源的信息的bundleName、moduleName 和 id，可以调用全球化的接口[getMediaContent](../apis-localization-kit/js-apis-resource-manager.md#getmediacontent9)来获取详细的资源数据信息。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| descriptionResource       | [Resource](../apis-localization-kit/js-apis-resource-manager.md#resource9) | 是 | 否 | 应用程序的描述资源信息，包含了该资源的信息的bundleName、moduleName 和 id，可以调用全球化的接口[getMediaContent](../apis-localization-kit/js-apis-resource-manager.md#getmediacontent9)来获取详细的资源数据信息。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| appDistributionType       | string                                                       | 是   | 否   | 应用程序签名证书的分发类型，分为： <li>app_gallery：应用市场分发的应用。 <li> enterprise：企业应用，可以安装到个人设备上。<li> enterprise_mdm：企业MDM应用，只能安装在企业设备上。需要设备管理特权，比如远程锁定，安装普通企业应用等。 <li>enterprise_normal：普通企业应用，只能通过企业MDM应用安装在企业设备上。无需设备管理特权。<li>os_integration：系统预置应用。<li>crowdtesting：众包测试应用。<li>internaltesting：应用市场内测的应用。<li>none：其他。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| appProvisionType          | string                                                       | 是   | 否   | 应用程序签名证书文件的类型，分为debug和release两种类型。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| systemApp          | boolean                                                       | 是   | 否   | 标识应用是否为系统应用，取值为true表示系统应用，取值为false表示非系统应用。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| bundleType                |[bundleManager.BundleType](js-apis-bundleManager.md#bundletype)             | 是   | 否   | 标识包的类型，取值为APP（应用）或者ATOMIC_SERVICE（原子化服务）。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| debug<sup>10+</sup>       | boolean                                | 是   | 否   | 标识应用是否处于调试模式，取值为true表示应用处于调试模式，取值为false表示应用处于非调试模式。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| dataUnclearable<sup>11+</sup>       | boolean                      | 是   | 否   | 标识应用数据是否可被删除。true表示不可删除，false表示可以删除。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| nativeLibraryPath<sup>12+</sup> | string                                                                     | 是   | 否   | 应用程序的本地库文件路径。                                                  |
| multiAppMode<sup>12+</sup> | [MultiAppMode](#multiappmode12) | 是   | 否   | 应用多开模式。|
| appIndex<sup>12+</sup>    | number    | 是   | 否   | 应用包的分身索引标识，仅在分身应用中生效。 |
| installSource<sup>12+</sup>    | string    | 是   | 否   | 应用程序的安装来源，支持的取值如下：<br/> - pre-installed表示应用为第一次开机时安装的预置应用。<br/> - ota表示应用为系统升级时新增的预置应用。<br/> - recovery表示卸载后再恢复的预置应用。<br/> - bundleName表示应用由此包名对应的应用安装。<br/> - unknown表示应用安装来源未知。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| releaseType<sup>12+</sup>    | string    | 是   | 否   | 标识应用打包时使用的SDK的发布类型。当前SDK的发布类型可能为Canary、Beta、Release，其中Canary和Beta可能通过序号进一步细分，例如Canary1、Canary2、Beta1、Beta2等。开发者可通过对比应用打包依赖的SDK发布类型和OS的发布类型（[deviceInfo.distributionOSReleaseType](../apis-basic-services-kit/js-apis-device-info.md)）来判断兼容性。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| cloudFileSyncEnabled<sup>12+</sup>    | boolean    | 是   | 否   | 标识当前应用是否启用端云文件同步能力。true表示当前应用启用端云文件同步能力，false表示当前应用不启用端云文件同步能力。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |

## MultiAppMode<sup>12+</sup>
表示[应用多开](../../quick-start/multiInstance.md)模式。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 名称      | 类型           | 只读 | 可选 | 说明                        |
| --------- | -------------- | ---- | ---- | --------------------------- |
| multiAppModeType | [bundleManager.MultiAppModeType](js-apis-bundleManager.md#multiappmodetype12) | 是 | 否 |  应用多开模式的类型。  |
| maxCount | number  | 是 | 否 |  应用多开的最大个数。  |

## ModuleMetadata<sup>10+</sup>

描述模块的元数据信息。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

| 名称      | 类型           | 只读 | 可选 | 说明                        |
| --------- | -------------- | ---- | ---- | --------------------------- |
| moduleName| string         | 是   | 否   | 模块名。   |
| metadata  | Array\<[Metadata](js-apis-bundleManager-metadata.md)>      | 是   | 否   | 该模块下的元数据信息列表。 |