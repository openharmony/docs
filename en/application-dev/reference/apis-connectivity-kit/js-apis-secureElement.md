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

try {
    let nfcSEService = secureElement.newSEService("serviceState", (state) => {
        if (state == secureElement.ServiceState.DISCONNECTED) {
            console.log("Service state is Disconnected");
        } else {
            console.log("Service state is Connected");
        }
    });
} catch (e) {
    console.error("newSEService occurs " + "exception: ${(e : BusinessError).message}");
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
    console.error("newSEService " + "excpetion: ${(e : BusinessError).message}");
}

try {
    if (nfcSEService != null) {
        nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        console.log("get reader successfully");
    } else {
        console.error("get reader failed");
    }
} catch (e) {
    console.error("getReaders " + "exception: ${(e : BusinessError).message}");
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
    console.error("newSEService" + "exception: ${(e : BusinessError).message}");
}

try {
    let ret: boolean = false;
    // refer to newSEService for this.nfcSEService 
    if (nfcSEService != null) {
        ret = nfcSEService.isConnected();
    }
    if (ret) {
        console.log("get state: connected");
    } else {
        console.log("get state: not connected");
    }
} catch (e) {
    console.error("isConnected " + "exception: ${(e : BusinessError).message}");
}
```

## SEService.shutdown

shutdown(): void

Releases all SE resources allocated to this SE service. After that, [isConnected](#seserviceisconnected) returns **false**.

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
    console.error("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    // refer to newSEService for this.nfcSEService 
    if (nfcSEService != null) {
        nfcSEService.shutdown();
    }
    console.log("shutdown successfully");
} catch (e) {
    console.error("shutdown exception:" + "exception: ${(e : BusinessError).message}");
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
    console.error("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    // refer to newSEService for this.nfcSEService 
    if (nfcSEService != null) {
        console.log("version: " + nfcSEService.getVersion());
    }
} catch (e) {
    console.error("getVersion " + "exception: ${(e : BusinessError).message}");
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
    console.error("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if (nfcSEService != null) {
        nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        console.log(nfcOmaReaderList[0].getName());
    } else {
        console.error("getName failed");
    }
} catch (e) {
    console.error("getName " + "exception: ${(e : BusinessError).message}");
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
    console.error("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if (nfcSEService != null) {
        nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        if (nfcOmaReaderList[0].isSecureElementPresent()) {
            console.log("isSecureElementPresent success");
        } else {
            console.log("isSecureElementPresent failed");
        }
    } else {
        console.error("isSecureElementPresent failed");
    }
} catch (e) {
    console.error("isSecureElementPresent " + "exception: ${(e : BusinessError).message}");
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
    console.error("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if (nfcSEService != null) {
        nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        if (nfcOmaReaderList[0].openSession()) {
            console.log("get session successfully");
        } else {
            console.log("get session failed");
        }
    } else {
        console.error("OpenSession failed");
    }
} catch (e) {
    console.error("OpenSession " + "exception: ${(e : BusinessError).message}");
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
    console.error("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if (nfcSEService != null) {
        nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        nfcOmaReaderList[0].closeSessions();
        console.log("closeSessions successfully");
    } else {
        console.error("closeSessions failed");
    }
} catch (e) {
    console.error("closeSessions " + "exception: ${(e : BusinessError).message}");
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
    console.error("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if (nfcSEService != null) {
        nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        omaSession = nfcOmaReaderList[0].openSession();
        if (omaSession.getReader() != null) {
            console.log("get reader successfully");
        } else {
            console.error("get reader failed");
        }
    } else {
        console.error("getReader failed");
    }
} catch (e) {
    console.error("getReader " + "exception: ${(e : BusinessError).message}");
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
    console.error("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if (nfcSEService != null) {
        nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        omaSession = nfcOmaReaderList[0].openSession();
        if (omaSession != null) {
            omaATR = omaSession.getATR();
        } else {
            console.error("getATR failed");
        }
    }
    if (omaATR != null && omaATR.length > 0) {
        str = 'getATR result:[';
        for (let i = 0; i < omaATR.length; ++i) {
            str += omaATR[i];
            str += ' ';
        }
        str += ']';
        console.log(str);
    } else {
        console.error("getATR failed");
    }
} catch (e) {
    console.error("getATR " + "exception: ${(e : BusinessError).message}");
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
    console.error("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if (nfcSEService != null) {
        nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        omaSession = nfcOmaReaderList[0].openSession();
        if (omaSession != null) {
            omaSession.close();
        } else {
            console.error("close failed");
        }
    }
} catch (e) {
    console.error("close " + "exception: ${(e : BusinessError).message}");
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
    console.error("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if (nfcSEService != null) {
      nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        omaSession = nfcOmaReaderList[0].openSession();
        if (omaSession != null) {
            console.log("openSession success");
            if (omaSession.isClosed()) {
                console.log("session is closed");
            }
        } else {
            console.error("openSession failed");
        }
    }
} catch (e) {
    console.error("isClosed " + "exception: ${(e : BusinessError).message}");
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
    console.error("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if (nfcSEService != null) {
      nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        omaSession = nfcOmaReaderList[0].openSession();
        if (omaSession != null) {
            omaSession.closeChannels();
            console.log("closeChannels success");
        } else {
            console.error("closeChannels failed");
        }
    }
} catch (e) {
    console.error("closeChannels " + "exception: ${(e : BusinessError).message}");
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
    console.error("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if (nfcSEService != null) {
      nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        omaSession = nfcOmaReaderList[0].openSession();
        if (omaSession != null) {
            getPromise = omaSession.openBasicChannel(aidArray);
        } else {
            console.error("openBasicChannel1 failed");
        }
    }
    if (getPromise != null) {
        console.log("openBasicChannel1 get channel successfully");
    }
} catch (e) {
    console.error("openBasicChannel1 " + "exception: ${(e : BusinessError).message}");
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
    console.error("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if (nfcSEService != null) {
      nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        omaSession = nfcOmaReaderList[0].openSession();
        if (omaSession != null) {
            omaSession.openBasicChannel(aidArray, (error, data) => {
                if (error) {
                    console.error("openBasicChannel2 failed:" + JSON.stringify(error));
                    return;
                }
                console.log("openBasicChannel2 get channel successfully");
            });
        }
    }
} catch (e) {
    console.error("openBasicChannel2 " + "exception: ${(e : BusinessError).message}");
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
    console.error("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if (nfcSEService != null) {
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
    console.error("openBasicChannel3 " + "exception: ${(e : BusinessError).message}");
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
    console.error("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if (nfcSEService != null) {
        nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        omaSession = nfcOmaReaderList[0].openSession();
    }
    if (omaSession != null) {
        omaSession.openBasicChannel(aidArray, p2, (error , data) => {
            if (error) {
                console.error("openBasicChannel4 failed:" + JSON.stringify(error));
                return;
            }
            nfcOmaChannel = data;
            console.log("openBasicChannel4 get channel successfully");
        });
    }
} catch (e) {
    console.error("openBasicChannel4 " + "exception: ${(e : BusinessError).message}");
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
    console.error("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if (nfcSEService != null) {
      nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        omaSession = nfcOmaReaderList[0].openSession();
        if (omaSession != null) {
            getPromise = omaSession.openLogicalChannel(aidArray);
        } else {
            console.error("openLogicalChannel1 failed");
        }
    }
    if (getPromise != null) {
        console.log("openLogicalChannel1 get channel successfully");
    }
} catch (e) {
    console.error("openLogicalChannel1 " + "exception: ${(e : BusinessError).message}");
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
    console.error("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if (nfcSEService != null) {
      nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        omaSession = nfcOmaReaderList[0].openSession();
    }
    if (omaSession != null) {
        omaSession.openLogicalChannel(aidArray, (error, data) => {
            if (error) {
                console.error("openLogicalChannel2 failed:" + JSON.stringify(error));
                return;
            }
            console.log("openLogicalChannel2 get channel successfully");
        });
    }
} catch (e) {
    console.error("openLogicalChannel2 " + "exception: ${(e : BusinessError).message}");
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
    console.error("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if (nfcSEService != null) {
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
    console.error("openLogicalChannel3 " + "exception: ${(e : BusinessError).message}");
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
    console.error("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if (nfcSEService != null) {
        nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        omaSession = nfcOmaReaderList[0].openSession();
    }
    if (omaSession != null) {
        omaSession.openLogicalChannel(aidArray, p2, (error, data) => {
            if (error) {
                console.error("openLogicalChannel4 failed:" + JSON.stringify(error));
                return;
            }
            nfcOmaChannel = data;
            console.log("openLogicalChannel4 get channel successfully");
        });
    }
} catch (e) {
    console.error("openLogicalChannel4 " + "exception: ${(e : BusinessError).message}");
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
    console.error("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if (nfcSEService != null) {
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
        console.error("get session failed");
    }
} catch (e) {
    console.error("get session " + "exception: ${(e : BusinessError).message}");
}
```

## Channel. close

close(): void

Closes this channel.

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
    console.error("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if (nfcSEService != null) {
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
    console.error("channel close " + "exception: ${(e : BusinessError).message}");
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
    console.error("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if (nfcSEService != null) {
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
    console.error("isBasicChannel " + "exception: ${(e : BusinessError).message}");
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
    console.error("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if (nfcSEService != null) {
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
    console.error("isBasicChannel " + "exception: ${(e : BusinessError).message}");
}
```

## Channel. getSelectResponse

getSelectResponse():number[]

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
    console.error("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if (nfcSEService != null) {
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
        console.error("getSelectResponse result is null");
    }
} catch (e) {
    console.error("isBasicChannel " + "exception: ${(e : BusinessError).message}");
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
    console.error("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if (nfcSEService != null) {
        nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        omaSession = nfcOmaReaderList[0].openSession();
    }
    if (omaSession != null) {
        getPromise = omaSession.openLogicalChannel(aidArray, p2);
        getPromise.then((channel) => {
            let command: number[] = [100, 200];
            // refer to Session.openBasicChannel for this.nfcOmaChannel
            responseArray = channel.transmit(command);
        })
    }
    if (responseArray != null) {
        console.log("transmit1 success");
    } else {
        console.error("transmit1 failed");
    }
} catch (e) {
    console.error("transmit1 " + "exception: ${(e : BusinessError).message}");
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
    console.error("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if (nfcSEService != null) {
        nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        omaSession = nfcOmaReaderList[0].openSession();
    }
    if (omaSession != null) {
        getPromise = omaSession.openLogicalChannel(aidArray, p2);
        getPromise.then((channel) => {
            let command: number[] = [100, 200];
            // refer to Session.openBasicChannel for this.nfcOmaChannel
            channel.transmit(command, (error, data) => {
                if (error) {
                    console.error("transmit2 exception:" + JSON.stringify(error));
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
    console.error("transmit2 " + "exception: ${(e : BusinessError).message}");
}
```
