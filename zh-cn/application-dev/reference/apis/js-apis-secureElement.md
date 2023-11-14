# @ohos.secureElement (安全单元的通道管理)

本模块主要用于操作及管理安全单元（SecureElement，简称SE）。文档中出现的SE服务为SEService实例，参见[newSEService](#secureelementnewseservice)。

对于文档中出现以下类型说明：

| 类型    | 说明                                           |
| ------- | ---------------------------------------------- |
| Session | 此类的实例表示与设备上可用的某个SE的连接会话。 |
| Reader  | 此类的实例表示该设备支持的SE Reader。          |
| Channel | 此类的实例表示向SE打开的ISO/IEC 7816-4通道。   |

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## **导入模块**

```js
import secureElement from '@ohos.secureElement';
```

## secureElement.ServiceState

定义不同的SE 服务状态值。

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
| type       | string                                               | 是      | 'serviceState'       |
| callback   | Callback<[ServiceState](#secureelementservicestate)> | 是      | 返回SE服务状态的回调 |

**返回值：**

| **类型**  | **说明**   |
| :-------- | :--------- |
| SEService | SE服务实例 |

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
    console.log("newSEService occurs " + "exception: ${(e : BusinessError).message}");
}
```

## SEService.getReaders

getReaders(): Reader[]

返回可用SE Reader的数组。返回的数组中不能有重复的对象。即使没有插入卡，也应列出所有可用的reader。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型** | **说明**               |
| :------- | :--------------------- |
| Reader[] | 返回可用Reader对象数组 |

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

检查SE服务是否已连接

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型** | **说明**                                       |
| :------- | :--------------------------------------------- |
| boolean  | true:SE 服务状态已连接  false:SE服务状态已断开 |

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
    console.log("newSEService" + "exception: ${(e : BusinessError).message}");
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
        console.log("isConnected " + "exception: ${(e : BusinessError).message}");
}
```

## SEService.shutdown

shutdown(): void

释放该service分配的所有SE资源。此后[isConnected](#seserviceisconnected)将返回false。

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
    console.log("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    // refer to newSEService for this.nfcSEService 
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

返回此实现所基于的OMA规范的版本号。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型** | **说明**                                           |
| -------- | -------------------------------------------------- |
| string   | OMA版本号（例如，“3.3”表示开放移动API规范版本3.3） |

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
    console.log("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    // refer to newSEService for this.nfcSEService 
    if (nfcSEService != null) {
        console.log("version: " + nfcSEService.getVersion());
    }
} catch (e) {
    console.log("getVersion " + "exception: ${(e : BusinessError).message}");
}
```

## Reader.getName

getName(): string

返回此reader的名称。如果此读卡器是SIM reader，则其名称必须为“SIM[Slot]”。如果读卡器是嵌入式SE reader，则其名称须为“eSE[slot]”。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型** | **说明**   |
| -------- | ---------- |
| string   | reader名称 |

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

连接到此reader中的SE。此方法在返回会话对象之前准备（初始化）SE进行通信。同一reader上可能同时打开多个会话。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型** | **说明**                       |
| -------- | ------------------------------ |
| Session  | 用于创建channel的Session对象。 |

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

关闭在此reader上打开的所有session。所有这些session打开的所有channel都将关闭。

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
    console.log("newSEService " + "exception: ${(e : BusinessError).message}");
}

try {
    if(nfcSEService != null) {
        nfcOmaReaderList = nfcSEService.getReaders();
    }
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        nfcOmaReaderList[0].closeSessions();
        console.log("closeSessions successfully");
    } else {
        console.log("closeSessions failed");
    }
} catch (e) {
  console.log("closeSessions " + "exception: ${(e : BusinessError).message}");
}
```

## Session.getReader

getReader(): Reader

获取提供此session的reader。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型** | **说明**                    |
| -------- | --------------------------- |
| Reader   | 返回此session的Reader对象。 |

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
            str += ' ';
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

关闭与SE的连接。这将关闭此应用程序与此SE打开的所有channel。

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

检查session是否关闭。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型** | **说明**                             |
| -------- | ------------------------------------ |
| boolean  | true：session状态已关闭，否则false。 |

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

关闭此session上打开的所有channel。

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

获取基本channel，参考[ISO 7816-4]协议，返回Channel实例对象，SE不能提供新逻辑Channel或因缺乏可用逻辑Channel对象而无法获取访问控制规则，返回null。

**系统能力：**  SystemCapability.Communication.SecureElement

**参数：**

| **参数名** | **类型** | **必填** | **说明**                                                     |
| ---------- | -------- | ------ | ------------------------------------------------------------ |
| aid        | number[] | 是      |在此channel上选择的applet的AID数组或如果没有applet被选择时空的数组null。 |

**返回值：**

| **类型** | **说明**              |
| -------- | --------------------- |
| Channel  | 可用Channel对象实例。 |

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

获取基本channel，参考[ISO 7816-4]协议，返回channel实例对象，SE不能提供新逻辑Channel或因缺乏可用逻辑Channel对象而无法获取访问控制规则，返回null。

**系统能力：**  SystemCapability.Communication.SecureElement

**参数：**

| **参数名** | **类型**               | **必填** | **说明**                                                     |
| ---------- | ---------------------- | ------ | ------------------------------------------------------------ |
| aid        | number[]               | 是      | 在此channel上选择的applet的AID数组或null 如果没有applet被选择。 |
| callback   | AsyncCallback\<Channel> | 是      | callback返回可用Channel对象实例。                            |

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

获取基本channel，参考[ISO 7816-4]协议，返回Channel实例对象，SE不能提供新逻辑Channel对象或因缺乏可用逻辑Channel对象而无法获取访问控制规则，返回null。

**系统能力：**  SystemCapability.Communication.SecureElement

**参数：**

| **参数名** | **类型** | **必填** | **说明**                                                     |
| ---------- | -------- | ------ | ------------------------------------------------------------ |
| aid        | number[] | 是       | 在此channel上选择的applet的AID数组或null 如果没有applet被选择。 |
| p2         | number   | 是       |在该channel上执行的SELECT APDU的P2参数。                     |

**返回值：**

| **类型** | **说明**              |
| -------- | --------------------- |
| Channel  | 可用Channel对象实例。 |

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

获取基本channel，参考[ISO 7816-4]协议，返回channel实例对象，SE不能提供新逻辑Channel对象或因缺乏可用逻辑Channel对象而无法获取访问控制规则，返回null。

**系统能力：**  SystemCapability.Communication.SecureElement

**参数：**

| **参数名** | **类型**               | **必填** | **说明**                                                     |
| ---------- | ---------------------- | ------ | ------------------------------------------------------------ |
| aid        | number[]               | 是      | 在此channel上选择的applet的AID数组或null 如果没有applet被选择。 |
| p2         | number                 | 是      | 此channel上执行SELECT APDU命令的P2参数。                     |
| callback   | AsyncCallback\<Channel> | 是      | callback返回可用Channel对象实例。                            |

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

打开指定SE的逻辑Channel对象。

**系统能力：**  SystemCapability.Communication.SecureElement

**参数：**

| **参数名** | **类型** | **必填** | **说明**                                |
| ---------- | -------- | ------ | --------------------------------------- |
| aid        | number[] | 是      | 在该Channel对象上选择的applet AID数组。 |

**返回值：**

| **类型** | **说明**                                                     |
| -------- | ------------------------------------------------------------ |
| Channel  | 返回可用Channel对象实例，SE不能提供新的Channel对象或因缺乏可用逻辑Channel对象无法获取访问控制规则返回null。 |

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

打开指定SE的逻辑Channel对象。

**系统能力：**  SystemCapability.Communication.SecureElement

**参数：**

| **参数名** | **类型**               | **必填** | **说明**                                                     |
| ---------- | ---------------------- | ------ | ------------------------------------------------------------ |
| aid        | number[]               | 是      | 在该Channel对象上被选择的applet AID数组。                    |
| callback   | AsyncCallback\<Channel> | 是      | callback返回可用Channel对象实例，SE不能提供新的channel或因缺乏可用逻辑Channel对象无法获取访问控制规则返回null。 |

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

使用SE打开逻辑通道，选择由给定AID数组（AID非null且长度不为0）表示的applet.

如果AID数组长度为0，则该方法将通过发送一个select命令来选择SE的Issuer Security Domain，该命令的AID长度为0（如[GPCS]中所定义）。

如果AID为Null，则该方法应仅发送MANAGE CHANNEL Open（管理通道打开），而不应发送SELECT（选择）命令。在这种情况下，默认情况下将选择与逻辑通道关联的默认applet.

P2通常为0x00。设备应允许P2的任何值，并且应允许以下值： 0x00, 0x04, 0x08, 0x0C (如 [ISO 7816-4](https://www.iso.org/standard/77180.html)中所定义).

**系统能力：**  SystemCapability.Communication.SecureElement

**参数：**

| **参数名** | **类型** | **必填** | **说明**                                  |
| ---------- | -------- | ------ | ----------------------------------------- |
| aid        | number[] | 是      | 在该Channel对象上被选择的applet AID数组。 |
| p2         | number   | 是      | 此channel上执行SELECT APDU命令的P2参数。  |

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

使用SE打开逻辑通道，选择由给定AID数组（AID非null且长度不为0）表示的applet.

如果AID数组长度为0，则该方法将通过发送一个select命令来选择SE的Issuer Security Domain，该命令的AID长度为0（如[GPCS]中所定义）。

如果AID为Null，则该方法应仅发送MANAGE CHANNEL Open（管理通道打开），而不应发送SELECT（选择）命令。在这种情况下，默认情况下将选择与逻辑通道关联的默认applet.

P2通常为0x00。设备应允许P2的任何值，并且应允许以下值： 0x00, 0x04, 0x08, 0x0C (如 [ISO 7816-4](https://www.iso.org/standard/77180.html)中所定义).

**系统能力：**  SystemCapability.Communication.SecureElement

**参数：**

| **参数名** | **类型**               | **必填** | **说明**                                                     |
| ---------- | ---------------------- | ------ | ------------------------------------------------------------ |
| aid        | number[]               | 是      | 在该Channel对象上被选择的applet AID数组。                    |
| p2         | number                 | 是      | 此channel上执行SELECT APDU命令的P2参数。                     |
| callback   | AsyncCallback\<Channel> | 是      | callback返回可用Channel对象实例，SE不能提供新的Channel对象或因缺乏可用逻辑Channel对象无法获取访问控制规则返回null。 |

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

获取打开该channel的Session对象。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型** | **说明**                      |
| -------- | ----------------------------- |
| Session  | 该channel绑定的Session 对象。 |

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

关闭与SE的此channel。

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

检查该channel是否为基本channel。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型** | **说明**                                                     |
| -------- | ------------------------------------------------------------ |
| boolean  | true: 该channel是基本channel false：该channel不是基本channel 。 |

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

检查该channel是否为closed。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型** | **说明**                                      |
| -------- | --------------------------------------------- |
| boolean  | true:channel是closed  false: 不是closed状态。 |

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

返回从应用程序选择命令接收的数据，包括在applet选择时接收的状态字。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型** | **说明**                                                     |
| -------- | ------------------------------------------------------------ |
| number[] | 返回从应用程序选择命令接收的数据，包括在applet选择时接收的状态字。 |

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

向SE发送APDU命令（根据ISO/IEC 7816）。

**系统能力：**  SystemCapability.Communication.SecureElement

**参数：**

| **参数名** | **类型** | **必填** | **说明**                              |
| ---------- | -------- | ------ | ------------------------------------- |
| command    | number[] | 是      | 在该channel上被选择的applet AID数组。 |

**返回值：**

| **类型** | **说明**       |
| -------- | -------------- |
| number[] | 响应结果数组。 |

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
            // refer to Session.openBasicChannel for this.nfcOmaChannel
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

向SE发送APDU命令（根据ISO/IEC 7816）。

**系统能力：**  SystemCapability.Communication.SecureElement

**参数：**

| **参数名** | **类型**                | **必填** | **说明**                              |
| ---------- | ----------------------- | ------ | ------------------------------------- |
| command    | number[]                | 是      | 在该Channel上被选择的applet AID数组。 |
| callback   | AsyncCallback<number[]> | 是      | 返回接收到的响应的回调，number数组。  |

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
            // refer to Session.openBasicChannel for this.nfcOmaChannel
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
