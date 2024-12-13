# deviceConfig内部结构


deviceConfig包含设备上的应用配置信息，可以包含default、tv、car、wearable等属性。default标签内的配置适用于所有通用设备，其他设备类型如果有特殊的需求，则需要在该设备类型的标签下进行配置。

## deviceConfig对象内部结构

**表1** **deviceConfig对象内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| default | 能够使用全部系统能力的设备。 | 对象 | 可缺省，缺省值为空。 |
| tablet | 标识平板的应用配置信息。 | 对象 | 可缺省，缺省值为空。 |
| tv | 标识智慧屏特有的应用配置信息。 | 对象 | 可缺省，缺省值为空。 |
| car | 标识车机特有的应用配置信息。 | 对象 | 可缺省，缺省值为空。 |
| wearable | 标识智能穿戴特有的应用配置信息。 | 对象 | 可缺省，缺省值为空。 |


上表中各类设备对象的内部结构说明参见[deviceConfig设备对象内部结构](#deviceconfig设备对象内部结构)。

## deviceConfig设备对象内部结构

**表2** **deviceConfig设备对象内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| process | 标识应用或者Ability的进程名。如果在deviceConfig标签下配置了process标签，则该应用的所有Ability都运行在这个进程中。如果在abilities标签下也为某个Ability配置了process标签，则该Ability就运行在这个进程中。该标签最大长度为31。 | 字符串 | 可缺省，缺省值为空。 |
| keepAlive | 标识应用是否始终保持运行状态，仅支持系统应用配置，三方应用配置不生效。该标签为布尔类型，可缺省，缺省值为false，如果配置为true，应用将始终保持为运行状态，并在系统启动的时候被系统驱动起来，应用进程退出后，系统也会重新启动应用进程。 | 布尔值 | 可缺省，缺省值为false。 |
| supportBackup | 标识应用是否支持备份和恢复。如果配置为"false"，则不支持为该应用执行备份或恢复操作。 | 布尔值 | 可缺省，缺省值为false。 |
| compressNativeLibs | 在打包hap时，该字段标识libs库是否以压缩存储的方式打包到HAP。<br/>-&nbsp;true：libs库以压缩方式存储。<br/>-&nbsp;false：libs库以不压缩方式存储。<br>在应用安装时，该字段用于标识libs库是否需要解压出来（API16及之后版本支持，之前的版本均默认解压libs库）。<br/>-&nbsp;true：libs库会解压出来。<br/>-&nbsp;false：libs库不会解压出来。 | 布尔值 | 该标签可缺省，在打包hap时缺省值为false。在安装应用时，该字段未配置时默认为true。 |
| network | 标识网络安全性配置。该标签允许应用通过配置文件的安全声明来自定义其网络安全，无需修改应用代码。 | 对象 | 可缺省，缺省值为空。 |

## network对象的内部结构

**表3** **network对象的内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| cleartextTraffic | 标识是否允许应用使用明文网络流量（例如，明文HTTP）。<br/>-&nbsp;true：允许应用使用明文流量的请求。<br/>-&nbsp;false：拒绝应用使用明文流量的请求。 | 布尔值 | 可缺省，缺省值为false。 |
| securityConfig | 标识应用的网络安全配置信息。 | 对象 | 可缺省，缺省为空。 |

## securityConfig对象的内部结构

**表4** **securityConfig对象的内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| domainSettings | 标识自定义的网域范围的安全配置，支持多层嵌套，即一个domainSettings对象中允许嵌套更小网域范围的domainSettings对象。 | 对象类型 | 可缺省，缺省为空。 |

## domainSettings对象内部结构

**表5** **domainSettings对象内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| cleartextPermitted | 标识自定义的网域范围内是否允许明文流量传输。当cleartextTraffic和security同时存在时，自定义网域是否允许明文流量传输以cleartextPermitted的取值为准。<br/>-&nbsp;true：允许明文流量传输。<br/>-&nbsp;false：拒绝明文流量传输。 | 布尔类型 | 可缺省，缺省值为空。 |
| domains | 标识域名配置信息，包含两个参数：subdomains和name。<br/>-&nbsp;subdomains：表示是否包含子域名，为布尔类型。取值为"true"时，表示该规则将与相应网域及所有子网域（包括子网域的子网域）匹配；取值为"false"时，表示该规则仅适用于精确匹配项。<br/>-&nbsp;name：表示域名名称，为字符串类型。 | 对象数组 | 可缺省，缺省值为空。 |

deviceConfig示例

```json
"deviceConfig": {
  "default": {
    "process": "com.example.test.example",
    "supportBackup": false,
    "network": {
      "cleartextTraffic": true,
      "securityConfig": {
        "domainSettings": {
          "cleartextPermitted": true,
          "domains": [
            {
              "subdomains": true,
              "name": "example.ohos.com"
            }
          ]
        }
      }
    }
  }
}
```
