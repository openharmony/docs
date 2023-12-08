# @ohos.data.cloudExtension (端云共享extension)

端云共享extension提供三方厂商适配共享云服务的能力。通过实现端云共享extension提供的接口，对接端侧共享的能力到共享云服务端，实现端云共享的发起、端云共享的取消、退出共享、更改共享数据的操作权限、查询共享参与者、根据共享邀请码查询共享参与者、确认共享邀请、更改已确认的共享邀请，同时按接口要求返回共享云服务返回的结果。

该模块提供以下端云共享extension相关的接口：

- [CloudService](#cloudservice)：提供实现连接ShareCenter的接口。
- [ShareCenter](#sharecenter)：提供实现发起共享、取消共享、退出共享、查询共享参与者、根据邀请码查询共享参与者、更改共享数据的操作权限、确认共享邀请、更改已确认的共享邀请的接口。

> **说明：** 
>
> - 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口为系统接口。

## 导入模块

```ts
import cloudExtension from '@ohos.data.cloudExtension';
```

## Result&lt;T&gt;
共享结果的返回值。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

| 名称          | 类型                          | 必填  | 说明           |
| ----------- | --------------------------- | --- | ------------ |
| code        | number                      | 是   | 错误码。       |
| description | string                      | 否   | 错误码详细描述。       |
| value       | T                           | 否   | 返回结果的值，具体类型由参数T指定。       |

## cloudExtension.createCloudServiceStub

createCloudServiceStub(instance: CloudService): Promise&lt;rpc.RemoteObject&gt;

创建[CloudService](#cloudservice)的rpc对象，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名    | 类型                            | 必填 | 说明                                                         |
| --------- | ------------------------------- | ---- | -------------------------------- |
| instance  | [CloudService](#cloudservice)   | 是    | CloudService的实例。                   |

**返回值：**

| 类型                | 说明                      |
| -------------------             | ------------------------- |
| Promise&lt;[rpc.RemoteObject](js-apis-rpc.md)&gt; | 返回结果RemoteObject的Promise对象。 |

**示例：**

```ts
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
import Want from '@ohos.app.ability.Want';
import rpc from '@ohos.rpc';
import cloudExtension from '@ohos.data.cloudExtension';

export default class MyCloudService implements cloudExtension.CloudService {
    constructor() {}
    async connectShareCenter(userId: number, bundleName: string): Promise<rpc.RemoteObject> {
        ...
    }
}

export default class MyServiceExtension extends ServiceExtensionAbility {
    onCreate(want: Want) {
        console.info(`onCreate: ${want}`);
    }
    onRequest(want: Want, startId: number) {
        console.info(`onRequest: ${want} ${startId}`);
    }
    onConnect(want: Want): rpc.RemoteObject | Promise<rpc.RemoteObject> {
        console.info(`onConnect: ${want}`);
        return cloudExtension.createCloudServiceStub(new MyCloudService());
    }
    onDisconnect(want: Want) {
        console.info(`onDisconnect: ${want}`);
    }
    onDestroy() {
        console.info(`onDestroy`);   
    }
}
```

## cloudExtension.createShareServiceStub

createShareServiceStub(instance: ShareCenter): Promise&lt;rpc.RemoteObject&gt;

创建[ShareCenter](#sharecenter)的rpc对象，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名    | 类型                            | 必填 | 说明                                                         |
| --------- | ------------------------------- | ---- | -------------------------------- |
| instance  | [ShareCenter](#sharecenter)   | 是    | ShareCenter的实例。                   |

**返回值：**

| 类型                | 说明                      |
| -------------------             | ------------------------- |
| Promise&lt;[rpc.RemoteObject](js-apis-rpc.md)&gt; | 返回结果RemoteObject的Promise对象。 |

**示例：**

```ts
import rpc from '@ohos.rpc';
import cloudExtension from '@ohos.data.cloudExtension';

export default class MyShareCenter implements cloudExtension.ShareCenter {
    constructor() {}
    ...
}

export default class MyCloudService implements cloudExtension.CloudService {
    constructor() {}
    async connectShareCenter(userId: number, bundleName: string): Promise<rpc.RemoteObject> {
        console.info(`connect share center, bundle: ${bundleName}`);
        return cloudExtension.createShareServiceStub(new MyShareCenter());
    }
}
```

## CloudService

提供云服务接口，需要开发者继承此接口以实现接口对接云的能力并按接口返回值进行返回。

### connectShareCenter

connectShareCenter(userId: number, bundleName: string): Promise&lt;rpc.RemoteObject&gt;

获取端云共享服务的RemoteObject，通过createShareServiceStub接口进行创建。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名  | 类型                    | 必填 | 说明                                            |
| ------- | ----------------------- | ---- | ----------------------------------------------- |
| userId      | number  | 是   | 表示用户ID。         |
| bundleName  | string  | 是   | 应用包名。   |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;rpc.RemoteObject&gt; | 返回云共享服务RemoteObject的Promise对象。 |

**示例：**

```ts
import rpc from '@ohos.rpc';
import cloudExtension from '@ohos.data.cloudExtension';

export default class MyShareCenter implements cloudExtension.ShareCenter {
    constructor() {}
    ...
}

export default class MyCloudService implements cloudExtension.CloudService {
    constructor() {}
    async connectShareCenter(userId: number, bundleName: string): Promise<rpc.RemoteObject> {
        console.info(`connect share center, bundle: ${bundleName}`);
        return cloudExtension.createShareServiceStub(new MyShareCenter());
    }
}
```

## ShareCenter

提供云共享服务接口，需要开发者继承此接口以实现接口对接共享云的能力，并按接口返回值进行返回。

### share

share(userId: number, bundleName: string, sharingResource: string, participants: Array&lt;cloudData.sharing.Participant&gt;): Promise&lt;Result&lt;Array&lt;Result&lt;cloudData.sharing.Participant&gt;&gt;&gt;&gt;

发起端云共享邀请调用的接口。共享邀请时，会指定当前发起共享的应用、共享数据的资源标志sharingResource和共享参与者。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名  | 类型                    | 必填 | 说明                                            |
| ------- | ----------------------- | ---- | ----------------------------------------------- |
| userId          | number  | 是   | 表示用户ID。  |
| bundleName      | string  | 是   | 应用包名。    |
| sharingResource | string  | 是   | 共享资源标志。   |
| participants    | Array&lt;cloudData.sharing.Participant&gt;  | 是   | 共享参与者。   |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;Result&lt;Array&lt;Result&lt;cloudData.sharing.Participant&gt;&gt;&gt;&gt; | 返回发起共享结果的Promise对象。 |

**示例：**

```ts
import cloudExtension from '@ohos.data.cloudExtension';
import cloudData from '@ohos.data.cloudData';

type Participant = cloudData.sharing.Participant;

export default class MyShareCenter implements cloudExtension.ShareCenter {
    constructor() {}
    async share(userId: number, bundleName: string, sharingResource: string, participants: Array<Participant>):
        Promise<cloudExtension.Result<Array<cloudExtension.Result<Participant>>>> {
        console.info(`share, bundle: ${bundleName}`);
        // 对接云共享服务端，并获得共享的返回值
        ...
        // 返回服务端发起共享的返回结果
        let result: Array<cloudExtension.Result<Participant>> = [];
        participants.forEach((item => {
            result.push({
                code: cloudData.sharing.sharingCode.SUCCESS,
                description: 'share success'    
            })
        }))
        return {
            code: cloudData.sharing.sharingCode.SUCCESS,
            description: 'share success',
            value: result
        }
    }
    ...
}
```

### unshare

unshare(userId: number, bundleName: string, sharingResource: string, participants: Array&lt;cloudData.sharing.Participant&gt;): Promise&lt;Result&lt;Array&lt;Result&lt;cloudData.sharing.Participant&gt;&gt;&gt;&gt;

取消共享的接口。取消共享时，会指定当前取消共享的应用、取消共享数据的资源标志sharingResource和取消共享的参与者。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名  | 类型                    | 必填 | 说明                                            |
| ------- | ----------------------- | ---- | ----------------------------------------------- |
| userId          | number  | 是   | 表示用户ID。  |
| bundleName      | string  | 是   | 应用包名。    |
| sharingResource | string  | 是   | 共享资源标志。   |
| participants    | Array&lt;cloudData.sharing.Participant&gt;  | 是   | 共享参与者。   |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;Result&lt;Array&lt;Result&lt;cloudData.sharing.Participant&gt;&gt;&gt;&gt; | 返回取消共享结果的Promise对象。 |

**示例：**

```ts
import cloudExtension from '@ohos.data.cloudExtension';
import cloudData from '@ohos.data.cloudData';

type Participant = cloudData.sharing.Participant;

export default class MyShareCenter implements cloudExtension.ShareCenter {
    constructor() {}
    async unshare(userId: number, bundleName: string, sharingResource: string, participants: Array<Participant>):
        Promise<cloudExtension.Result<Array<cloudExtension.Result<Participant>>>> {
        console.info(`unshare, bundle: ${bundleName}`);
        // 对接云共享服务端，并获得取消共享的返回值
        ...
        // 返回服务端取消共享的返回结果
        let result: Array<cloudExtension.Result<Participant>> = [];
        participants.forEach((item => {
            result.push({
                code: cloudData.sharing.sharingCode.SUCCESS,
                description: 'unshare success'    
            })
        }))
        return {
            code: cloudData.sharing.sharingCode.SUCCESS,
            description: 'unshare success',
            value: result
        }
    }
    ...
}
```

### exit

exit(userId: number, bundleName: string, sharingResource: string): Promise&lt;Result&lt;void&gt;&gt;

退出共享的接口。退出共享时，会指定当前退出共享的应用以及退出共享数据的资源标志sharingResource。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名  | 类型                    | 必填 | 说明                                            |
| ------- | ----------------------- | ---- | ----------------------------------------------- |
| userId          | number  | 是   | 表示用户ID。  |
| bundleName      | string  | 是   | 应用包名。    |
| sharingResource | string  | 是   | 共享资源标志。   |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;Result&lt;void&gt;&gt; | 返回退出共享结果的Promise对象。 |

**示例：**

```ts
import cloudExtension from '@ohos.data.cloudExtension';
import cloudData from '@ohos.data.cloudData';

export default class MyShareCenter implements cloudExtension.ShareCenter {
    constructor() {}
    async exit(userId: number, bundleName: string, sharingResource: string):
        Promise<cloudExtension.Result<void>> {
        console.info(`exit share, bundle: ${bundleName}`);
        // 对接云共享服务端，并获得退出共享的返回值
        ...
        // 返回服务端退出共享的返回结果
        return {
            code: cloudData.sharing.sharingCode.SUCCESS,
            description: 'exit share success'
        }
    }
    ...
}
```

### changePrivilege

changePrivilege(userId: number, bundleName: string, sharingResource: string, participants: Array&lt;cloudData.sharing.Participant&gt;): Promise&lt;Result&lt;Array&lt;Result&lt;cloudData.sharing.Participant&gt;&gt;&gt;&gt;

更改已共享数据的操作权限接口。更改权限时，会指定当前更改权限的应用、更改权限数据的资源标志sharingResource和更改权限的参与者。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名  | 类型                    | 必填 | 说明                                            |
| ------- | ----------------------- | ---- | ----------------------------------------------- |
| userId          | number  | 是   | 表示用户ID。  |
| bundleName      | string  | 是   | 应用包名。    |
| sharingResource | string  | 是   | 共享资源标志。   |
| participants    | Array&lt;cloudData.sharing.Participant&gt;  | 是   | 共享参与者。   |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;Result&lt;Array&lt;Result&lt;cloudData.sharing.Participant&gt;&gt;&gt;&gt; | 返回更改权限结果的Promise对象。 |

**示例：**

```ts
import cloudExtension from '@ohos.data.cloudExtension';
import cloudData from '@ohos.data.cloudData';

type Participant = cloudData.sharing.Participant;

export default class MyShareCenter implements cloudExtension.ShareCenter {
    constructor() {}
    async changePrivilege(userId: number, bundleName: string, sharingResource: string, participants: Array<Participant>):
        Promise<cloudExtension.Result<Array<cloudExtension.Result<Participant>>>> {
        console.info(`change privilege, bundle: ${bundleName}`);
        // 对接云共享服务端，并获得更改权限的返回值
        ...
        // 返回服务端更改权限的返回结果
        let result: Array<cloudExtension.Result<Participant>> = [];
        participants.forEach((item => {
            result.push({
                code: cloudData.sharing.sharingCode.SUCCESS,
                description: 'change privilege success'    
            })
        }))
        return {
            code: cloudData.sharing.sharingCode.SUCCESS,
            description: 'change privilege success',
            value: result
        }
    }
    ...
}
```

### queryParticipants

queryParticipants(userId: number, bundleName: string, sharingResource: string): Promise&lt;Result&lt;Array&lt;cloudData.sharing.Participant&gt;&gt;&gt;

查询当前共享参与者的接口。查询参与者时，会指定当前查询参与者的应用、查询参与者数据的资源标志sharingResource。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名  | 类型                    | 必填 | 说明                                            |
| ------- | ----------------------- | ---- | ----------------------------------------------- |
| userId          | number  | 是   | 表示用户ID。  |
| bundleName      | string  | 是   | 应用包名。    |
| sharingResource | string  | 是   | 共享资源标志。   |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;Result&lt;Array&lt;cloudData.sharing.Participant&gt;&gt;&gt; | 返回查询参与者结果的Promise对象。 |

**示例：**

```ts
import cloudExtension from '@ohos.data.cloudExtension';
import cloudData from '@ohos.data.cloudData';

type Participant = cloudData.sharing.Participant;

export default class MyShareCenter implements cloudExtension.ShareCenter {
    constructor() {}
    async queryParticipants(userId: number, bundleName: string, sharingResource: string):
        Promise<cloudExtension.Result<Array<Participant>>> {
        console.info(`query participants, bundle: ${bundleName}`);
        // 对接云共享服务端，并获得查询参与者的返回值
        ...
        // 返回服务端查询参与者的返回结果
        let privilege = {
            writable: false,
            readable: true,
            creatable: false,
            deletable: false,
            shareable: false
        }
        let participants = new Array();
        participants.push({
           identity: '000000000',
           role: cloudData.sharing.Role.ROLE_INVITEE,
           state: cloudData.sharing.State.STATE_ACCEPTED,
           privilege: privilege,
           attachInfo: ''
        })
        participants.push({
           identity: '111111111',
           role: cloudData.sharing.Role.ROLE_INVITEE,
           state: cloudData.sharing.State.STATE_ACCEPTED,
           privilege: privilege,
           attachInfo: ''
        })
        return {
            code: cloudData.sharing.sharingCode.SUCCESS,
            description: 'query participants success',
            value: participants
        }
    }
    ...
}
```

### queryParticipantsByInvitation

queryParticipantsByInvitation(userId: number, bundleName: string, invitationCode: string): Promise&lt;Result&lt;Array&lt;cloudData.sharing.Participant&gt;&gt;&gt;

根据邀请码查询当前共享参与者的接口。查询参与者时，会指定当前查询参与者的应用、共享数据的的邀请码。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名  | 类型                    | 必填 | 说明                                            |
| ------- | ----------------------- | ---- | ----------------------------------------------- |
| userId          | number  | 是   | 表示用户ID。  |
| bundleName      | string  | 是   | 应用包名。    |
| invitationCode  | string  | 是   | 共享邀请码，由共享应用从消息中心获取。   |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;Result&lt;Array&lt;cloudData.sharing.Participant&gt;&gt;&gt; | 返回查询参与者结果的Promise对象。 |

**示例：**

```ts
import cloudExtension from '@ohos.data.cloudExtension';
import cloudData from '@ohos.data.cloudData';

type Participant = cloudData.sharing.Participant;

export default class MyShareCenter implements cloudExtension.ShareCenter {
    constructor() {}
    async queryParticipantsByInvitation(userId: number, bundleName: string, invitationCode: string):
        Promise<cloudExtension.Result<Array<Participant>>> {
        console.info(`query participants by invitation, bundle: ${bundleName}`);
        // 对接云共享服务端，并获得查询参与者的返回值
        ...
        // 返回服务端查询参与者的返回结果
        let privilege = {
            writable: false,
            readable: true,
            creatable: false,
            deletable: false,
            shareable: false
        }
        let participants = new Array();
        participants.push({
           identity: '000000000',
           role: cloudData.sharing.Role.ROLE_INVITEE,
           state: cloudData.sharing.State.STATE_ACCEPTED,
           privilege: privilege,
           attachInfo: ''
        })
        participants.push({
           identity: '111111111',
           role: cloudData.sharing.Role.ROLE_INVITEE,
           state: cloudData.sharing.State.STATE_ACCEPTED,
           privilege: privilege,
           attachInfo: ''
        })
        return {
            code: cloudData.sharing.sharingCode.SUCCESS,
            description: 'query participants by invitation success',
            value: participants
        }
    }
    ...
}
```

### confirmInvitation

confirmInvitation(userId: number, bundleName: string, invitationCode: string, state: cloudData.sharing.State): Promise&lt;Result&lt;string&gt;&gt;

共享的被邀请者确认共享邀请的接口。共享邀请确认时，会指定当前确认邀请的应用、共享数据的的邀请码以及确认状态。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名  | 类型                    | 必填 | 说明                                            |
| ------- | ----------------------- | ---- | ----------------------------------------------- |
| userId          | number  | 是   | 表示用户ID。  |
| bundleName      | string  | 是   | 应用包名。    |
| invitationCode  | string  | 是   | 共享邀请码，由共享应用从消息中心获取。   |
| state           | cloudData.sharing.State  | 是   | 共享邀请的确认状态。   |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;Result&lt;string&gt;&gt; | 返回确认共享邀请数据的共享资源标志（sharingResource）的Promise对象。 |

**示例：**

```ts
import cloudExtension from '@ohos.data.cloudExtension';
import cloudData from '@ohos.data.cloudData';

export default class MyShareCenter implements cloudExtension.ShareCenter {
    constructor() {}
    async confirmInvitation(userId: number, bundleName: string, invitationCode: string, state: cloudData.sharing.State):
        Promise<cloudExtension.Result<string>> {
        console.info(`confirm invitation, bundle: ${bundleName}`);
        // 对接云共享服务端，并获得确认共享邀请的返回值
        ...
        // 返回服务端确认共享邀请的返回结果
        return {
            code: cloudData.sharing.sharingCode.SUCCESS,
            description: 'confirm invitation success',
            value: 'sharing_resource_test'
        }
    }
    ...
}
```

### changeConfirmation

changeConfirmation(userId: number, bundleName: string, sharingResource: string, state: cloudData.sharing.State): Promise&lt;Result&lt;void&gt;&gt;

更改共享邀请的接口。更改共享邀请时，会指定当前更改共享邀请的应用、共享数据的的共享资源标志以及更改的状态。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名  | 类型                    | 必填 | 说明                                            |
| ------- | ----------------------- | ---- | ----------------------------------------------- |
| userId          | number  | 是   | 表示用户ID。  |
| bundleName      | string  | 是   | 应用包名。    |
| sharingResource | string  | 是   | 共享资源标志。   |
| state           | cloudData.sharing.State  | 是   | 共享邀请的更改状态。   |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;Result&lt;void&gt;&gt; | 返回更改共享邀请结果的Promise对象。 |

**示例：**

```ts
import cloudExtension from '@ohos.data.cloudExtension';
import cloudData from '@ohos.data.cloudData';

export default class MyShareCenter implements cloudExtension.ShareCenter {
    constructor() {}
    async changeConfirmation(userId: number, bundleName: string, sharingResource: string, state: cloudData.sharing.State):
        Promise<cloudExtension.Result<void>> {
        console.info(`change confirm, bundle: ${bundleName}`);
        // 对接云共享服务端，并获得更改共享邀请的返回值
        ...
        // 返回服务端更改共享邀请的返回结果
        return {
            code: cloudData.sharing.sharingCode.SUCCESS,
            description: 'change confirm success'
        }
    }
    ...
}
```