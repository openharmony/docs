# ArkWeb子系统变更说明

## cl.arkweb.1 下载的cancel、pause、resume接口支持场景变更

**访问级别**

公开接口

**变更原因**

使用Webview.WebDownloadDelegate.onBeforeDownload回调事件中接收到的WebDownloadItem对象调用cancel或pause接口无效。

**变更影响**

该变更为兼容性变更。

变更前：使用WebView.WebDownloadDelegate.onBeforeDownload回调事件中接收到的WebDownloadItem对象调用cancel、pause、resume接口均无效，且对于pause和resume接口会返回17100019错误码。

变更后：使用WebView.WebDownloadDelegate.onBeforeDownload回调事件中接收到的WebDownloadItem对象调用cancel、pause、resume接口在符合使用规则的前提下可以生效，且不会返回17100019错误码。

**API Level**

起始支持版本为 API 11。

**变更发生版本**

从OpenHarmony SDK 5.0.0.18开始。

**适配指导**

1. 在使用WebView.WebDownloadDelegate.onBeforeDownload回调事件中接收到的WebDownloadItem对象调用cancel前，需要先调用start；
2. 在使用WebView.WebDownloadDelegate.onBeforeDownload回调事件中接收到的WebDownloadItem对象调用pause前，需要先调用start；
3. 在使用WebView.WebDownloadDelegate.onBeforeDownload回调事件中接收到的WebDownloadItem对象调用resume前，需要先调用pause。
