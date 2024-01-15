# DataAbility Configuration


## URI Introduction

A Uniform Resource Identifier (URI) is used to identify a specific data item, such as a table in the database or a file on the disk. URIs used comply with the commonly used URI standard. A URI consists of the components:

![fa-dataability-uri](figures/fa-dataability-uri.png)

- **scheme**: name of the scheme used by the DataAbility. The value is fixed at **dataability**.

- **authority**: device ID. To access data on a remote device, set this component to the ID of the remote device. To access data on the local device, leave this component empty.

- **path**: location of the specific resource to access.

- **query**: query parameters.

- **fragment**: subordinate resources to access.

Example URIs:

- Cross-device scenario: dataability://_device_id_/_com.domainname.dataability.persondata_/_person_/_10_

- Local device scenario: dataability:///_com.domainname.dataability.persondata_/_person_/_1_

> **NOTE**
>
> In the case of local-device communication, **device_id** is empty, and therefore, there are three slashes (/) after **dataability:**.


## Introduction to Certain Configuration Items

Similar to a PageAbility, a DataAbility is configured in **abilities** under **module** of the **config.json** file. The difference between a DataAbility and PageAbility lies in the **type** and **uri** fields.

**Table 1** DataAbility configuration items

| Name| Description|
| -------- | -------- |
| "name" | Ability name.|
| "type" | Type of the ability. The value **data** indicates a DataAbility.|
| "uri" | URI used for communication.|
| "visible" | Whether the ability is visible to other applications. Data sharing is allowed only when the value is **true**.|

The following is an example **config.json** file:


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

For details about the configuration items, see [Internal Structure of module](../quick-start/module-structure.md).
