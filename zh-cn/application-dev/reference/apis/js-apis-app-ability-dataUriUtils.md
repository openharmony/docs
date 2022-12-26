# @ohos.app.ability.dataUriUtils (DataUriUtils模块)

DataUriUtils模块提供用于处理uri对象的能力，包括获取、绑定、删除和更新指定uri对象的路径末尾的ID。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import dataUriUtils from '@ohos.app.ability.dataUriUtils';
```

## dataUriUtils.getId

getId(uri: string): number

获取指定uri路径末尾的ID。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称 | 类型   | 必填 | 描述                        |
| ---- | ------ | ---- | --------------------------- |
| uri  | string | 是   | 表示uri对象。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| number | 返回uri路径末尾的ID。 |

**示例：**

```ts
try {
    var id = dataUriUtils.getId("com.example.dataUriUtils/1221")
    console.info('get id: ' + id)
} catch(err) {
    console.error('get id err ,check the uri' + err)
}
```



## dataUriUtils.attachId

attachId(uri: string, id: number): string

将ID附加到uri的路径末尾。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称 | 类型   | 必填 | 描述                        |
| ---- | ------ | ---- | --------------------------- |
| uri  | string | 是   | 表示uri对象。 |
| id   | number | 是   | 表示要附加的ID。            |

**返回值：**

| 类型   | 说明                  |
| ------ | --------------------- |
| string | 返回附加ID之后的uri对象。 |

**示例：**

```ts
var id = 1122;
try {
    var uri = dataUriUtils.attachId(
        "com.example.dataUriUtils",
        id,
    )
    console.info('attachId the uri is: ' + uri)
} catch (err) {
    console.error('get id err ,check the uri' + err)
}

```



## dataUriUtils.deleteId

deleteId(uri: string): string

删除指定uri路径末尾的ID。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称 | 类型   | 必填 | 描述                        |
| ---- | ------ | ---- | --------------------------- |
| uri  | string | 是   | 表示要从中删除ID的uri对象。 |

**返回值：**

| 类型   | 说明                |
| ------ | ------------------- |
| string | 返回删除ID之后的uri对象。 |

**示例：**

```ts
try {
    var uri = dataUriUtils.deleteId("com.example.dataUriUtils/1221")
    console.info('delete id with the uri is: ' + uri)
} catch(err) {
    console.error('delete uri err, check the input uri' + err)
}

```



## dataUriUtils.updateId

updateId(uri: string, id: number): string

更新指定uri中的ID。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称 | 类型   | 必填 | 描述                |
| ---- | ------ | ---- | ------------------- |
| uri  | string | 是   | 表示uri对象 |
| id   | number | 是   | 表示要更新的ID            |

**返回值：**

| 类型   | 说明            |
| ------ | --------------- |
| string | 返回更新ID之后的uri对象。 |

**示例：**

```ts

try {
    var id = 1122;
    var uri = dataUriUtils.updateId(
        "com.example.dataUriUtils/1221",
        id
    )
} catch (err) {
    console.error('delete uri err, check the input uri' + err)
}
```

