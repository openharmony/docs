# @ohos.app.form.formInfo (formInfo)

The **formInfo** module provides types and enums related to the widget information and state.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import formInfo from '@ohos.app.form.formInfo';
```

## FormInfo

Defines the widget information.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

| Name       | Type                | Readable   | Writable   | Description                                                        |
| ----------- | -------- | -------- | -------------------- | ------------------------------------------------------------ |
| bundleName  | string               | Yes   | No    | Name of the bundle to which the widget belongs.                  |
| moduleName  | string               | Yes   | No    | Name of the module to which the widget belongs.                     |
| abilityName | string               | Yes   | No    | Name of the ability to which the widget belongs.                      |
| name        | string               | Yes   | No    | Name of an application or ability.                                |
| displayName<sup>11+</sup> | string               | Yes   | No    | Widget name.                                |
| displayNameId<sup>11+</sup> | number               | Yes   | No    | ID of the widget name displayed during widget preview.               |
| description | string               | Yes   | No    | Description of the widget.  |
| descriptionId<sup>10+</sup>      | number               | Yes   | No    | ID of the widget description.              |
| type        | [FormType](#formtype)             | Yes   | No    | Type of the widget. Currently, JS and ArkTS widgets are supported.|
| jsComponentName      | string               | Yes   | No    | Name of the component used in the JS widget.              |
| colorMode  | [ColorMode](#colormode) | Yes   | No    | Color mode of the widget.                                      |
| isDefault    | boolean      | Yes   | No    | Whether the widget is the default one.                             |
| updateEnabled  | boolean               | Yes   | No    | Whether the widget is updatable.                   |
| formVisibleNotify  | boolean        | Yes   | No    | Whether to send a notification when the widget is visible.           |
| scheduledUpdateTime        | string               | Yes   | No    | Time when the widget was updated.    |
| formConfigAbility | string               | Yes   | No    | Configuration ability of the widget, that is, the ability corresponding to the option in the selection box displayed when the widget is long pressed.  |
| updateDuration        | number       | Yes   | No    | Update period of the widget.|
| defaultDimension  | number | Yes   | No    | Widget specifications.                                      |
| supportDimensions    | Array&lt;number&gt;      | Yes   | No    | Dimensions supported by the widget. For details, see [FormDimension](#formdimension).  |
| customizeData    | Record\<string, string>      | Yes   | No    | Custom data of the widget.        |
| isDynamic<sup>10+</sup>      | boolean               | Yes   | No    | Whether the widget is a dynamic widget.<br>ArkTS widgets are classified into dynamic and static widgets. JS widgets are all dynamic widgets.              |
| transparencyEnabled<sup>11+</sup>      | boolean               | Yes   | No    | Whether the widget supports the setting of the background transparency.<br>For ArkTS widgets, the support for the background transparency setting depends on user configurations. For JS widgets, the background transparency setting is not supported.              |

## FormType

Enumerates the widget types.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

| Name       | Value  | Description        |
| ----------- | ---- | ------------ |
| JS      | 1    | JS widget.  |
| eTS     | 2    | ArkTS widget.|

## ColorMode

Enumerates the color modes supported by the widget.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

| Name       | Value  | Description        |
| ----------- | ---- | ------------ |
| MODE_AUTO   | -1    | Auto mode.  |
| MODE_DARK    | 0   | Dark mode.  |
| MODE_LIGHT     | 1   | Light mode.  |

## FormStateInfo

Describes the widget state information.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

| Name       | Type                | Readable   | Writable   | Description                                                        |
| ----------- | -------- | -------- | -------------------- | ------------------------------------------------------------ |
| formState  | [FormState](#formstate)               | Yes   | No    | Widget state.                         |
| want  | [Want](../apis-ability-kit/js-apis-app-ability-want.md)         | Yes   | No    | Want text.   |

##  FormState

Enumerates the widget states.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

| Name       | Value  | Description        |
| ----------- | ---- | ------------ |
| UNKNOWN    | -1    | Unknown state.  |
| DEFAULT     | 0   | Default state.  |
| READY      | 1   | Ready state.  |

##  FormParam

Enumerates the widget parameters.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

| Name       | Value  | Description        |
| ----------- | ---- | ------------ |
| IDENTITY_KEY     | 'ohos.extra.param.key.form_identity'    | Widget ID.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| DIMENSION_KEY      | 'ohos.extra.param.key.form_dimension'  | Widget dimension.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| NAME_KEY       | 'ohos.extra.param.key.form_name'   | Widget name.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| MODULE_NAME_KEY        | 'ohos.extra.param.key.module_name'   | Name of the module to which the widget belongs.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| WIDTH_KEY        | 'ohos.extra.param.key.form_width'   | Widget width.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| HEIGHT_KEY         | 'ohos.extra.param.key.form_height'   | Widget height.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| TEMPORARY_KEY          | 'ohos.extra.param.key.form_temporary'   | Temporary widget.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| ABILITY_NAME_KEY   | 'ohos.extra.param.key.ability_name'   | Ability name.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| BUNDLE_NAME_KEY    | 'ohos.extra.param.key.bundle_name'   | Bundle name.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| LAUNCH_REASON_KEY<sup>10+</sup>    | 'ohos.extra.param.key.form_launch_reason'   | Reason for creating the widget.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| PARAM_FORM_CUSTOMIZE_KEY<sup>10+</sup>    | 'ohos.extra.param.key.form_customize'   | Custom data.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| FORM_RENDERING_MODE_KEY<sup>11+</sup>    | 'ohos.extra.param.key.form_rendering_mode'   | Widget rendering mode.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| HOST_BG_INVERSE_COLOR_KEY<sup>12+</sup>    | 'ohos.extra.param.key.host_bg_inverse_color'   | Inverse background color of the widget client.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

##  FormDimension

Enumerates the widget dimensions.

**System capability**: SystemCapability.Ability.Form

| Name       | Value  | Description        |
| ----------- | ---- | ------------ |
| Dimension_1_2      | 1   | 1 x 2.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| Dimension_2_2      | 2   | 2 x 2.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| Dimension_2_4      | 3   | 2 x 4.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| Dimension_4_4      | 4   | 4 x 4.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| Dimension_2_1      | 5   | 2 x 1.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| DIMENSION_1_1<sup>11+<sup>      | 6   | 1 x 1.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| DIMENSION_6_4<sup>12+<sup>      | 7   | 6 x 4.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|


## FormInfoFilter

Defines the widget information filter. Only the widget information that meets the filter is returned.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

| Name       | Type  | Mandatory        |Description        |
| ----------- | ---- | ------------ |------------ |
| bundleName    | string    |No   | Only the information about the widget whose **bundleName** is the same as the provided value is returned.<br>If this parameter is not set, **bundleName** is not used for filtering.  |
| moduleName    | string    |No   | Only the information about the widget whose **moduleName** is the same as the provided value is returned.<br>If this parameter is not set, **moduleName** is not used for filtering.  |
| supportedDimensions | Array<number> |No   | Only the information about the widget whose **supportedDimensions** is the same as the provided value is returned.<br>If this parameter is not set, **supportedDimensions** is not used for filtering.  |

## VisibilityType

Enumerates the visibility types of the widget.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

| Name       |  Value  | Description        |
| ----------- | ---- | ------------ |
| UNKNOWN<sup>10+</sup> | 0   | The visibility type of the widget is unknown.|
| FORM_VISIBLE | 1   | The widget is visible.|
| FORM_INVISIBLE   | 2   | The widget is invisible.|


## LaunchReason<sup>10+</sup>

Enumerates the reasons for creating a widget.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

| Name       |  Value  | Description        |
| ----------- | ---- | ------------ |
| FORM_DEFAULT | 1   | The widget is created by default.|
| FORM_SHARE   | 2   | The widget is created for sharing.|
