# 示例服务器开发概述

示例服务器提供一个简易的升级包部署的服务器实例参考，用于搭建升级服务子系统的辅助验证环境。

## 基本概念

- 搜包服务：升级服务（UpdateService）提供的服务能力之一，依赖支持TCP和SSL协议的服务器。

- 搜包服务器：即支持搜包服务的通过TCP连接并支持SSL协议的服务器，本概述提及的升级服务示例服务器即是符合要求的搜包服务器之一。

- 下载服务器：普通的HTTP服务器即可满足下载服务器的要求。

- update.serverip.search：系统参数，指升级服务（UpdateService）侧配置的搜包服务器IP地址，默认值：127.0.0.1。

## 约束与限制

- 服务器返回报文格式Json示例，注意verifyInfo字段是升级包的sha256值，size字段是升级包的大小，单位为字节。

```json
{
    "searchStatus": 0,
    "errMsg": "success",
    "checkResults": [{
        "versionName": "versionNameSample",
        "versionCode": "versionCodeSample",
        "verifyInfo": "verifyInfoSHA256Value1234567",
        "size": 1234567,
        "packageType": 1,
        "url": "http://serverAddressSample/packageNameSample.fileTypeSample",
        "descriptPackageId": "abcdefg1234567ABCDEFG"
    }],
    "descriptInfo": [{
        "descriptionType": 0,
        "content": "This package is used for update."
    }]
}
```

