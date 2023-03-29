# 启动本地PageAbility


PageAbility相关的能力通过featureAbility提供，启动本地Ability通过featureAbility中的startAbility接口实现。


  **表1** featureAbility接口说明

| 接口名 | 接口描述 |
| -------- | -------- |
| startAbility(parameter:&nbsp;StartAbilityParameter) | 启动Ability。 |
| startAbilityForResult(parameter:&nbsp;StartAbilityParameter) | 启动Ability，并在该Ability被销毁时返回执行结果。 |


如下示例通过startAbility显式启动PageAbility。启动Ability的参数包含want，关于want的说明详见[对象间信息传递载体Want](want-fa.md)，相应的，隐式启动与显式启动也不在此赘述。

```ts
import featureAbility from '@ohos.ability.featureAbility'
(async () => {
  try {
    console.info('Begin to start ability')
    let param = {
      want: {
        bundleName: "com.example.myapplication",
        moduleName: "entry",
        abilityName: "com.example.myapplication.MainAbility"
      }
    }
    await featureAbility.startAbility(param)
    console.info(`Start ability succeed`)
  } 
  catch (error) {
    console.error('Start ability failed with ' + error)
  }
})()
```
