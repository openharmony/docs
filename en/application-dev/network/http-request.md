# HTTP Data Request

## When to Use

An application can initiate a data request over HTTP. Common HTTP methods include **GET**, **POST**, **OPTIONS**, **HEAD**, **PUT**, **DELETE**, **TRACE**, and **CONNECT**.

## Available APIs

The HTTP request function is mainly implemented by the HTTP module.

To use related APIs, you must declare the **ohos.permission.INTERNET** permission.

For details about how to apply for permissions, see [Declaring Permissions](../security/AccessToken/declare-permissions.md).

The following table provides only a simple description of the related APIs. For details, see [API Reference](../reference/apis-network-kit/js-apis-http.md).

| API                                   | Description                               |
| ----------------------------------------- | ----------------------------------- |
| createHttp()                              | Creates an HTTP request.                 |
| request()                                 | Initiates an HTTP request to a given URL.    |
| requestInStream()<sup>10+</sup>           | Initiates an HTTP network request to a given URL and returns a streaming response.|
| destroy()                                 | Destroys an HTTP request.                     |
| on(type: 'headersReceive')                | Registers an observer for HTTP Response Header events.    |
| off(type: 'headersReceive')               | Unregisters the observer for HTTP Response Header events.|
| once\('headersReceive'\)<sup>8+</sup>     | Registers a one-time observer for HTTP Response Header events.|
| on\('dataReceive'\)<sup>10+</sup>         | Registers an observer for events indicating receiving of HTTP streaming responses.     |
| off\('dataReceive'\)<sup>10+</sup>        | Unregisters the observer for events indicating receiving of HTTP streaming responses. |
| on\('dataEnd'\)<sup>10+</sup>             | Registers an observer for events indicating completion of receiving HTTP streaming responses. |
| off\('dataEnd'\)<sup>10+</sup>            | Unregisters the observer for events indicating completion of receiving HTTP streaming responses.|
| on\('dataReceiveProgress'\)<sup>10+</sup>        | Registers an observer for events indicating progress of receiving HTTP streaming responses. |
| off\('dataReceiveProgress'\)<sup>10+</sup>       | Unregisters the observer for events indicating progress of receiving HTTP streaming responses.|
| on\('dataSendProgress'\)<sup>11+</sup>        | Registers an observer for events indicating progress of sending HTTP requests. |
| off\('dataSendProgress'\)<sup>11+</sup>       | Unregisters the observer for events indicating progress of sending HTTP requests.|

## How to Develop request APIs

1. Import the **http** namespace from **@kit.NetworkKit**.
2. Call **createHttp()** to create an **HttpRequest** object.
3. Call **httpRequest.on()** to subscribe to HTTP response header events. This API returns a response earlier than the request. You can subscribe to HTTP response header events based on service requirements.
4. Call **httpRequest.request()** to initiate a network request. You need to pass in the URL and optional parameters of the HTTP request.
5. Parse the returned result based on service requirements.
6. Call **off()** to unsubscribe from HTTP response header events.
7. Call **httpRequest.destroy()** to release resources after the request is processed.

```ts
// Import the http namespace.
import { http } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
    // This field is used to transfer the request body when a POST request is used. Its format needs to be negotiated with the server.
    extraData: "data to send",
    expectDataType: http.HttpDataType.STRING, // Optional. This field specifies the type of the return data.
    usingCache: true, // Optional. The default value is true.
    priority: 1, // Optional. The default value is 1.
    connectTimeout: 60000 // Optional. The default value is 60000, in ms.
    readTimeout: 60000, // Optional. The default value is 60000, in ms.
    usingProtocol: http.HttpProtocol.HTTP1_1, // Optional. The default protocol type is automatically specified by the system.
    usingProxy: false, // Optional. By default, network proxy is not used. This field is supported since API version 10.
    caPath: '/path/to/cacert.pem', // Optional. The preset CA certificate is used by default. This field is supported since API version 10.
    clientCert: { // Optional. The client certificate is not used by default. This field is supported since API version 11.
      certPath: '/path/to/client.pem', // The client certificate is not used by default. This field is supported since API version 11.
      keyPath: '/path/to/client.key', // If the certificate contains key information, an empty string is passed. This field is supported since API version 11.
      certType: http.CertType.PEM, // Certificate type, optional. A certificate in the PEM format is used by default. This field is supported since API version 11.
      keyPassword: "passwordToKey" // Password of the key file, optional. It is supported since API version 11.
    },
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
  }, (err: BusinessError, data: http.HttpResponse) => {
    if (!err) {
      // data.result carries the HTTP response. Parse the response based on service requirements.
      console.info('Result:' + JSON.stringify(data.result));
      console.info('code:' + JSON.stringify(data.responseCode));
      // data.header carries the HTTP response header. Parse the content based on service requirements.
      console.info('header:' + JSON.stringify(data.header));
      console.info('cookies:' + JSON.stringify(data.cookies)); // 8+
      // Call the destroy() method to release resources after HttpRequest is complete.
      httpRequest.destroy();
    } else {
      console.error('error:' + JSON.stringify(err));
      // Unsubscribe from HTTP Response Header events.
      httpRequest.off('headersReceive');
      // Call the destroy() method to release resources after HttpRequest is complete.
      httpRequest.destroy();
    }
  }
);
```

## How to Develop requestInStream APIs

1. Import the **http** namespace from **@kit.NetworkKit**.
2. Call **createHttp()** to create an **HttpRequest** object.
3. Depending on your need, call **on()** of the **HttpRequest** object to subscribe to HTTP response header events as well as events indicating receiving of HTTP streaming responses, progress of receiving HTTP streaming responses, and completion of receiving HTTP streaming responses.
4. Call **requestInStream()** to initiate a network request. You need to pass in the URL and optional parameters of the HTTP request.
5. Parse the returned response code as needed.
6. Call **off()** of the **HttpRequest** object to unsubscribe from the related events.
7. Call **httpRequest.destroy()** to release resources after the request is processed.

```ts
// Import the http namespace.
import { http } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Each httpRequest corresponds to an HTTP request task and cannot be reused.
let httpRequest = http.createHttp();
// Subscribe to HTTP response header events.
httpRequest.on('headersReceive', (header: Object) => {
  console.info('header: ' + JSON.stringify(header));
});
// Subscribe to events indicating receiving of HTTP streaming responses.
let res = new ArrayBuffer(0);
httpRequest.on('dataReceive', (data: ArrayBuffer) => {
   const newRes = new ArrayBuffer(res.byteLength + data.byteLength);
   const resView = new Uint8Array(newRes);
   resView.set(new Uint8Array(res));
   resView.set(new Uint8Array(data), res.byteLength);
   res = newRes;
   console.info('res length: ' + res.byteLength);
});
// Subscribe to events indicating completion of receiving HTTP streaming responses.
httpRequest.on('dataEnd', () => {
  console.info('No more data in response, data receive end');
});
// Subscribe to events indicating progress of receiving HTTP streaming responses.
class Data {
  receiveSize: number = 0;
  totalSize: number = 0;
}
httpRequest.on('dataReceiveProgress', (data: Data) => {
  console.log("dataReceiveProgress receiveSize:" + data.receiveSize + ", totalSize:" + data.totalSize);
});

let streamInfo: http.HttpRequestOptions = {
  method: http.RequestMethod.POST, // Optional. The default value is http.RequestMethod.GET.
  // You can add header fields based on service requirements.
  header: {
    'Content-Type': 'application/json'
  },
  // This field is used to transfer the request body when a POST request is used. Its format needs to be negotiated with the server.
  extraData: "data to send",
  expectDataType: http.HttpDataType.STRING, // Optional. This field specifies the type of the return data.
  usingCache: true, // Optional. The default value is true.
  priority: 1, // Optional. The default value is 1.
  connectTimeout: 60000 // Optional. The default value is 60000, in ms.
  readTimeout: 60000, // Optional. The default value is 60000, in ms. If a large amount of data needs to be transmitted, you are advised to set this parameter to a larger value to ensure normal data transmission.
  usingProtocol: http.HttpProtocol.HTTP1_1 // Optional. The default protocol type is automatically specified by the system.
}

// Customize EXAMPLE_URL in extraData on your own. It is up to you whether to add parameters to the URL.
httpRequest.requestInStream("EXAMPLE_URL", streamInfo).then((data: number) => {
  console.info("requestInStream OK!");
  console.info('ResponseCode :' + JSON.stringify(data));
  // Unsubscribe from HTTP Response Header events.
  httpRequest.off('headersReceive');
  // Unregister the observer for events indicating receiving of HTTP streaming responses.
  httpRequest.off('dataReceive');
  // Unregister the observer for events indicating progress of receiving HTTP streaming responses.
  httpRequest.off('dataReceiveProgress');
  // Unregister the observer for events indicating completion of receiving HTTP streaming responses.
  httpRequest.off('dataEnd');
  // Call the destroy() method to release resources after HttpRequest is complete.
  httpRequest.destroy();
}).catch((err: Error) => {
  console.info("requestInStream ERROR : err = " + JSON.stringify(err));
});
```

