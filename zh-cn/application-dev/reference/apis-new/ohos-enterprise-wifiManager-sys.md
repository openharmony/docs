# @ohos.enterprise.wifiManager    
本模块提供企业设备WiFi管理能力，包括查询WiFi开启状态等。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import wifiManager from '@ohos.enterprise.wifiManager'    
```  
    
## WifiSecurityType    
表示加密类型的枚举。    
    
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager    
 **系统接口：** 此接口为系统接口。    
    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| WIFI_SEC_TYPE_INVALID | 0 | 无效加密类型。 |  
| WIFI_SEC_TYPE_OPEN | 1 | 开放加密类型。 |  
| WIFI_SEC_TYPE_WEP | 2 | WiredEquivalentPrivacy(WEP)加密类型。 |  
| WIFI_SEC_TYPE_PSK | 3 | Pre-sharedkey(PSK)加密类型。 |  
| WIFI_SEC_TYPE_SAE | 4 | SimultaneousAuthenticationofEquals(SAE)加密类型。 |  
| WIFI_SEC_TYPE_EAP | 5 | EAP加密类型。 |  
| WIFI_SEC_TYPE_EAP_SUITE_B | 6 | Suite-B 192位加密类型。 |  
| WIFI_SEC_TYPE_OWE | 7 | 机会性无线加密类型。 |  
| WIFI_SEC_TYPE_WAPI_CERT | 8 | WAPI-Cert加密类型。 |  
| WIFI_SEC_TYPE_WAPI_PSK | 9 | WAPI-PSK加密类型。 |  
    
## IpType    
表示IP类型的枚举。    
    
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager    
 **系统接口：** 此接口为系统接口。    
    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| STATIC | 0 | 静态IP。 |  
| DHCP | 1 | 通过DHCP获取。 |  
| UNKNOWN | 2 | 未指定。 |  
    
## IpProfile    
IP配置信息。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager    
### 属性    
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager    
 **系统接口：** 此接口为系统接口。    
    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| ipAddress | number | false | true | IP地址。 |  
| gateway | number | false | true | 网关。 |  
| prefixLength | number | false | true | 掩码。 |  
| dnsServers | number[] | false | true | DNS服务器。 |  
| domains | Array<string> | false | true | 域信息。 |  
    
## EapMethod    
表示EAP认证方式的枚举。    
    
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager    
 **系统接口：** 此接口为系统接口。    
    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
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
    
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager    
 **系统接口：** 此接口为系统接口。    
    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| PHASE2_NONE | 0 | 不指定。 |  
| PHASE2_PAP | 1 | PAP类型。 |  
| PHASE2_MSCHAP | 2 | MSCHAP类型。 |  
| PHASE2_MSCHAPV2 | 3 | MSCHAPV2类型。 |  
| PHASE2_GTC | 4 | GTC类型。 |  
| PHASE2_SIM | 5 | SIM类型。 |  
| PHASE2_AKA | 6 | AKA类型。 |  
| PHASE2_AKA_PRIME | 7 | AKA Prime类型。 |  
    
## WifiEapProfile    
可扩展身份验证协议配置信息。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager    
### 属性    
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager    
 **系统接口：** 此接口为系统接口。    
    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| eapMethod | EapMethod | false | true | EAP认证方式。 |  
| phase2Method | Phase2Method | false | true | 第二阶段认证方式。 |  
| identity | string | false | true | 身份信息。 |  
| anonymousIdentity | string | false | true | 匿名身份。 |  
| password | string | false | true | 密码。 |  
| caCertAliases | string | false | true | CA 证书别名。 |  
| caPath | string | false | true | CA 证书路径。 |  
| clientCertAliases | string | false | true | 客户端证书别名。 |  
| certEntry | Uint8Array | false | true | CA 证书内容。 |  
| certPassword | string | false | true | CA证书密码。 |  
| altSubjectMatch | string | false | true | 替代主题匹配。 |  
| domainSuffixMatch | string | false | true | 域后缀匹配。 |  
| realm | string | false | true | 通行证凭证的领域。 |  
| plmn | string | false | true | 公共陆地移动网的直通凭证提供商。 |  
| eapSubId | number | false | true | SIM卡的子ID。 |  
    
## WifiProfile    
WLAN配置信息  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager    
### 属性    
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager    
 **系统接口：** 此接口为系统接口。    
    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| ssid | string | false | true | 热点的SSID，编码格式为UTF-8。 |  
| bssid | string | false | false | 热点的BSSID。 |  
| preSharedKey | string | false | true | 热点的密钥。 |  
| isHiddenSsid | boolean | false | false | 是否是隐藏网络。 |  
| securityType | WifiSecurityType | false | true | 加密类型。 |  
| creatorUid | number | false | false | 创建用户的ID。 |  
| disableReason | number | false | false | 禁用原因。 |  
| netId | number | false | false | 分配的网络ID。 |  
| randomMacType | number | false | false | 随机MAC类型 |  
| randomMacAddr | string | false | false | 随机MAC地址 |  
| ipType | IpType | false | false | IP地址类型 |  
| staticIp | IpProfile | false | false | 静态IP配置信息。 |  
| eapProfile | WifiEapProfile | false | false | 可扩展身份验证协议配置。 |  
    
## isWifiActive    
指定设备管理应用查询wifi开启状态。  
 **调用形式：**     
    
- isWifiActive(admin: Want, callback: AsyncCallback\<boolean>): void    
起始版本： 10    
- isWifiActive(admin: Want): Promise\<boolean>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_SET_WIFI    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当接口调用成功，err为null，data为boolean值，true表示wifi开启，false表示wifi关闭，否则err为错误对象。 |  
| Promise<boolean> | Promise结果，返回wifi开启状态，true表示wifi开启，false表示wifi关闭。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 9200001 | the application is not an administrator of the device. |  
| 9200002 | the administrator application does not have permission to manage the device. |  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import Want from '@ohos.app.ability.Want';let wantTemp: Want = {  bundleName: 'com.example.myapplication',  abilityName: 'EntryAbility',};  
wifiManager.isWifiActive(wantTemp, (err, result) => {  if (err) {    console.error(`Failed to query is wifi active or not. Code: ${err.code}, message: ${err.message}`);    return;  }  console.info(`Succeeded in query is wifi active or not, result : ${result}`);});    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
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
  
    
## setWifiProfile    
指定设备管理应用为设备配置wifi，使连接到指定网络。  
 **调用形式：**     
    
- setWifiProfile(admin: Want, profile: WifiProfile, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setWifiProfile(admin: Want, profile: WifiProfile): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_SET_WIFI    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。 |  
| profile | WifiProfile | true | WLAN配置信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当接口调用成功，err为null，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。当配置wifi连接到指定网络失败时会抛出错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 9200001 | the application is not an administrator of the device. |  
| 9200002 | the administrator application does not have permission to manage the device. |  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import Want from '@ohos.app.ability.Want';let wantTemp: Want = {  bundleName: 'com.example.myapplication',  abilityName: 'EntryAbility',};let profile: wifiManager.WifiProfile = {  'ssid': 'name',  'preSharedKey': 'passwd',  'securityType': wifiManager.WifiSecurityType.WIFI_SEC_TYPE_PSK};  
wifiManager.setWifiProfile(wantTemp, profile, (err) => {  if (err) {    console.error(`Failed to set wifi profile. Code: ${err.code}, message: ${err.message}`);    return;  }  console.info('Succeeded in setting wifi profile');});    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
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
  
