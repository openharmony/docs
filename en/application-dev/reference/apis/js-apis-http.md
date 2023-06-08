# @ohos.net.http (Data Request)

The **http** module provides the HTTP data request capability. An application can initiate a data request over HTTP. Common HTTP methods include **GET**, **POST**, **OPTIONS**, **HEAD**, **PUT**, **DELETE**, **TRACE**, and **CONNECT**.

> **NOTE**
>
>The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>

## Modules to Import

```js
import http from '@ohos.net.http';
```

## Examples

```js
// Import the http namespace.
import http from '@ohos.net.http';

// Each httpRequest corresponds to an HTTP request task and cannot be reused.
let httpRequest = http.createHttp();
// This API is used to listen for the HTTP Response Header event, which is returned earlier than the result of the HTTP request. It is up to you whether to listen for HTTP Response Header events.
// on('headerReceive', AsyncCallback) is replaced by on('headersReceive', Callback) since API version 8.
httpRequest.on('headersReceive', (header) => {
  console.info('header: ' + JSON.stringify(header));
});
httpRequest.request(
  // Customize EXAMPLE_URL in extraData on your own. It is up to you whether to add parameters to the URL.
  "EXAMPLE_URL",
  {
    method: http.RequestMethod.POST, // Optional. The default value is http.RequestMethod.GET.
    // You can add header fields based on service requirements.
    header: {
      'Content-Type': 'application/json'
    },
    // This parameter is used to transfer data when the POST request is used.
    extraData: {
      "data": "data to send",
    },
    expectDataType: http.HttpDataType.STRING, // Optional. This parameter specifies the type of the return data.
    usingCache: true, // Optional. The default value is true.
    priority: 1, // Optional. The default value is 1.
    connectTimeout: 60000 // Optional. The default value is 60000, in ms.
    readTimeout: 60000, // Optional. The default value is 60000, in ms.
    usingProtocol: http.HttpProtocol.HTTP1_1, // Optional. The default protocol type is automatically specified by the system.
  }, (err, data) => {
    if (!err) {
      // data.result carries the HTTP response. Parse the response based on service requirements.
      console.info('Result:' + JSON.stringify(data.result));
      console.info('code:' + JSON.stringify(data.responseCode));
      // data.header carries the HTTP response header. Parse the content based on service requirements.
      console.info('header:' + JSON.stringify(data.header));
      console.info('cookies:' + JSON.stringify(data.cookies)); // 8+
      // Call the destroy() method to release resources after the HttpRequest is complete.
      httpRequest.destroy();
    } else {
      console.info('error:' + JSON.stringify(err));
      // Unsubscribe from HTTP Response Header events.
      httpRequest.off('headersReceive');
      // Call the destroy() method to release resources after the HttpRequest is complete.
      httpRequest.destroy();
    }
  }
);
```

> **NOTE**
> If the data in **console.info()** contains a newline character, the data will be truncated.

## http.createHttp

createHttp(): HttpRequest

Creates an HTTP request. You can use this API to initiate or destroy an HTTP request, or enable or disable listening for HTTP Response Header events. An **HttpRequest** object corresponds to an HTTP request. To initiate multiple HTTP requests, you must create an **HttpRequest** object for each HTTP request.

> **NOTE**
> Call the **destroy()** method to release resources after the HttpRequest is complete.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type       | Description                                                        |
| :---------- | :----------------------------------------------------------- |
| HttpRequest | An **HttpRequest** object, which contains the **request**, **destroy**, **on**, or **off** method.|

**Example**

```js
import http from '@ohos.net.http';

let httpRequest = http.createHttp();
```

## HttpRequest

Defines an HTTP request task. Before invoking APIs provided by **HttpRequest**, you must call [createHttp()](#httpcreatehttp) to create an **HttpRequestTask** object.

### request

request(url: string, callback: AsyncCallback\<HttpResponse\>):void

Initiates an HTTP request to a given URL. This API uses an asynchronous callback to return the result. 

> **NOTE**
> This API supports only receiving of data not greater than 5 MB.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                          | Mandatory| Description                   |
| -------- | ---------------------------------------------- | ---- | ----------------------- |
| url      | string                                         | Yes  | URL for initiating an HTTP request.|
| callback | AsyncCallback\<[HttpResponse](#httpresponse)\> | Yes  | Callback used to return the result.             |

**Error codes**

| ID  | Error Message                                                 |
|---------|-------------------------------------------------------|
| 401     | Parameter error.                                      |
| 201     | Permission denied.                                    |
| 2300003 | URL using bad/illegal format or missing URL.          |
| 2300007 | Couldn't connect to server.                           |
| 2300028 | Timeout was reached.                                  |
| 2300052 | Server returned nothing (no headers, no data).        |
| 2300999 | Unknown Other Error.                                  |

> **NOTE**
> For details about the error codes, see [HTTP Error Codes](../errorcodes/errorcode-net-http.md).
> The HTTP error code mapping is in the format of 2300000 + Curl error code. For more common error codes, see [Curl Error Codes](https://curl.se/libcurl/c/libcurl-errors.html).

**Example**

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

request(url: string, options: HttpRequestOptions, callback: AsyncCallback\<HttpResponse\>):void

Initiates an HTTP request containing specified options to a given URL. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API supports only receiving of data not greater than 5 MB.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                          | Mandatory| Description                                           |
| -------- | ---------------------------------------------- | ---- | ----------------------------------------------- |
| url      | string                                         | Yes  | URL for initiating an HTTP request.                        |
| options  | HttpRequestOptions                             | Yes  | Request options. For details, see [HttpRequestOptions](#httprequestoptions).|
| callback | AsyncCallback\<[HttpResponse](#httpresponse)\> | Yes  | Callback used to return the result.                                     |

**Error codes**

| ID  | Error Message                                                 |
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

> **NOTE**
> For details about the error codes, see [HTTP Error Codes](../errorcodes/errorcode-net-http.md).
> The HTTP error code mapping is in the format of 2300000 + Curl error code. For more common error codes, see [Curl Error Codes](https://curl.se/libcurl/c/libcurl-errors.html).

**Example**

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

request(url: string, options? : HttpRequestOptions): Promise\<HttpResponse\>

Initiates an HTTP request containing specified options to a given URL. This API uses a promise to return the result. 

> **NOTE**
> This API supports only receiving of data not greater than 5 MB.

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
| Promise<[HttpResponse](#httpresponse)> | Promise used to return the result.|

**Error codes**

| ID  | Error Message                                                 |
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

> **NOTE**
> For details about the error codes, see [HTTP Error Codes](../errorcodes/errorcode-net-http.md).
> The HTTP error code mapping is in the format of 2300000 + Curl error code. For more common error codes, see [Curl Error Codes](https://curl.se/libcurl/c/libcurl-errors.html).

**Example**

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

destroy(): void

Destroys an HTTP request.

**System capability**: SystemCapability.Communication.NetStack

**Example**

```js
httpRequest.destroy();
```

### on('headerReceive')<sup>(deprecated)</sup>

on(type: 'headerReceive', callback: AsyncCallback\<Object\>): void

Registers an observer for HTTP Response Header events.

> **NOTE**
> This API has been deprecated. You are advised to use [on('headersReceive')<sup>8+</sup>](#onheadersreceive8).

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                   | Mandatory| Description                             |
| -------- | ----------------------- | ---- | --------------------------------- |
| type     | string                  | Yes  | Event type. The value is **headerReceive**.|
| callback | AsyncCallback\<Object\> | Yes  | Callback used to return the result.                       |

**Example**

```js
httpRequest.on('headerReceive', (data) => {
  console.info('error:' + JSON.stringify(data));
});
```

### off('headerReceive')<sup>(deprecated)</sup>

off(type: 'headerReceive', callback?: AsyncCallback\<Object\>): void

Unregisters the observer for HTTP Response Header events.

> **NOTE**
>
>1. This API has been deprecated. You are advised to use [off('headersReceive')<sup>8+</sup>](#offheadersreceive8).
>
>2. You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                   | Mandatory| Description                                 |
| -------- | ----------------------- | ---- | ------------------------------------- |
| type     | string                  | Yes  | Event type. The value is **headerReceive**.|
| callback | AsyncCallback\<Object\> | No  | Callback used to return the result.                           |

**Example**

```js
httpRequest.off('headerReceive');
```

### on('headersReceive')<sup>8+</sup>

on(type: 'headersReceive', callback: Callback\<Object\>): void

Registers an observer for HTTP Response Header events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type              | Mandatory| Description                              |
| -------- | ------------------ | ---- | ---------------------------------- |
| type     | string             | Yes  | Event type. The value is **headersReceive**.|
| callback | Callback\<Object\> | Yes  | Callback used to return the result.                        |

**Example**

```js
httpRequest.on('headersReceive', (header) => {
  console.info('header: ' + JSON.stringify(header));
});
```

### off('headersReceive')<sup>8+</sup>

off(type: 'headersReceive', callback?: Callback\<Object\>): void

Unregisters the observer for HTTP Response Header events.

> **NOTE**
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type              | Mandatory| Description                                  |
| -------- | ------------------ | ---- | -------------------------------------- |
| type     | string             | Yes  | Event type. The value is **headersReceive**.|
| callback | Callback\<Object\> | No  | Callback used to return the result.                            |

**Example**

```js
httpRequest.off('headersReceive');
```

### once('headersReceive')<sup>8+</sup>

once(type: 'headersReceive', callback: Callback\<Object\>): void

Registers a one-time observer for HTTP Response Header events. Once triggered, the observer will be removed. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type              | Mandatory| Description                              |
| -------- | ------------------ | ---- | ---------------------------------- |
| type     | string             | Yes  | Event type. The value is **headersReceive**.|
| callback | Callback\<Object\> | Yes  | Callback used to return the result.                        |

**Example**

```js
httpRequest.once('headersReceive', (header) => {
  console.info('header: ' + JSON.stringify(header));
});
```

## HttpRequestOptions

Specifies the type and value range of the optional parameters in the HTTP request.

**System capability**: SystemCapability.Communication.NetStack

| Name        | Type                                         | Mandatory| Description                                                        |
| -------------- | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| method         | [RequestMethod](#requestmethod)               | No  | Request method. The default value is **GET**.                                                  |
| extraData      | string<sup>6+</sup> \| Object<sup>6+</sup> \| ArrayBuffer<sup>8+</sup>  | No  | Additional data for sending a request. This parameter is not used by default.<br>- If the HTTP request uses a POST or PUT method, this parameter serves as the content of the HTTP request and is encoded in UTF-8 format. If **'Content-Type'** is **'application/x-www-form-urlencoded'**, the data in the request body must be encoded in the format of **key1=value1&key2=value2&key3=value3** after URL transcoding.<br>- If the HTTP request uses the GET, OPTIONS, DELETE, TRACE, or CONNECT method, this parameter serves as a supplement to HTTP request parameters. Parameters of the string type need to be encoded before being passed to the HTTP request. Parameters of the object type do not need to be precoded and will be directly concatenated to the URL. Parameters of the ArrayBuffer type will not be concatenated to the URL.|
| expectDataType<sup>9+</sup>  | [HttpDataType](#httpdatatype9)  | No  | Type of the returned data. This parameter is not used by default. If this parameter is set, the system returns the specified type of data preferentially.|
| usingCache<sup>9+</sup>      | boolean                         | No  | Whether to use the cache. The default value is **true**.  |
| priority<sup>9+</sup>        | number                          | No  | Priority. The value range is [1,1000]. The default value is **1**.                          |
| header                       | Object                          | No  | HTTP request header. The default value is **{'Content-Type': 'application/json'}**.  |
| readTimeout                  | number                          | No  | Read timeout duration. The default value is **60000**, in ms.<br>The value **0** indicates no timeout.|
| connectTimeout               | number                          | No  | Connection timeout interval. The default value is **60000**, in ms.             |
| usingProtocol<sup>9+</sup>   | [HttpProtocol](#httpprotocol9)  | No  | Protocol. The default value is automatically specified by the system.                            |

## RequestMethod

Defines an HTTP request method.

**System capability**: SystemCapability.Communication.NetStack

| Name   | Value     | Description               |
| :------ | ------- | :------------------ |
| OPTIONS | "OPTIONS" | OPTIONS method.|
| GET     | "GET"     | GET method.    |
| HEAD    | "HEAD"    | HEAD method.   |
| POST    | "POST"    | POST method.   |
| PUT     | "PUT"     | PUT method.    |
| DELETE  | "DELETE"  | DELETE method. |
| TRACE   | "TRACE"   | TRACE method.  |
| CONNECT | "CONNECT" | CONNECT method.|

## ResponseCode

Enumerates the response codes for an HTTP request.

**System capability**: SystemCapability.Communication.NetStack

| Name             | Value  | Description                                                        |
| ----------------- | ---- | ------------------------------------------------------------ |
| OK                | 200  | The request is successful. The request has been processed successfully. This return code is generally used for GET and POST requests.                           |
| CREATED           | 201  | "Created." The request has been successfully sent and a new resource is created.                          |
| ACCEPTED          | 202  | "Accepted." The request has been accepted, but the processing has not been completed.                        |
| NOT_AUTHORITATIVE | 203  | "Non-Authoritative Information." The request is successful.                                      |
| NO_CONTENT        | 204  | "No Content." The server has successfully fulfilled the request but there is no additional content to send in the response payload body.                      |
| RESET             | 205  | "Reset Content." The server has successfully fulfilled the request and desires that the user agent reset the content.                                                  |
| PARTIAL           | 206  | "Partial Content." The server has successfully fulfilled the partial GET request for a given resource.                     |
| MULT_CHOICE       | 300  | "Multiple Choices." The requested resource corresponds to any one of a set of representations.                                                  |
| MOVED_PERM        | 301  | "Moved Permanently." The requested resource has been assigned a new permanent URI and any future references to this resource will be redirected to this URI.|
| MOVED_TEMP        | 302  | "Moved Temporarily." The requested resource is moved temporarily to a different URI.                                                  |
| SEE_OTHER         | 303  | "See Other." The response to the request can be found under a different URI.                                              |
| NOT_MODIFIED      | 304  | "Not Modified." The client has performed a conditional GET request and access is allowed, but the content has not been modified.                                                    |
| USE_PROXY         | 305  | "Use Proxy." The requested resource can only be accessed through the proxy.                                                  |
| BAD_REQUEST       | 400  | "Bad Request." The request could not be understood by the server due to incorrect syntax.                       |
| UNAUTHORIZED      | 401  | "Unauthorized." The request requires user authentication.                                    |
| PAYMENT_REQUIRED  | 402  | "Payment Required." This code is reserved for future use.                                            |
| FORBIDDEN         | 403  | "Forbidden." The server understands the request but refuses to process it.            |
| NOT_FOUND         | 404  | "Not Found." The server does not find anything matching the Request-URI.                |
| BAD_METHOD        | 405  | "Method Not Allowed." The method specified in the request is not allowed for the resource identified by the Request-URI.                                  |
| NOT_ACCEPTABLE    | 406  | "Not Acceptable." The server cannot fulfill the request according to the content characteristics of the request.                 |
| PROXY_AUTH        | 407  | "Proxy Authentication Required." The request requires user authentication with the proxy.                                    |
| CLIENT_TIMEOUT    | 408  | "Request Timeout." The client fails to generate a request within the timeout period.                                        |
| CONFLICT          | 409  | "Conflict." The request cannot be fulfilled due to a conflict with the current state of the resource. Conflicts are most likely to occur in response to a PUT request. |
| GONE              | 410  | "Gone." The requested resource has been deleted permanently and is no longer available.                                 |
| LENGTH_REQUIRED   | 411  | "Length Required." The server refuses to process the request without a defined Content-Length.    |
| PRECON_FAILED     | 412  | "Precondition Failed." The precondition in the request is incorrect.                              |
| ENTITY_TOO_LARGE  | 413  | "Request Entity Too Large." The server refuses to process a request because the request entity is larger than the server is able to process.           |
| REQ_TOO_LONG      | 414  | "Request-URI Too Long." The Request-URI is too long for the server to process.             |
| UNSUPPORTED_TYPE  | 415  | "Unsupported Media Type." The server is unable to process the media format in the request.                                   |
| INTERNAL_ERROR    | 500  | "Internal Server Error." The server encounters an unexpected error that prevents it from fulfilling the request.                              |
| NOT_IMPLEMENTED   | 501  | "Not Implemented." The server does not support the function required to fulfill the request.                      |
| BAD_GATEWAY       | 502  | "Bad Gateway." The server acting as a gateway or proxy receives an invalid response from the upstream server.|
| UNAVAILABLE       | 503  | "Service Unavailable." The server is currently unable to process the request due to a temporary overload or system maintenance.      |
| GATEWAY_TIMEOUT   | 504  | "Gateway Timeout." The server acting as a gateway or proxy does not receive requests from the remote server within the timeout period.        |
| VERSION           | 505  | "HTTP Version Not Supported." The server does not support the HTTP protocol version used in the request.                                 |

## HttpResponse

Defines the response to an HTTP request.

**System capability**: SystemCapability.Communication.NetStack

| Name              | Type                                        | Mandatory| Description                                                        |
| -------------------- | -------------------------------------------- | ---- | ------------------------------------------------------------ |
| result               | string<sup>6+</sup> \| Object<sup>deprecated 8+</sup> \| ArrayBuffer<sup>8+</sup> | Yes  | Response content returned based on **Content-type** in the response header:<br>- application/json: a string in JSON format. If you want to use specific content in the response, you need to implement parsing of that content.<br>- application/octet-stream: ArrayBuffer<br>- Others: string|
| resultType<sup>9+</sup> | [HttpDataType](#httpdatatype9)            | Yes  | Type of the return value.                          |
| responseCode         | [ResponseCode](#responsecode) \| number      | Yes  | Result code for an HTTP request. If the callback function is successfully executed, a result code defined in [ResponseCode](#responsecode) will be returned. Otherwise, an error code will be returned in the **err** field in **AsyncCallback**.|
| header               | Object                                       | Yes  | Response header. The return value is a string in JSON format. If you want to use specific content in the response, you need to implement parsing of that content. Common fields and parsing methods are as follows:<br>- content-type: header['content-type'];<br>- status-line: header['status-line'];<br>- date: header.date/header['date'];<br>- server: header.server/header['server'];|
| cookies<sup>8+</sup> | string                                       | Yes  | Cookies returned by the server.                                      |

## http.createHttpResponseCache<sup>9+</sup>

createHttpResponseCache(cacheSize?: number): HttpResponseCache

Creates a default object to store responses to HTTP access requests.

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

```js
import http from '@ohos.net.http';

let httpResponseCache = http.createHttpResponseCache();
```

## HttpResponseCache<sup>9+</sup>

Defines an object that stores the response to an HTTP request. Before invoking APIs provided by **HttpResponseCache**, you must call [createHttpResponseCache()](#httpcreatehttpresponsecache9) to create an **HttpRequestTask** object.

### flush<sup>9+</sup>

flush(callback: AsyncCallback\<void\>): void

Flushes data in the cache to the file system so that the cached data can be accessed in the next HTTP request. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
httpResponseCache.flush(err => {
  if (err) {
    console.info('flush fail');
    return;
  }
  console.info('flush success');
});
```

### flush<sup>9+</sup>

flush(): Promise\<void\>

Flushes data in the cache to the file system so that the cached data can be accessed in the next HTTP request. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Example**

```js
httpResponseCache.flush().then(() => {
  console.info('flush success');
}).catch(err => {
  console.info('flush fail');
});
```

### delete<sup>9+</sup>

delete(callback: AsyncCallback\<void\>): void

Disables the cache and deletes the data in it. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
httpResponseCache.delete(err => {
  if (err) {
    console.info('delete fail');
    return;
  }
  console.info('delete success');
});
```

### delete<sup>9+</sup>

delete(): Promise\<void\>

Disables the cache and deletes the data in it. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Example**

```js
httpResponseCache.delete().then(() => {
  console.info('delete success');
}).catch(err => {
  console.info('delete fail');
});
```

## HttpDataType<sup>9+</sup>

Enumerates HTTP data types.

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
| HTTP1_1   |  HTTP1.1 |
| HTTP2     |  HTTP2   |
