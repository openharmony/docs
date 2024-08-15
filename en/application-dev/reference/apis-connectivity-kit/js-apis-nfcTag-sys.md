# @ohos.nfc.tag (standard NFC Tags) (System API)

The **tag** module provides APIs for operating and managing NFC tags. The following tag read modes are available:

- Background mode: The device reads the tag by using NFC without starting any application, and then searches for applications based on the tag type. If only one application is matched, the card reading page of that application will be started. If multiple applications are matched, an application selector will be started, asking the user to select an application.
- Foreground mode: A foreground application has priority to read the NFC tag discovered.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.nfc.tag (standard NFC-Tag)](js-apis-nfcTag.md).

## **Modules to Import**

```js
import { tag } from '@kit.ConnectivityKit';
```

## TagInfo

Defines the **TagInfo** object, which provides information about the tag technologies supported by a card.

**System capability**: SystemCapability.Communication.NFC.Tag

**Required permissions**: ohos.permission.NFC_TAG

| **Name**                     | **Type**                                                     | **Readable**| **Writable**| **Description**                                                                                    |
| ----------------------------- | ------------------------------------------------------------- | -------- | -------- | -------------------------------------------------------------------------------------------- |
| extrasData<sup>9+</sup>       | [PacMap](../apis-ability-kit/js-apis-inner-ability-dataAbilityHelper.md#pacmap)[] | Yes      | No      | Extended attribute value of the tag technology.<br>**System API**: This is a system API.                           |
| tagRfDiscId<sup>9+</sup>      | number                                                        | Yes      | No      | ID allocated when the tag is discovered.<br>**System API**: This is a system API.                                 |
| remoteTagService<sup>9+</sup> | [rpc.RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject)               | Yes      | No      | Remote object of the NFC service process used for interface communication between the client and the service.<br>**System API**: This is a system API.|
