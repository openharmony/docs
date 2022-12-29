# Data Request

This module provides the HTTP data request capability. An application can initiate a data request over HTTP. Common HTTP methods include **GET**, **POST**, **OPTIONS**, **HEAD**, **PUT**, **DELETE**, **TRACE**, and **CONNECT**.

>**NOTE**
>
>The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>

## Modules to Import

```js
import http from '@ohos.net.http';
```

## Example

```js
import http from '@ohos.net.http';

// Each HttpRequest corresponds to an HttpRequestTask object and cannot be reused.
let httpRequest = http.createHttp();
// Subscribe to the HTTP response header, which is returned earlier than httpRequest. Whether to subscribe to the HTTP response header is up to your decision.
// on('headerReceive', AsyncCallback) is replaced by on('headersReceive', Callback) since API version 8.
httpRequest.on('headersReceive', (header) => {
    console.info('header: ' + JSON.stringify(header));
});
httpRequest.request(
    // Customize EXAMPLE_URL on your own. It is up to you whether to add parameters to the URL.
    "EXAMPLE_URL",
    {
        method: http.RequestMethod.POST, // Optional. The default value is http.RequestMethod.GET.
        // You can add header fields based on service requirements.
        header: {
            'Content-Type': 'application/json'
        },
        // This field is used to transfer data when the POST request is used.
        extraData: {
            "data": "data to send",
        },
        connectTimeout: 60000, // Optional. The default value is 60000, in ms.
        readTimeout: 60000, // Optional. The default value is 60000, in ms.
    }, (err, data) => {
        if (!err) {
            // data.result contains the HTTP response. Parse the response based on service requirements.
            console.info('Result:' + data.result);
            console.info('code:' + data.responseCode);
            // data.header contains the HTTP response header. Parse the content based on service requirements.
            console.info('header:' + JSON.stringify(data.header));
            console.info('cookies:' + data.cookies); // 8+
        } else {
            console.info('error:' + JSON.stringify(err));
            // Call the destroy() method to release resources after HttpRequest is complete.
            httpRequest.destroy();
        }
    }
);
```

## http.createHttp

createHttp\(\): HttpRequest

Creates an HTTP request. You can use this API to initiate or destroy an HTTP request, or enable or disable listening for HTTP Response Header events. An HttpRequest object corresponds to an HTTP request. To initiate multiple HTTP requests, you must create an **HttpRequest** object for each HTTP request.

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

HTTP request task. Before invoking APIs provided by **HttpRequest**, you must call [createHttp\(\)](#httpcreatehttp) to create an **HttpRequestTask** object.

### request

request\(url: string, callback: AsyncCallback\<HttpResponse\>\):void

Initiates an HTTP request to a given URL. This API uses an asynchronous callback to return the result. 

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                          | Mandatory| Description                   |
| -------- | ---------------------------------------------- | ---- | ----------------------- |
| url      | string                                         | Yes  | URL for initiating an HTTP request.|
| callback | AsyncCallback\<[HttpResponse](#httpresponse)\> | Yes  | Callback used to return the result.             |

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

request\(url: string, options: HttpRequestOptions, callback: AsyncCallback<HttpResponse\>\):void

Initiates an HTTP request containing specified options to a given URL. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                          | Mandatory| Description                                           |
| -------- | ---------------------------------------------- | ---- | ----------------------------------------------- |
| url      | string                                         | Yes  | URL for initiating an HTTP request.                        |
| options  | HttpRequestOptions                             | Yes  | Request options. For details, see [HttpRequestOptions](#httprequestoptions).|
| callback | AsyncCallback\<[HttpResponse](#httpresponse)\> | Yes  | Callback used to return the result.                                     |

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

request\(url: string, options? : HttpRequestOptions\): Promise<HttpResponse\>

Initiates an HTTP request to a given URL. This API uses a promise to return the result. 

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type              | Mandatory| Description                                           |
| ------- | ------------------ | ---- | ----------------------------------------------- |
| url     | string             | Yes  | URL for initiating an HTTP request.                        |
| options | HttpRequestOptions | Yes  | Request options. For details, see [HttpRequestOptions](#httprequestoptions).|

**Return value**

| Type                                  | Description                             |
| :------------------------------------- | :-------------------------------- |
| Promise<[HttpResponse](#httpresponse)> | Promise used to return the result.|


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

destroy\(\): void

Destroys an HTTP request.

**System capability**: SystemCapability.Communication.NetStack

**Example**

```js
httpRequest.destroy();
```

### on\('headerReceive'\)

on\(type: 'headerReceive', callback: AsyncCallback<Object\>\): void

Registers an observer for HTTP Response Header events.

>![](public_sys-resources/icon-note.gif) **NOTE**
>This API has been deprecated. You are advised to use [on\('headersReceive'\)<sup>8+</sup>](#onheadersreceive8) instead.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                   | Mandatory| Description                             |
| -------- | ----------------------- | ---- | --------------------------------- |
| type     | string                  | Yes  | Event type. The value is **headerReceive**.|
| callback | AsyncCallback\<Object\> | Yes  | Callback used to return the result.                       |

**Example**

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

Unregisters the observer for HTTP Response Header events.

>![](public_sys-resources/icon-note.gif) **NOTE**
>
>1. This API has been deprecated. You are advised to use [off\('headersReceive'\)<sup>8+</sup>](#offheadersreceive8) instead.
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

### on\('headersReceive'\)<sup>8+</sup>

on\(type: 'headersReceive', callback: Callback<Object\>\): void

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


### off\('headersReceive'\)<sup>8+</sup>

off\(type: 'headersReceive', callback?: Callback<Object\>\): void

Unregisters the observer for HTTP Response Header events.

>![](public_sys-resources/icon-note.gif) **NOTE**
>You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

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

### once\('headersReceive'\)<sup>8+</sup>

once\(type: 'headersReceive', callback: Callback<Object\>\): void

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
| method         | [RequestMethod](#requestmethod)               | No  | Request method.                                                  |
| extraData      | string \| Object  \| ArrayBuffer<sup>6+</sup> | No  | Additional data of the request.<br>- If the HTTP request uses a POST or PUT method, this parameter serves as the content of the HTTP request.<br>- If the HTTP request uses a GET, OPTIONS, DELETE, TRACE, or CONNECT method, this parameter is a supplement to the HTTP request parameters and will be added to the URL when the request is sent.<sup>6+</sup><br>- To pass in a string object, you first need to encode the object on your own.<sup>8+</sup> |
| header         | Object                                        | No  | HTTP request header. The default value is **{'Content-Type': 'application/json'}**.  |
| readTimeout    | number                                        | No  | Read timeout duration. The default value is **60000**, in ms.             |
| connectTimeout | number                                        | No  | Connection timeout interval. The default value is **60000**, in ms.             |

## RequestMethod

Defines an HTTP request method.

**System capability**: SystemCapability.Communication.NetStack

| Name   | Value     | Description               |
| :------ | ------- | :------------------ |
| OPTIONS | OPTIONS | OPTIONS method.|
| GET     | GET     | GET method.    |
| HEAD    | HEAD    | HEAD method.   |
| POST    | POST    | POST method.   |
| PUT     | PUT     | PUT method.    |
| DELETE  | DELETE  | DELETE method. |
| TRACE   | TRACE   | TRACE method.  |
| CONNECT | CONNECT | CONNECT method.|

## ResponseCode

Enumerates the response codes for an HTTP request.

**System capability**: SystemCapability.Communication.NetStack

| Name             | Value  | Description                                                        |
| ----------------- | ---- | ------------------------------------------------------------ |
| OK                | 200  | Request succeeded. The request has been processed successfully. This return code is generally used for GET and POST requests.                           |
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
| result               | string \| Object \| ArrayBuffer<sup>6+</sup> | Yes  | Response content returned based on **Content-type** in the response header:<br>- application/json: a string in JSON format. If you want to use specific content in the response, you need to implement parsing of that content.<br>- application/octet-stream: ArrayBuffer<br>- Others: string|
| responseCode         | [ResponseCode](#responsecode) \| number      | Yes  | Result code for an HTTP request. If the callback function is successfully executed, a result code defined in [ResponseCode](#responsecode) will be returned. Otherwise, an error code will be returned in the **err** field in **AsyncCallback**. For details, see [Error Codes](#error-codes).|
| header               | Object                                       | Yes  | Response header. The return value is a string in JSON format. If you want to use specific content in the response, you need to implement parsing of that content. Common fields and parsing methods are as follows:<br>- Content-Type: header['Content-Type'];<br>- Status-Line: header['Status-Line'];<br>- Date: header.Date/header['Date'];<br>- Server: header.Server/header['Server'];|
| cookies<sup>8+</sup> | Array\<string\>                              | Yes  | Cookies returned by the server.                                      |

## Error Codes

| Error Code| Description                                                        |
| ------ | ------------------------------------------------------------ |
| -1     | Incorrect parameters.                                                  |
| 3      | Incorrect URL format.                                               |
| 4      | Built-in request function, protocol, or option not found during build.                  |
| 5      | Unable to resolve the proxy.                                              |
| 6      | Unable to resolve the host.                                              |
| 7      | Unable to connect to the proxy or host.                                        |
