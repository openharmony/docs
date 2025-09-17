# 网络管理开发常见问题
<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->


## http网络请求中extraData支持的数据格式有哪些(API 9)

**解决措施**

extraData代表发送请求的额外数据，支持如下数据：

- 当HTTP请求为POST、PUT方法时，此字段为HTTP请求的content。

- 当HTTP请求为GET、OPTIONS、DELETE、TRACE、CONNECT方法时，此字段为HTTP请求的参数补充，参数内容会拼接到URL中进行发送。

- 开发者传入string对象，开发者需要自行编码，将编码后的string传入。


## http请求的错误码28是什么意思(API 9)

**问题现象**

发起http请求后报错，错误码28。

**解决措施**

错误码28代表CURLE_OPERATION_TIMEDOUT，操作超时。网络请求底层使用libcurl库，更多错误码可以查看相应文档。

**参考链接**

[http常见响应码](../reference/apis-network-kit/js-apis-http.md#responsecode)和[Curl错误码](https://curl.se/libcurl/c/libcurl-errors.html)


## http请求中response错误码返回6是什么意思(API 9)

**问题现象**

发起http请求后，返回信息中response错误码为6。

**解决措施**

错误码6表示地址无法解析主机，可以尝试ping一下request中的URL，确认是否可以ping通。

**参考链接**

更多错误码参考[http常见响应码](../reference/apis-network-kit/js-apis-http.md#responsecode)和[Curl错误码](https://curl.se/libcurl/c/libcurl-errors.html)

## \@ohos/axios三方件post请求queryParams参数场景下如何传参(API 9)

**问题现象**

三方件\@ohos/axios中发起post请求，以queryParams形式传递参数（将参数拼接在URL后）。

**解决措施**

- 方式一：使用axios.post接口只接收一个参数，Url.URLSearchParams需要转成字符串拼接在url后面。

  ```
  let params:Url.URLSearchParams = new Url.URLSearchParams()
  params.append('ctl', 'sug')
  params.append('query', 'wangjunkai')
  params.append('cfrom', '1099a')
  axios.post('http://10.100.195.234:3000/save?' + params.toString()).then(res => {
    this.message = "request result: " + JSON.stringify(res.data);
  }).catch(err => {
    this.message = "request error: " + err.message;
  })
  ```

- 方式二：使用axios接口只接收一个config对象，请求参数写在config对象的params中。

  ```
  axios({
    url: 'http://10.100.195.234:3000/save',
    method: 'post',
    params: {
    ctl: 'sug',
    query: 'wangjunkai',
    cfrom: '1099a'
    }
  }).then(res => {
    this.message = "request result: " + JSON.stringify(res.data);
  }).catch(err => {
    this.message = "request error: " + err.message;
  })
  ```


## connection.getNetCapabilities(mNetHandle)无法正常返回结果(API 9)

**问题现象**

在网络连接管理中，调用connection.getNetCapabilities()函数时无法取到数据。

**原因分析**

this指向存在问题，用(err,data)=&gt;{}可以进入回调函数并且拿到返回结果数据，不能使用function(err,data)，因为function声明的函数内存在自己的this，无法指向全局的this。

**解决措施**

getNetCapabilities的第二个参数把function(err,data)改成(err,data)。


## http请求如何以json形式进行传输(API 9)

**解决措施**

在HTTP协议消息头中，使用Content-Type来表示媒体类型信息。它被用来告诉服务端如何处理请求的数据，以及告诉客户端（一般是浏览器）如何解析响应的数据，比如显示图片，解析html或仅仅展示一个文本等。

设置该参数值为application/json，请求中的数据就会以json形式进行传输。

```
this.options = {
  method:  http.RequestMethod.GET,
  extraData: this.extraData,
  header: { 'Content-Type': 'application/json' },
  readTimeout: 50000,
  connectTimeout: 50000
}
```


## 调用camera拍摄的照片如何上传到服务器(API 9)

**问题现象**

应用调用摄像头拍照后如何将图片上传到服务器？

**解决措施**

启动应用，获取权限后系统会访问远程服务器，将拍摄照片保存在本地，通过上传接口将文件从个人设备传送至远程服务器。

**参考链接**

[上传下载](../reference/apis-basic-services-kit/js-apis-request.md)


## 设备网络正常，调用connection.hasDefaultNet()接口失败(API 9)

**问题现象**

设备可以上网，浏览器可以正常打开网页，但是hasDefaultNet这个方法调用失败，回调函数走到了失败的回调。

**解决措施**

connection.hasDefaultNet 接口需要注明需要权限ohos.permission.GET_NETWORK_INFO

权限申请链接：[声明权限](../security/AccessToken/declare-permissions.md)


## 如何理解connection.getDefaultNet返回对象netHandle中的netId(API 9)

**问题现象**

netId的值如0、100分别代表什么含义？

**解决措施**

正常情况下，netHandle里的netId为0时表示没联网，大于等于100时为有网状态。


## 如何使用http请求从网络上获取数据(API 9)

**解决措施**

使用\@ohos.net.http模块来发起http网络请求。

1. 导入http模块，创建http请求对象。

2. 设置请求地址URLl和参数，发起http请求。

3. 获取请求结果response，并解析数据。

**参考链接**

[http数据请求](../network/http-request.md)


## 如何使用JS封装网络请求(API 9)

**解决措施**

网络请求支持JS语言开发方式，可直接使用。具体使用参考如下文档：[网络连接](../reference/apis-network-kit/js-apis-http.md)


## 基于JS开发智能手表应用，如何编写网络请求(API 9)

**解决措施**

网络请求支持JS语言开发方式，可直接使用。具体使用参考如下文档：[网络连接](../reference/apis-network-kit/js-apis-http.md)


## 应用增加权限"ohos.permission.NOTIFICATION_CONTROLLER"，编译后无法启动(API 9)

**问题现象**

启动报错：error: install failed due to grant request permissions failed.

**解决措施**

权限"ohos.permission.NOTIFICATION_CONTROLLER为系统级“system core”权限，第三方应用无法获取该权限。


## WiFi模块中使用wifi.getIpInfo().ipAddress报错(API 9)

**问题现象**

WiFi模块中使用wifi.getIpInfo().ipAddress，报错Error: assertion (wifiDevicePtr != nullptr) failed: Wifi device instance is null

**解决措施**

权限不足。请先检查是否申请了相关的操作权限，权限相关信息可参考[权限管理](../security/AccessToken/determine-application-mode.md)。

## 在使用Socket连接相关接口时，NetAddress的address参数只能是IP地址，如果只有host的情况如何处理？(API 11)

**解决方案**

可通过使用getAddressByName接口解析主机名以获取IP地址。

**参考资料**

[@ohos.net.connection (网络连接管理)](../reference/apis-network-kit/js-apis-net-connection.md)

## 如何使用C接口使用网络相关功能？(API 11)
 
**解决方案**

目前提供了C接口的有如下几个模块：  
自定义DNS解析、证书校验、WebSocket  

没直接提供C接口的可以通过AKI机制调用ArkTS接口。

  
**参考资料**

https://gitcode.com/openharmony/interface_sdk_c/tree/master/network

## Socket下的TLSConnectOptions不配置是否会使用设备上的默认证书？(API 11)

**解决方案**

使用TLSSocket请求需要手动通过代码配置，不会使用设备上的默认证书。TLSConnectOptions部分配置证书需要使用与请求地址相匹配的证书内容，可将证书放至rawfile文件下通过getRawFileContent()方法读取转换为string类型数据放入。  

**参考资料**

[@ohos.net.socket (Socket连接)](../reference/apis-network-kit/js-apis-socket.md)