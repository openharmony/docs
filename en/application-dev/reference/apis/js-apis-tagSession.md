# NFC Tag Session

The **tagSession** module provides common APIs for establishing connections and transferring data.

> **NOTE**<br>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## **Modules to Import**

```js
import tag from '@ohos.nfc.tag';
```

## tagSession

Provides common APIs for establishing connections and transferring data. **tagSession** is the base class of all [NFC tag technologies](js-apis-nfctech.md).

A child class instance is required to access the following interfaces. You can use **get**XX**Tag()** to obtain a child class instance.

The specific API varies with the NFC tag technology in use. For details, see [NFC Tags](js-apis-nfcTag.md).

### tagSession.connectTag

connectTag(): boolean;

Connects to this tag.

Call this API to set up a connection before reading data from or writing data to a tag.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| boolean  | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object given by the NFC service when a tag is dispatched.
let isNfcConnected = tag.getXXXTag(taginfo).connectTag(); 
console.log("isNfcConnected:" +isNfcConnected);
```

### tagSession.reset()

reset(): void

Resets the connection to this tag and restores the default timeout duration for writing data to the tag.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| boolean  | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object given by the NFC service when a tag is dispatched.
let reset = tag.getXXXTag(taginfo).reset(); 
console.log("reset:" +reset);
```

### tagSession.isTagConnected

isTagConnected(): boolean

Checks whether the tag is connected.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| boolean  | Returns **true** if the tag is connected; returns **false** otherwise.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object given by the NFC service when a tag is dispatched.
let isTagConnected = tag.getXXXTag(taginfo).isTagConnected(); 
console.log("isTagConnected:" +isTagConnected);
```

### tagSession.getMaxSendLength

getMaxSendLength(): number

Obtains the maximum length of the data that can be sent to the tag.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number  | Maximum data length obtained.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object given by the NFC service when a tag is dispatched.
let mazSendLen = tag.getXXXTag(taginfo).getMaxSendLength(); 
console.log("mazSendLen:" +mazSendLen);
```
