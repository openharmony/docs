| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Added|NA|Class name: userAuth;<br>Method or attribute name: function getUserAuthInstance(authParam: AuthParam, widgetParam: WidgetParam): UserAuthInstance;|@ohos.userIAM.userAuth.d.ts|
|Added|NA|Class name: userAuth;<br>Method or attribute name: function sendNotice(noticeType: NoticeType, eventData: string): void;|@ohos.userIAM.userAuth.d.ts|
|Added|NA|Class name: userAuth;<br>Method or attribute name: function getUserAuthWidgetMgr(version: number): UserAuthWidgetMgr;|@ohos.userIAM.userAuth.d.ts|
|Added|NA|Class name: UserAuthType;<br>Method or attribute name: PIN = 1|@ohos.userIAM.userAuth.d.ts|
|Added|NA|Class name: WindowModeType;<br>Method or attribute name: DIALOG_BOX = 1|@ohos.userIAM.userAuth.d.ts|
|Added|NA|Class name: WindowModeType;<br>Method or attribute name: FULLSCREEN = 2|@ohos.userIAM.userAuth.d.ts|
|Added|NA|Class name: AuthParam;<br>Method or attribute name: challenge: Uint8Array;|@ohos.userIAM.userAuth.d.ts|
|Added|NA|Class name: AuthParam;<br>Method or attribute name: authType: UserAuthType[];|@ohos.userIAM.userAuth.d.ts|
|Added|NA|Class name: AuthParam;<br>Method or attribute name: authTrustLevel: AuthTrustLevel;|@ohos.userIAM.userAuth.d.ts|
|Added|NA|Class name: WidgetParam;<br>Method or attribute name: title: string;|@ohos.userIAM.userAuth.d.ts|
|Added|NA|Class name: WidgetParam;<br>Method or attribute name: navigationButtonText?: string;|@ohos.userIAM.userAuth.d.ts|
|Added|NA|Class name: WidgetParam;<br>Method or attribute name: windowMode?: WindowModeType;|@ohos.userIAM.userAuth.d.ts|
|Added|NA|Class name: UserAuthResult;<br>Method or attribute name: result: number;|@ohos.userIAM.userAuth.d.ts|
|Added|NA|Class name: UserAuthResult;<br>Method or attribute name: token?: Uint8Array;|@ohos.userIAM.userAuth.d.ts|
|Added|NA|Class name: UserAuthResult;<br>Method or attribute name: authType?: UserAuthType;|@ohos.userIAM.userAuth.d.ts|
|Added|NA|Class name: IAuthCallback;<br>Method or attribute name: onResult(result: UserAuthResult): void;|@ohos.userIAM.userAuth.d.ts|
|Added|NA|Class name: UserAuthInstance;<br>Method or attribute name: on(type: 'result', callback: IAuthCallback): void;|@ohos.userIAM.userAuth.d.ts|
|Added|NA|Class name: UserAuthInstance;<br>Method or attribute name: off(type: 'result', callback?: IAuthCallback): void;|@ohos.userIAM.userAuth.d.ts|
|Added|NA|Class name: UserAuthInstance;<br>Method or attribute name: start(): void;|@ohos.userIAM.userAuth.d.ts|
|Added|NA|Class name: UserAuthInstance;<br>Method or attribute name: cancel(): void;|@ohos.userIAM.userAuth.d.ts|
|Added|NA|Class name: NoticeType;<br>Method or attribute name: WIDGET_NOTICE = 1|@ohos.userIAM.userAuth.d.ts|
|Added|NA|Class name: UserAuthResultCode;<br>Method or attribute name: CANCELED_FROM_WIDGET = 12500011|@ohos.userIAM.userAuth.d.ts|
|Added|NA|Class name: UserAuthWidgetMgr;<br>Method or attribute name: on(type: 'command', callback: IAuthWidgetCallback): void;|@ohos.userIAM.userAuth.d.ts|
|Added|NA|Class name: UserAuthWidgetMgr;<br>Method or attribute name: off(type: 'command', callback?: IAuthWidgetCallback): void;|@ohos.userIAM.userAuth.d.ts|
|Added|NA|Class name: IAuthWidgetCallback;<br>Method or attribute name: sendCommand(cmdData: string): void;|@ohos.userIAM.userAuth.d.ts|
|Deprecated version changed|Class name: userAuth;<br>Method or attribute name: function getAuthInstance(challenge: Uint8Array, authType: UserAuthType, authTrustLevel: AuthTrustLevel): AuthInstance;<br>Old version information: |Class name: userAuth;<br>Method or attribute name: function getAuthInstance(challenge: Uint8Array, authType: UserAuthType, authTrustLevel: AuthTrustLevel): AuthInstance;<br>New version information: 10<br>Substitute API: ohos.userIAM.userAuth.getUserAuthInstance|@ohos.userIAM.userAuth.d.ts|
|Deprecated version changed|Class name: AuthInstance;<br>Method or attribute name: interface AuthInstance<br>Old version information: |Class name: AuthInstance;<br>Method or attribute name: interface AuthInstance<br>New version information: 10<br>Substitute API: ohos.userIAM.userAuth.UserAuthInstance|@ohos.userIAM.userAuth.d.ts|
|Deprecated version changed|Class name: AuthInstance;<br>Method or attribute name: on: (name: AuthEventKey, callback: AuthEvent) => void;<br>Old version information: |Class name: AuthInstance;<br>Method or attribute name: on: (name: AuthEventKey, callback: AuthEvent) => void;<br>New version information: 10<br>Substitute API: ohos.userIAM.userAuth.UserAuthInstance|@ohos.userIAM.userAuth.d.ts|
|Deprecated version changed|Class name: AuthInstance;<br>Method or attribute name: off: (name: AuthEventKey) => void;<br>Old version information: |Class name: AuthInstance;<br>Method or attribute name: off: (name: AuthEventKey) => void;<br>New version information: 10<br>Substitute API: ohos.userIAM.userAuth.UserAuthInstance|@ohos.userIAM.userAuth.d.ts|
|Deprecated version changed|Class name: AuthInstance;<br>Method or attribute name: start: () => void;<br>Old version information: |Class name: AuthInstance;<br>Method or attribute name: start: () => void;<br>New version information: 10<br>Substitute API: ohos.userIAM.userAuth.UserAuthInstance|@ohos.userIAM.userAuth.d.ts|
|Deprecated version changed|Class name: AuthInstance;<br>Method or attribute name: cancel: () => void;<br>Old version information: |Class name: AuthInstance;<br>Method or attribute name: cancel: () => void;<br>New version information: 10<br>Substitute API: ohos.userIAM.userAuth.UserAuthInstance|@ohos.userIAM.userAuth.d.ts|
