# @ohos.application.formInfo (formInfo)

<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @Qian-Win-->
<!--Designer: @cx983299475-->
<!--Tester: @mahailong123456-->
<!--Adviser: @HelloShuo-->
<!-- md-trans-meta sourceCommit=6b0733adc9a538f18ea8143587feeecb737929d9 translatedAt=2026-07-31T08:24:53.479Z pushedAt=2026-07-31T09:20:05.586Z -->

The **formInfo** module provides types and enums related to the widget information and state.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This module is deprecated since API version 9. You are advised to use [formInfo](js-apis-app-form-formInfo.md) instead.

## Modules to Import

```ts
import { formInfo } from '@kit.FormKit';
```

## FormInfo

Widget information.

**System capability**: SystemCapability.Ability.Form

| Name       | Type                | Read-Only   | Optional    | Description                                                        |
| ----------- | -------- |-------- | -------------------- | ------------------------------------------------------------ |
| bundleName  | string               | No   | No     | Name of the bundle to which the widget belongs.                  |
| moduleName  | string               | No   | No     | Name of the module to which the widget belongs.                      |
| abilityName | string               | No   | No     | Name of the ability to which the widget belongs.                    |
| name        | string               | No   | No     | Widget name.                                |
| description | string               | No   | No     | Description of the widget.  |
| type        | [FormType](#formtype)             | No   | No     | Type of the widget. Currently, only JS widgets are supported.|
| jsComponentName      | string               | No   | No     | Component name of the JS widget.              |
| colorMode  | [ColorMode](#colormode) | No   | No     | Color mode of the widget.                                      |
| isDefault    | boolean      | No   | No     | Whether the widget is the default one.<br>- **true**: The widget is the default one.<br>- **false**: The widget is not the default one.|
| updateEnabled  | boolean               | No   | No     | Whether the widget is updatable.<br>- **true**: The widget can be updated periodically.<br>- **false**: The widget cannot be updated periodically.|
| formVisibleNotify  | boolean               | No   | No     | Whether to send a notification when the widget is visible.<br>- **true**: The widget provider is notified of the status change.<br>- **false**: The widget provider is not notified of the status change.|
| relatedBundleName | string               | No   | No     | Name of the associated bundle to which the widget belongs.          |
| scheduledUpdateTime        | string               | No    | No      | Scheduled update time of the widget.     |
| formConfigAbility | string               | No   | No     | Configuration ability of the widget.  |
| updateDuration        | number             | No   | No     | Update period of the widget.|
| defaultDimension  | number | No    | No      | Default dimension of the widget.                                       |
| supportDimensions    | Array&lt;number&gt;      | No    | No      | Dimensions supported by the widget.                 |
| customizeData    | {[key: string]: [value: string]}      | No    | No      | Custom data of the widget.         |

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

| Name       | Type                | Read-Only   | Optional    | Description                                                        |
| ----------- | -------- |-------- | -------------------- | ------------------------------------------------------------ |
| formState  | [FormState](#formstate)               | No   | No     | Widget state.                         |
| want  | [Want](../apis-ability-kit/js-apis-app-ability-want.md)               | No    | No      | Want information of the widget.  |

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