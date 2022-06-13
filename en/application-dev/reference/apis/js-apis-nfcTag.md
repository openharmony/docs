# Standard NFC Tag

This module is used to manage Near-Field Communication (NFC) tags.

> **NOTE**<br>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## **Modules to Import**

```
import tag from '@ohos.nfc.tag';
```


## tag.getNfcATag

getNfcATag(tagInfo: TagInfo): NfcATag

Obtains the **NfcATag** object, which allows access to the tags that use the NfcA technology.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| NfcATag | **NfcATag** object obtained.|

## tag.getNfcBTag

getNfcBTag(tagInfo: TagInfo): NfcBTag

Obtains the **NfcBTag** object, which allows access to the tags that use the NfcB technology.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**        |
| -------- | ---------------- |
| NfcBTag  | **NfcBTag** object obtained.|

## tag.getNfcFTag

getNfcFTag(tagInfo: TagInfo): NfcFTag

Obtains the **NfcFTag** object, which allows access to the tags that use the NfcF technology.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**        |
| -------- | ---------------- |
| NfcFTag  | **NfcFTag** object obtained.|

## tag.getNfcVTag

getNfcVTag(tagInfo: TagInfo): NfcVTag

Obtains the **NfcVTag** object, which allows access to the tags that use the NfcV technology.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**        |
| -------- | ---------------- |
| NfcVTag  | **NfcVTag** object obtained.|
