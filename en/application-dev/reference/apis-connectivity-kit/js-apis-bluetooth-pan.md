# @ohos.bluetooth.pan (Bluetooth PAN Module)

The **pan** module provides APIs for accessing the Bluetooth personal area network (PAN).

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.



## Modules to Import

```js
import pan from '@ohos.bluetooth.pan';
```


## pan.createPanProfile

createPanProfile(): PanProfile

Creates a **PanProfile** instance.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                           | Description        |
| ----------------------------- | ---------- |
| PanProfile | **PanProfile** instance created.|

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let panProfile : pan.PanProfile= pan.createPanProfile();
    console.info('pan success');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```
