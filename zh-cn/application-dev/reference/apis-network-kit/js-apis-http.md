# @ohos.net.http (数据请求)

本模块提供HTTP数据请求能力。应用可以通过HTTP发起一个数据请求，支持常见的GET、POST、OPTIONS、HEAD、PUT、DELETE、TRACE、CONNECT方法。

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
import { http } from '@kit.NetworkKit';
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

httpRequest.request(// 填写HTTP请求的URL地址，可以带参数也可以不带参数。URL地址需要开发者自定义。请求的参数可以在extraData中指定。
  "EXAMPLE_URL",
  {
    method: http.RequestMethod.POST, // 可选，默认为http.RequestMethod.GET。
    // 当使用POST请求时此字段用于传递请求体内容，具体格式与服务端协商确定。
    extraData: 'data to send',
    expectDataType: http.HttpDataType.STRING, // 可选，指定返回数据的类型。
    usingCache: true, // 可选，默认为true。
    priority: 1, // 可选，默认为1。
    // 开发者根据自身业务需要添加header字段，且header字段不支持传入map对象。
    header: { 'Accept' : 'application/json' },
    readTimeout: 60000, // 可选，默认为60000ms。
    connectTimeout: 60000, // 可选，默认为60000ms。
    usingProtocol: http.HttpProtocol.HTTP1_1, // 可选，协议类型默认值由系统自动指定。
    usingProxy: false, //可选，默认不使用网络代理，自API 10开始支持该属性。
    caPath: '/path/to/cacert.pem', // 可选，默认使用系统预设CA证书，自API 10开始支持该属性。
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
    addressFamily: http.AddressFamily.DEFAULT // 可选，系统默认选择目标域名的IPv4地址或IPv6地址，自API 15开始支持该属性。
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
      // 取消订阅HTTP响应头事件。
      httpRequest.off('headersReceive');
      // 当该请求使用完毕时，开发者务必调用destroy方法主动销毁该JavaScript Object。
      httpRequest.destroy();
    } else {
      console.error('error:' + JSON.stringify(err));
      // 取消订阅HTTP响应头事件。
      httpRequest.off('headersReceive');
      // 当该请求使用完毕时，开发者务必调用destroy方法主动销毁该JavaScript Object。
      httpRequest.destroy();
    }
  });
```

> **说明：**
> console.info()输出的数据中包含换行符会导致数据出现截断现象。
>
> 自API 12开始支持接收经过brotli算法压缩的HTTP响应。

## http.createHttp

createHttp(): HttpRequest

创建一个HTTP请求，里面包括发起请求、中断请求、订阅/取消订阅HTTP Response Header事件。当发起多个HTTP请求时，需为每个HTTP请求创建对应HttpRequest对象。每一个HttpRequest对象对应一个HTTP请求。

> **说明：**
> 当该请求使用完毕时，需调用destroy方法主动销毁HttpRequest对象，否则会出现资源泄露问题。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型        | 说明                                                         |
| :---------- | :----------------------------------------------------------- |
| HttpRequest | 返回一个HttpRequest对象，里面包括request、requestInStream、destroy、on和off方法。 |

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
>(1) 此接口仅支持数据大小为5M以内的数据接收，如果有超过5M的数据接收，需要主动在[HttpRequestOptions](#httprequestoptions)的maxLimit中进行设置，或者使用[requestInStream](#requestinstream10)接口发起流式请求。
><br>(2)如需传入cookies，请开发者自行在参数options中添加。
> <br>(3)若URL包含中文或其他语言，需先调用encodeURL(URL)编码，再发起请求。

**需要权限**：ohos.permission.INTERNET

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                           | 必填 | 说明                    |
| -------- | ---------------------------------------------- | ---- | ---------------------- |
| url      | string                                         | 是   | 发起网络请求的URL地址。 |
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
| 2300997 | Cleartext traffic not permitted.                               |
| 2300998 | It is not allowed to access this domain.                       |
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
> 此接口仅支持数据大小为5M以内的数据接收，如果有超过5M的数据接收，需要主动在HttpRequestOptions的maxLimit中进行设置。
>
> 如需传入cookies，请开发者自行在参数options中添加。

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
    usingProxy: false, //可选，默认不使用网络代理，自API 10开始支持该属性。
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
> 此接口仅支持数据大小为5M以内的数据接收，如果有超过5M的数据接收，需要主动在HttpRequestOptions的maxLimit中进行设置。
>
> 如需传入cookies，请开发者自行在参数options中添加。

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
| Promise<[HttpResponse](#httpresponse)> | 以Promise形式返回发起请求的结果。 |

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

中断请求任务。

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
| callback | AsyncCallback\<number\>       | 是   | 回调函数。                                      |

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
| 2300997 | Cleartext traffic not permitted.                               |
| 2300998 | It is not allowed to access this domain.                       |
| 2300999 | Internal error.                                                 |

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
| callback | AsyncCallback\<[number](#responsecode)\>       | 是   | 回调函数。                                      |

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
| 2300997 | Cleartext traffic not permitted.                               |
| 2300998 | It is not allowed to access this domain.                       |
| 2300999 | Internal error.                                                 |

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
    extraData: 'data to send',
    expectDataType: http.HttpDataType.STRING, // 可选，指定返回数据的类型。
    usingCache: true, // 可选，默认为true。
    priority: 1, // 可选，默认为1。
    // 开发者根据自身业务需要添加header字段。
    header: new Header('application/json'),
    readTimeout: 60000, // 可选，默认为60000ms。
    connectTimeout: 60000, // 可选，默认为60000ms。
    usingProtocol: http.HttpProtocol.HTTP1_1, // 可选，协议类型默认值由系统自动指定。
    usingProxy: false, //可选，默认不使用网络代理，自API 10开始支持该属性。
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
| Promise\<[number](#responsecode)\> | 以Promise形式返回发起请求的结果。 |

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

### on("headerReceive")<sup>(deprecated)</sup>

on(type: "headerReceive", callback: AsyncCallback\<Object\>): void

订阅HTTP Response Header 事件。

> **说明：**
> 从API version 6开始支持，从API version 8开始废弃，建议使用[on("headersReceive")<sup>8+</sup>](#onheadersreceive8)替代。

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
> 从API version 6开始支持，从API version 8开始废弃，建议使用[off("headersReceive")<sup>8+</sup>](#offheadersreceive8)替代。

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
| type     | string             | 是   | 订阅的事件类型：'headersReceive'。 |
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
| callback | Callback\<ArrayBuffer\> | 是   | 回调函数。当订阅成功时，error为undefined，data为获取到的HTTP流式数据接收数据，类型为ArrayBuffer；否则为错误对象。 |

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

| 名称         | 类型                                          | 必填 | 说明                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
| -------------- | --------------------------------------------- | ---- |----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| method         | [RequestMethod](#requestmethod)               | 否   | 请求方式，默认为GET。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
| extraData      | string \| Object \| ArrayBuffer | 否   | 发送请求的额外数据，默认无此字段。<br />1. 当HTTP请求为POST、PUT等方法时，此字段为HTTP请求的content，以UTF-8编码形式作为请求体。<br />示例如下：<br />  (1) 当'content-Type'为'application/x-www-form-urlencoded'时，请求提交的信息主体数据必须在key和value进行URL转码后（encodeURIComponent/encodeURI），按照键值对"key1=value1&key2=value2&key3=value3"的方式进行编码，该字段对应的类型通常为String。<br />(2) 当'content-Type'为'text/xml'时，该字段对应的类型通常为String。<br />(3) 当'content-Type'为'application/json'时，该字段对应的类型通常为Object。<br />(4) 当'content-Type'为'application/octet-stream'时，该字段对应的类型通常为ArrayBuffer。<br />(5) 当'content-Type'为'multipart/form-data'且需上传的字段为文件时，该字段对应的类型通常为ArrayBuffer。<br>以上信息仅供参考，并可能根据具体情况有所不同。<br />2. 当HTTP请求为GET、OPTIONS、DELETE、TRACE、CONNECT等方法时，此字段为HTTP请求参数的补充。开发者需传入Encode编码后的string类型参数，Object类型的参数无需预编码，参数内容会拼接到URL中进行发送。ArrayBuffer类型的参数不会做拼接处理。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| expectDataType<sup>9+</sup>  | [HttpDataType](#httpdatatype9)  | 否   | 指定返回数据的类型，默认无此字段。如果设置了此参数，系统将优先返回指定的类型。当指定其类型为Object时，最大长度为65536字符数。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| usingCache<sup>9+</sup>      | boolean                         | 否   | 是否使用缓存，true表示请求时优先读取缓存，false表示不使用缓存；默认为true，请求时优先读取缓存。缓存跟随当前进程生效，新缓存会替换旧缓存。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |
| priority<sup>9+</sup>        | number                          | 否   | HTTP/HTTPS请求并发优先级，值越大优先级越高，范围[1,1000]，默认为1。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |
| header                       | Object                          | 否   | HTTP请求头字段。当请求方式为"POST" "PUT" "DELETE" 或者""时，默认{'content-Type': 'application/json'}， 否则默认{'content-Type': 'application/x-www-form-urlencoded'}。<br />如果head中包含number类型的字段，最大支持int64的整数。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| readTimeout                  | number                          | 否   | 读取超时时间。单位为毫秒（ms），默认为60000ms。传入值需为uint32_t范围内的整数。<br />设置为0表示不会出现超时情况。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| connectTimeout               | number                          | 否   | 连接超时时间。单位为毫秒（ms），默认为60000ms。传入值需为uint32_t范围内的整数。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
| usingProtocol<sup>9+</sup>   | [HttpProtocol](#httpprotocol9)  | 否   | 使用协议。默认值由系统自动指定。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
| usingProxy<sup>10+</sup>     | boolean \| [HttpProxy](js-apis-net-connection.md#httpproxy10)               | 否   | HTTP代理配置，该项不配置时表示不使用代理。<br />- 当usingProxy为布尔类型true时，使用默认网络代理，为false时，不使用代理。<br />- 当usingProxy为HttpProxy类型时，使用指定网络代理。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| caPath<sup>10+</sup>     | string               | 否   | 如果设置了此参数，系统将使用用户指定路径的CA证书（开发者需保证该路径下CA证书的可访问性），否则将使用系统预设CA证书。<br />系统预设CA证书位置：/etc/ssl/certs/cacert.pem。证书路径为沙箱映射路径（开发者可通过UIAbilityContext提供的能力获取应用沙箱路径）。目前仅支持后缀名为.pem的文本格式证书。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
| resumeFrom<sup>11+</sup> | number | 否 | 用于设置下载起始位置，该参数只能用于GET方法，不能用于其他。HTTP标准（RFC 7233第3.1节）允许服务器忽略范围请求。<br />- 使用HTTP PUT时，不能使用该选项，因为该选项可能与其他选项冲突。<br />- 取值范围是：[1，4294967296（4GB）]，超出范围则不生效。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| resumeTo<sup>11+</sup> | number | 否 | 用于设置下载结束位置，该参数只能用于GET方法，不能用于其他。HTTP标准（RFC 7233第3.1节）允许服务器忽略范围请求。<br />- 使用HTTP PUT时，不能使用该选项，因为该选项可能与其他选项冲突。<br />- 取值范围是：[1，4294967296（4GB）]，超出范围则不生效。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| clientCert<sup>11+</sup> | [ClientCert](#clientcert11) | 否 | 支持传输客户端证书。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| dnsOverHttps<sup>11+</sup> | string | 否 | 设置使用HTTPS协议的服务器进行DNS解析。<br />- 参数必须以以下格式进行URL编码："https:// host:port/path"。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| dnsServers<sup>11+</sup> | Array\<string\> | 否 | 设置指定的DNS服务器进行DNS解析。<br />- 最多可以设置3个DNS解析服务器。如果有3个以上，只取前3个。<br />- 服务器必须是IPV4或者IPV6地址。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| maxLimit<sup>11+</sup>   | number   | 否 | 响应消息的最大字节限制。<br />默认值为5\*1024\*1024，以字节为单位。最大值为100\*1024\*1024，以字节为单位。<br />                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
| multiFormDataList<sup>11+</sup> | Array<[MultiFormData](#multiformdata11)> | 否 | 当'content-Type'为'multipart/form-data'时，则上传该字段定义的数据字段表单列表。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| certificatePinning<sup>12+</sup> | [CertificatePinning](#certificatepinning12) \| CertificatePinning[] | 否 | 支持动态设置证书锁定配置，可以传入单个或多个证书PIN码。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |
| addressFamily<sup>15+</sup> | [AddressFamily](#addressfamily15) | 否 | 支持解析目标域名时限定地址类型。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |
| remoteValidation<sup>18+</sup> | [RemoteValidation](#remotevalidation18)                             | 否 | 证书颁发机构（CA），用于验证远程服务器的身份。如果未设置此字段，系统CA将用于验证远程服务器的标识。<br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| tlsOptions<sup>18+</sup> | [TlsOptions](#tlsoptions18)                                         | 否 | TLS配置。<br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| serverAuthentication<sup>18+</sup> | [ServerAuthentication](#serverauthentication18)                     | 否 | 安全连接期间的服务器身份验证配置。默认不认证。<br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |

## RequestMethod

HTTP 请求方法。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

| 名称    | 值      | 说明                |
| :------ | ------- | :------------------ |
| OPTIONS | "OPTIONS" | OPTIONS方法描述了目标资源的通信选项。 |
| GET     | "GET"     | GET方法请求指定资源的表示。使用GET的请求应该只检索数据，不应该包含请求内容。 |
| HEAD    | "HEAD"    | HEAD方法请求与GET请求相同的响应，但没有响应主体。 |
| POST    | "POST"    | POST方法将实体提交给指定的资源，通常会导致服务器上的状态更改。 |
| PUT     | "PUT"     | PUT方法将目标资源的所有当前表示替换为请求内容。 |
| DELETE  | "DELETE"  | DELETE方法用于删除指定的资源。 |
| TRACE   | "TRACE"   | TRACE方法沿到达目标资源的路径执行消息环回测试。 |
| CONNECT | "CONNECT" | CONNECT方法建立到由目标资源标识的服务器的隧道。 |

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
| VERSION           | 505  | 服务器请求的HTTP协议的版本。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                 |

## HttpResponse

request方法回调函数的返回值类型。

**系统能力**：SystemCapability.Communication.NetStack

| 名称                 | 类型                                         | 必填 | 说明                                                          |
| -------------------- | -------------------------------------------- | ---- | ------------------------------------------------------------ |
| result               | string \| Object \| ArrayBuffer | 是   | HTTP请求根据响应头中content-type类型返回对应的响应格式内容，若HttpRequestOptions无expectDataType字段，按如下规则返回：<br />- application/json：返回JSON格式的字符串。<br />- application/octet-stream：ArrayBuffer。<br />- image：ArrayBuffer。<br />- 其他：string。<br /> 若HttpRequestOption有expectDataType字段，开发者需传入与服务器返回类型相同的数据类型。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| resultType<sup>9+</sup> | [HttpDataType](#httpdatatype9)             | 是   | 返回值类型。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                           |
| responseCode         | [ResponseCode](#responsecode) \| number      | 是   | 回调函数执行成功时，此字段为[ResponseCode](#responsecode)。若执行失败，错误码将会从AsyncCallback中的err字段返回。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| header               | Object                                       | 是   | 发起HTTP请求返回来的响应头。当前返回的是JSON格式字符串，如需具体字段内容，需开发者自行解析。常见字段及解析方式如下：<br/>- content-type：header['content-type']。<br />- status-line：header['status-line']。<br />- date：header.date/header['date']。<br />- server：header.server/header['server']。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| cookies<sup>8+</sup> | string                                       | 是   | 服务器返回的原始cookies。开发者可自行处理。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。               |
| performanceTiming<sup>11+</sup> | [PerformanceTiming](#performancetiming11) | 是 | HTTP请求的各个阶段的耗时。|

## ClientCert<sup>11+</sup>

客户端证书类型。

**系统能力**：SystemCapability.Communication.NetStack

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------| --- | ----------- |
| certPath | string | 是 | 证书路径。 |
| certType | [CertType](#certtype11) | 否 | 证书类型，默认是PEM。 |
| keyPath | string | 是 | 证书密钥的路径。 |
| keyPassword | string | 否  | 证书密钥的密码。默认值为空字符串。 |

## PerformanceTiming<sup>11+</sup>

性能打点(单位：毫秒)。

**系统能力**：SystemCapability.Communication.NetStack

| 名称       | 类型   | 必填   | 说明                   |
| ---------- | ------ | ---- | --------------------- |
| dnsTiming  | number | 是   | 从[request](#request)请求到DNS解析完成耗时。 |
| tcpTiming  | number | 是   | 从[request](#request)请求到TCP连接完成耗时。 |
| tlsTiming  | number | 是   | 从[request](#request)请求到TLS连接完成耗时。 |
| firstSendTiming  | number | 是   | 从[request](#request)请求到开始发送第一个字节的耗时。 |
| firstReceiveTiming  | number | 是   | 从[request](#request)请求到接收第一个字节的耗时。 |
| totalFinishTiming  | number | 是   | 从[request](#request)请求到完成请求的耗时。 |
| redirectTiming  | number | 是   | 从[request](#request)请求到完成所有重定向步骤的耗时。 |
| responseHeaderTiming  | number | 是   | 从[request](#request)请求到header解析完成的耗时。 |
| responseBodyTiming  | number | 是   | 从[request](#request)请求到body解析完成的耗时。 |
| totalTiming  | number | 是   | 从[request](#request)请求回调到应用程序的耗时。 |

## DataReceiveProgressInfo<sup>11+</sup>

数据接收信息。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

| 名称 | 类型 | 必填 | 说明                |
| ---- | ---- | ---- |-------------------|
|  receiveSize        | number | 是  | 已接收的数据量（单位：字节）。   |
| totalSize| number | 是 | 总共要接收的数据量（单位：字节）。 |

## DataSendProgressInfo<sup>11+</sup>

数据发送信息。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

### 属性

| 名称 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| sendSize        | number | 是  | 每次发送的数据量(单位：字节)。  |
| totalSize | number | 是 | 总共要发送的数据量(单位：字节)。 |

## MultiFormData<sup>11+</sup>

多部分表单数据的类型。

**系统能力**：SystemCapability.Communication.NetStack

| 名称 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| name        | string | 是  | 数据名称。                                                                      |
| contentType | string | 是 | 数据类型，如'text/plain'，'image/png', 'image/jpeg', 'audio/mpeg', 'video/mp4'等。 |
| remoteFileName | string | 否 | 上传到服务器保存为文件的名称。                                                 |
| data | string \| Object \| ArrayBuffer | 否 | 表单数据内容。                                                 |
| filePath | string | 否 | 此参数根据文件的内容设置mime部件的正文内容。用于代替data将文件数据设置为数据内容，如果data为空，则必须设置filePath。如果data有值，则filePath不会生效。|

## http.createHttpResponseCache<sup>9+</sup>

createHttpResponseCache(cacheSize?: number): HttpResponseCache

创建一个HttpResponseCache对象，可用于存储HTTP请求的响应数据。对象中可调用[flush](#flush9)与[delete](#delete9)方法，cacheSize指定缓存大小。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| cacheSize | number | 否 | 缓存大小。最大为10\*1024\*1024（10MB），默认最大。 |

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
    // 当该请求使用完毕时，开发者务必调用destroy方法主动销毁该JavaScript Object。
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
  console.error("errocode" + JSON.stringify(error));
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
    console.log("success");
  }).catch((err: BusinessError) => {
    console.error("fail");
  });
  httpRequest.destroy();
}).catch((error: BusinessError) => {
  console.error("errocode" + JSON.stringify(error));
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

|  名称  |  类型  |  必填  |说明     |
| ------------------  |---- |-- | ----------- |
| publicKeyHash       | string | 是 |字符串类型的证书PIN码。 |
| hashAlgorithm        | 'SHA-256' |  是  |加密算法，当前仅支持该算法。 |

## HttpProxy<sup>10+</sup>

type HttpProxy = connection.HttpProxy

网络代理配置信息。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

|       类型       |            说明             |
| ---------------- | --------------------------- |
| connection.HttpProxy | 网络代理配置信息。     |

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
| cipherSuites        | [CipherSuite](#ciphersuite18)[] | 否      |是       | 声明加密套件类型的数组。 |

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
| TlsOptions | 表示使用自定义的TLS版本号和加密套件。 |

## RemoteValidation<sup>18+</sup>

type RemoteValidation = 'system' | 'skip'

验证远程服务器身份的方式。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

| 类型                         | 说明                                                                                 |
|-------------------------------|------------------------------------------------------------------------------------|
| 'system'  | 表示使用系统CA验证远端服务器身份，值固定为'system'字符串，是未配置时的默认值。 |
| 'skip'   | 表示跳过验证远端服务器身份流程，值固定为'skip'字符串。 |

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