# @ohos.app.ability.wantAgent    
app.ability.WantAgent模块提供了创建WantAgent实例、获取实例的用户ID、获取want信息、比较WantAgent实例和获取bundle名称等能力。该模块将会取代[apis-wantAgent.md)模块，建议优先使用本模块。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import wantAgent from '@ohos.app.ability.wantAgent'    
```  
    
## getWant    
获取WantAgent对象的want（callback形式）。  
 **调用形式：**     
    
- getWant(agent: WantAgent, callback: AsyncCallback\<Want>): void    
起始版本： 9    
- getWant(agent: WantAgent): Promise\<Want>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| agent | WantAgent | true | WantAgent对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 获取WantAgent对象want的回调方法。 |  
| Promise<Want> | 以Promise形式返回获取WantAgent实例的用户ID。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 16000007 | Service busy, there are concurrent tasks, waiting for retry. |  
| 16000015 | Service timeout. |  
| 16000151 | Invalid wantagent object. |  
    
 **示例代码1：**   
示例(callback):  
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
  
    
 **示例代码2：**   
示例(Prosmise):  
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
  
