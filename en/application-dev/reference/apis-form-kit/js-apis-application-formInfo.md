# @ohos.application.formInfo (formInfo)

The **formInfo** module provides types and enums related to the widget information and state.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> This module is deprecated since API version 9. You are advised to use [formInfo](js-apis-app-form-formInfo.md) instead.

## Modules to Import

```ts
import formInfo from '@ohos.application.formInfo';
```

## FormInfo

Describes widget information.

**System capability**: SystemCapability.Ability.Form

| Name       | Type                | Readable   | Writable    | Description                                                        |
| ----------- | -------- |-------- | -------------------- | ------------------------------------------------------------ |
| bundleName  | string               | Yes   | No     | Name of the bundle to which the widget belongs.                  |
| moduleName  | string               | Yes   | No     | Name of the module to which the widget belongs.                      |
| abilityName | string               | Yes   | No     | Name of the ability to which the widget belongs.                    |
| name        | string               | Yes   | No     | Widget name.                                |
| description | string               | Yes   | No     | Description of the widget.  |
| type        | [FormType](#formtype)             | Yes   | No     | Type of the widget. Currently, only JS widgets are supported.|
| jsComponentName      | string               | Yes   | No     | Name of the component used in the JS widget.              |
| colorMode  | [ColorMode](#colormode) | Yes   | No     | Color mode of the widget.                                      |
| isDefault    | boolean      | Yes   | No     | Whether the widget is the default one.                             |
| updateEnabled  | boolean               | Yes   | No     | Whether the widget is updatable.                   |
| formVisibleNotify  | boolean               | Yes   | No     | Whether to send a notification when the widget is visible.           |
| relatedBundleName | string               | Yes   | No     | Name of the associated bundle to which the widget belongs.          |
| scheduledUpdateTime        | string               | Yes   | No     | Time when the widget was updated.    |
| formConfigAbility | string               | Yes   | No     | Configuration ability of the widget.  |
| updateDuration        | number             | Yes   | No     | Update period of the widget.|
| defaultDimension  | number | Yes   | No     | Default dimension of the widget.                                      |
| supportDimensions    | Array&lt;number&gt;      | Yes   | No     | Dimensions supported by the widget.                |
| customizeData    | {[key: string]: [value: string]}      | Yes   | No     | Custom data of the widget.        |

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

| Name       | Type                | Readable   | Writable    | Description                                                        |
| ----------- | -------- |-------- | -------------------- | ------------------------------------------------------------ |
| formState  | [FormState](#formstate)               | Yes   | No     | Widget state.                         |
| want  | [Want](../apis-ability-kit/js-apis-app-ability-want.md)               | Yes   | No     | Want text.   |

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
| DIMENSION_KEY      | 'ohos.extra.param.key.form_dimension'  | Widget dimension.  |
| NAME_KEY       | 'ohos.extra.param.key.form_name'   | Widget name.  |
| MODULE_NAME_KEY        | 'ohos.extra.param.key.module_name'   | Name of the module to which the widget belongs.  |
| WIDTH_KEY        | 'ohos.extra.param.key.form_width'   | Widget width.  |
| HEIGHT_KEY         | 'ohos.extra.param.key.form_height'   | Widget height.  |
| TEMPORARY_KEY          | 'ohos.extra.param.key.form_temporary'   | Temporary widget.  |
