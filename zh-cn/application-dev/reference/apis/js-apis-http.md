# @ohos.net.http (数据请求)

本模块提供HTTP数据请求能力。应用可以通过HTTP发起一个数据请求，支持常见的GET、POST、OPTIONS、HEAD、PUT、DELETE、TRACE、CONNECT方法。

>**说明：**
>
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>

## 导入模块

```js
import http from '@ohos.net.http';
```

## 完整示例

```js
import http from '@ohos.net.http';

// 每一个httpRequest对应一个HTTP请求任务，不可复用
let httpRequest = http.createHttp();
// 用于订阅HTTP响应头，此接口会比request请求先返回。可以根据业务需要订阅此消息
// 从API 8开始，使用on('headersReceive', Callback)替代on('headerReceive', AsyncCallback)。 8+
httpRequest.on('headersReceive', (header) => {
    console.info('header: ' + JSON.stringify(header));
});
httpRequest.request(
    // 填写HTTP请求的URL地址，可以带参数也可以不带参数。URL地址需要开发者自定义。请求的参数可以在extraData中指定
    "EXAMPLE_URL",
    {
        method: http.RequestMethod.POST, // 可选，默认为http.RequestMethod.GET
        // 开发者根据自身业务需要添加header字段
        header: {
            'Content-Type': 'application/json'
        },
        // 当使用POST请求时此字段用于传递内容
        extraData: {
            "data": "data to send",
        },
        expectDataType: http.HttpDataType.STRING, // 可选，指定返回数据的类型
        usingCache: true, // 可选，默认为true
        priority: 1, // 可选，默认为1
        connectTimeout: 60000, // 可选，默认为60000ms
        readTimeout: 60000, // 可选，默认为60000ms
        usingProtocol: http.HttpProtocol.HTTP1_1, // 可选，协议类型默认值由系统自动指定
    }, (err, data) => {
        if (!err) {
            // data.result为HTTP响应内容，可根据业务需要进行解析
            console.info('Result:' + data.result);
            console.info('code:' + data.responseCode);
            // data.header为HTTP响应头，可根据业务需要进行解析
            console.info('header:' + JSON.stringify(data.header));
            console.info('cookies:' + data.cookies); // 8+
        } else {
            console.info('error:' + JSON.stringify(err));
            // 当该请求使用完毕时，调用destroy方法主动销毁。
            httpRequest.destroy();
        }
    }
);
```

## http.createHttp

createHttp\(\): HttpRequest

创建一个HTTP请求，里面包括发起请求、中断请求、订阅/取消订阅HTTP Response Header事件。每一个HttpRequest对象对应一个HTTP请求。如需发起多个HTTP请求，须为每个HTTP请求创建对应HttpRequest对象。

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型        | 说明                                                         |
| :---------- | :----------------------------------------------------------- |
| HttpRequest | 返回一个HttpRequest对象，里面包括request、destroy、on和off方法。 |

**示例：**

```js
import http from '@ohos.net.http';
let httpRequest = http.createHttp();
```

## HttpRequest

HTTP请求任务。在调用HttpRequest的方法前，需要先通过[createHttp\(\)](#httpcreatehttp)创建一个任务。

### request

request\(url: string, callback: AsyncCallback\<HttpResponse\>\):void

根据URL地址，发起HTTP网络请求，使用callback方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                           | 必填 | 说明                    |
| -------- | ---------------------------------------------- | ---- | ----------------------- |
| url      | string                                         | 是   | 发起网络请求的URL地址。 |
| callback | AsyncCallback\<[HttpResponse](#httpresponse)\> | 是   | 回调函数。              |

**示例：**

```js
httpRequest.request("EXAMPLE_URL", (err, data) => {
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

### request

request\(url: string, options: HttpRequestOptions, callback: AsyncCallback<HttpResponse\>\):void

根据URL地址和相关配置项，发起HTTP网络请求，使用callback方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                           | 必填 | 说明                                            |
| -------- | ---------------------------------------------- | ---- | ----------------------------------------------- |
| url      | string                                         | 是   | 发起网络请求的URL地址。                         |
| options  | HttpRequestOptions                             | 是   | 参考[HttpRequestOptions](#httprequestoptions)。 |
| callback | AsyncCallback\<[HttpResponse](#httpresponse)\> | 是   | 回调函数。                                      |

**示例：**

```js
httpRequest.request("EXAMPLE_URL",
{
    method: http.RequestMethod.GET,
    header: {
        'Content-Type': 'application/json'
    },
    readTimeout: 60000,
    connectTimeout: 60000
}, (err, data) => {
    if (!err) {
        console.info('Result:' + data.result);
        console.info('code:' + data.responseCode);
        console.info('header:' + JSON.stringify(data.header));
        console.info('cookies:' + data.cookies); // 8+
        console.info('header.Content-Type:' + data.header['Content-Type']);
        console.info('header.Status-Line:' + data.header['Status-Line']);
    } else {
        console.info('error:' + JSON.stringify(err));
    }
});
```

### request

request\(url: string, options? : HttpRequestOptions\): Promise<HttpResponse\>

根据URL地址，发起HTTP网络请求，使用Promise方式作为异步方法。

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


**示例：**

```js
let promise = httpRequest.request("EXAMPLE_URL", {
    method: http.RequestMethod.GET,
    connectTimeout: 60000,
    readTimeout: 60000,
    header: {
        'Content-Type': 'application/json'
    }
});
promise.then((data) => {
    console.info('Result:' + data.result);
    console.info('code:' + data.responseCode);
    console.info('header:' + JSON.stringify(data.header));
    console.info('cookies:' + data.cookies); // 8+
    console.info('header.Content-Type:' + data.header['Content-Type']);
    console.info('header.Status-Line:' + data.header['Status-Line']);
}).catch((err) => {
    console.info('error:' + JSON.stringify(err));
});
```

### destroy

destroy\(\): void

中断请求任务。

**系统能力**：SystemCapability.Communication.NetStack

**示例：**

```js
httpRequest.destroy();
```

### on\('headerReceive'\)

on\(type: 'headerReceive', callback: AsyncCallback<Object\>\): void

订阅HTTP Response Header 事件。

>![](public_sys-resources/icon-note.gif) **说明：**
>此接口已废弃，建议使用[on\('headersReceive'\)<sup>8+</sup>](#onheadersreceive8)替代。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                    | 必填 | 说明                              |
| -------- | ----------------------- | ---- | --------------------------------- |
| type     | string                  | 是   | 订阅的事件类型，'headerReceive'。 |
| callback | AsyncCallback\<Object\> | 是   | 回调函数。                        |

**示例：**

```js
httpRequest.on('headerReceive', (err, data) => {
    if (!err) {
        console.info('header: ' + JSON.stringify(data));
    } else {
        console.info('error:' + JSON.stringify(err));
    }
});
```

### off\('headerReceive'\)

off\(type: 'headerReceive', callback?: AsyncCallback<Object\>\): void

取消订阅HTTP Response Header 事件。

>![](public_sys-resources/icon-note.gif) **说明：**
>
>1. 此接口已废弃，建议使用[off\('headersReceive'\)<sup>8+</sup>](#offheadersreceive8)替代。
>
>2. 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                  |
| -------- | ----------------------- | ---- | ------------------------------------- |
| type     | string                  | 是   | 取消订阅的事件类型，'headerReceive'。 |
| callback | AsyncCallback\<Object\> | 否   | 回调函数。                            |

**示例：**

```js
httpRequest.off('headerReceive');
```

### on\('headersReceive'\)<sup>8+</sup>

on\(type: 'headersReceive', callback: Callback<Object\>\): void

订阅HTTP Response Header 事件。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型               | 必填 | 说明                               |
| -------- | ------------------ | ---- | ---------------------------------- |
| type     | string             | 是   | 订阅的事件类型：'headersReceive'。 |
| callback | Callback\<Object\> | 是   | 回调函数。                         |

**示例：**

```js
httpRequest.on('headersReceive', (header) => {
    console.info('header: ' + JSON.stringify(header));
});
```

### off\('headersReceive'\)<sup>8+</sup>

off\(type: 'headersReceive', callback?: Callback<Object\>\): void

取消订阅HTTP Response Header 事件。

>![](public_sys-resources/icon-note.gif) **说明：**
>可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型               | 必填 | 说明                                   |
| -------- | ------------------ | ---- | -------------------------------------- |
| type     | string             | 是   | 取消订阅的事件类型：'headersReceive'。 |
| callback | Callback\<Object\> | 否   | 回调函数。                             |

**示例：**

```js
httpRequest.off('headersReceive');
```

### once\('headersReceive'\)<sup>8+</sup>

once\(type: 'headersReceive', callback: Callback<Object\>\): void

订阅HTTP Response Header 事件，但是只触发一次。一旦触发之后，订阅器就会被移除。使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型               | 必填 | 说明                               |
| -------- | ------------------ | ---- | ---------------------------------- |
| type     | string             | 是   | 订阅的事件类型：'headersReceive'。 |
| callback | Callback\<Object\> | 是   | 回调函数。                         |

**示例：**

```js
httpRequest.once('headersReceive', (header) => {
    console.info('header: ' + JSON.stringify(header));
});
```

## HttpRequestOptions

发起请求可选参数的类型和取值范围。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.NetStack。

| 名称         | 类型                                          | 必填 | 说明                                                         |
| -------------- | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| method         | [RequestMethod](#requestmethod)               | 否   | 请求方式。                                                   |
| extraData      | string \| Object  \| ArrayBuffer<sup>6+</sup> | 否   | 发送请求的额外数据。<br />- 当HTTP请求为POST、PUT等方法时，此字段为HTTP请求的content。<br />- 当HTTP请求为GET、OPTIONS、DELETE、TRACE、CONNECT等方法时，此字段为HTTP请求的参数补充，参数内容会拼接到URL中进行发送。<sup>6+</sup><br />- 开发者传入string对象，开发者需要自行编码，将编码后的string传入。<sup>6+</sup> |
| expectDataType<sup>9+</sup>  | [HttpDataType](#httpdatatype9)   | 否   | 指定返回数据的类型。如果设置了此参数，系统将优先返回指定的类型。 |
| usingCache<sup>9+</sup>      | boolean                         | 否   | 是否使用缓存，默认为true。   |
| priority<sup>9+</sup>        | number                          | 否   | 优先级，范围\[1,1000]，默认是1。                           |
| header         | Object                                        | 否   | HTTP请求头字段。默认{'Content-Type': 'application/json'}。   |
| readTimeout    | number                                        | 否   | 读取超时时间。单位为毫秒（ms），默认为60000ms。              |
| connectTimeout | number                                        | 否   | 连接超时时间。单位为毫秒（ms），默认为60000ms。              |
| usingProtocol<sup>9+</sup>   | [HttpProtocol](#httpprotocol9)   | 否   | 使用协议。默认值由系统自动指定。              |

## RequestMethod

HTTP 请求方法。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.NetStack。

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

## ResponseCode

发起请求返回的响应码。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.NetStack。

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

## HttpResponse

request方法回调函数的返回值类型。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.NetStack。

| 名称               | 类型                                         | 必填 | 说明                                                         |
| -------------------- | -------------------------------------------- | ---- | ------------------------------------------------------------ |
| result               | string \| Object \| ArrayBuffer<sup>6+</sup> | 是   | HTTP请求根据响应头中Content-type类型返回对应的响应格式内容：<br />- application/json：返回JSON格式的字符串，如需HTTP响应具体内容，需开发者自行解析<br />- application/octet-stream：ArrayBuffer<br />- 其他：string |
| resultType<sup>9+</sup> | [HttpDataType](#httpdatatype9)             | 是   | 返回值类型。                           |
| responseCode         | [ResponseCode](#responsecode) \| number      | 是   | 回调函数执行成功时，此字段为[ResponseCode](#responsecode)。若执行失败，错误码将会从AsyncCallback中的err字段返回。错误码参考[Response错误码](#response常用错误码)。 |
| header               | Object                                       | 是   | 发起HTTP请求返回来的响应头。当前返回的是JSON格式字符串，如需具体字段内容，需开发者自行解析。常见字段及解析方式如下：<br/>- Content-Type：header['Content-Type']；<br />- Status-Line：header['Status-Line']；<br />- Date：header.Date/header['Date']；<br />- Server：header.Server/header['Server']； |
| cookies<sup>8+</sup> | Array\<string\>                              | 是   | 服务器返回的 cookies。                                       |

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

```js
import http from '@ohos.net.http';
let httpResponseCache = http.createHttpResponseCache();
```

## HttpResponseCache<sup>9+</sup>

存储HTTP访问请求响应的对象。

### flush<sup>9+</sup>

flush(callback: AsyncCallback\<void>): void

将缓存中的数据写入文件系统，以便在下一个HTTP请求中访问所有缓存数据，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<void> | 是   | 回调函数返回写入结果。 |

**示例：**

```js
httpResponseCache.flush(err => {
  if (err) {
    console.log('flush fail');
    return;
  }
  console.log('flush success');
});
```

### flush<sup>9+</sup>

flush(): Promise\<void>

将缓存中的数据写入文件系统，以便在下一个HTTP请求中访问所有缓存数据，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<void>> | 以Promise形式返回写入结果。 |

**示例：**

```js
httpResponseCache.flush().then(() => {
  console.log('flush success');
}).catch(err => {
  console.log('flush fail');
});
```

### delete<sup>9+</sup>

delete(callback: AsyncCallback\<void>): void

禁用缓存并删除其中的数据，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<void> | 是   | 回调函数返回删除结果。|

**示例：**

```js
httpResponseCache.delete(err => {
  if (err) {
    console.log('delete fail');
    return;
  }
  console.log('delete success');
});
```
### delete<sup>9+</sup>

delete(): Promise\<void>

禁用缓存并删除其中的数据，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<void> | 以Promise形式返回删除结果。 |

**示例：**

```js
httpResponseCache.delete().then(() => {
  console.log('delete success');
}).catch(err => {
  console.log('delete fail');
});
```

## Response常用错误码

| 错误码 | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| -1     | 参数错误。检查参数的个数与类型是否正确。                           |
| 3      | URL格式错误。检查URL的格式与语法是否正确。                         |
| 4      | 构建时无法找到内置的请求功能、协议或选项。一个功能或选项是不启用或明确禁用时，为了得到它的功能，你需要得到一个重建的libcurl。              |
| 5      | 无法解析代理，指定的代理服务器主机无法解析。建议排查：1、url地址是否正确。2、联网是否正常，网络是否可以和外部进行通信。3、是否有网络访问权限。  |
| 6      | 无法解析主机，指定的远程主机无法解析。建议排查：1、url地址是否正确。2、联网是否正常，网络是否可以和外部进行通信。3、是否有网络访问权限。       |
| 7      | 无法连接代理或主机。建议排查：1、端口号是否有问题。 2、查看本地是否开启http的代理影响的。                                    |

## HttpDataType<sup>9+</sup>

http的数据类型。

**系统能力**：SystemCapability.Communication.NetStack

| 名称 | 值 | 说明     |
| ------------------ | -- | ----------- |
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
