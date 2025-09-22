# @ohos.net.http (Data Request)

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

The **http** module provides APIs for implementing HTTP data request capabilities. An application can initiate a data request over HTTP. Common HTTP methods include **GET**, **POST**, **OPTIONS**, **HEAD**, **PUT**, **DELETE**, **TRACE**, and **CONNECT**.

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
## Modules to Import

```ts
import { http } from '@kit.NetworkKit';
```

## Example

>**NOTE**
>
>In the sample code provided in this topic, **this.context** is used to obtain **UIAbilityContext**, where **this** indicates a UIAbility instance inherited from **UIAbility**. To use **UIAbilityContext** APIs on pages, see [Obtaining the Context of UIAbility](../../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

<!--code_no_check-->
```ts
// Import the http namespace.
import { http } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

let context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;
// Each httpRequest corresponds to an HTTP request task and cannot be reused.
let httpRequest = http.createHttp();
// This API is used to listen for HTTP Response Header events, which is returned earlier than the result of the HTTP request. It is up to you whether to listen for HTTP response header events.
// on('headerReceive', AsyncCallback) is replaced by on('headersReceive', Callback) since API version 8.
httpRequest.on('headersReceive', (header: Object) => {
  console.info('header: ' + JSON.stringify(header));
});

httpRequest.request(// Customize EXAMPLE_URL in extraData on your own. It is up to you whether to add parameters to the URL.
  "EXAMPLE_URL",
  {
    method: http.RequestMethod.POST, // Optional. The default value is http.RequestMethod.GET.
    // This field is used to transfer the request body when a POST request is used. Its format needs to be negotiated with the server.
    extraData: 'data to send',
    expectDataType: http.HttpDataType.STRING, // Optional. This parameter specifies the type of the return data.
    usingCache: true, // Optional. The default value is true.
    priority: 1, // Optional. The default value is 1.
    // You can add header fields based on service requirements. Note that map objects cannot be passed to header fields.
    header: { 'Accept' : 'application/json' },
    readTimeout: 60000, // Optional. The default value is 60000, in ms.
    connectTimeout: 60000 // Optional. The default value is 60000, in ms.
    usingProtocol: http.HttpProtocol.HTTP1_1, // Optional. The default protocol type is automatically specified by the system.
    usingProxy: false, // Optional. By default, network proxy is not used. This field is supported since API version 10.
    caPath: '/path/to/cacert.pem', // Optional. The preset CA certificate is used by default. This field is supported since API version 10.
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
        '-----END CERTIFICATE-----', // Optional. The preset CA certificate is used by default. This field is supported since API version 20.
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
        filePath: `${context.filesDir}/fileName.txt`, // File path, optional. This field is supported since API version 11.
        remoteFileName: 'fileName.txt' // Optional. This field is supported since API version 11.
      }
    ],
    addressFamily: http.AddressFamily.DEFAULT // Optional. By default, the IPv4 or IPv6 address of the target domain name is selected. This attribute is supported since API version 15.
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
      console.error('error:' + JSON.stringify(err));
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

Creates an HTTP request. You can use this API to initiate or destroy an HTTP request, or enable or disable listening for HTTP Response Header events. To initiate multiple HTTP requests, you must create an **HttpRequest** object for each HTTP request. An **HttpRequest** object corresponds to an HTTP request.

> **NOTE**
> Call **destroy()** to destroy the **HttpRequest** object when it is no longer needed. Otherwise, resource leakage may occur.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type       | Description                                                        |
| :---------- | :----------------------------------------------------------- |
| HttpRequest | An **HttpRequest** object, which contains the **request**, **requestInStream**, **destroy**, **on**, or **off** method.|

**Example**

```ts
import { http } from '@kit.NetworkKit';

let httpRequest = http.createHttp();
```

## HttpRequest

Defines an HTTP request task. Before invoking APIs provided by **HttpRequest**, you must call [createHttp()](#httpcreatehttp) to create an **HttpRequestTask** object.

### request

request(url: string, callback: AsyncCallback\<HttpResponse\>): void

Initiates an HTTP request to a given URL. This API uses an asynchronous callback to return the result. 

> **NOTE**
>
>(1) This API can receive only data whose size is less than 5 MB. If the data size exceeds 5 MB, you need to set **maxLimit** to a larger value in [HttpRequestOptions](#httprequestoptions) or call [requestInStream](#requestinstream10) to initiate a streaming request.<br>
>(2) If you need to pass in cookies, add them to the **options** parameter.<br>
>(3) If the URL contains non-English characters, call **encodeURL(url)** to encode the URL before initiating an HTTP request.

**Required permissions**: ohos.permission.INTERNET

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                          | Mandatory| Description                   |
| -------- | ---------------------------------------------- | ---- | ---------------------- |
| url      | string                                         | Yes  | URL for initiating an HTTP request.|
| callback | AsyncCallback\<[HttpResponse](#httpresponse)\> | Yes  | Callback used to return the result.   |

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [HTTP Error Codes](errorcode-net-http.md).<br>
The HTTP error code mapping is in the format of 2300000 + Curl error code. For more common error codes, see [Curl Error Codes](https://curl.se/libcurl/c/libcurl-errors.html).

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
| 2300997 | Cleartext traffic not permitted.                               |
| 2300998 | It is not allowed to access this domain.                       |
| 2300999 | Internal error.                                                 |


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
    console.error('error:' + JSON.stringify(err));
  }
});
```

### request

request(url: string, options: HttpRequestOptions, callback: AsyncCallback\<HttpResponse\>):void

Initiates an HTTP request containing specified options to a given URL. This API uses an asynchronous callback to return the result.

> **NOTE**
>
>(1) This API can receive only data whose size is less than 5 MB. If the data size exceeds 5 MB, you need to set **maxLimit** to a larger value in [HttpRequestOptions](#httprequestoptions) or call [requestInStream](#requestinstream10) to initiate a streaming request.<br>
>(2) If you need to pass in cookies, add them to the **options** parameter.<br>
>(3) If the URL contains non-English characters, call **encodeURL(url)** to encode the URL before initiating an HTTP request.

**Required permissions**: ohos.permission.INTERNET

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                          | Mandatory| Description                                           |
| -------- | ---------------------------------------------- | ---- | ----------------------------------------------- |
| url      | string                                         | Yes  | URL for initiating an HTTP request.                        |
| options  | HttpRequestOptions                             | Yes  | Request options. For details, see [HttpRequestOptions](#httprequestoptions).|
| callback | AsyncCallback\<[HttpResponse](#httpresponse)\> | Yes  | Callback used to return the result. If the operation is successful, the callback content is an [HttpResponse](#httpresponse) object; otherwise, the callback content is undefined.                       |

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [HTTP Error Codes](errorcode-net-http.md).<br>
The HTTP error code mapping is in the format of 2300000 + Curl error code. For more common error codes, see [Curl Error Codes](https://curl.se/libcurl/c/libcurl-errors.html).

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
| 2300997 | Cleartext traffic not permitted.                               |
| 2300998 | It is not allowed to access this domain.                       |
| 2300999 | Internal error.                                                 |

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
    console.error('error:' + JSON.stringify(err));
  }
});
```

### request

request(url: string, options? : HttpRequestOptions): Promise\<HttpResponse\>

Initiates an HTTP request containing specified options to a given URL. This API uses a promise to return the result. 

> **NOTE**
>
>(1) This API can receive only data whose size is less than 5 MB. If the data size exceeds 5 MB, you need to set **maxLimit** to a larger value in [HttpRequestOptions](#httprequestoptions) or call [requestInStream](#requestinstream10) to initiate a streaming request.<br>
>(2) If you need to pass in cookies, add them to the **options** parameter.<br>
>(3) If the URL contains non-English characters, call **encodeURL(url)** to encode the URL before initiating an HTTP request.

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

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [HTTP Error Codes](errorcode-net-http.md).<br>
The HTTP error code mapping is in the format of 2300000 + Curl error code. For more common error codes, see [Curl Error Codes](https://curl.se/libcurl/c/libcurl-errors.html).

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
| 2300997 | Cleartext traffic not permitted.                               |
| 2300998 | It is not allowed to access this domain.                       |
| 2300999 | Internal error.                                                 |

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
  console.error('error:' + JSON.stringify(err));
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

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                          | Mandatory| Description                                           |
| -------- | ---------------------------------------------- | ---- | ----------------------------------------------- |
| url      | string                                         | Yes  | URL for initiating an HTTP request.                        |
| callback | AsyncCallback\<number\>       | Yes  | Callback used to return the result.                                     |

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [HTTP Error Codes](errorcode-net-http.md).<br>
The HTTP error code mapping is in the format of 2300000 + Curl error code. For more common error codes, see [Curl Error Codes](https://curl.se/libcurl/c/libcurl-errors.html).

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
| 2300997 | Cleartext traffic not permitted.                               |
| 2300998 | It is not allowed to access this domain.                       |
| 2300999 | Internal error.                                                 |

**Example**

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

Initiates an HTTP request containing specified options to a given URL. This API uses an asynchronous callback to return the result, which is a streaming response.

**Required permissions**: ohos.permission.INTERNET

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                          | Mandatory| Description                                           |
| -------- | ---------------------------------------------- | ---- | ----------------------------------------------- |
| url      | string                                         | Yes  | URL for initiating an HTTP request.                        |
| options  | HttpRequestOptions                             | Yes  | Request options. For details, see [HttpRequestOptions](#httprequestoptions).|
| callback | AsyncCallback\<[number](#responsecode)\>       | Yes  | Callback used to return the result.                                     |

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [HTTP Error Codes](errorcode-net-http.md).<br>
The HTTP error code mapping is in the format of 2300000 + Curl error code. For more common error codes, see [Curl Error Codes](https://curl.se/libcurl/c/libcurl-errors.html).

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
| 2300997 | Cleartext traffic not permitted.                               |
| 2300998 | It is not allowed to access this domain.                       |
| 2300999 | Internal error.                                                 |

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
    console.error("requestInStream ERROR : err = " + JSON.stringify(err));
  }
})
```

### requestInStream<sup>10+</sup>

requestInStream(url: string, options? : HttpRequestOptions): Promise\<number\>

Initiates an HTTP request containing specified options to a given URL. This API uses a promise to return the result, which is a streaming response.

**Required permissions**: ohos.permission.INTERNET

**Atomic service API**: This API can be used in atomic services since API version 15.

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

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [HTTP Error Codes](errorcode-net-http.md).<br>
The HTTP error code mapping is in the format of 2300000 + Curl error code. For more common error codes, see [Curl Error Codes](https://curl.se/libcurl/c/libcurl-errors.html).

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
| 2300997 | Cleartext traffic not permitted.                               |
| 2300998 | It is not allowed to access this domain.                       |
| 2300999 | Internal error.                                                 |

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
  console.error("requestInStream ERROR : err = " + JSON.stringify(err));
});
```

### on("headerReceive")<sup>(deprecated)</sup>

on(type: "headerReceive", callback: AsyncCallback\<Object\>): void

Registers an observer for HTTP Response Header events.

> **NOTE**
> This API is supported since API version 6 and deprecated since API version 8. You are advised to use [on("headersReceive")<sup>8+</sup>](#onheadersreceive8) instead.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                   | Mandatory| Description                             |
| -------- | ----------------------- | ---- | --------------------------------- |
| type     | string                  | Yes  | Event type. The value is **headerReceive**.|
| callback | AsyncCallback\<Object\> | Yes  | Callback used to return the result. If the operation is successful, **error** is **undefined**, and **data** is the received HTTP response header. Otherwise, **error** is an error object.|

**Example**

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

Unregisters the observer for HTTP Response Header events.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 8. You are advised to use [off("headersReceive")<sup>8+</sup>](#offheadersreceive8) instead.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                   | Mandatory| Description                                 |
| -------- | ----------------------- | ---- | ------------------------------------- |
| type     | string                  | Yes  | Event type. The value is **headerReceive**.|
| callback | AsyncCallback\<Object\> | No  | Callback used to return the result. You can pass the callback of the **on** function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.                          |

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

| Name  | Type              | Mandatory| Description                       |
| -------- | ------------------ | ---- |---------------------------|
| type     | string             | Yes  | Event type. The value is **headersReceive**.|
| callback | Callback\<Object\> | Yes  | Callback used to return the HTTP response header.        |

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

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type              | Mandatory| Description                                  |
| -------- | ------------------ | ---- | -------------------------------------- |
| type     | string             | Yes  | Event type. The value is **headersReceive**.|
| callback | Callback\<Object\> | No  | Callback used to return the result. You can pass the callback of the **on** function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.                            |

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

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type              | Mandatory| Description                              |
| -------- | ------------------ | ---- | ---------------------------------- |
| type     | string             | Yes  | Event type. The value is **headersReceive**.|
| callback | Callback\<Object\> | Yes  | Callback used to return the HTTP response header.                        |

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

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                   | Mandatory| Description                             |
| -------- | ----------------------- | ---- | --------------------------------- |
| type     | string                  | Yes  | Event type. The value is **dataReceive**.|
| callback | Callback\<ArrayBuffer\> | Yes  | Callback used to return the result. If the operation is successful, **error** is **undefined**, and **data** is the received HTTP streaming data of the ArrayBuffer type. Otherwise, **error** is an error object.|

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

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type              | Mandatory| Description                                  |
| -------- | ------------------ | ---- | -------------------------------------- |
| type     | string             | Yes  | Event type. The value is **dataReceive**.|
| callback | Callback\<ArrayBuffer\> | No  | Callback used to return the result. You can pass the callback of the **on** function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.                            |

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

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                   | Mandatory| Description                             |
| -------- | ----------------------- | ---- | --------------------------------- |
| type     | string                  | Yes  | Event type. The value is **dataEnd**.|
| callback | Callback\<void\>   | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an **Error** object.                       |

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

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type              | Mandatory| Description                                  |
| -------- | ------------------ | ---- | -------------------------------------- |
| type     | string             | Yes  | Event type. The value is **dataEnd**.|
| callback | Callback\<void\>   | No  | Callback used to return the result. You can pass the callback of the **on** function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.                            |

**Example**

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

Registers an observer for events indicating progress of receiving HTTP streaming responses.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                   | Mandatory| Description                             |
| -------- | ----------------------- | ---- | --------------------------------- |
| type     | string                  | Yes  | Event type. The value is **dataReceiveProgress**.|
| callback | Callback\<[DataReceiveProgressInfo](#datareceiveprogressinfo11)\>   | Yes  | Callback used to return the result. If the operation is successful, the callback content is a [DataReceiveProgressInfo](#datareceiveprogressinfo11) object; otherwise, the callback content is **undefined**.|

**Example**

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

Unregisters the observer for events indicating progress of receiving HTTP streaming responses.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type              | Mandatory| Description                                  |
| -------- | ------------------ | ---- | -------------------------------------- |
| type     | string             | Yes  | Event type. The value is **dataReceiveProgress**.|
| callback | Callback\<[DataReceiveProgressInfo](#datareceiveprogressinfo11)\>   | No  | Callback used to return the result. You can pass the callback of the **on** function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.   |

**Example**

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

Registers an observer for events indicating progress of sending HTTP requests.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                   | Mandatory| Description                             |
| -------- | ----------------------- | ---- | --------------------------------- |
| type     | string                  | Yes  | Event type. The value is **dataSendProgress**.|
| callback | Callback\<[DataSendProgressInfo](#datasendprogressinfo11)\>   | Yes  | Callback used to return the result. If the operation is successful, the callback content is a [DataSendProgressInfo](#datasendprogressinfo11) object; otherwise, the callback content is **undefined**.|

**Example**

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

Unregisters the observer for events indicating progress of sending HTTP requests.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type              | Mandatory| Description                                  |
| -------- | ------------------ | ---- | -------------------------------------- |
| type     | string             | Yes  | Event type. The value is **dataSendProgress**.|
| callback | Callback\<[DataSendProgressInfo](#datasendprogressinfo11)\>  | No| Callback used to return the result. You can pass the callback of the **on** function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.|

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

Defines the options for initiating an HTTP request.

**System capability**: SystemCapability.Communication.NetStack

| Name        | Type                                         | Read Only| Optional| Description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
| -------------- | --------------------------------------------- | ---- |----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| method         | [RequestMethod](#requestmethod)               | No | Yes | Request method. The default value is **GET**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |
| extraData      | string \| Object \| ArrayBuffer | No | Yes | Additional data for sending a request. This parameter is not used by default.<br>**Note**: Do not add this parameter if no extra data is available. If this parameter must be added, set it to **undefined** or **null**. Do not pass the parameter as "".<br>- If the HTTP request uses a POST or PUT method, this field serves as the content of the HTTP request and is encoded in UTF-8 format.<br>Example:<br>  (1) If **content-Type** is **application/x-www-form-urlencoded**, the data in the request body must be encoded in the format of **key1=value1&key2=value2&key3=value3** after URL transcoding (**encodeURIComponent/encodeURI**) and this field is usually in the String format.<br>(2) If **content-Type** is **text/xml**, this field is usually in the String format.<br>(3) If **content-Type** is **application/json**, this field is usually in the Object format.<br>(4) If **content-Type** is **application/octet-stream**, this field is usually in the ArrayBuffer format.<br>(5) If **content-Type** is **multipart/form-data** and the content to be uploaded is a file, this field is usually in the ArrayBuffer format.<br>The preceding information is for reference only and may vary according to the actual situation.<br>- If the HTTP request uses the GET, OPTIONS, DELETE, TRACE, or CONNECT method, this parameter serves as a supplement to HTTP request parameters. Parameters of the string type need to be encoded before being passed to the HTTP request. Parameters of the object type do not need to be precoded and will be directly concatenated to the URL. Parameters of the ArrayBuffer type will not be concatenated to the URL.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| expectDataType<sup>9+</sup>  | [HttpDataType](#httpdatatype9)  | No | Yes | Type of the returned data. This parameter is not used by default. If this parameter is set, the system returns the specified type of data preferentially. If the specified type is **Object**, the value can contain a maximum of 65536 characters.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| usingCache<sup>9+</sup>      | boolean                         | No | Yes | Whether to use the cache. The value **true** indicates that the cache is preferentially read when a request is initiated, and the value **false** indicates that the cache is not used. The default value is **true**. The cache function takes effect when the process is started. The new cached data will replace the existing cached data.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
| priority<sup>9+</sup>        | number                          | No | Yes | Priority of concurrent HTTP/HTTPS requests. A larger value indicates a higher priority. The value range is [1, 1000]. The default value is **1**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
| header                       | Object                          | No | Yes | HTTP request header. If the request method is POST, PUT, DELETE, or null, the default value is {'content-Type': 'application/json'}. Otherwise, the default value is {'content-Type': 'application/x-www-form-urlencoded'}.<br>If the header contains fields of numeric type, the maximum value must be an int64 integer.<br>The **header** field does not support map objects.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| readTimeout                  | number                          | No | Yes | Read timeout duration. The default value is **60000**, in ms. The input value must be an uint32_t integer.<br>The value **0** indicates no timeout.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| connectTimeout               | number                          | No | Yes | Connection timeout interval. The default value is **60000**, in ms. The input value must be an uint32_t integer.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| usingProtocol<sup>9+</sup>   | [HttpProtocol](#httpprotocol9)  | No | Yes | Protocol. The default value is automatically specified by the system.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| usingProxy<sup>10+</sup>     | boolean \| [HttpProxy](js-apis-net-connection.md#httpproxy10)               | No | Yes | HTTP proxy configuration. If this parameter is not set, no proxy is used.<br>- If **usingProxy** is set to **true**, the default network proxy is used. If **usingProxy** is set to **false**, no proxy is used.<br>- If **usingProxy** is of the **HttpProxy** type, the specified network proxy is used. Currently, **username** and **password** cannot be specified for **HttpProxy**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| caPath<sup>10+</sup>     | string               | No | Yes | CA certificate path. If the CA certificate path is set, the system uses the CA certificate in the specified path. Otherwise, the system uses the preset CA certificate.<br>The preset CA certificate is available at **/etc/ssl/certs/cacert.pem**. This path is the sandbox mapping path, which can be obtained by using **UIAbilityContext** APIs. Currently, only **.pem** certificates are supported.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
| caData<sup>20+</sup>     | string               | No | Yes | CA certificate data. If this parameter is set and the certificate is valid, the system uses the specified CA certificate and the preset CA certificate. Otherwise, the system uses only the preset CA certificate. If both **caPath** and **caData** are set, **caData** is ignored by the system. Currently, only certificates in **.pem** format are supported. The maximum length is 8000 bytes. Only one certificate can be specified. A certificate chain is not allowed.<br>The preset CA certificate is available at **/etc/ssl/certs/cacert.pem**. This path is the sandbox mapping path, which can be obtained by using **UIAbilityContext** APIs.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|
| resumeFrom<sup>11+</sup> | number | No| Yes| Download start position. This field can be used only for the GET method. As stipulated in section 3.1 of RFC 7233, servers are allowed to ignore range requests.<br>- If the HTTP PUT method is used, do not use this option because it may conflict with other options.<br>- The value ranges from **1** to **4294967296** (4 GB). If the value is out of this range, this field does not take effect.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| resumeTo<sup>11+</sup> | number | No| Yes| Download end position. This field can be used only for the GET method. As stipulated in section 3.1 of RFC 7233, servers are allowed to ignore range requests.<br>- If the HTTP PUT method is used, do not use this option because it may conflict with other options.<br>- The value ranges from **1** to **4294967296** (4 GB). If the value is out of this range, this field does not take effect.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| clientCert<sup>11+</sup> | [ClientCert](#clientcert11) | No| Yes| Client certificate.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
| dnsOverHttps<sup>11+</sup> | string | No| Yes| Specifies whether to use an HTTPS server for DNS resolution.<br>- The value must be URL-encoded in the following format: "https://host:port/path".                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
| dnsServers<sup>11+</sup> | Array\<string\> | No| Yes| Array of DNS servers used for DNS resolution.<br>- A maximum of three DNS servers can be set. If there are more than three DNS servers, only the first three DNS servers are used.<br>- The DNS servers must be expressed as IPv4 or IPv6 addresses.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| maxLimit<sup>11+</sup>   | number   | No| Yes| Maximum number of bytes in a response.<br>The default value is 5\*1024\*1024, in bytes. The maximum value is **100\*1024\*1024**.<br>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |
| multiFormDataList<sup>11+</sup> | Array<[MultiFormData](#multiformdata11)> | No| Yes| Form data list. This field is valid when **content-Type** is set to **multipart/form-data**.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| certificatePinning<sup>12+</sup> | [CertificatePinning](#certificatepinning12) \| CertificatePinning[] | No| Yes| Dynamic configuration of certificate pinning. One or more certificate PINs can be specified.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |
| addressFamily<sup>15+</sup> | [AddressFamily](#addressfamily15) | No| Yes| IP address family. You can specify an address type for domain name resolution.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                |
| remoteValidation<sup>18+</sup> | [RemoteValidation](#remotevalidation18)                             | No| Yes| Certificate authority (CA), which is used to verify the identity of a remote server. If the parameter is not set, the default value is used. The options are as follows:<br>**Atomic service API**: This API can be used in atomic services since API version 18.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| tlsOptions<sup>18+</sup> | [TlsOptions](#tlsoptions18)                                         | No| Yes| TLS configuration.<br>**Atomic service API**: This API can be used in atomic services since API version 18.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| serverAuthentication<sup>18+</sup> | [ServerAuthentication](#serverauthentication18)                     | No| Yes| Indicates whether to verify the server identity during a secure connection. The identity is not verified by default.<br>**Atomic service API**: This API can be used in atomic services since API version 18.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
| sslType<sup>20+</sup> | [SslType](#ssltype20) | No| Yes| Security communication protocol. You can use TLS (default) or TLCP. If TLCP is used, all TLS-related options (such as **caPath**, **caData**, and **clientCert**) will be ignored.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|
| clientEncCert<sup>20+</sup> | [ClientCert](#clientcert11) | No| Yes| Client certificate, which is used by the server to verify the client identity.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|

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
| OK                | 200  | The request is successful. This return code is generally used for GET and POST requests.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                           |
| CREATED           | 201  | "Created." The request has been successfully sent and a new resource is created.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                          |
| ACCEPTED          | 202  | "Accepted." The request has been accepted for processing, but the processing has not been completed.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                        |
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
| PAYMENT_REQUIRED  | 402  |  "Payment Required." This code is reserved for future use.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                            |
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

| Name  | Type                                          | Read Only| Optional|Description                   |
| -------- | ---------------------------------------------- | ---- | --- | ---------------------- |
| result               | string \| Object \| ArrayBuffer | No  | No  | Response content returned based on **Content-type** in the response header. If **HttpRequestOptions** does not contain the **expectDataType** field, the response content is returned according to the following rules:<br>- application/json: string in JSON format<br>- application/octet-stream: ArrayBuffer<br>- image: ArrayBuffer<br>- Others: string<br> If **HttpRequestOptions** contains the **expectDataType** field, the response content must be of the same type as the data returned by the server.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| resultType<sup>9+</sup> | [HttpDataType](#httpdatatype9)             | No  | No  | Type of the return value.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                          |
| responseCode         | [ResponseCode](#responsecode) \| number      | No  | No  | Result code for an HTTP request. If the callback function is successfully executed, a result code defined in [ResponseCode](#responsecode) will be returned. Otherwise, an error code will be returned in the **err** field in **AsyncCallback**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| header               | Object                                       | No  | No | Response header. The return value is a string in JSON format. If you want to use specific content in the response, you need to implement parsing of that content. Common fields and parsing methods are as follows:<br>- content-type: header['content-type']<br>- status-line: header['status-line']<br>- date: header.date/header['date']<br>- server: header.server/header['server']<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| cookies<sup>8+</sup> | string                                       | No  | No  | Original cookies returned by the server. How to process the cookies is up to your decision.<br>**Atomic service API**: This API can be used in atomic services since API version 11.              |
| performanceTiming<sup>11+</sup> | [PerformanceTiming](#performancetiming11) | No  | No| Time consumed in each phase of an HTTP request.|

## ClientCert<sup>11+</sup>

Defines the client certificate type.

**System capability**: SystemCapability.Communication.NetStack

| Name  | Type                                          | Read Only| Optional|Description                   |
| -------- | ---------------------------------------------- | ---- | --- | ---------------------- |
| certPath | string | No  | No| Path of the certificate file.|
| certType | [CertType](#certtype11) | No  | Yes| Certificate type. The default value is **PEM**.|
| keyPath | string | No  | No| Path of the certificate key file.|
| keyPassword | string | No  | Yes | Password of the certificate key file. The default value is an empty string.|

## PerformanceTiming<sup>11+</sup>

Configures the timing for performance tracing, in ms.

**System capability**: SystemCapability.Communication.NetStack

| Name  | Type                                          | Read Only| Optional|Description                   |
| -------- | ---------------------------------------------- | ---- | --- | ---------------------- |
| dnsTiming  | number | No  | No  | Duration from the time when the [request](#request) is sent to the time when the DNS resolution is complete.|
| tcpTiming  | number | No  | No  | Duration from the time when the [request](#request) is sent to the time when the TCP connection is complete.|
| tlsTiming  | number | No  | No  | Duration from the time when the [request](#request) is sent to the time when the TLS connection is complete.|
| firstSendTiming  | number | No  | No  | Duration from the time when the [request](#request) is sent to the time when the first byte is sent.|
| firstReceiveTiming  | number | No  | No  | Duration from the time when the [request](#request) is sent to the time when the first byte is received.|
| totalFinishTiming  | number | No  | No | Duration from the time when the [request](#request) is sent to the time when the request is complete.|
| redirectTiming  | number | No  | No | Duration from the time when the [request](#request) is sent to the time when all redirection steps are complete.|
| responseHeaderTiming  | number | No  | No  | Duration from the time when the [request](#request) is sent to the time when the header resolution is complete.|
| responseBodyTiming  | number | No  | No  | Duration from the time when the [request](#request) is sent to the time when the body resolution is complete.|
| totalTiming  | number | No  | No  | Duration from the time when the [request](#request) is sent to the time when a callback is returned to the application.|

## DataReceiveProgressInfo<sup>11+</sup>

Defines the data receiving progress information.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Communication.NetStack

| Name  | Type                                          | Read Only| Optional|Description                   |
| -------- | ---------------------------------------------- | ---- | --- | ---------------------- |
|  receiveSize        | number | No  | No | Amount of data that has been received, in bytes.  |
| totalSize| number | No  | No| Amount of data to be received, in bytes.|

## DataSendProgressInfo<sup>11+</sup>

Defines the data sending progress information.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Communication.NetStack

### Attributes

| Name  | Type                                          | Read Only| Optional|Description                   |
| -------- | ---------------------------------------------- | ---- | --- | ---------------------- |
| sendSize        | number | No  | No | Amount of data to be sent each time, in bytes. |
| totalSize | number | No  | No| Amount of data to be sent, in bytes.|

## MultiFormData<sup>11+</sup>

Defines the type of multi-form data.

**System capability**: SystemCapability.Communication.NetStack

| Name  | Type                                          | Read Only| Optional|Description                   |
| -------- | ---------------------------------------------- | ---- | --- | ---------------------- |
| name        | string | No| No| Data name.                                                                     |
| contentType | string | No| No| Data type, for example, **text/plain**, **image/png**, **image/jpeg**, **audio/mpeg**, or **video/mp4**.|
| remoteFileName | string | No| Yes| Name of the file uploaded to the server.<br>**Note**: If this field is specified, the **filename** field is added to the request header, indicating the name of the file uploaded to the server.<br>(1) If the data to be uploaded is a file and the file content is specified via the **data** field, the **remoteFileName** field usually needs to be set to specify the name of the file to be uploaded to the server (the actual result depends on the server). If the file path is specified via the **filePath** field, the **filename** field will be automatically added to the request header. Its default value is the file name in the **filePath** field. If a different name is required, it can also be changed via this field.<br>(2) When the data to be uploaded is in binary format, the **remoteFileName** field must be set.                                                |
| data | string \| Object \| ArrayBuffer | No| Yes| Form data content.                                              |
| filePath | string | No| Yes| File path. This field is used to configure the MIME body content based on the file content. This field is used as the substitute of **data** to set the file data as data content. If **data** is empty, **filePath** must be set. If **data** is present, **filePath** does not take effect.|

## http.createHttpResponseCache<sup>9+</sup>

createHttpResponseCache(cacheSize?: number): HttpResponseCache

Creates an **HttpResponseCache** object that stores the response data of HTTP requests. You can call [flush](#flush9) and [delete](#delete9) in the object.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| cacheSize | number | No| Cache size. The maximum value is 10\*1024\*1024 (10 MB). The maximum value is used by default.|

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

- **`Cache-Control`**: specifies the cache policy, for example, `no-cache`, `no-store`, `max-age`, `public`, or `private`.

- **`Expires`**: specifies the expiration time of a resource. The value is in the GMT format.

- **`ETag`**: identifies the resource version. The client can use the `If-None-Match` request header to check whether the resource has been modified.

- **`Last-Modified`**: specifies the last modification time of a resource. The client can use the `If-Modified-Since` request header to check whether a resource has been modified.

- **`Vary`**: specifies the parts of the request header that affect the cached response. This field is used to distinguish different cache versions.

When using these keywords, ensure that the response header is correctly configured on the server. The client determines whether to use the cached resource and how to verify whether the resource is the latest based on the response header. Correct cache policies help to improve application performance and user experience.

**How to Set the Cache-Control Header**

`Cache-Control` is a common header, but it is usually used on the server. It allows you to define when, how, and how long a response should be cached. The following are some common `Cache-Control` directives:

- **`no-cache`**: indicates that the response can be stored in the cache, but it must be verified with the origin server before each reuse. If the resource remains unchanged, the response status code is 304 (Not Modified). In this case, the resource content is not sent, and the resource in the cache is used. If the resource has expired, the response status code is 200 and the resource content is sent.

- `no-store`: indicates that resources cannot be cached. Resources must be obtained from the server for each request.

- `max-age`: specifies the maximum cache duration, in seconds. For example, `Cache-Control: max-age=3600` indicates that the valid cache duration is 3,600 seconds (that is, 1 hour).

- `public`: indicates that the response can be cached by any object, for example, the client that sends the request or the proxy server.

- `private`: indicates that the response can be cached only by a single user and cannot be used as a shared cache (that is, the response cannot be cached by the proxy server).

- `must-revalidate`: indicates that a resource must be revalidated with the origin server once it has become stable.

- **`no-transform`**: indicates that the proxy server is not allowed to modify the response content.

- **`proxy-revalidate`**: works in a way similar to `must-revalidate`, but applies only to shared caches.

- **`s-maxage`**: works in a way similar to `max-age`, but applies only to shared caches.

### flush<sup>9+</sup>

flush(callback: AsyncCallback\<void\>): void

Flushes data in the cache to the file system so that the cached data can be accessed in the next HTTP request. This API uses an asynchronous callback to return the result. Cached data includes the response header (header), response body (result), cookies, request time (requestTime), and response time (responseTime).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.  If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

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

Flushes data in the cache to the file system so that the cached data can be accessed in the next HTTP request. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<void\> | Promise that returns no value.|

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
    console.error('flush fail');
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
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

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
| Promise\<void\> | Promise that returns no value.|

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

HTTP data type.

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

| Name |   Value  | Description                                                                  |
| :-------- | :----------- |:---------------------------------------------------------------------|
| HTTP1_1   |   0   | HTTP1.1.<br>**Atomic service API**: This API can be used in atomic services since API version 11.      |
| HTTP2     |   1   | HTTP2.<br>**Atomic service API**: This API can be used in atomic services since API version 11.         |
| HTTP3<sup>11+</sup> |  2  | HTTP3. If the system or server does not support HTTP3, the HTTP protocol of an earlier version is used.<br>**Note**: This parameter takes effect only for HTTPS URLs. If this parameter is set to HTTP, the request will fail.|

## CertType<sup>11+</sup>

Enumerates certificate types.

**System capability**: SystemCapability.Communication.NetStack

| Name|   Value  | Description      |
| --- | ------ | ---------- |
| PEM | PEM | PEM certificate.|
| DER | DER | DER certificate.|
| P12 | P12 | P12 certificate.|

## CertificatePinning<sup>12+</sup>

Defines the dynamic configuration of certificate pinning.

**System capability**: SystemCapability.Communication.NetStack

| Name  | Type                                          | Read Only| Optional|Description                   |
| -------- | ---------------------------------------------- | ---- | --- | ---------------------- |
| publicKeyHash       | string | No  | No|Certificate PIN of the string type.|
| hashAlgorithm        | 'SHA-256' |  No  | No |Encryption algorithm. Currently, only SHA-256 is supported.|

## HttpProxy<sup>10+</sup>

type HttpProxy = connection.HttpProxy

Defines the network proxy configuration.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

|       Type      |            Description            |
| ---------------- | --------------------------- |
| connection.HttpProxy | Network proxy configuration.    |

## AddressFamily<sup>15+</sup>

Enumerates IP address families of the target domain name.

**System capability**: SystemCapability.Communication.NetStack

|       Name      |     Value    |            Description            |
| ---------------- | --------------- | --------------------------- |
| DEFAULT | CURL_IPRESOLVE_WHATEVER | Automatically selects the IPv4 or IPv6 address of the target domain name.    |
| ONLY_V4 | CURL_IPRESOLVE_V4 | Resolves only the IPv4 address of the target domain name and ignores the IPv6 address.    |
| ONLY_V6 | CURL_IPRESOLVE_V6 | Resolves only the IPv6 address of the target domain name and ignores the IPv4 address.    |

## Credential<sup>18+</sup>

Represents the credential used for server identity verification in a session, including the user name and password.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Communication.NetStack

|  Name |  Type |  Read Only | Optional |Description    |
| ------------------  |---- |-- | -- |----------- |
| username       | string | No|No|User name used for verification. The default value is **''**.|
| password        | string |  No |No|Password used for verification. The default value is **''**.|

## ServerAuthentication<sup>18+</sup>

Defines HTTP server identity verification information.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Communication.NetStack

|  Name              |  Type                                           | Read Only   |    Optional    |Description    |
| ------------------  |-------------------------------------------------|-------- |------------ |---------------|
| credential          | [Credential](#credential18)                     | No     | No        |Server credential. The default value is **undefined**.    |
| authenticationType  | [AuthenticationType](#authenticationtype18)     | No     | Yes       | Server identity verification type. If the type is not set, negotiation with the server is required.    |


## TlsConfig<sup>18+</sup>

Defines the the TLS configuration, including the version and cipher suite.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Communication.NetStack

|  Name              |  Type                           | Read Only   |    Optional    |Description    |
| ------------------  |---------------------------------|-------- |-------- |---------------|
| tlsVersionMin       | [TlsVersion](#tlsversion18)     | No     |No      | Earliest TLS version.    |
| tlsVersionMax        | [TlsVersion](#tlsversion18)    | No     |No      | Latest TLS version.    |
| cipherSuites        | [CipherSuite](#ciphersuite18)[] | No     |Yes      | Array of cipher suite types.|

## TlsVersion<sup>18+</sup>

Enumerates TLS versions.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Communication.NetStack

| Name       | Value| Description        |
|:----------|:--|:-----------|
| TLS_V_1_0 | 4 | TLS version 1.0.|
| TLS_V_1_1 | 5 | TLS version 1.1.|
| TLS_V_1_2 | 6 | TLS version 1.2.|
| TLS_V_1_3 | 7 | TLS version 1.3.|

## TlsOptions<sup>18+</sup>

type TlsOptions = 'system' | TlsConfig

Defines the TLS configuration.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Communication.NetStack

| Type                        | Description                                                                                |
|-------------------------------|------------------------------------------------------------------------------------|
| 'system'  | TLS version of the system. This field is defaulted to **system** when the value is not set.|
| TlsConfig | Custom TLS version and cipher suites.|

## RemoteValidation<sup>18+</sup>

type RemoteValidation = 'system' | 'skip'

Enumerates the identity verification modes of the remote server.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Communication.NetStack

| Type                        | Description                                                                                |
|-------------------------------|------------------------------------------------------------------------------------|
| 'system'  | Use of the system CA. This field is defaulted to **system** when the value is not set.|
| 'skip'   | Skipping of CA verification. This field has a fixed value of **skip**.|

## AuthenticationType<sup>18+</sup>

type AuthenticationType = 'basic' | 'ntlm' | 'digest'

Enumerates server authentication modes in a session.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Communication.NetStack

|Type                         | Description                                                                                                |
|-------------------------------|----------------------------------------------------------------------------------------------------|
| 'basic'  | Basic authentication mode. This field has a fixed value of **basic**.|
| 'ntlm'   | NTLM authentication mode. This field has a fixed value of **ntlm**.|
| 'digest' | Digest authentication mode. This field has a fixed value of **digest**.|

## CipherSuite<sup>18+</sup>

type CipherSuite = TlsV13CipherSuite

Declares the cipher suite.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Communication.NetStack

|       Type      | Description                                                               |
| ---------------- |-------------------------------------------------------------------|
| TlsV13CipherSuite | Cipher suite defined in [TlsV13CipherSuite](#tlsv13ciphersuite18).                |

## TlsV13CipherSuite<sup>18+</sup>

type TlsV13CipherSuite = TlsV12CipherSuite | TlsV13SpecificCipherSuite

Declares the cipher suite for TLS 1.3, which is also compatible with TLS 1.2.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Communication.NetStack

|       Type      | Description                                                               |
| ---------------- |-------------------------------------------------------------------|
| TlsV12CipherSuite | [TlsV11CipherSuite](#tlsv11ciphersuite18).                |
| TlsV13SpecificCipherSuite | [TlsV13SpecificCipherSuite](#tlsv13specificciphersuite18).|

## TlsV12CipherSuite<sup>18+</sup>

type TlsV12CipherSuite = TlsV11CipherSuite | TlsV12SpecificCipherSuite

Declares the cipher suite for TLS 1.2, which is also compatible with TLS 1.1.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Communication.NetStack

|       Type      | Description                                                               |
| ---------------- |-------------------------------------------------------------------|
| TlsV11CipherSuite | [TlsV11CipherSuite](#tlsv11ciphersuite18).                |
| TlsV12SpecificCipherSuite | [TlsV12SpecificCipherSuite](#tlsv12specificciphersuite18).|

## TlsV11CipherSuite<sup>18+</sup>

type TlsV11CipherSuite = TlsV10CipherSuite

Declares the cipher suite for TLS 1.1, which is the same as that for TLS1.0.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Communication.NetStack

|       Type      | Description                                               |
| ---------------- |---------------------------------------------------|
| TlsV10CipherSuite | [TlsV10CipherSuite](#tlsv10ciphersuite18).|

## TlsV10CipherSuite<sup>18+</sup>

type TlsV10CipherSuite = TlsV10SpecificCipherSuite

Declares the cipher suite for TLS 1.0.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Communication.NetStack

|       Type      | Description                                                               |
| ---------------- |-------------------------------------------------------------------|
| TlsV10SpecificCipherSuite | [TlsV10SpecificCipherSuite](#tlsv10specificciphersuite18).|

## TlsV13SpecificCipherSuite<sup>18+</sup>

type TlsV13SpecificCipherSuite = 'TLS_AES_128_GCM_SHA256' | 'TLS_AES_256_GCM_SHA384' | 'TLS_CHACHA20_POLY1305_SHA256'

Enumerates cipher suites supported by TLS 1.3 or later.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Communication.NetStack

|       Type      | Description  |
| ---------------- |------|
| 'TLS_AES_128_GCM_SHA256' | Supported cipher suite: TLS_AES_128_GCM_SHA256. The value is a string.|
| 'TLS_AES_256_GCM_SHA384' | Supported cipher suite: TLS_AES_256_GCM_SHA384. The value is a string.|
| 'TLS_CHACHA20_POLY1305_SHA256' | Supported cipher suite: TLS_CHACHA20_POLY1305_SHA256. The value is a string.|

## TlsV12SpecificCipherSuite<sup>18+</sup>

type TlsV12SpecificCipherSuite = 'TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256' | 'TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256' |
'TLS_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384' | 'TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384' |
'TLS_ECDHE_ECDSA_WITH_CHACHA20_POLY1305_SHA256' | 'TLS_ECDHE_RSA_WITH_CHACHA20_POLY1305_SHA256' |
'TLS_RSA_WITH_AES_128_GCM_SHA256' | 'TLS_RSA_WITH_AES_256_GCM_SHA384'

Enumerates cipher suites supported by TLS 1.2 or later.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Communication.NetStack

|       Type      | Description  |
| ---------------- |------|
| 'TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256' | Supported cipher suite: TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256. The value is a string.|
| 'TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256' | Supported cipher suite: TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256. The value is a string.|
| 'TLS_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384' | Supported cipher suite: TLS_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384. The value is a string.|
| 'TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384' | Supported cipher suite: TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384. The value is a string.|
| 'TLS_ECDHE_ECDSA_WITH_CHACHA20_POLY1305_SHA256' | Supported cipher suite: TLS_ECDHE_ECDSA_WITH_CHACHA20_POLY1305_SHA256. The value is a string.|
| 'TLS_ECDHE_RSA_WITH_CHACHA20_POLY1305_SHA256' | Supported cipher suite: TLS_ECDHE_RSA_WITH_CHACHA20_POLY1305_SHA256. The value is a string.|
| 'TLS_RSA_WITH_AES_128_GCM_SHA256' | Supported cipher suite: TLS_RSA_WITH_AES_128_GCM_SHA256. The value is a string.|
| 'TLS_RSA_WITH_AES_256_GCM_SHA384' | Supported cipher suite: TLS_RSA_WITH_AES_256_GCM_SHA384. The value is a string.|

## TlsV10SpecificCipherSuite<sup>18+</sup>

type TlsV10SpecificCipherSuite = 'TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA' | 'TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA' |
'TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA' | 'TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA' | 'TLS_RSA_WITH_AES_128_CBC_SHA' |
'TLS_RSA_WITH_AES_256_CBC_SHA' | 'TLS_RSA_WITH_3DES_EDE_CBC_SHA'

Enumerates cipher suites supported by TLS 1.0 or later.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Communication.NetStack

|       Type      | Description  |
| ---------------- |------|
| 'TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA' | Supported cipher suite: TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA. The value is a string.|
| 'TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA' | Supported cipher suite: TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA. The value is a string.|
| 'TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA' | Supported cipher suite: TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA. The value is a string.|
| 'TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA' | Supported cipher suite: TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA. The value is a string.|
| 'TLS_RSA_WITH_AES_128_CBC_SHA' | Supported cipher suite: TLS_RSA_WITH_AES_128_CBC_SHA. The value is a string.|
| 'TLS_RSA_WITH_AES_256_CBC_SHA' | Supported cipher suite: TLS_RSA_WITH_AES_256_CBC_SHA. The value is a string.|
| 'TLS_RSA_WITH_3DES_EDE_CBC_SHA' | Supported cipher suite: TLS_RSA_WITH_3DES_EDE_CBC_SHA. The value is a string.|

## SslType<sup>20+</sup>

type SslType = 'TLS' | 'TLCP'

Defines the secure communications protocol.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Communication.NetStack

| Type  | Description                                  |
| ------ | -------------------------------------- |
| 'TLS' | TLS protocol. The value is fixed to **TLS**.  |
| 'TLCP' | TLCP protocol. The value is fixed to **TLCP**.|
