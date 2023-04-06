# 启动DataAbility


启动DataAbility会获取一个工具接口类对象（DataAbilityHelper）。启动DataAbility的示例代码如下：

```ts
// 作为参数传递的URI,与config中定义的URI的区别是多了一个"/",有三个"/",具体原因详见。
import featureAbility from '@ohos.ability.featureAbility'

let urivar = "dataability:///com.ix.DataAbility"
let DAHelper = featureAbility.acquireDataAbilityHelper(urivar);
```

