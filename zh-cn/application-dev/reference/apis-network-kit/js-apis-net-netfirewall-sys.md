# @ohos.net.netFirewall (网络防火墙)(系统接口)

网络防火墙模块为应用程序提供查询防火墙能力。 通过配置防火墙策略，应用程序可以对机器进行防火墙策略管控，并提供防火墙拦截记录的查询。

> **说明：**
>
> 本模块首批接口从API version 14开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块为系统接口。

## 导入模块

```ts
import netfirewall from '@ohos.net.netFirewall';
```

## netFirewall.getInterceptedRecords

getInterceptedRecords(userId: number, requestParam: RequestParam): Promise\<InterceptedRecordPage\>

按userId获取截获的记录，需要指定分页查询参数。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_NET_FIREWALL

**系统能力**：SystemCapability.Communication.NetManager.NetFirewall

**参数：**

| 参数名       | 类型                                                     | 必填 | 说明                                         |
| ------------ | ------------------------------------------------------- | ---- | -------------------------------------------- |
| userId       | number                                                  | 是   | 系统中的多用户用户ID，只能是存在的用户ID。 |
| requestParam | [RequestParam](js-apis-net-netfirewall.md#requestparam) | 是   | 查询参数。                                   |

**返回值：**

| 类型                                                      | 说明                            |
| --------------------------------------------------------- | ------------------------------- |
| Promise\<[InterceptedRecordPage](#interceptedrecordpage)> | 以Promise形式返回拦截记录列表。 |

**错误码：**

以下错误码的详细介绍请参见通用错误码和网络连接管理错误码。
| 错误码ID | 错误信息                                                                        |
| -------  | --------------------------------------------------------------------------------|
| 201      | Permission denied.                                                              |
| 202      | Non-system applications use system APIs.                                        |
| 401      | Parameter error.                                                                |
| 2100001  | Invalid parameter value.                                                        |
| 2100002  | Operation failed. Cannot connect to service.                                    |
| 2100003  | System internal error.                                                          |
| 29400000 | The specified user does not exist.                                              |
  
**示例：**

```ts
import { netFirewall } '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let interceptRecordParam: netFirewall.RequestParam = {
  page: 1,
  pageSize: 10,
  orderField: netFirewall.NetFirewallOrderField.ORDER_BY_RECORD_TIME,
  orderType: netFirewall.NetFirewallOrderType.ORDER_DESC
};
netFirewall.getInterceptedRecords(100, interceptRecordParam).then((result: netFirewall.InterceptedRecordPage) => {
  console.info("result:", JSON.stringify(result));
}, (error: BusinessError) => {
  console.error("get intercept records failed: " + JSON.stringify(error));
});
```

## InterceptedRecord

拦截记录信息结构。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.NetFirewall

| 名称       | 类型   | 必填 | 说明                |
|------------| -------|------|-------------------- |
| time       | number | 是   | 时间戳。            |
| localIp    | string | 否   | 本地IP。            |
| remoteIp   | string | 否   | 远端IP。            |
| localPort  | number | 否   | 本地端口，默认值为0。          |
| remotePort | number | 否   | 远端端口，默认值为0。          |
| protocol   | number | 否   | 传输层协议，默认值为0。        |
| appUid     | number | 否   | 应用程序或服务UID，默认值为0。 |
| domain     | string | 否   | 域名。              |

## InterceptedRecordPage

拦截记录分页信息结构。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.NetFirewall

| 名称       | 类型                                            | 必填 | 说明       |
|------------| ----------------------------------------------- |------|----------  |
| page       | number                                          | 是   | 当前页码。 |
| pageSize   | number                                          | 是   | 页面大小。 |
| totalPage  | number                                          | 是   | 总页数。   |
| data       | Array\<[InterceptedRecord](#interceptedrecord)> | 是   | 页面数据。 |
