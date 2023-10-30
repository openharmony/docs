| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：userAuth;<br>方法or属性：function getUserAuthInstance(authParam: AuthParam, widgetParam: WidgetParam): UserAuthInstance;|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：userAuth;<br>方法or属性：function sendNotice(noticeType: NoticeType, eventData: string): void;|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：userAuth;<br>方法or属性：function getUserAuthWidgetMgr(version: number): UserAuthWidgetMgr;|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：UserAuthType;<br>方法or属性：PIN = 1|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：WindowModeType;<br>方法or属性：DIALOG_BOX = 1|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：WindowModeType;<br>方法or属性：FULLSCREEN = 2|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：AuthParam;<br>方法or属性：challenge: Uint8Array;|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：AuthParam;<br>方法or属性：authType: UserAuthType[];|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：AuthParam;<br>方法or属性：authTrustLevel: AuthTrustLevel;|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：WidgetParam;<br>方法or属性：title: string;|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：WidgetParam;<br>方法or属性：navigationButtonText?: string;|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：WidgetParam;<br>方法or属性：windowMode?: WindowModeType;|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：UserAuthResult;<br>方法or属性：result: number;|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：UserAuthResult;<br>方法or属性：token?: Uint8Array;|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：UserAuthResult;<br>方法or属性：authType?: UserAuthType;|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：IAuthCallback;<br>方法or属性：onResult(result: UserAuthResult): void;|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：UserAuthInstance;<br>方法or属性：on(type: 'result', callback: IAuthCallback): void;|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：UserAuthInstance;<br>方法or属性：off(type: 'result', callback?: IAuthCallback): void;|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：UserAuthInstance;<br>方法or属性：start(): void;|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：UserAuthInstance;<br>方法or属性：cancel(): void;|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：NoticeType;<br>方法or属性：WIDGET_NOTICE = 1|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：UserAuthResultCode;<br>方法or属性：CANCELED_FROM_WIDGET = 12500011|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：UserAuthWidgetMgr;<br>方法or属性：on(type: 'command', callback: IAuthWidgetCallback): void;|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：UserAuthWidgetMgr;<br>方法or属性：off(type: 'command', callback?: IAuthWidgetCallback): void;|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：IAuthWidgetCallback;<br>方法or属性：sendCommand(cmdData: string): void;|@ohos.userIAM.userAuth.d.ts|
|废弃版本有变化|类名：userAuth;<br>方法or属性：function getAuthInstance(challenge: Uint8Array, authType: UserAuthType, authTrustLevel: AuthTrustLevel): AuthInstance;<br>旧版本信息：|类名：userAuth;<br>方法or属性：function getAuthInstance(challenge: Uint8Array, authType: UserAuthType, authTrustLevel: AuthTrustLevel): AuthInstance;<br>新版本信息：10<br>代替接口： ohos.userIAM.userAuth.getUserAuthInstance|@ohos.userIAM.userAuth.d.ts|
|废弃版本有变化|类名：AuthInstance;<br>方法or属性：interface AuthInstance<br>旧版本信息：|类名：AuthInstance;<br>方法or属性：interface AuthInstance<br>新版本信息：10<br>代替接口： ohos.userIAM.userAuth.UserAuthInstance|@ohos.userIAM.userAuth.d.ts|
|废弃版本有变化|类名：AuthInstance;<br>方法or属性：on: (name: AuthEventKey, callback: AuthEvent) => void;<br>旧版本信息：|类名：AuthInstance;<br>方法or属性：on: (name: AuthEventKey, callback: AuthEvent) => void;<br>新版本信息：10<br>代替接口： ohos.userIAM.userAuth.UserAuthInstance|@ohos.userIAM.userAuth.d.ts|
|废弃版本有变化|类名：AuthInstance;<br>方法or属性：off: (name: AuthEventKey) => void;<br>旧版本信息：|类名：AuthInstance;<br>方法or属性：off: (name: AuthEventKey) => void;<br>新版本信息：10<br>代替接口： ohos.userIAM.userAuth.UserAuthInstance|@ohos.userIAM.userAuth.d.ts|
|废弃版本有变化|类名：AuthInstance;<br>方法or属性：start: () => void;<br>旧版本信息：|类名：AuthInstance;<br>方法or属性：start: () => void;<br>新版本信息：10<br>代替接口： ohos.userIAM.userAuth.UserAuthInstance|@ohos.userIAM.userAuth.d.ts|
|废弃版本有变化|类名：AuthInstance;<br>方法or属性：cancel: () => void;<br>旧版本信息：|类名：AuthInstance;<br>方法or属性：cancel: () => void;<br>新版本信息：10<br>代替接口： ohos.userIAM.userAuth.UserAuthInstance|@ohos.userIAM.userAuth.d.ts|
