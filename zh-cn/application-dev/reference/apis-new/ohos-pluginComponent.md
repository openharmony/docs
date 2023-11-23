# @ohos.pluginComponent    
用于给插件组件的使用者请求组件与数据，使用者发送组件模板和数据。如需实现插件模板的显示，请参考[PluginComponent](../arkui-ts/ts-basic-components-plugincomponent.md)。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import pluginComponentManager from '@ohos.pluginComponent'    
```  
    
## PluginComponentTemplate    
Plugin组件模板参数。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| source | string | false | true | 组件模板名。 |  
| ability | string | false | true | 提供者Ability的bundleName。 |  
    
## KVObject    
以键值对形式存储信息，符合json格式。    
## PushParameters    
用于设置FA模型下使用PluginManager.Push方法时候的需要传递的参数  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| want | Want | false | true | 组件使用者Ability信息。 |  
| name | string | false | true | 组件名称。 |  
| data | KVObject | false | true | 组件数据值。 |  
| extraData | KVObject | false | true | 附加数据值。 |  
| jsonPath | string | false | false | 存放模板路径的[external.json](#externaljson文件说明)件的路径。 |  
    
## RequestParameters    
用于设置FA模型下使用PluginManager.Request方法时候的需要传递的参数。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| want | Want | false | true | 组件提供者Ability信息。   |  
| name | string | false | true | 请求组件名称。 |  
| data | KVObject | false | true |  附加数据。  |  
| jsonPath | string | false | false | 存放模板路径的[external.json](#externaljson文件说明)文件的路径。jsonPath字段不为空或者未设置的时候不触发Request通信。 |  
    
## RequestCallbackParameters    
PluginManager.Request方法时候接收到的回调结果。  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| componentTemplate | PluginComponentTemplate | false | true | 组件模板。 |  
| data | KVObject | false | true | 组件数据。 |  
| extraData | KVObject | false | true | 附加数据。 |  
    
## RequestEventResult    
注册Request监听方法后，接受到的请求事件时候回应请求的数据类型。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| template | string | false | false | 组件模板。  |  
| data | KVObject | false | false | 组件数据。 |  
| extraData | KVObject | false | false | 附加数据。 |  
    
## OnPushEventCallback    
对应Push事件的监听回调函数。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
## OnRequestEventCallback    
对应request事件的监听回调函数。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
## push    
组件提供者向组件使用者主动发送组件与数据  
 **调用形式：**     
    
- push(param: PushParameters, callback: AsyncCallback\<void>): void    
起始版本： 8  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| param | PushParameters | true | 组件使用者的详细信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 此次接口调用的异步回调。 |  
    
 **示例代码：**   
    
## request    
组件使用者向组件提供者主动请求组件。  
 **调用形式：**     
    
- request(param: RequestParameters, callback: AsyncCallback\<RequestCallbackParameters>): void    
起始版本： 8  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| param | RequestParameters | true | 组件模板的详细请求信息。   |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 此次请求的异步回调，通过回调接口的参数返回接受请求的数据。 |  
    
## on    
提供者监听"request"类型的事件，给使用者返回通过request接口主动请求的数据；使用者监听"push"类型的事件，接收提供者通过push接口主动推送的数据。  
 **调用形式：**     
    
- on(eventType: string, callback: OnPushEventCallback | OnRequestEventCallback): void    
起始版本： 8  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| eventType | string | true | 监听的事件类型，可选值为："push"、"request"。<br/>"push”：指组件提供者向使用者主动推送数据。<br/>"request”：指组件使用者向提供者主动请求数据。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 对应监听回调，push事件对应回调类型为[OnPushEventCallback](#onpusheventcallback)，request事件对应回调类型为[OnRequestEventCallback] |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import pluginComponentManager from '@ohos.pluginComponent'import Want from '@ohos.app.ability.Want';function onPushListener(source:Want, template:PluginComponentTemplate, data:pluginComponentManager.KVObject, extraData:pluginComponentManager.KVObject) {  console.log("onPushListener template.source=" + template.source)  console.log("onPushListener source=" + JSON.stringify(source))  console.log("onPushListener template=" + JSON.stringify(template))  console.log("onPushListener data=" + JSON.stringify(data))  console.log("onPushListener extraData=" + JSON.stringify(extraData))}function onRequestListener(source:Want, name:string, data:pluginComponentManager.KVObject) {  console.error("onRequestListener");  console.log("onRequestListener source=" + JSON.stringify(source));  console.log("onRequestListener name=" + name);  console.log("onRequestListener data=" + JSON.stringify(data));  let RtnData:Record<string,string|pluginComponentManager.KVObject> = { 'template': "ets/pages/plugin.js", 'data': data }  return RtnData;}pluginComponentManager.on("push", onPushListener)pluginComponentManager.on("request", onRequestListener)    
```    
  
