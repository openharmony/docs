# FormInfo

The **FormInfo** module provides widget information and state.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```
import formInfo from '@ohos.application.formInfo';
```

## Required Permissions

None

## FormInfo

Describes widget information.

**System capability**: SystemCapability.Ability.Form

| Name       | Readable/Writable| Type                | Description                                                        |
| ----------- | -------- | -------------------- | ------------------------------------------------------------ |
| bundleName  | Read only    | string               | Name of the bundle to which the widget belongs.                          |
| moduleName  | Read only    | string               | Name of the module to which the widget belongs.                      |
| abilityName | Read only    | string               | Name of the ability to which the widget belongs.                      |
| name        | Read only    | string               | Widget name.                                |
| description | Read only    | string               | Description of the widget.  |
| type        | Read only    | [FormType](#formtype)             | Widget type. Currently, only JS widgets are supported.|
| jsComponentName      | Read only    | string               | Component name of the JS widget.              |
| colorMode  | Read only    | [ColorMode](#colormode) | Color mode of the widget.                                      |
| isDefault    | Read only    | boolean      | Whether the widget is the default one.                             |
| updateEnabled  | Read only    | boolean               | Whether the widget is updatable.                   |
| formVisibleNotify  | Read only    | string               | Whether to send a notification when the widget is visible.           |
| relatedBundleName | Read only    | string               | Name of the associated bundle to which the widget belongs.                  |
| scheduledUpdateTime        | Read only    | string               | Time when the widget was updated.    |
| formConfigAbility | Read only    | string               | Configuration ability of the widget.  |
| updateDuration        | Read only    | string             | Widget update period.|
| defaultDimension  | Read only    | number | Default dimension of the widget.                                      |
| supportDimensions    | Read only    | Array&lt;number&gt;      | Dimensions supported by the widget.                |
| customizeData    | Read only    | {[key: string]: [value: string]}      | Custom data of the widget.        |

## FormType

Enumerates the widget types.

**System capability**: SystemCapability.Ability.Form

| Name       | Value  | Description        |
| ----------- | ---- | ------------ |
| JS      | 1    | JS widget.  |

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

| Name       | Readable/Writable| Type                | Description                                                        |
| ----------- | -------- | -------------------- | ------------------------------------------------------------ |
| formState  | Read only    | [FormState](#formstate)               | Widget state.                         |
| want  | Read only    | Want               | Want text.   |

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
| IDENTITY_KEY<sup>9+</sup>     | "ohos.extra.param.key.form_identity"    | ID of a widget.<br>**System API**: This is a system API and cannot be called by third-party applications.  |
| DIMENSION_KEY      | "ohos.extra.param.key.form_dimension"  | Widget dimension.  |
| NAME_KEY       | "ohos.extra.param.key.form_name"   | Widget name.  |
| MODULE_NAME_KEY        | "ohos.extra.param.key.module_name"   | Name of the module to which the widget belongs.  |
| WIDTH_KEY        | "ohos.extra.param.key.form_width"   | Widget width.  |
| HEIGHT_KEY         | "ohos.extra.param.key.form_height"   | Widget height.  |
| TEMPORARY_KEY          | "ohos.extra.param.key.form_temporary"   | Temporary widget.  |
| ABILITY_NAME_KEY<sup>9+</sup>   | "ohos.extra.param.key.ability_name"   | Ability name.  |
| DEVICE_ID_KEY<sup>9+</sup>      | "ohos.extra.param.key.device_id"   | Device ID.<br>This is a system API.  |
| BUNDLE_NAME_KEY<sup>9+</sup>      | "ohos.extra.param.key.bundle_name"   | Key that specifies the target bundle name.|

##  FormDimension

Enumerates the widget dimensions.

**System capability**: SystemCapability.Ability.Form

| Name       | Value  | Description        |
| ----------- | ---- | ------------ |
| Dimension_1_2<sup>9+</sup>      | 1   | 1 x 2.  |
| Dimension_2_2<sup>9+</sup>      | 2   | 2 x 2.  |
| Dimension_2_4<sup>9+</sup>      | 3   | 2 x 4.  |
| Dimension_4_4<sup>9+</sup>      | 4   | 4 x 4.  |
| Dimension_2_1<sup>9+</sup>      | 5   | 2 x 1.  |


## FormInfoFilter

Defines the widget information filter. Only the widget information that meets the filter is returned.

**System capability**: SystemCapability.Ability.Form

| Name       |  Yes  | Description        |
| ----------- | ---- | ------------ |
| moduleName<sup>9+</sup>   | No  | Module name.|
