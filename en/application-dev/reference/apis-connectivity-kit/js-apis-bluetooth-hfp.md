# @ohos.bluetooth.hfp (Bluetooth HFP Module)

The **hfp** module provides APIs for using the Bluetooth Hands-Free Profile (HFP).

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.



## Modules to Import

```js
import hfp from '@ohos.bluetooth.hfp';
```


## hfp.createHfpAgProfile

createHfpAgProfile(): HandsFreeAudioGatewayProfile

Creates an **HfpAgProfile** instance.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                           | Description        |
| ----------------------------- | ---------- |
| HandsFreeAudioGatewayProfile | **HfpAgProfile** instance created.|

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let hfpAgProfile = hfp.createHfpAgProfile();
    console.info('hfpAg success');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## HandsFreeAudioGatewayProfile

Before using any API of **HandsFreeAudioGatewayProfile**, you need to create an instance of this class by using **createHfpAgProfile()**.
