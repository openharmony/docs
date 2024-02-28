# 分布式数据管理子系统ChangeLog

## cl.distributeddatamgr.1 OH_Rdb_CloudSync接口参数变更

**访问级别**

公开接口

**变更原因**

在执行回调的时候，可以获取到context。

**变更影响**

非兼容性变更，需要开发者进行适配。

**API level**

11

**变更发生版本**

从OpenHarmony SDK 4.1.6.5开始。

**变更的接口**

变更前:
    
```c
int OH_Rdb_CloudSync(OH_Rdb_Store *store, Rdb_SyncMode mode, const char *tables[], uint32_t count,
    Rdb_SyncCallback *callback);
```
变更后：
    
```c
int OH_Rdb_CloudSync(OH_Rdb_Store *store, Rdb_SyncMode mode, const char *tables[], uint32_t count,
    const Rdb_ProgressObserver *observer);
```

**适配指导**

开发者需新增一个Rdb_ProgressObserver类型的参数，其中包含原有的callback参数，并新增一个context参数。

```c
// 定义回调函数
void CloudSyncObserverCallback(void *context, Rdb_ProgressDetails *progressDetails)
{
// do something
}
const Rdb_ProgressObserver observer = { .context = nullptr, .callback = CloudSyncObserverCallback };
OH_Rdb_CloudSync(storeTestRdbStore_, Rdb_SyncMode::SYNC_MODE_TIME_FIRST, table, TABLE_COUNT, &observer);
```



