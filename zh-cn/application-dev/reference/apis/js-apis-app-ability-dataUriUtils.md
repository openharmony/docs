# DataUriUtils模块

DataUriUtils模块提供用于处理使用DataAbilityHelper方案的对象的实用程序类的能力，包括获取，添加，更新给定uri的路径末尾的ID。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import dataUriUtils from '@ohos.app.ability.dataUriUtils';
```

## dataUriUtils.getId

getId(uri: string): number

获取附加到给定uri的路径末尾的ID。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称 | 类型   | 必填 | 描述                        |
| ---- | ------ | ---- | --------------------------- |
| uri  | string | 是   | 指示要从中获取ID的uri对象。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| number | 附加到uri路径末尾的ID。 |

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

将给定ID附加到给定uri的路径末尾。可用于生成新的uri。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称 | 类型   | 必填 | 描述                        |
| ---- | ------ | ---- | --------------------------- |
| uri  | string | 是   | 指示要从中获取ID的uri对象。 |
| id   | number | 是   | 指示要附加的ID。            |

**返回值：**

| 类型   | 说明                  |
| ------ | --------------------- |
| string | 附加给定ID的uri对象。 |

**示例：**

```ts
var idint = 1122;
try {
    var uri = dataUriUtils.attachId(
        "com.example.dataUriUtils",
        idint,
    )
    console.info('attachId the uri is: ' + uri)
} catch (err) {
    console.error('get id err ,check the uri' + err)
}

```



## dataUriUtils.deleteId

deleteId(uri: string): string

从给定uri的路径的末尾删除ID。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称 | 类型   | 必填 | 描述                        |
| ---- | ------ | ---- | --------------------------- |
| uri  | string | 是   | 指示要从中删除ID的uri对象。 |

**返回值：**

| 类型   | 说明                |
| ------ | ------------------- |
| string | ID已删除的uri对象。 |

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
| uri  | string | 是   | 指示要更新的uri对象。 |
| id   | number | 是   | 指示新ID。            |

**返回值：**

| 类型   | 说明            |
| ------ | --------------- |
| string | 更新的uri对象。 |

**示例：**

```ts

try {
    var idint = 1122;
    var uri = dataUriUtils.updateId(
        "com.example.dataUriUtils",
        idint
    )
} catch (err) {
    console.error('delete uri err, check the input uri' + err)
}
```

