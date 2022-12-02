| 操作 | 新版本 | 旧版本 | d.ts文件 | 所属子系统 |
| ---- | ------ | ------ | -------- | ---------- |
|新增||模块名：ohos.accessibility.config<br>类名:config<br>方法名 or 属性名:on_enabledAccessibilityExtensionListChange|@ohos.accessibility.config.d.ts|无障碍软件服务|
|新增||模块名：ohos.accessibility.config<br>类名:config<br>方法名 or 属性名:off_enabledAccessibilityExtensionListChange|@ohos.accessibility.config.d.ts|无障碍软件服务|
|新增||方法名 or 属性名：getAbilityLists<br>函数：function getAbilityLists(abilityType: AbilityType, stateType: AbilityState,<br><br>    callback: AsyncCallback<Array<AccessibilityAbilityInfo>>): void;<br>function getAbilityLists(abilityType: AbilityType,    stateType: AbilityState): Promise<Array<AccessibilityAbilityInfo>>;<br>function getAbilityLists(abilityType: AbilityType,    stateType: AbilityState): Promise<Array<AccessibilityAbilityInfo>>;|@ohos.accessibility.d.ts|无障碍软件服务|
|新增||模块名：ohos.accessibility<br>类名:accessibility<br>方法名 or 属性名:getAccessibilityExtensionList|@ohos.accessibility.d.ts|无障碍软件服务|
|新增||模块名：ohos.accessibility<br>类名:accessibility<br>方法名 or 属性名:sendEvent|@ohos.accessibility.d.ts|无障碍软件服务|
|新增||模块名：ohos.accessibility<br>类名:accessibility<br>方法名 or 属性名:sendAccessibilityEvent|@ohos.accessibility.d.ts|无障碍软件服务|
|新增||模块名: ohos.accessibility.GesturePath<br>类名: GesturePath|@ohos.accessibility.GesturePath.d.ts|无障碍软件服务|
|新增||模块名: ohos.accessibility.GesturePath<br>类名: GesturePath<br>方法名 or 属性名： ructor(durationTime|@ohos.accessibility.GesturePath.d.ts|无障碍软件服务|
|新增||模块名: ohos.accessibility.GesturePath<br>类名: GesturePath<br>方法名 or 属性名： points|@ohos.accessibility.GesturePath.d.ts|无障碍软件服务|
|新增||模块名: ohos.accessibility.GesturePath<br>类名: GesturePath<br>方法名 or 属性名： durationTime|@ohos.accessibility.GesturePath.d.ts|无障碍软件服务|
|新增||模块名: ohos.accessibility.GesturePoint<br>类名: GesturePoint|@ohos.accessibility.GesturePoint.d.ts|无障碍软件服务|
|新增||模块名: ohos.accessibility.GesturePoint<br>类名: GesturePoint<br>方法名 or 属性名： ructor(positionX|@ohos.accessibility.GesturePoint.d.ts|无障碍软件服务|
|新增||模块名: ohos.accessibility.GesturePoint<br>类名: GesturePoint<br>方法名 or 属性名： positionX|@ohos.accessibility.GesturePoint.d.ts|无障碍软件服务|
|新增||模块名: ohos.accessibility.GesturePoint<br>类名: GesturePoint<br>方法名 or 属性名： positionY|@ohos.accessibility.GesturePoint.d.ts|无障碍软件服务|
|新增||方法名 or 属性名：performAction<br>函数：performAction(actionName: string, parameters?: object): Promise<void>;<br>performAction(actionName: string, callback: AsyncCallback<void>): void;<br>performAction(actionName: string, parameters: object, callback: AsyncCallback<void>): void;|AccessibilityExtensionContext.d.ts|无障碍软件服务|
|删除|模块名：ohos.accessibility.config<br>类名:config<br>方法名 or 属性名:on_enableAbilityListsStateChanged||@ohos.accessibility.config.d.ts|无障碍软件服务|
|删除|模块名：ohos.accessibility.config<br>类名:config<br>方法名 or 属性名:off_enableAbilityListsStateChanged||@ohos.accessibility.config.d.ts|无障碍软件服务|
|删除|模块名: ohos.application.AccessibilityExtensionAbility<br>类名: GesturePath||@ohos.application.AccessibilityExtensionAbility.d.ts|无障碍软件服务|
|删除|模块名: ohos.application.AccessibilityExtensionAbility<br>类名: GesturePath<br>方法名 or 属性名： points||@ohos.application.AccessibilityExtensionAbility.d.ts|无障碍软件服务|
|删除|模块名: ohos.application.AccessibilityExtensionAbility<br>类名: GesturePath<br>方法名 or 属性名： durationTime||@ohos.application.AccessibilityExtensionAbility.d.ts|无障碍软件服务|
|删除|模块名: ohos.application.AccessibilityExtensionAbility<br>类名: GesturePoint||@ohos.application.AccessibilityExtensionAbility.d.ts|无障碍软件服务|
|删除|模块名: ohos.application.AccessibilityExtensionAbility<br>类名: GesturePoint<br>方法名 or 属性名： positionX||@ohos.application.AccessibilityExtensionAbility.d.ts|无障碍软件服务|
|删除|模块名: ohos.application.AccessibilityExtensionAbility<br>类名: GesturePoint<br>方法名 or 属性名： positionY||@ohos.application.AccessibilityExtensionAbility.d.ts|无障碍软件服务|
|废弃版本有变化|方法名 or 属性名：getAbilityLists<br>废弃版本：|方法名 or 属性名：getAbilityLists<br><br>废弃版本：9<br>代替接口ohos.accessibility|@ohos.accessibility.d.ts|无障碍软件服务|
