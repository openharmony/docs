# 停止PageAbility


停止PageAbility通过featureAbility中的terminateSelf接口实现。


  **表1** featureAbility接口说明

| 接口名 | 接口描述 |
| -------- | -------- |
| terminateSelf() | 停止Ability。 |
| terminateSelfWithResult(parameter:&nbsp;AbilityResult) | 设置该PageAbility停止时返回给调用者的结果及数据并停止Ability。 |


如下示例展示了停止Ability的方法。

```ts
import featureAbility from '@ohos.ability.featureAbility'

(async () => {
  try {
    console.info('Begin to terminateSelf')
    await featureAbility.terminateSelf()
    console.info('terminateSelf succeed')
  } 
  catch (error) {
    console.error('terminateSelf failed with ' + error)
  }
})()
```
