# ApplicationInfo

应用程序信息，未做特殊说明的属性，均通过[bundle.getApplicationInfo](js-apis-Bundle.md#bundlegetapplicationinfodeprecated)获取。

> **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## ApplicationInfo<sup>(deprecated)<sup>

> 从API version 9开始不再维护，建议使用[bundleManager-ApplicationInfo](js-apis-bundleManager-applicationInfo.md)替代。

**系统能力**: SystemCapability.BundleManager.BundleFramework



| 名称                       | 类型                                                         | 只读 | 可选 | 说明                                                         |
| -------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| name                       | string                                                       | 是   | 否   | 应用程序的名称。                                             |
| description                | string                                                       | 是   | 否   | 应用程序的描述信息。                                         |
| descriptionId              | number                                                       | 是   | 否   | 应用程序的描述信息的资源id。                                 |
| systemApp                  | boolean                                                      | 是   | 否   | 判断是否为系统应用程序，取值为true表示系统应用，取值为false表示非系统应用。                        |
| enabled                    | boolean                                                      | 是   | 否   | 判断应用程序是否可以使用，取值为true表示可以使用，取值为false表示不可使用。                       |
| label                      | string                                                       | 是   | 否   | 应用程序显示的标签。                                         |
| labelId                    | string                                                       | 是   | 否   | 应用程序的标签的资源id值。                                   |
| icon                       | string                                                       | 是   | 否   | 应用程序的图标。                                             |
| iconId                     | string                                                       | 是   | 否   | 应用程序图标的资源id值。                                     |
| process                    | string                                                       | 是   | 否   | 应用程序的进程名称。                 |
| supportedModes             | number                                                       | 是   | 否   | 标识应用支持的运行模式，当前只定义了驾驶模式（drive）。该标签只适用于车机。 |
| moduleSourceDirs           | Array\<string>                                               | 是   | 否   | 应用程序的资源存放的相对路径。不能拼接路径访问资源文件，请使用[资源管理接口](../apis-localization-kit/js-apis-resource-manager.md)访问资源。                               |
| permissions                | Array\<string>                                               | 是   | 否   | 访问应用程序所需的权限。<br />通过调用[bundle.getApplicationInfo](js-apis-Bundle.md#bundlegetapplicationinfodeprecated)接口时，传入GET_APPLICATION_INFO_WITH_PERMISSION获取。 |
| moduleInfos                | Array\<[ModuleInfo](js-apis-bundle-ModuleInfo.md)>           | 是   | 否   | 应用程序的模块信息。                                         |
| entryDir                   | string                                                       | 是   | 否   | 应用程序的文件保存路径。不能拼接路径访问资源文件，请使用[资源管理接口](../apis-localization-kit/js-apis-resource-manager.md)访问资源。                                     |
| codePath<sup>8+</sup>      | string                                                       | 是   | 否   | 应用程序的安装目录。不能拼接路径访问资源文件，请使用[资源管理接口](../apis-localization-kit/js-apis-resource-manager.md)访问资源。                                         |
| metaData<sup>8+</sup>      | Map\<string, Array\<[CustomizeData](js-apis-bundle-CustomizeData.md)>> | 是   | 否   | 应用程序的自定义元信息。<br />通过调用[bundle.getApplicationInfo](js-apis-Bundle.md#bundlegetapplicationinfodeprecated)接口时，传入GET_APPLICATION_INFO_WITH_METADATA获取。 |
| removable<sup>8+</sup>     | boolean                                                      | 是   | 否   | 应用程序是否可以被移除，取值为true表示可以被移除，取值为false表示不可以被移除。                                     |
| accessTokenId<sup>8+</sup> | number                                                       | 是   | 否   | 应用程序的accessTokenId。                                    |
| uid<sup>8+</sup>           | number                                                       | 是   | 否   | 应用程序的uid。                                              |
| entityType                 | string                                                       | 是   | 否   | 应用程序的类别，例如游戏、社交、影视、新闻。 |