# @ohos.app.ability.wantAgent (WantAgent模块)

app.ability.WantAgent模块提供了创建WantAgent实例、获取实例的用户ID、获取want信息、比较WantAgent实例和获取bundle名称等能力。该模块将会取代[@ohos.wantAgent](js-apis-wantAgent.md)模块，建议优先使用本模块。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  

## 导入模块

```ts
import WantAgent from '@ohos.app.ability.wantAgent';
```

## WantAgent.getWantAgent

getWantAgent(info: WantAgentInfo, callback: AsyncCallback\<WantAgent\>): void

创建WantAgent（callback形式）。 创建失败返回的WantAgent为空值。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名     | 类型                       | 必填 | 说明                    |
| -------- | -------------------------- | ---- | ----------------------- |
| info     | [WantAgentInfo](js-apis-inner-wantAgent-wantAgentInfo.md)              | 是   | WantAgent信息。           |
| callback | AsyncCallback\<WantAgent\> | 是   | 创建WantAgent的回调方法。 |

**错误码：**

| 错误码ID    | 错误信息            |
|-----------|--------------------|
| 16000007   | Service busy, there are concurrent tasks, waiting for retry.|
| 16000151   | Invalid wantagent object.|

错误码详细介绍请参考[元能力子系统错误码](../errorcodes/errorcode-ability.md)

**示例：**

```ts
import WantAgent, { WantAgent as _WantAgent} from '@ohos.app.ability.wantAgent';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

//wantAgent对象
let wantAgent: _WantAgent;
//WantAgentInfo对象
let wantAgentInfo: WantAgent.WantAgentInfo = {
    wants: [
        {
            deviceId: 'deviceId',
            bundleName: 'com.example.myapplication',
            abilityName: 'EntryAbility',
            action: 'action1',
            entities: ['entity1'],
            type: 'MIMETYPE',
            uri: 'key={true,true,false}',
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: '[1, 2, 3]',
                mykey3: 'ssssssssssssssssssssssssss',
                mykey4: [false, true, false],
                mykey5: ['qqqqq', 'wwwwww', 'aaaaaaaaaaaaaaaaa'],
                mykey6: true,
            }
        } as Want
    ],
    operationType: WantAgent.OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

//getWantAgent回调
function getWantAgentCallback(err: BusinessError, data: _WantAgent) {
    if (err === undefined) {
        wantAgent = data;
    } else {
        console.error(`getWantAgent failed, error: ${JSON.stringify(err)}`);
    }
}
try {
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err) {
    console.error(`getWantAgent failed, error: ${JSON.stringify(err)}`);
}
```



## WantAgent.getWantAgent

getWantAgent(info: WantAgentInfo): Promise\<WantAgent\>

创建WantAgent（Promise形式）。 创建失败返回的WantAgent为空值。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型          | 必填 | 说明          |
| ---- | ------------- | ---- | ------------- |
| info | [WantAgentInfo](js-apis-inner-wantAgent-wantAgentInfo.md) | 是   | WantAgent信息。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<WantAgent\> | 以Promise形式返回WantAgent。 |

**错误码：**

| 错误码ID    | 错误信息            |
|-----------|--------------------|
| 16000007   | Service busy, there are concurrent tasks, waiting for retry.|
| 16000151   | Invalid wantagent object.|

错误码详细介绍请参考[元能力子系统错误码](../errorcodes/errorcode-ability.md)

**示例：**

```ts
import WantAgent, { WantAgent as _WantAgent} from '@ohos.app.ability.wantAgent';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

let wantAgent: _WantAgent;
//WantAgentInfo对象
let wantAgentInfo: WantAgent.WantAgentInfo = {
    wants: [
        {
            deviceId: 'deviceId',
            bundleName: 'com.example.myapplication',
            abilityName: 'EntryAbility',
            action: 'action1',
            entities: ['entity1'],
            type: 'MIMETYPE',
            uri: 'key={true,true,false}',
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: '[1, 2, 3]',
                mykey3: 'ssssssssssssssssssssssssss',
                mykey4: [false, true, false],
                mykey5: ['qqqqq', 'wwwwww', 'aaaaaaaaaaaaaaaaa'],
                mykey6: true,
            }
        } as Want
    ],
    operationType: WantAgent.OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

try {
    WantAgent.getWantAgent(wantAgentInfo).then((data) => {
    wantAgent = data;
}).catch((err: BusinessError) => {
    console.error('getWantAgent failed! ${err.code} ${err.message}');
});
} catch (err) {
    console.error('getWantAgent failed! ${err.code} ${err.message}');
}
```



## WantAgent.getBundleName

getBundleName(agent: WantAgent, callback: AsyncCallback\<string\>): void

获取WantAgent实例的包名（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名     | 类型                    | 必填 | 说明                              |
| -------- | ----------------------- | ---- | --------------------------------- |
| agent    | WantAgent               | 是   | WantAgent对象。                     |
| callback | AsyncCallback\<string\> | 是   | 获取WantAgent实例的包名的回调方法。 |

**错误码：**

| 错误码ID    | 错误信息            |
|-----------|--------------------|
| 16000007   | Service busy, there are concurrent tasks, waiting for retry.|
| 16000151   | Invalid wantagent object.|

错误码详细介绍请参考[元能力子系统错误码](../errorcodes/errorcode-ability.md)

**示例：**

```ts
import WantAgent, { WantAgent as _WantAgent} from '@ohos.app.ability.wantAgent';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

//wantAgent对象
let wantAgent: _WantAgent;
//WantAgentInfo对象
let wantAgentInfo: WantAgent.WantAgentInfo = {
    wants: [
        {
            deviceId: 'deviceId',
            bundleName: 'com.example.myapplication',
            abilityName: 'EntryAbility',
            action: 'action1',
            entities: ['entity1'],
            type: 'MIMETYPE',
            uri: 'key={true,true,false}',
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: '[1, 2, 3]',
                mykey3: 'ssssssssssssssssssssssssss',
                mykey4: [false, true, false],
                mykey5: ['qqqqq', 'wwwwww', 'aaaaaaaaaaaaaaaaa'],
                mykey6: true,
            }
        } as Want
    ],
    operationType: WantAgent.OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

//getWantAgent回调
function getWantAgentCallback(err: BusinessError, data: _WantAgent) {
    if (err === undefined) {
        wantAgent = data;
    } else {
        console.error(`getWantAgent failed ${JSON.stringify(wantAgent)}`);
    }
    //getBundleName回调
    let getBundleNameCallback = (err: BusinessError, data: string) => {
        if(err) {
            console.error(`getBundleName failed! ${err.code} ${err.message}`);
        } else {
            console.info(`getBundleName ok! ${JSON.stringify(data)}`);
        }
    }
    try {
        WantAgent.getBundleName(wantAgent, getBundleNameCallback);
    } catch(err) {
        console.error(`getBundleName failed! ${err.code} ${err.message}`);
    }
}
try {
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err) {
    console.error(`getWantAgent failed! ${err.code} ${err.message}`);
}
```



## WantAgent.getBundleName

getBundleName(agent: WantAgent): Promise\<string\>

获取WantAgent实例的包名（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名  | 类型      | 必填 | 说明          |
| ----- | --------- | ---- | ------------- |
| agent | WantAgent | 是   | WantAgent对象。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<string\> | 以Promise形式返回获取WantAgent实例的包名。 |

**错误码：**

| 错误码ID    | 错误信息            |
|-----------|--------------------|
| 16000007   | Service busy, there are concurrent tasks, waiting for retry.|
| 16000151   | Invalid wantagent object.|

错误码详细介绍请参考[元能力子系统错误码](../errorcodes/errorcode-ability.md)

**示例：**

```ts
import WantAgent, { WantAgent as _WantAgent} from '@ohos.app.ability.wantAgent';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

 //wantAgent对象
let wantAgent: _WantAgent;
//WantAgentInfo对象
let wantAgentInfo: WantAgent.WantAgentInfo = {
    wants: [
        {
            deviceId: 'deviceId',
            bundleName: 'com.example.myapplication',
            abilityName: 'EntryAbility',
            action: 'action1',
            entities: ['entity1'],
            type: 'MIMETYPE',
            uri: 'key={true,true,false}',
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: '[1, 2, 3]',
                mykey3: 'ssssssssssssssssssssssssss',
                mykey4: [false, true, false],
                mykey5: ['qqqqq', 'wwwwww', 'aaaaaaaaaaaaaaaaa'],
                mykey6: true,
            }
        } as Want
    ],
    operationType: WantAgent.OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

//getWantAgent回调
function getWantAgentCallback(err: BusinessError, data: _WantAgent) {
    if (err === undefined) {
        wantAgent = data;
    } else {
        console.error(`getWantAgent failed! ${JSON.stringify(wantAgent)}`);
    }
    try {
        WantAgent.getBundleName(wantAgent).then((data)=>{
            console.info(`getBundleName ok! ${JSON.stringify(data)}`);
        }).catch((err: BusinessError)=>{
            console.error(`getBundleName failed! ${err.code} ${err.message}`);
        });
    } catch(err){
        console.error(`getBundleName failed! ${err.code} ${err.message}`);
    }
}
try {
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err) {
    console.error(`getWantAgent failed! ${err.code} ${err.message}`);
}
```



## WantAgent.getUid

getUid(agent: WantAgent, callback: AsyncCallback\<number\>): void

获取WantAgent实例的用户ID（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名     | 类型                    | 必填 | 说明                                |
| -------- | ----------------------- | ---- | ----------------------------------- |
| agent    | WantAgent               | 是   | WantAgent对象。                       |
| callback | AsyncCallback\<number\> | 是   | 获取WantAgent实例的用户ID的回调方法。 |

**错误码：**

| 错误码ID    | 错误信息            |
|-----------|--------------------|
| 16000007   | Service busy, there are concurrent tasks, waiting for retry.|
| 16000151   | Invalid wantagent object.|

错误码详细介绍请参考[元能力子系统错误码](../errorcodes/errorcode-ability.md)

**示例：**

```ts
import WantAgent, { WantAgent as _WantAgent} from '@ohos.app.ability.wantAgent';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

//wantAgent对象
let wantAgent: _WantAgent;
//WantAgentInfo对象
let wantAgentInfo: WantAgent.WantAgentInfo = {
    wants: [
        {
            deviceId: 'deviceId',
            bundleName: 'com.example.myapplication',
            abilityName: 'EntryAbility',
            action: 'action1',
            entities: ['entity1'],
            type: 'MIMETYPE',
            uri: 'key={true,true,false}',
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: '[1, 2, 3]',
                mykey3: 'ssssssssssssssssssssssssss',
                mykey4: [false, true, false],
                mykey5: ['qqqqq', 'wwwwww', 'aaaaaaaaaaaaaaaaa'],
                mykey6: true,
            }
        } as Want
    ],
    operationType: WantAgent.OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

//getWantAgent回调
function getWantAgentCallback(err: BusinessError, data: _WantAgent) {
    if (err === undefined) {
        wantAgent = data;
    } else {
        console.info(`getWantAgent failed ${JSON.stringify(err)}`);
    }
    //getUid回调
    let getUidCallback = (err: BusinessError, data: number) => {
        if(err) {
            console.error(`getUid failed! ${err.code} ${err.message}`);
        } else {
            console.info(`getUid ok! ${JSON.stringify(data)}`);
        }
    }
    try {
        WantAgent.getUid(wantAgent, getUidCallback);
    } catch(err) {
        console.error(`getUid failed! ${err.code} ${err.message}`);
    }
}
try {
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err) {
    console.error(`getWantAgent failed! ${err.code} ${err.message}`);
}
```



## WantAgent.getUid

getUid(agent: WantAgent): Promise\<number\>

获取WantAgent实例的用户ID（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名  | 类型      | 必填 | 说明          |
| ----- | --------- | ---- | ------------- |
| agent | WantAgent | 是   | WantAgent对象。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<number\> | 以Promise形式返回获取WantAgent实例的用户ID。 |

**错误码：**

| 错误码ID    | 错误信息            |
|-----------|--------------------|
| 16000007   | Service busy, there are concurrent tasks, waiting for retry.|
| 16000151   | Invalid wantagent object.|

错误码详细介绍请参考[元能力子系统错误码](../errorcodes/errorcode-ability.md)

**示例：**

```ts
import WantAgent, { WantAgent as _WantAgent} from '@ohos.app.ability.wantAgent';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

//wantAgent对象
let wantAgent: _WantAgent;
//WantAgentInfo对象
let wantAgentInfo: WantAgent.WantAgentInfo = {
    wants: [
        {
            deviceId: 'deviceId',
            bundleName: 'com.example.myapplication',
            abilityName: 'EntryAbility',
            action: 'action1',
            entities: ['entity1'],
            type: 'MIMETYPE',
            uri: 'key={true,true,false}',
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: '[1, 2, 3]',
                mykey3: 'ssssssssssssssssssssssssss',
                mykey4: [false, true, false],
                mykey5: ['qqqqq', 'wwwwww', 'aaaaaaaaaaaaaaaaa'],
                mykey6: true,
            }
        } as Want
    ],
    operationType: WantAgent.OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

//getWantAgent回调
function getWantAgentCallback(err: BusinessError, data: _WantAgent) {
    if (err === undefined) {
        wantAgent = data;
    } else {
        console.error(`getWantAgent failed! ${JSON.stringify(wantAgent)}`);
    }
    try {
        WantAgent.getUid(wantAgent).then((data)=>{
            console.info(`getUid ok! ${JSON.stringify(data)}`);
        }).catch((err: BusinessError)=>{
            console.error(`getUid failed! ${err.code} ${err.message}`);
        });
    } catch(err){
        console.error(`getUid failed! ${err.code} ${err.message}`);
    }
}
try {
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err) {
    console.error(`getWantAgent failed! ${err.code} ${err.message}`);
}
```


## WantAgent.getWant

getWant(agent: WantAgent, callback: AsyncCallback\<Want\>): void

获取WantAgent对象的want（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                            |
| -------- | --------------------- | ---- | ------------------------------- |
| agent    | WantAgent             | 是   | WantAgent对象。                   |
| callback | AsyncCallback\<[Want](js-apis-app-ability-want.md)\> | 是   | 获取WantAgent对象want的回调方法。 |

**错误码：**

| 错误码ID    | 错误信息            |
|-----------|--------------------|
| 16000007   | Service busy, there are concurrent tasks, waiting for retry.|
| 16000015   | Service timeout.|
| 16000151   | Invalid wantagent object.|

错误码详细介绍请参考[元能力子系统错误码](../errorcodes/errorcode-ability.md)

**示例：**

```ts
import WantAgent, { WantAgent as _WantAgent} from '@ohos.app.ability.wantAgent';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

//wantAgent对象
let wantAgent: _WantAgent;
//WantAgentInfo对象
let wantAgentInfo: WantAgent.WantAgentInfo = {
    wants: [
        {
            deviceId: 'deviceId',
            bundleName: 'com.example.myapplication',
            abilityName: 'EntryAbility',
            action: 'action1',
            entities: ['entity1'],
            type: 'MIMETYPE',
            uri: 'key={true,true,false}',
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: '[1, 2, 3]',
                mykey3: 'ssssssssssssssssssssssssss',
                mykey4: [false, true, false],
                mykey5: ['qqqqq', 'wwwwww', 'aaaaaaaaaaaaaaaaa'],
                mykey6: true,
            }
        } as Want
    ],
    operationType: WantAgent.OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

//getWantAgent回调
function getWantAgentCallback(err: BusinessError, data: _WantAgent) {
    if (err === undefined) {
        wantAgent = data;
    } else {
        console.error(`getWantAgent failed ${JSON.stringify(wantAgent)}`);
    }
    //getWant回调
    let getWantCallback = (err: BusinessError, data: Want) => {
        if(err) {
            console.error(`getWant failed! ${err.code} ${err.message}`);
        } else {
            console.info(`getWant ok! ${JSON.stringify(data)}`);
        }
    }
    try {
        WantAgent.getWant(wantAgent, getWantCallback);
    } catch(err) {
        console.error(`getWant failed! ${err.code} ${err.message}`);
    }
}
try {
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err) {
    console.error(`getWantAgent failed! ${err.code} ${err.message}`);
}
```



## WantAgent.getWant

getWant(agent: WantAgent): Promise\<Want\>

获取WantAgent对象的want（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名  | 类型      | 必填 | 说明          |
| ----- | --------- | ---- | ------------- |
| agent | WantAgent | 是   | WantAgent对象。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<[Want](js-apis-app-ability-want.md)\> | 以Promise形式返回获取WantAgent对象的want。 |

**错误码：**

| 错误码ID    | 错误信息            |
|-----------|--------------------|
| 16000007   | Service busy, there are concurrent tasks, waiting for retry.|
| 16000015   | Service timeout.|
| 16000151   | Invalid wantagent object.|

错误码详细介绍请参考[元能力子系统错误码](../errorcodes/errorcode-ability.md)

**示例：**

```ts
import WantAgent, { WantAgent as _WantAgent} from '@ohos.app.ability.wantAgent';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

//wantAgent对象
let wantAgent: _WantAgent;
//WantAgentInfo对象
let wantAgentInfo: WantAgent.WantAgentInfo = {
    wants: [
        {
            deviceId: 'deviceId',
            bundleName: 'com.example.myapplication',
            abilityName: 'EntryAbility',
            action: 'action1',
            entities: ['entity1'],
            type: 'MIMETYPE',
            uri: 'key={true,true,false}',
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: '[1, 2, 3]',
                mykey3: 'ssssssssssssssssssssssssss',
                mykey4: [false, true, false],
                mykey5: ['qqqqq', 'wwwwww', 'aaaaaaaaaaaaaaaaa'],
                mykey6: true,
            }
        } as Want
    ],
    operationType: WantAgent.OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

//getWantAgent回调
function getWantAgentCallback(err: BusinessError, data: _WantAgent) {
    if (err === undefined) {
        wantAgent = data;
    } else {
        console.error(`getWantAgent failed! ${JSON.stringify(wantAgent)}`);
    }
    try {
        WantAgent.getUid(wantAgent).then((data)=>{
            console.info(`getUid ok! ${JSON.stringify(data)}`);
        }).catch((err: BusinessError)=>{
            console.error(`getUid failed! ${err.code} ${err.message}`);
        });
    } catch(err){
        console.error(`getUid failed! ${err.code} ${err.message}`);
    }
}
try {
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err) {
    console.error(`getWantAgent failed! ${err.code} ${err.message}}`);
}
```



## WantAgent.cancel

cancel(agent: WantAgent, callback: AsyncCallback\<void\>): void

取消WantAgent实例（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名     | 类型                  | 必填 | 说明                        |
| -------- | --------------------- | ---- | --------------------------- |
| agent    | WantAgent             | 是   | WantAgent对象。               |
| callback | AsyncCallback\<void\> | 是   | 取消WantAgent实例的回调方法。 |

**错误码：**

| 错误码ID    | 错误信息            |
|-----------|--------------------|
| 16000007   | Service busy, there are concurrent tasks, waiting for retry.|
| 16000151   | Invalid wantagent object.|

错误码详细介绍请参考[元能力子系统错误码](../errorcodes/errorcode-ability.md)

**示例：**

```ts
import WantAgent, { WantAgent as _WantAgent} from '@ohos.app.ability.wantAgent';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

//wantAgent对象
let wantAgent: _WantAgent;
//WantAgentInfo对象
let wantAgentInfo: WantAgent.WantAgentInfo = {
    wants: [
        {
            deviceId: 'deviceId',
            bundleName: 'com.example.myapplication',
            abilityName: 'EntryAbility',
            action: 'action1',
            entities: ['entity1'],
            type: 'MIMETYPE',
            uri: 'key={true,true,false}',
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: '[1, 2, 3]',
                mykey3: 'ssssssssssssssssssssssssss',
                mykey4: [false, true, false],
                mykey5: ['qqqqq', 'wwwwww', 'aaaaaaaaaaaaaaaaa'],
                mykey6: true,
            }
        } as Want
    ],
    operationType: WantAgent.OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

//getWantAgent回调
function getWantAgentCallback(err: BusinessError, data: _WantAgent) {
    if (err === undefined) {
        wantAgent = data;
    } else {
        console.error(`getWantAgent failed ${JSON.stringify(wantAgent)}`);
    }
    //cancel回调
    let cancelCallback = (err: BusinessError, data: void) => {
        if(err) {
            console.error(`cancel failed! ${err.code} ${err.message}`);
        } else {
            console.info(`cancel ok!`);
        }
    }
    try {
        WantAgent.cancel(wantAgent, cancelCallback);
    } catch(err) {
        console.error(`cancel failed! ${err.code} ${err.message}`);
    }
}
try {
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err) {
    console.error(`getWantAgent failed! ${err.code} ${err.message}`);
}
```



## WantAgent.cancel

cancel(agent: WantAgent): Promise\<void\>

取消WantAgent实例（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名  | 类型      | 必填 | 说明          |
| ----- | --------- | ---- | ------------- |
| agent | WantAgent | 是   | WantAgent对象。 |

**返回值：**

| 类型            | 说明                            |
| --------------- | ------------------------------- |
| Promise\<void\> | 以Promise形式获取异步返回结果。 |

**错误码：**

| 错误码ID    | 错误信息            |
|-----------|--------------------|
| 16000007   | Service busy, there are concurrent tasks, waiting for retry.|
| 16000151   | Invalid wantagent object.|

错误码详细介绍请参考[元能力子系统错误码](../errorcodes/errorcode-ability.md)

**示例：**

```ts
import WantAgent, { WantAgent as _WantAgent} from '@ohos.app.ability.wantAgent';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

//wantAgent对象
let wantAgent: _WantAgent;
//WantAgentInfo对象
let wantAgentInfo: WantAgent.WantAgentInfo = {
    wants: [
        {
            deviceId: 'deviceId',
            bundleName: 'com.example.myapplication',
            abilityName: 'EntryAbility',
            action: 'action1',
            entities: ['entity1'],
            type: 'MIMETYPE',
            uri: 'key={true,true,false}',
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: '[1, 2, 3]',
                mykey3: 'ssssssssssssssssssssssssss',
                mykey4: [false, true, false],
                mykey5: ['qqqqq', 'wwwwww', 'aaaaaaaaaaaaaaaaa'],
                mykey6: true,
            }
        } as Want
    ],
    operationType: WantAgent.OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

//getWantAgent回调
function getWantAgentCallback(err: BusinessError, data: _WantAgent) {
    if (err === undefined) {
        wantAgent = data;
    } else {
        console.error(`getWantAgent failed! ${JSON.stringify(wantAgent)}`);
    }
    try {
        WantAgent.cancel(wantAgent).then((data)=>{
            console.info('cancel ok!');
        }).catch((err: BusinessError)=>{
            console.error(`cancel failed! ${err.code} ${err.message}`);
        });
    } catch(err){
        console.error(`cancel failed! ${err.code} ${err.message}`);
    }
}
try {
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err) {
    console.error(`getWantAgent failed! ${err.code} ${err.message}`);
}
```

## WantAgent.trigger

trigger(agent: WantAgent, triggerInfo: TriggerInfo, callback?: AsyncCallback\<CompleteData\>): void

主动激发WantAgent实例（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名        | 类型                          | 必填 | 说明                            |
| ----------- | ----------------------------- | ---- | ------------------------------- |
| agent       | WantAgent                     | 是   | WantAgent对象。                   |
| triggerInfo | [TriggerInfo](js-apis-inner-wantAgent-triggerInfo.md)                   | 是   | TriggerInfo对象。                 |
| callback    | AsyncCallback\<[CompleteData](#completedata)\> | 否   | 主动激发WantAgent实例的回调方法。 |

**示例：**

```ts
import WantAgent, { WantAgent as _WantAgent} from '@ohos.app.ability.wantAgent';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

//wantAgent对象
let wantAgent: _WantAgent;
// triggerInfo
let triggerInfo: WantAgent.TriggerInfo = {
    code: 0 //自定义义结果码
};
//WantAgentInfo对象
let wantAgentInfo: WantAgent.WantAgentInfo = {
    wants: [
        {
            deviceId: 'deviceId',
            bundleName: 'com.example.myapplication',
            abilityName: 'EntryAbility',
            action: 'action1',
            entities: ['entity1'],
            type: 'MIMETYPE',
            uri: 'key={true,true,false}',
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: '[1, 2, 3]',
                mykey3: 'ssssssssssssssssssssssssss',
                mykey4: [false, true, false],
                mykey5: ['qqqqq', 'wwwwww', 'aaaaaaaaaaaaaaaaa'],
                mykey6: true,
            }
        } as Want
    ],
    operationType: WantAgent.OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

//getWantAgent回调
function getWantAgentCallback(err: BusinessError, data: _WantAgent) {
    if (err === undefined) {
        wantAgent = data;
    } else {
        console.error(`getWantAgent failed ${JSON.stringify(wantAgent)}`);
    }
    //trigger回调
    let triggerCallback = (err: BusinessError, data: WantAgent.CompleteData) => {
        if(err) {
            console.error(`getUid failed! ${err.code} ${err.message}`);
        } else {
            console.info(`getUid ok! ${JSON.stringify(data)}`);
        }
    }
    try {
        WantAgent.trigger(wantAgent, triggerInfo, triggerCallback);
    } catch(err) {
        console.error(`getUid failed! ${err.code} ${err.message}`);
    }
}
try {
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err) {
    console.error(`getWantAgent failed! ${err.code} ${err.message}`);
}
```



## WantAgent.equal

equal(agent: WantAgent, otherAgent: WantAgent, callback: AsyncCallback\<boolean\>): void

判断两个WantAgent实例是否相等（Callback形式）,以此来判断是否是来自同一应用的相同操作。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                     | 必填 | 说明                                    |
| ---------- | ------------------------ | ---- | --------------------------------------- |
| agent      | WantAgent                | 是   | WantAgent对象。                           |
| otherAgent | WantAgent                | 是   | WantAgent对象。                           |
| callback   | AsyncCallback\<boolean\> | 是   | 判断两个WantAgent实例是否相等的回调方法。 |

**示例：**

```ts
import WantAgent, { WantAgent as _WantAgent} from '@ohos.app.ability.wantAgent';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

//wantAgent对象
let wantAgent1: _WantAgent;
let wantAgent2: _WantAgent;
//WantAgentInfo对象
let wantAgentInfo: WantAgent.WantAgentInfo = {
    wants: [
        {
            deviceId: 'deviceId',
            bundleName: 'com.example.myapplication',
            abilityName: 'EntryAbility',
            action: 'action1',
            entities: ['entity1'],
            type: 'MIMETYPE',
            uri: 'key={true,true,false}',
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: '[1, 2, 3]',
                mykey3: 'ssssssssssssssssssssssssss',
                mykey4: [false, true, false],
                mykey5: ['qqqqq', 'wwwwww', 'aaaaaaaaaaaaaaaaa'],
                mykey6: true,
            }
        } as Want
    ],
    operationType: WantAgent.OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

//getWantAgent回调
function getWantAgentCallback(err: BusinessError, data: _WantAgent) {
    if (err === undefined) {
        wantAgent1 = data;
        wantAgent2 = data;
    } else {
        console.error(`getWantAgent failed, code: ${JSON.stringify(err.code)}, message: ${JSON.stringify(err.message)}`);
    }
    //equal回调
    let equalCallback = (err: BusinessError, data: boolean) => {
        if(err) {
            console.error(`equal failed! ${err.code} ${err.message}`);
        } else {
            console.info(`equal ok! ${JSON.stringify(data)}`);
        }
    }
    try {
        WantAgent.equal(wantAgent1,wantAgent2,equalCallback);
    } catch(err) {
        console.error(`equal failed! ${err.code} ${err.message}`);
    }
}
try {
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err) {
    console.error(`getWantAgent failed! ${err.code} ${err.message}`);
}
```



## WantAgent.equal

equal(agent: WantAgent, otherAgent: WantAgent): Promise\<boolean\>

判断两个WantAgent实例是否相等（Promise形式）,以此来判断是否是来自同一应用的相同操作。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型      | 必填 | 说明          |
| ---------- | --------- | ---- | ------------- |
| agent      | WantAgent | 是   | WantAgent对象。 |
| otherAgent | WantAgent | 是   | WantAgent对象。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | 以Promise形式返回获取判断两个WantAgent实例是否相等的结果。 |

**示例：**

```ts
import WantAgent, { WantAgent as _WantAgent} from '@ohos.app.ability.wantAgent';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

//wantAgent对象
let wantAgent1: _WantAgent;
let wantAgent2: _WantAgent;
//WantAgentInfo对象
let wantAgentInfo: WantAgent.WantAgentInfo = {
    wants: [
        {
            deviceId: 'deviceId',
            bundleName: 'com.example.myapplication',
            abilityName: 'EntryAbility',
            action: 'action1',
            entities: ['entity1'],
            type: 'MIMETYPE',
            uri: 'key={true,true,false}',
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: '[1, 2, 3]',
                mykey3: 'ssssssssssssssssssssssssss',
                mykey4: [false, true, false],
                mykey5: ['qqqqq', 'wwwwww', 'aaaaaaaaaaaaaaaaa'],
                mykey6: true,
            }
        } as Want
    ],
    operationType: WantAgent.OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

//getWantAgent回调
function getWantAgentCallback(err: BusinessError, data: _WantAgent) {
    if (err === undefined) {
        wantAgent1 = data;
        wantAgent2 = data;
    } else {
        console.error(`getWantAgent failed, code: ${JSON.stringify(err.code)}, message: ${JSON.stringify(err.message)}`);
    }
    try {
        WantAgent.equal(wantAgent1,wantAgent2).then((data)=>{
            console.info(`equal ok! ${JSON.stringify(data)}`);
        }).catch((err: BusinessError)=>{
            console.error(`equal failed! ${err.code} ${err.message}`);
        })
    } catch(err){
        console.error(`equal failed! ${err.code} ${err.message}`);
    }
}
try {
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err) {
    console.error(`getWantAgent failed! ${err.code} ${err.message}`);
}
```

## WantAgent.getOperationType

getOperationType(agent: WantAgent, callback: AsyncCallback\<number>): void;

获取一个WantAgent的OperationType信息（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                     | 必填 | 说明                                    |
| ---------- | ------------------------ | ---- | --------------------------------------- |
| agent      | WantAgent                | 是   | WantAgent对象。                           |
| callback   | AsyncCallback\<number> | 是   | 获取一个WantAgent的OperationType信息的回调方法。 |

**错误码：**

| 错误码ID    | 错误信息            |
|-----------|--------------------|
| 16000007   | Service busy, there are concurrent tasks, waiting for retry.|
| 16000015   | Service timeout.|
| 16000151   | Invalid wantagent object.|

错误码详细介绍请参考[元能力子系统错误码](../errorcodes/errorcode-ability.md)

**示例：**

```ts
import WantAgent, { WantAgent as _WantAgent} from '@ohos.app.ability.wantAgent';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

//wantAgent对象
let wantAgent: _WantAgent;
//WantAgentInfo对象
let wantAgentInfo: WantAgent.WantAgentInfo = {
    wants: [
        {
            deviceId: 'deviceId',
            bundleName: 'com.example.myapplication',
            abilityName: 'EntryAbility',
            action: 'action1',
            entities: ['entity1'],
            type: 'MIMETYPE',
            uri: 'key={true,true,false}',
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: '[1, 2, 3]',
                mykey3: 'ssssssssssssssssssssssssss',
                mykey4: [false, true, false],
                mykey5: ['qqqqq', 'wwwwww', 'aaaaaaaaaaaaaaaaa'],
                mykey6: true,
            }
        } as Want
    ],
    operationType: WantAgent.OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

//getWantAgent回调
function getWantAgentCallback(err: BusinessError, data: _WantAgent) {
    if (err === undefined) {
        wantAgent = data;
    } else {
        console.error(`getWantAgent failed ${JSON.stringify(wantAgent)}`);
    }
    //getOperationTypeCallback回调
    let getOperationTypeCallback = (err: BusinessError, data: number) => {
        if(err) {
            console.error(`getOperationType failed! ${err.code} ${err.message}`);
        } else {
            console.info(`getOperationType ok! ${JSON.stringify(data)}`);
        }
    }
    try {
        WantAgent.getOperationType(wantAgent, getOperationTypeCallback);
    } catch(err) {
        console.error(`getOperationTypeCallback failed! ${err.code} ${err.message}`);
    }
}
try {
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err) {
    console.error(`getWantAgent failed! ${err.code} ${err.message}`);
}
```

## WantAgent.getOperationType

getOperationType(agent: WantAgent): Promise\<number>;

获取一个WantAgent的OperationType信息（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型      | 必填 | 说明          |
| ---------- | --------- | ---- | ------------- |
| agent      | WantAgent | 是   | WantAgent对象。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<number> | 以Promise形式返回获取operationType的结果。 |

**错误码：**

| 错误码ID    | 错误信息            |
|-----------|--------------------|
| 16000007   | Service busy, there are concurrent tasks, waiting for retry.|
| 16000015   | Service timeout.|
| 16000151   | Invalid wantagent object.|

错误码详细介绍请参考[元能力子系统错误码](../errorcodes/errorcode-ability.md)

**示例：**

```ts
import WantAgent, { WantAgent as _WantAgent} from '@ohos.app.ability.wantAgent';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

//wantAgent对象
let wantAgent: _WantAgent;
//WantAgentInfo对象
let wantAgentInfo: WantAgent.WantAgentInfo = {
    wants: [
        {
            deviceId: 'deviceId',
            bundleName: 'com.example.myapplication',
            abilityName: 'EntryAbility',
            action: 'action1',
            entities: ['entity1'],
            type: 'MIMETYPE',
            uri: 'key={true,true,false}',
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: '[1, 2, 3]',
                mykey3: 'ssssssssssssssssssssssssss',
                mykey4: [false, true, false],
                mykey5: ['qqqqq', 'wwwwww', 'aaaaaaaaaaaaaaaaa'],
                mykey6: true,
            }
        } as Want
    ],
    operationType: WantAgent.OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

//getWantAgent回调
function getWantAgentCallback(err: BusinessError, data: _WantAgent) {
    if (err === undefined) {
        wantAgent = data;
    } else {
        console.error(`getWantAgent failed! ${JSON.stringify(wantAgent)}`);
    }
    try {
        WantAgent.getOperationType(wantAgent).then((data)=>{
            console.info(`getOperationType ok! ${JSON.stringify(data)}`);
        }).catch((err: BusinessError) => {
            console.error(`getOperationType failed! ${err.code} ${err.message}`);
        });
    } catch(err){
        console.error(`getOperationType failed! ${err.code} ${err.message}`);
    }
}
try {
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err) {
    console.error(`getWantAgent failed! ${err.code} ${err.message}`);
}
```

## WantAgentFlags

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称                | 值             | 说明                                                                      |
| ------------------- | -------------- |-------------------------------------------------------------------------|
| ONE_TIME_FLAG       | 0 | WantAgent仅能使用一次。                                                        |
| NO_BUILD_FLAG       | 1 | 如果描述WantAgent对象不存在，则不创建它，直接返回null。                                      |
| CANCEL_PRESENT_FLAG | 2 | 在生成一个新的WantAgent对象前取消已存在的一个WantAgent对象。                                 |
| UPDATE_PRESENT_FLAG | 3 | 使用新的WantAgent的额外数据替换已存在的WantAgent中的额外数据。                                |
| CONSTANT_FLAG       | 4 | WantAgent是不可变的。                                                         |
| REPLACE_ELEMENT     | 5 | 当前Want中的element属性可被WantAgent.trigger()中Want的element属性取代。当前版本暂不支持。       |
| REPLACE_ACTION      | 6 | 当前Want中的action属性可被WantAgent.trigger()中Want的action属性取代。当前版本暂不支持。         |
| REPLACE_URI         | 7 | 当前Want中的uri属性可被WantAgent.trigger()中Want的uri属性取代。当前版本暂不支持。               |
| REPLACE_ENTITIES    | 8 | 当前Want中的entities属性可被WantAgent.trigger()中Want的entities属性取代。当前版本暂不支持。     |
| REPLACE_BUNDLE      | 9 | 当前Want中的bundleName属性可被WantAgent.trigger()中Want的bundleName属性取代。当前版本暂不支持。 |



## OperationType

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称              | 值            | 说明                      |
| ----------------- | ------------- | ------------------------- |
| UNKNOWN_TYPE      | 0 | 不识别的类型。            |
| START_ABILITY     | 1 | 开启一个有页面的Ability。 |
| START_ABILITIES   | 2 | 开启多个有页面的Ability。 |
| START_SERVICE     | 3 | 开启一个无页面的ability。 |
| SEND_COMMON_EVENT | 4 | 发送一个公共事件。        |



## CompleteData 

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称           | 类型                           | 必填 | 说明                    |
| -------------- | ------------------------------ | ---- | ---------------------- |
| info           | WantAgent                       | 是   | 触发的wantAgent。       |
| want           | Want                            | 是   | 存在的被触发的want。     |
| finalCode      | number                          | 是   | 触发wantAgent的请求代码。|
| finalData      | string                          | 是   | 公共事件收集的最终数据。  |
| extraInfo      | Record\<string, Object>            | 否   | 额外数据。               |

