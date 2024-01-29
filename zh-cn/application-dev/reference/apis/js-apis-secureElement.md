# @ohos.secureElement (安全单元的通道管理)

本模块主要用于操作及管理安全单元（SecureElement，简称SE），电子设备上可能存在的安全单元有eSE(Embedded SE)和SIM卡。文档中出现的SE服务为SEService实例，参见[newSEService](#secureelementnewseservice)。

对于文档中出现以下类型说明：

| 类型    | 说明                                           |
| ------- | ---------------------------------------------- |
| Reader  | 此类的实例表示该设备支持的SE，如果支持eSE和SIM，这返回两个实例。 |
| Session | 此类的实例表示在某个SE Reader实例上创建连接会话。 |
| Channel | 此类的实例表示在某个Session实例上创建通道，可能为基础通道或逻辑通道。   |

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## **导入模块**

```js
import secureElement from '@ohos.secureElement';
```

## secureElement.ServiceState

定义不同的SE服务状态值。

**系统能力：**  SystemCapability.Communication.SecureElement

| 名称         | 值   | 说明               |
| ------------ | ---- | ------------------ |
| DISCONNECTED | 0    | SE服务状态已断开。 |
| CONNECTED    | 1    | SE服务状态已连接。 |

## secureElement.newSEService

newSEService(type: 'serviceState', callback: Callback<[ServiceState](#secureelementservicestate)>): SEService

建立一个可用于连接到系统中所有可用SE的新连接（服务）。连接过程较为耗时，所以此方法仅提供异步方式进行的。

仅当指定的回调或者当[isConnected](#seserviceisconnected)方法返回true时，该返回SEService对象是可用的。

**系统能力：**  SystemCapability.Communication.SecureElement

**参数：**

| **参数名** | **类型**                                             | **必填** | **说明**             |
| ---------- | ---------------------------------------------------- | ------ | -------------------- |
| type       | string                                               | 是      | 固定填'serviceState' 。      |
| callback   | Callback<[ServiceState](#secureelementservicestate)> | 是      | 返回SE服务状态的回调 。|

**返回值：**

| **类型**  | **说明**   |
| :-------- | :--------- |
| SEService | SE服务实例。 |

**示例：**

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

返回可用SE Reader的数组，包含该设备上支持的所有的安全单元。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型** | **说明**               |
| :------- | :--------------------- |
| Reader[] | 返回可用Reader对象数组。 |

**示例：**

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

检查SE服务是否已连接。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型** | **说明**                                       |
| :------- | :--------------------------------------------- |
| boolean  | true: SE服务状态已连接，false: SE服务状态已断开。 |

**示例：**

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

释放该Service分配的所有SE资源。此后[isConnected](#seserviceisconnected)将返回false。

**系统能力：**  SystemCapability.Communication.SecureElement

**示例：**

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

返回此实现所基于的Open Mobile API规范的版本号。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型** | **说明**                                           |
| -------- | -------------------------------------------------- |
| string   | OMA版本号（例如，“3.3”表示Open Mobile API规范版本3.3） |

**示例：**

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

返回此Reader的名称。如果此读卡器是SIM Reader，则其名称必须为“SIM[Slot]”。如果读卡器是eSE，则其名称须为“eSE”。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型** | **说明**   |
| -------- | ---------- |
| string   | Reader名称。 |

**示例：**

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

检查当前Reader所对应的安全单元是否可用。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型** | **说明**                                     |
| -------- | -------------------------------------------- |
| boolean  | true: 安全单元可用， false: 安全单元不可用。 |

**错误码：**

错误码的详细介绍请参见[SE错误码](../errorcodes/errorcode-se.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, service state exception. |

**示例：**

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

在SE Reader实例上创建连接会话，返回Session实例。在一个Reader上可能同时打开多个会话。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型** | **说明**                       |
| -------- | ------------------------------ |
| Session  | 连接会话Session实例。|

**错误码：**

错误码的详细介绍请参见[SE错误码](../errorcodes/errorcode-se.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, service state exception. |
| 3300104  | IOError, there is a communication problem to the reader or the SE.     |

**示例：**

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

关闭在此Reader上打开的所有Session。所有这些Session打开的所有Channel都将关闭。

**系统能力：**  SystemCapability.Communication.SecureElement

**错误码：**

错误码的详细介绍请参见[SE错误码](../errorcodes/errorcode-se.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, service state exception. |

**示例：**

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

获取提供此Session的Reader实例。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型** | **说明**                    |
| -------- | --------------------------- |
| Reader   | 返回此Session的Reader实例。 |

**示例：**

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

获取该SE的ATR。如果该SE的ATR不可用，则应返回空数组。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型** | **说明**                                     |
| -------- | -------------------------------------------- |
| number[] | 返回SE的ATR，SE的ATR不可用时，返回空的数组。 |

**错误码：**

错误码的详细介绍请参见[SE错误码](../errorcodes/errorcode-se.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, service state exception. |

**示例：**

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

关闭与SE的当前会话连接。这将关闭此Session打开的所有Channel。

**系统能力：**  SystemCapability.Communication.SecureElement

**错误码：**

错误码的详细介绍请参见[SE错误码](../errorcodes/errorcode-se.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, service state exception. |

**示例：**

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

检查Session是否关闭。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型** | **说明**                             |
| -------- | ------------------------------------ |
| boolean  | true：Session状态已关闭，false：Session是打开的。 |

**错误码：**

错误码的详细介绍请参见[SE错误码](../errorcodes/errorcode-se.md)。

**示例：**

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

关闭此Session上打开的所有Channel。

**系统能力：**  SystemCapability.Communication.SecureElement

**错误码：**

错误码的详细介绍请参见[SE错误码](../errorcodes/errorcode-se.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, service state exception. |

**示例：**

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

打开基础通道，参考[ISO 7816-4]协议，返回基础Channel实例对象。SE不能提供基础Channel或应用程序没有访问SE的权限时，返回null。

**系统能力：**  SystemCapability.Communication.SecureElement

**参数：**

| **参数名** | **类型** | **必填** | **说明**                                                     |
| ---------- | -------- | ------ | ------------------------------------------------------------ |
| aid        | number[] | 是      |在此Channel上选择的Applet的AID或如果没有Applet被选择时空的数组。|

**返回值：**

| **类型** | **说明**              |
| -------- | --------------------- |
| Channel  | 以Promise形式异步返回可用的基础Channel对象实例。 |

**错误码：**

错误码的详细介绍请参见[SE错误码](../errorcodes/errorcode-se.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, an attempt is made to use an SE session that has been closed. |
| 3300102  | NoSuchElementError, the AID on the SE is not available or cannot be selected.       |
| 3300103  | SecurityError, the calling application cannot be granted access to this AID or the default applet on this session.   |
| 3300104  | IOError, there is a communication problem to the reader or the SE.     |

**示例：**

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

打开基础通道，参考[ISO 7816-4]协议，返回基础Channel实例对象。SE不能提供基础Channel或应用程序没有访问SE的权限时，返回null。

**系统能力：**  SystemCapability.Communication.SecureElement

**参数：**

| **参数名** | **类型**               | **必填** | **说明**                                                     |
| ---------- | ---------------------- | ------ | ------------------------------------------------------------ |
| aid        | number[]               | 是      | 在此Channel上选择的Applet的AID或如果没有Applet被选择时空的数组。 |
| callback   | AsyncCallback\<Channel> | 是      | 以callback形式异步返回可用的基础Channel对象实例。                            |

**错误码：**

错误码的详细介绍请参见[SE错误码](../errorcodes/errorcode-se.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, an attempt is made to use an SE session that has been closed. |
| 3300102  | NoSuchElementError, the AID on the SE is not available or cannot be selected.       |
| 3300103  | SecurityError, the calling application cannot be granted access to this AID or the default applet on this session.   |
| 3300104  | IOError, there is a communication problem to the reader or the SE.     |

**示例：**

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

打开基础通道，参考[ISO 7816-4]协议，返回基础hannel实例对象。SE不能提供基础Channel或应用程序没有访问SE的权限时，返回null。

**系统能力：**  SystemCapability.Communication.SecureElement

**参数：**

| **参数名** | **类型** | **必填** | **说明**                                                     |
| ---------- | -------- | ------ | ------------------------------------------------------------ |
| aid        | number[] | 是       | 在此Channel上选择的Applet的AID或如果没有Applet被选择时空的数组。 |
| p2         | number   | 是       |在该Channel上执行的SELECT APDU的P2参数。                     |

**返回值：**

| **类型** | **说明**              |
| -------- | --------------------- |
| Channel  | 以Promise形式异步返回可用的基础Channel对象实例。 |

**错误码：**

错误码的详细介绍请参见[SE错误码](../errorcodes/errorcode-se.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, an attempt is made to use an SE session that has been closed. |
| 3300102  | NoSuchElementError, the AID on the SE is not available or cannot be selected.       |
| 3300103  | SecurityError, the calling application cannot be granted access to this AID or the default applet on this session.   |
| 3300104  | IOError, there is a communication problem to the reader or the SE.     |

**示例：**

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

打开基础通道，参考[ISO 7816-4]协议，返回基础Channel实例对象。SE不能提供基础Channel或应用程序没有访问SE的权限时，返回null。

**系统能力：**  SystemCapability.Communication.SecureElement

**参数：**

| **参数名** | **类型**               | **必填** | **说明**                                                     |
| ---------- | ---------------------- | ------ | ------------------------------------------------------------ |
| aid        | number[]               | 是      | 在此Channel上选择的Applet的AID或如果没有Applet被选择时空的数组。 |
| p2         | number                 | 是      | 此Channel上执行SELECT APDU命令的P2参数。                     |
| callback   | AsyncCallback\<Channel> | 是      | 以callback形式异步返回可用的基础Channel对象实例。                            |

**错误码：**

错误码的详细介绍请参见[SE错误码](../errorcodes/errorcode-se.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, an attempt is made to use an SE session that has been closed. |
| 3300102  | NoSuchElementError, the AID on the SE is not available or cannot be selected.      |
| 3300103  | SecurityError, the calling application cannot be granted access to this AID or the default applet on this session.   |
| 3300104  | IOError, there is a communication problem to the reader or the SE.     |

**示例：**

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

打开逻辑通道，参考[ISO 7816-4]协议，返回逻辑Channel实例对象。SE不能提供逻辑Channel或应用程序没有访问SE的权限时，返回null。

**系统能力：**  SystemCapability.Communication.SecureElement

**参数：**

| **参数名** | **类型** | **必填** | **说明**                                |
| ---------- | -------- | ------ | --------------------------------------- |
| aid        | number[] | 是      | 在此Channel上选择的Applet的AID或如果没有Applet被选择时空的数组。 |

**返回值：**

| **类型** | **说明**                                                     |
| -------- | ------------------------------------------------------------ |
| Channel  | 以Promise形式异步返回可用的逻辑Channel对象实例。 |

**错误码：**

错误码的详细介绍请参见[SE错误码](../errorcodes/errorcode-se.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, an attempt is made to use an SE session that has been closed. |
| 3300102  | NoSuchElementError, the AID on the SE is not available or cannot be selected.       |
| 3300103  | SecurityError, the calling application cannot be granted access to this AID or the default applet on this session.   |
| 3300104  | IOError, there is a communication problem to the reader or the SE.     |

**示例：**

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

打开逻辑通道，参考[ISO 7816-4]协议，返回逻辑Channel实例对象。SE不能提供逻辑Channel或应用程序没有访问SE的权限时，返回null。

**系统能力：**  SystemCapability.Communication.SecureElement

**参数：**

| **参数名** | **类型**               | **必填** | **说明**                                                     |
| ---------- | ---------------------- | ------ | ------------------------------------------------------------ |
| aid        | number[]               | 是      | 在此Channel上选择的Applet的AID或如果没有Applet被选择时空的数组。 |
| callback   | AsyncCallback\<Channel> | 是      | 以callback形式异步返回可用的逻辑Channel对象实例。 |

**错误码：**

错误码的详细介绍请参见[SE错误码](../errorcodes/errorcode-se.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, an attempt is made to use an SE session that has been closed. |
| 3300102  | NoSuchElementError, the AID on the SE is not available or cannot be selected.      |
| 3300103  | SecurityError, the calling application cannot be granted access to this AID or the default applet on this session.   |
| 3300104  | IOError, there is a communication problem to the reader or the SE.    |

**示例：**

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

打开逻辑通道，参考[ISO 7816-4]协议，返回逻辑Channel实例对象。SE不能提供逻辑Channel或应用程序没有访问SE的权限时，返回null。

**系统能力：**  SystemCapability.Communication.SecureElement

**参数：**

| **参数名** | **类型** | **必填** | **说明**                                  |
| ---------- | -------- | ------ | ----------------------------------------- |
| aid        | number[] | 是      | 在此Channel上选择的Applet的AID或如果没有Applet被选择时空的数组。 |
| p2         | number   | 是      | 此Channel上执行SELECT APDU命令的P2参数。  |

**返回值：**

| **类型** | **说明**       |
| -------- | -------------- |
| Channel | 以Promise形式异步返回可用的逻辑Channel实例对象。 |

**错误码：**

错误码的详细介绍请参见[SE错误码](../errorcodes/errorcode-se.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, an attempt is made to use an SE session that has been closed. |
| 3300102  | NoSuchElementError, the AID on the SE is not available or cannot be selected.      |
| 3300103  | SecurityError, the calling application cannot be granted access to this AID or the default applet on this session.   |
| 3300104  | IOError, there is a communication problem to the reader or the SE.     |

**示例：**

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

打开逻辑通道，参考[ISO 7816-4]协议，返回Channel实例对象。SE不能提供逻辑Channel或应用程序没有访问SE的权限时，返回null。

**系统能力：**  SystemCapability.Communication.SecureElement

**参数：**

| **参数名** | **类型**               | **必填** | **说明**                                                     |
| ---------- | ---------------------- | ------ | ------------------------------------------------------------ |
| aid        | number[]               | 是      | 在此Channel上选择的Applet的AID或如果没有Applet被选择时空的数组。 |
| p2         | number                 | 是      | 此Channel上执行SELECT APDU命令的P2参数。 |
| callback   | AsyncCallback\<Channel> | 是      | 以callback形式异步返回可用的逻辑Channel对象实例。 |

**错误码：**

错误码的详细介绍请参见[SE错误码](../errorcodes/errorcode-se.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, an attempt is made to use an SE session that has been closed. |
| 3300102  | NoSuchElementError, the AID on the SE is not available or cannot be selected.       |
| 3300103  | SecurityError, the calling application cannot be granted access to this AID or the default applet on this session.   |
| 3300104  | IOError, there is a communication problem to the reader or the SE.     |

**示例：**

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

获取打开该Channel的Session对象。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型** | **说明**                      |
| -------- | ----------------------------- |
| Session  | 该Channel绑定的Session 对象。 |

**示例：**

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

关闭Channel。

**系统能力：**  SystemCapability.Communication.SecureElement

**示例：**

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

检查该Channel是否为基础Channel。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型** | **说明**                                                     |
| -------- | ------------------------------------------------------------ |
| boolean  | true: 该Channel是基础Channel, false：该Channel逻辑Channel 。 |

**示例：**

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

检查该Channel是否已被关闭。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型** | **说明**                                      |
| -------- | --------------------------------------------- |
| boolean  | true: Channel是关闭的，false: 不是关闭的。 |

**示例：**

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

获取SELECT Applet时的响应数据，包含状态字。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型** | **说明**                                                     |
| -------- | ------------------------------------------------------------ |
| number[] | SELECT Applet时的响应数据，包含状态字。 |

**错误码：**

错误码的详细介绍请参见[SE错误码](../errorcodes/errorcode-se.md)。

**示例：**

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

向SE发送APDU数据，数据符合ISO/IEC 7816规范。

**系统能力：**  SystemCapability.Communication.SecureElement

**参数：**

| **参数名** | **类型** | **必填** | **说明**                              |
| ---------- | -------- | ------ | ------------------------------------- |
| command    | number[] | 是      | 需要发送到SE的APDU数据。 |

**返回值：**

| **类型** | **说明**       |
| -------- | -------------- |
| number[] | 以Promise形式异步返回接收到的响应APDU数据，number数组。 |

**错误码：**

错误码的详细介绍请参见[SE错误码](../errorcodes/errorcode-se.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, an attempt is made to use an SE session or channel that has been closed. |
| 3300103  | SecurityError, the command is filtered by the security policy. |
| 3300104  | IOError, there is a communication problem to the reader or the SE.     |

**示例：**

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

向SE发送APDU数据，数据符合ISO/IEC 7816规范。

**系统能力：**  SystemCapability.Communication.SecureElement

**参数：**

| **参数名** | **类型**                | **必填** | **说明**                              |
| ---------- | ----------------------- | ------ | ------------------------------------- |
| command    | number[]                | 是      | 需要发送到SE的APDU数据。 |
| callback   | AsyncCallback\<number[]> | 是      | 返回接收到的响应APDU数据，number数组。  |

**错误码：**

错误码的详细介绍请参见[SE错误码](../errorcodes/errorcode-se.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 3300101  | IllegalStateError, an attempt is made to use an SE session or channel that has been closed. |
| 3300103  | SecurityError, the command is filtered by the security policy. |
| 3300104  | IOError, there is a communication problem to the reader or the SE.     |

**示例：**

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
