# @ohos.net.http (数据请求)

本模块提供HTTP数据请求能力。应用可以通过HTTP发起一个数据请求，支持常见的GET、POST、OPTIONS、HEAD、PUT、DELETE、TRACE、CONNECT方法。

> **说明：**
>
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>

## 导入模块

```ts
import http from '@ohos.net.http';
```

## 完整示例

```ts
// 引入包名
import http from '@ohos.net.http';
import { BusinessError } from '@ohos.base';

// 每一个httpRequest对应一个HTTP请求任务，不可复用
let httpRequest = http.createHttp();
// 用于订阅HTTP响应头，此接口会比request请求先返回。可以根据业务需要订阅此消息
// 从API 8开始，使用on('headersReceive', Callback)替代on('headerReceive', AsyncCallback)。 8+
httpRequest.on('headersReceive', (header:Object) => {
  console.info('header: ' + JSON.stringify(header));
});
class ExtraData {
  public data: string;

  constructor(data: string) {
    this.data = data;
  }
}
class Header {
  public contentType: string;

  constructor(contentType: string) {
    this.contentType = contentType;
  }
}
httpRequest.request(
  // 填写HTTP请求的URL地址，可以带参数也可以不带参数。URL地址需要开发者自定义。请求的参数可以在extraData中指定
  "EXAMPLE_URL",
  {
    method: http.RequestMethod.POST, // 可选，默认为http.RequestMethod.GET
    // 当使用POST请求时此字段用于传递内容
    extraData: new ExtraData('data to send'),
    expectDataType: http.HttpDataType.STRING, // 可选，指定返回数据的类型
    usingCache: true, // 可选，默认为true
    priority: 1, // 可选，默认为1
    // 开发者根据自身业务需要添加header字段
    header: new Header('application/json'),
    readTimeout: 60000, // 可选，默认为60000ms
    connectTimeout: 60000, // 可选，默认为60000ms
    usingProtocol: http.HttpProtocol.HTTP1_1, // 可选，协议类型默认值由系统自动指定
    usingProxy: false, //可选，默认不使用网络代理，自API 10开始支持该属性
    caPath: "", // 可选，默认使用系统预设CA证书，自API 10开始支持该属性
  },
  (err: BusinessError, data: http.HttpResponse ) => {
  if (!err) {
    // data.result为HTTP响应内容，可根据业务需要进行解析
    console.info('Result:' + JSON.stringify(data.result));
    console.info('code:' + JSON.stringify(data.responseCode));
    // data.header为HTTP响应头，可根据业务需要进行解析
    console.info('header:' + JSON.stringify(data.header));
    console.info('cookies:' + JSON.stringify(data.cookies)); // 8+
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
  }});
```

> **说明：**
> console.info()输出的数据中包含换行符会导致数据出现截断现象。

## http.createHttp<sup>6+</sup>

createHttp(): HttpRequest

创建一个HTTP请求，里面包括发起请求、中断请求、订阅/取消订阅HTTP Response Header事件。每一个HttpRequest对象对应一个HTTP请求。如需发起多个HTTP请求，须为每个HTTP请求创建对应HttpRequest对象。

> **说明：**
> 当该请求使用完毕时，须调用destroy方法主动销毁HttpRequest对象。

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型        | 说明                                                         |
| :---------- | :----------------------------------------------------------- |
| HttpRequest | 返回一个HttpRequest对象，里面包括request、requestInStream、destroy、on和off方法。 |

**示例：**

```ts
import http from '@ohos.net.http';

let httpRequest = http.createHttp();
```

## HttpRequest

HTTP请求任务。在调用HttpRequest的方法前，需要先通过[createHttp()](#httpcreatehttp)创建一个任务。

### request<sup>6+</sup>

request(url: string, callback: AsyncCallback\<HttpResponse\>):void

根据URL地址，发起HTTP网络请求，使用callback方式作为异步方法。

> **说明：**
> 此接口仅支持数据大小为5M以内的数据接收。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                           | 必填 | 说明                    |
| -------- | ---------------------------------------------- | ---- | ----------------------- |
| url      | string                                         | 是   | 发起网络请求的URL地址。 |
| callback | AsyncCallback\<[HttpResponse](#httpresponse)\> | 是   | 回调函数。              |

**错误码：**

| 错误码ID   | 错误信息                                                  |
|---------|-------------------------------------------------------|
| 401     | Parameter error.                                      |
| 201     | Permission denied.                                    |
| 2300001 | Unsupported protocol.                                 |
| 2300003 | URL using bad/illegal format or missing URL.          |
| 2300005 | Couldn't resolve proxy name.                          |
| 2300006 | Couldn't resolve host name.                           |
| 2300007 | Couldn't connect to server.                           |
| 2300008 | Weird server reply.                                   |
| 2300009 | Access denied to remote resource.                     |
| 2300016 | Error in the HTTP2 framing layer.                     |
| 2300018 | Transferred a partial file.                           |
| 2300023 | Failed writing received data to disk/application.     |
| 2300025 | Upload failed.                                        |
| 2300026 | Failed to open/read local data from file/application. |
| 2300027 | Out of memory.                                        |
| 2300028 | Timeout was reached.                                  |
| 2300047 | Number of redirects hit maximum amount.               |
| 2300052 | Server returned nothing (no headers, no data).        |
| 2300055 | Failed sending data to the peer.                      |
| 2300056 | Failure when receiving data from the peer.            |
| 2300058 | Problem with the local SSL certificate.               |
| 2300059 | Couldn't use specified SSL cipher.                    |
| 2300060 | SSL peer certificate or SSH remote key was not OK.    |
| 2300061 | Unrecognized or bad HTTP Content or Transfer-Encoding.|
| 2300063 | Maximum file size exceeded.                           |
| 2300070 | Disk full or allocation exceeded.                     |
| 2300073 | Remote file already exists.                           |
| 2300077 | Problem with the SSL CA cert (path? access rights?).  |
| 2300078 | Remote file not found.                                |
| 2300094 | An authentication function returned an error.         |
| 2300999 | Unknown Other Error.                                  |

> **错误码说明：**
> 以上错误码的详细介绍参见[HTTP错误码](../errorcodes/errorcode-net-http.md)。
> HTTP 错误码映射关系：2300000 + curl错误码。更多常用错误码，可参考：[curl错误码](https://curl.se/libcurl/c/libcurl-errors.html)

**示例：**

```ts
import http from '@ohos.net.http';

let httpRequest = http.createHttp();
httpRequest.request("EXAMPLE_URL", (err: Error, data: http.HttpResponse) => {
  if (!err) {
    console.info('Result:' + data.result);
    console.info('code:' + data.responseCode);
    console.info('header:' + JSON.stringify(data.header));
    console.info('cookies:' + data.cookies); // 8+
  } else {
    console.info('error:' + JSON.stringify(err));
  }
});
```

### request<sup>6+</sup>

request(url: string, options: HttpRequestOptions, callback: AsyncCallback\<HttpResponse\>):void

根据URL地址和相关配置项，发起HTTP网络请求，使用callback方式作为异步方法。

> **说明：**
> 此接口仅支持数据大小为5M以内的数据接收。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                           | 必填 | 说明                                            |
| -------- | ---------------------------------------------- | ---- | ----------------------------------------------- |
| url      | string                                         | 是   | 发起网络请求的URL地址。                         |
| options  | HttpRequestOptions                             | 是   | 参考[HttpRequestOptions](#httprequestoptions)。 |
| callback | AsyncCallback\<[HttpResponse](#httpresponse)\> | 是   | 回调函数。                                      |

**错误码：**

| 错误码ID   | 错误信息                                                  |
|---------|-------------------------------------------------------|
| 401     | Parameter error.                                      |
| 201     | Permission denied.                                    |
| 2300001 | Unsupported protocol.                                 |
| 2300003 | URL using bad/illegal format or missing URL.          |
| 2300005 | Couldn't resolve proxy name.                          |
| 2300006 | Couldn't resolve host name.                           |
| 2300007 | Couldn't connect to server.                           |
| 2300008 | Weird server reply.                                   |
| 2300009 | Access denied to remote resource.                     |
| 2300016 | Error in the HTTP2 framing layer.                     |
| 2300018 | Transferred a partial file.                           |
| 2300023 | Failed writing received data to disk/application.     |
| 2300025 | Upload failed.                                        |
| 2300026 | Failed to open/read local data from file/application. |
| 2300027 | Out of memory.                                        |
| 2300028 | Timeout was reached.                                  |
| 2300047 | Number of redirects hit maximum amount.               |
| 2300052 | Server returned nothing (no headers, no data).        |
| 2300055 | Failed sending data to the peer.                      |
| 2300056 | Failure when receiving data from the peer.            |
| 2300058 | Problem with the local SSL certificate.               |
| 2300059 | Couldn't use specified SSL cipher.                    |
| 2300060 | SSL peer certificate or SSH remote key was not OK.    |
| 2300061 | Unrecognized or bad HTTP Content or Transfer-Encoding.|
| 2300063 | Maximum file size exceeded.                           |
| 2300070 | Disk full or allocation exceeded.                     |
| 2300073 | Remote file already exists.                           |
| 2300077 | Problem with the SSL CA cert (path? access rights?).  |
| 2300078 | Remote file not found.                                |
| 2300094 | An authentication function returned an error.         |
| 2300999 | Unknown Other Error.                                  |

> **错误码说明：**
> 以上错误码的详细介绍参见[HTTP错误码](../errorcodes/errorcode-net-http.md)。
> HTTP 错误码映射关系：2300000 + curl错误码。更多常用错误码，可参考：[curl错误码](https://curl.se/libcurl/c/libcurl-errors.html)

**示例：**

```ts
import http from '@ohos.net.http';

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
  console.info('header:' + JSON.stringify(data.header));
  console.info('cookies:' + data.cookies); // 8+
  console.info('header.Content-Type:' + data.header);
  console.info('header.Status-Line:' + data.header);

}).catch((err:Error) => {
  console.info('error:' + JSON.stringify(err));
});
```

### request<sup>6+</sup>

request(url: string, options? : HttpRequestOptions): Promise\<HttpResponse\>

根据URL地址，发起HTTP网络请求，使用Promise方式作为异步方法。

> **说明：**
> 此接口仅支持数据大小为5M以内的数据接收。

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
| Promise<[HttpResponse](#httpresponse)> | 以Promise形式返回发起请求的结果。 |

**错误码：**

| 错误码ID   | 错误信息                                                  |
|---------|-------------------------------------------------------|
| 401     | Parameter error.                                      |
| 201     | Permission denied.                                    |
| 2300001 | Unsupported protocol.                                 |
| 2300003 | URL using bad/illegal format or missing URL.          |
| 2300005 | Couldn't resolve proxy name.                          |
| 2300006 | Couldn't resolve host name.                           |
| 2300007 | Couldn't connect to server.                           |
| 2300008 | Weird server reply.                                   |
| 2300009 | Access denied to remote resource.                     |
| 2300016 | Error in the HTTP2 framing layer.                     |
| 2300018 | Transferred a partial file.                           |
| 2300023 | Failed writing received data to disk/application.     |
| 2300025 | Upload failed.                                        |
| 2300026 | Failed to open/read local data from file/application. |
| 2300027 | Out of memory.                                        |
| 2300028 | Timeout was reached.                                  |
| 2300047 | Number of redirects hit maximum amount.               |
| 2300052 | Server returned nothing (no headers, no data).        |
| 2300055 | Failed sending data to the peer.                      |
| 2300056 | Failure when receiving data from the peer.            |
| 2300058 | Problem with the local SSL certificate.               |
| 2300059 | Couldn't use specified SSL cipher.                    |
| 2300060 | SSL peer certificate or SSH remote key was not OK.    |
| 2300061 | Unrecognized or bad HTTP Content or Transfer-Encoding.|
| 2300063 | Maximum file size exceeded.                           |
| 2300070 | Disk full or allocation exceeded.                     |
| 2300073 | Remote file already exists.                           |
| 2300077 | Problem with the SSL CA cert (path? access rights?).  |
| 2300078 | Remote file not found.                                |
| 2300094 | An authentication function returned an error.         |
| 2300999 | Unknown Other Error.                                  |

> **错误码说明：**
> 以上错误码的详细介绍参见[HTTP错误码](../errorcodes/errorcode-net-http.md)。
> HTTP 错误码映射关系：2300000 + curl错误码。更多常用错误码，可参考：[curl错误码](https://curl.se/libcurl/c/libcurl-errors.html)

**示例：**

```ts
import http from '@ohos.net.http';

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
  console.info('header:' + JSON.stringify(data.header));
  console.info('cookies:' + data.cookies); // 8+
  console.info('header.Content-Type:' + data.header);
  console.info('header.Status-Line:' + data.header);
}).catch((err:Error) => {
  console.info('error:' + JSON.stringify(err));
});
```

### destroy

destroy(): void

中断请求任务。

**系统能力**：SystemCapability.Communication.NetStack

**示例：**

```ts
import http from '@ohos.net.http';
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
| callback | AsyncCallback\<[number](#responsecode)\>       | 是   | 回调函数。                                      |

**错误码：**

| 错误码ID   | 错误信息                                                  |
|---------|-------------------------------------------------------|
| 401     | Parameter error.                                      |
| 201     | Permission denied.                                    |
| 2300001 | Unsupported protocol.                                 |
| 2300003 | URL using bad/illegal format or missing URL.          |
| 2300005 | Couldn't resolve proxy name.                          |
| 2300006 | Couldn't resolve host name.                           |
| 2300007 | Couldn't connect to server.                           |
| 2300008 | Weird server reply.                                   |
| 2300009 | Access denied to remote resource.                     |
| 2300016 | Error in the HTTP2 framing layer.                     |
| 2300018 | Transferred a partial file.                           |
| 2300023 | Failed writing received data to disk/application.     |
| 2300025 | Upload failed.                                        |
| 2300026 | Failed to open/read local data from file/application. |
| 2300027 | Out of memory.                                        |
| 2300028 | Timeout was reached.                                  |
| 2300047 | Number of redirects hit maximum amount.               |
| 2300052 | Server returned nothing (no headers, no data).        |
| 2300055 | Failed sending data to the peer.                      |
| 2300056 | Failure when receiving data from the peer.            |
| 2300058 | Problem with the local SSL certificate.               |
| 2300059 | Couldn't use specified SSL cipher.                    |
| 2300060 | SSL peer certificate or SSH remote key was not OK.    |
| 2300061 | Unrecognized or bad HTTP Content or Transfer-Encoding.|
| 2300063 | Maximum file size exceeded.                           |
| 2300070 | Disk full or allocation exceeded.                     |
| 2300073 | Remote file already exists.                           |
| 2300077 | Problem with the SSL CA cert (path? access rights?).  |
| 2300078 | Remote file not found.                                |
| 2300094 | An authentication function returned an error.         |
| 2300999 | Unknown Other Error.                                  |

> **错误码说明：**
> 以上错误码的详细介绍参见[HTTP错误码](../errorcodes/errorcode-net-http.md)。
> HTTP 错误码映射关系：2300000 + curl错误码。更多常用错误码，可参考：[curl错误码](https://curl.se/libcurl/c/libcurl-errors.html)

**示例：**

```ts
import http from '@ohos.net.http';
import { BusinessError } from '@ohos.base';

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

| 错误码ID   | 错误信息                                                  |
|---------|-------------------------------------------------------|
| 401     | Parameter error.                                      |
| 201     | Permission denied.                                    |
| 2300001 | Unsupported protocol.                                 |
| 2300003 | URL using bad/illegal format or missing URL.          |
| 2300005 | Couldn't resolve proxy name.                          |
| 2300006 | Couldn't resolve host name.                           |
| 2300007 | Couldn't connect to server.                           |
| 2300008 | Weird server reply.                                   |
| 2300009 | Access denied to remote resource.                     |
| 2300016 | Error in the HTTP2 framing layer.                     |
| 2300018 | Transferred a partial file.                           |
| 2300023 | Failed writing received data to disk/application.     |
| 2300025 | Upload failed.                                        |
| 2300026 | Failed to open/read local data from file/application. |
| 2300027 | Out of memory.                                        |
| 2300028 | Timeout was reached.                                  |
| 2300047 | Number of redirects hit maximum amount.               |
| 2300052 | Server returned nothing (no headers, no data).        |
| 2300055 | Failed sending data to the peer.                      |
| 2300056 | Failure when receiving data from the peer.            |
| 2300058 | Problem with the local SSL certificate.               |
| 2300059 | Couldn't use specified SSL cipher.                    |
| 2300060 | SSL peer certificate or SSH remote key was not OK.    |
| 2300061 | Unrecognized or bad HTTP Content or Transfer-Encoding.|
| 2300063 | Maximum file size exceeded.                           |
| 2300070 | Disk full or allocation exceeded.                     |
| 2300073 | Remote file already exists.                           |
| 2300077 | Problem with the SSL CA cert (path? access rights?).  |
| 2300078 | Remote file not found.                                |
| 2300094 | An authentication function returned an error.         |
| 2300999 | Unknown Other Error.                                  |

> **错误码说明：**
> 以上错误码的详细介绍参见[HTTP错误码](../errorcodes/errorcode-net-http.md)。
> HTTP 错误码映射关系：2300000 + curl错误码。更多常用错误码，可参考：[curl错误码](https://curl.se/libcurl/c/libcurl-errors.html)

**示例：**

```ts
import http from '@ohos.net.http';
import { BusinessError } from '@ohos.base';

class Header {
  public contentType: string;

  constructor(contentType: string) {
    this.contentType = contentType;
  }
}

let httpRequest = http.createHttp();
httpRequest.requestInStream("EXAMPLE_URL", (err: BusinessError<void> , data: number) => {
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

| 错误码ID   | 错误信息                                                  |
|---------|-------------------------------------------------------|
| 401     | Parameter error.                                      |
| 201     | Permission denied.                                    |
| 2300001 | Unsupported protocol.                                 |
| 2300003 | URL using bad/illegal format or missing URL.          |
| 2300005 | Couldn't resolve proxy name.                          |
| 2300006 | Couldn't resolve host name.                           |
| 2300007 | Couldn't connect to server.                           |
| 2300008 | Weird server reply.                                   |
| 2300009 | Access denied to remote resource.                     |
| 2300016 | Error in the HTTP2 framing layer.                     |
| 2300018 | Transferred a partial file.                           |
| 2300023 | Failed writing received data to disk/application.     |
| 2300025 | Upload failed.                                        |
| 2300026 | Failed to open/read local data from file/application. |
| 2300027 | Out of memory.                                        |
| 2300028 | Timeout was reached.                                  |
| 2300047 | Number of redirects hit maximum amount.               |
| 2300052 | Server returned nothing (no headers, no data).        |
| 2300055 | Failed sending data to the peer.                      |
| 2300056 | Failure when receiving data from the peer.            |
| 2300058 | Problem with the local SSL certificate.               |
| 2300059 | Couldn't use specified SSL cipher.                    |
| 2300060 | SSL peer certificate or SSH remote key was not OK.    |
| 2300061 | Unrecognized or bad HTTP Content or Transfer-Encoding.|
| 2300063 | Maximum file size exceeded.                           |
| 2300070 | Disk full or allocation exceeded.                     |
| 2300073 | Remote file already exists.                           |
| 2300077 | Problem with the SSL CA cert (path? access rights?).  |
| 2300078 | Remote file not found.                                |
| 2300094 | An authentication function returned an error.         |
| 2300999 | Unknown Other Error.                                  |

> **错误码说明：**
> 以上错误码的详细介绍参见[HTTP错误码](../errorcodes/errorcode-net-http.md)。
> HTTP 错误码映射关系：2300000 + curl错误码。更多常用错误码，可参考：

**示例：**

```ts
import http from '@ohos.net.http';

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
promise.then((data: http.HttpResponse) => {
  console.info("requestInStream OK!" + JSON.stringify(data));
}).catch((err: Error) => {
  console.info("requestInStream ERROR : err = " + JSON.stringify(err));
});
```

### on('headerReceive')<sup>(deprecated)</sup>

on(type: 'headerReceive', callback: AsyncCallback\<Object\>): void

订阅HTTP Response Header 事件。

> **说明：**
> 此接口已废弃，建议使用[on('headersReceive')<sup>8+</sup>](#onheadersreceive8)替代。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                    | 必填 | 说明                              |
| -------- | ----------------------- | ---- | --------------------------------- |
| type     | string                  | 是   | 订阅的事件类型，'headerReceive'。 |
| callback | AsyncCallback\<Object\> | 是   | 回调函数。                        |

**示例：**

```ts
import http from '@ohos.net.http';
import { BusinessError } from '@ohos.base';

let httpRequest = http.createHttp();
httpRequest.on('headerReceive', (data: BusinessError) => {
  console.info('error:' + JSON.stringify(data));
});
```

### off('headerReceive')<sup>(deprecated)</sup>

off(type: 'headerReceive', callback?: AsyncCallback\<Object\>): void

取消订阅HTTP Response Header 事件。

> **说明：**
>
>1. 此接口已废弃，建议使用[off('headersReceive')<sup>8+</sup>](#offheadersreceive8)替代。
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
import http from '@ohos.net.http';

let httpRequest = http.createHttp();
httpRequest.off('headerReceive');
```

### on('headersReceive')<sup>8+</sup>

on(type: 'headersReceive', callback: Callback\<Object\>): void

订阅HTTP Response Header 事件。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型               | 必填 | 说明                               |
| -------- | ------------------ | ---- | ---------------------------------- |
| type     | string             | 是   | 订阅的事件类型：'headersReceive'。 |
| callback | Callback\<Object\> | 是   | 回调函数。                         |

**示例：**

```ts
import http from '@ohos.net.http';

let httpRequest = http.createHttp();
httpRequest.on('headersReceive', (header: Object) => {
  console.info('header: ' + JSON.stringify(header));
});
```

### off('headersReceive')<sup>8+</sup>

off(type: 'headersReceive', callback?: Callback\<Object\>): void

取消订阅HTTP Response Header 事件。

> **说明：**
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型               | 必填 | 说明                                   |
| -------- | ------------------ | ---- | -------------------------------------- |
| type     | string             | 是   | 取消订阅的事件类型：'headersReceive'。 |
| callback | Callback\<Object\> | 否   | 回调函数。                             |

**示例：**

```ts
import http from '@ohos.net.http';

let httpRequest = http.createHttp();
httpRequest.off('headersReceive');
```

### once('headersReceive')<sup>8+</sup>

once(type: 'headersReceive', callback: Callback\<Object\>): void

订阅HTTP Response Header 事件，但是只触发一次。一旦触发之后，订阅器就会被移除。使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型               | 必填 | 说明                               |
| -------- | ------------------ | ---- | ---------------------------------- |
| type     | string             | 是   | 订阅的事件类型：'headersReceive'。 |
| callback | Callback\<Object\> | 是   | 回调函数。                         |

**示例：**

```ts
import http from '@ohos.net.http';

let httpRequest = http.createHttp();
httpRequest.once('headersReceive', (header: Object) => {
  console.info('header: ' + JSON.stringify(header));
});
```

### on('dataReceive')<sup>10+</sup>

on(type: 'dataReceive', callback: Callback\<ArrayBuffer\>): void

订阅HTTP流式响应数据接收事件。

> **说明：**
> 暂不支持订阅HTTP流式数据上传的相关事件。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                    | 必填 | 说明                              |
| -------- | ----------------------- | ---- | --------------------------------- |
| type     | string                  | 是   | 订阅的事件类型，'dataReceive'。 |
| callback | AsyncCallback\<ArrayBuffer\> | 是   | 回调函数。                        |

**示例：**

```ts
import http from '@ohos.net.http';

let httpRequest = http.createHttp();
httpRequest.on('dataReceive', (data: ArrayBuffer) => {
  console.info('dataReceive length: ' + JSON.stringify(data.byteLength));
});
```

### off('dataReceive')<sup>10+</sup>

off(type: 'dataReceive', callback?: Callback\<ArrayBuffer\>): void

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
import http from '@ohos.net.http';

let httpRequest = http.createHttp();
httpRequest.off('dataReceive');
```

### on('dataEnd')<sup>10+</sup>

on(type: 'dataEnd', callback: Callback\<void\>): void

订阅HTTP流式响应数据接收完毕事件。

> **说明：**
> 暂不支持订阅HTTP流式数据上传的相关事件。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                    | 必填 | 说明                              |
| -------- | ----------------------- | ---- | --------------------------------- |
| type     | string                  | 是   | 订阅的事件类型，'dataEnd'。 |
| callback | AsyncCallback\<void\>   | 是   | 回调函数。                        |

**示例：**

```ts
import http from '@ohos.net.http';

let httpRequest = http.createHttp();
httpRequest.on('dataEnd', () => {
  console.info('Receive dataEnd !');
});
```

### off('dataEnd')<sup>10+</sup>

off(type: 'dataEnd', callback?: Callback\<void\>): void

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
import http from '@ohos.net.http';

let httpRequest = http.createHttp();
httpRequest.off('dataEnd');
```

### on('dataReceiveProgress')<sup>10+</sup>

on(type: 'dataReceiveProgress', callback: Callback\<{ receiveSize: number, totalSize: number }\>): void

订阅HTTP流式响应数据接收进度事件。

> **说明：**
> 暂不支持订阅HTTP流式数据上传的相关事件。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                    | 必填 | 说明                              |
| -------- | ----------------------- | ---- | --------------------------------- |
| type     | string                  | 是   | 订阅的事件类型，'dataReceiveProgress'。 |
| callback | AsyncCallback\<{ receiveSize: number, totalSize: number }\>   | 是   | 回调函数。<br>receiveSize：已接收的数据字节数，totalSize待接收的字节总数 |

**示例：**

```ts
import http from '@ohos.net.http';

class RequestData{
  receiveSize: number = 2000 
  totalSize: number = 2000 
}

let httpRequest = http.createHttp();
httpRequest.on('dataReceiveProgress', (data: RequestData) => {
  console.info('dataReceiveProgress:' + JSON.stringify(data));
});
```

### off('dataReceiveProgress')<sup>10+</sup>

off(type: 'dataReceiveProgress', callback?: Callback\<{ receiveSize: number, totalSize: number }\>): void

取消订阅HTTP流式响应数据接收进度事件。

> **说明：**
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型               | 必填 | 说明                                   |
| -------- | ------------------ | ---- | -------------------------------------- |
| type     | string             | 是   | 取消订阅的事件类型：'dataReceiveProgress'。 |
| callback | Callback\<{ receiveSize: number, totalSize: number }\>   | 否   | 回调函数。                             |

**示例：**

```ts
import http from '@ohos.net.http';

let httpRequest = http.createHttp();
httpRequest.off('dataReceiveProgress');
```

## HttpRequestOptions<sup>6+</sup>

发起请求可选参数的类型和取值范围。

**系统能力**：SystemCapability.Communication.NetStack

| 名称         | 类型                                          | 必填 | 说明                                                         |
| -------------- | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| method         | [RequestMethod](#requestmethod)               | 否   | 请求方式，默认为GET。                                                   |
| extraData      | string<sup>6+</sup> \| Object<sup>6+</sup> \| ArrayBuffer<sup>8+</sup> | 否   | 发送请求的额外数据，默认无此字段。<br />当HTTP请求为POST、PUT等方法时，此字段为HTTP请求的content，以UTF-8编码形式作为请求体。当'Content-Type'为'application/x-www-form-urlencoded'时，请求提交的信息主体数据应在key和value进行URL转码后按照键值对"key1=value1&key2=value2&key3=value3"的方式进行编码，该字段对应的类型通常为String；当'Content-Type'为'text/xml'时，该字段对应的类型通常为String；当'Content-Type'为'application/json'时，该字段对应的类型通常为Object；当'Content-Type'为'application/octet-stream'时，该字段对应的类型通常为ArrayBuffer；当'Content-Type'为'multipart/form-data'且需上传的字段为文件时，该字段对应的类型通常为ArrayBuffer。以上信息仅供参考，并可能根据具体情况有所不同。<br />- 当HTTP请求为GET、OPTIONS、DELETE、TRACE、CONNECT等方法时，此字段为HTTP请求参数的补充。开发者需传入Encode编码后的string类型参数，Object类型的参数无需预编码，参数内容会拼接到URL中进行发送；ArrayBuffer类型的参数不会做拼接处理。 |
| <span name="expectDataType">[expectDataType<sup>9+</sup>](#result)</span>  | [HttpDataType](#httpdatatype9)  | 否   | 指定返回数据的类型，默认无此字段。如果设置了此参数，系统将优先返回指定的类型。 |
| usingCache<sup>9+</sup>      | boolean                         | 否   | 是否使用缓存，默认为true。   |
| priority<sup>9+</sup>        | number                          | 否   | 优先级，范围[1,1000]，默认是1。                           |
| header                       | Object                          | 否   | HTTP请求头字段。默认{'Content-Type': 'application/json'}。   |
| readTimeout                  | number                          | 否   | 读取超时时间。单位为毫秒（ms），默认为60000ms。<br />设置为0表示不会出现超时情况。 |
| connectTimeout               | number                          | 否   | 连接超时时间。单位为毫秒（ms），默认为60000ms。              |
| usingProtocol<sup>9+</sup>   | [HttpProtocol](#httpprotocol9)  | 否   | 使用协议。默认值由系统自动指定。                             |
| usingProxy<sup>10+</sup>     | boolean \| Object               | 否   | 是否使用HTTP代理，默认为false，不使用代理。<br />- 当usingProxy为布尔类型true时，使用默认网络代理。<br />- 当usingProxy为object类型时，使用指定网络代理。 |
| caPath<sup>10+</sup>     | string               | 否   | 如果设置了此参数，系统将使用用户指定路径的CA证书，(开发者需保证该路径下CA证书的可访问性)，否则将使用系统预设CA证书，系统预设CA证书位置：/etc/ssl/certs/cacert.pem。证书路径为沙箱映射路径（开发者可通过Global.getContext().filesDir获取应用沙箱路径）。目前仅支持后缀名为.pem的文本格式证书。                             |

## RequestMethod<sup>6+</sup>

HTTP 请求方法。

**系统能力**：SystemCapability.Communication.NetStack

| 名称    | 值      | 说明                |
| :------ | ------- | :------------------ |
| OPTIONS | "OPTIONS" | HTTP 请求 OPTIONS。 |
| GET     | "GET"     | HTTP 请求 GET。     |
| HEAD    | "HEAD"    | HTTP 请求 HEAD。    |
| POST    | "POST"    | HTTP 请求 POST。    |
| PUT     | "PUT"     | HTTP 请求 PUT。     |
| DELETE  | "DELETE"  | HTTP 请求 DELETE。  |
| TRACE   | "TRACE"   | HTTP 请求 TRACE。   |
| CONNECT | "CONNECT" | HTTP 请求 CONNECT。 |

## ResponseCode<sup>6+</sup>

发起请求返回的响应码。

**系统能力**：SystemCapability.Communication.NetStack

| 名称              | 值   | 说明                                                         |
| ----------------- | ---- | ------------------------------------------------------------ |
| OK                | 200  | 请求成功。一般用于GET与POST请求。                            |
| CREATED           | 201  | 已创建。成功请求并创建了新的资源。                           |
| ACCEPTED          | 202  | 已接受。已经接受请求，但未处理完成。                         |
| NOT_AUTHORITATIVE | 203  | 非授权信息。请求成功。                                       |
| NO_CONTENT        | 204  | 无内容。服务器成功处理，但未返回内容。                       |
| RESET             | 205  | 重置内容。                                                   |
| PARTIAL           | 206  | 部分内容。服务器成功处理了部分GET请求。                      |
| MULT_CHOICE       | 300  | 多种选择。                                                   |
| MOVED_PERM        | 301  | 永久移动。请求的资源已被永久的移动到新URI，返回信息会包括新的URI，浏览器会自动定向到新URI。 |
| MOVED_TEMP        | 302  | 临时移动。                                                   |
| SEE_OTHER         | 303  | 查看其它地址。                                               |
| NOT_MODIFIED      | 304  | 未修改。                                                     |
| USE_PROXY         | 305  | 使用代理。                                                   |
| BAD_REQUEST       | 400  | 客户端请求的语法错误，服务器无法理解。                       |
| UNAUTHORIZED      | 401  | 请求要求用户的身份认证。                                     |
| PAYMENT_REQUIRED  | 402  | 保留，将来使用。                                             |
| FORBIDDEN         | 403  | 服务器理解请求客户端的请求，但是拒绝执行此请求。             |
| NOT_FOUND         | 404  | 服务器无法根据客户端的请求找到资源（网页）。                 |
| BAD_METHOD        | 405  | 客户端请求中的方法被禁止。                                   |
| NOT_ACCEPTABLE    | 406  | 服务器无法根据客户端请求的内容特性完成请求。                 |
| PROXY_AUTH        | 407  | 请求要求代理的身份认证。                                     |
| CLIENT_TIMEOUT    | 408  | 请求时间过长，超时。                                         |
| CONFLICT          | 409  | 服务器完成客户端的PUT请求是可能返回此代码，服务器处理请求时发生了冲突。 |
| GONE              | 410  | 客户端请求的资源已经不存在。                                 |
| LENGTH_REQUIRED   | 411  | 服务器无法处理客户端发送的不带Content-Length的请求信息。     |
| PRECON_FAILED     | 412  | 客户端请求信息的先决条件错误。                               |
| ENTITY_TOO_LARGE  | 413  | 由于请求的实体过大，服务器无法处理，因此拒绝请求。           |
| REQ_TOO_LONG      | 414  | 请求的URI过长（URI通常为网址），服务器无法处理。             |
| UNSUPPORTED_TYPE  | 415  | 服务器无法处理请求的格式。                                   |
| INTERNAL_ERROR    | 500  | 服务器内部错误，无法完成请求。                               |
| NOT_IMPLEMENTED   | 501  | 服务器不支持请求的功能，无法完成请求。                       |
| BAD_GATEWAY       | 502  | 充当网关或代理的服务器，从远端服务器接收到了一个无效的请求。 |
| UNAVAILABLE       | 503  | 由于超载或系统维护，服务器暂时的无法处理客户端的请求。       |
| GATEWAY_TIMEOUT   | 504  | 充当网关或代理的服务器，未及时从远端服务器获取请求。         |
| VERSION           | 505  | 服务器请求的HTTP协议的版本。                                 |

## HttpResponse<sup>6+</sup>

request方法回调函数的返回值类型。

**系统能力**：SystemCapability.Communication.NetStack

| 名称               | 类型                                         | 必填 | 说明                                                         |
| -------------------- | -------------------------------------------- | ---- | ------------------------------------------------------------ |
| <span name="result">[result](#expectDataType)</span>              | string<sup>6+</sup> \| Object<sup>deprecated 8+</sup> \| ArrayBuffer<sup>8+</sup> | 是   | HTTP请求根据响应头中Content-type类型返回对应的响应格式内容，若HttpRequestOptions无expectDataType字段，按如下规则返回：<br />- application/json：返回JSON格式的字符串；<br />- application/octet-stream：ArrayBuffer；<br />- image：ArrayBuffer；<br />- 其他：string。<br /> 若HttpRequestOption有expectDataType字段，开发者需传入与服务器返回类型相同的数据类型。 |
| resultType<sup>9+</sup> | [HttpDataType](#httpdatatype9)             | 是   | 返回值类型。                           |
| responseCode         | [ResponseCode](#responsecode) \| number      | 是   | 回调函数执行成功时，此字段为[ResponseCode](#responsecode)。若执行失败，错误码将会从AsyncCallback中的err字段返回。 |
| header               | Object                                       | 是   | 发起HTTP请求返回来的响应头。当前返回的是JSON格式字符串，如需具体字段内容，需开发者自行解析。常见字段及解析方式如下：<br/>- content-type：header['content-type']；<br />- status-line：header['status-line']；<br />- date：header.date/header['date']；<br />- server：header.server/header['server']； |
| cookies<sup>8+</sup> | string                                       | 是   | 服务器返回的 cookies。                                       |

## http.createHttpResponseCache<sup>9+</sup>

createHttpResponseCache(cacheSize?: number): HttpResponseCache

创建一个默认的对象来存储HTTP访问请求的响应。

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
import http from '@ohos.net.http';

let httpResponseCache = http.createHttpResponseCache();
```

## HttpResponseCache<sup>9+</sup>

存储HTTP访问请求响应的对象。在调用HttpResponseCache的方法前，需要先通过[createHttpResponseCache()](#httpcreatehttpresponsecache9)创建一个任务。

### flush<sup>9+</sup>

flush(callback: AsyncCallback\<void\>): void

将缓存中的数据写入文件系统，以便在下一个HTTP请求中访问所有缓存数据，使用callback方式作为异步方法。缓存数据包括：响应头（header）、响应体（result）、cookies、请求时间（requestTime）和响应时间（responseTime）。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<void\> | 是   | 回调函数返回写入结果。 |

**示例：**

```ts
import http from '@ohos.net.http';
import { BusinessError } from '@ohos.base';

let httpResponseCache = http.createHttpResponseCache();
httpResponseCache.flush((err: BusinessError) => {
  if (err) {
    console.info('flush fail');
    return;
  }
  console.info('flush success');
});
```

### flush<sup>9+</sup>

flush(): Promise\<void\>

将缓存中的数据写入文件系统，以便在下一个HTTP请求中访问所有缓存数据，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<void\> | 以Promise形式返回写入结果。 |

**示例：**

```ts
import http from '@ohos.net.http';
import { BusinessError } from '@ohos.base';

let httpResponseCache = http.createHttpResponseCache();
httpResponseCache.flush().then(() => {
  console.info('flush success');
}).catch((err: BusinessError) => {
  console.info('flush fail');
});
```

### delete<sup>9+</sup>

delete(callback: AsyncCallback\<void\>): void

禁用缓存并删除其中的数据，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<void\> | 是   | 回调函数返回删除结果。|

**示例：**

```ts
import http from '@ohos.net.http';
import { BusinessError } from '@ohos.base';

let httpResponseCache = http.createHttpResponseCache();
httpResponseCache.delete((err: BusinessError) => {
  if (err) {
    console.info('delete fail');
    return;
  }
  console.info('delete success');
});
```

### delete<sup>9+</sup>

delete(): Promise\<void\>

禁用缓存并删除其中的数据，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<void\> | 以Promise形式返回删除结果。 |

**示例：**

```ts
import http from '@ohos.net.http';
import { BusinessError } from '@ohos.base';

let httpResponseCache = http.createHttpResponseCache();
httpResponseCache.delete().then(() => {
  console.info('delete success');
}).catch((err: Error) => {
  console.info('delete fail');
});
```

## HttpDataType<sup>9+</sup>

http的数据类型。

**系统能力**：SystemCapability.Communication.NetStack

| 名称 | 值 | 说明     |
| ------------------  | -- | ----------- |
| STRING              | 0 | 字符串类型。 |
| OBJECT              | 1 | 对象类型。    |
| ARRAY_BUFFER        | 2 | 二进制数组类型。|

## HttpProtocol<sup>9+</sup>

http协议版本。

**系统能力**：SystemCapability.Communication.NetStack

| 名称  | 说明     |
| :-------- | :----------- |
| HTTP1_1   |  协议http1.1  |
| HTTP2     |  协议http2    |
