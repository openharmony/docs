# app对象内部结构


app对象包含应用全局配置信息，内部结构如下：

**表1** **app对象内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| bundleName | 标识应用的Bundle名称，用于标识应用的唯一性。Bundle名称是由字母、数字、下划线（_）和点号（.）组成的字符串，必须以字母开头。支持的字符串长度为7~128字节。Bundle名称通常采用反向域名形式表示（例如，"com.example.myapplication"）。建议第一级为域名后缀"com"，第二级为厂商/个人名，也可以采用多级。 | 字符串 | 不可缺省。 |
| vendor | 标识对应用开发厂商的描述。字符串长度不超过255字节。 | 字符串 | 可缺省，缺省值为空。 |
|version | 标识应用的版本信息。 | 对象 | 不可缺省。 |
| apiVersion | 标识应用程序所依赖的操作系统&nbsp;API版本。 | 对象 | 可缺省，缺省值为空。 |
| smartWindowSize | 标识应用在模拟器中运行时使用的屏幕尺寸。 | 字符串 | 可缺省，缺省值为空。 |
| smartWindowDeviceType | 标识应用在模拟器中运行时可以模拟的设备。 | 字符串数组 | 可缺省，缺省值为空。 |
| asanEnabled |   标识应用程序是否开启asan检测，用于辅助定位buffer越界造成的crash问题。<br/>-&nbsp;true：当前工程开启asan检测。<br/>-&nbsp;false：当前工程不开启asan检测。 | 布尔值 | 可缺省，缺省值false。 |

## version对象内部结构

**表2** **version对象内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| name | 标识应用的版本号，用于向应用的终端用户呈现。取值可以自定义，长度不超过127字节。自定义规则如下：API5及更早的版本：推荐使用三段数字版本号（也兼容两段式版本号），如A.B.C(也兼容A.B)，其中A、B、C取值为0-999范围内的整数。除此之外不支持其他格式。<br/>A段，一般表示主版本号(Major)。<br/>B段，一般表示次版本号(Minor)。<br/>C段，一般表示修订版本号(Patch)。API6版本起：推荐采用四段式数字版本号，如A.B.C.D，其中A、B、C取值为0-99范围内的整数，D的取值为0-999范围内的整数。<br/>A段，一般表示主版本号(Major)。<br/>B段，一般表示次版本号(Minor)。<br/>C段，一般表示特性版本号(Feature)。<br/>D段，一般表示修订版本号(Patch)。 | 数值 | 不可缺省。 |
| code | 标识应用的版本号，仅用于操作系统管理该应用，不对应用的终端用户呈现。取值规则如下：API5及更早版本：二进制32位以内的非负整数，需要从version.name的值转换得到。转换规则为：code值=A&nbsp;\*&nbsp;1,000,000&nbsp;+&nbsp;B&nbsp;\*&nbsp;1,000&nbsp;+&nbsp;C例如，version.name字段取值为2.2.1，则code值为2002001。API6版本起：code的取值不与version.name字段的取值关联，开发者可自定义code取值，取值范围为2^31以内的非负整数，但是每次应用版本的更新，均需要更新code字段的值，新版本code取值必须大于旧版本code的值。 | 数值 | 不可缺省。 |
| minCompatibleVersionCode | 标识应用可兼容的最低版本号，用于跨设备场景下，判断其他设备上该应用的版本是否兼容。格式与version.code字段的格式要求相同。 | 数值 | 可缺省，缺省值为code标签值。 |

## apiVersion内部结构

**表3** **apiVersion内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| compatible | 运行应用所需要的最低API版本，取值范围为0~2147483647。 | 数值 | 配置在build.profile中，打包时由IDE填充到config.json中。 |
| target | 用于标识应用运行时使用的API版本，取值范围为0~2147483647。 | 数值 | 配置在build.profile中，打包时由IDE填充到config.json中。 |
| releaseType | 用于标识应用运行时SDK的状态。<br/>canary：面向特定开发者早期预览版本，不承诺质量，不承诺API稳定。<br/>beta：公开发布的Beta版本，早期Beta版本不承诺API稳定，经历若干次发布后，通过Release&nbsp;Notes对开发者声明该Beta版本为API稳定里程碑，后续版本的API冻结。<br/>release：正式发布版本，承诺质量，API不可变更。当版本处于此状态时版本号中不呈现Stage字段。 | 字符串 | 配置在build.profile中，打包时由IDE填充到config.json中。 |

app对象示例

```json
"app": {
    "bundleName": "com.example.myapplication",
    "vendor": "example",
    "version": {
      "code": 8,
      "name": "8.0.1"
    },
    "apiVersion": {
      "compatible": 8,
      "target": 9,
      "releaseType": "Beta1"
    }
  }
```
