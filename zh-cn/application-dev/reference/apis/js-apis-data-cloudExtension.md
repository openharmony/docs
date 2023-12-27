# @ohos.data.cloudExtension (端云共享Extension)

端云共享Extension，提供三方厂商适配共享云服务的能力。通过实现端云共享Extension提供的接口，对接端侧的数据共享到服务端，实现端云共享的发起、取消或退出，更改共享数据的操作权限、查询共享参与者、根据共享邀请码查询共享参与者、确认或更改共享邀请，并支持返回共享云服务的相关结果。
<br>其中，端云共享资源标识是指：对于应用发起共享的每一条数据记录，该条数据在进行端云同步时会生成唯一的共享资源标识（字符串类型的值），此标识则作为该条数据记录共享时的识别标识。
<br>     端云共享参与者是指： 共享发起者根据好友列表选中的参与当前数据共享的所有人员。
<br>     端云共享邀请码是指： 共享发起后，在共享的服务端会生成当前共享操作的邀请码，并将该邀请码附加到当前共享邀请中，通过push消息推送到被邀请者的设备端，被邀请者可以通过该邀请码进行邀请的确认。
<br>     同步云是指： 端云同步的服务端，是同应用同账号跨设备的同步。
<br>     共享云是指： 端云共享的服务端，是同应用跨账号跨设备的共享。

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
| description | string                      | 否   | 错误码详细描述，默认为undefined。       |
| value       | T                           | 否   | 返回结果的值，具体类型由参数T指定，默认为undefined。       |

## cloudExtension.createCloudServiceStub

createCloudServiceStub(instance: CloudService): Promise&lt;rpc.RemoteObject&gt;

根据[CloudService](#cloudservice)类的实例创建对应的[RemoteObject](js-apis-rpc.md#remoteobject)对象，系统内部通过该对象调用[CloudService](#cloudservice)的实现接口，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名    | 类型                            | 必填 | 说明                                                         |
| --------- | ------------------------------- | ---- | -------------------------------- |
| instance  | [CloudService](#cloudservice)   | 是    | [CloudService](#cloudservice)类的实例。   |

**返回值：**

| 类型                | 说明                      |
| -------------------             | ------------------------- |
| Promise&lt;[rpc.RemoteObject](js-apis-rpc.md#remoteobject)&gt; | Promise对象，返回[CloudService](#cloudservice)的[RemoteObject](js-apis-rpc.md#remoteobject)对象。 |

**示例：**

```ts
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
import Want from '@ohos.app.ability.Want';
import rpc from '@ohos.rpc';

export default class MyCloudService implements cloudExtension.CloudService {
  constructor() {}
  async connectShareCenter(userId: number, bundleName: string): Promise<rpc.RemoteObject> {
    // ...
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
    console.info('onDestroy');
  }
}
```

## cloudExtension.createShareServiceStub

createShareServiceStub(instance: ShareCenter): Promise&lt;rpc.RemoteObject&gt;

根据[ShareCenter](#sharecenter)类的实例创建对应的[RemoteObject](js-apis-rpc.md#remoteobject)对象，系统内部通过该对象调用[ShareCenter](#sharecenter)的实现接口，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名    | 类型                            | 必填 | 说明                                                         |
| --------- | ------------------------------- | ---- | -------------------------------- |
| instance  | [ShareCenter](#sharecenter)   | 是    | [ShareCenter](#sharecenter)类的实例。                   |

**返回值：**

| 类型                | 说明                      |
| -------------------             | ------------------------- |
| Promise&lt;[rpc.RemoteObject](js-apis-rpc.md#remoteobject)&gt; | Promise对象，返回[ShareCenter](#sharecenter)的[RemoteObject](js-apis-rpc.md#remoteobject)对象。 |

**示例：**

```ts
import rpc from '@ohos.rpc';

export default class MyShareCenter implements cloudExtension.ShareCenter {
  constructor() {}
  // ...
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

提供对接同步云服务的类。开发者需要继承此类并实现类的接口，系统内部通过该类的接口联接并使用同步云服务。

### connectShareCenter

connectShareCenter(userId: number, bundleName: string): Promise&lt;rpc.RemoteObject&gt;

系统内部通过该接口获取[ShareCenter](#sharecenter)的[RemoteObject](js-apis-rpc.md#remoteobject)对象，可以通过[createShareServiceStub](#cloudextensioncreateshareservicestub)接口进行创建，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名  | 类型                    | 必填 | 说明                                            |
| ------- | ----------------------- | ---- | ----------------------------------------------- |
| userId      | number  | 是   | 表示用户ID。         |
| bundleName  | string  | 是   | 应用包名。   |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[rpc.RemoteObject](js-apis-rpc.md#remoteobject)&gt; | Promise对象，返回[ShareCenter](#sharecenter)的[RemoteObject](js-apis-rpc.md#remoteobject)对象。 |

**示例：**

```ts
import rpc from '@ohos.rpc';

export default class MyShareCenter implements cloudExtension.ShareCenter {
  constructor() {}
  // ...
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

提供对接共享云服务的类。开发者需要继承此类并实现类的接口，系统内部通过该类的接口联接并使用共享云服务，实现端云共享的发起、取消或退出等能力。

### share

share(userId: number, bundleName: string, sharingResource: string, participants: Array&lt;cloudData.sharing.Participant&gt;): Promise&lt;Result&lt;Array&lt;Result&lt;cloudData.sharing.Participant&gt;&gt;&gt;&gt;

发起端云共享邀请。共享邀请时，会指定当前发起共享的应用、共享数据的资源标识和共享参与者，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名  | 类型                    | 必填 | 说明                                            |
| ------- | ----------------------- | ---- | ----------------------------------------------- |
| userId          | number  | 是   | 表示用户ID。  |
| bundleName      | string  | 是   | 应用包名。    |
| sharingResource | string  | 是   | 端云共享资源的标识。   |
| participants    | Array&lt;[cloudData.sharing.Participant](js-apis-data-cloudData.md#participant11)&gt;  | 是   | 端云共享参与者。   |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[Result](#resultt)&lt;Array&lt;[Result](#resultt)&lt;[cloudData.sharing.Participant](js-apis-data-cloudData.md#participant11)&gt;&gt;&gt;&gt; | Promise对象，返回发起共享的结果。 |

**示例：**

```ts
import cloudData from '@ohos.data.cloudData';

type Participant = cloudData.sharing.Participant;

export default class MyShareCenter implements cloudExtension.ShareCenter {
  constructor() {}
  async share(userId: number, bundleName: string, sharingResource: string, participants: Array<Participant>):
    Promise<cloudExtension.Result<Array<cloudExtension.Result<Participant>>>> {
    console.info(`share, bundle: ${bundleName}`);
    // 对接云共享服务端，并获得共享的返回值
    // ...
    // 返回服务端发起共享的返回结果
    let result: Array<cloudExtension.Result<Participant>> = [];
    participants.forEach((item => {
      result.push({
        code: cloudData.sharing.SharingCode.SUCCESS,
        description: 'share succeeded'    
      })
    }))
    return {
      code: cloudData.sharing.SharingCode.SUCCESS,
      description: 'share succeeded',
      value: result
    }
  }
  // ...
}
```

### unshare

unshare(userId: number, bundleName: string, sharingResource: string, participants: Array&lt;cloudData.sharing.Participant&gt;): Promise&lt;Result&lt;Array&lt;Result&lt;cloudData.sharing.Participant&gt;&gt;&gt;&gt;

取消端云共享。取消共享时，会指定当前取消共享的应用、取消共享数据的资源标识和取消共享的参与者，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名  | 类型                    | 必填 | 说明                                            |
| ------- | ----------------------- | ---- | ----------------------------------------------- |
| userId          | number  | 是   | 表示用户ID。  |
| bundleName      | string  | 是   | 应用包名。    |
| sharingResource | string  | 是   | 端云共享资源标识。   |
| participants    | Array&lt;[cloudData.sharing.Participant](js-apis-data-cloudData.md#participant11)&gt;  | 是   | 端云共享参与者。   |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[Result](#resultt)&lt;Array&lt;[Result](#resultt)&lt;[cloudData.sharing.Participant](js-apis-data-cloudData.md#participant11)&gt;&gt;&gt;&gt; | Promise对象，返回取消共享的结果。 |

**示例：**

```ts
import cloudData from '@ohos.data.cloudData';

type Participant = cloudData.sharing.Participant;

export default class MyShareCenter implements cloudExtension.ShareCenter {
  constructor() {}
  async unshare(userId: number, bundleName: string, sharingResource: string, participants: Array<Participant>):
    Promise<cloudExtension.Result<Array<cloudExtension.Result<Participant>>>> {
    console.info(`unshare, bundle: ${bundleName}`);
    // 对接云共享服务端，并获得取消共享的返回值
    // ...
    // 返回服务端取消共享的返回结果
    let result: Array<cloudExtension.Result<Participant>> = [];
    participants.forEach((item => {
      result.push({
        code: cloudData.sharing.SharingCode.SUCCESS,
        description: 'unshare succeeded'    
      })
    }))
    return {
      code: cloudData.sharing.SharingCode.SUCCESS,
      description: 'unshare succeeded',
      value: result
    }
  }
  // ...
}
```

### exit

exit(userId: number, bundleName: string, sharingResource: string): Promise&lt;Result&lt;void&gt;&gt;

退出端云共享。退出共享时，会指定当前退出共享的应用以及退出共享数据的资源标识，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名  | 类型                    | 必填 | 说明                                            |
| ------- | ----------------------- | ---- | ----------------------------------------------- |
| userId          | number  | 是   | 表示用户ID。  |
| bundleName      | string  | 是   | 应用包名。    |
| sharingResource | string  | 是   | 端云共享资源标识。   |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[Result](#resultt)&lt;void&gt;&gt; | Promise对象，返回退出共享的结果。 |

**示例：**

```ts
import cloudData from '@ohos.data.cloudData';

export default class MyShareCenter implements cloudExtension.ShareCenter {
  constructor() {}
  async exit(userId: number, bundleName: string, sharingResource: string):
    Promise<cloudExtension.Result<void>> {
    console.info(`exit share, bundle: ${bundleName}`);
    // 对接云共享服务端，并获得退出共享的返回值
    // ...
    // 返回服务端退出共享的返回结果
    return {
      code: cloudData.sharing.SharingCode.SUCCESS,
      description: 'exit share succeeded'
    }
  }
  // ...
}
```

### changePrivilege

changePrivilege(userId: number, bundleName: string, sharingResource: string, participants: Array&lt;cloudData.sharing.Participant&gt;): Promise&lt;Result&lt;Array&lt;Result&lt;cloudData.sharing.Participant&gt;&gt;&gt;&gt;

更改已共享数据的操作权限。更改权限时，会指定当前更改权限的应用、更改权限数据的资源标识和更改权限的参与者，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名  | 类型                    | 必填 | 说明                                            |
| ------- | ----------------------- | ---- | ----------------------------------------------- |
| userId          | number  | 是   | 表示用户ID。  |
| bundleName      | string  | 是   | 应用包名。    |
| sharingResource | string  | 是   | 端云共享资源标识。   |
| participants    | Array&lt;[cloudData.sharing.Participant](js-apis-data-cloudData.md#participant11)&gt;  | 是   | 端云共享参与者。   |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[Result](#resultt)&lt;Array&lt;[Result](#resultt)&lt;[cloudData.sharing.Participant](js-apis-data-cloudData.md#participant11)&gt;&gt;&gt;&gt; | Promise对象，返回更改权限的结果。 |

**示例：**

```ts
import cloudData from '@ohos.data.cloudData';

type Participant = cloudData.sharing.Participant;

export default class MyShareCenter implements cloudExtension.ShareCenter {
  constructor() {}
  async changePrivilege(userId: number, bundleName: string, sharingResource: string, participants: Array<Participant>):
    Promise<cloudExtension.Result<Array<cloudExtension.Result<Participant>>>> {
    console.info(`change privilege, bundle: ${bundleName}`);
    // 对接云共享服务端，并获得更改权限的返回值
    // ...
    // 返回服务端更改权限的返回结果
    let result: Array<cloudExtension.Result<Participant>> = [];
    participants.forEach((item => {
      result.push({
        code: cloudData.sharing.SharingCode.SUCCESS,
        description: 'change privilege succeeded'    
      })
    }))
    return {
      code: cloudData.sharing.SharingCode.SUCCESS,
      description: 'change privilege succeeded',
      value: result
    }
  }
  // ...
}
```

### queryParticipants

queryParticipants(userId: number, bundleName: string, sharingResource: string): Promise&lt;Result&lt;Array&lt;cloudData.sharing.Participant&gt;&gt;&gt;

查询当前端云共享的参与者。查询时，会指定当前查询参与者的应用、查询参与者数据的资源标识，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名  | 类型                    | 必填 | 说明                                            |
| ------- | ----------------------- | ---- | ----------------------------------------------- |
| userId          | number  | 是   | 表示用户ID。  |
| bundleName      | string  | 是   | 应用包名。    |
| sharingResource | string  | 是   | 端云共享资源标识。   |

**返回值：**

| 类型                                                         | 说明                                    |
| ------------------------------------------------------------ | --------------------------------------- |
| Promise&lt;[Result](#resultt)&lt;Array&lt;[cloudData.sharing.Participant](js-apis-data-cloudData.md#participant11)&gt;&gt;&gt; | Promise对象，返回查询共享参与者的结果。 |

**示例：**

```ts
import cloudData from '@ohos.data.cloudData';

type Participant = cloudData.sharing.Participant;

export default class MyShareCenter implements cloudExtension.ShareCenter {
  constructor() {}
  async queryParticipants(userId: number, bundleName: string, sharingResource: string):
    Promise<cloudExtension.Result<Array<Participant>>> {
    console.info(`query participants, bundle: ${bundleName}`);
    // 对接云共享服务端，并获得查询参与者的返回值
    // ...
    // 返回服务端查询参与者的返回结果
    let participants = new Array<cloudData.sharing.Participant>();
    participants.push({
      identity: '000000000',
      role: cloudData.sharing.Role.ROLE_INVITEE,
      state: cloudData.sharing.State.STATE_ACCEPTED,
      privilege: {
        writable: false,
        readable: true,
        creatable: false,
        deletable: false,
        shareable: false
      },
      attachInfo: ''
    })
    participants.push({
      identity: '111111111',
      role: cloudData.sharing.Role.ROLE_INVITEE,
      state: cloudData.sharing.State.STATE_ACCEPTED,
      privilege: {
        writable: false,
        readable: true,
        creatable: false,
        deletable: false,
        shareable: false
      },
      attachInfo: ''
    })
    return {
      code: cloudData.sharing.SharingCode.SUCCESS,
      description: 'query participants succeeded',
      value: participants
    }
  }
  // ...
}
```

### queryParticipantsByInvitation

queryParticipantsByInvitation(userId: number, bundleName: string, invitationCode: string): Promise&lt;Result&lt;Array&lt;cloudData.sharing.Participant&gt;&gt;&gt;

根据邀请码查询当前端云共享的参与者。查询时，会指定当前查询参与者的应用、共享数据的邀请码，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名  | 类型                    | 必填 | 说明                                            |
| ------- | ----------------------- | ---- | ----------------------------------------------- |
| userId          | number  | 是   | 表示用户ID。  |
| bundleName      | string  | 是   | 应用包名。    |
| invitationCode  | string  | 是   | 端云共享邀请码。   |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[Result](#resultt)&lt;Array&lt;[cloudData.sharing.Participant](js-apis-data-cloudData.md#participant11)&gt;&gt;&gt; | Promise对象，返回根据邀请码查询共享参与者的结果。 |

**示例：**

```ts
import cloudData from '@ohos.data.cloudData';

type Participant = cloudData.sharing.Participant;

export default class MyShareCenter implements cloudExtension.ShareCenter {
  constructor() {}
  async queryParticipantsByInvitation(userId: number, bundleName: string, invitationCode: string):
    Promise<cloudExtension.Result<Array<Participant>>> {
    console.info(`query participants by invitation, bundle: ${bundleName}`);
    // 对接云共享服务端，并获得查询参与者的返回值
    // ...
    // 返回服务端查询参与者的返回结果
    let participants = new Array<cloudData.sharing.Participant>();
    participants.push({
      identity: '000000000',
      role: cloudData.sharing.Role.ROLE_INVITEE,
      state: cloudData.sharing.State.STATE_ACCEPTED,
      privilege: {
        writable: false,
        readable: true,
        creatable: false,
        deletable: false,
        shareable: false
      },
      attachInfo: ''
    })
    participants.push({
      identity: '111111111',
      role: cloudData.sharing.Role.ROLE_INVITEE,
      state: cloudData.sharing.State.STATE_ACCEPTED,
      privilege: {
        writable: false,
        readable: true,
        creatable: false,
        deletable: false,
        shareable: false
      },
      attachInfo: ''
    })
    return {
      code: cloudData.sharing.SharingCode.SUCCESS,
      description: 'query participants by invitation succeeded',
      value: participants
    }
  }
  // ...
}
```

### confirmInvitation

confirmInvitation(userId: number, bundleName: string, invitationCode: string, state: cloudData.sharing.State): Promise&lt;Result&lt;string&gt;&gt;

被邀请者确认端云共享邀请。确认时，会指定当前确认邀请的应用、共享数据的邀请码以及确认状态，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名  | 类型                    | 必填 | 说明                                            |
| ------- | ----------------------- | ---- | ----------------------------------------------- |
| userId          | number  | 是   | 表示用户ID。  |
| bundleName      | string  | 是   | 应用包名。    |
| invitationCode  | string  | 是   | 端云共享邀请码。   |
| state           | [cloudData.sharing.State](js-apis-data-cloudData.md#state11)  | 是   | 共享邀请的确认状态。   |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[Result](#resultt)&lt;string&gt;&gt; | Promise对象，返回确认端云共享邀请数据的共享资源标识。 |

**示例：**

```ts
import cloudData from '@ohos.data.cloudData';

export default class MyShareCenter implements cloudExtension.ShareCenter {
  constructor() {}
  async confirmInvitation(userId: number, bundleName: string, invitationCode: string, state: cloudData.sharing.State):
    Promise<cloudExtension.Result<string>> {
    console.info(`confirm invitation, bundle: ${bundleName}`);
    // 对接云共享服务端，并获得确认共享邀请的返回值
    // ...
    // 返回服务端确认共享邀请的返回结果
    return {
      code: cloudData.sharing.SharingCode.SUCCESS,
      description: 'confirm invitation succeeded',
      value: 'sharing_resource_test'
    }
  }
  // ...
}
```

### changeConfirmation

changeConfirmation(userId: number, bundleName: string, sharingResource: string, state: cloudData.sharing.State): Promise&lt;Result&lt;void&gt;&gt;

更改端云共享邀请。更改共享邀请时，会指定当前更改共享邀请的应用、共享数据的的共享资源标识以及更改的状态,使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名  | 类型                    | 必填 | 说明                                            |
| ------- | ----------------------- | ---- | ----------------------------------------------- |
| userId          | number  | 是   | 表示用户ID。  |
| bundleName      | string  | 是   | 应用包名。    |
| sharingResource | string  | 是   | 端云共享资源标识。   |
| state           | [cloudData.sharing.State](js-apis-data-cloudData.md#state11)  | 是   | 共享邀请的更改状态。   |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[Result](#resultt)&lt;void&gt;&gt; | Promise对象，返回更改共享邀请的结果。 |

**示例：**

```ts
import cloudData from '@ohos.data.cloudData';

export default class MyShareCenter implements cloudExtension.ShareCenter {
  constructor() {}
  async changeConfirmation(userId: number, bundleName: string, sharingResource: string, state: cloudData.sharing.State):
    Promise<cloudExtension.Result<void>> {
    console.info(`change confirm, bundle: ${bundleName}`);
    // 对接云共享服务端，并获得更改共享邀请的返回值
    // ...
    // 返回服务端更改共享邀请的返回结果
    return {
      code: cloudData.sharing.SharingCode.SUCCESS,
      description: 'change confirm succeeded'
    }
  }
  // ...
}
```
## 完整示例

以上示例中的类均采用implements实现，示例代码不能单独编译，需要实现父类中的所有方法才能使用，提供完整示例以作参考。

```ts
import cloudExtension from '@ohos.data.cloudExtension';
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
import Want from '@ohos.app.ability.Want';
import rpc from '@ohos.rpc';
import cloudData from '@ohos.data.cloudData';

type Participant = cloudData.sharing.Participant;

class MyShareCenter implements cloudExtension.ShareCenter {
  constructor() {
  }

  async share(userId: number, bundleName: string, sharingResource: string, participants: Array<Participant>):
    Promise<cloudExtension.Result<Array<cloudExtension.Result<Participant>>>> {
    console.info(`share, bundle: ${bundleName}`);
    // 对接云共享服务端，并获得共享的返回值
    // ...
    // 返回服务端发起共享的返回结果
    let result: Array<cloudExtension.Result<Participant>> = [];
    participants.forEach((item => {
      result.push({
        code: cloudData.sharing.SharingCode.SUCCESS,
        description: 'share succeeded'
      })
    }))
    return {
      code: cloudData.sharing.SharingCode.SUCCESS,
      description: 'share succeeded',
      value: result
    }
  }

  async unshare(userId: number, bundleName: string, sharingResource: string, participants: Array<Participant>):
    Promise<cloudExtension.Result<Array<cloudExtension.Result<Participant>>>> {
    console.info(`unshare, bundle: ${bundleName}`);
    // 对接云共享服务端，并获得取消共享的返回值
    // ...
    // 返回服务端取消共享的返回结果
    let result: Array<cloudExtension.Result<Participant>> = [];
    participants.forEach((item => {
      result.push({
        code: cloudData.sharing.SharingCode.SUCCESS,
        description: 'unshare succeeded'
      })
    }))
    return {
      code: cloudData.sharing.SharingCode.SUCCESS,
      description: 'unshare succeeded',
      value: result
    }
  }

  async exit(userId: number, bundleName: string, sharingResource: string):
    Promise<cloudExtension.Result<void>> {
    console.info(`exit share, bundle: ${bundleName}`);
    // 对接云共享服务端，并获得退出共享的返回值
    // ...
    // 返回服务端退出共享的返回结果
    return {
      code: cloudData.sharing.SharingCode.SUCCESS,
      description: 'exit share succeeded'
    }
  }

  async changePrivilege(userId: number, bundleName: string, sharingResource: string, participants: Array<Participant>):
    Promise<cloudExtension.Result<Array<cloudExtension.Result<Participant>>>> {
    console.info(`change privilege, bundle: ${bundleName}`);
    // 对接云共享服务端，并获得更改权限的返回值
    // ...
    // 返回服务端更改权限的返回结果
    let result: Array<cloudExtension.Result<Participant>> = [];
    participants.forEach((item => {
      result.push({
        code: cloudData.sharing.SharingCode.SUCCESS,
        description: 'change privilege succeeded'
      })
    }))
    return {
      code: cloudData.sharing.SharingCode.SUCCESS,
      description: 'change privilege succeeded',
      value: result
    }
  }

  async queryParticipants(userId: number, bundleName: string, sharingResource: string):
    Promise<cloudExtension.Result<Array<Participant>>> {
    console.info(`query participants, bundle: ${bundleName}`);
    // 对接云共享服务端，并获得查询参与者的返回值
    // ...
    // 返回服务端查询参与者的返回结果
    let participants = new Array<cloudData.sharing.Participant>();
    participants.push({
      identity: '000000000',
      role: cloudData.sharing.Role.ROLE_INVITEE,
      state: cloudData.sharing.State.STATE_ACCEPTED,
      privilege: {
        writable: false,
        readable: true,
        creatable: false,
        deletable: false,
        shareable: false
      },
      attachInfo: ''
    })
    participants.push({
      identity: '111111111',
      role: cloudData.sharing.Role.ROLE_INVITEE,
      state: cloudData.sharing.State.STATE_ACCEPTED,
      privilege: {
        writable: false,
        readable: true,
        creatable: false,
        deletable: false,
        shareable: false
      },
      attachInfo: ''
    })
    return {
      code: cloudData.sharing.SharingCode.SUCCESS,
      description: 'query participants succeeded',
      value: participants
    }
  }

  async queryParticipantsByInvitation(userId: number, bundleName: string, invitationCode: string):
    Promise<cloudExtension.Result<Array<Participant>>> {
    console.info(`query participants by invitation, bundle: ${bundleName}`);
    // 对接云共享服务端，并获得查询参与者的返回值
    // ...
    // 返回服务端查询参与者的返回结果
    let participants = new Array<cloudData.sharing.Participant>();
    participants.push({
      identity: '000000000',
      role: cloudData.sharing.Role.ROLE_INVITEE,
      state: cloudData.sharing.State.STATE_ACCEPTED,
      privilege: {
        writable: false,
        readable: true,
        creatable: false,
        deletable: false,
        shareable: false
      },
      attachInfo: ''
    })
    participants.push({
      identity: '111111111',
      role: cloudData.sharing.Role.ROLE_INVITEE,
      state: cloudData.sharing.State.STATE_ACCEPTED,
      privilege: {
        writable: false,
        readable: true,
        creatable: false,
        deletable: false,
        shareable: false
      },
      attachInfo: ''
    })
    return {
      code: cloudData.sharing.SharingCode.SUCCESS,
      description: 'query participants by invitation succeeded',
      value: participants
    }
  }

  async confirmInvitation(userId: number, bundleName: string, invitationCode: string, state: cloudData.sharing.State):
    Promise<cloudExtension.Result<string>> {
    console.info(`confirm invitation, bundle: ${bundleName}`);
    // 对接云共享服务端，并获得确认共享邀请的返回值
    // ...
    // 返回服务端确认共享邀请的返回结果
    return {
      code: cloudData.sharing.SharingCode.SUCCESS,
      description: 'confirm invitation succeeded',
      value: 'sharing_resource_test'
    }
  }

  async changeConfirmation(userId: number, bundleName: string, sharingResource: string, state: cloudData.sharing.State):
    Promise<cloudExtension.Result<void>> {
    console.info(`change confirm, bundle: ${bundleName}`);
    // 对接云共享服务端，并获得更改共享邀请的返回值
    // ...
    // 返回服务端更改共享邀请的返回结果
    return {
      code: cloudData.sharing.SharingCode.SUCCESS,
      description: 'change confirm succeeded'
    }
  }
}

class MyCloudService implements cloudExtension.CloudService {
  constructor() {
  }

  async connectShareCenter(userId: number, bundleName: string): Promise<rpc.RemoteObject> {
    console.info(`connect share center, bundle: ${bundleName}`);
    return cloudExtension.createShareServiceStub(new MyShareCenter());
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
    console.info('onDestroy');
  }
}
```
