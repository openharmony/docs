# 默认UserAgent定义

从API version 11起，Web组件基于ArkWeb的内核，默认UserAgent定义如下：

Mozilla/5.0 ({deviceType}; {OSName} {OSVersion}) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/114.0.0.0 Safari/537.36 ArkWeb/{ArkWeb VersionCode} {Mobile}

| 字段               | 含义               | 备注               |
| ------------------ | ------------------ | ------------------ |
| deviceType         | 设备类型           | 通过系统参数const.product.devicetype映射得到。|
| OSName             | 发行版操作系统名称 | 通过系统参数const.product.os.dist.name得到。|
| OSVersion          | 发行版操作系统版本 | 通过系统参数const.ohos.fullname解析版本号得到。|
| ArkWeb VersionCode | ArkWeb版本号       |- |
| Mobile（可选）     | 是否是手机设备     |- |

举例：

Mozilla/5.0 (Phone; OpenHarmony 4.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/114.0.0.0 Safari/537.36 ArkWeb/4.1.6.1 Mobile

建议通过ArkWeb关键字识别是否是OpenHarmony设备以及web内核是否为ArkWeb，同时可以通过deviceType识别设备类型用于不同设备上的页面显示