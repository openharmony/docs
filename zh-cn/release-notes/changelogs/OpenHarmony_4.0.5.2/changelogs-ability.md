# 元能力子系统ChangeLog

## cl.ability.appRecovery新增saveAppState接口

新增接口saveAppState(context?: UIAbilityContext): boolean;

**变更影响**

基于OpenHarmony4.0.5.2及之后的SDK版本开发的应用，可以使用saveAppState接口传入指定Ability Context，实现主动保存指定的Ability状态。

**关键接口/组件变更**

@ohos.app.ability.appRecovery.d.ts中新增saveAppState接口。

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|  -- | -- | -- | -- |
| @ohos.app.ability.appRecovery.d.ts | appRecovery | saveAppState(context?: UIAbilityContext): boolean; | 新增 |

**适配指导**

通过调用saveAppState传入UIAbility Context参数主动保存此指定的Ability的状态。

```ts
import appRecovery from '@ohos.app.ability.appRecovery';
onBackground() {
    hilog.info(0x0000, '[demo]', '%{public}s', 'EntryAbility onBackground');
    appRecovery.saveAppState(this.context)
}
```
## cl.ability.appRecovery新增setRestartWant接口

新增接口setRestartWant(want: Want): void;

**变更影响**

基于OpenHarmony4.0.5.2及之后的SDK版本开发的应用，可以使用setRestartWant接口设置下次由恢复主动拉起场景下的Ability。

**关键接口/组件变更**

@ohos.app.ability.appRecovery.d.ts中新增setRestartWant接口。

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|  -- | -- | -- | -- |
| @ohos.app.ability.appRecovery.d.ts | appRecovery | setRestartWant(want: Want): void; | 新增 |

**适配指导**

通过调用setRestartWant设置下次恢复到的指定Ability。

```ts
import appRecovery from '@ohos.app.ability.appRecovery';
Button("启动到恢复Ability")
    .fontSize(40)
    .fontWeight(FontWeight.Bold)
    .onClick(()=> {
        // set restart want
        let want = {
            bundleName: "ohos.samples.recovery",
            abilityName: "RecoveryAbility"
        };

        appRecovery.setRestartWant(want);
    })
```