# @ohos.app.ability.wantAgent (WantAgent模块)(系统接口)

app.ability.WantAgent模块提供了创建WantAgent实例、获取实例的用户ID、获取want信息、比较WantAgent实例和获取bundle名称等能力。该模块将会取代[@ohos.wantAgent](js-apis-wantAgent.md)模块，建议优先使用本模块。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.app.ability.wantAgent (WantAgent模块)](js-apis-app-ability-wantAgent.md)。

## 导入模块

```ts
import { WantAgent } from '@kit.AbilityKit';
```

## WantAgent.getWant

getWant(agent: WantAgent, callback: AsyncCallback\<Want\>): void

获取WantAgent对象的want（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                            |
| -------- | --------------------- | ---- | ------------------------------- |
| agent    | [WantAgent](js-apis-app-ability-wantAgent.md#wantagent)             | 是   | WantAgent对象。                   |
| callback | AsyncCallback\<[Want](js-apis-app-ability-want.md)\> | 是   | 获取WantAgent对象want的回调方法。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID    | 错误信息            |
|-----------|--------------------|
| 401        | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000007   | Service busy. There are concurrent tasks. Try again later. |
| 16000015   | Service timeout.|
| 16000151   | Invalid wantAgent object.|

**示例：**

```ts
import { wantAgent, WantAgent as _WantAgent, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

//wantAgent对象
let wantAgentData: _WantAgent;
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
  actionType: wantAgent.OperationType.START_ABILITIES,
  requestCode: 0,
  wantAgentFlags:[wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

//getWantAgent回调
function getWantAgentCallback(err: BusinessError, data: _WantAgent) {
  if (err) {
    console.error(`getWantAgent failed, code: ${err.code}, message: ${err.message}`);
  } else {
    wantAgentData = data;
  }
  //getWant回调
  let getWantCallback = (err: BusinessError, data: Want) => {
    if(err) {
      console.error(`getWant failed, code: ${err.code}, messgae: ${err.message}.`);
    } else {
      console.info(`getWant success, data: ${JSON.stringify(data)}.`);
    }
  }
  try {
    wantAgent.getWant(wantAgentData, getWantCallback);
  } catch(err) {
    let code = (err as BusinessError).code;
    let msg = (err as BusinessError).message;
    console.error(`getWant failed, code: ${code}, message: ${msg}.`);
  }
}

try {
  wantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err) {
  let code = (err as BusinessError).code;
  let msg = (err as BusinessError).message;
  console.error(`getWantAgent failed, code: ${code}, message: ${msg}.`);
}
```



## WantAgent.getWant

getWant(agent: WantAgent): Promise\<Want\>

获取WantAgent对象的want（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名  | 类型      | 必填 | 说明          |
| ----- | --------- | ---- | ------------- |
| agent | [WantAgent](js-apis-app-ability-wantAgent.md#wantagent) | 是   | WantAgent对象。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<[Want](js-apis-app-ability-want.md)\> | 以Promise形式返回获取WantAgent对象的want。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID    | 错误信息            |
|-----------|--------------------|
| 401        | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000007   | Service busy. There are concurrent tasks. Try again later. |
| 16000015   | Service timeout.|
| 16000151   | Invalid wantAgent object.|

错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)

**示例：**

```ts
import { wantAgent, WantAgent as _WantAgent, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

//wantAgent对象
let wantAgentData: _WantAgent;
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
  actionType: wantAgent.OperationType.START_ABILITIES,
  requestCode: 0,
  wantAgentFlags:[wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

//getWantAgent回调
function getWantAgentCallback(err: BusinessError, data: _WantAgent) {
  if (err) {
    console.error(`getWantAgent failed, code: ${err.code}, message: ${err.message}`);
  } else {
    wantAgentData = data;
  }
  try {
    wantAgent.getWant(wantAgentData).then((data)=>{
      console.info(`getWant success, data: ${JSON.stringify(data)}`);
    }).catch((err: BusinessError)=>{
      console.error(`getWant failed, code: ${err.code}, messgae: ${err.message}.`);
    });
  } catch(err){
    let code = (err as BusinessError).code;
    let msg = (err as BusinessError).message;
    console.error(`getWant failed, code: ${code}, messgae: ${msg}.`);
  }
}

try {
  wantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err) {
  let code = (err as BusinessError).code;
  let msg = (err as BusinessError).message;
  console.error(`getWantAgent failed, code: ${code}, messgae: ${msg}.`);
}
```

## WantAgent.setWantAgentMultithreading<sup>18+</sup>

setWantAgentMultithreading(isMultithreadingSupported: boolean) : void

开启或者关闭WantAgent多线程传递功能。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数**：

| 参数名     | 类型                  | 必填 | 说明                            |
| ---------- | --------------------- | ---- | ------------------------------- |
| isMultithreadingSupported    | boolean    | 是   |表示是否开启多线程传递功能。true表示开启，false表示关闭。   |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID    | 错误信息            |
|-----------|--------------------|
| 202       | Not system app. Interface caller is not a system app. |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例**：

```ts
import { wantAgent, WantAgent as _WantAgent, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 定义wantAgent对象
let wantAgentData: _WantAgent;
// 定义WantAgentInfo对象
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
  actionType: wantAgent.OperationType.START_ABILITIES,
  requestCode: 0,
  wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

// 定义getWantAgent回调
function getWantAgentCallback(err: BusinessError, data: _WantAgent) {
  if (err) {
    console.error(`Failed to call getWantAgentCallback. Code is ${err.code}. Message is ${err.message}.`);
  } else {
    wantAgentData = data;
  }

  try {
    wantAgent.setWantAgentMultithreading(true);
  } catch (err) {
    console.error(`Failed to set wantAgentMultithreading. Code is ${err.code}. Message is ${err.message}.`);
  }
}

try {
  wantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch (err) {
  console.error(`Failed to get wantAgent. Code is ${err.code}. Message is ${err.message}.`);
}
```

## wantAgent.triggerAsync<sup>20+</sup>

triggerAsync(agent: WantAgent, triggerInfo: TriggerInfo, context: Context): Promise\<CompleteData\>

主动触发WantAgent实例，即按照WantAgent实例中已封装的指定操作和参数等信息执行。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名        | 类型                          | 必填 | 说明                            |
| ----------- | ----------------------------- | ---- | ------------------------------- |
| agent       | [WantAgent](js-apis-app-ability-wantAgent.md#wantagent)                    | 是   | WantAgent对象。                   |
| triggerInfo | [TriggerInfo](js-apis-inner-wantAgent-triggerInfo.md)                   | 是   | TriggerInfo对象。                 |
| context     | [Context](js-apis-inner-application-context.md) | 是   |  请求触发WantAgent的UIAbility/ExtensionAbility的Context。|

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<[CompleteData](js-apis-app-ability-wantAgent.md#completedata)\> | 以Promise形式返回主动激发WantAgent获得的数据。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID    | 错误信息            |
|-----------|--------------------|
| 202       | The application is not system-app, can not use system-api. |
| 16000020   | The context is not ability context. |
| 16000151   | Invalid wantAgent object.|
| 16000153   | The WantAgent has been canceled.|

**示例：**

```ts
import { wantAgent, Want, UIAbility, AbilityConstant } from '@kit.AbilityKit';
import type { WantAgent } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// wantAgent对象
let wantAgentData: WantAgent;
// triggerInfo
let triggerInfo: wantAgent.TriggerInfo = {
  code: 0 // 自定义结果码
};
// WantAgentInfo对象
let wantAgentInfo: wantAgent.WantAgentInfo = {
  // 自定义参数
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
  // 指定的操作
  actionType: wantAgent.OperationType.START_ABILITY,
  requestCode: 0,
  // wantagent对象类型
  wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

class MyAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    try {
      // 创建wantAgent对象
      wantAgent.getWantAgent(wantAgentInfo, (err: BusinessError, data: WantAgent) => {
        if (err) {
          console.info(`getWantAgent failed, code: ${err.code}, message: ${err.message}`);
        } else {
          wantAgentData = data;
        }

        try {
          // 主动触发WantAgent实例
          wantAgent.triggerAsync(wantAgentData, triggerInfo, this.context).then((data) => {
            console.info(`trigger success, data: ${JSON.stringify(data)}`);
          }).catch((err: BusinessError) => {
            console.error(`triggerAsync failed! ${err.code} ${err.message}`);
          });
        } catch (err) {
          console.error(`triggerAsync failed! ${err.code} ${err.message}`);
        }
      });
    } catch (err) {
      let code = (err as BusinessError).code;
      let msg = (err as BusinessError).message;
      console.error(`getWantAgent failed, code: ${code}, message: ${msg}.`);
    }
  }
}
```

## OperationType

表示操作WantAgent类型的枚举。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称                      | 值 | 说明                                            |
|-------------------------|---|-----------------------------------------------|
| START_SERVICE_EXTENSION<sup>12+</sup> | 6 | 开启一个ServiceExtension。<br/>**系统接口**：该接口为系统接口。 |