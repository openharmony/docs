# 分布式数据管理子系统JS API变更Changelog

OpenHarmony 3.2.10.1(Mr)版本相较于OpenHarmony 3.2.beta4版本，分布式数据管理子系统的API变更如下

## cl.distributeddatamgr.1 接口变更
distributeddatamgr子系统kv_store组件接口存在变更：

由于时间固定，createKVManager方法需要改为同步接口。因此旧的接口function createKVManager(config: KVManagerConfig): Promise\<KVManager\>; 与 function createKVManager(config: KVManagerConfig, callback: AsyncCallback<KVManager>): void; 改为 function createKVManager(config: KVManagerConfig): KVManager;

开发者需要根据以下说明对应用进行适配。

 **变更影响**

影响API9版本的JS接口，应用需要进行适配才可以在新版本SDK环境正常实现功能。

**关键的接口/组件变更**

| 模块名                    | 类名                | 方法/属性/枚举/常量                                          | 变更类型 |
| ------------------------- | ------------------- | ------------------------------------------------------------ | -------- |
| @ohos.distributedKVStore        | distributedKVStore        | function createKVManager(config: KVManagerConfig): Promise\<KVManager\>; | 删除     |
| @ohos.distributedKVStore        | distributedKVStore        | function createKVManager(config: KVManagerConfig): KVManager; | 变更     |


**适配指导**

应用中调用createKVManager创建KVManager对象实例可参考下列代码

Stage模型下的示例：

```ts
import AbilityStage from '@ohos.application.Ability'
let kvManager;
export default class MyAbilityStage extends AbilityStage {
    onCreate() {
        console.log("MyAbilityStage onCreate")
        let context = this.context
        const kvManagerConfig = {
            context: context,
            bundleName: 'com.example.datamanagertest',
        }
        try {
            kvManager = distributedKVStore.createKVManager(kvManagerConfig);          
        } catch (e) {
            console.error(`Failed to create KVManager.code is ${e.code},message is ${e.message}`);
        }
    }
}
```

FA模型下的示例：

```ts
import featureAbility from '@ohos.ability.featureAbility'
let kvManager;
let context = featureAbility.getContext()
const kvManagerConfig = {
    context: context,
    bundleName: 'com.example.datamanagertest',
}
try {
    kvManager = distributedKVStore.createKVManager(kvManagerConfig);
} catch (e) {
    console.error(`Failed to create KVManager.code is ${e.code},message is ${e.message}`);
}
```