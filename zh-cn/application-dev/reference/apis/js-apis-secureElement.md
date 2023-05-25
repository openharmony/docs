# @ohos.secureElement(SE服务管理&SE Reader管理& 基础和逻辑通道管理)

本模块主要用于

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## **导入模块**

```js
import secureElement from '@ohos.secureElement';
```

## ServiceState

定义不同的SE 服务状态值。

**系统能力：**  SystemCapability.Communication.SecureElement

| 名称         | 值   | 说明               |
| ------------ | ---- | ------------------ |
| DISCONNECTED | 0    | SE服务状态已断开。 |
| CONNECTED    | 1    | SE服务状态已连接。 |

## secureElement.newSEService

newSEService(type: 'serviceState', callback: Callback<[ServiceState](#ServiceState)>): [SEService](#SEService)

建立一个可用于连接到系统中所有可用SE的新连接（服务）。连接过程可能很长，所以它是以异步方式进行的。仅当

指定的回调或者如果[isConnected](#SEService.isConnected)返回true时，该返回[SEService](#SEService)对象是可用的。

> **说明：**
> 从 API version10 开始支持

**系统能力：**  SystemCapability.Communication.SecureElement

**参数：**

| **参数名** | **类型**                                | **说明**               |
| ---------- | --------------------------------------- | ---------------------- |
| type       | string                                  | 'serviceState'         |
| callback   | Callback<[ServiceState](#ServiceState)> | 返回service 状态的回调 |

**返回值：**

| **类型**  | **说明**                                                     |
| :-------- | :----------------------------------------------------------- |
| SEService | 仅当callback状态是[ServiceState](#ServiceState).CONNECTED或[isConnected](#SEService.isConnected)接口返回值是true时，该service可用。                失败抛出异常 |

**错误码：**

错误码的详细介绍请参见[SE错误码](../errorcodes/errorcode-se.md)。

**示例：**

```js
import secureElement from '@ohos.secureElement';

@State result: string = ''
@State nfcSEService: secureElement.SEService = null;

this.result = "获取SEService结果：";
try 
{
    this.nfcSEService = secureElement.newSEService("serviceState", (state) => 				 	 	{
    		if (state == secureElement.ServiceState.DISCONNECTED) {
           		this.result = "Service state is Disconnected";
        	} else {
           		this.result = "Service state is connected";
        	}
    	}
    );
} catch (e) {
  this.result += "newSEService出现异常:" + e.message;
}
```

## SEService.getReaders

getReaders(): [Reader](#Reader)[]

返回可用SE [Reader](#Reader)的数组。返回的数组中不能有重复的对象。即使没有插入卡，也应列出所有可用的reader

> **说明：**
> 从 API version 10

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型**            | **说明**                          |
| :------------------ | :-------------------------------- |
| [Reader](#Reader)[] | 返回可用[Reader](#Reader)对象数组 |

**错误码：**

错误码的详细介绍请参见[SE错误码](../errorcodes/errorcode-se.md)。

**示例：**

```js
import secureElement from '@ohos.secureElement';

@State result: string = ''
@State nfcSEService: secureElement.SEService = null;
@State nfcServiceState: secureElement.ServiceState = null;
@State nfcOmaReader: secureElement.Reader = null;

// get SEService
try 
{
    this.nfcSEService = secureElement.newSEService("serviceState", (state) => 				 	 	{
    		if (state == secureElement.ServiceState.DISCONNECTED) {
           		this.result = "Service state is Disconnected";
        	} else {
           		this.result = "Service state is connected";
        	}
    	}
    );
} catch (e) {
  this.result += "newSEService出现异常:" + e.message;
}

try {
   this.nfcOmaReader = this.nfcSEService.getReaders()[0];
   if (this.nfcOmaReader) {
      this.result = "获取reader成功";
   } else {
      this.result = "获取reader失败";
   }
} catch (e) {
    this.result = "getReaders异常：" + e.message;
}
```

## SEService.isConnected

isConnected(): boolean

检查SE服务是否已连接

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型** | **说明**                                                     |
| :------- | :----------------------------------------------------------- |
| boolean  | true:SE 服务状态[ServiceState](#ServiceState).CONNECTED  false：SE服务状态[ServiceState](#ServiceState).DISCONNECTED |

**错误码：**

错误码的详细介绍请参见[SE错误码](../errorcodes/errorcode-se.md)。

**示例：**

```JS
import secureElement from '@ohos.secureElement';

@State result: string = ''
@State nfcSEService: secureElement.SEService = null;

try {
	let ret: boolean;
    // 有效this.nfcSEService,获取方式参考newService
    ret = this.nfcSEService.isConnected();
    if (ret) {
    	this.result = '获取连接状态：connected';
    } else {
        this.result = '获取连接状态：not connected';
    }
} catch (e) {
    this.result = "isConnected异常:" + e.message;
}
```

## SEService.shutdown

shutdown(): void

释放该service分配的所有SE资源。此后[isConnected](#SEService.isConnected)将返回false。

> **说明：**
> 从 API version 10 开始支持。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型** | **说明**     |
| -------- | ------------ |
| void     | 失败抛出异常 |

**错误码：**

错误码的详细介绍请参见[SE错误码](../errorcodes/errorcode-se.md)。

**示例：**

```js
import secureElement from '@ohos.secureElement';

@State result: string = '';
@State nfcSEService: secureElement.SEService = null;

try {
    // 有效this.nfcSEService,获取方式参考newService
    this.nfcSEService.shutdown();
    this.result = "shutdown成功";
} catch (e) {
    this.result = "shutdown异常：" + e.message;
}
```

## SEService.getVersion

getVersion(): string

返回此实现所基于的OMA规范的版本号

> **说明：**
> 从 API version 10 开始支持。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型** | **说明**                                                     |
| -------- | ------------------------------------------------------------ |
| string   | OMA版本号（例如，“3.3”表示开放移动API规范版本3.3），失败抛出异常。 |

**错误码：**

错误码的详细介绍请参见[SE错误码](../errorcodes/errorcode-se.md)。

**示例：**

```JS
import secureElement from '@ohos.secureElement';

@State result: string = '';
@State nfcSEService: secureElement.SEService = null;

this.result = "版本名称："
try {
    // 有效this.nfcSEService,获取方式参考newService
    this.result += this.nfcSEService.getVersion();
} catch (e) {
    this.result += "getVersion异常：" + e.message;
}
```

## Reader.getName

getName(): string

返回此reader的名称。如果此读卡器是SIM reader，则其名称必须为“SIM[Slot]”。如果读卡器是嵌入式SE reader，则其名称须为“eSE[slot]”

> **说明：**
> 从 API version 10 开始支持。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型** | **说明**   |
| -------- | ---------- |
| string   | reader名称 |

**错误码：**

错误码的详细介绍请参见[SE错误码](../errorcodes/errorcode-se.md)。

**示例：**

```js
import secureElement from '@ohos.secureElement';

@State result: string = ''
@State nfcOmaReader: secureElement.Reader = null;

try {
    // this.nfcOmaReader有效的Reader，获取方式参考SEService.getReaders
    this.result = this.nfcOmaReader.getName();
} catch (e) {
    this.result = "getName异常：" + e.message;
}
```

## Reader.isSecureElementPresent

isSecureElementPresent(): boolean

检查reader中是否存在SE。

> **说明：**
> 从 API version 10 开始支持。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型** | **说明**                              |
| -------- | ------------------------------------- |
| boolean  | 当前reader的SE存在返回true，否则false |

**错误码：**

错误码的详细介绍请参见[SE错误码](../errorcodes/errorcode-se.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 3300101  | Illegal service state exception. |

**示例：**

```js
import secureElement from '@ohos.secureElement';

@State result: string = ''
@State nfcOmaReader: secureElement.Reader = null;

try {
    // this.nfcOmaReader有效的Reader，获取方式参考SEService.getReaders
	if (this.nfcOmaReader.isSecureElementPresent()) {
    	this.result = "isSecureElementPresent返回TRUE";
    } else {
        this.result = "isSecureElementPresent返回FALSE";
    }
} catch (e) {
    this.result = "isSecureElementPresent异常：" + e.message;
}
```

## Reader.openSession

 openSession(): [Session](#Session)

连接到此reader中的SE。此方法在返回会话对象之前准备（初始化）SE进行通信。同一reader上可能同时打开多个会话。

> **说明：**
> 从 API version 10 开始支持。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型**            | **说明**                                   |
| ------------------- | ------------------------------------------ |
| [Session](#Session) | 用于创建channel的[Session](#Session)对象。 |

**错误码：**

错误码的详细介绍请参见[SE错误码](../errorcodes/errorcode-se.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 3300101  | Illegal service state exception. |
| 3300104  | Secure element IO exception.     |

**示例：**

```js
import secureElement from '@ohos.secureElement';

@State result: string = ''
@State nfcOmaReader: secureElement.Reader = null;
@State nfcOmaSession: secureElement.Session = null;

try {
    // this.nfcOmaReader有效的Reader，获取方式参考SEService.getReaders
    this.nfcOmaSession = this.nfcOmaReader.openSession();
    if (this.nfcOmaSession) {
    	this.result = "获取session成功";
    } else {
        this.result = "获取session失败";
    }
} catch (e) {
    this.result = "OpenSession异常：" + e.message;
}
```

## Reader.closeSessions

 closeSessions(): void

关闭在此reader上打开的所有session。所有这些session打开的所有channel都将关闭。

> **说明：**
> 从 API version 10 开始支持。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型** | **说明**     |
| -------- | ------------ |
| void     | 失败抛出异常 |

**错误码：**

错误码的详细介绍请参见[SE错误码](../errorcodes/errorcode-se.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 3300101  | Illegal service state exception. |

**示例：**

```js
import secureElement from '@ohos.secureElement';

@State result: string = ''
@State nfcOmaReader: secureElement.Reader = null;

try {
    // this.nfcOmaReader有效的Reader，获取方式参考SEService.getReaders
    this.nfcOmaReader.closeSessions();
    this.result = "关闭Sessions成功";
 } catch (e) {
	this.result = "closeSessions 异常：" + e.message;
 }
```

## Session.getReader

getReader(): [Reader](#Reader)

获取提供此session的reader

> **说明：**
> 从 API version 10 开始支持。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型**          | **说明**                             |
| ----------------- | ------------------------------------ |
| [Reader](#Reader) | 返回此session的[Reader](#Reader)对象 |

**错误码：**

错误码的详细介绍请参见[SE错误码](../errorcodes/errorcode-se.md)。

**示例：**

```js
import secureElement from '@ohos.secureElement';

@State result: string = ''
@State nfcOmaReader: secureElement.Reader = null;
@State nfcOmaSession: secureElement.Session = null;

try {
    // this.nfcOmaSession:有效的Session，获取方式参考Reader.openSession
	this.nfcOmaReader = this.nfcOmaSession.getReader();
	if (this.nfcOmaReader) {
       this.result = "获取reader成功";
    } else {
       this.result = "获取reader失败";
    }
} catch (e) {
	this.result = "getReader出现异常:" + e.message;
}
```

## Session.getATR

getATR(): number[]

获取该SE的ATR。如果该SE的ATR不可用，则应返回空数组。

> **说明：**
> 从 API version 10 开始支持。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型** | **说明**                                   |
| -------- | ------------------------------------------ |
| number[] | 返回SE的ATR，SE的ATR不可用时，返回空的数组 |

**错误码：**

错误码的详细介绍请参见[SE错误码](../errorcodes/errorcode-se.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 3300101  | Illegal service state exception. |

**示例：**

```js
import secureElement from '@ohos.secureElement';

@State result: string = ''
@State nfcOmaSession: secureElement.Session = null;

try {
    // this.nfcOmaSession:有效的Session，获取方式参考Reader.openSession
    let ret = this.nfcOmaSession.getATR();
    if (ret) {
       this.result = "getATR结果:[";
       for (let i = 0; i < ret.length; ++i) {
            this.result += ret[i];
            this.result += ' ';
       }
       this.result += ']'
    } else {
       this.result = "getATR结果为空"
    }
} catch (e) {
   this.result = "getATR异常：" + e.message;
}
```

## Session.close

close(): void

关闭与SE的连接。这将关闭此应用程序与此SE打开的所有channel。

> **说明：**
> 从 API version 10 开始支持。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型** | **说明**     |
| -------- | ------------ |
| void     | 失败抛出异常 |

**错误码：**

错误码的详细介绍请参见[SE错误码](../errorcodes/errorcode-se.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 3300101  | Illegal service state exception. |

**示例：**

```js
import secureElement from '@ohos.secureElement';

@State result: string = ''
@State nfcOmaSession: secureElement.Session = null;

try {
    // this.nfcOmaSession:有效的Session，获取方式参考Reader.openSession
    this.nfcOmaSession.close();
    this.result = "session close 成功";
} catch (e) {
    this.result = "session close 异常:" + e.message;
}
```

## Session. isClosed

isClosed(): boolean

检查session是否关闭.

> **说明：**
> 从 API version 10 开始支持。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型** | **说明**                           |
| -------- | ---------------------------------- |
| boolean  | true：session状态已关闭，否则false |

**错误码：**

错误码的详细介绍请参见[SE错误码](../errorcodes/errorcode-se.md)。

**示例：**

```Js
import secureElement from '@ohos.secureElement';

@State result: string = ''
@State nfcOmaSession: secureElement.Session = null;

try {
    // this.nfcOmaSession:有效的Session，获取方式参考Reader.openSession
    let ret = this.nfcOmaSession.isClosed();
    if (ret) {
       this.result = "session状态：closed";
    } else {
       this.result = "session状态：not closed";
    }
} catch (e) {
    this.result = "isClosed异常：" + e.message;
}
```

## Session.closeChannels

closeChannels(): void

关闭此session上打开的所有channel。

> **说明：**
> 从 API version 10 开始支持。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型** | **说明**     |
| -------- | ------------ |
| void     | 失败抛出异常 |

**错误码：**

错误码的详细介绍请参见[SE错误码](../errorcodes/errorcode-se.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 3300101  | Illegal service state exception. |

**示例：**

```js
import secureElement from '@ohos.secureElement';

@State result: string = ''
@State nfcOmaSession: secureElement.Session = null;

try {
   // this.nfcOmaSession:有效的Session，获取方式参考Reader.openSession
   this.nfcOmaSession.closeChannels();
   this.result = "关闭Channels成功";
} catch (e) {
   this.result = "closeChannels出现异常：" + e.message;
}
```

## Session.openBasicChannel

openBasicChannel(aid: number[]): Promise<[Channel](#Channel)>

获取基本channel，参考[ISO 7816-4](https://www.iso.org/standard/77180.html)协议，返回[Channel](#Channel)实例对象

> **说明：**
> 从 API version 10 开始支持。

**系统能力：**  SystemCapability.Communication.SecureElement

**参数：**

| **参数名** | **类型** | **说明**                                                     |
| ---------- | -------- | ------------------------------------------------------------ |
| aid        | number[] | 在此channel上选择的applet的AID数组或null 如果没有applet被选择 |

**返回值：**

| **类型**            | **说明**                                                     |
| ------------------- | ------------------------------------------------------------ |
| [Channel](#Channel) | 返回可用[Channel](#Channel)对象实例，SE不能提供新逻辑[Channel](#Channel)或因缺乏可用逻辑[Channel](#Channel)对象而无法获取访问控制规则，返回null |

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

@State result: string = ''
@State nfcOmaSession: secureElement.Session = null;
@State nfcOmaChannel: secureElement.Channel = null;

try {
    // this.nfcOmaSession:有效的Session，获取方式参考Reader.openSession
    let getPromise = this.nfcOmaSession.openBasicChannel(this.aidArray)
    getPromise.then((channel) => {
    	this.nfcOmaChannel = channel;
        this.result = "openBasicChannel1获取channel成功";
    }).catch((err) => {
         this.result = "openBasicChannel1出现异常:" + err.meesage;
    })
} catch (e) {
     this.result = "OpenBasicChannel1出现异常:" + e.message;
}
```

## Session.openBasicChannel

 openBasicChannel(aid: number[], callback: AsyncCallback<[Channel](#Channel)>): void

获取基本channel，参考[ISO 7816-4](https://www.iso.org/standard/77180.html)协议，返回channel实例对象

> **说明：**
> 从 API version 10 开始支持。

**系统能力：**  SystemCapability.Communication.SecureElement

**参数：**

| **参数名** | **类型**                           | **说明**                                                     |
| ---------- | ---------------------------------- | ------------------------------------------------------------ |
| aid        | number[]                           | 在此channel上选择的applet的AID数组或null 如果没有applet被选择 |
| callback   | AsyncCallback<[Channel](#Channel)> | callback返回可用[Channel](#Channel)对象实例，SE不能提供新逻辑[Channel](#Channel)或因缺乏可用逻辑[Channel](#Channel)对象而无法获取访问控制规则，返回null |

**返回值：**

| **类型** | **说明**     |
| -------- | ------------ |
| void     | 失败抛出异常 |

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

@State result: string = ''
@State nfcOmaSession: secureElement.Session = null;
@State nfcOmaChannel: secureElement.Channel = null;
aidArray: number[] = [720, 1080]

try {
  // this.nfcOmaSession:有效的Session，获取方式参考Reader.openSession
  this.nfcOmaSession.openBasicChannel(this.aidArray, (error, data) => {
  		if (error) {
     		this.result = "openBasicChannel2失败：" + JSON.stringify(error);
     		return;
  		}
  		this.nfcOmaChannel = data;
  		this.result = "openBasicChannel2获取channel成功";
  	}
  )
} catch (e) {
  this.result = "openBasicChannel2出现异常:" + e.message;
}
```

## Session.openBasicChannel

openBasicChannel(aid: number[], p2: number): Promise<[Channel](#Channel)>

获取基本channel，参考[ISO 7816-4](https://www.iso.org/standard/77180.html)协议，返回[Channel](#Channel)实例对象

> **说明：**
> 从 API version 10 开始支持。

**系统能力：**  SystemCapability.Communication.SecureElement

**参数：**

| **参数名** | **类型** | **说明**                                                     |
| ---------- | -------- | ------------------------------------------------------------ |
| aid        | number[] | 在此channel上选择的applet的AID数组或null 如果没有applet被选择 |
| p2         | number   | 在该channel上执行的SELECT APDU的P2参数                       |

**返回值：**

| **类型**            | **说明**                                                     |
| ------------------- | ------------------------------------------------------------ |
| [Channel](#Channel) | 返回可用[Channel](#Channel)对象实例，SE不能提供新逻辑[Channel](#Channel)对象或因缺乏可用逻辑[Channel](#Channel)对象而无法获取访问控制规则，返回null |

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

@State result: string = ''
@State nfcOmaSession: secureElement.Session = null;
@State nfcOmaChannel: secureElement.Channel = null;
aidArray: number[] = [720, 1080]
p2: number = 0x00

try {
    // this.nfcOmaSession:有效的Session，获取方式参考Reader.openSession
    let getPromise = this.nfcOmaSession.openBasicChannel(this.aidArray, this.p2)
    getPromise.then((channel) => {
        this.nfcOmaChannel = channel;
        this.result = "openBasicChannel3 获取channel成功";
    }).catch((err) => {
       this.result = "openBasicChannel3 出现异常";
    })
} catch (e) {
    this.result = "openBasicChannel3出现异常:" + e.message;
}
```

## Session.openBasicChannel

openBasicChannel(aid: number[], p2:number, callback: AsyncCallback<[Channel](#Channel)>): void

获取基本channel，参考[ISO 7816-4](https://www.iso.org/standard/77180.html)协议，返回channel实例对象

> **说明：**
> 从 API version 10 开始支持。

**系统能力：**  SystemCapability.Communication.SecureElement

**参数：**

| **参数名** | **类型**                           | **说明**                                                     |
| ---------- | ---------------------------------- | ------------------------------------------------------------ |
| aid        | number[]                           | 在此channel上选择的applet的AID数组或null 如果没有applet被选择 |
| p2         | number                             | 此channel上执行SELECT APDU命令的P2参数。                     |
| callback   | AsyncCallback<[Channel](#Channel)> | callback返回可用[Channel](#Channel)对象实例，SE不能提供新逻辑[Channel](#Channel)对象或因缺乏可用逻辑[Channel](#Channel)对象而无法获取访问控制规则，返回null |

**返回值：**

| **类型** | **说明**     |
| -------- | ------------ |
| void     | 失败抛出异常 |

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

@State result: string = ''
@State nfcOmaSession: secureElement.Session = null;
@State nfcOmaChannel: secureElement.Channel = null;
aidArray: number[] = [720, 1080]
p2: number = 0x00

try {
    // this.nfcOmaSession:有效的Session，获取方式参考Reader.openSession
   this.nfcOmaSession.openBasicChannel(this.aidArray, this.p2, (error, data) => {
   if (error) {
      this.result = "openBasicChannel4失败：" + JSON.stringify(error);
      return;
   }
   this.nfcOmaChannel = data;
   this.result = "openBasicChannel4获取channel成功";
   })
} catch (e) {
    this.result = "openBasicChannel4异常:" + e.message;
}
```

## Session.openLogicalChannel

openLogicalChannel(aid: number[]): Promise<[Channel](#Channel)>

打开指定SE的逻辑[Channel](#Channel)对象

> **说明：**
> 从 API version 10 开始支持。

**系统能力：**  SystemCapability.Communication.SecureElement

**参数：**

| **参数名** | **类型** | **说明**                                            |
| ---------- | -------- | --------------------------------------------------- |
| aid        | number[] | 在该[Channel](#Channel)对象上选择的applet AID数组。 |

**返回值：**

| **类型**            | **说明**                                                     |
| ------------------- | ------------------------------------------------------------ |
| [Channel](#Channel) | 返回可用[Channel](#Channel)对象实例，SE不能提供新的[Channel](#Channel)对象或因缺乏可用逻辑[Channel](#Channel)对象无法获取访问控制规则返回null |

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

@State result: string = ''
@State nfcOmaSession: secureElement.Session = null;
@State nfcOmaChannel: secureElement.Channel = null;
aidArray: number[] = [720, 1080]

try {
    // this.nfcOmaSession:有效的Session，获取方式参考Reader.openSession
   let getPromise = this.nfcOmaSession.openLogicalChannel(this.aidArray)
   getPromise.then((channel) => {
       this.nfcOmaChannel = channel;
   	   this.result = "openLogicChannel1获取channel成功";
   }).catch((err) => {
       this.result = "openLogicChannel1出现异常:" + err.code;
   })
} catch (e) {
   this.result = "openLogicChannel1出现异常:" + e.message;
}
```

## Session.openLogicalChannel

 openLogicalChannel(aid:number[], callback: AsyncCallback<[Channel](#Channel)>): void

打开指定SE的逻辑[Channel](#Channel)对象

> **说明：**
> 从 API version 10 开始支持。

**系统能力：**  SystemCapability.Communication.SecureElement

**参数：**

| **参数名** | **类型**                           | **说明**                                                     |
| ---------- | ---------------------------------- | ------------------------------------------------------------ |
| aid        | number[]                           | 在该[Channel](#Channel)对象上被选择的applet AID数组。        |
| callback   | AsyncCallback<[Channel](#Channel)> | callback返回可用[Channel](#Channel)对象实例，SE不能提供新的channel或因缺乏可用逻辑[Channel](#Channel)对象无法获取访问控制规则返回null |

**返回值：**

| **类型** | **说明**     |
| -------- | ------------ |
| void     | 失败抛出异常 |

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

@State result: string = ''
@State nfcOmaSession: secureElement.Session = null;
@State nfcOmaChannel: secureElement.Channel = null;
aidArray: number[] = [720, 1080]

try {
    // this.nfcOmaSession:有效的Session，获取方式参考Reader.openSession
   this.nfcOmaSession.openLogicalChannel(this.aidArray, (error, data) => {
   if (error) {
       this.result = "openLogicChannel2失败：" + JSON.stringify(error);
       return;
   }
   this.nfcOmaChannel = data;
   this.result = "openLogicChannel2获取channel成功";
   })
} catch (e) {
  this.result = "openLogicChannel2 异常:" + e.message;
}
```

## Session.openLogicalChannel

openLogicalChannel(aid: number[], p2: number): Promise<[Channel](#Channel)>

使用SE打开逻辑通道，选择由给定AID数组（AID非null且长度不为0）表示的applet.

如果AID数组长度为0，则该方法将通过发送一个select命令来选择SE的Issuer Security Domain，该命令的AID长度为0（如[GPCS]中所定义）。

如果AID为Null，则该方法应仅发送MANAGE CHANNEL Open（管理通道打开），而不应发送SELECT（选择）命令。在这种情况下，默认情况下将选择与逻辑通道关联的默认applet.

P2通常为0x00。设备应允许P2的任何值，并且应允许以下值： 0x00, 0x04, 0x08, 0x0C (如 [ISO 7816-4](https://www.iso.org/standard/77180.html)中所定义).

> **说明：**
> 从 API version 10 开始支持。

**系统能力：**  SystemCapability.Communication.SecureElement

**参数：**

| **参数名** | **类型** | **说明**                                              |
| ---------- | -------- | ----------------------------------------------------- |
| aid        | number[] | 在该[Channel](#Channel)对象上被选择的applet AID数组。 |
| p2         | number   | 此channel上执行SELECT APDU命令的P2参数。              |

**返回值：**

| **类型** | **说明**     |
| -------- | ------------ |
| void     | 失败抛出异常 |

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

@State result: string = ''
@State nfcOmaSession: secureElement.Session = null;
@State nfcOmaChannel: secureElement.Channel = null;
aidArray: number[] = [720, 1080]
p2: number = 0x00

if (this.nfcOmaSession) {
   try {
      // this.nfcOmaSession:有效的Session，获取方式参考Reader.openSession
      let getPromise = this.nfcOmaSession.openLogicalChannel(this.aidArray, this.p2)
      getPromise.then((channel) => {
      this.nfcOmaChannel = channel;
      this.result = "openLogicChannel3获取channel成功";
    }).catch((err) => {
       this.result = "openLogicChannel3 出现异常";
    })
} catch (e) {
	this.result = "openLogicChannel3出现异常:" + e.message;
}
```

## Session.openLogicalChannel

openLogicalChannel(aid: number[], p2: number, callback: AsyncCallback<[Channel](#Channel)>):void

使用SE打开逻辑通道，选择由给定AID数组（AID非null且长度不为0）表示的applet.

如果AID数组长度为0，则该方法将通过发送一个select命令来选择SE的Issuer Security Domain，该命令的AID长度为0（如[GPCS]中所定义）。

如果AID为Null，则该方法应仅发送MANAGE CHANNEL Open（管理通道打开），而不应发送SELECT（选择）命令。在这种情况下，默认情况下将选择与逻辑通道关联的默认applet.

P2通常为0x00。设备应允许P2的任何值，并且应允许以下值： 0x00, 0x04, 0x08, 0x0C (如 [ISO 7816-4](https://www.iso.org/standard/77180.html)中所定义).

> **说明：**
> 从 API version 10 开始支持。

**系统能力：**  SystemCapability.Communication.SecureElement

**参数：**

| **参数名** | **类型**                           | **说明**                                                     |
| ---------- | ---------------------------------- | ------------------------------------------------------------ |
| aid        | number[]                           | 在该[Channel](#Channel)对象上被选择的applet AID数组。        |
| p2         | number                             | 此channel上执行SELECT APDU命令的P2参数。                     |
| callback   | AsyncCallback<[Channel](#Channel)> | callback返回可用[Channel](#Channel)对象实例，SE不能提供新的[Channel](#Channel)对象或因缺乏可用逻辑[Channel](#Channel)对象无法获取访问控制规则返回null |

**返回值：**

| **类型** | **说明**     |
| -------- | ------------ |
| void     | 失败抛出异常 |

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

@State result: string = ''
@State nfcOmaSession: secureElement.Session = null;
@State nfcOmaChannel: secureElement.Channel = null;
aidArray: number[] = [720, 1080]
p2: number = 0x00

try {
    // this.nfcOmaSession:有效的Session，获取方式参考Reader.openSession
    this.nfcOmaSession.openLogicalChannel(this.aidArray, this.p2, (error, data) => {
    if (error) {
        this.result = "openLogicChannel4失败：" + JSON.stringify(error);
        return;
    }
    this.nfcOmaChannel = data;
    this.result = "openLogicChannel4获取channel成功";
    })
} catch (e) {
   this.result = "openLogicChannel4异常:" + e.message;
}
```

## Channel. getSession

 getSession(): [Session](#Session)

获取打开该channel的[Session](#Session)对象。

> **说明：**
> 从 API version 10 开始支持。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型**            | **说明**                                |
| ------------------- | --------------------------------------- |
| [Session](#Session) | 该channel绑定的[Session](#Session) 对象 |

**错误码：**

错误码的详细介绍请参见[SE错误码](../errorcodes/errorcode-se.md)。

**示例：**

```js
import secureElement from '@ohos.secureElement';

@State result: string = ''
@State nfcOmaSession: secureElement.Session = null;
@State nfcOmaChannel: secureElement.Channel = null;

try {
     // this.nfcOmaSession:有效的Session，获取方式参考Reader.openSession
     let ret = this.nfcOmaChannel.getSession();
     if (ret) {
        this.result = "获取到session对象";
     } else {
        this.result = "无法获取到session对象";
     }
} catch (e) {
    this.result = "getSession异常:" + e.message;
}
```

## Channel. close

close(): void

关闭与SE的此channel

> **说明：**
> 从 API version 10 开始支持。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型**     | **说明** |
| ------------ | -------- |
| 失败抛出异常 |

**错误码：**

错误码的详细介绍请参见[SE错误码](../errorcodes/errorcode-se.md)。

**示例：**

```js
import secureElement from '@ohos.secureElement';

@State result: string = ''
@State nfcOmaSession: secureElement.Session = null;
@State nfcOmaChannel: secureElement.Channel = null;

try {
   // this.nfcOmaChannel:获取方式参考Session.openBasicChannel
  this.nfcOmaChannel.close();
  this.result = "channel close成功";
}
catch (e) {
   this.result = "channel close异常:" + e.message;
}
```

## Channel. isBasicChannel

isBasicChannel(): boolean

检查该channel是否为基本channel

> **说明：**
> 从 API version 10 开始支持。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型** | **说明**                                       |
| -------- | ---------------------------------------------- |
| boolean  | true:如果该channel是基本channel，否则返回false |

**错误码：**

错误码的详细介绍请参见[SE错误码](../errorcodes/errorcode-se.md)。

**示例：**

```js
import secureElement from '@ohos.secureElement';

@State result: string = ''
@State nfcOmaChannel: secureElement.Channel = null;

try {
   // this.nfcOmaChannel:获取方式参考Session.openBasicChannel
   let ret = this.nfcOmaChannel.isBasicChannel();
   if (ret) {
     this.result = "isBasicChannel TRUE";
   } else {
     this.result = "isBasicChannel FALSE";
   }
} catch (e) {
  this.result = "isBasicChannel异常:" + e.message;
}
```

## Channel. isClosed

isClosed(): boolean

检查该channel是否为closed。

> **说明：**
> 从 API version 10 开始支持。

**系统能力：**  SystemCapability.Communication.SecureElement

**返回值：**

| **类型** | **说明**                                  |
| -------- | ----------------------------------------- |
| boolean  | true:如果该channel是closed，否则返回false |

**错误码：**

错误码的详细介绍请参见[SE错误码](../errorcodes/errorcode-se.md)。

**示例：**

```js
import secureElement from '@ohos.secureElement';

@State result: string = ''
@State nfcOmaChannel: secureElement.Channel = null;

try {
   // this.nfcOmaChannel:获取方式参考Session.openBasicChannel
   let ret = this.nfcOmaChannel.isClosed()
   if (ret) {
      this.result = "channel isClosed TRUE";
   } else {
      this.result = "channel isClosed False";
   }
} catch (e) {
   this.result = "Channel isClosed异常：" + e.message;
}
```

## Channel. getSelectResponse

getSelectResponse():number[]

返回从应用程序选择命令接收的数据，包括在applet选择时接收的状态字。

> **说明：**
> 从 API version 10 开始支持。

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

@State result: string = ''
@State nfcOmaChannel: secureElement.Channel = null;

try {
   // this.nfcOmaChannel:获取方式参考Session.openBasicChannel
   let ret = this.nfcOmaChannel.getSelectResponse();
   if (ret) {
      this.result = "getSelectResponse结果:[";
      for (let i = 0; i < ret.length; ++i) {
          this.result += ret[i];
          this.result += ' ';
      }
      this.result += ']'
   } else {
        this.result = "getSelectResponse结果为空"
   }
} catch (e) {
  this.result = "getSelectResponse异常：" + e.message;
}
```

## Channel. transmit

transmit(command: number[]): Promise<number[]>

向SE发送APDU命令（根据ISO/IEC 7816）

> **说明：**
> 从 API version 10 开始支持。

**系统能力：**  SystemCapability.Communication.SecureElement

**参数：**

| **参数名** | **类型** | **说明**                              |
| ---------- | -------- | ------------------------------------- |
| command    | number[] | 在该channel上被选择的applet AID数组。 |

**返回值：**

| **类型** | **说明**     |
| -------- | ------------ |
| number[] | 响应结果数组 |

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

@State result: string = ''
@State nfcOmaChannel: secureElement.Channel = null;

try {
   let command: number[] = [100, 200]
   // this.nfcOmaChannel:获取方式参考Session.openBasicChannel
   let getPromise = this.nfcOmaChannel.transmit(command);
   getPromise.then((data) => {
   this.result = "transmit1 结果:[";
   for (let i = 0; i < data.length; ++i) {
       this.result += data[i];
       this.result += " ";
   }
   this.result += "]";
}).catch((err) => {
   this.result = "transmit1出现异常:" + err.code;
   })
} catch (e) {
   this.result = "transit1 调用异常：" + e.message;
}
```

## Channel. transmit

transmit(command: number[], callback: AsyncCallback<number[]>): void

向SE发送APDU命令（根据ISO/IEC 7816）

> **说明：**
> 从 API version 10 开始支持。

**系统能力：**  SystemCapability.Communication.SecureElement

**参数：**

| **参数名** | **类型**                | **说明**                              |
| ---------- | ----------------------- | ------------------------------------- |
| command    | number[]                | 在该Channel上被选择的applet AID数组。 |
| callback   | AsyncCallback<number[]> | 返回接收到的响应的回调，number数组    |

**返回值：**

| **类型** | **说明**     |
| -------- | ------------ |
| void     | 出错抛出异常 |

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

@State result: string = ''
@State nfcOmaChannel: secureElement.Channel = null;

try {
    let command: number[] = [100, 200];
   // this.nfcOmaChannel:获取方式参考Session.openBasicChannel
    this.nfcOmaChannel.transmit(command, (error, data) => {
    if (error) {
       this.result = "transmit2异常：" + JSON.stringify(error);
       return;
    }
    this.result = "transmit2 结果：[";
    for (let i = 0; i < data.length; ++i) {
        this.result += data[i];
        this.result += " ";
    }
    this.result += "]";
    })
} catch(e) {
    this.result = "transit2 调用异常：" + e.message;
}
```

# SE Tech [ISO/IEC 7816-4]

## SEService

​	SEService实现与设备上可用的SE的通信。

## Reader

​	此类的实例表示该设备支持的SE Reader。

## Session

​	此类的实例表示与设备上可用的某个SE的连接会话。

## Channel

​	此类的实例表示向SE打开的ISO/IEC 7816-4通道。
