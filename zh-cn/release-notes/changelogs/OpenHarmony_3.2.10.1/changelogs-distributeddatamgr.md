# 分布式数据管理子系统JS API变更Changelog

OpenHarmony 3.2.10.1(Mr)版本相较于OpenHarmony 3.2.beta4版本，分布式数据管理子系统的API变更如下

## cl.distributeddatamgr.1 接口变更

**关键的接口/组件变更**

| 模块名                    | 类名                | 方法/属性/枚举/常量                                          | 变更类型 |
| ------------------------- | ------------------- | ------------------------------------------------------------ | -------- |
| @ohos.distributedKVStore        | distributedKVStore        | function createKVManager(config: KVManagerConfig): Promise\<KVManager\>; | 删除     |
| @ohos.distributedKVStore        | distributedKVStore        | function createKVManager(config: KVManagerConfig, callback: AsyncCallback\<KVManager\>): void; | 更改前     |
| @ohos.distributedKVStore        | distributedKVStore        | function createKVManager(config: KVManagerConfig): KVManager; | 更改后     |

        