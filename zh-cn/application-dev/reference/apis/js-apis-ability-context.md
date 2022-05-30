# Ability Context

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 9开始支持。API 9当前为Canary版本，仅供使用，不保证接口可稳定调用。

Ability的上下文环境，继承自Context。

# 导入模块

```js
import Ability from '@ohos.application.Ability'
```

## 使用说明
在使用AbilityContext的功能前，需要通过Ability子类实例获取。
```js
import Ability from '@ohos.application.Ability'
class MainAbility extends Ability {
    onWindowStageCreate(windowStage) {
        let context = this.context;
    }
}
```

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称                  | 参数类型        | 可读    | 可写    | 描述                                 |
| --------------------- | --------------- | ------ | ------- | ----------------------------------- |
| config                | Configuration   | 是     | 否      | 显示的配置信息。                      |
| abilityInfo           | AbilityInfo   | 是     | 否      | Abilityinfo相关信息。                  |
| currentHapModuleInfo  | HapModuleInfo   | 是     | 否      | 当前hap包的信息。                    |


## startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void

启动Ability。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 | 
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-featureAbility.md#Want) | 是 | 启动Ability的want信息。 | 
| callback | AsyncCallback&lt;void&gt; | 是 | callback形式返回启动结果。 | 

**示例**：

```js
var want = {
  "deviceId": "",
  "bundleName": "com.extreme.test",
  "abilityName": "com.extreme.test.MainAbility"
};
this.context.startAbility(want, (error) => {
    console.log("error.code = " + error.code)
})
```

## startAbility

startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void

启动Ability（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 | 
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-featureAbility.md#Want)  | 是 | 启动Ability的want信息。 | 
| options | StartOptions | 是 | 启动Ability所携带的参数。 |
| callback | AsyncCallback&lt;void&gt; | 是 | callback形式返回启动结果。 | 

**示例**：
    
```js
var want = {
  "deviceId": "",
  "bundleName": "com.extreme.test",
  "abilityName": "com.extreme.test.MainAbility"
};
var options = {
  windowMode: 0,
};
this.context.startAbility(want, options, (error) => {
    console.log("error.code = " + error.code)
})
```


## startAbility

startAbility(want: Want, options: StartOptions): Promise&lt;void&gt;

启动Ability（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 | 
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-featureAbility.md#Want) | 是 | 启动Ability的want信息。 | 
| options | StartOptions | 是 | 启动Ability所携带的参数。 |

**返回值**：

| 类型 | 说明 | 
| -------- | -------- |
| Promise&lt;void&gt; | Promise形式返回启动结果。 | 

**示例**：
```js
var want = {
  "deviceId": "",
  "bundleName": "com.extreme.test",
  "abilityName": "com.extreme.test.MainAbility"
};
var options = {
  windowMode: 0,
};
this.context.startAbility(want, options)
.then((data) => {
    console.log('Operation successful.')
}).catch((error) => {
    console.log('Operation failed.');
})
```

## startAbilityByCall

startAbilityByCall(want: Want): Promise&lt;Caller&gt;

获取指定通用组件服务端的caller通信接口, 并且将指定通用组件服务端拉起并切换到后台。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 | 
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-featureAbility.md#Want) | 是 | 传入需要启动的ability的信息，包含ability名称、包名、设备ID，设备ID缺省或为空表示启动本地ability。 | 

**返回值**：

| 类型 | 说明 | 
| -------- | -------- |
| Promise&lt;Caller&gt; | 获取要通讯的caller对象。 | 

**示例**：
    
```js
import Ability from '@ohos.application.Ability';
var caller;
export default class MainAbility extends Ability {
    onWindowStageCreate(windowStage) {
        this.context.startAbilityByCall({
            bundleName: "com.example.myservice",
            abilityName: "com.example.myservice.MainAbility",
            deviceId: ""
        }).then((obj) => {
            caller = obj;
            console.log('Caller GetCaller Get ' + call);
        }).catch((e) => {
            console.log('Caller GetCaller error ' + e);
        });
    }
}
```

## startAbilityWithAccount

startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void

通过账户启动Ability（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 | 
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-featureAbility.md#Want) | 是 | 启动Ability的want信息。 | 
| accountId | number                   | 是 | 账户ID。                  | 
| callback | AsyncCallback&lt;void&gt; | 是 | callback形式返回启动结果。 | 

**示例**：

```js
var want = {
  "deviceId": "",
  "bundleName": "com.extreme.test",
  "abilityName": "com.extreme.test.MainAbility"
};
var accountId = 11;
this.context.startAbility(want, accountId, (error) => {
    console.log("error.code = " + error.code)
})
```

## startAbilityWithAccount

startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback\<void>): void

通过账户启动Ability（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 | 
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-featureAbility.md#Want)  | 是 | 启动Ability的want信息。 | 
| accountId | number                   | 是 | 账户ID。                  | 
| options | StartOptions | 是 | 启动Ability所携带的参数。 |
| callback | AsyncCallback&lt;void&gt; | 是 | callback形式返回启动结果。 | 

**示例**：
    
```js
var want = {
  "deviceId": "",
  "bundleName": "com.extreme.test",
  "abilityName": "com.extreme.test.MainAbility"
};
var options = {
  windowMode: 0,
};
var accountId = 11;
this.context.startAbility(want, accountId, options, (error) => {
    console.log("error.code = " + error.code)
})
```


## startAbilityWithAccount

startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions): Promise\<void>

通过账户启动Ability（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 | 
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-featureAbility.md#Want) | 是 | 启动Ability的want信息。 | 
| accountId | number                   | 是 | 账户ID。                  |
| options | StartOptions | 否 | 启动Ability所携带的参数。 |

**返回值**：

| 类型 | 说明 | 
| -------- | -------- |
| Promise&lt;void&gt; | Promise形式返回启动结果。 | 

**示例**：
```js
var want = {
  "deviceId": "",
  "bundleName": "com.extreme.test",
  "abilityName": "com.extreme.test.MainAbility"
};
var options = {
  windowMode: 0,
};
var accountId = 11;
this.context.startAbility(want, accountId, options)
.then((data) => {
    console.log('Operation successful.')
}).catch((error) => {
    console.log('Operation failed.');
})
```

## startAbilityForResult

startAbilityForResult(want: Want, callback: AsyncCallback&lt;AbilityResult&gt;): void

启动Ability并在结束的时候返回执行结果（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-featureAbility.md#Want) | 是 | 启动Ability的want信息。 |
| callback | AsyncCallback&lt;[AbilityResult](js-apis-featureAbility.md#AbilityResult)&gt; | 是 | 执行结果回调函数。 |

**示例**：

```js
this.context.startAbilityForResult(
    {bundleName: "com.extreme.myapplication", abilityName: "MainAbilityDemo2"},
    (error, result) => {
      console.log("startAbilityForResult AsyncCallback is called, error.code = " + error.code)
      console.log("startAbilityForResult AsyncCallback is called, result.resultCode = " + result.resultCode)
    }
);
```

## startAbilityForResult

startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback&lt;AbilityResult&gt;): void

启动Ability并在结束的时候返回执行结果（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-featureAbility.md#Want) | 是 | 启动Ability的want信息。 |
| options | StartOptions | 是 | 启动Ability所携带的参数。 |
| callback | AsyncCallback&lt;[AbilityResult](js-apis-featureAbility.md#AbilityResult)&gt; | 是 | 执行结果回调函数。 |

**示例**：

```js
var options = {
  windowMode: 0,
};
this.context.startAbilityForResult(
    {bundleName: "com.extreme.myapplication", abilityName: "MainAbilityDemo2"}, options,
    (error, result) => {
      console.log("startAbilityForResult AsyncCallback is called, error.code = " + error.code)
      console.log("startAbilityForResult AsyncCallback is called, result.resultCode = " + result.resultCode)
    }
);
```


## startAbilityForResult

startAbilityForResult(want: Want, options: StartOptions): Promise&lt;AbilityResult&gt;;

启动Ability并在结束的时候返回执行结果（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 | 
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-featureAbility.md#Want) | 是 | 启动Ability的want信息。 |
| options | StartOptions | 是 | 启动Ability所携带的参数。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[AbilityResult](js-apis-featureAbility.md#AbilityResult)&gt; | Promise形式返回执行结果。 |

**示例**：
```js
var options = {
  windowMode: 0,
};
this.context.startAbilityForResult({bundleName: "com.extreme.myapplication", abilityName: "MainAbilityDemo2"}, options).then((result) => {
    console.log("startAbilityForResult Promise.resolve is called, result.resultCode = " + result.resultCode)
}, (error) => {
    console.log("startAbilityForResult Promise.Reject is called, error.code = " + error.code)
})
```

## startAbilityForResultWithAccount

startAbilityForResultWithAccount(want: Want, accountId: number, callback: AsyncCallback\<AbilityResult>): void

通过账户启动Ability并在结束的时候返回执行结果（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-featureAbility.md#Want) | 是 | 启动Ability的want信息。 |
| accountId | number                   | 是 | 账户ID。                  |
| callback | AsyncCallback&lt;[AbilityResult](js-apis-featureAbility.md#AbilityResult)&gt; | 是 | 执行结果回调函数。 |

**示例**：

```js
var accountId = 111;
this.context.startAbilityForResult(
    {bundleName: "com.extreme.myapplication", abilityName: "MainAbilityDemo2"},
    accountId, 
    (error, result) => {
      console.log("startAbilityForResult AsyncCallback is called, error.code = " + error.code)
      console.log("startAbilityForResult AsyncCallback is called, result.resultCode = " + result.resultCode)
    }
);
```

## startAbilityForResultWithAccount

startAbilityForResultWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback\<void>): void

通过账户启动Ability并在结束的时候返回执行结果（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-featureAbility.md#Want) | 是 | 启动Ability的want信息。 |
| accountId | number                   | 是 | 账户ID。                  |
| options | StartOptions | 是 | 启动Ability所携带的参数。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 执行结果回调函数。 |

**示例**：

```js
var options = {
  windowMode: 0,
};
var accountId = 111;
this.context.startAbilityForResult(
    {bundleName: "com.extreme.myapplication", abilityName: "MainAbilityDemo2"}, 
    accountId, 
    options,
    () => {
      console.log("startAbilityForResult AsyncCallback is called")
    }
);
```

## startAbilityForResultWithAccount

startAbilityForResultWithAccount(want: Want, accountId: number, options?: StartOptions): Promise\<AbilityResult>;

通过账户启动Ability并在结束的时候返回执行结果（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 | 
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-featureAbility.md#Want) | 是 | 启动Ability的want信息。 |
| accountId | number                   | 是 | 账户ID。                  |
| options | StartOptions | 是 | 启动Ability所携带的参数。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[AbilityResult](js-apis-featureAbility.md#AbilityResult)&gt; | Promise形式返回执行结果。 |

**示例**：

```js
var accountId = 111;
var options = {
  windowMode: 0,
};
this.context.startAbilityForResult({bundleName: "com.extreme.myapplication", abilityName: "MainAbilityDemo2"}, accountId, options).then((result) => {
    console.log("startAbilityForResult Promise.resolve is called, result.resultCode = " + result.resultCode)
}, (error) => {
    console.log("startAbilityForResult Promise.Reject is called, error.code = " + error.code)
})
```

## terminateSelf

terminateSelf(callback: AsyncCallback&lt;void&gt;): void

停止Ability自身（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 | 
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，返回接口调用是否成功的结果。 | 

**示例**：

```js
this.context.terminateSelf((err) => {
    console.log('terminateSelf result:' + JSON.stringfy(err));
});
```

## terminateSelf

terminateSelf(): Promise&lt;void&gt;

停止Ability自身（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值**：

| 类型 | 说明 | 
| -------- | -------- |
| Promise&lt;void&gt; | 返回一个Promise，包含接口的结果。 | 

**示例**：

```js
this.context.terminateSelf(want).then((data) => {
    console.log('success:' + JSON.stringfy(data));
}).catch((error) => {
    console.log('failed:' + JSON.stringfy(error));
});
```

## terminateSelfWithResult

terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback&lt;void&gt;): void

停止Ability，并返回给调用startAbilityForResult 接口调用方的相关信息（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| parameter | [AbilityResult](js-apis-featureAbility.md#AbilityResult) | 是 | 返回给调用startAbilityForResult&nbsp;接口调用方的相关信息。 |
| callback | AsyncCallback&lt;void&gt; | 是 | callback形式返回停止结果。 |

**示例**：

```js
this.context.terminateSelfWithResult(
    {
        want: {bundleName: "com.extreme.myapplication", abilityName: "MainAbilityDemo"},
        resultCode: 100
    }, (error) => {
        console.log("terminateSelfWithResult is called = " + error.code)
    }
);
```


## terminateSelfWithResult

terminateSelfWithResult(parameter: AbilityResult): Promise&lt;void&gt;

停止Ability，并返回给调用startAbilityForResult 接口相关信息（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| parameter | [AbilityResult](js-apis-featureAbility.md#AbilityResult) | 是 | 返回给startAbilityForResult&nbsp;调用方的信息。 |

**返回值**：
| 类型 | 说明 | 
| -------- | -------- |
| Promise&lt;void&gt; | promise形式返回停止结果。 | 

**示例**：
```js
this.context.terminateSelfWithResult(
{
    want: {bundleName: "com.extreme.myapplication", abilityName: "MainAbilityDemo"},
    resultCode: 100
}).then((result) => {
    console.log("terminateSelfWithResult")
})
```

## connectAbility

connectAbility(want: Want, options: ConnectOptions): number

使用AbilityInfo.AbilityType.SERVICE模板将当前能力连接到一个能力。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 | 
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-featureAbility.md#Want) | 是 | 启动Ability的want信息。 |
| options | ConnectOptions | 是 | 连接的远端对象实例 |

**返回值**:

| 类型 | 说明 | 
| -------- | -------- |
| number | 连接Ability的代码 |

**示例**：
```js
var want = {
  "deviceId": "",
  "bundleName": "com.extreme.test",
  "abilityName": "com.extreme.test.MainAbility"
}
var options = {
  onConnect: (elementName, remote) => {
    console.log('connectAbility onConnect, elementName: ' + elementName + ', remote: ' remote)
  },
  onDisconnect: (elementName) => {
    console.log('connectAbility onDisconnect, elementName: ' + elementName)
  },
  onFailed: (code) => {
    console.log('connectAbility onFailed, code: ' + code)
  }
}
this.context.connectAbility(want, options) {
  console.log('code: ' + code)
}
```

## connectAbilityWithAccount

connectAbilityWithAccount(want: Want, accountId: number, options: ConnectOptions): number

使用AbilityInfo.AbilityType.SERVICE模板和账户ID将当前能力连接到一个能力。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 | 
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-featureAbility.md#Want) | 是 | 启动Ability的want信息。 |
| accountId | number | 是 | 账户ID |
| options | ConnectOptions | 是 | 连接的远端对象实例 |

**返回值**:

| 类型 | 说明 | 
| -------- | -------- |
| number | 连接Ability的代码 |

**示例**：
```js
var want = {
  "deviceId": "",
  "bundleName": "com.extreme.test",
  "abilityName": "com.extreme.test.MainAbility"
}
var accountId = 111;
var options = {
  onConnect: (elementName, remote) => {
    console.log('connectAbility onConnect, elementName: ' + elementName + ', remote: ' remote)
  },
  onDisconnect: (elementName) => {
    console.log('connectAbility onDisconnect, elementName: ' + elementName)
  },
  onFailed: (code) => {
    console.log('connectAbility onFailed, code: ' + code)
  }
}
this.context.connectAbility(want, accountId, options) {
  console.log('code: ' + code)
}
```

## disconnectAbility

disconnectAbility(connection: number, callback:AsyncCallback<void>): void

断开Ability连接（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 | 
| -------- | -------- | -------- | -------- |
| connection | number | 是 | 连接的Ability的编号。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 断开Ability连接的回调函数。 |

**示例**：

```js
var connection = 111;
this.context.disconnectAbility(connection, () => {
  console.log('disconnection')
})
```

## disconnectAbility

disconnectAbility(connection: number): Promise<void>

断开Ability连接（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 | 
| -------- | -------- | -------- | -------- |
| connection | number | 是 | 连接的Ability的编号。 |

**返回值**：

| 类型 | 说明 | 
| -------- | -------- |
| Promise&lt;void&gt; | 返回一个Promise。 | 

**示例**：

```js
var connection = 111;
this.context.disconnectAbility(connection).then(() => {
  console.log('disconnect success')
}).catch((err) => {
  console.log('disconnect filed')
})
```

## setMissionLabel

setMissionLabel(label: string, callback:AsyncCallback&lt;void&gt;): void

设置ability在任务中显示的名称（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 | 
| -------- | -------- | -------- | -------- |
| label | string | 是 | 显示名称。 | 
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，返回接口调用是否成功的结果。 | 

**示例**：
    
```js
this.context.setMissionLabel("test",(result) => {
    console.log('requestPermissionsFromUserresult:' + JSON.stringfy(result));
});
```


## setMissionLabel

setMissionLabel(label: string): Promise\<void>

设置ability在任务中显示的名称（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 | 
| -------- | -------- | -------- | -------- |
| label | string | 是 | 显示名称。 | 

**返回值**：

| 类型 | 说明 | 
| -------- | -------- |
| Promise&lt;void&gt; | 返回一个Promise，包含接口的结果。 | 

**示例**：
    
```js
this.context.setMissionLabel("test").then((data) => {
    console.log('success:' + JSON.stringfy(data));
}).catch((error) => {
    console.log('failed:' + JSON.stringfy(error));
});
```

## requestPermissionsFromUser

requestPermissionsFromUser(permissions: Array&lt;string&gt;, requestCallback: AsyncCallback&lt;PermissionRequestResult&gt;) : void

拉起弹窗请求用户授权（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 | 
| -------- | -------- | -------- | -------- |
| permissions | Array&lt;string&gt; | 是 | 权限列表。 | 
| callback | AsyncCallback&lt;PermissionRequestResult&gt; | 是 | 回调函数，返回接口调用是否成功的结果。 | 

**示例**：
    
```js
this.context.requestPermissionsFromUser(permissions,(result) => {
    console.log('requestPermissionsFromUserresult:' + JSON.stringfy(result));
});
```


## requestPermissionsFromUser

requestPermissionsFromUser(permissions: Array&lt;string&gt;) : Promise&lt;PermissionRequestResult&gt;

拉起弹窗请求用户授权。通过Promise返回结果。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 | 
| -------- | -------- | -------- | -------- |
| permissions | Array&lt;string&gt; | 是 | 权限列表。 | 

**返回值**：

| 类型 | 说明 | 
| -------- | -------- |
| Promise&lt;PermissionRequestResult&gt; | 返回一个Promise，包含接口的结果。 | 

**示例**：
    
```js
this.context.requestPermissionsFromUser(permissions).then((data) => {
    console.log('success:' + JSON.stringfy(data));
}).catch((error) => {
    console.log('failed:' + JSON.stringfy(error));
});
```

## restoreWindowStage

restoreWindowStage(contentStorage: ContentStorage) : void

恢复Ability延续中的窗口阶段数据。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 | 
| -------- | -------- | -------- | -------- |
| contentStorage | ContentStorage | 是 | 用于恢复窗口阶段的存储数据。 | 

**示例**：

```js
var contentStorage = {
  "link": 'link',
};
this.context.restoreWindowStage(contentStorage);
```