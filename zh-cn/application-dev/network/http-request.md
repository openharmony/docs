# HTTP数据请求

## 场景介绍

应用通过HTTP发起一个数据请求，支持常见的GET、POST、OPTIONS、HEAD、PUT、DELETE、TRACE、CONNECT方法。

## 接口说明

HTTP数据请求功能主要由http模块提供。

使用该功能需要申请ohos.permission.INTERNET权限。

权限申请请参考[声明权限](../security/AccessToken/declare-permissions.md)。

涉及的接口如下表，具体的接口说明请参考[API文档](../reference/apis-network-kit/js-apis-http.md)。

| 接口名                                    | 描述                                |
| ----------------------------------------- | ----------------------------------- |
| createHttp()                              | 创建一个http请求。                  |
| request()                                 | 根据URL地址，发起HTTP网络请求。     |
| requestInStream()<sup>10+</sup>           | 根据URL地址，发起HTTP网络请求并返回流式响应。 |
| destroy()                                 | 中断请求任务。                      |
| on(type: 'headersReceive')                | 订阅HTTP Response Header 事件。     |
| off(type: 'headersReceive')               | 取消订阅HTTP Response Header 事件。 |
| once\('headersReceive'\)<sup>8+</sup>     | 订阅HTTP Response Header 事件，但是只触发一次。|
| on\('dataReceive'\)<sup>10+</sup>         | 订阅HTTP流式响应数据接收事件。      |
| off\('dataReceive'\)<sup>10+</sup>        | 取消订阅HTTP流式响应数据接收事件。  |
| on\('dataEnd'\)<sup>10+</sup>             | 订阅HTTP流式响应数据接收完毕事件。  |
| off\('dataEnd'\)<sup>10+</sup>            | 取消订阅HTTP流式响应数据接收完毕事件。 |
| on\('dataReceiveProgress'\)<sup>10+</sup>        | 订阅HTTP流式响应数据接收进度事件。  |
| off\('dataReceiveProgress'\)<sup>10+</sup>       | 取消订阅HTTP流式响应数据接收进度事件。 |
| on\('dataSendProgress'\)<sup>11+</sup>        | 订阅HTTP网络请求数据发送进度事件。  |
| off\('dataSendProgress'\)<sup>11+</sup>       | 取消订阅HTTP网络请求数据发送进度事件。 |

## request接口开发步骤

1. 从@kit.NetworkKit中导入http命名空间。
2. 调用createHttp()方法，创建一个HttpRequest对象。
3. 调用该对象的on()方法，订阅http响应头事件，此接口会比request请求先返回。可以根据业务需要订阅此消息。
4. 调用该对象的request()方法，传入http请求的url地址和可选参数，发起网络请求。
5. 按照实际业务需要，解析返回结果。
6. 调用该对象的off()方法，取消订阅http响应头事件。
7. 当该请求使用完毕时，调用destroy()方法主动销毁。

```ts
// 引入包名
import { http } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 每一个httpRequest对应一个HTTP请求任务，不可复用
let httpRequest = http.createHttp();
// 用于订阅HTTP响应头，此接口会比request请求先返回。可以根据业务需要订阅此消息
// 从API 8开始，使用on('headersReceive', Callback)替代on('headerReceive', AsyncCallback)。 8+
httpRequest.on('headersReceive', (header) => {
  console.info('header: ' + JSON.stringify(header));
});
httpRequest.request(
  // 填写HTTP请求的URL地址，可以带参数也可以不带参数。URL地址需要开发者自定义。请求的参数可以在extraData中指定
  "EXAMPLE_URL",
  {
    method: http.RequestMethod.POST, // 可选，默认为http.RequestMethod.GET
    // 开发者根据自身业务需要添加header字段
    header: {
      'Content-Type': 'application/json'
    },
    // 当使用POST请求时此字段用于传递请求体内容，具体格式与服务端协商确定
    extraData: "data to send",
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
      keyPassword: "passwordToKey" // 可选，输入key文件的密码，自API 11开始支持该属性
    },
    multiFormDataList: [ // 可选，仅当Header中，'content-Type'为'multipart/form-data'时生效，自API 11开始支持该属性
      {
        name: "Part1", // 数据名，自API 11开始支持该属性
        contentType: 'text/plain', // 数据类型，自API 11开始支持该属性
        data: 'Example data', // 可选，数据内容，自API 11开始支持该属性
        remoteFileName: 'example.txt' // 可选，自API 11开始支持该属性
      }, {
        name: "Part2", // 数据名，自API 11开始支持该属性
        contentType: 'text/plain', // 数据类型，自API 11开始支持该属性
        // data/app/el2/100/base/com.example.myapplication/haps/entry/files/fileName.txt
        filePath: `${getContext(this).filesDir}/fileName.txt`, // 可选，传入文件路径，自API 11开始支持该属性
        remoteFileName: 'fileName.txt' // 可选，自API 11开始支持该属性
      }
    ]
  }, (err: BusinessError, data: http.HttpResponse) => {
    if (!err) {
      // data.result为HTTP响应内容，可根据业务需要进行解析
      console.info('Result:' + JSON.stringify(data.result));
      console.info('code:' + JSON.stringify(data.responseCode));
      // data.header为HTTP响应头，可根据业务需要进行解析
      console.info('header:' + JSON.stringify(data.header));
      console.info('cookies:' + JSON.stringify(data.cookies)); // 8+
      // 当该请求使用完毕时，调用destroy方法主动销毁
      httpRequest.destroy();
    } else {
      console.error('error:' + JSON.stringify(err));
      // 取消订阅HTTP响应头事件
      httpRequest.off('headersReceive');
      // 当该请求使用完毕时，调用destroy方法主动销毁
      httpRequest.destroy();
    }
  }
);
```

## requestInStream接口开发步骤

1. 从@kit.NetworkKit中导入http命名空间。
2. 调用createHttp()方法，创建一个HttpRequest对象。
3. 调用该对象的on()方法，可以根据业务需要订阅HTTP响应头事件、HTTP流式响应数据接收事件、HTTP流式响应数据接收进度事件和HTTP流式响应数据接收完毕事件。
4. 调用该对象的requestInStream()方法，传入http请求的url地址和可选参数，发起网络请求。
5. 按照实际业务需要，可以解析返回的响应码。
6. 调用该对象的off()方法，取消订阅响应事件。
7. 当该请求使用完毕时，调用destroy()方法主动销毁。

```ts
// 引入包名
import { http } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 每一个httpRequest对应一个HTTP请求任务，不可复用
let httpRequest = http.createHttp();
// 用于订阅HTTP响应头事件
httpRequest.on('headersReceive', (header: Object) => {
  console.info('header: ' + JSON.stringify(header));
});
// 用于订阅HTTP流式响应数据接收事件
let res = new ArrayBuffer(0);
httpRequest.on('dataReceive', (data: ArrayBuffer) => {
   const newRes = new ArrayBuffer(res.byteLength + data.byteLength);
   const resView = new Uint8Array(newRes);
   resView.set(new Uint8Array(res));
   resView.set(new Uint8Array(data), res.byteLength);
   res = newRes;
   console.info('res length: ' + res.byteLength);
});
// 用于订阅HTTP流式响应数据接收完毕事件
httpRequest.on('dataEnd', () => {
  console.info('No more data in response, data receive end');
});
// 用于订阅HTTP流式响应数据接收进度事件
class Data {
  receiveSize: number = 0;
  totalSize: number = 0;
}
httpRequest.on('dataReceiveProgress', (data: Data) => {
  console.log("dataReceiveProgress receiveSize:" + data.receiveSize + ", totalSize:" + data.totalSize);
});

let streamInfo: http.HttpRequestOptions = {
  method: http.RequestMethod.POST,  // 可选，默认为http.RequestMethod.GET
  // 开发者根据自身业务需要添加header字段
  header: {
    'Content-Type': 'application/json'
  },
  // 当使用POST请求时此字段用于传递请求体内容，具体格式与服务端协商确定
  extraData: "data to send",
  expectDataType:  http.HttpDataType.STRING,// 可选，指定返回数据的类型
  usingCache: true, // 可选，默认为true
  priority: 1, // 可选，默认为1
  connectTimeout: 60000, // 可选，默认为60000ms
  readTimeout: 60000, // 可选，默认为60000ms。若传输的数据较大，需要较长的时间，建议增大该参数以保证数据传输正常终止
  usingProtocol: http.HttpProtocol.HTTP1_1 // 可选，协议类型默认值由系统自动指定
}

// 填写HTTP请求的URL地址，可以带参数也可以不带参数。URL地址需要开发者自定义。请求的参数可以在extraData中指定
httpRequest.requestInStream("EXAMPLE_URL", streamInfo).then((data: number) => {
  console.info("requestInStream OK!");
  console.info('ResponseCode :' + JSON.stringify(data));
  // 取消订阅HTTP响应头事件
  httpRequest.off('headersReceive');
  // 取消订阅HTTP流式响应数据接收事件
  httpRequest.off('dataReceive');
  // 取消订阅HTTP流式响应数据接收进度事件
  httpRequest.off('dataReceiveProgress');
  // 取消订阅HTTP流式响应数据接收完毕事件
  httpRequest.off('dataEnd');
  // 当该请求使用完毕时，调用destroy方法主动销毁
  httpRequest.destroy();
}).catch((err: Error) => {
  console.info("requestInStream ERROR : err = " + JSON.stringify(err));
});
```

## 证书锁定

可以通过预置应用级证书，或者预置证书公钥哈希值的方式来进行证书锁定，即只有开发者特别指定的证书才能正常建立https连接。

两种方式都是在配置文件中配置的，配置文件在APP中的路径是：`src/main/resources/base/profile/network_config.json`。在该配置中，可以为预置的证书与网络服务器建立对应关系。

如果不知道服务器域名的证书，可以通过以下方式访问该域名获取证书，注意把`www.example.com`改成想要获取域名证书的域名，`www.example.com.pem`改成想保存的证书文件名：

```
openssl s_client -servername www.example.com -connect www.example.com:443 \
    < /dev/null | sed -n "/-----BEGIN/,/-----END/p" > www.example.com.pem
```

如果你的环境是Windows系统，需要注意：

* 将`/dev/null`替换成`NUL`。
* 和Linux的OpenSSL表现可能不同，OpenSSL可能会等待用户输入才会退出，按Enter键即可。
* 如果没有sed命令，将输出中从`-----BEGIN CERTIFICATE-----`到`-----END CERTIFICATE-----`之间的部分复制下来保存即可（复制部分包括这两行）。

### 预置应用级证书

直接把证书原文件预置在APP中。目前支持crt和pem格式的证书文件。

> **注意：**
>
> 当前ohos.net.http和Image组件的证书锁定，会匹配证书链上所有证书的哈希值，如果服务器更新了任意一本证书，都会导致校验失败。如果服务器出现了更新证书的情况，APP版本应当随之更新并推荐消费者尽快升级APP版本，否则可能导致联网失败。

### 预置证书公钥哈希值

通过在配置中指定域名证书公钥的哈希值来只允许使用公钥哈希值匹配的域名证书访问此域名。

域名证书的公钥哈希值可以用如下的命令计算，这里假设域名证书是通过上面的OpenSSL命令获得的，并保存在`www.example.com.pem`文件。#开头的行是注释，可以不用输入：

```
# 从证书中提取出公钥
openssl x509 -in www.example.com.pem -pubkey -noout > www.example.com.pubkey.pem
# 将pem格式的公钥转换成der格式
openssl asn1parse -noout -inform pem -in www.example.com.pubkey.pem -out www.example.com.pubkey.der
# 计算公钥的SHA256并转换成base64编码
openssl dgst -sha256 -binary www.example.com.pubkey.der | openssl base64
```

### JSON配置文件示例

预置应用级证书的配置例子如下：

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

预置证书公钥哈希值的配置例子如下:
```
{
  "network-security-config": {
    "domain-config": [
      {
        "domains": [
          {
            "include-subdomains": true,
            "name": "server.com"
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

**各个字段含义:**

**network-security-config(object:网络安全配置)**

可包含0或者1个base-config

必须包含1个domain-config

**base-config(object:指示应用程序范围的安全配置)**

必须包含1个trust-anchors

**domain-config(array:指示每个域的安全配置)**

可以包含任意个item

item必须包含1个domains

item可以包含0或者1个trust-anchors

item可包含0个或者1个pin-set

**trust-anchors(array:受信任的CA)**

可以包含任意个item

item必须包含1个certificates(string:CA证书路径)

**domains(array:域)**

可以包含任意个item

item必须包含1个name(string:指示域名)

item可以包含0或者1个include-subdomains(boolean:指示规则是否适用于子域)

**pin-set(object:证书公钥哈希设置)**

必须包含1个pin

可以包含0或者1个expiration(string:指示证书公钥哈希的过期时间)

**pin(array:证书公钥哈希)**

可以包含任意个item

item必须包含1个digest-algorithm(string:指示用于生成哈希的摘要算法，目前只支持`sha256`)

item必须包含1个digest(string:指示公钥哈希)

## 相关实例

针对HTTP数据请求，有以下相关实例可供参考：

- [上传和下载（ArkTS）(API10)](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Connectivity/UploadAndDownLoad)

- [Http（ArkTS）（API10）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Connectivity/Http)
