# 启动ServiceAbility


ServiceAbility的启动与其他Ability并无区别，应用开发者可以在PageAbility中通过featureAbility的startAbility接口拉起ServiceAbility，在ServiceAbility中通过particleAbility的startAbility接口拉起ServiceAbility。ServiceAbility的启动规则详见[组件启动规则](component-startup-rules.md)章节。


如下示例展示了在PageAbility中通过startAbility启动bundleName为"com.example.myapplication"，abilityName为"ServiceAbility"的ServiceAbility的方法。启动FA模型的ServiceAbility时，需要在abilityName前拼接bundleName字符串。

```ts
import featureAbility from '@ohos.ability.featureAbility'

async function startServiceAbility() {
  try {
    console.info('Begin to start ability')
    let param = {
      want: {
        bundleName: "com.example.myapplication",
        abilityName: "com.example.myapplication.ServiceAbility"
      }
    }
    await featureAbility.startAbility(param)
    console.info(`Start ability succeed`)
  } catch (error) {
    console.error('Start ability failed with ' + error)
  }
}
```


执行上述代码后，Ability将通过startAbility() 方法来启动ServiceAbility。


- 如果ServiceAbility尚未运行，则系统会先调用onStart()来初始化ServiceAbility，再回调Service的onCommand()方法来启动ServiceAbility。

- 如果ServiceAbility正在运行，则系统会直接回调ServiceAbility的onCommand()方法来启动ServiceAbility。
