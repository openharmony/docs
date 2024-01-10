# Distributed Scheduler Subsystem Changelog

## cl.DistributedManagerService.1 continuationManager on()/off() Changes

- The event types passed to the **continuationManager.on** and **continuationManager.off** APIs do not comply with the OpenHarmony API specifications.
- The return value of **continuationManager.on** varies with the event type, which does not comply with the OpenHarmony API specifications.

The following changes have been made:

- Changed the event type **deviceConnect** to **deviceSelected** and **deviceDisconnect** to **deviceUnselected** in the **continuationManager.on** and **continuationManager.off** APIs.
- Changed the return value of **continuationManager.on** to **Callback&lt;Array&lt;ContinuationResult&gt;&gt;** for all events.

**Change Impact**

The application developed based on earlier versions needs to be adapted. Otherwise, the service logic will be affected.

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
Change the event names. The code snippet is as follows:

Event of device selection in **continuationManager.on**:

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

Event of device selection in **continuationManager.off**:

```ts
  let token = 1;
  try {
    continuationManager.off("deviceSelected", token);
  } catch (err) {
    console.error('off failed, cause: ' + JSON.stringify(err));
  }
```

Event of device deselection in **continuationManager.on**:

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

Event of device deselection in **continuationManager.off**:

```ts
  let token = 1;
  try {
    continuationManager.off("deviceUnselected", token);
  } catch (err) {
    console.error('off failed, cause: ' + JSON.stringify(err));
  }
```

## cl.DistributedManagerService.2 Adding DATASYNC Permission Verification to continuationManager APIs

In earlier versions, the **continuationManager** APIs do not verify the caller, which does not comply with the OpenHarmony API specifications.
Now, before using a **continuationManager** API, the caller must apply for the **ohos.permission.DISTRIBUTED_DATASYNC** permission.

**Change Impact**

The application developed based on earlier versions needs to apply for the **ohos.permission.DISTRIBUTED_DATASYNC** permission in advance. Otherwise, the service logic will be affected.

**Key API/Component Changes**

Involved APIs:

  - continuationManager.registerContinuation;
  - continuationManager.on;
  - continuationManager.off;
  - continuationManager.unregisterContinuation;
  - continuationManager.updateContinuationState;
  - continuationManager.startContinuationDeviceManager;
