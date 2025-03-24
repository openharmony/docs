# @ohos.net.netFirewall (Network Firewall) (System API)

The **netFirewall** module implements the firewall query functionality. It allows applications to query firewall interception records of the device.

> **NOTE**
>
> The initial APIs of this module are supported since API version 14. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import netfirewall from '@ohos.net.netFirewall';
```

## netFirewall.getInterceptedRecords

getInterceptedRecords(userId: number, requestParam: RequestParam): Promise<\InterceptedRecordPage>

Obtains interception records based on the specified user ID. You need to specify the pagination query parameter when calling this API.

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

Defines an interception record.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Name      | Type  | Mandatory| Description               |
|------------| -------|------|-------------------- |
| time       | number | Yes  | Timestamp.           |
| localIp    | string | No  | Local IP address.           |
| remoteIp   | string | No  | Remote IP address.           |
| localPort  | number | No  | Local port.         |
| remotePort | number | No  | Remote port.         |
| protocol   | number | No  | Transport layer protocol.       |
| appUid     | number | No  | Application or service UID.|
| domain     | string | No  | Domain name.             |

## InterceptedRecordPage

Defines the pagination structure for interception records.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Name      | Type                                           | Mandatory| Description      |
|------------| ----------------------------------------------- |------|----------  |
| page       | number                                          | Yes  | Current page.|
| pageSize   | number                                          | Yes  | Page size.|
| totalPage  | number                                          | Yes  | Total number of pages.  |
| data       | Array\<[InterceptedRecord](#interceptedrecord)> | Yes  | Page data.|
