# 启动DataAbility


启动DataAbility会获取一个工具接口类对象（DataAbilityHelper）。启动DataAbility的示例代码如下：

```ts
import featureAbility from '@ohos.ability.featureAbility'
```
```ts
private uri = 'dataability:///com.samples.famodelabilitydevelop.DataAbility';
private DAHelper = featureAbility.acquireDataAbilityHelper(this.uri);
```

