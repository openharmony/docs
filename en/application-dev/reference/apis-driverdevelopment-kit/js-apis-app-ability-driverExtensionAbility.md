# @ohos.app.ability.DriverExtensionAbility (Driver Extension Ability)

<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->
<!-- md-trans-meta sourceCommit=80a690690bb3dbcda24d03e53bc7c3a287326f14 translatedAt=2026-07-28T07:01:46.933Z pushedAt=2026-07-28T08:40:44.023Z -->

The **DriverExtensionAbility** module provides the ExtensionAbility related to drivers. It provides lifecycle callbacks to be invoked when a driver is created, destroyed, connected, or disconnected.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version. 

## Constraints

To ensure system security and stability and prevent **DriverExtensionAbility** from abusing system resources, the system restricts its capabilities. Referencing certain modules is not supported. For details, see [Appendix](#appendix).

## Modules to Import

```ts
import { DriverExtensionAbility } from '@kit.DriverDevelopmentKit';
```

## DriverExtensionAbility

### Properties

**DriverExtensionAbility** class, which contains the definition of driver lifecycle callbacks.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Driver.ExternalDevice

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| context | [DriverExtensionContext](js-apis-inner-application-driverExtensionContext.md)  | No| No| Context of the **DriverExtension**. This context is inherited from **ExtensionContext**.|

### onInit

onInit(want: Want): void

Called when a DriverExtensionAbility is created to initialize the service logic.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Driver.ExternalDevice

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |  [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes| Want information related to this DriverExtensionAbility, including the ability name and bundle name.|

**Example**

  ```ts
  import { DriverExtensionAbility } from '@kit.DriverDevelopmentKit';
  import { Want } from '@kit.AbilityKit';

  class DriverExt extends DriverExtensionAbility {
    onInit(want : Want) {
      console.info(`onInit, want: ${want.abilityName}`);
    }
  }
  ```

### onRelease

onRelease(): void

Called when this DriverExtensionAbility is destroyed to clear resources.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Driver.ExternalDevice

**Example**

  ```ts
  class DriverExt extends DriverExtensionAbility {
    onRelease() {
      console.info('onRelease');
    }
  }
  ```

### onConnect

onConnect(want: Want): rpc.RemoteObject | Promise<rpc.RemoteObject>

Called following [onCreate](../apis-ability-kit/js-apis-app-ability-abilityStage.md#oncreate). A [RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject) object is returned for communication between the server and client.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Driver.ExternalDevice

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |  [Want](../apis-ability-kit/js-apis-app-ability-want.md)| Yes| Want information related to this DriverExtensionAbility, including the ability name and bundle name.|

**Return value**

| Type| Description|
| -------- | -------- |
| rpc.[RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject) \| Promise<rpc.[RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject)> | A **RemoteObject** object is returned for communication between the server and client, or a **Promise** object returns the **RemoteObject** object used for communication.|

**Example**

  ```ts
  import { DriverExtensionAbility } from '@kit.DriverDevelopmentKit';
  import { rpc } from '@kit.IPCKit';
  import { Want } from '@kit.AbilityKit';

  class StubTest extends rpc.RemoteObject{
      constructor(des : string) {
          super(des);
      }
      onRemoteMessageRequest(code : number, data : rpc.MessageSequence, reply : rpc.MessageSequence, option : rpc.MessageOption) {
        // This interface must be overridden.
        return true;
      }
  }
  class DriverExt extends DriverExtensionAbility {
    onConnect(want : Want) {
      console.info(`onConnect , want: ${want.abilityName}`);
      return new StubTest('test');
    }
  }
  ```

If the returned [RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject) object depends on an asynchronous API, you can use the asynchronous lifecycle.

  ```ts
  import { DriverExtensionAbility } from '@kit.DriverDevelopmentKit';
  import { rpc } from '@kit.IPCKit';
  import { Want } from '@kit.AbilityKit';
  
  class StubTest extends rpc.RemoteObject{
      constructor(des : string) {
          super(des);
      }
      onRemoteMessageRequest(code : number, data : rpc.MessageSequence, reply : rpc.MessageSequence, option : rpc.MessageOption) {
        // This interface must be overridden.
        return true;
      }
  }
  async function getDescriptor() {
      // Call the asynchronous function.
      return "asyncTest";
  }
  class DriverExt extends DriverExtensionAbility {
    async onConnect(want : Want) {
      console.info(`onConnect , want: ${want.abilityName}`);
      let descriptor = await getDescriptor();
      return new StubTest(descriptor);
    }
  }
  ```

### onDisconnect

onDisconnect(want: Want): void | Promise\<void>

Called when a client is disconnected from this **DriverExtensionAbility**.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Driver.ExternalDevice

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |[Want](../apis-ability-kit/js-apis-app-ability-want.md)| Yes| Want information related to this DriverExtensionAbility, including the ability name and bundle name.|

**Return value**

| Type| Description|
| -------- | -------- |
| void \| Promise\<void> | Empty value, or promise used to return the value.|

**Example**

  ```ts
  import { DriverExtensionAbility } from '@kit.DriverDevelopmentKit';
  import { Want } from '@kit.AbilityKit';

  class DriverExt extends DriverExtensionAbility {
    onDisconnect(want : Want) {
      console.info(`onDisconnect, want: ${want.abilityName}`);
    }
  }
  ```

After the **onDisconnect** lifecycle callback is executed, the application may exit. As a result, the asynchronous function in **onDisconnect** may fail to be executed correctly, for example, asynchronously writing data to the database. The asynchronous lifecycle can be used to ensure that the subsequent lifecycle continues after the asynchronous **onDisconnect** is complete.

  ```ts
  import { DriverExtensionAbility } from '@kit.DriverDevelopmentKit';
  import { Want } from '@kit.AbilityKit';

  class DriverExt extends DriverExtensionAbility {
    async onDisconnect(want : Want) {
      console.info(`onDisconnect, want: ${want.abilityName}`);
      // Call the asynchronous function.
    }
  }
  ```

### onDump

onDump(params: Array\<string>): Array\<string>

Dumps client information. You are advised not to dump sensitive information.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Driver.ExternalDevice

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| params | Array\<string> | Yes| Parameters in the form of a command.|

**Return value**

| Type| Description|
| -------- | -------- |
| Array\<string> | String array used to dump client information.|

**Example**

  ```ts
  class DriverExt extends DriverExtensionAbility {
      onDump(params : Array<string>) {
          console.info(`dump, params: ${JSON.stringify(params)}`);
          return ['params'];
      }
  }
  ```

## DriverExtensionContext

type DriverExtensionContext = _DriverExtensionContext;

**DriverExtensionAbility** context.

**System capability**: SystemCapability.Driver.ExternalDevice

| Type| Description|
| -------- | -------- |
| _DriverExtensionContext | **DriverExtensionAbility** context, which is inherited from **ExtensionContext**. For details about how to use the context, see [DriverExtensionContext](js-apis-inner-application-driverExtensionContext.md).|

## Appendix

The following modules cannot be referenced in the **DriverExtensionAbility**.

| Kit | Module |
| -------- | -------- | 
| Ability Kit | [@ohos.abilityAccessCtrl (Application Access Control)](../apis-ability-kit/js-apis-abilityAccessCtrl.md)  |
| Ability Kit | [@ohos.ability.particleAbility (ParticleAbility Module)](../apis-ability-kit/js-apis-ability-particleAbility.md)  |
| Ability Kit | [@ohos.app.ability.abilityManager (Ability Information Management)](../apis-ability-kit/js-apis-app-ability-abilityManager.md)  |
| Ability Kit | [@ohos.app.ability.appManager (Application Management)](../apis-ability-kit/js-apis-app-ability-appManager.md)  |
|<!--DelRow-->Ability Kit | [@ohos.app.ability.missionManager (missionManager) (System API)](../apis-ability-kit/js-apis-app-ability-missionManager-sys.md)  |
|<!--DelRow-->Ability Kit | [@ohos.app.ability.quickFixManager (quickFixManager) (System API)](../apis-ability-kit/js-apis-app-ability-quickFixManager-sys.md)  |
|<!--DelRow-->Ability Kit| [@ohos.application.abilityManager (AbilityManager) (System API)](../apis-ability-kit/js-apis-application-abilityManager-sys.md)  |
| Ability Kit| [@ohos.application.appManager (appManager)](../apis-ability-kit/js-apis-application-appManager.md)  |
|<!--DelRow-->Ability Kit | [@ohos.application.missionManager (missionManager) (System API)](../apis-ability-kit/js-apis-application-missionManager-sys.md)  |
| Ability Kit | [@ohos.bundle (Bundle Module)](../apis-ability-kit/js-apis-Bundle.md)  |
|<!--DelRow-->Ability Kit | [@ohos.bundle.appControl (appControl Module) (System API)](../apis-ability-kit/js-apis-appControl-sys.md)  |
| Ability Kit | [@ohos.bundle.bundleManager (Bundle Management Module)](../apis-ability-kit/js-apis-bundleManager.md)  |
| Ability Kit | [@ohos.bundle.defaultAppManager (Default Application Management)](../apis-ability-kit/js-apis-defaultAppManager.md)  |
|<!--DelRow-->Ability Kit | [@ohos.bundle.distributedBundleManager (distributedBundleManager Module) (System API)](../apis-ability-kit/js-apis-distributedBundleManager-sys.md)  |
|<!--DelRow-->Ability Kit | [@ohos.bundle.freeInstall (freeInstall Module) (System API)](../apis-ability-kit/js-apis-freeInstall-sys.md)  |
|<!--DelRow-->Ability Kit | [@ohos.bundle.innerBundleManager (innerBundleManager Module) (System API)](../apis-ability-kit/js-apis-Bundle-InnerBundleManager-sys.md)  |
|<!--DelRow-->Ability Kit | [@ohos.bundle.installer (installer Module) (System API)](../apis-ability-kit/js-apis-installer-sys.md)  |
| Ability Kit | [@ohos.bundle.launcherBundleManager (launcherBundleManager Module)](../apis-ability-kit/js-apis-launcherBundleManager.md)  |
| Ability Kit | [Context (Context Base Class of the Stage Model)](../apis-ability-kit/js-apis-inner-application-context.md)  |
| Ability Kit | [@ohos.continuation.continuationManager (Continuation/Collaboration Management)](../apis-ability-kit/js-apis-continuation-continuationManager.md)  |
|<!--DelRow-->Ability Kit | [@ohos.distributedBundle (Distributed Bundle Management) (System API)](../apis-ability-kit/js-apis-Bundle-distributedBundle-sys.md)  |
|<!--DelRow-->Ability Kit | [@ohos.distributedMissionManager (Distributed Mission Management) (System API)](../apis-ability-kit/js-apis-distributedMissionManager-sys.md)  |
|<!--DelRow-->Ability Kit | [@ohos.privacyManager (Privacy Management) (System API)](../apis-ability-kit/js-apis-privacyManager-sys.md)  |
|<!--DelRow-->Accessibility Kit| [@ohos.accessibility.config (System API)](../apis-accessibility-kit/js-apis-accessibility-config-sys.md)|
| ArkData | [@ohos.data.distributedData (Distributed Data Management)](../apis-arkdata/js-apis-distributed-data.md)  |
| ArkData  | [@ohos.data.distributedDataObject (Distributed Data Object)](../apis-arkdata/js-apis-data-distributedobject.md)  |
| ArkData  | [@ohos.data.distributedKVStore (Distributed KV Store)](../apis-arkdata/js-apis-distributedKVStore.md)  |
| ArkData  | [@ohos.data.rdb (RDB Store)](../apis-arkdata/js-apis-data-rdb.md)  |
|<!--DelRow-->ArkData  | [@ohos.data.relationalStore (RDB Store) (System API)](../apis-arkdata/js-apis-data-relationalStore-sys.md)  |
|<!--DelRow-->ArkUI| [@ohos.screen (Screen) (System API)](../apis-arkui/js-apis-screen-sys.md)  |
| ArkUI  | [@ohos.screenshot (Screenshot)](../apis-arkui/js-apis-screenshot.md)  |
|<!--DelRow-->ArkUI  | [@ohos.window (Window) (System API)](../apis-arkui/js-apis-window-sys.md)  |
|<!--DelRow-->AVSession Kit| [@ohos.multimedia.avsession (AVSession Management) (System API)](../apis-avsession-kit/js-apis-avsession-sys.md)  |
| Background Tasks Kit| [@ohos.reminderAgent (Agent-powered Reminder)](../apis-backgroundtasks-kit/js-apis-reminderAgent.md)  |
| Background Tasks Kit | [@ohos.reminderAgentManager (Agent-powered Reminder)](../apis-backgroundtasks-kit/js-apis-reminderAgentManager.md)  |
| Background Tasks Kit | [@ohos.resourceschedule.backgroundTaskManager (Background Task Management)](../apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md)  | 
|<!--DelRow-->Background Tasks Kit | [@ohos.resourceschedule.usageStatistics (Device Usage Statistics) (System API)](../apis-backgroundtasks-kit/js-apis-resourceschedule-deviceUsageStatistics-sys.md)  |
| Background Tasks Kit | [@ohos.backgroundTaskManager (Background Task Management)](../apis-backgroundtasks-kit/js-apis-backgroundTaskManager.md)  |
| Background Tasks Kit | [@ohos.bundleState (Device Usage Statistics)](../apis-backgroundtasks-kit/js-apis-deviceUsageStatistics.md)  |
| Basic Services Kit| [@ohos.account.appAccount (Application Account Management)](../apis-basic-services-kit/js-apis-appAccount.md)  |
| Basic Services Kit  | [@ohos.account.distributedAccount (Distributed Account Management)](../apis-basic-services-kit/js-apis-distributed-account.md)  |
| Basic Services Kit  | [@ohos.account.osAccount (OS Account Management)](../apis-basic-services-kit/js-apis-osAccount.md)  |
| Basic Services Kit  | [@ohos.deviceInfo (Device Information)](../apis-basic-services-kit/js-apis-device-info.md)  |
| Basic Services Kit  | [@ohos.power (Power Management)](../apis-basic-services-kit/js-apis-power.md)  |
| Basic Services Kit   | [@ohos.request (Upload and Download)](../apis-basic-services-kit/js-apis-request.md)  |
| Basic Services Kit  | [@ohos.runningLock (RunningLock)](../apis-basic-services-kit/js-apis-runninglock.md)  |
| Basic Services Kit  | [@ohos.settings (Data Item Settings)](../apis-basic-services-kit/js-apis-settings.md)  |
| Basic Services Kit  | [@ohos.systemTime (System Time and Time Zone)](../apis-basic-services-kit/js-apis-system-time.md)  |
|<!--DelRow-->Basic Services Kit  | [@ohos.update (Update) (System API)](../apis-basic-services-kit/js-apis-update-sys.md)  |
| Basic Services Kit  | [@ohos.wallpaper (Wallpaper)](../apis-basic-services-kit/js-apis-wallpaper.md)  |
|<!--DelRow-->Camera Kit| [@ohos.multimedia.camera (Camera Management) (System API)](../apis-camera-kit/js-apis-camera-sys.md)  |
| Connectivity Kit| [@ohos.bluetooth (Bluetooth)](../apis-connectivity-kit/js-apis-bluetooth.md)  |
| Connectivity Kit| [@ohos.bluetoothManager (Bluetooth)](../apis-connectivity-kit/js-apis-bluetoothManager.md)  |
| Connectivity Kit| [@ohos.connectedTag  (Active Tags)](../apis-connectivity-kit/js-apis-connectedTag.md)  |
| Connectivity Kit| [@ohos.nfc.cardEmulation (Standard NFC Card Emulation)](../apis-connectivity-kit/js-apis-cardEmulation.md)  |
| Connectivity Kit| [@ohos.nfc.controller (Standard NFC)](../apis-connectivity-kit/js-apis-nfcController.md)  |
| Connectivity Kit| [@ohos.nfc.tag (Standard NFC Tags)](../apis-connectivity-kit/js-apis-nfcTag.md)  |
| Connectivity Kit| [@ohos.wifi (WLAN)](../apis-connectivity-kit/js-apis-wifi.md)  |
| Connectivity Kit| [@ohos.wifiext (WLAN Extension)](../apis-connectivity-kit/js-apis-wifiext.md)  |
| Connectivity Kit| [@ohos.wifiManager (WLAN)](../apis-connectivity-kit/js-apis-wifiManager.md)  |
| Connectivity Kit| [@ohos.wifiManagerExt (WLAN Extension)](../apis-connectivity-kit/js-apis-wifiManagerExt.md)  |
| Contacts Kit| [@ohos.contact (Contacts)](../apis-contacts-kit/js-apis-contact.md)  |
|<!--DelRow-->Core File Kit| [@ohos.file.fileAccess (User File Access and Management) (System API)](../apis-core-file-kit/js-apis-fileAccess-sys.md)  |
|<!--DelRow-->Core File Kit | [@ohos.filemanagement.userFileManager (User Data Management) (System API)](../apis-core-file-kit/js-apis-userFileManager-sys.md)  |
| Core File Kit | [@ohos.file.storageStatistics (Application Storage Statistics)](../apis-core-file-kit/js-apis-file-storage-statistics.md)  |
|<!--DelRow-->Core File Kit | [@ohos.file.volumeManager (Volume Management) (System API)](../apis-core-file-kit/js-apis-file-volumemanager-sys.md)  |
|<!--DelRow-->Form Kit| [@ohos.app.form.formHost (formHost) (System API)](../apis-form-kit/js-apis-app-form-formHost-sys.md)  |
| Form Kit | [@ohos.application.formError (formError)](../apis-form-kit/js-apis-application-formError.md)  |
|<!--DelRow-->Form Kit | [@ohos.application.formHost (formHost) (System API)](../apis-form-kit/js-apis-application-formHost-sys.md)  |
| IME Kit| [@ohos.inputMethod (Input Method Framework)](../apis-ime-kit/js-apis-inputmethod.md)  |
|<!--DelRow-->Input Kit| [@ohos.multimodalInput.inputMonitor (Input Monitor) (System API)](../apis-input-kit/js-apis-inputmonitor-sys.md)  |
| Location Kit | [@ohos.geolocation (Geolocation)](../apis-location-kit/js-apis-geolocation.md)  |
| Location Kit | [@ohos.geoLocationManager (Geolocation Manager)](../apis-location-kit/js-apis-geoLocationManager.md)  |
| MDM Kit| [@ohos.enterprise.adminManager (Administrator Permission Management)](../apis-mdm-kit/js-apis-enterprise-adminManager.md)  |
|<!--DelRow-->MDM Kit | [@ohos.enterprise.dateTimeManager (System Time Management) (System API)](../apis-mdm-kit/js-apis-enterprise-dateTimeManager-sys.md)  |
| MDM Kit | [@ohos.enterprise.deviceInfo (Device Information Management)](../apis-mdm-kit/js-apis-enterprise-deviceInfo.md)  |
|<!--DelRow-->Media Kit| [@ohos.multimedia.media (Media) (System API)](../apis-media-kit/js-apis-media-sys.md)  |
| MultimediaKit | @ohos.multimedia.mediaLibrary (Media Library Management) |
| Network Kit| [@ohos.net.connection (Network Connection Management)](../apis-network-kit/js-apis-net-connection.md)  |
| Network Kit| [@ohos.net.ethernet (Ethernet Connection Management)](../apis-network-kit/js-apis-net-ethernet.md)  |
| Network Kit| [@ohos.net.http (Data Request)](../apis-network-kit/js-apis-http.md)  |
| Network Kit| [@ohos.net.sharing (Network Sharing)](../apis-network-kit/js-apis-net-sharing.md)  |
| Network Kit| [@ohos.net.socket (Socket Connection)](../apis-network-kit/js-apis-socket.md)  |
| Network Kit| [@ohos.net.webSocket (WebSocket Connection)](../apis-network-kit/js-apis-webSocket.md)  |
| Notification Kit| [@ohos.notification (Notification)](../apis-notification-kit/js-apis-notification.md)  |
| Notification Kit| [@ohos.notificationManager (NotificationManager)](../apis-notification-kit/js-apis-notificationManager.md)  |
|<!--DelRow-->Notification Kit| [@ohos.notificationSubscribe (NotificationSubscribe) (System API)](../apis-notification-kit/js-apis-notificationSubscribe-sys.md)  |
| Performance Analysis Kit| [@ohos.hidebug (HiDebug)](../apis-performance-analysis-kit/js-apis-hidebug.md)  |
|<!--DelRow-->Performance Analysis Kit | [@ohos.hiSysEvent (System Event Logging) (System API)](../apis-performance-analysis-kit/js-apis-hisysevent-sys.md)  |
| Sensor Service Kit| [@ohos.sensor (Sensor)](../apis-sensor-service-kit/js-apis-sensor.md)  |
| Sensor Service Kit| [@ohos.vibrator (Vibrator)](../apis-sensor-service-kit/js-apis-vibrator.md)  |
| Telephony Kit| [@ohos.telephony.call (Call)](../apis-telephony-kit/js-apis-call.md)  |
| Telephony Kit | [@ohos.telephony.data (Cellular Data)](../apis-telephony-kit/js-apis-telephony-data.md)  |
| Telephony Kit | [@ohos.telephony.observer (Observer)](../apis-telephony-kit/js-apis-observer.md)  |
| Telephony Kit | [@ohos.telephony.radio (Network Search)](../apis-telephony-kit/js-apis-radio.md)  |
| Telephony Kit | [@ohos.telephony.sim (SIM Card Management)](../apis-telephony-kit/js-apis-sim.md)  |
| Telephony Kit | [@ohos.telephony.sms (SMS)](../apis-telephony-kit/js-apis-sms.md)  |
|<!--DelRow-->User Authentication Kit| [@ohos.userIAM.faceAuth (Facial Authentication) (System API)](../apis-user-authentication-kit/js-apis-useriam-faceauth-sys.md)  |