# 使用HTTP访问网络
<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->

## 场景介绍

应用通过HTTP发起一个数据请求，支持常见的GET、POST、OPTIONS、HEAD、PUT、DELETE、TRACE、CONNECT方法。当前提供了2种HTTP请求方式，若请求发送或接收的数据量较少，可使用[HttpRequest.request](../reference/apis-network-kit/js-apis-http.md#request)，若是大文件的上传或者下载，且关注数据发送和接收进度，可使用HTTP请求流式传输[HttpRequest.requestInStream](../reference/apis-network-kit/js-apis-http.md#requestinstream10)。从API version 22开始，若是需要在"HTTP请求-响应"生命周期中的关键节点插入自定义逻辑，可以使用[HTTP拦截器](#http拦截器)。

<!--RP1-->

<!--RP1End-->

当前HTTP请求支持的场景如下，以下功能对应的选项可以在HTTP请求的[HttpRequestOptions](../reference/apis-network-kit/js-apis-http.md#httprequestoptions)中进行设置：

| 功能分类     | 功能名称                           |功能描述                      | 开始支持的版本         |
| ----------- | -----------------------------------|-----------------------------|------------------------|
| 基础功能     | 设置请求方式                      | 支持GET、POST、HEAD、PUT、DELETE、TRACE、CONNECT、OPTIONS方法，默认为GET。  |  API version 6  |
| 基础功能     | 设置请求额外数据                 | 支持发送请求时同步携带额外数据，默认无此字段。 | API version 6    |
| 基础功能     | 设置读取超时时间                 | 该参数设置的是从请求开始到请求结束的总时间，包括DNS解析、连接建立、传输等。单位为毫秒（ms），默认为60000ms。 |  API version 6   |
| 基础功能     | 设置连接超时时间                 | 该参数设置的是连接超时时间。单位为毫秒（ms），默认为60000ms。 |  API version 6   |
| 基础功能     | 设置HTTP请求头                  | 当请求方式为"POST" "PUT" "DELETE" 或者""时，默认{'content-Type': 'application/json'}， 否则默认{'content-Type': 'application/x-www-form-urlencoded'}。 |  API version 6   |
| 基础功能     | 设置响应数据类型                | 可以指定HTTP响应数据的类型，默认无此字段。如果设置了此参数，系统将优先返回指定的类型。 |  API version 9   |
| 基础功能     | 设置请求并发优先级              |  指定HTTP/HTTPS请求并发优先级，值越大优先级越高，范围[1,1000]，默认为1。|  API version 9   |
| 基础功能     | 设置是否使用缓存                | 可以指定是否使用缓存，默认为true，请求时优先读取缓存。 缓存跟随当前进程生效。新缓存会替换旧缓存，设置为false表示不使用缓存。 |  API version 9   |
| 基础功能     | 设置使用协议类型                 | HTTPS的请求默认是HTTP/2，失败回退HTTP/1.1；HTTP直接用HTTP/1.1。用户可以指定为HTTP 1.1、HTTP 2、HTTP 3协议版本。 |  API version 9   |
| 代理设置     | 设置HTTP请求代理                 | 设置HTTP代理，默认值为false，表示不使用代理，若设置为true，表示使用HTTP代理，且为系统默认代理，也可通过配置HttpProxy自定义网络代理。 |  API version 10  |
| 证书验证     | 设置CA证书路径                   | 如果设置了此参数，系统将使用用户指定路径的CA证书（开发者需保证该路径下CA证书的可访问性），否则将使用系统预设CA证书。 | API version 10    |
| 证书验证     | 设置支持传输客户端证书            | 支持传输客户端证书，包括证书路径、证书类型、证书密钥路径和密码信息。 | API version 11    |
| 基础功能     | 设置下载起始位置和结束位置         | 指定客户端要获取的数据范围，通常在下载文件时配置该参数。 |  API version 11  |
| 基础功能     | 设置需要上传的数据字段表单列表        |设置多部分表单数据，通常用于上传文件。 |  API version 11   |
| DNS设置      | 设置使用HTTPS协议的服务器进行DNS解析  | 设置使用HTTPS协议的服务器进行DNS解析。参数必须根据以下格式进行URL编码:'https://host:port/path'。 | API version 11    |
| DNS设置     | 设置指定的DNS服务器进行DNS解析         | 设置指定的DNS服务器进行DNS解析。可以设置多个DNS解析服务器，最多3个服务器。如果有3个以上，只取前3个。服务器必须是IPV4或者IPV6地址形式。 |  API version 11   |
| 基础功能     | 设置响应消息的最大字节限制            | 响应消息的最大字节限制。以字节为单位，默认值为5\*1024\*1024，最大值为100\*1024\*1024。 |   API version 11  |
| 证书验证     | 设置动态设置证书锁定配置             | 动态设置证书锁定配置，可以传入单个或多个证书PIN码。 |   API version 12  |
| 证书验证     | 设置解析目标域名时限定地址类型        | 指定在解析目标域名时的地址类型，可以设置为：跟随系统网络配置、强制仅使用IPV4地址或者强制仅使用IPV6地址。 |  API version 15   |
| 证书验证     | 设置跳过SSL证书校验                     | 可以设置跳过SSL证书校验流程。 | API version 18    |
| 证书验证     | 设置证书校验的版本和加密套件             | 自定义证书校验版本和加密套件。 |  API version 18  |
| 证书验证     | 设置安全连接期间的服务器身份验证配置信息        | 设置安全连接期间的服务器身份验证配置。 |  API version 18   |
| 代理设置     | 设置SOCKS5代理        | 设置SOCKS5代理，默认不使用SOCKS5代理，若正确配置了[Socks5Proxy](../reference/apis-network-kit/js-apis-net-connection.md#socks5proxy)自定义SOCKS5代理，则HttpProxy不生效。 |  API version 26.0.0   |

## 发起HTTP数据请求

> **说明：**
>
> 在本文档的示例中，通过this.context来获取UIAbilityContext，其中this代表继承自UIAbility的UIAbility实例。如需在页面中使用UIAbilityContext提供的能力，请参见[获取UIAbility的上下文信息](../application-models/uiability-usage.md#获取uiability的上下文信息)。

完整示例代码见：[Http_case](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_case)

1. 导入HTTP一般数据请求所需模块

   <!-- @[HTTP_case_module_import_data_request](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_case/entry/src/main/ets/pages/Index.ets) -->  
   
   ``` TypeScript
   import { http } from '@kit.NetworkKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   ```

2. 创建HttpRequest对象

    调用[createHttp()](../reference/apis-network-kit/js-apis-http.md#httpcreatehttp)方法，创建HttpRequest对象。

    <!-- @[HTTP_case_create_http_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_case/entry/src/main/ets/pages/Index.ets) -->
    
    ``` TypeScript
    let context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;
    // 每一个httpRequest对应一个HTTP请求任务，不可复用。
    let httpRequest = http.createHttp();
    ```

3. 订阅HTTP响应头事件

    调用该对象的[on()](../reference/apis-network-kit/js-apis-http.md#onheadersreceive8)方法，订阅HTTP响应头事件，此接口会比request请求先返回。可以根据业务需要订阅此消息。

   <!-- @[HTTP_case_http_request_on_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_case/entry/src/main/ets/pages/Index.ets) -->
   
   ``` TypeScript
   // 用于订阅HTTP响应头，此接口会比request请求先返回。可以根据业务需要订阅此消息。
   // 从API 8开始，使用on('headersReceive', Callback)替代on('headerReceive', AsyncCallback)。
   httpRequest.on('headersReceive', (header) => {
    hilog.info(0x0000, 'testTag', `header: ${JSON.stringify(header)}`);
   });
   ```


4. 发起HTTP请求，解析服务器响应事件

    调用该对象的[request()](../reference/apis-network-kit/js-apis-http.md#httprequest)方法，传入HTTP请求的url地址和可选参数，发起网络请求，按照实际业务需要，解析返回结果。

   <!-- @[HTTP_case_http_request_request_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_case/entry/src/main/ets/pages/Index.ets) -->
   
   ``` TypeScript
   httpRequest.request(
     // 填写HTTP请求的URL地址，可以带参数也可以不带参数。URL地址需要开发者自定义。请求的参数可以在extraData中指定
     'EXAMPLE_URL',
     {
       method: http.RequestMethod.POST, // 可选，默认为http.RequestMethod.GET，用于从服务器获取数据，而POST方法用于向服务器上传数据。
       // 开发者根据自身业务需要添加header字段
       header: {
         'Content-Type': 'application/json'
       },
       // 当使用POST请求时此字段用于传递请求体内容，具体格式与服务端协商确定
       extraData: 'data to send',
       expectDataType: http.HttpDataType.STRING, // 可选，指定返回数据的类型
       usingCache: true, // 可选，默认为true
       priority: 1, // 可选，默认为1
       connectTimeout: 60000, // 可选，默认为60000ms
       readTimeout: 60000, // 可选，默认为60000ms
       usingProtocol: http.HttpProtocol.HTTP1_1, // 可选，协议类型默认值由系统自动指定
       usingProxy: false, // 可选，默认不使用网络代理，自API 10开始支持该属性
       caPath:'/path/to/cacert.pem', // 可选，默认使用系统预制证书，自API 10开始支持该属性
       clientCert: { // 可选，默认不使用客户端证书，自API 11开始支持该属性
         certPath: '/path/to/client.pem', // 默认不使用客户端证书，自API 11开始支持该属性
         keyPath: '/path/to/client.key', // 若证书包含Key信息，传入空字符串，自API 11开始支持该属性
         certType: http.CertType.PEM, // 可选，默认使用PEM，自API 11开始支持该属性
         keyPassword: 'passwordToKey' // 可选，输入key文件的密码，自API 11开始支持该属性
       },
       // 可选，仅当Header中，'content-Type'为'multipart/form-data'时生效,自API 11开始支持该属性
       // 该属性用于支持向服务器上传二进制数据，根据上传的具体数据类型进行选择。
       multiFormDataList: [
         {
           name: 'Part1', // 数据名，自API 11开始支持该属性
           contentType: 'text/plain', // 数据类型，自API 11开始支持该属性，上传的数据类型为普通文本文件。
           data: 'Example data', // 可选，数据内容，自API 11开始支持该属性
           remoteFileName: 'example.txt' // 可选，自API 11开始支持该属性
         }, {
         name: 'Part2', // 数据名，自API 11开始支持该属性
         contentType: 'text/plain', // 数据类型，自API 11开始支持该属性，上传的数据类型为普通文本文件。
         // data/app/el2/100/base/com.example.myapplication/haps/entry/files/fileName.txt
         filePath: `${context.filesDir}/fileName.txt`, // 可选，传入文件路径，自API 11开始支持该属性
         remoteFileName: 'fileName.txt' // 可选，自API 11开始支持该属性
         }, {
           name: 'Part3', // 数据名，自API 11开始支持该属性。
           contentType: 'image/png', // 数据类型，自API 11开始支持该属性，上传的数据类型为png格式的图片。
           // data/app/el2/100/base/com.example.myapplication/haps/entry/files/fileName.png。
           filePath: `${context.filesDir}/fileName.png`, // 可选，传入文件路径，自API 11开始支持该属性。
           remoteFileName: 'fileName.png' // 可选，自API 11开始支持该属性。
         }, {
           name: 'Part4', // 数据名，自API 11开始支持该属性。
           contentType: 'audio/mpeg', // 数据类型，自API 11开始支持该属性，上传的数据类型为mpeg格式的音频。
           // data/app/el2/100/base/com.example.myapplication/haps/entry/files/fileName.mpeg。
           filePath: `${context.filesDir}/fileName.mpeg`, // 可选，传入文件路径，自API 11开始支持该属性。
           remoteFileName: 'fileName.mpeg' // 可选，自API 11开始支持该属性。
         }, {
           name: 'Part5', // 数据名，自API 11开始支持该属性。
           contentType: 'video/mp4', // 数据类型，自API 11开始支持该属性，上传的数据类型为mp4格式的视频。
           // data/app/el2/100/base/com.example.myapplication/haps/entry/files/fileName.mp4。
           filePath: `${context.filesDir}/fileName.mp4`, // 可选，传入文件路径，自API 11开始支持该属性。
           remoteFileName: 'fileName.mp4' // 可选，自API 11开始支持该属性。
         }
       ]
     }, (err: BusinessError, data: http.HttpResponse) => {
     if (!err) {
       // ...
       // data.result为HTTP响应内容，可根据业务需要进行解析。
       hilog.info(0x0000, 'testTag', `Result: ${JSON.stringify(data.result)}`);
       hilog.info(0x0000, 'testTag', `code: ${JSON.stringify(data.responseCode)}`);
       // data.header为HTTP响应头，可根据业务需要进行解析。
       hilog.info(0x0000, 'testTag', `header: ${JSON.stringify(data.header)}`);
       hilog.info(0x0000, 'testTag', `cookies: ${JSON.stringify(data.cookies)}`);
       // 当该请求使用完毕时，调用destroy方法主动销毁。
       httpRequest.destroy();
     } else {
       // ...
       hilog.error(0x0000, 'testTag', `error: ${JSON.stringify(err)}`);
       // 取消订阅HTTP响应头事件
       httpRequest.off('headersReceive');
       // 当该请求使用完毕时，调用destroy方法主动销毁
       httpRequest.destroy();
     }
   }
   );
   ```


5. 取消订阅HTTP响应头事件

    调用该对象的[off()](../reference/apis-network-kit/js-apis-http.md#offheadersreceive8)方法，取消订阅HTTP响应头事件。

    ```ts
    // 在不需要该回调信息时，需要取消订阅HTTP响应头事件，该方法调用的时机，可以参考步骤4中的示例代码。
    httpRequest.off('headersReceive');
    ```
6. 调用destroy()方法销毁

    当该请求使用完毕时，调用[destroy()](../reference/apis-network-kit/js-apis-http.md#destroy)方法销毁。

    ```ts
    // 当该请求使用完毕时，调用destroy方法主动销毁，该方法调用的时机，可以参考步骤4中的示例代码。
    httpRequest.destroy();
    ```
## 发起HTTP流式传输请求

HTTP流式传输是指在处理HTTP响应时，可以一次只处理响应内容的一小部分，而不是一次性将整个响应加载到内存，这对于处理大文件、实时数据流等场景非常有用。

完整示例代码见：[Http_case](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_case)

1. 导入HTTP流式传输所需模块

     <!-- @[HTTP_case_module_import_data_request](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_case/entry/src/main/ets/pages/Index.ets) -->
     
     ``` TypeScript
     import { http } from '@kit.NetworkKit';
     import { BusinessError } from '@kit.BasicServicesKit';
     import { common } from '@kit.AbilityKit';
     import { hilog } from '@kit.PerformanceAnalysisKit';
     ```

2. 创建HTTP流式传输HttpRequest对象

    调用[createHttp()](../reference/apis-network-kit/js-apis-http.md#httpcreatehttp)方法，创建HttpRequest对象。

    <!-- @[request_in_stream_create_http_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_case/entry/src/main/ets/pages/Index.ets) -->
    
    ``` TypeScript
    // 每一个httpRequest对应一个HTTP请求任务，不可复用。
    let httpRequest = http.createHttp();
    ```

3. 按需订阅HTTP流式响应事件

   服务器响应的数据在dataReceive回调中返回，可通过订阅该信息获取服务器响应的数据，其他流式响应事件可按需进行订阅。
  
   <!-- @[request_in_stream_data_receive](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_case/entry/src/main/ets/pages/Index.ets) -->
   
   ``` TypeScript
   // 用于订阅HTTP流式响应数据接收事件。
   let res = new ArrayBuffer(0);
   // ...
   // 订阅HTTP流式响应数据接收事件
   httpRequest.on('dataReceive', (data: ArrayBuffer) => {
     const newRes = new ArrayBuffer(res.byteLength + data.byteLength);
     const resView = new Uint8Array(newRes);
     resView.set(new Uint8Array(res));
     resView.set(new Uint8Array(data), res.byteLength);
     res = newRes;
     hilog.info(0x0000, 'testTag', `res length: ${res.byteLength}`);
   });
   
   // 用于订阅HTTP流式响应数据接收完毕事件。
   httpRequest.on('dataEnd', () => {
     hilog.info(0x0000, 'testTag', `No more data in response, data receive end`);
   });
   
   // 订阅HTTP流式响应数据接收进度事件，下载服务器的数据时，可以通过该回调获取数据下载进度。
   httpRequest.on('dataReceiveProgress', (data: http.DataReceiveProgressInfo) => {
     hilog.info(0x0000, 'testTag', 'dataReceiveProgress receiveSize:' + data.receiveSize + ', totalSize:' + data.totalSize);
   });
   
   // 订阅HTTP流式响应数据发送进度事件，向服务器上传数据时，可以通过该回调获取数据上传进度。
   httpRequest.on('dataSendProgress', (data: http.DataSendProgressInfo) => {
     hilog.info(0x0000, 'testTag', 'dataSendProgress receiveSize:' + data.sendSize + ', totalSize:' + data.totalSize);
   });
   ```

4. 发起HTTP流式请求，获取服务端数据

   <!-- @[request_in_stream_get_server_data](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_case/entry/src/main/ets/pages/Index.ets) -->
   
   ``` TypeScript
   let streamInfo: http.HttpRequestOptions = {
     method: http.RequestMethod.POST, // 可选，默认为http.RequestMethod.GET，用于向服务器获取数据，而POST方法用于向服务器上传数据。
     // 开发者根据自身业务需要添加header字段。
     header: {
       'Content-Type': 'application/json'
     },
     // 当使用POST请求时此字段用于传递请求体内容，具体格式与服务端协商确定。
     extraData: 'data to send', // 请求体内容
     expectDataType: http.HttpDataType.STRING, // 可选，指定返回数据的类型。
     usingCache: true,  // 可选，默认为true。
     priority: 1, // 可选，默认为1。
     connectTimeout: 60000, // 可选，默认为60000ms。
     readTimeout: 60000, // 可选，默认为60000ms。若传输的数据较大，需要较长的时间，建议增大该参数以保证数据传输正常终止。
     usingProtocol: http.HttpProtocol.HTTP1_1 // 可选，协议类型默认值由系统自动指定。
   };
   
   // 填写HTTP请求的URL地址，可以带参数也可以不带参数。URL地址需要开发者自定义。请求的参数可以在extraData中指定。
   httpRequest.requestInStream('EXAMPLE_URL', streamInfo)
     .then((data: number) => {
       // ...
       hilog.info(0x0000, 'testTag', `requestInStream OK!`);
       hilog.info(0x0000, 'testTag', `ResponseCode : ${JSON.stringify(data)}`);
       // 取消订阅步骤3中订阅的事件，并调用destroy方法主动销毁。
       this.destroyRequest(httpRequest);
       // ...
     }).catch((err: Error) => {
       // ...
       hilog.error(0x0000, 'testTag', `requestInStream ERROR : err = ${JSON.stringify(err)}`);
       // 取消订阅步骤3中订阅的事件，并调用destroy方法主动销毁。
       this.destroyRequest(httpRequest);
     })
   ```


5. 取消步骤3中订阅HTTP流式响应事件，并调用destroy()方法销毁流式HTTP请求

    调用该对象的[off()](../reference/apis-network-kit/js-apis-http.md#offdatareceive10)方法，取消订阅步骤3中的事件，并且当该请求使用完毕时，调用[destroy()](../reference/apis-network-kit/js-apis-http.md#destroy)方法销毁，该方法调用的时机，可以参考步骤4中的示例代码。

   <!-- @[request_in_stream_destroy_request_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_case/entry/src/main/ets/pages/Index.ets) -->
   
   ``` TypeScript
   public destroyRequest(httpRequest: http.HttpRequest) {
     // 取消订阅HTTP流式响应数据接收事件。
     httpRequest.off('dataReceive');
     // 取消订阅HTTP流式响应数据发送进度事件。
     httpRequest.off('dataSendProgress');
     // 取消订阅HTTP流式响应数据接收进度事件。
     httpRequest.off('dataReceiveProgress');
     // 取消订阅HTTP流式响应数据接收完毕事件。
     httpRequest.off('dataEnd');
     // 当该请求使用完毕时，调用destroy方法主动销毁。
     httpRequest.destroy();
   }
   ```
## 通过HTTP发起WebDAV请求

从API version 23开始，HTTP请求支持WebDAV协议的文件访问，WebDAV是基于HTTP协议的扩展，支持对远程服务器上的文件进行创建、读取、更新、删除、移动、复制(MKCOL、GET、PUT、DELETE、MOVE、COPY)等操作。

完整示例代码见：[Http_case](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_case)

<!-- @[HTTP_webDav](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_case/entry/src/main/ets/pages/WebDav.ets) -->

``` TypeScript
import { http } from '@kit.NetworkKit';
import { ComponentId } from '../common/CommonConstant';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@Component
struct Index {
  proppatchXml = `example_proppatchXml`; // 修改资源Xml
  lockXml: string = `example_lockXml`; // 加锁Xml
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
              extraData: file, // 上传文件内容
              header: { 'Content-Type': 'text/plain; charset=utf-8', 'Content-Length': file.length.toString() },
              customMethod: 'PUT' // WebDav协议PUT请求方式
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
              customMethod: 'GET' // WebDav协议GET请求方式
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
              customMethod: 'MKCOL' // WebDav协议MKCOL请求方式
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
              customMethod: 'DELETE' // WebDav协议DELETE请求方式
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
              customMethod: 'COPY' // WebDav协议COPY请求方式
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
              customMethod: 'MOVE' // WebDav协议MOVE请求方式
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
              customMethod: 'PROPPATCH' // WebDav协议PROPPATCH请求方式
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
              customMethod: 'PROPFIND' // WebDav协议PROPFIND请求方式
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
              customMethod: 'LOCK' // WebDav协议LOCK请求方式
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
                'Lock-Token': this.lockToken, // 加锁时返回密钥
                'Depth': '0'
              },
              customMethod: 'UNLOCK' // WebDav协议UNLOCK请求方式
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
              customMethod: 'UNKNOWN' // 非WebDav协议请求方式
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
## 配置证书校验

当应用使用HTTPS协议时，涉及证书相关配置。面向互联网用户提供服务的应用仅需信任系统预置的CA证书。当前HTTP模块已默认信任系统预置的CA证书，无需特别设置。如果应用需要锁定证书，只信任开发者特别指定的证书，或者需要跳过证书校验，可以参考以下说明进行配置。

### TLS客户端证书验证流程

   在TLS握手过程中，客户端验证服务端证书以确保连接可信。服务端证书通常包括域名证书和中间CA证书。

 **证书链组成**
 
   证书链采用层级信任结构：`服务端证书 ← 中间CA证书 ← 根CA证书`。其中←表示签发与信任关系，证书链必须完整追溯到可信根证书。

**验证流程**

   客户端接收证书链后执行三级验证：

1. 证书链完整性验证
   - 从服务端证书开始逐级验证数字签名，确保每一级证书均由上一级有效签发，以形成完整的信任链条。

2. 根证书可信性验证
   - 在证书存储库中查找根证书是否存在。
   - 存储库来源包括：
     - 系统预置证书。
     - 应用信任证书。
     - 本次请求指定的CA证书。
   - 可通过相关API(请参考下方：**配置参考**)指定应用级和请求级信任证书。

3. 证书内容有效性验证
   - 证书有效期检查。
   - 域名匹配验证：主题备用名称(Subject Alternative Name, SAN)、通用名称(Common Name, CN)与访问域名一致。
   - 证书吊销状态检查：证书吊销列表(Certificate Revocation List, CRL)、在线证书状态协议(Online Certificate Status Protocol, OCSP)。

 验证结果
 
   - 验证成功：继续TLS握手建立安全连接。
   - 验证失败：终止连接并提示错误信息。

此流程确保只有持有有效且可信证书的服务端才能建立安全连接。

 **配置参考**
 
1. 配置应用信任证书（具体配置方法可参考[网络连接安全配置](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-network-ca-security#section5454123841911)）。
2. 配置请求级CA证书：
   - 通过[httprequestoptions](../reference/apis-network-kit/js-apis-http.md#httprequestoptions)的caPath和caData字段配置HTTPS请求CA证书。
   - 通过[websocketrequestoptions](../reference/apis-network-kit/js-apis-webSocket.md#websocketrequestoptions)的caPath字段配置WebSocket请求CA证书。
   - 通过[tlssecureoptions](../reference/apis-network-kit/js-apis-socket.md#tlssecureoptions9)的ca字段指定TLS请求CA证书。
3. 配置跳过证书校验：
   - HTTPS：通过[remoteValidation](../reference/apis-network-kit/js-apis-http.md#remotevalidation18) = 'skip' 配置。
   - WebSocket：通过[websocketrequestoptions](../reference/apis-network-kit/js-apis-webSocket.md#websocketrequestoptions)的skipServerCertVerification = true 配置。
   - TLSSocket：通过[tlsconnectoptions](../reference/apis-network-kit/js-apis-socket.md#tlsconnectoptions9)的skipRemoteValidation = true 配置。

 **调试参考**
 
   - 通过API校验指定证书是否可信：可参考[networkSecurity.certVerification](../reference/apis-network-kit/js-apis-networkSecurity.md#networksecuritycertverification)。
   - 通过openssl命令校验域名服务器证书链是否被系统信任：`hdc shell openssl s_client -connect 主机名:端口 -CApath /etc/security/certificates -brief`。若出现`Verification: OK`说明证书链可信。将`-brief`替换为`-trace -showcerts`可以打印详细的TLS握手信息。


### 证书锁定

可以通过预置应用级证书，或者预置证书公钥哈希值的方式来进行证书锁定，即只有开发者特别指定的证书才能正常建立HTTPS连接。

两种方式都是在配置文件中配置的，配置文件在APP中的路径是：`src/main/resources/base/profile/network_config.json`。在该配置中，可以为预置的证书与网络服务器建立对应关系。

如果不知道服务器域名的证书，可以通过以下方式访问该域名获取证书，注意把`www.example.com`改成想要获取域名证书的域名，`www.example.com.pem`改成想保存的证书文件名：

```ts
openssl s_client -servername www.example.com -connect www.example.com:443 \
    < /dev/null | sed -n "/-----BEGIN/,/-----END/p" > www.example.com.pem
```

如果你的环境是Windows系统，需要注意：

* 将`/dev/null`替换成`NUL`。
* 和Linux的OpenSSL表现可能不同，OpenSSL可能会等待用户输入才会退出，按Enter键即可。
* 如果没有sed命令，将输出中从`-----BEGIN CERTIFICATE-----`到`-----END CERTIFICATE-----`之间的部分复制下来保存即可（复制部分包括这两行）。

**预置应用级证书**

直接把证书原文件预置在APP中。目前支持crt和pem格式的证书文件。

> **注意：**
>
> 当前ohos.net.http和Image组件的证书锁定，会匹配证书链上所有证书的哈希值，如果服务器更新了任意一本证书，都会导致校验失败。如果服务器出现了更新证书的情况，APP版本应当随之更新并推荐消费者尽快升级APP版本，否则可能导致联网失败。

**预置证书公钥哈希值**

通过在配置中指定域名证书公钥的哈希值，只允许使用公钥哈希值匹配的域名证书访问此域名。

域名证书的公钥哈希值可以用如下的命令计算。假设域名证书是通过上面的OpenSSL命令获得的，并保存在`www.example.com.pem`文件。#开头的行是注释，可以不用输入：

```ts
# 从证书中提取出公钥
openssl x509 -in www.example.com.pem -pubkey -noout > www.example.com.pubkey.pem
# 将pem格式的公钥转换成der格式
openssl asn1parse -noout -inform pem -in www.example.com.pubkey.pem -out www.example.com.pubkey.der
# 计算公钥的SHA256并转换成base64编码
openssl dgst -sha256 -binary www.example.com.pubkey.der | openssl base64
```

**JSON配置文件示例**

预置应用级证书的配置例子如下（具体配置路径可参考[网络连接安全配置](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-network-ca-security#section5454123841911)）：

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

预置证书公钥哈希值的配置例子如下：

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

证书锁定的配置例子如下:

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

**各个字段含义:**

| 字段                      | 类型            | 说明                                   |
| --------------------------| --------------- | -------------------------------------- |
|network-security-config    | object          |网络安全配置。可包含0或者1个base-config，必须包含1个domain-config。|
|base-config                | object          |指示应用程序范围的安全配置。必须包含1个trust-anchors。                          |
|domain-config              | array           |指示每个域的安全配置。可以包含任意个item。item必须包含1个domains，可以包含0或者1个trust-anchors，可以包含0个或者1个pin-set。|
|trust-anchors              | array           |受信任的CA。可以包含任意个item。item必须包含1个certificates。|
|certificates               | string          |CA证书路径。 |
|domains                    | array           |域。可以包含任意个item。item必须包含1个name(string：指示域名)，可以包含0或者1个include-subdomains。|
|include-subdomains         | boolean         |指示规则是否适用于子域。true：表示规则适用于该域名及其所有子域名；false：表示规则仅适用于该域名。默认为true。 |
|pin-set                    | object          |证书公钥哈希设置。必须包含1个pin，可以包含0或者1个expiration。|
|expiration                 | string          |指示证书公钥哈希的过期时间。 |
|pin                        | array           |证书公钥哈希。可以包含任意个item。item必须包含1个digest-algorithm，item必须包含1个digest。|
|digest-algorithm           | string          |指示用于生成哈希的摘要算法。目前只支持`sha256`。                                    |
|digest                     | string          |指示公钥哈希。 |

### 配置不信任用户安装的CA证书

系统默认信任系统预置的CA证书和用户安装的CA证书，可配置不信任用户安装的CA证书提升安全性。配置不信任用户安装的CA证书可以在src/main/resources/base/profile/network_config.json进行配置，更多网络连接安全相关的配置可以参考[网络连接安全配置](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-network-ca-security#section5454123841911)。

```json5
{
  "network-security-config": {
    // 其他网络安全配置
  },
  "trust-global-user-ca": false, // 配置是否信任企业MDM系统或设备管理员用户手动安装的CA证书，默认为true
  "trust-current-user-ca" : false // 配置是否信任当前用户安装的CA证书，默认为true
}
```
### 明文HTTP访问权限配置说明

该配置用于控制HTTP请求是否允许以明文形式传输。以下为明文HTTP访问权限的配置示例（含应用、组件及域名级配置），以及各字段的详细含义说明。更多网络连接安全相关的配置可以参考[网络连接安全配置](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-network-ca-security#section5454123841911)。
> **说明：**
>
> 配置优先级规则：组件配置（component-config）> 域名配置（domain-config）> 基础配置（base-config），优先级高的配置会覆盖优先级低的规则。


``` json5
// src/main/resources/base/profile/network_config.json
{
  "network-security-config": {
    "base-config": {
      "cleartextTrafficPermitted": true // 可选，自API version 18开始支持该属性。
    },
    "domain-config": [
      {
        "domains": [
          {
            "include-subdomains": true,
            "name": "example.com"
          }
        ],
        "cleartextTrafficPermitted": false // 可选，自API version 18开始支持该属性。
      }
    ],
    "component-config": {
        "Request": true, // 可选，自API version 20开始支持配置该属性，默认值为true。配置为true表示开启明文HTTP功能，配置为false表示关闭明文HTTP功能。
        "Network Kit": true, // 可选，自API version 20开始支持配置该属性。
        "ArkWeb": false, // 可选，自API version 20开始支持配置该属性。
        "Media Kit": false, // 可选，自API version 23开始支持配置该属性。
        "Remote Communication Kit": false // 可选，自API version 23开始支持配置该属性。
    }
  }
}
```

**各个字段含义:**

| 字段                      | 类型            | 必填 | 说明                                   |
| --------------------------| --------------- |--------- |-------------------------------------- |
|base-config                     | object          | 否| 指示应用程序范围的明文配置。优先级最低。 |
|cleartextTrafficPermitted<sup>18+</sup>  | boolean          |否 | 明文HTTP是否允许。true表示允许，false表示不允许，默认为true。 |
|domain-config                     | array          | 否|  指示每个域的明文配置。可以包含任意个item。每个item必须包含1个domains。若相同域存在规则冲突时，以匹配到的第一条为准。优先级次于component-config。 |
|include-subdomains         | boolean         | 否| 指示规则是否适用于子域。true表示适用于子域，false表示不适用于子域。默认为true。注意：每增加1000条域名配置，正则匹配的延迟将增加大约10至15毫秒。当域名配置数量超过10000条时，正则匹配会带来较高耗时。默认为true。 |
|name         | string         | 否| 配置主域名。 |
|component-config<sup>20+</sup>                    | object         |  否| 指示每个组件的明文配置。优先级最高。|
|Request                    | boolean          |否| [Request](../reference/apis-basic-services-kit/js-apis-request.md)从API version 18开始默认支持明文HTTP功能，不可配置。从API version 20开始支持配置开启或关闭明文HTTP功能。true表示配置开启，false表示配置关闭，默认为true。|
|Network Kit                 | boolean          |否| Network Kit从API version 18开始默认支持明文HTTP功能，不可配置。从API version 20开始支持配置开启或关闭明文HTTP功能。true表示配置开启，false表示配置关闭，默认为true。 |
|ArkWeb                    | boolean          |否| ArkWeb从API version 20开始支持配置开启或关闭明文HTTP功能。true表示配置开启，false表示配置关闭，默认为false。 |
|Media Kit                    | boolean          |否| Media Kit从API version 23开始支持配置开启或关闭明文HTTP功能。true表示配置开启，false表示配置关闭，默认为false。 |
|Remote Communication Kit                    | boolean          |否| Remote Communication Kit从API version 23开始支持配置开启或关闭明文HTTP功能。true表示配置开启，false表示配置关闭，默认为false。 |

## HTTP拦截器

从API version 22开始，HTTP拦截器模块提供了一种强大且可定制的机制，允许开发者在"HTTP请求-响应"生命周期中的关键节点插入自定义逻辑。通过拦截器，开发者可以无需修改核心网络代码即可实现修改请求头/体、缓存策略、重定向处理、网络监控、响应预处理等全局功能。

### 拦截点说明

| 拦截点名称                        | 位置说明                                                     | 拦截点interceptorHandle接口的出参和入参                                                   |
| :-------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 初始请求拦截点（INITIAL_REQUEST）   | 初始请求组装完成后，这是第一个拦截点，适合用于添加全局参数、签名、加密请求体。 | 当出参为true时，此时入参中的request值为原始值，可以修改，response值为空值，修改无效。<br />当出参为false时，此时入参中的request值为原始值，修改无效，response值为空值，可以修改。 |
| 网络连接拦截点（NETWORK_CONNECT） | 在网络连接建立之前，例如TCP/TLS连接。适合进行网络链路相关的操作，如记录网络连接开始时间。 | 当出参为true时，此时入参中的request值为原始值，可以修改，response值为空值，修改无效。<br />当出参为false时，此时入参中的request值为原始值，修改无效，response值为空值，可以修改。 |
| 缓存拦截点（CACHE_CHECKED）       | 缓存检查逻辑命中缓存之后，已确认存在可用缓存。适用于查看缓存值或者修改查询到的缓存结果。 | 当出参为true时，此时入参中的request值为原始值，修改无效，response值为原始值，修改无效。<br />当出参为false时，此时入参中的request值为原始值，修改无效，response值为原始值，可以修改。 |
| 重定向拦截点（REDIRECTION）       | 收到重定向响应并准备发送新请求之前。允许修改重定向的目标URL或请求信息。 | 当出参为true时，此时入参中的request值为原始值，可以修改URL，response值为原始值，修改无效。<br />当出参为false时，此时入参中的request值为原始值，修改无效，response值为原始值，可以修改。 |
| 最终响应拦截点（FINAL_RESPONSE）    | 获得最终响应之后。最后一个拦截点，适合对响应进行统一解密、解析、日志记录、错误处理。 | 当出参为true时，此时入参中的request值为原始值，修改无效，response值为原始值，修改无效。<br />当出参为false时，此时入参中的request值为原始值，修改无效，response值为原始值，可以修改。 |

**顺序执行**：拦截器严格按照INITIAL_REQUEST->CACHE_CHECKED->NETWORK_CONNECT->(REDIRECTION)->FINAL_RESPONSE的顺序被触发调用。（括号中表示如果请求涉及重定向，则会走重定向拦截器）

**重定向循环**：这是流程中最关键的一个循环。当REDIRECTION拦截器被触发后，流程会跳回到NETWORK_CONNECT阶段，重新开始一个新的“请求周期”，直到不再发生重定向为止。这确保了重定向后的新请求也能被所有必要的拦截器（如认证头添加、日志记录等）正确处理。

**缓存拦截**：CACHE_CHECKED是一个决策点。如果缓存存在且有效，请求会在此处经过CACHE_CHECKED处理后，直接跳转到FINAL_RESPONSE阶段返回缓存数据，从而避免不必要的网络操作。

### HTTP拦截器开发步骤

1.  导入HTTP请求拦截器所需模块。

    <!-- @[HTTP_interceptor_case_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_interceptor_case/entry/src/main/ets/pages/Index.ets) -->  
    
    ``` TypeScript
    import { http } from '@kit.NetworkKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    ```

2.  调用[createHttp()](../reference/apis-network-kit/js-apis-http.md#httpcreatehttp)方法，创建HttpRequest对象。

     <!-- @[HTTP_interceptor_case_creat_request](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_interceptor_case/entry/src/main/ets/pages/Index.ets) -->
     
     ``` TypeScript
     // 创建http请求
     let httpRequest: http.HttpRequest = http.createHttp();
     ```

3.  调用[HttpInterceptorChain()](../reference/apis-network-kit/js-apis-http.md#httpinterceptorchain22)方法，创建拦截器链对象。

    <!-- @[HTTP_interceptor_case_chain](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_interceptor_case/entry/src/main/ets/pages/Index.ets) -->
    
    ``` TypeScript
    // 创建拦截器链
    let chain: http.HttpInterceptorChain = new http.HttpInterceptorChain();
    ```

4.  创建拦截器类实现http.HttpInterceptor接口。

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
        // 命中拦截器后对请求报文与请求响应操作
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
        // 命中拦截器后对请求报文与请求响应操作
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
        // 命中拦截器后对请求报文与请求响应操作
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

5.  调用[addChain()](../reference/apis-network-kit/js-apis-http.md#addchain22)方法，将需要的拦截器实例加入到拦截器链中。

    <!-- @[HTTP_interceptor_case_addChain](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_interceptor_case/entry/src/main/ets/pages/Index.ets) -->
    
    ``` TypeScript
    // 创建所需要的拦截器对象,将拦截器对象加入拦截器链中
    chain.addChain([
      new InitialHttpInterceptor(http.InterceptorType.INITIAL_REQUEST, true),
      new NetworkHttpInterceptor(http.InterceptorType.NETWORK_CONNECT, true),
      new FinalHttpInterceptor(http.InterceptorType.FINAL_RESPONSE, true)
    ]);
    ```

6.  调用[apply()](../reference/apis-network-kit/js-apis-http.md#apply22)方法，将当前配置好的拦截器链附加到httpRequest中。

    <!-- @[HTTP_interceptor_case_apply](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_interceptor_case/entry/src/main/ets/pages/Index.ets) -->
    
    ``` TypeScript
    // 将当前配置好的拦截器链附加到httpRequest中
    chain.apply(httpRequest);
    ```

7.  创建请求可选项。

    <!-- @[HTTP_interceptor_case_options](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_interceptor_case/entry/src/main/ets/pages/Index.ets) -->
    
    ``` TypeScript
    // 创建请求可选项
    let options: http.HttpRequestOptions = {
      method: http.RequestMethod.POST,
      header: { 'content-type': 'text/html' } as Record<string, string>,
      extraData: { 'context': 'BODY' } as Record<string, string>,
    };
    ```

8.  调用该对象的[request()](../reference/apis-network-kit/js-apis-http.md#request-1)方法，传入HTTP请求的URL地址和可选参数，发起网络请求，按照实际业务需要，解析服务器响应事件。

    <!-- @[HTTP_interceptor_case_request](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_interceptor_case/entry/src/main/ets/pages/Index.ets) -->
    
    ``` TypeScript
    // 发起请求
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

9.  调用[destroy()](../reference/apis-network-kit/js-apis-http.md#destroy)方法销毁http请求。

    <!-- @[HTTP_interceptor_case_request_destroy](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_interceptor_case/entry/src/main/ets/pages/Index.ets) -->
    
    ``` TypeScript
    // 销毁请求
    httpRequest.destroy();
    ```

## 
## 相关实例

针对HTTP数据请求，有以下相关实例可供参考：

* [上传和下载（ArkTS）(API10)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Connectivity/UploadAndDownLoad)

* [Http（ArkTS）（API10）](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Connectivity/Http)

* [Http_case](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_case)

* [HTTP_interceptor_case(网络请求拦截器)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/HTTP_interceptor_case)
