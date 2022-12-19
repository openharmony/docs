# ApplicationInfo

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

应用程序信息，系统应用可以通过[getBundleInfo](js-apis-bundleManager.md#bundlemanagergetbundleinfo)获取自身或其他应用的应用程序信息，三方应用可以通过[getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)获取自身的应用程序信息，其中入参[BundleFlag](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-bundleManager.md#bundleflag)需要使用GET_BUNDLE_INFO_WITH_APPLICATION。

## ApplicationInfo

**系统能力**: 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework.Core
| 名称                       | 类型                                                         | 可读 | 可写 | 说明                                                         |
| -------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| name                       | string                                                       | 是   | 否   | 应用程序的名称                                                 |
| description                | string                                                       | 是   | 否   | 标识应用的描述信息                                                 |
| descriptionId              | number                                                       | 是   | 否   | 标识应用的描述信息的资源id                                               |
| enabled                    | boolean                                                      | 是   | 否   | 判断应用程序是否可以使用，默认为true                           |
| label                      | string                                                       | 是   | 否   | 标识应用的名称                                                 |
| labelId                    | number                                                 | 是   | 否   | 标识应用名称的资源id                                               |
| icon                       | string                                                       | 是   | 否   | 应用程序的图标                                                 |
| iconId                     | number                                                 | 是   | 否   | 应用程序图标的资源id                                               |
| process                    | string                                                       | 是   | 否   | 应用程序的进程，如果不设置，默认为包的名称。                   |
| permissions                | Array\<string>                                               | 是   | 否   | 访问应用程序所需的权限，通过传入GET_APPLICATION_INFO_WITH_PERMISSION获取 |
| entryDir                   | string                                                       | 是   | 否   | 应用程序的文件保存路径                                         |
| codePath                   | string                                                       | 是   | 否   | 应用程序的安装目录                                             |
| metadata                   | Map\<string, Array\<[Metadata](js-apis-bundleManager-metadata.md)>> | 是   | 否   | 应用程序的元信息，通过传入GET_APPLICATION_INFO_WITH_METADATA获取 |
| removable                  | boolean                                                      | 是   | 否   | 应用程序是否可以被移除                                         |
| accessTokenId             | number                                                       | 是   | 否   | 应用程序的accessTokenId                                      |
| uid                       | number                                                       | 是   | 否   | 应用程序的uid                                                |
| iconResource              | [Resource](js-apis-resource-manager.md#resource9) | 是 | 否 | 应用程序的图标资源信息                         |
| labelResource             | [Resource](js-apis-resource-manager.md#resource9) | 是 | 否 | 应用程序的标签资源信息                         |
| descriptionResource       | [Resource](js-apis-resource-manager.md#resource9) | 是 | 否 | 应用程序的描述资源信息                         |
| appDistributionType       | string                                                       | 是   | 否   | 应用程序签名证书的分发类型，分为：app_gallery、enterprise、os_integration和crowdtesting    |
| appProvisionType          | string                                                       | 是   | 否   | 应用程序签名证书文件的类型，分为debug和release两种类型           |