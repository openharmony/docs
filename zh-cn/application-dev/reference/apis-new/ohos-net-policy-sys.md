# @ohos.net.policy    
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import policy from '@ohos.net.policy'    
```  
    
## setBackgroundAllowed    
设置是否允许后台应用访问网络，使用 callback 方式作为异步方法。  
 **调用形式：**     
    
- setBackgroundAllowed(isAllowed: boolean, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setBackgroundAllowed(isAllowed: boolean): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Core  
 **需要权限：** ohos.permission.MANAGE_NET_STRATEGY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isAllowed | boolean | true | 设置是否允许后台应用访问网络，使用 callback 方式作为异步方法。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，成功时，err 为 undefined，失败返回错误码错误信息。 |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2100001 | Invalid parameter value. |  
| 2100002 | Operation failed. Cannot connect to service. |  
| 2100003 | System internal error. |  
    
 **示例代码1：**   
```ts    
import { BusinessError } from '@ohos.base';  
policy.setBackgroundAllowed(true, (error: BusinessError) => {  
  console.log(JSON.stringify(error));  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
policy.setBackgroundAllowed(true).then(() => {  
  console.log("setBackgroundAllowed success");  
}).catch((error: BusinessError) => {  
  console.log(JSON.stringify(error));  
});  
    
```    
  
    
## isBackgroundAllowed    
获取当前应用是否允许后台访问网络，使用 callback 方式作为异步方法。  
 **调用形式：**     
    
- isBackgroundAllowed(callback: AsyncCallback\<boolean>): void    
起始版本： 10    
- isBackgroundAllowed(): Promise\<boolean>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Core  
 **需要权限：** ohos.permission.MANAGE_NET_STRATEGY    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回 true 代表后台策略为允许。失败返回错误码错误信息。 |  
| Promise<boolean> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2100001 | Invalid parameter value. |  
| 2100002 | Operation failed. Cannot connect to service. |  
| 2100003 | System internal error. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
policy.isBackgroundAllowed((error: BusinessError, data: boolean) => {  
  console.log(JSON.stringify(error));  
  console.log(JSON.stringify(data));  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
policy  
  .isBackgroundAllowed()  
  .then((data: boolean) => {  
    console.log(JSON.stringify(data));  
  })  
  .catch((error: BusinessError) => {  
    console.log(JSON.stringify(error));  
  });  
    
```    
  
    
## getBackgroundPolicyByUid    
获取指定 uid 是否能访问后台网络，使用 callback 方式作为异步方法。  
 **调用形式：**     
    
- getBackgroundPolicyByUid(uid: number, callback: AsyncCallback\<NetBackgroundPolicy>): void    
起始版本： 10    
- getBackgroundPolicyByUid(uid: number): Promise\<NetBackgroundPolicy>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Core  
 **需要权限：** ohos.permission.MANAGE_NET_STRATEGY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uid | number | true | app 唯一标识符 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回获取结果。 |  
| Promise<NetBackgroundPolicy> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2100001 | Invalid parameter value. |  
| 2100002 | Operation failed. Cannot connect to service. |  
| 2100003 | System internal error. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
policy.getBackgroundPolicyByUid(11111, (error: BusinessError, data: number) => {  
  console.log(JSON.stringify(error));  
  console.log(JSON.stringify(data));  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
policy  
  .getBackgroundPolicyByUid(11111)  
  .then((data: number) => {  
    console.log(JSON.stringify(data));  
  })  
  .catch((error: BusinessError) => {  
    console.log(JSON.stringify(error));  
  });  
    
```    
  
    
## setPolicyByUid    
设置对应 uid 应用是否能够访问计量网络的策略，使用 callback 方式作为异步方法。  
 **调用形式：**     
    
- setPolicyByUid(uid: number, policy: NetUidPolicy, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setPolicyByUid(uid: number, policy: NetUidPolicy): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Core  
 **需要权限：** ohos.permission.MANAGE_NET_STRATEGY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uid | number | true | app 唯一标识符 |  
| policy | NetUidPolicy | true | 应用对应的策略 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，成功返回空，失败返回错误码错误信息。 |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2100001 | Invalid parameter value. |  
| 2100002 | Operation failed. Cannot connect to service. |  
| 2100003 | System internal error. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
policy.setPolicyByUid(11111, policy.NetUidPolicy.NET_POLICY_NONE, (error: BusinessError) => {  
  console.log(JSON.stringify(error));  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
policy  
  .setPolicyByUid(11111, policy.NetUidPolicy.NET_POLICY_NONE)  
  .then(() => {  
    console.log('setPolicyByUid success');  
  })  
  .catch((error: BusinessError) => {  
    console.log(JSON.stringify(error));  
  });  
    
```    
  
    
## getPolicyByUid    
通过应用 uid 获取对应访问网络策略，使用 callback 方式作为异步方法。  
 **调用形式：**     
    
- getPolicyByUid(uid: number, callback: AsyncCallback\<NetUidPolicy>): void    
起始版本： 10    
- getPolicyByUid(uid: number): Promise\<NetUidPolicy>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Core  
 **需要权限：** ohos.permission.MANAGE_NET_STRATEGY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uid | number | true | app 唯一标识符 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，成功返回获取策略结果，失败返回错误码错误信息。 |  
| Promise<NetUidPolicy> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2100001 | Invalid parameter value. |  
| 2100002 | Operation failed. Cannot connect to service. |  
| 2100003 | System internal error. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
policy.getPolicyByUid(11111, (error: BusinessError, data: policy.NetUidPolicy) => {  
  console.log(JSON.stringify(error));  
  console.log(JSON.stringify(data));  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
policy  
  .getPolicyByUid(11111)  
  .then((data: policy.NetUidPolicy) => {  
    console.log(JSON.stringify(data));  
  })  
  .catch((error: BusinessError) => {  
    console.log(JSON.stringify(error));  
  });  
    
```    
  
    
## getUidsByPolicy    
通过策略获取跟策略匹配的所有 uid，使用 callback 方式作为异步方法。  
 **调用形式：**     
    
- getUidsByPolicy(policy: NetUidPolicy, callback: AsyncCallback\<Array\<number>>): void    
起始版本： 10    
- getUidsByPolicy(policy: NetUidPolicy): Promise\<Array\<number>>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Core  
 **需要权限：** ohos.permission.MANAGE_NET_STRATEGY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| policy | NetUidPolicy | true | 应用对应的计量网络下的策略 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，成功返回应用的 uid 数组，失败返回错误码错误信息。 |  
| Promise<Array<number>> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2100001 | Invalid parameter value. |  
| 2100002 | Operation failed. Cannot connect to service. |  
| 2100003 | System internal error. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
policy.getUidsByPolicy(11111, (error: BusinessError, data: number[]) => {  
  console.log(JSON.stringify(error));  
  console.log(JSON.stringify(data));  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
policy  
  .getUidsByPolicy(11111)  
  .then((data: object) => {  
    console.log(JSON.stringify(data));  
  })  
  .catch((error: BusinessError) => {  
    console.log(JSON.stringify(error));  
  });  
    
```    
  
    
## isUidNetAllowed    
判断对应 uid 能否访问计量或非计量网络，使用 Promise 方式作为异步方法。  
 **调用形式：**     
    
- isUidNetAllowed(uid: number, isMetered: boolean, callback: AsyncCallback\<boolean>): void    
起始版本： 10    
- isUidNetAllowed(uid: number, isMetered: boolean): Promise\<boolean>    
起始版本： 10    
- isUidNetAllowed(uid: number, iface: string, callback: AsyncCallback\<boolean>): void    
起始版本： 10    
- isUidNetAllowed(uid: number, iface: string): Promise\<boolean>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Core  
 **需要权限：** ohos.permission.MANAGE_NET_STRATEGY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uid | number | true | app 唯一标识符 |  
| isMetered | boolean | true | 是否为计量网络 |  
| iface | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<boolean> | 以 Promise 形式返回设定结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2100001 | Invalid parameter value. |  
| 2100002 | Operation failed. Cannot connect to service. |  
| 2100003 | System internal error. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
policy.isUidNetAllowed(11111, true, (error: BusinessError, data: boolean) => {  
  console.log(JSON.stringify(error));  
  console.log(JSON.stringify(data));  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
policy  
  .isUidNetAllowed(11111, true)  
  .then((data: boolean) => {  
    console.log(JSON.stringify(data));  
  })  
  .catch((error: BusinessError) => {  
    console.log(JSON.stringify(error));  
  });  
    
```    
  
    
## setNetQuotaPolicies    
设置计量网络策略，使用 callback 方式作为异步方法。  
 **调用形式：**     
    
- setNetQuotaPolicies(quotaPolicies: Array\<NetQuotaPolicy>, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setNetQuotaPolicies(quotaPolicies: Array\<NetQuotaPolicy>): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Core  
 **需要权限：** ohos.permission.MANAGE_NET_STRATEGY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| quotaPolicies | Array<NetQuotaPolicy> | true | 计量网络策略 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，成功返回空，失败返回错误码错误信息。 |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2100001 | Invalid parameter value. |  
| 2100002 | Operation failed. Cannot connect to service. |  
| 2100003 | System internal error. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import connection from '@ohos.net.connection';  
import { BusinessError } from '@ohos.base';  
  
let netQuotaPolicyList: Array<policy.NetQuotaPolicy> = [];  
let netquotapolicy: policy.NetQuotaPolicy = {  
  networkMatchRule: {  
    netType: connection.NetBearType.BEARER_CELLULAR,  
    identity: '',  
    simId: '1'  
  },  
  quotaPolicy: {  
    periodDuration: 'M1',  
    warningBytes: 40000,  
    limitBytes: 50000,  
    metered: true,  
    limitAction: policy.LimitAction.LIMIT_ACTION_NONE  
  }  
}  
netQuotaPolicyList.push(netquotapolicy);  
  
policy.setNetQuotaPolicies(netQuotaPolicyList, (error: BusinessError) => {  
  console.log(JSON.stringify(error));  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import connection from '@ohos.net.connection';  
import { BusinessError } from '@ohos.base';  
  
let netQuotaPolicyList: Array<policy.NetQuotaPolicy> = [];  
let netquotapolicy: policy.NetQuotaPolicy = {  
  networkMatchRule: {  
    netType: connection.NetBearType.BEARER_CELLULAR,  
    identity: '',  
    simId: '1'  
  },  
  quotaPolicy: {  
    periodDuration: 'M1',  
    warningBytes: 40000,  
    limitBytes: 50000,  
    metered: true,  
    limitAction: policy.LimitAction.LIMIT_ACTION_NONE  
  }  
}  
netQuotaPolicyList.push(netquotapolicy);  
  
policy  
  .setNetQuotaPolicies(netQuotaPolicyList)  
  .then(() => {  
    console.log('setNetQuotaPolicies success');  
  })  
  .catch((error: BusinessError) => {  
    console.log(JSON.stringify(error));  
  });  
    
```    
  
    
## getNetQuotaPolicies    
获取计量网络策略，使用 callback 方式作为异步方法。  
 **调用形式：**     
    
- getNetQuotaPolicies(callback: AsyncCallback\<Array\<NetQuotaPolicy>>): void    
起始版本： 10    
- getNetQuotaPolicies(): Promise\<Array\<NetQuotaPolicy>>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Core  
 **需要权限：** ohos.permission.MANAGE_NET_STRATEGY    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回获取结果。 |  
| Promise<Array<NetQuotaPolicy>> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2100001 | Invalid parameter value. |  
| 2100002 | Operation failed. Cannot connect to service. |  
| 2100003 | System internal error. |  
    
 **示例代码1：**   
示例（callback<span style="letter-spacing: 0px;">）</span>  
```ts    
import { BusinessError } from '@ohos.base';  
policy.getNetQuotaPolicies((error: BusinessError, data: policy.NetQuotaPolicy[]) => {  
  console.log(JSON.stringify(error));  
  console.log(JSON.stringify(data));  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
policy  
  .getNetQuotaPolicies()  
  .then((data: policy.NetQuotaPolicy[]) => {  
    console.log(JSON.stringify(data));  
  })  
  .catch((error: BusinessError) => {  
    console.log(JSON.stringify(error));  
  });  
    
```    
  
    
## updateRemindPolicy    
更新提醒策略，使用 callback 方式作为异步方法。  
 **调用形式：**     
    
- updateRemindPolicy(netType: NetBearType, simId: string, remindType: RemindType, callback: AsyncCallback\<void>): void    
起始版本： 10    
- updateRemindPolicy(netType: NetBearType, simId: string, remindType: RemindType): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Core  
 **需要权限：** ohos.permission.MANAGE_NET_STRATEGY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| netType | NetBearType | true | 网络类型 |  
| simId | string | true | SIM 卡 ID |  
| remindType | RemindType | true | 提醒类型 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，成功返回空，失败返回错误码错误信息。 |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2100001 | Invalid parameter value. |  
| 2100002 | Operation failed. Cannot connect to service. |  
| 2100003 | System internal error. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import connection from '@ohos.net.connection';  
import { BusinessError } from '@ohos.base';  
policy.updateRemindPolicy(  
  connection.NetBearType.BEARER_CELLULAR,  
  '1',  
  policy.RemindType.REMIND_TYPE_WARNING,  
  (error: BusinessError) => {  
    console.log(JSON.stringify(error));  
  }  
);  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import connection from '@ohos.net.connection';  
import { BusinessError } from '@ohos.base';  
policy  
  .updateRemindPolicy(  
    connection.NetBearType.BEARER_CELLULAR,  
    '1',  
    policy.RemindType.REMIND_TYPE_WARNING  
  )  
  .then(() => {  
    console.log('updateRemindPolicy success');  
  })  
  .catch((error: BusinessError) => {  
    console.log(JSON.stringify(error));  
  });  
    
```    
  
    
## setDeviceIdleTrustlist    
设置多个 uid 是否在休眠防火墙的白名单，使用 callback 方式作为异步方法。  
 **调用形式：**     
    
- setDeviceIdleTrustlist(uids: Array\<number>, isAllowed: boolean, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setDeviceIdleTrustlist(uids: Array\<number>, isAllowed: boolean): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Core  
 **需要权限：** ohos.permission.MANAGE_NET_STRATEGY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uids | Array<number> | true | app 唯一标识符 |  
| isAllowed | boolean | true | 是否加入白名单 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，成功返回空，失败返回错误码错误信息。 |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2100001 | Invalid parameter value. |  
| 2100002 | Operation failed. Cannot connect to service. |  
| 2100003 | System internal error. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
policy.setDeviceIdleTrustlist([11111, 22222], true, (error: BusinessError) => {  
  console.log(JSON.stringify(error));  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
policy  
  .setDeviceIdleTrustlist([11111, 22222], true)  
  .then(() => {  
    console.log('setDeviceIdleTrustlist success');  
  })  
  .catch((error: BusinessError) => {  
    console.log(JSON.stringify(error));  
  });  
    
```    
  
    
## getDeviceIdleTrustlist    
获取休眠模式白名单所包含的 uid，使用 callback 方式作为异步方法。  
 **调用形式：**     
    
- getDeviceIdleTrustlist(callback: AsyncCallback\<Array\<number>>): void    
起始版本： 10    
- getDeviceIdleTrustlist(): Promise\<Array\<number>>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Core  
 **需要权限：** ohos.permission.MANAGE_NET_STRATEGY    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回获取结果。 |  
| Promise<Array<number>> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2100001 | Invalid parameter value. |  
| 2100002 | Operation failed. Cannot connect to service. |  
| 2100003 | System internal error. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
policy.getDeviceIdleTrustlist((error: BusinessError, data: number[]) => {  
  console.log(JSON.stringify(error));  
  console.log(JSON.stringify(data));  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
policy  
  .getDeviceIdleTrustlist()  
  .then((data: number[]) => {  
    console.log(JSON.stringify(data));  
  })  
  .catch((error: BusinessError) => {  
    console.log(JSON.stringify(error));  
  });  
    
```    
  
    
## setPowerSaveTrustlist    
设置指定 uid 应用是否在省电防火墙的白名单，使用 callback 方式作为异步方法。  
 **调用形式：**     
    
- setPowerSaveTrustlist(uids: Array\<number>, isAllowed: boolean, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setPowerSaveTrustlist(uids: Array\<number>, isAllowed: boolean): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Core  
 **需要权限：** ohos.permission.MANAGE_NET_STRATEGY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uids | Array<number> | true | app 唯一标识符 |  
| isAllowed | boolean | true | 是否加入白名单 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，成功返回空，失败返回错误码错误信息。 |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2100001 | Invalid parameter value. |  
| 2100002 | Operation failed. Cannot connect to service. |  
| 2100003 | System internal error. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
policy.setPowerSaveTrustlist([11111, 22222], true, (error: BusinessError) => {  
  console.log(JSON.stringify(error));  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
policy  
  .setPowerSaveTrustlist([11111, 22222], true)  
  .then(() => {  
    console.log('setPowerSaveTrustlist success');  
  })  
  .catch((error: BusinessError) => {  
    console.log(JSON.stringify(error));  
  });  
    
```    
  
    
## getPowerSaveTrustlist    
获取省电模式白名单所包含的 uid 数组，使用 callback 方式作为异步方法。  
 **调用形式：**     
    
- getPowerSaveTrustlist(callback: AsyncCallback\<Array\<number>>): void    
起始版本： 10    
- getPowerSaveTrustlist(): Promise\<Array\<number>>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Core  
 **需要权限：** ohos.permission.MANAGE_NET_STRATEGY    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回获取结果。 |  
| Promise<Array<number>> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2100001 | Invalid parameter value. |  
| 2100002 | Operation failed. Cannot connect to service. |  
| 2100003 | System internal error. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
policy.getPowerSaveTrustlist((error: BusinessError, data: number[]) => {  
  console.log(JSON.stringify(error));  
  console.log(JSON.stringify(data));  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
policy  
  .getPowerSaveTrustlist()  
  .then((data: number[]) => {  
    console.log(JSON.stringify(data));  
  })  
  .catch((error: BusinessError) => {  
    console.log(JSON.stringify(error));  
  });  
    
```    
  
    
## resetPolicies    
重置对应 sim 卡 id 的蜂窝网络、后台网络策略、防火墙策略、应用对应的策略，使用 callback 方式作为异步方法。  
 **调用形式：**     
    
- resetPolicies(simId: string, callback: AsyncCallback\<void>): void    
起始版本： 10    
- resetPolicies(simId: string): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Core  
 **需要权限：** ohos.permission.MANAGE_NET_STRATEGY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| simId | string | true | SIM 卡 ID |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，成功返回空，失败返回错误码错误信息。 |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2100001 | Invalid parameter value. |  
| 2100002 | Operation failed. Cannot connect to service. |  
| 2100003 | System internal error. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
policy.resetPolicies('1', (error: BusinessError) => {  
  console.log(JSON.stringify(error));  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
policy  
  .resetPolicies('1')  
  .then(() => {  
    console.log('resetPolicies success');  
  })  
  .catch((error: BusinessError) => {  
    console.log(JSON.stringify(error));  
  });  
    
```    
  
    
## on('netUidPolicyChange')    
注册 policy 发生改变时的回调，使用 callback 方式作为异步方法。  
 **调用形式：**     
    
- on(type: 'netUidPolicyChange', callback: Callback\<{ uid: number, policy: NetUidPolicy }>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Core  
 **需要权限：** ohos.permission.MANAGE_NET_STRATEGY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | policy 发生改变的类型 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。注册 policy 发生改变时调用。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2100001 | Invalid parameter value. |  
| 2100002 | Operation failed. Cannot connect to service. |  
| 2100003 | System internal error. |  
    
 **示例代码：**   
```ts    
import policy from '@ohos.net.policy';  
interface Data {  
  uid: number,  
  policy: policy.NetUidPolicy  
}  
policy.on('netUidPolicyChange', (data: Data) => {  
  console.log('on netUidPolicyChange: ' + JSON.stringify(data));  
});  
    
```    
  
    
## off('netUidPolicyChange')    
注销 policy 发生改变时的回调，使用 callback 方式作为异步方法。  
 **调用形式：**     
    
- off(type: 'netUidPolicyChange', callback?: Callback\<{ uid: number, policy: NetUidPolicy }>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Core  
 **需要权限：** ohos.permission.MANAGE_NET_STRATEGY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | policy 发生改变的类型 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。注册 policy 发生改变时调用。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2100001 | Invalid parameter value. |  
| 2100002 | Operation failed. Cannot connect to service. |  
| 2100003 | System internal error. |  
    
 **示例代码：**   
```ts    
let callback = (data: object) => {  
  console.log('on netUidPolicyChange, data:' + JSON.stringify(data));  
};  
policy.on('netUidPolicyChange', callback);  
policy.off('netUidPolicyChange', callback);    
```    
  
    
## on('netUidRuleChange')    
注册 rule 发生改变时的回调，使用 callback 方式作为异步方法。  
 **调用形式：**     
    
- on(type: 'netUidRuleChange', callback: Callback\<{ uid: number, rule: NetUidRule }>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Core  
 **需要权限：** ohos.permission.MANAGE_NET_STRATEGY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | rule 发生改变的类型 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。注册 rule 发生改变时的调用 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2100001 | Invalid parameter value. |  
| 2100002 | Operation failed. Cannot connect to service. |  
| 2100003 | System internal error. |  
    
 **示例代码：**   
```ts    
policy.on('netUidRuleChange', (data: object) => {  
  console.log('on netUidRuleChange: ' + JSON.stringify(data));  
});    
```    
  
    
## off('netUidRuleChange')    
注销 rule 发生改变时的回调，使用 callback 方式作为异步方法。  
 **调用形式：**     
    
- off(type: 'netUidRuleChange', callback?: Callback\<{ uid: number, rule: NetUidRule }>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Core  
 **需要权限：** ohos.permission.MANAGE_NET_STRATEGY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | rule 发生改变的类型 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。注册 rule 发生改变时的调用 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2100001 | Invalid parameter value. |  
| 2100002 | Operation failed. Cannot connect to service. |  
| 2100003 | System internal error. |  
    
 **示例代码：**   
```ts    
let callback = (data: object) => {  
  console.log('on netUidRuleChange, data:' + JSON.stringify(data));  
};  
policy.on('netUidRuleChange', callback);  
policy.off('netUidRuleChange', callback);    
```    
  
    
## on('netMeteredIfacesChange')    
注册计量 iface 发生改变时的回调，使用 callback 方式作为异步方法。  
 **调用形式：**     
    
- on(type: 'netMeteredIfacesChange', callback: Callback\<Array\<string>>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Core  
 **需要权限：** ohos.permission.MANAGE_NET_STRATEGY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 计量 iface 发生改变的类型 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。注册计量 iface 发生改变时调用。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2100001 | Invalid parameter value. |  
| 2100002 | Operation failed. Cannot connect to service. |  
| 2100003 | System internal error. |  
    
 **示例代码：**   
```ts    
policy.on('netMeteredIfacesChange', (data: string[]) => {  
  console.log('on netMeteredIfacesChange: ' + JSON.stringify(data));  
});    
```    
  
    
## off('netMeteredIfacesChange')    
注销计量 iface 发生改变时的回调，使用 callback 方式作为异步方法。  
 **调用形式：**     
    
- off(type: 'netMeteredIfacesChange', callback?: Callback\<Array\<string>>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Core  
 **需要权限：** ohos.permission.MANAGE_NET_STRATEGY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 计量 iface 发生改变的类型 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。注册计量 iface 发生改变时调用。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2100001 | Invalid parameter value. |  
| 2100002 | Operation failed. Cannot connect to service. |  
| 2100003 | System internal error. |  
    
 **示例代码：**   
```ts    
let callback = (data: string[]) => {  
  console.log('on netMeteredIfacesChange, data:' + JSON.stringify(data));  
};  
policy.on('netMeteredIfacesChange', callback);  
policy.off('netMeteredIfacesChange', callback);    
```    
  
    
## on('netQuotaPolicyChange')    
注册计量网络策略发生改变时的回调，使用 callback 方式作为异步方法。  
 **调用形式：**     
    
- on(type: 'netQuotaPolicyChange', callback: Callback\<Array\<NetQuotaPolicy>>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Core  
 **需要权限：** ohos.permission.MANAGE_NET_STRATEGY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 计量网络策略发生改变的类型 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。注册计量网络策略发生改变时调用。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2100001 | Invalid parameter value. |  
| 2100002 | Operation failed. Cannot connect to service. |  
| 2100003 | System internal error. |  
    
 **示例代码：**   
```ts    
policy.on('netQuotaPolicyChange', (data: policy.NetQuotaPolicy[]) => {  
  console.log('on netQuotaPolicyChange: ' + JSON.stringify(data));  
});    
```    
  
    
## off('netQuotaPolicyChange')    
注销计量网络策略发生改变时的回调，使用 callback 方式作为异步方法。  
 **调用形式：**     
    
- off(type: 'netQuotaPolicyChange', callback?: Callback\<Array\<NetQuotaPolicy>>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Core  
 **需要权限：** ohos.permission.MANAGE_NET_STRATEGY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 计量网络策略发生改变的类型 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。注册计量网络策略发生改变时调用。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2100001 | Invalid parameter value. |  
| 2100002 | Operation failed. Cannot connect to service. |  
| 2100003 | System internal error. |  
    
 **示例代码：**   
```ts    
policy.on('netQuotaPolicyChange', (data: Array<policy.NetQuotaPolicy>) => {  
  console.log('on netQuotaPolicyChange, data:' + JSON.stringify(data));  
});  
policy.off('netQuotaPolicyChange', (data: Array<policy.NetQuotaPolicy>) => {  
  console.log('on netQuotaPolicyChange, data:' + JSON.stringify(data));  
});    
```    
  
    
## on('netBackgroundPolicyChange')    
注册后台网络策略发生改变时的回调，使用 callback 方式作为异步方法。  
 **调用形式：**     
    
- on(type: 'netBackgroundPolicyChange', callback: Callback\<boolean>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Core  
 **需要权限：** ohos.permission.MANAGE_NET_STRATEGY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 后台网络策略发生改变的类型 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。注册后台网络策略发生改变时调用。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2100001 | Invalid parameter value. |  
| 2100002 | Operation failed. Cannot connect to service. |  
| 2100003 | System internal error. |  
    
 **示例代码：**   
```ts    
policy.on('netBackgroundPolicyChange', (data: boolean) => {  
  console.log('on netBackgroundPolicyChange: ' + JSON.stringify(data));  
});    
```    
  
    
## off('netBackgroundPolicyChange')    
注销后台网络策略发生改变时的回调，使用 callback 方式作为异步方法。  
 **调用形式：**     
    
- off(type: 'netBackgroundPolicyChange', callback?: Callback\<boolean>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Core  
 **需要权限：** ohos.permission.MANAGE_NET_STRATEGY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 后台网络策略发生改变的类型 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。注册后台网络策略发生改变时调用。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2100001 | Invalid parameter value. |  
| 2100002 | Operation failed. Cannot connect to service. |  
| 2100003 | System internal error. |  
    
 **示例代码：**   
```ts    
let callback = (data: boolean) => {  
  console.log('on netBackgroundPolicyChange, data:' + JSON.stringify(data));  
};  
policy.on('netBackgroundPolicyChange', callback);  
policy.off('netBackgroundPolicyChange', callback);    
```    
  
    
## NetBackgroundPolicy    
后台网络策略。    
    
 **系统能力:**  SystemCapability.Communication.NetManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NET_BACKGROUND_POLICY_NONE | 0 | 默认值。 |  
| NET_BACKGROUND_POLICY_ENABLE | 1 | 应用在后台可以使用计量网路。 |  
| NET_BACKGROUND_POLICY_DISABLE | 2 | 应用在后台不可以使用计量网路。 |  
| NET_BACKGROUND_POLICY_TRUSTLIST | 3 | 只有应用指定的列表在后台可以使用计量网络。 |  
    
## NetQuotaPolicy    
计量网络策略。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.NetManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| networkMatchRule | NetworkMatchRule | false | true | 网络标识，用来确定设置哪一个网络 |  
| quotaPolicy | QuotaPolicy | false | true | 具体的计量网络策略 |  
    
## QuotaPolicy    
计量网络策略  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.NetManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| periodDuration | string | false | true | 流量限制计量周期。D1，M1，Y1 分别代表 1 天，1 个月，1 年内流量限制，超出时间则不受限制。 |  
| warningBytes | number | false | true | 发出警告的流量阈值。 |  
| limitBytes | number | false | true | 流量设置的配额。 |  
| metered | boolean | false | true | 是否为计量网络。 |  
| limitAction | LimitAction | false | true | 到达流量限制后的动作。 |  
| lastWarningRemind | number | false | false | 最新一次发出警告的时间。 |  
| lastLimitRemind | number | false | false | 最新一次配额耗尽的时间 |  
    
## NetworkMatchRule    
网络标识，用来确定设置哪一个网络  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.NetManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| netType | NetBearType | false | true | 网络类型。 |  
| identity | string | false | true | 计量蜂窝网络中配合 simId 联合使用。以太网，wifi 网络单独使用。用于标记类型。 |  
| simId | string | false | true | 计量蜂窝网络的 SIM 卡的标识值。以太网，wifi 网络不会用到 |  
    
## LimitAction    
限制动作。    
    
 **系统能力:**  SystemCapability.Communication.NetManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| LIMIT_ACTION_NONE | -1 | 默认值。 |  
| LIMIT_ACTION_ACCESS_DISABLED | 0 | 当配额策略达到限制时，访问被禁用。 |  
| LIMIT_ACTION_ALERT_ONLY | 1 | 当配额策略达到限制时，将警告用户。 |  
    
## NetUidRule    
计量网络规则。    
    
 **系统能力:**  SystemCapability.Communication.NetManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NET_RULE_NONE | 0 | 默认规则 |  
| NET_RULE_ALLOW_METERED_FOREGROUND | 1 << 0 | 允许前台访问计量网络 |  
| NET_RULE_ALLOW_METERED | 1 << 1 | 允许访问计量网络 |  
| NET_RULE_REJECT_METERED | 1 << 2 | 拒绝访问计量网络 |  
| NET_RULE_ALLOW_ALL | 1 << 5 | 允许访问所有网络 |  
| NET_RULE_REJECT_ALL | 1 << 6 | 拒绝访问所有网络 |  
    
## RemindType    
提醒类型。    
    
 **系统能力:**  SystemCapability.Communication.NetManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| REMIND_TYPE_WARNING | 1 | 警告提醒 |  
| REMIND_TYPE_LIMIT | 2 | 限制提醒 |  
    
## NetUidPolicy    
应用对应的网络策略。    
    
 **系统能力:**  SystemCapability.Communication.NetManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NET_POLICY_NONE | 0 | 默认网络策略 |  
| NET_POLICY_ALLOW_METERED_BACKGROUND | 1 << 0 | 允许应用在后台访问计量网络 |  
| NET_POLICY_REJECT_METERED_BACKGROUND | 1 << 1 | 拒绝应用在后台访问计量网络。 |  
