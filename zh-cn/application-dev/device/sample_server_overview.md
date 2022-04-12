# 示例服务器开发概述

升级服务示例服务器提供一个简易的升级包部署的服务器实例参考，用于升级服务子系统的辅助验证环境搭建。

## 基本概念

- 搜包服务

升级服务(UpdateService)提供的服务能力之一，依赖环境需要TCP连接并支持SSL协议的服务器。

- 搜包服务器

即上文支持搜包服务的通过TCP连接并支持SSL协议的服务器，本概述提及的升级服务示例服务器即是符合要求的搜包服务器之一。

- 下载服务器


普通的HTTP服务器即可满足下载服务器的要求，可以参考Nginx和Tomcat搭建，并将升级包放在对应路径下。

- 设置升级包下载url


在搜包报文的url字段指定升级包下载url即可完成设置。

- 系统参数update.serverip.search


指升级服务(UpdateService)侧配置的搜包服务器IP地址，默认值：127.0.0.1。

## 约束与限制

- 客户端请求报文格式Json示例

参考升级服务组件搜包相关代码定义格式约束。

- 服务器返回报文格式Json示例

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
		"url": "http://serverAddressSample/packageNameSample.fileTypeSample".
		"descriptPackageId": "packageNameSample.fileTypeSample"
	}],
	"descriptInfo": [{
		"descriptPackageId": "packageNameSample.fileTypeSample",
		"content": "This package is used for update."
	}]
}
```

