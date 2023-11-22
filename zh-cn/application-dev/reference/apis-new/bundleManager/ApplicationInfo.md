# ApplicationInfo    
应用程序信息，未做特殊说明的属性，均通过[bundle.getApplicationInfo](js-apis-Bundle.md#bundlegetapplicationinfodeprecated)获取。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## ApplicationInfo  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| name | string | true | true | 应用程序的名称。 |  
| description | string | true | true | 应用程序的描述信息。 |  
| descriptionId | number | true | true | 应用程序的描述信息的资源id。 |  
| enabled | boolean | true | true | 判断应用程序是否可以使用，默认为true。 |  
| label | string | true | true | 应用程序显示的标签。 |  
| labelId | number | true | true | 应用程序的标签的资源id值。 |  
| icon | string | true | true | 应用程序的图标。 |  
| iconId | number | true | true | 应用程序图标的资源id值。 |  
| process | string | true | true | 应用程序的进程，如果不设置，默认为包的名称。 |  
| permissions | Array<string> | true | true | 访问应用程序所需的权限。<br />通过调用[bundle.getApplicationInfo](js-apis-Bundle.md#bundlegetapplicationinfodeprecated)接口时，传入GET_APPLICATION_INFO_WITH_PERMISSION获取。 |  
| codePath | string | true | true | 应用程序的安装目录。不能拼接路径访问资源文件，请使用[资源管理接口](js-apis-resource-manager.md)访问资源。                    |  
| metadata<sup>(deprecated)</sup> | Map<string, Array<Metadata>> | true | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ApplicationInfo#metadataArray替代。<br>应用程序的自定义元信息。<br />通过调用[bundle.getApplicationInfo](js-apis-Bundle.md#bundlegetapplicationinfodeprecated)接口时，传入GET_APPLICATION_INFO_WITH_METADATA获取。 |  
| metadataArray<sup>(10+)</sup> | Array<ModuleMetadata> | true | true |  |  
| removable | boolean | true | true | 应用程序是否可以被移除。 |  
| accessTokenId | number | true | true | 应用程序的accessTokenId。 |  
| uid | number | true | true | 应用程序的uid。 |  
| iconResource | Resource | true | true |  |  
| labelResource | Resource | true | true |  |  
| descriptionResource | Resource | true | true |  |  
| appDistributionType | string | true | true |  |  
| appProvisionType | string | true | true |  |  
| systemApp | boolean | true | true | 判断是否为系统应用程序，默认为false。 |  
| bundleType | bundleManager.BundleType | true | true |  |  
| debug<sup>(10+)</sup> | boolean | true | true |  |  
    
## ModuleMetadata<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| moduleName<sup>(10+)</sup> | string | true | true |  |  
| metadata<sup>(10+)</sup> | Array<Metadata> | true | true |  |  
