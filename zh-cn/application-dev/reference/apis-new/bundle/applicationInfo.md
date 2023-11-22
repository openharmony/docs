# applicationInfo    
应用程序信息，未做特殊说明的属性，均通过[bundle.getApplicationInfo](js-apis-Bundle.md#bundlegetapplicationinfodeprecated)获取。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## ApplicationInfo<sup>(deprecated)</sup>    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bundle.bundleManager.ApplicationInfo替代。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>应用程序的名称。 |  
| description<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>应用程序的描述信息。 |  
| descriptionId<sup>(deprecated)</sup> | number | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>应用程序的描述信息的资源id。 |  
| systemApp<sup>(deprecated)</sup> | boolean | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>判断是否为系统应用程序，默认为false。 |  
| enabled<sup>(deprecated)</sup> | boolean | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>判断应用程序是否可以使用，默认为true。 |  
| label<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>应用程序显示的标签。 |  
| labelId<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bundle.bundleManager.ApplicationInfo.labelIndex替代。<br>应用程序的标签的资源id值。 |  
| icon<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>应用程序的图标。 |  
| iconId<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bundle.bundleManager.ApplicationInfo.iconIndex替代。<br>应用程序图标的资源id值。 |  
| process<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>应用程序的进程，如果不设置，默认为包的名称。 |  
| supportedModes<sup>(deprecated)</sup> | number | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>标识应用支持的运行模式，当前只定义了驾驶模式（drive）。该标签只适用于车机。 |  
| moduleSourceDirs<sup>(deprecated)</sup> | Array<string> | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>应用程序的资源存放的相对路径。不能拼接路径访问资源文件，请使用[资源管理接口](js-apis-resource-manager.md)访问资源。 |  
| permissions<sup>(deprecated)</sup> | Array<string> | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>访问应用程序所需的权限。<br />通过调用[bundle.getApplicationInfo](js-apis-Bundle.md#bundlegetapplicationinfodeprecated)接口时，传入GET_APPLICATION_INFO_WITH_PERMISSION获取。 |  
| moduleInfos<sup>(deprecated)</sup> | Array<ModuleInfo> | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>应用程序的模块信息。 |  
| entryDir<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>应用程序的文件保存路径。不能拼接路径访问资源文件，请使用[资源管理接口](js-apis-resource-manager.md)访问资源。 |  
| codePath<sup>(deprecated)</sup> | string | true | true | 从API version 8 开始支持，从API version 9 开始废弃。<br><span style="letter-spacing: 0px;">应用程序的安装目录。不能拼接路径访问资源文件，请使用[资源管理接口](js-apis-resource-manager.md)访问资源。</span> |  
| metaData<sup>(deprecated)</sup> | Map<string, Array<CustomizeData>> | true | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>应用程序的自定义元信息。<br />通过调用[bundle.getApplicationInfo](js-apis-Bundle.md#bundlegetapplicationinfodeprecated)接口时，传入GET_APPLICATION_INFO_WITH_METADATA获取。 |  
| removable<sup>(deprecated)</sup> | boolean | true | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>应用程序是否可以被移除。 |  
| accessTokenId<sup>(deprecated)</sup> | number | true | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>应用程序的accessTokenId。 |  
| uid<sup>(deprecated)</sup> | number | true | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>应用程序的uid。 |  
| entityType<sup>(deprecated)</sup> | string | true | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>应用程序的类别，例如游戏、社交、影视、新闻。 |  
