# ExtensionAbilityInfo

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。 
> API9 当前为Canary版本，仅供试用，不保证接口可稳定调用。

ExtensionAbility信息

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework

| 名称                                | 类型                          | 可读   | 可写   | 说明                                |
| --------------------------------- | --------------------------- | ---- | ---- | --------------------------------- |
| bundleName           | string                      | 是    | 否    | 应用包名                              |
| moduleName           | string                      | 是    | 否    | ExtensionAbility所属的HAP包的名称        |
| name                 | string                      | 是    | 否    | ExtensionAbility名称                |
| labelId              | number                      | 是    | 否    | ExtensionAbility的标签id             |
| descriptionId        | number                      | 是    | 否    | ExtensionAbility的描述id             |
| iconId               | number                      | 是    | 否    | ExtensionAbility的图标id             |
| isVisible            | boolean                     | 是    | 否    | 判断ExtensionAbility是否可以被其他应用调用     |
| extensionAbilityType | bundle.ExtensionAbilityType | 是    | 否    | ExtensionAbility类型                |
| permissions        | Array\<string>              | 是    | 否    | 被其他应用ExtensionAbility调用时需要申请的权限集合 |
| applicationInfo      | ApplicationInfo             | 是    | 否    | 应用程序的配置信息                         |
| metaData             | Array\<[Metadata](js-apis-bundle-Metadata.md)>            | 是    | 否    | ExtensionAbility的元信息              |
| enabled              | boolean                     | 是    | 否    | ExtensionAbility是否可用              |
| readPermission       | string                      | 是    | 否    | 读取ExtensionAbility数据所需的权限         |
| writePermission      | string                      | 是    | 否    | 向ExtensionAbility写数据所需的权限         |
