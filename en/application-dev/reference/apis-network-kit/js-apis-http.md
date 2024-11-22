# @ohos.net.http (Data Request)

The **http** module provides the HTTP data request capability. An application can initiate a data request over HTTP. Common HTTP methods include **GET**, **POST**, **OPTIONS**, **HEAD**, **PUT**, **DELETE**, **TRACE**, and **CONNECT**.

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> **You are advised to use Remote Communication Kit for implementing HTTP data request capabilities. The Kit will continue to evolve to provide more functions.**
## Modules to Import

```ts
import { http } from '@kit.NetworkKit';
```

## Examples

```ts
// Import the http namespace.
import { http } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Each httpRequest corresponds to an HTTP request task and cannot be reused.
let httpRequest = http.createHttp();
// This API is used to listen for the HTTP Response Header event, which is returned earlier than the result of the HTTP request. It is up to you whether to listen for HTTP Response Header events.
// on('headerReceive', AsyncCallback) is replaced by on('headersReceive', Callback) since API version 8.
httpRequest.on('headersReceive', (header: Object) => {
  console.info('header: ' + JSON.stringify(header));
});

httpRequest.request( // Customize EXAMPLE_URL in extraData on your own. It is up to you whether to add parameters to the URL.
  "EXAMPLE_URL",
  {
    method: http.RequestMethod.POST, // Optional. The default value is http.RequestMethod.GET.
    // This field is used to transfer the request body when a POST request is used. Its format needs to be negotiated with the server.
    extraData: 'data to send',
    expectDataType: http.HttpDataType.STRING, // Optional. This parameter specifies the type of the return data.
    usingCache: true, // Optional. The default value is true.
    priority: 1, // Optional. The default value is 1.
    // You can add header fields based on service requirements.
    header: { 'Accept' : 'application/json' },
    readTimeout: 60000, // Optional. The default value is 60000, in ms.
    connectTimeout: 60000 // Optional. The default value is 60000, in ms.
    usingProtocol: http.HttpProtocol.HTTP1_1, // Optional. The default protocol type is automatically specified by the system.
    usingProxy: false, // Optional. By default, network proxy is not used. This field is supported since API version 10.
    caPath: '/path/to/cacert.pem', // Optional. The preset CA certificate is used by default. This field is supported since API version 10.
    clientCert: { // Optional. The client certificate is not used by default. This field is supported since API version 11.
      certPath: '/path/to/client.pem', // The client certificate is not used by default. This field is supported since API version 11.
      keyPath: '/path/to/client.key', // If the certificate contains key information, an empty string is passed. This field is supported since API version 11.
      certType: http.CertType.PEM, // Certificate type, optional. A certificate in the PEM format is used by default. This field is supported since API version 11.
      keyPassword: "passwordToKey" // Password of the key file, optional. It is supported since API version 11.
    },
    certificatePinning: [ // Optional. It determines whether to enable dynamic configuration of certificate pinning. This attribute is supported since API version 12.
      {
        publicKeyHash: 'Pin1', // Certificate PIN passed by the application. This attribute is supported since API version 12.
        hashAlgorithm: 'SHA-256' // Encryption algorithm. Currently, it can only be set to SHA-256. This attribute is supported since API version 12.
      }, {
        publicKeyHash: 'Pin2', // Certificate PIN passed by the application. This attribute is supported since API version 12.
        hashAlgorithm: 'SHA-256' // Encryption algorithm. Currently, it can only be set to SHA-256. This attribute is supported since API version 12.
      }
    ],
    multiFormDataList: [ // Optional. This field is valid only when content-Type in the header is multipart/form-data. It is supported since API version 11.
      {
        name: "Part1", // Data name. This field is supported since API version 11.
        contentType: 'text/plain', // Data type. This field is supported since API version 11.
        data: 'Example data', // Data content, optional. This field is supported since API version 11.
        remoteFileName: 'example.txt' // Optional. This field is supported since API version 11.
      }, {
        name: "Part2", // Data name. This field is supported since API version 11.
        contentType: 'text/plain', // Data type. This field is supported since API version 11.
        // data/app/el2/100/base/com.example.myapplication/haps/entry/files/fileName.txt
        filePath: `${getContext(this).filesDir}/fileName.txt`, // File path, optional. This field is supported since API version 11.
        remoteFileName: 'fileName.txt' // Optional. This field is supported since API version 11.
      }
    ]
  },
  (err: BusinessError, data: http.HttpResponse) => {
    if (!err) {
      // data.result carries the HTTP response. Parse the response based on service requirements.
      console.info('Result:' + JSON.stringify(data.result));
      console.info('code:' + JSON.stringify(data.responseCode));
      console.info('type:' + JSON.stringify(data.resultType));
      // data.header carries the HTTP response header. Parse the content based on service requirements.
      console.info('header:' + JSON.stringify(data.header));
      console.info('cookies:' + JSON.stringify(data.cookies)); // Cookies are supported since API version 8.
      // Unsubscribe from HTTP Response Header events.
      httpRequest.off('headersReceive');
      // Call destroy() to destroy the JavaScript object after the HTTP request is complete.
      httpRequest.destroy();
    } else {
      console.info('error:' + JSON.stringify(err));
      // Unsubscribe from HTTP Response Header events.
      httpRequest.off('headersReceive');
      // Call destroy() to destroy the JavaScript object after the HTTP request is complete.
      httpRequest.destroy();
    }
  });
```

> **NOTE**
> If the data in **console.info()** contains a newline character, the data will be truncated.
>
> HTTP responses compressed by the brotli algorithm are supported since API version 12.

## http.createHttp

createHttp(): HttpRequest

Creates an HTTP request. You can use this API to initiate or destroy an HTTP request, or enable or disable listening for HTTP Response Header events. An **HttpRequest** object corresponds to an HTTP request. To initiate multiple HTTP requests, you must create an **HttpRequest** object for each HTTP request.

> **NOTE**
> Call the **destroy()** method to release resources after the HttpRequest is complete.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type       | Description                                                        |
| :---------- | :----------------------------------------------------------- |
| HttpRequest | **HttpRequest** object, which contains the **request**, **requestInStream**, **destroy**, **on**, or **off** method.|

**Example**

```ts
import { http } from '@kit.NetworkKit';

let httpRequest = http.createHttp();
```

## HttpRequest

Defines an HTTP request task. Before invoking methods of **HttpRequest**, you must call **createHttp()** to create an HTTP request task.

### request

request(url: string, callback: AsyncCallback\<HttpResponse\>): void

Initiates an HTTP request to a given URL. This API uses an asynchronous callback to return the result. 

> **NOTE**
> This API supports only receiving of data not greater than 5 MB.
> If the URL contains non-English characters, call **encodeURL(url)** to encode the URL before initiating an HTTP request.

**Required permissions**: ohos.permission.INTERNET

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                          | Mandatory| Description                   |
| -------- | ---------------------------------------------- | ---- | ---------------------- |
| url      | string                                         | Yes  | URL for initiating an HTTP request.|
| callback | AsyncCallback\<[HttpResponse](#httpresponse)\> | Yes  | Callback used to return the result.   |

**Error codes**

| ID  | Error Message                                                        |
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

> **NOTE**
> For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [HTTP Error Codes](errorcode-net-http.md).
> The HTTP error code mapping is in the format of 2300000 + Curl error code. For more common error codes, see [Curl Error Codes](https://curl.se/libcurl/c/libcurl-errors.html).

**Example**

```ts
import { http } from '@kit.NetworkKit';

let httpRequest = http.createHttp();
httpRequest.request("EXAMPLE_URL", (err: Error, data: http.HttpResponse) => {
  if (!err) {
    console.info('Result:' + data.result);
    console.info('code:' + data.responseCode);
    console.info('type:' + JSON.stringify(data.resultType));
    console.info('header:' + JSON.stringify(data.header));
    console.info('cookies:' + data.cookies); // Cookies are supported since API version 8.
  } else {
    console.info('error:' + JSON.stringify(err));
  }
});
```

### request

request(url: string, options: HttpRequestOptions, callback: AsyncCallback\<HttpResponse\>):void

Initiates an HTTP request containing specified options to a given URL. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API supports only receiving of data not greater than 5 MB.
>
> If you need to pass in cookies, add them to the **options** parameter.

**Required permissions**: ohos.permission.INTERNET

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                          | Mandatory| Description                                           |
| -------- | ---------------------------------------------- | ---- | ----------------------------------------------- |
| url      | string                                         | Yes  | URL for initiating an HTTP request.                        |
| options  | HttpRequestOptions                             | Yes  | Request options. For details, see [HttpRequestOptions](#httprequestoptions).|
| callback | AsyncCallback\<[HttpResponse](#httpresponse)\> | Yes  | Callback used to return the result.                           |

**Error codes**

| ID  | Error Message                                                        |
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

> **NOTE**
> For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [HTTP Error Codes](errorcode-net-http.md).
> The HTTP error code mapping is in the format of 2300000 + Curl error code. For more common error codes, see [Curl Error Codes](https://curl.se/libcurl/c/libcurl-errors.html).

**Example**

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
    method: http.RequestMethod.POST, // Optional. The default value is http.RequestMethod.GET.
    // This field is used to transfer the request body when a POST request is used. Its format needs to be negotiated with the server.
    extraData: 'data to send',
    expectDataType: http.HttpDataType.STRING, // Optional. This parameter specifies the type of the return data.
    usingCache: true, // Optional. The default value is true.
    priority: 1, // Optional. The default value is 1.
    // You can add header fields based on service requirements.
    header: new Header('application/json'),
    readTimeout: 60000, // Optional. The default value is 60000, in ms.
    connectTimeout: 60000 // Optional. The default value is 60000, in ms.
    usingProtocol: http.HttpProtocol.HTTP1_1, // Optional. The default protocol type is automatically specified by the system.
    usingProxy: false, // Optional. By default, network proxy is not used. This field is supported since API version 10.
};

httpRequest.request("EXAMPLE_URL", options, (err: Error, data: http.HttpResponse) => {
  if (!err) {
    console.info('Result:' + data.result);
    console.info('code:' + data.responseCode);
    console.info('type:' + JSON.stringify(data.resultType));
    console.info('header:' + JSON.stringify(data.header));
    console.info('cookies:' + data.cookies); // Cookies are supported since API version 8.
  } else {
    console.info('error:' + JSON.stringify(err));
  }
});
```

### request

request(url: string, options? : HttpRequestOptions): Promise\<HttpResponse\>

Initiates an HTTP request containing specified options to a given URL. This API uses a promise to return the result. 

> **NOTE**
> This API supports only receiving of data not greater than 5 MB.
>
> If you need to pass in cookies, add them to the **options** parameter.

**Required permissions**: ohos.permission.INTERNET

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type              | Mandatory| Description                                           |
| ------- | ------------------ | ---- | ----------------------------------------------- |
| url     | string             | Yes  | URL for initiating an HTTP request.                        |
| options | HttpRequestOptions | No  | Request options. For details, see [HttpRequestOptions](#httprequestoptions).|

**Return value**

| Type                                  | Description                             |
| :------------------------------------- | :-------------------------------- |
| Promise<[HttpResponse](#httpresponse)> | Promise used to return the result.|

**Error codes**

| ID  | Error Message                                                        |
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

> **NOTE**
> For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [HTTP Error Codes](errorcode-net-http.md).
> The HTTP error code mapping is in the format of 2300000 + Curl error code. For more common error codes, see [Curl Error Codes](https://curl.se/libcurl/c/libcurl-errors.html).

**Example**

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
  console.info('cookies:' + data.cookies); // Cookies are supported since API version 8.
  console.info('header.content-Type:' + data.header);
  console.info('header.Status-Line:' + data.header);
}).catch((err:Error) => {
  console.info('error:' + JSON.stringify(err));
});
```

### destroy

destroy(): void

Destroys an HTTP request.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

**Example**

```ts
import { http } from '@kit.NetworkKit';
let httpRequest = http.createHttp();

httpRequest.destroy();
```

### requestInStream<sup>10+</sup>

requestInStream(url: string, callback: AsyncCallback\<number\>): void

Initiates an HTTP request containing specified options to a given URL. This API uses an asynchronous callback to return the result, which is a streaming response.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                          | Mandatory| Description                                           |
| -------- | ---------------------------------------------- | ---- | ----------------------------------------------- |
| url      | string                                         | Yes  | URL for initiating an HTTP request.                        |
| callback | AsyncCallback\<number\>       | Yes  | Callback used to return the result.                                     |

**Error codes**

| ID  | Error Message                                                        |
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

> **NOTE**
> For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [HTTP Error Codes](errorcode-net-http.md).
> The HTTP error code mapping is in the format of 2300000 + Curl error code. For more common error codes, see [Curl Error Codes](https://curl.se/libcurl/c/libcurl-errors.html).

**Example**

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

Initiates an HTTP request containing specified options to a given URL. This API uses an asynchronous callback to return the result, which is a streaming response.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                          | Mandatory| Description                                           |
| -------- | ---------------------------------------------- | ---- | ----------------------------------------------- |
| url      | string                                         | Yes  | URL for initiating an HTTP request.                        |
| options  | HttpRequestOptions                             | Yes  | Request options. For details, see [HttpRequestOptions](#httprequestoptions).|
| callback | AsyncCallback\<[number](#responsecode)\>       | Yes  | Callback used to return the result.                                     |

**Error codes**

| ID  | Error Message                                                        |
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

> **NOTE**
> For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [HTTP Error Codes](errorcode-net-http.md).
> The HTTP error code mapping is in the format of 2300000 + Curl error code. For more common error codes, see [Curl Error Codes](https://curl.se/libcurl/c/libcurl-errors.html).

**Example**

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
    method: http.RequestMethod.POST, // Optional. The default value is http.RequestMethod.GET.
    // This field is used to transfer the request body when a POST request is used. Its format needs to be negotiated with the server.
    extraData: 'data to send',
    expectDataType: http.HttpDataType.STRING, // Optional. This parameter specifies the type of the return data.
    usingCache: true, // Optional. The default value is true.
    priority: 1, // Optional. The default value is 1.
    // You can add header fields based on service requirements.
    header: new Header('application/json'),
    readTimeout: 60000, // Optional. The default value is 60000, in ms.
    connectTimeout: 60000 // Optional. The default value is 60000, in ms.
    usingProtocol: http.HttpProtocol.HTTP1_1, // Optional. The default protocol type is automatically specified by the system.
    usingProxy: false, // Optional. By default, network proxy is not used. This field is supported since API version 10.
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

Initiates an HTTP request containing specified options to a given URL. This API uses a promise to return the result, which is a streaming response.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type              | Mandatory| Description                                           |
| ------- | ------------------ | ---- | ----------------------------------------------- |
| url     | string             | Yes  | URL for initiating an HTTP request.                        |
| options | HttpRequestOptions | No  | Request options. For details, see [HttpRequestOptions](#httprequestoptions).|

**Return value**

| Type                                  | Description                             |
| :------------------------------------- | :-------------------------------- |
| Promise\<[number](#responsecode)\> | Promise used to return the result.|

**Error codes**

| ID  | Error Message                                                        |
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

> **NOTE**
> For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [HTTP Error Codes](errorcode-net-http.md).
> The HTTP error code mapping is in the format of 2300000 + Curl error code. For more common error codes, see [Curl Error Codes](https://curl.se/libcurl/c/libcurl-errors.html).

**Example**

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

Registers an observer for HTTP Response Header events.

> **NOTE**
> This API has been deprecated. You are advised to use [on("headersReceive")<sup>8+</sup>](#onheadersreceive8).

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                   | Mandatory| Description                             |
| -------- | ----------------------- | ---- | --------------------------------- |
| type     | string                  | Yes  | Event type. The value is **headerReceive**.|
| callback | AsyncCallback\<Object\> | Yes  | Callback used to return the result.                       |

**Example**

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

Unregisters the observer for HTTP Response Header events.

> **NOTE**
>
>1. This API has been deprecated. You are advised to use [off("headersReceive")<sup>8+</sup>](#offheadersreceive8).
>
>2. You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                   | Mandatory| Description                                 |
| -------- | ----------------------- | ---- | ------------------------------------- |
| type     | string                  | Yes  | Event type. The value is **headerReceive**.|
| callback | AsyncCallback\<Object\> | No  | Callback used to return the result.                           |

**Example**

```ts
import { http } from '@kit.NetworkKit';

let httpRequest = http.createHttp();
httpRequest.off("headerReceive");
```

### on("headersReceive")<sup>8+</sup>

on(type: "headersReceive", callback: Callback\<Object\>): void

Registers an observer for HTTP Response Header events.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type              | Mandatory| Description                              |
| -------- | ------------------ | ---- | ---------------------------------- |
| type     | string             | Yes  | Event type. The value is **headersReceive**.|
| callback | Callback\<Object\> | Yes  | Callback used to return the result.                        |

**Example**

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

Unregisters the observer for HTTP Response Header events.

> **NOTE**
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type              | Mandatory| Description                                  |
| -------- | ------------------ | ---- | -------------------------------------- |
| type     | string             | Yes  | Event type. The value is **headersReceive**.|
| callback | Callback\<Object\> | No  | Callback used to return the result.                            |

**Example**

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

Registers a one-time observer for HTTP Response Header events. Once triggered, the observer will be removed. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type              | Mandatory| Description                              |
| -------- | ------------------ | ---- | ---------------------------------- |
| type     | string             | Yes  | Event type. The value is **headersReceive**.|
| callback | Callback\<Object\> | Yes  | Callback used to return the result.                        |

**Example**

```ts
import { http } from '@kit.NetworkKit';

let httpRequest = http.createHttp();
httpRequest.once("headersReceive", (header: Object) => {
  console.info("header: " + JSON.stringify(header));
});
```

### on("dataReceive")<sup>10+</sup>

on(type: "dataReceive", callback: Callback\<ArrayBuffer\>): void

Registers an observer for events indicating receiving of HTTP streaming responses.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                   | Mandatory| Description                             |
| -------- | ----------------------- | ---- | --------------------------------- |
| type     | string                  | Yes  | Event type. The value is **dataReceive**.|
| callback | AsyncCallback\<ArrayBuffer\> | Yes  | Callback used to return the result.                       |

**Example**

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

Unregisters the observer for events indicating receiving of HTTP streaming responses.

> **NOTE**
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type              | Mandatory| Description                                  |
| -------- | ------------------ | ---- | -------------------------------------- |
| type     | string             | Yes  | Event type. The value is **dataReceive**.|
| callback | Callback\<ArrayBuffer\> | No  | Callback used to return the result.                            |

**Example**

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

Registers an observer for events indicating completion of receiving HTTP streaming responses.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                   | Mandatory| Description                             |
| -------- | ----------------------- | ---- | --------------------------------- |
| type     | string                  | Yes  | Event type. The value is **dataEnd**.|
| callback | AsyncCallback\<void\>   | Yes  | Callback used to return the result.                       |

**Example**

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

Unregisters the observer for events indicating completion of receiving HTTP streaming responses.

> **NOTE**
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type              | Mandatory| Description                                  |
| -------- | ------------------ | ---- | -------------------------------------- |
| type     | string             | Yes  | Event type. The value is **dataEnd**.|
| callback | Callback\<void\>   | No  | Callback used to return the result.                            |

**Example**

```ts
import { http } from '@kit.NetworkKit';

let httpRequest = http.createHttp();
httpRequest.on("dataEnd", () => {
  console.info("Receive dataEnd !");
});
httpRequest.off("dataEnd");
```

### on("dataReceiveProgress")<sup>10+</sup>

on(type: "dataReceiveProgress", callback: Callback\<DataReceiveProgressInfo\>): void

Registers an observer for events indicating progress of receiving HTTP streaming responses.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                   | Mandatory| Description                             |
| -------- | ----------------------- | ---- | --------------------------------- |
| type     | string                  | Yes  | Event type. The value is **dataReceiveProgress**.|
| callback | AsyncCallback\<[DataReceiveProgressInfo](#datareceiveprogressinfo11)\>   | Yes  | Callback used to return the data receiving progress.|

**Example**

```ts
import { http } from '@kit.NetworkKit';

let httpRequest = http.createHttp();
httpRequest.on("dataReceiveProgress", (data: http.DataReceiveProgressInfo) => {
  console.info("dataReceiveProgress:" + JSON.stringify(data));
});
httpRequest.off("dataReceiveProgress");
```

### off("dataReceiveProgress")<sup>10+</sup>

off(type: "dataReceiveProgress", callback?: Callback\<DataReceiveProgressInfo\>): void

Unregisters the observer for events indicating progress of receiving HTTP streaming responses.

> **NOTE**
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type              | Mandatory| Description                                  |
| -------- | ------------------ | ---- | -------------------------------------- |
| type     | string             | Yes  | Event type. The value is **dataReceiveProgress**.|
| callback | Callback\<[DataReceiveProgressInfo](#datareceiveprogressinfo11)\>   | No  | Callback used to return the data receiving progress.   |

**Example**

```ts
import { http } from '@kit.NetworkKit';

let httpRequest = http.createHttp();
httpRequest.on("dataReceiveProgress", (data: http.DataReceiveProgressInfo) => {
  console.info("dataReceiveProgress:" + JSON.stringify(data));
});
httpRequest.off("dataReceiveProgress");
```

### on("dataSendProgress")<sup>11+</sup>

on(type: "dataSendProgress", callback: Callback\<DataSendProgressInfo\>): void

Registers an observer for events indicating progress of sending HTTP requests.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                   | Mandatory| Description                             |
| -------- | ----------------------- | ---- | --------------------------------- |
| type     | string                  | Yes  | Event type. The value is **dataSendProgress**.|
| callback | AsyncCallback\<[DataSendProgressInfo](#datasendprogressinfo11)\>   | Yes  | Callback used to return the data sending progress.|

**Example**

```ts
import { http } from '@kit.NetworkKit';

let httpRequest = http.createHttp();
httpRequest.on("dataSendProgress", (data: http.DataSendProgressInfo) => {
  console.info("dataSendProgress:" + JSON.stringify(data));
});
httpRequest.off("dataSendProgress");
```

### off("dataSendProgress")<sup>11+</sup>

off(type: "dataSendProgress", callback?: Callback\<DataSendProgressInfo\>): void

Unregisters the observer for events indicating progress of sending HTTP requests.

> **NOTE**
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type              | Mandatory| Description                                  |
| -------- | ------------------ | ---- | -------------------------------------- |
| type     | string             | Yes  | Event type. The value is **dataSendProgress**.|
| callback | Callback\<[DataSendProgressInfo](#datasendprogressinfo11)\>  | No| Callback used to return the data sending progress.|

**Example**

```ts
import { http } from '@kit.NetworkKit';

let httpRequest = http.createHttp();
httpRequest.on("dataSendProgress", (data: http.DataSendProgressInfo) => {
  console.info("dataSendProgress:" + JSON.stringify(data));
});
httpRequest.off("dataSendProgress");
```

## HttpRequestOptions

Specifies the type and value range of the optional parameters in the HTTP request.

**System capability**: SystemCapability.Communication.NetStack

| Name        | Type                                         | Mandatory| Description                                                        |
| -------------- | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| method         | [RequestMethod](#requestmethod)               | No  | Request method. The default value is **GET**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                  |
| extraData      | string \| Object \| ArrayBuffer | No  | Additional data for sending a request. This parameter is not used by default.<br>- If the HTTP request uses a POST or PUT method, this field serves as the content of the HTTP request and is encoded in UTF-8 format. If **content-Type** is **application/x-www-form-urlencoded**, the data in the request body must be encoded in the format of **key1=value1&key2=value2&key3=value3** after URL transcoding (encodeURIComponent/encodeURI) and this field is usually in the String format. If **content-Type** is **text/xml**, this field is usually in the String format. If **content-Type** is **application/json**, this field is usually in the Object format. If **content-Type** is **application/octet-stream**, this field is usually in the ArrayBuffer format. If **content-Type** is **multipart/form-data** and the content to be uploaded is a file, this field is usually in the ArrayBuffer format. The preceding information is for reference only and may vary according to the actual situation.<br>- If the HTTP request uses the GET, OPTIONS, DELETE, TRACE, or CONNECT method, this parameter serves as a supplement to HTTP request parameters. Parameters of the string type need to be encoded before being passed to the HTTP request. Parameters of the object type do not need to be precoded and will be directly concatenated to the URL. Parameters of the ArrayBuffer type will not be concatenated to the URL.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| expectDataType<sup>9+</sup>  | [HttpDataType](#httpdatatype9)  | No  | Type of the returned data. This parameter is not used by default. If this parameter is set, the system returns the specified type of data preferentially. If the specified type is **Object**, the value can contain a maximum of 65536 characters.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| usingCache<sup>9+</sup>      | boolean                         | No  | Whether to use the cache. The default value is **true**. The cache takes effect with the current process. The new cache will replace the old one.<br>**Atomic service API**: This API can be used in atomic services since API version 11. |
| priority<sup>9+</sup>        | number                          | No  | Priority of concurrent HTTP/HTTPS requests. A larger value indicates a higher priority. The value range is [1,1000]. The default value is **1**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                          |
| header                       | Object                          | No  | HTTP request header. The default value is **{'content-Type': 'application/json'}**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.  |
| readTimeout                  | number                          | No  | Read timeout duration. The default value is **60000**, in ms.<br>The value **0** indicates no timeout.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| connectTimeout               | number                          | No  | Connection timeout interval. The default value is **60000**, in ms.<br>**Atomic service API**: This API can be used in atomic services since API version 11.             |
| usingProtocol<sup>9+</sup>   | [HttpProtocol](#httpprotocol9)  | No  | Protocol. The default value is automatically specified by the system.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                            |
| usingProxy<sup>10+</sup>     | boolean \| [HttpProxy](js-apis-net-connection.md#httpproxy10)               | No  | Whether to use HTTP proxy. The default value is **false**, which means not to use HTTP proxy.<br>- If **usingProxy** is of the **Boolean** type and the value is **true**, network proxy is used by default.<br>- If **usingProxy** is of the **HttpProxy** type, the specified network proxy is used.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| caPath<sup>10+</sup>     | string               | No  | Path of CA certificates. If a path is set, the system uses the CA certificates in this path. If a path is not set, the system uses the preset CA certificate, namely, **/etc/ssl/certs/cacert.pem**. This path is the sandbox mapping path, which can be obtained through **getContext().filesDir**. Currently, only **.pem** certificates are supported.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                            |
| resumeFrom<sup>11+</sup> | number | No| Download start position. This field can be used only for the GET method. According to section 3.1 of RFC 7233:<br>- If the HTTP PUT method is used, do not use this option because it may conflict with other options.<br>- The value ranges from **1** to **4294967296** (4 GB). If the value is out of this range, this field does not take effect.|
| resumeTo<sup>11+</sup> | number | No| Download end position. This field can be used only for the GET method. According to section 3.1 of RFC 7233:<br>- If the HTTP PUT method is used, do not use this option because it may conflict with other options.<br>- The value ranges from **1** to **4294967296** (4 GB). If the value is out of this range, this field does not take effect.|
| clientCert<sup>11+</sup> | [ClientCert](#clientcert11) | No| Client certificate.|
| dnsOverHttps<sup>11+</sup> | string | No| DNS resolution for a server that uses the HTTPS protocol.<br>The value must be URL-encoded in the following format: "https://host:port/path".|
| dnsServers<sup>11+</sup> | Array\<string\> | No| Array of DNS servers used for DNS resolution.<br>- You can set a maximum of three DNS servers. If there are more than three DNS servers, only the first three DNS servers are used.<br>- The DNS servers must be expressed as IPv4 or IPv6 addresses.|
| maxLimit<sup>11+</sup>   | number   | No| Maximum number of bytes in a response. The default value is **5\*1024\*1024**. The maximum value is **100\*1024\*1024**. |
| multiFormDataList<sup>11+</sup> | Array<[MultiFormData](#multiformdata11)> | No| Form data list. This field is valid when **content-Type** is set to **multipart/form-data**.|
| certificatePinning<sup>12+</sup> | [CertificatePinning](#certificatepinning12) \| CertificatePinning[] | No| Dynamic configuration of certificate pinning. One or more certificate PINs can be specified.|

## RequestMethod

Defines an HTTP request method.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

| Name   | Value     | Description               |
| :------ | ------- | :------------------ |
| OPTIONS | "OPTIONS" | Describes the communication options of the target resource.|
| GET     | "GET"     | Requests the representation of the specified resource. The GET request should only retrieve data and should not contain the request content.|
| HEAD    | "HEAD"    | Requests the same response (but does not have a response body) as the GET request.|
| POST    | "POST"    | Submits an entity to a specified resource, which usually causes a status change on the server.|
| PUT     | "PUT"     | Replaces all current representations of the target resource with the requested content.|
| DELETE  | "DELETE"  | Deletes the specified resource.|
| TRACE   | "TRACE"   | Performs a message loopback test along the path to the target resource.|
| CONNECT | "CONNECT" | Establishes a tunnel to the server identified by the target resource.|

## ResponseCode

Enumerates the response codes for an HTTP request.

**System capability**: SystemCapability.Communication.NetStack

| Name             | Value  | Description                                                        |
| ----------------- | ---- | ------------------------------------------------------------ |
| OK                | 200  | The request is successful. The request has been processed successfully. This return code is generally used for GET and POST requests.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                           |
| CREATED           | 201  | "Created." The request has been successfully sent and a new resource is created.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                          |
| ACCEPTED          | 202  | "Accepted." The request has been accepted, but the processing has not been completed.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                        |
| NOT_AUTHORITATIVE | 203  | "Non-Authoritative Information." The request is successful.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                      |
| NO_CONTENT        | 204  | "No Content." The server has successfully fulfilled the request but there is no additional content to send in the response payload body.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                      |
| RESET             | 205  | "Reset Content." The server has successfully fulfilled the request and desires that the user agent reset the content.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                  |
| PARTIAL           | 206  | "Partial Content." The server has successfully fulfilled the partial GET request for a given resource.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                     |
| MULT_CHOICE       | 300  | "Multiple Choices." The requested resource corresponds to any one of a set of representations.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                  |
| MOVED_PERM        | 301  | "Moved Permanently." The requested resource has been assigned a new permanent URI and any future references to this resource will be redirected to this URI.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| MOVED_TEMP        | 302  | "Moved Temporarily." The requested resource is moved temporarily to a different URI.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                  |
| SEE_OTHER         | 303  | "See Other." The response to the request can be found under a different URI.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                              |
| NOT_MODIFIED      | 304  | "Not Modified." The client has performed a conditional GET request and access is allowed, but the content has not been modified.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                    |
| USE_PROXY         | 305  | "Use Proxy." The requested resource can only be accessed through the proxy.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                  |
| BAD_REQUEST       | 400  | "Bad Request." The request could not be understood by the server due to incorrect syntax. <br>**Atomic service API**: This API can be used in atomic services since API version 11.                      |
| UNAUTHORIZED      | 401  | "Unauthorized." The request requires user authentication.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                    |
| PAYMENT_REQUIRED  | 402  | "Payment Required." This code is reserved for future use.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                            |
| FORBIDDEN         | 403  | "Forbidden." The server understands the request but refuses to process it.<br>**Atomic service API**: This API can be used in atomic services since API version 11.            |
| NOT_FOUND         | 404  | "Not Found." The server does not find anything matching the Request-URI.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                |
| BAD_METHOD        | 405  | "Method Not Allowed." The method specified in the request is not allowed for the resource identified by the Request-URI.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                  |
| NOT_ACCEPTABLE    | 406  | "Not Acceptable." The server cannot fulfill the request according to the content characteristics of the request. <br>**Atomic service API**: This API can be used in atomic services since API version 11.                |
| PROXY_AUTH        | 407  | "Proxy Authentication Required." The request requires user authentication with the proxy.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                    |
| CLIENT_TIMEOUT    | 408  | "Request Timeout." The client fails to generate a request within the timeout period.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                        |
| CONFLICT          | 409  | "Conflict." The request cannot be fulfilled due to a conflict with the current state of the resource. Conflicts are most likely to occur in response to a PUT request. <br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| GONE              | 410  | "Gone." The requested resource has been deleted permanently and is no longer available. <br>**Atomic service API**: This API can be used in atomic services since API version 11.                                |
| LENGTH_REQUIRED   | 411  | "Length Required." The server refuses to process the request without a defined Content-Length.<br>**Atomic service API**: This API can be used in atomic services since API version 11.    |
| PRECON_FAILED     | 412  | "Precondition Failed." The precondition in the request is incorrect.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                              |
| ENTITY_TOO_LARGE  | 413  | "Request Entity Too Large." The server refuses to process a request because the request entity is larger than the server is able to process. <br>**Atomic service API**: This API can be used in atomic services since API version 11.          |
| REQ_TOO_LONG      | 414  | "Request-URI Too Long." The Request-URI is too long for the server to process. <br>**Atomic service API**: This API can be used in atomic services since API version 11.            |
| UNSUPPORTED_TYPE  | 415  | "Unsupported Media Type." The server is unable to process the media format in the request. <br>**Atomic service API**: This API can be used in atomic services since API version 11.                                  |
| RANGE_NOT_SATISFIABLE<sup>12+</sup> | 416  | "Range Not Satisfiable." The server cannot serve the requested ranges.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                 |
| INTERNAL_ERROR    | 500  | "Internal Server Error." The server encounters an unexpected error that prevents it from fulfilling the request.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                              |
| NOT_IMPLEMENTED   | 501  | "Not Implemented." The server does not support the function required to fulfill the request.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                      |
| BAD_GATEWAY       | 502  | "Bad Gateway." The server acting as a gateway or proxy receives an invalid response from the upstream server.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| UNAVAILABLE       | 503  | "Service Unavailable." The server is currently unable to process the request due to a temporary overload or system maintenance.<br>**Atomic service API**: This API can be used in atomic services since API version 11.      |
| GATEWAY_TIMEOUT   | 504  | "Gateway Timeout." The server acting as a gateway or proxy does not receive requests from the remote server within the timeout period.<br>**Atomic service API**: This API can be used in atomic services since API version 11.        |
| VERSION           | 505  | "HTTP Version Not Supported." The server does not support the HTTP protocol version used in the request. <br>**Atomic service API**: This API can be used in atomic services since API version 11.                                |

## HttpResponse

Defines the response to an HTTP request.

**System capability**: SystemCapability.Communication.NetStack

| Name                | Type                                        | Mandatory| Description                                                         |
| -------------------- | -------------------------------------------- | ---- | ------------------------------------------------------------ |
| result               | string \| Object \| ArrayBuffer | Yes  | Response content returned based on **Content-type** in the response header. If **HttpRequestOptions** does not contain the **expectDataType** field, the response content is returned according to the following rules:<br>- application/json: string in JSON format<br>- application/octet-stream: ArrayBuffer<br>- image: ArrayBuffer<br>- Others: string<br> If **HttpRequestOptions** contains the **expectDataType** field, the response content must be of the same type as the data returned by the server.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| resultType<sup>9+</sup> | [HttpDataType](#httpdatatype9)             | Yes  | Type of the return value.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                          |
| responseCode         | [ResponseCode](#responsecode) \| number      | Yes  | Result code for an HTTP request. If the callback function is successfully executed, a result code defined in [ResponseCode](#responsecode) will be returned. Otherwise, an error code will be returned in the **err** field in **AsyncCallback**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| header               | Object                                       | Yes  | Response header. The return value is a string in JSON format. If you want to use specific content in the response, you need to implement parsing of that content. Common fields and parsing methods are as follows:<br>- content-type: header['content-type'];<br>- status-line: header['status-line'];<br>- date: header.date/header['date'];<br>- server: header.server/header['server'];<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| cookies<sup>8+</sup> | string                                       | Yes  | Original cookies returned by the server. How to process the cookies is up to your decision.<br>**Atomic service API**: This API can be used in atomic services since API version 11.              |
| performanceTiming<sup>11+</sup> | [PerformanceTiming](#performancetiming11) | Yes| Time consumed in each phase of an HTTP request.|

## ClientCert<sup>11+</sup>

Defines the client certificate type.

**System capability**: SystemCapability.Communication.NetStack

| Name| Type| Mandatory| Description|
| -------- | -------| --- | ----------- |
| certPath | string | Yes| Certificate path.|
| certType | [CertType](#certtype11) | No| Certificate type. The default value is **PEM**.|
| keyPath | string | Yes| Path of the certificate key file.|
| keyPassword | string | No | Password of the certificate key file.|

## PerformanceTiming<sup>11+</sup>

Configures the timing for performance tracing, in ms.

**System capability**: SystemCapability.Communication.NetStack

| Name      | Type  | Mandatory  | Description                  |
| ---------- | ------ | ---- | --------------------- |
| dnsTiming  | number | Yes  | Duration from the time when the [request](#request) is sent to the time when the DNS resolution is complete.|
| tcpTiming  | number | Yes  | Duration from the time when the [request](#request) is sent to the time when the TCP connection is complete.|
| tlsTiming  | number | Yes  | Duration from the time when the [request](#request) is sent to the time when the TLS connection is complete.|
| firstSendTiming  | number | Yes  | Duration from the time when the [request](#request) is sent to the time when the first byte is sent.|
| firstReceiveTiming  | number | Yes  | Duration from the time when the [request](#request) is sent to the time when the first byte is received.|
| totalFinishTiming  | number | Yes  | Duration from the time when the [request](#request) is sent to the time when the request is complete.|
| redirectTiming  | number | Yes  | Duration from the time when the [request](#request) is sent to the time when all redirection steps are complete.|
| responseHeaderTiming  | number | Yes  | Duration from the time when the [request](#request) is sent to the time when the header resolution is complete.|
| responseBodyTiming  | number | Yes  | Duration from the time when the [request](#request) is sent to the time when the body resolution is complete.|
| totalTiming  | number | Yes  | Duration from the time when the [request](#request) is sent to the time when a callback is returned to the application.|

## DataReceiveProgressInfo<sup>11+</sup>

Defines the data receiving progress information.

**System capability**: SystemCapability.Communication.NetStack

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
|  receiveSize        | number | Yes | Size of data that has been received, in bytes.          |
| totalSize| number | Yes| Total size of data to be received, in bytes.|

## DataSendProgressInfo<sup>11+</sup>

Defines the data sending progress information.

**System capability**: SystemCapability.Communication.NetStack

### Attributes

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| sendSize        | number | Yes | Size of data to be sent, in bytes. |
| totalSize | number | Yes| Total size of data to be sent, in bytes.|

## MultiFormData<sup>11+</sup>

Defines the type of multi-form data.

**System capability**: SystemCapability.Communication.NetStack

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| name        | string | Yes | Data name.                                                                     |
| contentType | string | Yes| Data type, for example, **text/plain**, **image/png**, **image/jpeg**, **audio/mpeg**, or **video/mp4**.|
| remoteFileName | string | No| Name of the file uploaded to the server.                                                |
| data | string \| Object \| ArrayBuffer | No| Form data content.                                                |
| filePath | string | No| File path. This field is used to configure the MIME body content based on the file content. This field is used as the substitute of **data** to set the file data as data content. If **data** is empty, **filePath** must be set. If **data** is present, **filePath** does not take effect.|

## http.createHttpResponseCache<sup>9+</sup>

createHttpResponseCache(cacheSize?: number): HttpResponseCache

Creates an **HttpResponseCache** object that stores the response data of HTTP requests. You can call the **flush** or **delete** method as needed in the object. **cacheSize** specifies the cache size.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| cacheSize | number | No| Cache size. The maximum value is 10\*1024\*1024 (10 MB). By default, the maximum value is used.|

**Return value**

| Type       | Description                                                        |
| :---------- | :----------------------------------------------------------- |
| [HttpResponseCache](#httpresponsecache9) | Object that stores the response to the HTTP request.|

**Example**

```ts
import { http } from '@kit.NetworkKit';

let httpResponseCache = http.createHttpResponseCache();
```

## HttpResponseCache<sup>9+</sup>

Defines an object that stores the response to an HTTP request. Before invoking APIs provided by **HttpResponseCache**, you must call [createHttpResponseCache()](#httpcreatehttpresponsecache9) to create an **HttpRequestTask** object.

**Usage of Keywords in the Response Header**

- `Cache-Control`: specifies the cache policy, for example, `no-cache`, `no-store`, `max-age`, `public`, or `private`.

- `Expires`: specifies the expiration time of a resource. The value is in the GMT format.

- `ETag`: identifies the resource version. The client can use the `If-None-Match` request header to check whether the resource has been modified.

- `Last-Modified`: specifies the last modification time of a resource. The client can use the `If-Modified-Since` request header to check whether a resource has been modified.

- `Vary`: specifies the parts of the request header that affect the cached response. This field is used to distinguish different cache versions.

When using these keywords, ensure that the response header is correctly configured on the server. The client determines whether to use the cached resource and how to verify whether the resource is the latest based on the response header. Correct cache policies help to improve application performance and user experience.

**How to Set the Cache-Control Header**

`Cache-Control` is a common header, but it is usually used on the server. It allows you to define when, how, and how long a response should be cached. The following are some common `Cache-Control` directives:

1. `no-cache`: indicates that the response can be stored in the cache, but it must be verified with the origin server before each reuse. If the resource remains unchanged, the response status code is 304 (Not Modified). In this case, the resource content is not sent, and the resource in the cache is used. If the resource has expired, the response status code is 200 and the resource content is sent.

2. `no-store`: indicates that resources cannot be cached. Resources must be obtained from the server for each request.

3. `max-age`: specifies the maximum cache duration, in seconds. For example, `Cache-Control: max-age=3600` indicates that the valid cache duration is 3,600 seconds (that is, 1 hour).

4. `public` indicates that the response can be cached by any object, for example, the client that sends the request or the proxy server.

5. `private`: indicates that the response can be cached only by a single user and cannot be used as a shared cache (that is, the response cannot be cached by the proxy server).

6. `must-revalidate`: indicates that the response can be cached and can only be reused 

7. `no-transform`: indicates that the proxy server is not allowed to modify the response content.

8. `proxy-revalidate`: works in a way similar to `must-revalidate`, but applies only to shared caches.

9. `s-maxage`: works in a way similar to `max-age`, but applies only to shared caches.

### flush<sup>9+</sup>

flush(callback: AsyncCallback\<void\>): void

Flushes cached data to the file system so that the data can be accessed in the next HTTP request. This API uses an asynchronous callback to return the result. Cached data includes the response header (header), response body (result), cookies, request time (requestTime), and response time (responseTime).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

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
    // Call destroy() to destroy the JavaScript object after the HTTP request is complete.
    httpRequest.destroy();
  }
});
```

### flush<sup>9+</sup>

flush(): Promise\<void\>

Flushes cached data to the file system so that the data can be accessed in the next HTTP request. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Example**

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

Disables the cache and deletes the data in it. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

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

Disables the cache and deletes the data in it. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Example**

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

Enumerates HTTP data types.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

| Name| Value| Description    |
| ------------------  | -- | ----------- |
| STRING              | 0 | String type.|
| OBJECT              | 1 | Object type.   |
| ARRAY_BUFFER        | 2 | Binary array type.|

## HttpProtocol<sup>9+</sup>

Enumerates HTTP protocol versions.

**System capability**: SystemCapability.Communication.NetStack

| Name | Description    |
| :-------- | :----------- |
| HTTP1_1   |  HTTP1.1<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| HTTP2     |  HTTP2<br>**Atomic service API**: This API can be used in atomic services since API version 11.  |
| HTTP3<sup>11+</sup> | HTTP3 protocol. If the system or server does not support HTTP3, the HTTP protocol of an earlier version is used.<br>This field is valid only for HTTPS URLs. For HTTP URLs, the request fails.|

## CertType<sup>11+</sup>

Enumerates certificate types.

**System capability**: SystemCapability.Communication.NetStack

| Name| Description      |
| --- | ---------- |
| PEM | PEM certificate.|
| DER | DER certificate.|
| P12 | P12 certificate.|

## CertificatePinning<sup>12+</sup>

Defines the dynamic configuration of certificate pinning.

**System capability**: SystemCapability.Communication.NetStack

|  Name |  Type |  Mandatory |Description    |
| ------------------  |---- |-- | ----------- |
| publicKeyHash       | string | Yes|Certificate PIN of the string type.|
| hashAlgorithm        | 'SHA-256' |  Yes |Encryption algorithm. Currently, only SHA-256 is supported.|
