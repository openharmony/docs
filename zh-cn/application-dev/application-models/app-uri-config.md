# 应用链接说明

## URI的基本格式

当在module.json5文件的skills中声明uris时，主要包含如下字段。其中，scheme为必选字段，其他字段仅当scheme存在时才有意义。

- scheme：协议名称。常见的取值有http、https、http、file、ftp等，也可以自定义。
- host：域名或IP地址。例如域名`developer.huawei.com`或IP地址`127.0.0.1`。
- port：端口号。例如`developer.huawei.com:80`后面的80即为端口号。
- path：路径，表示域名服务器上的目录或文件路径，该字段在scheme存在时才有意义。例如`developer.huawei.com/consumer/`中`consumer`。
- pathStartWith：路径前缀，该字段在scheme存在时才有意义，表示域名服务器上的目录或文件路径的前缀，用于前缀匹配。
- pathRegex：路径正则，该字段在scheme存在时才有意义，表示域名服务器上的目录或文件路径的正则表达式，用于正则匹配。
- linkFeature：应用的功能类型（如文件打开、分享、导航等）。取值为长度不超过127字节的字符串，不支持中文。

按照配置的字段不同，uris可以拼接为不同的表达式。

当只配置scheme，或者只配置scheme和host，或者只配置scheme、host和port时，组成的表达式如下。

- `scheme://`
- `scheme://host`
- `scheme://host:port`    

当配置了path、pathStartWith或pathRegex字段时，组成的表达式如下。path、pathStartWith或pathRegex三选一配置，如果配置了多个字段，任一字段匹配成功，则匹配结果为true。

- **全路径表达式**：`scheme://host:port/path`
- **路径前缀表达式**：`scheme://host:port/pathStartWith`
- **路径正则表达式**：`scheme://host:port/pathRegex`

> **说明：**
> 
> 如果多个应用的URL配置相同，应用跳转时匹配到同多个应用，则会拉起应用选择框。为了更好的用户体验，开发者可以通过链接的path字段去区分同一域名下的不同应用，如链接https://www.example.com/path1拉起目标应用1，链接https://www.example.com/path2拉起目标应用2。

## linkFeature标签说明

linkFeature标签为可选字段，主要用于如下两种场景：

1. 应用间跳转确认弹框体验增强：应用申明linkFeature，系统将认证申明的linkFeature与实际拉起的功能是否一致，认证通过后其他应用通过此链接拉起应用时，应用间跳转确认弹框将变为可信跳转确认样式，例如：默认选中x天不再提醒等。

2. 系统入口呈现：用户在访问系统入口（各系统垂域面板、设置等）时，系统将展示认证通过的应用功能入口；用户点击后，系统可向应用发起功能调用，例如缓存清理、导航、路线规划等

**linkFeature**的枚举定义。

|值|说明|弹框体验增强|系统入口呈现|
|---|---|---|---|
|Login|指示登录、授权登录等功能|是|否|
|Pay|指示支付页面、收银台等功能|是|否|
|AppStorageMgmt|指示清理应用沙箱目录中缓存数据的功能|否|是|
|FileOpen|指示打开处理文件的功能|否|是|
|Navigation|指示导航功能|否|是|
|RoutePlan|指示路线规划功能|否|是|
|PlaceSerach|指示地点搜索功能|否|是|

## 配置示例

参考应用链接（[Deep Linking](deep-linking-startup.md)、[App Linking](app-linking-startup.md)）的配置要求进行URI配置。

下面以授权登录场景举例说明：

```json
"uris": [
    {
        "scheme": "https",
        "host": "developer.huawei.com",
        "path": "consumer",
        "linkFeature": "Login"  
    }
]
```
