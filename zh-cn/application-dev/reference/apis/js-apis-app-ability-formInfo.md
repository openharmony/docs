# FormInfo

FormInfo模块提供对卡片的相关卡片信息和状态进行设置和查询的能力。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```
import formInfo from '@ohos.app.ability.formInfo';
```

## 权限

无

## FormInfo

卡片信息

**系统能力**：SystemCapability.Ability.Form

| 名称        | 读写属性 | 类型                 | 描述                                                         |
| ----------- | -------- | -------------------- | ------------------------------------------------------------ |
| bundleName  | 只读     | string               | 表示卡片所属包的包名。                           |
| moduleName  | 只读     | string               | 表示卡片所属模块的模块名。                       |
| abilityName | 只读     | string               | 表示卡片所属的Ability名称。                       |
| name        | 只读     | string               | 表示卡片名称。                                 |
| description | 只读     | string               | 表示卡片描述。   |
| type        | 只读     | [FormType](#formtype)             | 表示卡片类型，当前支持JS卡片。 |
| jsComponentName      | 只读     | string               | 表示js卡片的组件名。               |
| colorMode  | 只读     | [ColorMode](#colormode) | 表示卡片颜色模式。                                       |
| isDefault    | 只读     | boolean      | 表示是否是默认卡片。                              |
| updateEnabled  | 只读     | boolean               | 表示卡片是否使能更新。                    |
| formVisibleNotify  | 只读     | string               | 表示卡片是否使能可见通知。            |
| relatedBundleName | 只读     | string               | 表示卡片所属的相关联包名。                   |
| scheduledUpdateTime        | 只读     | string               | 表示卡片更新时间。     |
| formConfigAbility | 只读     | string               | 表示卡片配置ability。   |
| updateDuration        | 只读     | string             | 表示卡片更新周期。 |
| defaultDimension  | 只读     | number | 表示卡片规格                                       |
| supportDimensions    | 只读     | Array&lt;number&gt;      | 表示卡片支持的规格。                 |
| customizeData    | 只读     | {[key: string]: [value: string]}      | 表示卡片用户数据。         |

## FormType

枚举，支持的卡片类型。

**系统能力**：SystemCapability.Ability.Form

| 名称        | 值   | 说明         |
| ----------- | ---- | ------------ |
| JS      | 1    | 卡片类型为JS。   |
| eTS      | 2    | 卡片类型为eTS。   |

## ColorMode

枚举，卡片支持的颜色模式。

**系统能力**：SystemCapability.Ability.Form

| 名称        | 值   | 说明         |
| ----------- | ---- | ------------ |
| MODE_AUTO   | -1    | 自动模式。   |
| MODE_DARK    | 0   | 暗色。   |
| MODE_LIGHT     | 1   | 亮色。   |

## FormStateInfo

卡片状态信息。

**系统能力**：SystemCapability.Ability.Form

| 名称        | 读写属性 | 类型                 | 描述                                                         |
| ----------- | -------- | -------------------- | ------------------------------------------------------------ |
| formState  | 只读     | [FormState](#formstate)               | 表示卡片状态。                          |
| want  | 只读     | Want               | Want文本内容。    |

##  FormState

枚举，卡片状态。

**系统能力**：SystemCapability.Ability.Form

| 名称        | 值   | 说明         |
| ----------- | ---- | ------------ |
| UNKNOWN    | -1    | 未知状态。   |
| DEFAULT     | 0   | 默认状态。   |
| READY      | 1   | 就绪状态。   |

##  FormParam

枚举，卡片参数。

**系统能力**：SystemCapability.Ability.Form

| 名称        | 值   | 说明         |
| ----------- | ---- | ------------ |
| IDENTITY_KEY     | "ohos.extra.param.key.form_identity"    | 卡片标识。<br>**系统API**: 此接口为系统接口，三方应用不支持调用。   |
| DIMENSION_KEY      | "ohos.extra.param.key.form_dimension"  | 卡片规格样式。   |
| NAME_KEY       | "ohos.extra.param.key.form_name"   | 卡片名称。   |
| MODULE_NAME_KEY        | "ohos.extra.param.key.module_name"   | 卡片所属模块名称。   |
| WIDTH_KEY        | "ohos.extra.param.key.form_width"   | 卡片宽度。   |
| HEIGHT_KEY         | "ohos.extra.param.key.form_height"   | 卡片高度。   |
| TEMPORARY_KEY          | "ohos.extra.param.key.form_temporary"   | 临时卡片。   |
| ABILITY_NAME_KEY   | "ohos.extra.param.key.ability_name"   | ability名称   |
| DEVICE_ID_KEY      | "ohos.extra.param.key.device_id"   | 设备标识。<br/>此接口为系统接口。   |
| BUNDLE_NAME_KEY      | "ohos.extra.param.key.bundle_name"   | 指示指定要获取的捆绑包名称的键。|

##  FormDimension

定义卡片尺寸枚举。

**系统能力**：SystemCapability.Ability.Form

| 名称        | 值   | 说明         |
| ----------- | ---- | ------------ |
| Dimension_1_2      | 1   | 1 x 2 form。   |
| Dimension_2_2      | 2   | 2 x 2 form。   |
| Dimension_2_4      | 3   | 2 x 4 form。   |
| Dimension_4_4      | 4   | 4 x 4 form。   |
| Dimension_2_1      | 5   | 2 x 1 form。   |

## VisibilityType

卡片可见性。

**系统能力**：SystemCapability.Ability.Form

| 名称        | 值   | 说明         |
| ----------- | ---- | ------------ |
| FORM_VISIBLE         | 1   | 卡片状态为可见。  |
| FORM_INVISIBLE       | 2   | 卡片状态为不可见。 | 

## FormInfoFilter

卡片信息过滤器，仅将符合过滤器内要求的卡片信息返回。

**系统能力**：SystemCapability.Ability.Form

| 名称        |  必选   | 说明         |
| ----------- | ---- | ------------ |
| moduleName   | 否   | 可选字段，表示仅保留moduleName与提供值相符的卡片信息。 |
