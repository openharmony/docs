| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Added|NA|Class name: cooperate;<br>Method or attribute name: function prepare(callback: AsyncCallback\<void>): void;|@ohos.cooperate.d.ts|
|Added|NA|Class name: cooperate;<br>Method or attribute name: function prepare(): Promise\<void>;|@ohos.cooperate.d.ts|
|Added|NA|Class name: cooperate;<br>Method or attribute name: function unprepare(callback: AsyncCallback\<void>): void;|@ohos.cooperate.d.ts|
|Added|NA|Class name: cooperate;<br>Method or attribute name: function unprepare(): Promise\<void>;|@ohos.cooperate.d.ts|
|Added|NA|Class name: cooperate;<br>Method or attribute name: function activate(targetNetworkId: string, inputDeviceId: number, callback: AsyncCallback\<void>): void;|@ohos.cooperate.d.ts|
|Added|NA|Class name: cooperate;<br>Method or attribute name: function activate(targetNetworkId: string, inputDeviceId: number): Promise\<void>;|@ohos.cooperate.d.ts|
|Added|NA|Class name: cooperate;<br>Method or attribute name: function deactivate(isUnchained: boolean, callback: AsyncCallback\<void>): void;|@ohos.cooperate.d.ts|
|Added|NA|Class name: cooperate;<br>Method or attribute name: function deactivate(isUnchained: boolean): Promise\<void>;|@ohos.cooperate.d.ts|
|Added|NA|Class name: cooperate;<br>Method or attribute name: function getCrossingSwitchState(networkId: string, callback: AsyncCallback\<boolean>): void;|@ohos.cooperate.d.ts|
|Added|NA|Class name: cooperate;<br>Method or attribute name: function getCrossingSwitchState(networkId: string): Promise\<boolean>;|@ohos.cooperate.d.ts|
|Added|NA|Class name: cooperate;<br>Method or attribute name: function on(type: 'cooperate', callback: Callback\<{ networkId: string, msg: CooperateMsg }>): void;|@ohos.cooperate.d.ts|
|Added|NA|Class name: cooperate;<br>Method or attribute name: function off(type: 'cooperate', callback?: Callback\<void>): void;|@ohos.cooperate.d.ts|
|Added|NA|Class name: CooperateMsg;<br>Method or attribute name: COOPERATE_PREPARE = 0|@ohos.cooperate.d.ts|
|Added|NA|Class name: CooperateMsg;<br>Method or attribute name: COOPERATE_UNPREPARE = 1|@ohos.cooperate.d.ts|
|Added|NA|Class name: CooperateMsg;<br>Method or attribute name: COOPERATE_ACTIVATE = 2|@ohos.cooperate.d.ts|
|Added|NA|Class name: CooperateMsg;<br>Method or attribute name: COOPERATE_ACTIVATE_SUCCESS = 3|@ohos.cooperate.d.ts|
|Added|NA|Class name: CooperateMsg;<br>Method or attribute name: COOPERATE_ACTIVATE_FAIL = 4|@ohos.cooperate.d.ts|
|Added|NA|Class name: CooperateMsg;<br>Method or attribute name: COOPERATE_DEACTIVATE_SUCCESS = 5|@ohos.cooperate.d.ts|
|Added|NA|Class name: CooperateMsg;<br>Method or attribute name: COOPERATE_DEACTIVATE_FAIL = 6|@ohos.cooperate.d.ts|
|Added|NA|Class name: CooperateMsg;<br>Method or attribute name: COOPERATE_SESSION_DISCONNECTED = 7|@ohos.cooperate.d.ts|
|Added|NA|Class name: dragInteraction;<br>Method or attribute name: function on(type: 'drag', callback: Callback\<DragState>): void;|@ohos.deviceStatus.dragInteraction.d.ts|
|Added|NA|Class name: dragInteraction;<br>Method or attribute name: function off(type: 'drag', callback?: Callback\<DragState>): void;|@ohos.deviceStatus.dragInteraction.d.ts|
|Added|NA|Class name: DragState;<br>Method or attribute name: MSG_DRAG_STATE_START = 1|@ohos.deviceStatus.dragInteraction.d.ts|
|Added|NA|Class name: DragState;<br>Method or attribute name: MSG_DRAG_STATE_STOP = 2|@ohos.deviceStatus.dragInteraction.d.ts|
|Added|NA|Class name: DragState;<br>Method or attribute name: MSG_DRAG_STATE_CANCEL = 3|@ohos.deviceStatus.dragInteraction.d.ts|
