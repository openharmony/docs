# JS API Changes of the Accessibility Subsystem

The table below lists the APIs changes of the accessibility subsystem in OpenHarmony 3.1 Release over OpenHarmony 3.0 LTS.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.accessibility | EventInfo | itemCount?: number; | Added|
| ohos.accessibility | EventInfo | endIndex?: number; | Added|
| ohos.accessibility | EventInfo | currentIndex?: number; | Added|
| ohos.accessibility | EventInfo | beginIndex?: number; | Added|
| ohos.accessibility | EventInfo | lastContent?: string; | Added|
| ohos.accessibility | EventInfo | contents?: Array\<string>; | Added|
| ohos.accessibility | EventInfo | textMoveUnit?: TextMoveUnit; | Added|
| ohos.accessibility | EventInfo | triggerAction: Action; | Added|
| ohos.accessibility | EventInfo | description?: string; | Added|
| ohos.accessibility | EventInfo | pageId ?: number; | Added|
| ohos.accessibility | EventInfo | componentType?: string; | Added|
| ohos.accessibility | EventInfo | bundleName: string; | Added|
| ohos.accessibility | EventInfo | windowUpdateType?: WindowUpdateType; | Added|
| ohos.accessibility | EventInfo | type: EventType; | Added|
| ohos.accessibility | EventInfo | constructor(jsonObject); | Added|
| ohos.accessibility | AccessibilityAbilityInfo | readonly eventTypes: Array\<EventType>; | Added|
| ohos.accessibility | AccessibilityAbilityInfo | readonly description: string; | Added|
| ohos.accessibility | AccessibilityAbilityInfo | readonly capabilities: Array\<Capability>; | Added|
| ohos.accessibility | AccessibilityAbilityInfo | readonly abilityTypes: Array\<AbilityType>; | Added|
| ohos.accessibility | AccessibilityAbilityInfo | readonly bundleName: string; | Added|
| ohos.accessibility | AccessibilityAbilityInfo | readonly name: string; | Added|
| ohos.accessibility | AccessibilityAbilityInfo | readonly id: string; | Added|
| ohos.accessibility | CaptionsStyle | windowColor: number \| string; | Added|
| ohos.accessibility | CaptionsStyle | backgroundColor: number \| string; | Added|
| ohos.accessibility | CaptionsStyle | fontEdgeType: CaptionsFontEdgeType; | Added|
| ohos.accessibility | CaptionsStyle | fontColor: number \| string; | Added|
| ohos.accessibility | CaptionsStyle | fontScale: number; | Added|
| ohos.accessibility | CaptionsStyle | fontFamily: CaptionsFontFamily; | Added|
| ohos.accessibility | CaptionsManager | off(type: 'styleChange', callback?: Callback\<CaptionsStyle>): void; | Added|
| ohos.accessibility | CaptionsManager | off(type: 'enableChange', callback?: Callback\<boolean>): void; | Added|
| ohos.accessibility | CaptionsManager | on(type: 'styleChange', callback: Callback\<CaptionsStyle>): void; | Added|
| ohos.accessibility | CaptionsManager | on(type: 'enableChange', callback: Callback\<boolean>): void; | Added|
| ohos.accessibility | CaptionsManager | style: CaptionsStyle; | Added|
| ohos.accessibility | CaptionsManager | enabled: boolean; | Added|
| ohos.accessibility | accessibility | getCaptionsManager(): CaptionsManager; | Added|
| ohos.accessibility | accessibility | off(type: 'touchGuideStateChange', callback?: Callback\<boolean>): void; | Added|
| ohos.accessibility | accessibility | off(type: 'accessibilityStateChange', callback?: Callback\<boolean>): void; | Added|
| ohos.accessibility | accessibility | on(type: 'touchGuideStateChange', callback: Callback\<boolean>): void; | Added|
| ohos.accessibility | accessibility | on(type: 'accessibilityStateChange', callback: Callback\<boolean>): void; | Added|
| ohos.accessibility | accessibility | sendEvent(event: EventInfo, callback: AsyncCallback\<void>): void;<br>sendEvent(event: EventInfo): Promise\<void>; | Added|
| ohos.accessibility | accessibility | getAbilityLists(abilityType: AbilityType, stateType: AbilityState, callback: AsyncCallback\<Array\<AccessibilityAbilityInfo>>): void;<br>getAbilityLists(abilityType: AbilityType, stateType: AbilityState): Promise\<Array\<AccessibilityAbilityInfo>>; | Added|
| ohos.accessibility | accessibility | isOpenTouchGuide(callback: AsyncCallback\<boolean>): void;<br>isOpenTouchGuide(): Promise\<boolean>; | Added|
| ohos.accessibility | accessibility | isOpenAccessibility(callback: AsyncCallback\<boolean>): void;<br>isOpenAccessibility(): Promise\<boolean>; | Added|
