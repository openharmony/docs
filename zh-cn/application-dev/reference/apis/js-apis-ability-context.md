# AbilityContext

AbilityContext是Ability的上下文环境，继承自Context。

AbilityContext模块提供允许访问特定Ability的资源的能力，包括对Ability的启动、停止的设置、获取caller通信接口、拉起弹窗请求用户授权等。

> **说明：**
>
>  - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>  - 本模块接口仅可在Stage模型下使用。

## 使用说明

在使用AbilityContext的功能前，需要通过Ability子类实例获取。

```js
import Ability from '@ohos.application.Ability';
class MainAbility extends Ability {
    onWindowStageCreate(windowStage) {
        let context = this.context;
    }
}
```

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| abilityInfo | AbilityInfo | 是 | 否 | Abilityinfo相关信息 |
| currentHapModuleInfo | HapModuleInfo | 是 | 否 | 当前hap包的信息 |
| config | [Configuration](js-apis-configuration.md) | 是 | 否 | 表示配置信息。 |

## AbilityContext.startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void;

启动Ability（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | 是 | 启动Ability的want信息。 |
| callback | AsyncCallback&lt;void&gt; | 是 | callback形式返回启动结果 |

**示例：**

  ```js
  var want = {
  	"deviceId": "",
  	"bundleName": "com.extreme.test",
  	"abilityName": "MainAbility"
  };
  this.context.startAbility(want, (error) => {
      console.log("error.code = " + error.code)
  })
  ```


## AbilityContext.startAbility

startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void;

启动Ability（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md)  | 是 | 启动Ability的want信息。 |
| options | [StartOptions](js-apis-application-StartOptions.md) | 是 | 启动Ability所携带的参数。 |
| callback | AsyncCallback&lt;void&gt; | 是 | callback形式返回启动结果。 |

**示例：**

  ```js
  var want = {
  	"deviceId": "",
  	"bundleName": "com.extreme.test",
  	"abilityName": "MainAbility"
  };
  var options = {
  	windowMode: 0,
  };
  this.context.startAbility(want, options, (error) => {
      console.log("error.code = " + error.code)
  })
  ```


## AbilityContext.startAbility

startAbility(want: Want, options?: StartOptions): Promise&lt;void&gt;;

启动Ability（promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | 是 | 启动Ability的want信息。 |
| options | [StartOptions](js-apis-application-StartOptions.md) | 否 | 启动Ability所携带的参数。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise形式返回启动结果。 |

**示例：**

  ```js
  var want = {
  	"deviceId": "",
  	"bundleName": "com.extreme.test",
  	"abilityName": "MainAbility"
  };
  var options = {
  	windowMode: 0,
  };
  this.context.startAbility(want, options)
  .then(() => {
      console.log('Operation successful.')
  }).catch((error) => {
      console.log('Operation failed.');
  })
  ```


## AbilityContext.startAbilityForResult

startAbilityForResult(want: Want, callback: AsyncCallback&lt;AbilityResult&gt;): void;

启动Ability并在结束的时候返回执行结果（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-application-Want.md) | 是 | 启动Ability的want信息。 |
| callback | AsyncCallback&lt;[AbilityResult](js-apis-featureAbility.md#abilityresult)&gt; | 是 | 执行结果回调函数。 |


**示例：**

  ```js
  this.context.startAbilityForResult(
      {deviceId: "", bundleName: "com.extreme.myapplication", abilityName: "MainAbilityDemo2"},
      (error, result) => {
          console.log("startAbilityForResult AsyncCallback is called, error.code = " + error.code)
          console.log("startAbilityForResult AsyncCallback is called, result.resultCode = " + result.resultCode)
       }
  );
  ```

## AbilityContext.startAbilityForResult

startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback&lt;AbilityResult&gt;): void;

启动Ability并在结束的时候返回执行结果（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-application-Want.md) | 是 | 启动Ability的want信息。 |
| options | [StartOptions](js-apis-application-StartOptions.md) | 是 | 启动Ability所携带的参数。 |
| callback | AsyncCallback&lt;[AbilityResult](js-apis-featureAbility.md#abilityresult)&gt; | 是 | 执行结果回调函数。 |


**示例：**

  ```js
  var options = {
    windowMode: 0,
  };
  this.context.startAbilityForResult(
      {deviceId: "", bundleName: "com.extreme.myapplication", abilityName: "MainAbilityDemo2"}, options,
      (error, result) => {
          console.log("startAbilityForResult AsyncCallback is called, error.code = " + error.code)
          console.log("startAbilityForResult AsyncCallback is called, result.resultCode = " + result.resultCode)
       }
  );
  ```


## AbilityContext.startAbilityForResult

startAbilityForResult(want: Want, options?: StartOptions): Promise&lt;AbilityResult&gt;;

启动Ability并在结束的时候返回执行结果（promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | 是 | 启动Ability的want信息。 |
| options | [StartOptions](js-apis-application-StartOptions.md) | 否 | 启动Ability所携带的参数。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[AbilityResult](js-apis-featureAbility.md#abilityresult)&gt; | Promise形式返回执行结果。 |

**示例：**

  ```js
  var options = {
    windowMode: 0,
  };
  this.context.startAbilityForResult({deviceId: "", bundleName: "com.extreme.myapplication", abilityName: "MainAbilityDemo2"}, options).then((result) => {
      console.log("startAbilityForResult Promise.resolve is called, result.resultCode = " + result.resultCode)
  }, (error) => {
      console.log("startAbilityForResult Promise.Reject is called, error.code = " + error.code)
  })
  ```

## AbilityContext.startAbilityForResultWithAccount

startAbilityForResultWithAccount(want: Want, accountId: number, callback: AsyncCallback\<AbilityResult>): void;

启动一个Ability并在该Ability帐号销毁时返回执行结果（callback形式）。

**需要权限**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | 是 | 启动Ability的want信息。 |
| accountId | number | 是 | 系统帐号的帐号ID，详情参考[getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess)。 |
| callback | AsyncCallback\<AbilityResult\> | 是 | 启动Ability的回调函数，返回Ability结果。 |

**示例：**

  ```js
  var want = {
    "deviceId": "",
    "bundleName": "com.extreme.test",
    "abilityName": "MainAbility"
  };
  var accountId = 100;
  this.context.startAbilityWithAccount(want, accountId, (err, data) => {
    console.log('---------- startAbilityWithAccount fail, err:  -----------', err);
    console.log('---------- startAbilityWithAccount success, data:  -----------', data);
  });
  ```


## AbilityContext.startAbilityForResultWithAccount

startAbilityForResultWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback\<void\>): void;

启动一个Ability并在该Ability帐号销毁时返回执行结果（callback形式）。

**需要权限**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | 是 | 启动Ability的want信息。 |
| accountId | number | 是 | 系统帐号的帐号ID，详情参考[getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess)。 |
| options | [StartOptions](js-apis-application-StartOptions.md) | 是 | 启动Ability所携带的参数。 |
| callback | AsyncCallback\<void\> | 是 | 启动Ability的回调函数。 |

**示例：**

  ```js
  var want = {
    "deviceId": "",
    "bundleName": "com.extreme.test",
    "abilityName": "MainAbility"
  };
  var accountId = 100;
  var options = {
    windowMode: 0,
  };
  this.context.startAbilityForResultWithAccount(want, accountId, options, (err) => {
    console.log('---------- startAbilityForResultWithAccount fail, err:  -----------', err);
  });
  ```


## AbilityContext.startAbilityForResultWithAccount

startAbilityForResultWithAccount(want: Want, accountId: number, options?: StartOptions): Promise\<AbilityResult\>;

启动一个Ability并在该Ability帐号销毁时返回执行结果（promise形式）。

**需要权限**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | 是 | 启动Ability的want信息。 |
| accountId | number | 是 | 系统帐号的帐号ID，详情参考[getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess)。 |
| options | [StartOptions](js-apis-application-StartOptions.md) | 否 | 启动Ability所携带的参数。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;AbilityResult&gt; | 返回一个Promise，包含Ability结果。 |

**示例：**

  ```js
  var want = {
    "deviceId": "",
    "bundleName": "com.extreme.test",
    "abilityName": "MainAbility"
  };
  var accountId = 100;
  var options = {
    windowMode: 0,
  };
  this.context.startAbilityForResultWithAccount(want, accountId, options)
    .then((data) => {
        console.log('---------- startAbilityForResultWithAccount success, data:  -----------', data);
    })
    .catch((err) => {
        console.log('---------- startAbilityForResultWithAccount fail, err:  -----------', err);
    })
  ```
## AbilityContext.startServiceExtensionAbility

startServiceExtensionAbility(want: Want, callback: AsyncCallback\<void>): void;

启动一个新的ServiceExtensionAbility（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | 是 | 启动Ability的want信息。 |
| callback | AsyncCallback\<void\> | 是 | 启动Ability的回调函数。 |

**示例：**

  ```js
  var want = {
    "deviceId": "",
    "bundleName": "com.extreme.test",
    "abilityName": "MainAbility"
  };
  this.context.startServiceExtensionAbility(want, (err) => {
    console.log('---------- startServiceExtensionAbility fail, err:  -----------', err);
  });
  ```

## AbilityContext.startServiceExtensionAbility

startServiceExtensionAbility(want: Want): Promise\<void>;

启动一个新的ServiceExtensionAbility（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | 是 | 启动Ability的want信息。 |

**示例：**

  ```js
  var want = {
    "deviceId": "",
    "bundleName": "com.extreme.test",
    "abilityName": "MainAbility"
  };
  this.context.startServiceExtensionAbility(want)
    .then(() => {
        console.log('---------- startServiceExtensionAbility success -----------');
    })
    .catch((err) => {
        console.log('---------- startServiceExtensionAbility fail, err:  -----------', err);
    })
  ```
## AbilityContext.startServiceExtensionAbilityWithAccount

startServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;

启动一个新的ServiceExtensionAbility（callback形式）。

**需要权限**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | 是 | 启动Ability的want信息。 |
| accountId | number | 是 | 系统帐号的帐号ID，详情参考[getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess)。 |
| callback | AsyncCallback\<void\> | 是 | 启动Ability的回调函数。 |

**示例：**

  ```js
  var want = {
    "deviceId": "",
    "bundleName": "com.extreme.test",
    "abilityName": "MainAbility"
  };
  var accountId = 100;
  this.context.startServiceExtensionAbilityWithAccount(want,accountId, (err) => {
    console.log('---------- startServiceExtensionAbilityWithAccount fail, err:  -----------', err);
  });
  ```

## AbilityContext.startServiceExtensionAbilityWithAccount

startServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise\<void>;

启动一个新的ServiceExtensionAbility（Promise形式）。

**需要权限**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | 是 | 启动Ability的want信息。 |
| accountId | number | 是 | 系统帐号的帐号ID，详情参考[getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess)。 |

**示例：**

  ```js
  var want = {
    "deviceId": "",
    "bundleName": "com.extreme.test",
    "abilityName": "MainAbility"
  };
  var accountId = 100;
  this.context.startServiceExtensionAbilityWithAccount(want,accountId)
    .then(() => {
        console.log('---------- startServiceExtensionAbilityWithAccount success -----------');
    })
    .catch((err) => {
        console.log('---------- startServiceExtensionAbilityWithAccount fail, err:  -----------', err);
    })
  ```
## AbilityContext.stopServiceExtensionAbility

stopServiceExtensionAbility(want: Want, callback: AsyncCallback\<void>): void;

停止同一应用程序内的服务（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | 是 | 启动Ability的want信息。 |
| callback | AsyncCallback\<void\> | 是 | 启动Ability的回调函数。 |

**示例：**

  ```js
  var want = {
    "deviceId": "",
    "bundleName": "com.extreme.test",
    "abilityName": "MainAbility"
  };
  this.context.stopServiceExtensionAbility(want, (err) => {
    console.log('---------- stopServiceExtensionAbility fail, err:  -----------', err);
  });
  ```

## AbilityContext.stopServiceExtensionAbility

stopServiceExtensionAbility(want: Want): Promise\<void>;

停止同一应用程序内的服务（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | 是 | 启动Ability的want信息。 |

**示例：**

  ```js
  var want = {
    "deviceId": "",
    "bundleName": "com.extreme.test",
    "abilityName": "MainAbility"
  };
  this.context.stopServiceExtensionAbility(want)
    .then(() => {
        console.log('---------- stopServiceExtensionAbility success -----------');
    })
    .catch((err) => {
        console.log('---------- stopServiceExtensionAbility fail, err:  -----------', err);
    })
  ```

## AbilityContext.stopServiceExtensionAbilityWithAccount

stopServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;

使用帐户停止同一应用程序内的服务（callback形式）。

**需要权限**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | 是 | 启动Ability的want信息。 |
| accountId | number | 是 | 系统帐号的帐号ID，详情参考[getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess)。 |
| callback | AsyncCallback\<void\> | 是 | 启动Ability的回调函数。 |

**示例：**

  ```js
  var want = {
    "deviceId": "",
    "bundleName": "com.extreme.test",
    "abilityName": "MainAbility"
  };
  var accountId = 100;
  this.context.stopServiceExtensionAbilityWithAccount(want,accountId, (err) => {
    console.log('---------- stopServiceExtensionAbilityWithAccount fail, err:  -----------', err);
  });
  ```

## AbilityContext.stopServiceExtensionAbilityWithAccount

stopServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise\<void>;

使用帐户停止同一应用程序内的服务（Promise形式）。

**需要权限**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | 是 | 启动Ability的want信息。 |
| accountId | number | 是 | 系统帐号的帐号ID，详情参考[getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess)。 |

**示例：**

  ```js
  var want = {
    "deviceId": "",
    "bundleName": "com.extreme.test",
    "abilityName": "MainAbility"
  };
  var accountId = 100;
  this.context.stopServiceExtensionAbilityWithAccount(want,accountId)
    .then(() => {
        console.log('---------- stopServiceExtensionAbilityWithAccount success -----------');
    })
    .catch((err) => {
        console.log('---------- stopServiceExtensionAbilityWithAccount fail, err:  -----------', err);
    })
  ```

## AbilityContext.terminateSelf

terminateSelf(callback: AsyncCallback&lt;void&gt;): void;

停止Ability自身（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，返回接口调用是否成功的结果。 |

**示例：**

  ```js
  this.context.terminateSelf((err) => {
      console.log('terminateSelf result:' + JSON.stringify(err));
  });
  ```


## AbilityContext.terminateSelf

terminateSelf(): Promise&lt;void&gt;;

停止Ability自身（promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 返回一个Promise，包含接口的结果。 |

**示例：**

  ```js
  this.context.terminateSelf().then(() => {
      console.log('success');
  }).catch((error) => {
      console.log('failed:' + JSON.stringify(error));
  });
  ```


## AbilityContext.terminateSelfWithResult

terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback&lt;void&gt;): void;

停止Ability，配合startAbilityForResult使用，返回给接口调用方AbilityResult信息（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| parameter | [AbilityResult](js-apis-featureAbility.md#abilityresult) | 是 | 返回给调用startAbilityForResult&nbsp;接口调用方的相关信息。 |
| callback | AsyncCallback&lt;void&gt; | 是 | callback形式返回停止结果。 |

**示例：**

  ```js
  var want = {
    "bundleName": "com.extreme.myapplication",
    "abilityName": "SecondAbility"
  }
  var resultCode = 100;
  // 返回给接口调用方AbilityResult信息
  var abilityResult = {
    want,
    resultCode
  }
  this.context.terminateSelfWithResult(abilityResult, (error) => {
          console.log("terminateSelfWithResult is called = " + error.code)
      }
  );
  ```


## AbilityContext.terminateSelfWithResult

terminateSelfWithResult(parameter: AbilityResult): Promise&lt;void&gt;;

停止Ability，配合startAbilityForResult使用，返回给接口调用方AbilityResult信息（promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| parameter | [AbilityResult](js-apis-featureAbility.md#abilityresult) | 是 | 返回给startAbilityForResult&nbsp;调用方的信息。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | promise形式返回停止结果。 |

**示例：**

  ```js
  var want = {
    "bundleName": "com.extreme.myapplication",
    "abilityName": "SecondAbility"
  }
  var resultCode = 100;
  // 返回给接口调用方AbilityResult信息
  var abilityResult = {
    want,
    resultCode
  }
  this.context.terminateSelfWithResult(abilityResult).then((result) => {
      console.log("terminateSelfWithResult")
  }
  )
  ```

## AbilityContext.connectAbility

connectAbility(want: Want, options: ConnectOptions): number;

使用AbilityInfo.AbilityType.SERVICE模板将当前Ability连接到一个Ability。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | 是 | 启动Ability的want信息。 |
| options | [ConnectOptions](js-apis-featureAbility.md#connectoptions) | 否 | 远端对象实例。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回Ability连接的结果code。 |

**示例：**

  ```js
  var want = {
    "deviceId": "",
    "bundleName": "com.extreme.test",
    "abilityName": "MainAbility"
  };
  var options = {
    onConnect(elementName, remote) { console.log('----------- onConnect -----------') },
    onDisconnect(elementName) { console.log('----------- onDisconnect -----------') },
    onFailed(code) { console.log('----------- onFailed -----------') }
  }
  const result = this.context.connectAbility(want, options);
  console.log('----------- connectAbilityResult: ------------', result);
  ```


## AbilityContext.connectAbilityWithAccount

connectAbilityWithAccount(want: Want, accountId: number, options: ConnectOptions): number;

使用AbilityInfo.AbilityType.SERVICE模板和account将当前Ability连接到一个Ability。

**需要权限：** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | 是 | 启动Ability的want信息。 |
| accountId | number | 是 | 系统帐号的帐号ID，详情参考[getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess)。 |
| options | [ConnectOptions](js-apis-featureAbility.md#connectoptions) | 否 | 远端对象实例。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回Ability连接的结果code。 |

**示例：**

  ```js
  var want = {
    "deviceId": "",
    "bundleName": "com.extreme.test",
    "abilityName": "MainAbility"
  };
  var accountId = 100;
  var options = {
    onConnect(elementName, remote) { console.log('----------- onConnect -----------') },
    onDisconnect(elementName) { console.log('----------- onDisconnect -----------') },
    onFailed(code) { console.log('----------- onFailed -----------') }
  }
  const result = this.context.connectAbilityWithAccount(want, accountId, options);
  console.log('----------- connectAbilityResult: ------------', result);
  ```

## AbilityContext.disconnectAbility

disconnectAbility(connection: number): Promise\<void>;

断开连接（promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| connection | number | 是 | 连接的Ability的数字代码。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | 返回执行结果。 |

**示例：**

  ```js
  var connectionNumber = 0;
  this.context.disconnectAbility(connectionNumber).then(() => {
       console.log('disconnectAbility success');
  }).catch((err) => {
       console.log('disconnectAbility fail, err: ', err);
  });
  ```

## AbilityContext.disconnectAbility

disconnectAbility(connection: number, callback:AsyncCallback\<void>): void;

断开连接（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| connection | number | 是 | 连接的Ability的数字代码。 |
| callback | AsyncCallback\<void> | 是 | 表示指定的回调方法。 |

**示例：**

  ```js
    var connectionNumber = 0;
    this.context.disconnectAbility(connectionNumber, (err) => {
       console.log('---------- disconnectAbility fail, err: -----------', err);
    });
  ```

## AbilityContext.startAbilityByCall

startAbilityByCall(want: Want): Promise&lt;Caller&gt;;

启动指定Ability至前台或后台，同时获取其Caller通信接口，调用方可使用Caller与被启动的Ability进行通信。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | 是 | 传入需要启动的Ability的信息，包含abilityName、moduleName、bundleName、deviceId(可选)、parameters(可选)，其中deviceId缺省或为空表示启动本地Ability，parameters缺省或为空表示后台启动Ability。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;Caller&gt; | 获取要通讯的caller对象。 |

**示例：**

  ```js
  let caller = undefined;

  // 后台启动Ability，不配置parameters
  var wantBackground = {
      bundleName: "com.example.myservice",
      moduleName: "entry",
      abilityName: "MainAbility",
      deviceId: ""
  };
  this.context.startAbilityByCall(wantBackground)
    .then((obj) => {
        caller = obj;
        console.log('GetCaller success');
    }).catch((error) => {
        console.log(`GetCaller failed with ${error}`);
    });

  // 前台启动Ability，将parameters中的"ohos.aafwk.param.callAbilityToForeground"配置为true
  var wantForeground = {
      bundleName: "com.example.myservice",
      moduleName: "entry",
      abilityName: "MainAbility",
      deviceId: "",
      parameters: {
        "ohos.aafwk.param.callAbilityToForeground": true
      }
  };
  this.context.startAbilityByCall(wantForeground)
    .then((obj) => {
        caller = obj;
        console.log('GetCaller success');
    }).catch((error) => {
        console.log(`GetCaller failed with ${error}`);
    });
  ```

## AbilityContext.startAbilityWithAccount

startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void\>): void;

根据account启动Ability（callback形式）。

**需要权限**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | 是 | 启动Ability的want信息。 |
| accountId | number | 是 | 系统帐号的帐号ID，详情参考[getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess)。 |
| callback | AsyncCallback\<void\> | 是 | 启动Ability的回调函数。 |

**示例：**

  ```js
  var want = {
    "deviceId": "",
    "bundleName": "com.extreme.test",
    "abilityName": "MainAbility"
  };
  var accountId = 100;
  this.context.startAbilityWithAccount(want, accountId, (err) => {
    console.log('---------- startAbilityWithAccount fail, err:  -----------', err);
  });
  ```


## AbilityContext.startAbilityWithAccount

startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback\<void\>): void;

根据account启动Ability（callback形式）。

**需要权限**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | 是 | 启动Ability的want信息。 |
| accountId | number | 是 | 系统帐号的帐号ID，详情参考[getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess)。|
| options | [StartOptions](js-apis-application-StartOptions.md) | 否 | 启动Ability所携带的参数。 |
| callback | AsyncCallback\<void\> | 是 | 启动Ability的回调函数。 |

**示例：**

  ```js
  var want = {
    "deviceId": "",
    "bundleName": "com.extreme.test",
    "abilityName": "MainAbility"
  };
  var accountId = 100;
  var options = {
    windowMode: 0,
  };
  this.context.startAbilityWithAccount(want, accountId, options, (err) => {
    console.log('---------- startAbilityWithAccount fail, err:  -----------', err);
  });
  ```


## AbilityContext.startAbilityWithAccount

startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions): Promise\<void\>;

根据account启动Ability（Promise形式）。

**需要权限**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | 是 | 启动Ability的want信息。 |
| accountId | number | 是 | 系统帐号的帐号ID，详情参考[getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess)。 |
| options | [StartOptions](js-apis-application-StartOptions.md) | 否 | 启动Ability所携带的参数。 |

**示例：**

  ```js
  var want = {
    "deviceId": "",
    "bundleName": "com.extreme.test",
    "abilityName": "MainAbility"
  };
  var accountId = 100;
  var options = {
    windowMode: 0,
  };
  this.context.startAbilityWithAccount(want, accountId, options)
    .then(() => {
        console.log('---------- startAbilityWithAccount success -----------');
    })
    .catch((err) => {
        console.log('---------- startAbilityWithAccount fail, err:  -----------', err);
    })
  ```

## AbilityContext.requestPermissionsFromUser

requestPermissionsFromUser(permissions: Array&lt;string&gt;, requestCallback: AsyncCallback&lt;PermissionRequestResult&gt;) : void;

拉起弹窗请求用户授权（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| permissions | Array&lt;string&gt; | 是 | 权限列表。 |
| callback | AsyncCallback&lt;[PermissionRequestResult](js-apis-permissionrequestresult.md)&gt; | 是 | 回调函数，返回接口调用是否成功的结果。 |

**示例：**

  ```js
       var permissions=['com.example.permission']
       this.context.requestPermissionsFromUser(permissions,(result) => {
       console.log('requestPermissionsFromUserresult:' + JSON.stringify(result));
  });

  ```


## AbilityContext.requestPermissionsFromUser

requestPermissionsFromUser(permissions: Array&lt;string&gt;) : Promise&lt;PermissionRequestResult&gt;;

拉起弹窗请求用户授权（promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| permissions | Array&lt;string&gt; | 是 | 权限列表。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[PermissionRequestResult](js-apis-permissionrequestresult.md)&gt; | 返回一个Promise，包含接口的结果。 |

**示例：**

  ```js
   var permissions=['com.example.permission']
       this.context.requestPermissionsFromUser(permissions).then((data) => {
      console.log('success:' + JSON.stringify(data));
  }).catch((error) => {
      console.log('failed:' + JSON.stringify(error));
  });

  ```


## AbilityContext.setMissionLabel

setMissionLabel(label: string, callback:AsyncCallback&lt;void&gt;): void;

设置ability在任务中显示的名称（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| label | string | 是 | 显示名称。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，返回接口调用是否成功的结果。 |

**示例：**

  ```js
  this.context.setMissionLabel("test",(result) => {
      console.log('requestPermissionsFromUserresult:' + JSON.stringify(result));
  });
  ```


## AbilityContext.setMissionLabel

setMissionLabel(label: string): Promise&lt;void&gt;;

设置ability在任务中显示的名称（promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| label | string | 是 | 显示名称。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 返回一个Promise，包含接口的结果。 |

**示例：**

  ```js
  this.context.setMissionLabel("test").then(() => {
      console.log('success');
  }).catch((error) => {
      console.log('failed:' + JSON.stringify(error));
  });
  ```
## AbilityContext.setMissionIcon

setMissionIcon(icon: image.PixelMap, callback:AsyncCallback\<void>): void;

设置当前ability在任务中显示的图标（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| icon | image.PixelMap | 是 | 在最近的任务中显示的ability图标。 |
| callback | AsyncCallback\<void> | 是 | 指定的回调函数的结果。 |

**示例：**

  ```js
    import image from '@ohos.multimedia.image';
    var imagePixelMap;
    var color = new ArrayBuffer(0);
    var initializationOptions = {
       size: {
           height: 100,
           width: 100
       }
    };
    image.createPixelMap(color, initializationOptions)
       .then((data) => {
           imagePixelMap = data;
       })
       .catch((err) => {
           console.log('--------- createPixelMap fail, err: ---------', err)
       });
    this.context.setMissionIcon(imagePixelMap, (err) => {
       console.log('---------- setMissionIcon fail, err: -----------', err);
    })
  ```


## AbilityContext.setMissionIcon

setMissionIcon(icon: image.PixelMap): Promise\<void>;

设置当前ability在任务中显示的图标（promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| icon | image.PixelMap | 是 | 在最近的任务中显示的ability图标。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 返回一个Promise，包含接口的结果。 |

**示例：**

  ```js
    import image from '@ohos.multimedia.image';
    var imagePixelMap;
    var color = new ArrayBuffer(0);
    var initializationOptions = {
      size: {
          height: 100,
          width: 100
      }
    };
    image.createPixelMap(color, initializationOptions)
      .then((data) => {
          imagePixelMap = data;
      })
      .catch((err) => {
          console.log('--------- createPixelMap fail, err: ---------', err)
      });
    this.context.setMissionIcon(imagePixelMap)
      .then(() => {
          console.log('-------------- setMissionIcon success -------------');
      })
      .catch((err) => {
          console.log('-------------- setMissionIcon fail, err: -------------', err);
      });
  ```
## AbilityContext.restoreWindowStage

restoreWindowStage(localStorage: LocalStorage) : void;

恢复ability中的window stage数据。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| localStorage | image.LocalStorage | 是 | 用于恢复window stage的存储数据。 |

**示例：**

  ```js
    var storage = new LocalStorage();
    this.context.restoreWindowStage(storage);
  ```

## AbilityContext.isTerminating

isTerminating(): boolean;

查询ability是否在terminating状态。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| bool | true：ability当前处于terminating状态；false：不处于terminating状态。 |

**示例：**

  ```js
  var isTerminating = this.context.isTerminating();
  console.log('ability state :' + isTerminating);
  ```