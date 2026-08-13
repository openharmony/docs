# Using HTTP for Network Access

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=4adc34af5c27c45b2593c410f9b794378b879132 translatedAt=2026-08-13T03:09:04.363Z pushedAt=2026-08-13T03:59:21.925Z -->

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->

## When to Use

An app initiates a data request over HTTP, supporting the common GET, POST, OPTIONS, HEAD, PUT, DELETE, TRACE, and CONNECT methods. Two HTTP request modes are currently provided. If the amount of data sent or received in a request is small, use [HttpRequest.request](../reference/apis-network-kit/js-apis-http.md#request). For uploading or downloading large files, where you need to track the data sending and receiving progress, use HTTP request streaming transmission [HttpRequest.requestInStream](../reference/apis-network-kit/js-apis-http.md#requestinstream10). Starting from API version 22, if you need to insert custom logic at key nodes in the "HTTP request-response" lifecycle, use the [HTTP interceptor](#http-interceptor).

<!--RP1-->

<!--RP1End-->

The following table lists the functions supported by the HTTP request. The options corresponding to these functions can be set in [HttpRequestOptions](../reference/apis-network-kit/js-apis-http.md#httprequestoptions) of the HTTP request.

| Category    | Function                          |Feature Description                     | Available Since        |
| ----------- | -----------------------------------|-----------------------------|------------------------|
| Basic    | Setting the request method                     | Specifies the request method, including **GET**, **POST**, **HEAD**, **PUT**, **DELETE**, **TRACE**, **CONNECT**, and **OPTIONS**. The default value is **GET**. |  API version 6  |
| Basic    | Setting additional data of the request                | Specifies that additional data can be carried with the request. This parameter is not used by default.| API version 6    |
| Basic    | Setting the read timeout interval                | Specifies the total time from the start to the end of a request, including DNS resolution, connection setup, and transmission. The default value is **60000**, in ms.|  API version 6   |
| Basic    | Setting the connection timeout interval                | Specifies the connection timeout interval. The default value is **60000**, in ms.|  API version 6   |
| Basic    | Setting the HTTP request header                 | Specifies the HTTP request header. If the request method is **POST**, **PUT**, **DELETE**, or left empty, the default value is {'content-Type': 'application/json'}. Otherwise, the default value is {'content-Type': 'application/x-www-form-urlencoded'}.|  API version 6   |
| Basic    | Setting the response data type               | Specifies the type of the HTTP response data. This parameter is not used by default. If this parameter is set, the system returns the specified type of data preferentially.|  API version 9   |
| Basic    | Setting the priority of concurrent requests             |  Specifies the priority of concurrent HTTP/HTTPS requests. A larger value indicates a higher priority. The value ranges from 1 to 1000. The default value is **1**.|  API version 9   |
| Basic    | Enabling the cache               | Specifies whether to use the cache. The default value is **true**. The data in the cache is preferentially read. The cache takes effect with the current process. The new cache replaces the old cache. If this parameter is set to **false**, the cache is not used.|  API version 9   |
| basic function     | Setting the protocol type                 | Specifies the protocol type. HTTPS requests use HTTP/2 by default and fall back to HTTP/1.1 on failure; HTTP uses HTTP/1.1 directly. You can specify HTTP 1.1, HTTP 2, or HTTP 3 as the protocol version. |  API version 9   |
| Proxy setting    | Setting the HTTP request proxy                | Specifies whether to use the HTTP proxy. The default value is **false**, indicating that proxy is not used. If this parameter is set to **true**, the default proxy of the system is used. You can also configure a custom network proxy through **HttpProxy**.|  API version 10  |
| Certificate verification    | Setting the CA certificate path                  | Specifies the CA certificate path. If the CA certificate path is set, the system uses the CA certificate in the specified path. Otherwise, the system uses the preset CA certificate.| API version 10    |
| Certificate verification    | Setting the transmission of client certificates           | Specifies whether to enable the transmission of client certificates, which include the certificate path, certificate type, certificate key path, and password information.| API version 11    |
| Basic    | Setting the start and end positions of the download        | Specifies the data range to retrieve, which is commonly used in file download scenarios.|  API version 11  |
| Basic    | Setting the list of data fields to be uploaded       |Specifies the multipart form data, which is commonly used in file upload scenarios.|  API version 11   |
| DNS setting     | HTTPS server for DNS resolution. | Specifies whether to use an HTTPS server for DNS resolution. The value must be URL-encoded in the following format: 'https://host:port/path'.| API version 11    |
| DNS setting    | Specifies whether to use the specified DNS server for DNS resolution.<br>        | Specifies whether to use the specified DNS server for DNS resolution.<br> - You can set a maximum of three DNS servers. If there are more than three DNS servers, only the first three DNS servers are used.<br> The DNS servers must be expressed as IPv4 or IPv6 addresses.|  API version 11   |
| Basic    | Setting the maximum number of bytes in a response message           | Specifies the maximum number of bytes in a response message. The unit is byte. The default value is 5 x 1024 x 1024, and the maximum value is 100 x 1024 x 1024.|   API version 11  |
| Certificate verification    | Setting the certificate pinning configuration            | Specifies the certificate pinning configuration. One or more certificate PINs can be specified.|   API version 12  |
| Certificate verification    | Setting the IP address family       | Specifies the IP address family for resolving the target domain name. The address type can be set to follow the system network configuration, forcibly use only IPv4 addresses for resolution, or forcibly use only IPv6 addresses for resolution.|  API version 15   |
| Certificate verification    | Setting whether to skip SSL certificate verification                    | Specifies whether to skip SSL certificate verification.| API version 18    |
| Certificate verification    | Setting the certificate verification version and cipher suite            | Customizes the certificate verification version and cipher suite.|  API version 18  |
| Certificate verification    | Setting server authentication for secure connections       | Specifies server authentication for secure connections.|  API version 18   |
| proxy settings     | Setting SOCKS5 proxy        | Sets a SOCKS5 proxy. By default, no SOCKS5 proxy is used. If a custom SOCKS5 proxy is correctly configured through [Socks5Proxy](../reference/apis-network-kit/js-apis-net-connection.md#socks5proxy), HttpProxy does not take effect. |  API version 26.0.0   |

## Initiating HTTP Data Requests

> **NOTE**
>
> In the sample code provided in this topic, **this.context** is used to obtain the UIAbilityContext, where **this** indicates a UIAbility instance inherited from **UIAbility**. To use **UIAbilityContext** APIs on pages, see [Obtaining the Context of UIAbility](../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

Complete sample code: [Http_case](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_case)

1. Import the **http**, **BusinessError**, and **common** modules.

   <!-- @[HTTP_case_module_import_data_request](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_case/entry/src/main/ets/pages/Index.ets) -->  

   ``` TypeScript
   import { http } from '@kit.NetworkKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   ```

2. Create an **HttpRequest** object.

    Call [createHttp()](../reference/apis-network-kit/js-apis-http.md#httpcreatehttp) to create an **HttpRequest** object.

    <!-- @[HTTP_case_create_http_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_case/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    let context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;
    // Each httpRequest corresponds to an HTTP request task and cannot be reused.
    let httpRequest = http.createHttp();
    ```

3. Subscribe to the HTTP response header events.

    Call the corresponding [on()](../reference/apis-network-kit/js-apis-http.md#onheadersreceive8) method of the object to subscribe to HTTP response header events. This API returns before the request does. You can subscribe to this message based on your business requirement.

   <!-- @[HTTP_case_http_request_on_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_case/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   // This API is used to listen for HTTP Response Header events, which is returned earlier than the result of the HTTP request. It is up to you whether to listen for HTTP response header events.
   // on('headerReceive', AsyncCallback) will be replaced by on('headersReceive', Callback) in API version 8.
   httpRequest.on('headersReceive', (header) => {
    hilog.info(0x0000, 'testTag', `header: ${JSON.stringify(header)}`);
   });
   ```

4. Initiate an HTTP request, and parse the server response event.

    Call the corresponding [request()](../reference/apis-network-kit/js-apis-http.md#httprequest) method of the object, pass in the URL and optional parameters of the HTTP request, initiate the network request, and parse the returned result based on your actual business requirement.

   <!-- @[HTTP_case_http_request_request_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_case/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   httpRequest.request(
     // Customize EXAMPLE_URL in extraData on your own. It is up to you whether to add parameters to the URL.
     'EXAMPLE_URL',
     {
       method: http.RequestMethod.POST, // Optional. The default value is http.RequestMethod.GET. The GET method is used to retrieve data from the server while the POST method is used to submit data such as forms and files to the server.
       // You can add header fields based on service requirements.
       header: {
         'Content-Type': 'application/json'
       },
       // This field is used to transfer the request body when a POST request is used. Its format needs to be negotiated with the server.
       extraData: 'data to send',
       expectDataType: http.HttpDataType.STRING, // Optional. This parameter specifies the type of the return data.
       usingCache: true, // Optional. The default value is true.
       priority: 1, // Optional. The default value is 1.
       connectTimeout: 60000 // Optional. The default value is 60000, in ms.
       readTimeout: 60000, // Optional. The default value is 60000, in ms.
       usingProtocol: http.HttpProtocol.HTTP1_1, // Optional. The default protocol type is automatically specified by the system.
       usingProxy: false, // Optional. By default, network proxy is not used. This field is supported since API version 10.
       caPath: '/path/to/cacert.pem', // Optional. The prebuilt CA certificate is used by default. This field is supported since API version 10.
       clientCert: { // Optional. The client certificate is not used by default. This field is supported since API version 11.
         certPath: '/path/to/client.pem', // The client certificate is not used by default. This field is supported since API version 11.
         keyPath: '/path/to/client.key', // If the certificate contains key information, an empty string is passed. This field is supported since API version 11.
         certType: http.CertType.PEM, // Certificate type, optional. A certificate in the PEM format is used by default. This field is supported since API version 11.
         keyPassword: 'passwordToKey' // Password of the key file, optional. It is supported since API version 11.
       },
       // Optional. This field is valid only when content-Type in the header is multipart/form-data. It is supported since API version 11.
       // This field is used to upload binary data to the server. You can set the field based on the data type to be uploaded.
       multiFormDataList: [
         {
           name: 'Part1', // Data name. This field is supported since API version 11.
           contentType: 'text/plain', // Data type. This field is supported since API version 11. The data to upload must be a common text file.
           data: 'Example data', // Data content, optional. This field is supported since API version 11.
           remoteFileName: 'example.txt' // Optional. This field is supported since API version 11.
         }, {
         name: 'Part2', // Data name. This field is supported since API version 11.
         contentType: 'text/plain', // Data type. This field is supported since API version 11. The data to upload must be a common text file.
         // data/app/el2/100/base/com.example.myapplication/haps/entry/files/fileName.txt
         filePath: `${context.filesDir}/fileName.txt`, // File path, optional. This field is supported since API version 11.
         remoteFileName: 'fileName.txt' // Optional. This field is supported since API version 11.
         }, {
           name: 'Part3', // Data name. This field is supported since API version 11.
           contentType: 'image/png', // Data type. This field is supported since API version 11. The data to be uploaded must be a PNG image.
           // Example: data/app/el2/100/base/com.example.myapplication/haps/entry/files/fileName.png
           filePath: `${context.filesDir}/fileName.png`, // File path, optional. This field is supported since API version 11.
           remoteFileName: 'fileName.png' // Optional. This field is supported since API version 11.
         }, {
           name: 'Part4', // Data name. This field is supported since API version 11.
           contentType: 'audio/mpeg', // Data type. This field is supported since API version 11. The data to be uploaded must be an MPEG audio file.
           // Example: data/app/el2/100/base/com.example.myapplication/haps/entry/files/fileName.mpeg.
           filePath: `${context.filesDir}/fileName.mpeg`, // File path, optional. This field is supported since API version 11.
           remoteFileName: 'fileName.mpeg' // Optional. This field is supported since API version 11.
         }, {
           name: 'Part5', // Data name. This field is supported since API version 11.
           contentType: 'video/mp4', // Data type. This field is supported since API version 11. The data to be uploaded must be an MP4 video file.
           // Example: data/app/el2/100/base/com.example.myapplication/haps/entry/files/fileName.mp4.
           filePath: `${context.filesDir}/fileName.mp4`, // File path, optional. This field is supported since API version 11
           remoteFileName: 'fileName.mp4' // Optional. This field is supported since API version 11.
         }
       ]
     }, (err: BusinessError, data: http.HttpResponse) => {
     if (!err) {
       // ...
       // data.result carries the HTTP response. Parse the response based on service requirements.
       hilog.info(0x0000, 'testTag', `Result: ${JSON.stringify(data.result)}`);
       hilog.info(0x0000, 'testTag', `code: ${JSON.stringify(data.responseCode)}`);
       // data.header carries the HTTP response header. Parse the content based on service requirements.
       hilog.info(0x0000, 'testTag', `header: ${JSON.stringify(data.header)}`);
       hilog.info(0x0000, 'testTag', `cookies: ${JSON.stringify(data.cookies)}`);
       // Call destroy() to destroy the httpRequest object when it is no longer needed.
       httpRequest.destroy();
     } else {
       // ...
       hilog.error(0x0000, 'testTag', `error: ${JSON.stringify(err)}`);
       // Unsubscribe from HTTP Response Header events.
       httpRequest.off('headersReceive');
       // Call the destroy() method to release resources after HttpRequest is complete.
       httpRequest.destroy();
     }
   }
   );
   ```

5. Unsubscribe from HTTP response header events.

    Call the corresponding [off()](../reference/apis-network-kit/js-apis-http.md#offheadersreceive8) method of the object to unsubscribe from HTTP response header events.

    ```ts
    // Unsubscribe from HTTP response header events when the callback information is no longer needed. For details about how to use the API, see the sample code in step 4.
    httpRequest.off('headersReceive');
    ```

6. Call **destroy()** to destroy the **httpRequest** object when it is no longer needed.

    When the request is no longer needed, call [destroy()](../reference/apis-network-kit/js-apis-http.md#destroy) to destroy it.

    ```ts
    // Call destroy to destroy the httpRequest when it is no longer needed. For details about how to use the API, see the sample code in step 4.
    httpRequest.destroy();
    ```

## Initiating an HTTP Streaming Request

HTTP streaming refers to the process where, when handling an HTTP response, only a small chunk of the response content is processed at a time, rather than loading the entire response into memory all at once. This is particularly useful for scenarios such as processing large files and real-time data streams, among others.

Complete sample code: [Http_case](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_case)

1. Import the **http**, **BusinessError**, and **common** modules.

     <!-- @[HTTP_case_module_import_data_request](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_case/entry/src/main/ets/pages/Index.ets) -->

     ``` TypeScript
     import { http } from '@kit.NetworkKit';
     import { BusinessError } from '@kit.BasicServicesKit';
     import { common } from '@kit.AbilityKit';
     import { hilog } from '@kit.PerformanceAnalysisKit';
     ```

2. Create an **HttpRequest** object for HTTP streaming.

    Call [createHttp()](../reference/apis-network-kit/js-apis-http.md#httpcreatehttp) to create an **HttpRequest** object.

    <!-- @[request_in_stream_create_http_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_case/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    // Each httpRequest corresponds to an HTTP request task and cannot be reused.
    let httpRequest = http.createHttp();
    ```

3. Subscribe to HTTP streaming response events on demand.

   The data returned by the server is returned in the **dataReceive** callback. You can obtain the server response data by subscribing to this message. Other streaming response events can be subscribed to on demand.

   <!-- @[request_in_stream_data_receive](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_case/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   // Subscribe to events indicating receiving of HTTP streaming responses.
   let res = new ArrayBuffer(0);
   // ...
   // Register an observer for events indicating receiving of HTTP streaming responses.
   httpRequest.on('dataReceive', (data: ArrayBuffer) => {
     const newRes = new ArrayBuffer(res.byteLength + data.byteLength);
     const resView = new Uint8Array(newRes);
     resView.set(new Uint8Array(res));
     resView.set(new Uint8Array(data), res.byteLength);
     res = newRes;
     hilog.info(0x0000, 'testTag', `res length: ${res.byteLength}`);
   });
   
   // Subscribe to events indicating completion of receiving HTTP streaming responses.
   httpRequest.on('dataEnd', () => {
     hilog.info(0x0000, 'testTag', `No more data in response, data receive end`);
   });
   
   // Subscribe to events indicating progress of receiving HTTP streaming responses. When downloading data from the server, you can obtain the data download progress through this callback.
   httpRequest.on('dataReceiveProgress', (data: http.DataReceiveProgressInfo) => {
     hilog.info(0x0000, 'testTag', 'dataReceiveProgress receiveSize:' + data.receiveSize + ', totalSize:' + data.totalSize);
   });
   
   // Subscribe to events indicating progress of sending HTTP streaming responses. When uploading data from the server, you can obtain the data upload progress through this callback.
   httpRequest.on('dataSendProgress', (data: http.DataSendProgressInfo) => {
     hilog.info(0x0000, 'testTag', 'dataSendProgress receiveSize:' + data.sendSize + ', totalSize:' + data.totalSize);
   });
   ```

4. Initiate an HTTP streaming request to obtain server data.

   <!-- @[request_in_stream_get_server_data](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_case/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   let streamInfo: http.HttpRequestOptions = {
     method: http.RequestMethod.POST, // Optional. The default value is http.RequestMethod.GET. The GET method is used to retrieve data from the server while the POST method is used to submit data such as forms and files to the server.
     // You can add header fields based on service requirements.
     header: {
       'Content-Type': 'application/json'
     },
     // This field is used to transfer the request body when a POST request is used. Its format needs to be negotiated with the server.
     extraData: 'data to send', // Request body
     expectDataType: http.HttpDataType.STRING, // Optional. This parameter specifies the type of the return data.
     usingCache: true,  // Optional. The default value is true.
     priority: 1, // Optional. The default value is 1.
     connectTimeout: 60000 // Optional. The default value is 60000, in ms.
     readTimeout: 60000, // Optional. The default value is 60000, in ms. If a large amount of data needs to be transmitted, you are advised to set this parameter to a larger value to ensure normal data transmission.
     usingProtocol: http.HttpProtocol.HTTP1_1 // Optional. The default protocol type is automatically specified by the system.
   };
   
   // Customize EXAMPLE_URL in extraData on your own. It is up to you whether to add parameters to the URL.
   httpRequest.requestInStream('EXAMPLE_URL', streamInfo)
     .then((data: number) => {
       // ...
       hilog.info(0x0000, 'testTag', `requestInStream OK!`);
       hilog.info(0x0000, 'testTag', `ResponseCode : ${JSON.stringify(data)}`);
       // Unsubscribe from the events subscribed in step 3, and call the destroy method to destroy the httpRequest object.
       this.destroyRequest(httpRequest);
       // ...
     }).catch((err: Error) => {
       // ...
       hilog.error(0x0000, 'testTag', `requestInStream ERROR : err = ${JSON.stringify(err)}`);
       // Unsubscribe from the events subscribed in step 3, and call the destroy method to destroy the httpRequest object.
       this.destroyRequest(httpRequest);
     })
   ```

5. Unsubscribe from the HTTP streaming response events subscribed in step 3, and call **destroy()** to destroy the **httpRequest** object.

    Call the corresponding [off()](../reference/apis-network-kit/js-apis-http.md#offdatareceive10) method of the object to unsubscribe from the events in step 3, and when the request is no longer needed, call [destroy()](../reference/apis-network-kit/js-apis-http.md#destroy) to destroy it. For the timing of calling this method, see the sample code in step 4.

   <!-- @[request_in_stream_destroy_request_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_case/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   public destroyRequest(httpRequest: http.HttpRequest) {
     // Unsubscribe from the events indicating receiving of HTTP streaming responses.
     httpRequest.off('dataReceive');
     // Unsubscribe from the events indicating progress of sending HTTP streaming responses.
     httpRequest.off('dataSendProgress');
     // Unsubscribe from the events indicating progress of receiving HTTP streaming responses.
     httpRequest.off('dataReceiveProgress');
     // Unsubscribe from the events indicating completion of receiving HTTP streaming responses.
     httpRequest.off('dataEnd');
     // Call destroy() to destroy the httpRequest object when it is no longer needed.
     httpRequest.destroy();
   }
   ```

## Initiating a WebDAV Request Using HTTP

In API version 23 and later versions, HTTP requests support WebDAV-based file access. WebDAV is an extension of HTTP and supports operations such as creating, reading, updating, deleting, moving, and copying (MKCOL, GET, PUT, DELETE, MOVE and COPY) files on remote servers.

Complete sample code: [Http_case](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_case)

<!-- @[HTTP_webDav](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_case/entry/src/main/ets/pages/WebDav.ets) -->

``` TypeScript
import { http } from '@kit.NetworkKit';
import { ComponentId } from '../common/CommonConstant';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@Component
struct Index {
  proppatchXml = `example_proppatchXml`; // Modify the resource XML.
  lockXml: string = `example_lockXml`; // Lock the XML.
  lockToken: string = '';

  build() {
    Column({ space: 5 }) {
      Button($r('app.string.HTTP_WEBDAV_PUT'))
        .id(ComponentId.HTTP_WEBDAV_PUT)
        .onClick(async () => {
          let httpRequest = http.createHttp();
          let file = 'example';
          httpRequest.request('EXAMPLE_URL' + 'example.txt',
            {
              expectDataType: http.HttpDataType.STRING,
              extraData: file, // Upload file content.
              header: { 'Content-Type': 'text/plain; charset=utf-8', 'Content-Length': file.length.toString() },
              customMethod: 'PUT' // Custom method of the WebDAV protocol PUT request.
            },
            (err: Error, data: http.HttpResponse) => {
              if (!err) {
                hilog.info(0x0000, 'testTag', 'Result:' + data.result);
                hilog.info(0x0000, 'testTag', 'code:' + data.responseCode);
                hilog.info(0x0000, 'testTag', 'header:' + JSON.stringify(data.header));
                httpRequest.destroy();
              } else {
                hilog.error(0x0000, 'testTag', 'error:' + JSON.stringify(err));
                httpRequest.destroy();
              }
            })
        })

      Button($r('app.string.HTTP_WEBDAV_GET'))
        .id(ComponentId.HTTP_WEBDAV_GET)
        .onClick(() => {
          let httpRequest = http.createHttp();
          httpRequest.request('EXAMPLE_URL' + 'example.txt',
            {
              expectDataType: http.HttpDataType.STRING,
              customMethod: 'GET' // Custom method of the WebDAV protocol GET request.
            },
            (err: Error, data: http.HttpResponse) => {
              if (!err) {
                hilog.info(0x0000, 'testTag', 'Result:' + data.result.toString());
                hilog.info(0x0000, 'testTag', 'code:' + data.responseCode);
                hilog.info(0x0000, 'testTag', 'header:' + JSON.stringify(data.header));
                httpRequest.destroy();
              } else {
                hilog.error(0x0000, 'testTag', 'error:' + JSON.stringify(err));
                httpRequest.destroy();
              }
            })
        })

      Button($r('app.string.HTTP_WEBDAV_MKCOL'))
        .id(ComponentId.HTTP_WEBDAV_MKCOL)
        .onClick(() => {
          let httpRequest = http.createHttp();
          httpRequest.request('EXAMPLE_URL' + 'example/',
            {
              expectDataType: http.HttpDataType.STRING,
              customMethod: 'MKCOL' // Custom method of the WebDAV protocol MKCOL request.
            },
            (err: Error, data: http.HttpResponse) => {
              if (!err) {
                hilog.info(0x0000, 'testTag', 'Result:' + data.result);
                hilog.info(0x0000, 'testTag', 'code:' + data.responseCode);
                hilog.info(0x0000, 'testTag', 'header:' + JSON.stringify(data.header));
                httpRequest.destroy();
              } else {
                hilog.error(0x0000, 'testTag', 'error:' + JSON.stringify(err));
                httpRequest.destroy();
              }
            })
        })

      Button($r('app.string.HTTP_WEBDAV_DELETE'))
        .id(ComponentId.HTTP_WEBDAV_DELETE)
        .onClick(() => {
          let httpRequest = http.createHttp();
          httpRequest.request('EXAMPLE_URL' + 'example/',
            {
              expectDataType: http.HttpDataType.STRING,
              header: { 'Content-Type': 'text/xml' },
              customMethod: 'DELETE' // Custom method of the WebDAV protocol DELETE request.
            },
            (err: Error, data: http.HttpResponse) => {
              if (!err) {
                hilog.info(0x0000, 'testTag', 'Result:' + data.result);
                hilog.info(0x0000, 'testTag', 'code:' + data.responseCode);
                hilog.info(0x0000, 'testTag', 'header:' + JSON.stringify(data.header));
                httpRequest.destroy();
              } else {
                hilog.error(0x0000, 'testTag', 'error:' + JSON.stringify(err));
                httpRequest.destroy();
              }
            })
        })

      Button($r('app.string.HTTP_WEBDAV_COPY'))
        .id(ComponentId.HTTP_WEBDAV_COPY)
        .onClick(() => {
          let httpRequest = http.createHttp();
          httpRequest.request('EXAMPLE_URL' + 'example.txt',
            {
              expectDataType: http.HttpDataType.STRING,
              header: { 'Destination': 'EXAMPLE_URL' + 'new_example.txt' },
              customMethod: 'COPY' // Custom method of the WebDAV protocol COPY request.
            },
            (err: Error, data: http.HttpResponse) => {
              if (!err) {
                hilog.info(0x0000, 'testTag', 'Result:' + data.result);
                hilog.info(0x0000, 'testTag', 'code:' + data.responseCode);
                hilog.info(0x0000, 'testTag', 'header:' + JSON.stringify(data.header));
                httpRequest.destroy();
              } else {
                hilog.error(0x0000, 'testTag', 'error:' + JSON.stringify(err));
                httpRequest.destroy();
              }
            })
        })

      Button($r('app.string.HTTP_WEBDAV_MOVE'))
        .id(ComponentId.HTTP_WEBDAV_MOVE)
        .onClick(() => {
          let httpRequest = http.createHttp();
          httpRequest.request('EXAMPLE_URL' + 'example.txt',
            {
              expectDataType: http.HttpDataType.STRING,
              header: { 'Destination': 'EXAMPLE_URL' + 'reNameText.txt' },
              customMethod: 'MOVE' // Custom method of the WebDAV protocol MOVE request.
            },
            (err: Error, data: http.HttpResponse) => {
              if (!err) {
                hilog.info(0x0000, 'testTag', 'Result:' + data.result);
                hilog.info(0x0000, 'testTag', 'code:' + data.responseCode);
                hilog.info(0x0000, 'testTag', 'header:' + JSON.stringify(data.header));
                httpRequest.destroy();
              } else {
                hilog.error(0x0000, 'testTag', 'error:' + JSON.stringify(err));
                httpRequest.destroy();
              }
            })
        })

      Button($r('app.string.HTTP_WEBDAV_PROPPATCH'))
        .id(ComponentId.HTTP_WEBDAV_PROPPATCH)
        .onClick(() => {
          let httpRequest = http.createHttp();
          httpRequest.request('EXAMPLE_URL' + 'example.txt',
            {
              extraData: this.proppatchXml,
              expectDataType: http.HttpDataType.STRING,
              header: { 'Content-Type': 'application/xml; charset=utf-8', 'Depth': 'infinity' },
              customMethod: 'PROPPATCH' // Custom method of the WebDAV protocol PROPPATCH request.
            },
            (err: Error, data: http.HttpResponse) => {
              if (!err) {
                hilog.info(0x0000, 'testTag', 'Result:' + data.result);
                hilog.info(0x0000, 'testTag', 'code:' + data.responseCode);
                hilog.info(0x0000, 'testTag', 'header:' + JSON.stringify(data.header));
                httpRequest.destroy();
              } else {
                hilog.error(0x0000, 'testTag', 'error:' + JSON.stringify(err));
                httpRequest.destroy();
              }
            })
        })

      Button($r('app.string.HTTP_WEBDAV_PROPFIND'))
        .id(ComponentId.HTTP_WEBDAV_PROPFIND)
        .onClick(() => {
          let httpRequest = http.createHttp();
          httpRequest.request('EXAMPLE_URL' + 'example.txt',
            {
              expectDataType: http.HttpDataType.STRING,
              header: {
                'Content-Type': 'text/xml',
                'Depth': '0'
              },
              customMethod: 'PROPFIND' // Custom method of the WebDAV protocol PROPFIND request.
            },
            (err: Error, data: http.HttpResponse) => {
              if (!err) {
                hilog.info(0x0000, 'testTag', 'Result:' + data.result);
                hilog.info(0x0000, 'testTag', 'code:' + data.responseCode);
                hilog.info(0x0000, 'testTag', 'header:' + JSON.stringify(data.header));
                httpRequest.destroy();
              } else {
                hilog.error(0x0000, 'testTag', 'error:' + JSON.stringify(err));
                httpRequest.destroy();
              }
            })
        })

      Button($r('app.string.HTTP_WEBDAV_LOCK'))
        .id(ComponentId.HTTP_WEBDAV_LOCK)
        .onClick(() => {
          let httpRequest = http.createHttp();
          httpRequest.request('EXAMPLE_URL' + 'example.txt',
            {
              extraData: this.lockXml,
              expectDataType: http.HttpDataType.STRING,
              header: {
                'Content-Type': 'application/xml',
                'Depth': '0',
              },
              customMethod: 'LOCK' // Custom method of the WebDAV protocol LOCK request.
            },
            (err: Error, data: http.HttpResponse) => {
              if (!err) {
                let lockTokenRegex = /<D:href>(urn:uuid:[a-fA-F0-9\-]+)<\/D:href>/;
                let statusMatch: RegExpMatchArray | null = (data.result as string).match(lockTokenRegex);
                if (statusMatch) {
                  this.lockToken = statusMatch[1];
                }
                hilog.info(0x0000, 'testTag', 'Result:' + data.result);
                hilog.info(0x0000, 'testTag', 'code:' + data.responseCode);
                hilog.info(0x0000, 'testTag', 'header:' + JSON.stringify(data.header));
                hilog.info(0x0000, 'testTag', 'lockToken:' + this.lockToken);
                httpRequest.destroy();
              } else {
                hilog.error(0x0000, 'testTag', 'error:' + JSON.stringify(err));
                httpRequest.destroy();
              }
            })
        })

      Button($r('app.string.HTTP_WEBDAV_UNLOCK'))
        .id(ComponentId.HTTP_WEBDAV_UNLOCK)
        .onClick(() => {
          let httpRequest = http.createHttp();
          httpRequest.request('EXAMPLE_URL' + 'example.txt',
            {
              header: {
                'Content-Length': '0',
                'Lock-Token': this.lockToken, // Return the key when adding a lock.
                'Depth': '0'
              },
              customMethod: 'UNLOCK' // Custom method of the WebDAV protocol UNLOCK request.
            },
            (err: Error, data: http.HttpResponse) => {
              if (!err) {
                hilog.info(0x0000, 'testTag', 'Result:' + data.result);
                hilog.info(0x0000, 'testTag', 'code:' + data.responseCode);
                hilog.info(0x0000, 'testTag', 'header:' + JSON.stringify(data.header));
                httpRequest.destroy();
              } else {
                hilog.error(0x0000, 'testTag', 'error:' + JSON.stringify(err));
                httpRequest.destroy();
              }
            })
        })

      Button($r('app.string.HTTP_WEBDAV_UNKNOWN'))
        .id(ComponentId.HTTP_WEBDAV_UNKNOWN)
        .onClick(() => {
          let httpRequest = http.createHttp();
          httpRequest.request('EXAMPLE_URL',
            {
              customMethod: 'UNKNOWN' // Custom method of a non-WebDAV request
            },
            (err: Error, data: http.HttpResponse) => {
              if (!err) {
                hilog.info(0x0000, 'testTag', 'Result:' + data.result);
                hilog.info(0x0000, 'testTag', 'code:' + data.responseCode);
                hilog.info(0x0000, 'testTag', 'header:' + JSON.stringify(data.header));
                httpRequest.destroy();
              } else {
                hilog.error(0x0000, 'testTag', 'error:' + JSON.stringify(err));
                httpRequest.destroy();
              }
            })
        })
    }
    .width('100%')
    .height('100%')
    .justifyContent(FlexAlign.Center)
  }
}
```

## Configuring Certificate Verification

Certificate-related configurations are required for using the HTTPS protocol. The applications that provide services for Internet users only need to trust the system's prebuilt CA certificates. Currently, the HTTP module trusts the CA certificates preset in the system by default. No special setting is required. If an application needs to trust only the certificates specified by developers, or skip certificate verification, you can configure certificate pinning.

### Certificate Verification Process on the TLS Client

   During the TLS handshake, the client verifies the server certificate to ensure that the connection is trusted. The server certificate usually includes the domain name certificate and intermediate CA certificate.

 **Certificate Chain Composition**

   The certificate chain adopts the hierarchical trust structure: **server certificate ← intermediate CA certificate ← root CA certificate**. The **←** symbol indicates the issuance and trust relationship. The certificate chain must be fully traceable back to a trusted root certificate.

**Process to Be Verified**

   After receiving the certificate chain, the client performs three-level verification:

1. Verify the integrity of the certificate chain.

   - Starting from the server certificate, verify the digital signature level by level to ensure that each level of the certificate is validly issued by the previous level, thereby forming a complete trust chain.

2. Verify the trustworthiness of the root certificate.

   - Check whether the root certificate exists in the certificate repository.

   - The repository sources are as follows:

     - Preset certificate.

     - Application trust certificate.

     - CA certificate specified by the request.

   - You can specify the application-level and request-level trust certificates using related APIs (for details, see the following **Configuration Reference**).

3. Verify the validity of the certificate content.

   - Certificate validity period check.

   - Domain name matching verification: The subject alternative name (SAN) and common name (CN) are the same as the access domain name.

   - Certificate revocation status check: Certificate Revocation List (CRL) and Online Certificate Status Protocol (OCSP).

 Verification Result

   - Verification succeeds: The TLS handshake continues and a secure connection is established.

   - Verification fails: The connection is terminated and an error message is displayed.

This process ensures that only the server that holds a valid and trusted certificate can establish a secure connection.

 **Configuration Reference**

1. Configuring the application trust certificate: [Network Connection Security Configuration](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-network-ca-security#section5454123841911).

2. Configuring the request-level CA certificate:

   - Configuring the HTTPS request CA certificate through the caPath and caData fields of [httprequestoptions](../reference/apis-network-kit/js-apis-http.md#httprequestoptions).

   - Configuring the WebSocket request CA certificate through the caPath field of [websocketrequestoptions](../reference/apis-network-kit/js-apis-webSocket.md#websocketrequestoptions).

   - Specifying the TLS request CA certificate through the ca field of [tlssecureoptions](../reference/apis-network-kit/js-apis-socket.md#tlssecureoptions9).

3. Configuring certificate verification skipping:

   - HTTPS: configure through [remoteValidation](../reference/apis-network-kit/js-apis-http.md#remotevalidation18) = 'skip'.

   - WebSocket: configure through skipServerCertVerification = true of [websocketrequestoptions](../reference/apis-network-kit/js-apis-webSocket.md#websocketrequestoptions).

   - TLSSocket: configure through skipRemoteValidation = true of [tlsconnectoptions](../reference/apis-network-kit/js-apis-socket.md#tlsconnectoptions9).

 **Debugging Reference**

   - Check whether the specified certificate is trusted through the API. For details, see [networkSecurity.certVerification](../reference/apis-network-kit/js-apis-networkSecurity.md#networksecuritycertverification).

   - Use the OpenSSL command to verify whether the domain name server certificate chain is trusted by the system: `hdc shell openssl s_client -connect host:port -CApath /etc/security/certificates -brief`. If `Verification: OK` appears, the certificate chain is trusted. Replace `-brief` with `-trace -showcerts` to print detailed TLS handshake information.

### Certificate Pinning

You can prebuild application-level certificates or public key hash values for certificate pinning. This way, an HTTPS connection can be established only when the prebuilt certificate is used.

Both modes are configured through `src/main/resources/base/profile/network_config.json`. In the configuration file, you can create a mapping between prebuilt certificates and network servers.

If you do not know the certificate mapping a server domain name, you can use the following command to obtain the certificate. When running the command, change `www.example.com` to the server domain name and `www.example.com.pem` to the name of the obtained certificate file.

```ts
openssl s_client -servername www.example.com -connect www.example.com:443 \
    < /dev/null | sed -n "/-----BEGIN/,/-----END/p" > www.example.com.pem
```

If you are using a Windows environment, you need to:

* Replace `/dev/null` with `NUL`.

* Press **Enter** to exit. This is different from OpenSSL of Linux, which may exit until the user enters a value.

* If the **sed** command is not present, copy the content between `-----BEGIN CERTIFICATE-----` and `-----END CERTIFICATE-----` (with these two lines included) in the command output and save it.

**Prebuilding Application-level Certificate**

Prebuilding application-level certificates means to embed the original certificate files in the application. Currently, certificate files in the **.crt** and **.pem** formats are supported.

> **NOTE**
>
> Currently, certificate pinning has been enabled for the ohos.net.http and Image components, and the hash values of all certificates in the certificate chain are matched. If any certificate is updated on the server, the verification fails. Therefore, if any certificate on the server has been updated, upgrade the application to the latest version as soon as possible. Otherwise, network connection may fail.

**Prebuilding Certificate Public Key Hash Values**

You can create mapping between public key hash values and domain name certificates in the configuration file. This way, access to the domain name is allowed only if the used domain name certificate matches the prebuilt public key hash value.

The public key hash value of the domain name certificate can be calculated using the following command. Assume that the domain name certificate is obtained using the preceding OpenSSL command and saved in the `www.example.com.pem` file. The line that starts with # is treated as a comment.

```ts
# Extract the public key from the certificate.
openssl x509 -in www.example.com.pem -pubkey -noout > www.example.com.pubkey.pem
# Convert the public key from the pem format to the der format.
openssl asn1parse -noout -inform pem -in www.example.com.pubkey.pem -out www.example.com.pubkey.der
# Calculate the SHA256 of the public key and convert it to Base64.
openssl dgst -sha256 -binary www.example.com.pubkey.der | openssl base64
```

**Example JSON Configuration File**

The following is an example of prebuilt application-level certificates. For details about the configuration path, see [Network Connection Security Configuration](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-network-ca-security#section5454123841911).

```json
{
  "network-security-config": {
    "base-config": {
      "trust-anchors": [
        {
          "certificates": "/etc/security/certificates"
        }
      ]
    },
    "domain-config": [
      {
        "domains": [
          {
            "include-subdomains": true,
            "name": "example.com"
          }
        ],
        "trust-anchors": [
          {
            "certificates": "/data/storage/el1/bundle/entry/resources/resfile"
          }
        ]
      }
    ]
  }
}
```

The following is an example of prebuilt certificate public key hash values:

```json
{
  "network-security-config": {
    "domain-config": [
      {
        "domains": [
          {
            "include-subdomains": true,
            "name": "*.server.com"
          }
        ],
        "pin-set": {
          "expiration": "2024-11-08",
          "pin": [
            {
              "digest-algorithm": "sha256",
              "digest": "FEDCBA987654321"
            }
          ]
        }
      }
    ]
  }
}
```

The following is an example configuration of the certificate pin:

```json
{
  "network-security-config": {
    "domain-config": [
      {
        "domains": [
          {
            "include-subdomains": true,
            "name": "*.server.com"
          }
        ],
        "pin-set": {
          "expiration": "2024-11-08",
          "pin": [
            {
              "digest-algorithm": "sha256",
              "digest": "FEDCBA987654321"
            }
          ]
        }
      }
    ]
  },
  "trust-global-user-ca": false,
  "trust-current-user-ca": false
}
```

**Description of fields**

| Field                     | Type           | Description                                  |
| --------------------------| --------------- | -------------------------------------- |
|network-security-config    | object          |Network security configuration. The value can contain zero or one **base-config** and must contain one **domain-config**.|
|base-config                | object          |Application security configuration. The value must contain one **trust-anchors**.                         |
|domain-config              | array           |Domain security configuration. The value can contain any number of items. An item must contain one **domains** and can contain zero or one **trust-anchors** and **pin-set**.|
|trust-anchors              | array           |Trusted CA. The value can contain any number of items. An item must contain one **certificates**.|
|certificates               | string          |CA certificate path.|
|domains                    | array           |Domain. The value can contain any number of items. An item must contain one **name** (string: domain name) and can contain zero or one **include-subdomains**.|
|include-subdomains         | boolean         |Whether the rule applies to subdomains. **true**: the rule applies to the domain and all its subdomains; **false**: the rule applies only to the domain. The default value is **true**. |
|pin-set                    | object          |Certificate public key hash setting. The value must contain one **pin** and can contain zero or one **expiration**.|
|expiration                 | string          |Expiration time of the certificate public key hash.|
|pin                        | array           |Certificate public key hash. The value can contain any number of items. An item must contain one **digest-algorithm** and **digest**.|
|digest-algorithm           | string          |Digest algorithm used to generate hashes. Currently, only `sha256` is supported.                                   |
|digest                     | string          |Public key hash.|

### Configuring Untrusted User-Installed CA Certificates

By default, the system trusts the prebuilt CA certificates and user-installed CA certificates. To further improve security, you can configure untrusted user-installed CA certificates in **src/main/resources/base/profile/network_config.json**. For more network connection security configurations, see [Network Connection Security Configuration](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-network-ca-security#section5454123841911).

```json5
{
  "network-security-config": {
    // Other network security configurations.
  },
  "trust-global-user-ca": false, // Set whether to trust the CA certificate manually installed by the enterprise MDM system or device administrator. The default value is true.
  "trust-current-user-ca" : false // Set whether to trust the certificate installed by the current user. The default value is true.
}
```

### Configuring Plaintext HTTP Access Permissions

This configuration item is used to control whether HTTP requests can be transmitted in plaintext. The following is an example of configuring plaintext HTTP access permissions (including application, component, and domain name configurations) and the description of each field. For more network connection security configurations, see [Network Connection Security Configuration](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-network-ca-security#section5454123841911).
> **NOTE**
>
> The configuration priority rules are as follows: **component-config** > **domain-config** > **base-config**. The configuration with a higher priority overrides the configuration with a lower priority.

``` json5
// src/main/resources/base/profile/network_config.json
{
  "network-security-config": {
    "base-config": {
      "cleartextTrafficPermitted": true // Optional. Supported since API version 18.
    },
    "domain-config": [
      {
        "domains": [
          {
            "include-subdomains": true,
            "name": "example.com"
          }
        ],
        "cleartextTrafficPermitted": false // Optional. Supported since API version 18.
      }
    ],
    "component-config": {
        "Request": true, // Optional. Supported since API version 20. The default value is true. The value true indicates that prohibiting plaintext transmission is supported, and false indicates that prohibiting plaintext transmission is not supported.
        "Network Kit": true, // Optional. Supported since API version 20.
        "ArkWeb": false, // Optional. Supported since API version 20.
        "Media Kit": false, // Optional. Supported since API version 23.
        "Remote Communication Kit": false // Optional, supported since API version 23.
    }
  }
}
```

**Description of fields**

| Field                     | Type           | Mandatory| Description                                  |
| --------------------------| --------------- |--------- |-------------------------------------- |
|base-config                     | object          | No| Indicates the application-wide cleartext configuration. It has the lowest priority. |
|cleartextTrafficPermitted<sup>18+</sup>  | boolean          |No| Whether plaintext HTTP is allowed. The value **true** indicates that plaintext HTTP is allowed, and the value **false** indicates the opposite.|
|domain-config                     | array          | No|  Indicates the plaintext configuration of each domain. The value can contain any number of items. Each item must contain one **domains**. If rules conflict in the same domain, the first matched rule is used. The priority is lower than that of **component-config**.|
|include-subdomains         | boolean         | No| Indicates whether the rule applies to subdomains. The value **true** indicates that it applies to subdomains, and **false** indicates that it does not. It defaults to **true**. Note: For every additional 1000 domain configurations, the latency of regular expression matching increases by approximately 10 to 15 milliseconds. When the number of domain configurations exceeds 10000, regular expression matching incurs high latency. It defaults to **true**. |
|name         | string         | No| Main domain name.|
|component-config<sup>20+</sup>                    | object         |  No| Indicates the cleartext configuration of each component. It has the highest priority.|
|Request                    | boolean          |No| [Request](../reference/apis-basic-services-kit/js-apis-request.md) supports cleartext HTTP by default since API version 18, and this cannot be configured. Since API version 20, you can enable or disable cleartext HTTP. The value **true** indicates support, and **false** indicates no support. It defaults to **true**.|
|Network Kit                 | boolean          |No| Network Kit supports plaintext HTTP by default since API version 18. The plaintext HTTP feature cannot be configured. Plaintext HTTP can be enabled or disabled since API version 20. The value **true** indicates that plaintext transmission is enabled, and the value **false** indicates the opposite. The default value is **true**.|
|ArkWeb                    | boolean          |No| Plaintext HTTP can be enabled or disabled since API version 20. The value **true** indicates that plaintext transmission is enabled, and the value **false** indicates the opposite. The default value is **false**.|
|Media Kit                    | boolean          |No|Plaintext HTTP can be enabled or disabled since API version 23. The value **true** indicates that plaintext transmission is enabled, and the value **false** indicates the opposite. The default value is **false**.|
|Remote Communication Kit                    | boolean          |No| Plaintext HTTP can be enabled or disabled since API version 23. The value **true** indicates that plaintext transmission is enabled, and the value **false** indicates the opposite. The default value is **false**.|

## HTTP Interceptor

From API version 22, the HTTP Interceptor module provides a powerful and customizable mechanism that allows developers to insert custom logic at key points in the "HTTP request-response" lifecycle. With interceptors, you can implement global features such as request header/body modification, cache policy, redirection, network monitoring, and response preprocessing without modifying the core network code.

### Intercept Point Description

| Point Name                       | Position Description                                                    | Output and Input Parameters of the interceptorHandle API for the Intercept Point                                                  |
| :-------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| INITIAL_REQUEST  | The first intercept point after the initial request is assembled. Suitable for adding global parameters, signing, and encrypting the request body.| The output parameter **true** indicates that the **request** value in the input parameter is the original value and can be modified, while the **response** value is empty and cannot be modified.<br>The output parameter **false** indicates that the **request** value in the input parameter is the original value and cannot be modified, while the **response** value is empty and can be modified.|
| NETWORK_CONNECT | Before a network connection is established, for example, a TCP/TLS connection. Suitable for operations related to the network link, such as recording the network connection start time. | The output parameter **true** indicates that the **request** value in the input parameter is the original value and can be modified, while the **response** value is empty and cannot be modified.<br>The output parameter **false** indicates that the **request** value in the input parameter is the original value and cannot be modified, while the **response** value is empty and can be modified. |
| CACHE_CHECKED      | Located after the cache check logic hits the cache and determined that the cache is available. Suitable for viewing the cache value or modifying the queried cache result.| The output parameter **true** indicates that the **request** value in the input parameter is the original value and cannot be modified, while the **response** value is the original value and cannot be modified.<br>The output parameter **false** indicates that the **request** value in the input parameter is the original value and cannot be modified, while the **response** value is the original value and can be modified.|
| REDIRECTION      | Located before a redirection response is received and a new request is ready to be sent. Allows the target URL or request information of redirection to be modified.| The output parameter **true** indicates that the **request** value in the input parameter is the original value and the URL can be modified. The **response** value is the original value and the modification is invalid.<br>The output parameter **false** indicates that the **request** value in the input parameter is the original value and cannot be modified, while the **response** value is the original value and can be modified.|
| FINAL_RESPONSE   | Located after the final response is obtained. The last intercept point, which is suitable for unified decryption, parsing, logging, and error handling of responses.| The output parameter **true** indicates that the **request** value in the input parameter is the original value and cannot be modified, while the **response** value is the original value and cannot be modified.<br>The output parameter **false** indicates that the **request** value in the input parameter is the original value and cannot be modified, while the **response** value is the original value and can be modified.|

**Sequential Execution**: The interceptor is triggered in the sequence specified by INITIAL_REQUEST > CACHE_CHECKED > NETWORK_CONNECT > (REDIRECTION) > FINAL_RESPONSE. (The bracket indicates that if the request involves redirection, it will go through the redirection interceptor.)

**Redirection Loop**: This is the most critical loop in the process. When the **REDIRECTION** interceptor is triggered, the process jumps back to the **NETWORK_CONNECT** phase and starts a new request cycle until no redirection occurs. This ensures that the new request after redirection can be correctly processed by all necessary interceptors (such as adding authentication headers and recording logs).

**Cache interception**: **CACHE_CHECKED** is a decision point. If the cache exists and is valid, the request is processed by **CACHE_CHECKED** and directly jumps to the **FINAL_RESPONSE** phase to return the cache data, avoiding unnecessary network operations.

### HTTP Interceptor Development Procedure

1.  Import the modules required by the HTTP request interceptor.

    <!-- @[HTTP_interceptor_case_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_interceptor_case/entry/src/main/ets/pages/Index.ets) -->  

    ``` TypeScript
    import { http } from '@kit.NetworkKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    ```

2.  Call [createHttp()](../reference/apis-network-kit/js-apis-http.md#httpcreatehttp) to create an **HttpRequest** object.

     <!-- @[HTTP_interceptor_case_creat_request](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_interceptor_case/entry/src/main/ets/pages/Index.ets) -->

     ``` TypeScript
     // Create an HTTP request.
     let httpRequest: http.HttpRequest = http.createHttp();
     ```

3.  Call [HttpInterceptorChain()](../reference/apis-network-kit/js-apis-http.md#httpinterceptorchain22) to create an interceptor chain object.

    <!-- @[HTTP_interceptor_case_chain](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_interceptor_case/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    // Create an interceptor chain.
    let chain: http.HttpInterceptorChain = new http.HttpInterceptorChain();
    ```

4.  Create an interceptor class to implement the **http.HttpInterceptor** API.

    <!-- @[HTTP_interceptor_case_creat_http_interceptor](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_interceptor_case/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    class InitialHttpInterceptor implements http.HttpInterceptor {
      interceptorType: http.InterceptorType = http.InterceptorType.INITIAL_REQUEST;
      result: boolean = false;
    
      constructor(interceptorType: http.InterceptorType, result: boolean) {
        this.interceptorType = interceptorType;
        this.result = result;
      }
    
      interceptorHandle(reqContext: http.HttpRequestContext, rspContext: http.HttpResponse): Promise<http.ChainContinue> {
        // Perform operations on request packets and responses after the interceptor is hit.
        hilog.info(0xFF00, 'httpNormalRequest', `INITIAL_REQUEST, Original req: ${JSON.stringify(reqContext)}`);
        hilog.info(0xFF00, 'httpNormalRequest', `INITIAL_REQUEST, Original rsp: ${JSON.stringify(rspContext)}`);
    
        reqContext.url = EXAMPLE_INITIAL_URL;
        reqContext.header = { 'content-type': 'text/plain' };
        reqContext.body = { 'context': 'INITIAL_REQUEST' };
    
        rspContext.result = 'INITIAL_REQUEST';
        rspContext.responseCode = 200;
        rspContext.header =
          'content-encoding:br \r\n content-type:text/html\r\ncharset=UTF-8,cxy_all:+5c4ea5d1638626cbb796a7db10e0d663\r\ndate:Tue';
    
        hilog.info(0xFF00, 'httpNormalRequest', `INITIAL_REQUEST, Update req: ${JSON.stringify(reqContext)}`);
        hilog.info(0xFF00, 'httpNormalRequest', `INITIAL_REQUEST, Update rsp: ${JSON.stringify(rspContext)}`);
        return Promise.resolve(this.result);
      }
    }
    
    class NetworkHttpInterceptor implements http.HttpInterceptor {
      interceptorType: http.InterceptorType = http.InterceptorType.INITIAL_REQUEST;
      result: boolean = false;
    
      constructor(interceptorType: http.InterceptorType, result: boolean) {
        this.interceptorType = interceptorType;
        this.result = result;
      }
    
      interceptorHandle(reqContext: http.HttpRequestContext, rspContext: http.HttpResponse): Promise<http.ChainContinue> {
        // Perform operations on request packets and responses after the interceptor is hit.
        hilog.info(0xFF00, 'httpNormalRequest', `NETWORK_CONNECT, Original req: ${JSON.stringify(reqContext)}`);
        hilog.info(0xFF00, 'httpNormalRequest', `NETWORK_CONNECT, Original rsp: ${JSON.stringify(rspContext)}`);
    
        reqContext.url = EXAMPLE_URL;
        reqContext.header = { 'content-type': 'text/xml' };
        reqContext.body = { 'context': 'NETWORK_CONNECT' };
    
        rspContext.result = 'NETWORK_CONNECT';
        rspContext.responseCode = 300;
        rspContext.header =
          'content-encoding:br \r\n content-type:text/html\r\ncharset=UTF-8,cxy_all:+5c4ea5d1638626cbb796a7db10e0d663\r\ndate:Tue';
    
        hilog.info(0xFF00, 'httpNormalRequest', `NETWORK_CONNECT, Update req: ${JSON.stringify(reqContext)}`);
        hilog.info(0xFF00, 'httpNormalRequest', `NETWORK_CONNECT, Update rsp: ${JSON.stringify(rspContext)}`);
        return Promise.resolve(this.result);
      }
    }
    
    class FinalHttpInterceptor implements http.HttpInterceptor {
      interceptorType: http.InterceptorType = http.InterceptorType.INITIAL_REQUEST;
      result: boolean = false;
    
      constructor(interceptorType: http.InterceptorType, result: boolean) {
        this.interceptorType = interceptorType;
        this.result = result;
      }
    
      interceptorHandle(reqContext: http.HttpRequestContext, rspContext: http.HttpResponse): Promise<http.ChainContinue> {
        // Perform operations on request packets and responses after the interceptor is hit.
        hilog.info(0xFF00, 'httpNormalRequest', `FINAL_RESPONSE, Original req: ${JSON.stringify(reqContext)}`);
        hilog.info(0xFF00, 'httpNormalRequest', `FINAL_RESPONSE, Original rsp: ${JSON.stringify(rspContext)}`);
    
        reqContext.url = EXAMPLE_Final_URL;
        reqContext.header = { 'content-type': 'text/html' };
        reqContext.body = { 'context': 'FINAL_RESPONSE' };
    
        rspContext.result = 'FINAL_RESPONSE';
        rspContext.responseCode = 200;
        rspContext.header =
          'content-encoding:br \r\n content-type:text/html\r\ncharset=UTF-8,cxy_all:+5c4ea5d1638626cbb796a7db10e0d663\r\ndate:Tue';
    
        hilog.info(0xFF00, 'httpNormalRequest', `FINAL_RESPONSE, Update req: ${JSON.stringify(reqContext)}`);
        hilog.info(0xFF00, 'httpNormalRequest', `FINAL_RESPONSE, Update rsp: ${JSON.stringify(rspContext)}`);
        return Promise.resolve(this.result);
      }
    }
    ```

5.  Call [addChain()](../reference/apis-network-kit/js-apis-http.md#addchain22) to add the required interceptor instances to the interceptor chain.

    <!-- @[HTTP_interceptor_case_addChain](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_interceptor_case/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    // Create the required interceptor object and add it to the interceptor chain.
    chain.addChain([
      new InitialHttpInterceptor(http.InterceptorType.INITIAL_REQUEST, true),
      new NetworkHttpInterceptor(http.InterceptorType.NETWORK_CONNECT, true),
      new FinalHttpInterceptor(http.InterceptorType.FINAL_RESPONSE, true)
    ]);
    ```

6.  Call [apply()](../reference/apis-network-kit/js-apis-http.md#apply22) to attach the currently configured interceptor chain to the httpRequest.

    <!-- @[HTTP_interceptor_case_apply](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_interceptor_case/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    // Attach the configured interceptor chain to **httpRequest**.
    chain.apply(httpRequest);
    ```

7.  Create request options.

    <!-- @[HTTP_interceptor_case_options](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_interceptor_case/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    // Create request options.
    let options: http.HttpRequestOptions = {
      method: http.RequestMethod.POST,
      header: { 'content-type': 'text/html' } as Record<string, string>,
      extraData: { 'context': 'BODY' } as Record<string, string>,
    };
    ```

8.  Call the corresponding [request()](../reference/apis-network-kit/js-apis-http.md#request-1) method of the object, pass in the URL and optional parameters of the HTTP request, initiate the network request, and parse the server response events based on your actual service requirement.

    <!-- @[HTTP_interceptor_case_request](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_interceptor_case/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    // Initiate a request.
    httpRequest.request(EXAMPLE_URL, options, (err: BusinessError, res: http.HttpResponse) => {
      if (err) {
        hilog.error(0xFF00, 'httpNormalRequest', `request fail, error code: ${err.code}, msg: ${err.message}`);
        // ...
      } else {
        hilog.info(0xFF00, 'httpNormalRequest', `res:${JSON.stringify(res)}`);
        // ...
      }
      // ...
    });
    ```

9.  Call [destroy()](../reference/apis-network-kit/js-apis-http.md#destroy) to destroy the HTTP request.

    <!-- @[HTTP_interceptor_case_request_destroy](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_interceptor_case/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    // Destroy the request.
    httpRequest.destroy();
    ```

## 

## Samples

The following sample is provided to help you better understand how to develop the HTTP data request feature:

* [Upload and Download (ArkTS) (API10)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Connectivity/UploadAndDownLoad)

* [Http (ArkTS) (API10)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Connectivity/Http)

* [Http_case](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_case)

* [HTTP_interceptor_case](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_interceptor_case)