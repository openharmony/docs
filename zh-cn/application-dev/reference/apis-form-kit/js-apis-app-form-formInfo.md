# @ohos.app.form.formInfo (formInfo)

formInfo模块提供了卡片信息和状态等相关类型和枚举。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { formInfo } from '@kit.FormKit';
```

## FormInfo

卡片配置信息。

**系统能力：** SystemCapability.Ability.Form

| 名称        | 类型                 | 可读    | 可写    | 说明                                                         |
| ----------- | -------- | -------- | -------------------- | ------------------------------------------------------------ |
| bundleName  | string               | 是    | 否     | 卡片所属包的Bundle名称。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| moduleName  | string               | 是    | 否     | 卡片所属模块的模块名称。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| abilityName | string               | 是    | 否     | 卡片所属的Ability名称。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。  |
| name        | string               | 是    | 否     | 应用/原子化服务名称。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| displayName<sup>11+</sup> | string               | 是    | 否     | 卡片名称。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| displayNameId<sup>11+</sup> | number               | 是    | 否     | 卡片预览时标识卡片名称的ID。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| description | string               | 是    | 否     | 卡片描述。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| descriptionId<sup>10+</sup>      | number               | 是    | 否     | 卡片描述id。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| type        | [FormType](#formtype)             | 是    | 否     | 卡片类型。当前支持JS卡片、ArkTS卡片。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| jsComponentName      | string               | 是    | 否     | js卡片的组件名。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| colorMode  | [ColorMode](#colormode) | 是    | 否     | 卡片颜色模式。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| isDefault    | boolean      | 是    | 否     | 卡片是否是默认卡片。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| updateEnabled  | boolean               | 是    | 否     | 卡片是否使能更新。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| formVisibleNotify  | boolean        | 是    | 否     | 卡片是否使能可见通知。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| scheduledUpdateTime        | string               | 是    | 否     | 卡片更新时间。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| formConfigAbility | string               | 是    | 否     | 卡片配置ability。指定长按卡片弹出的选择框内，编辑选项所对应的ability。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| updateDuration        | number       | 是    | 否     | 卡片更新周期。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| defaultDimension  | number | 是    | 否     | 卡片规格  <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| supportDimensions    | Array&lt;number&gt;      | 是    | 否     | 卡片支持的规格。具体可选规格参考[FormDimension](#formdimension) <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| customizeData    | Record\<string, string>      | 是    | 否     | 卡片用户数据。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| isDynamic<sup>10+</sup>      | boolean               | 是    | 否     | 卡片是否为动态卡片。<br/>仅ArkTS卡片区分动静态卡片，JS卡片均为动态卡片。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| transparencyEnabled<sup>11+</sup>      | boolean               | 是    | 否     | 卡片是否支持设置背景透明度。<br/>ArkTS卡片由用户配置决定是否支持，JS卡片均不支持。  <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| supportedShapes<sup>12+</sup>    | Array&lt;number&gt;      | 是    | 否     | 卡片支持的形状。具体可选形状参考[FormShape<sup>12+</sup>](#formshape12) <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。  |

## FormType

支持的卡片类型枚举。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

| 名称        | 值   | 说明         |
| ----------- | ---- | ------------ |
| JS      | 1    | 卡片类型为JS。   |
| eTS     | 2    | 卡片类型为ArkTS。 |

## ColorMode

卡片支持的颜色模式枚举。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

| 名称        | 值   | 说明         |
| ----------- | ---- | ------------ |
| MODE_AUTO   | -1    | 表示自动模式。   |
| MODE_DARK    | 0   | 表示暗色。   |
| MODE_LIGHT     | 1   | 表示亮色。   |

## FormStateInfo

卡片状态信息。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

| 名称        | 类型                 | 可读    | 可写    | 说明                                                         |
| ----------- | -------- | -------- | -------------------- | ------------------------------------------------------------ |
| formState  | [FormState](#formstate)               | 是    | 否     | 卡片状态。                          |
| want  | [Want](../apis-ability-kit/js-apis-app-ability-want.md)         | 是    | 否     | Want文本内容。    |

##  FormState

卡片状态枚举。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

| 名称        | 值   | 说明         |
| ----------- | ---- | ------------ |
| UNKNOWN    | -1    | 表示未知状态。   |
| DEFAULT     | 0   | 表示默认状态。   |
| READY      | 1   | 表示就绪状态。   |

##  FormParam

卡片参数枚举。

**系统能力：** SystemCapability.Ability.Form

| 名称        | 值   | 说明         |
| ----------- | ---- | ------------ |
| IDENTITY_KEY     | 'ohos.extra.param.key.form_identity'    | 卡片标识。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| DIMENSION_KEY      | 'ohos.extra.param.key.form_dimension'  | 卡片规格样式。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| NAME_KEY       | 'ohos.extra.param.key.form_name'   | 卡片名称。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| MODULE_NAME_KEY        | 'ohos.extra.param.key.module_name'   | 卡片所属模块名称。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| WIDTH_KEY        | 'ohos.extra.param.key.form_width'   | 卡片宽度。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| HEIGHT_KEY         | 'ohos.extra.param.key.form_height'   | 卡片高度。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| TEMPORARY_KEY          | 'ohos.extra.param.key.form_temporary'   | 临时卡片。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| ABILITY_NAME_KEY   | 'ohos.extra.param.key.ability_name'   | ability名称。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| BUNDLE_NAME_KEY    | 'ohos.extra.param.key.bundle_name'   | Bundle名称。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| LAUNCH_REASON_KEY<sup>10+</sup>    | 'ohos.extra.param.key.form_launch_reason'   | 卡片创建原因。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| PARAM_FORM_CUSTOMIZE_KEY<sup>10+</sup>    | 'ohos.extra.param.key.form_customize'   | 自定义数据。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| FORM_RENDERING_MODE_KEY<sup>11+</sup>    | 'ohos.extra.param.key.form_rendering_mode'   | 卡片渲染模式。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| HOST_BG_INVERSE_COLOR_KEY<sup>12+</sup>    | 'ohos.extra.param.key.host_bg_inverse_color'   | 卡片使用方的背景反色颜色值。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| FORM_LOCATION_KEY<sup>12+</sup>    | 'ohos.extra.param.key.form_location'   | 卡片位置。|
| FORM_PERMISSION_NAME_KEY<sup>12+</sup> | 'ohos.extra.param.key.permission_name' | 用户授权权限名称。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| FORM_PERMISSION_GRANTED_KEY<sup>12+</sup> | 'ohos.extra.param.key.permission_granted' | 用户是否授权。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |

##  FormDimension

定义卡片尺寸枚举。

**系统能力：** SystemCapability.Ability.Form

| 名称        | 值   | 说明         |
| ----------- | ---- | ------------ |
| Dimension_1_2      | 1   | 1 x 2 form。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| Dimension_2_2      | 2   | 2 x 2 form。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| Dimension_2_4      | 3   | 2 x 4 form。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| Dimension_4_4      | 4   | 4 x 4 form。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| Dimension_2_1      | 5   | 2 x 1 form。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| DIMENSION_1_1<sup>11+<sup>      | 6   | 1 x 1 form。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| DIMENSION_6_4<sup>12+<sup>      | 7   | 6 x 4 form。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|

##  FormShape<sup>12+</sup> 

定义卡片形状枚举。

**系统能力：** SystemCapability.Ability.Form

| 名称        | 值   | 说明         |
| ----------- | ---- | ------------ |
| RECT        | 1   | 方形 form。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| CIRCLE      | 2   | 圆形 form。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|

## FormInfoFilter

卡片信息过滤器，仅将符合过滤器内要求的卡片信息返回。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

| 名称        | 类型   | 必填         |说明         |
| ----------- | ---- | ------------ |------------ |
| moduleName    | string    |否    | 选填，仅保留含moduleName与提供值相符的卡片信息，<br>未填写时则不通过moduleName进行过滤。   |



## VisibilityType

卡片当前可见类型枚举。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

| 名称        |  值   | 说明         |
| ----------- | ---- | ------------ |
| UNKNOWN<sup>10+</sup> | 0   | 表示卡片为未知。 |
| FORM_VISIBLE | 1   | 表示卡片为可见。 |
| FORM_INVISIBLE   | 2   | 表示卡片为不可见。 |


## LaunchReason<sup>10+</sup>

卡片创建原因枚举。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

| 名称        |  值   | 说明         |
| ----------- | ---- | ------------ |
| FORM_DEFAULT | 1   | 表示卡片创建原因为默认创建。 |
| FORM_SHARE   | 2   | 表示卡片创建原因为共享创建。 |
