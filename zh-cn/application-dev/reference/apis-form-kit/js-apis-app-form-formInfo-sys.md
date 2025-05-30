# @ohos.app.form.formInfo (formInfo)(系统接口)

formInfo模块提供了卡片信息和状态等相关类型和枚举。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 当前页面仅包含本模块的系统接口，其他公共接口参见[@ohos.app.form.formInfo (formInfo)](./js-apis-app-form-formInfo.md)。

## 导入模块

```ts
import { formInfo } from '@kit.FormKit';
```

## FormInfo

卡片配置信息。

**系统能力：** SystemCapability.Ability.Form

| 名称        | 类型                 | 可读    | 可写    | 说明                                                         |
| ----------- | -------- | -------- | -------------------- | ------------------------------------------------------------ |
| previewImages<sup>18+</sup> | Array&lt;number&gt; | 是 | 否 | 卡片预览图资源ID。<br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。|
| enableBlurBackground<sup>18+</sup>  | boolean               | 是    | 否     | 卡片是否使用模糊背板。 |
| renderingMode<sup>18+</sup>|[RenderingMode](./js-apis-app-form-formInfo-sys.md#renderingmode18)|是|否|卡片渲染模式。|


##  FormParam

卡片参数枚举。

**系统能力：** SystemCapability.Ability.Form

| 名称        | 值   | 说明         |
| ----------- | ---- | ------------ |
| DEVICE_ID_KEY    | 'ohos.extra.param.key.device_id'   | 设备标识。 <br>**系统接口：** 此接口为系统接口。  |

## FormUsageState

卡片当前使用状态枚举。

**系统能力：** SystemCapability.Ability.Form

**系统接口：** 此接口为系统接口。

| 名称        |  值   | 说明         |
| ----------- | ---- | ------------ |
| USED<sup>11+</sup> | 0   | 表示卡片在使用中。 |
| UNUSED<sup>11+</sup> | 1   | 表示卡片未被使用。 |

## RunningFormInfo<sup>10+</sup>

已添加的卡片信息，包括使用中的以及未使用的卡片。

**系统能力：** SystemCapability.Ability.Form

**系统接口：** 此接口为系统接口。

| 名称        | 类型                 | 可读    | 可写    | 说明                                                         |
| ----------- | -------- | -------- | -------------------- | ------------------------------------------------------------ |
| formId  | string               | 是    | 否     | 卡片标识。                   |
| bundleName<sup>10+</sup>  | string               | 是    | 否     | 提供方卡片所属包的Bundle名称。                   |
| hostBundleName  | string               | 是    | 否     | 使用方卡片所属包的Bundle名称。                   |
| visibilityType  | [VisibilityType](js-apis-app-form-formInfo.md#visibilitytype)               | 是    | 否     | 卡片当前可见类型枚举。                   |
| moduleName<sup>10+</sup>  | string               | 是    | 否     | 卡片所属模块的模块名称。                      |
| abilityName<sup>10+</sup> | string               | 是    | 否     | 卡片所属的Ability名称。                       |
| formName<sup>10+</sup>        | string               | 是    | 否     | 卡片名称。                                 |
| dimension | number               | 是    | 否     | 卡片规格。   |
| formUsageState<sup>11+</sup> | [FormUsageState](#formusagestate)         | 是    | 否     | 卡片当前使用状态枚举。   |
| formDescription<sup>11+</sup> | string         | 是    | 否     | 提供方卡片配置文件中的描述信息。   |
| formLocation<sup>12+</sup> | [FormLocation](#formlocation12)| 是    | 否     | 卡片位置信息。   |

## formProviderFilter<sup>10+</sup>

卡片提供方信息。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Ability.Form

**系统接口：** 此接口为系统接口。

| 名称        | 类型                 | 可读    | 可写    | 说明                                                         |
| ----------- | -------- | -------- | -------------------- | ------------------------------------------------------------ |
| bundleName  | string               | 是    | 是     | 提供方卡片所属包的Bundle名称。  |
| formName    | string               | 是    | 是     | 卡片名称。                     |
| moduleName  | string               | 是    | 是     | 卡片所属模块的模块名称。        |
| abilityName | string               | 是    | 是     | 卡片所属的Ability名称。        |
| isUnusedIncluded<sup>11+</sup> | boolean               | 是    | 是     | 是否包含未使用的卡片。<br/>-&nbsp;true：包含未使用的卡片。<br/>-&nbsp;false：不包含未使用的卡片。<br/>默认值：false。        |


## FormInfoFilter

卡片信息过滤器，仅将符合过滤器内要求的卡片信息返回。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

| 名称        | 类型   | 必填         |说明         |
| ----------- | ---- | ------------ |------------ |
| bundleName    | string    |否    | 选填，仅保留含bundleName与提供值相符的卡片信息，未填写时则不通过bundleName进行过滤。<br>**系统接口：** 此接口为系统接口。  |
| supportedDimensions | Array\<number\> |否    | 选填，仅保留含supportedDimensions提供值相符的卡片信息，未填写时则不通过supportedDimensions进行过滤。<br>**系统接口：** 此接口为系统接口。  |
| supportedShapes<sup>12+</sup>  | Array\<number\> |否    | 选填，仅保留含supportedShapes提供值相符的卡片信息，未填写时则不通过supportedShapes进行过滤。<br>**系统接口：** 此接口为系统接口。   |

## FormLocation<sup>12+</sup>

卡片当前位置枚举。

**系统能力**：SystemCapability.Ability.Form

| 名称                         | 值   | 说明                             |
| ---------------------------- | ---- | -------------------------------- |
| OTHER                        | -1   | 表示卡片位于其他位置。           |
| DESKTOP                      | 0    | 表示卡片位于桌面。               |
| FORM_CENTER                  | 1    | 表示卡片位于桌面的卡片中心。     |
| FORM_MANAGER                 | 2    | 表示卡片位于桌面的卡片管理器。   |
| NEGATIVE_SCREEN              | 3    | 表示卡片位于负一屏。             |
| FORM_CENTER_NEGATIVE_SCREEN  | 4    | 表示卡片位于负一屏的服务中心。   |
| FORM_MANAGER_NEGATIVE_SCREEN | 5    | 表示卡片位于负一屏的卡片管理器。 |
| SCREEN_LOCK                  | 6    | 表示卡片位于锁屏。               |
| AI_SUGGESTION                | 7    | 表示卡片位于小艺建议推荐区。     |

## PublishFormResult<sup>12+</sup>

发布卡片加桌结果。

**系统能力：** SystemCapability.Ability.Form

| 名称    | 类型                                          | 可读 | 可写 | 说明                       |
| ------- | --------------------------------------------- | ---- | ---- | -------------------------- |
| code    | [PublishFormErrorCode](#publishformerrorcode12) | 是   | 否   | 发布卡片加桌错误码。       |
| message | string                                        | 是   | 否   | 设置卡片加桌结果返回信息。 |

## PublishFormErrorCode<sup>12+</sup>

发布卡片加桌错误码枚举。

**系统能力**：SystemCapability.Ability.Form

| 名称           | 值   | 说明                             |
| -------------- | ---- | -------------------------------- |
| SUCCESS        | 0    | 表示卡片加桌成功。               |
| NO_SPACE       | 1    | 表示没有空间添加卡片。           |
| PARAM_ERROR    | 2    | 表示参数检查失败。               |
| INTERNAL_ERROR | 3    | 表示卡片处理过程中出现内部错误。 |

## RenderingMode<sup>18+</sup>

卡片支持的渲染模式枚举。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

| 名称        | 值   | 说明         |
| ----------- | ---- | ------------ |
| AUTO_COLOR    | 0    | 表示自动模式。   |
| FULL_COLOR     | 1   | 表示全色模式。   |
| SINGLE_COLOR      | 2   | 表示单色模式。   |

## OverflowRequest<sup>20+</sup>

互动卡片动效请求信息。

**系统能力：** SystemCapability.Ability.Form

**系统接口：** 此接口为系统接口。

| 名称 | 类型 | 只读 | 可选 | 说明 |
|-----|-----|----|----|-----|
| formId       | string  | 是  | 否  | 卡片id。|
| isOverflow   | boolean | 是  | 否  | 动效请求类型标记，true 表示互动卡片请求触发动效，false 表示互动卡片请求取消动效。|
| overflowInfo | [formInfo.OverflowInfo](js-apis-app-form-formInfo.md#overflowinfo20) | 是 | 是 | 动效请求参数信息，包括溢出动效时长（单位：ms）和溢出动效区域（溢出动效区域范围以卡片左上角为原点，单位为vp），默认值为空。 |

## ChangeSceneAnimationStateRequest<sup>20+</sup>

互动卡片状态切换请求信息。互动卡片状态分为激活态和非激活态，非激活态下，互动卡片同普通卡片一致；激活态下，互动卡片支持拉起卡片提供方所开发的LiveFormExtensionAbility进程，实现互动卡片动效。

**系统能力：** SystemCapability.Ability.Form

**系统接口：** 此接口为系统接口。

| 名称 | 类型 | 只读 | 可选 | 说明 |
|-----|-----|-----|-----|----------------------------------------|
| formId | string | 是 | 否 | 卡片id。                                  |
| state  | number | 是 | 否 | 状态切换请求类型标记：1 表示请求切换为激活态，0 表示请求切换为非激活态。 |

## FunInteractionParams<sup>20+</sup>

趣味交互卡片配置参数。

**系统能力：** SystemCapability.Ability.Form

**系统接口：** 此接口为系统接口。

| 名称 | 类型 | 只读 | 可选 | 说明                                                                                                                                   |
|-----|-----|----|-----|--------------------------------------------------------------------------------------------------------------------------------------|
| abilityName | string | 是  | 是   | 趣味交互场景 extensionAbility 名称，默认为空。 |
| targetBundleName  | string | 是  | 否   | 趣味交互场景[主包包名](https://developer.huawei.com/consumer/cn/doc/quickApp-Guides/quickgame-independent-subpackage-0000002076341729)。        |
| subBundleName  | string | 是  | 否   | 趣味交互场景趣味交互场景[独立分包名](https://developer.huawei.com/consumer/cn/doc/quickApp-Guides/quickgame-independent-subpackage-0000002076341729)。 |
| keepStateDuration  | number | 是  | 是   | 趣味交互场景无交互时，激活态保持时长。默认值为10000，单位ms。取值为[0,10000]的整数，超过取值范围则取默认值10000。 |

## SceneAnimationParams<sup>20+</sup>

场景动效卡片配置参数。

**系统能力：** SystemCapability.Ability.Form

**系统接口：** 此接口为系统接口。

| 名称 | 类型 | 只读 | 可选 | 说明                                                                                                                                              |
|-----|-----|------|----|-------------------------------------------------------------------------------------------------------------------------------------------------|
| abilityName | string | 是 | 否  | 场景动效 extensionAbility 名称，如卡片提供方LiveFormExtensionAbility名称。                                     |
| disabledDesktopBehaviors | string | 是 | 是  | 支持的取值包括SWIPE_DESKTOP（滑动桌面）、PULL_DOWN_SEARCH（下拉全搜）、LONG_CLICK（长按）、DRAG（拖动）。可以取值一个或多个，不同行为通过 \| 拼接，例如SWIPE_DESKTOP\|PULL_DOWN_SEARCH。缺省表示不禁用任何行为。 |