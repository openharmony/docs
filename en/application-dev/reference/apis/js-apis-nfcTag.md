# Standard NFC Tag

Manages Near-Field Communication (NFC) tags.

> **NOTE**<br>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## **Modules to Import**

```
import tag from '@ohos.nfc.tag';
```


## tag.getNfcATag

getNfcATag(tagInfo: TagInfo): NfcATag

Obtains an **NfcATag** object, which allows access to the tags that use the NFC-A technology.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| NfcATag | **NfcATag** object obtained.|

## tag.getNfcBTag

getNfcBTag(tagInfo: TagInfo): NfcBTag

Obtains an **NfcBTag** object, which allows access to the tags that use the NFC-B technology.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**        |
| -------- | ---------------- |
| NfcBTag  | **NfcBTag** object obtained.|

## tag.getNfcFTag

getNfcFTag(tagInfo: TagInfo): NfcFTag

Obtains an **NfcFTag** object, which allows access to the tags that use the NFC-F technology.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**        |
| -------- | ---------------- |
| NfcFTag  | **NfcFTag** object obtained.|

## tag.getNfcVTag

getNfcVTag(tagInfo: TagInfo): NfcVTag

Obtains an **NfcVTag** object, which allows access to the tags that use the NFC-V technology.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**        |
| -------- | ---------------- |
| NfcVTag  | **NfcVTag** object obtained.|
