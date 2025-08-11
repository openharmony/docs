# DataAbility组件配置
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @xialiangwei-->
<!--SE: @jsjzju-->
<!--TSE: @lixueqing513-->


## URI介绍

DataAbility的提供方和使用方都通过URI（Uniform Resource Identifier）来标识一个具体的数据，例如数据库中的某个表或磁盘上的某个文件。此处的URI仍基于URI通用标准，格式如下：

![fa-dataability-uri](figures/fa-dataability-uri.png)

- scheme：协议方案名，固定为"dataability"，代表Data Ability所使用的协议类型。

- authority：设备ID。如果为跨设备场景，则为目标设备的ID；如果为本地设备场景，则不需要填写。

- path：资源的路径信息，代表特定资源的位置信息。

- query：查询参数。

- fragment：可以用于指示要访问的子资源。

URI示例：

- 跨设备场景：dataability://_device_id_/_com.domainname.dataability.persondata_/_person_/_10_

- 本地设备：dataability:///_com.domainname.dataability.persondata_/_person_/_1_

> **说明：**
> 本地设备的"device_id"字段为空，因此在"dataability:"后面有三个"/"。


## 部分配置项介绍

与PageAbility类似，DataAbility的相关配置在config.json配置文件的"module"对象的"abilities"对象中，与PageAbility的区别在于"type"属性及"uri"属性。

  **表1** DataAbility的部分配置项说明

| Json重要字段 | 备注说明 |
| -------- | -------- |
| "name" | Ability名称。 |
| "type" | UIAbility类型，DataAbility的类型为"data"。 |
| "uri" | 通信使用的URI。 |
| "visible" | 对其他应用是否可见，设置为true时，DataAbility才能与其他应用进行通信传输数据。 |

config.json配置样例


```json
"abilities": [
  ...
  {
    "name": ".DataAbility",
    "srcLanguage": "ets",
    "srcPath": "DataAbility",
    "icon": "$media:icon",
    "description": "$string:DataAbility_desc",
    "type": "data",
    "visible": true,
    "uri": "dataability://com.samples.famodelabilitydevelop.DataAbility",
    "readPermission": "ohos.permission.READ_CONTACTS",
    "writePermission": "ohos.permission.WRITE_CONTACTS"
  },
  ...
]
```

DataAbility支持的配置项及详细说明详见[module对象内部结构](../quick-start/module-structure.md)。
