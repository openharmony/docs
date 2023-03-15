# JS API Changes of the Distributed Data Management Subsystem

The table below lists the APIs changes of the distributed data management subsystem in OpenHarmony 3.2 Beta3 over OpenHarmony 3.2 Beta2.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.data.distributedData | KVStore     | deleteBackup(files:Array\<string>, callback: AsyncCallback\<Array\<[string, number]>>):void;<br>deleteBackup(files:Array\<string>): Promise\<Array\<[string, number]>>;                                                                                       | Added|
| ohos.data.distributedData | KVStore     | restore(file:string, callback: AsyncCallback\<void>):void;<br>restore(file:string): Promise\<void>;                                                                                                                                                           | Added|
| ohos.data.distributedData | KVStore     | backup(file:string, callback: AsyncCallback\<void>):void;<br>backup(file:string): Promise\<void>;                                                                                                                                                             | Added|
| ohos.data.rdb             | StoreConfig | encrypt?: boolean;                                                                                                                                                                                                                                             | Added|
| ohos.data.rdb             | RdbStore    | remoteQuery(device: string, table: string, predicates: RdbPredicates, columns: Array\<string>, callback: AsyncCallback\<ResultSet>): void;<br>remoteQuery(device: string, table: string, predicates: RdbPredicates, columns: Array\<string>): Promise\<ResultSet>; | Added|
| ohos.data.rdb             | RdbStore    | batchInsert(table: string, values: Array\<ValuesBucket>, callback: AsyncCallback\<number>): void;<br>batchInsert(table: string, values: Array\<ValuesBucket>): Promise\<number>;                                                                              | Added|
| ohos.data.dataShare | DataShareHelper | getFileTypes(uri: string,  mimeTypeFilter:string, callback: AsyncCallback\<Array\<string>>): void;<br>getFileTypes(uri: string,  mimeTypeFilter: string): Promise\<Array\<string>>; | Deleted|
| ohos.data.dataShare | DataShareHelper | getType(uri: string, callback: AsyncCallback\<string>): void;<br>getType(uri: string): Promise\<string>;                                                                       | Deleted|
| ohos.data.dataShare | DataShareHelper | openFile(uri: string, mode: string, callback: AsyncCallback\<number>): void;<br>openFile(uri: string, mode: string): Promise\<number>;                                         | Deleted|
