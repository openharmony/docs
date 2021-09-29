### DataUriUtils模块(JS端SDK接口)

#### 支持设备

| API                                            | 手机 | 平板 | 智慧屏 | 智能穿戴 | 轻量级智能穿戴 | 智慧视觉设备 |
| ---------------------------------------------- | ---- | ---- | ------ | -------- | -------------- | ------------ |
| DataUriUtils.getId(uri: string)                | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |
| DataUriUtils.attachId(uri: string, id: number) | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |
| DataUriUtils.deleteId(uri: string)             | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |
| DataUriUtils.updateId(uri: string, id: number) | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |

#### 权限列表

ohos.permission.RUNNING_LOCK permission

#### 导入模块

```js
import notify from '@ohos.ability.dataUriUtils';
```

#### DataUriUtils.getId(uri: string)

- 接口说明

  获取附加到给定uri的路径组件末尾的ID

- 参数描述


| 名称 | 读写属性 | 类型   | 必填 | 描述                      |
| ---- | -------- | ------ | ---- | ------------------------- |
| uri  | 只读     | string | 是   | 指示要从中获取ID的uri对象 |

- 返回值

  附加到路径组件末尾的ID

- 示例

```js
import dataUriUtils from '@ohos.ability.datauriutils'
dataUriUtils.getIdSync("com.example.dataUriUtils/1221")
```



#### DataUriUtils.attachId(uri: string, id: number)  

- 接口说明

  将给定ID附加到给定uri的路径组件的末尾

- 参数描述


| 名称 | 读写属性 | 类型   | 必填 | 描述                      |
| ---- | -------- | ------ | ---- | ------------------------- |
| uri  | 只读     | string | 是   | 指示要从中获取ID的uri对象 |
| id   | 只读     | number | 是   | 指示要附加的ID            |

- 返回值

  附加给定ID的uri对象

- 示例

```js
import dataUriUtils from '@ohos.ability.datauriutils'
var idint = 1122;
dataUriUtils.attachId(
    "com.example.dataUriUtils"
	idint,
)
```



#### DataUriUtils.deleteId(uri: string)

- 接口说明

  从给定uri的路径组件的末尾删除ID

- 参数描述

  | 名称 | 读写属性 | 类型   | 必填 | 描述                      |
  | ---- | -------- | ------ | ---- | ------------------------- |
  | uri  | 只读     | string | 是   | 指示要从中删除ID的uri对象 |

- 返回值

  ID已删除的uri对象

- 示例

```js
import dataUriUtils from '@ohos.ability.datauriutils'
dataUriUtils.deleteId("com.example.dataUriUtils/1221")
```



#### DataUriUtils.updateId(uri: string, id: number) 

- 接口说明 

  更新指定uri中的ID

- updateId参数描述

  | 名称 | 读写属性 | 类型   | 必填 | 描述                |
  | ---- | -------- | ------ | ---- | ------------------- |
  | uri  | 只读     | string | 是   | 指示要更新的uri对象 |
  | id   | 只读     | number | 是   | 指示新ID            |

- 返回值

  更新的uri对象

- 示例

```js
import dataUriUtils from '@ohos.ability.datauriutils'
var idint = 1122;
dataUriUtils.updateId(
    "com.example.dataUriUtils"
	idint,
)
```

