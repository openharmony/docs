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
> 如果多个应用的URL配置相同，应用跳转时匹配到同多个应用，则会拉起应用选择框。为了更好的用户体验，开发者可以通过链接的path字段去区分同一域名下的不同应用，如链接‘https://www.example.com/path1’拉起目标应用1，链接‘https://www.example.com/path2’拉起目标应用2。

## linkFeature标签说明

目标应用在linkFeature字段中申明功能类型，并通过应用市场上架审核后，可以提升应用跳转体验。

1. 系统识别同类应用：当调用方拉起垂类应用（例如导航类应用）时，系统会根据linkFeature字段识别到匹配的应用，并在应用面板中展现。

2. 跳转一键返回能力：当用户从其他应用通过此应用链接跳转至您的应用的某个功能界面，若您申请为该链接配置了相应功能的linkFeature并通过系统认证，您可调用系统[一键返回能力](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextbacktocallerabilitywithresult12)，在用户确认后直接返回来源应用。例如：A应用跳转至B应用的支付功能界面，若B应用已申请了支付的linkfeature，用户在B应用内完成操作后，可无拦截一键返回A应用。


**linkFeature**的枚举定义。

|值|说明|跳转一键返回能力|系统识别同类应用|
|---|---|---|---|
|Login|指示登录、授权登录等功能|是|否|
|Pay|指示支付页面、收银台等功能|是|否|
|AppStorageMgmt|指示清理应用沙箱目录中缓存数据的功能|否|是|
|FileOpen|指示打开处理文件的功能|否|是|
|Navigation|指示导航功能|否|是|
|RoutePlan|指示路线规划功能|否|是|
|PlaceSerach|指示地点搜索功能|否|是|
|Share|指示地点搜索功能|是|否|

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
