# @ohos.app.form.formInfo (formInfo) (System API)

The **formInfo** module provides types and enums related to the widget information and state.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.app.form.formInfo (formInfo)](./js-apis-app-form-formInfo.md).

## Modules to Import

```ts
import formInfo from '@ohos.app.form.formInfo';
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
