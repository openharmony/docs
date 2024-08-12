# 应用链接说明

## URL的基本格式

应用链接是指可以将用户引导至应用内特定位置或相关网页的URL。URL的基本格式如下：
```
scheme://host[:port]/path/
```

- scheme：协议名称。例如http、https等。
- host：域名或IP地址。例如域名`developer.huawei.com`或IP地址`127.0.0.1`；
- port：端口号。例如`developer.huawei.com:80`后面的80即为端口号。
- path：路径，表示域名服务器上的目录或文件路径。例如`developer.huawei.com/consumer/`中`consumer`。
- linkFeature：标识URI提供的功能类型（如文件打开、分享、导航等），用于实现应用间跳转。取值为长度不超过127字节的字符串，不支持中文。

> **说明：**
> 
> 系统应用预留scheme统一以`ohos`开头，例如`ohosclock://`。三方应用组件配置的scheme不能与系统应用重复，否则会导致无法通过该uri拉起三方应用组件。 
> 
> 如果多个应用的URL配置相同，应用跳转时匹配到同多个应用，则会拉起应用选择框。为了更好的用户体验，开发者可以通过链接的path字段去区分同一域名下的不同应用，如链接`https://www.example.com/path1`拉起目标应用1，链接`https://www.example.com/path2`拉起目标应用2。

## linkFeature标签说明

配置后主要有两类作用，应用间跳转确认体验增强、系统入口呈现

1、应用间跳转确认弹框体验增强：应用申明linkFeature，系统将认证申明的linkFeature与实际拉起的功能是否一致，认证通过后其他应用通过此链接拉起应用时，应用间跳转确认弹框将变为可信跳转确认样式，例如：默认选中x天不再提醒等。

2、系统入口呈现：用户在访问系统入口（各系统垂域面板、设置等）时，系统将展示认证通过的应用功能入口；用户点击后，系统可向应用发起功能调用，例如缓存清理、导航、路线规划等

## 配置示例

参考应用链接（[Deep Linking](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/application-models/deep-linking-startup.md)、[App Linking](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/application-models/app-linking-startup.md)）的配置要求进行URI配置，最后在URI配置中指定相对应的linkFeature即可。

下面以授权登录场景举例说明：

```json
    "uris": [
        {
            "scheme": "xxx",
            "host": "xxx.xxx.xxx",
            "path": "xxx/xxxx",
            "linkFeature": "Login" 
        }
    ]
```

标准化应用功能**linkFeature**的枚举定义。

|名称|值|说明|
|---|---|---|
|登录|Login|指示登录、授权登录等功能|
|支付|Pay|指示支付页面、收银台等功能|
|分享|Share|指示分享功能|
|缓存清理|AppStorageMgmt|指示清理应用沙箱目录中缓存数据的功能|
|扫码|ScanCode|指示扫码功能|
|打开本地文件|FileOpen|指示打开处理文件的功能|
|导航|Navigation|指示导航功能|
|路线规划|RoutePlan|指示路线规划功能|
|地点搜索|PlaceSerach|指示地点搜索功能|