# Common Event and Notification Subsystem ChangeLog

## cl.notification.1 API Exception Handling Method Changes

Certain event notification APIs use service logic return values to indicate error information, which does not comply with the API error code specifications of OpenHarmony.

**Change Impacts**

The application developed based on earlier versions needs to adapt the new APIs and their method for returning API error information. Otherwise, the original service logic will be affected.

**Key API/Component Changes**

For adaptation to the unified API exception handling mode, certain event notification APIs are deprecated (original APIs in the following table) and corresponding new APIs in the following table are added. The newly added APIs support unified error code handling specifications and function the same as the original APIs.

| Original API                 | New API                          |
| ----------------------- | -------------------------------- |
| @ohos.commonEvent.d.ts  | @ohos.commonEventManager.d.ts    |
| @ohos.notification.d.ts | @ohos.notificationManager.d.ts   |
| @ohos.notification.d.ts | @ohos.notificationSubscribe.d.ts |

**Adaptation Guide**

The original APIs are only migrated to the new namespace. Therefore, you can modify **import** to solve the adaptation problem.

If the original API uses **@ohos.commonEvent**:

```js
import commonEvent from '@ohos.commonEvent';
```

You can directly modify **import** to switch to the new namespace:

```js
import commonEvent from '@ohos.commonEventManager';
```

**@ohos.notification** is split into two namespaces. You need to select a new namespace for adaptation.

In addition, exception handling is needed. For details, see the API reference for the new APIs.

## cl.notification.2 API Changes

The names of some event notification APIs are changed.

**Key API/Component Changes**

| Module                   | Class               | Method/Attribute/Enumeration/Constant                                         | Change Type|
| ------------------------- | ------------------- | ------------------------------------------------------------ | -------- |
| @ohos.notification        | notification        | **function** enableNotification(bundle: BundleOption, enable: boolean, callback: AsyncCallback<**void**>): **void**; | Deprecated    |
| @ohos.notification        | notification        | **function** enableNotification(bundle: BundleOption, enable: boolean): Promise<**void**>; | Deprecated    |
| @ohos.notificationManager | notificationManager | **function** setNotificationEnable(bundle: BundleOption, enable: boolean, callback: AsyncCallback<**void**>): **void**; | Added    |
| @ohos.notificationManager | notificationManager | **function** setNotificationEnable(bundle: BundleOption, enable: boolean): Promise<**void**>; | Added    |
| @ohos.notification        | notification        | **function** enableNotificationSlot(bundle: BundleOption, **type**: SlotType, enable: boolean, callback: AsyncCallback<**void**>): **void**; | Deprecated    |
| @ohos.notification        | notification        | **function** enableNotificationSlot(bundle: BundleOption, **type**: SlotType, enable: boolean): Promise<**void**>; | Deprecated    |
| @ohos.notificationManager | notificationManager | **function** setNotificationEnableSlot(bundle: BundleOption, **type**: SlotType, enable: boolean, callback: AsyncCallback<**void**>): **void**; | Added    |
| @ohos.notificationManager | notificationManager | **function** setNotificationEnableSlot(bundle: BundleOption, **type**: SlotType, enable: boolean): Promise<**void**>; | Added    |
| @ohos.notification        | notification        | **function** enableDistributed(enable: boolean, callback: AsyncCallback<**void**>): **void**; | Deprecated    |
| @ohos.notification        | notification        | **function** enableDistributed(enable: boolean, callback: AsyncCallback<**void**>): **void**; | Deprecated    |
| @ohos.notificationManager | notificationManager | **function** setDistributedEnable(enable: boolean, callback: AsyncCallback<**void**>): **void**; | Added    |
| @ohos.notificationManager | notificationManager | **function** setDistributedEnable(enable: boolean): Promise<**void**>; | Added    |
| @ohos.notification        | notification        | **function** enableDistributedByBundle(bundle: BundleOption, enable: boolean, callback: AsyncCallback<**void**>): **void**; | Deprecated    |
| @ohos.notification        | notification        | **function** enableDistributedByBundle(bundle: BundleOption, enable: boolean): Promise<**void**>; | Deprecated    |
| @ohos.notificationManager | notificationManager | **function** setDistributedEnableByBundle(bundle: BundleOption, enable: boolean, callback: AsyncCallback<**void**>): **void**; | Added    |
| @ohos.notificationManager | notificationManager | **function** setDistributedEnableByBundle(bundle: BundleOption, enable: boolean): Promise<**void**>; | Added    |
