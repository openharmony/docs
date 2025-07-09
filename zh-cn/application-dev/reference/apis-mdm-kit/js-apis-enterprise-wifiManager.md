# @ohos.enterprise.wifiManager（Wi-Fi管理）

本模块提供企业设备Wi-Fi管理能力，包括查询Wi-Fi开启状态等。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对设备管理应用开放，且调用接口前需激活设备管理应用，具体请参考[MDM Kit开发指南](../../mdm/mdm-kit-guide.md)。
>
> 全局通用限制类策略由restrictions统一提供，若要全局禁用Wi-Fi，请参考[@ohos.enterprise.restrictions（限制类策略）](js-apis-enterprise-restrictions.md)。

## 导入模块

```ts
import { wifiManager } from '@kit.MDMKit';
```

## wifiManager.isWifiActiveSync

isWifiActiveSync(admin: Want): boolean

查询当前设备Wi-Fi开启状态。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_WIFI

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                   |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |

**返回值：**

| 类型    | 说明                                                       |
| ------- | ---------------------------------------------------------- |
| boolean | 返回Wi-Fi开启状态，true表示Wi-Fi开启，false表示Wi-Fi关闭。 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { wifiManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
  let result: boolean = wifiManager.isWifiActiveSync(wantTemp);
  console.info(`Succeeded in query is wifi active or not, result : ${result}`);
} catch (err) {
  console.error(`Failed to query is wifi active or not. Code: ${err.code}, message: ${err.message}`);
}
```

## wifiManager.setWifiProfileSync

setWifiProfileSync(admin: Want, profile: WifiProfile): void

为当前设备配置Wi-Fi，使连接到指定网络。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_WIFI

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名  | 类型                                                    | 必填 | 说明                   |
| ------- | ------------------------------------------------------- | ---- | ---------------------- |
| admin   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |
| profile | [WifiProfile](#wifiprofile)                             | 是   | Wi-Fi配置信息。         |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { wifiManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  //需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let profile: wifiManager.WifiProfile = {
  //需根据实际情况进行替换
  'ssid': 'name',
  'preSharedKey': 'passwd',
  'securityType': wifiManager.WifiSecurityType.WIFI_SEC_TYPE_PSK
};

try {
  wifiManager.setWifiProfileSync(wantTemp, profile);
  console.info('Succeeded in setting wifi profile.');
} catch (err) {
  console.error(`Failed to set wifi profile. Code: ${err.code}, message: ${err.message}`);
}
```

## wifiManager.addAllowedWifiList<sup>19+</sup>

addAllowedWifiList(admin: Want, list: Array&lt;WifiAccessInfo&gt;): void

添加Wi-Fi允许名单。添加允许名单后当前设备仅允许连接该名单下的Wi-Fi。

以下情况下，调用本接口会报策略冲突：

1. 已经通过[setDiallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy)接口禁用了设备Wi-Fi能力。通过[setDiallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy)解除Wi-Fi禁用后，可解除冲突。
2. 已经通过[addDisallowedWifiList](#wifimanageradddisallowedwifilist19)接口添加了Wi-Fi禁用名单。通过[removeDisallowedWifiList](#wifimanagerremovedisallowedwifilist19)移除Wi-Fi禁用名单后，可解除冲突。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_WIFI

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名       | 类型                                                       | 必填 | 说明                                                         |
| ------------ | -------------------------------------------------------    | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md)    | 是   | 企业设备管理扩展组件。                                       |
| list         | Array&lt;[WifiAccessInfo](#wifiaccessinfo19)&gt;                   | 是   | Wi-Fi允许名单数组。数组总长度不能超过200。例如，若当前允许名单数组中已有100个Wi-Fi，则最多支持通过该接口再添加100个。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200010  | A conflict policy has been configured.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { wifiManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  //需根据实际情况进行替换
  bundleName: 'com.example.edmtest',
  abilityName: 'com.example.edmtest.EnterpriseAdminAbility'
};
try {
  let wifiIds: Array<wifiManager.WifiAccessInfo> = [{
    //需根据实际情况进行替换
    ssid: "wifi_name",
    bssid: "68:77:24:77:A6:D8"
  }];
  wifiManager.addAllowedWifiList(wantTemp, wifiIds);
  console.info(`Succeeded in adding allowed wifi list.`);
} catch (err) {
  console.error(`Failed to add allowed wifi list. Code: ${err.code}, message: ${err.message}`);
}
```

## wifiManager.removeAllowedWifiList<sup>19+</sup>

removeAllowedWifiList(admin: Want, list: Array&lt;WifiAccessInfo&gt;): void

移除Wi-Fi允许名单。若移除允许名单中的部分Wi-Fi，则当前设备仅允许连接剩下未移除的Wi-Fi。若移除允许名单中的所有Wi-Fi，则当前设备可以连接任意Wi-Fi。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_WIFI

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名       | 类型                                                    | 必填 | 说明                                                         |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                                       |
| list         | Array&lt;[WifiAccessInfo](#wifiaccessinfo19)&gt;                | 是   | 待移除的Wi-Fi允许名单数组。数组总长度不能超过200。                                            |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { wifiManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  //需根据实际情况进行替换
  bundleName: 'com.example.edmtest',
  abilityName: 'com.example.edmtest.EnterpriseAdminAbility'
};
try {
  let wifiIds: Array<wifiManager.WifiAccessInfo> = [{
    //需根据实际情况进行替换
    ssid: "wifi_name",
    bssid: "68:77:24:77:A6:D8"
  }];
  wifiManager.removeAllowedWifiList(wantTemp, wifiIds);
  console.info(`Succeeded in removing allowed wifi list.`);
} catch (err) {
  console.error(`Failed to remove allowed wifi list. Code: ${err.code}, message: ${err.message}`);
}
```

## wifiManager.getAllowedWifiList<sup>19+</sup>

getAllowedWifiList(admin: Want): Array&lt;WifiAccessInfo&gt;

获取Wi-Fi允许名单。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_WIFI

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                                   |
| ------ | ------------------------------------------------------- | ---- | -------------------------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |

**返回值：**

| 类型                               | 说明                      |
| ---------------------------------- | ------------------------- |
| Array&lt;[WifiAccessInfo](#wifiaccessinfo19)&gt; | Wi-Fi允许名单数组。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { wifiManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  //需根据实际情况进行替换
  bundleName: 'com.example.edmtest',
  abilityName: 'com.example.edmtest.EnterpriseAdminAbility'
};
try {
  let result: Array<wifiManager.WifiAccessInfo> = wifiManager.getAllowedWifiList(wantTemp);
  console.info(`Succeeded in getting allowed wifi list. Result: ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get allowed wifi list. Code: ${err.code}, message: ${err.message}`);
}
```

## wifiManager.addDisallowedWifiList<sup>19+</sup>

addDisallowedWifiList(admin: Want, list: Array&lt;WifiAccessInfo&gt;): void

添加Wi-Fi禁用名单。添加禁用名单后当前设备不允许连接该名单下的Wi-Fi。

以下情况下，调用本接口会报策略冲突：

1. 已经通过[setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy)接口禁用了设备Wi-Fi能力。通过[setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy)解除Wi-Fi禁用后，可解除冲突。
2. 已经通过[addAllowedWifiList](#wifimanageraddallowedwifilist19)接口添加了Wi-Fi允许名单。通过[removeAllowedWifiList](#wifimanagerremoveallowedwifilist19)移除Wi-Fi允许名单后，可解除冲突。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_WIFI

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名       | 类型                                                    | 必填 | 说明                                                         |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                                       |
| list         | Array&lt;[WifiAccessInfo](#wifiaccessinfo19)&gt;                | 是   | Wi-Fi禁用名单数组。数组总长度不能超过200。例如，若当前禁用名单数组中已有100个Wi-Fi，则最多支持通过该接口再添加100个。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200010  | A conflict policy has been configured.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { wifiManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  //需根据实际情况进行替换
  bundleName: 'com.example.edmtest',
  abilityName: 'com.example.edmtest.EnterpriseAdminAbility'
};
try {
  let wifiIds: Array<wifiManager.WifiAccessInfo> = [{
    //需根据实际情况进行替换
    ssid: "wifi_name",
    bssid: "68:77:24:77:A6:D8"
  }];
  wifiManager.addDisallowedWifiList(wantTemp, wifiIds);
  console.info(`Succeeded in adding disallowed wifi list.`);
} catch (err) {
  console.error(`Failed to add disallowed wifi list. Code: ${err.code}, message: ${err.message}`);
}
```

## wifiManager.removeDisallowedWifiList<sup>19+</sup>

removeDisallowedWifiList(admin: Want, list: Array&lt;WifiAccessInfo&gt;): void

移除Wi-Fi禁用名单。若移除禁用名单中的部分Wi-Fi，则当前设备不允许连接禁用名单内剩余的Wi-Fi。若移除禁用名单中的所有Wi-Fi，则当前设备可以连接任意的Wi-Fi。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_WIFI

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名       | 类型                                                    | 必填 | 说明                                                         |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                                       |
| list         | Array&lt;[WifiAccessInfo](#wifiaccessinfo19)&gt;                | 是   | 待移除的Wi-Fi禁用名单数组。数组总长度不能超过200。                      |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { wifiManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  //需根据实际情况进行替换
  bundleName: 'com.example.edmtest',
  abilityName: 'com.example.edmtest.EnterpriseAdminAbility'
};
try {
  let wifiIds: Array<wifiManager.WifiAccessInfo> = [{
    //需根据实际情况进行替换
    ssid: "wifi_name",
    bssid: "68:77:24:77:A6:D8"
  }];
  wifiManager.removeDisallowedWifiList(wantTemp, wifiIds);
  console.info(`Succeeded in removing disallowed wifi list.`);
} catch (err) {
  console.error(`Failed to remove disallowed wifi list. Code: ${err.code}, message: ${err.message}`);
}
```

## wifiManager.getDisallowedWifiList<sup>19+</sup>

getDisallowedWifiList(admin: Want): Array&lt;WifiAccessInfo&gt;

获取Wi-Fi禁用名单。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_WIFI

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                                   |
| ------ | ------------------------------------------------------- | ---- | -------------------------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |

**返回值：**

| 类型                               | 说明                      |
| ---------------------------------- | ------------------------- |
| Array&lt;[WifiAccessInfo](#wifiaccessinfo19)&gt; | Wi-Fi禁用名单数组。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { wifiManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  //需根据实际情况进行替换
  bundleName: 'com.example.edmtest',
  abilityName: 'com.example.edmtest.EnterpriseAdminAbility'
};
try {
  let result: Array<wifiManager.WifiAccessInfo> = wifiManager.getDisallowedWifiList(wantTemp);
  console.info(`Succeeded in getting disallowed wifi list. Result: ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get disallowed wifi list. Code: ${err.code}, message: ${err.message}`);
}
```

## WifiAccessInfo<sup>19+</sup>

Wi-Fi的SSID和BSSID信息。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



| 名称          | 类型                             | 只读 | 可选 | 说明                                                        |
| ------------- | --------------------------------| ---- | -----| ------------------------------------------------------ |
| ssid          | string                           | 否   | 否 | Wi-Fi热点名称，编码格式为UTF-8，最大长度为32字节（中文字符占3位，英文字符占1位）。           |
| bssid         | string                           | 否   | 是 | Wi-Fi热点的mac地址，例如：00:11:22:33:44:55。<br/>调用[addAllowedWifiList](#wifimanageraddallowedwifilist19)和[removeAllowedWifiList](#wifimanagerremoveallowedwifilist19)时为必填。<br/>调用[addDisallowedWifiList](#wifimanageradddisallowedwifilist19)和[removeDisallowedWifiList](#wifimanagerremovedisallowedwifilist19)时为选填（默认值为空字符串）。            |

## WifiProfile

Wi-Fi配置信息。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



| 名称          | 类型                              | 只读 | 可选 | 说明                                                        |
| ------------- | ----------------------------------| ---- | ----| ------------------------------------------------------- |
| ssid          | string                                | 否   | 否 | 热点的SSID，编码格式为UTF-8。                               |
| bssid         | string                                | 否   | 是 | 热点的BSSID。                                               |
| preSharedKey  | string                                | 否   | 否 | 热点的密钥。                                                |
| isHiddenSsid  | boolean                               | 否   | 是 | 是否是隐藏网络。true表示是隐藏网络，false表示不是隐藏网络。 |
| securityType  | [WifiSecurityType](#wifisecuritytype) | 否   | 否 | 加密类型。                                                  |
| creatorUid    | number                                | 否   | 是 | 创建用户的ID。                                              |
| disableReason | number                                | 否   | 是 | 禁用原因。                                                  |
| netId         | number                                | 否   | 是 | 分配的网络ID。                                              |
| randomMacType | number                                | 否   | 是 | 随机MAC类型。                                               |
| randomMacAddr | string                                | 否   | 是 | 随机MAC地址。                                               |
| ipType        | [IpType](#iptype)                     | 否   | 是 | IP地址类型。                                                |
| staticIp      | [IpProfile](#ipprofile)               | 否   | 是 | 静态IP配置信息。                                            |
| eapProfile    | [WifiEapProfile](#wifieapprofile)     | 否   | 是 | 可扩展身份验证协议配置。                                    |

## WifiSecurityType

表示加密类型的枚举。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



| 名称                      | 值   | 说明                                                         |
| ------------------------- | ---- | ------------------------------------------------------------ |
| WIFI_SEC_TYPE_INVALID     | 0    | 无效加密类型。                                               |
| WIFI_SEC_TYPE_OPEN        | 1    | 开放加密类型。                                               |
| WIFI_SEC_TYPE_WEP         | 2    | Wired&nbsp;Equivalent&nbsp;Privacy&nbsp;(WEP)加密类型。      |
| WIFI_SEC_TYPE_PSK         | 3    | Pre-shared&nbsp;key&nbsp;(PSK)加密类型。                     |
| WIFI_SEC_TYPE_SAE         | 4    | Simultaneous&nbsp;Authentication&nbsp;of&nbsp;Equals&nbsp;(SAE)加密类型。 |
| WIFI_SEC_TYPE_EAP         | 5    | EAP加密类型。                                                |
| WIFI_SEC_TYPE_EAP_SUITE_B | 6    | Suite-B 192位加密类型。                                      |
| WIFI_SEC_TYPE_OWE         | 7    | 机会性无线加密类型。                                         |
| WIFI_SEC_TYPE_WAPI_CERT   | 8    | WAPI-Cert加密类型。                                          |
| WIFI_SEC_TYPE_WAPI_PSK    | 9    | WAPI-PSK加密类型。                                           |

## IpType

表示IP类型的枚举。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



| 名称    | 值   | 说明           |
| ------- | ---- | -------------- |
| STATIC  | 0    | 静态IP。       |
| DHCP    | 1    | 通过DHCP获取。 |
| UNKNOWN | 2    | 未指定。       |

## IpProfile

IP配置信息。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



| 名称         | 类型                | 必填 | 说明        |
| ------------ | ------------------- | ---- | ----------- |
| ipAddress    | number              | 是   | IP地址。    |
| gateway      | number              | 是   | 网关。      |
| prefixLength | number              | 是   | 掩码。      |
| dnsServers   | number[]            | 是   | DNS服务器。 |
| domains      | Array&lt;string&gt; | 是   | 域信息。    |

## WifiEapProfile

可扩展身份验证协议配置信息。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



| 名称              | 类型                          | 只读 | 可选 | 说明                             |
| ----------------- | ----------------------------- | ---- |----| -------------------------------- |
| eapMethod         | [EapMethod](#eapmethod)       | 否   | 否 | AP认证方式。                     |
| phase2Method      | [Phase2Method](#phase2method) | 否   | 否 | 第二阶段认证方式。               |
| identity          | string                        | 否   | 否 | 身份信息。                       |
| anonymousIdentity | string                        | 否   | 否 | 匿名身份。                       |
| password          | string                        | 否   | 否 | 密码。                           |
| caCertAliases     | string                        | 否   | 否 | CA 证书别名。                    |
| caPath            | string                        | 否   | 否 | CA 证书路径。                    |
| clientCertAliases | string                        | 否   | 否 | 客户端证书别名。                 |
| certEntry         | Uint8Array                    | 否   | 否 | CA 证书内容。                    |
| certPassword      | string                        | 否   | 否 | CA证书密码。                     |
| altSubjectMatch   | string                        | 否   | 否 | 替代主题匹配。                   |
| domainSuffixMatch | string                        | 否   | 否 | 域后缀匹配。                     |
| realm             | string                        | 否   | 否 | 通行证凭证的领域。               |
| plmn              | string                        | 否   | 否 | 公共陆地移动网的直通凭证提供商。 |
| eapSubId          | number                        | 否   | 否 | SIM卡的子ID。                    |

## EapMethod

表示EAP认证方式的枚举。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



| 名称           | 值   | 说明             |
| -------------- | ---- | ---------------- |
| EAP_NONE       | 0    | 不指定。         |
| EAP_PEAP       | 1    | PEAP类型。       |
| EAP_TLS        | 2    | TLS类型。        |
| EAP_TTLS       | 3    | TTLS类型。       |
| EAP_PWD        | 4    | PWD类型。        |
| EAP_SIM        | 5    | SIM类型。        |
| EAP_AKA        | 6    | AKA类型。        |
| EAP_AKA_PRIME  | 7    | AKA Prime类型。  |
| EAP_UNAUTH_TLS | 8    | UNAUTH TLS类型。 |

## Phase2Method

表示第二阶段认证方式的枚举。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



| 名称             | 值   | 说明            |
| ---------------- | ---- | --------------- |
| PHASE2_NONE      | 0    | 不指定。        |
| PHASE2_PAP       | 1    | PAP类型。       |
| PHASE2_MSCHAP    | 2    | MSCHAP类型。    |
| PHASE2_MSCHAPV2  | 3    | MSCHAPV2类型。  |
| PHASE2_GTC       | 4    | GTC类型。       |
| PHASE2_SIM       | 5    | SIM类型。       |
| PHASE2_AKA       | 6    | AKA类型。       |
| PHASE2_AKA_PRIME | 7    | AKA Prime类型。 |

## wifiManager.turnOnWifi<sup>20+</sup>

turnOnWifi(admin: Want, isForce: boolean): void

打开Wi-Fi开关。

以下情况下，通过本接口打开Wi-Fi开关，会打开失败并提示"系统功能被禁用"：

​	已经通过[setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy)接口禁用了Wi-Fi。需通过[setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy)接口启用Wi-Fi，解决"系统功能被禁用"报错。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_WIFI

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名  | 类型                                                    | 必填 | 说明                                                         |
| ------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                                       |
| isForce | boolean                                                 | 是   | 是否强制打开Wi-Fi功能。<br/>true表示强制开启Wi-Fi，强制开启后不支持用户在设备上手动关闭Wi-Fi开关，必须采用[turnOffWifi](#wifimanagerturnoffwifi20)接口关闭。false表示非强制开启Wi-Fi，此时用户可以在设备上手动操作关闭Wi-Fi开关。 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 203      | This function is prohibited by enterprise management policies. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { wifiManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

try {
  wifiManager.turnOnWifi(wantTemp, true);
  console.info(`Succeeded in turning on wifi.`);
} catch (err) {
  console.error(`Failed to turn on wifi. Code: ${err.code}, message: ${err.message}`);
}
```

## wifiManager.turnOffWifi<sup>20+</sup>

turnOffWifi(admin: Want): void

关闭Wi-Fi开关。

以下情况下，通过本接口关闭Wi-Fi开关，会提示"系统功能被禁用"：

​	已经通过[setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy)接口禁用了Wi-Fi。需通过[setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy)接口启用Wi-Fi，解决"系统功能被禁用"报错。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_WIFI

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                   |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 203      | This function is prohibited by enterprise management policies. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { wifiManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

try {
  wifiManager.turnOffWifi(wantTemp);
  console.info(`Succeeded in turning off wifi.`);
} catch (err) {
  console.error(`Failed to turn off wifi. Code: ${err.code}, message: ${err.message}`);
}
```

