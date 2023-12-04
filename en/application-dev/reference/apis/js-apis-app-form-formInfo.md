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

Describes widget information.

**System capability**: SystemCapability.Ability.Form

| Name       | Type                | Readable   | Writable   | Description                                                        |
| ----------- | -------- | -------- | -------------------- | ------------------------------------------------------------ |
| bundleName  | string               | Yes   | No    | Name of the bundle to which the widget belongs.                  |
| moduleName  | string               | Yes   | No    | Name of the module to which the widget belongs.                     |
| abilityName | string               | Yes   | No    | Name of the ability to which the widget belongs.                      |
| name        | string               | Yes   | No    | Widget name.                                |
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
| defaultDimension  | number | Yes   | No    | Default dimension of the widget.                                      |
| supportDimensions    | Array&lt;number&gt;      | Yes   | No    | Dimensions supported by the widget. For details, see [FormDimension](#formdimension).  |
| customizeData    | {[key: string]: [value: string]}      | Yes   | No    | Custom data of the widget.        |
| isDynamic<sup>10+</sup>      | boolean               | Yes   | No    | Whether the widget is a dynamic widget.<br>ArkTS widgets are classified into dynamic and static widgets. JS widgets are all dynamic widgets.              |
| transparencyEnabled<sup>11+</sup>      | boolean               | Yes   | No    | Whether the widget supports the setting of the background transparency.<br>For ArkTS widgets, the support for the background transparency setting depends on user configurations. For JS widgets, the background transparency setting is not supported.              |

## FormType

Enumerates the widget types.

**System capability**: SystemCapability.Ability.Form

| Name       | Value  | Description        |
| ----------- | ---- | ------------ |
| JS      | 1    | JS widget.  |
| eTS     | 2    | ArkTS widget.|

## ColorMode

Enumerates the color modes supported by the widget.

**System capability**: SystemCapability.Ability.Form

| Name       | Value  | Description        |
| ----------- | ---- | ------------ |
| MODE_AUTO   | -1    | Auto mode.  |
| MODE_DARK    | 0   | Dark mode.  |
| MODE_LIGHT     | 1   | Light mode.  |

## FormStateInfo

Describes the widget state information.

**System capability**: SystemCapability.Ability.Form

| Name       | Type                | Readable   | Writable   | Description                                                        |
| ----------- | -------- | -------- | -------------------- | ------------------------------------------------------------ |
| formState  | [FormState](#formstate)               | Yes   | No    | Widget state.                         |
| want  | [Want](js-apis-app-ability-want.md)         | Yes   | No    | Want text.   |

##  FormState

Enumerates the widget states.

**System capability**: SystemCapability.Ability.Form

| Name       | Value  | Description        |
| ----------- | ---- | ------------ |
| UNKNOWN    | -1    | Unknown state.  |
| DEFAULT     | 0   | Default state.  |
| READY      | 1   | Ready state.  |

##  FormParam

Enumerates the widget parameters.

**System capability**: SystemCapability.Ability.Form

| Name       | Value  | Description        |
| ----------- | ---- | ------------ |
| IDENTITY_KEY     | 'ohos.extra.param.key.form_identity'    | Widget ID.  |
| DIMENSION_KEY      | 'ohos.extra.param.key.form_dimension'  | Widget dimension.  |
| NAME_KEY       | 'ohos.extra.param.key.form_name'   | Widget name.  |
| MODULE_NAME_KEY        | 'ohos.extra.param.key.module_name'   | Name of the module to which the widget belongs.  |
| WIDTH_KEY        | 'ohos.extra.param.key.form_width'   | Widget width.  |
| HEIGHT_KEY         | 'ohos.extra.param.key.form_height'   | Widget height.  |
| TEMPORARY_KEY          | 'ohos.extra.param.key.form_temporary'   | Temporary widget.  |
| ABILITY_NAME_KEY   | 'ohos.extra.param.key.ability_name'   | Ability name. |
| DEVICE_ID_KEY    | 'ohos.extra.param.key.device_id'   | Device ID.<br>**System API**: This is a system API and cannot be called by third-party applications. |
| BUNDLE_NAME_KEY    | 'ohos.extra.param.key.bundle_name'   | Key that specifies the target bundle name.|
| LAUNCH_REASON_KEY<sup>10+</sup>    | 'ohos.extra.param.key.form_launch_reason'   | Reason for creating the widget.  |
| PARAM_FORM_CUSTOMIZE_KEY<sup>10+</sup>    | 'ohos.extra.param.key.form_customize'   | Custom data.  |

##  FormDimension

Enumerates the widget dimensions.

**System capability**: SystemCapability.Ability.Form

| Name       | Value  | Description        |
| ----------- | ---- | ------------ |
| Dimension_1_2      | 1   | 1 x 2.  |
| Dimension_2_2      | 2   | 2 x 2.  |
| Dimension_2_4      | 3   | 2 x 4.  |
| Dimension_4_4      | 4   | 4 x 4.  |
| Dimension_2_1      | 5   | 2 x 1.  |
| Dimension_1_1      | 6   | 1 x 1.  |


## FormInfoFilter

Defines the widget information filter. Only the widget information that meets the filter is returned.

**System capability**: SystemCapability.Ability.Form

| Name       | Type  | Mandatory        |Description        |
| ----------- | ---- | ------------ |------------ |
| moduleName    | string    |No   | Optional. Only the information about the widget whose **moduleName** is the same as the provided value is returned.<br>If this parameter is not set, **moduleName** is not used for filtering.  |

## VisibilityType

Enumerates the visibility types of the widget.

**System capability**: SystemCapability.Ability.Form

| Name       |  Value  | Description        |
| ----------- | ---- | ------------ |
| UNKNOWN<sup>10+</sup> | 0   | The visibility type of the widget is unknown.|
| FORM_VISIBLE | 1   | The widget is visible.|
| FORM_INVISIBLE   | 2   | The widget is invisible.|

## FormUsageState

Enumerates the usage statuses of widgets.

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API and cannot be called by third-party applications.

| Name       |  Value  | Description        |
| ----------- | ---- | ------------ |
| USED<sup>11+</sup> | 0   | The widget is in use.|
| UNUSED<sup>11+</sup> | 1   | The widget is not in use.|

## RunningFormInfo<sup>10+</sup>

Defines the information about the widget host.

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API and cannot be called by third-party applications.

| Name       | Type                | Readable   | Writable   | Description                                                        |
| ----------- | -------- | -------- | -------------------- | ------------------------------------------------------------ |
| formId  | string               | Yes   | No    | Widget ID.                  |
| bundleName<sup>10+</sup>  | string               | Yes   | No    | Name of the bundle to which the widget provider belongs.                  |
| hostBundleName  | string               | Yes   | No    | Name of the bundle to which the widget host belongs.                  |
| visibilityType  | [VisibilityType](#visibilitytype)               | Yes   | No    | Visibility types of the widget.                  |
| moduleName<sup>10+</sup>  | string               | Yes   | No    | Name of the module to which the widget belongs.                     |
| abilityName<sup>10+</sup> | string               | Yes   | No    | Name of the ability to which the widget belongs.                      |
| formName<sup>10+</sup>        | string               | Yes   | No    | Widget name.                                |
| dimension | number               | Yes   | No    | Widget specifications.  |
| formUsageState<sup>11+</sup> | [FormUsageState](#formusagestate)         | Yes   | No    | Usage status of the widget.  |

## formProviderFilter<sup>10+</sup>

Defines the information about the widget provider.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API and cannot be called by third-party applications.

| Name       | Type                | Readable   | Writable   | Description                                                        |
| ----------- | -------- | -------- | -------------------- | ------------------------------------------------------------ |
| bundleName  | string               | Yes   | No    | Name of the bundle to which the widget provider belongs. |
| formName    | string               | Yes   | No    | Widget name.                    |
| moduleName  | string               | Yes   | No    | Name of the module to which the widget belongs.       |
| abilityName | string               | Yes   | No    | Name of the ability to which the widget belongs.       |
| isUnusedIncluded<sup>11+</sup> | boolean               | Yes   | No    | Whether an unused widget is included.       |

## LaunchReason<sup>10+</sup>

Enumerates the reasons for creating a widget.

**System capability**: SystemCapability.Ability.Form

| Name       |  Value  | Description        |
| ----------- | ---- | ------------ |
| FORM_DEFAULT | 1   | The widget is created by default.|
| FORM_SHARE   | 2   | The widget is created for sharing.|
