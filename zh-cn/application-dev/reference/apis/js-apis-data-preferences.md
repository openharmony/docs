# 首选项

首选项为应用提供key-value键值型的数据处理能力，支持应用持久化轻量级数据，并对其修改和查询。数据存储形式为键值对，键的类型为字符串型，值的存储数据类型包括数字型、字符型、布尔型。


> **说明：**
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import preferences from '@ohos.data.preferences';
```

## 常量

**系统能力：** 以下各项对应的系统能力均为SystemCapability.DistributedDataManager.Preferences.Core

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| MAX_KEY_LENGTH | string | 是 | 否 | key的最大长度限制，需小于80字节。 |
| MAX_VALUE_LENGTH | string | 是 | 否 | value的最大长度限制，需小于8192字节。 |


## preferences.getPreferences

getPreferences(context: Context, name: string, callback: AsyncCallback&lt;Preferences&gt;): void

读取指定首选项持久化文件，将数据加载到Preferences实例，用于数据操作，该方法使用callback方式作为异步方法。


**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | context | [Context](js-apis-ability-context.md) | 是 | 应用程序或功能的上下文。 |
  | name | string | 是 | 应用程序内部数据存储名称。 |
  | callback | AsyncCallback&lt;[Preferences](#preferences)&gt; | 是 | 回调函数。 |

**示例：**
```ts
preferences.getPreferences(this.context, 'mystore', function (err, pref) {
    if (err) {
        console.info("Get preferences failed.")
        return;
    }
    console.info("Get preferences successfully.")
})
```


## preferences.getPreferences

getPreferences(context: Context, name: string): Promise&lt;Preferences&gt;

读取指定首选项持久化文件，将数据加载到Preferences实例，用于数据操作，该方法使用Promise方式作为异步方法。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | context | [Context](js-apis-ability-context.md) | 是 | 应用程序或功能的上下文。 |
  | name | string | 是 | 应用程序内部数据存储名称。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[Preferences](#preferences)&gt; | Promise实例，用于异步获取结果。 |

**示例：**
```ts
let promise = preferences.getPreferences(this.context, 'mystore')
promise.then((pref) => {
    console.info("Get preferences successfully.")
}).catch((err) => {
    console.info("Get preferences failed.")
})
```


## preferences.deletePreferences

deletePreferences(context: Context, name: string, callback: AsyncCallback&lt;void&gt;): void

从内存中移除指定首选项持久化文件对应的Preferences单实例，并删除指定文件及其备份文件和损坏文件。
删除指定首选项持久化文件时，应用不允许再使用该实例进行数据操作，否则会出现数据一致性问题，该方法使用callback方式作为异步方法。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | context | [Context](js-apis-ability-context.md) | 是 | 应用程序或功能的上下文。 |
  | name | string | 是 | 应用程序内部数据存储名称。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

**示例：**
```ts
preferences.deletePreferences(this.context, 'mystore', function (err) {
    if (err) {
        console.info("Deleted preferences failed, err: " + err)
        return
    }
    console.info("Deleted preferences successfully.")
})
```


## preferences.deletePreferences

deletePreferences(context: Context, name: string): Promise&lt;void&gt;

从内存中移除指定首选项持久化文件对应的Preferences单实例，并删除指定文件及其备份文件和损坏文件。
删除指定首选项持久化文件时，应用不允许再使用该实例进行数据操作，否则会出现数据一致性问题，该方法使用Promise方式作为异步方法。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | context | [Context](js-apis-ability-context.md) | 是 | 应用程序或功能的上下文。 |
  | name | string | 是 | 应用程序内部数据存储名称。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise实例，用于异步获取结果。 |

**示例：**
```ts
let promise = preferences.deletePreferences(this.context, 'mystore')
promise.then(() => {
    console.info("Deleted preferences successfully.")
}).catch((err) => {
    console.info("Deleted preferences failed, err: " + err)
})
```


## preferences.removePreferencesFromCache

removePreferencesFromCache(context: Context, name: string, callback: AsyncCallback&lt;void&gt;): void

从内存中移除指定首选项持久化文件对应的Preferences单实例。

移除Preferences单实例时，应用不允许再使用该实例进行数据操作，否则会出现数据一致性问题，该方法使用callback方式作为异步方法。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | context | [Context](js-apis-ability-context.md) | 是 | 应用程序或功能的上下文。 |
  | name | string | 是 | 应用程序内部数据存储名称。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

**示例：**
```ts
preferences.removePreferencesFromCache(this.context, 'mystore', function (err) {
    if (err) {
        console.info("Removed preferences from cache failed, err: " + err)
        return
    }
    console.info("Removed preferences from cache successfully.")
})
```


## preferences.removePreferencesFromCache

removePreferencesFromCache(context: Context, name: string): Promise&lt;void&gt;

从内存中移除指定首选项持久化文件对应的Preferences单实例。

移除Preferences单实例时，应用不允许再使用该实例进行数据操作，否则会出现数据一致性问题，该方法使用Promise方式作为异步方法。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | context | [Context](js-apis-ability-context.md) | 是 | 应用程序或功能的上下文。 |
  | name | string | 是 | 应用程序内部数据存储名称。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise实例，用于异步获取结果。 |

**示例：**
```ts
let promise = preferences.removePreferencesFromCache(this.context, 'mystore')
promise.then(() => {
    console.info("Removed preferences from cache successfully.")
}).catch((err) => {
    console.info("Removed preferences from cache failed, err: " + err)
})
```


## Preferences

提供获取和修改存储数据的接口。


### get

get(key: string, defValue: ValueType, callback: AsyncCallback&lt;ValueType&gt;): void

获取键对应的值，如果值为null或者非默认值类型，返回默认数据，该方法使用callback方式作为异步方法。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | key | string | 是 | 要获取的存储key名称，不能为空。 |
  | defValue | [ValueType](#valuetype) | 是 | 默认返回值。支持number、string、boolean。 |
  | callback | AsyncCallback&lt;ValueType&gt; | 是 | 回调函数。 |

**示例：**
```ts
pref.get('startup', 'default', function(err, value) {
    if (err) {
        console.info("Get value of startup failed, err: " + err)
        return
    }
    console.info("Get value of startup is " + value)
})
```


### get

get(key: string, defValue: ValueType): Promise&lt;ValueType&gt;

获取键对应的值，如果值为null或者非默认值类型，返回默认数据，该方法使用Promise方式作为异步方法。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

- **参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | key | string | 是 | 要获取的存储key名称，不能为空。 |
  | defValue | [ValueType](#valuetype) | 是 | 默认返回值。支持number、string、boolean。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;ValueType&gt; | Promise实例，用于异步获取结果。 |

**示例：**
```ts
let promise = pref.get('startup', 'default')
promise.then((value) => {
    console.info("Get value of startup is " + value)
}).catch((err) => {
    console.info("Get value of startup failed, err: " + err)
})
```

### getAll

getAll(callback: AsyncCallback&lt;Object&gt;): void;

返回含有所有键值的Object对象。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;Object&gt; | 是 | 回调函数。返回含有所有键值的Object对象。 |

**示例：**
```ts
pref.getAll(function (err, value) {
    if (err) {
        console.info("getAll failed, err: " + err)
        return
    }
    let keys = Object.keys(value)
    console.info('getAll keys = ' + keys)
    console.info("getAll object = " + JSON.stringify(value))
});
```


### getAll

getAll(): Promise&lt;Object&gt;

返回含有所有键值的Object对象。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;Object&gt; | Promise对象。返回含有所有键值的Object对象。 |

**示例：**
```ts
let promise = pref.getAll()
promise.then((value) => {
    let keys = Object.keys(value)
    console.info('getAll keys = ' + keys)
    console.info("getAll object = " + JSON.stringify(value))
}).catch((err) => {
    console.info("getAll failed, err: " + err)
})
```

### put

put(key: string, value: ValueType, callback: AsyncCallback&lt;void&gt;): void

首先获取指定首选项持久化文件对应的Preferences实例，然后借助Preferences API将数据写入Preferences实例，通过flush或者flushSync将Preferences实例持久化，该方法使用callback方式作为异步方法。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | key | string | 是 | 要修改的存储的key，不能为空。 |
  | value | [ValueType](#valuetype) | 是 | 存储的新值。支持number、string、boolean。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

**示例：**
```ts
pref.put('startup', 'auto', function (err) {
    if (err) {
        console.info("Put value of startup failed, err: " + err)
        return
    }
    console.info("Put value of startup successfully.")
})
```


### put

put(key: string, value: ValueType): Promise&lt;void&gt;

首先获取指定首选项持久化文件对应的Preferences实例，然后借助Preferences API将数据写入Preferences实例，通过flush或者flushSync将Preferences实例持久化，该方法使用Promise方式作为异步方法。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | key | string | 是 | 要修改的存储的key，不能为空。 |
  | value | [ValueType](#valuetype) | 是 | 存储的新值。支持number、string、boolean。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise实例，用于异步处理。 |

**示例：**
```ts
let promise = pref.put('startup', 'auto')
promise.then(() => {
    console.info("Put value of startup successfully.")
}).catch((err) => {
    console.info("Put value of startup failed, err: " + err)
})
```


### has

has(key: string, callback: AsyncCallback&lt;boolean&gt;): void

检查存储对象是否包含名为给定key的存储键值对，该方法使用callback方式作为异步方法。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | key | string | 是 | 要检查的存储key名称，不能为空。 |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。返回存储对象是否包含给定key的存储键值对，true表示存在，false表示不存在。 |

**示例：**
```ts
pref.has('startup', function (err, isExist) {
    if (err) {
        console.info("Check the key of startup failed, err: " + err)
        return
    }
    if (isExist) {
        console.info("The key of startup is contained.")
    } else {
        console.info("The key of startup dose not contain.")
    }
})
```


### has

has(key: string): Promise&lt;boolean&gt;

检查存储对象是否包含名为给定key的存储键值对，该方法使用Promise方式作为异步方法。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | key | string | 是 | 要检查的存储key名称，不能为空。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise对象。返回存储对象是否包含给定key的存储键值对，true表示存在，false表示不存在。 |

**示例：**
```ts
let promise = pref.has('startup')
promise.then((isExist) => {
    if (isExist) {
        console.info("The key of startup is contained.")
    } else {
        console.info("The key of startup dose not contain.")
    }
}).catch((err) => {
    console.info("Check the key of startup failed, err: " + err)
})
```


### delete

delete(key: string, callback: AsyncCallback&lt;void&gt;): void

从存储对象中删除名为给定key的存储键值对，该方法使用callback方式作为异步方法。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | key | string | 是 | 要删除的存储key名称，不能为空。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

**示例：**
```ts
pref.delete('startup', function (err) {
    if (err) {
        console.info("Delete startup key failed, err: " + err)
        return
    }
    console.info("Deleted startup key successfully.")
})
```


### delete

delete(key: string): Promise&lt;void&gt;

从存储对象删除名为给定key的存储键值对，该方法使用Promise方式作为异步方法。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | key | string | 是 | 要删除的存储key名称，不能为空。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise实例，用于异步处理。 |

**示例：**
```ts
let promise = pref.delete('startup')
promise.then(() => {
    console.info("Deleted startup key successfully.")
}).catch((err) => {
    console.info("Delete startup key failed, err: " + err)
})
```


### flush

flush(callback: AsyncCallback&lt;void&gt;): void

将当前preferences对象中的修改保存到当前的preferences，并异步存储到首选项持久化文件中，该方法使用callback方式作为异步方法。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

**示例：**
```ts
pref.flush(function (err) {
    if (err) {
        console.info("Flush to file failed, err: " + err)
        return
    }
    console.info("Flushed to file successfully.")
})
```


### flush

flush(): Promise&lt;void&gt;

将当前preferences对象中的修改保存到当前的preferences，并异步存储到首选项持久化文件中，该方法使用Promise方式作为异步方法。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise实例，用于异步处理。 |

**示例：**
```ts
let promise = pref.flush()
promise.then(() => {
    console.info("Flushed to file successfully.")
}).catch((err) => {
    console.info("Flush to file failed, err: " + err)
})
```


### clear

clear(callback: AsyncCallback&lt;void&gt;): void

清除此存储对象中的所有存储，该方法使用callback方式作为异步方法。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

**示例：**
```ts
pref.clear(function (err) {
    if (err) {
        console.info("Clear to file failed, err: " + err)
        return
    }
    console.info("Cleared to file successfully.")
})
```


### clear

clear(): Promise&lt;void&gt;

清除此存储对象中的所有存储，该方法使用Promise方式作为异步方法。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise实例，用于异步处理。 |

**示例：**
```ts
let promise = pref.clear()
promise.then(() => {
    console.info("Cleared to file successfully.")
}).catch((err) => {
    console.info("Clear to file failed, err: " + err)
})
```


### on('change')

on(type: 'change', callback: Callback&lt;{ key : string }&gt;): void

订阅数据变更者类，订阅的key的值发生变更后，在执行flush方法后，callback方法会被回调。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 |  事件类型，固定值'change'，表示数据变更。 |
  | callback | Callback&lt;{ key : string }&gt;  | 是| 回调对象实例。 |

**示例：**
```ts
var observer = function (key) {
    console.info("The key of " + key + " changed.")
}

pref.on('change', observer)
pref.put('startup', 'auto', function (err) {
    if (err) {
        console.info("Put the value of startup failed, err: " + err)
        return
    }
    console.info("Put the value of startup successfully.")

    pref.flush(function (err) {
        if (err) {
            console.info("Flush to file failed, err: " + err)
            return
        }
        console.info("Flushed to file successfully.")    // observer will be called.
    })
})
```


### off('change')

off(type: 'change', callback?: Callback&lt;{ key : string }&gt;): void

当不再进行订阅数据变更时，使用此接口取消订阅。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 事件类型，固定值'change'，表示数据变更。 |
  | callback | Callback&lt;{ key : string }&gt;  | 否| 需要取消的回调对象实例，不填则全部取消。 |

**示例：**
```ts
var observer = function (key) {
    console.info("The key of " + key + " changed.")
}

pref.on('change', observer)
pref.put('startup', 'auto', function (err) {
    if (err) {
        console.info("Put the value of startup failed, err: " + err)
        return
    }
    console.info("Put the value of startup successfully.")

    pref.flush(function (err) {
        if (err) {
            console.info("Flush to file failed, err: " + err)
            return
        }
        console.info("Flushed to file successfully.")    // observer will be called.
        pref.off('change', observer)
    })
})
```

## ValueType

用于表示允许的数据字段类型。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

| 名称          | 说明                   |
| ------------- | ---------------------- |
| number        | 表示值类型为数字。     |
| string        | 表示值类型为字符。     |
| boolean       | 表示值类型为布尔值。   |
| Array<number> | 表示值类型为数字数组。 |
| Array<string> | 表示值类型为字符数组。 |
| Array<bool>   | 表示值类型为布尔数组。 |
