| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：LaunchReason<br>方法or属性：SHARE = 5|@ohos.app.ability.AbilityConstant.d.ts|
|新增|NA|模块名: ohos.app.ability.abilityManager<br>类名: abilityManager<br>方法 or 属性: function acquireShareData(missionId: number, callback: AsyncCallback\<{ [key: string]: Object }>): void;|@ohos.app.ability.abilityManager.d.ts|
|新增|NA|模块名: ohos.app.ability.abilityManager<br>类名: abilityManager<br>方法 or 属性: function acquireShareData(missionId: number): Promise\<{ [key: string]: Object }>;|@ohos.app.ability.abilityManager.d.ts|
|新增|NA|模块名: ohos.app.ability.appManager<br>类名: appManager<br>方法 or 属性: function isSharedBundleRunning(bundleName: string, versionCode: number): Promise\<boolean>;|@ohos.app.ability.appManager.d.ts|
|新增|NA|模块名: ohos.app.ability.appManager<br>类名: appManager<br>方法 or 属性: function isSharedBundleRunning(bundleName: string, versionCode: number, callback: AsyncCallback\<boolean>): void;|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：appRecovery<br>方法or属性：function setRestartWant(want: Want): void;|@ohos.app.ability.appRecovery.d.ts|
|新增|NA|类名：appRecovery<br>方法or属性：function saveAppState(context?: UIAbilityContext): boolean;|@ohos.app.ability.appRecovery.d.ts|
|新增|NA|模块名: ohos.app.ability.quickFixManager<br>类名: quickFixManager<br>方法 or 属性: function revokeQuickFix(bundleName: string, callback: AsyncCallback\<void>): void;|@ohos.app.ability.quickFixManager.d.ts|
|新增|NA|模块名: ohos.app.ability.quickFixManager<br>类名: quickFixManager<br>方法 or 属性: function revokeQuickFix(bundleName: string): Promise\<void>;|@ohos.app.ability.quickFixManager.d.ts|
|新增|NA|模块名: ohos.app.ability.UIAbility<br>类名: OnRemoteStateChangeCallback|@ohos.app.ability.UIAbility.d.ts|
|新增|NA|模块名: ohos.app.ability.UIAbility<br>类名: OnRemoteStateChangeCallback<br>方法 or 属性：(msg: string): void;|@ohos.app.ability.UIAbility.d.ts|
|新增|NA|模块名: ohos.app.ability.UIAbility<br>类名: Caller<br>方法 or 属性：onRemoteStateChange(callback: OnRemoteStateChangeCallback): void;|@ohos.app.ability.UIAbility.d.ts|
|新增|NA|类名：UIAbility<br>方法or属性：onShare(wantParam: { [key: string]: Object }): void;|@ohos.app.ability.UIAbility.d.ts|
|新增|NA|模块名: ohos.app.ability.wantConstant<br>类名: Params<br>方法 or 属性: ABILITY_RECOVERY_RESTART = "ohos.ability.params.abilityRecoveryRestart"|@ohos.app.ability.wantConstant.d.ts|
|新增|NA|模块名: ohos.app.ability.wantConstant<br>类名: Params<br>方法 or 属性: CONTENT_TITLE_KEY = 'ohos.extra.param.key.contentTitle'|@ohos.app.ability.wantConstant.d.ts|
|新增|NA|模块名: ohos.app.ability.wantConstant<br>类名: Params<br>方法 or 属性: SHARE_ABSTRACT_KEY = 'ohos.extra.param.key.shareAbstract'|@ohos.app.ability.wantConstant.d.ts|
|新增|NA|模块名: ohos.app.ability.wantConstant<br>类名: Params<br>方法 or 属性: SHARE_URL_KEY = 'ohos.extra.param.key.shareUrl'|@ohos.app.ability.wantConstant.d.ts|
|新增|NA|模块名: ohos.app.form.FormExtensionAbility<br>类名: FormExtensionAbility<br>方法 or 属性: onAcquireFormData?(formId: string): { [key: string]: Object };|@ohos.app.form.FormExtensionAbility.d.ts|
|新增|NA|模块名: ohos.app.form.formHost<br>类名: formHost<br>方法 or 属性: function getRunningFormInfos(callback: AsyncCallback\<Array\<formInfo.RunningFormInfo>>, hostBundleName?: string): void;|@ohos.app.form.formHost.d.ts|
|新增|NA|模块名: ohos.app.form.formHost<br>类名: formHost<br>方法 or 属性: function getRunningFormInfos(hostBundleName?: string): Promise\<Array\<formInfo.RunningFormInfo>>;|@ohos.app.form.formHost.d.ts|
|新增|NA|模块名: ohos.app.form.formHost<br>类名: formHost<br>方法 or 属性: function on(type: "formAdd", observerCallback: Callback\<formInfo.RunningFormInfo>, bundleName?: string): void;|@ohos.app.form.formHost.d.ts|
|新增|NA|模块名: ohos.app.form.formHost<br>类名: formHost<br>方法 or 属性: function off(type: "formAdd", observerCallback?: Callback\<formInfo.RunningFormInfo>, bundleName?: string): void;|@ohos.app.form.formHost.d.ts|
|新增|NA|模块名: ohos.app.form.formHost<br>类名: formHost<br>方法 or 属性: function on(type: "formRemove", observerCallback: Callback\<formInfo.RunningFormInfo>, bundleName?: string): void;|@ohos.app.form.formHost.d.ts|
|新增|NA|模块名: ohos.app.form.formHost<br>类名: formHost<br>方法 or 属性: function off(type: "formRemove", observerCallback?: Callback\<formInfo.RunningFormInfo>, bundleName?: string): void;|@ohos.app.form.formHost.d.ts|
|新增|NA|模块名: ohos.app.form.formHost<br>类名: formHost<br>方法 or 属性: function acquireFormData(formId: string, callback: AsyncCallback\<{[key: string]: Object}>): void;|@ohos.app.form.formHost.d.ts|
|新增|NA|模块名: ohos.app.form.formHost<br>类名: formHost<br>方法 or 属性: function acquireFormData(formId: string): Promise\<{[key: string]: Object}>;|@ohos.app.form.formHost.d.ts|
|新增|NA|模块名: ohos.app.form.formHost<br>类名: formHost<br>方法 or 属性: function getRunningFormInfosByFilter(formProviderFilter: formInfo.FormProviderFilter): Promise\<Array\<formInfo.RunningFormInfo>>;|@ohos.app.form.formHost.d.ts|
|新增|NA|模块名: ohos.app.form.formHost<br>类名: formHost<br>方法 or 属性: function getRunningFormInfosByFilter(formProviderFilter: formInfo.FormProviderFilter, callback: AsyncCallback\<Array\<formInfo.RunningFormInfo>>): void;|@ohos.app.form.formHost.d.ts|
|新增|NA|模块名: ohos.app.form.formHost<br>类名: formHost<br>方法 or 属性: function getRunningFormInfoById(formId: string): Promise\<formInfo.RunningFormInfo>;|@ohos.app.form.formHost.d.ts|
|新增|NA|模块名: ohos.app.form.formHost<br>类名: formHost<br>方法 or 属性: function getRunningFormInfoById(formId: string, callback: AsyncCallback\<formInfo.RunningFormInfo>): void;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：FormInfo<br>方法or属性：descriptionId: number;|@ohos.app.form.formInfo.d.ts|
|新增|NA|模块名: ohos.app.form.formInfo<br>类名: FormParam<br>方法 or 属性：LAUNCH_REASON_KEY = "ohos.extra.param.key.form_launch_reason"|@ohos.app.form.formInfo.d.ts|
|新增|NA|模块名: ohos.app.form.formInfo<br>类名: FormParam<br>方法 or 属性：PARAM_FORM_CUSTOMIZE_KEY = "ohos.extra.param.key.form_customize"|@ohos.app.form.formInfo.d.ts|
|新增|NA|模块名: ohos.app.form.formInfo<br>类名: VisibilityType<br>方法 or 属性：UNKNOWN = 0|@ohos.app.form.formInfo.d.ts|
|新增|NA|模块名: ohos.app.form.formInfo<br>类名: LaunchReason|@ohos.app.form.formInfo.d.ts|
|新增|NA|模块名: ohos.app.form.formInfo<br>类名: LaunchReason<br>方法 or 属性：FORM_DEFAULT = 1|@ohos.app.form.formInfo.d.ts|
|新增|NA|模块名: ohos.app.form.formInfo<br>类名: LaunchReason<br>方法 or 属性：FORM_SHARE|@ohos.app.form.formInfo.d.ts|
|新增|NA|模块名: ohos.app.form.formInfo<br>类名: FormProviderFilter|@ohos.app.form.formInfo.d.ts|
|新增|NA|模块名: ohos.app.form.formInfo<br>类名: FormProviderFilter<br>方法 or 属性：bundleName: string;|@ohos.app.form.formInfo.d.ts|
|新增|NA|模块名: ohos.app.form.formInfo<br>类名: FormProviderFilter<br>方法 or 属性：formName ?: string;|@ohos.app.form.formInfo.d.ts|
|新增|NA|模块名: ohos.app.form.formInfo<br>类名: FormProviderFilter<br>方法 or 属性：moduleName ?: string;|@ohos.app.form.formInfo.d.ts|
|新增|NA|模块名: ohos.app.form.formInfo<br>类名: FormProviderFilter<br>方法 or 属性：abilityName ?: string;|@ohos.app.form.formInfo.d.ts|
|新增|NA|模块名: ohos.app.form.formInfo<br>类名: RunningFormInfo|@ohos.app.form.formInfo.d.ts|
|新增|NA|模块名: ohos.app.form.formInfo<br>类名: RunningFormInfo<br>方法 or 属性：readonly formId: string;|@ohos.app.form.formInfo.d.ts|
|新增|NA|模块名: ohos.app.form.formInfo<br>类名: RunningFormInfo<br>方法 or 属性：readonly bundleName: string;|@ohos.app.form.formInfo.d.ts|
|新增|NA|模块名: ohos.app.form.formInfo<br>类名: RunningFormInfo<br>方法 or 属性：readonly hostBundleName: string;|@ohos.app.form.formInfo.d.ts|
|新增|NA|模块名: ohos.app.form.formInfo<br>类名: RunningFormInfo<br>方法 or 属性：readonly visibilityType: VisibilityType;|@ohos.app.form.formInfo.d.ts|
|新增|NA|模块名: ohos.app.form.formInfo<br>类名: RunningFormInfo<br>方法 or 属性：readonly moduleName: string;|@ohos.app.form.formInfo.d.ts|
|新增|NA|模块名: ohos.app.form.formInfo<br>类名: RunningFormInfo<br>方法 or 属性：readonly abilityName: string;|@ohos.app.form.formInfo.d.ts|
|新增|NA|模块名: ohos.app.form.formInfo<br>类名: RunningFormInfo<br>方法 or 属性：readonly formName: string;|@ohos.app.form.formInfo.d.ts|
|新增|NA|模块名: ohos.app.form.formInfo<br>类名: RunningFormInfo<br>方法 or 属性：readonly dimension: number;|@ohos.app.form.formInfo.d.ts|
|新增|NA|模块名: ohos.application.StaticSubscriberExtensionAbility<br>类名: StaticSubscriberExtensionAbility<br>方法 or 属性: context: StaticSubscriberExtensionContext;|@ohos.application.StaticSubscriberExtensionAbility.d.ts|
|新增|NA|模块名: ohos.application.StaticSubscriberExtensionContext<br>类名: StaticSubscriberExtensionContext|@ohos.application.StaticSubscriberExtensionContext.d.ts|
|新增|NA|模块名: ohos.application.StaticSubscriberExtensionContext<br>类名: StaticSubscriberExtensionContext<br>方法 or 属性: startAbility(want: Want, callback: AsyncCallback\<void>): void;|@ohos.application.StaticSubscriberExtensionContext.d.ts|
|新增|NA|模块名: ohos.application.StaticSubscriberExtensionContext<br>类名: StaticSubscriberExtensionContext<br>方法 or 属性: startAbility(want: Want): Promise\<void>;|@ohos.application.StaticSubscriberExtensionContext.d.ts|
|新增|NA|模块名: ohos.application.uriPermissionManager<br>类名: uriPermissionManager|@ohos.application.uriPermissionManager.d.ts|
|新增|NA|模块名: ohos.application.uriPermissionManager<br>类名: uriPermissionManager<br>方法 or 属性: function grantUriPermission(uri: string, flag: wantConstant.Flags, targetBundleName: string, callback: AsyncCallback\<number>): void;|@ohos.application.uriPermissionManager.d.ts|
|新增|NA|模块名: ohos.application.uriPermissionManager<br>类名: uriPermissionManager<br>方法 or 属性: function grantUriPermission(uri: string, flag: wantConstant.Flags, targetBundleName: string): Promise\<number>;|@ohos.application.uriPermissionManager.d.ts|
|新增|NA|模块名: ohos.application.uriPermissionManager<br>类名: uriPermissionManager<br>方法 or 属性: function revokeUriPermission(uri: string, targetBundleName: string, callback: AsyncCallback\<number>): void;|@ohos.application.uriPermissionManager.d.ts|
|新增|NA|模块名: ohos.application.uriPermissionManager<br>类名: uriPermissionManager<br>方法 or 属性: function revokeUriPermission(uri: string, targetBundleName: string): Promise\<number>;|@ohos.application.uriPermissionManager.d.ts|
|新增|NA|模块名: ErrorObserver<br>类名: ErrorObserver<br>方法 or 属性: onException?(errObject: Error): void;|ErrorObserver.d.ts|
|新增|NA|类名：ServiceExtensionContext<br>方法or属性：startAbilityByCallWithAccount(want: Want, accountId: number): Promise\<Caller>;|ServiceExtensionContext.d.ts|
|新增|NA|类名：UIAbilityContext<br>方法or属性：startAbilityByCallWithAccount(want: Want, accountId: number): Promise\<Caller>;|UIAbilityContext.d.ts|
|新增(权限)|类名：ServiceExtensionContext<br>方法 or 属性：startServiceExtensionAbility(want: Want, callback: AsyncCallback\<void>): void;<br>权限:N/A|类名：ServiceExtensionContext<br>方法 or 属性：startServiceExtensionAbility(want: Want, callback: AsyncCallback\<void>): void;<br>权限:ohos.permission.START_INVISIBLE_ABILITY|ServiceExtensionContext.d.ts|
|新增(权限)|类名：ServiceExtensionContext<br>方法 or 属性：startServiceExtensionAbility(want: Want): Promise\<void>;<br>权限:N/A|类名：ServiceExtensionContext<br>方法 or 属性：startServiceExtensionAbility(want: Want): Promise\<void>;<br>权限:ohos.permission.START_INVISIBLE_ABILITY|ServiceExtensionContext.d.ts|
|新增(权限)|类名：ServiceExtensionContext<br>方法 or 属性：connectServiceExtensionAbility(want: Want, options: ConnectOptions): number;<br>权限:N/A|类名：ServiceExtensionContext<br>方法 or 属性：connectServiceExtensionAbility(want: Want, options: ConnectOptions): number;<br>权限:ohos.permission.ABILITY_BACKGROUND_COMMUNICATION|ServiceExtensionContext.d.ts|
|新增(权限)|类名：UIAbilityContext<br>方法 or 属性：startServiceExtensionAbility(want: Want, callback: AsyncCallback\<void>): void;<br>权限:N/A|类名：UIAbilityContext<br>方法 or 属性：startServiceExtensionAbility(want: Want, callback: AsyncCallback\<void>): void;<br>权限:ohos.permission.START_INVISIBLE_ABILITY|UIAbilityContext.d.ts|
|新增(权限)|类名：UIAbilityContext<br>方法 or 属性：startServiceExtensionAbility(want: Want): Promise\<void>;<br>权限:N/A|类名：UIAbilityContext<br>方法 or 属性：startServiceExtensionAbility(want: Want): Promise\<void>;<br>权限:ohos.permission.ABILITY_BACKGROUND_COMMUNICATION|UIAbilityContext.d.ts|
|新增(权限)|类名：UIAbilityContext<br>方法 or 属性：connectServiceExtensionAbility(want: Want, options: ConnectOptions): number;<br>权限:N/A|类名：UIAbilityContext<br>方法 or 属性：connectServiceExtensionAbility(want: Want, options: ConnectOptions): number;<br>权限:ohos.permission.ABILITY_BACKGROUND_COMMUNICATION|UIAbilityContext.d.ts|
