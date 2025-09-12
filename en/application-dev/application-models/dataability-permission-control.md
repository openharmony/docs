# DataAbility Permission Control
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @xialiangwei-->
<!--Designer: @jsjzju-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->


The DataAbility uses permission control to determine whether an ability can access the data service it provides. There are static and dynamic permission controls.


## Static Permission Control

The DataAbility functions as the server. When being started, the DataAbility verifies the client permissions against the settings of the optional fields **readPermission**, **writePermission**, and **Permission** fields in the **config.json** file. The following is an example:


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

The client permission is configured in **reqPermissions** under **module** in the **config.json** file. The following is an example:


```json
{
  ...
  "module": {
    ...
    "reqPermissions": [
      {
        "name": "ohos.permission.READ_CONTACTS"
      },
      {
        "name": "ohos.permission.WRITE_CONTACTS"
      },
      ...
    ],
    ...
  }
}
```


## Dynamic Permission Control

Static permission control determines whether a DataAbility can be started by another ability or application. It does not verify the permission of each read/write interface.

Dynamic permission control verifies whether the client has the corresponding permission for every read/write interface. The table below lists the permissions required for calling these interfaces.

**Table 1** Permission configuration for data read/write interfaces

| Interface with the Read Permission| Interface with the Write Permission| Interface with the Read/Write Permission Based on Actual Requirements|
| -------- | -------- | -------- |
| query, normalizeUri, denormalizeUri, openfile (with **mode** set to **'r'**)| insert, batchInsert, delete, update, openfile (with **mode** set to **'w'**)| executeBatch |

For interfaces that require the read permission, the server must have **readPermission** specified, and the client must obtain the read permission before calling them.

For interfaces that require the write permission, the server must have **writePermission** specified, and the client must obtain the write permission before calling them.
