# 分布式数据对象跨设备数据同步


## 场景介绍

传统方式下，设备之间的数据同步，需要开发者完成消息处理逻辑，包括：建立通信链接、消息收发处理、错误重试、数据冲突解决等操作，工作量非常大。而且设备越多，调试复杂度也将同步增加。

其实设备之间的状态、消息发送进度、发送的数据等都是“变量”。如果这些变量支持“全局”访问，那么开发者跨设备访问这些变量就能像操作本地变量一样，从而能够自动高效、便捷地实现数据多端同步。

分布式数据对象即实现了对“变量”的“全局”访问。向应用开发者提供内存对象的创建、查询、删除、修改、订阅等基本数据对象的管理能力，同时具备分布式能力。为开发者在分布式应用场景下提供简单易用的JS接口，轻松实现多设备间同应用的数据协同，同时设备间可以监听对象的状态和数据变更。满足超级终端场景下，相同应用多设备间的数据对象协同需求。与传统方式相比，分布式数据对象大大减少了开发者的工作量。


## 基本概念

- **分布式内存数据库**
  分布式内存数据库将数据缓存在内存中，以便应用获得更快的数据存取速度，不会将数据进行持久化。若数据库关闭，则数据不会保留。

- **分布式数据对象**
  分布式数据对象是一个JS对象型的封装。每一个分布式数据对象实例会创建一个内存数据库中的数据表，每个应用程序创建的内存数据库相互隔离，对分布式数据对象的“读取”或“赋值”会自动映射到对应数据库的get/put操作。

  分布式数据对象的生命周期包括以下状态：

  - 未初始化：未实例化，或已被销毁。
  - 本地数据对象：已创建对应的数据表，但是还无法进行数据同步。
  - 分布式数据对象：已创建对应的数据表，设备在线且组网内设置同样sessionId的对象数&gt;=2，可以跨设备同步数据。若设备掉线或将sessionId置为空，分布式数据对象退化为本地数据对象。


## 运作机制

**图1** 分布式数据对象运作机制 

![distributedObject](figures/distributedObject.jpg)

分布式数据对象生长在分布式内存数据库之上，在分布式内存数据库上进行了JS对象型的封装，能像操作本地变量一样操作分布式数据对象，数据的跨设备同步由系统自动完成。


### JS对象型存储与封装机制

- 为每个分布式数据对象实例创建一个内存数据库，通过SessionId标识，每个应用程序创建的内存数据库相互隔离。

- 在分布式数据对象实例化的时候，（递归）遍历对象所有属性，使用“Object.defineProperty”定义所有属性的set和get方法，set和get中分别对应数据库一条记录的put和get操作，Key对应属性名，Value对应属性值。

- 在开发者对分布式数据对象进行“读取”或者“赋值”的时候，都会自动调用到set和get方法，映射到对应数据库的操作。

**表1** 分布式数据对象和分布式数据库的对应关系
  
| 分布式对象实例 | 对象实例 | 属性名称 | 属性值 | 
| -------- | -------- | -------- | -------- |
| 分布式内存数据库 | 一个数据库（sessionID标识） | 一条数据库记录的key | 一条数据库记录的value | 


### 跨设备同步和数据变更通知机制

分布式数据对象，最重要的功能就是对象之间的数据同步。可信组网内的设备可以在本地创建分布式数据对象，并设置sessionID。不同设备上的分布式数据对象，通过设置相同的sessionID，建立对象之间的同步关系。

如下图所示，设备A和设备B上的“分布式数据对象1”，其sessionID均为session1，这两个对象建立了session1的同步关系。

  **图2** 对象的同步关系  

![distributedObject_sync](figures/distributedObject_sync.jpg)

一个同步关系中，一个设备只能有一个对象加入。比如上图中，设备A的“分布式数据对象1”已经加入了session1的同步关系，所以设备A的“分布式数据对象2”就加入失败了。

建立同步关系后，每个Session有一份共享对象数据。加入了同一个Session的对象，支持以下操作：

（1）读取/修改Session中的数据。

（2）监听数据变更，感知其他设备对共享对象数据的修改。

（3）监听状态变更，感知其他设备的加入和退出。


### 同步的最小单位

关于分布式数据对象的数据同步，值得注意的是，同步的最小单位是“属性”。比如，下图中对象1包含三个属性：name、age和parents。当其中一个属性变更时，则数据同步时只需同步此变更的属性。

**图3** 数据同步视图 
 

![distributedObject_syncView](figures/distributedObject_syncView.jpg)


### 对象持久化缓存机制

分布式对象主要运行在应用程序的进程空间。当调用分布式对象持久化接口时，通过分布式数据库对对象进行持久化和同步，进程退出后数据也不会丢失。

该场景是分布式对象的扩展场景，主要用于以下情况：

- 在设备上创建持久化对象后APP退出，重新打开APP，创建持久化对象，加入同一个Session，数据可以恢复到APP退出前的数据。

- 在设备A上创建持久化对象并同步后持久化到设备B后，A设备的APP退出，设备B打开APP，创建持久化对象，加入同一个Session，数据可以恢复到A设备退出前的数据。


## 约束限制

- 不同设备间只有相同bundleName的应用才能直接同步。

- 分布式数据对象的数据同步发生在同一个应用程序下，且同sessionID之间。

- 不建议创建过多的分布式数据对象，每个分布式数据对象将占用100-150KB内存。

- 每个分布式数据对象大小不超过500KB。

- 设备A修改1KB数据，设备B收到变更通知，50ms内完成。

- 单个应用程序最多只能创建16个分布式数据对象实例。

- 考虑到性能和用户体验，最多不超过3个设备进行数据协同。

- 如对复杂类型的数据进行修改，仅支持修改根属性，暂不支持下级属性修改。

- 支持JS接口间的互通，与其他语言不互通。


## 接口说明

以下是分布式对象跨设备数据同步功能的相关接口，大部分为异步接口。异步接口均有callback和Promise两种返回形式，下表均以callback形式为例，更多接口及使用方式请见[分布式数据对象](../reference/apis/js-apis-data-distributedobject.md)。

| 接口名称 | 描述 | 
| -------- | -------- |
| create(context: Context, source: object): DataObject | 创建并得到一个分布式数据对象实例。 | 
| genSessionId(): string | 创建一个sessionId，可作为分布式数据对象的sessionId。 | 
| setSessionId(sessionId: string, callback: AsyncCallback&lt;void&gt;): void | 设置同步的sessionId，当可信组网中有多个设备时，多个设备间的对象如果设置为同一个sessionId，就能自动同步。 | 
| setSessionId(callback: AsyncCallback&lt;void&gt;): void | 退出所有已加入的session。 | 
| on(type: 'change', callback: Callback&lt;{ sessionId: string, fields: Array&lt;string&gt; }&gt;): void | 监听分布式数据对象的数据变更。 | 
| on(type: 'status', callback: Callback&lt;{ sessionId: string, networkId: string, status: 'online' \| 'offline' }&gt;): void | 监听分布式数据对象的上下线。 | 
| save(deviceId: string, callback: AsyncCallback&lt;SaveSuccessResponse&gt;): void | 保存分布式数据对象。 | 
| revokeSave(callback: AsyncCallback&lt;RevokeSaveSuccessResponse&gt;): void | 撤回保存的分布式数据对象。 | 


## 开发步骤

以一次分布式数据对象同步为例，说明开发步骤。

1. 导入`@ohos.data.distributedDataObject`模块。
     
   ```js
   import distributedDataObject from '@ohos.data.distributedDataObject';
   ```

2. 请求权限。

   1. 需要申请ohos.permission.DISTRIBUTED_DATASYNC权限，配置方式请参见[配置文件权限声明](../security/accesstoken-guidelines.md#配置文件权限声明)。
   2. 同时需要在应用首次启动时弹窗向用户申请授权，使用方式请参见[向用户申请授权](../security/accesstoken-guidelines.md#向用户申请授权)。

3. 创建并得到一个分布式数据对象实例。

   Stage模型示例：
     
   ```js
   // 导入模块
   import distributedDataObject from '@ohos.data.distributedDataObject';
   import UIAbility from '@ohos.app.ability.UIAbility';
   
   class EntryAbility extends UIAbility {
     onWindowStageCreate(windowStage) {
       // 创建对象，该对象包含4个属性类型：string、number、boolean和Object
       let localObject = distributedDataObject.create(this.context, {
         name: 'jack',
         age: 18,
         isVis: false,
         parent: { mother: 'jack mom', father: 'jack Dad' },
         list: [{ mother: 'jack mom' }, { father: 'jack Dad' }]
       });
     }
   }
   ```

   FA模型示例：

     
   ```js
   // 导入模块
   import distributedDataObject from '@ohos.data.distributedDataObject';
   import featureAbility from '@ohos.ability.featureAbility';
   // 获取context
   let context = featureAbility.getContext();
   // 创建对象，该对象包含4个属性类型：string、number、boolean和Object
   let localObject = distributedDataObject.create(context, {
     name: 'jack',
     age: 18,
     isVis: false,
     parent: { mother: 'jack mom', father: 'jack Dad' },
     list: [{ mother: 'jack mom' }, { father: 'jack Dad' }]
   });
   ```

4. 加入同步组网。同步组网中的数据对象分为发起方和被拉起方。
     
   ```js
   // 设备1加入sessionId
   let sessionId = '123456';
   
   localObject.setSessionId(sessionId);
   
   // 和设备1协同的设备2加入同一个session
   
   // 创建对象，该对象包含4个属性类型：string、number、boolean和Object
   let remoteObject = distributedDataObject.create(this.context, {
     name: undefined,
     age: undefined, //  undefined表示数据来自对端
     isVis: true,
     parent: undefined,
     list: undefined
   });
   // 收到status上线后remoteObject同步数据，即name变成jack,age是18
   remoteObject.setSessionId(sessionId);
   ```

5. 监听对象数据变更。可监听对端数据的变更，以callback作为变更回调实例。
     
   ```js
   function changeCallback(sessionId, changeData) {
     console.info(`change: ${sessionId}`);
   
     if (changeData !== null && changeData !== undefined) {
       changeData.forEach(element => {
         console.info(`The element ${localObject[element]} changed.`);
       });
     }
   }
   
   // 发起方要在changeCallback里刷新界面，则需要将正确的this绑定给changeCallback
   localObject.on("change", this.changeCallback.bind(this));
   ```

6. 修改对象属性，对象属性支持基本类型（数字类型、布尔类型、字符串类型）以及复杂类型（数组、基本类型嵌套等）。
     
   ```js
   localObject.name = 'jack1';
   localObject.age = 19;
   localObject.isVis = false;
   localObject.parent = { mother: 'jack1 mom', father: 'jack1 Dad' };
   localObject.list = [{ mother: 'jack1 mom' }, { father: 'jack1 Dad' }];
   ```

   > **说明：**
   >
   > 针对复杂类型的数据修改，目前仅支持对根属性的修改，暂不支持对下级属性的修改。

     
   ```js
   // 支持的修改方式
   localObject.parent = { mother: 'mom', father: 'dad' };
   // 不支持的修改方式
   localObject.parent.mother = 'mom';
   ```

7. 访问对象。可以通过直接获取的方式访问到分布式数据对象的属性，且该数据为组网内的最新数据。
     
   ```js
   console.info(`name:${localObject['name']}`); 
   ```

8. 删除监听数据变更。可以指定删除监听的数据变更回调；也可以不指定，这将会删除该分布式数据对象的所有数据变更回调。
     
   ```js
   // 删除变更回调changeCallback
   localObject.off('change', this.changeCallback);
   // 删除所有的变更回调
   localObject.off('change'); 
   ```

9. 监听分布式数据对象的上下线。可以监听对端分布式数据对象的上下线。
     
   ```js
   function statusCallback(sessionId, networkId, status) {
     // 业务处理
   }
   
   localObject.on('status', this.statusCallback);
   ```

10. 保存和撤回已保存的数据对象。
     
    ```js
    // 保存数据对象，如果应用退出后组网内设备需要恢复对象数据时调用
    localObject.save('local').then((result) => {
      console.info(`Succeeded in saving. SessionId:${result.sessionId},version:${result.version},deviceId:${result.deviceId}`);
    }).catch((err) => {
      console.error(`Failed to save. Code:${err.code},message:${err.message}`);
    });
   
    // 撤回保存的数据对象
    localObject.revokeSave().then((result) => {
      console.info(`Succeeded in revokeSaving. Session:${result.sessionId}`);
    }).catch((err) => {
      console.error(`Failed to revokeSave. Code:${err.code},message:${err.message}`);
    });
    ```

11. 删除监听分布式数据对象的上下线。可以指定删除监听的上下线回调；也可以不指定，这将会删除该分布式数据对象的所有上下线回调。
     
    ```js
    // 删除上下线回调statusCallback
    localObject.off('status', this.statusCallback);
    // 删除所有的上下线回调
    localObject.off('status');
    ```

12. 退出同步组网。分布式数据对象退出组网后，本地的数据变更对端不会同步。
     
    ```js
    localObject.setSessionId(() => {
        console.info('leave all lession.');
    });
    ```

## 相关实例

针对分布式数据对象开发，有以下相关实例可供参考：

- [分布式组网认证（ArkTS）（Full SDK）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-3.2-Release/code/SuperFeature/DistributedAppDev/DistributedAuthentication)

- [分布式对象（ArkTS）（Full SDK）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-3.2-Release/code/SuperFeature/DistributedAppDev/DistributedNote)