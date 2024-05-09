| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|错误码变更|类名：inputMethod；<br>API声明：function switchInputMethod(target: InputMethodProperty, callback: AsyncCallback\<boolean>): void;<br>差异内容：12800005,12800008,201,401|类名：inputMethod；<br>API声明：function switchInputMethod(target: InputMethodProperty, callback: AsyncCallback\<boolean>): void;<br>差异内容：12800005,12800008,401|api/@ohos.inputMethod.d.ts|
|错误码变更|类名：inputMethod；<br>API声明：function switchInputMethod(target: InputMethodProperty): Promise\<boolean>;<br>差异内容：12800005,12800008,201,401|类名：inputMethod；<br>API声明：function switchInputMethod(target: InputMethodProperty): Promise\<boolean>;<br>差异内容：12800005,12800008,401|api/@ohos.inputMethod.d.ts|
|错误码变更|类名：inputMethod；<br>API声明：function switchCurrentInputMethodSubtype(target: InputMethodSubtype, callback: AsyncCallback\<boolean>): void;<br>差异内容：12800005,12800008,201,401|类名：inputMethod；<br>API声明：function switchCurrentInputMethodSubtype(target: InputMethodSubtype, callback: AsyncCallback\<boolean>): void;<br>差异内容：12800005,12800008,401|api/@ohos.inputMethod.d.ts|
|错误码变更|类名：inputMethod；<br>API声明：function switchCurrentInputMethodSubtype(target: InputMethodSubtype): Promise\<boolean>;<br>差异内容：12800005,12800008,201,401|类名：inputMethod；<br>API声明：function switchCurrentInputMethodSubtype(target: InputMethodSubtype): Promise\<boolean>;<br>差异内容：12800005,12800008,401|api/@ohos.inputMethod.d.ts|
|错误码变更|类名：inputMethod；<br>API声明：function switchCurrentInputMethodAndSubtype(inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype, callback: AsyncCallback\<boolean>): void;<br>差异内容：12800005,12800008,201,401|类名：inputMethod；<br>API声明：function switchCurrentInputMethodAndSubtype(inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype, callback: AsyncCallback\<boolean>): void;<br>差异内容：12800005,12800008,401|api/@ohos.inputMethod.d.ts|
|错误码变更|类名：inputMethod；<br>API声明：function switchCurrentInputMethodAndSubtype(inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype): Promise\<boolean>;<br>差异内容：12800005,12800008,201,401|类名：inputMethod；<br>API声明：function switchCurrentInputMethodAndSubtype(inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype): Promise\<boolean>;<br>差异内容：12800005,12800008,401|api/@ohos.inputMethod.d.ts|
|权限变更|类名：inputMethod；<br>API声明：function switchInputMethod(target: InputMethodProperty, callback: AsyncCallback\<boolean>): void;<br>差异内容：ohos.permission.CONNECT_IME_ABILITY|类名：inputMethod；<br>API声明：function switchInputMethod(target: InputMethodProperty, callback: AsyncCallback\<boolean>): void;<br>差异内容：NA|api/@ohos.inputMethod.d.ts|
|权限变更|类名：inputMethod；<br>API声明：function switchInputMethod(target: InputMethodProperty): Promise\<boolean>;<br>差异内容：ohos.permission.CONNECT_IME_ABILITY|类名：inputMethod；<br>API声明：function switchInputMethod(target: InputMethodProperty): Promise\<boolean>;<br>差异内容：NA|api/@ohos.inputMethod.d.ts|
|权限变更|类名：inputMethod；<br>API声明：function switchCurrentInputMethodSubtype(target: InputMethodSubtype, callback: AsyncCallback\<boolean>): void;<br>差异内容：ohos.permission.CONNECT_IME_ABILITY|类名：inputMethod；<br>API声明：function switchCurrentInputMethodSubtype(target: InputMethodSubtype, callback: AsyncCallback\<boolean>): void;<br>差异内容：NA|api/@ohos.inputMethod.d.ts|
|权限变更|类名：inputMethod；<br>API声明：function switchCurrentInputMethodSubtype(target: InputMethodSubtype): Promise\<boolean>;<br>差异内容：ohos.permission.CONNECT_IME_ABILITY|类名：inputMethod；<br>API声明：function switchCurrentInputMethodSubtype(target: InputMethodSubtype): Promise\<boolean>;<br>差异内容：NA|api/@ohos.inputMethod.d.ts|
|权限变更|类名：inputMethod；<br>API声明：function switchCurrentInputMethodAndSubtype(inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype, callback: AsyncCallback\<boolean>): void;<br>差异内容：ohos.permission.CONNECT_IME_ABILITY|类名：inputMethod；<br>API声明：function switchCurrentInputMethodAndSubtype(inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype, callback: AsyncCallback\<boolean>): void;<br>差异内容：NA|api/@ohos.inputMethod.d.ts|
|权限变更|类名：inputMethod；<br>API声明：function switchCurrentInputMethodAndSubtype(inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype): Promise\<boolean>;<br>差异内容：ohos.permission.CONNECT_IME_ABILITY|类名：inputMethod；<br>API声明：function switchCurrentInputMethodAndSubtype(inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype): Promise\<boolean>;<br>差异内容：NA|api/@ohos.inputMethod.d.ts|
|新增API|NA|类名：inputMethod；<br>API声明：function getDefaultInputMethod(): InputMethodProperty;<br>差异内容：function getDefaultInputMethod(): InputMethodProperty;|api/@ohos.inputMethod.d.ts|
|新增API|NA|类名：inputMethod；<br>API声明：function getSystemInputMethodConfigAbility(): ElementName;<br>差异内容：function getSystemInputMethodConfigAbility(): ElementName;|api/@ohos.inputMethod.d.ts|
|新增API|NA|类名：InputMethodSetting；<br>API声明：getInputMethodsSync(enable: boolean): Array\<InputMethodProperty>;<br>差异内容：getInputMethodsSync(enable: boolean): Array\<InputMethodProperty>;|api/@ohos.inputMethod.d.ts|
|新增API|NA|类名：InputMethodSetting；<br>API声明：getAllInputMethods(callback: AsyncCallback\<Array\<InputMethodProperty>>): void;<br>差异内容：getAllInputMethods(callback: AsyncCallback\<Array\<InputMethodProperty>>): void;|api/@ohos.inputMethod.d.ts|
|新增API|NA|类名：InputMethodSetting；<br>API声明：getAllInputMethods(): Promise\<Array\<InputMethodProperty>>;<br>差异内容：getAllInputMethods(): Promise\<Array\<InputMethodProperty>>;|api/@ohos.inputMethod.d.ts|
|新增API|NA|类名：InputMethodSetting；<br>API声明：getAllInputMethodsSync(): Array\<InputMethodProperty>;<br>差异内容：getAllInputMethodsSync(): Array\<InputMethodProperty>;|api/@ohos.inputMethod.d.ts|
|新增API|NA|类名：TextInputType；<br>API声明：NUMBER_PASSWORD<br>差异内容：NUMBER_PASSWORD|api/@ohos.inputMethod.d.ts|
|新增API|NA|类名：global；<br>API声明： export interface PanelInfo<br>差异内容： export interface PanelInfo|api/@ohos.inputMethod.Panel.d.ts|
|新增API|NA|类名：PanelInfo；<br>API声明：type: PanelType;<br>差异内容：type: PanelType;|api/@ohos.inputMethod.Panel.d.ts|
|新增API|NA|类名：PanelInfo；<br>API声明：flag?: PanelFlag;<br>差异内容：flag?: PanelFlag;|api/@ohos.inputMethod.Panel.d.ts|
|新增API|NA|类名：global；<br>API声明： export enum PanelFlag<br>差异内容： export enum PanelFlag|api/@ohos.inputMethod.Panel.d.ts|
|新增API|NA|类名：PanelFlag；<br>API声明：FLAG_FIXED = 0<br>差异内容：FLAG_FIXED = 0|api/@ohos.inputMethod.Panel.d.ts|
|新增API|NA|类名：PanelFlag；<br>API声明：FLAG_FLOATING<br>差异内容：FLAG_FLOATING|api/@ohos.inputMethod.Panel.d.ts|
|新增API|NA|类名：PanelFlag；<br>API声明：FLAG_CANDIDATE<br>差异内容：FLAG_CANDIDATE|api/@ohos.inputMethod.Panel.d.ts|
|新增API|NA|类名：global；<br>API声明： export enum PanelType<br>差异内容： export enum PanelType|api/@ohos.inputMethod.Panel.d.ts|
|新增API|NA|类名：PanelType；<br>API声明：SOFT_KEYBOARD = 0<br>差异内容：SOFT_KEYBOARD = 0|api/@ohos.inputMethod.Panel.d.ts|
|新增API|NA|类名：PanelType；<br>API声明：STATUS_BAR<br>差异内容：STATUS_BAR|api/@ohos.inputMethod.Panel.d.ts|
|新增API|NA|类名：inputMethodEngine；<br>API声明：const PATTERN_PASSWORD_SCREEN_LOCK: number;<br>差异内容：const PATTERN_PASSWORD_SCREEN_LOCK: number;|api/@ohos.inputMethodEngine.d.ts|
|新增API|NA|类名：inputMethodEngine；<br>API声明：const PATTERN_PASSWORD_NUMBER: number;<br>差异内容：const PATTERN_PASSWORD_NUMBER: number;|api/@ohos.inputMethodEngine.d.ts|
|新增API|NA|类名：KeyboardController；<br>API声明：exitCurrentInputType(callback: AsyncCallback\<void>): void;<br>差异内容：exitCurrentInputType(callback: AsyncCallback\<void>): void;|api/@ohos.inputMethodEngine.d.ts|
|新增API|NA|类名：KeyboardController；<br>API声明：exitCurrentInputType(): Promise\<void>;<br>差异内容：exitCurrentInputType(): Promise\<void>;|api/@ohos.inputMethodEngine.d.ts|
|新增API|NA|类名：InputMethodAbility；<br>API声明：on(type: 'securityModeChange', callback: Callback\<SecurityMode>): void;<br>差异内容：on(type: 'securityModeChange', callback: Callback\<SecurityMode>): void;|api/@ohos.inputMethodEngine.d.ts|
|新增API|NA|类名：InputMethodAbility；<br>API声明：off(type: 'securityModeChange', callback?: Callback\<SecurityMode>): void;<br>差异内容：off(type: 'securityModeChange', callback?: Callback\<SecurityMode>): void;|api/@ohos.inputMethodEngine.d.ts|
|新增API|NA|类名：InputMethodAbility；<br>API声明：getSecurityMode(): SecurityMode;<br>差异内容：getSecurityMode(): SecurityMode;|api/@ohos.inputMethodEngine.d.ts|
|新增API|NA|类名：Panel；<br>API声明：setPrivacyMode(isPrivacyMode: boolean): void;<br>差异内容：setPrivacyMode(isPrivacyMode: boolean): void;|api/@ohos.inputMethodEngine.d.ts|
|新增API|NA|类名：inputMethodEngine；<br>API声明： export enum SecurityMode<br>差异内容： export enum SecurityMode|api/@ohos.inputMethodEngine.d.ts|
|新增API|NA|类名：SecurityMode；<br>API声明：BASIC = 0<br>差异内容：BASIC = 0|api/@ohos.inputMethodEngine.d.ts|
|新增API|NA|类名：SecurityMode；<br>API声明：FULL<br>差异内容：FULL|api/@ohos.inputMethodEngine.d.ts|
|新增API|NA|类名：global；<br>API声明： export interface PatternOptions<br>差异内容： export interface PatternOptions|api/@ohos.inputMethodList.d.ets|
|新增API|NA|类名：PatternOptions；<br>API声明：defaultSelected?: number;<br>差异内容：defaultSelected?: number;|api/@ohos.inputMethodList.d.ets|
|新增API|NA|类名：PatternOptions；<br>API声明：patterns: Array\<Pattern>;<br>差异内容：patterns: Array\<Pattern>;|api/@ohos.inputMethodList.d.ets|
|新增API|NA|类名：PatternOptions；<br>API声明：action: (index: number) => void;<br>差异内容：action: (index: number) => void;|api/@ohos.inputMethodList.d.ets|
|新增API|NA|类名：global；<br>API声明： export interface Pattern<br>差异内容： export interface Pattern|api/@ohos.inputMethodList.d.ets|
|新增API|NA|类名：Pattern；<br>API声明：icon: Resource;<br>差异内容：icon: Resource;|api/@ohos.inputMethodList.d.ets|
|新增API|NA|类名：Pattern；<br>API声明：selectedIcon: Resource;<br>差异内容：selectedIcon: Resource;|api/@ohos.inputMethodList.d.ets|
|新增API|NA|类名：global；<br>API声明： export declare struct InputMethodListDialog<br>差异内容： export declare struct InputMethodListDialog|api/@ohos.inputMethodList.d.ets|
|新增API|NA|类名：InputMethodListDialog；<br>API声明：controller: CustomDialogController;<br>差异内容：controller: CustomDialogController;|api/@ohos.inputMethodList.d.ets|
|新增API|NA|类名：InputMethodListDialog；<br>API声明：patternOptions?: PatternOptions;<br>差异内容：patternOptions?: PatternOptions;|api/@ohos.inputMethodList.d.ets|
|kit变更|NA|IMEKit|api/@ohos.inputMethod.d.ts|
|kit变更|NA|IMEKit|api/@ohos.inputMethodEngine.d.ts|
|kit变更|NA|IMEKit|api/@ohos.InputMethodExtensionAbility.d.ts|
|kit变更|NA|IMEKit|api/@ohos.InputMethodExtensionContext.d.ts|
|kit变更|NA|IMEKit|api/@ohos.InputMethodSubtype.d.ts|
