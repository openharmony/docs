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

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                            |
| -------- | --------------------- | ---- | ------------------------------- |
| agent    | WantAgent             | 是   | WantAgent对象。                   |
| callback | AsyncCallback\<[Want](js-apis-app-ability-want.md)\> | 是   | 获取WantAgent对象want的回调方法。 |

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
  operationType: wantAgent.OperationType.START_ABILITIES,
  requestCode: 0,
  wantAgentFlags:[wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

//getWantAgent回调
function getWantAgentCallback(err: BusinessError, data: _WantAgent) {
  if (err) {
    console.info(`getWantAgent failed, code: ${JSON.stringify(err.code)}, message: ${JSON.stringify(err.message)}`);
  } else {
    wantAgentData = data;
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
    wantAgent.getWant(wantAgentData, getWantCallback);
  } catch(err) {
    console.error(`getWant failed! ${err.code} ${err.message}`);
  }
}

try {
  wantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
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
  operationType: wantAgent.OperationType.START_ABILITIES,
  requestCode: 0,
  wantAgentFlags:[wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

//getWantAgent回调
function getWantAgentCallback(err: BusinessError, data: _WantAgent) {
  if (err) {
    console.info(`getWantAgent failed, code: ${JSON.stringify(err.code)}, message: ${JSON.stringify(err.message)}`);
  } else {
    wantAgentData = data;
  }
  try {
    wantAgent.getUid(wantAgentData).then((data)=>{
      console.info(`getUid ok! ${JSON.stringify(data)}`);
    }).catch((err: BusinessError)=>{
      console.error(`getUid failed! ${err.code} ${err.message}`);
    });
  } catch(err){
    console.error(`getUid failed! ${err.code} ${err.message}`);
  }
}

try {
  wantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err) {
  console.error(`getWantAgent failed! ${err.code} ${err.message}}`);
}
```
## OperationType

表示操作WantAgent类型的枚举。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称                      | 值 | 说明                                            |
|-------------------------|---|-----------------------------------------------|
| START_SERVICE_EXTENSION<sup>12+</sup> | 6 | 开启一个ServiceExtension。<br/>**系统接口：** 该接口为系统接口。 |