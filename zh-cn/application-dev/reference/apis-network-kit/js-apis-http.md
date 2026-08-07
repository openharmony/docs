# @ohos.net.http (数据请求)

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

本模块提供HTTP数据请求能力。应用可以通过HTTP发起一个数据请求，支持常见的GET、POST、OPTIONS、HEAD、PUT、DELETE、PATCH、TRACE、CONNECT方法。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
## 导入模块

```ts
import { http } from '@kit.NetworkKit';
```

## 完整示例 

>**说明：** 
>
>在本文档的示例中，通过this.context来获取UIAbilityContext，其中this代表继承自UIAbility的UIAbility实例。如需在页面中使用UIAbilityContext提供的能力，请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

<!--code_no_check-->
```ts
// 引入包名
import { http, connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

let context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;
// 每一个httpRequest对应一个HTTP请求任务，不可复用。
let httpRequest = http.createHttp();
// 用于订阅HTTP响应头，此接口会比request请求先返回。可以根据业务需要订阅此消息。
// 从API 8开始，使用on('headersReceive', Callback)替代on('headerReceive', AsyncCallback)。 8+
httpRequest.on('headersReceive', (header: Object) => {
  console.info('header: ' + JSON.stringify(header));
});

httpRequest.request(// 填写HTTP请求的URL地址，可以带参数也可以不带参数。URL地址需要开发者自定义。
  "EXAMPLE_URL",
  {
    method: http.RequestMethod.POST, // 可选，默认为http.RequestMethod.GET。
    // 推荐使用body字段传递请求体内容，具体格式与服务端协商确定。
    body: 'data to send', // 自API 26开始支持。
    // 推荐使用queryParams字段传递URL参数。可传string或对象。
    queryParams: { scene: 'demo', tag: ['a', 'b'] }, // 自API 26开始支持。
    expectDataType: http.HttpDataType.STRING, // 可选，指定返回数据的类型。
    usingCache: true, // 可选，默认为true。
    priority: 1, // 可选，默认为1。
    // 开发者根据自身业务需要添加header字段，且header字段不支持传入map对象。
    header: { 'Accept' : 'application/json' },
    readTimeout: 60000, // 可选，默认为60000ms。
    connectTimeout: 60000, // 可选，默认为60000ms。
    usingProtocol: http.HttpProtocol.HTTP1_1, // 可选，协议类型默认值由系统自动指定。
    usingProxy: false, // 可选，默认使用系统代理，设置为false不使用代理，自API 10开始支持该属性。
    caPath: '/path/to/cacert.pem', // 可选，默认使用系统预设CA证书，自API 10开始支持该属性。
    caData: '-----BEGIN CERTIFICATE-----\n' +
        'MIIDaTCCAlGgAwIBAgIICN287lmB2cMwDQYJKoZIhvcNAQELBQAwgYoxCzAJBgNV\n' +
        'BAYTAkNOMRMwEQYDVQQDDApleGFtcGxlLmNuMRAwDgYDVQQKDAdDb21wYW55MREw\n' +
        'DwYDVQQLDAhEaXZpc2lvbjEOMAwGA1UECAwFQW5IdWkxDjAMBgNVBAcMBUhlRmVp\n' +
        'MSEwHwYJKoZIhvcNAQkBFhJleGFtcGxlQGV4YW1wbGUuY24wHhcNMjUwNDEzMDAy\n' +
        'MjQxWhcNMjgwNDEzMDAyMjQxWjBeMQswCQYDVQQGEwJDTjESMBAGA1UEAwwJMTI3\n' +
        'LjAuMC4xMQkwBwYDVQQKDAAxCTAHBgNVBAsMADEJMAcGA1UECAwAMQkwBwYDVQQH\n' +
        'DAAxDzANBgkqhkiG9w0BCQEWADCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoC\n' +
        'ggEBANN/JrQC8dy7sxUk+TDJlGlq4h8lajdqSASkFbWVBadU4eMCbRrKejXuFX/n\n' +
        'Yu4J3wkgni0NKRejdWu/M+LLibQEIF9RUGNR/OgdlR4AKr8ZxmG44+7Ps2aiDcOy\n' +
        'Z95UcxYj59ctfFk63cacbBi19aq200spjl/H0jTVsQ2/JvwMVEH62WbyjIJ3KXgq\n' +
        'yyjf75rKbR9CdVdGk+OoR4S4c6nY5cTZP6T7iCupYR6MpKEtIR2bbams/N5GxQEh\n' +
        '9+7YxswTQn4EkVhi+UOFZolYLhtIdoLThmStN+WiSL5VDvchAkTUmwUBTGV21WnH\n' +
        'qo6J1t7XtwUpAZF6OuWl85R8D50CAwEAATANBgkqhkiG9w0BAQsFAAOCAQEAqjKq\n' +
        'gwR+4B6bwdAOZ6k0cutLqxvVgBaktX28omuYtoiYagM0zfB8/8WijXL8jT1VLEFx\n' +
        'wPaojwegqYWANfQkPd7A6rjsabgOH7oYBCDoCH52cjzGlJunC0BL6w5g3z6MCOB4\n' +
        'Ciz8rnYMvYqQJiMqrO7Po9onoFBHiRQGO4Wva3O8ErEmd2dKvXb3vN02P3T7CtwM\n' +
        'Z6D0rtZbzdsSOQfGcX08WFIfvfpz6tdU/X/6VqKrt5oiaNQH7ded6gJ3C6RM/Q/x\n' +
        'I2j/hSKy0yU7FoCFSOnlhxbm3TlbIvtjZKQ9ymK4x7iE0VKqExUAA6Z8qsIUBUt4\n' +
        'aqNDeZWXFBqrSujLJA==\n' +
        '-----END CERTIFICATE-----', // 可选，默认使用系统预设CA证书，自API 20开始支持该属性。
    clientCert: { // 可选，默认不使用客户端证书，自API 11开始支持该属性。
      certPath: '/path/to/client.pem', // 默认不使用客户端证书，自API 11开始支持该属性。
      keyPath: '/path/to/client.key', // 若证书包含Key信息，传入空字符串，自API 11开始支持该属性。
      certType: http.CertType.PEM, // 可选，默认使用PEM，自API 11开始支持该属性。
      keyPassword: "passwordToKey" // 可选，输入key文件的密码，自API 11开始支持该属性。
    },
    certificatePinning: [ // 可选，支持证书锁定配置信息的动态设置，自API 12开始支持该属性。
      {
        publicKeyHash: 'Pin1', // 由应用传入的证书PIN码，自API 12开始支持该属性。
        hashAlgorithm: 'SHA-256' // 加密算法，当前仅支持SHA-256，自API 12开始支持该属性。
      }, {
        publicKeyHash: 'Pin2', // 由应用传入的证书PIN码，自API 12开始支持该属性。
        hashAlgorithm: 'SHA-256' // 加密算法，当前仅支持SHA-256，自API 12开始支持该属性。
      }
    ],
    multiFormDataList: [ // 可选，仅当Header中，'content-Type'为'multipart/form-data'时生效，自API 11开始支持该属性。
      {
        name: "Part1", // 数据名，自API 11开始支持该属性。
        contentType: 'text/plain', // 数据类型，自API 11开始支持该属性。
        data: 'Example data', // 可选，数据内容，自API 11开始支持该属性。
        remoteFileName: 'example.txt' // 可选，自API 11开始支持该属性。
      }, {
        name: "Part2", // 数据名，自API 11开始支持该属性。
        contentType: 'text/plain', // 数据类型，自API 11开始支持该属性。
        // data/app/el2/100/base/com.example.myapplication/haps/entry/files/fileName.txt
        filePath: `${context.filesDir}/fileName.txt`, // 可选，传入文件路径，自API 11开始支持该属性。
        remoteFileName: 'fileName.txt' // 可选，自API 11开始支持该属性。
      }
    ],
    addressFamily: http.AddressFamily.DEFAULT, // 可选，系统默认选择目标域名的IPv4地址或IPv6地址，自API 15开始支持该属性。
    customMethod: 'GET', // 可选，自API 23开始支持该属性。
    maxRedirects: 30, // 可选，默认值是30次，自API 23开始支持该属性。
    sniHostName: "www.example.com", // 可选，自API 23开始支持该属性。
    reuseConnections: true, // 可选，默认为true，自API 26.0.0开始支持该属性。
    inactivityMs: 0, // 可选，默认为0表示不限制，自API 26.0.0开始支持该属性。
    usingSocks5Proxy: { // 可选，默认不使用SOCKS5代理，自API 26.0.0开始支持该属性。如果指定了此属性，usingProxy属性不生效。
      host: 'host', // SOCKS5代理服务器主机名，自API 26.0.0开始支持该属性。
      port: 1080, // SOCKS5代理服务器端口，自API 26.0.0开始支持该属性。
      username: 'username', // 可选，SOCKS5代理认证用户名，自API 26.0.0开始支持该属性。
      password: 'password', // 可选，SOCKS5代理认证密码，自API 26.0.0开始支持该属性。
      dnsStrategy: connection.Socks5DnsStrategy.SYSTEM_MODE, // 可选，指定DNS解析由系统执行还是由SOCKS5代理服务器执行，默认由系统执行，自API 26.0.0开始支持该属性。
      exclusionList: [ 'www.example.com' ] // 可选，指定哪些域名不使用SOCKS5代理，自API 26.0.0开始支持该属性。
    }
  },
  (err: BusinessError, data: http.HttpResponse) => {
    if (!err) {
      // data.result为HTTP响应内容，可根据业务需要进行解析。
      console.info('Result:' + JSON.stringify(data.result));
      console.info('code:' + JSON.stringify(data.responseCode));
      console.info('type:' + JSON.stringify(data.resultType));
      // data.header为HTTP响应头，可根据业务需要进行解析。
      console.info('header:' + JSON.stringify(data.header));
      console.info('cookies:' + JSON.stringify(data.cookies)); // 自API version 8开始支持cookie。
      // 自API version 24开始支持获取http交互信息。
      console.info('connectionExtraInfo:' + JSON.stringify(data.connectionExtraInfo));
      // 取消订阅HTTP响应头事件。
      httpRequest.off('headersReceive');
      // 当该请求使用完毕时，开发者务必调用destroy方法释放资源，避免出现内存泄漏。
      httpRequest.destroy();
    } else {
      console.error('error:' + JSON.stringify(err));
      // 取消订阅HTTP响应头事件。
      httpRequest.off('headersReceive');
      // 当该请求使用完毕时，开发者务必调用destroy方法释放资源，避免出现内存泄漏。
      httpRequest.destroy();
    }
  });
```

> **说明：**
> console.info()输出的数据中包含换行符会将换行符渲染为换行进行显示。
>
> 自API 12开始支持接收经过brotli算法压缩的HTTP响应。

## http.createHttp

createHttp(): HttpRequest

创建一个HTTP请求，里面包括发起请求、中断请求、订阅/取消订阅HTTP Response Header事件。当发起多个HTTP请求时，需为每个HTTP请求创建对应HttpRequest对象。每一个HttpRequest对象对应一个HTTP请求。

> **说明：**
> 当该请求使用完毕时，需调用destroy方法释放资源，否则会出现内存泄露问题。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型        | 说明                                                         |
| :---------- | :----------------------------------------------------------- |
| HttpRequest | 返回一个HttpRequest对象，里面包括request、requestInStream、requestSync、enableAutoCookie、destroy、on和off方法。 |

**示例：**

```ts
import { http } from '@kit.NetworkKit';

let httpRequest = http.createHttp();
```

## HttpRequest

HTTP请求任务。在调用HttpRequest的方法前，需要先通过[createHttp()](#httpcreatehttp)创建一个任务。

### request

request(url: string, callback: AsyncCallback\<HttpResponse\>): void

根据URL地址，发起HTTP网络请求，使用callback方式作为异步方法。

> **说明：**
>
>(1) 此接口仅支持接收5MB以内的数据，如果需要接收超过5MB的数据，则需主动在[HttpRequestOptions](#httprequestoptions)的maxLimit中进行设置，或者使用[requestInStream](#requestinstream10)接口发起流式请求。自API version 23开始，本接口支持的最大接收数据量为50MB，API version 23之前仍为5MB，超过5MB会接收失败。<br>
>(2) 如需传入cookies，请开发者自行在参数options中添加。<br>
>(3) 若URL包含中文或其他语言，需先调用encodeURL(URL)编码，再发起请求。

**需要权限**：ohos.permission.INTERNET

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                           | 必填 | 说明                    |
| -------- | ---------------------------------------------- | ---- | ---------------------- |
| url      | string                                         | 是   | 发起网络请求的URL地址。示例：https://www.test.com |
| callback | AsyncCallback\<[HttpResponse](#httpresponse)\> | 是   | 回调函数。    |

**错误码：**

以下错误码的详细介绍参见[通用错误码](../errorcode-universal.md)和[HTTP错误码](errorcode-net-http.md)。<br>
HTTP错误码映射关系：2300000 + curl错误码。更多常用错误码可参考：[curl错误码](https://curl.se/libcurl/c/libcurl-errors.html)

| 错误码ID   | 错误信息                                                         |
|---------|----------------------------------------------------------------|
| 401     | Parameter error.                                               |
| 201     | Permission denied.                                             |
| 2300001 | Unsupported protocol.                                          |
| 2300003 | Invalid URL format or missing URL.                             |
| 2300005 | Failed to resolve the proxy name.                              |
| 2300006 | Failed to resolve the host name.                               |
| 2300007 | Failed to connect to the server.                               |
| 2300008 | Invalid server response.                                       |
| 2300009 | Access to the remote resource denied.                          |
| 2300016 | Error in the HTTP2 framing layer.                              |
| 2300018 | Transferred a partial file.                                    |
| 2300023 | Failed to write the received data to the disk or application.  |
| 2300025 | Upload failed.                                                 |
| 2300026 | Failed to open or read local data from the file or application.|
| 2300027 | Out of memory.                                                 |
| 2300028 | Operation timeout.                                             |
| 2300047 | The number of redirections reaches the maximum allowed.        |
| 2300052 | The server returned nothing (no header or data).               |
| 2300055 | Failed to send data to the peer.                               |
| 2300056 | Failed to receive data from the peer.                          |
| 2300058 | Local SSL certificate error.                                   |
| 2300059 | The specified SSL cipher cannot be used.                       |
| 2300060 | Invalid SSL peer certificate or SSH remote key.                |
| 2300061 | Invalid HTTP encoding format.                                  |
| 2300063 | Maximum file size exceeded.                                    |
| 2300070 | Remote disk full.                                              |
| 2300073 | Remote file already exists.                                    |
| 2300077 | The SSL CA certificate does not exist or is inaccessible.      |
| 2300078 | Remote file not found.                                         |
| 2300094 | Authentication error.                                          |
| 2300996 | The request was intercepted by the HTTP global interceptor. <br>适用版本：26.0.0+ |
| 2300997 | Cleartext traffic not permitted. <br>适用版本：18+              |
| 2300998 | It is not allowed to access this domain. <br>适用版本：12+      |
| 2300999 | Internal error.                                                 |


**示例：**

```ts
import { http } from '@kit.NetworkKit';

let httpRequest = http.createHttp();
httpRequest.request("EXAMPLE_URL", (err: Error, data: http.HttpResponse) => {
  if (!err) {
    console.info('Result:' + data.result);
    console.info('code:' + data.responseCode);
    console.info('type:' + JSON.stringify(data.resultType));
    console.info('header:' + JSON.stringify(data.header));
    console.info('cookies:' + data.cookies); // 自API version 8开始支持cookie。
  } else {
    console.error('error:' + JSON.stringify(err));
  }
});
```

### request

request(url: string, options: HttpRequestOptions, callback: AsyncCallback\<HttpResponse\>):void

根据URL地址和相关配置项，发起HTTP网络请求，使用callback方式作为异步方法。

> **说明：**
>
>(1) 此接口仅支持接收5MB以内的数据，如果需要接收超过5MB的数据，则需主动在[HttpRequestOptions](#httprequestoptions)的maxLimit中进行设置，或者使用[requestInStream](#requestinstream10)接口发起流式请求。自API version 23开始，本接口支持的最大接收数据量为50MB，API version 23之前仍为5MB，超过5MB会接收失败。<br>
>(2) 如需传入cookies，请开发者自行在参数options中添加。<br>
>(3) 若URL包含中文或其他语言，需先调用encodeURL(URL)编码，再发起请求。

**需要权限**：ohos.permission.INTERNET

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                           | 必填 | 说明                                            |
| -------- | ---------------------------------------------- | ---- | ----------------------------------------------- |
| url      | string                                         | 是   | 发起网络请求的URL地址。                         |
| options  | HttpRequestOptions                             | 是   | 参考[HttpRequestOptions](#httprequestoptions)。 |
| callback | AsyncCallback\<[HttpResponse](#httpresponse)\> | 是   | 回调函数。当请求成功时，回调内容是[HttpResponse](#httpresponse) ，请求失败时为undefined。                        |

**错误码：**

以下错误码的详细介绍参见[通用错误码](../errorcode-universal.md)和[HTTP错误码](errorcode-net-http.md)。<br>
HTTP错误码映射关系：2300000 + curl错误码。更多常用错误码可参考：[curl错误码](https://curl.se/libcurl/c/libcurl-errors.html)

| 错误码ID   | 错误信息                                                         |
|---------|----------------------------------------------------------------|
| 401     | Parameter error.                                               |
| 201     | Permission denied.                                             |
| 2300001 | Unsupported protocol.                                          |
| 2300003 | Invalid URL format or missing URL.                             |
| 2300005 | Failed to resolve the proxy name.                              |
| 2300006 | Failed to resolve the host name.                               |
| 2300007 | Failed to connect to the server.                               |
| 2300008 | Invalid server response.                                       |
| 2300009 | Access to the remote resource denied.                          |
| 2300016 | Error in the HTTP2 framing layer.                              |
| 2300018 | Transferred a partial file.                                    |
| 2300023 | Failed to write the received data to the disk or application.  |
| 2300025 | Upload failed.                                                 |
| 2300026 | Failed to open or read local data from the file or application.|
| 2300027 | Out of memory.                                                 |
| 2300028 | Operation timeout.                                             |
| 2300047 | The number of redirections reaches the maximum allowed.        |
| 2300052 | The server returned nothing (no header or data).               |
| 2300055 | Failed to send data to the peer.                               |
| 2300056 | Failed to receive data from the peer.                          |
| 2300058 | Local SSL certificate error.                                   |
| 2300059 | The specified SSL cipher cannot be used.                       |
| 2300060 | Invalid SSL peer certificate or SSH remote key.                |
| 2300061 | Invalid HTTP encoding format.                                  |
| 2300063 | Maximum file size exceeded.                                    |
| 2300070 | Remote disk full.                                              |
| 2300073 | Remote file already exists.                                    |
| 2300077 | The SSL CA certificate does not exist or is inaccessible.      |
| 2300078 | Remote file not found.                                         |
| 2300094 | Authentication error.                                          |
| 2300996 | The request was intercepted by the HTTP global interceptor. <br>适用版本：26.0.0+ |
| 2300997 | Cleartext traffic not permitted. <br>适用版本：18+              |
| 2300998 | It is not allowed to access this domain. <br>适用版本：12+      |
| 2300999 | Internal error.                                                 |

**示例：**

```ts
import { http } from '@kit.NetworkKit';

class Header {
  public contentType: string;

  constructor(contentType: string) {
    this.contentType = contentType;
  }
}

let httpRequest = http.createHttp();
let options: http.HttpRequestOptions = {
    method: http.RequestMethod.POST, // 可选，默认为http.RequestMethod.GET。
  // 推荐使用body字段传递请求体内容，具体格式与服务端协商确定。
  body: 'data to send', // 自API 26开始支持。
  // 推荐使用queryParams字段传递URL参数。可传string或对象。
  queryParams: { scene: 'request-demo', page: 1 }, // 自API 26开始支持。
    expectDataType: http.HttpDataType.STRING, // 可选，指定返回数据的类型。
    usingCache: true, // 可选，默认为true。
    priority: 1, // 可选，默认为1。
    // 开发者根据自身业务需要添加header字段。
    header: new Header('application/json'),
    readTimeout: 60000, // 可选，默认为60000ms。
    connectTimeout: 60000, // 可选，默认为60000ms。
    usingProtocol: http.HttpProtocol.HTTP1_1, // 可选，协议类型默认值由系统自动指定。
    usingProxy: false, // 可选，默认使用系统代理，设置为false不使用代理，自API 10开始支持该属性。
};

httpRequest.request("EXAMPLE_URL", options, (err: Error, data: http.HttpResponse) => {
  if (!err) {
    console.info('Result:' + data.result);
    console.info('code:' + data.responseCode);
    console.info('type:' + JSON.stringify(data.resultType));
    console.info('header:' + JSON.stringify(data.header));
    console.info('cookies:' + data.cookies); // 自API version 8开始支持cookie。
  } else {
    console.error('error:' + JSON.stringify(err));
  }
});
```

### request

request(url: string, options? : HttpRequestOptions): Promise\<HttpResponse\>

根据URL地址，发起HTTP网络请求，使用Promise方式作为异步方法。

> **说明：**
>
>(1) 此接口仅支持接收5MB以内的数据，如果需要接收超过5MB的数据，则需主动在[HttpRequestOptions](#httprequestoptions)的maxLimit中进行设置，或者使用[requestInStream](#requestinstream10)接口发起流式请求。自API version 23开始，本接口支持的最大接收数据量为50MB，API version 23之前仍为5MB，超过5MB会接收失败。<br>
>(2) 如需传入cookies，请开发者自行在参数options中添加。<br>
>(3) 若URL包含中文或其他语言，需先调用encodeURL(URL)编码，再发起请求。

**需要权限**：ohos.permission.INTERNET

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名  | 类型               | 必填 | 说明                                            |
| ------- | ------------------ | ---- | ----------------------------------------------- |
| url     | string             | 是   | 发起网络请求的URL地址。                         |
| options | HttpRequestOptions | 否   | 参考[HttpRequestOptions](#httprequestoptions)。 |

**返回值：**

| 类型                                   | 说明                              |
| :------------------------------------- | :-------------------------------- |
| Promise<[HttpResponse](#httpresponse)> | Promise对象，返回请求的响应结果。 |

**错误码：**

以下错误码的详细介绍参见[通用错误码](../errorcode-universal.md)和[HTTP错误码](errorcode-net-http.md)。<br>
HTTP错误码映射关系：2300000 + curl错误码。更多常用错误码可参考：[curl错误码](https://curl.se/libcurl/c/libcurl-errors.html)

| 错误码ID   | 错误信息                                                         |
|---------|----------------------------------------------------------------|
| 401     | Parameter error.                                               |
| 201     | Permission denied.                                             |
| 2300001 | Unsupported protocol.                                          |
| 2300003 | Invalid URL format or missing URL.                             |
| 2300005 | Failed to resolve the proxy name.                              |
| 2300006 | Failed to resolve the host name.                               |
| 2300007 | Failed to connect to the server.                               |
| 2300008 | Invalid server response.                                       |
| 2300009 | Access to the remote resource denied.                          |
| 2300016 | Error in the HTTP2 framing layer.                              |
| 2300018 | Transferred a partial file.                                    |
| 2300023 | Failed to write the received data to the disk or application.  |
| 2300025 | Upload failed.                                                 |
| 2300026 | Failed to open or read local data from the file or application.|
| 2300027 | Out of memory.                                                 |
| 2300028 | Operation timeout.                                             |
| 2300047 | The number of redirections reaches the maximum allowed.        |
| 2300052 | The server returned nothing (no header or data).               |
| 2300055 | Failed to send data to the peer.                               |
| 2300056 | Failed to receive data from the peer.                          |
| 2300058 | Local SSL certificate error.                                   |
| 2300059 | The specified SSL cipher cannot be used.                       |
| 2300060 | Invalid SSL peer certificate or SSH remote key.                |
| 2300061 | Invalid HTTP encoding format.                                  |
| 2300063 | Maximum file size exceeded.                                    |
| 2300070 | Remote disk full.                                              |
| 2300073 | Remote file already exists.                                    |
| 2300077 | The SSL CA certificate does not exist or is inaccessible.      |
| 2300078 | Remote file not found.                                         |
| 2300094 | Authentication error.                                          |
| 2300996 | The request was intercepted by the HTTP global interceptor. <br>适用版本：26.0.0+ |
| 2300997 | Cleartext traffic not permitted. <br>适用版本：18+              |
| 2300998 | It is not allowed to access this domain. <br>适用版本：12+      |
| 2300999 | Internal error.                                                 |

**示例：**

```ts
import { http } from '@kit.NetworkKit';

class Header {
  public contentType: string;

  constructor(contentType: string) {
    this.contentType = contentType;
  }
}

let httpRequest = http.createHttp();
let promise = httpRequest.request("EXAMPLE_URL", {
  method: http.RequestMethod.GET,
  connectTimeout: 60000,
  readTimeout: 60000,
  header: new Header('application/json')
});
promise.then((data:http.HttpResponse) => {
  console.info('Result:' + data.result);
  console.info('code:' + data.responseCode);
  console.info('type:' + JSON.stringify(data.resultType));
  console.info('header:' + JSON.stringify(data.header));
  console.info('cookies:' + data.cookies); // 自API version 8开始支持cookie。
  console.info('header.content-Type:' + data.header);
  console.info('header.Status-Line:' + data.header);
}).catch((err:Error) => {
  console.error('error:' + JSON.stringify(err));
});
```

### destroy

destroy(): void

终止HTTP请求任务，同时释放系统资源。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**示例：**

```ts
import { http } from '@kit.NetworkKit';
let httpRequest = http.createHttp();

httpRequest.destroy();
```

### requestInStream<sup>10+</sup>

requestInStream(url: string, callback: AsyncCallback\<number\>): void

根据URL地址，发起HTTP网络请求并返回流式响应，使用callback方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                           | 必填 | 说明                                            |
| -------- | ---------------------------------------------- | ---- | ----------------------------------------------- |
| url      | string                                         | 是   | 发起网络请求的URL地址。                         |
| callback | AsyncCallback\<number\>       | 是   | 回调函数。当请求成功，err为undefined，返回HTTP请求响应错误码，具体含义见[ResponseCode](#responsecode)；否则为错误对象。                                      |

**错误码：**

以下错误码的详细介绍参见[通用错误码](../errorcode-universal.md)和[HTTP错误码](errorcode-net-http.md)。<br>
HTTP错误码映射关系：2300000 + curl错误码。更多常用错误码可参考：[curl错误码](https://curl.se/libcurl/c/libcurl-errors.html)

| 错误码ID   | 错误信息                                                         |
|---------|----------------------------------------------------------------|
| 401     | Parameter error.                                               |
| 201     | Permission denied.                                             |
| 2300001 | Unsupported protocol.                                          |
| 2300003 | Invalid URL format or missing URL.                             |
| 2300005 | Failed to resolve the proxy name.                              |
| 2300006 | Failed to resolve the host name.                               |
| 2300007 | Failed to connect to the server.                               |
| 2300008 | Invalid server response.                                       |
| 2300009 | Access to the remote resource denied.                          |
| 2300016 | Error in the HTTP2 framing layer.                              |
| 2300018 | Transferred a partial file.                                    |
| 2300023 | Failed to write the received data to the disk or application.  |
| 2300025 | Upload failed.                                                 |
| 2300026 | Failed to open or read local data from the file or application.|
| 2300027 | Out of memory.                                                 |
| 2300028 | Operation timeout.                                             |
| 2300047 | The number of redirections reaches the maximum allowed.        |
| 2300052 | The server returned nothing (no header or data).               |
| 2300055 | Failed to send data to the peer.                               |
| 2300056 | Failed to receive data from the peer.                          |
| 2300058 | Local SSL certificate error.                                   |
| 2300059 | The specified SSL cipher cannot be used.                       |
| 2300060 | Invalid SSL peer certificate or SSH remote key.                |
| 2300061 | Invalid HTTP encoding format.                                  |
| 2300063 | Maximum file size exceeded.                                    |
| 2300070 | Remote disk full.                                              |
| 2300073 | Remote file already exists.                                    |
| 2300077 | The SSL CA certificate does not exist or is inaccessible.      |
| 2300078 | Remote file not found.                                         |
| 2300094 | Authentication error.                                          |
| 2300996 | The request was intercepted by the HTTP global interceptor. <br>适用版本：26.0.0+ |
| 2300997 | Cleartext traffic not permitted. <br>适用版本：18+              |
| 2300998 | It is not allowed to access this domain. <br>适用版本：12+      |
| 2300999 | Unknown error.                                                |

**示例：**

```ts
import { http } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let httpRequest = http.createHttp();
httpRequest.requestInStream("EXAMPLE_URL", (err: BusinessError, data: number) => {
  if (!err) {
    console.info("requestInStream OK! ResponseCode is " + JSON.stringify(data));
  } else {
    console.error("requestInStream ERROR : err = " + JSON.stringify(err));
  }
})
```

### requestInStream<sup>10+</sup>

requestInStream(url: string, options: HttpRequestOptions, callback: AsyncCallback\<number\>): void

根据URL地址和相关配置项，发起HTTP网络请求并返回流式响应，使用callback方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                           | 必填 | 说明                                            |
| -------- | ---------------------------------------------- | ---- | ----------------------------------------------- |
| url      | string                                         | 是   | 发起网络请求的URL地址。                         |
| options  | HttpRequestOptions                             | 是   | 参考[HttpRequestOptions](#httprequestoptions)。 |
| callback | AsyncCallback\<number\>       | 是   | 回调函数。当请求成功，err为undefined，返回HTTP请求响应错误码，具体含义见[ResponseCode](#responsecode)；否则为错误对象。                                    |

**错误码：**

以下错误码的详细介绍参见[通用错误码](../errorcode-universal.md)和[HTTP错误码](errorcode-net-http.md)。<br>
HTTP错误码映射关系：2300000 + curl错误码。更多常用错误码可参考：[curl错误码](https://curl.se/libcurl/c/libcurl-errors.html)

| 错误码ID   | 错误信息                                                         |
|---------|----------------------------------------------------------------|
| 401     | Parameter error.                                               |
| 201     | Permission denied.                                             |
| 2300001 | Unsupported protocol.                                          |
| 2300003 | Invalid URL format or missing URL.                             |
| 2300005 | Failed to resolve the proxy name.                              |
| 2300006 | Failed to resolve the host name.                               |
| 2300007 | Failed to connect to the server.                               |
| 2300008 | Invalid server response.                                       |
| 2300009 | Access to the remote resource denied.                          |
| 2300016 | Error in the HTTP2 framing layer.                              |
| 2300018 | Transferred a partial file.                                    |
| 2300023 | Failed to write the received data to the disk or application.  |
| 2300025 | Upload failed.                                                 |
| 2300026 | Failed to open or read local data from the file or application.|
| 2300027 | Out of memory.                                                 |
| 2300028 | Operation timeout.                                             |
| 2300047 | The number of redirections reaches the maximum allowed.        |
| 2300052 | The server returned nothing (no header or data).               |
| 2300055 | Failed to send data to the peer.                               |
| 2300056 | Failed to receive data from the peer.                          |
| 2300058 | Local SSL certificate error.                                   |
| 2300059 | The specified SSL cipher cannot be used.                       |
| 2300060 | Invalid SSL peer certificate or SSH remote key.                |
| 2300061 | Invalid HTTP encoding format.                                  |
| 2300063 | Maximum file size exceeded.                                    |
| 2300070 | Remote disk full.                                              |
| 2300073 | Remote file already exists.                                    |
| 2300077 | The SSL CA certificate does not exist or is inaccessible.      |
| 2300078 | Remote file not found.                                         |
| 2300094 | Authentication error.                                          |
| 2300996 | The request was intercepted by the HTTP global interceptor. <br>适用版本：26.0.0+ |
| 2300997 | Cleartext traffic not permitted. <br>适用版本：18+              |
| 2300998 | It is not allowed to access this domain. <br>适用版本：12+      |
| 2300999 | Unknown error.                                                |

**示例：**

```ts
import { http } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

class Header {
  public contentType: string;

  constructor(contentType: string) {
    this.contentType = contentType;
  }
}

let httpRequest = http.createHttp();
let options: http.HttpRequestOptions = {
    method: http.RequestMethod.POST, // 可选，默认为http.RequestMethod.GET。
    // 当使用POST请求时此字段用于传递请求体内容，具体格式与服务端协商确定。
    extraData: 'data to send', // 自API version 26开始，推荐使用body字段传递请求体内容，具体格式与服务端协商确定。
    expectDataType: http.HttpDataType.STRING, // 可选，指定返回数据的类型。
    usingCache: true, // 可选，默认为true。
    priority: 1, // 可选，默认为1。
    // 开发者根据自身业务需要添加header字段。
    header: new Header('application/json'),
    readTimeout: 60000, // 可选，默认为60000ms。
    connectTimeout: 60000, // 可选，默认为60000ms。
    usingProtocol: http.HttpProtocol.HTTP1_1, // 可选，协议类型默认值由系统自动指定。
    usingProxy: false, // 可选，默认使用系统代理，设置为false不使用代理，自API 10开始支持该属性。
};
httpRequest.requestInStream("EXAMPLE_URL", options, (err: BusinessError<void> , data: number) => {
  if (!err) {
    console.info("requestInStream OK! ResponseCode is " + JSON.stringify(data));
  } else {
    console.error("requestInStream ERROR : err = " + JSON.stringify(err));
  }
})
```

### requestInStream<sup>10+</sup>

requestInStream(url: string, options? : HttpRequestOptions): Promise\<number\>

根据URL地址，发起HTTP网络请求并返回流式响应，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名  | 类型               | 必填 | 说明                                            |
| ------- | ------------------ | ---- | ----------------------------------------------- |
| url     | string             | 是   | 发起网络请求的URL地址。                         |
| options | HttpRequestOptions | 否   | 参考[HttpRequestOptions](#httprequestoptions)。 |

**返回值：**

| 类型                                   | 说明                              |
| :------------------------------------- | :-------------------------------- |
| Promise\<number\> | 以Promise形式返回发起请求的结果，具体含义见[ResponseCode](#responsecode)。 |

**错误码：**

以下错误码的详细介绍参见[通用错误码](../errorcode-universal.md)和[HTTP错误码](errorcode-net-http.md)。<br>
HTTP错误码映射关系：2300000 + curl错误码。更多常用错误码可参考：[curl错误码](https://curl.se/libcurl/c/libcurl-errors.html)

| 错误码ID   | 错误信息                                                         |
|---------|----------------------------------------------------------------|
| 401     | Parameter error.                                               |
| 201     | Permission denied.                                             |
| 2300001 | Unsupported protocol.                                          |
| 2300003 | Invalid URL format or missing URL.                             |
| 2300005 | Failed to resolve the proxy name.                              |
| 2300006 | Failed to resolve the host name.                               |
| 2300007 | Failed to connect to the server.                               |
| 2300008 | Invalid server response.                                       |
| 2300009 | Access to the remote resource denied.                          |
| 2300016 | Error in the HTTP2 framing layer.                              |
| 2300018 | Transferred a partial file.                                    |
| 2300023 | Failed to write the received data to the disk or application.  |
| 2300025 | Upload failed.                                                 |
| 2300026 | Failed to open or read local data from the file or application.|
| 2300027 | Out of memory.                                                 |
| 2300028 | Operation timeout.                                             |
| 2300047 | The number of redirections reaches the maximum allowed.        |
| 2300052 | The server returned nothing (no header or data).               |
| 2300055 | Failed to send data to the peer.                               |
| 2300056 | Failed to receive data from the peer.                          |
| 2300058 | Local SSL certificate error.                                   |
| 2300059 | The specified SSL cipher cannot be used.                       |
| 2300060 | Invalid SSL peer certificate or SSH remote key.                |
| 2300061 | Invalid HTTP encoding format.                                  |
| 2300063 | Maximum file size exceeded.                                    |
| 2300070 | Remote disk full.                                              |
| 2300073 | Remote file already exists.                                    |
| 2300077 | The SSL CA certificate does not exist or is inaccessible.      |
| 2300078 | Remote file not found.                                         |
| 2300094 | Authentication error.                                          |
| 2300996 | The request was intercepted by the HTTP global interceptor. <br>适用版本：26.0.0+ |
| 2300997 | Cleartext traffic not permitted. <br>适用版本：18+              |
| 2300998 | It is not allowed to access this domain. <br>适用版本：12+      |
| 2300999 | Unknown error.                                                |

**示例：**

```ts
import { http } from '@kit.NetworkKit';

class Header {
  public contentType: string;

  constructor(contentType: string) {
    this.contentType = contentType;
  }
}

let httpRequest = http.createHttp();
let promise = httpRequest.requestInStream("EXAMPLE_URL", {
  method: http.RequestMethod.GET,
  connectTimeout: 60000,
  readTimeout: 60000,
  header: new Header('application/json')
});
promise.then((data: number) => {
  console.info("requestInStream OK!" + data);
}).catch((err: Error) => {
  console.error("requestInStream ERROR : err = " + JSON.stringify(err));
});
```

### requestSync

requestSync(url: string, options?: HttpRequestOptions): HttpResponse

根据URL地址、相关配置项（可选），发起HTTP网络请求，同步返回响应结果。

> **说明：**
>
 >(1) 此接口仅支持接收50MB以内的数据，如果需要接收超过50MB的数据，则需主动在[HttpRequestOptions](#httprequestoptions)的maxLimit中进行设置。<br>
 >(2) 如需传入cookies，请开发者自行在参数options中添加。<br>
 >(3) 若URL包含中文或其他语言，需先调用encodeURL(URL)编码，再发起请求。<br>
 >(4) 此接口为同步接口，会阻塞当前线程直到返回HTTP请求响应结果或错误码。
 
 **起始版本：** 26.0.0

**需要权限：** ohos.permission.INTERNET

**系统能力：** SystemCapability.Communication.NetStack

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名  | 类型               | 必填 | 说明                                            |
| ------- | ------------------ | ---- | ----------------------------------------------- |
| url     | string             | 是   | 发起网络请求的URL地址。                         |
| options | HttpRequestOptions | 否   | 参考[HttpRequestOptions](#httprequestoptions)。 |

**返回值：**

| 类型                                   | 说明                              |
| -------------------------------------- | --------------------------------- |
| [HttpResponse](#httpresponse) | 同步返回HTTP请求响应结果。 |

**错误码：**

以下错误码的详细介绍参见[通用错误码](../errorcode-universal.md)和[HTTP错误码](errorcode-net-http.md)。<br>
HTTP错误码映射关系：2300000 + curl错误码。更多常用错误码可参考：[curl错误码](https://curl.se/libcurl/c/libcurl-errors.html)。

| 错误码ID   | 错误信息                                                         |
|---------|----------------------------------------------------------------|
| 201     | Permission denied.                                             |
| 2300001 | Unsupported protocol.                                          |
| 2300003 | Invalid URL format or missing URL.                             |
| 2300005 | Failed to resolve the proxy name.                              |
| 2300006 | Failed to resolve the host name.                               |
| 2300007 | Failed to connect to the server.                               |
| 2300008 | Invalid server response.                                       |
| 2300009 | Access to the remote resource denied.                          |
| 2300016 | Error in the HTTP2 framing layer.                              |
| 2300018 | Transferred a partial file.                                    |
| 2300023 | Failed to write the received data to the disk or application.  |
| 2300025 | Upload failed.                                                 |
| 2300026 | Failed to open or read local data from the file or application.|
| 2300027 | Out of memory.                                                 |
| 2300028 | Operation timeout.                                             |
| 2300047 | The number of redirections reaches the maximum allowed.        |
| 2300052 | The server returned nothing (no header or data).               |
| 2300055 | Failed to send data to the peer.                               |
| 2300056 | Failed to receive data from the peer.                          |
| 2300058 | Local SSL certificate error.                                   |
| 2300059 | The specified SSL cipher cannot be used.                       |
| 2300060 | Invalid SSL peer certificate or SSH remote key.                |
| 2300061 | Invalid HTTP encoding format.                                  |
| 2300063 | Maximum file size exceeded.                                    |
| 2300070 | Remote disk full.                                              |
| 2300073 | Remote file already exists.                                    |
| 2300077 | The SSL CA certificate does not exist or is inaccessible.      |
| 2300078 | Remote file not found.                                         |
| 2300094 | Authentication error.                                          |
| 2300996 | The request was intercepted by the HTTP global interceptor.    |
| 2300997 | Cleartext traffic not permitted.                               |
| 2300998 | It is not allowed to access this domain.                       |
| 2300999 | Internal error.                                                 |

**示例：**

```ts
import { http } from '@kit.NetworkKit';

class Header {
  public contentType: string;

  constructor(contentType: string) {
    this.contentType = contentType;
  }
}

let httpRequest = http.createHttp();
let options: http.HttpRequestOptions = {
    method: http.RequestMethod.POST, // 可选，默认为http.RequestMethod.GET。
    // 当使用POST请求时此字段用于传递请求体内容，具体格式与服务端协商确定。
    extraData: 'data to send',
    expectDataType: http.HttpDataType.STRING, // 可选，指定返回数据的类型。
    usingCache: true, // 可选，默认为true。
    priority: 1, // 可选，默认为1。
    // 开发者根据自身业务需要添加header字段。
    header: new Header('application/json'),
    readTimeout: 60000, // 可选，默认为60000ms。
    connectTimeout: 60000, // 可选，默认为60000ms。
    usingProtocol: http.HttpProtocol.HTTP1_1, // 可选，协议类型默认值由系统自动指定。
    usingProxy: false, // 可选，默认使用系统代理，设置为false不使用代理，自API 10开始支持该属性。
};
let url = "EXAMPLE_URL"; // 访问url
try {
  let data: http.HttpResponse = httpRequest.requestSync(url, options);
  console.info('Result:' + data.result);
  console.info('code:' + data.responseCode);
  console.info('type:' + JSON.stringify(data.resultType));
  console.info('header:' + JSON.stringify(data.header));
  console.info('cookies:' + data.cookies); // 自API version 8开始支持cookie。
} catch (err) {
  console.error('error:' + JSON.stringify(err));
}
httpRequest.destroy();
```

### enableAutoCookie

enableAutoCookie(enable: boolean): void

设置是否自动携带和共享Cookie，用于在同一个HttpRequest实例的多次请求之间自动复用服务端下发的Cookie。

> **说明：**
>
> (1) 默认值为false，表示默认不自动携带Cookie。<br>
> (2) 当配置由false切换为true后，会在后续调用request接口发起请求时生效，并自动共享Cookie。<br>
> (3) 当配置由true切换为false时，会清空当前实例内保存的Cookie共享状态。<br>
> (4) 关于重定向场景的Cookie处理：通过header字段手动配置的Cookie在发生重定向时不会自动发送给重定向后的目标主机，仅服务端通过Set-Cookie下发的Cookie会根据域名规则自动携带。<br>
> (5) 关于跨域Cookie携带规则：Cookie的自动携带仅在相同域名或相同子域名之间生效，不同域名之间不支持Cookie的自动携带。

**起始版本：** 26.0.0

**系统能力：** SystemCapability.Communication.NetStack

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------- | ------- | ---- | ----------------------------------------------- |
| enable | boolean | 是 | 是否自动携带Cookie。true表示开启，false表示关闭。 |

**示例：**

```ts
import { http } from '@kit.NetworkKit';

let httpRequest = http.createHttp();
let url = "EXAMPLE_URL"; // 访问url，需要开发者根据实际场景自行定义。

// 开启自动Cookie共享。
httpRequest.enableAutoCookie(true);

httpRequest.request(url, {
  method: http.RequestMethod.GET
}).then((data: http.HttpResponse) => {
  console.info('first request code:' + data.responseCode);
  // 后续请求将自动复用该实例保存的Cookie。
  return httpRequest.request(url, { method: http.RequestMethod.GET });
}).then((data: http.HttpResponse) => {
  console.info('second request code:' + data.responseCode);
}).catch((err: Error) => {
  console.error('error:' + JSON.stringify(err));
}).finally(() => {
  httpRequest.destroy();
});
```

### on("headerReceive")<sup>(deprecated)</sup>

on(type: "headerReceive", callback: AsyncCallback\<Object\>): void

订阅HTTP Response Header 事件。

> **说明：**
> 从API version 6开始支持，从API version 8开始废弃，建议使用[on("headersReceive")](#onheadersreceive8)替代。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                    | 必填 | 说明                              |
| -------- | ----------------------- | ---- | --------------------------------- |
| type     | string                  | 是   | 订阅的事件类型，'headerReceive'。 |
| callback | AsyncCallback\<Object\> | 是   | 回调函数。当订阅成功，error为undefined，data为获取到HTTP响应头；否则为错误对象。 |

**示例：**

```ts
import { http } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let httpRequest = http.createHttp();
httpRequest.on("headerReceive", (data: BusinessError) => {
  console.error("error:" + JSON.stringify(data));
});
```

### off("headerReceive")<sup>(deprecated)</sup>

off(type: "headerReceive", callback?: AsyncCallback\<Object\>): void

取消订阅HTTP Response Header事件。

> **说明：**
>
> 从API version 6开始支持，从API version 8开始废弃，建议使用[off("headersReceive")](#offheadersreceive8)替代。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                  |
| -------- | ----------------------- | ---- | ------------------------------------- |
| type     | string                  | 是   | 取消订阅的事件类型，'headerReceive'。 |
| callback | AsyncCallback\<Object\> | 否   | 回调函数。可以指定传入on中的callback取消对应的订阅，也可以不指定callback清空所有订阅。                           |

**示例：**

```ts
import { http } from '@kit.NetworkKit';

let httpRequest = http.createHttp();
httpRequest.off("headerReceive");
```

### on("headersReceive")<sup>8+</sup>

on(type: "headersReceive", callback: Callback\<Object\>): void

订阅HTTP Response Header 事件。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型               | 必填 | 说明                        |
| -------- | ------------------ | ---- |---------------------------|
| type     | string             | 是   | 订阅的事件类型：'headersReceive'。 |
| callback | Callback\<Object\> | 是   | 回调函数，返回HTTP响应头对象。         |

**示例：**

```ts
import { http } from '@kit.NetworkKit';

let httpRequest = http.createHttp();
httpRequest.on("headersReceive", (header: Object) => {
  console.info("header: " + JSON.stringify(header));
});
httpRequest.off("headersReceive");
```

### off("headersReceive")<sup>8+</sup>

off(type: "headersReceive", callback?: Callback\<Object\>): void

取消订阅HTTP Response Header 事件。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型               | 必填 | 说明                                   |
| -------- | ------------------ | ---- | -------------------------------------- |
| type     | string             | 是   | 取消订阅的事件类型：'headersReceive'。 |
| callback | Callback\<Object\> | 否   | 回调函数。可以指定传入on中的callback取消对应的订阅，也可以不指定callback清空所有订阅。                             |

**示例：**

```ts
import { http } from '@kit.NetworkKit';

let httpRequest = http.createHttp();
httpRequest.on("headersReceive", (header: Object) => {
  console.info("header: " + JSON.stringify(header));
});
httpRequest.off("headersReceive");
```

### once("headersReceive")<sup>8+</sup>

once(type: "headersReceive", callback: Callback\<Object\>): void

订阅HTTP Response Header 事件，只能触发一次。触发之后，订阅器就会被移除。使用callback方式作为异步方法。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型               | 必填 | 说明                               |
| -------- | ------------------ | ---- | ---------------------------------- |
| type     | string             | 是   | 订阅事件，固定为'headersReceive'。headersReceive：响应头接收事件。 |
| callback | Callback\<Object\> | 是   | 回调函数。返回HTTP响应头对象。                         |

**示例：**

```ts
import { http } from '@kit.NetworkKit';

let httpRequest = http.createHttp();
httpRequest.once("headersReceive", (header: Object) => {
  console.info("header: " + JSON.stringify(header));
});
```

### on("dataReceive")<sup>10+</sup>

on(type: "dataReceive", callback: Callback\<ArrayBuffer\>): void

订阅HTTP流式响应数据接收事件。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                    | 必填 | 说明                              |
| -------- | ----------------------- | ---- | --------------------------------- |
| type     | string                  | 是   | 订阅的事件类型，'dataReceive'。 |
| callback | Callback\<ArrayBuffer\> | 是   | 回调函数。当订阅成功时，err为undefined，data为获取到的HTTP流式数据接收数据，类型为ArrayBuffer；否则为错误对象。 |

**示例：**

```ts
import { http } from '@kit.NetworkKit';

let httpRequest = http.createHttp();
httpRequest.on("dataReceive", (data: ArrayBuffer) => {
  console.info("dataReceive length: " + JSON.stringify(data.byteLength));
});
httpRequest.off("dataReceive");
```

### off("dataReceive")<sup>10+</sup>

off(type: "dataReceive", callback?: Callback\<ArrayBuffer\>): void

取消订阅HTTP流式响应数据接收事件。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型               | 必填 | 说明                                   |
| -------- | ------------------ | ---- | -------------------------------------- |
| type     | string             | 是   | 取消订阅的事件类型：'dataReceive'。 |
| callback | Callback\<ArrayBuffer\> | 否   | 回调函数。可以指定传入on中的callback取消对应的订阅，也可以不指定callback清空所有订阅。                             |

**示例：**

```ts
import { http } from '@kit.NetworkKit';

let httpRequest = http.createHttp();
httpRequest.on("dataReceive", (data: ArrayBuffer) => {
  console.info("dataReceive length: " + JSON.stringify(data.byteLength));
});
httpRequest.off("dataReceive");
```

### on("dataEnd")<sup>10+</sup>

on(type: "dataEnd", callback: Callback\<void\>): void

订阅HTTP流式响应数据接收完毕事件。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                    | 必填 | 说明                              |
| -------- | ----------------------- | ---- | --------------------------------- |
| type     | string                  | 是   | 订阅的事件类型，'dataEnd'。 |
| callback | Callback\<void\>   | 是   | 回调函数。当订阅成功时，err为undefined，否则为错误对象。                        |

**示例：**

```ts
import { http } from '@kit.NetworkKit';

let httpRequest = http.createHttp();
httpRequest.on("dataEnd", () => {
  console.info("Receive dataEnd !");
});
httpRequest.off("dataEnd");
```

### off("dataEnd")<sup>10+</sup>

off(type: "dataEnd", callback?: Callback\<void\>): void

取消订阅HTTP流式响应数据接收完毕事件。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型               | 必填 | 说明                                   |
| -------- | ------------------ | ---- | -------------------------------------- |
| type     | string             | 是   | 取消订阅的事件类型：'dataEnd'。 |
| callback | Callback\<void\>   | 否   | 回调函数。可以指定传入on中的callback取消对应的订阅，也可以不指定callback清空所有订阅。                             |

**示例：**

```ts
import { http } from '@kit.NetworkKit';

let httpRequest = http.createHttp();
httpRequest.on("dataEnd", () => {
  console.info("Receive dataEnd !");
});
httpRequest.off("dataEnd");
```

### on('dataReceiveProgress')<sup>10+</sup>

on(type: 'dataReceiveProgress', callback: Callback\<DataReceiveProgressInfo\>): void

订阅HTTP流式响应数据接收进度事件。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                    | 必填 | 说明                              |
| -------- | ----------------------- | ---- | --------------------------------- |
| type     | string                  | 是   | 订阅的事件类型，'dataReceiveProgress'。 |
| callback | Callback\<[DataReceiveProgressInfo](#datareceiveprogressinfo11)\>   | 是   | 回调函数。当订阅成功时，回调内容是[DataReceiveProgressInfo](#datareceiveprogressinfo11)，订阅失败时为undefined。 |

**示例：**

```ts
import { http } from '@kit.NetworkKit';

let httpRequest = http.createHttp();
httpRequest.on("dataReceiveProgress", (data: http.DataReceiveProgressInfo) => {
  console.info("dataReceiveProgress:" + JSON.stringify(data));
});
httpRequest.off("dataReceiveProgress");
```

### off('dataReceiveProgress')<sup>10+</sup>

off(type: 'dataReceiveProgress', callback?: Callback\<DataReceiveProgressInfo\>): void

取消订阅HTTP流式响应数据接收进度事件。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型               | 必填 | 说明                                   |
| -------- | ------------------ | ---- | -------------------------------------- |
| type     | string             | 是   | 取消订阅的事件类型：'dataReceiveProgress'。 |
| callback | Callback\<[DataReceiveProgressInfo](#datareceiveprogressinfo11)\>   | 否   | 回调函数。 可以指定传入on中的callback取消对应的订阅，也可以不指定callback清空所有订阅。    |

**示例：**

```ts
import { http } from '@kit.NetworkKit';

let httpRequest = http.createHttp();
httpRequest.on("dataReceiveProgress", (data: http.DataReceiveProgressInfo) => {
  console.info("dataReceiveProgress:" + JSON.stringify(data));
});
httpRequest.off("dataReceiveProgress");
```

### on('dataSendProgress')<sup>11+</sup>

on(type: 'dataSendProgress', callback: Callback\<DataSendProgressInfo\>): void

订阅HTTP网络请求数据发送进度事件。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                    | 必填 | 说明                              |
| -------- | ----------------------- | ---- | --------------------------------- |
| type     | string                  | 是   | 订阅的事件类型，'dataSendProgress'。 |
| callback | Callback\<[DataSendProgressInfo](#datasendprogressinfo11)\>   | 是   | 回调函数。当订阅成功时，回调内容是[DataSendProgressInfo](#datasendprogressinfo11)，订阅失败时为undefined。|

**示例：**

```ts
import { http } from '@kit.NetworkKit';

let httpRequest = http.createHttp();
httpRequest.on("dataSendProgress", (data: http.DataSendProgressInfo) => {
  console.info("dataSendProgress:" + JSON.stringify(data));
});
httpRequest.off("dataSendProgress");
```

### off('dataSendProgress')<sup>11+</sup>

off(type: 'dataSendProgress', callback?: Callback\<DataSendProgressInfo\>): void

取消订阅HTTP网络请求数据发送进度事件。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型               | 必填 | 说明                                   |
| -------- | ------------------ | ---- | -------------------------------------- |
| type     | string             | 是   | 取消订阅的事件类型：'dataSendProgress'。 |
| callback | Callback\<[DataSendProgressInfo](#datasendprogressinfo11)\>  | 否 | 回调函数。可以指定传入on中的callback取消对应的订阅，也可以不指定callback清空所有订阅。 |

**示例：**

```ts
import { http } from '@kit.NetworkKit';

let httpRequest = http.createHttp();
httpRequest.on("dataSendProgress", (data: http.DataSendProgressInfo) => {
  console.info("dataSendProgress:" + JSON.stringify(data));
});
httpRequest.off("dataSendProgress");
```

## HttpRequestOptions

发起HTTP请求时，可选配置信息。

**系统能力**：SystemCapability.Communication.NetStack

<!--Table: 12%; 14%; 8%; 8%; 58%-->
| 名称         | 类型                                          | 只读 | 可选 | 说明                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
| -------------- | --------------------------------------------- | ---- |----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| method         | [RequestMethod](#requestmethod)               | 否  | 是  | 请求方式，默认为GET。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
| extraData      | string \| Object \| ArrayBuffer | 否  | 是  | 发送请求的额外数据，默认无此字段。自API version 26开始，建议优先使用body和queryParams字段。<br />**说明：** 没有额外数据时，避免添加该参数；若必须添加，请填写undefined或者null，避免直接传入"。<br />1. 当HTTP请求为POST、PUT、DELETE等方法时，此字段为HTTP请求的content，以UTF-8编码形式作为请求体。<br />示例如下：<br />  (1) 当'content-Type'为'application/x-www-form-urlencoded'时，请求提交的信息主体数据必须在key和value进行URL转码后（encodeURIComponent/encodeURI），按照键值对"key1=value1&key2=value2&key3=value3"的方式进行编码，该字段对应的类型通常为String。<br />(2) 当'content-Type'为'text/xml'时，该字段对应的类型通常为String。<br />(3) 当'content-Type'为'application/json'时，该字段对应的类型通常为Object。<br />(4) 当'content-Type'为'application/octet-stream'时，该字段对应的类型通常为ArrayBuffer。<br />(5) 当'content-Type'为'multipart/form-data'且需上传的字段为文件时，该字段对应的类型通常为ArrayBuffer。<br>以上信息仅供参考，并可能根据具体情况有所不同。<br />2. 当HTTP请求为GET、OPTIONS、TRACE、CONNECT等方法时，此字段为HTTP请求参数的补充。开发者需传入Encode编码后的string类型参数，Object类型的参数无需预编码，参数内容会拼接到URL中进行发送。ArrayBuffer类型的参数不会做拼接处理。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| body | string \| Object \| ArrayBuffer | 否 | 是 | HTTP请求体内容。设置该字段后，框架会优先将该字段作为请求体发送。<br/>- 支持string、Object、ArrayBuffer三种类型：string按原值发送，Object会序列化后发送，ArrayBuffer按二进制发送。<br/>- 当body与extraData同时配置时，body优先，extraData会被忽略。<br/>- 可与任意请求方法搭配使用，用于显式指定请求体。<br/>**起始版本：** 26.0.0<br/>**模型约束：** 此接口仅可在Stage模型下使用。 |
| queryParams | string \| [QueryParamObject](#queryparamobject) | 否 | 是 | 附加到URL中的请求参数。<br/>- 支持string和QueryParamObject两种形式：string会按原样拼接到URL（不重复编码）；QueryParamObject会由系统自动编码并序列化。<br/>- 使用string时不需要携带前导`?`，多个参数用`&`分隔。<br/>- 当queryParams与extraData同时配置时，queryParams优先，extraData中的URL参数补充逻辑会被忽略。<br/>**起始版本：** 26.0.0<br/>**模型约束：** 此接口仅可在Stage模型下使用。 |
| expectDataType<sup>9+</sup>  | [HttpDataType](#httpdatatype9)  | 否  | 是  | 指定返回数据的类型，默认无此字段。如果设置了此参数，系统将优先返回指定的类型。当指定其类型为Object时，最大长度为65536字符数。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| usingCache<sup>9+</sup>      | boolean                         | 否  | 是  | 是否使用缓存，true表示请求时优先读取缓存，false表示不使用缓存；默认为true，请求时优先读取缓存。缓存跟随当前进程生效，新缓存会替换旧缓存。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |
| priority<sup>9+</sup>        | number                          | 否  | 是  | HTTP/HTTPS请求并发优先级，值越大优先级越高，范围[1,1000]，默认为1，超出范围将设置为默认值。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |
| header                       | Object                          | 否  | 是  | HTTP请求头字段。当请求方式为"POST" "PUT" "DELETE" 或者""时，默认{'content-Type': 'application/json'}， 否则默认{'content-Type': 'application/x-www-form-urlencoded'}。<br />如果header中包含number类型的字段，最大支持int64的整数。<br />header字段支持JSON格式如 [完整示例](js-apis-http.md#完整示例) 和Record<string, string>格式输入。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| readTimeout                  | number                          | 否  | 是  | 读取超时时间。单位为毫秒（ms），默认为60000ms。传入值需为uint32_t范围内的整数。<br />设置为0表示不会出现超时情况。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| connectTimeout               | number                          | 否  | 是  | 连接超时时间。单位为毫秒（ms），默认为60000ms。传入值需为uint32_t范围内的整数。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
| usingProtocol<sup>9+</sup>   | [HttpProtocol](#httpprotocol9)  | 否  | 是  | HTTP请求使用的协议版本。未指定时，由系统自动协商最适合的协议版本。若指定HTTP3，由于HTTP3协议的安全限制，需通过[TlsConfig](js-apis-http.md#tlsconfig18)指定TLS 版本为1.3，且目标域名支持HTTP3协议，才能启用HTTP3，否则将协商降级。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| usingProxy<sup>10+</sup>     | boolean \| [HttpProxy](js-apis-net-connection.md#httpproxy10)               | 否  | 是  | HTTP代理配置，该项不配置时默认使用系统代理。<br />- 当usingProxy为布尔类型true时，使用默认网络代理，为false时，不使用代理。<br />- 当usingProxy为HttpProxy类型时，使用指定网络代理。从API version 22开始，HttpProxy支持指定username和password字段。<br>- 从API version 26.0.0开始，当usingSocks5Proxy被正确配置时，usingProxy项不生效。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| caPath<sup>10+</sup>     | string               | 否  | 是  | 如果设置了此参数且证书有效，系统将使用用户指定的CA证书和系统预设的CA证书；否则仅使用系统预设的CA证书。CA证书路径为沙箱映射路径（开发者可通过[UIAbilityContext](../apis-ability-kit/js-apis-app-ability-common.md#uiabilitycontext)提供的能力获取应用沙箱路径）。目前仅支持后缀名为.pem的文本格式证书。<br> 系统预设CA证书位置：/etc/ssl/certs/cacert.pem。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
| caData<sup>20+</sup>     | string               | 否  | 是  | 如果设置了此参数且证书有效，系统将使用用户指定的CA证书和系统预设的CA证书；否则仅使用系统预设的CA证书。如果同时设置了caPath和caData，caData将被系统忽略。目前仅支持传入.pem格式的证书内容，最大长度为8000字节。仅支持传入单证书，不支持证书链传入。<br />系统预设CA证书位置：/etc/ssl/certs/cacert.pem。证书路径为沙箱映射路径（开发者可通过UIAbilityContext提供的能力获取应用沙箱路径）。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。|
| resumeFrom<sup>11+</sup> | number | 否 | 是 | 用于设置下载起始位置，该参数只能用于GET方法，不能用于其他。HTTP标准（RFC 7233第3.1节）允许服务器忽略范围请求。<br />- 使用HTTP PUT时，不能使用该选项，因为该选项可能与其他选项冲突。<br />- 取值范围是：[1，4294967296（4GB）]，超出范围则不生效。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| resumeTo<sup>11+</sup> | number | 否 | 是 | 用于设置下载结束位置，该参数只能用于GET方法，不能用于其他。HTTP标准（RFC 7233第3.1节）允许服务器忽略范围请求。<br />- 使用HTTP PUT时，不能使用该选项，因为该选项可能与其他选项冲突。<br />- 取值范围是：[1，4294967296（4GB）]，超出范围则不生效。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| clientCert<sup>11+</sup> | [ClientCert](#clientcert11) | 否 | 是 | 支持传输客户端证书。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| dnsOverHttps<sup>11+</sup> | string | 否 | 是 | 设置使用HTTPS协议的服务器进行DNS解析。<br />- 参数必须根据以下格式进行URL编码："https:// host:port/path"。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| dnsServers<sup>11+</sup> | Array\<string\> | 否 | 是 | 设置指定的DNS服务器进行DNS解析。<br />- 最多可以设置3个DNS解析服务器。如果有3个以上，只取前3个。<br />- 服务器必须是IPV4或者IPV6地址。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| maxLimit<sup>11+</sup>   | number   | 否 | 是 | 响应消息的最大字节限制。<br />默认值为5\*1024\*1024，以Byte为单位。最大值为100\*1024\*1024，以Byte为单位。<br />                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
| multiFormDataList<sup>11+</sup> | Array<[MultiFormData](#multiformdata11)> | 否 | 是 | 当'content-Type'为'multipart/form-data'时，则上传该字段定义的数据字段表单列表。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| certificatePinning<sup>12+</sup> | [CertificatePinning](#certificatepinning12) \| CertificatePinning[] | 否 | 是 | 支持动态设置证书锁定配置，可以传入单个或多个证书PIN码。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |
| addressFamily<sup>15+</sup> | [AddressFamily](#addressfamily15) | 否 | 是 | 支持解析目标域名时限定地址类型。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |
| remoteValidation<sup>18+</sup> | [RemoteValidation](#remotevalidation18)                             | 否 | 是 | 证书颁发机构（CA），用于验证远程服务器的身份。如果未设置此字段，系统CA将用于验证远程服务器的标识。<br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| tlsOptions<sup>18+</sup> | [TlsOptions](#tlsoptions18)                                         | 否 | 是 | TLS配置。<br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| serverAuthentication<sup>18+</sup> | [ServerAuthentication](#serverauthentication18)                     | 否 | 是 | 安全连接期间的服务器身份验证配置。默认不认证。<br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| sslType<sup>20+</sup> | [SslType](#ssltype20) | 否 | 是 | 使用安全通信协议TLS（默认）或TLCP。如果使用TLCP，相关的选项（如caPath、clientCert和clientEncCert）必须赋有效值。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |
| clientEncCert<sup>20+</sup> | [ClientCert](#clientcert11) | 否 | 是 | 支持应用程序传入客户端证书，使服务器能够进行验证客户端的加密身份。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |
| customMethod<sup>23+</sup> | string | 否 | 是 | 支持自定义请求方法，例如实现WebDAV扩展协议，当与method同时配置时，customMethod优先级更高。<br />- 默认值为空字符串，最大长度128个字符，超出则不生效。<br />- 当customMethod符合WebDAV扩展协议请求方式，但服务器不支持时，本次请求的服务器响应码通常为405或501（实际结果与服务器具体行为有关）。<br />- 当customMethod不符合WebDAV扩展协议请求方式时，本次请求的服务器响应码通常为400或405（实际结果与服务器具体行为有关）。 |
| maxRedirects<sup>23+</sup> | number | 否 | 是 | 支持针对HttpRequest指定最大跳转次数。<br />- 默认值为30次。<br />- 取值范围是：[0，2147483647]，设置0即为关闭重定向，当服务器的重定向次数超过设置的最大重定向次数时会返回错误码2300047。超出此范围该配置不生效，配置默认值30。 |
| sniHostName<sup>23+</sup> | string | 否 | 是 | 支持客户端通过配置SNI（Server Name Indication，服务器名称指示）在TLS握手阶段向服务器声明目标域名，使服务器能够根据域名选择对应的SSL/TLS证书进行加密通信。<br />- 默认值为空字符串，sniHostName参数长度上限为255个字符。若超出长度限制或设置为空字符串，该设置将不会生效。 |
| pathPreference<sup>23+</sup> |[PathPreference](#pathpreference23) | 否 | 是 |支持HTTP请求指定特定激活的网络。 |
| reuseConnections | boolean | 否 | 是 | HTTP请求是否复用连接。默认值为true，表示复用已有的连接；设置为false时，每次请求将建立新的连接，不再复用已有连接。本字段可与inactivityMs字段搭配使用，自定义连接超时关闭时间。<br />- 连接复用是指在完成一次HTTP请求后，底层的TCP连接不会被立即关闭，而是保持在连接池中，后续的HTTP请求如果目标地址相同，可以重用该连接，从而减少TCP握手和TLS握手的开销，提高性能。<br/>**起始版本：** 26.0.0 <br/>**模型约束：** 此接口仅可在Stage模型下使用。|
| inactivityMs | number | 否 | 是 | 连接池中的连接最大空闲时间，超过该时间后连接将被关闭。单位为毫秒（ms），默认配置值为118秒。系统内部比较时间时会先计算连接空闲时间的差值，然后向下取整到秒，再与配置的值进行比较。<br/>- 取值范围是(0, 2147483647]，传入小于等于0的数值时系统使用默认值118秒。当reuseConnections配置为false时，该参数不生效。<br/>**起始版本：** 26.0.0 <br/>**模型约束：** 此接口仅可在Stage模型下使用。|
| usingSocks5Proxy | [Socks5Proxy](#socks5proxy) | 否 | 是 | SOCKS5代理配置，该项不配置时不启动SOCKS5代理。<br />当该项被正确配置时，如果同时配置了usingProxy，usingProxy不生效。<br />**起始版本：** 26.0.0 <br/>**模型约束：** 此接口仅可在Stage模型下使用。|
| enablePartialChain | boolean | 否 | 是 | 是否允许在证书链验证时使用信任库中的中间CA证书作为信任锚点。设置为false时，证书链必须逐级验证至受信任的根CA证书。设置为true时，若信任库中存在中间CA证书，则证书链验证到该中间CA时即可视为通过，无需继续追溯至根CA证书。当[SslType](#ssltype20)使用默认值或设置为TLS时，默认值为true；当[SslType](#ssltype20)设置为TLCP时，默认值为false。<br/>**起始版本：** 26.0.0 <br/>**模型约束：** 此接口仅可在Stage模型下使用。|

## RequestMethod

HTTP 请求方法。

**系统能力**：SystemCapability.Communication.NetStack

| 名称    | 值      | 说明                |
| :------ | ------- | :------------------ |
| OPTIONS | "OPTIONS" | OPTIONS方法描述了目标资源的通信选项。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| GET     | "GET"     | GET方法请求指定资源的表示。使用GET的请求应该只检索数据，不应该包含请求内容。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| HEAD    | "HEAD"    | HEAD方法请求与GET请求相同的响应，但没有响应主体。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| POST    | "POST"    | POST方法将实体提交给指定的资源，通常会导致服务器上的状态更改。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| PUT     | "PUT"     | PUT方法将目标资源的所有当前表示替换为请求内容。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| DELETE  | "DELETE"  | DELETE方法用于删除指定的资源。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| TRACE   | "TRACE"   | TRACE方法沿到达目标资源的路径执行消息环回测试。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| CONNECT | "CONNECT" | CONNECT方法建立到由目标资源标识的服务器的隧道。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| PATCH   | "PATCH"   | PATCH方法对资源进行部分修改。 <br/>**起始版本：** 26.0.0<br/>**模型约束：** 此接口仅可在Stage模型下使用。|

## ResponseCode

发起请求返回的响应码。

**系统能力**：SystemCapability.Communication.NetStack

| 名称              | 值   | 说明                                                         |
| ----------------- | ---- | ------------------------------------------------------------ |
| OK                | 200  | 请求成功。用于GET与POST请求。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                            |
| CREATED           | 201  | 已创建。请求成功并已创建新资源。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                           |
| ACCEPTED          | 202  | 已接受。请求已被接受，但未处理完成。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                         |
| NOT_AUTHORITATIVE | 203  | 非授权信息。请求成功。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                       |
| NO_CONTENT        | 204  | 无内容。服务器成功处理，但未返回内容。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                       |
| RESET             | 205  | 重置内容。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                   |
| PARTIAL           | 206  | 部分内容。服务器成功处理了部分GET请求。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                      |
| MULT_CHOICE       | 300  | 多种选择。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                   |
| MOVED_PERM        | 301  | 永久移动。请求的资源已被永久的移动到新URI，返回信息会包括新的URI，浏览器会自动定向到新URI。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| MOVED_TEMP        | 302  | 临时移动。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                   |
| SEE_OTHER         | 303  | 查看其它地址。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                               |
| NOT_MODIFIED      | 304  | 未修改。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                     |
| USE_PROXY         | 305  | 使用代理。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                   |
| BAD_REQUEST       | 400  | 客户端请求的语法错误，服务器无法理解。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                       |
| UNAUTHORIZED      | 401  | 请求需要用户的身份认证。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                     |
| PAYMENT_REQUIRED  | 402  | 保留字段，将来使用。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                             |
| FORBIDDEN         | 403  | 服务器理解请求客户端的请求，但是拒绝执行此请求。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。             |
| NOT_FOUND         | 404  | 服务器无法根据客户端的请求找到资源(网页)。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                 |
| BAD_METHOD        | 405  | 客户端请求中的方法被禁止。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                   |
| NOT_ACCEPTABLE    | 406  | 服务器无法根据客户端请求的内容特性完成请求。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                 |
| PROXY_AUTH        | 407  | 请求需要代理的身份认证。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                     |
| CLIENT_TIMEOUT    | 408  | 请求超时。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                         |
| CONFLICT          | 409  | 服务器完成客户端的PUT请求时可能返回此代码，服务器处理请求时发生了冲突。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| GONE              | 410  | 客户端请求的资源已经不存在。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                 |
| LENGTH_REQUIRED   | 411  | 服务器无法处理客户端发送的不带Content-Length的请求信息。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。     |
| PRECON_FAILED     | 412  | 客户端请求信息的先决条件错误。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                               |
| ENTITY_TOO_LARGE  | 413  | 由于请求的实体过大，服务器无法处理，因此拒绝请求。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。           |
| REQ_TOO_LONG      | 414  | 请求的URI过长(URI通常为网址)，服务器无法处理。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。             |
| UNSUPPORTED_TYPE  | 415  | 服务器无法处理请求的格式。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                   |
| RANGE_NOT_SATISFIABLE<sup>12+</sup> | 416  | 请求范围不符合要求。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                  |
| INTERNAL_ERROR    | 500  | 服务器内部错误，无法完成请求。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                               |
| NOT_IMPLEMENTED   | 501  | 服务器不支持请求的功能，无法完成请求。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                       |
| BAD_GATEWAY       | 502  | 充当网关或代理的服务器，从远端服务器接收到了一个无效的请求。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| UNAVAILABLE       | 503  | 由于超载或系统维护，服务器暂时无法处理客户端的请求。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。       |
| GATEWAY_TIMEOUT   | 504  | 充当网关或代理的服务器，未及时从远端服务器获取请求。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。         |
| VERSION           | 505  | 服务器不支持客户端请求中使用的HTTP协议版本。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                 |

## HttpResponse

request方法回调函数的返回值类型。

**系统能力**：SystemCapability.Communication.NetStack

| 名称   | 类型                                           | 只读 | 可选 |说明                    |
| -------- | ---------------------------------------------- | ---- | --- | ---------------------- |
| result               | string \| Object \| ArrayBuffer | 否   | 否   | HTTP请求根据响应头中content-type类型返回对应的响应格式内容，若HttpRequestOptions无expectDataType字段，按如下规则返回：<br />- application/json：返回JSON格式的字符串。<br />- application/octet-stream：ArrayBuffer。<br />- image：ArrayBuffer。<br />- 其他：string。<br /> 若HttpRequestOption有expectDataType字段，开发者需传入与服务器返回类型相同的数据类型。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| resultType<sup>9+</sup> | [HttpDataType](#httpdatatype9)             | 否   | 否   | 返回值类型。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                           |
| responseCode         | [ResponseCode](#responsecode) \| number      | 否   | 否   | 回调函数执行成功时，此字段为[ResponseCode](#responsecode)。若执行失败，错误码将会从AsyncCallback中的err字段返回。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| header               | Object                                       | 否   | 否  | 发起HTTP请求返回来的响应头。当前返回的是JSON格式字符串，如需具体字段内容，需开发者自行解析。常见字段及解析方式如下：<br/>- content-type：header['content-type']。<br />- status-line：header['status-line']。<br />- date：header.date/header['date']。<br />- server：header.server/header['server']。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| cookies<sup>8+</sup> | string                                       | 否   | 否   | 服务器返回的原始cookies。开发者可自行处理。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。               |
| performanceTiming<sup>11+</sup> | [PerformanceTiming](#performancetiming11) | 否   | 否 | HTTP请求的各个阶段的耗时。|
| connectionExtraInfo<sup>24+</sup> | [ConnectionExtraInfo](#connectionextrainfo24) | 否 | 是 | HTTP请求交互的详细信息。 |

## ClientCert<sup>11+</sup>

客户端证书类型。

**系统能力**：SystemCapability.Communication.NetStack

| 名称   | 类型                                           | 只读 | 可选 |说明                    |
| -------- | ---------------------------------------------- | ---- | --- | ---------------------- |
| certPath | string | 否   | 否 | 证书路径。 |
| certType | [CertType](#certtype11) | 否   | 是 | 证书类型，默认是PEM。 |
| keyPath | string | 否   | 否 | 证书密钥的路径。 |
| keyPassword | string | 否   | 是  | 证书密钥的密码。默认值为空字符串。 |

## PerformanceTiming<sup>11+</sup>

性能打点(单位：ms)。

**系统能力**：SystemCapability.Communication.NetStack

| 名称   | 类型                                           | 只读 | 可选 |说明                    |
| -------- | ---------------------------------------------- | ---- | --- | ---------------------- |
| dnsTiming  | number | 否   | 否   | 从[request](#request)请求到DNS解析完成耗时。 |
| tcpTiming  | number | 否   | 否   | 从[request](#request)请求到TCP连接完成耗时。 |
| tlsTiming  | number | 否   | 否   | 从[request](#request)请求到TLS连接完成耗时。 |
| firstSendTiming  | number | 否   | 否   | 从[request](#request)请求到开始发送第一个字节的耗时。 |
| firstReceiveTiming  | number | 否   | 否   | 从[request](#request)请求到接收第一个字节的耗时。 |
| totalFinishTiming  | number | 否   | 否  | 从[request](#request)请求到完成请求的耗时。 |
| redirectTiming  | number | 否   | 否  | 从[request](#request)请求到完成所有重定向步骤的耗时。 |
| responseHeaderTiming  | number | 否   | 否   | 从[request](#request)请求到header解析完成的耗时。 |
| responseBodyTiming  | number | 否   | 否   | 从[request](#request)请求到body解析完成的耗时。 |
| totalTiming  | number | 否   | 否   | 从[request](#request)请求回调到应用程序的耗时。 |

## ConnectionExtraInfo<sup>24+</sup>

HTTP请求交互的详细信息。

**系统能力**：SystemCapability.Communication.NetStack

**模型约束**：此接口仅可在Stage模型下使用。

| 名称                | 类型                          | 只读 | 可选 | 说明                                                         |
| ------------------- | ----------------------------- | ---- | ---- | ------------------------------------------------------------ |
| networkProtocolName | string                        | 否   | 否   | [request](#request)请求过程中的HTTP协议版本，如'HTTP/1.0'，'HTTP/1.1'，'HTTP/2'，'HTTP/2 over TLS'，'HTTP/3'，'Unknown/Non-HTTP'等。 |
| tlsVersion          | [TlsVersion](#tlsversion18)   | 否   | 是   | request请求过程中的TLS协议版本。只有当使用TLS协议时返回相应的TLS版本。 |
| cipherSuite         | [CipherSuite](#ciphersuite18) | 否   | 是   | request请求过程中的加密套件。只有当使用TLS协议时返回相应的加密套件。 |
| localAddress        | string                        | 否   | 否   | request请求过程中的客户端IP地址。                            |
| remoteAddress       | string                        | 否   | 否   | request请求过程中的服务端IP地址。                            |
| localPort           | number                        | 否   | 否   | request请求过程中的客户端端口，取值范围[1, 65535]。           |
| remotePort          | number                        | 否   | 否   | request请求过程中的服务端端口，取值范围[1, 65535]。           |
| isReusedConnection  | boolean                       | 否   | 否   | request请求过程中是否复用连接。true表示新建连接，false表示复用连接。 |
| isProxyConnection   | boolean                       | 否   | 否   | request请求过程中是否使用代理。true表示使用代理，false表示未使用代理。 |
| isCacheHit          | boolean                       | 否   | 否   | request请求过程中是否命中本地缓存。true表示命中本地缓存，false表示未命中本地缓存。 |
| redirectCount       | number                        | 否   | 否   | request请求过程中的重定向次数。                              |

## DataReceiveProgressInfo<sup>11+</sup>

数据接收信息。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

| 名称   | 类型                                           | 只读 | 可选 |说明                    |
| -------- | ---------------------------------------------- | ---- | --- | ---------------------- |
|  receiveSize        | number | 否   | 否  | 已接收的数据量（单位：Byte）。   |
| totalSize| number | 否   | 否 | 总共要接收的数据量（单位：Byte）。 |

## DataSendProgressInfo<sup>11+</sup>

数据发送信息。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

### 属性

| 名称   | 类型                                           | 只读 | 可选 |说明                    |
| -------- | ---------------------------------------------- | ---- | --- | ---------------------- |
| sendSize        | number | 否   | 否  | 每次发送的数据量(单位：Byte)。  |
| totalSize | number | 否   | 否 | 总共要发送的数据量(单位：Byte)。 |

## MultiFormData<sup>11+</sup>

多部分表单数据的类型。

**系统能力**：SystemCapability.Communication.NetStack

| 名称   | 类型                                           | 只读 | 可选 |说明                    |
| -------- | ---------------------------------------------- | ---- | --- | ---------------------- |
| name        | string | 否 | 否 | 数据名称。                                                                      |
| contentType | string | 否 | 否 | 数据类型，如'text/plain'，'image/png', 'image/jpeg', 'audio/mpeg', 'video/mp4'等。 |
| remoteFileName | string | 否 | 是 | 上传到服务器保存为文件的名称。<br>**说明**：指定该字段后，请求头中会添加filename字段，表示上传到服务器文件的名称。<br>（1）当上传数据为文件时，若通过data字段指定文件内容，通常需要设置remoteFileName字段，用以指定上传到服务器文件的名称（实际结果与服务器具体行为有关）；若通过filePath字段指定文件路径，请求头中会自动添加filename字段，其默认值为filePath中的文件名称，如需特殊指定，也可通过本字段对filename重新设置。<br>（2）当上传数据为二进制格式时，则必须设置remoteFileName字段。<br>（3）当使用filePath上传文件时，设置remoteFileName字段会影响文件传输方式。若设置了remoteFileName，系统会先尝试将文件完整读入内存后再发送；若未设置remoteFileName，系统会使用流式传输方式直接从文件读取并发送数据。对于大文件（如超过100MB）的上传场景，建议不设置remoteFileName，使用系统默认的流式传输方式，避免内存占用过高。 |
| data | string \| Object \| ArrayBuffer | 否 | 是 | 表单数据内容。                                               |
| filePath | string | 否 | 是 | 此参数将文件路径指向的文件内容设置为表单数据，如果未指定data内容，则必须设置filePath。<br>**说明**：需传入文件管理模块支持的格式，可以通过文件管理的[access](../apis-core-file-kit/js-apis-file-fs.md#fileioaccess)接口，验证文件是否存在且可访问。|

## http.createHttpResponseCache<sup>9+</sup>

createHttpResponseCache(cacheSize?: number): HttpResponseCache

创建一个HttpResponseCache对象，可用于存储HTTP请求的响应数据。对象中可调用[flush](#flush9)与[delete](#delete9)方法，cacheSize指定缓存大小。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| cacheSize | number | 否 | 响应缓存大小，单位为Byte。取值范围为1\*1024\*1024到10\*1024\*1024，即1MB到10MB。默认值为10MB。超出10MB时设置为10MB；小于1MB时，设置为1MB。 |

**返回值：**

| 类型        | 说明                                                         |
| :---------- | :----------------------------------------------------------- |
| [HttpResponseCache](#httpresponsecache9) | 返回一个存储HTTP访问请求响应的对象。 |

**示例：**

```ts
import { http } from '@kit.NetworkKit';

let httpResponseCache = http.createHttpResponseCache();
```

## HttpResponseCache<sup>9+</sup>

存储HTTP访问请求响应的对象。在调用HttpResponseCache的方法前，需要先通过[createHttpResponseCache()](#httpcreatehttpresponsecache9)创建一个任务。

**响应头中的相应关键字使用**

- **`Cache-Control`**：用于指定缓存策略，如`no-cache`, `no-store`, `max-age`, `public`, `private`等。

- **`Expires`**：指定资源的过期时间，格式为GMT时间。

- **`ETag`**：用于资源版本标识，客户端可以使用`If-None-Match`请求头来验证资源是否已更改。

- **`Last-Modified`**：指定资源最后修改时间，客户端可以使用`If-Modified-Since`请求头来验证资源是否已更改。

- **`Vary`**：指定哪些请求头的值会影响缓存的响应，用于区分不同的缓存版本。

使用这些关键字时，服务器端需要正确配置响应头，客户端则需要根据这些响应头来决定是否使用缓存的资源，以及如何验证资源是否是最新的。正确的缓存策略可以显著提高应用的性能和用户体验。

**如何设置Cache-Control头**

`Cache-Control`为通用报头，但通常是在服务器端进行的，允许定义一个响应资源应该何时、如何被缓存以及缓存多长时间。以下是一些常用的`Cache-Control`指令及其含义：

- **`no-cache`**：表示在使用缓存前，必须先去源服务器校验资源的有效性。如果资源未变更，则响应状态码为304(Not Modified)，不发送资源内容，使用缓存中的资源。如果资源已经过期，则响应状态码为200(OK)，并发送资源内容。

- **`no-store`**：表示不允许缓存资源，每次请求都必须从服务器获取资源。

- **`max-age`**：指定缓存的最大时间(以秒为单位)。例如，`Cache-Control: max-age=3600`表示缓存的有效期为1小时。

- **`public`**：表明响应可以被任何对象(包括：发送请求的客户端，代理服务器等)缓存。

- **`private`**：表明响应只能被单个用户缓存，不能作为共享缓存(即代理服务器不能缓存)。

- **`must-revalidate`**：表示必须在使用缓存前验证旧资源的状态，并且在缓存过期后，需要重新验证资源。

- **`no-transform`**：表示不允许代理服务器修改响应内容。

- **`proxy-revalidate`**：与`must-revalidate`类似，但仅适用于共享缓存。

- **`s-maxage`**：类似于`max-age`，但仅适用于共享缓存。

### flush<sup>9+</sup>

flush(callback: AsyncCallback\<void\>): void

将缓存中的数据写入文件系统，以便在下一个HTTP请求中访问所有缓存数据，使用callback方式作为异步方法。缓存数据包括：响应头(header)、响应体(result)、cookies、请求时间(requestTime)和响应时间(responseTime)。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<void\> | 是   | 回调函数。返回写入结果。当写入成功时，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { http } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let httpResponseCache = http.createHttpResponseCache();
let httpRequest = http.createHttp();
httpRequest.request("EXAMPLE_URL", (err: BusinessError, data: http.HttpResponse) => {
  if (!err) {
    httpResponseCache.flush((err: BusinessError) => {
      if (err) {
        console.error('flush fail');
      }
      console.info('flush success');
    });
    httpRequest.destroy();
  } else {
    console.error('error:' + JSON.stringify(err));
    // 当该请求使用完毕时，开发者务必调用destroy方法释放资源，避免出现内存泄漏。
    httpRequest.destroy();
  }
});
```

### flush<sup>9+</sup>

flush(): Promise\<void\>

将缓存中的数据写入文件系统，以便在下一个HTTP请求中访问所有缓存数据，使用Promise方式作为异步方法。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
import { http } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let httpRequest = http.createHttp();
let httpResponseCache = http.createHttpResponseCache();
let promise = httpRequest.request("EXAMPLE_URL");

promise.then((data: http.HttpResponse) => {
  httpResponseCache.flush().then(() => {
    console.error('flush success');
  }).catch((err: BusinessError) => {
    console.error('flush fail');
  });
}).catch((err: Error) => {
  console.error('error:' + JSON.stringify(err));
});
```

### delete<sup>9+</sup>

delete(callback: AsyncCallback\<void\>): void

禁用缓存并删除其中的数据，使用callback方式作为异步方法。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<void\> | 是   | 回调函数。当删除成功时，err为undefined，否则为错误对象。|

**示例：**

```ts
import { http } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let httpRequest = http.createHttp();
httpRequest.request("EXAMPLE_URL").then(data => {
  const httpResponseCache = http.createHttpResponseCache();
  httpResponseCache.delete((err: BusinessError) => {
    try {
      if (err) {
        console.error('fail: ' + err);
      } else {
        console.info('success');
      }
    } catch (err) {
      console.error('error: ' + err);
    }
  });
  httpRequest.destroy();
}).catch((error: BusinessError) => {
  console.error("errcode" + JSON.stringify(error));
});
```

### delete<sup>9+</sup>

delete(): Promise\<void\>

禁用缓存并删除其中的数据，使用Promise方式作为异步方法。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
import { http } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let httpRequest = http.createHttp();
httpRequest.request("EXAMPLE_URL").then(data => {
  const httpResponseCache = http.createHttpResponseCache();
  httpResponseCache.delete().then(() => {
    console.info("success");
  }).catch((err: BusinessError) => {
    console.error("fail");
  });
  httpRequest.destroy();
}).catch((error: BusinessError) => {
  console.error("errcode" + JSON.stringify(error));
});
```

## HttpDataType<sup>9+</sup>

HTTP的数据类型。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

| 名称 | 值 | 说明     |
| ------------------  | -- | ----------- |
| STRING              | 0 | 字符串类型。 |
| OBJECT              | 1 | 对象类型。    |
| ARRAY_BUFFER        | 2 | 二进制数组类型。|

## HttpProtocol<sup>9+</sup>

HTTP协议版本。

**系统能力**：SystemCapability.Communication.NetStack

| 名称  |   值   | 说明                                                                   |
| :-------- | :----------- |:---------------------------------------------------------------------|
| HTTP1_1   |   0   | 协议HTTP1.1。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。       |
| HTTP2     |   1   | 协议HTTP2。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。          |
| HTTP3<sup>11+</sup> |  2  | 协议HTTP3，若系统或服务器不支持，则使用低版本的HTTP协议请求。<br />**注意：** 仅对HTTPS的URL生效，HTTP则会请求失败。 |

## CertType<sup>11+</sup>

枚举，证书类型。

**系统能力**：SystemCapability.Communication.NetStack

| 名称 |   值   | 说明       |
| --- | ------ | ---------- |
| PEM | PEM | 证书类型PEM。 |
| DER | DER | 证书类型DER。 |
| P12 | P12 | 证书类型P12。 |

## CertificatePinning<sup>12+</sup>

由应用配置的证书。

**系统能力**：SystemCapability.Communication.NetStack

| 名称   | 类型                                           | 只读 | 可选 |说明                    |
| -------- | ---------------------------------------------- | ---- | --- | ---------------------- |
| publicKeyHash       | string | 否   | 否 |字符串类型的证书PIN码。 |
| hashAlgorithm        | 'SHA-256' |  否   | 否  |加密算法，当前仅支持该算法。 |

## HttpProxy<sup>10+</sup>

type HttpProxy = connection.HttpProxy

网络代理配置信息。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

|       类型       |            说明             |
| ---------------- | --------------------------- |
| connection.HttpProxy | 网络代理配置信息。     |

## Socks5Proxy

type Socks5Proxy = connection.Socks5Proxy

SOCKS5代理配置信息。

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Communication.NetStack

|       类型       |            说明             |
| ---------------- | --------------------------- |
| [connection.Socks5Proxy](js-apis-net-connection.md#socks5proxy) | SOCKS5代理配置信息。     |

## QueryParamValue

type QueryParamValue = string \| number \| boolean \| null \| undefined

QueryParamObject中允许使用的单个参数值类型。

**起始版本：** 26.0.0

**系统能力**：SystemCapability.Communication.NetStack

**模型约束：** 此接口仅可在Stage模型下使用。

| 类型 | 说明 |
| ---------------- | --------------------------- |
| string | 字符串类型。 |
| number | 数字类型，会先转为字符串再参与编码。 |
| boolean | 布尔类型，会先转为字符串再参与编码。 |
| null | 空值类型，会按仅key不带`=`值的形式序列化。 |
| undefined | 未定义类型，会按仅key不带`=`值的形式序列化。 |

## QueryParamObject

type QueryParamObject = Record\<string, QueryParamValue \| QueryParamValue[]\>

用于构造URL查询参数的键值对象类型。

**起始版本：** 26.0.0

**系统能力**：SystemCapability.Communication.NetStack

**模型约束：** 此接口仅可在Stage模型下使用。

| 类型 | 说明 |
| ---------------- | --------------------------- |
| Record\<string, [QueryParamValue](#queryparamvalue) \| [QueryParamValue](#queryparamvalue)[]\> | 键值对象类型，用于构造URL查询参数。每个属性名作为URL参数的key，属性值作为参数值。<br>**说明：**<br>(1) 对象的每个属性名作为URL参数的key，属性值作为参数值。例如`{ scene: 'demo', page: 1 }`会序列化为`scene=demo&page=1`。<br>(2) 当属性值为数组时，会展开为同名多参数。例如`{ tag: ['a', 'b'] }`会序列化为`tag=a&tag=b`。<br>(3) key和value由系统自动进行URL编码，开发者应传入原始未编码内容。<br>(4) 如需严格控制参数顺序或重复键顺序，建议直接使用queryParams的string形式。 |

## AddressFamily<sup>15+</sup>

枚举，解析目标域名时限定的地址类型。

**系统能力**：SystemCapability.Communication.NetStack

|       名称       |     值     |            说明             |
| ---------------- | --------------- | --------------------------- |
| DEFAULT | CURL_IPRESOLVE_WHATEVER | 设置此选项后，系统将自行选择目标域名的IPv4地址或IPv6地址。     |
| ONLY_V4 | CURL_IPRESOLVE_V4 | 设置此选项后，系统仅解析目标域名的IPv4地址，忽略IPv6地址。     |
| ONLY_V6 | CURL_IPRESOLVE_V6 | 设置此选项后，系统仅解析目标域名的IPv6地址，忽略IPv4地址。     |

## Credential<sup>18+</sup>

会话中服务器身份验证设置所使用的身份验证凭据，包括用户名和密码。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

|  名称  |  类型  |  只读  | 可选  |说明     |
| ------------------  |---- |-- | -- |----------- |
| username       | string | 否 |否 |用于身份验证的用户名。默认值为' '。 |
| password        | string |  否  |否 |用于身份验证的密码。默认值为' '。 |

## ServerAuthentication<sup>18+</sup>

HTTP服务器身份验证。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

|  名称               |  类型                                            | 只读    |    可选     |说明     |
| ------------------  |-------------------------------------------------|-------- |------------ |---------------|
| credential          | [Credential](#credential18)                     | 否      | 否         |服务器的凭证。默认值为undefined。     |
| authenticationType  | [AuthenticationType](#authenticationtype18)     | 否      | 是        | 服务器的认证类型。如果没有设置，需与服务器协商。     |


## TlsConfig<sup>18+</sup>

TLS加密版本及套件配置。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

|  名称               |  类型                            | 只读    |    可选     |说明     |
| ------------------  |---------------------------------|-------- |-------- |---------------|
| tlsVersionMin       | [TlsVersion](#tlsversion18)     | 否      |否       | TLS最低版本号。     |
| tlsVersionMax        | [TlsVersion](#tlsversion18)    | 否      |否       | TLS最高版本号。     |
| cipherSuites        | [CipherSuite](#ciphersuite18)[] | 否      |是       | 声明加密套件类型的数组。如果没有设置，默认携带全部支持的加密套件类型，加密套件类型参考[TlsV13SpecificCipherSuite](#tlsv13specificciphersuite18)、[TlsV12SpecificCipherSuite](#tlsv12specificciphersuite18)、[TlsV10SpecificCipherSuite](#tlsv10specificciphersuite18)。 |

## TlsVersion<sup>18+</sup>

枚举，TLS版本号。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

| 名称        | 值 | 说明         |
|:----------|:--|:-----------|
| TLS_V_1_0 | 4 | TLS版本号1.0。 |
| TLS_V_1_1 | 5 | TLS版本号1.1。 |
| TLS_V_1_2 | 6 | TLS版本号1.2。 |
| TLS_V_1_3 | 7 | TLS版本号1.3。 |

## TlsOptions<sup>18+</sup>

type TlsOptions = 'system' | TlsConfig

TLS配置。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

| 类型                         | 说明                                                                                 |
|-------------------------------|------------------------------------------------------------------------------------|
| 'system'  | 表示使用系统的TLS版本，是未进行TLS设置的默认值，值固定为'system'字符串。 |
| TlsConfig | 表示使用自定义的TLS版本号和加密套件。 |

## RemoteValidation<sup>18+</sup>

type RemoteValidation = 'system' | 'skip' | ValidationCallback

验证远程服务器身份的方式。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

| 类型                         | 说明                                                                                 |
|-------------------------------|------------------------------------------------------------------------------------|
| 'system'  | 表示使用系统CA验证远端服务器身份，值固定为'system'字符串，是未配置时的默认值。 |
| 'skip'   | 表示跳过验证远端服务器身份流程，值固定为'skip'字符串。 |
| [ValidationCallback](#validationcallback) | 表示使用自定义验证方式验证远端服务器身份。<br/>**起始版本：** 26.0.0<br/>**模型约束：** 此接口仅可在Stage模型下使用。 |

## X509Cert

type X509Cert = cert.X509Cert

X509证书对象。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Communication.NetStack

|       类型       |            说明             |
| ---------------- | --------------------------- |
| [cert.X509Cert](../apis-device-certificate-kit/js-apis-cert.md#x509cert) | X509证书对象。     |

## ValidationContext

验证远端服务器身份时的证书上下文信息，作为[ValidationCallback](#validationcallback)的参数传入。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Communication.NetStack

| 名称   | 类型                                           | 只读 | 可选 |说明                    |
| -------- | ---------------------------------------------- | ---- | --- | ---------------------- |
| pemCerts        | string[] | 否   | 否  | PEM格式的证书原始数据。   |
| x509Certs | [X509Cert](#x509cert)[] | 否   | 否 | X509证书链。 |
| host        | string | 否   | 否  | 本次请求的目标主机名。   |
| ip | string | 否   | 否 | 本次请求实际连接的IP地址。 |

## ValidationCallback

type ValidationCallback = (context: ValidationContext) => boolean | Promise\<boolean\>

自定义远端服务器身份验证回调函数。开发者可通过此回调实现自定义的证书验证逻辑，支持同步或异步返回验证结果。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名 | 类型    | 必填 | 说明                            |
| ---------------- | -------------------  | ------ | --------------------------------------------- |
| context | [ValidationContext](#validationcontext) | 是 | 证书验证上下文，包含证书链、主机名和IP地址等信息。             |

**返回值：**

| 类型 | 说明                                   |
| ------ | -------------------------------------- |
| boolean \| Promise\<boolean\> | 返回布尔值表示验证是否通过。true表示验证通过，false表示验证不通过。支持返回Promise对象，用于异步验证场景。   |

## AuthenticationType<sup>18+</sup>

type AuthenticationType = 'basic' | 'ntlm' | 'digest'

在会话中的服务器身份验证时可以设置使用不同的身份验证机制。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

|类型                          | 说明                                                                                                 |
|-------------------------------|----------------------------------------------------------------------------------------------------|
| 'basic'  | 表示使用基本认证方式，值固定为'basic'字符串。 |
| 'ntlm'   | 表示使用ntlm认证方式，值固定为'ntlm'字符串。 |
| 'digest' | 表示使用摘要认证方式，值固定为'digest'字符串。 |

## CipherSuite<sup>18+</sup>

type CipherSuite = TlsV13CipherSuite

加密套件声明函数。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

|       类型       | 说明                                                                |
| ---------------- |-------------------------------------------------------------------|
| TlsV13CipherSuite | 表示值的类型为[TlsV13CipherSuite](#tlsv13ciphersuite18)。                 |

## TlsV13CipherSuite<sup>18+</sup>

type TlsV13CipherSuite = TlsV12CipherSuite | TlsV13SpecificCipherSuite

TLS1.3的加密套件声明函数，支持TLS1.3版本，兼容TLS1.2版本。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

|       类型       | 说明                                                                |
| ---------------- |-------------------------------------------------------------------|
| TlsV12CipherSuite | 表示值的类型为[TlsV11CipherSuite](#tlsv11ciphersuite18)。                 |
| TlsV13SpecificCipherSuite | 表示值的类型为[TlsV13SpecificCipherSuite](#tlsv13specificciphersuite18)。 |

## TlsV12CipherSuite<sup>18+</sup>

type TlsV12CipherSuite = TlsV11CipherSuite | TlsV12SpecificCipherSuite

TLS1.2的加密套件声明函数，支持TLS1.2版本，兼容TLS1.1版本。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

|       类型       | 说明                                                                |
| ---------------- |-------------------------------------------------------------------|
| TlsV11CipherSuite | 表示值的类型为[TlsV11CipherSuite](#tlsv11ciphersuite18)。                 |
| TlsV12SpecificCipherSuite | 表示值的类型为[TlsV12SpecificCipherSuite](#tlsv12specificciphersuite18)。 |

## TlsV11CipherSuite<sup>18+</sup>

type TlsV11CipherSuite = TlsV10CipherSuite

TLS1.1的加密套件声明函数，与TLS1.0的加密套件相同。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

|       类型       | 说明                                                |
| ---------------- |---------------------------------------------------|
| TlsV10CipherSuite | 表示值的类型为[TlsV10CipherSuite](#tlsv10ciphersuite18)。 |

## TlsV10CipherSuite<sup>18+</sup>

type TlsV10CipherSuite = TlsV10SpecificCipherSuite

TLS1.0的加密套件声明函数。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

|       类型       | 说明                                                                |
| ---------------- |-------------------------------------------------------------------|
| TlsV10SpecificCipherSuite | 表示值的类型为[TlsV10SpecificCipherSuite](#tlsv10specificciphersuite18)。 |

## TlsV13SpecificCipherSuite<sup>18+</sup>

type TlsV13SpecificCipherSuite = 'TLS_AES_128_GCM_SHA256' | 'TLS_AES_256_GCM_SHA384' | 'TLS_CHACHA20_POLY1305_SHA256'

TLS1.3及以上版本支持的加密套件。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

|       类型       | 说明   |
| ---------------- |------|
| 'TLS_AES_128_GCM_SHA256' | 表示值的类型为字符串，可取'TLS_AES_128_GCM_SHA256'。 |
| 'TLS_AES_256_GCM_SHA384' | 表示值的类型为字符串，可取'TLS_AES_256_GCM_SHA384'。 |
| 'TLS_CHACHA20_POLY1305_SHA256' | 表示值的类型为字符串，可取'TLS_CHACHA20_POLY1305_SHA256'。 |

## TlsV12SpecificCipherSuite<sup>18+</sup>

type TlsV12SpecificCipherSuite = 'TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256' | 'TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256' |
'TLS_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384' | 'TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384' |
'TLS_ECDHE_ECDSA_WITH_CHACHA20_POLY1305_SHA256' | 'TLS_ECDHE_RSA_WITH_CHACHA20_POLY1305_SHA256' |
'TLS_RSA_WITH_AES_128_GCM_SHA256' | 'TLS_RSA_WITH_AES_256_GCM_SHA384'

TLS1.2及以上版本支持的加密套件。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

|       类型       | 说明   |
| ---------------- |------|
| 'TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256' | 表示值的类型为字符串，可取'TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256'。 |
| 'TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256' | 表示值的类型为字符串，可取'TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256'。 |
| 'TLS_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384' | 表示值的类型为字符串，可取'TLS_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384'。 |
| 'TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384' | 表示值的类型为字符串，可取'TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384'。 |
| 'TLS_ECDHE_ECDSA_WITH_CHACHA20_POLY1305_SHA256' | 表示值的类型为字符串，可取'TLS_ECDHE_ECDSA_WITH_CHACHA20_POLY1305_SHA256'。 |
| 'TLS_ECDHE_RSA_WITH_CHACHA20_POLY1305_SHA256' | 表示值的类型为字符串，可取'TLS_ECDHE_RSA_WITH_CHACHA20_POLY1305_SHA256'。 |
| 'TLS_RSA_WITH_AES_128_GCM_SHA256' | 表示值的类型为字符串，可取'TLS_RSA_WITH_AES_128_GCM_SHA256'。 |
| 'TLS_RSA_WITH_AES_256_GCM_SHA384' | 表示值的类型为字符串，可取'TLS_RSA_WITH_AES_256_GCM_SHA384'。 |

## TlsV10SpecificCipherSuite<sup>18+</sup>

type TlsV10SpecificCipherSuite = 'TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA' | 'TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA' |
'TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA' | 'TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA' | 'TLS_RSA_WITH_AES_128_CBC_SHA' |
'TLS_RSA_WITH_AES_256_CBC_SHA' | 'TLS_RSA_WITH_3DES_EDE_CBC_SHA'

TLS1.0及以上版本支持的加密套件。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

|       类型       | 说明   |
| ---------------- |------|
| 'TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA' | 表示值的类型为字符串，可取'TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA'。 |
| 'TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA' | 表示值的类型为字符串，可取'TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA'。 |
| 'TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA' | 表示值的类型为字符串，可取'TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA'。 |
| 'TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA' | 表示值的类型为字符串，可取'TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA'。 |
| 'TLS_RSA_WITH_AES_128_CBC_SHA' | 表示值的类型为字符串，可取'TLS_RSA_WITH_AES_128_CBC_SHA'。 |
| 'TLS_RSA_WITH_AES_256_CBC_SHA' | 表示值的类型为字符串，可取'TLS_RSA_WITH_AES_256_CBC_SHA'。 |
| 'TLS_RSA_WITH_3DES_EDE_CBC_SHA' | 表示值的类型为字符串，可取'TLS_RSA_WITH_3DES_EDE_CBC_SHA'。 |

## SslType<sup>20+</sup>

type SslType = 'TLS' | 'TLCP'

安全通信协议。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

| 类型   | 说明                                   |
| ------ | -------------------------------------- |
| 'TLS' | 表示使用TLS安全通信协议，值固定为'TLS'字符串。   |
| 'TLCP' | 表示使用TLCP安全通信协议，值固定为'TLCP'字符串。<br>**说明**：<br>（1）证书支持字符串的规格：<br> - UTF8String（英文字符集）<br> - PrintableString<br>  - IA5String<br>从API Version 22开始支持：<br> - TeletexString<br>（2）证书支持扩展的规格：<br> - BasicConstraints（OID 2.5.29.19）<br> - KeyUsage（OID2.5.29.15）<br> - SubjectKeyIdentifier（OID2.5.29.14）<br> - AuthorityKeyIdentifier（OID2.5.29.35）<br>从API Version 22开始支持：<br> - SubjectAltName（OID 2.5.29.17）<br> - ExtendedKeyUsage（OID 2.5.29.37）<br/> |

## InterceptorType<sup>22+</sup>

HTTP拦截器的类型枚举。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

| 名称   | 值 |说明                                   |
| ------ | --|-------------------------------------- |
| INITIAL_REQUEST |'INITIAL_REQUEST' |在初始HTTP请求组装完成后拦截。|
| REDIRECTION | 'REDIRECTION' |当收到重定向响应时拦截。|
| CACHE_CHECKED | 'READ_CACHE' |在检查并且命中HTTP缓存时拦截。|
| NETWORK_CONNECT | 'CONNECT_NETWORK' |在网络请求将要发出前拦截。|
| FINAL_RESPONSE | 'FINAL_RESPONSE' |在获取最终HTTP响应时拦截。|

## HttpRequestContext<sup>22+</sup>

HTTP请求上下文数据。该对象实例在拦截器的[interceptorHandle](#interceptorhandle22)方法中作为参数传入，开发者可以通过该对象获取和修改HTTP请求的相关信息。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

### 属性

| 名称   | 类型 |只读 |可选 |说明                      |
| --   | -- |-- |-- |--                      |
| url   | string |否 |否 |HTTP拦截器从HTTP请求中获取到的URL，支持在拦截器中进行修改。|
| header   | Object |否 |否 |HTTP拦截器从HTTP请求中获取到的请求头，支持在拦截器中进行修改。|
| body   | Object |否 |否 |HTTP拦截器从HTTP请求中获取到的请求体，支持在拦截器中进行修改。|

## ChainContinue<sup>22+</sup>

type ChainContinue = boolean

是否继续处理拦截器链。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

| 类型   | 说明                                    |
| ------ | -------------------------------------- |
| boolean | true表示继续处理拦截器链，false表示终止并返回HTTP响应。                   |

## HttpInterceptor<sup>22+</sup>

HTTP拦截器接口。用户可以实现此接口来定义拦截处理函数。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

### 属性

| 名称   | 类型 |只读 |可选 |说明                      |
| --   | -- |-- |-- |--                      |
| interceptorType   | [InterceptorType](#interceptortype22)|否 |否 |拦截器类型，定义此拦截器何时被调用。                      |


### interceptorHandle<sup>22+</sup>

interceptorHandle(reqContext: HttpRequestContext, rspContext: HttpResponse): Promise\<ChainContinue\>

拦截HTTP处理过程并进行所需的更改。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型 | 必填 |说明                      |
| --   | -- | -- | --                      |
| reqContext   | [HttpRequestContext](#httprequestcontext22) |是 |经过HTTP拦截器的请求参数的上下文。                      |
| rspContext   | [HttpResponse](#httpresponse) |是 |经过HTTP拦截器的返回结果的上下文。                      |

**返回值：**

| 类型   | 说明                                   |
| ------ | -------------------------------------- |
| Promise\<[ChainContinue](#chaincontinue22)\> | 继续HTTP处理或终止并返回HTTP响应。   |

**示例：**

```ts
import { http } from '@kit.NetworkKit';

// 创建自定义拦截器
class CustomInterceptor implements http.HttpInterceptor {
  interceptorType: http.InterceptorType = http.InterceptorType.INITIAL_REQUEST;

  async interceptorHandle(reqContext: http.HttpRequestContext, rspContext: http.HttpResponse): Promise<http.ChainContinue> {
    // 在初始请求阶段添加认证头
    reqContext.header['Authorization'] = 'Bearer token';
    console.info('Interceptor: Added authorization header');
    return true; // 继续处理拦截器链
  }
}

let customInterceptor = new CustomInterceptor();
```

## HttpInterceptorChain<sup>22+</sup>

HTTP拦截器链。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**示例：**

```ts
import { http } from '@kit.NetworkKit';

let interceptorChain = new http.HttpInterceptorChain();
```

### addChain<sup>22+</sup>

addChain(chain: HttpInterceptor[]): boolean

向HTTP客户端添加拦截器。

> **说明：**
>
> 拦截器链中不能包含相同类型的拦截器实例。如果传入相同类型的拦截器，会抛出错误码2300802（Duplicated interceptor type in the chain）。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型   |必填   |说明   |
| ------ | ------ | ------ | ------ |
| chain | [HttpInterceptor](#httpinterceptor22)[] | 是 | 拦截器实例组成的拦截链，支持传入单个或者多个不同类型的拦截器。 |

**返回值：**

| 类型   | 说明                                   |
| ------ | -------------------------------------- |
| boolean | 拦截器是否添加成功。true表示拦截器添加成功，false表示拦截器没有添加成功。                   |

**错误码：**

以下错误码的详细介绍参见[通用错误码](../errorcode-universal.md)和[HTTP错误码](errorcode-net-http.md)。<br>
HTTP错误码映射关系：2300000 + curl错误码。更多常用错误码可参考：[curl错误码](https://curl.se/libcurl/c/libcurl-errors.html)

| 错误码ID    | 错误信息                                               |
| ------      | --------------------------------------                |
| 2300801 | Parameter type not supported by the interceptor.          |
| 2300802 | Duplicated interceptor type in the chain.                 |
| 2300999 | Internal error.                                           |

**示例：**

```ts
import { http } from '@kit.NetworkKit';

// 创建认证拦截器
class AuthInterceptor implements http.HttpInterceptor {
  interceptorType: http.InterceptorType = http.InterceptorType.INITIAL_REQUEST;

  async interceptorHandle(reqContext: http.HttpRequestContext, rspContext: http.HttpResponse): Promise<http.ChainContinue> {
    // 在初始请求阶段添加认证头
    reqContext.header['Authorization'] = 'Bearer token';
    console.info('Interceptor: Added authorization header');
    return true; // 继续处理拦截器链
  }
}

class LoggingInterceptor implements http.HttpInterceptor {
  interceptorType: http.InterceptorType = http.InterceptorType.FINAL_RESPONSE;

  async interceptorHandle(reqContext: http.HttpRequestContext, rspContext: http.HttpResponse): Promise<http.ChainContinue> {
    // 在最终响应阶段记录日志
    console.info(`LoggingInterceptor: Request to ${reqContext.url} completed with status ${rspContext.responseCode}`);
    return true; // 继续处理拦截器链
  }
}

// 创建拦截器链并应用到请求
let interceptorChain = new http.HttpInterceptorChain();
let authInterceptor = new AuthInterceptor();
let loggingInterceptor = new LoggingInterceptor();

// 添加拦截器到链中
try {
  let success = interceptorChain.addChain([authInterceptor, loggingInterceptor]);
  if (!success) {
    console.error('Failed to add interceptor chain');
  }
} catch (e) {
  console.error(`Interceptor chain add failed: code=${e.code}, message=${e.message}`);
}
```

### getChain<sup>22+</sup>

getChain(): HttpInterceptor[]

获取当前拦截器链中的所有拦截器实例。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型   | 说明                                     |
| ------ | --------------------------------------   |
| [HttpInterceptor](#httpinterceptor22)[] | 返回通过[addChain](#addchain22)方法添加的所有拦截器实例。             |

**示例：**

```ts
import { http } from '@kit.NetworkKit';

// 创建自定义拦截器
class CustomInterceptor implements http.HttpInterceptor {
  interceptorType: http.InterceptorType = http.InterceptorType.INITIAL_REQUEST;

  async interceptorHandle(reqContext: http.HttpRequestContext, rspContext: http.HttpResponse): Promise<http.ChainContinue> {
    // 在初始请求阶段添加认证头
    reqContext.header['Authorization'] = 'Bearer token';
    console.info('Interceptor: Added authorization header');
    return true; // 继续处理拦截器链
  }
}

// 创建拦截器链并应用到请求
let interceptorChain = new http.HttpInterceptorChain();
let customInterceptor = new CustomInterceptor();

// 添加拦截器到链中
try {
  let success = interceptorChain.addChain([customInterceptor]);
  if (!success) {
    console.error('Failed to add interceptor chain');
  }
} catch (e) {
  console.error(`Interceptor chain add failed: code=${e.code}, message=${e.message}`);
}

// 获取当前拦截器链中的所有拦截器
let chain = interceptorChain.getChain();
console.info(`Current interceptor chain has ${chain.length} interceptors`);
```

### apply<sup>22+</sup>

apply(httpRequest: HttpRequest): boolean

将拦截器链附加到目标HTTP请求。每个HTTP请求实例只能附加一个拦截器链。

> **说明：**
>
> 将拦截器链附加到[HttpRequest](#httprequest)实例后，当该实例发起HTTP请求时，会触发已附加的拦截器链中相应类型的拦截器。<br>
> 更多使用HTTP请求触发拦截器功能，可以参考[HTTP拦截器功能代码示例](../../network/http-request.md#http拦截器)。<br>
> HTTP拦截器相关能力仅支持[HttpRequest.request](#request)接口，目前暂不支持[HttpRequest.requestInStream](#requestinstream10)(流式传输)接口。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型   |必填   |说明   |
| ------ | ------ | ------ | ------ |
| httpRequest | [HttpRequest](#httprequest) | 是 | 要发起HTTP请求的[HttpRequest](#httprequest)。 |

**返回值：**

| 类型   | 说明                                   |
| ------ | -------------------------------------- |
| boolean | 拦截器是否附加成功。true表示拦截器附加成功，false表示拦截器没有附加成功。                   |

**错误码：**

以下错误码的详细介绍参见[通用错误码](../errorcode-universal.md)和[HTTP错误码](errorcode-net-http.md)。<br>
HTTP错误码映射关系：2300000 + curl错误码。更多常用错误码可参考：[curl错误码](https://curl.se/libcurl/c/libcurl-errors.html)

| 错误码ID    | 错误信息                                               |
| ------      | --------------------------------------                |
| 2300801 | Parameter type not supported by the interceptor.          |
| 2300999 | Internal error.                                           |

**示例：**

```ts
import { http } from '@kit.NetworkKit';

// 创建认证拦截器
class AuthInterceptor implements http.HttpInterceptor {
  interceptorType: http.InterceptorType = http.InterceptorType.INITIAL_REQUEST;

  async interceptorHandle(reqContext: http.HttpRequestContext, rspContext: http.HttpResponse): Promise<http.ChainContinue> {
    // 在初始请求阶段添加认证头
    reqContext.header['Authorization'] = 'Bearer token';
    console.info('Interceptor: Added authorization header');
    return true; // 继续处理拦截器链
  }
}

class LoggingInterceptor implements http.HttpInterceptor {
  interceptorType: http.InterceptorType = http.InterceptorType.FINAL_RESPONSE;

  async interceptorHandle(reqContext: http.HttpRequestContext, rspContext: http.HttpResponse): Promise<http.ChainContinue> {
    // 在最终响应阶段记录日志
    console.info(`LoggingInterceptor: Request to ${reqContext.url} completed with status ${rspContext.responseCode}`);
    return true; // 继续处理拦截器链
  }
}

// 创建拦截器链
let interceptorChain = new http.HttpInterceptorChain();
let authInterceptor = new AuthInterceptor();
let loggingInterceptor = new LoggingInterceptor();

// 创建HTTP请求
let httpRequest = http.createHttp();

try {
  // 添加拦截器到链中
  let success = interceptorChain.addChain([authInterceptor, loggingInterceptor]);
  if (!success) {
    console.error('Failed to add interceptor chain');
  }

  // 将拦截器链应用到HTTP请求
  let applySuccess = interceptorChain.apply(httpRequest);
  if (!applySuccess) {
    console.error('Failed to apply interceptor chain');
  }
} catch (e) {
  console.error(`Interceptor chain add failed: code=${e.code}, message=${e.message}`);
}

// 发起HTTP请求。如需使用拦截，仅支持通过request接口发起请求
httpRequest.request("EXAMPLE_URL", {
  method: http.RequestMethod.GET,
  header: { 'Content-Type': 'application/json' }
}, (err: Error, data: http.HttpResponse) => {
  if (!err) {
    console.info('Request completed with response code: ' + data.responseCode);
  } else {
    console.error('Request failed: ' + JSON.stringify(err));
  }
  httpRequest.destroy();
});
```
## PathPreference<sup>23+</sup>

type PathPreference = 'auto' | 'primaryCellular' | 'secondaryCellular'

HTTP请求指定特定网络的类型枚举。

> **说明：**
>
> 推荐在网络并发等场景下使用。<br>
> 当指定的网络没有激活时，系统按照指定默认网络处理。

**系统能力**：SystemCapability.Communication.NetStack


| 类型   | 说明                                   |
| ------ | -------------------------------------- |
| 'auto' |表示HTTP请求指定默认的网络连接。|
| 'primaryCellular' |表示在蜂窝网络激活的场景下，HTTP请求指定默认的蜂窝网络连接。|
| 'secondaryCellular' |表示在双蜂窝网络激活的场景下，HTTP请求指定副卡的蜂窝网络连接。|

