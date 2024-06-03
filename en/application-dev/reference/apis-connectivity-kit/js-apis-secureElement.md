# @ohos.secureElement (SE Management)

The **secureElement** module provides APIs for managing secure elements (SEs). SEs include the Embedded SE (eSE) and SIM on a device. The SE service mentioned in this topic is an **SEService** instance. For details, see [newSEService](#secureelementnewseservice).

The instances of the following types are mentioned in this topic:

| Type   | Description                                          |
| ------- | ---------------------------------------------- |
| Reader  | SE supported by the device. If eSE and SIM are supported, two instances will be returned.|
| Session | Session created on an SE **Reader** instance.|
| Channel | Channel set up by a **Session** instance. The channel can be a basic channel or a logical channel.  |

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## **Modules to Import**

```js
import secureElement from '@ohos.secureElement';
```

## secureElement.ServiceState

Enumerates the SE service stats.

**System capability**: SystemCapability.Communication.SecureElement

| Name        | Value  | Description              |
| ------------ | ---- | ------------------ |
| DISCONNECTED | 0    | The SE service is disconnected.|
| CONNECTED    | 1    | The SE service is connected.|

## secureElement.newSEService

newSEService(type: 'serviceState', callback: Callback<[ServiceState](#secureelementservicestate)>): SEService

Creates an **SEService** instance for connecting to all available SEs in the system. The connection is time-consuming. Therefore, this API supports only the asynchronous mode.

The returned **SEService** instance is available only when **true** is returned by the specified callback or [isConnected](#seserviceisconnected).

**System capability**: SystemCapability.Communication.SecureElement

**Parameters**

| **Name**| **Type**                                            | **Mandatory**| **Description**            |
| ---------- | ---------------------------------------------------- | ------ | -------------------- |
| type       | string                                               | Yes     | Type of the SE service to create. It has a fixed value of **'serviceState'**.     |
| callback   | Callback<[ServiceState](#secureelementservicestate)> | Yes     | Callback used to return the SE service state.|

**Return value**

| **Type** | **Description**  |
| :-------- | :--------- |
| SEService | **SEService** instance created.|

**Example**

```js
import secureElement from '@ohos.secureElement';
import { BusinessError } from '@ohos.base';

let seService : secureElement.SEService;

function secureElementDemo() {
    // Obtain the service.
    try {
        seService = secureElement.newSEService("serviceState", (state) => {
        hilog.info(0x0000, 'testTag', 'se service state = %{public}s', JSON.stringify(state));
        });
    } catch (error) {
        hilog.error(0x0000, 'testTag', 'newSEService error %{public}s', JSON.stringify(error));
    }
    if (seService == undefined || !seService.isConnected()) {
        hilog.error(0x0000, 'testTag', 'secure element service disconnected.');
        return;
    }
}
```

## SEService.getReaders

getReaders(): Reader[]

Obtains available SE readers, which include all the SEs on the device.

**System capability**: SystemCapability.Communication.SecureElement

**Return value**

| **Type**| **Description**              |
| :------- | :--------------------- |
| Reader[] | Available readers obtained.|

**Example**

```js
import secureElement from '@ohos.secureElement';
import { BusinessError } from '@ohos.base';

let seService : secureElement.SEService;
let seReaders : secureElement.Reader[];

// Initialize seService before using it.
function secureElementDemo() {
    // Obtain readers.
    try {
        seReaders = seService.getReaders();
    } catch (error) {
        hilog.error(0x0000, 'testTag', 'getReaders error %{public}s', JSON.stringify(error));
    }
    if (seReaders == undefined || seReaders.length == 0) {
        hilog.error(0x0000, 'testTag', 'no valid reader found.');
        return;
    }
}
```

## SEService.isConnected

isConnected(): boolean

Checks whether this SE service is connected.

**System capability**: SystemCapability.Communication.SecureElement

**Return value**

| **Type**| **Description**                                      |
| :------- | :--------------------------------------------- |
| boolean  | Returns **true** if the SE service is connected; returns **false** otherwise.|

**Example**

```JS
import secureElement from '@ohos.secureElement';
import { BusinessError } from '@ohos.base';

let seService : secureElement.SEService;

function secureElementDemo() {
    // Obtain the service.
    try {
        seService = secureElement.newSEService("serviceState", (state) => {
        hilog.info(0x0000, 'testTag', 'se service state = %{public}s', JSON.stringify(state));
        });
    } catch (error) {
        hilog.error(0x0000, 'testTag', 'newSEService error %{public}s', JSON.stringify(error));
    }
    if (seService == undefined || !seService.isConnected()) {
        hilog.error(0x0000, 'testTag', 'secure element service disconnected.');
        return;
    }
}
```

## SEService.shutdown

shutdown(): void

Releases all SE resources allocated to this SE service. After that, [isConnected](#seserviceisconnected) returns **false**.

**System capability**: SystemCapability.Communication.SecureElement

**Example**

```js
import secureElement from '@ohos.secureElement';
import { BusinessError } from '@ohos.base';

let seService : secureElement.SEService;

// Initialize seService before using it.

try {
    seService.shutdown();
} catch (error) {
    hilog.error(0x0000, 'testTag', 'shutdown error %{public}s', JSON.stringify(error));
}
```

## SEService.getVersion

getVersion(): string

Obtains the version of the Open Mobile API (OMAPI) specification used.

**System capability**: SystemCapability.Communication.SecureElement

**Return value**

| **Type**| **Description**                                          |
| -------- | -------------------------------------------------- |
| string   | OMAPI version obtained. For example, **3.3** indicates Open Mobile API Specification v3.3.|

**Example**

```JS
import secureElement from '@ohos.secureElement';
import { BusinessError } from '@ohos.base';

let seService : secureElement.SEService;

// Initialize seService before using it.

try {
    let version = seService.getVersion();
    hilog.error(0x0000, 'testTag', 'version %{public}s', JSON.stringify(version));
} catch (error) {
    hilog.error(0x0000, 'testTag', 'getVersion error %{public}s', JSON.stringify(error));
}
```

## Reader.getName

getName(): string

Obtains the name of this reader. The name is **SIM[*Slot*]** for a SIM reader and **eSE** for an eSE.

**System capability**: SystemCapability.Communication.SecureElement

**Return value**

| **Type**| **Description**  |
| -------- | ---------- |
| string   | Reader name obtained.|

**Example**

```js
let seReaders : secureElement.Reader[];

// Initialize seReaders before using it.

try {
    let reader = seReaders[0]; // change it to the selected reader, ese or sim.
    let name = reader.getName();
    hilog.info(0x0000, 'testTag', 'name %{public}s', JSON.stringify(name));
} catch (error) {
    hilog.error(0x0000, 'testTag', 'getName error %{public}s', JSON.stringify(error));
}
```

## Reader.isSecureElementPresent

isSecureElementPresent(): boolean

Checks whether the SE corresponding to this reader is available.

**System capability**: SystemCapability.Communication.SecureElement

**Return value**

| **Type**| **Description**                                    |
| -------- | -------------------------------------------- |
| boolean  | Returns **true** if the SE is available; returns **false** otherwise.|

**Error codes**

For details about error codes, see [SE Error Codes](errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, service state exception. |

**Example**

```js
let seReaders : secureElement.Reader[];

// Initialize seReaders before using it.

try {
    let reader = seReaders[0]; // change it to the selected reader, ese or sim.
    let isPresent = reader.isSecureElementPresent();
    hilog.info(0x0000, 'testTag', 'isPresent %{public}s', JSON.stringify(isPresent));
} catch (error) {
    hilog.error(0x0000, 'testTag', 'isSecureElementPresent error %{public}s', JSON.stringify(error));
}
```

## Reader.openSession

 openSession(): Session

Opens a session to connect to an SE in this reader. Multiple sessions can be opened on a reader at the same time.

**System capability**: SystemCapability.Communication.SecureElement

**Return value**

| **Type**| **Description**                      |
| -------- | ------------------------------ |
| Session  | Session instance opened.|

**Error codes**

For details about error codes, see [SE Error Codes](errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, service state exception. |
| 3300104  | IOError, there is a communication problem to the reader or the SE.     |

**Example**

```js
let seReaders : secureElement.Reader[];
let seSession : secureElement.Session;

// Initialize seReaders before using it.
function secureElementDemo() {
    try {
        let reader = seReaders[0]; // change it to the selected reader, ese or sim.
        seSession = reader.openSession();
    } catch (error) {
        hilog.error(0x0000, 'testTag', 'openSession error %{public}s', JSON.stringify(error));
    }
    if (seSession == undefined) {
        hilog.error(0x0000, 'testTag', 'seSession invalid.');
        return;
    }
}
```

## Reader.closeSessions

 closeSessions(): void

Closes all sessions opened on this reader. All channels opened by these sessions will be closed.

**System capability**: SystemCapability.Communication.SecureElement

**Error codes**

For details about error codes, see [SE Error Codes](errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, service state exception. |

**Example**

```js
let seReaders : secureElement.Reader[];
let seSession : secureElement.Session;
let reader : secureElement.Reader;

// Initialize seReaders before using it.
function secureElementDemo() {
    try {
        reader = seReaders[0]; // change it to the selected reader, ese or sim.
        seSession = reader.openSession();
    } catch (error) {
        hilog.error(0x0000, 'testTag', 'openSession error %{public}s', JSON.stringify(error));
    }
    if (seSession == undefined) {
        hilog.error(0x0000, 'testTag', 'seSession invalid.');
        return;
    }
    try {
        reader.closeSessions();
    } catch (error) {
        hilog.error(0x0000, 'testTag', 'closeSessions error %{public}s', JSON.stringify(error));
    }
}
```

## Session.getReader

getReader(): Reader

Obtains the reader that provides this session.

**System capability**: SystemCapability.Communication.SecureElement

**Return value**

| **Type**| **Description**                   |
| -------- | --------------------------- |
| Reader   | Reader instance obtained.|

**Example**

```js
let seReaders : secureElement.Reader[];
let seSession : secureElement.Session;
let reader : secureElement.Reader;

// Initialize seReaders before using it.
function secureElementDemo() {
    try {
        reader = seReaders[0]; // change it to the selected reader, ese or sim.
        seSession = reader.openSession();
    } catch (error) {
        hilog.error(0x0000, 'testTag', 'openSession error %{public}s', JSON.stringify(error));
    }
    if (seSession == undefined) {
        hilog.error(0x0000, 'testTag', 'seSession invalid.');
        return;
    }
    try {
        let sessionReader = seSession.getReader();
    } catch (error) {
        hilog.error(0x0000, 'testTag', 'getReader error %{public}s', JSON.stringify(error));
    }
}
```

## Session.getATR

getATR(): number[]

Obtains the Answer to Reset (ATR) of this SE. If the ATR of this SE is not available, an empty array will be returned.

**System capability**: SystemCapability.Communication.SecureElement

**Return value**

| **Type**| **Description**                                    |
| -------- | -------------------------------------------- |
| number[] | Returns the ATR obtained if the SE has an available ATR; returns an empty array otherwise.|

**Error codes**

For details about error codes, see [SE Error Codes](errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, service state exception. |

**Example**

```js
let seSession : secureElement.Session;

// Initialize seSession before using it.

try {
    let atr = seSession.getATR();
    hilog.info(0x0000, 'testTag', 'atr %{public}s', JSON.stringify(atr));
} catch (error) {
    hilog.error(0x0000, 'testTag', 'getATR error %{public}s', JSON.stringify(error));
}
```

## Session.close

close(): void

Closes the session with the SE. All channels opened by this session will be closed.

**System capability**: SystemCapability.Communication.SecureElement

**Error codes**

For details about error codes, see [SE Error Codes](errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, service state exception. |

**Example**

```js
let seSession : secureElement.Session;

// Initialize seSession before using it.

try {
    seSession.close();
} catch (error) {
    hilog.error(0x0000, 'testTag', 'close error %{public}s', JSON.stringify(error));
}
```

## Session. isClosed

isClosed(): boolean

Checks whether this session is closed.

**System capability**: SystemCapability.Communication.SecureElement

**Return value**

| **Type**| **Description**                            |
| -------- | ------------------------------------ |
| boolean  | Returns **true** if the session is closed; returns **false** otherwise.|

**Error codes**

For details about error codes, see [SE Error Codes](errorcode-se.md).

**Example**

```Js
let seSession : secureElement.Session;

// Initialize seSession before using it.

try {
    let isClosed = seSession.isClosed();
    hilog.info(0x0000, 'testTag', 'isClosed %{public}s', JSON.stringify(isClosed));
} catch (error) {
    hilog.error(0x0000, 'testTag', 'isClosed error %{public}s', JSON.stringify(error));
}
```

## Session.closeChannels

closeChannels(): void

Closes all channels opened on this session.

**System capability**: SystemCapability.Communication.SecureElement

**Error codes**

For details about error codes, see [SE Error Codes](errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, service state exception. |

**Example**

```js
let seSession : secureElement.Session;

// Initialize seSession before using it.

try {
    seSession.closeChannels();
} catch (error) {
    hilog.error(0x0000, 'testTag', 'closeChannels error %{public}s', JSON.stringify(error));
}
```

## Session.openBasicChannel

openBasicChannel(aid: number[]): Promise\<Channel>

Opens a basic channel, as defined in ISO/IEC 7816-4. This API uses a promise to return the result. If the SE cannot provide the basic channel or the application does not have the permission to access the SE, null is returned.

**System capability**: SystemCapability.Communication.SecureElement

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**                                                    |
| ---------- | -------- | ------ | ------------------------------------------------------------ |
| aid        | number[] | Yes     |AID of the Applet to be selected on this channel as a byte array, or an empty array if no Applet is to be selected.|

**Return value**

| **Type**| **Description**             |
| -------- | --------------------- |
| Channel  | Promise used to return the basic channel instance obtained.|

**Error codes**

For details about error codes, see [SE Error Codes](errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, an attempt is made to use an SE session that has been closed. |
| 3300102  | NoSuchElementError, the AID on the SE is not available or cannot be selected.       |
| 3300103  | SecurityError, the calling application cannot be granted access to this AID or the default applet on this session.   |
| 3300104  | IOError, there is a communication problem to the reader or the SE.     |

**Example**

```js
let seSession : secureElement.Session;
let seChannel : secureElement.Channel;
let aidArray : number[] = [0xA0, 0x00, 0x00, 0x00, 0x03, 0x10, 0x10];

// Initialize seSession before using it.
function secureElementDemo() {
    try {
        // Change the AID value for the channel to open.
        seSession.openBasicChannel(aidArray).then((data) => {
            seChannel = data;
        }).catch((error : BusinessError)=> {
            hilog.error(0x0000, 'testTag', 'openBasicChannel error %{public}s', JSON.stringify(error));
        });
    } catch (exception) {
        hilog.error(0x0000, 'testTag', 'openBasicChannel exception %{public}s', JSON.stringify(exception));
    }
    if (seChannel == undefined) {
        hilog.error(0x0000, 'testTag', 'seChannel invalid.');
        return;
    }
}
```

## Session.openBasicChannel

 openBasicChannel(aid: number[], callback: AsyncCallback\<Channel>): void

Opens a basic channel, as defined in ISO/IEC 7816-4. This API uses an asynchronous callback to return the result. If the SE cannot provide the basic channel or the application does not have the permission to access the SE, null is returned.

**System capability**: SystemCapability.Communication.SecureElement

**Parameters**

| **Name**| **Type**              | **Mandatory**| **Description**                                                    |
| ---------- | ---------------------- | ------ | ------------------------------------------------------------ |
| aid        | number[]               | Yes     | AID of the Applet to be selected on this channel as a byte array, or an empty array if no Applet is to be selected.|
| callback   | AsyncCallback\<Channel> | Yes     | Callback used to return the basic channel instance obtained.                           |

**Error codes**

For details about error codes, see [SE Error Codes](errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, an attempt is made to use an SE session that has been closed. |
| 3300102  | NoSuchElementError, the AID on the SE is not available or cannot be selected.       |
| 3300103  | SecurityError, the calling application cannot be granted access to this AID or the default applet on this session.   |
| 3300104  | IOError, there is a communication problem to the reader or the SE.     |

**Example**

```js
let seSession : secureElement.Session;
let seChannel : secureElement.Channel;
let aidArray : number[] = [0xA0, 0x00, 0x00, 0x00, 0x03, 0x10, 0x10];

// Initialize seSession before using it.
function secureElementDemo() {
    try {
        // Change the AID value for the channel to open.
        seSession.openBasicChannel(aidArray, (error, data) => {
            if (error) {
                hilog.error(0x0000, 'testTag', 'openBasicChannel error %{public}s', JSON.stringify(error));
            } else {
                seChannel = data;
            }
        });
    } catch (exception) {
        hilog.error(0x0000, 'testTag', 'openBasicChannel exception %{public}s', JSON.stringify(exception));
    }
    if (seChannel == undefined) {
        hilog.error(0x0000, 'testTag', 'seChannel invalid.');
        return;
    }
}
```

## Session.openBasicChannel

openBasicChannel(aid: number[], p2: number): Promise\<Channel>

Opens a basic channel, as defined in ISO/IEC 7816-4. This API uses a promise to return the result. If the SE cannot provide the basic channel or the application does not have the permission to access the SE, null is returned.

**System capability**: SystemCapability.Communication.SecureElement

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**                                                    |
| ---------- | -------- | ------ | ------------------------------------------------------------ |
| aid        | number[] | Yes      | AID of the Applet to be selected on this channel as a byte array, or an empty array if no Applet is to be selected.|
| p2         | number   | Yes      |P2 parameter of the **SELECT APDU** command executed on this channel.                    |

**Return value**

| **Type**| **Description**             |
| -------- | --------------------- |
| Channel  | Promise used to return the basic channel instance obtained.|

**Error codes**

For details about error codes, see [SE Error Codes](errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, an attempt is made to use an SE session that has been closed. |
| 3300102  | NoSuchElementError, the AID on the SE is not available or cannot be selected.       |
| 3300103  | SecurityError, the calling application cannot be granted access to this AID or the default applet on this session.   |
| 3300104  | IOError, there is a communication problem to the reader or the SE.     |

**Example**

```js
let seSession : secureElement.Session;
let seChannel : secureElement.Channel;
let aidArray : number[] = [0xA0, 0x00, 0x00, 0x00, 0x03, 0x10, 0x10];
let p2 : number = 0x00;

// Initialize seSession before using it.
function secureElementDemo() {
    try {
        // Change the AID value for the channel to open.
        seSession.openBasicChannel(aidArray, p2).then((data) => {
            seChannel = data;
        }).catch((error : BusinessError)=> {
            hilog.error(0x0000, 'testTag', 'openBasicChannel error %{public}s', JSON.stringify(error));
        });
    } catch (exception) {
        hilog.error(0x0000, 'testTag', 'openBasicChannel exception %{public}s', JSON.stringify(exception));
    }
    if (seChannel == undefined) {
        hilog.error(0x0000, 'testTag', 'seChannel invalid.');
        return;
    }
}
```

## Session.openBasicChannel

openBasicChannel(aid: number[], p2:number, callback: AsyncCallback\<Channel>): void

Opens a basic channel, as defined in ISO/IEC 7816-4. This API uses an asynchronous callback to return the result. If the SE cannot provide the basic channel or the application does not have the permission to access the SE, null is returned.

**System capability**: SystemCapability.Communication.SecureElement

**Parameters**

| **Name**| **Type**              | **Mandatory**| **Description**                                                    |
| ---------- | ---------------------- | ------ | ------------------------------------------------------------ |
| aid        | number[]               | Yes     | AID of the Applet to be selected on this channel as a byte array, or an empty array if no Applet is to be selected.|
| p2         | number                 | Yes     | P2 parameter of the **SELECT APDU** command executed on this channel.                    |
| callback   | AsyncCallback\<Channel> | Yes     | Callback used to return the basic channel instance obtained.                           |

**Error codes**

For details about error codes, see [SE Error Codes](errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, an attempt is made to use an SE session that has been closed. |
| 3300102  | NoSuchElementError, the AID on the SE is not available or cannot be selected.      |
| 3300103  | SecurityError, the calling application cannot be granted access to this AID or the default applet on this session.   |
| 3300104  | IOError, there is a communication problem to the reader or the SE.     |

**Example**

```js
let seSession : secureElement.Session;
let seChannel : secureElement.Channel;
let aidArray : number[] = [0xA0, 0x00, 0x00, 0x00, 0x03, 0x10, 0x10];
let p2 : number = 0x00;

// Initialize seSession before using it.
function secureElementDemo() {
    try {
        // Change the AID value for the channel to open.
        seSession.openBasicChannel(aidArray, p2, (error, data) => {
            if (error) {
                hilog.error(0x0000, 'testTag', 'openBasicChannel error %{public}s', JSON.stringify(error));
            } else {
                seChannel = data;
            }
        });
    } catch (exception) {
        hilog.error(0x0000, 'testTag', 'openBasicChannel exception %{public}s', JSON.stringify(exception));
    }
    if (seChannel == undefined) {
        hilog.error(0x0000, 'testTag', 'seChannel invalid.');
        return;
    }
}
```

## Session.openLogicalChannel

openLogicalChannel(aid: number[]): Promise\<Channel>

Opens a logical channel, as defined in ISO/IEC 7816-4. This API uses a promise to return the result. If the SE cannot provide the logical channel or the application does not have the permission to access the SE, null is returned.

**System capability**: SystemCapability.Communication.SecureElement

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**                               |
| ---------- | -------- | ------ | --------------------------------------- |
| aid        | number[] | Yes     | AID of the Applet to be selected on this channel as a byte array, or an empty array if no Applet is to be selected.|

**Return value**

| **Type**| **Description**                                                    |
| -------- | ------------------------------------------------------------ |
| Channel  | Promise used to return the logical channel instance obtained.|

**Error codes**

For details about error codes, see [SE Error Codes](errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, an attempt is made to use an SE session that has been closed. |
| 3300102  | NoSuchElementError, the AID on the SE is not available or cannot be selected.       |
| 3300103  | SecurityError, the calling application cannot be granted access to this AID or the default applet on this session.   |
| 3300104  | IOError, there is a communication problem to the reader or the SE.     |

**Example**

```js
let seSession : secureElement.Session;
let seChannel : secureElement.Channel;
let aidArray : number[] = [0xA0, 0x00, 0x00, 0x00, 0x03, 0x10, 0x10];

// Initialize seSession before using it.
function secureElementDemo() {
    try {
        // Change the AID value for the channel to open.
        seSession.openLogicalChannel(aidArray).then((data) => {
            seChannel = data;
        }).catch((error : BusinessError)=> {
            hilog.error(0x0000, 'testTag', 'openLogicalChannel error %{public}s', JSON.stringify(error));
        });
    } catch (exception) {
        hilog.error(0x0000, 'testTag', 'openLogicalChannel exception %{public}s', JSON.stringify(exception));
    }
    if (seChannel == undefined) {
        hilog.error(0x0000, 'testTag', 'seChannel invalid.');
        return;
    }
}
```

## Session.openLogicalChannel

 openLogicalChannel(aid: number[], callback: AsyncCallback\<Channel>): void

Opens a logical channel, as defined in ISO/IEC 7816-4. This API uses an asynchronous callback to return the result. If the SE cannot provide the logical channel or the application does not have the permission to access the SE, null is returned.

**System capability**: SystemCapability.Communication.SecureElement

**Parameters**

| **Name**| **Type**              | **Mandatory**| **Description**                                                    |
| ---------- | ---------------------- | ------ | ------------------------------------------------------------ |
| aid        | number[]               | Yes     | AID of the Applet to be selected on this channel as a byte array, or an empty array if no Applet is to be selected.|
| callback   | AsyncCallback\<Channel> | Yes     | Callback used to return the logical channel instance obtained.|

**Error codes**

For details about error codes, see [SE Error Codes](errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, an attempt is made to use an SE session that has been closed. |
| 3300102  | NoSuchElementError, the AID on the SE is not available or cannot be selected.      |
| 3300103  | SecurityError, the calling application cannot be granted access to this AID or the default applet on this session.   |
| 3300104  | IOError, there is a communication problem to the reader or the SE.    |

**Example**

```js
let seSession : secureElement.Session;
let seChannel : secureElement.Channel;
let aidArray : number[] = [0xA0, 0x00, 0x00, 0x00, 0x03, 0x10, 0x10];

// Initialize seSession before using it.
function secureElementDemo() {
    try {
        // Change the AID value for the channel to open.
        seSession.openLogicalChannel(aidArray, (error, data) => {
            if (error) {
                hilog.error(0x0000, 'testTag', 'openLogicalChannel error %{public}s', JSON.stringify(error));
            } else {
                seChannel = data;
            }
        });
    } catch (exception) {
        hilog.error(0x0000, 'testTag', 'openLogicalChannel exception %{public}s', JSON.stringify(exception));
    }
    if (seChannel == undefined) {
        hilog.error(0x0000, 'testTag', 'seChannel invalid.');
        return;
    }
}
```

## Session.openLogicalChannel

openLogicalChannel(aid: number[], p2: number): Promise\<Channel>

Opens a logical channel, as defined in ISO/IEC 7816-4. This API uses a promise to return the result. If the SE cannot provide the logical channel or the application does not have the permission to access the SE, null is returned.

**System capability**: SystemCapability.Communication.SecureElement

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**                                 |
| ---------- | -------- | ------ | ----------------------------------------- |
| aid        | number[] | Yes     | AID of the Applet to be selected on this channel as a byte array, or an empty array if no Applet is to be selected.|
| p2         | number   | Yes     | P2 parameter of the **SELECT APDU** command executed on this channel. |

**Return value**

| **Type**| **Description**      |
| -------- | -------------- |
| Promise\<Channel> | Promise used to return the logical channel instance obtained.|

**Error codes**

For details about error codes, see [SE Error Codes](errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, an attempt is made to use an SE session that has been closed. |
| 3300102  | NoSuchElementError, the AID on the SE is not available or cannot be selected.      |
| 3300103  | SecurityError, the calling application cannot be granted access to this AID or the default applet on this session.   |
| 3300104  | IOError, there is a communication problem to the reader or the SE.     |

**Example**

```js
let seSession : secureElement.Session;
let seChannel : secureElement.Channel;
let aidArray : number[] = [0xA0, 0x00, 0x00, 0x00, 0x03, 0x10, 0x10];
let p2 : number = 0x00;

// Initialize seSession before using it.
function secureElementDemo() {
    try {
        // Change the AID value for the channel to open.
        seSession.openLogicalChannel(aidArray, p2).then((data) => {
            seChannel = data;
        }).catch((error : BusinessError)=> {
            hilog.error(0x0000, 'testTag', 'openLogicalChannel error %{public}s', JSON.stringify(error));
        });
    } catch (exception) {
        hilog.error(0x0000, 'testTag', 'openLogicalChannel exception %{public}s', JSON.stringify(exception));
    }
    if (seChannel == undefined) {
        hilog.error(0x0000, 'testTag', 'seChannel invalid.');
        return;
    }
}
```

## Session.openLogicalChannel

openLogicalChannel(aid: number[], p2: number, callback: AsyncCallback\<Channel>):void

Opens a logical channel, as defined in ISO/IEC 7816-4. This API uses an asynchronous callback to return the result. If the SE cannot provide the logical channel or the application does not have the permission to access the SE, null is returned.

**System capability**: SystemCapability.Communication.SecureElement

**Parameters**

| **Name**| **Type**              | **Mandatory**| **Description**                                                    |
| ---------- | ---------------------- | ------ | ------------------------------------------------------------ |
| aid        | number[]               | Yes     | AID of the Applet to be selected on this channel as a byte array, or an empty array if no Applet is to be selected.|
| p2         | number                 | Yes     | P2 parameter of the **SELECT APDU** command executed on this channel.|
| callback   | AsyncCallback\<Channel> | Yes     | Callback used to return the logical channel instance obtained.|

**Error codes**

For details about error codes, see [SE Error Codes](errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, an attempt is made to use an SE session that has been closed. |
| 3300102  | NoSuchElementError, the AID on the SE is not available or cannot be selected.       |
| 3300103  | SecurityError, the calling application cannot be granted access to this AID or the default applet on this session.   |
| 3300104  | IOError, there is a communication problem to the reader or the SE.     |

**Example**

```js
let seSession : secureElement.Session;
let seChannel : secureElement.Channel;
let aidArray : number[] = [0xA0, 0x00, 0x00, 0x00, 0x03, 0x10, 0x10];
let p2 : number = 0x00;

// Initialize seSession before using it.
function secureElementDemo() {
    try {
    // Change the AID value for the channel to open.
        seSession.openLogicalChannel(aidArray, p2, (error, data) => {
            if (error) {
                hilog.error(0x0000, 'testTag', 'openLogicalChannel error %{public}s', JSON.stringify(error));
            } else {
                seChannel = data;
            }
        });
    } catch (exception) {
        hilog.error(0x0000, 'testTag', 'openLogicalChannel exception %{public}s', JSON.stringify(exception));
    }
    if (seChannel == undefined) {
        hilog.error(0x0000, 'testTag', 'seChannel invalid.');
        return;
    }
}
```

## Channel. getSession

 getSession(): Session

Obtains the session used to open this channel.

**System capability**: SystemCapability.Communication.SecureElement

**Return value**

| **Type**| **Description**                     |
| -------- | ----------------------------- |
| Session  | Session instance obtained.|

**Example**

```js
let seSession : secureElement.Session;
let seChannel : secureElement.Channel;

// Initialize seChannel before using it.

try {
    seSession = seChannel.getSession();
} catch (exception) {
    hilog.error(0x0000, 'testTag', 'getSession exception %{public}s', JSON.stringify(exception));
}
```

## Channel. close

close(): void

Closes this channel.

**System capability**: SystemCapability.Communication.SecureElement

**Example**

```js
let seChannel : secureElement.Channel;

// Initialize seChannel before using it.

try {
    seChannel.close();
} catch (exception) {
    hilog.error(0x0000, 'testTag', 'close exception %{public}s', JSON.stringify(exception));
}
```

## Channel. isBasicChannel

isBasicChannel(): boolean

Checks whether this channel is a basic channel.

**System capability**: SystemCapability.Communication.SecureElement

**Return value**

| **Type**| **Description**                                                    |
| -------- | ------------------------------------------------------------ |
| boolean  | Returns **true** if the channel is a basic channel; returns **false** otherwise.|

**Example**

```js
let seChannel : secureElement.Channel;

// Initialize seChannel before using it.

try {
    let isBasic = seChannel.isBasicChannel();
    hilog.info(0x0000, 'testTag', 'isBasic = %{public}s', JSON.stringify(isBasic));
} catch (exception) {
    hilog.error(0x0000, 'testTag', 'isBasicChannel exception %{public}s', JSON.stringify(exception));
}
```

## Channel. isClosed

isClosed(): boolean

Checks whether this channel is closed.

**System capability**: SystemCapability.Communication.SecureElement

**Return value**

| **Type**| **Description**                                     |
| -------- | --------------------------------------------- |
| boolean  | Returns **true** if the channel is closed; returns **false** otherwise.|

**Example**

```js
let seChannel : secureElement.Channel;

// Initialize seChannel before using it.

try {
    let isClosed = seChannel.isClosed();
    hilog.info(0x0000, 'testTag', 'isClosed = %{public}s', JSON.stringify(isClosed));
} catch (exception) {
    hilog.error(0x0000, 'testTag', 'isClosed exception %{public}s', JSON.stringify(exception));
}
```

## Channel. getSelectResponse

getSelectResponse(): number[]

Obtains the response data including the status word of **SELECT Applet**.

**System capability**: SystemCapability.Communication.SecureElement

**Return value**

| **Type**| **Description**                                                    |
| -------- | ------------------------------------------------------------ |
| number[] | Response data including the status word obtained.|

**Error codes**

For details about error codes, see [SE Error Codes](errorcode-se.md).

**Example**

```js
let seChannel : secureElement.Channel;

// Initialize seChannel before using it.

try {
    let response = seChannel.getSelectResponse();
    hilog.info(0x0000, 'testTag', 'response = %{public}s', JSON.stringify(response));
} catch (exception) {
    hilog.error(0x0000, 'testTag', 'getSelectResponse exception %{public}s', JSON.stringify(exception));
}
```

## Channel. transmit

transmit(command: number[]): Promise\<number[]>

Transmits APDU data (as per ISO/IEC 7816) to the SE.

**System capability**: SystemCapability.Communication.SecureElement

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**                             |
| ---------- | -------- | ------ | ------------------------------------- |
| command    | number[] | Yes     | APDU data to send.|

**Return value**

| **Type**| **Description**      |
| -------- | -------------- |
| number[] | Promise used to return the response received, in a number array.|

**Error codes**

For details about error codes, see [SE Error Codes](errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, an attempt is made to use an SE session or channel that has been closed. |
| 3300103  | SecurityError, the command is filtered by the security policy. |
| 3300104  | IOError, there is a communication problem to the reader or the SE.     |

**Example**

```js
let seChannel : secureElement.Channel;

// Initialize seChannel before using it.

let cmdData = [0x01, 0x02, 0x03, 0x04]; // Change the raw data as required.
try {
    seChannel.transmit(cmdData).then((response) => {
        hilog.info(0x0000, 'testTag', 'transmit response = %{public}s.', JSON.stringify(response));
    }).catch((error : BusinessError) => {
        hilog.error(0x0000, 'testTag', 'transmit error = %{public}s.', JSON.stringify(error));
    });
} catch (exception) {
    hilog.error(0x0000, 'testTag', 'transmit exception = %{public}s.', JSON.stringify(exception));
}
```

## Channel. transmit

transmit(command: number[], callback: AsyncCallback\<number[]>): void

Transmits APDU data (as per ISO/IEC 7816) to the SE.

**System capability**: SystemCapability.Communication.SecureElement

**Parameters**

| **Name**| **Type**               | **Mandatory**| **Description**                             |
| ---------- | ----------------------- | ------ | ------------------------------------- |
| command    | number[]                | Yes     | APDU data to send.|
| callback   | AsyncCallback\<number[]> | Yes     | Callback used to return the response received, in a number array. |

**Error codes**

For details about error codes, see [SE Error Codes](errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, an attempt is made to use an SE session or channel that has been closed. |
| 3300103  | SecurityError, the command is filtered by the security policy. |
| 3300104  | IOError, there is a communication problem to the reader or the SE.     |

**Example**

```js
let seChannel : secureElement.Channel;

// Initialize seChannel before using it.

let cmdData = [0x01, 0x02, 0x03, 0x04]; // Change the raw data as required.
try {
    seChannel.transmit(cmdData, (error, response) => {
    if (error) {
        hilog.error(0x0000, 'testTag', 'transmit error %{public}s', JSON.stringify(error));
    } else {
        hilog.info(0x0000, 'testTag', 'transmit response = %{public}s.', JSON.stringify(response));
    }
    });
} catch (exception) {
    hilog.error(0x0000, 'testTag', 'transmit exception %{public}s', JSON.stringify(exception));
}
```
