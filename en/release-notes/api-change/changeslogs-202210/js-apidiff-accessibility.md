| Change Type | New Version | Old Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Added||Module name: ohos.accessibility.config<br>Class name: config<br>Method or attribute name: on_enabledAccessibilityExtensionListChange|@ohos.accessibility.config.d.ts|
|Added||Module name: ohos.accessibility.config<br>Class name: config<br>Method or attribute name: off_enabledAccessibilityExtensionListChange|@ohos.accessibility.config.d.ts|
|Added||Module name: ohos.accessibility<br>Class name: accessibility<br>Method or attribute name: getAccessibilityExtensionList|@ohos.accessibility.d.ts|
|Added||Module name: ohos.accessibility<br>Class name: accessibility<br>Method or attribute name: getAccessibilityExtensionList|@ohos.accessibility.d.ts|
|Added||Module name: ohos.accessibility<br>Class name: accessibility<br>Method or attribute name: sendAccessibilityEvent|@ohos.accessibility.d.ts|
|Added||Module name: ohos.accessibility<br>Class name: accessibility<br>Method or attribute name: sendAccessibilityEvent|@ohos.accessibility.d.ts|
|Added||Module name: ohos.accessibility.GesturePath<br>Class name: GesturePath|@ohos.accessibility.GesturePath.d.ts|
|Added||Module name: ohos.accessibility.GesturePath<br>Class name: GesturePath<br>Method or attribute name: ructor(durationTime|@ohos.accessibility.GesturePath.d.ts|
|Added||Module name: ohos.accessibility.GesturePath<br>Class name: GesturePath<br>Method or attribute name: points|@ohos.accessibility.GesturePath.d.ts|
|Added||Module name: ohos.accessibility.GesturePath<br>Class name: GesturePath<br>Method or attribute name: durationTime|@ohos.accessibility.GesturePath.d.ts|
|Added||Module name: ohos.accessibility.GesturePoint<br>Class name: GesturePoint|@ohos.accessibility.GesturePoint.d.ts|
|Added||Module name: ohos.accessibility.GesturePoint<br>Class name: GesturePoint<br>Method or attribute name: ructor(positionX|@ohos.accessibility.GesturePoint.d.ts|
|Added||Module name: ohos.accessibility.GesturePoint<br>Class name: GesturePoint<br>Method or attribute name: positionX|@ohos.accessibility.GesturePoint.d.ts|
|Added||Module name: ohos.accessibility.GesturePoint<br>Class name: GesturePoint<br>Method or attribute name: positionY|@ohos.accessibility.GesturePoint.d.ts|
|Added||Method or attribute name: performAction<br>Function name: performAction(actionName: string, parameters?: object): Promise<void>;|AccessibilityExtensionContext.d.ts|
|Added||Method or attribute name: performAction<br>Function name: performAction(actionName: string, callback: AsyncCallback<void>): void;|AccessibilityExtensionContext.d.ts|
|Added||Method or attribute name: performAction<br>Function name: performAction(actionName: string, parameters: object, callback: AsyncCallback<void>): void;|AccessibilityExtensionContext.d.ts|
|Deleted|Module name: ohos.accessibility.config<br>Class name: config<br>Method or attribute name: on_enableAbilityListsStateChanged||@ohos.accessibility.config.d.ts|
|Deleted|Module name: ohos.accessibility.config<br>Class name: config<br>Method or attribute name: off_enableAbilityListsStateChanged||@ohos.accessibility.config.d.ts|
|Deleted|Module name: ohos.application.AccessibilityExtensionAbility<br>Class name: GesturePath||@ohos.application.AccessibilityExtensionAbility.d.ts|
|Deleted|Module name: ohos.application.AccessibilityExtensionAbility<br>Class name: GesturePath<br>Method or attribute name: points||@ohos.application.AccessibilityExtensionAbility.d.ts|
|Deleted|Module name: ohos.application.AccessibilityExtensionAbility<br>Class name: GesturePath<br>Method or attribute name: durationTime||@ohos.application.AccessibilityExtensionAbility.d.ts|
|Deleted|Module name: ohos.application.AccessibilityExtensionAbility<br>Class name: GesturePoint||@ohos.application.AccessibilityExtensionAbility.d.ts|
|Deleted|Module name: ohos.application.AccessibilityExtensionAbility<br>Class name: GesturePoint<br>Method or attribute name: positionX||@ohos.application.AccessibilityExtensionAbility.d.ts|
|Deleted|Module name: ohos.application.AccessibilityExtensionAbility<br>Class name: GesturePoint<br>Method or attribute name: positionY||@ohos.application.AccessibilityExtensionAbility.d.ts|
|Deprecated version changed|Method or attribute name: getAbilityLists<br>Deprecated version: N/A|Method or attribute name: getAbilityLists<br>Deprecated version: 9<br>New API: ohos.accessibility|@ohos.accessibility.d.ts|
|Deprecated version changed|Method or attribute name: getAbilityLists<br>Deprecated version: N/A|Method or attribute name: getAbilityLists<br>Deprecated version: 9|@ohos.accessibility.d.ts|
|Deprecated version changed|Method or attribute name: sendEvent<br>Deprecated version: N/A|Method or attribute name: sendEvent<br>Deprecated version: 9<br>New API: ohos.accessibility|@ohos.accessibility.d.ts|
|Deprecated version changed|Method or attribute name: sendEvent<br>Deprecated version: N/A|Method or attribute name: sendEvent<br>Deprecated version: 9|@ohos.accessibility.d.ts|
|Error code added||Method or attribute name: enableAbility<br>Error code: 201, 401, 9300001, 9300002|@ohos.accessibility.config.d.ts|
|Error code added||Method or attribute name: disableAbility<br>Error code: 201, 401, 9300001|@ohos.accessibility.config.d.ts|
|Error code added||Method or attribute name: set<br>Error code: 201, 401|@ohos.accessibility.config.d.ts|
|Error code added||Method or attribute name: on<br>Error code: 401|@ohos.accessibility.config.d.ts|
|Error code added||Method or attribute name: on_accessibilityStateChange<br>Error code: 401|@ohos.accessibility.d.ts|
|Error code added||Method or attribute name: on_touchGuideStateChange<br>Error code: 401|@ohos.accessibility.d.ts|
|Error code added||Method or attribute name: off_accessibilityStateChange<br>Error code: 401|@ohos.accessibility.d.ts|
|Error code added||Method or attribute name: off_touchGuideStateChange<br>Error code: 401|@ohos.accessibility.d.ts|
|Error code added||Method or attribute name: on_enableChange<br>Error code: 401|@ohos.accessibility.d.ts|
|Error code added||Method or attribute name: on_styleChange<br>Error code: 401|@ohos.accessibility.d.ts|
|Error code added||Method or attribute name: off_enableChange<br>Error code: 401|@ohos.accessibility.d.ts|
|Error code added||Method or attribute name: off_styleChange<br>Error code: 401|@ohos.accessibility.d.ts|
|Error code added||Method or attribute name: setTargetBundleName<br>Error code: 401|AccessibilityExtensionContext.d.ts|
|Error code added||Method or attribute name: getFocusElement<br>Error code: 9300003|AccessibilityExtensionContext.d.ts|
|Error code added||Method or attribute name: getWindowRootElement<br>Error code: 9300003|AccessibilityExtensionContext.d.ts|
|Error code added||Method or attribute name: getWindows<br>Error code: 9300003|AccessibilityExtensionContext.d.ts|
|Error code added||Method or attribute name: injectGesture<br>Error code: 401, 9300003|AccessibilityExtensionContext.d.ts|
|Error code added||Method or attribute name: attributeValue<br>Error code: 401, 9300004|AccessibilityExtensionContext.d.ts|
|Error code added||Method or attribute name: findElement<br>Error code: 401|AccessibilityExtensionContext.d.ts|
|Error code added||Method or attribute name: findElement<br>Error code: 401|AccessibilityExtensionContext.d.ts|
|Error code added||Method or attribute name: findElement<br>Error code: 401|AccessibilityExtensionContext.d.ts|
