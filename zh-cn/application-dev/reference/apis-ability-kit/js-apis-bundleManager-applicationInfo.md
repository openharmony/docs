# ApplicationInfo
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @memghaiyang-->
<!--Adviser: @HelloCrease-->

应用程序信息，可以通过[bundleManager.getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)获取自身的应用程序信息，其中参数[bundleFlags](js-apis-bundleManager.md#bundleflag)至少包含GET_BUNDLE_INFO_WITH_APPLICATION。

> **说明：**
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { bundleManager } from '@kit.AbilityKit';
```

## ApplicationInfo

**系统能力**: SystemCapability.BundleManager.BundleFramework.Core

<!--Table: 20%; 20%; 8%; 8%; 44%-->
| 名称                       | 类型                                                         | 只读 | 可选 | 说明                                                         |
| -------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| name                       | string                                                       | 是   | 否   | 应用包的bundle名称，对应[app.json5](../../quick-start/app-configuration-file.md)里面的bundleName。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                 |
| description                | string                                                       | 是   | 否   | 标识应用的描述信息，对应[app.json5](../../quick-start/app-configuration-file.md)中配置的description字段。关于description的详细信息详见本表中的descriptionResource字段说明。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| descriptionId              | number                                                       | 是   | 否   | 标识应用的描述信息的资源id，是编译构建时根据应用配置的description自动生成的资源id。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| enabled                    | boolean                                                      | 是   | 否   | 判断应用程序是否可以使用，取值为true表示可以使用，取值为false表示不可使用。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| label                      | string                                                       | 是   | 否   | 标识应用的名称，对应[app.json5](../../quick-start/app-configuration-file.md)中配置的label字段。关于label的详细信息详见本表中的labelResource字段说明。从API version 20开始，如果是通过[bundleManager.getAbilityInfo](js-apis-bundleManager.md#bundlemanagergetabilityinfo20)获取ApplicationInfo信息，该字段为应用对用户显示的名称，而不是资源描述符。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| labelId                    | number                                                       | 是   | 否   | 标识应用名称的资源id，是编译构建时根据应用配置的label自动生成的资源id。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| icon                       | string                                                       | 是   | 否   | 应用程序的图标，对应[app.json5](../../quick-start/app-configuration-file.md)中配置的icon字段。关于icon的详细信息详见本表中的iconResource字段说明。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| iconId                     | number                                                       | 是   | 否   | 应用程序图标的资源id，是编译构建时根据应用配置的icon自动生成的资源id。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| process                    | string                                                       | 是   | 否   | 应用程序的进程名称。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| permissions                | Array\<string>                                               | 是   | 否   | 访问应用程序所需的权限列表<!--Del-->，可以通过调用[getApplicationInfo](js-apis-bundleManager-sys.md#bundlemanagergetapplicationinfo)接口，appFlags参数传入GET_APPLICATION_INFO_WITH_PERMISSION获取<!--DelEnd-->。<br/>[getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)或者[getBundleInfo](js-apis-bundleManager.md#bundlemanagergetbundleinfo14)接口获取ApplicationInfo信息时不会返回该字段内容，可以通过获取[bundleInfo](js-apis-bundleManager-bundleInfo.md#bundleinfo-1).reqPermissionDetails信息获取权限列表。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| codePath                   | string                                                       | 是   | 否   | 应用程序的安装目录。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| metadata<sup>(deprecated)</sup>  | Map\<string, Array\<[Metadata](js-apis-bundleManager-metadata.md)>> | 是   | 否   | 应用程序的元信息，通过调用[getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)接口，bundleFlags参数传入GET_BUNDLE_INFO_WITH_APPLICATION和GET_BUNDLE_INFO_WITH_METADATA获取。<br/>**说明：** 从API version 9开始支持，从API version 10开始不再维护，建议使用metadataArray替代。 |
| metadataArray<sup>10+</sup>              | Array\<[ModuleMetadata](#modulemetadata10)> | 是   | 否   | 应用程序的元信息，通过调用[getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)接口，bundleFlags参数传入GET_BUNDLE_INFO_WITH_APPLICATION和GET_BUNDLE_INFO_WITH_METADATA获取。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| removable                  | boolean                                                      | 是   | 否   | 应用程序是否可以被移除，取值为true表示可以被移除，取值为false表示不可以被移除。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| accessTokenId             | number                                                       | 是   | 否   | 应用程序的accessTokenId，应用的身份标识，在[checkAccessToken](js-apis-abilityAccessCtrl.md#checkaccesstoken9)中使用。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| uid                       | number                                                       | 是   | 否   | 应用程序的UID。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| iconResource              | [Resource](../apis-localization-kit/js-apis-resource-manager.md#resource9) | 是 | 否 | 应用程序的图标资源信息，包含了该资源信息的bundleName、moduleName和id，可以调用全球化的接口[getMediaContentBase64](../apis-localization-kit/js-apis-resource-manager.md#getmediacontentbase649)，传入参数iconResource.id来获取详细的资源数据信息。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| labelResource             | [Resource](../apis-localization-kit/js-apis-resource-manager.md#resource9) | 是 | 否 | 应用程序的名称资源信息，包含了该资源信息的bundleName、moduleName和id，可以调用全球化的接口[getStringValue](../apis-localization-kit/js-apis-resource-manager.md#getstringvalue9)，传入参数labelResource.id来获取详细的资源数据信息。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| descriptionResource       | [Resource](../apis-localization-kit/js-apis-resource-manager.md#resource9) | 是 | 否 | 应用程序的描述资源信息，包含了该资源信息的bundleName、moduleName和id，可以调用全球化的接口[getStringValue](../apis-localization-kit/js-apis-resource-manager.md#getstringvalue9)，传入参数descriptionResource.id来获取详细的资源数据信息。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| appDistributionType       | string                                                       | 是   | 否   | 应用程序签名证书的分发类型，分为： <li>app_gallery：应用市场安装的应用。<!--RP1--><!--RP1End--> <li> enterprise：企业内部应用，企业自行开发、仅限企业内部员工使用的应用，不通过应用市场等公开渠道发布，而是通过企业自己的渠道进行内部分发。<!--RP2--><!--RP2End--><li> enterprise_mdm：企业[MDM应用](../../mdm/mdm-kit-term.md#mdm应用)。<!--Del-->需要通过调用[enableAdmin](../apis-mdm-kit/js-apis-enterprise-adminManager-sys.md#adminmanagerenableadmin)接口激活管理员特权后，才能安装普通企业应用。<!--DelEnd--><!--RP3--><!--RP3End--> <li>enterprise_normal：普通企业应用，无需上架华为应用市场，可通过企业[MDM应用](../../mdm/mdm-kit-term.md#mdm应用)以及离线安装器分发安装。<!--RP4--><!--RP4End--><li>os_integration：预置应用，三方应用无法申请配置。<li>crowdtesting：众包测试应用，是由应用市场分发给部分用户，有一定的有效期的特定应用，系统检测到应用的有效期到期后，会通知用户到应用市场更新release版本的应用。从API version 11开始被废弃。<li>internaltesting：应用市场内测的应用。<!--RP5--><!--RP5End--><li>none：其他。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| appProvisionType          | string                                                       | 是   | 否   | 应用程序签名证书文件的类型，分为'debug'和'release'两种类型。'debug'类型用于开发测试阶段，可调试和验证功能；'release'类型用于生产环境中正式发布的应用。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| systemApp          | boolean                                                       | 是   | 否   | 标识应用是否为系统应用，取值为true表示系统应用，取值为false表示非系统应用。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| bundleType                |[bundleManager.BundleType](js-apis-bundleManager.md#bundletype)             | 是   | 否   | 标识包的类型，取值为APP（应用）或者ATOMIC_SERVICE（原子化服务）。APP为传统的应用形态，需要用户主动安装；ATOMIC_SERVICE为原子化服务形态，即点即用，无需安装。开发者可根据此字段判断当前应用的类型并进行差异化处理。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| debug<sup>10+</sup>       | boolean                                | 是   | 否   | 标识应用是否处于调试模式，取值为true表示应用处于调试模式，取值为false表示应用处于非调试模式。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| dataUnclearable<sup>11+</sup>       | boolean                      | 是   | 否   | 标识应用数据是否可被删除。true表示不可删除，false表示可以删除。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| nativeLibraryPath<sup>12+</sup> | string                                                                     | 是   | 否   | 应用程序的本地库文件路径。                                                  |
| multiAppMode<sup>12+</sup> | [MultiAppMode](#multiappmode12) | 是   | 否   | 应用多开模式。适用于管理企业多账号（如工作账号和个人账号同时登录）、多环境并行（如测试环境和生产环境）、社交多身份（如个人账号和工作账号）等需要同时运行多个应用实例的场景。|
| appIndex<sup>12+</sup>    | number    | 是   | 否   | 应用包的分身索引标识，仅在分身应用中生效。取值为整数，范围：[0-5]，0表示主应用，1-5表示分身应用。 |
| installSource<sup>12+</sup>    | string    | 是   | 否   | 标识应用程序的安装来源，支持的取值如下：<br/> - pre-installed：表示首次开机时已安装的预置应用。<br/> - ota：表示系统升级时新增的预置应用。<br/> - recovery：表示用户卸载后又手动恢复的预置应用。<br/> - bundleName：表示由此包名对应的应用安装。该bundleName代表变量，以实际值为准。<br/> - unknown：表示应用安装来源未知。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| releaseType<sup>12+</sup>    | string    | 是   | 否   | 标识应用打包时使用的SDK的发布类型。当前SDK的发布类型为Canary、Beta或Release，其中Canary和Beta通过序号进一步细分，例如Canary1、Canary2、Beta1、Beta2等。开发者可通过对比应用打包依赖的SDK发布类型和OS的发布类型（[deviceInfo.distributionOSReleaseType](../apis-basic-services-kit/js-apis-device-info.md)）来判断兼容性。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| cloudFileSyncEnabled<sup>12+</sup>    | boolean    | 是   | 否   | 标识当前应用是否启用端云文件同步能力。true表示当前应用启用端云文件同步能力，false表示当前应用不启用端云文件同步能力。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| cloudStructuredDataSyncEnabled<sup>20+</sup>    | boolean    | 是   | 是   | 标识当前应用是否启用端云结构化数据同步能力。true表示当前应用启用端云结构化数据同步能力，false表示当前应用不启用端云结构化数据同步能力。<br/>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |

## MultiAppMode<sup>12+</sup>
表示[应用多开](../../quick-start/multiInstance.md)模式。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

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