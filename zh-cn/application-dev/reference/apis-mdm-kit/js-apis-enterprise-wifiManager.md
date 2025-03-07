# @ohos.enterprise.wifiManager（Wi-Fi管理）

本模块提供企业设备Wi-Fi管理能力，包括查询Wi-Fi开启状态等。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对[设备管理应用](../../mdm/mdm-kit-guide.md#功能介绍)开放，需将设备管理应用激活后调用，实现相应功能。
>
> 全局通用限制类策略由restrictions统一提供，若要全局禁用Wi-Fi，请参考[@ohos.enterprise.restrictions（限制类策略）](js-apis-enterprise-restrictions.md)。

## 导入模块

```ts
import { wifiManager } from '@kit.MDMKit';
```

## wifiManager.isWifiActiveSync

isWifiActiveSync(admin: Want): boolean

查询设备Wi-Fi开启状态。

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

为设备配置Wi-Fi，使连接到指定网络。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_WIFI

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名  | 类型                                                    | 必填 | 说明                   |
| ------- | ------------------------------------------------------- | ---- | ---------------------- |
| admin   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |
| profile | [WifiProfile](#wifiprofile)                             | 是   | WLAN配置信息。         |

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
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let profile: wifiManager.WifiProfile = {
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

## WifiProfile

WLAN配置信息。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



| 名称          | 类型                                  | 必填 | 说明                          |
| ------------- | ------------------------------------- | ---- | ----------------------------- |
| ssid          | string                                | 是   | 热点的SSID，编码格式为UTF-8。 |
| bssid         | string                                | 否   | 热点的BSSID。                 |
| preSharedKey  | string                                | 是   | 热点的密钥。                  |
| isHiddenSsid  | boolean                               | 否   | 是否是隐藏网络。              |
| securityType  | [WifiSecurityType](#wifisecuritytype) | 是   | 加密类型。                    |
| creatorUid    | number                                | 否   | 创建用户的ID。                |
| disableReason | number                                | 否   | 禁用原因。                    |
| netId         | number                                | 否   | 分配的网络ID。                |
| randomMacType | number                                | 否   | 随机MAC类型。                 |
| randomMacAddr | string                                | 否   | 随机MAC地址。                 |
| ipType        | [IpType](#iptype)                     | 否   | IP地址类型。                  |
| staticIp      | [IpProfile](#ipprofile)               | 否   | 静态IP配置信息。              |
| eapProfile    | [WifiEapProfile](#wifieapprofile)     | 否   | 可扩展身份验证协议配置。      |

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



| 名称              | 类型                          | 必填 | 说明                             |
| ----------------- | ----------------------------- | ---- | -------------------------------- |
| eapMethod         | [EapMethod](#eapmethod)       | 是   | AP认证方式。                     |
| phase2Method      | [Phase2Method](#phase2method) | 是   | 第二阶段认证方式。               |
| identity          | string                        | 是   | 身份信息。                       |
| anonymousIdentity | string                        | 是   | 匿名身份。                       |
| password          | string                        | 是   | 密码。                           |
| caCertAliases     | string                        | 是   | CA 证书别名。                    |
| caPath            | string                        | 是   | CA 证书路径。                    |
| clientCertAliases | string                        | 是   | 客户端证书别名。                 |
| certEntry         | Uint8Array                    | 是   | CA 证书内容。                    |
| certPassword      | string                        | 是   | CA证书密码。                     |
| altSubjectMatch   | string                        | 是   | 替代主题匹配。                   |
| domainSuffixMatch | string                        | 是   | 域后缀匹配。                     |
| realm             | string                        | 是   | 通行证凭证的领域。               |
| plmn              | string                        | 是   | 公共陆地移动网的直通凭证提供商。 |
| eapSubId          | number                        | 是   | SIM卡的子ID。                    |

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
