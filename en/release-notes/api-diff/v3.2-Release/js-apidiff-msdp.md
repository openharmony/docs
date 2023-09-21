| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Added|NA|Class name: stationary;<br>Method or attribute name: type ActivityType = 'still' \| 'relativeStill';|@ohos.stationary.d.ts|
|Added|NA|Class name: stationary;<br>Method or attribute name: function on(activity: ActivityType, event: ActivityEvent, reportLatencyNs: number, callback: Callback\<ActivityResponse>): void;|@ohos.stationary.d.ts|
|Added|NA|Class name: stationary;<br>Method or attribute name: function once(activity: ActivityType, callback: Callback\<ActivityResponse>): void;|@ohos.stationary.d.ts|
|Added|NA|Class name: stationary;<br>Method or attribute name: function off(activity: ActivityType, event: ActivityEvent, callback?: Callback\<ActivityResponse>): void;|@ohos.stationary.d.ts|
|Added|NA|Class name: ActivityResponse;<br>Method or attribute name: state: ActivityState;|@ohos.stationary.d.ts|
|Added|NA|Class name: ActivityEvent;<br>Method or attribute name: ENTER = 1|@ohos.stationary.d.ts|
|Added|NA|Class name: ActivityState;<br>Method or attribute name: ENTER = 1|@ohos.stationary.d.ts|
|Added|NA|Class name: ActivityEvent;<br>Method or attribute name: EXIT = 2|@ohos.stationary.d.ts|
|Added|NA|Class name: ActivityState;<br>Method or attribute name: EXIT = 2|@ohos.stationary.d.ts|
|Added|NA|Class name: ActivityEvent;<br>Method or attribute name: ENTER_EXIT = 3|@ohos.stationary.d.ts|
