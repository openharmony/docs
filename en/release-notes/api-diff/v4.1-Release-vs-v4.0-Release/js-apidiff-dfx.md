| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|API added|NA|Class name: hichecker;<br>API declaration: const RULE_CHECK_ARKUI_PERFORMANCE: 17179869184n;<br>Differences: const RULE_CHECK_ARKUI_PERFORMANCE: 17179869184n;|api/@ohos.hichecker.d.ts|
|API added|NA|Class name: hidebug;<br>API declaration: function getVss(): bigint;<br>Differences: function getVss(): bigint;|api/@ohos.hidebug.d.ts|
|API added|NA|Class name: hiAppEvent;<br>API declaration:  namespace domain<br>Differences:  namespace domain|api/@ohos.hiviewdfx.hiAppEvent.d.ts|
|API added|NA|Class name: domain;<br>API declaration: const OS: string;<br>Differences: const OS: string;|api/@ohos.hiviewdfx.hiAppEvent.d.ts|
|API added|NA|Class name: event;<br>API declaration: const APP_CRASH: string;<br>Differences: const APP_CRASH: string;|api/@ohos.hiviewdfx.hiAppEvent.d.ts|
|API added|NA|Class name: event;<br>API declaration: const APP_FREEZE: string;<br>Differences: const APP_FREEZE: string;|api/@ohos.hiviewdfx.hiAppEvent.d.ts|
|API added|NA|Class name: AppEventFilter;<br>API declaration: names?: string[];<br>Differences: names?: string[];|api/@ohos.hiviewdfx.hiAppEvent.d.ts|
|API added|NA|Class name: hiAppEvent;<br>API declaration:  interface AppEventGroup<br>Differences:  interface AppEventGroup|api/@ohos.hiviewdfx.hiAppEvent.d.ts|
|API added|NA|Class name: AppEventGroup;<br>API declaration: name: string;<br>Differences: name: string;|api/@ohos.hiviewdfx.hiAppEvent.d.ts|
|API added|NA|Class name: AppEventGroup;<br>API declaration: appEventInfos: Array\<AppEventInfo>;<br>Differences: appEventInfos: Array\<AppEventInfo>;|api/@ohos.hiviewdfx.hiAppEvent.d.ts|
|API added|NA|Class name: Watcher;<br>API declaration: onReceive?: (domain: string, appEventGroups: Array\<AppEventGroup>) => void;<br>Differences: onReceive?: (domain: string, appEventGroups: Array\<AppEventGroup>) => void;|api/@ohos.hiviewdfx.hiAppEvent.d.ts|
|API added|NA|Class name: hiAppEvent;<br>API declaration: function setUserId(name: string, value: string): void;<br>Differences: function setUserId(name: string, value: string): void;|api/@ohos.hiviewdfx.hiAppEvent.d.ts|
|API added|NA|Class name: hiAppEvent;<br>API declaration: function getUserId(name: string): string;<br>Differences: function getUserId(name: string): string;|api/@ohos.hiviewdfx.hiAppEvent.d.ts|
|API added|NA|Class name: hiAppEvent;<br>API declaration: function setUserProperty(name: string, value: string): void;<br>Differences: function setUserProperty(name: string, value: string): void;|api/@ohos.hiviewdfx.hiAppEvent.d.ts|
|API added|NA|Class name: hiAppEvent;<br>API declaration: function getUserProperty(name: string): string;<br>Differences: function getUserProperty(name: string): string;|api/@ohos.hiviewdfx.hiAppEvent.d.ts|
|API added|NA|Class name: hiAppEvent;<br>API declaration:  interface AppEventReportConfig<br>Differences:  interface AppEventReportConfig|api/@ohos.hiviewdfx.hiAppEvent.d.ts|
|API added|NA|Class name: AppEventReportConfig;<br>API declaration: domain?: string;<br>Differences: domain?: string;|api/@ohos.hiviewdfx.hiAppEvent.d.ts|
|API added|NA|Class name: AppEventReportConfig;<br>API declaration: name?: string;<br>Differences: name?: string;|api/@ohos.hiviewdfx.hiAppEvent.d.ts|
|API added|NA|Class name: AppEventReportConfig;<br>API declaration: isRealTime?: boolean;<br>Differences: isRealTime?: boolean;|api/@ohos.hiviewdfx.hiAppEvent.d.ts|
|API added|NA|Class name: hiAppEvent;<br>API declaration:  interface Processor<br>Differences:  interface Processor|api/@ohos.hiviewdfx.hiAppEvent.d.ts|
|API added|NA|Class name: Processor;<br>API declaration: name: string;<br>Differences: name: string;|api/@ohos.hiviewdfx.hiAppEvent.d.ts|
|API added|NA|Class name: Processor;<br>API declaration: debugMode?: boolean;<br>Differences: debugMode?: boolean;|api/@ohos.hiviewdfx.hiAppEvent.d.ts|
|API added|NA|Class name: Processor;<br>API declaration: routeInfo?: string;<br>Differences: routeInfo?: string;|api/@ohos.hiviewdfx.hiAppEvent.d.ts|
|API added|NA|Class name: Processor;<br>API declaration: appId?: string;<br>Differences: appId?: string;|api/@ohos.hiviewdfx.hiAppEvent.d.ts|
|API added|NA|Class name: Processor;<br>API declaration: onStartReport?: boolean;<br>Differences: onStartReport?: boolean;|api/@ohos.hiviewdfx.hiAppEvent.d.ts|
|API added|NA|Class name: Processor;<br>API declaration: onBackgroundReport?: boolean;<br>Differences: onBackgroundReport?: boolean;|api/@ohos.hiviewdfx.hiAppEvent.d.ts|
|API added|NA|Class name: Processor;<br>API declaration: periodReport?: number;<br>Differences: periodReport?: number;|api/@ohos.hiviewdfx.hiAppEvent.d.ts|
|API added|NA|Class name: Processor;<br>API declaration: batchReport?: number;<br>Differences: batchReport?: number;|api/@ohos.hiviewdfx.hiAppEvent.d.ts|
|API added|NA|Class name: Processor;<br>API declaration: userIds?: string[];<br>Differences: userIds?: string[];|api/@ohos.hiviewdfx.hiAppEvent.d.ts|
|API added|NA|Class name: Processor;<br>API declaration: userProperties?: string[];<br>Differences: userProperties?: string[];|api/@ohos.hiviewdfx.hiAppEvent.d.ts|
|API added|NA|Class name: Processor;<br>API declaration: eventConfigs?: AppEventReportConfig[];<br>Differences: eventConfigs?: AppEventReportConfig[];|api/@ohos.hiviewdfx.hiAppEvent.d.ts|
|API added|NA|Class name: hiAppEvent;<br>API declaration: function addProcessor(processor: Processor): number;<br>Differences: function addProcessor(processor: Processor): number;|api/@ohos.hiviewdfx.hiAppEvent.d.ts|
|API added|NA|Class name: hiAppEvent;<br>API declaration: function removeProcessor(id: number): void;<br>Differences: function removeProcessor(id: number): void;|api/@ohos.hiviewdfx.hiAppEvent.d.ts|
|Kit changed|NA|PerformanceAnalysisKit|api/@ohos.bytrace.d.ts|
|Kit changed|NA|PerformanceAnalysisKit|api/@ohos.faultLogger.d.ts|
|Kit changed|NA|PerformanceAnalysisKit|api/@ohos.hiAppEvent.d.ts|
|Kit changed|NA|PerformanceAnalysisKit|api/@ohos.hichecker.d.ts|
|Kit changed|NA|PerformanceAnalysisKit|api/@ohos.hidebug.d.ts|
|Kit changed|NA|PerformanceAnalysisKit|api/@ohos.hilog.d.ts|
|Kit changed|NA|PerformanceAnalysisKit|api/@ohos.hiTraceChain.d.ts|
|Kit changed|NA|PerformanceAnalysisKit|api/@ohos.hiTraceMeter.d.ts|
|Kit changed|NA|PerformanceAnalysisKit|api/@ohos.hiviewdfx.hiAppEvent.d.ts|
