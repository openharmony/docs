# 分布式数据对象开发指导

## 场景介绍

分布式数据对象为开发者在分布式应用场景下提供简单易用的功能接口，可实现多设备间同应用的数据协同，同时设备间还可以监听对象的状态和数据变更。

比如，当设备1上应用A的分布式数据对象增、删、改数据后，设备2上应用A也可以获取到对应的数据变化，同时还能监听数据变更以及对端数据对象的上下线。

## 接口说明

分布式数据对象相关功能接口请见[分布式数据对象](../reference/apis/js-apis-data-distributedobject.md)。

### 创建数据对象实例

创建一个分布式数据对象实例，开发者可以通过source指定分布式数据对象中的属性。


**表1** 分布式数据对象实例创建接口

| Bundle名称 | 接口名 | 描述 |
| -------- | -------- | -------- |
| ohos.data.distributedDataObject| createDistributedObject(source: object): DistributedObject | 创建一个分布式数据对象实例，用于数据操作。 <br>-&nbsp;source：设置分布式数据对象的属性。<br>-&nbsp;DistributedObject：返回值是创建好的分布式数据对象。 |

### 创建分布式数据对象sessionId

创建一个随机的sessionId，可将其设置为一个分布式数据对象的sessionId。

**表2** 分布式数据对象sessionId创建接口

| Bundle名称 | 接口名 | 描述 |
| -------- | -------- | -------- |
| ohos.data.distributedDataObject| genSessionId(): string | 创建一个sessionId，可作为分布式数据对象的sessionId。 |

### 设置分布式数据对象sessionId

设置分布式数据对象的sessionId，sessionId是一次（多设备）协同的唯一标识，同步的多个数据对象需要关联同一个sessionId。

**表3** 分布式数据对象sessionId设置接口

| 类名 | 接口名 | 描述 |
| -------- | -------- | -------- |
| DistributedDataObject | setSessionId(sessionId?: string): boolean | 为分布式数据对象设置sessionId。<br>&nbsp;sessionId：分布式数据对象在可信组网中的标识ID。如果要退出分布式组网，设置为""或不设置均可。 |

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

### 保存和撤回已保存的数据对象

保存数据对象：数据对象保存成功后，当应用存在时不会释放对象数据；当应用退出后，重新进入应用时，恢复保存在设备上的数据。

撤回保存的数据对象：如果该对象保存在本地设备，那么将删除所有受信任设备上所保存的数据；如果对象保存在其他设备，那么将删除本地设备上的数据。

有以下几种情况时，保存的数据将会被释放：

- 存储时间超过24小时。
- 应用卸载。
- 成功恢复数据之后。

**表6** 分布式数据对象保存和撤回保存接口

| 类名 | 接口名 | 描述 |
| -------- | -------- | -------- |
| DistributedDataObject | save(deviceId: string): Promise&lt;SaveSuccessResponse&gt; | 保存数据对象。 |
| DistributedDataObject| revokeSave(): Promise&lt;RevokeSaveSuccessResponse&gt; | 撤回已保存的数据对象。 |

## 开发步骤

以一次分布式数据对象同步为例，说明开发步骤。

1. 准备工作，导入@ohos.data.distributedDataObject模块到开发环境。

   ```js   
   import distributedObject from '@ohos.data.distributedDataObject';   
   ```
2. 请求权限。

   需要在`config.json`文件里进行配置请求权限（FA模型）。

   ```json
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
   Stage模型下的权限请求请参见[权限声明-Stage模型](../security/accesstoken-guidelines.md#stage模型)。

   这个权限还需要在应用首次启动的时候弹窗获取用户授权。

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

   ```js
   let localObject = distributedObject.createDistributedObject({
       name: undefined,
       age: undefined,
       isVis: true,
       parent: undefined,
       list: undefined
   });
   let sessionId = distributedObject.genSessionId();
   ```

4. 加入同步组网。同步组网中的数据对象分为发起方和被拉起方。

   ```js
   // 发起方
   let localObject = distributedObject.createDistributedObject({
       name: "jack",
       age: 18,
       isVis: true,
       parent: { mother: "jack mom", father: "jack Dad" },
       list: [{ mother: "jack mom" }, { father: "jack Dad" }]
   });
   localObject.setSessionId(sessionId);
   
   // 被拉起方
   let remoteObject = distributedObject.createDistributedObject({
       name: undefined,
       age: undefined,
       isVis: true,
       parent: undefined,
       list: undefined
   });
   // 收到status上线后remoteObject同步数据，即name变成jack,age是18
   remoteObject.setSessionId(sessionId);
   ```

5. 监听对象数据变更。可监听对端数据的变更，以Callback作为变更回调实例。
   
   ```js
   function changeCallback(sessionId, changeData) {
       console.info("change" + sessionId);
   
       if (changeData != null && changeData != undefined) {
           changeData.forEach(element => {
               console.info("changed !" + element + " " + localObject[element]);
           });
       }
   } 
   
   // 发起方要在changeCallback里刷新界面，则需要将正确的this绑定给changeCallback
   localObject.on("change", this.changeCallback.bind(this));
   ```
   
6. 修改对象属性，对象属性支持基本类型（数字类型、布尔类型、字符串类型）以及复杂类型（数组、基本类型嵌套等）。

   ```js
   localObject.name = "jack";
   localObject.age = 19;
   localObject.isVis = false;
   localObject.parent = { mother: "jack mom", father: "jack Dad" };
   localObject.list = [{ mother: "jack mom" }, { father: "jack Dad" }];
   ```

   > **说明：**
   > 针对复杂类型的数据修改，目前支持对根属性的修改，暂不支持对下级属性的修改。

   ```js
   // 支持的修改方式
   localObject.parent = { mother: "mom", father: "dad" };
   // 不支持的修改方式
   localObject.parent.mother = "mom";
   ```

7. 访问对象。可以通过直接获取的方式访问到分布式数据对象的属性，且该数据为组网内的最新数据。

   ```js
   console.info("name " + localObject["name"]); 
   ```
8. 删除监听数据变更。可以指定删除监听的数据变更回调；也可以不指定，这将会删除该分布式数据对象的所有数据变更回调。

   ```js
   // 删除变更回调changeCallback
   localObject.off("change", changeCallback);
   // 删除所有的变更回调
   localObject.off("change"); 
   ```
9. 监听分布式数据对象的上下线。可以监听对端分布式数据对象的上下线。

   ```js
   function statusCallback(sessionId, networkId, status) {
       this.response += "status changed " + sessionId + " " + status + " " + networkId;
   }
   
   localObject.on("status", this.statusCallback);
   ```

10. 保存和撤回已保存的数据对象。

    ```js
    // 保存数据对象
    localObject.save("local").then((result) => {
        console.info("save sessionId " + result.sessionId);
        console.info("save version " + result.version);
        console.info("save deviceId " + result.deviceId);
    }, (result) => {
        console.info("save local failed.");
    });
    // 撤回保存的数据对象
    localObject.revokeSave().then((result) => {
        console.info("revokeSave success.");
    }, (result) => {
        console.info("revokeSave failed.");
    });
    ```
11. 删除监听分布式数据对象的上下线。可以指定删除监听的上下线回调；也可以不指定，这将会删除该分布式数据对象的所有上下线回调。

    ```js
    // 删除上下线回调statusCallback
    localObject.off("status", this.statusCallback);
    // 删除所有的上下线回调
    localObject.off("status");
    ```
12. 退出同步组网。分布式数据对象退出组网后，本地的数据变更对端不会同步。

    ```js
    localObject.setSessionId("");
    ```

## 相关实例

针对分布式数据对象，有以下相关实例可供参考：
- [`DistributedNote`：分布式备忘录（ArkTS）（API9）（Full SDK）](https://gitee.com/openharmony/applications_app_samples/tree/master/data/DistributedNote)
- [`DistributedObjectDms`：分布式跑马灯（ArkTS）（API9）（Full SDK）](https://gitee.com/openharmony/applications_app_samples/tree/master/data/DistributedObjectDms)