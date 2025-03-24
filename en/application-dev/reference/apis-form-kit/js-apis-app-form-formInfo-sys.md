# @ohos.app.form.formInfo (formInfo) (System API)

The **formInfo** module provides types and enums related to the widget information and state.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.app.form.formInfo (formInfo)](./js-apis-app-form-formInfo.md).

## Modules to Import

```ts
import { formInfo } from '@kit.FormKit';
```


##  FormParam

Enumerates the widget parameters.

**System capability**: SystemCapability.Ability.Form

| Name       | Value  | Description        |
| ----------- | ---- | ------------ |
| DEVICE_ID_KEY    | 'ohos.extra.param.key.device_id'   | Device ID.<br>**System API**: This is a system API. |

## FormUsageState

Enumerates the usage statuses of widgets.

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API.

| Name       |  Value  | Description        |
| ----------- | ---- | ------------ |
| USED<sup>11+</sup> | 0   | The widget is in use.|
| UNUSED<sup>11+</sup> | 1   | The widget is not in use.|

## RunningFormInfo<sup>10+</sup>

Defines the information about an added widget, which can be either in use or not.

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API.

| Name       | Type                | Readable   | Writable   | Description                                                        |
| ----------- | -------- | -------- | -------------------- | ------------------------------------------------------------ |
| formId  | string               | Yes   | No    | Widget ID.                  |
| bundleName<sup>10+</sup>  | string               | Yes   | No    | Name of the bundle to which the widget provider belongs.                  |
| hostBundleName  | string               | Yes   | No    | Name of the bundle to which the widget host belongs.                  |
| visibilityType  | [VisibilityType](js-apis-app-form-formInfo.md#visibilitytype)               | Yes   | No    | Visibility types of the widget.                  |
| moduleName<sup>10+</sup>  | string               | Yes   | No    | Name of the module to which the widget belongs.                     |
| abilityName<sup>10+</sup> | string               | Yes   | No    | Name of the ability to which the widget belongs.                      |
| formName<sup>10+</sup>        | string               | Yes   | No    | Widget name.                                |
| dimension | number               | Yes   | No    | Widget specifications.  |
| formUsageState<sup>11+</sup> | [FormUsageState](#formusagestate)         | Yes   | No    | Usage status of the widget.  |
| formDescription<sup>11+</sup> | string         | Yes   | No    | Description in the widget configuration file of the provider.  |
| formLocation<sup>12+</sup> | [FormLocation](#formlocation12)| Yes   | No    | Location of the widget.  |

## formProviderFilter<sup>10+</sup>

Defines the information about the widget provider.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API.

| Name       | Type                | Readable   | Writable   | Description                                                        |
| ----------- | -------- | -------- | -------------------- | ------------------------------------------------------------ |
| bundleName  | string               | Yes   | No    | Name of the bundle to which the widget provider belongs. |
| formName    | string               | Yes   | No    | Widget name.                    |
| moduleName  | string               | Yes   | No    | Name of the module to which the widget belongs.       |
| abilityName | string               | Yes   | No    | Name of the ability to which the widget belongs.       |
| isUnusedIncluded<sup>11+</sup> | boolean               | Yes   | No    | Whether an unused widget is included.       |


## FormInfoFilter

Defines the widget information filter. Only the widget information that meets the filter is returned.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

| Name       | Type  | Mandatory        |Description        |
| ----------- | ---- | ------------ |------------ |
| bundleName    | string    |No   | Only the widget information in which **bundleName** is the same as the provided value is returned. If this parameter is left unspecified, the widget information is not filtered by **bundleName**.<br>**System API**: This is a system API. |
| supportedDimensions | Array\<number\> |No   | Only the widget information in which **supportedDimensions** is the same as the provided value is returned. If this parameter is left unspecified, the widget information is not filtered by **supportedDimensions**.<br>**System API**: This is a system API. |
| supportedShapes<sup>12+</sup>  | Array\<number\> |No   | Only the widget information in which **supportedShapes** is the same as the provided value is returned. If this parameter is left unspecified, the widget information is not filtered by **supportedShapes**.<br>**System API**: This is a system API.  |

## FormLocation<sup>12+</sup>

Enumerates the widget locations.

**System capability**: SystemCapability.Ability.Form

| Name                        | Value  | Description                            |
| ---------------------------- | ---- | -------------------------------- |
| OTHER                        | -1   | The widget is not located in any of the following defined positions.          |
| DESKTOP                      | 0    | The widget is located on the home screen.              |
| FORM_CENTER                  | 1    | The widget is located in the widget center of the home screen.    |
| FORM_MANAGER                 | 2    | The widget is located in the widget manager of the home screen.  |
| NEGATIVE_SCREEN              | 3    | The widget is located on the minus 1 screen.            |
| FORM_CENTER_NEGATIVE_SCREEN  | 4    | The widget is located in the service panel of the minus 1 screen.  |
| FORM_MANAGER_NEGATIVE_SCREEN | 5    | The widget is located in the widget manager of the minus 1 screen.|
| SCREEN_LOCK                  | 6    | The widget is located on the locked screen.              |
| AI_SUGGESTION                | 7    | The widget is located in the area of Celia Suggestions.    |

## PublishFormResult<sup>12+</sup>

Describes the result for the operation of adding a widget to the home screen.

**System capability**: SystemCapability.Ability.Form

| Name   | Type                                         | Readable| Writable| Description                      |
| ------- | --------------------------------------------- | ---- | ---- | -------------------------- |
| code    | [PublishFormErrorCode](#publishformerrorcode12) | Yes  | No  | Result code of the operation.      |
| message | string                                        | Yes  | No  | Message returned for the operation.|

## PublishFormErrorCode<sup>12+</sup>

Enumerates the result codes that may be used for the operation of adding a widget to the home screen.

**System capability**: SystemCapability.Ability.Form

| Name          | Value  | Description                            |
| -------------- | ---- | -------------------------------- |
| SUCCESS        | 0    | The widget is added to the home screen.              |
| NO_SPACE       | 1    | There is no space for adding widgets.          |
| PARAM_ERROR    | 2    | Parameter check fails.              |
| INTERNAL_ERROR | 3    | An internal error occurs during widget processing.|
