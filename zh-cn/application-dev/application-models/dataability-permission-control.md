# DataAbility权限控制
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @xialiangwei-->
<!--Designer: @jsjzju-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->


DataAbility提供数据服务，并不是所有的Ability都有权限读写它，DataAbility有一套权限控制机制来保证数据安全。分为静态权限控制和动态权限控制两部分。


## 静态权限控制

DataAbility作为服务端，在被拉起的时候，会根据config.json里面配置的权限来进行校验，有"readPermission"、"writePermission"和"Permission"三个配置项，可以不配或者为空。示例如下:


```json
"abilities": [
  // ...
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
  // ...
]
```

客户端在拉起DataAbility的时候，需要校验客户端是否有权限拉起该DataAbility。客户端的权限配置在config.json配置文件的"module"对象的"reqPermissions"对象中，示例如下：


```json
{
  // ...
  "module": {
    // ...
    "reqPermissions": [
      {
        "name": "ohos.permission.READ_CONTACTS"
      },
      {
        "name": "ohos.permission.WRITE_CONTACTS"
      },
      // ...
    ],
    // ...
  }
}
```


## 动态权限控制

静态权限校验只能控制某个DataAbility是否能被另一个Ability或应用拉起，无法精确校验每个读写接口的权限，因为拉起DataAbility的时候，还不知道应用是否需要读写它的数据。

动态权限控制是校验每个数据操作的接口是否有对应的权限。客户端调用数据操作接口所需的权限如下表所示。

  **表1** 接口对应的读写权限配置

| 需要配置读权限的接口 | 需要配置写权限的接口 | 据实际操作配置读写权限的接口 |
| -------- | -------- | -------- |
| query、normalizeUri、denormalizeUri、openfile（传入mode有'r'） | insert、batchInsert、delete、update、openfile（传入mode有'w'） | executeBatch |

对于需要配置读权限的接口，服务端需要配置readPermission，客户端必须申请相应的读权限才能调用相关的接口。

对于需要配置写权限的接口，服务端需要配置writePermission，客户端必须申请相应的写权限才能调用相关的接口。
