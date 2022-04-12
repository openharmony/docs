# 示例服务器开发指导

## 场景介绍

升级服务示例服务器开发指导的主要工作是为了解决升级服务的实际应用场景测试中缺乏相应搜包服务器提供查询升级包、获取升级包下载url等功能，使得测试升级服务和二次开发功能验证比较困难的问题得到解决，为升级服务的应用场景提供尽可能完善的端到端环境搭建。开发者能够基于此指导快速开发一个简易的搜包服务器用于升级服务应用场景测试。

## 接口说明

| 接口名                                           | 描述             |
| ------------------------------------------------ | ---------------- |
| int SetParam(const char *key, const char *value) | 设置字段参数值。 |
| int GetParam(const char *key, char *value)       | 获取字段参数值。 |

## 开发步骤

### 生成SSL证书

会生成serverKey.pem和serverCert.cer两个文件。

```bash
openssl req -newkey rsa:2048 -nodes -keyout serverKey.pem -x509 -days 365 -out serverCert.cer -subj "/C=CN/ST=GD/L=GZ/O=abc/OU=defg/CN=hijk/emailAddress=test.com"
```



### 修改bundle.json

在build字段的sub_component字段中开始位置新增一行。

```cmake
"sub_component": [
	"//base/update/updateservice/server_sample:testserver",
	...
],
```

### 下载代码仓

通过repo下载OpenHarmony全仓，或者通过git clone下载本代码仓。

```bash
git clone https://gitee.com/openharmony/update_updateservice.git -b master
```



### 建立代码目录

进入到本仓update_updateservice目录下，执行以下命令，建立代码目录。

```bash
mkdir server_sample							// 建立示例服务器server_sample目录
touch server_sample/BUILD.gn				 // 创建BUILD.gn编译文件
mkdir server_sample/include					 // 建立示例服务器头文件include目录
touch server_process.h						// 创建server_process.h头文件
mkdir server_sample/src						// 建立示例服务器c/c++文件src目录
touch server_sample/src/server_process.c	  // 创建server_process.c文件
touch server_sample/src/main.cpp			 // 创建main.cpp文件
```

### 编译文件BUILD.gn编写

文件BUILD.gn一共编译两个ohos组件，一个是ohos_shared_library库文件libserver_process.z.so，一个是ohos_executable可执行文件testserver。

```cmake
import("//build/ohos.gni")

ohos_shared_library("server_process") {
	sources = [
		"//base/update/updateservice/./src/server_process.c",
	]
	
	include_dirs = [
		"//base/update/updateservice/server_sample/include",
		"//third_party/openssl/include",
	]
	
	deps = [
		"//base/update/updater/services/log:libupdaterlog",
		"//third_party/bounds_checking_function:libsec_static",
		"//third_party/openssl:crypto_source",
		"//third_party/openssl:ssl_source",
		"//utils/native/base:utils",
	]
	
	part_name = "update_service"
}

ohos_executable("testserver") {
	source = [
		"//base/update/updateservice/server_sample/src/main.cpp",
	]
	
	include_dirs = [
		"//base/update/updateservice/server_sample/include",
	]
	
	deps = [
		"//base/update/updateservice/server_sample:server_process",
	]
	
	part_name = "update_service"
}
```

### 头文件server_process.h编写

文件server_process.h声明了示例服务器的一些接口。

```c++
#ifndef __SERVER_PROCESS_H__
#define __SERVER_PROCESS_H__

/*
Init函数：用于创建socket环境，并预设置一些属性
*/
int Init();

/*
SetParam函数：所有插件参数设置的统一接口
*/
int SetParam(const char *key, const char *value);

/*
GetParam函数：所有插件参数获取的统一接口
*/
int GetParam(const char *key, char *value);

/*
ReverseSetParamCallback函数：回调
*/
int ReverseSetParamCallback(int(*setParam)(const char *key, const char *value));

/*
Open函数：用于服务打开的接口
*/
int Open();

/*
MainLoop函数：每隔100ms调用一次
*/
int MainLoop();

/*
Close函数，用于关闭服务并释放资源
*/
int Close();

#endif //__SERVER_PROCESS_H__
```

### server_process.c、main.cpp编写

文件server_process.c主要声明了服务器的返回报文格式respondContent；main.cpp编写在此略去，可参考普通SSL协议的服务器编写，注意包含相关头文件，同时加载serverKey.pem和serverCert.cer两个证书。

```c
#include "server_process.h"

#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "openssl/err.h"
#include "openssl/ssl.h"

#define SERVER_PEM "/data/sdcard/serverKey.pem"  //使用绝对路径
#define SERVER_CER "/data/sdcard/serverCert.cer" //使用绝对路径

#define LOG_PRINT(fmt, ...) printf("[ServerProcess][%s:%d] " fmt "\n", __func__, __LINE__, ##__VA_ARGS__)
#define DO_CHECK(cond, log, ...) \
	if (!(cond)) {\
		LOG_PRINT(log);\
		__VA_ARGS__;\
		return -1;\
	}

// 请参考server_process.h的接口予以实现，注意服务器返回的内容格式。
respondContent = "{"
        "\"searchStatus\": 0,"
        "\"errMsg\": \"success\","
        "\"checkResults\": [{"
            "\"versionName\": \"sampleVersionName\","
            "\"versionCode\": \"sampleVersionCode\","
            "\"verifyInfo\": \"sampleVerifyInfoSha256Value\","
            "\"size\": 1234567,"
            "\"packageType\": 1,"
            "\"descriptPackageId\": \"update.bin\","
        "}],"
        "\"descriptInfo\": [{"
            "\"descriptPackageId\": \"update.bin\","
            "\"content\": \"This package message is used for sampleContent\""
        "}]"
	"}";
```

### 编译输出产物

编译输出目录会新增testserver和libserver_process.z.so两个文件。

### 升级包制作

参考OpenHarmony的update_packaging_tools仓制作升级包。

```http
https://gitee.com/openharmony/update_packaging_tools
```

**启动搜包服务器**

建议在开发板上新建一个纯英文路径；然后将testserver、libserver_process.z.so、serverCert.cer和serverKey.pem放到同一个目录下，进入该目录，执行以下启动命令即可启动搜包服务器。

```bash
./testserver ./libserver_process.z.so &
```

