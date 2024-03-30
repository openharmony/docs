# @ohos.bluetooth.pbap (Bluetooth PBAP Module)

The **pbap** module provides APIs for accessing the phone book of a device using the Bluetooth Phone Book Access Profile (PBAP).

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.



## Modules to Import

```js
import pbap from '@ohos.bluetooth.pbap';
```


## pbap.createPbapServerProfile

createPbapServerProfile(): PbapServerProfile

Create a **PbapServerProfile** instance.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                           | Description        |
| ----------------------------- | ---------- |
| PbapServerProfile | **PbapServerProfile** instance created.|

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let pbapServerProfile = pbap.createPbapServerProfile();
    console.info('pbapServer success');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## PbapServerProfile

Provides APIs for accessing the phone book of a device. Before using any API of **PbapServerProfile**, you need to create an instance of this class by using **createPbapServerProfile()**.
