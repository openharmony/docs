# FeatureAbility Module (JavaScript)

## Constraints

APIs of the **FeatureAbility** module can be called only by Page abilities.

## Modules to Import

```
import featureAbility from '@ohos.ability.featureAbility'
```

## featureAbility.startAbility

startAbility(parameter: StartAbilityParameter, callback: AsyncCallback\<number>): void

Starts an ability. This method uses a callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| --------- | --------------------- | ---- | ------------------- |
| parameter | [StartAbilityParameter](#startabilityparameter) | Yes| Ability to start.|
| callback  | AsyncCallback\<number>         | Yes| Callback used to return the result.|

**Example**

```javascript
import featureAbility from '@ohos.ability.featureAbility'
import wantConstant from '@ohos.ability.wantConstant'
featureAbility.startAbility(
        {
        want:
        {
            action: "",
            entities: [""],
            type: "",
            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: "",
            bundleName: "com.example.startability",
            abilityName: "com.example.startability.MainAbility",
            uri: ""
        },
    },
);
```



## featureAbility.startAbility

startAbility(parameter: StartAbilityParameter): Promise\<number>

Starts an ability. This method uses a promise to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| --------- | ----------------------------------------------- | ---- | --------------------- |
| parameter | [StartAbilityParameter](#startabilityparameter) | Yes| Ability to start.|

**Example**

```javascript
import featureAbility from '@ohos.ability.featureAbility'
import wantConstant from '@ohos.ability.wantConstant'
featureAbility.startAbility(
    {
        want:
        {
            action: "action.system.home",
            entities: ["entity.system.home"],
            type: "MIMETYPE",
			flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: "",
            bundleName: "com.example.startability",
            abilityName: "com.example.startability.MainAbility",
            uri: ""
        },
    }
   ).then((data) => {
	console.info("==========================>startAbility=======================>");
});
```

## featureAbility.acquireDataAbilityHelper

acquireDataAbilityHelper(uri: string): DataAbilityHelper

Obtains a **dataAbilityHelper** object.

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ------ | ---- | ------------------------ |
| uri  | string | Yes| URI of the file to open.|

**Return value**

| Type| Description|
| ----------------- | -------------------------------------------- |
| DataAbilityHelper | A utility class used to help other abilities access the Data ability.|

**Example**

```javascript
import featureAbility from '@ohos.ability.featureAbility'
featureAbility.acquireDataAbilityHelper(
    "dataability:///com.exmaple.DataAbility"
)
```

## featureAbility.startAbilityForResult

startAbilityForResult(parameter: StartAbilityParameter, callback: AsyncCallback\<AbilityResult>): void

Starts an ability. This method uses a callback to return the execution result when the ability is destroyed.

**Parameters**

| Name| Type| Mandatory| Description|
| --------- | ----------------------------------------------- | ---- | --------------------- |
| parameter | [StartAbilityParameter](#startabilityparameter) | Yes| Ability to start.|
| callback  | AsyncCallback\<[AbilityResult](#abilityresult)> | Yes| Callback used to return the result.|

**Example**

```javascript
import featureAbility from '@ohos.ability.featureability';
import wantConstant from '@ohos.ability.wantConstant'
featureAbility.startAbilityForResult(
   {
        want:
        {
            action: "action.system.home",
            entities: ["entity.system.home"],
            type: "MIMETYPE",
            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: "",
            bundleName: "com.example.featureabilitytest",
            abilityName: "com.example.featureabilitytest.MainAbility",
            uri:""
        },
    },
)
```

## featureAbility.startAbilityForResult

startAbilityForResult(parameter: StartAbilityParameter): Promise\<AbilityResult>

Starts an ability. This method uses a promise to return the execution result when the ability is destroyed.

**Parameters**

| Name| Type| Mandatory| Description|
| --------- | ----------------------------------------------- | ---- | ------------------- |
| parameter | [StartAbilityParameter](#startabilityparameter) | Yes| Ability to start.|

**Return value**
| Type| Description|
| ----------------------------------------- | -------------- |
| Promise\<[AbilityResult](#abilityresult)> | Promised returned with the execution result.|

**Example**

```javascript
import featureAbility from '@ohos.ability.featureability';
import wantConstant from '@ohos.ability.wantConstant'
featureAbility.startAbilityForResult(
    {
        want:
        {
            action: "action.system.home",
            entities: ["entity.system.home"],
            type: "MIMETYPE",
            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: "",
            bundleName: "com.example.featureabilitytest",
            abilityName: "com.example.featureabilitytest.MainAbility",
            uri:"",
            parameters:
            {
                mykey0: 1111,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "xxxxxxxxxxxxxxxxxxxxxx",
                mykey4: [1, 15],
                mykey5: [false, true, false],
                mykey6: ["aaaaaa", "bbbbb", "ccccccccccc"],
                mykey7: true,
            },
        },
        requestCode: 2,
    },
).then((data) => {
    console.info("==========================>startAbilityForResult=======================>");
});
```

## featureAbility.terminateSelfWithResult

terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback\<void>): void

Destroys this Page ability, with the result code and data sent to the caller. This method uses a callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| --------- | ------------- | ---- | ------------------- |
| parameter | [AbilityResult](#abilityresult) | Yes| Ability to start.|
| callback  | AsyncCallback\<void> | Yes| Callback used to return the result.|

**Example**

```javascript
import featureAbility from '@ohos.ability.featureAbility'
import wantConstant from '@ohos.ability.wantConstant'
featureAbility.terminateSelfWithResult(
    {
        resultCode: 1,
        want:
        {
            action: "action.system.home",
            entities: ["entity.system.home"],
            type: "MIMETYPE",
            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: "",
            bundleName: "com.example.featureabilitytest",
            abilityName: "com.example.featureabilitytest.MainAbility",
            uri:"",
            parameters: {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "ssssssssssssssssssssssssss",
                mykey4: [1, 15],
                mykey5: [false, true, false],
                mykey6: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
                mykey7: true,
            }
        },
    },
);
```

## featureAbility.terminateSelfWithResult

terminateSelfWithResult(parameter: AbilityResult): Promise\<void>

Destroys this Page ability, with the result code and data sent to the caller. This method uses a promise to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| --------- | ------------------------------- | ---- | ------------------- |
| parameter | [AbilityResult](#abilityresult) | Yes| Ability to start.|

**Return value**
| Type| Description|
| -------------- | ----------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```javascript
import featureAbility from '@ohos.ability.featureability';
import wantConstant from '@ohos.ability.wantConstant'
featureAbility.terminateSelfWithResult(
    {
        resultCode: 1,
        want:
        {
            action: "action.system.home",
            entities: ["entity.system.home"],
            type: "MIMETYPE",
            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: "",
            bundleName: "com.example.featureabilitytest",
            abilityName: "com.example.featureabilitytest.MainAbility",
            uri:"",
            parameters: {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "ssssssssssssssssssssssssss",
                mykey4: [1, 15],
                mykey5: [false, true, false],
                mykey6: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
                mykey7: true,
            }
        },
    }
).then((data) => {
    console.info("==========================>terminateSelfWithResult=======================>");
});
```



## featureAbility.hasWindowFocus

hasWindowFocus(callback: AsyncCallback\<boolean>): void

Checks whether the main window of this ability has the focus. This method uses a callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<boolean> | Yes| Callback used to return the result. <br>Returns **true** if the main window of this ability has the focus; returns **false** otherwise.|

**Example**

```javascript
import featureAbility from '@ohos.ability.featureability';
featureAbility.hasWindowFocus()
```



## featureAbility.hasWindowFocus

hasWindowFocus(): Promise\<boolean>

Checks whether the main window of this ability has the focus. This method uses a promise to return the result.

**Return value**

| Type| Description|
| ----------------- | ---------------------------------------------------------- |
| Promise\<boolean> | Returns **true** if the main window of this ability has the focus; returns **false** otherwise.|

**Example**

```javascript
import featureAbility from '@ohos.ability.featureability';
featureAbility.hasWindowFocus().then((data) => {
    console.info("==========================>hasWindowFocus=======================>");
});
```



## featureAbility.getWant

getWant(callback: AsyncCallback\<Want>): void

Obtains the **Want** object sent from this ability. This method uses a callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ----------------------------- | ---- | ------------------ |
| callback | AsyncCallback\<[Want](#want)> | Yes| Callback used to return the result.|

**Example**

```javascript
import featureAbility from '@ohos.ability.featureability';
featureAbility.getWant()
```



## featureAbility.getWant

getWant(): Promise\<Want>

Obtains the **Want** object sent from this ability. This method uses a promise to return the result.

**Return value**
| Type| Description|
| ----------------------- | ------------------------- |
| Promise\<[Want](#want)> | Promise used to return the result.|

**Example**

```javascript
import featureAbility from '@ohos.ability.featureability';
featureAbility.getWant().then((data) => {
		console.info("==========================>getWantCallBack=======================>");
});
```

## featureAbility.getContext

getContext(): Context

Obtains the application context.

**Return value**
| Type| Description|
| ------- | -------------------- |
| Context | Application context returned.|

**Example**

```javascript
import featureAbility from '@ohos.ability.featureability';
var context = featureAbility.getContext()
context.getBundleName()
```



## featureAbility.terminateSelf

terminateSelf(callback: AsyncCallback\<void>): void

Destroys this Page ability, with the result code and data sent to the caller. This method uses a callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------------------- | ---- | ---------------- |
| callback | AsyncCallback\<void> | Yes| Callback used to return the result.|

**Example**

```javascript
import featureAbility from '@ohos.ability.featureability';
featureAbility.terminateSelf()
```



## featureAbility.terminateSelf

terminateSelf(): Promise\<void>

Destroys this Page ability, with the result code and data sent to the caller. This method uses a promise to return the result.

**Return value**
| Type| Description|
| -------------- | ------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```javascript
import featureAbility from '@ohos.ability.featureability';
featureAbility.terminateSelf().then((data) => {		    console.info("==========================>terminateSelfCallBack=======================>");
});
```

## featureAbility.connectAbility

connectAbility(request: Want, options:ConnectOptions): number

Connects this ability to a specific Service ability. This method uses a callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| ------- | -------------- | ---- | ---------------------------- |
| request | [Want](#want)           | Yes| Service ability to connect.|
| options | ConnectOptions | Yes| Callback used to return the result.|

Want

| Name| Readable/Writable| Type| Mandatory| Description|
| ------------ | -------- | -------- | ---- | ----------------------------------                               |
| deviceId     | Read-only| string   | No| Device ID of the Service ability to connect. The default value is the local device ID.|
| bundleName   | Read-only| string   | Yes| Bundle name of the Service ability to connect.|
| abilityName  | Read-only| string   | Yes| Class name of the Service ability to connect.|

ConnectOptions

| Name| Readable/Writable| Type| Mandatory| Description|
| ------------ | -------- | -------- | ---- | ---------------------------------- |
| onConnect    | Read-only| function | Yes| Callback invoked when the connection is successful.|
| onDisconnect | Read-only| function | Yes| Callback invoked when the connection fails.|
| onFailed     | Read-only| function | Yes| Callback invoked when **connectAbility** fails to be called.|

**Return value**
| Type| Description|
| ------ | ------------------------ |
| number | Returns the ID of the Service ability connected.|

**Example**

```javascript
import rpc from '@ohos.rpc'
import featureAbility from '@ohos.ability.featureAbility'
function onConnectCallback(element, remote){
    console.log('ConnectAbility onConnect remote is proxy:' + (remote instanceof rpc.RemoteProxy));
}
function onDisconnectCallback(element){
    console.log('ConnectAbility onDisconnect element.deviceId : ' + element.deviceId)
}
function onFailedCallback(code){
    console.log('featureAbilityTest ConnectAbility onFailed errCode : ' + code)
}
var connId = featureAbility.connectAbility(
    {
        deviceId: "",
        bundleName: "com.ix.ServiceAbility",
        abilityName: "ServiceAbilityA",
    },
    {
        onConnect: onConnectCallback,
        onDisconnect: onDisconnectCallback,
        onFailed: onFailedCallback,
    },
);
```

## featureAbility.disconnectAbility

disconnectAbility(connection: number, callback:AsyncCallback\<void>): void

Disconnects this ability from a specific Service ability. This method uses a callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| ---------- | ------------- | ---- | ------------------------------ |
| connection | number        | Yes| ID of the Service ability to disconnect.|
| callback   | AsyncCallback\<void> | Yes| Callback used to return the result.|

**Example**

```javascript
import rpc from '@ohos.rpc'
import featureAbility from '@ohos.ability.featureAbility'
function onConnectCallback(element, remote){
    console.log('ConnectAbility onConnect remote is proxy:' + (remote instanceof rpc.RemoteProxy));
}
function onDisconnectCallback(element){
    console.log('ConnectAbility onDisconnect element.deviceId : ' + element.deviceId)
}
function onFailedCallback(code){
    console.log('featureAbilityTest ConnectAbility onFailed errCode : ' + code)
}
var connId = featureAbility.connectAbility(
    {
        bundleName: "com.ix.ServiceAbility",
        abilityName: "ServiceAbilityA",
    },
    {
        onConnect: onConnectCallback,
        onDisconnect: onDisconnectCallback,
        onFailed: onFailedCallback,
    },
);
var result = featureAbility.disconnectAbility(connId,
    (error,data) => {
    console.log('featureAbilityTest DisConnectJsSameBundleName result errCode : ' + error.code + " data: " + data)
    },
);
```

## featureAbility.disconnectAbility

disconnectAbility(connection: number): Promise\<void>

Disconnects this ability from a specific Service ability. This method uses a promise to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| ---------- | ------ | ---- | ------------------------------ |
| connection | number | Yes| ID of the Service ability to disconnect.|

**Return value**
| Type| Description|
| -------------- | ----------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```javascript
import rpc from '@ohos.rpc'
import featureAbility from '@ohos.ability.featureAbility'
function onConnectCallback(element, remote){
    console.log('ConnectAbility onConnect remote is proxy:' + (remote instanceof rpc.RemoteProxy));
}
function onDisconnectCallback(element){
    console.log('ConnectAbility onDisconnect element.deviceId : ' + element.deviceId)
}
function onFailedCallback(code){
    console.log('featureAbilityTest ConnectAbility onFailed errCode : ' + code)
}
var connId = featureAbility.connectAbility(
    {
        bundleName: "com.ix.ServiceAbility",
        abilityName: "ServiceAbilityA",
    },
    {
        onConnect: onConnectCallback,
        onDisconnect: onDisconnectCallback,
        onFailed: onFailedCallback,
    },
);
var result = await featureAbility.disconnectAbility(connId);
```

## featureAbility.continueAbility

continueAbility(options: ContinueAbilityOptions, callback: AsyncCallback\<void>): void

Migrates an ability to another device. This method uses a callback to return the execution result.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ---------------------- | ---- | ------------------- |
| options  | ContinueAbilityOptions | Yes| Ability to migrate.|
| callback | AsyncCallback\<void>   | Yes| Callback used to return the result.|

ContinueAbilityOptions

| Name| Readable/Writable| Type| Mandatory| Description|
| ---------- | -------- | ------- | ---- | ------------------------------------------------------------ |
| deviceId   | Read-only| string  | Yes| Information about the ability to migrate.|
| reversible | Read-only| boolean | Yes| Whether migration back is supported. Currently, this feature is not supported. This parameter is reserved and can be set to **false**.|

**Example**

```javascript
import device from '@system.device'
import ability from '@ohos.ability.featureability'

var DEVICE_LIST_LOCALHOST
export default {
    data: {
        title: "",
        deviceId: '',
        deviceList: [],
        remoteDeviceModel : new RemoteDeviceModel()
    },
    onInit() {
        DEVICE_LIST_LOCALHOST = {
            id: 'localhost',
        };
        this.deviceList = [DEVICE_LIST_LOCALHOST];
    },
    onShow() {
        const core = Core.getInstance()
        const expectExtend = new ExpectExtend({
            'id': 'extend'
        })
        const reportExtend = new ReportExtend(file)
        core.addService('expect', expectExtend)
        core.addService('report', reportExtend)
        core.init()
        const configService = core.getDefaultService('config')
        configService.setConfig(this)
        core.execute()
    },
    onReady() {
    },
    GetNetWorkId(){
        let self = this;
        this.remoteDeviceModel.registerDeviceListCallback(() => {
            var list = [];
            list[0] = DEVICE_LIST_LOCALHOST;
            var deviceList = self.remoteDeviceModel.deviceList;
            for (var i = 0; i < deviceList.length; i++) {
                list[i] = {
                    id: deviceList[i].deviceId,
                };
            }
            self.deviceList = list;
        });
    },
    ShowNetWorkId(){
        this.deviceId = this.deviceList[0].id;
    },

    async ContinueAbility(){
        function ContinueAbilityCallback(err) {
            console.info("=============>ContinueAbilityCallback============>");
        }
        var continueAbilityOptions = {
            reversible: false,
            deviceId: this.deviceId,
        }
        //continueAbility callback
        await ability.continueAbility(continueAbilityOptions, ContinueAbilityCallback);
    },
}
```

## featureAbility.continueAbility

continueAbility(options: ContinueAbilityOptions): Promise\<void>;

Migrates an ability to another device. This method uses a promise to return the execution result.

**Parameters**

| Name| Type| Mandatory| Description|
| ------- | ---------------------- | ---- | ------------------- |
| options | ContinueAbilityOptions | Yes| Ability to migrate.|

ContinueAbilityOptions

| Name| Readable/Writable| Type| Mandatory| Description|
| ---------- | -------- | ------- | ---- | ------------------------------------------------------------ |
| deviceId   | Read-only| string  | Yes| Information about the ability to migrate.|
| reversible | Read-only| boolean | Yes| Whether migration back is supported. Currently, this feature is not supported. This parameter is reserved and can be set to **false**.|

**Example**

```javascript
import device from '@system.device'
import ability from '@ohos.ability.featureability'

var DEVICE_LIST_LOCALHOST
export default {
    data: {
        title: "",
        deviceId: '',
        deviceList: [],
        remoteDeviceModel : new RemoteDeviceModel()
    },
    onInit() {
        DEVICE_LIST_LOCALHOST = {
            id: 'localhost',
        };
        this.deviceList = [DEVICE_LIST_LOCALHOST];
    },
    onShow() {
        const core = Core.getInstance()
        const expectExtend = new ExpectExtend({
            'id': 'extend'
        })
        const reportExtend = new ReportExtend(file)
        core.addService('expect', expectExtend)
        core.addService('report', reportExtend)
        core.init()
        const configService = core.getDefaultService('config')
        configService.setConfig(this)
        core.execute()
    },
    onReady() {
    },
    GetNetWorkId(){
        let self = this;
        this.remoteDeviceModel.registerDeviceListCallback(() => {
            var list = [];
            list[0] = DEVICE_LIST_LOCALHOST;
            var deviceList = self.remoteDeviceModel.deviceList;
            for (var i = 0; i < deviceList.length; i++) {
                list[i] = {
                    id: deviceList[i].deviceId,
                };
            }
            self.deviceList = list;
        });
    },
    ShowNetWorkId(){
        this.deviceId = this.deviceList[0].id;
    },

    async ContinueAbility(){
        function ContinueAbilityCallback(err) {
            console.info("=============>ContinueAbilityCallback============>");
        }
        var continueAbilityOptions = {
            reversible: false,
            deviceId: this.deviceId,
        }
        //continueAbility promise
        await ability.continueAbility(continueAbilityOptions).then(() => {
            console.info("=======>continueAbilityCallback=========>");
        });
    },
}
```

## AbilityResult

| Name| Readable/Writable| Type| Mandatory| Description|
| ---------- | -------- | --------------------- | ---- | ------------------------------------------------------------ |
| resultCode | Read-only| number                | Yes| Result code returned after the ability is destroyed. The feature for defining error-specific result codes is coming soon.|
| want       | Read-only| [Want](#want) | No| Data returned after the ability is destroyed. You can define the data to be returned. This parameter can be **null**.|

## StartAbilityParameter

| Name| Readable/Writable| Type| Mandatory| Description|
| ------------------- | -------- | -------------------- | ---- | ------------------------------------------------------------ |
| want                | Read-only| [Want](#want)        | Yes| Information about the ability to start.|
| abilityStartSetting | Read-only| {[key: string]: any} | No| Special attribute of the ability to start. This attribute can be passed in the method call.|

## Want

| Name| Readable/Writable| Type| Mandatory| Description|
| ----------- | -------- | -------------------- | ---- | ------------------------------------------------------------ |
| deviceId    | Read-only| string               | No| ID of the device that runs the ability.|
| bundleName  | Read-only| string               | No| Bundle name of the ability to start. If both **bundleName** and **abilityName** are specified in a **Want** object, the **Want** object can directly match the specified ability.|
| abilityName | Read-only| string               | No| Name of the ability to start. If both **bundleName** and **abilityName** are specified in a **Want** object, the **Want** object can directly match the specified ability.|
| uri         | Read-only| string               | No| URI information to match. If **uri** is specified in a **Want** object, the **Want** object will match the specified URI information, including **scheme**, **schemeSpecificPart**, **authority**, and **path**.|
| type        | Read-only| string               | No| MIME type, for example, text/plain or image/*.|
| flags       | Read-only| number               | No| How the **Want** object will be handled. By default, a number is passed. For details, see [flags](#flags).|
| action      | Read-only| string               | No| Action option.|
| parameters  | Read-only| {[key: string]: any} | No| List of parameters in a **Want** object.|
| entities    | Read-only| Array\<string>       | No| List of entities.|

## flags

| Name| Name| Description|
| ------------------------------------ | ---------- | ------------------------------------------------------------ |
| FLAG_AUTH_READ_URI_PERMISSION        | 0x00000001 | Indicates the permission to read the URI.|
| FLAG_AUTH_WRITE_URI_PERMISSION       | 0x00000002 | Indicates the permission to write the URI.|
| FLAG_ABILITY_FORWARD_RESULT          | 0x00000004 | Returns the result to the ability.|
| FLAG_ABILITY_CONTINUATION            | 0x00000008 | Indicates whether the ability on the local device can be migrated to a remote device.|
| FLAG_NOT_OHOS_COMPONENT              | 0x00000010 | Indicates that a component does not belong to OHOS.|
| FLAG_ABILITY_FORM_ENABLED            | 0x00000020 | Indicates whether to enable an ability.|
| FLAG_AUTH_PERSISTABLE_URI_PERMISSION | 0x00000040 | Indicates the permission to make the URI persistent.|
| FLAG_AUTH_PREFIX_URI_PERMISSION      | 0x00000080 | Indicates the permission to verify URIs by prefix matching.|
| FLAG_ABILITYSLICE_MULTI_DEVICE       | 0x00000100 | Supports cross-device startup in a distributed scheduler.|
| FLAG_START_FOREGROUND_ABILITY        | 0x00000200 | Indicates that the Service ability is started regardless of whether the host application has been started.|
| FLAG_ABILITY_CONTINUATION_REVERSIBLE | 0x00000400 | Indicates that the migration is reversible.|
| FLAG_INSTALL_ON_DEMAND               | 0x00000800 | Indicates that the specific ability will be installed if it has not been installed.|
| FLAG_INSTALL_WITH_BACKGROUND_MODE    | 0x80000000 | Indicates that the specific ability will be installed in the background if it has not been installed.|
| FLAG_ABILITY_CLEAR_MISSION           | 0x00008000 | Clears other operation missions. This flag can be set for the **Want** object passed to **ohos.app.Context#startAbility** and must be used together with **flag_ABILITY_NEW_MISSION**.|
| FLAG_ABILITY_NEW_MISSION             | 0x10000000 | Creates a mission on the historical mission stack.|
| FLAG_ABILITY_MISSION_TOP             | 0x20000000 | Starts the mission on the top of the existing mission stack; creates an ability instance if no mission exists.|
