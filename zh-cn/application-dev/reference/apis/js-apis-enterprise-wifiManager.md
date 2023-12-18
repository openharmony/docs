# @ohos.enterprise.wifiManager（WiFi管理）

本模块提供企业设备WiFi管理能力，包括查询WiFi开启状态等。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对[设备管理应用](enterpriseDeviceManagement-overview.md#基本概念)开放，需将[设备管理应用激活](js-apis-enterprise-adminManager.md#adminmanagerenableadmin)后调用，实现相应功能。

## 导入模块

```ts
import wifiManager from '@ohos.enterprise.wifiManager';
```

## wifiManager.isWifiActive

isWifiActive(admin: Want, callback: AsyncCallback&lt;boolean&gt;): void

指定设备管理应用查询wifi开启状态。使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_SET_WIFI

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理应用。                  |
| callback | AsyncCallback&lt;boolean&gt;            | 是    | 回调函数，当接口调用成功，err为null，data为boolean值，true表示wifi开启，false表示wifi关闭，否则err为错误对象。       |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

wifiManager.isWifiActive(wantTemp, (err, result) => {
  if (err) {
    console.error(`Failed to query is wifi active or not. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in query is wifi active or not, result : ${result}`);
});
```

## wifiManager.isWifiActive

isWifiActive(admin: Want): Promise&lt;boolean&gt;

指定设备管理应用获取wifi开启状态。使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_SET_WIFI

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;boolean&gt; | Promise结果，返回wifi开启状态，true表示wifi开启，false表示wifi关闭。  |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

wifiManager.isWifiActive(wantTemp).then((result) => {
  console.info(`Succeeded in query is wifi active or not, result : ${result}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to query is wifi active or not. Code: ${err.code}, message: ${err.message}`);
});
```

## wifiManager.setWifiProfile

setWifiProfile(admin: Want, profile: WifiProfile, callback: AsyncCallback&lt;void&gt;): void

指定设备管理应用为设备配置wifi，使连接到指定网络。使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_SET_WIFI

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理应用。                  |
| profile    | [WifiProfile](#wifiprofile)     | 是    | WLAN配置信息。                  |
| callback | AsyncCallback&lt;void&gt;            | 是    | 回调函数，当接口调用成功，err为null，否则为错误对象。      |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let profile: wifiManager.WifiProfile = {
  'ssid': 'name',
  'preSharedKey': 'passwd',
  'securityType': wifiManager.WifiSecurityType.WIFI_SEC_TYPE_PSK
};

wifiManager.setWifiProfile(wantTemp, profile, (err) => {
  if (err) {
    console.error(`Failed to set wifi profile. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in setting wifi profile');
});
```

## wifiManager.setWifiProfile

setWifiProfile(admin: Want, profile: WifiProfile): Promise&lt;void&gt;

指定设备管理应用为设备配置wifi，使连接到指定网络。使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_SET_WIFI

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。 |
| profile    | [WifiProfile](#wifiprofile)     | 是    | WLAN配置信息。                  |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。当配置wifi连接到指定网络失败时会抛出错误对象。 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let profile: wifiManager.WifiProfile = {
  'ssid': 'name',
  'preSharedKey': 'passwd',
  'securityType': wifiManager.WifiSecurityType.WIFI_SEC_TYPE_PSK
};

wifiManager.setWifiProfile(wantTemp, profile).then(() => {
  console.info('Succeeded in setting wifi profile');
}).catch((err: BusinessError) => {
  console.error(`Failed to set wifi profile. Code: ${err.code}, message: ${err.message}`);
});
```

## WifiProfile

WLAN配置信息

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

| 名称         | 类型     | 可读 | 可写   | 说明                            |
| ----------- | --------| ---- | ----- | ------------------------------- |
| ssid | string | 是 | 否 | 热点的SSID，编码格式为UTF-8。 |
| bssid | string | 是 | 否 | 热点的BSSID。 |
| preSharedKey | string | 是 | 否 | 热点的密钥。 |
| isHiddenSsid | boolean | 是 | 否 | 是否是隐藏网络。 |
| securityType | [WifiSecurityType](#wifisecuritytype) | 是 | 否 | 加密类型。 |
| creatorUid | number | 是 | 否 | 创建用户的ID。 |
| disableReason | number | 是 | 否 | 禁用原因。 |
| netId | number | 是 | 否 | 分配的网络ID。 |
| randomMacType | number | 是 | 否 | 随机MAC类型 |
| randomMacAddr | string | 是 | 否 | 随机MAC地址 |
| ipType | [IpType](#iptype) | 是 | 否 | IP地址类型 |
| staticIp | [IpProfile](#ipprofile) | 是 | 否 | 静态IP配置信息。 |
| eapProfile | [WifiEapProfile](#wifieapprofile) | 是 | 否 | 可扩展身份验证协议配置。 |

## WifiSecurityType

表示加密类型的枚举。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| WIFI_SEC_TYPE_INVALID | 0 | 无效加密类型。 |
| WIFI_SEC_TYPE_OPEN | 1 | 开放加密类型。 |
| WIFI_SEC_TYPE_WEP | 2 | Wired&nbsp;Equivalent&nbsp;Privacy&nbsp;(WEP)加密类型。 |
| WIFI_SEC_TYPE_PSK | 3 | Pre-shared&nbsp;key&nbsp;(PSK)加密类型。 |
| WIFI_SEC_TYPE_SAE | 4 | Simultaneous&nbsp;Authentication&nbsp;of&nbsp;Equals&nbsp;(SAE)加密类型。 |
| WIFI_SEC_TYPE_EAP | 5 | EAP加密类型。 |
| WIFI_SEC_TYPE_EAP_SUITE_B | 6 | Suite-B 192位加密类型。 |
| WIFI_SEC_TYPE_OWE | 7 | 机会性无线加密类型。 |
| WIFI_SEC_TYPE_WAPI_CERT | 8 | WAPI-Cert加密类型。 |
| WIFI_SEC_TYPE_WAPI_PSK | 9 | WAPI-PSK加密类型。 |

## IpType

表示IP类型的枚举。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| STATIC | 0 | 静态IP。 |
| DHCP | 1 | 通过DHCP获取。 |
| UNKNOWN | 2 | 未指定。 |

## IpProfile

IP配置信息。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| ipAddress | number | 是 | 否 | IP地址。 |
| gateway | number | 是 | 否 | 网关。 |
| prefixLength | number | 是 | 否 | 掩码。 |
| dnsServers | number[] | 是 | 否 | DNS服务器。 |
| domains | Array&lt;string&gt; | 是 | 否 | 域信息。 |

## WifiEapProfile

可扩展身份验证协议配置信息。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

| **名称** | **类型** | **可读** | **可写** | **说明** |
| -------- | -------- | -------- | -------- | -------- |
| eapMethod | [EapMethod](#eapmethod) | 是 | 否 | EAP认证方式。 |
| phase2Method | [Phase2Method](#phase2method) | 是 | 否 | 第二阶段认证方式。 |
| identity | string | 是 | 否 | 身份信息。 |
| anonymousIdentity | string | 是 | 否 | 匿名身份。 |
| password | string | 是 | 否 | 密码。 |
| caCertAliases | string | 是 | 否 | CA 证书别名。 |
| caPath | string | 是 | 否 | CA 证书路径。 |
| clientCertAliases | string | 是 | 否 | 客户端证书别名。 |
| certEntry | Uint8Array | 是 | 是 | CA 证书内容。 |
| certPassword | string | 是 | 是 | CA证书密码。 |
| altSubjectMatch | string | 是 | 否 | 替代主题匹配。 |
| domainSuffixMatch | string | 是 | 否 | 域后缀匹配。 |
| realm | string | 是 | 否 | 通行证凭证的领域。 |
| plmn | string | 是 | 否 | 公共陆地移动网的直通凭证提供商。 |
| eapSubId | number | 是 | 否 | SIM卡的子ID。 |

## EapMethod

表示EAP认证方式的枚举。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| EAP_NONE | 0 | 不指定。 |
| EAP_PEAP | 1 | PEAP类型。 |
| EAP_TLS | 2 | TLS类型。 |
| EAP_TTLS | 3 | TTLS类型。 |
| EAP_PWD | 4 | PWD类型。 |
| EAP_SIM | 5 | SIM类型。 |
| EAP_AKA | 6 | AKA类型。 |
| EAP_AKA_PRIME | 7 | AKA Prime类型。 |
| EAP_UNAUTH_TLS | 8 | UNAUTH TLS类型。 |


## Phase2Method

表示第二阶段认证方式的枚举。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| PHASE2_NONE | 0 | 不指定。 |
| PHASE2_PAP | 1 | PAP类型。 |
| PHASE2_MSCHAP | 2 | MSCHAP类型。 |
| PHASE2_MSCHAPV2 | 3 | MSCHAPV2类型。 |
| PHASE2_GTC | 4 | GTC类型。 |
| PHASE2_SIM | 5 | SIM类型。 |
| PHASE2_AKA | 6 | AKA类型。 |
| PHASE2_AKA_PRIME | 7 | AKA Prime类型。 |

## wifiManager.isWifiDisabled<sup>11+</sup>

isWifiDisabled(admin: Want): boolean

指定设备管理应用查询wifi是否被禁用。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_WIFI

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API：** 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| boolean | 返回wifi禁用状态，true表示wifi被禁用，false表示wifi未被禁用。 |

**错误码：**

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
try {
  boolean result = wifiManager.isWifiDisabled(wantTemp);
  console.info(`Succeeded in query the wifi is disabled or not, result : ${result}`);
} catch((err) {
  console.error(`Failed to query the wifi is disabled or not. Code: ${err.code}, message: ${err.message}`);
});
```

## wifiManager.setWifiDisabled<sup>11+</sup>

setWifiDisabled(admin: Want, isDisabled: boolean): void

指定设备管理应用设置禁用wifi策略。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_WIFI

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API：** 此接口为系统接口。

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                      |
| ---------- | ----------------------------------- | ---- | ----------------------------------------- |
| admin      | [Want](js-apis-app-ability-want.md) | 是   | 设备管理应用。                            |
| isDisabled | boolean                             | 是   | true表示禁用wifi，false表示解除wifi禁用。 |

**错误码：**

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | the application is not an administrator of the device.       |
| 9200002  | the administrator application does not have permission to manage the device. |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
  wifiManager.setWifiDisabled(wantTemp, true);
  console.info('Succeeded in set the wifi disabled');
} catch((err) {
  console.error(`Failed to set the wifi disabled. Code: ${err.code}, message: ${err.message}`);
});
```
