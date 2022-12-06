# 分布式数据对象

本模块提供管理基本数据对象的相关能力，包括创建、查询、删除、修改、订阅等；同时支持相同应用多设备间的分布式数据对象协同能力。

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import distributedObject from '@ohos.data.distributedDataObject';
```

## distributedObject.create<sup>9+</sup>

create(context: Context, source: object): DistributedObjectV9

创建一个分布式数据对象。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | context | Context | 是 | 应用的上下文。 <br>FA模型的应用Context定义见[Context](js-apis-Context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-ability-context.md)。 |
  | source | object | 是 | 设置分布式数据对象的属性。 |
  
**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [DistributedObjectV9](#distributedobjectv9) | 创建完成的分布式数据对象。 |

**示例：**

FA模型示例：

```js
// 导入模块
import distributedObject from '@ohos.data.distributedDataObject';
import featureAbility from '@ohos.ability.featureAbility';
// 获取context
let context = featureAbility.getContext();
// 创建对象，该对象包含4个属性类型，string,number,boolean和Object
let g_object = distributedObject.create(context, {name:"Amy", age:18, isVis:false, parent:{mother:"jack mom",father:"jack Dad"}});
```

Stage模型示例：

```ts
// 导入模块
import distributedObject from '@ohos.data.distributedDataObject';
import Ability from '@ohos.application.Ability';
// 获取context
let context;
class MainAbility extends Ability{
    onWindowStageCreate(windowStage){
        context = this.context
    }
}
// 创建对象，该对象包含4个属性类型，string,number,boolean和Object
let g_object = distributedObject.create(context, {name:"Amy", age:18, isVis:false, parent:{mother:"jack mom",father:"jack Dad"}});
```

## distributedObject.genSessionId

genSessionId(): string

随机创建一个sessionId。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | string | 随机创建的sessionId。 |

**示例：**

```js
import distributedObject from '@ohos.data.distributedDataObject';
let sessionId = distributedObject.genSessionId();
```

## SaveSuccessResponse<sup>9+</sup>

save接口回调信息。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

| 名称 | 类型 | 说明 |
| -------- | -------- | -------- |
| sessionId | string | 多设备协同的唯一标识。 |
| version | number |已保存对象的版本。 |
| deviceId | string | 存储数据的设备号，标识需要保存对象的设备。默认为"local"，标识本地设备；可自定义设置其他标识设备的字符串。 |

## RevokeSaveSuccessResponse<sup>9+</sup>

revokeSave接口回调信息。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

| 名称 | 类型 | 说明 |
| -------- | -------- | -------- |
| sessionId | string | 多设备协同的唯一标识。 |

## DistributedObjectV9

表示一个分布式数据对象。

### setSessionId<sup>9+</sup>

setSessionId(sessionId: string, callback: AsyncCallback&lt;void&gt;): void

设置同步的sessionId，当可信组网中有多个设备时，多个设备间的对象如果设置为同一个sessionId，就能自动同步。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | sessionId | string | 是 | 分布式数据对象在可信组网中的标识ID。|
  | callback | AsyncCallback&lt;void&gt; | 是 | 加入session的异步回调。|

**错误码：**

  以下错误码的详细介绍参见[分布式数据对象错误码](../errorcodes/errorcode-distributed-dataObject.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 15400001 | 创建内存数据库失败。|

**示例：**

FA模型示例

```js
import distributedObject from '@ohos.data.distributedDataObject';
import featureAbility from '@ohos.ability.featureAbility';
// 获取context
let context = featureAbility.getContext();
let g_object = distributedObject.create(context, {name:"Amy", age:18, isVis:false, parent:{mother:"jack mom",father:"jack Dad"}});
// g_object加入分布式组网
g_object.setSessionId(distributedObject.genSessionId(), ()=>{
    console.log("join session");
});
```
Stage模型示例

```ts
import distributedObject from '@ohos.data.distributedDataObject';
import Ability from '@ohos.application.Ability';
// 获取context
let context;
class MainAbility extends Ability{
    onWindowStageCreate(windowStage){
        context = this.context
    }
}
let g_object = distributedObject.create(context, {name:"Amy", age:18, isVis:false, parent:{mother:"jack mom",father:"jack Dad"}});
// g_object加入分布式组网
g_object.setSessionId(distributedObject.genSessionId(), ()=>{
    console.log("join session");
});
```

### setSessionId<sup>9+</sup>

setSessionId(callback: AsyncCallback&lt;void&gt;): void

退出所有已加入的session。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | 是 | 退出所有已加入session的异步回调。 |

**错误码：**

  以下错误码的详细介绍参见[分布式数据对象错误码](../errorcodes/errorcode-distributed-dataObject.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 15400001 | 创建内存数据库失败。|

**示例：**

FA模型示例

```js
import distributedObject from '@ohos.data.distributedDataObject';
import featureAbility from '@ohos.ability.featureAbility';
// 获取context
let context = featureAbility.getContext();
let g_object = distributedObject.create(context, {name:"Amy", age:18, isVis:false, parent:{mother:"jack mom",father:"jack Dad"}});
// g_object加入分布式组网
g_object.setSessionId(distributedObject.genSessionId(), ()=>{
    console.log("join session");
});
// 退出分布式组网
g_object.setSessionId(() => {
    console.log("leave all lession.");
});
```
Stage模型示例

```ts
import distributedObject from '@ohos.data.distributedDataObject';
import Ability from '@ohos.application.Ability';
// 获取context
let context;
class MainAbility extends Ability{
    onWindowStageCreate(windowStage){
        context = this.context
    }
}
let g_object = distributedObject.create(context, {name:"Amy", age:18, isVis:false, parent:{mother:"jack mom",father:"jack Dad"}});
// g_object加入分布式组网
g_object.setSessionId(distributedObject.genSessionId(), ()=>{
    console.log("join session");
});
// 退出分布式组网
g_object.setSessionId(() => {
    console.log("leave all lession.");
});
```

### setSessionId<sup>9+</sup>

setSessionId(sessionId?: string): Promise&lt;void&gt;

设置同步的sessionId，当可信组网中有多个设备时，多个设备间的对象如果设置为同一个sessionId，就能自动同步。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | sessionId | string | 否 | 分布式数据对象在可信组网中的标识ID。如果要退出分布式组网，设置为""或不设置均可。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。|

**错误码：**

  以下错误码的详细介绍参见[分布式数据对象错误码](../errorcodes/errorcode-distributed-dataObject.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 15400001 | 创建内存数据库失败。|

**示例：**

FA模型示例

```js
import distributedObject from '@ohos.data.distributedDataObject';
import featureAbility from '@ohos.ability.featureAbility';
// 获取context
let context = featureAbility.getContext();
let g_object = distributedObject.create(context, {name:"Amy", age:18, isVis:false, parent:{mother:"jack mom",father:"jack Dad"}});
// g_object加入分布式组网
g_object.setSessionId(distributedObject.genSessionId()).then (()=>{
    console.log("join session.");
    }).catch((error)=>{
        console.info("error:" + error.code + error.message);
});
// 退出分布式组网
g_object.setSessionId().then (()=>{
    console.log("leave all lession.");
    }).catch((error)=>{
        console.info("error:" + error.code + error.message);
});
```
Stage模型示例

```ts
import distributedObject from '@ohos.data.distributedDataObject';
import Ability from '@ohos.application.Ability';
// 获取context
let context;
class MainAbility extends Ability{
    onWindowStageCreate(windowStage){
        context = this.context
    }
}
let g_object = distributedObject.create(context, {name:"Amy", age:18, isVis:false, parent:{mother:"jack mom",father:"jack Dad"}});
// g_object加入分布式组网
g_object.setSessionId(distributedObject.genSessionId()).then (()=>{
    console.info("join session.");
    }).catch((error)=>{
        console.info("error:" + error.code + error.message);
});
// 退出分布式组网
g_object.setSessionId().then (()=>{
    console.log("leave all lession.");
    }).catch((error)=>{
        console.info("error:" + error.code + error.message);
});
```

### on('change')<sup>9+</sup>

on(type: 'change', callback: Callback<{ sessionId: string, fields: Array&lt;string&gt; }>): void

监听分布式数据对象的数据变更。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 事件类型，固定为'change'，表示数据变更。 |
  | callback | Callback<{ sessionId: string, fields: Array&lt;string&gt; }> | 是 | 变更回调对象实例。<br>sessionId：标识变更对象的sessionId； <br>fields：标识对象变更的属性名。 |

**示例：**

FA模型示例

```js
import distributedObject from '@ohos.data.distributedDataObject';
import featureAbility from '@ohos.ability.featureAbility';
// 获取context
let context = featureAbility.getContext();
let g_object = distributedObject.create(context, {name:"Amy", age:18, isVis:false, parent:{mother:"jack mom",father:"jack Dad"}});
globalThis.changeCallback = (sessionId, changeData) => {
    console.info("change" + sessionId);
    if (changeData != null && changeData != undefined) {
        changeData.forEach(element => {
        console.info("changed !" + element + " " + g_object[element]);
        });
    }
}
g_object.on("change", globalThis.changeCallback);
```

Stage模型示例

```ts
import distributedObject from '@ohos.data.distributedDataObject';
import Ability from '@ohos.application.Ability';
// 获取context
let context;
class MainAbility extends Ability{
    onWindowStageCreate(windowStage){
        context = this.context
    }
}
let g_object = distributedObject.create(context, {name:"Amy", age:18, isVis:false, parent:{mother:"jack mom",father:"jack Dad"}});
globalThis.changeCallback = (sessionId, changeData) => {
    console.info("change" + sessionId);
    if (changeData != null && changeData != undefined) {
        changeData.forEach(element => {
        console.info("changed !" + element + " " + g_object[element]);
        });
    }
}
g_object.on("change", globalThis.changeCallback);
```

### off('change')<sup>9+</sup>

off(type: 'change', callback?: Callback<{ sessionId: string, fields: Array&lt;string&gt; }>): void

当不再进行数据变更监听时，使用此接口删除对象的变更监听。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 事件类型，固定为'change'，表示数据变更。 |
  | callback | Callback<{ sessionId: string, fields: Array&lt;string&gt; }> | 否 | 需要删除的数据变更回调，若不设置则删除该对象所有的数据变更回调。<br>sessionId：标识变更对象的sessionId； <br>fields：标识对象变更的属性名。 |


**示例：**

FA模型示例

```js
import distributedObject from '@ohos.data.distributedDataObject';
import featureAbility from '@ohos.ability.featureAbility';
// 获取context
let context = featureAbility.getContext();
let g_object = distributedObject.create(context, {name:"Amy", age:18, isVis:false, parent:{mother:"jack mom",father:"jack Dad"}});
// 删除数据变更回调changeCallback
g_object.off("change", globalThis.changeCallback);
// 删除所有的数据变更回调
g_object.off("change");
```

Stage模型示例

```ts
import distributedObject from '@ohos.data.distributedDataObject';
import Ability from '@ohos.application.Ability';
// 获取context
let context;
class MainAbility extends Ability{
    onWindowStageCreate(windowStage){
        context = this.context
    }
}
let g_object = distributedObject.create(context, {name:"Amy", age:18, isVis:false, parent:{mother:"jack mom",father:"jack Dad"}});
// 删除数据变更回调changeCallback
g_object.off("change", globalThis.changeCallback);
// 删除所有的数据变更回调
g_object.off("change");
```

### on('status')<sup>9+</sup>

on(type: 'status', callback: Callback<{ sessionId: string, networkId: string, status: 'online' | 'offline' }>): void

监听分布式数据对象的上下线。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 事件类型，固定为'status'，表示对象上下线。 |
  | callback | Callback<{ sessionId: string, networkId: string, status: 'online' \| 'offline' }> | 是 | 监听上下线回调实例。<br>sessionId：标识变更对象的sessionId； <br>networkId：标识对象设备，即deviceId； <br>status：标识对象为'online'(上线)或'offline'(下线)的状态。 |

**示例：**

FA模型示例

```js
import distributedObject from '@ohos.data.distributedDataObject';
import featureAbility from '@ohos.ability.featureAbility';
// 获取context
let context = featureAbility.getContext();
globalThis.statusCallback = (sessionId, networkId, status) => {
    globalThis.response += "status changed " + sessionId + " " + status + " " + networkId;
}
let g_object = distributedObject.create(context, {name:"Amy", age:18, isVis:false, parent:{mother:"jack mom",father:"jack Dad"}});
g_object.on("status", globalThis.statusCallback);
```

Stage模型示例

```ts
import distributedObject from '@ohos.data.distributedDataObject';
import Ability from '@ohos.application.Ability';
// 获取context
let context;
class MainAbility extends Ability{
    onWindowStageCreate(windowStage){
        context = this.context
    }
}
globalThis.statusCallback = (sessionId, networkId, status) => {
    globalThis.response += "status changed " + sessionId + " " + status + " " + networkId;
}
let g_object = distributedObject.create(context, {name:"Amy", age:18, isVis:false, parent:{mother:"jack mom",father:"jack Dad"}});
g_object.on("status", globalThis.statusCallback);
```

### off('status')<sup>9+</sup>

off(type: 'status', callback?: Callback<{ sessionId: string, deviceId: string, status: 'online' | 'offline' }>): void

当不再进行对象上下线监听时，使用此接口删除对象的上下线监听。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 事件类型，固定为'status'，表示对象上下线。 |
  | callback | Callback<{ sessionId: string, deviceId: string, status: 'online' \| 'offline' }> | 否 | 需要删除的上下线回调，若不设置则删除该对象所有的上下线回调。<br>sessionId：标识变更对象的sessionId； <br>deviceId：标识变更对象的deviceId； <br>status：标识对象为'online'(上线)或'offline'(下线)的状态。 |


**示例：**

FA模型示例

```js
import distributedObject from '@ohos.data.distributedDataObject'; 
import featureAbility from '@ohos.ability.featureAbility';
// 获取context
let context = featureAbility.getContext();
let g_object = distributedObject.create(context, {name:"Amy", age:18, isVis:false, parent:{mother:"jack mom",father:"jack Dad"}});
globalThis.statusCallback = (sessionId, networkId, status) => {
    globalThis.response += "status changed " + sessionId + " " + status + " " + networkId;
}
// 删除上下线回调changeCallback
g_object.off("status",globalThis.statusCallback);
// 删除所有的上下线回调
g_object.off("status");
```

Stage模型示例

```ts
import distributedObject from '@ohos.data.distributedDataObject'; 
import Ability from '@ohos.application.Ability';
// 获取context
let context;
class MainAbility extends Ability{
    onWindowStageCreate(windowStage){
        context = this.context
    }
}
let g_object = distributedObject.create(context, {name:"Amy", age:18, isVis:false, parent:{mother:"jack mom",father:"jack Dad"}});
globalThis.statusCallback = (sessionId, networkId, status) => {
    globalThis.response += "status changed " + sessionId + " " + status + " " + networkId;
}
// 删除上下线回调changeCallback
g_object.off("status",globalThis.statusCallback);
// 删除所有的上下线回调
g_object.off("status");
```

### save<sup>9+</sup>

save(deviceId: string, callback: AsyncCallback&lt;SaveSuccessResponse&gt;): void

保存分布式数据对象。使用callback方式异步回调。

对象数据保存成功后，当应用存在时不会释放对象数据，当应用退出后，重新进入应用时，恢复保存在设备上的数据。

有以下几种情况时，保存的数据将会被释放：

- 存储时间超过24小时。
- 应用卸载。
- 成功恢复数据之后。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | deviceId | string | 是 | 保存数据的deviceId，当deviceId为"local"，代表存储在本地设备。 |
  | callback | AsyncCallback&lt;[SaveSuccessResponse](#savesuccessresponse9)&gt; | 是 | 回调函数。返回SaveSuccessResponse，包含sessionId、version、deviceId等信息。 |

**示例：**

FA模型示例
```ts
import distributedObject from '@ohos.data.distributedDataObject';
import featureAbility from '@ohos.ability.featureAbility';
// 获取context
let context = featureAbility.getContext();
let g_object = distributedObject.create(context, {name:"Amy", age:18, isVis:false});
g_object.setSessionId("123456");
g_object.save("local", (result) => {
    console.log("save callback");
    console.info("save sessionId: " + result.sessionId);
    console.info("save version: " + result.version);
    console.info("save deviceId:  " + result.deviceId);
});
```

Stage模型示例
```ts
import distributedObject from '@ohos.data.distributedDataObject';
import Ability from '@ohos.application.Ability';
// 获取context
let context;
class MainAbility extends Ability{
    onWindowStageCreate(windowStage){
        context = this.context
    }
}
let g_object = distributedObject.create(context, {name:"Amy", age:18, isVis:false});
g_object.setSessionId("123456");
g_object.save("local", (result) => {
    console.log("save callback");
    console.info("save sessionId: " + result.sessionId);
    console.info("save version: " + result.version);
    console.info("save deviceId:  " + result.deviceId);
});
```

### save<sup>9+</sup>

save(deviceId: string): Promise&lt;SaveSuccessResponse&gt;

保存分布式数据对象。使用Promise方式作为异步回调。

对象数据保存成功后，当应用存在时不会释放对象数据，当应用退出后，重新进入应用时，恢复保存在设备上的数据。

有以下几种情况时，保存的数据将会被释放：

- 存储时间超过24小时。
- 应用卸载。
- 成功恢复数据之后。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | deviceId | string | 是 | 保存数据的设备号，当deviceId默认为"local"，标识需要保存对象的设备。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[SaveSuccessResponse](#savesuccessresponse9)&gt; | Promise对象。返回SaveSuccessResponse，包含sessionId、version、deviceId等信息。|

**示例：**

```js
import distributedObject from '@ohos.data.distributedDataObject';
import featureAbility from '@ohos.ability.featureAbility';
// 获取context
let context = featureAbility.getContext();
let g_object = distributedObject.create(context,{name:"Amy", age:18, isVis:false});
g_object.setSessionId("123456");
g_object.save("local").then((result) => {
    console.log("save callback");
    console.info("save sessionId " + result.sessionId);
    console.info("save version " + result.version);
    console.info("save deviceId " + result.deviceId);
}, () => {
    console.error("save failed");
});
```

```js
import distributedObject from '@ohos.data.distributedDataObject';
import Ability from '@ohos.application.Ability';
// 获取context
let context;
class MainAbility extends Ability{
    onWindowStageCreate(windowStage){
        context = this.context
    }
}
let g_object = distributedObject.create(context,{name:"Amy", age:18, isVis:false});
g_object.setSessionId("123456");
g_object.save("local").then((result) => {
    console.log("save callback");
    console.info("save sessionId " + result.sessionId);
    console.info("save version " + result.version);
    console.info("save deviceId " + result.deviceId);
}, () => {
    console.error("save failed");
});
```

### revokeSave<sup>9+</sup>

revokeSave(callback: AsyncCallback&lt;RevokeSaveSuccessResponse&gt;): void

撤回保存的分布式数据对象。使用callback方式作为异步方法。

如果对象保存在本地设备，那么将删除所有受信任设备上所保存的数据。
如果对象保存在其他设备，那么将删除本地设备上的数据。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[RevokeSaveSuccessResponse](#revokesavesuccessresponse9)&gt; | 是 | 回调函数。返回RevokeSaveSuccessResponse，包含sessionId。 |

**示例：**

FA模型示例

```js
import distributedObject from '@ohos.data.distributedDataObject';
import featureAbility from '@ohos.ability.featureAbility';
// 获取context
let context = featureAbility.getContext();
let g_object = distributedObject.create(context, {name:"Amy", age:18, isVis:false});
g_object.setSessionId("123456");
// 持久化数据
g_object.save("local", (result) => {
    console.log("save callback");
    console.info("save sessionId " + result.sessionId);
    console.info("save version " + result.version);
    console.info("save deviceId " + result.deviceId);
});
// 删除持久化保存的数据
g_object.revokeSave((result) => {
  console.log("revokeSave callback");
  console.log("revokeSave sessionId " + result.sessionId);
});
```

Stage模型示例

```ts
import distributedObject from '@ohos.data.distributedDataObject';
import Ability from '@ohos.application.Ability';
// 获取context
let context;
class MainAbility extends Ability {
    onWindowStageCreate(windowStage) {
        context = this.context
    }
}
let g_object = distributedObject.create(context, {name:"Amy", age:18, isVis:false});
g_object.setSessionId("123456");
// 持久化数据
g_object.save("local", (result) => {
    console.log("save callback");
    console.info("save sessionId " + result.sessionId);
    console.info("save version " + result.version);
    console.info("save deviceId " + result.deviceId);
});
// 删除持久化保存的数据
g_object.revokeSave((result) => {
  console.log("revokeSave callback");
  console.log("revokeSave sessionId " + result.sessionId);
});
```

### revokeSave<sup>9+</sup>

revokeSave(): Promise&lt;RevokeSaveSuccessResponse&gt;

撤回保存的分布式数据对象。使用Promise方式作为异步方法。

如果对象保存在本地设备，那么将删除所有受信任设备上所保存的数据。
如果对象保存在其他设备，那么将删除本地设备上的数据。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[RevokeSaveSuccessResponse](#revokesavesuccessresponse9)&gt; | Promise对象。返回RevokeSaveSuccessResponse，包含sessionId。 |

**示例：**

FA模型示例

```ts
import distributedObject from '@ohos.data.distributedDataObject';
import featureAbility from '@ohos.ability.featureAbility';
// 获取context
let context = featureAbility.getContext();
let g_object = distributedObject.create(context, {name:"Amy", age:18, isVis:false});
g_object.setSessionId("123456");
// 持久化数据
g_object.save("local").then((result) => {
    console.log("save callback");
    console.info("save sessionId " + result.sessionId);
    console.info("save version " + result.version);
    console.info("save deviceId " + result.deviceId);
}, () => {
    console.error("save failed");
});
// 删除持久化保存的数据
g_object.revokeSave().then((result) => {
    console.log("revokeSave callback");
    console.log("sessionId" + result.sessionId);
}, () => {
    console.error("revokeSave failed");
});
```

Stage模型示例

```ts
import distributedObject from '@ohos.data.distributedDataObject';
import Ability from '@ohos.application.Ability';
// 获取context
let context;
class MainAbility extends Ability {
    onWindowStageCreate(windowStage) {
        context = this.context
    }
}
let g_object = distributedObject.create(context, {name:"Amy", age:18, isVis:false});
g_object.setSessionId("123456");
g_object.save("local").then((result) => {
    console.log("save callback");
    console.info("save sessionId " + result.sessionId);
    console.info("save version " + result.version);
    console.info("save deviceId " + result.deviceId);
}, () => {
    console.error("save failed");
});

// 删除持久化保存的数据
g_object.revokeSave().then((result) => {
    console.log("revokeSave callback");
    console.log("sessionId" + result.sessionId);
}, () => {
    console.error("revokeSave failed");
});
```

## distributedObject.createDistributedObject<sup>(deprecated)</sup>

createDistributedObject(source: object): DistributedObject


创建一个分布式数据对象。

> **说明：**
>
> 从 API Version 8 开始支持，从 API Version 9 开始废弃，建议使用distributedObject.create替代。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | source | object | 是 | 设置分布式数据对象的属性。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [DistributedObject](#distributedobjectdeprecated) | 创建完成的分布式数据对象。 |

**示例：**

```js
import distributedObject from '@ohos.data.distributedDataObject';
// 创建对象，对象包含4个属性类型，string,number,boolean和Object
let g_object = distributedObject.createDistributedObject({name:"Amy", age:18, isVis:false, parent:{mother:"jack mom",father:"jack Dad"}});
```

## DistributedObject<sup>(deprecated)</sup>

表示一个分布式数据对象。

### setSessionId<sup>(deprecated)</sup>

setSessionId(sessionId?: string): boolean

设置同步的sessionId，当可信组网中有多个设备时，多个设备间的对象如果设置为同一个sessionId，就能自动同步。

> **说明：**
>
> 从 API Version 8 开始支持，从 API Version 9 开始废弃，建议使用[setSessionId](#setsessionid9)替代。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | sessionId | string | 否 | 分布式数据对象在可信组网中的标识ID。如果要退出分布式组网，设置为""或不设置均可。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | true：标识设置sessionId成功。 <br>false：标识设置sessionId失败。 |

**示例：**

```js
import distributedObject from '@ohos.data.distributedDataObject';
let g_object = distributedObject.createDistributedObject({name:"Amy", age:18, isVis:false, parent:{mother:"jack mom",father:"jack Dad"}});;
// g_object加入分布式组网
g_object.setSessionId(distributedObject.genSessionId());
// 设置为""退出分布式组网
g_object.setSessionId("");
```

### on('change')<sup>(deprecated)</sup>

on(type: 'change', callback: Callback<{ sessionId: string, fields: Array&lt;string&gt; }>): void

监听分布式数据对象的变更。

> **说明：**
>
> 从 API Version 8 开始支持，从 API Version 9 开始废弃，建议使用[on('change')](#onchange9)替代。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 事件类型，固定为'change'，表示数据变更。 |
  | callback | Callback<{ sessionId: string, fields: Array&lt;string&gt; }> | 是 | 变更回调对象实例。<br>sessionId：标识变更对象的sessionId； <br>fields：标识对象变更的属性名。 |

**示例：**

```js
import distributedObject from '@ohos.data.distributedDataObject';  
let g_object = distributedObject.createDistributedObject({name:"Amy", age:18, isVis:false, parent:{mother:"jack mom",father:"jack Dad"}});
globalThis.changeCallback = (sessionId, changeData) => {
    console.info("change" + sessionId);
    if (changeData != null && changeData != undefined) {
        changeData.forEach(element => {
        console.info("changed !" + element + " " + g_object[element]);
        });
    }
}
g_object.on("change", globalThis.changeCallback);
```

### off('change')<sup>(deprecated)</sup>

off(type: 'change', callback?: Callback<{ sessionId: string, fields: Array&lt;string&gt; }>): void

当不再进行数据变更监听时，使用此接口删除对象的变更监听。

> **说明：**
>
> 从 API Version 8 开始支持，从 API Version 9 开始废弃，建议使用[off('change')](#offchange9)替代。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 事件类型，固定为'change'，表示数据变更。 |
  | callback | Callback<{ sessionId: string, fields: Array&lt;string&gt; }> | 否 | 需要删除的数据变更回调，若不设置则删除该对象所有的数据变更回调。<br>sessionId：标识变更对象的sessionId； <br>fields：标识对象变更的属性名。 |


**示例：**

```js
import distributedObject from '@ohos.data.distributedDataObject';  
let g_object = distributedObject.createDistributedObject({name:"Amy", age:18, isVis:false, parent:{mother:"jack mom",father:"jack Dad"}});
// 删除数据变更回调changeCallback
g_object.off("change", globalThis.changeCallback);
// 删除所有的数据变更回调
g_object.off("change");
```

### on('status')<sup>(deprecated)</sup>

on(type: 'status', callback: Callback<{ sessionId: string, networkId: string, status: 'online' | 'offline' }>): void

监听分布式数据对象的上下线。

> **说明：**
>
> 从 API Version 8 开始支持，从 API Version 9 开始废弃，建议使用[on('status')](#onstatus9)替代。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 事件类型，固定为'status'，表示对象上下线。 |
  | callback | Callback<{ sessionId: string, networkId: string, status: 'online' \| 'offline' }> | 是 | 监听上下线回调实例。<br>sessionId：标识变更对象的sessionId； <br>networkId：标识对象设备，即deviceId； <br>status：标识对象为'online'(上线)或'offline'(下线)的状态。 |

**示例：**

```js
import distributedObject from '@ohos.data.distributedDataObject';
globalThis.statusCallback = (sessionId, networkId, status) => {
    globalThis.response += "status changed " + sessionId + " " + status + " " + networkId;
}
let g_object = distributedObject.createDistributedObject({name:"Amy", age:18, isVis:false, parent:{mother:"jack mom",father:"jack Dad"}});
g_object.on("status", globalThis.statusCallback);
```

### off('status')<sup>(deprecated)</sup>

off(type: 'status', callback?: Callback<{ sessionId: string, deviceId: string, status: 'online' | 'offline' }>): void

当不再进行对象上下线监听时，使用此接口删除对象的上下线监听。

> **说明：**
>
> 从 API Version 8 开始支持，从 API Version 9 开始废弃，建议使用[off('status')](#offstatus9)替代。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 事件类型，固定为'status'，表示对象上下线。 |
  | callback | Callback<{ sessionId: string, deviceId: string, status: 'online' \| 'offline' }> | 否 | 需要删除的上下线回调，若不设置则删除该对象所有的上下线回调。<br>sessionId：标识变更对象的sessionId； <br>deviceId：标识变更对象的deviceId； <br>status：标识对象为'online'(上线)或'offline'(下线)的状态。 |


**示例：**

```js
import distributedObject from '@ohos.data.distributedDataObject'; 
let g_object = distributedObject.createDistributedObject({name:"Amy", age:18, isVis:false, parent:{mother:"jack mom",father:"jack Dad"}});
globalThis.statusCallback = (sessionId, networkId, status) => {
    globalThis.response += "status changed " + sessionId + " " + status + " " + networkId;
}
// 删除上下线回调changeCallback
g_object.off("status",globalThis.statusCallback);
// 删除所有的上下线回调
g_object.off("status");
```
