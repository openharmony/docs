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

let nfcSEService = null;

try {
    nfcSEService = secureElement.newSEService("serviceState", (state) => {
        if (state == secureElement.ServiceState.DISCONNECTED) {
            console.log("Service state is Disconnected");
        } else {
            console.log.("Service state is Connected");
        }
    });
} catch (e) {
    console.log("newSEService occurs exception:" + e.message);
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
import secureElement from '@ohos.secureElement';

let nfcSEService = null;
let nfcServiceState = null;
let nfcOmaReader = null;
let nfcOmaReaderList = null;

// get SEService
try {
    nfcSEService = secureElement.newSEService("serviceState", (state) => {
        if (state == secureElement.ServiceState.DISCONNECTED) {
            console.log("Service state is Disconnected");
        } else {
            console.log("Service state is Connected");
        }
    });
} catch (e) {
    console.log("newSEService excpetion:" + e.message);
}

try {
    nfcOmaReaderList = nfcSEService.getReaders();
    if (nfcOmaReaderList != null && nfcOmaReaderList.length > 0) {
        nfcOmaReader = this.nfcOmaReaderList[0];
        console.log("get reader successfully");
    } else {
        console.log("get reader failed");
    }
} catch (e) {
    console.log("getReaders exception:" + e.message);
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
import secureElement from '@ohos.secureElement';

let nfcSEService = null;

try {
    let ret: boolean;
    // refer to newSEService for this.nfcSEService 
    ret = nfcSEService.isConnected();
    if (ret) {
        console.log("get state: connected");
    } else {
        console.log("get state: not connected");
    }
} catch (e) {
    console.log("isConnected exception: " + e.message);
}
```

## SEService.shutdown

shutdown(): void

释放该service分配的所有SE资源。此后[isConnected](#seserviceisconnected)将返回false。

**系统能力：**  SystemCapability.Communication.SecureElement

**示例：**

```js
import secureElement from '@ohos.secureElement';


let nfcSEService = null;

try {
    // refer to newSEService for this.nfcSEService 
    nfcSEService.shutdown();
    console.log("shutdown successfully");
} catch (e) {
    console.log("shutdown exception:" + e.message);
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
import secureElement from '@ohos.secureElement';

let nfcSEService = null;

this.result = "version: "
try {
    // refer to newSEService for this.nfcSEService 
    console.log("version: " + nfcSEService.getVersion());
} catch (e) {
    console.log("getVersion exception:" + e.message);
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
import secureElement from '@ohos.secureElement';

let nfcOmaReader = null;

try {
    // refer to SEService.getReaders for this.nfcOmaReader 
    console.log(nfcOmaReader.getName());
} catch (e) {
    console.log("getName exception:" + e.message);
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
| 3300101  | Illegal service state exception. |

**示例：**

```js
import secureElement from '@ohos.secureElement';

let nfcOmaReader = null;

try {
    // refer to SEService.getReaders for this.nfcOmaReader
    if (nfcOmaReader.isSecureElementPresent()) {
        console.log("isSecureElementPresent TRUE");
    } else {
        console.log("isSecureElementPresent FALSE");
    }
} catch (e) {
    console.log("isSecureElementPresent exception:" + e.message);
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
| 3300101  | Illegal service state exception. |
| 3300104  | Secure element IO exception.     |

**示例：**

```js
import secureElement from '@ohos.secureElement';

let nfcOmaReader = null;
let nfcOmaSession = null;

try {
    // refer to SEService.getReaders for this.nfcOmaReader
    nfcOmaSession = nfcOmaReader.openSession();
    if (nfcOmaSession) {
        console.log("get session successfully");
    } else {
        console.log("get session failed");
    }
} catch (e) {
    console.log("OpenSession exception: " + e.message);
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
| 3300101  | Illegal service state exception. |

**示例：**

```js
import secureElement from '@ohos.secureElement';

nfcOmaReader = null;

try {
    // refer to SEService.getReaders for this.nfcOmaReader
    nfcOmaReader.closeSessions();
    console.log("close Sessions successfully");
} catch (e) {
    console.log("closeSessions exception:" + e.message);
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
import secureElement from '@ohos.secureElement';

let nfcOmaReader = null;
let nfcOmaSession = null;

try {
    // refer to Reader.openSession for this.nfcOmaSession
    nfcOmaReader = nfcOmaSession.getReader();
    if (nfcOmaReader) {
        console.log("get reader successfully");
    } else {
        console.log("get reader failed");
    }
} catch (e) {
    console.log("getReader exception:" + e.message);
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
| 3300101  | Illegal service state exception. |

**示例：**

```js
import secureElement from '@ohos.secureElement';

let nfcOmaSession = null;
let str = ""; 

try {
    // refer to Reader.openSession for this.nfcOmaSession
    let ret = nfcOmaSession.getATR();
    if (ret) {
       str = 'getATR result:[';
        for (let i = 0; i < ret.length; ++i) {
            str += ret[i];
            str += ' ';
        }
        str += ']';
        console.log(str);
    } else {
        console.log("getATR result is null");
    }
} catch (e) {
    console.log("getATR exception:" + e.message);
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
| 3300101  | Illegal service state exception. |

**示例：**

```js
import secureElement from '@ohos.secureElement';

let nfcOmaSession = null;

try {
    // refer to Reader.openSession for this.nfcOmaSession
    nfcOmaSession.close();
    console.log("session close successfully");
} catch (e) {
    console.log("session close exception:" + e.message);
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
import secureElement from '@ohos.secureElement';

let nfcOmaSession = null;

try {
    // refer to Reader.openSession for this.nfcOmaSession
    let ret = nfcOmaSession.isClosed();
    if (ret) {
        console.log("session state is closed");
    } else {
        console.log("session state is not closed");
    }
} catch (e) {
    console.log("isClosed exception:" + e.message);
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
| 3300101  | Illegal service state exception. |

**示例：**

```js
import secureElement from '@ohos.secureElement';

let nfcOmaSession = null;

try {
    // refer to Reader.openSession for this.nfcOmaSession
    nfcOmaSession.closeChannels();
    console.log("close Channels successfully");
} catch (e) {
    console.log("closeChannels exception:" + e.message);
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
| 3300101  | Illegal service state exception. |
| 3300102  | No such element exception.       |
| 3300103  | Illegal access rule exception.   |
| 3300104  | Secure element IO exception.     |

**示例：**

```js
import secureElement from '@ohos.secureElement';

let nfcOmaSession = null;
let nfcOmaChannel = null;

try {
    // refer to Reader.openSession for this.nfcOmaSession
    let getPromise = nfcOmaSession.openBasicChannel(this.aidArray);
    getPromise.then((channel) => {
        nfcOmaChannel = channel;
        console.log("openBasicChannel1 get channel successfully");
    }).catch ((err) => {
        console.log("openBasicChannel1 exception:" + err.message);
    });
} catch (e) {
    console.log("OpenBasicChannel1 exception:" + e.message);
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
| 3300101  | Illegal service state exception. |
| 3300102  | No such element exception.       |
| 3300103  | Illegal access rule exception.   |
| 3300104  | Secure element IO exception.     |

**示例：**

```js
import secureElement from '@ohos.secureElement';

let nfcOmaSession = null;
let nfcOmaChannel = null;
let aidArray = [720, 1080];

try {
    // refer to Reader.openSession for this.nfcOmaSession
    nfcOmaSession.openBasicChannel(aidArray, (error, data) => {
        if (error) {
            console.log("openBasicChannel2 failed:" + JSON.stringify(error));
            return;
        }
        nfcOmaChannel = data;
        console.log("openBasicChannel2 get channel successfully");
    });
} catch (e) {
    console.log("openBasicChannel2 exception:" + e.message);
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
| 3300101  | Illegal service state exception. |
| 3300102  | No such element exception.       |
| 3300103  | Illegal access rule exception.   |
| 3300104  | Secure element IO exception.     |

**示例：**

```js
import secureElement from '@ohos.secureElement';

let nfcOmaSession = null;
let nfcOmaChannel = null;
let aidArray = [720, 1080];
let p2 = 0x00;

try {
    // refer to Reader.openSession for this.nfcOmaSession
    let getPromise = nfcOmaSession.openBasicChannel(aidArray, p2);
    getPromise.then((channel) => {
        nfcOmaChannel = channel;
        console.log("openBasicChannel3 get channel successfully");
    }).catch ((err) => {
        console.log("openBasicChannel3 exception");
    });
} catch (e) {
    console.log("openBasicChannel3 exception:" + e.message);
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
| 3300101  | Illegal service state exception. |
| 3300102  | No such element exception.       |
| 3300103  | Illegal access rule exception.   |
| 3300104  | Secure element IO exception.     |

**示例：**

```js
import secureElement from '@ohos.secureElement';


let nfcOmaSession = null;
let nfcOmaChannel = null;
let aidArray = [720, 1080];
let p2 = 0x00;

try {
    // refer to Reader.openSession for this.nfcOmaSession
    nfcOmaSession.openBasicChannel(aidArray, p2, (error, data) => {
        if (error) {
            console.log("openBasicChannel4 failed:" + JSON.stringify(error));
            return;
        }
        nfcOmaChannel = data;
        console.log("openBasicChannel4 get channel successfully");
    });
} catch (e) {
    console.log("openBasicChannel4 exception:" + e.message);
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
| 3300101  | Illegal service state exception. |
| 3300102  | No such element exception.       |
| 3300103  | Illegal access rule exception.   |
| 3300104  | Secure element IO exception.     |

**示例：**

```js
import secureElement from '@ohos.secureElement';

let nfcOmaSession = null;
let nfcOmaChannel = null;
let aidArray = [720, 1080];

try {
    // refer to Reader.openSession for this.nfcOmaSession
    let getPromise = nfcOmaSession.openLogicalChannel(aidArray)
    getPromise.then((channel) => {
        nfcOmaChannel = channel;
   	    console.log("openLogicChannel1 get channel successfully");
    }).catch ((err) => {
        console.log("openLogicChannel1 exception:" + err.message);
    });
} catch (e) {
    console.log("openLogicChannel1 exception:" + e.message);
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
| 3300101  | Illegal service state exception. |
| 3300102  | No such element exception.       |
| 3300103  | Illegal access rule exception.   |
| 3300104  | Secure element IO exception.     |

**示例：**

```js
import secureElement from '@ohos.secureElement';

let nfcOmaSession = null;
let nfcOmaChannel = null;
let aidArray = [720, 1080];

try {
    // refer to Reader.openSession for this.nfcOmaSession
    nfcOmaSession.openLogicalChannel(aidArray, (error, data) => {
        if (error) {
            console.log("openLogicChannel2 failed:" + JSON.stringify(error));
            return;
        }
        nfcOmaChannel = data;
        console.log("openLogicChannel2 get channel successfully");
    });
} catch (e) {
    console.log("openLogicChannel2 exception:" + e.message);
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
| 3300101  | Illegal service state exception. |
| 3300102  | No such element exception.       |
| 3300103  | Illegal access rule exception.   |
| 3300104  | Secure element IO exception.     |

**示例：**

```js
import secureElement from '@ohos.secureElement';


let nfcOmaSession = null;
let nfcOmaChannel = null;
let aidArray = [720, 1080];
let p2 = 0x00;

if (nfcOmaSession) {
    try {
    // refer to Reader.openSession for this.nfcOmaSession
        let getPromise = nfcOmaSession.openLogicalChannel(aidArray, p2);
        getPromise.then((channel) => {
            nfcOmaChannel = channel;
            console.log("openLogicChannel3 get channel successfully");
        }).catch ((err) => {
            console.log("openLogicChannel3 exception");
        })
} catch (e) {
    console.log("openLogicChannel3 exception:" + e.message);
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
| 3300101  | Illegal service state exception. |
| 3300102  | No such element exception.       |
| 3300103  | Illegal access rule exception.   |
| 3300104  | Secure element IO exception.     |

**示例：**

```js
import secureElement from '@ohos.secureElement';

let nfcOmaSession = null;
let nfcOmaChannel = null;
let aidArray = [720, 1080];
let p2 = 0x00;

try {
    // refer to Reader.openSession for this.nfcOmaSession
    nfcOmaSession.openLogicalChannel(aidArray, p2, (error, data) => {
        if (error) {
            console.log("openLogicChannel4 failed:" + JSON.stringify(error));
            return;
        }
        nfcOmaChannel = data;
        console.log("openLogicChannel4 get channel successfully");
    })
} catch (e) {
    console.log("openLogicChannel4 exception:" + e.message);
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
import secureElement from '@ohos.secureElement';

let nfcOmaSession = null;
let nfcOmaChannel = null;

try {
    // refer to Session.openBasicChannel for this.nfcOmaChannel
    let ret = nfcOmaChannel.getSession();
    if (ret) {
        console.log("get session successfully");
    } else {
        console.log("get session failed");
    }
} catch (e) {
    console.log("getSession exception:" + e.message);
}
```

## Channel. close

close(): void

关闭与SE的此channel。

**系统能力：**  SystemCapability.Communication.SecureElement

**示例：**

```js
import secureElement from '@ohos.secureElement';

let nfcOmaSession = null;
let nfcOmaChannel = null;

try {
    // refer to Session.openBasicChannel for this.nfcOmaChannel
    nfcOmaChannel.close();
    console.log("channel close successfully");
} catch (e) {
    console.log("channel close exception:" + e.message);
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
import secureElement from '@ohos.secureElement';

let nfcOmaChannel = null;

try {
    // refer to Session.openBasicChannel for this.nfcOmaChannel
    let ret = nfcOmaChannel.isBasicChannel();
    if (ret) {
        console.log("isBasicChannel TRUE");
    } else {
        console.log("isBasicChannel FALSE");
    }
} catch (e) {
    console.log("isBasicChannel异常:" + e.message);
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
import secureElement from '@ohos.secureElement';

let nfcOmaChannel = null;

try {
    // refer to Session.openBasicChannel for this.nfcOmaChannel
    let ret = nfcOmaChannel.isClosed();
    if (ret) {
        console.log("channel isClosed TRUE");
    } else {
        console.log("channel isClosed False");
    }
} catch (e) {
    console.log("Channel isClosed exception:" + e.message);
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
import secureElement from '@ohos.secureElement';

let str = '';
let nfcOmaChannel = null;

try {
    // refer to Session.openBasicChannel for this.nfcOmaChannel
    let ret = nfcOmaChannel.getSelectResponse();
    if (ret) {
        str = "getSelectResponse result:[";
        for (let i = 0; i < ret.length; ++i) {
            str += ret[i];
            str += ' ';
        }
        str += ']';
        console.log(str);
    } else {
        console.log("getSelectResponse result is null");
    }
} catch (e) {
    console.log("getSelectResponse exception:" + e.message);
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
| 3300101  | Illegal service state exception. |
| 3300103  | Illegal access rule exception.   |
| 3300104  | Secure element IO exception.     |

**示例：**

```js
import secureElement from '@ohos.secureElement';

let nfcOmaChannel = null;
let str = "";
try {
    let command: number[] = [100, 200];
    // refer to Session.openBasicChannel for this.nfcOmaChannel
    let getPromise = nfcOmaChannel.transmit(command);
    getPromise.then((data) => {
        str = "transmit1 result:[";
        for (let i = 0; i < data.length; ++i) {
            str += data[i];
            str += " ";
        }
        str += "]";
        console.log(str);
    }).catch ((err) => {
        console.log("transmit1 exception:" + err.code);
    })
} catch (e) {
    console.log("transit1 exception:" + e.message);
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
| 3300101  | Illegal service state exception. |
| 3300103  | Illegal access rule exception.   |
| 3300104  | Secure element IO exception.     |

**示例：**

```js
import secureElement from '@ohos.secureElement';

let str = "";
let nfcOmaChannel = null;

try {
    let command: number[] = [100, 200];
    // refer to Session.openBasicChannel for this.nfcOmaChannel
    nfcOmaChannel.transmit(command, (error, data) => {
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
} catch (e) {
    console.log("transit2 exception:" + e.message);
}
```
