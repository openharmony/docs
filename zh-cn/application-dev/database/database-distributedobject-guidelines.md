# 分布式数据对象开发指导

## 场景介绍

分布式数据对象通过屏蔽设备间复杂的数据交互处理，提供了与本地变量类似的极简操作，当设备1的应用A的分布式数据对象增、删、改数据后，设备2的应用A也可以获取到对应的数据变化，同时还能监听数据变更以及对端数据对象的上下线。分布式数据对象支持的数据类型包括数字型、字符型、布尔型等基本类型，同时也支持数组、基本类型嵌套等复杂类型。


## 接口说明
具体分布式数据对象相关功能接口请见[分布式数据对象](../reference/apis/js-apis-data-distributedobject.md)。

### 创建数据对象实例

创建一个分布式数据对象实例，用户可以通过source指定分布式对象中的属性。


**表1** 分布式数据对象实例创建接口
| 包名 | 接口名 | 描述 | 
| -------- | -------- | -------- |
| ohos.data.distributedDataObject| createDistributedObject(source: object): DistributedObject | 创建一个分布式数据对象实例，用于数据操作 <br>-&nbsp;source：设置distributedObject的属性。<br>-&nbsp;DistributedObject：返回值是创建好的分布式对象。| 

### 创建分布式数据对象sessionId

创建一个随机的sessionId，可将其设置为一个分布式数据对象的sessionId。

**表2** 分布式数据对象sessionId创建接口
| 包名 | 接口名 | 描述 |
| -------- | -------- | -------- |
| ohos.data.distributedDataObject| genSessionId(): string | 创建一个sessionId，可作为分布式数据对象的sessionId |

### 设置分布式数据对象sessionId

设置分布式数据对象的sessionId，sessionId是一次（多设备）协同的唯一标识，同步的多个数据对象需要关联同一个sessionId。

**表3** 分布式数据对象sessionId设置接口
| 类名 | 接口名 | 描述 |
| -------- | -------- | -------- |
| DistributedDataObject | setSessionId(sessionId?: string): boolean | 为分布式数据对象设置sessionId <br>&nbsp;sessionId：分布式对象在可信组网中的标识ID。如果要退出分布式组网，设置为""或不设置均可。|

### 订阅数据变更

订阅数据变更需要指定Callback作为回调方法，订阅的数据对象发生数据变更后，Callback被回调。

**表4** 分布式数据对象数据变更订阅接口
| 类名 | 接口名 | 描述 | 
| -------- | -------- | -------- |
| DistributedDataObject| on(type: 'change', callback: Callback<{ sessionId: string, fields: Array&lt;string&gt; }>): void | 订阅数据变更。 | 
| DistributedDataObject| off(type: 'change', callback?: Callback<{ sessionId: string, fields: Array&lt;string&gt; }>): void | 注销订阅。需要删除的变更回调，若不设置则删除该对象所有的变更回调。 |

### 订阅数据对象上下线

订阅数据对象上下线需要指定Callback作为回调方法，订阅的数据对象上线/下线后，对端的数据对象会收到Callback回调。

**表5** 分布式数据对象数据上下线订阅接口
| 类名 | 接口名 | 描述 |
| -------- | -------- | -------- |
| DistributedDataObject| on(type: 'status', callback: Callback<{ sessionId: string, networkId: string, status: 'online' \| 'offline' }>): void | 订阅数据对象上下线。 |
| DistributedDataObject| off(type: 'status', callback?: Callback<{ sessionId: string, deviceId: string, status: 'online' \| 'offline' }>): void | 注销订阅。 |



## 开发步骤

以一次分布式数据对象同步为例，说明开发步骤。

1. 准备工作，导入@ohos.data.distributedDataObject模块到开发环境。
   ```js   
   import distributedObject from '@ohos.data.distributedDataObject';   
   ```   
2. 请求权限。需要在`config.json`里面进行配置请求权限，示例代码如下：
    ```
     {
       "module": {
           "reqPermissions": [
               {
                  "name": "ohos.permission.DISTRIBUTED_DATASYNC"
               }
           ]
       }
     }
    ```	 
    这个权限还需要在应用首次启动的时候弹窗获取用户授权，可以通过如下代码实现：
    ```js
    import featureAbility from '@ohos.ability.featureAbility';
	
    function grantPermission() {
        console.info('grantPermission');
        let context = featureAbility.getContext();
        context.requestPermissionsFromUser(['ohos.permission.DISTRIBUTED_DATASYNC'], 666, function (result) {
            console.info(`result.requestCode=${result.requestCode}`)
    
        })
        console.info('end grantPermission');
    }
    grantPermission();
    ```

3. 获取分布式数据对象实例。

   以下为创建分布式数据对象的代码示例：
   ```js
   var local_object = distributedObject.createDistributedObject({name:undefined, age:undefined, isVis:true, 
                  parent:undefined, list:undefined});
   var sessionId = distributedObject.genSessionId();
   ```


4. 加入同步组网。同步组网中的数据对象分为发起方和被拉起方。
   
   以下为加入同步组网的代码示例:

   ```js
   //发起方
   var local_object = distributedObject.createDistributedObject({name:"jack", age:18, isVis:true, 
       parent:{mother:"jack mom",father:"jack Dad"},list:[{mother:"jack mom"}, {father:"jack Dad"}]});
   local_object.setSessionId(sessionId);
   
   //被拉起方
   var remote_object = distributedObject.createDistributedObject({name:undefined, age:undefined, isVis:true, 
                  parent:undefined, list:undefined});
   remote_object.setSessionId(sessionId);
   //收到status上线后remote_object同步数据，即name变成jack,age是18
   ```
   
5. 监听对象数据变更。可监听对端数据的变更，以callback作为变更回调实例。

   以下为监听对象数据变更的代码示例。
   
   ```js
   function changeCallback(sessionId, changeData) {
        console.info("change" + sessionId);
   
        if (changeData != null && changeData != undefined) {
            changeData.forEach(element => {
                console.info("changed !" + element + " " + local_object[element]);
        });
        }
    } 

    // 发起方要在changeCallback里刷新界面，则需要将正确的this绑定给changeCallback
    local_object.on("change", this.changeCallback.bind(this));
   ```
   
6. 修改对象属性，对象属性支持基本类型（数字类型、布尔类型、字符串类型）以及复杂类型（数组、基本类型嵌套等）。
   
   以下为修改分布式数据对象属性的代码示例：
   ```js
   local_object.name = "jack";
   local_object.age = 19;
   local_object.isVis = false;
   local_object.parent = {mother:"jack mom",father:"jack Dad"};
   local_object.list = [{mother:"jack mom"}, {father:"jack Dad"}];
   ```

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 针对复杂类型的数据修改，目前支持对根属性的修改，暂不支持对下级属性的修改。示例如下：
   ```js
   //支持的修改方式
   local_object.parent = {mother:"mom", father:"dad"};
   //不支持的修改方式
   local_object.parent.mother = "mom";
   ```

7. 访问对象。可以通过直接获取的方式访问到分布式数据对象的属性，且该数据为组网内的最新数据。
   
   以下为访问对象的代码示例：
   ```js
   console.info("name " + local_object["name"]); 
   ```
8. 删除监听数据变更。可以指定删除监听的数据变更回调；也可以不指定，这将会删除该分布式数据对象的所有数据变更回调。

   以下为取消监听数据变更的代码示例：
   ```js
   //删除变更回调changeCallback
   local_object.off("change", changeCallback);
   //删除所有的变更回调
   local_object.off("change"); 
   ```
9. 监听分布式对象的上下线。可以监听对端分布式数据对象的上下线。
   以下为访问对象的代码示例：
   ```js
    function statusCallback(sessionId, networkId, status) {
      this.response += "status changed " + sessionId + " " + status + " " + networkId;
    }
   
    local_object.on("status", this.statusCallback);
   ```
10. 删除监听分布式对象的上下线。可以指定删除监听的上下线回调；也可以不指定，这将会删除该分布式数据对象的所有上下线回调。
   
    以下为取消监听数据变更的代码示例：
   ```js
   //删除上下线回调statusCallback
   local_object.off("status", statusCallback);
   //删除所有的上下线回调
   local_object.off("status");
   ```
11. 退出同步组网。分布式对象退出组网后，本地的数据变更对端不会同步。

     以下为退出同步组网的代码示例：
       ```js
       local_object.setSessionId("");
       ```
## 开发实例

针对分布式数据对象，有以下开发实例可供参考： 

- [备忘录应用](https://gitee.com/openharmony/distributeddatamgr_objectstore/tree/master/samples/distributedNotepad)


在备忘录应用中，当某一个设备上的备忘录事件发生变更时，通过分布式数据对象将事件变更同步在可信组网内的其他设备上，比如新增备忘录事件、编辑事件标题和内容、清空事件列表等。
 
