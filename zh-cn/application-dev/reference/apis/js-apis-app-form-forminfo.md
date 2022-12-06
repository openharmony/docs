# FormInfo

FormInfo模块提供对卡片的相关卡片信息和状态进行设置和查询的能力。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import formInfo from '@ohos.app.form.formInfo';
```

## FormInfo

卡片信息

**系统能力**：SystemCapability.Ability.Form

| 名称        | 可读    | 可写    | 类型                 | 说明                                                         |
| ----------- | -------- | -------- | -------------------- | ------------------------------------------------------------ |
| bundleName  | 是    | 否     | string               | 卡片所属包的包名。                           |
| moduleName  | 是    | 否     | string               | 卡片所属模块的模块名。                       |
| abilityName | 是    | 否     | string               | 卡片所属的Ability名称。                       |
| name        | 是    | 否     | string               | 卡片名称。                                 |
| description | 是    | 否     | string               | 卡片描述。   |
| type        | 是    | 否     | [FormType](#formtype)             | 卡片类型。当前支持JS卡片。 |
| jsComponentName      | 是    | 否     | string               | js卡片的组件名。               |
| colorMode  | 是    | 否     | [ColorMode](#colormode) | 卡片颜色模式。                                       |
| isDefault    | 是    | 否     | boolean      | 卡片是否是默认卡片。                              |
| updateEnabled  | 是    | 否     | boolean               | 卡片是否使能更新。                    |
| formVisibleNotify  | 是    | 否     | string               | 卡片是否使能可见通知。            |
| relatedBundleName | 是    | 否     | string               | 卡片所属的相关联包名。                   |
| scheduledUpdateTime        | 是    | 否     | string               | 卡片更新时间。     |
| formConfigAbility | 是    | 否     | string               | 卡片配置ability。指定长按卡片弹出的选择框内，编辑选项所对应的ability。   |
| updateDuration        | 是    | 否     | string             | 卡片更新周期。 |
| defaultDimension  | 是    | 否     | number | 表示卡片规格                                       |
| supportDimensions    | 是    | 否     | Array&lt;number&gt;      | 卡片支持的规格。具体可选规格参考[FormDimension](#formdimension)   |
| customizeData    | 是    | 否     | {[key: string]: [value: string]}      | 卡片用户数据。         |

## FormType

支持的卡片类型枚举。

**系统能力**：SystemCapability.Ability.Form

| 名称        | 值   | 说明         |
| ----------- | ---- | ------------ |
| JS      | 1    | 卡片类型为JS。   |
| eTS     | 2    | 卡片类型为eTS。 |

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

| 名称        | 可读    | 可写    | 类型                 | 说明                                                         |
| ----------- | -------- | -------- | -------------------- | ------------------------------------------------------------ |
| formState  | 是    | 否     | [FormState](#formstate)               | 卡片状态。                          |
| want  | 是    | 否     | Want               | Want文本内容。    |

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
| IDENTITY_KEY     | "ohos.extra.param.key.form_identity"    | 卡片标识。<br>**系统接口**: 此接口为系统接口。   |
| DIMENSION_KEY      | "ohos.extra.param.key.form_dimension"  | 卡片规格样式。   |
| NAME_KEY       | "ohos.extra.param.key.form_name"   | 卡片名称。   |
| MODULE_NAME_KEY        | "ohos.extra.param.key.module_name"   | 卡片所属模块名称。   |
| WIDTH_KEY        | "ohos.extra.param.key.form_width"   | 卡片宽度。   |
| HEIGHT_KEY         | "ohos.extra.param.key.form_height"   | 卡片高度。   |
| TEMPORARY_KEY          | "ohos.extra.param.key.form_temporary"   | 临时卡片。   |
| ABILITY_NAME_KEY   | "ohos.extra.param.key.ability_name"   | ability名称   |
| DEVICE_ID_KEY    | "ohos.extra.param.key.device_id"   | 设备标识。<br/>**系统接口**: 此接口为系统接口。   |
| BUNDLE_NAME_KEY    | "ohos.extra.param.key.bundle_name"   | 指示指定要获取的捆绑包名称的键。|

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


## FormInfoFilter

卡片信息过滤器，仅将符合过滤器内要求的卡片信息返回。

**系统能力**：SystemCapability.Ability.Form

| 名称        |  必选   | 说明         |
| ----------- | ---- | ------------ |
| moduleName   | 否   | 仅保留moduleName与提供值相符的卡片信息。 |

## VisibilityType

卡片当前可见类型枚举。

**系统能力**：SystemCapability.Ability.Form

| 名称        |  值   | 说明         |
| ----------- | ---- | ------------ |
| FORM_VISIBLE | 否   | 表示卡片为可见。 |
| FORM_INVISIBLE   | 否   | 表示卡片为不可见。 |