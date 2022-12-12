# FormInfo

FormInfo模块提供对卡片的相关卡片信息和状态进行设置和查询的能力。

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 从API version 9 开始不再维护，建议使用[FormInfo](js-apis-app-form-formInfo.md)替代。

## 导入模块

```ts
import formInfo from '@ohos.application.formInfo';
```

## FormInfo

卡片信息

**系统能力**：SystemCapability.Ability.Form

| 名称        | 类型                 | 可读    | 可写     | 说明                                                         |
| ----------- | -------- |-------- | -------------------- | ------------------------------------------------------------ |
| bundleName  | string               | 是    | 否      | 表示卡片所属包的包名。                           |
| moduleName  | string               | 是    | 否      | 表示卡片所属模块的模块名。                       |
| abilityName | string               | 是    | 否      | 表示卡片所属的Ability名称。                       |
| name        | string               | 是    | 否      | 表示卡片名称。                                 |
| description | string               | 是    | 否      | 表示卡片描述。   |
| type        | [FormType](#formtype)             | 是    | 否      | 表示卡片类型，当前支持JS卡片。 |
| jsComponentName      | string               | 是    | 否      | 表示js卡片的组件名。               |
| colorMode  | [ColorMode](#colormode) | 是    | 否      | 表示卡片颜色模式。                                       |
| isDefault    | boolean      | 是    | 否      | 表示是否是默认卡片。                              |
| updateEnabled  | boolean               | 是    | 否      | 表示卡片是否使能更新。                    |
| formVisibleNotify  | string               | 是    | 否      | 表示卡片是否使能可见通知。            |
| relatedBundleName | string               | 是    | 否      | 表示卡片所属的相关联包名。                   |
| scheduledUpdateTime        | string               | 是    | 否      | 表示卡片更新时间。     |
| formConfigAbility | string               | 是    | 否      | 表示卡片配置ability。   |
| updateDuration        | string             | 是    | 否      | 表示卡片更新周期。 |
| defaultDimension  | number | 是    | 否      | 表示卡片规格                                       |
| supportDimensions    | Array&lt;number&gt;      | 是    | 否      | 表示卡片支持的规格。                 |
| customizeData    | {[key: string]: [value: string]}      | 是    | 否      | 表示卡片用户数据。         |

## FormType

支持的卡片类型枚举。

**系统能力**：SystemCapability.Ability.Form

| 名称        | 值   | 说明         |
| ----------- | ---- | ------------ |
| JS      | 1    | 卡片类型为JS。   |
| eTS<sup>9+<sup>     | 2    | 卡片类型为eTS。 |

## ColorMode

卡片支持的颜色模式枚举。

**系统能力**：SystemCapability.Ability.Form

| 名称        | 值   | 说明         |
| ----------- | ---- | ------------ |
| MODE_AUTO   | -1    | 表示自动模式。   |
| MODE_DARK    | 0   | 表示暗色。   |
| MODE_LIGHT     | 1   | 表示亮色。   |

## FormStateInfo

卡片状态信息。

**系统能力**：SystemCapability.Ability.Form

| 名称        | 类型                 | 可读    | 可写     | 说明                                                         |
| ----------- | -------- |-------- | -------------------- | ------------------------------------------------------------ |
| formState  | [FormState](#formstate)               | 是    | 否      | 表示卡片状态。                          |
| want  | Want               | 是    | 否      | Want文本内容。    |

##  FormState

卡片状态枚举。

**系统能力**：SystemCapability.Ability.Form

| 名称        | 值   | 说明         |
| ----------- | ---- | ------------ |
| UNKNOWN    | -1    | 表示未知状态。   |
| DEFAULT     | 0   | 表示默认状态。   |
| READY      | 1   | 表示就绪状态。   |

##  FormParam

卡片参数枚举。

**系统能力**：SystemCapability.Ability.Form

| 名称        | 值   | 说明         |
| ----------- | ---- | ------------ |
| IDENTITY_KEY<sup>9+</sup>     | "ohos.extra.param.key.form_identity"    | 卡片标识。<br>**系统接口**: 此接口为系统接口。   |
| DIMENSION_KEY      | "ohos.extra.param.key.form_dimension"  | 卡片规格样式。   |
| NAME_KEY       | "ohos.extra.param.key.form_name"   | 卡片名称。   |
| MODULE_NAME_KEY        | "ohos.extra.param.key.module_name"   | 卡片所属模块名称。   |
| WIDTH_KEY        | "ohos.extra.param.key.form_width"   | 卡片宽度。   |
| HEIGHT_KEY         | "ohos.extra.param.key.form_height"   | 卡片高度。   |
| TEMPORARY_KEY          | "ohos.extra.param.key.form_temporary"   | 临时卡片。   |
| ABILITY_NAME_KEY<sup>9+</sup>   | "ohos.extra.param.key.ability_name"   | ability名称   |
| DEVICE_ID_KEY<sup>9+</sup>      | "ohos.extra.param.key.device_id"   | 设备标识。<br/>**系统接口**: 此接口为系统接口。   |
| BUNDLE_NAME_KEY<sup>9+</sup>      | "ohos.extra.param.key.bundle_name"   | 指示指定要获取的捆绑包名称的键。|

##  FormDimension<sup>9+</sup>

定义卡片尺寸枚举。

**系统能力**：SystemCapability.Ability.Form

| 名称        | 值   | 说明         |
| ----------- | ---- | ------------ |
| Dimension_1_2 <sup>9+</sup>      | 1   | 1 x 2 form。   |
| Dimension_2_2 <sup>9+</sup>      | 2   | 2 x 2 form。   |
| Dimension_2_4 <sup>9+</sup>      | 3   | 2 x 4 form。   |
| Dimension_4_4 <sup>9+</sup>      | 4   | 4 x 4 form。   |
| Dimension_2_1 <sup>9+</sup>      | 5   | 2 x 1 form。   |

## VisibilityType

卡片可见性。

**系统能力**：SystemCapability.Ability.Form

| 名称        | 值   | 说明         |
| ----------- | ---- | ------------ |
| FORM_VISIBLE<sup>9+<sup>         | 1   | 卡片状态为可见。  |
| FORM_INVISIBLE<sup>9+<sup>       | 2   | 卡片状态为不可见。 |      

## FormInfoFilter<sup>9+</sup>

卡片信息过滤器，仅将符合过滤器内要求的卡片信息返回。

**系统能力**：SystemCapability.Ability.Form

| 名称        | 说明         |
| ----------- | ------------ |
| moduleName<sup>9+</sup>   | 仅保留moduleName与提供值相符的卡片信息。 |

## VisibilityType<sup>9+</sup>

卡片当前可见类型枚举。

**系统能力**：SystemCapability.Ability.Form

| 名称        |  值   | 说明         |
| ----------- | ---- | ------------ |
| FORM_VISIBLE<sup>9+<sup>   | 1   | 表示卡片为可见。 |
| FORM_INVISIBLE<sup>9+<sup>   | 2   | 表示卡片为不可见。 |