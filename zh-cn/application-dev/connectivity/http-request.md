# HTTP数据请求

## 场景介绍

应用通过HTTP发起一个数据请求，支持常见的GET、POST、OPTIONS、HEAD、PUT、DELETE、TRACE、CONNECT方法。

## 接口说明

HTTP数据请求功能主要由http模块提供。

使用该功能需要申请ohos.permission.INTERNET权限。

权限申请请参考[访问控制（权限）开发指导](../security/accesstoken-guidelines.md)。

涉及的接口如下表，具体的接口说明请参考[API文档](../reference/apis/js-apis-http.md)。

| 接口名                                    | 功能描述                            |
| ----------------------------------------- | ----------------------------------- |
| createHttp()                              | 创建一个http请求。                  |
| request()                                 | 根据URL地址，发起HTTP网络请求。     |
| destroy()                                 | 中断请求任务。                      |
| on(type: 'headersReceive')                | 订阅HTTP Response Header 事件。     |
| off(type: 'headersReceive')               | 取消订阅HTTP Response Header 事件。 |

## 开发步骤

1. import需要的http模块。
2. 创建一个HTTP请求，返回一个HttpRequest对象。
3. （可选）订阅HTTP响应头。
4. 根据URL地址，发起HTTP网络请求。
5. （可选）处理HTTP响应头和HTTP网络请求的返回结果。

```js
import http from '@ohos.net.http';

// 每一个httpRequest对应一个http请求任务，不可复用
let httpRequest = http.createHttp();

// 用于订阅http响应头，此接口会比request请求先返回。可以根据业务需要订阅此消息
// 从API 8开始，使用on('headersReceive', Callback)替代on('headerReceive', AsyncCallback)。 8+
httpRequest.on('headersReceive', (header) => {
    console.info('header: ' + JSON.stringify(header));
});

httpRequest.request(
    // 填写http请求的url地址，可以带参数也可以不带参数。URL地址需要开发者自定义。请求的参数可以在extraData中指定
    "EXAMPLE_URL",
    {
        method: http.RequestMethod.POST, // 可选，默认为http.RequestMethod.GET
        // 开发者根据自身业务需要添加header字段
        header: {
            'Content-Type': 'application/json'
        },
        // 当使用POST请求时此字段用于传递内容
        extraData: {
            "data": "data to send",
        },
        connectTimeout: 60000, // 可选，默认为60s
        readTimeout: 60000, // 可选，默认为60s
    }, (err, data) => {
        if (!err) {
            // data.result为http响应内容，可根据业务需要进行解析
            console.info('Result:' + data.result);
            console.info('code:' + data.responseCode);
            // data.header为http响应头，可根据业务需要进行解析
            console.info('header:' + JSON.stringify(data.header));
            console.info('cookies:' + data.cookies); // 8+
        } else {
            console.info('error:' + JSON.stringify(err));
            // 该请求不再使用，调用destroy方法主动销毁。
            httpRequest.destroy();
        }
    }
);
```

## 相关实例
针对HTTP数据请求，有以下相关实例可供参考：
- [`Http:`数据请求（ArkTS）（API9））](https://gitee.com/openharmony/applications_app_samples/tree/master/Network/Http)
- [使用HTTP实现与服务端通信（ArkTS）（API9）](https://gitee.com/openharmony/codelabs/tree/master/NetworkManagement/SmartChatEtsOH)