# ServiceExtAbilityContext


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
>
> 本模块首批接口从API version 9开始支持。API 9当前为Canary版本，仅供使用，不保证接口可稳定调用。


## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 参数类型 | 可读 | 可写 | 说明 | 
| -------- | -------- | -------- | -------- | -------- |
| extensionAbilityInfo | ExtensionAbilityInfo | 是 | 否 | ExtensionAbility信息。  | 


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
    console.log('terminateSelf result:' + JSON.stringify(err));
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
    console.log('success:' + JSON.stringify(data));
}).catch((error) => {
    console.log('failed:' + JSON.stringify(error));
});
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

disconnectAbility(connection: number, callback:AsyncCallback\<void>): void

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

disconnectAbility(connection: number): Promise\<void>

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
  console.log('disconnected successfully')
}).catch((err) => {
  console.log('disconnected failed')
})
```