# @ohos.secureElement (SE Management)

The **secureElement** module provides APIs for operating and managing the SecureElement (SE). The SE service mentioned in this document is an **SEService** instance. For details, see [newSEService](#secureelementnewseservice).

The instances of the following classes are involved in this document.

| Class   | Description                                          |
| ------- | ---------------------------------------------- |
| Session | A **Session** instance represents a session for connecting to an available SE on the device.|
| Reader  | A **Reader** instance represents an SE reader supported by the device.         |
| Channel | A **Channel** instance represents an ISO/IEC 7816-4 channel opened to the SE.  |

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## **Modules to Import**

```js
import secureElement from '@ohos.secureElement';
```

## secureElement.ServiceState

Defines the SE service status values.

**System capability**: SystemCapability.Communication.SecureElement

| Name        | Value  | Description              |
| ------------ | ---- | ------------------ |
| DISCONNECTED | 0    | The SE service is disconnected.|
| CONNECTED    | 1    | The SE service is connected.|

## secureElement.newSEService

newSEService(type: 'serviceState', callback: Callback<[ServiceState](#secureelementservicestate)>): SEService

Creates an **SEService** instance for connecting to all available SEs in the system. The connection is time-consuming. Therefore, this API supports only the asynchronous mode.

The returned **SEService** object is available only when **true** is returned by the specified callback or [isConnected](#seserviceisconnected).

**System capability**: SystemCapability.Communication.SecureElement

**Parameters**

| **Name**| **Type**                                            | **Description**            |
| ---------- | ---------------------------------------------------- | -------------------- |
| type       | string                                               | 'serviceState'       |
| callback   | Callback<[ServiceState](#secureelementservicestate)> | Callback invoked to return the SE service status.|

**Return value**

| **Type** | **Description**  |
| :-------- | :--------- |
| SEService | Returns the **SEService** instance created.|

**Example**

```js
import secureElement from '@ohos.secureElement';

@State result: string = '';
@State nfcSEService: secureElement.SEService = null;

this.result = "Service state is Unkown";
try {
    this.nfcSEService = secureElement.newSEService("serviceState", (state) => {
        if (state == secureElement.ServiceState.DISCONNECTED) {
            this.result = "Service state is Disconnected";
        } else {
            this.result = "Service state is Connected";
        }
    });
} catch (e) {
    this.result = "newSEService occurs exception:" + e.message;
}
```

## SEService.getReaders

getReaders(): Reader[]

Obtains the available SE readers. The returned array cannot contain duplicate objects. Even if no card is inserted, all available readers should be listed.

**System capability**: SystemCapability.Communication.SecureElement

**Return value**

| **Type**| **Description**              |
| :------- | :--------------------- |
| Reader[] | Returns an array of available **Reader** objects.|

**Example**

```js
import secureElement from '@ohos.secureElement';

@State result: string = '';
@State nfcSEService: secureElement.SEService = null;
@State nfcServiceState: secureElement.ServiceState = null;
@State nfcOmaReader: secureElement.Reader = null;
@State nfcOmaReaderList: secureElement.Reader[] = null;

// get SEService
try {
    this.nfcSEService = secureElement.newSEService("serviceState", (state) => {
        if (state == secureElement.ServiceState.DISCONNECTED) {
            this.result = "Service state is Disconnected";
        } else {
            this.result = "Service state is Connected";
        }
    });
} catch (e) {
    this.result = "newSEService excpetion:" + e.message;
}

try {
    this.nfcOmaReaderList = this.nfcSEService.getReaders();
    if (this.nfcOmaReaderList != null && this.nfcOmaReaderList.length > 0) {
        this.nfcOmaReader = this.nfcOmaReaderList[0];
        this.result = "get reader successfully";
    } else {
        this.result = "get reader failed";
    }
} catch (e) {
    this.result = "getReaders exception:" + e.message;
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

@State result: string = ''
@State nfcSEService: secureElement.SEService = null;

try {
    let ret: boolean;
    // refer to newSEService for this.nfcSEService 
    ret = this.nfcSEService.isConnected();
    if (ret) {
        this.result = 'get state: connected';
    } else {
        this.result = 'get state: not connected';
    }
} catch (e) {
    this.result = "isConnected exception: " + e.message;
}
```

## SEService.shutdown

shutdown(): void

Releases all SE resources allocated to this service. After that, [isConnected](#seserviceisconnected) returns **false**.

**System capability**: SystemCapability.Communication.SecureElement

**Example**

```js
import secureElement from '@ohos.secureElement';

@State result: string = '';
@State nfcSEService: secureElement.SEService = null;

try {
    // refer to newSEService for this.nfcSEService 
    this.nfcSEService.shutdown();
    this.result = "shutdown successfully";
} catch (e) {
    this.result = "shutdown exception:" + e.message;
}
```

## SEService.getVersion

getVersion(): string

Obtains the version of the Open Mobile API Specification used for the implementation.

**System capability**: SystemCapability.Communication.SecureElement

**Return value**

| **Type**| **Description**                                          |
| -------- | -------------------------------------------------- |
| string   | Returns the OMA version. For example, **3.3** indicates Open Mobile API Specification v3.3.|

**Example**

```JS
import secureElement from '@ohos.secureElement';

@State result: string = '';
@State nfcSEService: secureElement.SEService = null;

this.result = "version: "
try {
    // refer to newSEService for this.nfcSEService 
    this.result += this.nfcSEService.getVersion();
} catch (e) {
    this.result = "getVersion exception:" + e.message;
}
```

## Reader.getName

getName(): string

Obtains the reader name. If the card reader is a SIM reader, its name must be in **SIM[Slot]** format. If the card reader is an embedded SE reader, its name must be in **eSE[slot]** format.

**System capability**: SystemCapability.Communication.SecureElement

**Return value**

| **Type**| **Description**  |
| -------- | ---------- |
| string   | Returns the reader name obtained.|

**Example**

```js
import secureElement from '@ohos.secureElement';

@State result: string = '';
@State nfcOmaReader: secureElement.Reader = null;

try {
    // refer to SEService.getReaders for this.nfcOmaReader 
    this.result = this.nfcOmaReader.getName();
} catch (e) {
    this.result = "getName exception:" + e.message;
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

For details about error codes, see [SE Error Codes](../errorcodes/errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | Illegal service state exception. |

**Example**

```js
import secureElement from '@ohos.secureElement';

@State result: string = '';
@State nfcOmaReader: secureElement.Reader = null;

try {
    // refer to SEService.getReaders for this.nfcOmaReader
    if (this.nfcOmaReader.isSecureElementPresent()) {
        this.result = "isSecureElementPresent TRUE";
    } else {
        this.result = "isSecureElementPresent FALSE";
    }
} catch (e) {
    this.result = "isSecureElementPresent exception:" + e.message;
}
```

## Reader.openSession

 openSession(): Session

Connects to the SE of this reader. This API initializes the SE for communication before returning the session object. Multiple sessions may be opened on a reader at the same time.

**System capability**: SystemCapability.Communication.SecureElement

**Return value**

| **Type**| **Description**                      |
| -------- | ------------------------------ |
| Session  | Returns the **Session** object used to create a channel.|

**Error codes**

For details about error codes, see [SE Error Codes](../errorcodes/errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | Illegal service state exception. |
| 3300104  | Secure element IO exception.     |

**Example**

```js
import secureElement from '@ohos.secureElement';

@State result: string = '';
@State nfcOmaReader: secureElement.Reader = null;
@State nfcOmaSession: secureElement.Session = null;

try {
    // refer to SEService.getReaders for this.nfcOmaReader
    this.nfcOmaSession = this.nfcOmaReader.openSession();
    if (this.nfcOmaSession) {
        this.result = "get session successfully";
    } else {
        this.result = "get session failed";
    }
} catch (e) {
    this.result = "OpenSession exception: " + e.message;
}
```

## Reader.closeSessions

 closeSessions(): void

Closes all sessions opened on this reader. This API closes all channels opened by these sessions.

**System capability**: SystemCapability.Communication.SecureElement

**Error codes**

For details about error codes, see [SE Error Codes](../errorcodes/errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | Illegal service state exception. |

**Example**

```js
import secureElement from '@ohos.secureElement';

@State result: string = '';
@State nfcOmaReader: secureElement.Reader = null;

try {
    // refer to SEService.getReaders for this.nfcOmaReader
    this.nfcOmaReader.closeSessions();
    this.result = "close Sessions successfully";
} catch (e) {
    this.result = "closeSessions exception:" + e.message;
}
```

## Session.getReader

getReader(): Reader

Obtains the reader that provides this session.

**System capability**: SystemCapability.Communication.SecureElement

**Return value**

| **Type**| **Description**                   |
| -------- | --------------------------- |
| Reader   | Returns the **Reader** object obtained.|

**Example**

```js
import secureElement from '@ohos.secureElement';

@State result: string = '';
@State nfcOmaReader: secureElement.Reader = null;
@State nfcOmaSession: secureElement.Session = null;

try {
    // refer to Reader.openSession for this.nfcOmaSession
    this.nfcOmaReader = this.nfcOmaSession.getReader();
    if (this.nfcOmaReader) {
        this.result = "get reader successfully";
    } else {
        this.result = "get reader failed";
    }
} catch (e) {
    this.result = "getReader exception:" + e.message;
}
```

## Session.getATR

getATR(): number[]

Obtains the ATR of this SE. If the ATR of this SE is not available, an empty array will be returned.

**System capability**: SystemCapability.Communication.SecureElement

**Return value**

| **Type**| **Description**                                    |
| -------- | -------------------------------------------- |
| number[] | Returns the ATR obtained if the SE has an available ATR; returns an empty array otherwise.|

**Error codes**

For details about error codes, see [SE Error Codes](../errorcodes/errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | Illegal service state exception. |

**Example**

```js
import secureElement from '@ohos.secureElement';

@State result: string = '';
@State nfcOmaSession: secureElement.Session = null;

try {
    // refer to Reader.openSession for this.nfcOmaSession
    let ret = this.nfcOmaSession.getATR();
    if (ret) {
        this.result = "getATR result:[";
        for (let i = 0; i < ret.length; ++i) {
            this.result += ret[i];
            this.result += ' ';
        }
        this.result += ']';
    } else {
        this.result = "getATR result is null";
    }
} catch (e) {
    this.result = "getATR exception:" + e.message;
}
```

## Session.close

close(): void

Closes the connection with this SE. This API closes all channels opened between this application and the SE.

**System capability**: SystemCapability.Communication.SecureElement

**Error codes**

For details about error codes, see [SE Error Codes](../errorcodes/errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | Illegal service state exception. |

**Example**

```js
import secureElement from '@ohos.secureElement';

@State result: string = '';
@State nfcOmaSession: secureElement.Session = null;

try {
    // refer to Reader.openSession for this.nfcOmaSession
    this.nfcOmaSession.close();
    this.result = "session close successfully";
} catch (e) {
    this.result = "session close exception:" + e.message;
}
```

## Session. isClosed

isClosed(): boolean

Checks whether the session is closed.

**System capability**: SystemCapability.Communication.SecureElement

**Return value**

| **Type**| **Description**                            |
| -------- | ------------------------------------ |
| boolean  | Returns **true** if the session is closed; returns **false** otherwise.|

**Error codes**

For details about error codes, see [SE Error Codes](../errorcodes/errorcode-se.md).

**Example**

```Js
import secureElement from '@ohos.secureElement';

@State result: string = '';
@State nfcOmaSession: secureElement.Session = null;

try {
    // refer to Reader.openSession for this.nfcOmaSession
    let ret = this.nfcOmaSession.isClosed();
    if (ret) {
        this.result = "session state is closed";
    } else {
        this.result = "session state is not closed";
    }
} catch (e) {
    this.result = "isClosed exception:" + e.message;
}
```

## Session.closeChannels

closeChannels(): void

Closes all channels opened in this session.

**System capability**: SystemCapability.Communication.SecureElement

**Error codes**

For details about error codes, see [SE Error Codes](../errorcodes/errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | Illegal service state exception. |

**Example**

```js
import secureElement from '@ohos.secureElement';

@State result: string = '';
@State nfcOmaSession: secureElement.Session = null;

try {
    // refer to Reader.openSession for this.nfcOmaSession
    this.nfcOmaSession.closeChannels();
    this.result = "close Channels successfully";
} catch (e) {
    this.result = "closeChannels exception:" + e.message;
}
```

## Session.openBasicChannel

openBasicChannel(aid: number[]): Promise<Channel>

Opens a basic channel. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.SecureElement

**Parameters**

| **Name**| **Type**| **Description**                                                    |
| ---------- | -------- | ------------------------------------------------------------ |
| aid        | number[] | AIDs of the applets selected on this channel or null if no applet is selected. |

**Return value**

| **Type**| **Description**             |
| -------- | --------------------- |
| Channel  | Returns the **Channel** instance opened. If the SE cannot provide a new basic channel or cannot obtain the access control rule due to lack of available basic channels, null will be returned. |

**Error codes**

For details about error codes, see [SE Error Codes](../errorcodes/errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | Illegal service state exception. |
| 3300102  | No such element exception.       |
| 3300103  | Illegal access rule exception.   |
| 3300104  | Secure element IO exception.     |

**Example**

```js
import secureElement from '@ohos.secureElement';

@State result: string = '';
@State nfcOmaSession: secureElement.Session = null;
@State nfcOmaChannel: secureElement.Channel = null;

try {
    // See Reader.openSession for this.nfcOmaSession.
    let getPromise = this.nfcOmaSession.openBasicChannel(this.aidArray);
    getPromise.then((channel) => {
        this.nfcOmaChannel = channel;
        this.result = "openBasicChannel1 get channel successfully";
    }).catch ((err) => {
        this.result = "openBasicChannel1 exception:" + err.message;
    });
} catch (e) {
    this.result = "OpenBasicChannel1 exception:" + e.message;
}
```

## Session.openBasicChannel

 openBasicChannel(aid: number[], callback: AsyncCallback<Channel>): void

Opens a basic channel. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.SecureElement

**Parameters**

| **Name**| **Type**              | **Description**                                                    |
| ---------- | ---------------------- | ------------------------------------------------------------ |
| aid        | number[]               | AIDs of the applets selected on this channel or null if no applet is selected. |
| callback   | AsyncCallback<Channel> | Callback invoked to return the **Channel** instance opened. If the SE cannot provide a new basic channel or cannot obtain the access control rule due to lack of available basic channels, null will be returned.                 |

**Error codes**

For details about error codes, see [SE Error Codes](../errorcodes/errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | Illegal service state exception. |
| 3300102  | No such element exception.       |
| 3300103  | Illegal access rule exception.   |
| 3300104  | Secure element IO exception.     |

**Example**

```js
import secureElement from '@ohos.secureElement';

@State result: string = '';
@State nfcOmaSession: secureElement.Session = null;
@State nfcOmaChannel: secureElement.Channel = null;
aidArray: number[] = [720, 1080];

try {
    // See Reader.openSession for this.nfcOmaSession.
    this.nfcOmaSession.openBasicChannel(this.aidArray, (error, data) => {
        if (error) {
            this.result = "openBasicChannel2 failed:" + JSON.stringify(error);
            return;
        }
        this.nfcOmaChannel = data;
        this.result = "openBasicChannel2 get channel successfully";
    });
} catch (e) {
    this.result = "openBasicChannel2 exception:" + e.message;
}
```

## Session.openBasicChannel

openBasicChannel(aid: number[], p2: number): Promise<Channel>

Opens a basic channel. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.SecureElement

**Parameters**

| **Name**| **Type**| **Description**                                                    |
| ---------- | -------- | ------------------------------------------------------------ |
| aid        | number[] | AIDs of the applets selected on this channel or null if no applet is selected. |
| p2         | number   | P2 parameter of the **SELECT APDU** command executed on the channel.                    |

**Return value**

| **Type**| **Description**             |
| -------- | --------------------- |
| Channel  | Returns the **Channel** instance opened. If the SE cannot provide a new basic channel or cannot obtain the access control rule due to lack of available basic channels, null will be returned. |

**Error codes**

For details about error codes, see [SE Error Codes](../errorcodes/errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | Illegal service state exception. |
| 3300102  | No such element exception.       |
| 3300103  | Illegal access rule exception.   |
| 3300104  | Secure element IO exception.     |

**Example**

```js
import secureElement from '@ohos.secureElement';

@State result: string = '';
@State nfcOmaSession: secureElement.Session = null;
@State nfcOmaChannel: secureElement.Channel = null;
aidArray: number[] = [720, 1080];
p2: number = 0x00;

try {
    // See Reader.openSession for this.nfcOmaSession.
    let getPromise = this.nfcOmaSession.openBasicChannel(this.aidArray, this.p2);
    getPromise.then((channel) => {
        this.nfcOmaChannel = channel;
        this.result = "openBasicChannel3 get channel successfully";
    }).catch ((err) => {
        this.result = "openBasicChannel3 exception";
    });
} catch (e) {
    this.result = "openBasicChannel3 exception:" + e.message;
}
```

## Session.openBasicChannel

openBasicChannel(aid: number[], p2:number, callback: AsyncCallback<Channel>): void

Opens a basic channel. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.SecureElement

**Parameters**

| **Name**| **Type**              | **Description**                                                    |
| ---------- | ---------------------- | ------------------------------------------------------------ |
| aid        | number[]               | AIDs of the applets selected on this channel or null if no applet is selected. |
| p2         | number                 | P2 parameter of the **SELECT APDU** command executed on the channel.                    |
| callback   | AsyncCallback<Channel> | Callback invoked to return the **Channel** instance opened. If the SE cannot provide a new basic channel or cannot obtain the access control rule due to lack of available basic channels, null will be returned.                 |

**Error codes**

For details about error codes, see [SE Error Codes](../errorcodes/errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | Illegal service state exception. |
| 3300102  | No such element exception.       |
| 3300103  | Illegal access rule exception.   |
| 3300104  | Secure element IO exception.     |

**Example**

```js
import secureElement from '@ohos.secureElement';

@State result: string = '';
@State nfcOmaSession: secureElement.Session = null;
@State nfcOmaChannel: secureElement.Channel = null;
aidArray: number[] = [720, 1080];
p2: number = 0x00;

try {
    // See Reader.openSession for this.nfcOmaSession.
    this.nfcOmaSession.openBasicChannel(this.aidArray, this.p2, (error, data) => {
        if (error) {
            this.result = "openBasicChannel4 failed:" + JSON.stringify(error);
            return;
        }
        this.nfcOmaChannel = data;
        this.result = "openBasicChannel4 get channel successfully";
    });
} catch (e) {
    this.result = "openBasicChannel4 exception:" + e.message;
}
```

## Session.openLogicalChannel

openLogicalChannel(aid: number[]): Promise<Channel>

Opens a logical channel. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.SecureElement

**Parameters**

| **Name**| **Type**| **Description**                               |
| ---------- | -------- | --------------------------------------- |
| aid        | number[] | AIDs of the applets selected on the **Channel** instance. |

**Return value**

| **Type**| **Description**                                                    |
| -------- | ------------------------------------------------------------ |
| Channel  | Returns the **Channel** instance opened. If the SE cannot provide a new **Channel** instance or cannot obtain access control rules due to lack of available logical **Channel** instances, null will be returned.|

**Error codes**

For details about error codes, see [SE Error Codes](../errorcodes/errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | Illegal service state exception. |
| 3300102  | No such element exception.       |
| 3300103  | Illegal access rule exception.   |
| 3300104  | Secure element IO exception.     |

**Example**

```js
import secureElement from '@ohos.secureElement';

@State result: string = '';
@State nfcOmaSession: secureElement.Session = null;
@State nfcOmaChannel: secureElement.Channel = null;
aidArray: number[] = [720, 1080];

try {
    // See Reader.openSession for this.nfcOmaSession.
    let getPromise = this.nfcOmaSession.openLogicalChannel(this.aidArray)
    getPromise.then((channel) => {
        this.nfcOmaChannel = channel;
   	    this.result = "openLogicChannel1 get channel successfully";
    }).catch ((err) => {
        this.result = "openLogicChannel1 exception:" + err.message;
    });
} catch (e) {
    this.result = "openLogicChannel1 exception:" + e.message;
}
```

## Session.openLogicalChannel

 openLogicalChannel(aid:number[], callback: AsyncCallback<Channel>): void

Opens a logical channel. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.SecureElement

**Parameters**

| **Name**| **Type**              | **Description**                                                    |
| ---------- | ---------------------- | ------------------------------------------------------------ |
| aid        | number[]               | AIDs of the applets selected on the **Channel** instance.                 |
| callback   | AsyncCallback<Channel> | Callback invoked to return the **Channel** instance opened. If the SE cannot provide a new **Channel** instance or cannot obtain access control rules due to lack of available logical **Channel** instances, null will be returned.|

**Error codes**

For details about error codes, see [SE Error Codes](../errorcodes/errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | Illegal service state exception. |
| 3300102  | No such element exception.       |
| 3300103  | Illegal access rule exception.   |
| 3300104  | Secure element IO exception.     |

**Example**

```js
import secureElement from '@ohos.secureElement';

@State result: string = '';
@State nfcOmaSession: secureElement.Session = null;
@State nfcOmaChannel: secureElement.Channel = null;
aidArray: number[] = [720, 1080];

try {
    // See Reader.openSession for this.nfcOmaSession.
    this.nfcOmaSession.openLogicalChannel(this.aidArray, (error, data) => {
        if (error) {
            this.result = "openLogicChannel2 failed:" + JSON.stringify(error);
            return;
        }
        this.nfcOmaChannel = data;
        this.result = "openLogicChannel2 get channel successfully";
    });
} catch (e) {
    this.result = "openLogicChannel2 exception:" + e.message;
}
```

## Session.openLogicalChannel

openLogicalChannel(aid: number[], p2: number): Promise<Channel>

Opens a logical channel with the applet represented by the given AID (the AID is not null and the length is not 0).

If the AID length is 0, this API sends a **select** command with the AID length of 0 (as per [GPCS]) to select the Issuer Security Domain of the SE.

If the AID is null, this API sends the **MANAGE CHANNEL Open** only. In this case, the default applet associated with the logical channel is selected.

**P2** is usually **0x00**. The device shall allow any value of **P2** and the following values: **0x00**, **0x04**, **0x08**, **0x0C** as defined in [ISO 7816-4](https://www.iso.org/standard/77180.html).

**System capability**: SystemCapability.Communication.SecureElement

**Parameters**

| **Name**| **Type**| **Description**                                 |
| ---------- | -------- | ----------------------------------------- |
| aid        | number[] | AIDs of the applets selected on the **Channel** instance. |
| p2         | number   | P2 parameter of the **SELECT APDU** command executed on the channel. |

**Error codes**

For details about error codes, see [SE Error Codes](../errorcodes/errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | Illegal service state exception. |
| 3300102  | No such element exception.       |
| 3300103  | Illegal access rule exception.   |
| 3300104  | Secure element IO exception.     |

**Example**

```js
import secureElement from '@ohos.secureElement';

@State result: string = '';
@State nfcOmaSession: secureElement.Session = null;
@State nfcOmaChannel: secureElement.Channel = null;
aidArray: number[] = [720, 1080];
p2: number = 0x00;

if (this.nfcOmaSession) {
    try {
    // See Reader.openSession for this.nfcOmaSession.
        let getPromise = this.nfcOmaSession.openLogicalChannel(this.aidArray, this.p2);
        getPromise.then((channel) => {
            this.nfcOmaChannel = channel;
            this.result = "openLogicChannel3 get channel successfully";
        }).catch ((err) => {
            this.result = "openLogicChannel3 exception";
        })
} catch (e) {
    this.result = "openLogicChannel3 exception:" + e.message;
}
```

## Session.openLogicalChannel

openLogicalChannel(aid: number[], p2: number, callback: AsyncCallback<Channel>):void

Opens a logical channel with the applet represented by the given AID (the AID is not null and the length is not 0).

If the AID length is 0, this API sends a **select** command with the AID length of 0 (as per [GPCS]) to select the Issuer Security Domain of the SE.

If the AID is null, this API sends the **MANAGE CHANNEL Open** only. In this case, the default applet associated with the logical channel is selected.

**P2** is usually **0x00**. The device shall allow any value of **P2** and the following values: **0x00**, **0x04**, **0x08**, **0x0C** as defined in [ISO 7816-4](https://www.iso.org/standard/77180.html).

**System capability**: SystemCapability.Communication.SecureElement

**Parameters**

| **Name**| **Type**              | **Description**                                                    |
| ---------- | ---------------------- | ------------------------------------------------------------ |
| aid        | number[]               | AIDs of the applets selected on the **Channel** instance.                 |
| p2         | number                 | P2 parameter of the **SELECT APDU** command executed on the channel.                    |
| callback   | AsyncCallback<Channel> | Callback invoked to return the **Channel** instance opened. If the SE cannot provide a new **Channel** instance or cannot obtain access control rules due to lack of available logical **Channel** instances, null will be returned.|

**Error codes**

For details about error codes, see [SE Error Codes](../errorcodes/errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | Illegal service state exception. |
| 3300102  | No such element exception.       |
| 3300103  | Illegal access rule exception.   |
| 3300104  | Secure element IO exception.     |

**Example**

```js
import secureElement from '@ohos.secureElement';

@State result: string = '';
@State nfcOmaSession: secureElement.Session = null;
@State nfcOmaChannel: secureElement.Channel = null;
aidArray: number[] = [720, 1080];
p2: number = 0x00;

try {
    // See Reader.openSession for this.nfcOmaSession.
    this.nfcOmaSession.openLogicalChannel(this.aidArray, this.p2, (error, data) => {
        if (error) {
            this.result = "openLogicChannel4 failed:" + JSON.stringify(error);
            return;
        }
        this.nfcOmaChannel = data;
        this.result = "openLogicChannel4 get channel successfully";
    })
} catch (e) {
    this.result = "openLogicChannel4 exception:" + e.message;
}
```

## Channel. getSession

 getSession(): Session

Obtains the session that opens this channel.

**System capability**: SystemCapability.Communication.SecureElement

**Return value**

| **Type**| **Description**                     |
| -------- | ----------------------------- |
| Session  | Returns the session obtained.|

**Example**

```js
import secureElement from '@ohos.secureElement';

@State result: string = '';
@State nfcOmaSession: secureElement.Session = null;
@State nfcOmaChannel: secureElement.Channel = null;

try {
    // See Session.openBasicChannel for this.nfcOmaChannel.
    let ret = this.nfcOmaChannel.getSession();
    if (ret) {
        this.result = "get session successfully";
    } else {
        this.result = "get session failed";
    }
} catch (e) {
    this.result = "getSession exception:" + e.message;
}
```

## Channel. close

close(): void

Closes the channel of the SE.

**System capability**: SystemCapability.Communication.SecureElement

**Example**

```js
import secureElement from '@ohos.secureElement';

@State result: string = '';
@State nfcOmaSession: secureElement.Session = null;
@State nfcOmaChannel: secureElement.Channel = null;

try {
    // See Session.openBasicChannel for this.nfcOmaChannel.
    this.nfcOmaChannel.close();
    this.result = "channel close successfully";
} catch (e) {
    this.result = "channel close exception:" + e.message;
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
import secureElement from '@ohos.secureElement';

@State result: string = '';
@State nfcOmaChannel: secureElement.Channel = null;

try {
    // See Session.openBasicChannel for this.nfcOmaChannel.
    let ret = this.nfcOmaChannel.isBasicChannel();
    if (ret) {
        this.result = "isBasicChannel TRUE";
    } else {
        this.result = "isBasicChannel FALSE";
    }
} catch (e) {
    this.result = "isBasicChannel Exception: "+ e.message;
}
```

## Channel. isClosed

isClosed(): boolean

Checks whether this channel is closed.

**System capability**: SystemCapability.Communication.SecureElement

**Return value**

| **Type**| **Description**                                     |
| -------- | --------------------------------------------- |
| boolean  | Returns **true** if this channel is closed; returns **false** otherwise.|

**Example**

```js
import secureElement from '@ohos.secureElement';

@State result: string = '';
@State nfcOmaChannel: secureElement.Channel = null;

try {
    // See Session.openBasicChannel for this.nfcOmaChannel.
    let ret = this.nfcOmaChannel.isClosed();
    if (ret) {
        this.result = "channel isClosed TRUE";
    } else {
        this.result = "channel isClosed False";
    }
} catch (e) {
    this.result = "Channel isClosed exception:" + e.message;
}
```

## Channel. getSelectResponse

getSelectResponse():number[]

Obtains the data as received from the application **select** command, including the status word received when the applet is selected.

**System capability**: SystemCapability.Communication.SecureElement

**Return value**

| **Type**| **Description**                                                    |
| -------- | ------------------------------------------------------------ |
| number[] | Returns the data obtained.|

**Error codes**

For details about error codes, see [SE Error Codes](../errorcodes/errorcode-se.md).

**Example**

```js
import secureElement from '@ohos.secureElement';

@State result: string = '';
@State nfcOmaChannel: secureElement.Channel = null;

try {
    // See Session.openBasicChannel for this.nfcOmaChannel.
    let ret = this.nfcOmaChannel.getSelectResponse();
    if (ret) {
        this.result = "getSelectResponse result:[";
        for (let i = 0; i < ret.length; ++i) {
            this.result += ret[i];
            this.result += ' ';
        }
        this.result += ']';
    } else {
        this.result = "getSelectResponse result is null";
    }
} catch (e) {
    this.result = "getSelectResponse exception:" + e.message;
}
```

## Channel. transmit

transmit(command: number[]): Promise<number[]>

Transmits the **APDU** command to the SE (according to ISO/IEC 7816). This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.SecureElement

**Parameters**

| **Name**| **Type**| **Description**                             |
| ---------- | -------- | ------------------------------------- |
| command    | number[] | AIDs of the applets selected on the channel. |

**Return value**

| **Type**| **Description**      |
| -------- | -------------- |
| number[] | Returns the response obtained.|

**Error codes**

For details about error codes, see [SE Error Codes](../errorcodes/errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | Illegal service state exception. |
| 3300103  | Illegal access rule exception.   |
| 3300104  | Secure element IO exception.     |

**Example**

```js
import secureElement from '@ohos.secureElement';

@State result: string = '';
@State nfcOmaChannel: secureElement.Channel = null;

try {
    let command: number[] = [100, 200];
    // See Session.openBasicChannel for this.nfcOmaChannel.
    let getPromise = this.nfcOmaChannel.transmit(command);
    getPromise.then((data) => {
        this.result = "transmit1 result:[";
        for (let i = 0; i < data.length; ++i) {
            this.result += data[i];
            this.result += " ";
        }
        this.result += "]";
    }).catch ((err) => {
        this.result = "transmit1 exception:" + err.code;
    })
} catch (e) {
    this.result = "transit1 exception:" + e.message;
}
```

## Channel. transmit

transmit(command: number[], callback: AsyncCallback<number[]>): void

Transmits the **APDU** command to the SE (according to ISO/IEC 7816). This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.SecureElement

**Parameters**

| **Name**| **Type**               | **Description**                             |
| ---------- | ----------------------- | ------------------------------------- |
| command    | number[]                | AIDs of the applets selected on the channel. |
| callback   | AsyncCallback<number[]> | Callback invoked to return the result. |

**Error codes**

For details about error codes, see [SE Error Codes](../errorcodes/errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | Illegal service state exception. |
| 3300103  | Illegal access rule exception.   |
| 3300104  | Secure element IO exception.     |

**Example**

```js
import secureElement from '@ohos.secureElement';

@State result: string = '';
@State nfcOmaChannel: secureElement.Channel = null;

try {
    let command: number[] = [100, 200];
    // See Session.openBasicChannel for this.nfcOmaChannel.
    this.nfcOmaChannel.transmit(command, (error, data) => {
        if (error) {
            this.result = "transmit2 exception:" + JSON.stringify(error);
            return;
        }
        this.result = "transmit2 result:[";
        for (let i = 0; i < data.length; ++i) {
            this.result += data[i];
            this.result += " ";
        }
        this.result += "]";
    });
} catch (e) {
    this.result = "transit2 exception:" + e.message;
}
```
