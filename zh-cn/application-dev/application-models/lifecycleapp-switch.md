# LifecycleApp接口切换


  | FA模型接口 | Stage模型接口对应d.ts文件 | Stage模型对应接口 | 
| -------- | -------- | -------- |
| onShow?():&nbsp;void; | \@ohos.window.d.ts | [on(eventType:&nbsp;'windowStageEvent',&nbsp;callback:&nbsp;Callback&lt;WindowStageEventType&gt;):&nbsp;void;](../reference/apis/js-apis-window.md#onwindowstageevent9)<br/>监听[FOREGROUND](../reference/apis/js-apis-window.md#windowstageeventtype9)切到前台状态 |
| onHide?():&nbsp;void; | \@ohos.window.d.ts | [on(eventType:&nbsp;'windowStageEvent',&nbsp;callback:&nbsp;Callback&lt;WindowStageEventType&gt;):&nbsp;void;](../reference/apis/js-apis-window.md#onwindowstageevent9)<br/>监听[BACKGROUND](../reference/apis/js-apis-window.md#windowstageeventtype9)切到后台状态 |
| onDestroy?():&nbsp;void; | \@ohos.app.ability.UIAbility.d.ts | [onDestroy():&nbsp;void;](../reference/apis/js-apis-app-ability-uiAbility.md#abilityondestroy) | 
| onCreate?():&nbsp;void; | \@ohos.app.ability.UIAbility.d.ts | [onCreate(want:&nbsp;Want,&nbsp;param:&nbsp;AbilityConstant.LaunchParam):&nbsp;void;](../reference/apis/js-apis-app-ability-uiAbility.md#abilityoncreate) |
| onWindowDisplayModeChanged?(isShownInMultiWindow:&nbsp;boolean,&nbsp;newConfig:&nbsp;resourceManager.Configuration):&nbsp;void; | Stage模型无对应接口 | 暂时未提供对应接口 |
| onStartContinuation?():&nbsp;boolean; | Stage模型无对应接口 | Stage模型上，应用无需感知迁移是否成功（由应用发起迁移请求时感知），onStartContinuation废弃 |
| onSaveData?(data:&nbsp;Object):&nbsp;boolean; | \@ohos.app.ability.UIAbility.d.ts | [onContinue(wantParam&nbsp;:&nbsp;{[key:&nbsp;string]:&nbsp;any}):&nbsp;AbilityConstant.OnContinueResult;](../reference/apis/js-apis-app-ability-uiAbility.md#abilityoncontinue) |
| onCompleteContinuation?(result:&nbsp;number):&nbsp;void; | application\ContinueCallback.d.ts | [onContinueDone(result:&nbsp;number):&nbsp;void;](../reference/apis/js-apis-distributedMissionManager.md#continuecallback) |
| onRestoreData?(data:&nbsp;Object):&nbsp;void; | \@ohos.app.ability.UIAbility.d.ts | [onCreate(want:&nbsp;Want,&nbsp;param:&nbsp;AbilityConstant.LaunchParam):&nbsp;void;](../reference/apis/js-apis-app-ability-uiAbility.md#abilityoncreate)<br/>[onNewWant(want:&nbsp;Want,&nbsp;launchParams:&nbsp;AbilityConstant.LaunchParam):&nbsp;void;](../reference/apis/js-apis-app-ability-uiAbility.md#abilityonnewwant)<br/>标准实例模式Ability迁移目标端在onCreate回调中完成数据恢复，单实例应用迁移目标端在onCreate回调中完成数据恢复，回调中通过判断launchParam.launchReason可获取迁移启动的场景，从而可以从Want中获取迁移前保存的数据 |
| onRemoteTerminated?():&nbsp;void; | application\ContinueCallback.d.ts | [onContinueDone(result:&nbsp;number):&nbsp;void;](../reference/apis/js-apis-distributedMissionManager.md#continuecallback) |
| onSaveAbilityState?(outState:&nbsp;PacMap):&nbsp;void; | \@ohos.app.ability.UIAbility.d.ts | [onSaveState(reason:&nbsp;AbilityConstant.StateType,&nbsp;wantParam&nbsp;:&nbsp;{[key:&nbsp;string]:&nbsp;any}):&nbsp;AbilityConstant.OnSaveResult;](../reference/apis/js-apis-app-ability-uiAbility.md#abilityonsavestate) |
| onRestoreAbilityState?(inState:&nbsp;PacMap):&nbsp;void; | \@ohos.app.ability.UIAbility.d.ts | [onCreate(want:&nbsp;Want,&nbsp;param:&nbsp;AbilityConstant.LaunchParam):&nbsp;void;](../reference/apis/js-apis-app-ability-uiAbility.md#abilityoncreate)<br/>应用重启后会触发Ability的onCreate方法，通过判断launchParam.launchReason可获取自恢复的场景，从而可以从Want中获取重启前保存的数据 |
| onInactive?():&nbsp;void; | \@ohos.app.ability.UIAbility.d.ts | [onBackground():&nbsp;void;](../reference/apis/js-apis-app-ability-uiAbility.md#abilityonbackground) |
| onActive?():&nbsp;void; | \@ohos.app.ability.UIAbility.d.ts | [onForeground():&nbsp;void;](../reference/apis/js-apis-app-ability-uiAbility.md#abilityonforeground) |
| onNewWant?(want:&nbsp;Want):&nbsp;void; | \@ohos.app.ability.UIAbility.d.ts | [onNewWant(want:&nbsp;Want,&nbsp;launchParams:&nbsp;AbilityConstant.LaunchParam):&nbsp;void;](../reference/apis/js-apis-app-ability-uiAbility.md#abilityonnewwant) |
| onMemoryLevel?(level:&nbsp;number):&nbsp;void | \@ohos.app.ability.UIAbility.d.ts | [onMemoryLevel(level:&nbsp;AbilityConstant.MemoryLevel):&nbsp;void;](../reference/apis/js-apis-app-ability-ability.md#abilityonmemorylevel) |
