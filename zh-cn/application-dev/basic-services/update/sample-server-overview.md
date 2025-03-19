# 示例服务器开发概述

示例服务器提供一个简易的升级包部署的服务器实例参考，用于搭建升级服务子系统的辅助验证环境。

## 场景介绍

开发者在实际应用中，需要服务器提供升级包的查询、下载等能力。示例服务器为开发者提供了如下能力：

- 升级包的查询：服务器返回升级包的版本信息。

- 升级包的下载：服务器返回升级包的下载链接。

示例服务器支持测试升级服务和二次开发功能验证，为升级服务的应用场景提供尽可能完善的端到端环境搭建。

## 基本概念

- 搜包服务：升级服务（UpdateService）提供的服务能力之一，依赖支持TCP和SSL协议的服务器。

- 搜包服务器：即支持搜包服务的通过TCP连接并支持SSL协议的服务器，本概述提及的升级服务示例服务器即是符合要求的搜包服务器之一。

- 下载服务器：普通的HTTP服务器即可满足下载服务器的要求。

- update.serverip.search：系统参数，指升级服务（UpdateService）侧配置的搜包服务器IP地址，默认值：127.0.0.1。

## 约束与限制

- 服务器返回报文格式json示例，注意verifyInfo字段是升级包的sha256值，size字段是升级包的大小，单位为字节。

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

