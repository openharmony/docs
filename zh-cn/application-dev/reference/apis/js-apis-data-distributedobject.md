# 分布式对象

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import distributedObject from '@ohos.data.distributedDataObject'
```


## 权限

无


## distributedDataObject.createDistributedObject

createDistributedObject(source: object): DistributedObject


创建一个分布式对象distributedObject，用户可以通过source指定分布式对象中的属性，属性支持基本类型以及复杂类型，返回值是创建好的分布式对象。
- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | object | source | 是 | 设置distributedObject的属性。 |
  

- 示例：
  ```js
  import distributedObject from '@ohos.data.distributedDataObject'
  // 创建对象，对象包含4个属性类型，string,number,boolean和Object
  var g_object = distributedObject.createDistributedObject({name:"Amy", age:18, isVis:false, 
                 parent:{mother:"jack mom",father:"jack Dad"}});
  ```


## distributedObject.genSessionId()

genSessionId(): string

随机创建一个sessionId，返回值是随机创建的sessionId。


- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | string | 随机创建的sessionId。 |

- 示例：
  ```js
  import distributedObject from '@ohos.data.distributedDataObject'
  var sessionId = distributedObject.genSessionId();
  ```


## DistributedObject

表示一个分布式对象。
### setSessionId

setSessionId(sessionId?: string): boolean

设置同步的sessionId,当可信组网中有多个设备时，多个设备间的对象如果设置为同一个sessionId,就能自动同步。sessionId是指定的sessionId,如果要退出分布式组网，设置为""或不设置均可。结果以boolean形式返回，true标识设置sessionId成功

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | sessionId | string | 是 | 分布式对象在可信组网中的标识ID。 |
  

- 示例：
  ```js
  import distributedObject from '@ohos.data.distributedDataObject'
  var g_object = distributedObject.createDistributedObject({name:"Amy", age:18, isVis:false, 
                 parent:{mother:"jack mom",father:"jack Dad"}});
  //g_object加入分布式组网
  g_object.setSessionId(distributedObject.genSessionId());
  //设置为""退出分布式组网
  g_object.setSessionId("");
  ```


### on('change')

on(type: 'change', callback: Callback<{ sessionId: string, fields: Array&lt;string&gt; }>): void

监听分布式对象的变更，type需固定为'change'，callback是变更时触发的回调，回调参数sessionId标识变更对象的sessionId,fields标识对象变更的属性名


- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 事件类型，固定为'change'，表示数据变更。 |
  | callback | Callback<{ sessionId: string, fields: Array&lt;string&gt; }> | 是 | 变更回调对象实例。 |

- 示例：
  ```js
  import distributedObject from '@ohos.data.distributedDataObject'
  var g_object = distributedObject.createDistributedObject({name:"Amy", age:18, isVis:false, 
                 parent:{mother:"jack mom",father:"jack Dad"}});
  changeCallback : function (sessionId, changeData) {
        console.info("change" + sessionId);

        if (changeData != null && changeData != undefined) {
            changeData.forEach(element => {
                console.info("changed !" + element + " " + g_object[element]);
        });
        }
  } 
  g_object.on("change", this.changeCallback);
  ```

### off('change')

off(type: 'change', callback?: Callback<{ sessionId: string, fields: Array&lt;string&gt; }>): void

当不再进行数据变更监听时，使用此接口删除对象的变更监听，type固定为'change'，callback为可选参数，若不设置则表示删除该对象所有的变更监听

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 事件类型，固定为'change'，表示数据变更。 |
  | callback | Callback<{ sessionId: string, fields: Array&lt;string&gt; }> | 否 | 需要删除的变更回调，若不设置则删除该对象所有的变更回调。 |


示例：
  ```js
  import distributedObject from '@ohos.data.distributedDataObject'
  var g_object = distributedObject.createDistributedObject({name:"Amy", age:18, isVis:false, 
                 parent:{mother:"jack mom",father:"jack Dad"}});
  changeCallback : function (sessionId, changeData) {
        console.info("change" + sessionId);
  }

  g_object.on("change", this.changeCallback);
  //删除变更回调changeCallback
  g_object.off("change", changeCallback);
  //删除所有的变更回调
  g_object.off("change");
  ```

### on('status')

on(type: 'status', callback: Callback<{ sessionId: string, networkId: string, status: 'online' | 'offline' }>): void

监听分布式对象的上下线，type需固定为'status'，callback是分布式对象上下线时触发的回调，回调参数sessionId标识变更对象的sessionId,networkId标识对象设备的networkId，status标识对象为'online'(上线)或'offline'(下线)的状态

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 事件类型，固定为'status'，表示对象上下线。 |
  | callback | Callback<{ sessionId: string, networkId: string, status: 'online' \\| 'offline' }> | 是 | 监听上下线回调实例。 |

示例：
  ```js
  import distributedObject from '@ohos.data.distributedDataObject'
  var g_object = distributedObject.createDistributedObject({name:"Amy", age:18, isVis:false, 
                 parent:{mother:"jack mom",father:"jack Dad"}});
  statusCallback : function (sessionId, networkid, status) {
      this.response += "status changed " + sessionId + " " + status + " " + networkId;
  }

  g_object.on("status", this.changeCallback);
  ```

### off('status')

off(type: 'status', callback?: Callback<{ sessionId: string, deviceId: string, status: 'online' | 'offline' }>): void


当不再进行对象上下线监听时，使用此接口删除对象的上下线监听，type固定为'status'，callback为可选参数，若不设置则表示删除该对象所有的上下线监听


- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 事件类型，固定为'status'，表示对象上下线。 |
  | callback | Callback<{ sessionId: string, networkId: string, status: 'online' \\| 'offline' }> | 否 | 需要删除的上下线回调，若不设置则删除该对象所有的上下线回调。 |


示例：
  ```js
  import distributedObject from '@ohos.data.distributedDataObject'
  statusCallback : function (sessionId, networkId, status) {
      this.response += "status changed " + sessionId + " " + status + " " + networkId;
  }

  g_object.on("status", this.changeCallback);
  //删除上下线回调changeCallback
  g_object.off("status", changeCallback);
  //删除所有的上下线回调
  g_object.off("status");
  ```
