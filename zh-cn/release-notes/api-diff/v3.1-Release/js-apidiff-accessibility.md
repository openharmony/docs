# 无障碍子系统JS API变更

OpenHarmony 3.1 Release版本相较于OpenHarmony 3.0 LTS版本，无障碍子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.accessibility | EventInfo | itemCount?: number; | 新增 |
| ohos.accessibility | EventInfo | endIndex?: number; | 新增 |
| ohos.accessibility | EventInfo | currentIndex?: number; | 新增 |
| ohos.accessibility | EventInfo | beginIndex?: number; | 新增 |
| ohos.accessibility | EventInfo | lastContent?: string; | 新增 |
| ohos.accessibility | EventInfo | contents?: Array\<string>; | 新增 |
| ohos.accessibility | EventInfo | textMoveUnit?: TextMoveUnit; | 新增 |
| ohos.accessibility | EventInfo | triggerAction: Action; | 新增 |
| ohos.accessibility | EventInfo | description?: string; | 新增 |
| ohos.accessibility | EventInfo | pageId ?: number; | 新增 |
| ohos.accessibility | EventInfo | componentType?: string; | 新增 |
| ohos.accessibility | EventInfo | bundleName: string; | 新增 |
| ohos.accessibility | EventInfo | windowUpdateType?: WindowUpdateType; | 新增 |
| ohos.accessibility | EventInfo | type: EventType; | 新增 |
| ohos.accessibility | EventInfo | constructor(jsonObject); | 新增 |
| ohos.accessibility | AccessibilityAbilityInfo | readonly eventTypes: Array\<EventType>; | 新增 |
| ohos.accessibility | AccessibilityAbilityInfo | readonly description: string; | 新增 |
| ohos.accessibility | AccessibilityAbilityInfo | readonly capabilities: Array\<Capability>; | 新增 |
| ohos.accessibility | AccessibilityAbilityInfo | readonly abilityTypes: Array\<AbilityType>; | 新增 |
| ohos.accessibility | AccessibilityAbilityInfo | readonly bundleName: string; | 新增 |
| ohos.accessibility | AccessibilityAbilityInfo | readonly name: string; | 新增 |
| ohos.accessibility | AccessibilityAbilityInfo | readonly id: string; | 新增 |
| ohos.accessibility | CaptionsStyle | windowColor: number \| string; | 新增 |
| ohos.accessibility | CaptionsStyle | backgroundColor: number \| string; | 新增 |
| ohos.accessibility | CaptionsStyle | fontEdgeType: CaptionsFontEdgeType; | 新增 |
| ohos.accessibility | CaptionsStyle | fontColor: number \| string; | 新增 |
| ohos.accessibility | CaptionsStyle | fontScale: number; | 新增 |
| ohos.accessibility | CaptionsStyle | fontFamily: CaptionsFontFamily; | 新增 |
| ohos.accessibility | CaptionsManager | off(type: 'styleChange', callback?: Callback\<CaptionsStyle>): void; | 新增 |
| ohos.accessibility | CaptionsManager | off(type: 'enableChange', callback?: Callback\<boolean>): void; | 新增 |
| ohos.accessibility | CaptionsManager | on(type: 'styleChange', callback: Callback\<CaptionsStyle>): void; | 新增 |
| ohos.accessibility | CaptionsManager | on(type: 'enableChange', callback: Callback\<boolean>): void; | 新增 |
| ohos.accessibility | CaptionsManager | style: CaptionsStyle; | 新增 |
| ohos.accessibility | CaptionsManager | enabled: boolean; | 新增 |
| ohos.accessibility | accessibility | getCaptionsManager(): CaptionsManager; | 新增 |
| ohos.accessibility | accessibility | off(type: 'touchGuideStateChange', callback?: Callback\<boolean>): void; | 新增 |
| ohos.accessibility | accessibility | off(type: 'accessibilityStateChange', callback?: Callback\<boolean>): void; | 新增 |
| ohos.accessibility | accessibility | on(type: 'touchGuideStateChange', callback: Callback\<boolean>): void; | 新增 |
| ohos.accessibility | accessibility | on(type: 'accessibilityStateChange', callback: Callback\<boolean>): void; | 新增 |
| ohos.accessibility | accessibility | sendEvent(event: EventInfo, callback: AsyncCallback\<void>): void;<br>sendEvent(event: EventInfo): Promise\<void>; | 新增 |
| ohos.accessibility | accessibility | getAbilityLists(abilityType: AbilityType, stateType: AbilityState, callback: AsyncCallback\<Array\<AccessibilityAbilityInfo>>): void;<br>getAbilityLists(abilityType: AbilityType, stateType: AbilityState): Promise\<Array\<AccessibilityAbilityInfo>>; | 新增 |
| ohos.accessibility | accessibility | isOpenTouchGuide(callback: AsyncCallback\<boolean>): void;<br>isOpenTouchGuide(): Promise\<boolean>; | 新增 |
| ohos.accessibility | accessibility | isOpenAccessibility(callback: AsyncCallback\<boolean>): void;<br>isOpenAccessibility(): Promise\<boolean>; | 新增 |
