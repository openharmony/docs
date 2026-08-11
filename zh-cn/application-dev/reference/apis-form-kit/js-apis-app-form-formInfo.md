# @ohos.app.form.formInfo (formInfo)
<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @Qian-Win-->
<!--Designer: @cx983299475-->
<!--Tester: @mahailong123456-->
<!--Adviser: @HelloShuo-->

formInfo模块提供了卡片信息和状态等相关类型和枚举，用于获取卡片配置信息、状态信息、参数枚举等，适用于需要查询卡片属性、管理卡片状态、处理卡片参数的场景，帮助开发者快速访问和操作卡片相关信息。

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

| 名称        | 类型                 | 只读    | 可选    | 说明                                                         |
| ----------- | -------- | -------- | -------------------- | ------------------------------------------------------------ |
| bundleName  | string               | 否    | 否     | 卡片所属包的Bundle名称。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| moduleName  | string               | 否    | 否     | 卡片所属模块的模块名称。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| abilityName | string               | 否    | 否     | 卡片所属的Ability名称。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。  |
| name        | string               | 否    | 否     | 卡片名称。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| displayName<sup>11+</sup> | string               | 否    | 否     | 卡片展示名称。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| displayNameId<sup>11+</sup> | number               | 否    | 否     | 卡片预览时标识卡片名称的ID。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。<br>**说明：** 数值为大于0小于2^32的整数。 |
| description | string               | 否    | 否     | 卡片描述。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| descriptionId<sup>10+</sup>      | number               | 否    | 否     | 卡片描述ID。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。<br>**说明：** 数值为大于0小于2^32的整数。 |
| type        | [FormType](#formtype)             | 否    | 否     | 卡片类型。当前支持JS卡片、ArkTS卡片。<br>**说明：** 当卡片类型为JS时，isDynamic强制为true，transparencyEnabled不生效，jsComponentName为必填项。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| jsComponentName      | string               | 否    | 否     | JS卡片的组件名，仅当卡片类型为JS时有效。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| colorMode<sup>(deprecated)</sup>  | [ColorMode](#colormodedeprecated) | 否    | 否     | 卡片颜色模式。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。<br> **说明：** <br> 从API version 9开始支持，从API version 20开始废弃。无替代接口。 |
| isDefault    | boolean      | 否    | 否     | 卡片是否是默认卡片。<br/>-&nbsp;true：默认卡片。<br/>-&nbsp;false：非默认卡片。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| updateEnabled  | boolean               | 否    | 否     | 卡片是否使能更新。<br/>-&nbsp;true：表示支持周期性刷新。<br/>-&nbsp;false：表示不支持周期性刷新。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| formVisibleNotify  | boolean        | 否    | 否     | 卡片是否使能可见通知。<br/>-&nbsp;true：通知卡片提供方可见状态变化。<br/>-&nbsp;false：不通知卡片提供方可见状态变化。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| scheduledUpdateTime        | string               | 否    | 否     | 卡片更新时间。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| formConfigAbility | string               | 否    | 否     | 卡片配置Ability。指定长按卡片弹出的选择框内，编辑选项所对应的Ability。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| updateDuration        | number       | 否    | 否     | 卡片更新周期。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。<br>**说明：** 数值为[0, 336]的整数。超出范围时抛出异常。 |
| defaultDimension  | number | 否    | 否     | 卡片规格。具体可选规格参考[FormDimension](#formdimension)。  <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。<br>**说明：** 数值为[1, 9]的整数，数值5从API version 9开始支持，从API version 20开始废弃。超出范围时抛出异常。 |
| supportDimensions    | Array&lt;number&gt;      | 否    | 否     | 卡片支持的规格。具体可选规格参考[FormDimension](#formdimension)。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。<br>**说明：** 最大长度为9，数值取值范围[1, 9]的整数的数组，数值5从API version 9开始支持，从API version 20开始废弃。超出范围时抛出异常。 |
| customizeData    | Record&lt;string, string&gt;      | 否    | 否     | 卡片用户数据。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| isDynamic<sup>10+</sup>      | boolean               | 否    | 否     | 卡片是否为动态卡片。<br/>仅ArkTS卡片区分动静态卡片，JS卡片均为动态卡片。<br/>-&nbsp;true：为动态卡片。<br/>-&nbsp;false：为静态卡片。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| transparencyEnabled<sup>11+</sup>      | boolean               | 否    | 否     | 卡片是否支持设置背景透明度。<br/>ArkTS卡片由用户配置决定是否支持，JS卡片均不支持。<br/>-&nbsp;true：表示是透明卡片。<br/>-&nbsp;false：表示不是透明卡片。  <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| supportedShapes<sup>12+</sup>    | Array&lt;number&gt;      | 否    | 否     | 卡片支持的形状。具体可选形状参考[FormShape<sup>12+</sup>](#formshape12) <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br>**说明：** 1代表方形，2代表圆形。 |

## FormType

支持的卡片类型枚举。JS卡片使用Web技术实现，适合简单的展示类卡片；ArkTS卡片使用ArkTS语言开发，支持更丰富的交互和动画效果。开发时应根据卡片复杂度和交互需求选择合适类型。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

| 名称        | 值   | 说明         |
| ----------- | ---- | ------------ |
| JS      | 1    | 卡片类型为JS。使用Web技术开发，功能相对基础，适合简单场景。   |
| eTS     | 2    | 卡片类型为ArkTS。使用ArkTS语言开发，支持丰富的交互和动画，适合复杂场景。 |

## ColorMode<sup>(deprecated)</sup>

卡片主题样式统一跟随系统的颜色模式，卡片支持的颜色模式枚举。

> **说明：**
>
> 从API version 9开始支持，从API version 20开始废弃。无替代接口。

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

| 名称        | 类型                 | 只读    | 可选    | 说明                                                         |
| ----------- | -------- | -------- | -------------------- | ------------------------------------------------------------ |
| formState  | [FormState](#formstate)               | 否    | 否     | 卡片状态，用于标识卡片当前状态（如未知、默认、就绪）。                          |
| want  | [Want](../apis-ability-kit/js-apis-app-ability-want.md)         | 否    | 否     | Want对象，用于承载卡片状态切换时的意图信息。    |

## FormState

卡片状态枚举。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

| 名称        | 值   | 说明         |
| ----------- | ---- | ------------ |
| UNKNOWN    | -1    | 表示未知状态。   |
| DEFAULT     | 0   | 表示默认状态。   |
| READY      | 1   | 表示就绪状态。   |

## FormParam

卡片参数枚举。

**系统能力：** SystemCapability.Ability.Form

| 名称        | 值   | 说明         |
| ----------- | ---- | ------------ |
| IDENTITY_KEY     | 'ohos.extra.param.key.form_identity'    | 卡片标识。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| DIMENSION_KEY      | 'ohos.extra.param.key.form_dimension'  | 卡片规格，规格尺寸参考[FormDimension](#formdimension)。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| NAME_KEY       | 'ohos.extra.param.key.form_name'   | 卡片名称。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| MODULE_NAME_KEY        | 'ohos.extra.param.key.module_name'   | 卡片所属模块名称。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| WIDTH_KEY        | 'ohos.extra.param.key.form_width'   | 卡片宽度。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| HEIGHT_KEY         | 'ohos.extra.param.key.form_height'   | 卡片高度。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| TEMPORARY_KEY          | 'ohos.extra.param.key.form_temporary'   | 临时卡片。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| ABILITY_NAME_KEY   | 'ohos.extra.param.key.ability_name'   | Ability名称。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| BUNDLE_NAME_KEY    | 'ohos.extra.param.key.bundle_name'   | Bundle名称。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| LAUNCH_REASON_KEY<sup>10+</sup>    | 'ohos.extra.param.key.form_launch_reason'   | 卡片创建原因。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| PARAM_FORM_CUSTOMIZE_KEY<sup>10+</sup>    | 'ohos.extra.param.key.form_customize'   | 自定义数据。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| FORM_RENDERING_MODE_KEY<sup>11+</sup>    | 'ohos.extra.param.key.form_rendering_mode'   | 卡片渲染模式。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| HOST_BG_INVERSE_COLOR_KEY<sup>12+</sup>    | 'ohos.extra.param.key.host_bg_inverse_color'   | 卡片使用方的背景反色颜色值。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| FORM_LOCATION_KEY<sup>12+</sup>    | 'ohos.extra.param.key.form_location'   | 卡片位置。 具体可选位置参考[FormLocation](#formlocation20)。|
| FORM_PERMISSION_NAME_KEY<sup>12+</sup> | 'ohos.extra.param.key.permission_name' | 用户授权权限名称。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| FORM_PERMISSION_GRANTED_KEY<sup>12+</sup> | 'ohos.extra.param.key.permission_granted' | 用户是否授权。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| ORIGINAL_FORM_KEY<sup>20+</sup> | 'ohos.extra.param.key.original_form_id' | 用groupId关联的一组卡片，在调整大小时，会先创建新尺寸的卡片，再删除旧尺寸的卡片。新尺寸卡片创建时want参数会通过该key传递旧尺寸卡片的卡片id。<br/>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |
| EDIT_FORM_KEY<sup>22+</sup> | 'ohos.extra.param.key.edit_form_id' | 在半模态页面的卡片编辑中，通过onAddForm回调函数传递该key表示被编辑的卡片id，用来确保预览卡片与被编辑卡片信息同步。如果卡片onAddForm回调函数中携带了该key，则说明当前卡片为半模态页面中的预览卡片，需要基于被编辑卡片来筛选预览卡片内容。  <br/>**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。 |
| UPDATE_FORM_REASON_KEY<sup>24+</sup> | 'ohos.extra.param.key.update_form_reason' | 卡片更新的原因，请参考[FormUpdateReason](#formupdatereason24)。<br/>**原子化服务API：** 从API version 24开始，该接口支持在原子化服务中使用。<br/>**模型约束：** 此接口仅可在Stage模型下使用。 |

## FormDimension

定义卡片尺寸枚举。

**系统能力：** SystemCapability.Ability.Form

| 名称        | 值   | 说明         |
| ----------- | ---- | ------------ |
| Dimension_1_2      | 1   | 1 x 2 form。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| Dimension_2_2      | 2   | 2 x 2 form。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| Dimension_2_4      | 3   | 2 x 4 form。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| Dimension_4_4      | 4   | 4 x 4 form。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| Dimension_2_1<sup>(deprecated)</sup>      | 5   | 2 x 1 form。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。<br>**说明：** 该字段从API version 9开始支持，从API version 20开始废弃。|
| DIMENSION_1_1<sup>11+</sup>      | 6   | 1 x 1 form。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。<br>**说明：** 该尺寸仅在锁屏卡片上生效。|
| DIMENSION_6_4<sup>12+</sup>      | 7   | 6 x 4 form。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| DIMENSION_2_3<sup>18+</sup>      | 8   | 2 x 3 form。<br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。<br>**设备行为差异：** 该字段仅在Wearable上生效，在其他设备类型中无效果。|
| DIMENSION_3_3<sup>18+</sup>      | 9   | 3 x 3 form。<br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。<br>**设备行为差异：** 该字段仅在Wearable上生效，在其他设备类型中无效果。|

## FormShape<sup>12+</sup> 

定义卡片形状枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

| 名称        | 值   | 说明         |
| ----------- | ---- | ------------ |
| RECT        | 1   | 矩形 form。|
| CIRCLE      | 2   | 圆形 form。|

## FormInfoFilter

卡片信息过滤器，仅将符合过滤器内要求的卡片信息返回。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

| 名称        | 类型   | 只读         | 可选         |说明         |
| ----------- | ---- | ------------ | ------------ |------------ |
| moduleName    | string    |否  |是    | 卡片所属模块的名称，用于过滤卡片信息。仅保留含moduleName与提供值相符的卡片信息，未填写时则不通过moduleName进行过滤。   |



## VisibilityType

卡片当前可见类型枚举。表示卡片在宿主界面上的可见状态，当卡片从桌面移入/移出屏幕或切换应用时状态会发生变化，开发者可据此优化卡片刷新策略。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

| 名称        |  值   | 说明         |
| ----------- | ---- | ------------ |
| UNKNOWN<sup>10+</sup> | 0   | 表示卡片为未知。 |
| FORM_VISIBLE | 1   | 表示卡片为可见。卡片在前台显示，会正常接收更新和可见性通知。 |
| FORM_INVISIBLE   | 2   | 表示卡片为不可见。卡片不在前台显示，系统可能暂停更新以节省资源。 |


## LaunchReason<sup>10+</sup>

卡片创建原因枚举。

**系统能力：** SystemCapability.Ability.Form

| 名称        |  值   | 说明         |
| ----------- | ---- | ------------ |
| FORM_DEFAULT | 1   | 表示卡片创建原因为默认创建。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| FORM_SHARE   | 2   | 表示卡片创建原因为共享创建。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| FORM_SIZE_CHANGE<sup>20+</sup>    | 3   | 表示卡片创建原因为尺寸变化。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |

## FormUpdateReason<sup>24+</sup> 

卡片更新原因枚举。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Ability.Form

**原子化服务API：** 从API version 24开始，该接口支持在原子化服务中使用。

| 名称        | 值   | 说明         |
| ----------- | ---- | ------------ |
| UNKNOWN        | -1 | 卡片更新的原因未知。|
| FORM_NODE_REUSE      | 0   | 卡片更新的原因是节点复用。|

## OverflowInfo<sup>20+</sup>

互动卡片动效信息。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

| 名称 | 类型 | 只读 | 可选  | 说明                              |
|-----|-----|------|-----|---------------------------------|
| area     | [Rect](#rect20) | 否 | 否   | 描述互动卡片动效区域范围，以卡片左上角为原点。   |
| duration | number | 否 | 否   | 互动卡片动效持续时长，单位ms。取值为大于0的整数，<!--Del-->针对三方应用，<!--DelEnd-->取值要求不大于3500<!--Del-->，系统应用无此限制<!--DelEnd-->。 |
| useDefaultAnimation | boolean | 否 | 是   | 互动卡片状态切换时是否启动系统提供的默认动效，默认为true。<br/>-&nbsp;true：表示系统提供默认切换动效。<br/>-&nbsp;false：表示系统不提供切换动效，画面直接切换，适合切换时非激活态和激活态UI完全一致的场景。 |

## Rect<sup>20+</sup>

通用矩形区域信息。可用于描述卡片坐标区域、互动卡片动效区域等信息。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

| 名称 | 类型 | 只读 | 可选  | 说明 |
|-----|-----|------|-----|-------|
| left   | number | 否 | 否   | 描述矩形的左上角顶点的 x 坐标，单位：vp，用于定位卡片区域的位置。范围参考[请求参数约束](../../form/arkts-ui-liveform-sceneanimation-development.md#请求参数约束)。|
| top    | number | 否 | 否   | 描述矩形的左上角顶点的 y 坐标，单位：vp，用于定位卡片区域的位置。范围参考[请求参数约束](../../form/arkts-ui-liveform-sceneanimation-development.md#请求参数约束)。|
| width  | number | 否 | 否   | 描述矩形的宽度，单位：vp，用于定义卡片区域的尺寸。范围参考[请求参数约束](../../form/arkts-ui-liveform-sceneanimation-development.md#请求参数约束)。|
| height | number | 否 | 否   | 描述矩形的高度，单位：vp，用于定义卡片区域的尺寸。范围参考[请求参数约束](../../form/arkts-ui-liveform-sceneanimation-development.md#请求参数约束)。|

## FormLocation<sup>20+</sup>

卡片当前位置枚举。

**系统能力：** SystemCapability.Ability.Form

| 名称                         | 值   | 说明                             |
| ---------------------------- | ---- | -------------------------------- |
| DESKTOP                      | 0    | 表示卡片位于桌面。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。               |
| FORM_CENTER                  | 1    | 表示卡片位于桌面的卡片中心。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。     |
| FORM_MANAGER                 | 2    | 表示卡片位于桌面的卡片管理器。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。   |
<!--RP1--><!--RP1End-->

## RunningFormInfo<sup>20+</sup>

已经添加到桌面的卡片信息。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

| 名称        | 类型                 | 只读    | 可选    | 说明                                                         |
| ----------- | -------- | -------- | -------------------- | ------------------------------------------------------------ |
| formId  | string               | 是    | 否     | 卡片唯一标识，用于识别和管理已添加到桌面的卡片实例。                   |
| bundleName  | string               | 是    | 否     | 卡片提供方所属包的Bundle名称，用于定位卡片提供方应用。                   |
| moduleName  | string               | 是    | 否     | 卡片所属模块的名称，用于定位卡片提供方的具体模块。                      |
| abilityName | string               | 是    | 否     | 卡片所属的Ability名称，用于定位卡片提供方的具体Ability组件。                       |
| formName        | string               | 是    | 否     | 卡片名称，用于标识和区分同一模块中的不同卡片。                                 |
| dimension | number               | 是    | 否     | 卡片尺寸，用于标识卡片的大小规格。取值及其对应含义请参考[FormDimension](#formdimension)。<br>**说明：** 取值范围[1, 9]的整数，数值5从API version 9开始支持，从API version 20开始废弃。   |
| formLocation | [FormLocation](#formlocation20)| 是    | 否     | 卡片位置信息，用于标识卡片当前所在的位置（如桌面、卡片中心等）。   |