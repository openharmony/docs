# 元能力子系统ChangeLog

## cl.ability.1 应用组件启动规则变更

元能力子系统应用组件启动规则在如下场景中存在变更：

 - 应用位于后台启动应用组件
 - 跨应用启动invisible应用组件
 - 跨应用启动FA模型的serviceAbility与dataAbility
 - 使用startAbilityByCall接口

开发者需要根据以下说明对应用进行适配。


**变更影响**

若未适配新规则，在上述场景下将无法启动应用组件
> **注意，启动应用组件是指一切启动或连接Ability的行为：**
<br> 1. 启动Ability，如使用startAbility、startServiceExtensionAbility、startAbilityByCall等接口。
<br> 2. 连接Ability，如使用connectAbility、connectServiceExtensionAbility、acquireDataAbilityHelper、createDataShareHelper等接口。

**关键的接口/组件变更**

 - 涉及的应用组件
   - Stage模型
     - Ability
     - ServiceExtension
     - DataShareExtension
   - FA模型
     - PageAbility
     - ServiceAbility
     - DataAbility 
 - 涉及接口
   - Stage模型
     - startAbility(want: Want, callback: AsyncCallback<void>): void;
     - startAbility(want: Want, options: StartOptions, callback: AsyncCallback<void>): void;
     - startAbility(want: Want, options?: StartOptions): Promise<void>;
     - startAbilityByCall(want: Want): Promise<Caller>;
     - startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback<void>): void;
     - startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback<void>): void;
     - startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions): Promise<void>;
     - startAbilityForResult(want: Want, callback: AsyncCallback<AbilityResult>): void;
     - startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback<AbilityResult>): void;
     - startAbilityForResult(want: Want, options?: StartOptions): Promise<AbilityResult>;
     - startAbilityForResultWithAccount(want: Want, accountId: number, callback: AsyncCallback<AbilityResult>): void;
     - startAbilityForResultWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback<void>): void;
     - startAbilityForResultWithAccount(want: Want, accountId: number, options?: StartOptions): Promise<AbilityResult>;
     - startServiceExtensionAbility(want: Want, callback: AsyncCallback<void>): void;
     - startServiceExtensionAbility(want: Want): Promise<void>;
     - startServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback<void>): void;
     - startServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise<void>;
     - stopServiceExtensionAbility(want: Want, callback: AsyncCallback<void>): void;
     - stopServiceExtensionAbility(want: Want): Promise<void>;
     - stopServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback<void>): void;
     - stopServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise<void>;
     - connectAbility(want: Want, options: ConnectOptions): number;
     - connectAbilityWithAccount(want: Want, accountId: number, options: ConnectOptions): number;
     - createDataShareHelper(context: Context, uri: string, callback: AsyncCallback<DataShareHelper>): void
   - FA模型
     - startAbility(parameter: StartAbilityParameter, callback: AsyncCallback<number>): void;
     - startAbility(parameter: StartAbilityParameter): Promise<number>;
     - startAbilityForResult(parameter: StartAbilityParameter, callback: AsyncCallback<AbilityResult>): void;
     - startAbilityForResult(parameter: StartAbilityParameter): Promise<AbilityResult>;
     - acquireDataAbilityHelper(uri: string): DataAbilityHelper;
     - connectAbility(request: Want, options:ConnectOptions ): number;

**适配指导**

不同场景下的启动规则说明如下：
 - **应用后台启动应用组件**
   - OpenHarmony 3.2-beta3 版本规则：
      - 应用位于后台时，启动应用组件不受任何限制。
   - OpenHarmony 3.2-Release 版本新规则：
     - 当应用位于后台时，启动应用组件需鉴权，需申请的权限如下：
      - ```json
        {
            "name": "ohos.permission.START_ABILITIES_FROM_BACKGROUND",
            "grantMode": "system_grant",
            "availableLevel": "system_basic",  
            "provisionEnable": true,
            "distributedSceneEnable": false
        }
        ```
          > **注：**
          <br> 1. 即使启动同应用的组件，也受该规则限制。
          <br> 2. 对于API8以及之前的SDK，启动serviceAbility和dataAbility不受此规则限制。

 - **跨应用启动invisible应用组件**
   - OpenHarmony 3.2.beta3 版本规则：
     - 对于APL为normal的应用，无法跨应用启动invisible的应用组件
   - OpenHarmony 3.2-Release 版本新规则：
     - 所有应用，若需要跨应用启动invisible的应用组件，需鉴权，需申请的权限如下：
     - ```json
        {
            "name": "ohos.permission.START_INVISIBLE_ABILITY",
            "grantMode": "system_grant",
            "availableLevel": "system_core",
            "provisionEnable": true,
            "distributedSceneEnable": false
        }
        ```

 - **跨应用启动FA模型的serviceAbility与dataAbility**

   - OpenHarmony 3.2.beta3 版本规则：
     - 可任意跨应用启动serviceAbility与dataAbility
   - OpenHarmony 3.2-Release 版本新规则：
     - serviceAbility与dataAbility的提供方应用需配置关联启动，否则无法被跨应用拉起。（普通应用无法配置关联启动）


 - **startAbilityByCall接口**
   - OpenHarmony 3.2.beta3 版本规则：
     - 可任意进行Call调用
   - OpenHarmony 3.2-Release 版本新规则：
     - 不支持同应用startAbilityByCall调用
      - 跨应用startAbilityByCall调用需鉴权，需申请的权限如下：

      - ```json
        {
            "name": "ohos.permission.ABILITY_BACKGROUND_COMMUNICATION",
            "grantMode": "system_grant",
            "availableLevel": "system_basic",
            "provisionEnable": true,
            "distributedSceneEnable": false
        }
        ```
        > **注：**
        <br> 使用startAbilityByCall接口同时也受上述后台启动、跨应用启动invisible规则的限制。