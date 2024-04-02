| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：accessibility;<br>方法or属性：function isOpenAccessibilitySync(): boolean;|@ohos.accessibility.d.ts|
|新增|NA|类名：accessibility;<br>方法or属性：function isOpenTouchGuideSync(): boolean;|@ohos.accessibility.d.ts|
|新增|NA|类名：sourcefile;<br>方法or属性：export type AccessibilityElement = _AccessibilityElement;|@ohos.application.AccessibilityExtensionAbility.d.ts|
|新增|NA|类名：sourcefile;<br>方法or属性：export type ElementAttributeValues = _ElementAttributeValues;|@ohos.application.AccessibilityExtensionAbility.d.ts|
|新增|NA|类名：sourcefile;<br>方法or属性：export type FocusDirection = _FocusDirection;|@ohos.application.AccessibilityExtensionAbility.d.ts|
|新增|NA|类名：sourcefile;<br>方法or属性：export type ElementAttributeKeys = keyof ElementAttributeValues;|@ohos.application.AccessibilityExtensionAbility.d.ts|
|新增|NA|类名：sourcefile;<br>方法or属性：export type FocusType = _FocusType;|@ohos.application.AccessibilityExtensionAbility.d.ts|
|新增|NA|类名：sourcefile;<br>方法or属性：export type WindowType = _WindowType;|@ohos.application.AccessibilityExtensionAbility.d.ts|
|新增|NA|类名：sourcefile;<br>方法or属性：export type Rect = _Rect;|@ohos.application.AccessibilityExtensionAbility.d.ts|
|新增|NA|类名：sourcefile;<br>方法or属性：export type AccessibilityExtensionContext = _AccessibilityExtensionContext.default;|@ohos.application.AccessibilityExtensionAbility.d.ts|
|新增|NA|类名：AccessibilityExtensionContext;<br>方法or属性：injectGestureSync(gesturePath: GesturePath): void;|AccessibilityExtensionContext.d.ts|
|废弃版本有变化|类名：accessibility;<br>方法or属性：function isOpenAccessibility(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：accessibility;<br>方法or属性：function isOpenAccessibility(callback: AsyncCallback\<boolean>): void;<br>新版本信息：10<br>代替接口： ohos.accessibility#isOpenAccessibilitySync|@ohos.accessibility.d.ts|
|废弃版本有变化|类名：accessibility;<br>方法or属性：function isOpenAccessibility(): Promise\<boolean>;<br>旧版本信息：|类名：accessibility;<br>方法or属性：function isOpenAccessibility(): Promise\<boolean>;<br>新版本信息：10<br>代替接口： ohos.accessibility#isOpenAccessibilitySync|@ohos.accessibility.d.ts|
|废弃版本有变化|类名：accessibility;<br>方法or属性：function isOpenTouchGuide(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：accessibility;<br>方法or属性：function isOpenTouchGuide(callback: AsyncCallback\<boolean>): void;<br>新版本信息：10<br>代替接口： ohos.accessibility#isOpenTouchGuideSync|@ohos.accessibility.d.ts|
|废弃版本有变化|类名：accessibility;<br>方法or属性：function isOpenTouchGuide(): Promise\<boolean>;<br>旧版本信息：|类名：accessibility;<br>方法or属性：function isOpenTouchGuide(): Promise\<boolean>;<br>新版本信息：10<br>代替接口： ohos.accessibility#isOpenTouchGuideSync|@ohos.accessibility.d.ts|
|废弃版本有变化|类名：AccessibilityExtensionContext;<br>方法or属性：injectGesture(gesturePath: GesturePath, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：AccessibilityExtensionContext;<br>方法or属性：injectGesture(gesturePath: GesturePath, callback: AsyncCallback\<void>): void;<br>新版本信息：10<br>代替接口： AccessibilityExtensionContext/AccessibilityExtensionContext#injectGestureSync|AccessibilityExtensionContext.d.ts|
|废弃版本有变化|类名：AccessibilityExtensionContext;<br>方法or属性：injectGesture(gesturePath: GesturePath): Promise\<void>;<br>旧版本信息：|类名：AccessibilityExtensionContext;<br>方法or属性：injectGesture(gesturePath: GesturePath): Promise\<void>;<br>新版本信息：10<br>代替接口： AccessibilityExtensionContext/AccessibilityExtensionContext#injectGestureSync|AccessibilityExtensionContext.d.ts|
|type有变化|类名：accessibility;<br>方法or属性：type AbilityType = 'audible' \| 'generic' \| 'haptic' \| 'spoken' \| 'visual' \| 'all';<br>旧版本信息：'audible' \| 'generic' \| 'haptic' \| 'spoken' \| 'visual' \| 'all'|类名：accessibility;<br>方法or属性：type AbilityType = 'audible' \| 'generic' \| 'haptic' \| 'spoken' \| 'visual' \| 'all';<br>新版本信息：|@ohos.accessibility.d.ts|
