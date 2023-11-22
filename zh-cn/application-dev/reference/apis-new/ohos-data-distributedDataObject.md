# @ohos.data.distributedDataObject    
本模块提供管理基本数据对象的相关能力，包括创建、查询、删除、修改、订阅等；同时支持相同应用多设备间的分布式数据对象协同能力。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import distributedDataObject from '@ohos.data.distributedDataObject'    
```  
    
## createDistributedObject<sup>(deprecated)</sup>    
创建一个分布式数据对象。  
 **调用形式：**     
- createDistributedObject(source: object): DistributedObject  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.distributedDataObject.create。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataObject.DistributedObject    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| source<sup>(deprecated)</sup> | object | true | 设置分布式数据对象的属性。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DistributedObject | 创建完成的分布式数据对象。 |  
    
 **示例代码：**   
```ts    
import distributedObject from '@ohos.data.distributedDataObject';  
class SourceObject {  
    name: string  
    age: number  
    isVis: boolean  
  
    constructor(name: string, age: number, isVis: boolean) {  
        this.name = name  
        this.age = age  
        this.isVis = isVis  
    }  
}  
  
let source: SourceObject = new SourceObject("amy", 18, false);  
let g_object: distributedObject.DistributedObject = distributedObject.createDistributedObject(source);  
    
```    
  
    
## create<sup>(9+)</sup>    
创建一个分布式数据对象。  
 **调用形式：**     
- create(context: Context, source: object): DataObject  
  
 **系统能力:**  SystemCapability.DistributedDataManager.DataObject.DistributedObject    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context | Context | true | 应用的上下文。 <br>FA模型的应用Context定义见[Context](js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-inner-application-uiAbilityContext.md)。  |  
| source | object | true | 设置分布式数据对象的属性。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataObject | 创建完成的分布式数据对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
// 导入模块  
import distributedObject from '@ohos.data.distributedDataObject';  
import UIAbility from '@ohos.app.ability.UIAbility';  
import { BusinessError } from '@ohos.base';  
import window from '@ohos.window';  
  
let g_object: distributedObject.DataObject|null = null;  
class SourceObject {  
    name: string  
    age: number  
    isVis: boolean  
  
    constructor(name: string, age: number, isVis: boolean) {  
        this.name = name  
        this.age = age  
        this.isVis = isVis  
    }  
}  
  
class EntryAbility extends UIAbility {  
    onWindowStageCreate(windowStage: window.WindowStage) {  
        let source: SourceObject = new SourceObject("amy", 18, false);  
        let g_object: distributedObject.DataObject = distributedObject.create(this.context, source);  
    }  
}  
    
```    
  
    
## genSessionId    
随机创建一个sessionId。  
 **调用形式：**     
- genSessionId(): string  
  
 **系统能力:**  SystemCapability.DistributedDataManager.DataObject.DistributedObject    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 随机创建的sessionId。 |  
    
 **示例代码：**   
```ts    
import distributedObject from '@ohos.data.distributedDataObject';let sessionId: string = distributedObject.genSessionId();    
```    
  
    
## SaveSuccessResponse<sup>(9+)</sup>    
save接口回调信息。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataObject.DistributedObject    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.DataObject.DistributedObject    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| sessionId<sup>(9+)</sup> | string | false | true | 多设备协同的唯一标识。  |  
| version<sup>(9+)</sup> | number | false | true | 已保存对象的版本。  |  
| deviceId<sup>(9+)</sup> | string | false | true | 存储数据的设备号，标识需要保存对象的设备。默认为"local"，标识本地设备；可自定义设置其他标识设备的字符串。  |  
    
## RevokeSaveSuccessResponse<sup>(9+)</sup>    
revokeSave接口回调信息。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataObject.DistributedObject    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.DataObject.DistributedObject    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| sessionId<sup>(9+)</sup> | string | false | true | 多设备协同的唯一标识。  |  
    
## DistributedObject<sup>(deprecated)</sup>    
表示一个分布式数据对象。在使用以下接口前，需调用[createDistributedObject()](#distributedobjectcreatedistributedobjectdeprecated)获取DistributedObject对象。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.distributedDataObject.DataObject替代。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataObject.DistributedObject    
### setSessionId<sup>(deprecated)</sup>    
设置同步的sessionId，当可信组网中有多个设备时，多个设备间的对象如果设置为同一个sessionId，就能自动同步。  
 **调用形式：**     
- setSessionId(sessionId?: string): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.distributedDataObject.DataObject.setSessionId。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataObject.DistributedObject  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| sessionId<sup>(deprecated)</sup> | string | false | 分布式数据对象在可信组网中的标识ID。如果要退出分布式组网，设置为""或不设置均可。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：标识设置sessionId成功。 <br>false：标识设置sessionId失败。 |  
    
 **示例代码：**   
```ts    
// g_object加入分布式组网g_object.setSessionId(distributedObject.genSessionId(), ()=>{  console.info("join session");});// 退出分布式组网g_object.setSessionId(() => {  console.info("leave all session.");});    
```    
  
    
### on('change')<sup>(deprecated)</sup>    
监听分布式数据对象的变更。  
 **调用形式：**     
- on(type: 'change', callback: (sessionId: string, fields: Array\<string>) => void): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.distributedDataObject.DataObject.on。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataObject.DistributedObject    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 事件类型，固定为'change'，表示数据变更。  |  
| callback<sup>(deprecated)</sup> | (sessionId: string, fields: Array<string>) => void | true | 变更回调对象实例。<br>sessionId：标识变更对象的sessionId； <br>fields：标识对象变更的属性名。  |  
    
 **示例代码：**   
```ts    
import distributedObject from '@ohos.data.distributedDataObject';  
class SourceObject {  
    name: string  
    age: number  
    isVis: boolean  
  
    constructor(name: string, age: number, isVis: boolean) {  
        this.name = name  
        this.age = age  
        this.isVis = isVis  
    }  
}  
  
let source: SourceObject = new SourceObject("amy", 18, false);  
let g_object: distributedObject.DistributedObject = distributedObject.createDistributedObject(source);  
g_object.on("change", (sessionId: string, fields: Array<string>) => {  
    console.info("change" + sessionId);  
    if (fields != null  fields != undefined) {  
        for (let index: number = 0; index < fields.length; index++) {  
            console.info("changed !" + fields[index] + " " + g_object[fields[index]]);  
        }  
    }  
});  
    
```    
  
    
### off('change')<sup>(deprecated)</sup>    
当不再进行数据变更监听时，使用此接口删除对象的变更监听。  
 **调用形式：**     
- off(type: 'change', callback?: (sessionId: string, fields: Array\<string>) => void): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.distributedDataObject.DataObject.off。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataObject.DistributedObject    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 事件类型，固定为'change'，表示数据变更。  |  
| callback<sup>(deprecated)</sup> | (sessionId: string, fields: Array<string>) => void | false | 需要删除的数据变更回调，若不设置则删除该对象所有的数据变更回调。<br>sessionId：标识变更对象的sessionId； <br>fields：标识对象变更的属性名。  |  
    
 **示例代码：**   
```ts    
import distributedObject from '@ohos.data.distributedDataObject';  
class SourceObject {  
    name: string  
    age: number  
    isVis: boolean  
  
    constructor(name: string, age: number, isVis: boolean) {  
        this.name = name  
        this.age = age  
        this.isVis = isVis  
    }  
}  
  
let source: SourceObject = new SourceObject("amy", 18, false);  
let g_object: distributedObject.DistributedObject = distributedObject.createDistributedObject(source);  
// 删除数据变更回调changeCallback  
g_object.off("change", (sessionId: string, fields: Array<string>) => {  
    console.info("change" + sessionId);  
    if (fields != null  fields != undefined) {  
        for (let index: number = 0; index < fields.length; index++) {  
            console.info("changed !" + fields[index] + " " + g_object[fields[index]]);  
        }  
    }  
});  
// 删除所有的数据变更回调  
g_object.off("change");  
    
```    
  
    
### on('status')<sup>(deprecated)</sup>    
监听分布式数据对象的上下线。  
 **调用形式：**     
- on(      type: 'status',      callback: (sessionId: string, networkId: string, status: 'online' | 'offline' ) => void    ): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.distributedDataObject.DataObject.on。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataObject.DistributedObject    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 事件类型，固定为'status'，表示对象上下线。  |  
| callback<sup>(deprecated)</sup> | (sessionId: string, networkId: string, status: 'online' \| 'offline' ) => void | true | 监听上下线回调实例。<br>sessionId：标识变更对象的sessionId； <br>networkId：标识对象设备； <br>status：标识对象为'online'(上线)或'offline'(下线)的状态。  |  
    
 **示例代码：**   
```ts    
import distributedObject from '@ohos.data.distributedDataObject';  
class SourceObject {  
    name: string  
    age: number  
    isVis: boolean  
  
    constructor(name: string, age: number, isVis: boolean) {  
        this.name = name  
        this.age = age  
        this.isVis = isVis  
    }  
}  
  
let source: SourceObject = new SourceObject("amy", 18, false);  
let g_object: distributedObject.DistributedObject = distributedObject.createDistributedObject(source);  
  
g_object.on("status", (sessionId: string, networkId: string, status: 'online' | 'offline') => {  
    console.info("status changed " + sessionId + " " + status + " " + networkId);  
});  
    
```    
  
    
### off('status')<sup>(deprecated)</sup>    
当不再进行对象上下线监听时，使用此接口删除对象的上下线监听。  
 **调用形式：**     
- off(      type: 'status',      callback?: (sessionId: string, networkId: string, status: 'online' | 'offline' ) => void    ): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.distributedDataObject.DataObject.off。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataObject.DistributedObject    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 事件类型，固定为'status'，表示对象上下线。  |  
| callback<sup>(deprecated)</sup> | (sessionId: string, networkId: string, status: 'online' \| 'offline' ) => void | false | 需要删除的上下线回调，若不设置则删除该对象所有的上下线回调。<br>sessionId：标识变更对象的sessionId； <br>networkId：标识变更对象； <br>status：标识对象为'online'(上线)或'offline'(下线)的状态。  |  
    
 **示例代码：**   
```ts    
import distributedObject from '@ohos.data.distributedDataObject';  
class SourceObject {  
    name: string  
    age: number  
    isVis: boolean  
  
    constructor(name: string, age: number, isVis: boolean) {  
        this.name = name  
        this.age = age  
        this.isVis = isVis  
    }  
}  
  
let source: SourceObject = new SourceObject("amy", 18, false);  
let g_object: distributedObject.DistributedObject = distributedObject.createDistributedObject(source);  
// 删除上下线回调changeCallback  
g_object.off("status", (sessionId: string, networkId: string, status: 'online' | 'offline') => {  
    console.info("status changed " + sessionId + " " + status + " " + networkId);  
});  
// 删除所有的上下线回调  
g_object.off("status");  
    
```    
  
    
## DataObject<sup>(9+)</sup>    
表示一个分布式数据对象。在使用以下接口前，需调用[create()](#distributedobjectcreate9)获取DataObject对象。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataObject.DistributedObject    
### setSessionId    
设置同步的sessionId，当可信组网中有多个设备时，多个设备间的对象如果设置为同一个sessionId，就能自动同步。  
 **调用形式：**     
    
- setSessionId(sessionId: string, callback: AsyncCallback\<void>): void    
起始版本： 8    
- setSessionId(callback: AsyncCallback\<void>): void    
起始版本： 8    
- setSessionId(sessionId?: string): Promise\<void>    
起始版本： 8  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| sessionId | string | true | 分布式数据对象在可信组网中的标识ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 加入session的异步回调。 |  
| Promise<void> | Promise对象。 |  
    
 **示例代码1：**   
示例 （callback）：  
```ts    
// g_object加入分布式组网g_object.setSessionId(distributedObject.genSessionId(), ()=>{  console.info("join session");});// 退出分布式组网g_object.setSessionId(() => {  console.info("leave all session.");});    
```    
  
    
 **示例代码2：**   
```ts    
// g_object加入分布式组网g_object.setSessionId(distributedObject.genSessionId()).then (()=>{  console.info("join session.");  }).catch((error: BusinessError)=>{    console.info("error:" + error.code + error.message);});// 退出分布式组网g_object.setSessionId().then (()=>{  console.info("leave all session.");  }).catch((error: BusinessError)=>{    console.info("error:" + error.code + error.message);});    
```    
  
    
### on('change')<sup>(9+)</sup>    
监听分布式数据对象的数据变更。  
 **调用形式：**     
    
- on(type: 'change', callback: (sessionId: string, fields: Array\<string>) => void ): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.DistributedDataManager.DataObject.DistributedObject    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件类型，固定为'change'，表示数据变更。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
g_object.on("change", (sessionId: string, fields: Array<string>) => {  console.info("change" + sessionId);  if (fields != null  fields != undefined) {    for (let index: number = 0; index < fields.length; index++) {      console.info("changed !" + fields[index] + " " + g_object[fields[index]]);    }  }});    
```    
  
    
### off('change')<sup>(9+)</sup>  
 **调用形式：**     
    
- off(type: 'change', callback?: (sessionId: string, fields: Array\<string>) => void ): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.DistributedDataManager.DataObject.DistributedObject    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
// 删除数据变更回调changeCallbackg_object.off("change", (sessionId: string, fields: Array<string>) => {  console.info("change" + sessionId);  if (fields != null  fields != undefined) {    for (let index: number = 0; index < fields.length; index++) {      console.info("changed !" + fields[index] + " " + g_object[fields[index]]);    }  }});// 删除所有的数据变更回调g_object.off("change");    
```    
  
    
### on('status')<sup>(9+)</sup>  
 **调用形式：**     
    
- on(      type: 'status',      callback: (sessionId: string, networkId: string, status: 'online' | 'offline' ) => void    ): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.DistributedDataManager.DataObject.DistributedObject    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 变更回调对象实例。<br>sessionId：标识变更对象的sessionId； <br>fields：标识对象变更的属性名。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
g_object.on("status", (sessionId: string, networkId: string, status: 'online' | 'offline') => {  console.info("status changed " + sessionId + " " + status + " " + networkId);});    
```    
  
    
### off('status')<sup>(9+)</sup>    
当不再进行数据变更监听时，使用此接口删除对象的变更监听。  
 **调用形式：**     
    
- off(      type: 'status',      callback?: (sessionId: string, networkId: string, status: 'online' | 'offline' ) => void    ): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.DistributedDataManager.DataObject.DistributedObject    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件类型，固定为'change'，表示数据变更。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 需要删除的数据变更回调，若不设置则删除该对象所有的数据变更回调。<br>sessionId：标识变更对象的sessionId； <br>fields：标识对象变更的属性名。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
// 删除上下线回调changeCallbackg_object.off("status", (sessionId: string, networkId: string, status: 'online' | 'offline') => {  console.info("status changed " + sessionId + " " + status + " " + networkId);});// 删除所有的上下线回调g_object.off("status");    
```    
  
    
### save<sup>(9+)</sup>    
保存分布式数据对象。使用Promise方式作为异步回调。  对象数据保存成功后，当应用存在时不会释放对象数据，当应用退出后，重新进入应用时，恢复保存在设备上的数据。  有以下几种情况时，保存的数据将会被释放：  - 存储时间超过24小时。 - 应用卸载。 - 成功恢复数据之后。  
 **调用形式：**     
    
- save(deviceId: string, callback: AsyncCallback\<SaveSuccessResponse>): void    
起始版本： 9    
- save(deviceId: string): Promise\<SaveSuccessResponse>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.DistributedDataManager.DataObject.DistributedObject    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId | string | true | 保存数据的设备号，当deviceId默认为"local"，标识需要保存对象的设备。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<SaveSuccessResponse> | Promise对象。返回SaveSuccessResponse，包含sessionId、version、deviceId等信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
    
 **示例代码1：**   
示例 （callback）：  
```ts    
// 删除上下线回调changeCallbackg_object.off("status", (sessionId: string, networkId: string, status: 'online' | 'offline') => {  console.info("status changed " + sessionId + " " + status + " " + networkId);});// 删除所有的上下线回调g_object.off("status");    
```    
  
    
 **示例代码2：**   
示例 （promise）：  
```ts    
g_object.setSessionId("123456");g_object.save("local").then((result: distributedObject.SaveSuccessResponse) => {  console.info("save callback");  console.info("save sessionId " + result.sessionId);  console.info("save version " + result.version);  console.info("save deviceId " + result.deviceId);}).catch((err: BusinessError) => {  console.info("save failed, error code = " + err.code);  console.info("save failed, error message: " + err.message);});    
```    
  
    
### revokeSave<sup>(9+)</sup>    
撤回保存的分布式数据对象。使用callback方式作为异步方法。  如果对象保存在本地设备，那么将删除所有受信任设备上所保存的数据。 如果对象保存在其他设备，那么将删除本地设备上的数据。  
 **调用形式：**     
    
- revokeSave(callback: AsyncCallback\<RevokeSaveSuccessResponse>): void    
起始版本： 9    
- revokeSave(): Promise\<RevokeSaveSuccessResponse>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.DistributedDataManager.DataObject.DistributedObject    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回RevokeSaveSuccessResponse，包含sessionId。 |  
| Promise<RevokeSaveSuccessResponse> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
    
 **示例代码1：**   
示例 （callback）：  
```ts    
g_object.setSessionId("123456");// 持久化数据g_object.save("local", (err: BusinessError, result: distributedObject.SaveSuccessResponse) => {  if (err) {    console.info("save failed, error code = " + err.code);    console.info("save failed, error message: " + err.message);    return;  }  console.info("save callback");  console.info("save sessionId: " + result.sessionId);  console.info("save version: " + result.version);  console.info("save deviceId: " + result.deviceId);});// 删除持久化保存的数据g_object.revokeSave((err: BusinessError, result: distributedObject.RevokeSaveSuccessResponse) => {  if (err) {   console.info("revokeSave failed, error code = " + err.code);   console.info("revokeSave failed, error message: " + err.message);   return;  }  console.info("revokeSave callback");  console.info("revokeSave sessionId " + result.sessionId);});    
```    
  
    
 **示例代码2：**   
示例 （promise）：  
```ts    
g_object.setSessionId("123456");// 持久化数据g_object.save("local").then((result: distributedObject.SaveSuccessResponse) => {  console.info("save callback");  console.info("save sessionId " + result.sessionId);  console.info("save version " + result.version);  console.info("save deviceId " + result.deviceId);}).catch((err: BusinessError) => {  console.info("save failed, error code = " + err.code);  console.info("save failed, error message: " + err.message);});// 删除持久化保存的数据g_object.revokeSave().then((result: distributedObject.RevokeSaveSuccessResponse) => {  console.info("revokeSave callback");  console.info("sessionId" + result.sessionId);}).catch((err: BusinessError)=> {  console.info("revokeSave failed, error code = " + err.code);  console.info("revokeSave failed, error message = " + err.message);});    
```    
  
