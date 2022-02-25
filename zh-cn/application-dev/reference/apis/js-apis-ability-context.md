# AbilityContext

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


Ability的上下文环境，继承自Context。


## 属性

| 名称 | 参数类型 | 可读 | 可写 | 说明 | 
| -------- | -------- | -------- | -------- | -------- |
| abilityInfo | AbilityInfo | 是 | 否 | Abilityinfo相关信息 | 
| currentHapModuleInfo | HapModuleInfo | 是 | 否 | 当前hap包的信息 | 


## startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void

启动Ability。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | want | [Want](js-apis-featureAbility.md#Want类型说明) | 是 | 启动Ability的want信息。 | 
  | callback | AsyncCallback&lt;void&gt; | 是 | callback形式返回启动结果 | 

- 示例：
  ```
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

startAbility(want: Want): Promise&lt;void&gt;;

启动Ability。通过Promise返回结果。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | want | [Want](js-apis-featureAbility.md#Want类型说明) | 是 | 启动Ability的want信息。 | 

- 返回值：
  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise形式返回启动结果。 | 

- 示例：
  ```
  var want = {
  	"deviceId": "",
  	"bundleName": "com.extreme.test",
  	"abilityName": "com.extreme.test.MainAbility"
  };
  this.context.startAbility(want)
  .then((data) => {
      console.log('Operation successful.')
  }).catch((error) => {
      console.log('Operation failed.');
  })
  ```


## startAbilityForResult

startAbilityForResult(want: Want, callback: AsyncCallback&lt;AbilityResult&gt;): void;

启动Ability并在结束的时候返回执行结果。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | want |[Want](js-apis-featureAbility.md#Want类型说明) | 是 | 启动Ability的want信息。 |
  | callback | Callback&lt;[AbilityResult](js-apis-featureAbility.md#abilityresult)&gt; | 是 | 执行结果回调函数。 |


- 示例：
  ```
  this.context.startAbilityForResult(
      {bundleName: "com.extreme.myapplication", abilityName: "MainAbilityDemo2"},
      (error, result) => {
          console.log("startAbilityForResult AsyncCallback is called, error.code = " + error.code)
          console.log("startAbilityForResult AsyncCallback is called, result.resultCode = " + result.resultCode)
       }
  );
  ```


## startAbilityForResult

startAbilityForResult(want: Want): Promise&lt;AbilityResult&gt;;

启动Ability并在结束的时候返回执行结果。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | want | [Want](js-apis-featureAbility.md#Want类型说明) | 是 | 启动Ability的want信息。 | 

- 返回值
  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[AbilityResult](js-apis-featureAbility.md#abilityresult)&gt; | Promise形式返回执行结果。 |

- 示例：
  ```
  this.context.startAbilityForResult({bundleName: "com.extreme.myapplication", abilityName: "MainAbilityDemo2"}).then((result) => {
      console.log("startAbilityForResult Promise.resolve is called, result.resultCode = " + result.resultCode)
  }, (error) => {
      console.log("startAbilityForResult Promise.Reject is called, error.code = " + error.code)
  })
  ```


## terminateSelf

terminateSelf(callback: AsyncCallback&lt;void&gt;): void;

停止Ability自身。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | 否 | 回调函数，返回接口调用是否成功的结果。 | 

- 示例：
  ```
  this.context.terminateSelf((err) => {
      console.log('terminateSelf result:' + JSON.stringfy(err));
  });
  ```


## terminateSelf

terminateSelf(): Promise&lt;void&gt;;

停止Ability自身。通过Promise返回结果。

- 返回值：
  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;void&gt; | 返回一个Promise，包含接口的结果。 | 

- 示例：
  ```
  this.context.terminateSelf(want).then((data) => {
      console.log('success:' + JSON.stringfy(data));
  }).catch((error) => {
      console.log('failed:' + JSON.stringfy(error));
  });
  ```


## terminateSelfWithResult

terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback&lt;void&gt;): void;

停止Ability，并返回给调用startAbilityForResult 接口调用方的相关信息。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | parameter | [AbilityResult](js-apis-featureAbility.md#abilityresult) | 是 | 返回给调用startAbilityForResult&nbsp;接口调用方的相关信息。 |
  | callback | Callback&lt;void&gt; | 否 | callback形式返回停止结果 |

- 示例：
  ```
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

terminateSelfWithResult(parameter: AbilityResult): Promise&lt;void&gt;;

停止Ability，并返回给调用startAbilityForResult 接口相关信息。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | parameter | [AbilityResult](js-apis-featureAbility.md#abilityresult) | 是 | 返回给startAbilityForResult&nbsp;调用方的信息。 |

- 返回值：
  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;void&gt; | promise形式返回停止结果 | 

- 示例：
  ```
  this.context.terminateSelfWithResult(
  {
      want: {bundleName: "com.extreme.myapplication", abilityName: "MainAbilityDemo"},
      resultCode: 100
  }).then((result) => {
      console.log("terminateSelfWithResult")
  }
  )
  ```
