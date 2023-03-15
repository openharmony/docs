# 分布式调度子系统ChangeLog

## cl.DistributedManagerService.1 continuationManager事件监听接口on/off变更

- continuationManager事件监听接口on/off传入的参数事件类型名，命名不符合OpenHarmony的API接口规范。
- continuationManager.on对于不同的事件接口返回值未进行统一，不符合OpenHarmony的API接口规范。

已做出以下变更：

- continuationManager.on和continuationManager.off的设备选择事件名由原来的"deviceConnect"变更为"deviceSelected"，设备取消选择事件名由原来的"deviceDisconnect"变更为"deviceUnselected"。
- continuationManager.on对于不同事件统一callback返回值类型"Callback&lt;Array&lt;ContinuationResult&gt;&gt;"。

**变更影响**

基于此前版本开发的应用，需适配变更接口，否则会影响原有业务逻辑。

**关键的接口/组件变更**

- 涉及接口

  continuationManager.on;
  continuationManager.off;

- 变更前：

```js
  function on(type: "deviceConnect", token: number, callback: Callback<Array<ContinuationResult>>): void;
  function off(type: "deviceConnect", token: number): void;
  function on(type: "deviceDisconnect", token: number, callback: Callback<Array<string>>): void;
  function off(type: "deviceDisconnect", token: number): void;
```

- 变更后：

```js
  function on(type: "deviceSelected", token: number, callback: Callback<Array<ContinuationResult>>): void;
  function off(type: "deviceSelected", token: number): void;
  function on(type: "deviceUnselected", token: number, callback: Callback<Array<ContinuationResult>>): void;
  function off(type: "deviceUnselected", token: number): void;
```

**适配指导**
修改事件名称，示例代码如下：

continuationManager.on 设备选择事件

```ts
  let token = 1;
  try {
    continuationManager.on("deviceSelected", token, (data) => {
      console.info('onDeviceSelected len: ' + data.length);
      for (let i = 0; i < data.length; i++) {
        console.info('onDeviceSelected deviceId: ' + JSON.stringify(data[i].id));
        console.info('onDeviceSelected deviceType: ' + JSON.stringify(data[i].type));
        console.info('onDeviceSelected deviceName: ' + JSON.stringify(data[i].name));
      }
    });
  } catch (err) {
    console.error('on failed, cause: ' + JSON.stringify(err));
  }
```

continuationManager.off 设备选择事件

```ts
  let token = 1;
  try {
    continuationManager.off("deviceSelected", token);
  } catch (err) {
    console.error('off failed, cause: ' + JSON.stringify(err));
  }
```

continuationManager.on 设备取消选择事件

```ts
  let token = 1;
  try {
    continuationManager.on("deviceUnselected", token, (data) => {
      console.info('onDeviceUnselected len: ' + data.length);
      for (let i = 0; i < data.length; i++) {
        console.info('onDeviceUnselected deviceId: ' + JSON.stringify(data[i].id));
        console.info('onDeviceUnselected deviceType: ' + JSON.stringify(data[i].type));
        console.info('onDeviceUnselected deviceName: ' + JSON.stringify(data[i].name));
      }
      console.info('onDeviceUnselected finished.');
    });
  } catch (err) {
    console.error('on failed, cause: ' + JSON.stringify(err));
  }
```

continuationManager.off 设备取消选择事件

```ts
  let token = 1;
  try {
    continuationManager.off("deviceUnselected", token);
  } catch (err) {
    console.error('off failed, cause: ' + JSON.stringify(err));
  }
```