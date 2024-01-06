# 设备管理Changelog


## cl.device_manager.1 接口权限变更

从Opeharmonny 4.0.8.2版本开始，部分接口新增权限校验。

**变更影响**

在Opeharmonny 4.0.8.2之后版本开发的应用，需要持有相应权限，否则无法正常调用接口。

**关键的接口/组件变更**

| 模块名 | 类名 | 方法/属性/枚举/常量 | 新增权限 | 
| -------- | -------- | -------- | -------- |
| \@ohos.distributedHardware.deviceManager | deviceManager | **function**&nbsp;release():&nbsp;void | ohos.permission.ACCESS_SERVICE_DM | 
| \@ohos.distributedHardware.deviceManager | deviceManager | **function**&nbsp;getTrustedDeviceListSync():&nbsp;Array&lt;DeviceInfo&gt; | ohos.permission.ACCESS_SERVICE_DM | 
| \@ohos.distributedHardware.deviceManager | deviceManager | **function**&nbsp;getTrustedDeviceList(callback:AsyncCallback&lt;Array&lt;DeviceInfo&gt;&gt;):&nbsp;void | ohos.permission.ACCESS_SERVICE_DM | 
| \@ohos.distributedHardware.deviceManager | deviceManager | **function**&nbsp;getTrustedDeviceList():&nbsp;Promise&lt;Array&lt;DeviceInfo&gt;&gt; | ohos.permission.ACCESS_SERVICE_DM | 
| \@ohos.distributedHardware.deviceManager | deviceManager | **function**&nbsp;getLocalDeviceInfoSync():&nbsp;DeviceInfo | ohos.permission.ACCESS_SERVICE_DM | 
| \@ohos.distributedHardware.deviceManager | deviceManager | **function**&nbsp;getLocalDeviceInfo(callback:AsyncCallback&lt;DeviceInfo&gt;):&nbsp;void | ohos.permission.ACCESS_SERVICE_DM | 
| \@ohos.distributedHardware.deviceManager | deviceManager | **function**&nbsp;getLocalDeviceInfo():&nbsp;Promise&lt;DeviceInfo&gt; | ohos.permission.ACCESS_SERVICE_DM | 
| \@ohos.distributedHardware.deviceManager | deviceManager | **function**&nbsp;getDeviceInfo(networkId:&nbsp;string,&nbsp;callback:AsyncCallback&lt;DeviceInfo&gt;):&nbsp;void | ohos.permission.ACCESS_SERVICE_DM | 
| \@ohos.distributedHardware.deviceManager | deviceManager | **function**&nbsp;getDeviceInfo(networkId:&nbsp;string):&nbsp;Promise&lt;DeviceInfo&gt; | ohos.permission.ACCESS_SERVICE_DM | 
| \@ohos.distributedHardware.deviceManager | deviceManager | **function**&nbsp;startDeviceDiscovery(subscribeInfo:&nbsp;SubscribeInfo):&nbsp;void | ohos.permission.ACCESS_SERVICE_DM | 
| \@ohos.distributedHardware.deviceManager | deviceManager | **function**&nbsp;startDeviceDiscovery(subscribeInfo:&nbsp;SubscribeInfo,&nbsp;filterOptions?:&nbsp;string):&nbsp;void | ohos.permission.ACCESS_SERVICE_DM | 
| \@ohos.distributedHardware.deviceManager | deviceManager | **function**&nbsp;stopDeviceDiscovery(subscribeId:&nbsp;number):&nbsp;void | ohos.permission.ACCESS_SERVICE_DM | 
| \@ohos.distributedHardware.deviceManager | deviceManager | **function**&nbsp;publishDeviceDiscovery(publishInfo:&nbsp;PublishInfo):&nbsp;void | ohos.permission.ACCESS_SERVICE_DM | 
| \@ohos.distributedHardware.deviceManager | deviceManager | **function**&nbsp;unPublishDeviceDiscovery(publishId:&nbsp;number):&nbsp;void | ohos.permission.ACCESS_SERVICE_DM | 
| \@ohos.distributedHardware.deviceManager | deviceManager | **function**&nbsp;authenticateDevice(deviceInfo:&nbsp;DeviceInfo,&nbsp;authParam:&nbsp;AuthParam,&nbsp;callback:&nbsp;AsyncCallback&lt;{deviceId:&nbsp;string,&nbsp;pinToken&nbsp;?:&nbsp;number}&gt;):&nbsp;void | ohos.permission.ACCESS_SERVICE_DM | 
| \@ohos.distributedHardware.deviceManager | deviceManager | **function**&nbsp;unAuthenticateDevice(deviceInfo:&nbsp;DeviceInfo):&nbsp;void | ohos.permission.ACCESS_SERVICE_DM | 
| \@ohos.distributedHardware.deviceManager | deviceManager | **function**&nbsp;verifyAuthInfo(authInfo:&nbsp;AuthInfo,&nbsp;callback:&nbsp;AsyncCallback&lt;{deviceId:&nbsp;string,&nbsp;level:&nbsp;number}&gt;):&nbsp;void | ohos.permission.ACCESS_SERVICE_DM | 
| \@ohos.distributedHardware.deviceManager | deviceManager | **function**&nbsp;setUserOperation(operateAction:&nbsp;number,&nbsp;params:&nbsp;string):&nbsp;void | ohos.permission.ACCESS_SERVICE_DM | 
| \@ohos.distributedHardware.deviceManager | deviceManager | **function**&nbsp;requestCredentialRegisterInfo(requestInfo:&nbsp;string,&nbsp;callback:&nbsp;AsyncCallback&lt;{registerInfo:&nbsp;string}&gt;):&nbsp;void; | ohos.permission.ACCESS_SERVICE_DM | 
| \@ohos.distributedHardware.deviceManager | deviceManager | **function**&nbsp;importCredential(credentialInfo:&nbsp;string,&nbsp;callback:&nbsp;AsyncCallback&lt;{resultInfo:&nbsp;string}&gt;):&nbsp;void; | ohos.permission.ACCESS_SERVICE_DM | 
| \@ohos.distributedHardware.deviceManager | deviceManager | **function**&nbsp;deleteCredential(queryInfo:&nbsp;string,&nbsp;callback:&nbsp;AsyncCallback&lt;{resultInfo:&nbsp;string}&gt;):&nbsp;void; | ohos.permission.ACCESS_SERVICE_DM | 
| \@ohos.distributedHardware.deviceManager | deviceManager | **function**&nbsp;on(type:&nbsp;'uiStateChange',&nbsp;callback:&nbsp;Callback&lt;{&nbsp;param:&nbsp;string}&gt;):&nbsp;void; | ohos.permission.ACCESS_SERVICE_DM | 
| \@ohos.distributedHardware.deviceManager | deviceManager | **function**&nbsp;off(type:&nbsp;'uiStateChange',&nbsp;callback?:&nbsp;Callback&lt;{&nbsp;param:&nbsp;string}&gt;):&nbsp;void; | ohos.permission.ACCESS_SERVICE_DM | 
| \@ohos.distributedHardware.deviceManager | deviceManager | **function**&nbsp;on(type:&nbsp;'deviceStateChange',&nbsp;callback:&nbsp;Callback&lt;{&nbsp;action:&nbsp;DeviceStateChangeAction,&nbsp;device:&nbsp;DeviceInfo&nbsp;}&gt;):&nbsp;void | ohos.permission.ACCESS_SERVICE_DM | 
| \@ohos.distributedHardware.deviceManager | deviceManager | **function**&nbsp;off(type:&nbsp;'deviceStateChange',&nbsp;callback?:&nbsp;Callback&lt;{&nbsp;action:&nbsp;DeviceStateChangeAction,&nbsp;device:&nbsp;DeviceInfo&nbsp;}&gt;):&nbsp;void | ohos.permission.ACCESS_SERVICE_DM | 
| \@ohos.distributedHardware.deviceManager | deviceManager | **function**&nbsp;on(type:&nbsp;'deviceFound',&nbsp;callback:&nbsp;Callback&lt;{&nbsp;subscribeId:&nbsp;number,&nbsp;device:&nbsp;DeviceInfo&nbsp;}&gt;):&nbsp;void | ohos.permission.ACCESS_SERVICE_DM | 
| \@ohos.distributedHardware.deviceManager | deviceManager | **function**&nbsp;off(type:&nbsp;'deviceFound',&nbsp;callback?:&nbsp;Callback&lt;{&nbsp;subscribeId:&nbsp;number,&nbsp;device:&nbsp;DeviceInfo&nbsp;}&gt;):&nbsp;void | ohos.permission.ACCESS_SERVICE_DM | 
| \@ohos.distributedHardware.deviceManager | deviceManager | **function**&nbsp;on(type:&nbsp;'discoverFail',&nbsp;callback:&nbsp;Callback&lt;{&nbsp;subscribeId:&nbsp;number,&nbsp;reason:&nbsp;number&nbsp;}&gt;):&nbsp;void | ohos.permission.ACCESS_SERVICE_DM | 
| \@ohos.distributedHardware.deviceManager | deviceManager | **function**&nbsp;off(type:&nbsp;'discoverFail',&nbsp;callback?:&nbsp;Callback&lt;{&nbsp;subscribeId:&nbsp;number,&nbsp;reason:&nbsp;number&nbsp;}&gt;):&nbsp;void | ohos.permission.ACCESS_SERVICE_DM | 
| \@ohos.distributedHardware.deviceManager | deviceManager | **function**&nbsp;on(type:&nbsp;'publishSuccess',&nbsp;callback:&nbsp;Callback&lt;{&nbsp;publishId:&nbsp;number&nbsp;}&gt;):&nbsp;void | ohos.permission.ACCESS_SERVICE_DM | 
| \@ohos.distributedHardware.deviceManager | deviceManager | **function**&nbsp;off(type:&nbsp;'publishSuccess',&nbsp;callback?:&nbsp;Callback&lt;{&nbsp;publishId:&nbsp;number&nbsp;}&gt;):&nbsp;void | ohos.permission.ACCESS_SERVICE_DM | 
| \@ohos.distributedHardware.deviceManager | deviceManager | **function**&nbsp;on(type:&nbsp;'publishFail',&nbsp;callback:&nbsp;Callback&lt;{&nbsp;publishId:&nbsp;number,&nbsp;reason:&nbsp;number&nbsp;}&gt;):&nbsp;void | ohos.permission.ACCESS_SERVICE_DM | 
| \@ohos.distributedHardware.deviceManager | deviceManager | **function**&nbsp;off(type:&nbsp;'publishFail',&nbsp;callback?:&nbsp;Callback&lt;{&nbsp;publishId:&nbsp;number,&nbsp;reason:&nbsp;number&nbsp;}&gt;):&nbsp;void | ohos.permission.ACCESS_SERVICE_DM | 
| \@ohos.distributedHardware.deviceManager | deviceManager | **function**&nbsp;on(type:&nbsp;'serviceDie',&nbsp;callback:&nbsp;()&nbsp;=&gt;&nbsp;void):&nbsp;void | ohos.permission.ACCESS_SERVICE_DM | 
| \@ohos.distributedHardware.deviceManager | deviceManager | **function**&nbsp;off(type:&nbsp;'serviceDie',&nbsp;callback?:&nbsp;()&nbsp;=&gt;&nbsp;void):&nbsp;void | ohos.permission.ACCESS_SERVICE_DM | 

**适配指导**

调用以上接口，需要申请相应的权限才能正常调用。
