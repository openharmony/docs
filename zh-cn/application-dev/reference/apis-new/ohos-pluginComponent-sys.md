# @ohos.pluginComponent    
用于给插件组件的使用者请求组件与数据，使用者发送组件模板和数据。如需实现插件模板的显示，请参考[PluginComponent](../arkui-ts/ts-basic-components-plugincomponent.md)。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import pluginComponentManager from '@ohos.pluginComponent'    
```  
    
## PushParameterForStage<sup>(9+)</sup>    
用于设置Stage模型下使用PluginManager.Push方法时候的需要传递的参数。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
## RequestParameterForStage<sup>(9+)</sup>    
用于设置Stage模型下使用PluginManager.Request方法时候的需要传递的参数。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
## push<sup>(9+)</sup>    
组件提供者向组件使用者主动发送组件与数据。  
 **调用形式：**     
    
- push(param: PushParameterForStage, callback: AsyncCallback\<void>): void    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| param | PushParameterForStage | true | 组件使用者的详细信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 此次接口调用的异步回调。 |  
    
 **示例代码：**   
```ts    
import pluginComponentManager from '@ohos.pluginComponent'pluginComponentManager.push({owner: {bundleName: "com.example.provider",abilityName: "com.example.provider.MainAbility"},target: {bundleName: "com.example.provider",abilityName: "com.example.provider.MainAbility",},name: "ets/pages/plugin2.js",data: {"js": "ets/pages/plugin.js","key_1": 1111,},extraData: {"extra_str": "this is push event"},jsonPath: "",},(err, data) => {console.log("push_callback:err: ", JSON.stringify(err));console.log("push_callback:data: ", JSON.stringify(data));console.log("push_callback: push ok!");})    
```    
  
    
## request<sup>(9+)</sup>    
组件使用者向组件提供者主动请求组件。  
 **调用形式：**     
    
- request(param: RequestParameterForStage, callback: AsyncCallback\<RequestCallbackParameters>): void    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| param | RequestParameterForStage | true | 组件模板的详细请求信息。     |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 此次请求的异步回调，通过回调接口的参数返回接受请求的数据。 |  
    
 **示例代码：**   
```ts    
import pluginComponentManager from '@ohos.pluginComponent'pluginComponentManager.request(  {    owner: {      bundleName: "com.example.provider",      abilityName: "com.example.provider.MainAbility"    },    target: {      bundleName: "com.example.provider",      abilityName: "ets/pages/plugin2.js",    },    name: "plugintemplate",    data: {      "key_1": " myapplication plugin component test",    },    jsonPath: "",  },  (err, data) => {    console.log("request_callback: componentTemplate.ability=" + data.componentTemplate.ability)    console.log("request_callback: componentTemplate.source=" + data.componentTemplate.source)  })    
```    
  
