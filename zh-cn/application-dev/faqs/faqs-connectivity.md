# 网络与连接开发常见问题

## 网络请求中extraData支持哪几种的数据格式

适用于：OpenHarmony SDK 3.2.2.5版本， API9 Stage模型

extraData代表发送请求的额外数据，支持如下数据：

1. 当HTTP请求为POST、PUT方法时，此字段为HTTP请求的content。

2. 当HTTP请求为GET、OPTIONS、DELETE、TRACE、CONNECT方法时，此字段为HTTP请求的参数补充，参数内容会拼接到URL中进行发送。

3. 开发者传入string对象，开发者需要自行编码，将编码后的string传入。

## 如何理解http请求的错误码28

适用于：OpenHarmony SDK 3.2.2.5版本，API9 Stage模型

错误码28代表CURLE_OPERATION_TIMEDOUT，操作超时。网络请求底层使用libcurl库，更多错误码可以查看相应文档。

参考文档：[开发指南](../reference/apis/js-apis-http.md#response%E5%B8%B8%E7%94%A8%E9%94%99%E8%AF%AF%E7%A0%81)和[Curl错误码](https://curl.se/libcurl/c/libcurl-errors.html)

## \@ohos.net.http.d.ts的response错误码返回6是什么意思？

适用于：OpenHarmony SDK 3.2.3.5版本

6表示地址无法解析主机，可以尝试ping一下request中的url，确认是否可以ping通。

更多错误码参考[Response常用错误码](../reference/apis/js-apis-http.md#response%E5%B8%B8%E7%94%A8%E9%94%99%E8%AF%AF%E7%A0%81)或者[Curl错误码](https://curl.se/libcurl/c/libcurl-errors.html)

## 调用camera拍摄的照片怎么上传到服务器

适用于：所有版本

具体开发参考文档：[上传下载](https://gitee.com/openharmony/app_samples/tree/master/Network/UploadDownload)

## OpenHarmony的http接口如何设置cookie

适用于：OpenHarmony SDK 3.2.6.5版本，API9 Stage模型

HttpRequestOptions中的header是一个Object类型，可以直接在header里设置cookie，具体开发参考文档：[数据请求](../reference/apis/js-apis-http.md#request)。

## http请求的官方示例代码里的extra data部分怎么写

适用于：OpenHarmony SDK 3.2.6.5版本，API9 Stage模型

1. 鼠标移到extraData, ctrl+鼠标左键，跳转到sdk中，里面有关于extraData的传参说明。可以发现文档中对extraData的定义是这样的 extraData?: string | Object,也就是extraData支持string 和 Object两种类型。

2. 这两种写法都可以实现：
  a.extraData:"data to send"；
  b. extraData:{ data:"data to send", },

## 设备连接wifi后，如何获取当前设备的IP地址

适用于：OpenHarmony SDK 3.2.7.5版本，API9 Stage模型

使用wifi模块获取ipInfo，然后转换为IP常用格式，注意wifi.getIpInfo()接口需要权限 ohos.permission.GET_WIFI_INFO。

示例：

  
```
import wifi from '@ohos.wifi'
@Entry
@Component
struct Page {
  @State ip: string = '点击获取ip'

  resolveIP(ip) {
    if (ip < 0 || ip > 0xFFFFFFFF) {
      throw ("The number is not normal!");
    }
    return (ip >>> 24) + "." + (ip >> 16 & 0xFF) + "." + (ip >> 8 & 0xFF) + "." + (ip & 0xFF);
  }

  build() {
    Row() {
      Column() {
        Text(this.ip)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(()=>{
            this.ip = this.resolveIP(wifi.getIpInfo().ipAddress)
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## 如何判断当前是否有网络

适用于：OpenHarmony SDK 3.2.6.5版本，API9 Stage模型

通过如下hasDefaultNet接口判断是否有网络，注意需要申请 ohos.permission.GET_NETWORK_INFO 权限

  
```
connection.hasDefaultNet().then((has)=> {
  console.log("hasDefaultNet " + JSON.stringify(has))
})
```