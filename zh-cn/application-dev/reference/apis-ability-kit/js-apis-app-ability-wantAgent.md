# @ohos.app.ability.wantAgent (WantAgent模块)

app.ability.WantAgent是一个封装了[Want](./js-apis-app-ability-want.md)对象的类，允许应用程序能够在未来的某个时间点执行该Want。该模块提供了创建WantAgent实例、获取实例的用户ID、获取want信息、比较WantAgent实例和获取包名等功能。
WantAgent的一个典型应用场景是通知处理。例如，当用户点击通知时，会触发WantAgent的[trigger](#wantagenttrigger)接口，并拉起目标应用。具体使用请参考[通知模块](../../notification/notification-with-wantagent.md)。该模块将会取代[@ohos.wantAgent](js-apis-wantAgent.md)模块，建议优先使用本模块。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { wantAgent } from '@kit.AbilityKit';
```

## wantAgent.getWantAgent

getWantAgent(info: WantAgentInfo, callback: AsyncCallback\<WantAgent\>): void

创建WantAgent（callback形式）。 创建失败返回的WantAgent为空值。

三方应用只能设置自己应用的Ability。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名     | 类型                       | 必填 | 说明                    |
| -------- | -------------------------- | ---- | ----------------------- |
| info     | [WantAgentInfo](js-apis-inner-wantAgent-wantAgentInfo.md)              | 是   | WantAgent信息。           |
| callback | AsyncCallback\<WantAgent\> | 是   | 创建WantAgent的回调方法。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID    | 错误信息            |
|-----------|--------------------|
| 401        | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000007   | Service busy. There are concurrent tasks. Try again later. |
| 16000151   | Invalid wantagent object.|

**示例：**

```ts
import { wantAgent, Want } from '@kit.AbilityKit';
import type { WantAgent } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

//wantAgent对象
let wantAgentData: WantAgent;
//WantAgentInfo对象
let wantAgentInfo: wantAgent.WantAgentInfo = {
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
  actionType: wantAgent.OperationType.START_ABILITY,
  requestCode: 0,
  wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

//getWantAgent回调
function getWantAgentCallback(err: BusinessError, data: WantAgent) {
  if (err) {
    console.error(`getWantAgent failed, code: ${JSON.stringify(err.code)}, message: ${JSON.stringify(err.message)}`);
  } else {
    wantAgentData = data;
  }
}

try {
  wantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch (err) {
  console.error(`getWantAgent failed, error: ${JSON.stringify(err)}`);
}
```

## wantAgent.getWantAgent

getWantAgent(info: WantAgentInfo): Promise\<WantAgent\>

创建WantAgent（Promise形式）。 创建失败返回的WantAgent为空值。

三方应用只能设置自己应用的Ability。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

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

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID    | 错误信息            |
|-----------|--------------------|
| 401        | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000007   | Service busy. There are concurrent tasks. Try again later. |
| 16000151   | Invalid wantagent object.|

**示例：**

```ts
import { wantAgent, Want } from '@kit.AbilityKit';
import type { WantAgent } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantAgentData: WantAgent;
//WantAgentInfo对象
let wantAgentInfo: wantAgent.WantAgentInfo = {
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
  actionType: wantAgent.OperationType.START_ABILITY,
  requestCode: 0,
  wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

try {
  wantAgent.getWantAgent(wantAgentInfo).then((data) => {
    wantAgentData = data;
  }).catch((err: BusinessError) => {
    console.error(`getWantAgent failed, code: ${JSON.stringify(err.code)}, message: ${JSON.stringify(err.message)}`);
  });
} catch (err) {
  console.error(`getWantAgent failed! ${err.code} ${err.message}`);
}
```



## wantAgent.getBundleName

getBundleName(agent: WantAgent, callback: AsyncCallback\<string\>): void

获取WantAgent实例的包名（callback形式）。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名     | 类型                    | 必填 | 说明                              |
| -------- | ----------------------- | ---- | --------------------------------- |
| agent    | WantAgent               | 是   | WantAgent对象。                     |
| callback | AsyncCallback\<string\> | 是   | 获取WantAgent实例的包名的回调方法。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID    | 错误信息            |
|-----------|--------------------|
| 401        | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000007   | Service busy. There are concurrent tasks. Try again later. |
| 16000151   | Invalid wantagent object.|

**示例：**

```ts
import { wantAgent, Want } from '@kit.AbilityKit';
import type { WantAgent } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

//wantAgent对象
let wantAgentData: WantAgent;
//WantAgentInfo对象
let wantAgentInfo: wantAgent.WantAgentInfo = {
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
  actionType: wantAgent.OperationType.START_ABILITY,
  requestCode: 0,
  wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

//getWantAgent回调
function getWantAgentCallback(err: BusinessError, data: WantAgent) {
  if (err) {
    console.error(`getWantAgent failed, code: ${JSON.stringify(err.code)}, message: ${JSON.stringify(err.message)}`);
  } else {
    wantAgentData = data;
  }
  //getBundleName回调
  let getBundleNameCallback = (err: BusinessError, data: string) => {
    if (err) {
      console.error(`getBundleName failed! ${err.code} ${err.message}`);
    } else {
      console.info(`getBundleName ok! ${JSON.stringify(data)}`);
    }
  }
  try {
    wantAgent.getBundleName(wantAgentData, getBundleNameCallback);
  } catch (err) {
    console.error(`getBundleName failed! ${err.code} ${err.message}`);
  }
}

try {
  wantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch (err) {
  console.error(`getWantAgent failed! ${err.code} ${err.message}`);
}
```

## wantAgent.getBundleName

getBundleName(agent: WantAgent): Promise\<string\>

获取WantAgent实例的包名（Promise形式）。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

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

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID    | 错误信息            |
|-----------|--------------------|
| 401        | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000007   | Service busy. There are concurrent tasks. Try again later. |
| 16000151   | Invalid wantagent object.|

**示例：**

```ts
import { wantAgent, Want } from '@kit.AbilityKit';
import type { WantAgent } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

//wantAgent对象
let wantAgentData: WantAgent;
//WantAgentInfo对象
let wantAgentInfo: wantAgent.WantAgentInfo = {
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
  actionType: wantAgent.OperationType.START_ABILITY,
  requestCode: 0,
  wantAgentFlags:[wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

//getWantAgent回调
function getWantAgentCallback(err: BusinessError, data: WantAgent) {
  if (err) {
    console.error(`getWantAgent failed, code: ${JSON.stringify(err.code)}, message: ${JSON.stringify(err.message)}`);
  } else {
    wantAgentData = data;
  }
  try {
    wantAgent.getBundleName(wantAgentData).then((data)=>{
      console.info(`getBundleName ok! ${JSON.stringify(data)}`);
    }).catch((err: BusinessError)=>{
      console.error(`getBundleName failed! ${err.code} ${err.message}`);
    });
  } catch(err){
    console.error(`getBundleName failed! ${err.code} ${err.message}`);
  }
}
try {
  wantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err) {
  console.error(`getWantAgent failed! ${err.code} ${err.message}`);
}
```

## wantAgent.getUid

getUid(agent: WantAgent, callback: AsyncCallback\<number\>): void

获取WantAgent实例的用户ID（callback形式）。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名     | 类型                    | 必填 | 说明                                |
| -------- | ----------------------- | ---- | ----------------------------------- |
| agent    | WantAgent               | 是   | WantAgent对象。                       |
| callback | AsyncCallback\<number\> | 是   | 获取WantAgent实例的用户ID的回调方法。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID    | 错误信息            |
|-----------|--------------------|
| 401        | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000007   | Service busy. There are concurrent tasks. Try again later. |
| 16000151   | Invalid wantagent object.|

**示例：**

```ts
import { wantAgent, Want } from '@kit.AbilityKit';
import type { WantAgent } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

//wantAgent对象
let wantAgentData: WantAgent;
//WantAgentInfo对象
let wantAgentInfo: wantAgent.WantAgentInfo = {
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
  actionType: wantAgent.OperationType.START_ABILITY,
  requestCode: 0,
  wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

//getWantAgent回调
function getWantAgentCallback(err: BusinessError, data: WantAgent) {
  if (err) {
    console.info(`getWantAgent failed, code: ${JSON.stringify(err.code)}, message: ${JSON.stringify(err.message)}`);
  } else {
    wantAgentData = data;
  }
  //getUid回调
  let getUidCallback = (err: BusinessError, data: number) => {
    if (err) {
      console.error(`getUid failed! ${err.code} ${err.message}`);
    } else {
      console.info(`getUid ok! ${JSON.stringify(data)}`);
    }
  }
  try {
    wantAgent.getUid(wantAgentData, getUidCallback);
  } catch (err) {
    console.error(`getUid failed! ${err.code} ${err.message}`);
  }
}

try {
  wantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch (err) {
  console.error(`getWantAgent failed! ${err.code} ${err.message}`);
}
```

## wantAgent.getUid

getUid(agent: WantAgent): Promise\<number\>

获取WantAgent实例的用户ID（Promise形式）。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

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

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID    | 错误信息            |
|-----------|--------------------|
| 401        | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000007   | Service busy. There are concurrent tasks. Try again later. |
| 16000151   | Invalid wantagent object.|

**示例：**

```ts
import { wantAgent, Want } from '@kit.AbilityKit';
import type { WantAgent } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

//wantAgent对象
let wantAgentData: WantAgent;
//WantAgentInfo对象
let wantAgentInfo: wantAgent.WantAgentInfo = {
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
  actionType: wantAgent.OperationType.START_ABILITY,
  requestCode: 0,
  wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

//getWantAgent回调
function getWantAgentCallback(err: BusinessError, data: WantAgent) {
  if (err) {
    console.info(`getWantAgent failed, code: ${JSON.stringify(err.code)}, message: ${JSON.stringify(err.message)}`);
  } else {
    wantAgentData = data;
  }
  try {
    wantAgent.getUid(wantAgentData).then((data) => {
      console.info(`getUid ok! ${JSON.stringify(data)}`);
    }).catch((err: BusinessError) => {
      console.error(`getUid failed! ${err.code} ${err.message}`);
    });
  } catch (err) {
    console.error(`getUid failed! ${err.code} ${err.message}`);
  }
}

try {
  wantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch (err) {
  console.error(`getWantAgent failed! ${err.code} ${err.message}`);
}
```

## wantAgent.cancel

cancel(agent: WantAgent, callback: AsyncCallback\<void\>): void

取消WantAgent实例（callback形式）。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名     | 类型                  | 必填 | 说明                        |
| -------- | --------------------- | ---- | --------------------------- |
| agent    | WantAgent             | 是   | WantAgent对象。               |
| callback | AsyncCallback\<void\> | 是   | 取消WantAgent实例的回调方法。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID    | 错误信息            |
|-----------|--------------------|
| 401        | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000007   | Service busy. There are concurrent tasks. Try again later. |
| 16000151   | Invalid wantagent object.|

**示例：**

```ts
import { wantAgent, Want } from '@kit.AbilityKit';
import type { WantAgent } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

//wantAgent对象
let wantAgentData: WantAgent;
//WantAgentInfo对象
let wantAgentInfo: wantAgent.WantAgentInfo = {
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
  actionType: wantAgent.OperationType.START_ABILITY,
  requestCode: 0,
  wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

//getWantAgent回调
function getWantAgentCallback(err: BusinessError, data: WantAgent) {
  if (err) {
    console.info(`getWantAgent failed, code: ${JSON.stringify(err.code)}, message: ${JSON.stringify(err.message)}`);
  } else {
    wantAgentData = data;
  }
  //cancel回调
  let cancelCallback = (err: BusinessError, data: void) => {
    if (err) {
      console.error(`cancel failed! ${err.code} ${err.message}`);
    } else {
      console.info(`cancel ok!`);
    }
  }
  try {
    wantAgent.cancel(wantAgentData, cancelCallback);
  } catch (err) {
    console.error(`cancel failed! ${err.code} ${err.message}`);
  }
}

try {
  wantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch (err) {
  console.error(`getWantAgent failed! ${(err as BusinessError).code} ${(err as BusinessError).message}`);
}
```

## wantAgent.cancel

cancel(agent: WantAgent): Promise\<void\>

取消WantAgent实例（Promise形式）。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

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

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID    | 错误信息            |
|-----------|--------------------|
| 401        | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000007   | Service busy. There are concurrent tasks. Try again later. |
| 16000151   | Invalid wantagent object.|

**示例：**

```ts
import { wantAgent, Want } from '@kit.AbilityKit';
import type { WantAgent } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

//wantAgent对象
let wantAgentData: WantAgent;
//WantAgentInfo对象
let wantAgentInfo: wantAgent.WantAgentInfo = {
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
  actionType: wantAgent.OperationType.START_ABILITY,
  requestCode: 0,
  wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

//getWantAgent回调
function getWantAgentCallback(err: BusinessError, data: WantAgent) {
  if (err) {
    console.info(`getWantAgent failed, code: ${JSON.stringify(err.code)}, message: ${JSON.stringify(err.message)}`);
  } else {
    wantAgentData = data;
  }
  try {
    wantAgent.cancel(wantAgentData).then((data) => {
      console.info('cancel ok!');
    }).catch((err: BusinessError) => {
      console.error(`cancel failed! ${err.code} ${err.message}`);
    });
  } catch (err) {
    console.error(`cancel failed! ${err.code} ${err.message}`);
  }
}

try {
  wantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch (err) {
  console.error(`getWantAgent failed! ${(err as BusinessError).code} ${(err as BusinessError).message}`);
}
```

## wantAgent.trigger

trigger(agent: WantAgent, triggerInfo: TriggerInfo, callback?: AsyncCallback\<CompleteData\>): void

主动激发WantAgent实例（callback形式）。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名        | 类型                          | 必填 | 说明                            |
| ----------- | ----------------------------- | ---- | ------------------------------- |
| agent       | WantAgent                     | 是   | WantAgent对象。                   |
| triggerInfo | [TriggerInfo](js-apis-inner-wantAgent-triggerInfo.md)                   | 是   | TriggerInfo对象。                 |
| callback    | AsyncCallback\<[CompleteData](#completedata)\> | 否   | 主动激发WantAgent实例的回调方法。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID    | 错误信息            |
|-----------|--------------------|
| 401        | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

```ts
import { wantAgent, Want } from '@kit.AbilityKit';
import type { WantAgent } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

//wantAgent对象
let wantAgentData: WantAgent;
// triggerInfo
let triggerInfo: wantAgent.TriggerInfo = {
  code: 0 //自定义义结果码
};
//WantAgentInfo对象
let wantAgentInfo: wantAgent.WantAgentInfo = {
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
  actionType: wantAgent.OperationType.START_ABILITY,
  requestCode: 0,
  wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

//getWantAgent回调
function getWantAgentCallback(err: BusinessError, data: WantAgent) {
  if (err) {
    console.info(`getWantAgent failed, code: ${JSON.stringify(err.code)}, message: ${JSON.stringify(err.message)}`);
  } else {
    wantAgentData = data;
  }
  //trigger回调
  let triggerCallback = (err: BusinessError, data: wantAgent.CompleteData) => {
    if (err) {
      console.error(`getUid failed! ${err.code} ${err.message}`);
    } else {
      console.info(`getUid ok! ${JSON.stringify(data)}`);
    }
  }
  try {
    wantAgent.trigger(wantAgentData, triggerInfo, triggerCallback);
  } catch (err) {
    console.error(`getUid failed! ${err.code} ${err.message}`);
  }
}

try {
  wantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch (err) {
  console.error(`getWantAgent failed! ${(err as BusinessError).code} ${(err as BusinessError).message}`);
}
```

## wantAgent.equal

equal(agent: WantAgent, otherAgent: WantAgent, callback: AsyncCallback\<boolean\>): void

判断两个WantAgent实例是否相等（Callback形式）,以此来判断是否是来自同一应用的相同操作。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                     | 必填 | 说明                                    |
| ---------- | ------------------------ | ---- | --------------------------------------- |
| agent      | WantAgent                | 是   | WantAgent对象。                           |
| otherAgent | WantAgent                | 是   | WantAgent对象。                           |
| callback   | AsyncCallback\<boolean\> | 是   | 判断两个WantAgent实例是否相等的回调方法。返回true表示两个WantAgent实例相等，false表示两个WantAgent实例不相等。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID    | 错误信息            |
|-----------|--------------------|
| 401        | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

```ts
import { wantAgent, Want } from '@kit.AbilityKit';
import type { WantAgent } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

//wantAgent对象
let wantAgent1: WantAgent;
let wantAgent2: WantAgent;
//WantAgentInfo对象
let wantAgentInfo: wantAgent.WantAgentInfo = {
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
  actionType: wantAgent.OperationType.START_ABILITY,
  requestCode: 0,
  wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

//getWantAgent回调
function getWantAgentCallback(err: BusinessError, data: WantAgent) {
  if (err) {
    console.error(`getWantAgent failed, code: ${JSON.stringify(err.code)}, message: ${JSON.stringify(err.message)}`);
  } else {
    wantAgent1 = data;
    wantAgent2 = data;
  }
  //equal回调
  let equalCallback = (err: BusinessError, data: boolean) => {
    if (err) {
      console.error(`equal failed! ${err.code} ${err.message}`);
    } else {
      console.info(`equal ok! ${JSON.stringify(data)}`);
    }
  }
  try {
    wantAgent.equal(wantAgent1, wantAgent2, equalCallback);
  } catch (err) {
    console.error(`equal failed! ${(err as BusinessError).code} ${(err as BusinessError).message}`);
  }
}

try {
  wantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch (err) {
  console.error(`getWantAgent failed! ${(err as BusinessError).code} ${(err as BusinessError).message}`);
}
```

## wantAgent.equal

equal(agent: WantAgent, otherAgent: WantAgent): Promise\<boolean\>

判断两个WantAgent实例是否相等（Promise形式）,以此来判断是否是来自同一应用的相同操作。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型      | 必填 | 说明          |
| ---------- | --------- | ---- | ------------- |
| agent      | WantAgent | 是   | WantAgent对象。 |
| otherAgent | WantAgent | 是   | WantAgent对象。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | 以Promise形式返回获取判断两个WantAgent实例是否相等的结果。返回true表示两个WantAgent实例相等，false表示两个WantAgent实例不相等。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID    | 错误信息            |
|-----------|--------------------|
| 401        | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

```ts
import { wantAgent, Want } from '@kit.AbilityKit';
import type { WantAgent } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

//wantAgent对象
let wantAgent1: WantAgent;
let wantAgent2: WantAgent;
//WantAgentInfo对象
let wantAgentInfo: wantAgent.WantAgentInfo = {
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
  actionType: wantAgent.OperationType.START_ABILITY,
  requestCode: 0,
  wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

//getWantAgent回调
function getWantAgentCallback(err: BusinessError, data: WantAgent) {
  if (err) {
    console.error(`getWantAgent failed, code: ${JSON.stringify(err.code)}, message: ${JSON.stringify(err.message)}`);
  } else {
    wantAgent1 = data;
    wantAgent2 = data;
  }
  try {
    wantAgent.equal(wantAgent1, wantAgent2).then((data) => {
      console.info(`equal ok! ${JSON.stringify(data)}`);
    }).catch((err: BusinessError) => {
      console.error(`equal failed! ${err.code} ${err.message}`);
    })
  } catch (err) {
    console.error(`equal failed! ${(err as BusinessError).code} ${(err as BusinessError).message}`);
  }
}

try {
  wantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch (err) {
  console.error(`getWantAgent failed! ${(err as BusinessError).code} ${(err as BusinessError).message}`);
}
```

## wantAgent.getOperationType

getOperationType(agent: WantAgent, callback: AsyncCallback\<number>): void

获取一个WantAgent的OperationType信息（callback形式）。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                     | 必填 | 说明                                    |
| ---------- | ------------------------ | ---- | --------------------------------------- |
| agent      | WantAgent                | 是   | WantAgent对象。                           |
| callback   | AsyncCallback\<number> | 是   | 获取一个WantAgent的OperationType信息的回调方法。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID    | 错误信息            |
|-----------|--------------------|
| 401        | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000007   | Service busy. There are concurrent tasks. Try again later. |
| 16000015   | Service timeout.|
| 16000151   | Invalid wantagent object.|

**示例：**

```ts
import { wantAgent, Want } from '@kit.AbilityKit';
import type { WantAgent } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

//wantAgent对象
let wantAgentData: WantAgent;
//WantAgentInfo对象
let wantAgentInfo: wantAgent.WantAgentInfo = {
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
  actionType: wantAgent.OperationType.START_ABILITY,
  requestCode: 0,
  wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

//getWantAgent回调
function getWantAgentCallback(err: BusinessError, data: WantAgent) {
  if (err) {
    console.error(`getWantAgent failed, code: ${JSON.stringify(err.code)}, message: ${JSON.stringify(err.message)}`);
  } else {
    wantAgentData = data;
  }
  //getOperationTypeCallback回调
  let getOperationTypeCallback = (err: BusinessError, data: number) => {
    if (err) {
      console.error(`getOperationType failed! ${err.code} ${err.message}`);
    } else {
      console.info(`getOperationType ok! ${JSON.stringify(data)}`);
    }
  }
  try {
    wantAgent.getOperationType(wantAgentData, getOperationTypeCallback);
  } catch (err) {
    console.error(`getOperationTypeCallback failed! ${(err as BusinessError).code} ${(err as BusinessError).message}`);
  }
}

try {
  wantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch (err) {
  console.error(`getWantAgent failed! ${(err as BusinessError).code} ${(err as BusinessError).message}`);
}
```

## wantAgent.getOperationType

getOperationType(agent: WantAgent): Promise\<number>

获取一个WantAgent的OperationType信息（Promise形式）。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

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

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID    | 错误信息            |
|-----------|--------------------|
| 401        | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000007   | Service busy. There are concurrent tasks. Try again later. |
| 16000015   | Service timeout.|
| 16000151   | Invalid wantagent object.|

错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)

**示例：**

```ts
import { wantAgent, Want } from '@kit.AbilityKit';
import type { WantAgent } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

//wantAgent对象
let wantAgentData: WantAgent;
//WantAgentInfo对象
let wantAgentInfo: wantAgent.WantAgentInfo = {
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
  actionType: wantAgent.OperationType.START_ABILITY,
  requestCode: 0,
  wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

//getWantAgent回调
function getWantAgentCallback(err: BusinessError, data: WantAgent) {
  if (err) {
    console.error(`getWantAgent failed, code: ${JSON.stringify(err.code)}, message: ${JSON.stringify(err.message)}`);
  } else {
    wantAgentData = data;
  }
  try {
    wantAgent.getOperationType(wantAgentData).then((data) => {
      console.info(`getOperationType ok! ${JSON.stringify(data)}`);
    }).catch((err: BusinessError) => {
      console.error(`getOperationType failed! ${err.code} ${err.message}`);
    });
  } catch (err) {
    console.error(`getOperationType failed! ${(err as BusinessError).code} ${(err as BusinessError).message}`);
  }
}

try {
  wantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch (err) {
  console.error(`getWantAgent failed! ${(err as BusinessError).code} ${(err as BusinessError).message}`);
}
```

## WantAgentFlags

表示使用WantAgent类型的枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

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

表示操作WantAgent类型的枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称              | 值            | 说明                      |
| ----------------- | ------------- | ------------------------- |
| UNKNOWN_TYPE      | 0 | 不识别的类型。            |
| START_ABILITY     | 1 | 开启一个有页面的Ability。 |
| START_ABILITIES   | 2 | 开启多个有页面的Ability。 |
| START_SERVICE     | 3 | 开启一个无页面的Ability（仅在FA模型下生效）。 |
| SEND_COMMON_EVENT | 4 | 发送一个公共事件。        |



## CompleteData

表示主动激发WantAgent返回的数据。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| info           | WantAgent                       | 否 | 否   | 触发的wantAgent。       |
| want           | [Want](js-apis-app-ability-want.md#属性)                            | 否 | 否   | 存在的被触发的want。     |
| finalCode      | number                          | 否 | 否   | 触发wantAgent的执行结果。<br/>- 对于启动Ability的场景(即[OperationType](#operationtype) 取值为 1、2、3时)，执行成功finalcode为0，执行失败finalcode取值参见[元能力子系统错误码](errorcode-ability.md)。<br/>- 对于发布公共事件的场景(即[OperationType](#operationtype)取值为4时)，执行成功finalcode为0，执行失败finalcode取值参见[事件错误码](../apis-basic-services-kit/errorcode-CommonEventService.md)。 |
| finalData      | string                          | 否 | 否   | 公共事件收集的最终数据。  |
| extraInfo      | Record\<string, Object>            | 否 |是   | 额外数据。               |

