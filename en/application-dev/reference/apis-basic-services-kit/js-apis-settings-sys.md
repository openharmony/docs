# @ohos.settings (Data Item Settings) (System API)

The **settings** module provides APIs for setting data items.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.
> - This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.settings (Data Item Settings)](./js-apis-settings.md).

## Modules to Import

```js
import settings from '@ohos.settings';
```

## domainName

Provides the domain name.

### Attributes

**System capability**: SystemCapability.Applications.Settings.Core

| Name               | Type  | Readable| Writable| Description                                                        |
| ------------------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| USER_SECURITY<sup>11+</sup>      | string | Yes  | Yes  | User security attribute domain.                                         |

## settings.setValue<sup>(deprecated)</sup>

setValue(dataAbilityHelper: DataAbilityHelper, name: string, value: object, callback: AsyncCallback\<boolean>): void

Sets the value for a data item. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setValue()](js-apis-settings.md#settingssetvalue10) instead.

**System API**: This is a system API.

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.Applications.Settings.Core

**Parameters**

| Name           | Type                                                        | Mandatory| Description                                                        |
| ----------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| dataAbilityHelper | [DataAbilityHelper](../apis-ability-kit/js-apis-inner-ability-dataAbilityHelper.md) | Yes  | **DataAbilityHelper** class.                                            |
| name              | string                                                       | Yes  | Name of the target data item. Data items can be classified as follows:<br>- Existing data items in the database<br>- Custom data items|
| value             | object                                                       | Yes  | Value of the data item. The value range varies by service.                              |
| callback          | AsyncCallback\<boolean>                                      | Yes  | Callback used to return the result. Returns **true** if the operation is successful; returns **false** otherwise.              |


## settings.setValue<sup>(deprecated)</sup>

setValue(dataAbilityHelper: DataAbilityHelper, name: string, value: object): Promise\<boolean>

Sets the value for a data item. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setValue()](js-apis-settings.md#settingssetvalue10-1) instead.

**System API**: This is a system API.

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.Applications.Settings.Core

**Parameters**

| Name           | Type                                                        | Mandatory| Description                                                        |
| ----------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| dataAbilityHelper | [DataAbilityHelper](../apis-ability-kit/js-apis-inner-ability-dataAbilityHelper.md) | Yes  | **DataAbilityHelper** class.                                            |
| name              | string                                                       | Yes  | Name of the target data item. Data items can be classified as follows:<br>- Existing data items in the database<br>- Custom data items|
| value             | object                                                       | Yes  | Value of the data item. The value range varies by service.                              |

**Return value**

| Type             | Description                                              |
| ----------------- | -------------------------------------------------- |
| Promise\<boolean> | Promise used to return the result. Returns **true** if the operation is successful; returns **false** otherwise.|
