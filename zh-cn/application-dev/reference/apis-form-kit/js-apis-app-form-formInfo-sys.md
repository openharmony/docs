# @ohos.app.form.formInfo (formInfo)(系统接口)
<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @Qian-Win-->
<!--Designer: @cx983299475-->
<!--Tester: @mahailong123456-->
<!--Adviser: @HelloShuo-->

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

| 名称        | 类型                 | 只读    | 可选    | 说明                                                         |
| ----------- | -------- | -------- | -------------------- | ------------------------------------------------------------ |
| previewImages<sup>18+</sup> | Array&lt;number&gt; | 是 | 是 | 卡片预览图资源ID。<br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。<br>**说明：** 值为正整数的数组。|
| enableBlurBackground<sup>18+</sup>  | boolean               | 是    | 是     | 卡片是否使用模糊背板。<br/>-&nbsp;true：开启模糊背板。<br/>-&nbsp;false：关闭模糊背板。|
| renderingMode<sup>18+</sup>|[RenderingMode](./js-apis-app-form-formInfo-sys.md#renderingmode18)|是|是|卡片渲染模式。|
| resizable<sup>20+</sup> | boolean  | 是    | 是     | 表示是否可以拖拽卡片调整大小。调整值必须在该卡片或者同groupId卡片的supportDimensions配置列表中。<br/>-&nbsp;true：可以调整大小。<br/>-&nbsp;false：不可以调整大小。 |
| groupId<sup>20+</sup> | string     | 是    | 是     | 表示一组卡片的共同id。多张卡片的groupId相同且resizable为true时，多张卡片的supportDimensions配置共享。例如，卡片A和B的groupId相同且resizable均为true，则卡片A可以调整为卡片A和B的supportDimensions配置中的任意尺寸。<br>推荐多张卡片功能相同且需要调整卡片尺寸时配置。 |
| funInteractionParams<sup>20+</sup> | [FunInteractionParams](#funinteractionparams20)     | 是    | 是     | 趣味交互卡片配置参数。主要配置互动卡片激活态时长等参数。 |
| sceneAnimationParams<sup>20+</sup> | [SceneAnimationParams](#sceneanimationparams20)     | 是    | 是     | 场景动效卡片配置参数。主要配置互动卡片触发方式和禁用手势等参数。 |
| isTemplateForm<sup>23+</sup> | boolean  | 是    | 是     | 表示卡片是否是模板卡。<br/>-&nbsp;true：是模板卡。<br/>-&nbsp;false：不是模板卡。 |
| isStandbySupported<sup>23+</sup> | boolean  | 是    | 是     | 卡片是否支持在灵动显示界面展示。<br/>-&nbsp;true：支持灵动显示。<br/>-&nbsp;false：不支持灵动显示。<br>**模型约束：** 此接口仅可在Stage模型下使用。|
| isStandbyAdapted<sup>23+</sup> | boolean  | 是    | 是     | 卡片是否已适配灵动显示规则。<br/>-&nbsp;true：已适配灵动显示。<br/>-&nbsp;false：未适配灵动显示。<br>**模型约束：** 此接口仅可在Stage模型下使用。|
| isPrivacySensitive<sup>23+</sup> | boolean  | 是    | 是     | 卡片是否是隐私敏感卡片。<br/>-&nbsp;true：是隐私敏感卡片。<br/>-&nbsp;false：不是隐私敏感卡片。<br>**模型约束：** 此接口仅可在Stage模型下使用。|
| isFontScaleFollowSystem | boolean  | 否    | 是     | 卡片的字体缩放是否跟随系统，默认值为true。<br/>-&nbsp;true：字体缩放跟随系统。<br/>-&nbsp;false：字体缩放不会跟随系统。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br/>**起始版本：** 26.0.0 |

##  FormParam

卡片参数枚举。

**系统能力：** SystemCapability.Ability.Form

| 名称        | 值   | 说明         |
| ----------- | ---- | ------------ |
| DEVICE_ID_KEY    | 'ohos.extra.param.key.device_id'   | 设备标识。 <br>**系统接口：** 此接口为系统接口。  |
| THEME_KEY    | 'ohos.extra.param.key.form_is_theme'   | 主题标识。 <br>**系统接口：** 此接口为系统接口。  |
| FORM_MANAGER_SHOW_SINGLE_FORM <sup>23+</sup>   | 'ohos.extra.param.key.form_manager_show_single_form'   | 打开卡片管理页是否只显示特定单张卡片 <br/>-&nbsp;true：表示只显示特定单张卡片。<br/>-&nbsp;false：表示显示所有卡片。<br>**系统接口：** 此接口为系统接口。  |
| TEMPLATE_FORM_DETAIL_ID<sup>23+</sup>    | 'ohos.extra.param.key.template_form_detail_id'   | 模板卡片id。 <br>**系统接口：** 此接口为系统接口。  |
| TEMPLATE_FORM_DATA<sup>23+</sup>   | 'ohos.extra.param.key.template_form_data'   | 模板卡片数据。 <br>**系统接口：** 此接口为系统接口。  |
| TEMPLATE_FORM_DISPLAY_NAME<sup>23+</sup>    | 'ohos.extra.param.key.template_form_display_name'   | 模板卡片显示名称。 <br>**系统接口：** 此接口为系统接口。  |
| TEMPLATE_FORM_DESCRIPTION<sup>23+</sup>    | 'ohos.extra.param.key.template_form_description'   | 模板卡片描述。 <br>**系统接口：** 此接口为系统接口。  |
| FORM_FONT_SIZE_SCALE_KEY    | 'ohos.extra.param.key.form_font_size_scale'   | 卡片字体大小缩放键值。 <br>**系统接口：** 此接口为系统接口。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br/>**起始版本：** 26.0.0  |
| FORM_FONT_WEIGHT_SCALE_KEY    | 'ohos.extra.param.key.form_font_weight_scale'   | 卡片字重缩放键值。 <br>**系统接口：** 此接口为系统接口。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br/>**起始版本：** 26.0.0  |

## FormUsageState<sup>11+</sup>

卡片当前使用状态枚举。

**系统能力：** SystemCapability.Ability.Form

**系统接口：** 此接口为系统接口。

| 名称        |  值   | 说明         |
| ----------- | ---- | ------------ |
| USED | 0   | 表示卡片在使用中。 |
| UNUSED | 1   | 表示卡片未被使用。 |

## RunningFormInfo<sup>10+</sup>

已添加的卡片信息，包括使用中的以及未使用的卡片。

**系统能力：** SystemCapability.Ability.Form

**系统接口：** 此接口为系统接口。

| 名称        | 类型                 | 只读    | 可选    | 说明                                                         |
| ----------- | -------- | -------- | -------------------- | ------------------------------------------------------------ |
| hostBundleName  | string               | 是    | 否     | 使用方卡片所属包的Bundle名称。                   |
| visibilityType  | [VisibilityType](js-apis-app-form-formInfo.md#visibilitytype)               | 是    | 否     | 卡片当前可见类型枚举。                   |
| formUsageState<sup>11+</sup> | [FormUsageState](#formusagestate11)         | 是    | 否     | 卡片当前使用状态枚举。默认值为FormUsageState.USED |
| formDescription<sup>11+</sup> | string         | 是    | 否     | 提供方卡片配置文件中的描述信息。   |
| extraData<sup>12+</sup> | Record<string, Object> | 是    | 是     | 卡片的额外数据。   |

## formProviderFilter<sup>10+</sup>

卡片提供方信息。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Ability.Form

**系统接口：** 此接口为系统接口。

| 名称        | 类型                 | 只读    | 可选    | 说明                                                         |
| ----------- | -------- | -------- | -------------------- | ------------------------------------------------------------ |
| bundleName  | string               | 否    | 否     | 提供方卡片所属包的Bundle名称。  |
| formName    | string               | 否    | 是     | 卡片名称。                     |
| moduleName  | string               | 否    | 是     | 卡片所属模块的名称。        |
| abilityName | string               | 否    | 是     | 卡片所属的Ability名称。        |
| isUnusedIncluded<sup>11+</sup> | boolean               | 否    | 是     | 是否包含未使用的卡片。<br/>-&nbsp;true：包含未使用的卡片。<br/>-&nbsp;false：不包含未使用的卡片。<br/>默认值：false。        |


## FormInfoFilter

卡片信息过滤器，仅将符合过滤器内要求的卡片信息返回。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

| 名称        | 类型   | 必填         |说明         |
| ----------- | ---- | ------------ |------------ |
| bundleName<sup>12+</sup>    | string    |否    | 选填，仅保留含bundleName与提供值相符的卡片信息，未填写时则不通过bundleName进行过滤。<br>**系统接口：** 此接口为系统接口。  |
| supportedDimensions<sup>12+</sup> | Array&lt;number&gt; |否    | 选填，仅保留含supportedDimensions提供值相符的卡片信息，未填写时则不通过supportedDimensions进行过滤。<br>**系统接口：** 此接口为系统接口。<br>**说明：** 最大长度为9，数值取值范围[1, 9]的整数的数组，数值5从API version 9开始支持，从API version 20开始废弃。<br>具体规格参考 [formInfo.FormDimension](js-apis-app-form-formInfo.md#formdimension)。  |
| supportedShapes<sup>12+</sup>  | Array&lt;number&gt; |否    | 选填，仅保留含supportedShapes提供值相符的卡片信息，未填写时则不通过supportedShapes进行过滤。<br>**系统接口：** 此接口为系统接口。<br>**说明：** 只有1和2两个值。1代表方形，2代表圆形。   |

## FormLocation<sup>12+</sup>

卡片当前位置枚举。

**系统能力**：SystemCapability.Ability.Form

| 名称                         | 值   | 说明                             |
| ---------------------------- | ---- | -------------------------------- |
| OTHER                        | -1   | 表示卡片位于其他位置。           |
| DESKTOP                      | 0    | 表示卡片位于桌面。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。               |
| FORM_CENTER                  | 1    | 表示卡片位于桌面的卡片中心。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。     |
| FORM_MANAGER                 | 2    | 表示卡片位于桌面的卡片管理器。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。   |
| NEGATIVE_SCREEN              | 3    | 表示卡片位于负一屏。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。             |
| FORM_CENTER_NEGATIVE_SCREEN  | 4    | 表示卡片位于负一屏的服务中心。   |
| FORM_MANAGER_NEGATIVE_SCREEN | 5    | 表示卡片位于负一屏的卡片管理器。 |
| SCREEN_LOCK                  | 6    | 表示卡片位于锁屏。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。               |
| AI_SUGGESTION                | 7    | 表示卡片位于AI智慧助手推荐区。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。     |
| STANDBY<sup>23+</sup>        | 8    | 表示卡片位于灵动显示界面。<br>**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。<br>**模型约束：** 此接口仅可在Stage模型下使用。 |

## PublishFormResult<sup>12+</sup>

发布卡片加桌结果。

**系统能力：** SystemCapability.Ability.Form

**模型约束：** 此接口仅可在Stage模型下使用。

| 名称    | 类型                                          | 只读 | 可选 | 说明                       |
| ------- | --------------------------------------------- | ---- | ---- | -------------------------- |
| code    | [PublishFormErrorCode](#publishformerrorcode12) | 否   | 否   | 发布卡片加桌错误码。       |
| message | string                                        | 否   | 否   | 设置卡片加桌结果返回信息。 |

## PublishFormErrorCode<sup>12+</sup>

发布卡片加桌错误码枚举。

**系统能力**：SystemCapability.Ability.Form

**模型约束：** 此接口仅可在Stage模型下使用。

| 名称           | 值   | 说明                             |
| -------------- | ---- | -------------------------------- |
| SUCCESS        | 0    | 表示卡片加桌成功。               |
| NO_SPACE       | 1    | 表示没有空间添加卡片。           |
| PARAM_ERROR    | 2    | 表示参数检查失败。               |
| INTERNAL_ERROR | 3    | 表示卡片处理过程中出现内部错误。 |

## RenderingMode<sup>18+</sup>

卡片支持的渲染模式枚举。

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
| formId       | string  | 否  | 否  | 卡片id。|
| isOverflow   | boolean | 否  | 否  | 动效请求类型标记，true 表示互动卡片请求触发动效，false 表示互动卡片请求取消动效。|
| overflowInfo | [formInfo.OverflowInfo](js-apis-app-form-formInfo.md#overflowinfo20) | 否 | 是 | 动效请求参数信息，包括动效时长（单位：ms）和动效区域（动效区域范围以卡片左上角为原点，单位为vp），默认值为空。 |

## ChangeSceneAnimationStateRequest<sup>20+</sup>

互动卡片状态切换请求信息。互动卡片状态分为激活态和非激活态，非激活态下，互动卡片同普通卡片一致；激活态下，互动卡片支持拉起卡片提供方所开发的LiveFormExtensionAbility进程，实现互动卡片动效。

**系统能力：** SystemCapability.Ability.Form

**系统接口：** 此接口为系统接口。

| 名称 | 类型 | 只读 | 可选 | 说明 |
|-----|-----|-----|-----|----------------------------------------|
| formId | string | 否 | 否 | 卡片id。                                  |
| state  | number | 否 | 否 | 状态切换请求类型标记：1 表示请求切换为激活态，0 表示请求切换为非激活态。 |

## FunInteractionParams<sup>20+</sup>

趣味交互卡片配置参数。

**系统能力：** SystemCapability.Ability.Form

**系统接口：** 此接口为系统接口。

| 名称 | 类型 | 只读 | 可选 | 说明                                                                                                                                   |
|-----|-----|----|-----|--------------------------------------------------------------------------------------------------------------------------------------|
| abilityName | string | 否  | 是   | 趣味交互场景 extensionAbility 名称，默认为空。 |
| targetBundleName  | string | 否  | 否   | 趣味交互场景[主包包名](https://developer.huawei.com/consumer/cn/doc/quickApp-Guides/quickgame-independent-subpackage-0000002076341729)。        |
| subBundleName  | string | 否  | 否   | 趣味交互场景[独立分包名](https://developer.huawei.com/consumer/cn/doc/quickApp-Guides/quickgame-independent-subpackage-0000002076341729)。 |
| keepStateDuration  | number | 否  | 是   | 趣味交互场景无交互时，激活态保持时长。默认值为10000，单位ms。取值为(0,60000]的整数，超过取值范围则取最大值60000。<br/>**说明：** 在API版本26.0.0之前该字段为(0,10000]的整数，超过取值范围则取默认值10000。 |

## SceneAnimationParams<sup>20+</sup>

场景动效卡片配置参数。

**系统能力：** SystemCapability.Ability.Form

**系统接口：** 此接口为系统接口。

| 名称 | 类型 | 只读 | 可选 | 说明                                                                                                                                              |
|-----|-----|------|----|-------------------------------------------------------------------------------------------------------------------------------------------------|
| abilityName | string | 否 | 否  | 场景动效 extensionAbility 名称，如卡片提供方LiveFormExtensionAbility名称。                                     |
| disabledDesktopBehaviors | string | 否 | 是  | 支持的取值包括SWIPE_DESKTOP（滑动桌面）、PULL_DOWN_SEARCH（下拉全搜）、LONG_CLICK（长按）、DRAG（拖动）。可以取值一个或多个，不同行为通过 \| 拼接，例如SWIPE_DESKTOP\|PULL_DOWN_SEARCH。缺省表示不禁用任何行为。 |
| triggerTypes    | Array&lt;[SceneAnimationTriggerType](#sceneanimationtriggertype)&gt;      | 否    | 是     | 场景动效卡片触发类型。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br/>**起始版本：** 26.0.0  |

## GetFormRectInfoCallback<sup>20+</sup>

type GetFormRectInfoCallback = (formId: string) => Promise&lt;formInfo.Rect&gt;

卡片位置、尺寸查询回调。使用Promise异步回调。

**系统能力：** SystemCapability.Ability.Form

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|-----|-----|------|------------------|
| formId | string | 是 | 卡片Id。|

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[formInfo.Rect](js-apis-app-form-formInfo.md#rect20)&gt; | Promise对象，返回卡片相对屏幕左上角的位置信息和卡片尺寸信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                                                  |
|-------|-----------------------------------------------------------------------------------------------------------|
| 202   | The application is not a system application.                                                              |

**示例：**

```ts
import { formInfo } from '@kit.FormKit';

// 卡片使用方需要对查询请求进行处理，计算并返回卡片尺寸、位置信息
let getFormRectInfoCallback: formInfo.GetFormRectInfoCallback =
  (formId: string): Promise<formInfo.Rect> => {
    return new Promise<formInfo.Rect>((resolve: (value: formInfo.Rect) => void) => {
      console.info(`formId is ${formId}`);
      let formRect: formInfo.Rect = {
        left: 0,
        top: 0,
        width: 0,
        height: 0
      };
      resolve(formRect);
    })
  };
```

## TemplateFormDetailInfo<sup>23+</sup>

模板卡对应的真实卡片信息。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Ability.Form

**系统接口：** 此接口为系统接口。

| 名称 | 类型 | 只读 | 可选 | 说明               |
|-----|-----|------|----|---------------------------------|
| bundleName | string | 否 | 否  | 卡片所属包的Bundle名称。           |
| moduleName | string | 否 | 否  | 卡片所属模块的名称。 |
| abilityName | string | 否 | 否  | 卡片所属的Ability名称。 |
| formName | string | 否 | 否  | 卡片名称。 |
| dimension | string | 否 | 否  | 卡片规格 |
| detailId | string | 否 | 否  | 卡片信息id |
| displayName | string | 否 | 否  | 卡片展示名称 |
| description | string | 否 | 否  | 卡片描述 |

## TemplateFormDetailInfoCallback<sup>23+</sup>

type TemplateFormDetailInfoCallback =  (info: Array\<TemplateFormDetailInfo>) => void

模板卡真实卡片信息回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Ability.Form

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|-----|-----|------|------------------|
| info | Array\<[TemplateFormDetailInfo](#templateformdetailinfo23)>| 是 | 模板卡真实卡片信息。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                                                  |
|-------|-----------------------------------------------------------------------------------------------------------|
| 202   | The application is not a system application.                                                              |

**示例：**

```ts
import { formInfo } from '@kit.FormKit';

let templateFormDetailInfoCallback: formInfo.TemplateFormDetailInfoCallback =
  (info: Array<formInfo.TemplateFormDetailInfo>): void => {
    console.info('template form detail info callback success.');
  };
```

## PublishFormCrossBundleInfo<sup>23+</sup>

跨应用加卡管控信息。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Ability.Form

**系统接口：** 此接口为系统接口。

| 名称 | 类型 | 只读 | 可选 | 说明       |
|-----|-----|------|----|------------------------------------------------|
| callerBundleName | string | 否 | 否  | 跨应用加卡拉起方的Bundle名称。           |
| targetBundleName | string | 否 | 否  | 跨应用加卡被拉起方的Bundle名称。 |
| targetTemplateFormDetailId | string | 否 | 否  | 被添加的真实卡片信息id |

## PublishFormCrossBundleControlCallback<sup>23+</sup>

type PublishFormCrossBundleControlCallback = (info: PublishFormCrossBundleInfo) => boolean

跨应用加卡管控回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Ability.Form

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|-----|-----|------|------------------|
| info | [PublishFormCrossBundleInfo](#publishformcrossbundleinfo23)| 是 | 跨应用加卡管控信息。|

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 跨应用加卡管控结果。<br/>-&nbsp;true：表示管控通过。<br/>-&nbsp;false：表示管控未通过。 |

**示例：**

```ts
import { formInfo } from '@kit.FormKit';

let publishFormCrossBundleControlCallback: formInfo.PublishFormCrossBundleControlCallback =
  (info: formInfo.PublishFormCrossBundleInfo): boolean => {
    console.info('publish form cross bundle info callback success.');
    return true;
  };
```

## SceneAnimationTriggerType

场景动效卡片触发类型枚举。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Ability.Form

**系统接口：** 此接口为系统接口。

| 名称        |  值   | 说明         |
| ----------- | ---- | ------------ |
| SHAKE | 1   | 摇一摇。 |

## GetWantParamsCallback

type GetWantParamsCallback = (formInfo: Array&lt;FormInfo&gt;) => Array&lt;Record&lt;string, Object&gt;&gt;

获取卡片参数回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Ability.Form

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|------|------|----|------|
| formInfo | Array&lt;[FormInfo](#forminfo)&gt; | 是 | 卡片信息列表。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Array&lt;Record&lt;string, Object&gt;&gt; | 返回卡片参数列表，与输入的卡片信息列表一一对应。 |

**示例：**

```ts
import { formInfo } from '@kit.FormKit';

let getWantParamsCallback: formInfo.GetWantParamsCallback =
  (formInfo: Array<formInfo.FormInfo>): Array<Record<string, Object>> => {
    console.info('get want params callback, form count: ' + formInfo.length);
    let wantParamsList: Array<Record<string, Object>> = [];
    for (let i = 0; i < formInfo.length; i++) {
      let params: Record<string, Object> = {
        'key': 'value'
      };
      wantParamsList.push(params);
    }
    return wantParamsList;
  };
```

## FormCustomConfig

卡片自定义配置信息。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Ability.Form

**系统接口：** 此接口为系统接口。

| 名称 | 类型 | 只读 | 可选 | 说明 |
|-----|-----|------|----|------|
| bundleName | string | 否 | 否 | 卡片所属包的Bundle名称。 |
| moduleName | string | 否 | 否 | 卡片所属模块的名称。 |
| abilityName | string | 否 | 否 | 卡片所属的Ability名称。 |
| formName | string | 否 | 否 | 卡片名称。 |
| isShowInFormCenter | boolean | 否 | 否 | 卡片是否在卡片中心展示。<br/>-&nbsp;true：在卡片中心展示。<br/>-&nbsp;false：不在卡片中心展示。 |
| relatedBundleName | string | 否 | 否 | 关联的Bundle名称。 |
| isRepeatAdditionSupported | boolean | 否 | 否 | 卡片是否支持重复添加。<br/>-&nbsp;true：支持重复添加。<br/>-&nbsp;false：不支持重复添加。 |

## UpdateFormsConfigCallback

type UpdateFormsConfigCallback = (configInfo: Array&lt;FormCustomConfig&gt;) => void

卡片配置更新回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Ability.Form

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|------|------|----|------|
| configInfo | Array&lt;[FormCustomConfig](#formcustomconfig)&gt; | 是 | 卡片配置信息列表。 |

**示例：**

```ts
import { formInfo } from '@kit.FormKit';

let updateFormsConfigCallback: formInfo.UpdateFormsConfigCallback =
  (configInfo: Array<formInfo.FormCustomConfig>): void => {
    console.info('update forms config callback, config count: ' + configInfo.length);
  };
```

## DeleteFormsCallback

type DeleteFormsCallback = (formIds: Array&lt;string&gt;) => void

卡片删除回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Ability.Form

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|------|------|----|------|
| formIds | Array&lt;string&gt; | 是 | 被删除的卡片标识列表。 |

**示例：**

```ts
import { formInfo } from '@kit.FormKit';

let deleteFormsCallback: formInfo.DeleteFormsCallback =
  (formIds: Array<string>): void => {
    console.info('delete forms callback, form count: ' + formIds.length);
  };
```