# Distributed Scheduler Subsystem ChangeLog

## cl.DistributedManagerService.1 continuationManager API Changes

- Event names passed to the **continuationManager** API do not comply with the OpenHarmony API specifications.
- The **continuationManager.on** API does not have a unified return value for various events, which does not comply with the OpenHarmony API specifications.

The following changes have been made:

- The device selection event name of **continuationManager.on** and **continuationManager.off** is changed from **deviceConnect** to **deviceSelected**, and the device deselection event name is changed from **deviceDisconnect** to **deviceUnselected**.
- The **continuationManager.on** API returns **Callback&lt;Array&lt;ContinuationResult&gt;&gt;** for all events.

**Change Impacts**

The application developed based on earlier versions needs to adapt the new APIs. Otherwise, the original service logic will be affected.

**Key API/Component Changes**

- Involved APIs:

  continuationManager.on;
  continuationManager.off;

- Before change:

```js
  function on(type: "deviceConnect", token: number, callback: Callback<Array<ContinuationResult>>): void;
  function off(type: "deviceConnect", token: number): void;
  function on(type: "deviceDisconnect", token: number, callback: Callback<Array<string>>): void;
  function off(type: "deviceDisconnect", token: number): void;
```

- After change:

```js
  function on(type: "deviceSelected", token: number, callback: Callback<Array<ContinuationResult>>): void;
  function off(type: "deviceSelected", token: number): void;
  function on(type: "deviceUnselected", token: number, callback: Callback<Array<ContinuationResult>>): void;
  function off(type: "deviceUnselected", token: number): void;
```

**Adaptation Guide**

Change the event names. The sample code is as follows:

Device selection event of **continuationManager.on**:

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

Device selection event of **continuationManager.off**:

```ts
  let token = 1;
  try {
    continuationManager.off("deviceSelected", token);
  } catch (err) {
    console.error('off failed, cause: ' + JSON.stringify(err));
  }
```

Device deselection event of **continuationManager.on**:

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

Device deselection event of **continuationManager.off**:

```ts
  let token = 1;
  try {
    continuationManager.off("deviceUnselected", token);
  } catch (err) {
    console.error('off failed, cause: ' + JSON.stringify(err));
  }
```
