# @ohos.wantAgent    
WantAgent模块提供了创建WantAgent实例、获取实例的用户ID、获取want信息、比较WantAgent实例和获取bundle名称等能力。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import wantAgent from '@ohos.wantAgent'    
```  
    
## getBundleName<sup>(deprecated)</sup>    
获取WantAgent实例的Bundle名称（callback形式）。  
 **调用形式：**     
- getBundleName(agent: WantAgent, callback: AsyncCallback\<string>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.wantAgent/wantAgent#getBundleName。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| agent<sup>(deprecated)</sup> | WantAgent | true | WantAgent对象。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<string> | true | 获取WantAgent实例的包名的回调方法。 |  
    
 **示例代码：**   
```ts    
import WantAgent, { WantAgent as _WantAgent} from '@ohos.wantAgent';  
import { BusinessError } from '@ohos.base';  
  
//wantAgent对象  
let wantAgent: _WantAgent;  
  
//getWantAgent回调  
function getWantAgentCallback(err: BusinessError, data: _WantAgent) {  
	console.info('==========================>getWantAgentCallback=======================>');  
    if (err.code == 0) {  
    	wantAgent = data;  
    } else {  
        console.error('getWantAgent failed, error: ' + JSON.stringify(err));  
        return;  
    }  
  
    //getBundleName回调  
    let getBundleNameCallback = (err: BusinessError, data: string) => {  
        console.info('==========================>getBundleNameCallback=======================>');  
    }  
    WantAgent.getBundleName(wantAgent, getBundleNameCallback);  
}  
  
WantAgent.getWantAgent({  
    wants: [  
        {  
            deviceId: 'deviceId',  
            bundleName: 'com.neu.setResultOnAbilityResultTest1',  
            abilityName: 'com.example.test.EntryAbility',  
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
        }  
    ],  
    operationType: WantAgent.OperationType.START_ABILITIES,  
    requestCode: 0,  
    wantAgentFlags:[WantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]  
}, getWantAgentCallback)  
    
```    
  
    
## getBundleName<sup>(deprecated)</sup>    
获取WantAgent实例的Bundle名称（Promise形式）。  
 **调用形式：**     
- getBundleName(agent: WantAgent): Promise\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.wantAgent/wantAgent#getBundleName。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| agent<sup>(deprecated)</sup> | WantAgent | true | WantAgent对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<string> | 以Promise形式返回获取WantAgent实例的Bundle名称。 |  
    
 **示例代码：**   
```ts    
import WantAgent, { WantAgent as _WantAgent} from '@ohos.wantAgent';  
//wantAgent对象let wantAgent: _WantAgent;  
WantAgent.getWantAgent({    wants: [        {            deviceId: 'deviceId',            bundleName: 'com.neu.setResultOnAbilityResultTest1',            abilityName: 'com.example.test.EntryAbility',            action: 'action1',            entities: ['entity1'],            type: 'MIMETYPE',            uri: 'key={true,true,false}',            parameters:            {                mykey0: 2222,                mykey1: [1, 2, 3],                mykey2: '[1, 2, 3]',                mykey3: 'ssssssssssssssssssssssssss',                mykey4: [false, true, false],                mykey5: ['qqqqq', 'wwwwww', 'aaaaaaaaaaaaaaaaa'],                mykey6: true,            }        }    ],    operationType: WantAgent.OperationType.START_ABILITIES,    requestCode: 0,    wantAgentFlags:[WantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]}).then((data: _WantAgent) => {console.info('==========================>getWantAgentCallback=======================>');    wantAgent = data;    if (wantAgent) {        WantAgent.getBundleName(wantAgent).then((data) => {            console.info('==========================>getBundleNameCallback=======================>');        });    }});    
```    
  
    
## getUid<sup>(deprecated)</sup>    
获取WantAgent实例的用户ID（callback形式）。  
 **调用形式：**     
- getUid(agent: WantAgent, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.wantAgent/wantAgent#getUid。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| agent<sup>(deprecated)</sup> | WantAgent | true | WantAgent对象。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 获取WantAgent实例的用户ID的回调方法。 |  
    
 **示例代码：**   
```ts    
import WantAgent, { WantAgent as _WantAgent} from '@ohos.wantAgent';  
import { BusinessError } from '@ohos.base';  
  
//wantAgent对象  
let wantAgent: _WantAgent;  
  
//getWantAgent回调  
function getWantAgentCallback(err: BusinessError, data: _WantAgent) {  
	console.info('==========================>getWantAgentCallback=======================>');  
    if (err.code == 0) {  
    	wantAgent = data;  
    } else {  
        console.error('getWantAgent failed, error: ' + JSON.stringify(err));  
        return;  
    }  
  
    //getUid回调  
    let getUidCallback = (err: BusinessError, data: number) => {  
        console.info('==========================>getUidCallback=======================>');  
    }  
    WantAgent.getUid(wantAgent, getUidCallback);  
}  
  
WantAgent.getWantAgent({  
    wants: [  
        {  
            deviceId: 'deviceId',  
            bundleName: 'com.neu.setResultOnAbilityResultTest1',  
            abilityName: 'com.example.test.EntryAbility',  
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
        }  
    ],  
    operationType: WantAgent.OperationType.START_ABILITIES,  
    requestCode: 0,  
    wantAgentFlags:[WantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]  
}, getWantAgentCallback)  
    
```    
  
    
## getUid<sup>(deprecated)</sup>    
获取WantAgent实例的用户ID（Promise形式）。  
 **调用形式：**     
- getUid(agent: WantAgent): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.wantAgent/wantAgent#getUid。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| agent<sup>(deprecated)</sup> | WantAgent | true | WantAgent对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | 以Promise形式返回获取WantAgent实例的用户ID。 |  
    
 **示例代码：**   
```ts    
import WantAgent, { WantAgent as _WantAgent} from '@ohos.wantAgent';  
//wantAgent对象let wantAgent: _WantAgent;  
WantAgent.getWantAgent({    wants: [        {            deviceId: 'deviceId',            bundleName: 'com.neu.setResultOnAbilityResultTest1',            abilityName: 'com.example.test.EntryAbility',            action: 'action1',            entities: ['entity1'],            type: 'MIMETYPE',            uri: 'key={true,true,false}',            parameters:            {                mykey0: 2222,                mykey1: [1, 2, 3],                mykey2: '[1, 2, 3]',                mykey3: 'ssssssssssssssssssssssssss',                mykey4: [false, true, false],                mykey5: ['qqqqq', 'wwwwww', 'aaaaaaaaaaaaaaaaa'],                mykey6: true,            }        }    ],    operationType: WantAgent.OperationType.START_ABILITIES,    requestCode: 0,    wantAgentFlags:[WantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]}).then((data) => {console.info('==========================>getWantAgentCallback=======================>');    wantAgent = data;    if (wantAgent) {        WantAgent.getUid(wantAgent).then((data) => {        console.info('==========================>getUidCallback=======================>');    });    }});    
```    
  
    
## cancel<sup>(deprecated)</sup>    
取消WantAgent实例（callback形式）。  
 **调用形式：**     
- cancel(agent: WantAgent, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.wantAgent/wantAgent#cancel。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| agent<sup>(deprecated)</sup> | WantAgent | true | WantAgent对象。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 取消WantAgent实例的回调方法。 |  
    
 **示例代码：**   
```ts    
import WantAgent, { WantAgent as _WantAgent} from '@ohos.wantAgent';  
import { BusinessError } from '@ohos.base';  
  
//wantAgent对象  
let wantAgent: _WantAgent;  
  
//getWantAgent回调  
function getWantAgentCallback(err: BusinessError, data: _WantAgent) {  
	console.info('==========================>getWantAgentCallback=======================>');  
    if (err.code == 0) {  
    	wantAgent = data;  
    } else {  
        console.error('getWantAgent failed, error: ' + JSON.stringify(err));  
        return;  
    }  
  
    //cancel回调  
    let cancelCallback = (err: BusinessError) => {  
        console.info('==========================>cancelCallback=======================>');  
    }  
    WantAgent.cancel(wantAgent, cancelCallback);  
}  
  
WantAgent.getWantAgent({  
    wants: [  
        {  
            deviceId: 'deviceId',  
            bundleName: 'com.neu.setResultOnAbilityResultTest1',  
            abilityName: 'com.example.test.EntryAbility',  
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
        }  
    ],  
    operationType: WantAgent.OperationType.START_ABILITIES,  
    requestCode: 0,  
    wantAgentFlags:[WantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]  
}, getWantAgentCallback)  
    
```    
  
    
## cancel<sup>(deprecated)</sup>    
取消WantAgent实例（Promise形式）。  
 **调用形式：**     
- cancel(agent: WantAgent): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.wantAgent/wantAgent#cancel。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| agent<sup>(deprecated)</sup> | WantAgent | true | WantAgent对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 以Promise形式获取异步返回结果。 |  
    
 **示例代码：**   
```ts    
import WantAgent, { WantAgent as _WantAgent} from '@ohos.wantAgent';  
import { BusinessError } from '@ohos.base';  
  
//wantAgent对象  
let wantAgent: _WantAgent;  
  
WantAgent.getWantAgent({  
    wants: [  
    {  
        deviceId: 'deviceId',  
        bundleName: 'com.neu.setResultOnAbilityResultTest1',  
        abilityName: 'com.example.test.EntryAbility',  
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
    }  
],  
    operationType: WantAgent.OperationType.START_ABILITIES,  
    requestCode: 0,  
    wantAgentFlags:[WantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]  
}).then((data) => {  
	console.info('==========================>getWantAgentCallback=======================>');  
    wantAgent = data;  
    if (wantAgent) {          
        WantAgent.cancel(wantAgent).then((data) => {  
            console.info('==========================>cancelCallback=======================>');  
        });  
    }  
});  
    
```    
  
    
## trigger<sup>(deprecated)</sup>    
主动激发WantAgent实例（callback形式）。  
 **调用形式：**     
- trigger(agent: WantAgent, triggerInfo: TriggerInfo, callback?: Callback\<CompleteData>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.wantAgent/wantAgent#trigger。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| agent<sup>(deprecated)</sup> | WantAgent | true | WantAgent对象。 |  
| triggerInfo<sup>(deprecated)</sup> | TriggerInfo | true | TriggerInfo对象。 |  
| callback<sup>(deprecated)</sup> | Callback<CompleteData> | false | 主动激发WantAgent实例的回调方法。 |  
    
 **示例代码：**   
```ts    
import WantAgent, { WantAgent as _WantAgent} from '@ohos.wantAgent';  
import { BusinessError } from '@ohos.base';  
  
//wantAgent对象  
let wantAgent: _WantAgent;  
  
//getWantAgent回调  
function getWantAgentCallback(err: BusinessError, data: _WantAgent) {  
	console.info('==========================>getWantAgentCallback=======================>');  
    if (err.code == 0) {  
    	wantAgent = data;  
    } else {  
        console.error('getWantAgent failed, error: ' + JSON.stringify(err));  
        return;  
    }  
  
    //trigger回调  
    let triggerCallback = (data: WantAgent.CompleteData) => {  
        console.info('==========================>triggerCallback=======================>');  
    }  
  
    WantAgent.trigger(wantAgent, {code:0}, triggerCallback)  
}  
  
WantAgent.getWantAgent({  
    wants: [  
        {  
            deviceId: 'deviceId',  
            bundleName: 'com.neu.setResultOnAbilityResultTest1',  
            abilityName: 'com.example.test.EntryAbility',  
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
        }  
    ],  
    operationType: WantAgent.OperationType.START_ABILITIES,  
    requestCode: 0,  
    wantAgentFlags:[WantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]  
}, getWantAgentCallback)  
    
```    
  
    
## equal<sup>(deprecated)</sup>    
判断两个WantAgent实例是否相等（callback形式）,以此来判断是否是来自同一应用的相同操作。  
 **调用形式：**     
- equal(agent: WantAgent, otherAgent: WantAgent, callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.wantAgent/wantAgent#equal。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| agent<sup>(deprecated)</sup> | WantAgent | true | WantAgent对象。 |  
| otherAgent<sup>(deprecated)</sup> | WantAgent | true | WantAgent对象。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 判断两个WantAgent实例是否相等的回调方法。 |  
    
 **示例代码：**   
```ts    
import WantAgent, { WantAgent as _WantAgent} from '@ohos.wantAgent';  
import { BusinessError } from '@ohos.base';  
  
//wantAgent对象  
let wantAgent1: _WantAgent;  
let wantAgent2: _WantAgent;  
  
//getWantAgent回调  
function getWantAgentCallback(err: BusinessError, data: _WantAgent) {  
	console.info('==========================>getWantAgentCallback=======================>');  
    if (err.code == 0) {  
    	wantAgent1 = data;  
        wantAgent2 = data;  
    } else {  
        console.error('getWantAgent failed, error: ' + JSON.stringify(err));  
        return;  
    }  
  
    //equal回调  
    let equalCallback = (err: BusinessError, data: boolean) => {  
        console.info('==========================>equalCallback=======================>');  
    }  
    WantAgent.equal(wantAgent1, wantAgent2, equalCallback)  
}  
  
WantAgent.getWantAgent({  
    wants: [  
        {  
            deviceId: 'deviceId',  
            bundleName: 'com.neu.setResultOnAbilityResultTest1',  
            abilityName: 'com.example.test.EntryAbility',  
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
        }  
    ],  
    operationType: WantAgent.OperationType.START_ABILITIES,  
    requestCode: 0,  
    wantAgentFlags:[WantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]  
}, getWantAgentCallback)  
    
```    
  
    
## equal<sup>(deprecated)</sup>    
判断两个WantAgent实例是否相等（Promise形式）,以此来判断是否是来自同一应用的相同操作。  
 **调用形式：**     
- equal(agent: WantAgent, otherAgent: WantAgent): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.wantAgent/wantAgent#equal。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| agent<sup>(deprecated)</sup> | WantAgent | true | WantAgent对象。 |  
| otherAgent<sup>(deprecated)</sup> | WantAgent | true | WantAgent对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | 以Promise形式返回获取判断两个WantAgent实例是否相等的结果。 |  
    
 **示例代码：**   
```ts    
import WantAgent, { WantAgent as _WantAgent} from '@ohos.wantAgent';  
import { BusinessError } from '@ohos.base';  
  
  
//wantAgent对象  
let wantAgent1: _WantAgent;  
let wantAgent2: _WantAgent;  
  
WantAgent.getWantAgent({  
    wants: [  
        {  
            deviceId: 'deviceId',  
            bundleName: 'com.neu.setResultOnAbilityResultTest1',  
            abilityName: 'com.example.test.EntryAbility',  
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
        }  
    ],  
    operationType: WantAgent.OperationType.START_ABILITIES,  
    requestCode: 0,  
    wantAgentFlags:[WantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]  
}).then((data) => {  
	console.info('==========================>getWantAgentCallback=======================>');  
    wantAgent1 = data;  
    wantAgent2 = data;  
    if (data) {  
        WantAgent.equal(wantAgent1, wantAgent2).then((data) => {  
            console.info('==========================>equalCallback=======================>');  
        });  
    }  
});  
    
```    
  
    
## getWantAgent<sup>(deprecated)</sup>    
创建WantAgent（callback形式）。 创建失败返回的WantAgent为空值。  
 **调用形式：**     
- getWantAgent(info: WantAgentInfo, callback: AsyncCallback\<WantAgent>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.wantAgent/wantAgent#getWantAgent。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| info<sup>(deprecated)</sup> | WantAgentInfo | true | WantAgent信息。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<WantAgent> | true | 创建WantAgent的回调方法。 |  
    
 **示例代码：**   
```ts    
import WantAgent, { WantAgent as _WantAgent} from '@ohos.wantAgent';  
import { BusinessError } from '@ohos.base';  
  
//getWantAgent回调  
function getWantAgentCallback(err: BusinessError, data: _WantAgent) {  
    if (err.code) {  
        console.info('getWantAgent Callback err:' + JSON.stringify(err))  
    } else {   
        console.info('getWantAgent Callback success')  
    }  
}  
  
WantAgent.getWantAgent({  
    wants: [  
        {  
            deviceId: 'deviceId',  
            bundleName: 'com.neu.setResultOnAbilityResultTest1',  
            abilityName: 'com.example.test.EntryAbility',  
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
        }  
    ],  
    operationType: WantAgent.OperationType.START_ABILITIES,  
    requestCode: 0,  
    wantAgentFlags:[WantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]  
}, getWantAgentCallback);  
    
```    
  
    
## getWantAgent<sup>(deprecated)</sup>    
创建WantAgent（Promise形式）。 创建失败返回的WantAgent为空值。  
 **调用形式：**     
- getWantAgent(info: WantAgentInfo): Promise\<WantAgent>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.wantAgent/wantAgent#getWantAgent。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| info<sup>(deprecated)</sup> | WantAgentInfo | true | WantAgent信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<WantAgent> | WantAgent信息。 |  
    
 **示例代码：**   
```ts    
import WantAgent, { WantAgent as _WantAgent} from '@ohos.wantAgent';  
WantAgent.getWantAgent({    wants: [        {            deviceId: 'deviceId',            bundleName: 'com.neu.setResultOnAbilityResultTest1',            abilityName: 'com.example.test.EntryAbility',            action: 'action1',            entities: ['entity1'],            type: 'MIMETYPE',            uri: 'key={true,true,false}',            parameters:            {                mykey0: 2222,                mykey1: [1, 2, 3],                mykey2: '[1, 2, 3]',                mykey3: 'ssssssssssssssssssssssssss',                mykey4: [false, true, false],                mykey5: ['qqqqq', 'wwwwww', 'aaaaaaaaaaaaaaaaa'],                mykey6: true,            }        }    ],    operationType: WantAgent.OperationType.START_ABILITIES,    requestCode: 0,    wantAgentFlags:[WantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]}).then((data: _WantAgent) => {console.info('==========================>getWantAgentCallback=======================>');});    
```    
  
    
## WantAgentFlags<sup>(deprecated)</sup>    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.wantAgent/wantAgent#WantAgentFlags替代。    
    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| ONE_TIME_FLAG<sup>(deprecated)</sup> | 0 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.wantAgent/wantAgent.WantAgentFlags#ONE_TIME_FLAG替代。<br>WantAgent仅能使用一次。 |  
| NO_BUILD_FLAG<sup>(deprecated)</sup> | 1 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.wantAgent/wantAgent.WantAgentFlags#NO_BUILD_FLAG替代。<br>如果说明WantAgent对象不存在，则不创建它，直接返回null。 |  
| CANCEL_PRESENT_FLAG<sup>(deprecated)</sup> | 2 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.wantAgent/wantAgent.WantAgentFlags#CANCEL_PRESENT_FLAG替代。<br>在生成一个新的WantAgent对象前取消已存在的一个WantAgent对象。 |  
| UPDATE_PRESENT_FLAG<sup>(deprecated)</sup> | 3 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.wantAgent/wantAgent.WantAgentFlags#UPDATE_PRESENT_FLAG替代。<br>使用新的WantAgent的额外数据替换已存在的WantAgent中的额外数据。 |  
| CONSTANT_FLAG<sup>(deprecated)</sup> | 4 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.wantAgent/wantAgent.WantAgentFlags#CONSTANT_FLAG替代。<br>WantAgent是不可变的。 |  
| REPLACE_ELEMENT<sup>(deprecated)</sup> | 5 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.wantAgent/wantAgent.WantAgentFlags#REPLACE_ELEMENT替代。<br>当前Want中的element属性可被WantAgent.trigger()中Want的element属性取代 |  
| REPLACE_ACTION<sup>(deprecated)</sup> | 6 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.wantAgent/wantAgent.WantAgentFlags#REPLACE_ACTION替代。<br>当前Want中的action属性可被WantAgent.trigger()中Want的action属性取代 |  
| REPLACE_URI<sup>(deprecated)</sup> | 7 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.wantAgent/wantAgent.WantAgentFlags#REPLACE_URI替代。<br>当前Want中的uri属性可被WantAgent.trigger()中Want的uri属性取代 |  
| REPLACE_ENTITIES<sup>(deprecated)</sup> | 8 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.wantAgent/wantAgent.WantAgentFlags#REPLACE_ENTITIES替代。<br>当前Want中的entities属性可被WantAgent.trigger()中Want的entities属性取代 |  
| REPLACE_BUNDLE<sup>(deprecated)</sup> | 9 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.wantAgent/wantAgent.WantAgentFlags#REPLACE_BUNDLE替代。<br>当前Want中的bundleName属性可被WantAgent.trigger()中Want的bundleName属性取代 |  
    
## OperationType<sup>(deprecated)</sup>    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.wantAgent/wantAgent#OperationType替代。    
    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| UNKNOWN_TYPE<sup>(deprecated)</sup> | 0 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.wantAgent/wantAgent.OperationType#UNKNOWN_TYPE替代。<br>不识别的类型。 |  
| START_ABILITY<sup>(deprecated)</sup> | 1 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.wantAgent/wantAgent.OperationType#START_ABILITY替代。<br>开启一个有页面的Ability。 |  
| START_ABILITIES<sup>(deprecated)</sup> | 2 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.wantAgent/wantAgent.OperationType#START_ABILITIES替代。<br>开启多个有页面的Ability。 |  
| START_SERVICE<sup>(deprecated)</sup> | 3 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.wantAgent/wantAgent.OperationType#START_SERVICE替代。<br>开启一个无页面的ability。 |  
| SEND_COMMON_EVENT<sup>(deprecated)</sup> | 4 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.wantAgent/wantAgent.OperationType#SEND_COMMON_EVENT替代。<br>发送一个公共事件。 |  
    
## CompleteData<sup>(deprecated)</sup>    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.wantAgent/wantAgent#CompleteData替代。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### 属性    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| info<sup>(deprecated)</sup> | WantAgent | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.wantAgent/wantAgent.CompleteData#info替代。<br>触发的wantAgent。 |  
| want<sup>(deprecated)</sup> | Want | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.wantAgent/wantAgent.CompleteData#want替代。<br>存在的被触发的want。 |  
| finalCode<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.wantAgent/wantAgent.CompleteData#finalCode替代。<br>触发wantAgent的请求代码。 |  
| finalData<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.wantAgent/wantAgent.CompleteData#finalData替代。<br>公共事件收集的最终数据。 |  
| extraInfo<sup>(deprecated)</sup> | object | false | false | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.wantAgent/wantAgent.CompleteData#extraInfo替代。<br>额外数据。 |  
    
## WantAgent    
WantAgent模块提供了创建WantAgent实例、获取实例的用户ID、获取want信息、比较WantAgent实例和获取bundle名称等能力。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
