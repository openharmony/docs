# @ohos.net.http (数据请求)

本模块提供HTTP数据请求能力。应用可以通过HTTP发起一个数据请求，支持常见的GET、POST、OPTIONS、HEAD、PUT、DELETE、TRACE、CONNECT方法。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> **建议使用[Remote Communication Kit](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/remote-communication-kit-guide-V5)进行HTTP请求，Remote Communication Kit将持续演进。**
## 导入模块

```ts
import { http } from '@kit.NetworkKit';
```

## 完整示例

```ts
// 引入包名
import { http } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 每一个httpRequest对应一个HTTP请求任务，不可复用
let httpRequest = http.createHttp();
// 用于订阅HTTP响应头，此接口会比request请求先返回。可以根据业务需要订阅此消息
// 从API 8开始，使用on('headersReceive', Callback)替代on('headerReceive', AsyncCallback)。 8+
httpRequest.on('headersReceive', (header: Object) => {
  console.info('header: ' + JSON.stringify(header));
});

httpRequest.request(// 填写HTTP请求的URL地址，可以带参数也可以不带参数。URL地址需要开发者自定义。请求的参数可以在extraData中指定
  "EXAMPLE_URL",
  {
    method: http.RequestMethod.POST, // 可选，默认为http.RequestMethod.GET
    // 当使用POST请求时此字段用于传递请求体内容，具体格式与服务端协商确定
    extraData: 'data to send',
    expectDataType: http.HttpDataType.STRING, // 可选，指定返回数据的类型
    usingCache: true, // 可选，默认为true
    priority: 1, // 可选，默认为1
    // 开发者根据自身业务需要添加header字段
    header: { 'Accept' : 'application/json' },
    readTimeout: 60000, // 可选，默认为60000ms
    connectTimeout: 60000, // 可选，默认为60000ms
    usingProtocol: http.HttpProtocol.HTTP1_1, // 可选，协议类型默认值由系统自动指定
    usingProxy: false, //可选，默认不使用网络代理，自API 10开始支持该属性
    caPath: '/path/to/cacert.pem', // 可选，默认使用系统预设CA证书，自API 10开始支持该属性
    clientCert: { // 可选，默认不使用客户端证书，自API 11开始支持该属性
      certPath: '/path/to/client.pem', // 默认不使用客户端证书，自API 11开始支持该属性
      keyPath: '/path/to/client.key', // 若证书包含Key信息，传入空字符串，自API 11开始支持该属性
      certType: http.CertType.PEM, // 可选，默认使用PEM，自API 11开始支持该属性
      keyPassword: "passwordToKey" // 可选，输入key文件的密码，自API 11开始支持该属性
    },
    certificatePinning: [ // 可选，支持证书锁定配置信息的动态设置，自API 12开始支持该属性
      {
        publicKeyHash: 'Pin1', // 由应用传入的证书PIN码，自API 12开始支持该属性
        hashAlgorithm: 'SHA-256' // 加密算法，当前仅支持SHA-256，自API 12开始支持该属性
      }, {
        publicKeyHash: 'Pin2', // 由应用传入的证书PIN码，自API 12开始支持该属性
        hashAlgorithm: 'SHA-256' // 加密算法，当前仅支持SHA-256，自API 12开始支持该属性
      }
    ],
    multiFormDataList: [ // 可选，仅当Header中，'content-Type'为'multipart/form-data'时生效，自API 11开始支持该属性
      {
        name: "Part1", // 数据名，自API 11开始支持该属性
        contentType: 'text/plain', // 数据类型，自API 11开始支持该属性
        data: 'Example data', // 可选，数据内容，自API 11开始支持该属性
        remoteFileName: 'example.txt' // 可选，自API 11开始支持该属性
      }, {
        name: "Part2", // 数据名，自API 11开始支持该属性
        contentType: 'text/plain', // 数据类型，自API 11开始支持该属性
        // data/app/el2/100/base/com.example.myapplication/haps/entry/files/fileName.txt
        filePath: `${getContext(this).filesDir}/fileName.txt`, // 可选，传入文件路径，自API 11开始支持该属性
        remoteFileName: 'fileName.txt' // 可选，自API 11开始支持该属性
      }
    ]
  },
  (err: BusinessError, data: http.HttpResponse) => {
    if (!err) {
      // data.result为HTTP响应内容，可根据业务需要进行解析
      console.info('Result:' + JSON.stringify(data.result));
      console.info('code:' + JSON.stringify(data.responseCode));
      console.info('type:' + JSON.stringify(data.resultType));
      // data.header为HTTP响应头，可根据业务需要进行解析
      console.info('header:' + JSON.stringify(data.header));
      console.info('cookies:' + JSON.stringify(data.cookies)); // 自API version 8开始支持cookie
      // 取消订阅HTTP响应头事件
      httpRequest.off('headersReceive');
      // 当该请求使用完毕时，开发者务必调用destroy方法主动销毁该JavaScript Object。
      httpRequest.destroy();
    } else {
      console.info('error:' + JSON.stringify(err));
      // 取消订阅HTTP响应头事件
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

创建一个HTTP请求，里面包括发起请求、中断请求、订阅/取消订阅HTTP Response Header事件。每一个HttpRequest对象对应一个HTTP请求。如需发起多个HTTP请求，须为每个HTTP请求创建对应HttpRequest对象。

> **说明：**
> 当该请求使用完毕时，须调用destroy方法主动销毁HttpRequest对象。

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

HTTP请求任务。在调用HttpRequest的方法前，需要先通过createHttp()创建一个任务。

### request

request(url: string, callback: AsyncCallback\<HttpResponse\>): void

根据URL地址，发起HTTP网络请求，使用callback方式作为异步方法。

> **说明：**
> 此接口仅支持数据大小为5M以内的数据接收。
> 若url包含中文或其他语言，需先调用encodeURL(url)编码，再发起请求。

**需要权限**：ohos.permission.INTERNET

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                           | 必填 | 说明                    |
| -------- | ---------------------------------------------- | ---- | ---------------------- |
| url      | string                                         | 是   | 发起网络请求的URL地址。 |
| callback | AsyncCallback\<[HttpResponse](#httpresponse)\> | 是   | 回调函数。    |

**错误码：**

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
| 2300998 | It is not allowed to access this domain.                       |
| 2300999 | Unknown error.                                                 |

> **错误码说明：**
> 以上错误码的详细介绍参见[通用错误码](../errorcode-universal.md)和[HTTP错误码](errorcode-net-http.md)。
> HTTP 错误码映射关系：2300000 + curl错误码。更多常用错误码，可参考：[curl错误码](https://curl.se/libcurl/c/libcurl-errors.html)

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
    console.info('cookies:' + data.cookies); // 自API version 8开始支持cookie
  } else {
    console.info('error:' + JSON.stringify(err));
  }
});
```

### request

request(url: string, options: HttpRequestOptions, callback: AsyncCallback\<HttpResponse\>):void

根据URL地址和相关配置项，发起HTTP网络请求，使用callback方式作为异步方法。

> **说明：**
> 此接口仅支持数据大小为5M以内的数据接收。
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
| callback | AsyncCallback\<[HttpResponse](#httpresponse)\> | 是   | 回调函数。                            |

**错误码：**

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
| 2300998 | It is not allowed to access this domain.                       |
| 2300999 | Unknown error.                                                 |

> **错误码说明：**
> 以上错误码的详细介绍参见[通用错误码](../errorcode-universal.md)和[HTTP错误码](errorcode-net-http.md)。
> HTTP 错误码映射关系：2300000 + curl错误码。更多常用错误码，可参考：[curl错误码](https://curl.se/libcurl/c/libcurl-errors.html)

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
    method: http.RequestMethod.POST, // 可选，默认为http.RequestMethod.GET
    // 当使用POST请求时此字段用于传递请求体内容，具体格式与服务端协商确定
    extraData: 'data to send',
    expectDataType: http.HttpDataType.STRING, // 可选，指定返回数据的类型
    usingCache: true, // 可选，默认为true
    priority: 1, // 可选，默认为1
    // 开发者根据自身业务需要添加header字段
    header: new Header('application/json'),
    readTimeout: 60000, // 可选，默认为60000ms
    connectTimeout: 60000, // 可选，默认为60000ms
    usingProtocol: http.HttpProtocol.HTTP1_1, // 可选，协议类型默认值由系统自动指定
    usingProxy: false, //可选，默认不使用网络代理，自API 10开始支持该属性
};

httpRequest.request("EXAMPLE_URL", options, (err: Error, data: http.HttpResponse) => {
  if (!err) {
    console.info('Result:' + data.result);
    console.info('code:' + data.responseCode);
    console.info('type:' + JSON.stringify(data.resultType));
    console.info('header:' + JSON.stringify(data.header));
    console.info('cookies:' + data.cookies); // 自API version 8开始支持cookie
  } else {
    console.info('error:' + JSON.stringify(err));
  }
});
```

### request

request(url: string, options? : HttpRequestOptions): Promise\<HttpResponse\>

根据URL地址，发起HTTP网络请求，使用Promise方式作为异步方法。

> **说明：**
> 此接口仅支持数据大小为5M以内的数据接收。
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
| 2300998 | It is not allowed to access this domain.                       |
| 2300999 | Unknown error.                                                 |

> **错误码说明：**
> 以上错误码的详细介绍参见[通用错误码](../errorcode-universal.md)和[HTTP错误码](errorcode-net-http.md)。
> HTTP 错误码映射关系：2300000 + curl错误码。更多常用错误码，可参考：[curl错误码](https://curl.se/libcurl/c/libcurl-errors.html)

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
  console.info('cookies:' + data.cookies); // 自API version 8开始支持cookie
  console.info('header.content-Type:' + data.header);
  console.info('header.Status-Line:' + data.header);
}).catch((err:Error) => {
  console.info('error:' + JSON.stringify(err));
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

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                           | 必填 | 说明                                            |
| -------- | ---------------------------------------------- | ---- | ----------------------------------------------- |
| url      | string                                         | 是   | 发起网络请求的URL地址。                         |
| callback | AsyncCallback\<number\>       | 是   | 回调函数。                                      |

**错误码：**

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
| 2300998 | It is not allowed to access this domain.                       |
| 2300999 | Unknown error.                                                 |

> **错误码说明：**
> 以上错误码的详细介绍参见[通用错误码](../errorcode-universal.md)和[HTTP错误码](errorcode-net-http.md)。
> HTTP 错误码映射关系：2300000 + curl错误码。更多常用错误码，可参考：[curl错误码](https://curl.se/libcurl/c/libcurl-errors.html)

**示例：**

```ts
import { http } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let httpRequest = http.createHttp();
httpRequest.requestInStream("EXAMPLE_URL", (err: BusinessError, data: number) => {
  if (!err) {
    console.info("requestInStream OK! ResponseCode is " + JSON.stringify(data));
  } else {
    console.info("requestInStream ERROR : err = " + JSON.stringify(err));
  }
})
```

### requestInStream<sup>10+</sup>

requestInStream(url: string, options: HttpRequestOptions, callback: AsyncCallback\<number\>): void

根据URL地址和相关配置项，发起HTTP网络请求并返回流式响应，使用callback方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                           | 必填 | 说明                                            |
| -------- | ---------------------------------------------- | ---- | ----------------------------------------------- |
| url      | string                                         | 是   | 发起网络请求的URL地址。                         |
| options  | HttpRequestOptions                             | 是   | 参考[HttpRequestOptions](#httprequestoptions)。 |
| callback | AsyncCallback\<[number](#responsecode)\>       | 是   | 回调函数。                                      |

**错误码：**

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
| 2300998 | It is not allowed to access this domain.                       |
| 2300999 | Unknown error.                                                 |

> **错误码说明：**
> 以上错误码的详细介绍参见[通用错误码](../errorcode-universal.md)和[HTTP错误码](errorcode-net-http.md)。
> HTTP 错误码映射关系：2300000 + curl错误码。更多常用错误码，可参考：[curl错误码](https://curl.se/libcurl/c/libcurl-errors.html)

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
    method: http.RequestMethod.POST, // 可选，默认为http.RequestMethod.GET
    // 当使用POST请求时此字段用于传递请求体内容，具体格式与服务端协商确定
    extraData: 'data to send',
    expectDataType: http.HttpDataType.STRING, // 可选，指定返回数据的类型
    usingCache: true, // 可选，默认为true
    priority: 1, // 可选，默认为1
    // 开发者根据自身业务需要添加header字段
    header: new Header('application/json'),
    readTimeout: 60000, // 可选，默认为60000ms
    connectTimeout: 60000, // 可选，默认为60000ms
    usingProtocol: http.HttpProtocol.HTTP1_1, // 可选，协议类型默认值由系统自动指定
    usingProxy: false, //可选，默认不使用网络代理，自API 10开始支持该属性
};
httpRequest.requestInStream("EXAMPLE_URL", options, (err: BusinessError<void> , data: number) => {
  if (!err) {
    console.info("requestInStream OK! ResponseCode is " + JSON.stringify(data));
  } else {
    console.info("requestInStream ERROR : err = " + JSON.stringify(err));
  }
})
```

### requestInStream<sup>10+</sup>

requestInStream(url: string, options? : HttpRequestOptions): Promise\<number\>

根据URL地址，发起HTTP网络请求并返回流式响应，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

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
| 2300998 | It is not allowed to access this domain.                       |
| 2300999 | Unknown error.                                                 |

> **错误码说明：**
> 以上错误码的详细介绍参见[通用错误码](../errorcode-universal.md)和[HTTP错误码](errorcode-net-http.md)。
> HTTP 错误码映射关系：2300000 + curl错误码。更多常用错误码，可参考：[curl错误码](https://curl.se/libcurl/c/libcurl-errors.html)

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
  console.info("requestInStream ERROR : err = " + JSON.stringify(err));
});
```

### on("headerReceive")<sup>(deprecated)</sup>

on(type: "headerReceive", callback: AsyncCallback\<Object\>): void

订阅HTTP Response Header 事件。

> **说明：**
> 此接口已废弃，建议使用[on("headersReceive")<sup>8+</sup>](#onheadersreceive8)替代。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                    | 必填 | 说明                              |
| -------- | ----------------------- | ---- | --------------------------------- |
| type     | string                  | 是   | 订阅的事件类型，'headerReceive'。 |
| callback | AsyncCallback\<Object\> | 是   | 回调函数。                        |

**示例：**

```ts
import { http } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let httpRequest = http.createHttp();
httpRequest.on("headerReceive", (data: BusinessError) => {
  console.info("error:" + JSON.stringify(data));
});
```

### off("headerReceive")<sup>(deprecated)</sup>

off(type: "headerReceive", callback?: AsyncCallback\<Object\>): void

取消订阅HTTP Response Header 事件。

> **说明：**
>
>1. 此接口已废弃，建议使用[off("headersReceive")<sup>8+</sup>](#offheadersreceive8)替代。
>
>2. 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                  |
| -------- | ----------------------- | ---- | ------------------------------------- |
| type     | string                  | 是   | 取消订阅的事件类型，'headerReceive'。 |
| callback | AsyncCallback\<Object\> | 否   | 回调函数。                            |

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

| 参数名   | 类型               | 必填 | 说明                               |
| -------- | ------------------ | ---- | ---------------------------------- |
| type     | string             | 是   | 订阅的事件类型：'headersReceive'。 |
| callback | Callback\<Object\> | 是   | 回调函数。                         |

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

> **说明：**
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型               | 必填 | 说明                                   |
| -------- | ------------------ | ---- | -------------------------------------- |
| type     | string             | 是   | 取消订阅的事件类型：'headersReceive'。 |
| callback | Callback\<Object\> | 否   | 回调函数。                             |

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

订阅HTTP Response Header 事件，但是只触发一次。一旦触发之后，订阅器就会被移除。使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型               | 必填 | 说明                               |
| -------- | ------------------ | ---- | ---------------------------------- |
| type     | string             | 是   | 订阅的事件类型：'headersReceive'。 |
| callback | Callback\<Object\> | 是   | 回调函数。                         |

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

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                    | 必填 | 说明                              |
| -------- | ----------------------- | ---- | --------------------------------- |
| type     | string                  | 是   | 订阅的事件类型，'dataReceive'。 |
| callback | AsyncCallback\<ArrayBuffer\> | 是   | 回调函数。                        |

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

> **说明：**
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型               | 必填 | 说明                                   |
| -------- | ------------------ | ---- | -------------------------------------- |
| type     | string             | 是   | 取消订阅的事件类型：'dataReceive'。 |
| callback | Callback\<ArrayBuffer\> | 否   | 回调函数。                             |

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

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                    | 必填 | 说明                              |
| -------- | ----------------------- | ---- | --------------------------------- |
| type     | string                  | 是   | 订阅的事件类型，'dataEnd'。 |
| callback | AsyncCallback\<void\>   | 是   | 回调函数。                        |

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

> **说明：**
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型               | 必填 | 说明                                   |
| -------- | ------------------ | ---- | -------------------------------------- |
| type     | string             | 是   | 取消订阅的事件类型：'dataEnd'。 |
| callback | Callback\<void\>   | 否   | 回调函数。                             |

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

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                    | 必填 | 说明                              |
| -------- | ----------------------- | ---- | --------------------------------- |
| type     | string                  | 是   | 订阅的事件类型，'dataReceiveProgress'。 |
| callback | AsyncCallback\<[DataReceiveProgressInfo](#datareceiveprogressinfo11)\>   | 是   | 回调函数。返回数据接收进度信息。 |

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

> **说明：**
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型               | 必填 | 说明                                   |
| -------- | ------------------ | ---- | -------------------------------------- |
| type     | string             | 是   | 取消订阅的事件类型：'dataReceiveProgress'。 |
| callback | Callback\<[DataReceiveProgressInfo](#datareceiveprogressinfo11)\>   | 否   | 回调函数。 返回数据接收进度信息。    |

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

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                    | 必填 | 说明                              |
| -------- | ----------------------- | ---- | --------------------------------- |
| type     | string                  | 是   | 订阅的事件类型，'dataSendProgress'。 |
| callback | AsyncCallback\<[DataSendProgressInfo](#datasendprogressinfo11)\>   | 是   | 回调函数。返回数据发送进度信息。|

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

> **说明：**
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型               | 必填 | 说明                                   |
| -------- | ------------------ | ---- | -------------------------------------- |
| type     | string             | 是   | 取消订阅的事件类型：'dataSendProgress'。 |
| callback | Callback\<[DataSendProgressInfo](#datasendprogressinfo11)\>  | 否 | 回调函数。返回数据接发送进度信息。 |

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

发起请求可选参数的类型和取值范围。

**系统能力**：SystemCapability.Communication.NetStack

| 名称         | 类型                                          | 必填 | 说明                                                         |
| -------------- | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| method         | [RequestMethod](#requestmethod)               | 否   | 请求方式，默认为GET。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                   |
| extraData      | string \| Object \| ArrayBuffer | 否   | 发送请求的额外数据，默认无此字段。<br />当HTTP请求为POST、PUT等方法时，此字段为HTTP请求的content，以UTF-8编码形式作为请求体。当'content-Type'为'application/x-www-form-urlencoded'时，请求提交的信息主体数据必须在key和value进行URL转码后(encodeURIComponent/encodeURI)，按照键值对"key1=value1&key2=value2&key3=value3"的方式进行编码，该字段对应的类型通常为String；当'content-Type'为'text/xml'时，该字段对应的类型通常为String；当'content-Type'为'application/json'时，该字段对应的类型通常为Object；当'content-Type'为'application/octet-stream'时，该字段对应的类型通常为ArrayBuffer；当'content-Type'为'multipart/form-data'且需上传的字段为文件时，该字段对应的类型通常为ArrayBuffer。以上信息仅供参考，并可能根据具体情况有所不同。<br />- 当HTTP请求为GET、OPTIONS、DELETE、TRACE、CONNECT等方法时，此字段为HTTP请求参数的补充。开发者需传入Encode编码后的string类型参数，Object类型的参数无需预编码，参数内容会拼接到URL中进行发送；ArrayBuffer类型的参数不会做拼接处理。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| expectDataType<sup>9+</sup>  | [HttpDataType](#httpdatatype9)  | 否   | 指定返回数据的类型，默认无此字段。如果设置了此参数，系统将优先返回指定的类型。当指定其类型为Object时，最大长度为65536 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| usingCache<sup>9+</sup>      | boolean                         | 否   | 是否使用缓存，默认为true，请求时优先读取缓存。 缓存跟随当前进程生效。新缓存会替换旧缓存。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。  |
| priority<sup>9+</sup>        | number                          | 否   | http/https请求并发优先级，值越大优先级越高，范围[1,1000]，默认为1。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                           |
| header                       | Object                          | 否   | HTTP请求头字段。当请求方式为"POST" "PUT" "DELETE" 或者""时，默认{'content-Type': 'application/json'}， 否则默认{'content-Type': 'application/x-www-form-urlencoded'}。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。   |
| readTimeout                  | number                          | 否   | 读取超时时间。单位为毫秒（ms），默认为60000ms。<br />设置为0表示不会出现超时情况。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| connectTimeout               | number                          | 否   | 连接超时时间。单位为毫秒（ms），默认为60000ms。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。              |
| usingProtocol<sup>9+</sup>   | [HttpProtocol](#httpprotocol9)  | 否   | 使用协议。默认值由系统自动指定。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                             |
| usingProxy<sup>10+</sup>     | boolean \| [HttpProxy](js-apis-net-connection.md#httpproxy10)               | 否   | 是否使用HTTP代理，默认为false，不使用代理。<br />- 当usingProxy为布尔类型true时，使用默认网络代理。<br />- 当usingProxy为HttpProxy类型时，使用指定网络代理。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| caPath<sup>10+</sup>     | string               | 否   | 如果设置了此参数，系统将使用用户指定路径的CA证书，(开发者需保证该路径下CA证书的可访问性)，否则将使用系统预设CA证书，系统预设CA证书位置：/etc/ssl/certs/cacert.pem。证书路径为沙箱映射路径（开发者可通过getContext().filesDir获取应用沙箱路径）。目前仅支持后缀名为.pem的文本格式证书。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                             |
| resumeFrom<sup>11+</sup> | number | 否 | 用于设置下载起始位置，该参数只能用于GET方法，不要用于其他。HTTP标准（RFC 7233第3.1节）允许服务器忽略范围请求。<br />-使用HTTP PUT时，不应使用该选项，因为该选项可能与其他选项冲突。<br />-取值范围是:1~4294967296(4GB)，超出范围则不生效。 |
| resumeTo<sup>11+</sup> | number | 否 | 用于设置下载结束位置，该参数只能用于GET方法，不要用于其他。HTTP标准（RFC 7233第3.1节）允许服务器忽略范围请求。<br />-使用HTTP PUT时，不应使用该选项，因为该选项可能与其他选项冲突。<br />-取值范围是:1~4294967296(4GB)，超出范围则不生效。 |
| clientCert<sup>11+</sup> | [ClientCert](#clientcert11) | 否 | 支持传输客户端证书。 |
| dnsOverHttps<sup>11+</sup> | string | 否 | 设置使用https协议的服务器进行DNS解析。<br />-参数必须以以下格式进行URL编码："https:// host:port/path"。 |
| dnsServers<sup>11+</sup> | Array\<string\> | 否 | 设置指定的DNS服务器进行DNS解析。<br />-可以设置多个DNS解析服务器，最多3个服务器。如果有3个以上，只取前3个。<br />-服务器必须是IPV4或者IPV6地址。 |
| maxLimit<sup>11+</sup>   | number   | 否 | 响应消息的最大字节限制，默认值为5\*1024\*1024，以字节为单位。最大值为100\*1024\*1024，以字节为单位。  |
| multiFormDataList<sup>11+</sup> | Array<[MultiFormData](#multiformdata11)> | 否 | 当'content-Type'为'multipart/form-data'时，则上传该字段定义的数据字段表单列表。 |
| certificatePinning<sup>12+</sup> | [CertificatePinning](#certificatepinning12) \| CertificatePinning[] | 否 | 支持动态设置证书锁定配置，可以传入单个或多个证书PIN码。 |

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
| OK                | 200  | 请求成功。一般用于GET与POST请求。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                            |
| CREATED           | 201  | 已创建。成功请求并创建了新的资源。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                           |
| ACCEPTED          | 202  | 已接受。已经接受请求，但未处理完成。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                         |
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
| UNAUTHORIZED      | 401  | 请求要求用户的身份认证。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                     |
| PAYMENT_REQUIRED  | 402  | 保留，将来使用。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                             |
| FORBIDDEN         | 403  | 服务器理解请求客户端的请求，但是拒绝执行此请求。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。             |
| NOT_FOUND         | 404  | 服务器无法根据客户端的请求找到资源（网页）。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                 |
| BAD_METHOD        | 405  | 客户端请求中的方法被禁止。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                   |
| NOT_ACCEPTABLE    | 406  | 服务器无法根据客户端请求的内容特性完成请求。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                 |
| PROXY_AUTH        | 407  | 请求要求代理的身份认证。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                     |
| CLIENT_TIMEOUT    | 408  | 请求时间过长，超时。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                         |
| CONFLICT          | 409  | 服务器完成客户端的PUT请求是可能返回此代码，服务器处理请求时发生了冲突。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| GONE              | 410  | 客户端请求的资源已经不存在。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                 |
| LENGTH_REQUIRED   | 411  | 服务器无法处理客户端发送的不带Content-Length的请求信息。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。     |
| PRECON_FAILED     | 412  | 客户端请求信息的先决条件错误。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                               |
| ENTITY_TOO_LARGE  | 413  | 由于请求的实体过大，服务器无法处理，因此拒绝请求。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。           |
| REQ_TOO_LONG      | 414  | 请求的URI过长（URI通常为网址），服务器无法处理。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。             |
| UNSUPPORTED_TYPE  | 415  | 服务器无法处理请求的格式。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                   |
| RANGE_NOT_SATISFIABLE<sup>12+</sup> | 416  | 请求范围不符合要求。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                  |
| INTERNAL_ERROR    | 500  | 服务器内部错误，无法完成请求。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                               |
| NOT_IMPLEMENTED   | 501  | 服务器不支持请求的功能，无法完成请求。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                       |
| BAD_GATEWAY       | 502  | 充当网关或代理的服务器，从远端服务器接收到了一个无效的请求。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| UNAVAILABLE       | 503  | 由于超载或系统维护，服务器暂时的无法处理客户端的请求。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。       |
| GATEWAY_TIMEOUT   | 504  | 充当网关或代理的服务器，未及时从远端服务器获取请求。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。         |
| VERSION           | 505  | 服务器请求的HTTP协议的版本。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                 |

## HttpResponse

request方法回调函数的返回值类型。

**系统能力**：SystemCapability.Communication.NetStack

| 名称                 | 类型                                         | 必填 | 说明                                                          |
| -------------------- | -------------------------------------------- | ---- | ------------------------------------------------------------ |
| result               | string \| Object \| ArrayBuffer | 是   | HTTP请求根据响应头中content-type类型返回对应的响应格式内容，若HttpRequestOptions无expectDataType字段，按如下规则返回：<br />- application/json：返回JSON格式的字符串；<br />- application/octet-stream：ArrayBuffer；<br />- image：ArrayBuffer；<br />- 其他：string。<br /> 若HttpRequestOption有expectDataType字段，开发者需传入与服务器返回类型相同的数据类型。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| resultType<sup>9+</sup> | [HttpDataType](#httpdatatype9)             | 是   | 返回值类型。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                           |
| responseCode         | [ResponseCode](#responsecode) \| number      | 是   | 回调函数执行成功时，此字段为[ResponseCode](#responsecode)。若执行失败，错误码将会从AsyncCallback中的err字段返回。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| header               | Object                                       | 是   | 发起HTTP请求返回来的响应头。当前返回的是JSON格式字符串，如需具体字段内容，需开发者自行解析。常见字段及解析方式如下：<br/>- content-type：header['content-type']；<br />- status-line：header['status-line']；<br />- date：header.date/header['date']；<br />- server：header.server/header['server']；<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| cookies<sup>8+</sup> | string                                       | 是   | 服务器返回的原始cookies。开发者可自行处理。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。               |
| performanceTiming<sup>11+</sup> | [PerformanceTiming](#performancetiming11) | 是 | HTTP请求的各个阶段的耗时。|

## ClientCert<sup>11+</sup>

客户端证书类型。

**系统能力**：SystemCapability.Communication.NetStack

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------| --- | ----------- |
| certPath | string | 是 | 证书路径 |
| certType | [CertType](#certtype11) | 否 | 证书类型，默认是PEM |
| keyPath | string | 是 | 证书秘钥的路径 |
| keyPassword | string | 否  | 证书秘钥的密码 |

## PerformanceTiming<sup>11+</sup>

性能打点（单位：毫秒）。

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

数据接收信息

**系统能力**：SystemCapability.Communication.NetStack

| 名称 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
|  receiveSize        | number | 是  | 已接收的数据量（字节）。           |
| totalSize| number | 是 | 总共要接收的数据量（字节）|

## DataSendProgressInfo<sup>11+</sup>

数据发送信息

**系统能力**：SystemCapability.Communication.NetStack

### 属性

| 名称 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| sendSize        | number | 是  | 每次发送的数据量（字节）。  |
| totalSize | number | 是 | 总共要发送的数据量（字节）。 |

## MultiFormData<sup>11+</sup>

多部分表单数据的类型。

**系统能力**：SystemCapability.Communication.NetStack

| 名称 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| name        | string | 是  | 数据名称                                                                      |
| contentType | string | 是 | 数据类型，如'text/plain'，'image/png', 'image/jpeg', 'audio/mpeg', 'video/mp4'等 |
| remoteFileName | string | 否 | 上传到服务器保存为文件的名称。                                                 |
| data | string \| Object \| ArrayBuffer | 否 | 表单数据内容。                                                 |
| filePath | string | 否 | 此参数根据文件的内容设置mime部件的正文内容。用于代替data将文件数据设置为数据内容，如果data为空，则必须设置filePath。如果data有值，则filePath不会生效。|

## http.createHttpResponseCache<sup>9+</sup>

createHttpResponseCache(cacheSize?: number): HttpResponseCache

创建一个HttpResponseCache对象，可用于存储HTTP请求的响应数据。对象中可调用flush与delete方法，cacheSize指定缓存大小。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| cacheSize | number | 否 | 缓存大小最大为10\*1024\*1024（10MB），默认最大。 |

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

`Cache-Control`为通用报头，但通常是在服务器端进行的，它允许你定义一个响应资源应该何时、如何被缓存以及缓存多长时间。以下是一些常用的`Cache-Control`指令及其含义：

1. **`no-cache`**：表示在使用缓存前，必须先去源服务器校验资源的有效性。如果资源未变更，则响应状态码为304（Not Modified），不发送资源内容，使用缓存中的资源。如果资源已经过期，则响应状态码为200，并发送资源内容。

2. **`no-store`**：表示不允许缓存资源，每次请求都必须从服务器获取资源。

3. **`max-age`**：指定缓存的最大时间（以秒为单位）。例如，`Cache-Control: max-age=3600`表示缓存的有效期为1小时。

4. **`public`**：表明响应可以被任何对象（包括：发送请求的客户端，代理服务器等）缓存。

5. **`private`**：表明响应只能被单个用户缓存，不能作为共享缓存（即代理服务器不能缓存它）。

6. **`must-revalidate`**：表示缓存必须在使用前验证旧资源的状态，并且在缓存过期后，必须重新验证资源。

7. **`no-transform`**：表示不允许代理服务器修改响应内容。

8. **`proxy-revalidate`**：与`must-revalidate`类似，但仅适用于共享缓存。

9. **`s-maxage`**：类似于`max-age`，但仅适用于共享缓存。

### flush<sup>9+</sup>

flush(callback: AsyncCallback\<void\>): void

将缓存中的数据写入文件系统，以便在下一个HTTP请求中访问所有缓存数据，使用callback方式作为异步方法。缓存数据包括：响应头（header）、响应体（result）、cookies、请求时间（requestTime）和响应时间（responseTime）。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<void\> | 是   | 回调函数返回写入结果。 |

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
| Promise\<void\> | 以Promise形式返回写入结果。 |

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
    console.info('flush fail');
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
| callback | AsyncCallback\<void\> | 是   | 回调函数返回删除结果。|

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
| Promise\<void\> | 以Promise形式返回删除结果。 |

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

http的数据类型。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

| 名称 | 值 | 说明     |
| ------------------  | -- | ----------- |
| STRING              | 0 | 字符串类型。 |
| OBJECT              | 1 | 对象类型。    |
| ARRAY_BUFFER        | 2 | 二进制数组类型。|

## HttpProtocol<sup>9+</sup>

http协议版本。

**系统能力**：SystemCapability.Communication.NetStack

| 名称  |   值   | 说明     |
| :-------- | :----------- | :----------- |
| HTTP1_1   |   0   |  协议http1.1 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| HTTP2     |   1   |  协议http2 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。   |
| HTTP3<sup>11+</sup> |  2  | 协议http3，若系统或服务器不支持，则使用低版本的http协议请求。<br />- 仅对https的URL生效，http则会请求失败。 |

## CertType<sup>11+</sup>

证书类型的枚举。

**系统能力**：SystemCapability.Communication.NetStack

| 名称 | 说明       |
| --- | ---------- |
| PEM | 证书类型PEM |
| DER | 证书类型DER |
| P12 | 证书类型P12 |

## CertificatePinning<sup>12+</sup>

由应用配置的证书。

**系统能力**：SystemCapability.Communication.NetStack

|  名称  |  类型  |  必填  |说明     |
| ------------------  |---- |-- | ----------- |
| publicKeyHash       | string | 是 |字符串类型的证书PIN码。 |
| hashAlgorithm        | 'SHA-256' |  是  |加密算法，当前仅支持该算法。 |
