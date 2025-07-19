# 扩展认证


# @ohos.net.eap (网络管理EAP模块)

该模块提供了三方客户端介入802.1X认证流程的机制，支撑客户端的定制认证。

> **说明：**
> 
> 本模块首批接口从API version 20开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import {eap} from '@kit.NetworkKit';
```

## eap.regCustomEapHandler

regCustomEapHandler(netType: number, eapCode: number, eapType: number, callback: Callback\<EapData\>): void;

用于指定需要定制化处理的EAP报文类型和对应的处理callback。系统会将符合条件的EAP报文送入callback函数中供企业应用获取

**需要权限**：ohos.permission.MANAGE_ENTERPRISE_WIFI_CONNECTION

**系统能力**：SystemCapability.Communication.NetManager.Eap
**参数：**

| 参数名                              | 类型|必填|说明|
| ----------------------------- | ---------- |---------- |---------- |
| netType| number|是|网络类型|
| eapCode|number |是|需要进行定制的EAP code. 取值范围为1，2，3，4|
| eapType| number |是|需要进行定制处理的EAP method类型|
| callback| Callback |是|对指定的code+type的报文进行回调处理|

**错误码**：

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.          |
|33200006 | Invalid net type.          |
|33200007 | Invalid eap code.          |
|33200008 | Invalid eap type.          |
|33200009 | netmanager stop.          |
|33200099 | internal error.          |

**示例：**

```js
import {eap} from '@kit.NetworkKit';
import {BusinessError} from '@kit.BaseicServicesKit';
try {
    eap.regCustomEapHandler(netType, eapCode, eapType, eapData);
    console.info('regCustomEapHandler success');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## eap.unregCustomEapHandler

unregCustomEapHandler(netType:number, eapCode: number, eapType: number, callback: Callback\<EapData\>): void;

用于指定需要取消定制化处理的EAP报文类型和对应的处理callback

**需要权限**：ohos.permission.MANAGE_ENTERPRISE_WIFI_CONNECTION

**系统能力**：SystemCapability.Communication.NetManager.Eap
**参数：**

| 类型                            | 类型|必填|说明|
| ----------------------------- | ---------- |---------- |---------- |
| netType| number|是|网络类型|
| eapCode|number |是|需要进行定制的EAP code. 取值范围为1，2，3，4|
| eapType| number |是|需要进行定制处理的EAP method类型|
| callback| Callback |是|对指定的code+type的报文进行回调处理|

**错误码**：

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.          |
|33200006 | Invalid net type.          |
|33200007 | Invalid eap code.          |
|33200008 | Invalid eap type.          |
|33200009 | netmanager stop.          |
|33200099 | internal error.          |

**示例：**

```js
import {eap} from '@kit.NetworkKit';
import {BusinessError} from '@kit.BaseicServicesKit';
try {
    eap.unregCustomEapHandler(netType, eapCode, eapType, eapData);
    console.info('unregCustomEapHandler success');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## eap.replyCustomEapData

replyCustomEapData(result:number, data: number): void;

该接口用于通知系统已完成该步定制化处理。若用于处理rx时的callback，传给系统的eap数据需要剥离服务器添加的定制部分。若用于处理tx时的callback，传给系统的eap数据为经过添加定制部分后的eap数据

**需要权限**：ohos.permission.MANAGE_ENTERPRISE_WIFI_CONNECTION
**系统能力**：SystemCapability.Communication.NetManager.Eap
**参数：**

| 参数名                            | 类型|必填|说明|
| ----------------------------- | ---------- |---------- |---------- |
| result| CustomResult|是|定制化判定结果|
| data|EapData |是|经过定制化的eap数据|

**错误码**：

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.          |
|33200004 | Invalid result.          |
|33200005 | Invalid size of eap data.          |
|33200009 | netmanager stop.          |
|33200099 | internal error.          |

```js
import {eap} from '@kit.NetworkKit';
import {BusinessError} from '@kit.BaseicServicesKit';
try {
    eap.replyCustomEapData(result, eapData);
    console.info('replyCustomEapData success');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## eap.startEthEap

startEthEap(netId: number, profile: EthEapProfile): void;
该接口用于指定一个以太网卡发起EAP认证。

**需要权限**：ohos.permission.MANAGE_ENTERPRISE_WIFI_CONNECTION
**系统能力**：SystemCapability.Communication.NetManager.Eap
**参数：**

| 参数名                            | 类型|必填|说明|
| ----------------------------- | ---------- |---------- |---------- |
| netId| number|是|network Id|
| profile|EthEapProfile |是|eap profile|

**错误码**：

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.          |
|33200001 | Invalid netId.          |
|33200003 | Invalid profile.          |
|33200009 | netmanager stop.          |
|33200010 | invalid eth state.          |
|33200099 | internal error.          |

**示例：**

```js
import {eap} from '@kit.NetworkKit';
import {BusinessError} from '@kit.BaseicServicesKit';
try {
    let netId = 100;
    eap.startEthEap(netId, profile);
    console.log('startEthEap success');
  } catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
  }
```

## eap.logOffEthEap

logOffEthEap(netId: number): void;
该接口用于指定一个以太网卡从EAP已认证状态退出。

**需要权限**：ohos.permission.MANAGE_ENTERPRISE_WIFI_CONNECTION
**系统能力**：SystemCapability.Communication.NetManager.Eap
**参数：**

| 参数名                            | 类型|必填|说明|
| ----------------------------- | ---------- |---------- |---------- |
| netId| number|是|network Id|
| profile|EthEapProfile|是|eap profile|

**错误码**：

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.          |
|33200001 | Invalid netId.          |
|33200002 | Log off fail.          |
|33200009 | netmanager stop.          |
|33200010 | invalid eth state.          |
|33200099 | internal error.          |

**示例：**

```js
import {eap} from '@kit.NetworkKit';
import {BusinessError} from '@kit.BaseicServicesKit';
try{
    let netId = 100;
    eap.logOffEthEap(netId);
    console.error("logOffEthEap succes");
 } catch (err) {
    console.error("errCode: " + (err as BusinessError).code) ', errMessage: ' + (err as BusinessError).message);
 }
```