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

| **Name**| **Type**                                            | **Mandatory**| **Description**            |
| ---------- | ---------------------------------------------------- | ------ | -------------------- |
| type       | string                                               | Yes     | 'serviceState'       |
| callback   | Callback<[ServiceState](#secureelementservicestate)> | Yes     | Callback invoked to return the SE service status.|

**Return value**

| **Type** | **Description**  |
| :-------- | :--------- |
| SEService | Returns the **SEService** instance created.|

**Example**

```js
import secureElement from '@ohos.secureElement';
import { BusinessError } from '@ohos.base';

try {
    let nfcSEService = secureElement.newSEService("serviceState", (state) => {
        if (state == secureElement.ServiceState.DISCONNECTED) {
            console.log("Service state is Disconnected");
        } else {
            console.log("Service state is Connected");
        }
    });
} catch (e) {
    console.log("newSEService occurs " + "exception: ${(e : BusinessError).message}");
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
import omapi from '@ohos.secureElement';
import secureElement from '@ohos.secureElement';
import { BusinessError } from '@ohos.base';

let nfcSEService : omapi.SEService | null = null;
let nfcOmaReaderList : omapi.Reader[] | null = null;

try {
    nfcSEService = secureElement.newSEService("serviceState", (state) => {
        if (state == secureElement.ServiceState.DISCONNECTED) {
            console.log("Service state is Disconnected");
        } else {
            console.log("Service state is Connected");
        }
    });
} catch (e) {
    console.log("newSEService " + "excpetion: ${(e : BusinessError).message}");
}

try {
    if(nfcSEService != null) {
        nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        console.log("get reader successfully");
    } else {
        console.log("get reader failed");
    }
} catch (e) {
    console.log("getReaders " + "exception: ${(e : BusinessError).message}");
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
import omapi from '@ohos.secureElement';
import secureElement from '@ohos.secureElement';
import { BusinessError } from '@ohos.base';

let nfcSEService : omapi.SEService | null = null;

try {
    nfcSEService = secureElement.newSEService("serviceState", (state) => {
        if (state == secureElement.ServiceState.DISCONNECTED) {
            console.log("Service state is Disconnected");
        } else {
            console.log("Service state is Connected");
        }
    });
} catch (e) {
    console.log("newSEService" + "exception: ${(e : BusinessError).message}");
}

try {
    let ret: boolean = false;
    // Refer to newSEService for this.nfcSEService.
    if (nfcSEService != null) {
        ret = nfcSEService.isConnected();
    }
    if (ret) {
        console.log("get state: connected");
    } else {
        console.log("get state: not connected");
    }
} catch (e) {
        console.log("isConnected " + "exception: ${(e : BusinessError).message}");
}
```

## SEService.shutdown

shutdown(): void

Releases all SE resources allocated to this service. After that, [isConnected](#seserviceisconnected) returns **false**.

**System capability**: SystemCapability.Communication.SecureElement

**Example**

```js
import omapi from '@ohos.secureElement';
import secureElement from '@ohos.secureElement';
import { BusinessError } from '@ohos.base';

let nfcSEService : omapi.SEService | null = null;

try {
    nfcSEService = secureElement.newSEService("serviceState", (state) => {
        if (state == secureElement.ServiceState.DISCONNECTED) {
            console.log("Service state is Disconnected");
        } else {
            console.log("Service state is Connected");
        }
    });
} catch (e) {
    console.log("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    // Refer to newSEService for this.nfcSEService.
    if (nfcSEService != null) {
        nfcSEService.shutdown();
    }
    console.log("shutdown successfully");
} catch (e) {
    console.log("shutdown exception:" + "exception: ${(e : BusinessError).message}");
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
import omapi from '@ohos.secureElement';
import secureElement from '@ohos.secureElement';
import { BusinessError } from '@ohos.base';

let nfcSEService : omapi.SEService | null = null;

try {
    nfcSEService = secureElement.newSEService("serviceState", (state) => {
        if (state == secureElement.ServiceState.DISCONNECTED) {
            console.log("Service state is Disconnected");
        } else {
            console.log("Service state is Connected");
        }
    });
} catch (e) {
    console.log("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    // Refer to newSEService for this.nfcSEService.
    if (nfcSEService != null) {
        console.log("version: " + nfcSEService.getVersion());
    }
} catch (e) {
    console.log("getVersion " + "exception: ${(e : BusinessError).message}");
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
import omapi from '@ohos.secureElement';
import secureElement from '@ohos.secureElement';
import { BusinessError } from '@ohos.base';

let nfcSEService : omapi.SEService | null = null;
let nfcOmaReaderList : omapi.Reader[] | null = null;

try {
    nfcSEService = secureElement.newSEService("serviceState", (state) => {
        if (state == secureElement.ServiceState.DISCONNECTED) {
            console.log("Service state is Disconnected");
        } else {
            console.log("Service state is Connected");
        }
    });
} catch (e) {
    console.log("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if(nfcSEService != null) {
        nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        console.log(nfcOmaReaderList[0].getName());
    } else {
        console.log("getName failed");
    }
} catch (e) {
    console.log("getName " + "exception: ${(e : BusinessError).message}");
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
| 3300101  | IllegalStateError, service state exception. |

**Example**

```js

import omapi from '@ohos.secureElement';
import secureElement from '@ohos.secureElement';
import { BusinessError } from '@ohos.base';

let nfcSEService : omapi.SEService | null = null;
let nfcOmaReaderList : omapi.Reader[] | null = null;

try {
    nfcSEService = secureElement.newSEService("serviceState", (state) => {
        if (state == secureElement.ServiceState.DISCONNECTED) {
            console.log("Service state is Disconnected");
        } else {
            console.log("Service state is Connected");
        }
    });
} catch (e) {
    console.log("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if(nfcSEService != null) {
        nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        if (nfcOmaReaderList[0].isSecureElementPresent()) {
            console.log("isSecureElementPresent success");
        } else {
            console.log("isSecureElementPresent failed");
        }
    } else {
        console.log("isSecureElementPresent failed");
    }
} catch (e) {
    console.log("isSecureElementPresent " + "exception: ${(e : BusinessError).message}");
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
| 3300101  | IllegalStateError, service state exception. |
| 3300104  | IOError, there is a communication problem to the reader or the SE.     |

**Example**

```js
import omapi from '@ohos.secureElement';
import secureElement from '@ohos.secureElement';
import { BusinessError } from '@ohos.base';

let nfcSEService : omapi.SEService | null = null;
let nfcOmaReaderList : omapi.Reader[] | null = null;

try {
    nfcSEService = secureElement.newSEService("serviceState", (state) => {
        if (state == secureElement.ServiceState.DISCONNECTED) {
            console.log("Service state is Disconnected");
        } else {
            console.log("Service state is Connected");
        }
    });
} catch (e) {
    console.log("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if(nfcSEService != null) {
        nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        if (nfcOmaReaderList[0].openSession()) {
            console.log("get session successfully");
        } else {
            console.log("get session failed");
        }
    } else {
        console.log("OpenSession failed");
    }
} catch (e) {
    console.log("OpenSession " + "exception: ${(e : BusinessError).message}");
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
| 3300101  | IllegalStateError, service state exception. |

**Example**

```js
import omapi from '@ohos.secureElement';
import secureElement from '@ohos.secureElement';
import { BusinessError } from '@ohos.base';

let nfcSEService : omapi.SEService | null = null;
let nfcOmaReaderList : omapi.Reader[] | null = null;

try {
    nfcSEService = secureElement.newSEService("serviceState", (state) => {
        if (state == secureElement.ServiceState.DISCONNECTED) {
            console.log("Service state is Disconnected");
        } else {
            console.log("Service state is Connected");
        }
    });
} catch (e) {
    console.log("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if(nfcSEService != null) {
        nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        if (nfcOmaReaderList[0].closeSessions()) {
            console.log("closeSessions successfully");
        } else {
            console.log("closeSessions failed");
        }
    } else {
        console.log("closeSessions failed");
    }
} catch (e) {
  console.log("closeSessions " + "exception: ${(e : BusinessError).message}");
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
import omapi from '@ohos.secureElement';
import secureElement from '@ohos.secureElement';
import { BusinessError } from '@ohos.base';

let nfcSEService : omapi.SEService | null = null;
let nfcOmaReaderList : omapi.Reader[] | null = null;
let omaSession : omapi.Session | null = null;

try {
    nfcSEService = secureElement.newSEService("serviceState", (state) => {
        if (state == secureElement.ServiceState.DISCONNECTED) {
            console.log("Service state is Disconnected");
        } else {
            console.log("Service state is Connected");
        }
    });
} catch (e) {
    console.log("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if(nfcSEService != null) {
        nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        omaSession = nfcOmaReaderList[0].openSession();
        if (omaSession.getReader() != null) {
            console.log("get reader successfully");
        } else {
            console.log("get reader failed");
        }
    } else {
        console.log("getReader failed");
    }
} catch (e) {
    console.log("getReader " + "exception: ${(e : BusinessError).message}");
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
| 3300101  | IllegalStateError, service state exception. |

**Example**

```js
import omapi from '@ohos.secureElement';
import secureElement from '@ohos.secureElement';
import { BusinessError } from '@ohos.base';

let nfcSEService : omapi.SEService | null = null;
let nfcOmaReaderList : omapi.Reader[] | null = null;
let omaSession : omapi.Session | null = null;
let omaATR : number[] | null = null;
let str : string = "";

try {
    nfcSEService = secureElement.newSEService("serviceState", (state) => {
        if (state == secureElement.ServiceState.DISCONNECTED) {
            console.log("Service state is Disconnected");
        } else {
            console.log("Service state is Connected");
        }
    });
} catch (e) {
    console.log("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if(nfcSEService != null) {
        nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        omaSession = nfcOmaReaderList[0].openSession();
        if (omaSession != null) {
            omaATR = omaSession.getATR();
        } else {
            console.log("getATR failed");
        }
    }
    if (omaATR != null && omaATR.length > 0) {
        str = 'getATR result:[';
        for (let i = 0; i < omaATR.length; ++i) {
            str += omaATR[i];
            tr += ' ';
        }
        str += ']';
        console.log(str);
    } else {
        console.log("getATR failed");
    }
} catch (e) {
    console.log("getATR " + "exception: ${(e : BusinessError).message}");
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
| 3300101  | IllegalStateError, service state exception. |

**Example**

```js
import omapi from '@ohos.secureElement';
import secureElement from '@ohos.secureElement';
import { BusinessError } from '@ohos.base';

let nfcSEService : omapi.SEService | null = null;
let nfcOmaReaderList : omapi.Reader[] | null = null;
let omaSession : omapi.Session | null = null;

try {
    nfcSEService = secureElement.newSEService("serviceState", (state) => {
        if (state == secureElement.ServiceState.DISCONNECTED) {
            console.log("Service state is Disconnected");
        } else {
            console.log("Service state is Connected");
        }
    });
} catch (e) {
    console.log("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if(nfcSEService != null) {
        nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        omaSession = nfcOmaReaderList[0].openSession();
        if (omaSession != null) {
            omaSession.close();
        } else {
            console.log("close failed");
        }
    }
} catch (e) {
    console.log("close " + "exception: ${(e : BusinessError).message}");
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
import omapi from '@ohos.secureElement';
import secureElement from '@ohos.secureElement';
import { BusinessError } from '@ohos.base';

let nfcSEService : omapi.SEService | null = null;
let nfcOmaReaderList : omapi.Reader[] | null = null;
let omaSession : omapi.Session | null = null;

try {
    nfcSEService = secureElement.newSEService("serviceState", (state) => {
        if (state == secureElement.ServiceState.DISCONNECTED) {
            console.log("Service state is Disconnected");
        } else {
            console.log("Service state is Connected");
        }
    });
} catch (e) {
    console.log("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if(nfcSEService != null) {
      nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        omaSession = nfcOmaReaderList[0].openSession();
        if (omaSession != null &&  omaSession.isClosed()) {
           console.log("isClosed success");
        } else {
            console.log("isClosed failed");
        }
    }
} catch (e) {
    console.log("isClosed " + "exception: ${(e : BusinessError).message}");
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
| 3300101  | IllegalStateError, service state exception. |

**Example**

```js
import omapi from '@ohos.secureElement';
import secureElement from '@ohos.secureElement';
import { BusinessError } from '@ohos.base';

let nfcSEService : omapi.SEService | null = null;
let nfcOmaReaderList : omapi.Reader[] | null = null;
let omaSession : omapi.Session | null = null;

try {
    nfcSEService = secureElement.newSEService("serviceState", (state) => {
        if (state == secureElement.ServiceState.DISCONNECTED) {
            console.log("Service state is Disconnected");
        } else {
            console.log("Service state is Connected");
        }
    });
} catch (e) {
    console.log("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if(nfcSEService != null) {
      nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        omaSession = nfcOmaReaderList[0].openSession();
        if (omaSession != null) {
            omaSession.closeChannels();
            console.log("closeChannels success");
        } else {
            console.log("closeChannels failed");
        }
    }
} catch (e) {
    console.log("closeChannels " + "exception: ${(e : BusinessError).message}");
}
```

## Session.openBasicChannel

openBasicChannel(aid: number[]): Promise\<Channel>

Opens a basic channel. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.SecureElement

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**                                                    |
| ---------- | -------- | ------ | ------------------------------------------------------------ |
| aid        | number[] | Yes     |AIDs of the applets selected on this channel or null if no applet is selected.|

**Return value**

| **Type**| **Description**             |
| -------- | --------------------- |
| Channel  | Returns the **Channel** instance opened. If the SE cannot provide a new basic channel or cannot obtain the access control rule due to lack of available basic channels, null will be returned.|

**Error codes**

For details about error codes, see [SE Error Codes](../errorcodes/errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, an attempt is made to use an SE session that has been closed. |
| 3300102  | NoSuchElementError, the AID on the SE is not available or cannot be selected.       |
| 3300103  | SecurityError, the calling application cannot be granted access to this AID or the default applet on this session.   |
| 3300104  | IOError, there is a communication problem to the reader or the SE.     |

**Example**

```js
import omapi from '@ohos.secureElement';
import secureElement from '@ohos.secureElement';
import { BusinessError } from '@ohos.base';

let nfcSEService : omapi.SEService | null = null;
let nfcOmaReaderList : omapi.Reader[] | null = null;
let omaSession : omapi.Session | null = null;
let aidArray : number[] = [720, 1080];
let getPromise : Promise<omapi.Channel> | null = null;

try {
    nfcSEService = secureElement.newSEService("serviceState", (state) => {
        if (state == secureElement.ServiceState.DISCONNECTED) {
            console.log("Service state is Disconnected");
        } else {
            console.log("Service state is Connected");
        }
    });
} catch (e) {
    console.log("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if(nfcSEService != null) {
      nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        omaSession = nfcOmaReaderList[0].openSession();
        if (omaSession != null) {
            getPromise = omaSession.openBasicChannel(aidArray);
        } else {
            console.log("openBasicChannel1 failed");
        }
    }
    if (getPromise != null) {
        console.log("openBasicChannel1 get channel successfully");
    }
} catch (e) {
    console.log("openBasicChannel1 " + "exception: ${(e : BusinessError).message}");
}
```

## Session.openBasicChannel

 openBasicChannel(aid: number[], callback: AsyncCallback\<Channel>): void

Opens a basic channel. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.SecureElement

**Parameters**

| **Name**| **Type**              | **Mandatory**| **Description**                                                    |
| ---------- | ---------------------- | ------ | ------------------------------------------------------------ |
| aid        | number[]               | Yes     | AIDs of the applets selected on this channel or null if no applet is selected.|
| callback   | AsyncCallback\<Channel> | Yes     | Callback invoked to return the **Channel** instance opened. If the SE cannot provide a new basic channel or cannot obtain the access control rule due to lack of available basic channels, null will be returned.                           |

**Error codes**

For details about error codes, see [SE Error Codes](../errorcodes/errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, an attempt is made to use an SE session that has been closed. |
| 3300102  | NoSuchElementError, the AID on the SE is not available or cannot be selected.       |
| 3300103  | SecurityError, the calling application cannot be granted access to this AID or the default applet on this session.   |
| 3300104  | IOError, there is a communication problem to the reader or the SE.     |

**Example**

```js
import omapi from '@ohos.secureElement';
import secureElement from '@ohos.secureElement';
import { BusinessError } from '@ohos.base';

let nfcSEService : omapi.SEService | null = null;
let nfcOmaReaderList : omapi.Reader[] | null = null;
let omaSession : omapi.Session | null = null;
let aidArray : number[] = [720, 1080];

try {
    nfcSEService = secureElement.newSEService("serviceState", (state) => {
        if (state == secureElement.ServiceState.DISCONNECTED) {
            console.log("Service state is Disconnected");
        } else {
            console.log("Service state is Connected");
        }
    });
} catch (e) {
    console.log("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if(nfcSEService != null) {
      nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        omaSession = nfcOmaReaderList[0].openSession();
        if (omaSession != null) {
            omaSession.openBasicChannel(aidArray, (error, data) => {
                if (error) {
                    console.log("openBasicChannel2 failed:" + JSON.stringify(error));
                    return;
                }
                console.log("openBasicChannel2 get channel successfully");
            });
        }
    }
} catch (e) {
    console.log("openBasicChannel2 " + "exception: ${(e : BusinessError).message}");
}
```

## Session.openBasicChannel

openBasicChannel(aid: number[], p2: number): Promise\<Channel>

Opens a basic channel. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.SecureElement

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**                                                    |
| ---------- | -------- | ------ | ------------------------------------------------------------ |
| aid        | number[] | Yes      | AIDs of the applets selected on this channel or null if no applet is selected.|
| p2         | number   | Yes      |P2 parameter of the **SELECT APDU** command executed on the channel.                    |

**Return value**

| **Type**| **Description**             |
| -------- | --------------------- |
| Channel  | Returns the **Channel** instance opened. If the SE cannot provide a new basic channel or cannot obtain the access control rule due to lack of available basic channels, null will be returned.|

**Error codes**

For details about error codes, see [SE Error Codes](../errorcodes/errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, an attempt is made to use an SE session that has been closed. |
| 3300102  | NoSuchElementError, the AID on the SE is not available or cannot be selected.       |
| 3300103  | SecurityError, the calling application cannot be granted access to this AID or the default applet on this session.   |
| 3300104  | IOError, there is a communication problem to the reader or the SE.     |

**Example**

```js
import omapi from '@ohos.secureElement';
import secureElement from '@ohos.secureElement';
import { BusinessError } from '@ohos.base';

let nfcSEService : omapi.SEService | null = null;
let nfcOmaReaderList : omapi.Reader[] | null = null;
let omaSession : omapi.Session | null = null;
let getPromise : Promise<omapi.Channel> | null = null;
let nfcOmaChannel : omapi.Channel | null = null;
let aidArray : number[] = [720, 1080];
let p2 : number = 0x00;

try {
    nfcSEService = secureElement.newSEService("serviceState", (state) => {
        if (state == secureElement.ServiceState.DISCONNECTED) {
            console.log("Service state is Disconnected");
        } else {
            console.log("Service state is Connected");
        }
    });
} catch (e) {
    console.log("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if(nfcSEService != null) {
      nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        omaSession = nfcOmaReaderList[0].openSession();
    }
    if (omaSession != null) {
        getPromise = omaSession.openBasicChannel(aidArray, p2);
        getPromise.then((channel) => {
            nfcOmaChannel = channel;
            console.log("openBasicChannel3 get channel successfully");
        })
    }
} catch (e) {
    console.log("openBasicChannel3 " + "exception: ${(e : BusinessError).message}");
}
```

## Session.openBasicChannel

openBasicChannel(aid: number[], p2:number, callback: AsyncCallback\<Channel>): void

Opens a basic channel. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.SecureElement

**Parameters**

| **Name**| **Type**              | **Mandatory**| **Description**                                                    |
| ---------- | ---------------------- | ------ | ------------------------------------------------------------ |
| aid        | number[]               | Yes     | AIDs of the applets selected on this channel or null if no applet is selected.|
| p2         | number                 | Yes     | P2 parameter of the **SELECT APDU** command executed on the channel.                    |
| callback   | AsyncCallback\<Channel> | Yes     | Callback invoked to return the **Channel** instance opened. If the SE cannot provide a new basic channel or cannot obtain the access control rule due to lack of available basic channels, null will be returned.                           |

**Error codes**

For details about error codes, see [SE Error Codes](../errorcodes/errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, an attempt is made to use an SE session that has been closed. |
| 3300102  | NoSuchElementError, the AID on the SE is not available or cannot be selected.      |
| 3300103  | SecurityError, the calling application cannot be granted access to this AID or the default applet on this session.   |
| 3300104  | IOError, there is a communication problem to the reader or the SE.     |

**Example**

```js
import omapi from '@ohos.secureElement';
import secureElement from '@ohos.secureElement';
import { BusinessError } from '@ohos.base';

let nfcSEService : omapi.SEService | null = null;
let nfcOmaReaderList : omapi.Reader[] | null = null;
let omaSession : omapi.Session | null = null;
let nfcOmaChannel : omapi.Channel | null = null;
let aidArray : number[] = [720, 1080];
let p2 : number = 0x00;

try {
    nfcSEService = secureElement.newSEService("serviceState", (state) => {
        if (state == secureElement.ServiceState.DISCONNECTED) {
            console.log("Service state is Disconnected");
        } else {
            console.log("Service state is Connected");
        }
    });
} catch (e) {
    console.log("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
  if(nfcSEService != null) {
    nfcOmaReaderList = nfcSEService.getReaders();
  }
  if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
    omaSession = nfcOmaReaderList[0].openSession();
  }
  if (omaSession != null) {
    omaSession.openBasicChannel(aidArray, p2, (error , data) => {
      if (error) {
        console.log("openBasicChannel4 failed:" + JSON.stringify(error));
        return;
      }
      nfcOmaChannel = data;
      console.log("openBasicChannel4 get channel successfully");
    });
  }
} catch (e) {
  console.log("openBasicChannel4 " + "exception: ${(e : BusinessError).message}");
}
```

## Session.openLogicalChannel

openLogicalChannel(aid: number[]): Promise\<Channel>

Opens a logical channel. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.SecureElement

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**                               |
| ---------- | -------- | ------ | --------------------------------------- |
| aid        | number[] | Yes     | AIDs of the applets selected on the **Channel** instance.|

**Return value**

| **Type**| **Description**                                                    |
| -------- | ------------------------------------------------------------ |
| Channel  | Returns the **Channel** instance opened. If the SE cannot provide a new **Channel** instance or cannot obtain access control rules due to lack of available logical **Channel** instances, null will be returned.|

**Error codes**

For details about error codes, see [SE Error Codes](../errorcodes/errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, an attempt is made to use an SE session that has been closed. |
| 3300102  | NoSuchElementError, the AID on the SE is not available or cannot be selected.       |
| 3300103  | SecurityError, the calling application cannot be granted access to this AID or the default applet on this session.   |
| 3300104  | IOError, there is a communication problem to the reader or the SE.     |

**Example**

```js
import omapi from '@ohos.secureElement';
import secureElement from '@ohos.secureElement';
import { BusinessError } from '@ohos.base';

let nfcSEService : omapi.SEService | null = null;
let nfcOmaReaderList : omapi.Reader[] | null = null;
let omaSession : omapi.Session | null = null;
let aidArray : number[] = [720, 1080];
let getPromise : Promise<omapi.Channel> | null = null;

try {
    nfcSEService = secureElement.newSEService("serviceState", (state) => {
        if (state == secureElement.ServiceState.DISCONNECTED) {
            console.log("Service state is Disconnected");
        } else {
            console.log("Service state is Connected");
        }
    });
} catch (e) {
    console.log("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if(nfcSEService != null) {
      nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        omaSession = nfcOmaReaderList[0].openSession();
        if (omaSession != null) {
            getPromise = omaSession.openLogicalChannel(aidArray);
        } else {
            console.log("openLogicalChannel1 failed");
        }
    }
    if (getPromise != null) {
        console.log("openLogicalChannel1 get channel successfully");
    }
} catch (e) {
    console.log("openLogicalChannel1 " + "exception: ${(e : BusinessError).message}");
}
```

## Session.openLogicalChannel

 openLogicalChannel(aid:number[], callback: AsyncCallback\<Channel>): void

Opens a logical channel. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.SecureElement

**Parameters**

| **Name**| **Type**              | **Mandatory**| **Description**                                                    |
| ---------- | ---------------------- | ------ | ------------------------------------------------------------ |
| aid        | number[]               | Yes     | AIDs of the applets selected on the **Channel** instance.                   |
| callback   | AsyncCallback\<Channel> | Yes     | Callback invoked to return the **Channel** instance opened. If the SE cannot provide a new **Channel** instance or cannot obtain access control rules due to lack of available logical **Channel** instances, null will be returned.|

**Error codes**

For details about error codes, see [SE Error Codes](../errorcodes/errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, an attempt is made to use an SE session that has been closed. |
| 3300102  | NoSuchElementError, the AID on the SE is not available or cannot be selected.      |
| 3300103  | SecurityError, the calling application cannot be granted access to this AID or the default applet on this session.   |
| 3300104  | IOError, there is a communication problem to the reader or the SE.    |

**Example**

```js
import omapi from '@ohos.secureElement';
import secureElement from '@ohos.secureElement';
import { BusinessError } from '@ohos.base';

let nfcSEService : omapi.SEService | null = null;
let nfcOmaReaderList : omapi.Reader[] | null = null;
let omaSession : omapi.Session | null = null;
let aidArray : number[] = [720, 1080];

try {
    nfcSEService = secureElement.newSEService("serviceState", (state) => {
        if (state == secureElement.ServiceState.DISCONNECTED) {
            console.log("Service state is Disconnected");
        } else {
            console.log("Service state is Connected");
        }
    });
} catch (e) {
    console.log("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if(nfcSEService != null) {
      nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        omaSession = nfcOmaReaderList[0].openSession();
    }
    if (omaSession != null) {
        omaSession.openLogicalChannel(aidArray, (error, data) => {
            if (error) {
                console.log("openLogicalChannel2 failed:" + JSON.stringify(error));
                return;
            }
            console.log("openLogicalChannel2 get channel successfully");
        });
    }
} catch (e) {
    console.log("openLogicalChannel2 " + "exception: ${(e : BusinessError).message}");
}
```

## Session.openLogicalChannel

openLogicalChannel(aid: number[], p2: number): Promise\<Channel>

Opens a logical channel with the applet represented by the given AID (the AID is not null and the length is not 0).

If the AID length is 0, this API sends a **select** command with the AID length of 0 (as per [GPCS]) to select the Issuer Security Domain of the SE.

If the AID is null, this API sends the **MANAGE CHANNEL Open** only. In this case, the default applet associated with the logical channel is selected.

**P2** is usually **0x00**. The device shall allow any value of **P2** and the following values: **0x00**, **0x04**, **0x08**, **0x0C** as defined in [ISO 7816-4](https://www.iso.org/standard/77180.html).

**System capability**: SystemCapability.Communication.SecureElement

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**                                 |
| ---------- | -------- | ------ | ----------------------------------------- |
| aid        | number[] | Yes     | AIDs of the applets selected on the **Channel** instance.|
| p2         | number   | Yes     | P2 parameter of the **SELECT APDU** command executed on the channel. |

**Error codes**

For details about error codes, see [SE Error Codes](../errorcodes/errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, an attempt is made to use an SE session that has been closed. |
| 3300102  | NoSuchElementError, the AID on the SE is not available or cannot be selected.      |
| 3300103  | SecurityError, the calling application cannot be granted access to this AID or the default applet on this session.   |
| 3300104  | IOError, there is a communication problem to the reader or the SE.     |

**Example**

```js
import omapi from '@ohos.secureElement';
import secureElement from '@ohos.secureElement';
import { BusinessError } from '@ohos.base';

let nfcSEService : omapi.SEService | null = null;
let nfcOmaReaderList : omapi.Reader[] | null = null;
let omaSession : omapi.Session | null = null;
let getPromise : Promise<omapi.Channel> | null = null;
let nfcOmaChannel : omapi.Channel | null = null;
let aidArray : number[] = [720, 1080];
let p2 : number = 0x00;

try {
    nfcSEService = secureElement.newSEService("serviceState", (state) => {
        if (state == secureElement.ServiceState.DISCONNECTED) {
            console.log("Service state is Disconnected");
        } else {
            console.log("Service state is Connected");
        }
    });
} catch (e) {
    console.log("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if(nfcSEService != null) {
      nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        omaSession = nfcOmaReaderList[0].openSession();
    }
    if (omaSession != null) {
        getPromise = omaSession.openLogicalChannel(aidArray, p2);
        getPromise.then((channel) => {
            nfcOmaChannel = channel;
            console.log("openLogicalChannel3 get channel successfully");
        })
    }
} catch (e) {
    console.log("openLogicalChannel3 " + "exception: ${(e : BusinessError).message}");
}
```

## Session.openLogicalChannel

openLogicalChannel(aid: number[], p2: number, callback: AsyncCallback\<Channel>):void

Opens a logical channel with the applet represented by the given AID (the AID is not null and the length is not 0).

If the AID length is 0, this API sends a **select** command with the AID length of 0 (as per [GPCS]) to select the Issuer Security Domain of the SE.

If the AID is null, this API sends the **MANAGE CHANNEL Open** only. In this case, the default applet associated with the logical channel is selected.

**P2** is usually **0x00**. The device shall allow any value of **P2** and the following values: **0x00**, **0x04**, **0x08**, **0x0C** as defined in [ISO 7816-4](https://www.iso.org/standard/77180.html).

**System capability**: SystemCapability.Communication.SecureElement

**Parameters**

| **Name**| **Type**              | **Mandatory**| **Description**                                                    |
| ---------- | ---------------------- | ------ | ------------------------------------------------------------ |
| aid        | number[]               | Yes     | AIDs of the applets selected on the **Channel** instance.                   |
| p2         | number                 | Yes     | P2 parameter of the **SELECT APDU** command executed on the channel.                    |
| callback   | AsyncCallback\<Channel> | Yes     | Callback invoked to return the **Channel** instance opened. If the SE cannot provide a new **Channel** instance or cannot obtain access control rules due to lack of available logical **Channel** instances, null will be returned.|

**Error codes**

For details about error codes, see [SE Error Codes](../errorcodes/errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, an attempt is made to use an SE session that has been closed. |
| 3300102  | NoSuchElementError, the AID on the SE is not available or cannot be selected.       |
| 3300103  | SecurityError, the calling application cannot be granted access to this AID or the default applet on this session.   |
| 3300104  | IOError, there is a communication problem to the reader or the SE.     |

**Example**

```js
import omapi from '@ohos.secureElement';
import secureElement from '@ohos.secureElement';
import { BusinessError } from '@ohos.base';

let nfcSEService : omapi.SEService | null = null;
let nfcOmaReaderList : omapi.Reader[] | null = null;
let omaSession : omapi.Session | null = null;
let nfcOmaChannel : omapi.Channel | null = null;
let aidArray : number[] = [720, 1080];
let p2 : number = 0x00;

try {
    nfcSEService = secureElement.newSEService("serviceState", (state) => {
        if (state == secureElement.ServiceState.DISCONNECTED) {
            console.log("Service state is Disconnected");
        } else {
            console.log("Service state is Connected");
        }
    });
} catch (e) {
    console.log("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
  if(nfcSEService != null) {
    nfcOmaReaderList = nfcSEService.getReaders();
  }
  if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
    omaSession = nfcOmaReaderList[0].openSession();
  }
  if (omaSession != null) {
    omaSession.openLogicalChannel(aidArray, p2, (error, data) => {
      if (error) {
        console.log("openLogicalChannel4 failed:" + JSON.stringify(error));
        return;
      }
      nfcOmaChannel = data;
      console.log("openLogicalChannel4 get channel successfully");
    });
  }
} catch (e) {
  console.log("openLogicalChannel4 " + "exception: ${(e : BusinessError).message}");
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
import omapi from '@ohos.secureElement';
import secureElement from '@ohos.secureElement';
import { BusinessError } from '@ohos.base';

let nfcSEService : omapi.SEService | null = null;
let nfcOmaReaderList : omapi.Reader[] | null = null;
let omaSession : omapi.Session | null = null;
let getPromise : Promise<omapi.Channel> | null = null;
let aidArray : number[] = [720, 1080];
let p2 : number = 0x00;
let mySession : omapi.Session | null = null;

try {
    nfcSEService = secureElement.newSEService("serviceState", (state) => {
        if (state == secureElement.ServiceState.DISCONNECTED) {
            console.log("Service state is Disconnected");
        } else {
            console.log("Service state is Connected");
        }
    });
} catch (e) {
    console.log("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if(nfcSEService != null) {
      nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        omaSession = nfcOmaReaderList[0].openSession();
    }
    if (omaSession != null) {
        getPromise = omaSession.openLogicalChannel(aidArray, p2);
        getPromise.then((channel) => {
            mySession = channel.getSession();
            console.log("openLogicalChannel get channel successfully");
        })
    }
    if (mySession != null) {
        console.log("get session successfully");
    } else {
        console.log("get session failed");
    }
} catch (e) {
    console.log("get session " + "exception: ${(e : BusinessError).message}");
}
```

## Channel. close

close(): void

Closes the channel of the SE.

**System capability**: SystemCapability.Communication.SecureElement

**Example**

```js
import omapi from '@ohos.secureElement';
import secureElement from '@ohos.secureElement';
import { BusinessError } from '@ohos.base';

let nfcSEService : omapi.SEService | null = null;
let nfcOmaReaderList : omapi.Reader[] | null = null;
let omaSession : omapi.Session | null = null;
let getPromise : Promise<omapi.Channel> | null = null;
let aidArray : number[] = [720, 1080];
let p2 : number = 0x00;

try {
    nfcSEService = secureElement.newSEService("serviceState", (state) => {
        if (state == secureElement.ServiceState.DISCONNECTED) {
            console.log("Service state is Disconnected");
        } else {
            console.log("Service state is Connected");
        }
    });
} catch (e) {
    console.log("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if(nfcSEService != null) {
      nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        omaSession = nfcOmaReaderList[0].openSession();
    }
    if (omaSession != null) {
        getPromise = omaSession.openLogicalChannel(aidArray, p2);
        getPromise.then((channel) => {
            channel.close();
            console.log("channel close successfully");
        })
    }
} catch (e) {
    console.log("channel close " + "exception: ${(e : BusinessError).message}");
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
import omapi from '@ohos.secureElement';
import secureElement from '@ohos.secureElement';
import { BusinessError } from '@ohos.base';

let nfcSEService : omapi.SEService | null = null;
let nfcOmaReaderList : omapi.Reader[] | null = null;
let omaSession : omapi.Session | null = null;
let getPromise : Promise<omapi.Channel> | null = null;
let aidArray : number[] = [720, 1080];
let p2 : number = 0x00;
let ret : boolean = false;

try {
    nfcSEService = secureElement.newSEService("serviceState", (state) => {
        if (state == secureElement.ServiceState.DISCONNECTED) {
            console.log("Service state is Disconnected");
        } else {
            console.log("Service state is Connected");
        }
    });
} catch (e) {
    console.log("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if(nfcSEService != null) {
      nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        omaSession = nfcOmaReaderList[0].openSession();
    }
    if (omaSession != null) {
        getPromise = omaSession.openLogicalChannel(aidArray, p2);
        getPromise.then((channel) => {
            ret = channel.isBasicChannel();
        })
    }
    if (ret) {
        console.log("isBasicChannel TRUE");
    } else {
        console.log("isBasicChannel FALSE");
    }
} catch (e) {
    console.log("isBasicChannel " + "exception: ${(e : BusinessError).message}");
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
import omapi from '@ohos.secureElement';
import secureElement from '@ohos.secureElement';
import { BusinessError } from '@ohos.base';

let nfcSEService : omapi.SEService | null = null;
let nfcOmaReaderList : omapi.Reader[] | null = null;
let omaSession : omapi.Session | null = null;
let getPromise : Promise<omapi.Channel> | null = null;
let aidArray : number[] = [720, 1080];
let p2 : number = 0x00;
let ret : boolean = false;

try {
    nfcSEService = secureElement.newSEService("serviceState", (state) => {
        if (state == secureElement.ServiceState.DISCONNECTED) {
            console.log("Service state is Disconnected");
        } else {
            console.log("Service state is Connected");
        }
    });
} catch (e) {
    console.log("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if(nfcSEService != null) {
      nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        omaSession = nfcOmaReaderList[0].openSession();
    }
    if (omaSession != null) {
        getPromise = omaSession.openLogicalChannel(aidArray, p2);
        getPromise.then((channel) => {
            ret = channel.isClosed();
        })
    }
    if (ret) {
        console.log("channel isClosed TRUE");
    } else {
        console.log("channel isClosed False");
    }
} catch (e) {
    console.log("isBasicChannel " + "exception: ${(e : BusinessError).message}");
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
import omapi from '@ohos.secureElement';
import secureElement from '@ohos.secureElement';
import { BusinessError } from '@ohos.base';

let nfcSEService : omapi.SEService | null = null;
let nfcOmaReaderList : omapi.Reader[] | null = null;
let omaSession : omapi.Session | null = null;
let getPromise : Promise<omapi.Channel> | null = null;
let aidArray : number[] = [720, 1080];
let p2 : number = 0x00;
let responseArray : number[] = [720, 1080];
let str : string = "";

try {
    nfcSEService = secureElement.newSEService("serviceState", (state) => {
        if (state == secureElement.ServiceState.DISCONNECTED) {
            console.log("Service state is Disconnected");
        } else {
            console.log("Service state is Connected");
        }
    });
} catch (e) {
    console.log("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if(nfcSEService != null) {
      nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        omaSession = nfcOmaReaderList[0].openSession();
    }
    if (omaSession != null) {
        getPromise = omaSession.openLogicalChannel(aidArray, p2);
        getPromise.then((channel) => {
            responseArray = channel.getSelectResponse();
        })
    }
    if (responseArray) {
        str = "getSelectResponse result:[";
        for (let i = 0; i < responseArray.length; ++i) {
            str += responseArray[i];
            str += ' ';
        }
        str += ']';
        console.log(str);
    } else {
        console.log("getSelectResponse result is null");
    }
} catch (e) {
    console.log("isBasicChannel " + "exception: ${(e : BusinessError).message}");
}
```

## Channel. transmit

transmit(command: number[]): Promise<number[]>

Transmits the **APDU** command to the SE (according to ISO/IEC 7816). This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.SecureElement

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**                             |
| ---------- | -------- | ------ | ------------------------------------- |
| command    | number[] | Yes     | AIDs of the applets selected on the channel.|

**Return value**

| **Type**| **Description**      |
| -------- | -------------- |
| number[] | Returns the response obtained.|

**Error codes**

For details about error codes, see [SE Error Codes](../errorcodes/errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, an attempt is made to use an SE session or channel that has been closed. |
| 3300103  | SecurityError, the command is filtered by the security policy. |
| 3300104  | IOError, there is a communication problem to the reader or the SE.     |

**Example**

```js
import omapi from '@ohos.secureElement';
import secureElement from '@ohos.secureElement';
import { BusinessError } from '@ohos.base';

let nfcSEService : omapi.SEService | null = null;
let nfcOmaReaderList : omapi.Reader[] | null = null;
let omaSession : omapi.Session | null = null;
let getPromise : Promise<omapi.Channel> | null = null;
let aidArray : number[] = [720, 1080];
let p2 : number = 0x00;
let responseArray : Promise<number[]> | null = null;

try {
    nfcSEService = secureElement.newSEService("serviceState", (state) => {
        if (state == secureElement.ServiceState.DISCONNECTED) {
            console.log("Service state is Disconnected");
        } else {
            console.log("Service state is Connected");
        }
    });
} catch (e) {
    console.log("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if(nfcSEService != null) {
      nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        omaSession = nfcOmaReaderList[0].openSession();
    }
    if (omaSession != null) {
        getPromise = omaSession.openLogicalChannel(aidArray, p2);
        getPromise.then((channel) => {
            let command: number[] = [100, 200];
            // Refer to Session.openBasicChannel for this.nfcOmaChannel.
            responseArray = channel.transmit(command);
        })
    }
    if (responseArray != null) {
        console.log("transmit1 success");
    } else {
        console.log("transmit1 failed");
    }
} catch (e) {
    console.log("transmit1 " + "exception: ${(e : BusinessError).message}");
}
```

## Channel. transmit

transmit(command: number[], callback: AsyncCallback<number[]>): void

Transmits the **APDU** command to the SE (according to ISO/IEC 7816). This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.SecureElement

**Parameters**

| **Name**| **Type**               | **Mandatory**| **Description**                             |
| ---------- | ----------------------- | ------ | ------------------------------------- |
| command    | number[]                | Yes     | AIDs of the applets selected on the channel.|
| callback   | AsyncCallback<number[]> | Yes     | Callback invoked to return the result. |

**Error codes**

For details about error codes, see [SE Error Codes](../errorcodes/errorcode-se.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, an attempt is made to use an SE session or channel that has been closed. |
| 3300103  | SecurityError, the command is filtered by the security policy. |
| 3300104  | IOError, there is a communication problem to the reader or the SE.     |

**Example**

```js
import omapi from '@ohos.secureElement';
import secureElement from '@ohos.secureElement';
import { BusinessError } from '@ohos.base';

let nfcSEService : omapi.SEService | null = null;
let nfcOmaReaderList : omapi.Reader[] | null = null;
let omaSession : omapi.Session | null = null;
let getPromise : Promise<omapi.Channel> | null = null;
let aidArray : number[] = [720, 1080];
let p2 : number = 0x00;
let str : string = "";

try {
    nfcSEService = secureElement.newSEService("serviceState", (state) => {
        if (state == secureElement.ServiceState.DISCONNECTED) {
            console.log("Service state is Disconnected");
        } else {
            console.log("Service state is Connected");
        }
    });
} catch (e) {
    console.log("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if(nfcSEService != null) {
      nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        omaSession = nfcOmaReaderList[0].openSession();
    }
    if (omaSession != null) {
        getPromise = omaSession.openLogicalChannel(aidArray, p2);
        getPromise.then((channel) => {
            let command: number[] = [100, 200];
            // Refer to Session.openBasicChannel for this.nfcOmaChannel.
            channel.transmit(command, (error, data) => {
                if (error) {
                    console.log("transmit2 exception:" + JSON.stringify(error));
                    return;
                }
                str = "transmit2 result:[";
                for (let i = 0; i < data.length; ++i) {
                    str += data[i];
                    str += " ";
                }
                str += "]";
                console.log(str)
            });
        })
    }
} catch (e) {
    console.log("transmit2 " + "exception: ${(e : BusinessError).message}");
}
```
