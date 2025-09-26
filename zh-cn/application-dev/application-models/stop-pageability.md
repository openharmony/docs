# 停止PageAbility

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @lidongrui-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

停止PageAbility通过featureAbility中的terminateSelf接口实现。


  **表1** featureAbility接口说明

| 接口名 | 接口描述 |
| -------- | -------- |
| terminateSelf() | 停止Ability。 |
| terminateSelfWithResult(parameter:&nbsp;AbilityResult) | 设置该PageAbility停止时返回给调用者的结果及数据并停止Ability。 |


如下示例展示了停止Ability的方法。

```ts
import featureAbility from '@ohos.ability.featureAbility';
import hilog from '@ohos.hilog';

const TAG: string = 'PagePageAbilityFirst';
const domain: number = 0xFF00;
```
```ts
//...
(async (): Promise<void> => {
  try {
    hilog.info(domain, TAG, 'Begin to terminateSelf');
    await featureAbility.terminateSelf();
    hilog.info(domain, TAG, 'terminateSelf succeed');
  } catch (error) {
    hilog.error(domain, TAG, 'terminateSelf failed with ' + error);
  }
})()
//...
```
