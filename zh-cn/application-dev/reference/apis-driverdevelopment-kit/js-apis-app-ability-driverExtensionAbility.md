# @ohos.app.ability.DriverExtensionAbility (驱动程序扩展能力)
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->

DriverExtensionAbility模块提供驱动相关扩展能力，提供驱动创建、销毁、连接、断开等生命周期回调。

> **说明：**
> 
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  

## 约束限制

为保障系统安全性和稳定性，防止 DriverExtensionAbility滥用系统资源，系统对其能力进行管控，不支持部分模块的引用，详情请参考[附录](#附录)。

## 导入模块

```ts
import { DriverExtensionAbility } from '@kit.DriverDevelopmentKit';
```


## DriverExtensionAbility

### 属性

DriverExtensionAbility类，包含驱动生命周期回调的定义。

**模型约束**：此接口仅在Stage模型下使用。

**系统能力**：SystemCapability.Driver.ExternalDevice


| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| context | [DriverExtensionContext](js-apis-inner-application-driverExtensionContext.md)  | 否 | 否 | DriverExtension的上下文环境，继承自ExtensionContext。 |

### onInit

onInit(want: Want): void

Extension生命周期回调，在创建时回调，执行初始化业务逻辑操作。

**模型约束**：此接口仅在Stage模型下使用。

**系统能力**：SystemCapability.Driver.ExternalDevice

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want |  [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是 | 当前Extension相关的Want类型信息，包括ability名称、bundle名称等。 |

**示例：**

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

Extension生命周期回调，在销毁时回调，执行资源清理等操作。

**模型约束**：此接口仅在Stage模型下使用。

**系统能力**：SystemCapability.Driver.ExternalDevice

**示例：**

  ```ts
  class DriverExt extends DriverExtensionAbility {
    onRelease() {
      console.info('onRelease');
    }
  }
  ```

### onConnect

onConnect(want: Want): rpc.RemoteObject | Promise<rpc.RemoteObject>

Extension生命周期回调，会在[onCreate](../apis-ability-kit/js-apis-app-ability-abilityStage.md#oncreate)之后回调。返回一个[RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject)对象，用于客户端和服务端进行通信。

**模型约束**：此接口仅在Stage模型下使用。

**系统能力**：SystemCapability.Driver.ExternalDevice

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want |  [Want](../apis-ability-kit/js-apis-app-ability-want.md)| 是 | 当前Extension相关的Want类型信息，包括ability名称、bundle名称等。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| rpc.[RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject) \| Promise<rpc.[RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject)> | 一个RemoteObject对象，用于客户端和服务端进行通信；或一个Promise对象，返回用于通信的RemoteObject对象。|

**示例：**

  ```ts
  import { DriverExtensionAbility } from '@kit.DriverDevelopmentKit';
  import { rpc } from '@kit.IPCKit';
  import { Want } from '@kit.AbilityKit';

  class StubTest extends rpc.RemoteObject{
      constructor(des : string) {
          super(des);
      }
      onRemoteMessageRequest(code : number, data : rpc.MessageSequence, reply : rpc.MessageSequence, option : rpc.MessageOption) {
        // 必须重写此接口
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

如果生成返回值[RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject)依赖一个异步接口，可以使用异步生命周期：

  ```ts
  import { DriverExtensionAbility } from '@kit.DriverDevelopmentKit';
  import { rpc } from '@kit.IPCKit';
  import { Want } from '@kit.AbilityKit';
  
  class StubTest extends rpc.RemoteObject{
      constructor(des : string) {
          super(des);
      }
      onRemoteMessageRequest(code : number, data : rpc.MessageSequence, reply : rpc.MessageSequence, option : rpc.MessageOption) {
        // 必须重写此接口
        return true;
      }
  }
  async function getDescriptor() {
      // 调用异步函数...
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

Extension的生命周期回调，客户端执行断开连接服务时回调。

**模型约束**：此接口仅在Stage模型下使用。

**系统能力**：SystemCapability.Driver.ExternalDevice

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want |[Want](../apis-ability-kit/js-apis-app-ability-want.md)| 是 | 当前Extension相关的Want类型信息，包括ability名称、bundle名称等。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| void \| Promise\<void> | 返回值为空；或一个Promise对象，无返回结果。 |

**示例：**

  ```ts
  import { DriverExtensionAbility } from '@kit.DriverDevelopmentKit';
  import { Want } from '@kit.AbilityKit';

  class DriverExt extends DriverExtensionAbility {
    onDisconnect(want : Want) {
      console.info(`onDisconnect, want: ${want.abilityName}`);
    }
  }
  ```

在执行完onDisconnect生命周期回调后，应用可能会退出，从而可能导致onDisconnect中的异步函数未能正确执行，比如异步写入数据库。可以使用异步生命周期，以确保异步onDisconnect完成后再继续后续的生命周期。

  ```ts
  import { DriverExtensionAbility } from '@kit.DriverDevelopmentKit';
  import { Want } from '@kit.AbilityKit';

  class DriverExt extends DriverExtensionAbility {
    async onDisconnect(want : Want) {
      console.info(`onDisconnect, want: ${want.abilityName}`);
      // 调用异步函数...
    }
  }
  ```

### onDump

onDump(params: Array\<string>): Array\<string>

转储客户端信息时调用，建议不要转储敏感信息。

**模型约束**：此接口仅在Stage模型下使用。

**系统能力**：SystemCapability.Driver.ExternalDevice

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| params | Array\<string> | 是 | 表示命令形式的参数。|

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Array\<string> | 一个string类型的数组，用于转存客户端信息。 |

**示例：**
    
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

DriverExtensionAbility的上下文环境。

**系统能力**：SystemCapability.Driver.ExternalDevice

| 类型 | 说明 |
| -------- | -------- |
| _DriverExtensionContext | DriverExtensionAbility的上下文环境，继承自ExtensionContext，其具体使用方法可参考[DriverExtensionContext](js-apis-inner-application-driverExtensionContext.md)。|

## 附录

DriverExtensionAbility不支持以下模块的引用。
| Kit | 模块 |
| -------- | -------- | 
| Ability Kit（程序框架服务） | [@ohos.abilityAccessCtrl (程序访问控制管理)](../apis-ability-kit/js-apis-abilityAccessCtrl.md)  |
| Ability Kit（程序框架服务） | [@ohos.ability.particleAbility (ParticleAbility模块)](../apis-ability-kit/js-apis-ability-particleAbility.md)  |
| Ability Kit（程序框架服务） | [@ohos.app.ability.abilityManager (Ability信息管理)](../apis-ability-kit/js-apis-app-ability-abilityManager.md)  |
| Ability Kit（程序框架服务） | [@ohos.app.ability.appManager (应用管理)](../apis-ability-kit/js-apis-app-ability-appManager.md)  |
|<!--DelRow-->Ability Kit（程序框架服务） | [@ohos.app.ability.missionManager (missionManager)(系统接口)](../apis-ability-kit/js-apis-app-ability-missionManager-sys.md)  |
|<!--DelRow-->Ability Kit（程序框架服务） | [@ohos.app.ability.quickFixManager (quickFixManager)(系统接口)](../apis-ability-kit/js-apis-app-ability-quickFixManager-sys.md)  |
|<!--DelRow-->Ability Kit（程序框架服务）| [@ohos.application.abilityManager (AbilityManager)(系统接口)](../apis-ability-kit/js-apis-application-abilityManager-sys.md)  |
| Ability Kit（程序框架服务）| [@ohos.application.appManager (appManager)](../apis-ability-kit/js-apis-application-appManager.md)  |
|<!--DelRow-->Ability Kit（程序框架服务） | [@ohos.application.missionManager (missionManager)(系统接口)](../apis-ability-kit/js-apis-application-missionManager-sys.md)  |
| Ability Kit（程序框架服务） | [@ohos.bundle (Bundle模块)](../apis-ability-kit/js-apis-Bundle.md)  |
|<!--DelRow-->Ability Kit（程序框架服务） | [@ohos.bundle.appControl (appControl模块)(系统接口)](../apis-ability-kit/js-apis-appControl-sys.md)  |
| Ability Kit（程序框架服务） | [@ohos.bundle.bundleManager (应用程序包管理模块)](../apis-ability-kit/js-apis-bundleManager.md)  |
| Ability Kit（程序框架服务） | [@ohos.bundle.defaultAppManager (默认应用管理)](../apis-ability-kit/js-apis-defaultAppManager.md)  |
|<!--DelRow-->Ability Kit（程序框架服务） | [@ohos.bundle.distributedBundleManager (distributedBundleManager模块)(系统接口)](../apis-ability-kit/js-apis-distributedBundleManager-sys.md)  |
|<!--DelRow-->Ability Kit（程序框架服务） | [@ohos.bundle.freeInstall (freeInstall模块)(系统接口)](../apis-ability-kit/js-apis-freeInstall-sys.md)  |
|<!--DelRow-->Ability Kit（程序框架服务） | [@ohos.bundle.innerBundleManager (innerBundleManager模块)(系统接口)](../apis-ability-kit/js-apis-Bundle-InnerBundleManager-sys.md)  |
|<!--DelRow-->Ability Kit（程序框架服务） | [@ohos.bundle.installer (installer模块)(系统接口)](../apis-ability-kit/js-apis-installer-sys.md)  |
| Ability Kit（程序框架服务） | [@ohos.bundle.launcherBundleManager (launcherBundleManager模块)](../apis-ability-kit/js-apis-launcherBundleManager.md)  |
| Ability Kit（程序框架服务） | [Context (Stage模型的上下文基类)](../apis-ability-kit/js-apis-inner-application-context.md)  |
| Ability Kit（程序框架服务） | [@ohos.continuation.continuationManager (流转/协同管理)](../apis-ability-kit/js-apis-continuation-continuationManager.md)  |
|<!--DelRow-->Ability Kit（程序框架服务） | [@ohos.distributedBundle (分布式包管理)(系统接口)](../apis-ability-kit/js-apis-Bundle-distributedBundle-sys.md)  |
|<!--DelRow-->Ability Kit（程序框架服务） | [@ohos.distributedMissionManager (分布式任务管理)(系统接口)](../apis-ability-kit/js-apis-distributedMissionManager-sys.md)  |
|<!--DelRow-->Ability Kit（程序框架服务） | [@ohos.privacyManager (隐私管理)(系统接口)](../apis-ability-kit/js-apis-privacyManager-sys.md)  |
|<!--DelRow-->Accessibility Kit（无障碍服务）| [@ohos.accessibility.config (系统辅助功能配置)(系统接口)](../apis-accessibility-kit/js-apis-accessibility-config-sys.md)|
| ArkData（方舟数据管理）| [@ohos.data.distributedData (分布式数据管理)](../apis-arkdata/js-apis-distributed-data.md)  |
| ArkData（方舟数据管理）  | [@ohos.data.distributedDataObject (分布式数据对象)](../apis-arkdata/js-apis-data-distributedobject.md)  |
| ArkData（方舟数据管理）  | [@ohos.data.distributedKVStore (分布式键值数据库)](../apis-arkdata/js-apis-distributedKVStore.md)  |
| ArkData（方舟数据管理）  | [@ohos.data.rdb（关系型数据库）](../apis-arkdata/js-apis-data-rdb.md)  |
|<!--DelRow-->ArkData（方舟数据管理）  | [@ohos.data.relationalStore（关系型数据库）（系统接口）](../apis-arkdata/js-apis-data-relationalStore-sys.md)  |
|<!--DelRow-->ArkUI（方舟UI框架）| [@ohos.screen (屏幕)(系统接口)](../apis-arkui/js-apis-screen-sys.md)  |
| ArkUI（方舟UI框架）  | [@ohos.screenshot (屏幕截图)](../apis-arkui/js-apis-screenshot.md)  |
|<!--DelRow-->ArkUI（方舟UI框架）  | [@ohos.window (窗口)(系统接口)](../apis-arkui/js-apis-window-sys.md)  |
|<!--DelRow-->AVSession Kit（音视频播控服务）| [@ohos.multimedia.avsession (媒体会话管理)(系统接口)](../apis-avsession-kit/js-apis-avsession-sys.md)  |
| Background Tasks Kit（后台任务开发服务）| [@ohos.reminderAgent (后台代理提醒)](../apis-backgroundtasks-kit/js-apis-reminderAgent.md)  |
| Background Tasks Kit（后台任务开发服务） | [@ohos.reminderAgentManager (后台代理提醒)](../apis-backgroundtasks-kit/js-apis-reminderAgentManager.md)  |
| Background Tasks Kit（后台任务开发服务） | [@ohos.resourceschedule.backgroundTaskManager (后台任务管理)](../apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md)  | 
|<!--DelRow-->Background Tasks Kit（后台任务开发服务） | [@ohos.resourceschedule.usageStatistics (设备使用信息统计)(系统接口)](../apis-backgroundtasks-kit/js-apis-resourceschedule-deviceUsageStatistics-sys.md)  |
| Background Tasks Kit（后台任务开发服务） | [@ohos.backgroundTaskManager (后台任务管理)](../apis-backgroundtasks-kit/js-apis-backgroundTaskManager.md)  |
| Background Tasks Kit（后台任务开发服务） | [@ohos.bundleState (设备使用信息统计)](../apis-backgroundtasks-kit/js-apis-deviceUsageStatistics.md)  |
| Basic Services Kit（基础服务）| [@ohos.account.appAccount (应用账号管理)](../apis-basic-services-kit/js-apis-appAccount.md)  |
| Basic Services Kit（基础服务）  | [@ohos.account.distributedAccount (分布式账号管理)](../apis-basic-services-kit/js-apis-distributed-account.md)  |
| Basic Services Kit（基础服务）  | [@ohos.account.osAccount (系统账号管理)](../apis-basic-services-kit/js-apis-osAccount.md)  |
| Basic Services Kit（基础服务）  | [@ohos.deviceInfo (设备信息)](../apis-basic-services-kit/js-apis-device-info.md)  |
| Basic Services Kit（基础服务）  | [@ohos.power (系统电源管理)](../apis-basic-services-kit/js-apis-power.md)  |
| Basic Services Kit（基础服务）   | [@ohos.request (上传下载)](../apis-basic-services-kit/js-apis-request.md)  |
| Basic Services Kit（基础服务）  | [@ohos.runningLock (RunningLock锁)](../apis-basic-services-kit/js-apis-runninglock.md)  |
| Basic Services Kit（基础服务）  | [@ohos.settings (设置数据项名称)](../apis-basic-services-kit/js-apis-settings.md)  |
| Basic Services Kit（基础服务）  | [@ohos.systemTime (系统时间、时区)](../apis-basic-services-kit/js-apis-system-time.md)  |
|<!--DelRow-->Basic Services Kit（基础服务）  | [@ohos.update (升级)(系统接口)](../apis-basic-services-kit/js-apis-update-sys.md)  |
| Basic Services Kit（基础服务）  | [@ohos.wallpaper (壁纸)](../apis-basic-services-kit/js-apis-wallpaper.md)  |
|<!--DelRow-->Camera Kit（相机服务）| [@ohos.multimedia.camera (相机管理)(系统接口)](../apis-camera-kit/js-apis-camera-sys.md)  |
| Connectivity Kit（短距通信服务）| [@ohos.bluetooth (蓝牙)](../apis-connectivity-kit/js-apis-bluetooth.md)  |
| Connectivity Kit（短距通信服务）| [@ohos.bluetoothManager (蓝牙)](../apis-connectivity-kit/js-apis-bluetoothManager.md)  |
| Connectivity Kit（短距通信服务）| [@ohos.connectedTag (有源标签)](../apis-connectivity-kit/js-apis-connectedTag.md)  |
| Connectivity Kit（短距通信服务）| [@ohos.nfc.cardEmulation (标准NFC-cardEmulation)](../apis-connectivity-kit/js-apis-cardEmulation.md)  |
| Connectivity Kit（短距通信服务）| [@ohos.nfc.controller (标准NFC)](../apis-connectivity-kit/js-apis-nfcController.md)  |
| Connectivity Kit（短距通信服务）| [@ohos.nfc.tag (标准NFC-Tag)](../apis-connectivity-kit/js-apis-nfcTag.md)  |
| Connectivity Kit（短距通信服务）| [@ohos.wifi (WLAN)](../apis-connectivity-kit/js-apis-wifi.md)  |
| Connectivity Kit（短距通信服务）| [@ohos.wifiext (WLAN扩展接口)](../apis-connectivity-kit/js-apis-wifiext.md)  |
| Connectivity Kit（短距通信服务）| [@ohos.wifiManager (WLAN)](../apis-connectivity-kit/js-apis-wifiManager.md)  |
| Connectivity Kit（短距通信服务）| [@ohos.wifiManagerExt (WLAN扩展接口)](../apis-connectivity-kit/js-apis-wifiManagerExt.md)  |
| Contacts Kit（联系人服务）| [@ohos.contact (联系人)](../apis-contacts-kit/js-apis-contact.md)  |
|<!--DelRow-->Core File Kit（文件基础服务）| [@ohos.file.fileAccess (公共文件访问与管理)(系统接口)](../apis-core-file-kit/js-apis-fileAccess-sys.md)  |
|<!--DelRow-->Core File Kit（文件基础服务） | [@ohos.filemanagement.userFileManager (用户数据管理)(系统接口)](../apis-core-file-kit/js-apis-userFileManager-sys.md)  |
| Core File Kit（文件基础服务） | [@ohos.file.storageStatistics (应用空间统计)](../apis-core-file-kit/js-apis-file-storage-statistics.md)  |
|<!--DelRow-->Core File Kit（文件基础服务） | [@ohos.file.volumeManager (卷管理)(系统接口)](../apis-core-file-kit/js-apis-file-volumemanager-sys.md)  |
|<!--DelRow-->Form Kit（卡片开发服务）| [@ohos.app.form.formHost (formHost)(系统接口)](../apis-form-kit/js-apis-app-form-formHost-sys.md)  |
| Form Kit（卡片开发服务） | [@ohos.application.formError (formError)](../apis-form-kit/js-apis-application-formError.md)  |
|<!--DelRow-->Form Kit（卡片开发服务） | [@ohos.application.formHost (formHost)(系统接口)](../apis-form-kit/js-apis-application-formHost-sys.md)  |
| IME Kit（输入法开发服务）| [@ohos.inputMethod (输入法框架)](../apis-ime-kit/js-apis-inputmethod.md)  |
|<!--DelRow-->Input Kit（多模输入服务）| [@ohos.multimodalInput.inputMonitor (输入监听)(系统接口)](../apis-input-kit/js-apis-inputmonitor-sys.md)  |
| Location Kit | [@ohos.geolocation (位置服务)](../apis-location-kit/js-apis-geolocation.md)  |
| Location Kit | [@ohos.geoLocationManager (位置服务)](../apis-location-kit/js-apis-geoLocationManager.md)  |
| MDM Kit（企业设备管理服务）| [@ohos.enterprise.adminManager（admin权限管理）](../apis-mdm-kit/js-apis-enterprise-adminManager.md)  |
|<!--DelRow-->MDM Kit（企业设备管理服务） | [@ohos.enterprise.dateTimeManager （系统时间管理）(系统接口)](../apis-mdm-kit/js-apis-enterprise-dateTimeManager-sys.md)  |
| MDM Kit（企业设备管理服务） | [@ohos.enterprise.deviceInfo（设备信息管理）](../apis-mdm-kit/js-apis-enterprise-deviceInfo.md)  |
|<!--DelRow-->Media Kit（媒体服务）| [@ohos.multimedia.media (媒体服务)(系统接口)](../apis-media-kit/js-apis-media-sys.md)  |
| MultimediaKit | @ohos.multimedia.mediaLibrary (媒体库管理) |
| Network Kit（网络服务）| [@ohos.net.connection (网络连接管理)](../apis-network-kit/js-apis-net-connection.md)  |
| Network Kit（网络服务）| [@ohos.net.ethernet (以太网连接管理)](../apis-network-kit/js-apis-net-ethernet.md)  |
| Network Kit（网络服务）| [@ohos.net.http (数据请求)](../apis-network-kit/js-apis-http.md)  |
| Network Kit（网络服务）| [@ohos.net.sharing (网络共享管理)](../apis-network-kit/js-apis-net-sharing.md)  |
| Network Kit（网络服务）| [@ohos.net.socket (Socket连接)](../apis-network-kit/js-apis-socket.md)  |
| Network Kit（网络服务）| [@ohos.net.webSocket (WebSocket连接)](../apis-network-kit/js-apis-webSocket.md)  |
| Notification Kit（用户通知服务）| [@ohos.notification (Notification模块)](../apis-notification-kit/js-apis-notification.md)  |
| Notification Kit（用户通知服务）| [@ohos.notificationManager (NotificationManager模块)](../apis-notification-kit/js-apis-notificationManager.md)  |
|<!--DelRow-->Notification Kit（用户通知服务）| [@ohos.notificationSubscribe (NotificationSubscribe模块)(系统接口)](../apis-notification-kit/js-apis-notificationSubscribe-sys.md)  |
| Performance Analysis Kit（性能分析服务）| [@ohos.hidebug (Debug调试)](../apis-performance-analysis-kit/js-apis-hidebug.md)  |
|<!--DelRow-->Performance Analysis Kit（性能分析服务） | [@ohos.hiSysEvent (系统事件打点)(系统接口)](../apis-performance-analysis-kit/js-apis-hisysevent-sys.md)  |
| Sensor Service Kit（传感器服务）| [@ohos.sensor (传感器)](../apis-sensor-service-kit/js-apis-sensor.md)  |
| Sensor Service Kit（传感器服务）| [@ohos.vibrator (振动)](../apis-sensor-service-kit/js-apis-vibrator.md)  |
| Telephony Kit（蜂窝通信服务）| [@ohos.telephony.call (拨打电话)](../apis-telephony-kit/js-apis-call.md)  |
| Telephony Kit（蜂窝通信服务） | [@ohos.telephony.data (蜂窝数据)](../apis-telephony-kit/js-apis-telephony-data.md)  |
| Telephony Kit（蜂窝通信服务） | [@ohos.telephony.observer (observer)](../apis-telephony-kit/js-apis-observer.md)  |
| Telephony Kit（蜂窝通信服务） | [@ohos.telephony.radio (网络搜索)](../apis-telephony-kit/js-apis-radio.md)  |
| Telephony Kit（蜂窝通信服务） | [@ohos.telephony.sim (SIM卡管理)](../apis-telephony-kit/js-apis-sim.md)  |
| Telephony Kit（蜂窝通信服务） | [@ohos.telephony.sms (短信服务)](../apis-telephony-kit/js-apis-sms.md)  |
|<!--DelRow-->User Authentication Kit（用户认证服务）| [@ohos.userIAM.faceAuth (人脸认证)(系统接口)](../apis-user-authentication-kit/js-apis-useriam-faceauth-sys.md)  |