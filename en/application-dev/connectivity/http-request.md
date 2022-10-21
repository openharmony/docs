# HTTP Data Request

## Use Cases

An application can initiate a data request over HTTP. Common HTTP methods include **GET**, **POST**, **OPTIONS**, **HEAD**, **PUT**, **DELETE**, **TRACE**, and **CONNECT**.

## Available APIs

The HTTP request function is mainly implemented by the HTTP module.

To use related APIs, you must declare the **ohos.permission.INTERNET** permission.

For details about how to apply for permissions, see [Access Control Development](../security/accesstoken-guidelines.md).

The following table provides only a simple description of the related APIs. For details, see [API Reference](../reference/apis/js-apis-http.md).

| API                                       | Description                                               |
| ----------------------------------------- | --------------------------------------------------------- |
| createHttp()                              | Creates an HTTP request.                                  |
| request()                                 | Initiates an HTTP request to a given URL.                 |
| destroy()                                 | Destroys an HTTP request.                                 |
| on(type: 'headersReceive')                | Registers an observer for HTTP Response Header events.    |
| off(type: 'headersReceive')               | Unregisters the observer for HTTP Response Header events. |

## How to Develop

1. Import the required HTTP module.
2. Create an **HttpRequest** object.
3. (Optional) Listen for HTTP Response Header events.
4. Initiate an HTTP request to a given URL.
5. (Optional) Process the HTTP Response Header event and the return result of the HTTP request.

```js
import http from '@ohos.net.http';

// Each HttpRequest corresponds to an HttpRequestTask object and cannot be reused.
let httpRequest = http.createHttp();

// Subscribe to the HTTP response header, which is returned earlier than HttpRequest. You can subscribe to HTTP Response Header events based on service requirements.
// on('headerReceive', AsyncCallback) will be replaced by on('headersReceive', Callback) in API version 8. 8+
httpRequest.on('headersReceive', (header) => {
    console.info('header: ' + JSON.stringify(header));
});

httpRequest.request(
    // Set the URL of the HTTP request. You need to define the URL. Set the parameters of the request in extraData.
    "EXAMPLE_URL",
    {
        method: http.RequestMethod.POST, // Optional. The default value is http.RequestMethod.GET.
        // You can add the header field based on service requirements.
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
            // Call the destroy() method to destroy the request if it is no longer needed.
            httpRequest.destroy();
        }
    }
);
```
