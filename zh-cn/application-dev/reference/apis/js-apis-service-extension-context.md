# ServiceExtensionContext

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


ServiceExtension的上下文环境，提供ServiceExtension具有的能力和接口，继承自ExtensionContext。


## startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void;

启动Ability。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | want | [Want](js-apis-featureAbility.md#Want类型说明)  | 是 | Want类型参数，传入需要启动的ability的信息，如ability名称，包名等。 | 
  | callback | AsyncCallback&lt;void&gt; | 否 | 回调函数，返回接口调用是否成功的结果。 | 

**示例：**

  ```js
  let want = {
      "bundleName": "com.example.myapp",
      "abilityName": "com.example.myapp.MyAbility"
  };
  this.context.startAbility(want, (err) => {
      console.log('startAbility result:' + JSON.stringify(err));
  });
  ```


## ServiceExtensionContext.startAbility

startAbility(want: Want): Promise&lt;void&gt;;

启动Ability。通过Promise返回结果。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | want | [Want](js-apis-featureAbility.md#Want类型说明)  | 是 | Want类型参数，传入需要启动的ability的信息，如ability名称，包名等。 | 

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;void&gt; | 返回一个Promise，包含接口的结果。 | 

**示例：**

  ```js
  let want = {
      "bundleName": "com.example.myapp",
      "abilityName": "com.example.myapp.MyAbility"
  };
  this.context.startAbility(want).then((data) => {
      console.log('success:' + JSON.stringify(data));
  }).catch((error) => {
      console.log('failed:' + JSON.stringify(error));
  });
  ```


## ServiceExtensionContext.terminateSelf

terminateSelf(callback: AsyncCallback&lt;void&gt;): void;

停止Ability自身。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | 否 | 回调函数，返回接口调用是否成功的结果。 | 

**示例：**

  ```js
  this.context.terminateSelf((err) => {
      console.log('terminateSelf result:' + JSON.stringify(err));
  });
  ```


## ServiceExtensionContext.terminateSelf

terminateSelf(): Promise&lt;void&gt;;

停止自身。通过Promise返回结果。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;void&gt; | 返回一个Promise，包含接口的结果。 | 

**示例：**

  ```js
  this.context.terminateSelf(want).then((data) => {
      console.log('success:' + JSON.stringify(data));
  }).catch((error) => {
      console.log('failed:' + JSON.stringify(error));
  });
  ```


## ServiceExtensionContext.connectAbility

connectAbility(want: Want, options: ConnectOptions): number;

将一个Ability与服务类型的Ability绑定。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | want | [Want](js-apis-featureAbility.md#Want类型说明)  | 是 | Want类型参数，传入需要启动的ability的信息，如ability名称，包名等。 | 
  | options | [ConnectOptions](#connectoptions) | 是 | ConnectOptions类型的回调函数，返回服务连接成功、断开或连接失败后的信息。 | 

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | number | 返回一个number，后续根据这个number去断开连接。 | 

**示例：**

  ```js
  let want = {
      "bundleName": "com.example.myapp",
      "abilityName": "com.example.myapp.MyAbility"
  };
  let options = {
      onConnect: function(elementName, proxy) {},
      onDisConnect: function(elementName) {},
      onFailed: function(code) {}
  }
  let connection = this.context.connectAbility(want,options);
  ```


## ServiceExtensionContext.disconnectAbility

disconnectAbility(connection: number, callback:AsyncCallback&lt;void&gt;): void;

将一个Ability与绑定的服务类型的Ability解绑。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | connection | number | 是 | 在connectAbility中返回的number。 | 
  | callback | AsyncCallback&lt;void&gt; | 否 | 回调函数，返回接口调用是否成功的结果。 | 

**示例：**

  ```js
  this.context.disconnectAbility(connection, (err) => { // connection为connectAbility中的返回值
      console.log('terminateSelf result:' + JSON.stringify(err));
  });
  ```


## ServiceExtensionContext.disconnectAbility

disconnectAbility(connection: number): Promise&lt;void&gt;;

将一个Ability与绑定的服务类型的Ability解绑。通过Promise返回结果。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | connection | number | 是 | 在connectAbility中返回的number。 | 

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;void&gt; | 返回一个Promise，包含接口的结果。 | 
 
**示例：**

  ```js
  this.context.disconnectAbility(connection).then((data) => { // connection为connectAbility中的返回值
      console.log('success:' + JSON.stringify(data));
  }).catch((error) => {
      console.log('failed:' + JSON.stringify(error));
  });
  ```


## ConnectOptions

ConnectOptions数据结构。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 说明 | 
| -------- | -------- |
| onConnect(elementName:ElementName,&nbsp;remote:IRemoteObject) | Ability成功连接一个服务类型Ability的回调接口。 | 
| onDisconnect(elementName:ElementName) | 对端服务发生异常或者被杀死回调该接口。 | 
| onFailed(code:&nbsp;number) | 连接失败时回调该接口。 | 
