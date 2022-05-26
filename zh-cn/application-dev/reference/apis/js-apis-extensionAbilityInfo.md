# ExtensionAbilityInfo

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
>
> 本模块首批接口从API version 9开始支持。API 9当前为Canary版本，仅供使用，不保证接口可稳定调用。

## 导入模块

```js
import bundle from "@ohos.bundle";
```


## AbilityInfo

Ability信息

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称                    | 类型                    | 可读   | 可写   | 说明                       |
| --------------------- | --------------------- | ---- | ---- | ------------------------ |
| bundleName            | string                | 是    | 否    | 应用包名                     |
| moduleName            | string                | 是    | 否    | Ability所属的HAP包的名称        |
| name                  | string                | 是    | 否    | Ability名称                |
| labelId               | number                | 是    | 否    | Ability的标签id             |
| descriptionId         | number                | 是    | 否    | Ability的描述id             |
| iconId                | number                | 是    | 否    | Ability的图标id             |
| isVisible             | boolean               | 是    | 否    | 判断Ability是否可以被其他应用调用     |
| extensionAbilityType  | bundle.ExtensionAbilityType | 是   | 否   | ExtensionAbility类型      |
| permissions           | Array\<string>        | 是    | 否    | 被其他应用Ability调用时需要申请的权限集合 |
| applicationInfo       | ApplicationInfo       | 是    | 否    | 应用程序的配置信息                |
| metaData              | Array\<Metadata>      | 是    | 否    | ability的元信息              |
| enabled               | boolean               | 是    | 否    | ability是否可用              |
| readPermission        | string                | 是    | 否    | 读取Ability数据所需的权限         |
| writePermission       | string                | 是    | 否    | 向Ability写数据所需的权限         |