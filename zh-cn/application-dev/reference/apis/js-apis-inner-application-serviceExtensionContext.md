# ServiceExtensionContext

ServiceExtensionContext模块是ServiceExtensionAbility的上下文环境，继承自ExtensionContext。

ServiceExtensionContext模块提供ServiceExtensionAbility具有的能力，包括启动、停止、绑定、解绑Ability。

> **说明：**
> 
>  - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>  - 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import common from '@ohos.app.ability.common';
```

## 使用说明

在使用ServiceExtensionContext的功能前，需要通过ServiceExtensionAbility子类实例获取。

```ts
  import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';

  let context;
  let commRemote; // 断开连接时需要释放
  class EntryAbility extends ServiceExtensionAbility {
    onCreate() {
      context = this.context; // 获取ServiceExtensionContext
    }
  }
```

## ServiceExtensionContext.startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void;

启动Ability。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md)  | 是 | Want类型参数，传入需要启动的ability的信息，如Ability名称，Bundle名称等。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，返回接口调用是否成功的结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden.        |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

以上错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

**示例：**

  ```ts
  let want = {
    bundleName: 'com.example.myapp',
    abilityName: 'MyAbility'
  };

  try {
    this.context.startAbility(want, (error) => {
      if (error.code) {
        // 处理业务逻辑错误
        console.error('startAbility failed, error.code: ${error.code}, error.message: ${error.message}');
        return;
      }
      // 执行正常业务
      console.log('startAbility succeed');
    });
  } catch (paramError) {
    // 处理入参错误异常
    console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
  }
  ```

## ServiceExtensionContext.startAbility

startAbility(want: Want, options?: StartOptions): Promise\<void>;

启动Ability，结果以Promise的形式返回。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md)  | 是 | Want类型参数，传入需要启动的ability的信息，如Ability名称，Bundle名称等。 |
| options | [StartOptions](js-apis-app-ability-startOptions.md) | 否 | 启动Ability所携带的参数。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 返回一个Promise，包含启动的结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden.        |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

以上错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

**示例：**

  ```ts
  let want = {
    bundleName: 'com.example.myapp',
    abilityName: 'MyAbility'
  };
  let options = {
  	windowMode: 0,
  };

  try {
    this.context.startAbility(want, options)
      .then((data) => {
        // 执行正常业务
        console.log('startAbility succeed');
      })
      .catch((error) => {
        // 处理业务逻辑错误
        console.error('startAbility failed, error.code: ${error.code}, error.message: ${error.message}');
      });
  } catch (paramError) {
    // 处理入参错误异常
    console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
  }
  ```

## ServiceExtensionContext.startAbility

startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void

启动Ability，结果以Callback的形式返回。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md)  | 是 | 启动Ability的want信息。 |
| options | [StartOptions](js-apis-app-ability-startOptions.md) | 是 | 启动Ability所携带的参数。 |
| callback | AsyncCallback&lt;void&gt; | 是 | callback形式返回启动结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden.        |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

以上错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

**示例：**

  ```ts
  let want = {
    deviceId: '',
    bundleName: 'com.example.myapplication',
    abilityName: 'EntryAbility'
  };
  let options = {
    windowMode: 0
  };

  try {
    this.context.startAbility(want, options, (error) => {
      if (error.code) {
        // 处理业务逻辑错误
        console.error('startAbility failed, error.code: ${error.code}, error.message: ${error.message}');
        return;
      }
      // 执行正常业务
      console.log('startAbility succeed');
    });
  } catch (paramError) {
    // 处理入参错误异常
    console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
  }
  ```

## ServiceExtensionContext.startAbilityWithAccount

startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;

根据account启动Ability（callback形式）。

使用规则：
 - 调用方应用位于后台时，使用该接口启动Ability需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限
 - 跨应用场景下，目标Ability的exported属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限
 - 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)

**需要权限**：ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | 是 | 启动Ability的want信息。 |
| accountId | number | 是 | 系统帐号的帐号ID，详情参考[getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess)。 |
| callback | AsyncCallback\<void\> | 是 | 启动Ability的回调函数。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden.        |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

以上错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

**示例：**

  ```ts
  let want = {
    deviceId: '',
    bundleName: 'com.example.myapplication',
    abilityName: 'EntryAbility'
  };
  let accountId = 100;

  try {
    this.context.startAbilityWithAccount(want, accountId, (error) => {
      if (error.code) {
        // 处理业务逻辑错误
        console.error('startAbilityWithAccount failed, error.code: ${error.code}, error.message: ${error.message}');
        return;
      }
      // 执行正常业务
      console.log('startAbilityWithAccount succeed');
    });
  } catch (paramError) {
    // 处理入参错误异常
    console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
  }
  ```

## ServiceExtensionContext.startAbilityWithAccount

startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback\<void\>): void;

根据account启动Ability（callback形式）。

使用规则：
 - 调用方应用位于后台时，使用该接口启动Ability需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限
 - 跨应用场景下，目标Ability的exported属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限
 - 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)

**需要权限**：ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | 是 | 启动Ability的want信息。 |
| accountId | number | 是 | 系统帐号的帐号ID，详情参考[getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess)。 |
| options | [StartOptions](js-apis-app-ability-startOptions.md) | 是 | 启动Ability所携带的参数。 |
| callback | AsyncCallback\<void\> | 是 | 启动Ability的回调函数。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden.        |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

以上错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

**示例：**

  ```ts
  let want = {
    deviceId: '',
    bundleName: 'com.example.myapplication',
    abilityName: 'EntryAbility'
  };
  let accountId = 100;
  let options = {
    windowMode: 0
  };

  try {
    this.context.startAbilityWithAccount(want, accountId, options, (error) => {
      if (error.code) {
        // 处理业务逻辑错误
        console.error('startAbilityWithAccount failed, error.code: ${error.code}, error.message: ${error.message}');
        return;
      }
      // 执行正常业务
      console.log('startAbilityWithAccount succeed');
    });
  } catch (paramError) {
    // 处理入参错误异常
    console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
  }
  ```


## ServiceExtensionContext.startAbilityWithAccount

startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions): Promise\<void>;

根据account启动Ability（Promise形式）。

使用规则：
 - 调用方应用位于后台时，使用该接口启动Ability需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限
 - 跨应用场景下，目标Ability的exported属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限
 - 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)

**需要权限**：ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | 是 | 启动Ability的want信息。 |
| accountId | number | 是 | 系统帐号的帐号ID，详情参考[getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess)。。 |
| options | [StartOptions](js-apis-app-ability-startOptions.md) | 否 | 启动Ability所携带的参数。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 返回一个Promise，包含接口的结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden.        |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

以上错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

**示例：**

  ```ts
  let want = {
    deviceId: '',
    bundleName: 'com.example.myapplication',
    abilityName: 'EntryAbility'
  };
  let accountId = 100;
  let options = {
    windowMode: 0
  };

  try {
    this.context.startAbilityWithAccount(want, accountId, options)
      .then((data) => {
        // 执行正常业务
        console.log('startAbilityWithAccount succeed');
      })
      .catch((error) => {
        // 处理业务逻辑错误
        console.error('startAbilityWithAccount failed, error.code: ${error.code}, error.message: ${error.message}');
      });
  } catch (paramError) {
    // 处理入参错误异常
    console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
  }
  ```

## ServiceExtensionContext.startServiceExtensionAbility

startServiceExtensionAbility(want: Want, callback: AsyncCallback\<void>): void;

启动一个新的ServiceExtensionAbility（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | 是 | 启动Ability的want信息。 |
| callback | AsyncCallback\<void\> | 是 | 启动Ability的回调函数。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

以上错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

**示例：**

  ```ts
  let want = {
    deviceId: '',
    bundleName: 'com.example.myapplication',
    abilityName: 'EntryAbility'
  };

  try {
    this.context.startServiceExtensionAbility(want, (error) => {
      if (error.code) {
        // 处理业务逻辑错误
        console.error('startServiceExtensionAbility failed, error.code: ${error.code}, error.message: ${error.message}');
        return;
      }
      // 执行正常业务
      console.log('startServiceExtensionAbility succeed');
    });
  } catch (paramError) {
    // 处理入参错误异常
    console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
  }
  ```

## ServiceExtensionContext.startServiceExtensionAbility

startServiceExtensionAbility(want: Want): Promise\<void>;

启动一个新的ServiceExtensionAbility（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | 是 | 启动Ability的want信息。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 返回一个Promise，包含接口的结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

以上错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

**示例：**

  ```ts
  let want = {
    deviceId: '',
    bundleName: 'com.example.myapplication',
    abilityName: 'EntryAbility'
  };

  try {
    this.context.startServiceExtensionAbility(want)
      .then((data) => {
        // 执行正常业务
        console.log('startServiceExtensionAbility succeed');
      })
      .catch((error) => {
        // 处理业务逻辑错误
        console.error('startServiceExtensionAbility failed, error.code: ${error.code}, error.message: ${error.message}');
      });
  } catch (paramError) {
    // 处理入参错误异常
    console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
  }
  ```

## ServiceExtensionContext.startServiceExtensionAbilityWithAccount

startServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;

启动一个新的ServiceExtensionAbility（callback形式）。

> **说明：**
> 
> 当accountId为当前用户时，不需要校验该权限。

**需要权限**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | 是 | 启动Ability的want信息。 |
| accountId | number | 是 | 系统帐号的帐号ID，详情参考[getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess)。 |
| callback | AsyncCallback\<void\> | 是 | 启动Ability的回调函数。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

以上错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。


**示例：**

  ```ts
  let want = {
    deviceId: '',
    bundleName: 'com.example.myapplication',
    abilityName: 'EntryAbility'
  };
  let accountId = 100;

  try {
    this.context.startServiceExtensionAbilityWithAccount(want, accountId, (error) => {
      if (error.code) {
        // 处理业务逻辑错误
        console.error('startServiceExtensionAbilityWithAccount failed, error.code: ${error.code}, error.message: ${error.message}');
        return;
      }
      // 执行正常业务
      console.log('startServiceExtensionAbilityWithAccount succeed');
    });
  } catch (paramError) {
    // 处理入参错误异常
    console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
  }
  ```

## ServiceExtensionContext.startServiceExtensionAbilityWithAccount

startServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise\<void>;

启动一个新的ServiceExtensionAbility（Promise形式）。

> **说明：**
> 
> 当accountId为当前用户时，不需要校验该权限。

**需要权限**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | 是 | 启动Ability的want信息。 |
| accountId | number | 是 | 系统帐号的帐号ID，详情参考[getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess)。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 返回一个Promise，包含接口的结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

以上错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

**示例：**

  ```ts
  let want = {
    deviceId: '',
    bundleName: 'com.example.myapplication',
    abilityName: 'EntryAbility'
  };
  let accountId = 100;

  try {
    this.context.startServiceExtensionAbilityWithAccount(want, accountId)
      .then((data) => {
        // 执行正常业务
        console.log('startServiceExtensionAbilityWithAccount succeed');
      })
      .catch((error) => {
        // 处理业务逻辑错误
        console.error('startServiceExtensionAbilityWithAccount failed, error.code: ${error.code}, error.message: ${error.message}');
      });
  } catch (paramError) {
    // 处理入参错误异常
    console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
  }
  ```

## ServiceExtensionContext.stopServiceExtensionAbility

stopServiceExtensionAbility(want: Want, callback: AsyncCallback\<void>): void;

停止同一应用程序内的服务（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | 是 | 停止Ability的want信息。 |
| callback | AsyncCallback\<void\> | 是 | 停止Ability的回调函数。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000011 | The context does not exist.        |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

以上错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

**示例：**

  ```ts
  let want = {
    deviceId: '',
    bundleName: 'com.example.myapplication',
    abilityName: 'EntryAbility'
  };

  try {
    this.context.stopServiceExtensionAbility(want, (error) => {
      if (error.code) {
        // 处理业务逻辑错误
        console.error('stopServiceExtensionAbility failed, error.code: ${error.code}, error.message: ${error.message}');
        return;
      }
      // 执行正常业务
      console.log('stopServiceExtensionAbility succeed');
    });
  } catch (paramError) {
    // 处理入参错误异常
    console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
  }
  ```

## ServiceExtensionContext.stopServiceExtensionAbility

stopServiceExtensionAbility(want: Want): Promise\<void>;

停止同一应用程序内的服务（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | 是 | 停止Ability的want信息。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 返回一个Promise，包含接口的结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000011 | The context does not exist.        |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

以上错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

**示例：**

  ```ts
  let want = {
    deviceId: '',
    bundleName: 'com.example.myapplication',
    abilityName: 'EntryAbility'
  };

  try {
    this.context.stopServiceExtensionAbility(want)
      .then((data) => {
        // 执行正常业务
        console.log('stopServiceExtensionAbility succeed');
      })
      .catch((error) => {
        // 处理业务逻辑错误
        console.error('stopServiceExtensionAbility failed, error.code: ${error.code}, error.message: ${error.message}');
      });
  } catch (paramError) {
    // 处理入参错误异常
    console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
  }
  ```

## ServiceExtensionContext.stopServiceExtensionAbilityWithAccount

stopServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;

使用帐户停止同一应用程序内的服务（callback形式）。

> **说明：**
> 
> 当accountId为当前用户时，不需要校验该权限。

**需要权限**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | 是 | 停止Ability的want信息。 |
| accountId | number | 是 | 需要停止的系统帐号的帐号ID，详情参考[getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess)。 |
| callback | AsyncCallback\<void\> | 是 | 停止Ability的回调函数。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000011 | The context does not exist.        |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

以上错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

**示例：**

  ```ts
  let want = {
    deviceId: '',
    bundleName: 'com.example.myapplication',
    abilityName: 'EntryAbility'
  };
  let accountId = 100;

  try {
    this.context.stopServiceExtensionAbilityWithAccount(want, accountId, (error) => {
      if (error.code) {
        // 处理业务逻辑错误
        console.error('stopServiceExtensionAbilityWithAccount failed, error.code: ${error.code, error.message: ${error.message}');
        return;
      }
      // 执行正常业务
      console.log('stopServiceExtensionAbilityWithAccount succeed');
    });
  } catch (paramError) {
    // 处理入参错误异常
    console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
  }
  ```

## ServiceExtensionContext.stopServiceExtensionAbilityWithAccount

stopServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise\<void>;

使用帐户停止同一应用程序内的服务（Promise形式）。

> **说明：**
> 
> 当accountId为当前用户时，不需要校验该权限。

**需要权限**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | 是 | 停止Ability的want信息。 |
| accountId | number | 是 | 需要停止的系统帐号的帐号ID，详情参考[getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess)。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 返回一个Promise，包含接口的结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000011 | The context does not exist.        |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

以上错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

**示例：**

  ```ts
  let want = {
    deviceId: '',
    bundleName: 'com.example.myapplication',
    abilityName: 'EntryAbility'
  };
  let accountId = 100;

  try {
    this.context.stopServiceExtensionAbilityWithAccount(want, accountId)
      .then((data) => {
        // 执行正常业务
        console.log('stopServiceExtensionAbilityWithAccount succeed');
      })
      .catch((error) => {
        // 处理业务逻辑错误
        console.error('stopServiceExtensionAbilityWithAccount failed, error.code: ${error.code}, error.message: ${error.message}');
      });
  } catch (paramError) {
    // 处理入参错误异常
    console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
  }
  ```

## ServiceExtensionContext.terminateSelf

terminateSelf(callback: AsyncCallback&lt;void&gt;): void;

停止Ability自身。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，返回接口调用是否成功的结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist.        |
| 16000050 | Internal error. |

以上错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

**示例：**

  ```ts
  this.context.terminateSelf((error) => {
    if (error.code) {
      // 处理业务逻辑错误
      console.error('terminateSelf failed, error.code: ${error.code}, error.message: ${error.message}');
      return;
    }
    // 执行正常业务
    console.log('terminateSelf succeed');
  });
  ```

## ServiceExtensionContext.terminateSelf

terminateSelf(): Promise&lt;void&gt;;

停止ability自身。通过Promise返回结果。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 返回一个Promise，包含接口的结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist.        |
| 16000050 | Internal error. |

以上错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

**示例：**

  ```ts
  this.context.terminateSelf().then((data) => {
    // 执行正常业务
    console.log('terminateSelf succeed');
  }).catch((error) => {
    // 处理业务逻辑错误
    console.error('terminateSelf failed, error.code: ${error.code}, error.message: ${error.message}');
  });
  ```

## ServiceExtensionContext.connectServiceExtensionAbility

connectServiceExtensionAbility(want: Want, options: ConnectOptions): number;

将一个Ability与服务类型的Ability绑定。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md)  | 是 | Want类型参数，传入需要启动的ability的信息，如Ability名称，Bundle名称等。 |
| options | [ConnectOptions](js-apis-inner-ability-connectOptions.md) | 是 | ConnectOptions类型的回调函数，返回服务连接成功、断开或连接失败后的信息。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回一个number，后续根据这个number去断开连接。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16000011 | The context does not exist.        |
| 16000050 | Internal error. |

以上错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

**示例：**

  ```ts
  let want = {
    bundleName: 'com.example.myapp',
    abilityName: 'MyAbility'
  };
  let options = {
    onConnect(elementName, remote) { 
      commRemote = remote;
      console.log('----------- onConnect -----------'); 
    },
    onDisconnect(elementName) { console.log('----------- onDisconnect -----------') },
    onFailed(code) { console.error('----------- onFailed -----------') }
  };

  let connection = null;
  try {
    connection = this.context.connectServiceExtensionAbility(want, options);
  } catch (paramError) {
    // 处理入参错误异常
    console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
  }
  ```

## ServiceExtensionContext.connectServiceExtensionAbilityWithAccount

connectServiceExtensionAbilityWithAccount(want: Want, accountId: number, options: ConnectOptions): number;

使用AbilityInfo.AbilityType.SERVICE模板和account将当前能力连接到一个能力。

**需要权限**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | 是 | 启动Ability的want信息。 |
| accountId | number | 是 | 系统帐号的帐号ID，详情参考[getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess)。 |
| options | ConnectOptions | 是 | 远端对象实例。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回Ability连接的结果code。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16000011 | The context does not exist.        |
| 16000050 | Internal error. |

以上错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

**示例：**

  ```ts
  let want = {
    deviceId: '',
    bundleName: 'com.example.myapplication',
    abilityName: 'EntryAbility'
  };
  let accountId = 100;
  let options = {
    onConnect(elementName, remote) { 
      commRemote = remote;
      console.log('----------- onConnect -----------');
    },
    onDisconnect(elementName) { console.log('----------- onDisconnect -----------'); },
    onFailed(code) { console.log('----------- onFailed -----------'); }
  };

  let connection = null;
  try {
    connection = this.context.connectServiceExtensionAbilityWithAccount(want, accountId, options);
  } catch (paramError) {
    // 处理入参错误异常
    console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
  }
  ```

## ServiceExtensionContext.disconnectServiceExtensionAbility

disconnectServiceExtensionAbility(connection: number, callback:AsyncCallback&lt;void&gt;): void;

将一个Ability与绑定的服务类型的Ability解绑，断开连接之后需要将连接成功时返回的remote对象置空。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| connection | number | 是 | 在connectServiceExtensionAbility中返回的number。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，返回接口调用是否成功的结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000011 | The context does not exist.        |
| 16000050 | Internal error. |

以上错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

**示例：**

  ```ts
  // connection为connectServiceExtensionAbility中的返回值
  let connection = 1;

  try {
    this.context.disconnectServiceExtensionAbility(connection, (error) => {
      commRemote = null;
      if (error.code) {
        // 处理业务逻辑错误
        console.error('disconnectServiceExtensionAbility failed, error.code: ${error.code}, error.message: ${error.message}');
        return;
      }
      // 执行正常业务
      console.log('disconnectServiceExtensionAbility succeed');
    });
  } catch (paramError) {
    commRemote = null;
    // 处理入参错误异常
    console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
  }
  ```

## ServiceExtensionContext.disconnectServiceExtensionAbility

disconnectServiceExtensionAbility(connection: number): Promise&lt;void&gt;;

将一个Ability与绑定的服务类型的Ability解绑，断开连接之后需要将连接成功时返回的remote对象置空(Promise形式返回结果)。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| connection | number | 是 | 在connectServiceExtensionAbility中返回的number。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 返回一个Promise，包含接口的结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000011 | The context does not exist.        |
| 16000050 | Internal error. |

以上错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

**示例：**

  ```ts
  // connection为connectServiceExtensionAbility中的返回值
  let connection = 1;

  try {
    this.context.disconnectServiceExtensionAbility(connection)
      .then((data) => {
        commRemote = null;
        // 执行正常业务
        console.log('disconnectServiceExtensionAbility succeed');
      })
      .catch((error) => {
        commRemote = null;
        // 处理业务逻辑错误
        console.error('disconnectServiceExtensionAbility failed, error.code: ${error.code}, error.message: ${error.message}');
      });
  } catch (paramError) {
    commRemote = null;
    // 处理入参错误异常
    console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
  }
  ```

## ServiceExtensionContext.startAbilityByCall

startAbilityByCall(want: Want): Promise&lt;Caller&gt;;

启动指定Ability至前台或后台，同时获取其Caller通信接口，调用方可使用Caller与被启动的Ability进行通信。

使用规则：
 - 调用方应用位于后台时，使用该接口启动Ability需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限
 - 跨应用场景下，目标Ability的exported属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限
 - 同设备与跨设备场景下，该接口的使用规则存在差异，详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)

**需要权限**: ohos.permission.ABILITY_BACKGROUND_COMMUNICATION

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | 是 | 传入需要启动的Ability的信息，包含abilityName、moduleName、bundleName、deviceId(可选)、parameters(可选)，其中deviceId缺省或为空表示启动本地Ability，parameters缺省或为空表示后台启动Ability。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;Caller&gt; | 获取要通讯的caller对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | Static permission denied. The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |
| 16200001 | The caller has been released.        |

以上错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

**示例：**

  后台启动：

  ```ts
  let caller;

  // 后台启动Ability，不配置parameters
  let wantBackground = {
      bundleName: 'com.example.myservice',
      moduleName: 'entry',
      abilityName: 'EntryAbility',
      deviceId: ''
  };

  try {
    this.context.startAbilityByCall(wantBackground)
      .then((obj) => {
        // 执行正常业务
        caller = obj;
        console.log('startAbilityByCall succeed');
      }).catch((error) => {
        // 处理业务逻辑错误
        console.error('startAbilityByCall failed, error.code: ${error.code}, error.message: ${error.message}');
      });
  } catch (paramError) {
    // 处理入参错误异常
    console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
  }
  ```

  前台启动：

  ```ts
  let caller;

  // 前台启动Ability，将parameters中的'ohos.aafwk.param.callAbilityToForeground'配置为true
  let wantForeground = {
      bundleName: 'com.example.myservice',
      moduleName: 'entry',
      abilityName: 'EntryAbility',
      deviceId: '',
      parameters: {
        'ohos.aafwk.param.callAbilityToForeground': true
      }
  };

  try {
    this.context.startAbilityByCall(wantForeground)
      .then((obj) => {
        // 执行正常业务
        caller = obj;
        console.log('startAbilityByCall succeed');
      }).catch((error) => {
        // 处理业务逻辑错误
        console.error('startAbilityByCall failed, error.code: ${error.code}, error.message: ${error.message}');
      });
  } catch (paramError) {
    // 处理入参错误异常
    console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
  }
  ```
## ServiceExtensionContext.startRecentAbility

startRecentAbility(want: Want, callback: AsyncCallback\<void>): void;

启动一个指定的Ability，如果这个Ability有多个实例，将拉起最近启动的那个实例。启动结果以callback的形式返回开发者。

使用规则：
 - 调用方应用位于后台时，使用该接口启动Ability需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限
 - 跨应用场景下，目标Ability的exported属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限
 - 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | 是 | 需要启动Ability的want信息。 |
| callback | AsyncCallback\<void> | 是 | 指定的回调函数的结果。 |

**错误码：**

以下错误码的详细介绍请参见[errcode-ability](../errorcodes/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

**示例：**

  ```ts
let want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

try {
  this.context.startRecentAbility(want, (err) => {
    if (err.code) {
      // 处理业务逻辑错误
      console.error(`startRecentAbility failed, code is ${err.code}, message is ${err.message}`);
      return;
    }
    // 执行正常业务
    console.info('startRecentAbility succeed');
  });
} catch (err) {
  // 处理入参错误异常
  console.error(`startRecentAbility failed failed, code is ${err.code}, message is ${err.message}`);
}
  ```
## ServiceExtensionContext.startRecentAbility

startRecentAbility(want: Want, options: StartOptions, callback: AsyncCallback\<void>): void;

启动一个指定的Ability，如果这个Ability有多个实例，将拉起最近启动的那个实例。启动结果以callback的形式返回开发者。
当开发者需要携带启动参数时可以选择此API。

使用规则：
 - 调用方应用位于后台时，使用该接口启动Ability需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限
 - 跨应用场景下，目标Ability的exported属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限
 - 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | 是 | 需要启动Ability的want信息。 |
| options | [StartOptions](js-apis-app-ability-startOptions.md) | 是 | 启动Ability所携带的参数。 |
| callback | AsyncCallback\<void> | 是 | 指定的回调函数的结果。 |

**错误码：**

以下错误码的详细介绍请参见[errcode-ability](../errorcodes/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

**示例：**

  ```ts
let want = {
  deviceId: '',
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let options = {
  windowMode: 0
};

try {
  this.context.startRecentAbility(want, options, (err) => {
    if (err.code) {
      // 处理业务逻辑错误
      console.error(`startRecentAbility failed, code is ${err.code}, message is ${err.message}`);
      return;
    }
    // 执行正常业务
    console.info('startRecentAbility succeed');
  });
} catch (err) {
  // 处理入参错误异常
  console.error(`startRecentAbility failed failed, code is ${err.code}, message is ${err.message}`);
}
  ```
## ServiceExtensionContext.startRecentAbility

startRecentAbility(want: Want, options?: StartOptions): Promise\<void>;

启动一个指定的Ability，如果这个Ability有多个实例，将拉起最近启动的那个实例。
当开发者期望启动结果以Promise形式返回时可以选择此API。

使用规则：
 - 调用方应用位于后台时，使用该接口启动Ability需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限
 - 跨应用场景下，目标Ability的exported属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限
 - 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | 是 | 需要启动Ability的want信息。 |
| options | [StartOptions](js-apis-app-ability-startOptions.md) | 否 | 启动Ability所携带的参数。 |

**错误码：**

以下错误码的详细介绍请参见[errcode-ability](../errorcodes/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

**示例：**

  ```ts
let want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let options = {
  windowMode: 0,
};

try {
  this.context.startRecentAbility(want, options)
    .then(() => {
      // 执行正常业务
      console.info('startRecentAbility succeed');
    })
    .catch((err) => {
      // 处理业务逻辑错误
      console.error(`startRecentAbility failed, code is ${err.code}, message is ${err.message}`);
    });
} catch (err) {
  // 处理入参错误异常
  console.error(`startRecentAbility failed, code is ${err.code}, message is ${err.message}`);
}
  ```

## ServiceExtensionContext.startAbilityByCallWithAccount<sup>10+</sup>

startAbilityByCallWithAccount(want: Want, accountId: number): Promise&lt;Caller&gt;;

根据accountId对指定的Ability进行call调用，并且可以使用返回的Caller通信接口与被调用方进行通信。

使用规则：
 - 跨用户场景下，Call调用目标Ability时，调用方应用需同时申请`ohos.permission.ABILITY_BACKGROUND_COMMUNICATION`与`ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS`权限
 - 调用方应用位于后台时，使用该接口启动Ability需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限
 - 跨应用场景下，目标Ability的exported属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限
 - 同设备与跨设备场景下，该接口的使用规则存在差异，详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)

**需要权限**: ohos.permission.ABILITY_BACKGROUND_COMMUNICATION, ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | 是 | 传入需要启动的Ability的信息，包含abilityName、moduleName、bundleName、deviceId(可选)、parameters(可选)，其中deviceId缺省或为空表示启动本地Ability，parameters缺省或为空表示后台启动Ability。 |
| accountId | number | 是 | 系统帐号的帐号ID，-1表示当前活动用户，详情参考[getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess)。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;Caller&gt; | 获取要通讯的caller对象。 |

**错误码：**

以下错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | Static permission denied. The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16200001 | The caller has been released.        |

**示例：**

  ```ts
  let caller;

  // 系统账号的账号ID, -1表示当前激活用户
  let accountId = -1;

  // 指定启动的Ability
  let want = {
      bundleName: 'com.acts.actscalleeabilityrely',
      moduleName: 'entry',
      abilityName: 'EntryAbility',
      deviceId: '',
      parameters: {
        // 'ohos.aafwk.param.callAbilityToForeground' 值设置为true时为前台启动, 设置false或不设置为后台启动
        'ohos.aafwk.param.callAbilityToForeground': true
      }
  };

  try {
    this.context.startAbilityByCallWithAccount(want, accountId)
      .then((obj) => {
        // 执行正常业务
        caller = obj;
        console.log('startAbilityByCallWithAccount succeed');
      }).catch((error) => {
        // 处理业务逻辑错误
        console.error('startAbilityByCallWithAccount failed, error.code: ${error.code}, error.message: ${error.message}');
      });
  } catch (paramError) {
    // 处理入参错误异常
    console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
  }
  ```