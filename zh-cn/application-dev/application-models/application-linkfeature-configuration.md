# 概述

- 应用链接（[Deep Linking](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/application-models/deep-linking-startup.md)[、App Linking](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/application-models/app-linking-startup.md)）是系统推荐的指向性[应用跳转](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/application-models/link-between-apps-overview.md")方案，开发者可以通过在[module.json5配置文件](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/quick-start/module-configuration-file.md)申明[skills中的URI](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/quick-start/module-configuration-file.md#skills%25E6%25A0%2587%25E7%25AD%25BE)对外暴露可跳入的应用链接。

- URI中的linkFeature字段，用于标识通过应用链接跳转后的标准化应用功能（如登录、支付、分享等），取值为系统预定义的linkFeature值，配置时请注意保持linkFeature与实际链接功能相对应。

- 例如，URI中的linkFeature配置为Share，表示应用链接跳转后可以打开应用中的分享功能页面。 

- linkFeature完成配置申明并通过系统认证后，可以在应用间跳转、系统面板等系统服务中使用。

# 配置示例

参考应用链接（[Deep Linking](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/application-models/deep-linking-startup.md)、[App Linking](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/application-models/app-linking-startup.md)）的配置要求进行URI配置，最后在URI配置中指定相对应的linkFeature即可。

下面以授权登录场景举例说明：

1. 原应用链接的URI配置如下，跳转后的功能为授权登录
    ```json
    "uris": [
        {
            "scheme": "xxx",
            "host": "xxx.xxx.xxx",
            "path":"xxx/xxxx"
        }
    ]
    ```

1. 补充配置对应URI的linkFeature为Login即可
    ```json
    "uris": [
        {
            "scheme": "xxx",
            "host": "xxx.xxx.xxx",
            "path":"xxx/xxxx",
            "linkFeature"："Login" 
        }
    ]
    ```

标准化应用功能**linkFeature**的枚举定义。

||||
|---|---|---|
|名称|值|说明|
|登录|Login|指示登录、授权登录等功能|
|支付|Pay|指示支付页面、收银台等功能|
|分享|Share|指示分享功能|
|缓存清理|AppStorageMgmt|指示清理应用沙箱目录中缓存数据的功能|
|扫码|ScanCode|指示扫码功能|
|打开本地文件|FileOpen|指示打开处理文件的功能|
|导航|Navigation|指示导航功能|
|路线规划|RoutePlan|指示路线规划功能|
|地点搜索|PlaceSerach|指示地点搜索功能|