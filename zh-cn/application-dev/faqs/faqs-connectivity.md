# 网络与连接开发常见问题



## Post请求时，extraData支持哪几种的数据格式？

适用于：OpenHarmony SDK 3.2.2.5版本， API9 Stage模型

extraData代表发送请求的额外数据，支持如下数据：

1. 当HTTP请求为POST、PUT方法时，此字段为HTTP请求的content。

2. 当HTTP请求为GET、OPTIONS、DELETE、TRACE、CONNECT方法时，此字段为HTTP请求的参数补充，参数内容会拼接到URL中进行发送。

3. 开发者传入string对象，开发者需要自行编码，将编码后的string传入。

## 如何理解http请求的错误码28？

适用于：OpenHarmony SDK 3.2.2.5版本，API9 Stage模型

错误码28代表CURLE_OPERATION_TIMEDOUT，操作超时。网络请求底层使用libcurl库，更多错误码可以查看相应文档。

参考文档：[开发指南](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-http.md#response%E5%B8%B8%E7%94%A8%E9%94%99%E8%AF%AF%E7%A0%81)和[Curl错误码](https://curl.se/libcurl/c/libcurl-errors.html)

## \@ohos.net.http.d.ts的response错误码返回6是什么意思？

适用于：OpenHarmony SDK 3.2.3.5版本

6表示地址无法解析主机，可以尝试ping一下request中的url，确认是否可以ping通。

更多错误码参考[Response常用错误码](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-http.md#response%E5%B8%B8%E7%94%A8%E9%94%99%E8%AF%AF%E7%A0%81)或者[Curl错误码](https://curl.se/libcurl/c/libcurl-errors.html)
