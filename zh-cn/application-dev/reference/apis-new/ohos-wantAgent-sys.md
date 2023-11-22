# @ohos.wantAgent    
WantAgent模块提供了创建WantAgent实例、获取实例的用户ID、获取want信息、比较WantAgent实例和获取bundle名称等能力。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import wantAgent from '@ohos.wantAgent'    
```  
    
## getWant<sup>(deprecated)</sup>    
获取WantAgent中的Want(callback形式)。  
 **调用形式：**     
- getWant(agent: WantAgent, callback: AsyncCallback\<Want>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.wantAgent/wantAgent#getWant。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| agent<sup>(deprecated)</sup> | WantAgent | true | WantAgent信息。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Want> | true | 获取WantAgent中的Want的回调方法。 |  
    
 **示例代码：**   
```ts    
import WantAgent, { WantAgent as _WantAgent} from '@ohos.wantAgent';  
import Want from '@ohos.app.ability.Want';  
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
  
    //getWant回调  
    let getWantCallback = (err: BusinessError, data: Want) => {  
        console.info('==========================>getWantCallback=======================>');  
    }  
    WantAgent.getWant(wantAgent, getWantCallback);  
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
  
    
## getWant<sup>(deprecated)</sup>    
获取WantAgent中的Want(Promise形式)。  
 **调用形式：**     
- getWant(agent: WantAgent): Promise\<Want>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.wantAgent/wantAgent#getWant。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| agent<sup>(deprecated)</sup> | WantAgent | true | WantAgent信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Want> | 以Promise形式返回Want。 |  
    
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
        WantAgent.getWant(wantAgent).then((data) => {  
            console.info('==========================>getWantCallback=======================>');  
        });  
    }  
});  
    
```    
  
