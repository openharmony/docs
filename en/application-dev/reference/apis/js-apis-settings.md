# Settings

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The initial APIs of this module are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


This module provides APIs for setting data items.


## Modules to Import

```typescript
import settings from '@ohos.settings';
```



## settings.getUriSync

getUriSync(name: string): string

Obtains the URI of a data item.

**System capability**: SystemCapability.Applictaions.settings.Core

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | name | string | Yes| Name of the target data item. Data items can be classified as follows:<br> <ul><li>Existing data items in the database, for example:<br></li> <ul><li>Brightness: 'settings.screen.brightness'<br> </li>  <li>Time format: 'settings.time.format'<br> </li></ul> <li>Custom data items</li></ul>|

- Return value
  | Type| Description|
  | -------- | -------- |
  | string | URI of the data item.|

- Example
  ```typescript
   // Obtain the URI of a data item.
   let urivar = settings.getUriSync('settings.screen.brightness');  
  ```


## settings.getValueSync

getValueSync(dataAbilityHelper: DataAbilityHelper, name: string, defValue: string): string

Obtains the value of a data item.

**System capability**: SystemCapability.Applictaions.settings.Core

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | dataAbilityHelper | [DataAbilityHelper](js-apis-dataAbilityHelper.md) | Yes| **DataAbilityHelper** class.|
  | name | string | Yes| Name of the target data item. Data items can be classified as follows:<br> <ul><li>Existing data items in the database, for example:<br></li> <ul><li>Brightness: 'settings.screen.brightness'<br> </li>  <li>Time format: 'settings.time.format'<br> </li></ul> <li>Custom data items</li></ul>|
  | defValue | string | Yes| Default value This parameter is user-defined. If it is not found in the database, the default value is returned.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | string | Value of the data item.|

- Example
  ```typescript
  import featureAbility from '@ohos.ability.featureAbility';

  // Obtain the value of 'settings.screen.brightness' (this data item already exists in the database).
  let brightness = 'settings.screen.brightness';
  let uri = settings.getUriSync(brightness);
  let helper = featureAbility.acquireDataAbilityHelper(uri);
  let value = settings.getValueSync(helper, brightness, '10');
  ```


## settings.setValueSync

setValueSync(dataAbilityHelper: DataAbilityHelper, name: string, value: string): boolean

Sets the value of a data item.
If the specified data item exists in the database, the **setValueSync** method updates the value of the data item. If the data item does not exist in the database, the **setValueSync** method inserts the data item into the database.

**Required permissions**: ohos.permission.WRITE_SYSTEM_SETTING

**System capability**: SystemCapability.Applictaions.settings.Core

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | dataAbilityHelper | [DataAbilityHelper](js-apis-dataAbilityHelper.md) | Yes| **DataAbilityHelper** class.|
  | name | string | Yes| Name of the target data item. Data items can be classified as follows:<br> <ul><li>Existing data items in the database, for example:<br></li> <ul><li>Brightness: 'settings.screen.brightness'<br> </li>  <li>Time format: 'settings.time.format'<br> </li></ul> <li>Custom data items</li></ul>|
  | value | string | Yes| Value of the data item.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | boolean | Result indicating whether the value is set successfully. Returns **true** if the value is set successfully; returns **false** otherwise.|

- Example
  ```typescript
  import featureAbility from '@ohos.ability.featureAbility';

  // Update the value of 'settings.screen.brightness'. (As this data item exists in the database, the setValueSync 
     method will update the value of the data item.)
  let brightness = 'settings.screen.brightness';
  let uri = settings.getUriSync(brightness);
  let helper = featureAbility.acquireDataAbilityHelper(uri);
  let ret = settings.setValueSync(helper, brightness, '100');
  ```
