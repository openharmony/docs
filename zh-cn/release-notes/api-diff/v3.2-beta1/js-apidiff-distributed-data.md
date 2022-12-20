# 分布式数据管理子系统JS API变更

OpenHarmony 3.2 Beta1版本相较于OpenHarmony 3.1 Release版本，分布式数据管理子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.data.preferences | preferences | const MAX_VALUE_LENGTH: 8192; | 新增 |
| ohos.data.preferences | preferences | const MAX_KEY_LENGTH: 80; | 新增 |
| ohos.data.preferences | Preferences | off(type: 'change', callback?: Callback\<{ key: string }>): void; | 新增 |
| ohos.data.preferences | Preferences | on(type: 'change', callback: Callback\<{ key: string }>): void; | 新增 |
| ohos.data.preferences | Preferences | flush(callback: AsyncCallback\<void>): void;<br>flush(): Promise\<void>; | 新增 |
| ohos.data.preferences | Preferences | clear(callback: AsyncCallback\<void>): void;<br>clear(): Promise\<void>; | 新增 |
| ohos.data.preferences | Preferences | delete(key: string, callback: AsyncCallback\<void>): void;<br>delete(key: string): Promise\<void>; | 新增 |
| ohos.data.preferences | Preferences | put(key: string, value: ValueType, callback: AsyncCallback\<void>): void;<br>put(key: string, value: ValueType): Promise\<void>; | 新增 |
| ohos.data.preferences | Preferences | has(key: string, callback: AsyncCallback\<boolean>): void;<br>has(key: string): Promise\<boolean>; | 新增 |
| ohos.data.preferences | Preferences | getAll(callback: AsyncCallback\<Object>): void;<br>getAll(): Promise\<Object>; | 新增 |
| ohos.data.preferences | Preferences | get(key: string, defValue: ValueType, callback: AsyncCallback\<ValueType>): void;<br>get(key: string, defValue: ValueType): Promise\<ValueType>; | 新增 |
| ohos.data.preferences | preferences | removePreferencesFromCache(context: Context, name: string, callback: AsyncCallback\<void>): void;<br>removePreferencesFromCache(context: Context, name: string): Promise\<void>; | 新增 |
| ohos.data.preferences | preferences | deletePreferences(context: Context, name: string, callback: AsyncCallback\<void>): void;<br>deletePreferences(context: Context, name: string): Promise\<void>; | 新增 |
| ohos.data.preferences | preferences | getPreferences(context: Context, name: string, callback: AsyncCallback\<Preferences>): void;<br>getPreferences(context: Context, name: string): Promise\<Preferences>; | 新增 |
| ohos.data.storage | storage | const MAX_VALUE_LENGTH: 8192; | 废弃 |
| ohos.data.storage | storage | const MAX_KEY_LENGTH: 80; | 废弃 |
| ohos.data.storage | StorageObserver | key: string; | 废弃 |
| ohos.data.storage | Storage | off(type: 'change', callback: Callback\<StorageObserver>): void; | 废弃 |
| ohos.data.storage | Storage | on(type: 'change', callback: Callback\<StorageObserver>): void; | 废弃 |
| ohos.data.storage | Storage | flush(callback: AsyncCallback\<void>): void;<br>flush(): Promise\<void>; | 废弃 |
| ohos.data.storage | Storage | flushSync(): void; | 废弃 |
| ohos.data.storage | Storage | clear(callback: AsyncCallback\<void>): void;<br>clear(): Promise\<void>; | 废弃 |
| ohos.data.storage | Storage | clearSync(): void; | 废弃 |
| ohos.data.storage | Storage | delete(key: string, callback: AsyncCallback\<void>): void;<br>delete(key: string): Promise\<void>; | 废弃 |
| ohos.data.storage | Storage | deleteSync(key: string): void; | 废弃 |
| ohos.data.storage | Storage | put(key: string, value: ValueType, callback: AsyncCallback\<void>): void;<br>put(key: string, value: ValueType): Promise\<void>; | 废弃 |
| ohos.data.storage | Storage | putSync(key: string, value: ValueType): void; | 废弃 |
| ohos.data.storage | Storage | has(key: string, callback: AsyncCallback\<boolean>): boolean;<br>has(key: string): Promise\<boolean>; | 废弃 |
| ohos.data.storage | Storage | hasSync(key: string): boolean; | 废弃 |
| ohos.data.storage | Storage | get(key: string, defValue: ValueType, callback: AsyncCallback\<ValueType>): void;<br>get(key: string, defValue: ValueType): Promise\<ValueType>; | 废弃 |
| ohos.data.storage | Storage | getSync(key: string, defValue: ValueType): ValueType; | 废弃 |
| ohos.data.storage | storage | removeStorageFromCache(path: string, callback: AsyncCallback\<void>): void;<br>removeStorageFromCache(path: string): Promise\<void>; | 废弃 |
| ohos.data.storage | storage | removeStorageFromCacheSync(path: string): void; | 废弃 |
| ohos.data.storage | storage | deleteStorage(path: string, callback: AsyncCallback\<void>): void;<br>deleteStorage(path: string): Promise\<void>; | 废弃 |
| ohos.data.storage | storage | deleteStorageSync(path: string): void; | 废弃 |
| ohos.data.storage | storage | getStorage(path: string, callback: AsyncCallback\<Storage>): void;<br>getStorage(path: string): Promise\<Storage>; | 废弃 |
| ohos.data.storage | storage | getStorageSync(path: string): Storage; | 废弃 |

