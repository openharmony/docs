# @ohos.net.netFirewall (Network Firewall) (System API)

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

The **netFirewall** module implements the firewall query functionality. It allows applications to query firewall interception records.

> **NOTE**
>
> The initial APIs of this module are supported since API version 14. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import netfirewall from '@ohos.net.netFirewall';
```

## netFirewall.getInterceptedRecords

getInterceptedRecords(userId: number, requestParam: RequestParam): Promise\<InterceptedRecordPage\>

Obtains interception records based on the specified user ID. You need to specify the pagination query parameter when calling this API. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_NET_FIREWALL

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

**Parameters**

| Name      | Type                                                    | Mandatory| Description                                        |
| ------------ | ------------------------------------------------------- | ---- | -------------------------------------------- |
| userId       | number                                                  | Yes  | Existing user ID.|
| requestParam | [RequestParam](js-apis-net-netfirewall.md#requestparam) | Yes  | Query parameter.                                  |

**Return value**

| Type                                                     | Description                           |
| --------------------------------------------------------- | ------------------------------- |
| Promise\<[InterceptedRecordPage](#interceptedrecordpage)> | Promise used to return the result, which is a list of interception records.|

**Error codes**

For details about the error codes, see [Network Connection Management Error Codes](errorcode-net-connection.md) and [Universal Error Codes](../errorcode-universal.md).
| ID| Error Message                                                                       |
| -------  | --------------------------------------------------------------------------------|
| 201      | Permission denied.                                                              |
| 202      | Non-system applications use system APIs.                                        |
| 401      | Parameter error.                                                                |
| 2100001  | Invalid parameter value.                                                        |
| 2100002  | Operation failed. Cannot connect to service.                                    |
| 2100003  | System internal error.                                                          |
| 29400000 | The specified user does not exist.                                              |
  
**Example**

```ts
import { netFirewall } from '@kit.NetworkKit';
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

Defines an interception record.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Name      | Type  | Read-only|Optional| Description               |
|------------| -------|------|---|-------------------- |
| time       | number | No  |No| Timestamp.           |
| localIp    | string | No  |Yes|Local IP address.           |
| remoteIp   | string | No  |Yes| Remote IP address.           |
| localPort  | number | No  |Yes|Local port. The default value is **0**.         |
| remotePort | number | No  | Yes|Remote port. The default value is **0**.         |
| protocol   | number | No  |Yes|Transport layer protocol. The default value is **0**.       |
| appUid     | number | No  |Yes|Application or service UID. The default value is **0**.|
| domain     | string | No  | Yes|Domain name.             |

## InterceptedRecordPage

Defines the pagination structure for interception records.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Name      | Type                                           | Read-only|Optional| Description      |
|------------| ----------------------------------------------- |------|---|----------  |
| page       | number                                          | No  |No|Current page.|
| pageSize   | number                                          |   No |No|Page size.|
| totalPage  | number                                          |  No  | No|Total number of pages.  |
| data       | Array\<[InterceptedRecord](#interceptedrecord)> |  No  |No|Page data.|
