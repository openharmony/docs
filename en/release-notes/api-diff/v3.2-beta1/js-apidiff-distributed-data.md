# JS API Changes of the Distributed Data Management Subsystem

The table below lists the APIs changes of the distributed data management subsystem in OpenHarmony 3.2 Beta1 over OpenHarmony 3.1 Release.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.data.preferences | preferences | const MAX_VALUE_LENGTH: 8192; | Added|
| ohos.data.preferences | preferences | const MAX_KEY_LENGTH: 80; | Added|
| ohos.data.preferences | Preferences | off(type: 'change', callback?: Callback\<{ key: string }>): void; | Added|
| ohos.data.preferences | Preferences | on(type: 'change', callback: Callback\<{ key: string }>): void; | Added|
| ohos.data.preferences | Preferences | flush(callback: AsyncCallback\<void>): void;<br>flush(): Promise\<void>; | Added|
| ohos.data.preferences | Preferences | clear(callback: AsyncCallback\<void>): void;<br>clear(): Promise\<void>; | Added|
| ohos.data.preferences | Preferences | delete(key: string, callback: AsyncCallback\<void>): void;<br>delete(key: string): Promise\<void>; | Added|
| ohos.data.preferences | Preferences | put(key: string, value: ValueType, callback: AsyncCallback\<void>): void;<br>put(key: string, value: ValueType): Promise\<void>; | Added|
| ohos.data.preferences | Preferences | has(key: string, callback: AsyncCallback\<boolean>): void;<br>has(key: string): Promise\<boolean>; | Added|
| ohos.data.preferences | Preferences | getAll(callback: AsyncCallback\<Object>): void;<br>getAll(): Promise\<Object>; | Added|
| ohos.data.preferences | Preferences | get(key: string, defValue: ValueType, callback: AsyncCallback\<ValueType>): void;<br>get(key: string, defValue: ValueType): Promise\<ValueType>; | Added|
| ohos.data.preferences | preferences | removePreferencesFromCache(context: Context, name: string, callback: AsyncCallback\<void>): void;<br>removePreferencesFromCache(context: Context, name: string): Promise\<void>; | Added|
| ohos.data.preferences | preferences | deletePreferences(context: Context, name: string, callback: AsyncCallback\<void>): void;<br>deletePreferences(context: Context, name: string): Promise\<void>; | Added|
| ohos.data.preferences | preferences | getPreferences(context: Context, name: string, callback: AsyncCallback\<Preferences>): void;<br>getPreferences(context: Context, name: string): Promise\<Preferences>; | Added|
| ohos.data.storage | storage | const MAX_VALUE_LENGTH: 8192; | Deprecated|
| ohos.data.storage | storage | const MAX_KEY_LENGTH: 80; | Deprecated|
| ohos.data.storage | StorageObserver | key: string; | Deprecated|
| ohos.data.storage | Storage | off(type: 'change', callback: Callback\<StorageObserver>): void; | Deprecated|
| ohos.data.storage | Storage | on(type: 'change', callback: Callback\<StorageObserver>): void; | Deprecated|
| ohos.data.storage | Storage | flush(callback: AsyncCallback\<void>): void;<br>flush(): Promise\<void>; | Deprecated|
| ohos.data.storage | Storage | flushSync(): void; | Deprecated|
| ohos.data.storage | Storage | clear(callback: AsyncCallback\<void>): void;<br>clear(): Promise\<void>; | Deprecated|
| ohos.data.storage | Storage | clearSync(): void; | Deprecated|
| ohos.data.storage | Storage | delete(key: string, callback: AsyncCallback\<void>): void;<br>delete(key: string): Promise\<void>; | Deprecated|
| ohos.data.storage | Storage | deleteSync(key: string): void; | Deprecated|
| ohos.data.storage | Storage | put(key: string, value: ValueType, callback: AsyncCallback\<void>): void;<br>put(key: string, value: ValueType): Promise\<void>; | Deprecated|
| ohos.data.storage | Storage | putSync(key: string, value: ValueType): void; | Deprecated|
| ohos.data.storage | Storage | has(key: string, callback: AsyncCallback\<boolean>): boolean;<br>has(key: string): Promise\<boolean>; | Deprecated|
| ohos.data.storage | Storage | hasSync(key: string): boolean; | Deprecated|
| ohos.data.storage | Storage | get(key: string, defValue: ValueType, callback: AsyncCallback\<ValueType>): void;<br>get(key: string, defValue: ValueType): Promise\<ValueType>; | Deprecated|
| ohos.data.storage | Storage | getSync(key: string, defValue: ValueType): ValueType; | Deprecated|
| ohos.data.storage | storage | removeStorageFromCache(path: string, callback: AsyncCallback\<void>): void;<br>removeStorageFromCache(path: string): Promise\<void>; | Deprecated|
| ohos.data.storage | storage | removeStorageFromCacheSync(path: string): void; | Deprecated|
| ohos.data.storage | storage | deleteStorage(path: string, callback: AsyncCallback\<void>): void;<br>deleteStorage(path: string): Promise\<void>; | Deprecated|
| ohos.data.storage | storage | deleteStorageSync(path: string): void; | Deprecated|
| ohos.data.storage | storage | getStorage(path: string, callback: AsyncCallback\<Storage>): void;<br>getStorage(path: string): Promise\<Storage>; | Deprecated|
| ohos.data.storage | storage | getStorageSync(path: string): Storage; | Deprecated|
