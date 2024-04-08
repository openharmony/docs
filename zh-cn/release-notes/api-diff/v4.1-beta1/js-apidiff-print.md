| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|API访问级别变更|文件名：api\@ohos.print.d.ts；<br>类名：print；<br>API声明： interface PrinterRange<br>差异内容：systemapi|文件名：api\@ohos.print.d.ts；<br>类名：print；<br>API声明： interface PrinterRange<br>差异内容：NA|api\@ohos.print.d.ts|
|API访问级别变更|文件名：api\@ohos.print.d.ts；<br>类名：PrinterRange；<br>API声明：startPage?: number;<br>差异内容：systemapi|文件名：api\@ohos.print.d.ts；<br>类名：PrinterRange；<br>API声明：startPage?: number;<br>差异内容：NA|api\@ohos.print.d.ts|
|API访问级别变更|文件名：api\@ohos.print.d.ts；<br>类名：PrinterRange；<br>API声明：endPage?: number;<br>差异内容：systemapi|文件名：api\@ohos.print.d.ts；<br>类名：PrinterRange；<br>API声明：endPage?: number;<br>差异内容：NA|api\@ohos.print.d.ts|
|API访问级别变更|文件名：api\@ohos.print.d.ts；<br>类名：PrinterRange；<br>API声明：pages?: Array\<number>;<br>差异内容：systemapi|文件名：api\@ohos.print.d.ts；<br>类名：PrinterRange；<br>API声明：pages?: Array\<number>;<br>差异内容：NA|api\@ohos.print.d.ts|
|API访问级别变更|文件名：api\@ohos.print.d.ts；<br>类名：print；<br>API声明： interface PrintPageSize<br>差异内容：systemapi|文件名：api\@ohos.print.d.ts；<br>类名：print；<br>API声明： interface PrintPageSize<br>差异内容：NA|api\@ohos.print.d.ts|
|API访问级别变更|文件名：api\@ohos.print.d.ts；<br>类名：PrintPageSize；<br>API声明：id: string;<br>差异内容：systemapi|文件名：api\@ohos.print.d.ts；<br>类名：PrintPageSize；<br>API声明：id: string;<br>差异内容：NA|api\@ohos.print.d.ts|
|API访问级别变更|文件名：api\@ohos.print.d.ts；<br>类名：PrintPageSize；<br>API声明：name: string;<br>差异内容：systemapi|文件名：api\@ohos.print.d.ts；<br>类名：PrintPageSize；<br>API声明：name: string;<br>差异内容：NA|api\@ohos.print.d.ts|
|API访问级别变更|文件名：api\@ohos.print.d.ts；<br>类名：PrintPageSize；<br>API声明：width: number;<br>差异内容：systemapi|文件名：api\@ohos.print.d.ts；<br>类名：PrintPageSize；<br>API声明：width: number;<br>差异内容：NA|api\@ohos.print.d.ts|
|API访问级别变更|文件名：api\@ohos.print.d.ts；<br>类名：PrintPageSize；<br>API声明：height: number;<br>差异内容：systemapi|文件名：api\@ohos.print.d.ts；<br>类名：PrintPageSize；<br>API声明：height: number;<br>差异内容：NA|api\@ohos.print.d.ts|
|API废弃|文件名：api\@ohos.print.d.ts；<br>类名：print；<br>API声明：function queryAllPrintJobs(callback: AsyncCallback\<void>): void;<br>差异内容：-1|文件名：api\@ohos.print.d.ts；<br>类名：print；<br>API声明：function queryAllPrintJobs(callback: AsyncCallback\<void>): void;<br>差异内容：11|api\@ohos.print.d.ts|
|API废弃|文件名：api\@ohos.print.d.ts；<br>类名：print；<br>API声明：function queryAllPrintJobs(): Promise\<void>;<br>差异内容：-1|文件名：api\@ohos.print.d.ts；<br>类名：print；<br>API声明：function queryAllPrintJobs(): Promise\<void>;<br>差异内容：11|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：print；<br>API声明：function print(files: Array\<string>, context: Context, callback: AsyncCallback\<PrintTask>): void;<br>差异内容：function print(files: Array\<string>, context: Context, callback: AsyncCallback\<PrintTask>): void;|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：print；<br>API声明：function print(files: Array\<string>, context: Context): Promise\<PrintTask>;<br>差异内容：function print(files: Array\<string>, context: Context): Promise\<PrintTask>;|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：print；<br>API声明：function print(jobName: string, printAdapter: PrintDocumentAdapter, printAttributes: PrintAttributes,<br>    context: Context): Promise\<PrintTask>;<br>差异内容：function print(jobName: string, printAdapter: PrintDocumentAdapter, printAttributes: PrintAttributes,<br>    context: Context): Promise\<PrintTask>;|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：print；<br>API声明： interface PrintDocumentAdapter<br>差异内容： interface PrintDocumentAdapter|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintDocumentAdapter；<br>API声明：onStartLayoutWrite(jobId: string, oldAttrs: PrintAttributes, newAttrs: PrintAttributes, fd: number,<br>      writeResultCallback: (jobId: string, writeResult: PrintFileCreationState) => void): void;<br>差异内容：onStartLayoutWrite(jobId: string, oldAttrs: PrintAttributes, newAttrs: PrintAttributes, fd: number,<br>      writeResultCallback: (jobId: string, writeResult: PrintFileCreationState) => void): void;|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintDocumentAdapter；<br>API声明：onJobStateChanged(jobId: string, state: PrintDocumentAdapterState): void;<br>差异内容：onJobStateChanged(jobId: string, state: PrintDocumentAdapterState): void;|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：print；<br>API声明： interface PrintAttributes<br>差异内容： interface PrintAttributes|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintAttributes；<br>API声明：copyNumber?: number;<br>差异内容：copyNumber?: number;|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintAttributes；<br>API声明：pageRange?: PrinterRange;<br>差异内容：pageRange?: PrinterRange;|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintAttributes；<br>API声明：pageSize?: PrintPageSize \| PrintPageType;<br>差异内容：pageSize?: PrintPageSize \| PrintPageType;|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintAttributes；<br>API声明：directionMode?: PrintDirectionMode;<br>差异内容：directionMode?: PrintDirectionMode;|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintAttributes；<br>API声明：colorMode?: PrintColorMode;<br>差异内容：colorMode?: PrintColorMode;|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintAttributes；<br>API声明：duplexMode?: PrintDuplexMode;<br>差异内容：duplexMode?: PrintDuplexMode;|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrinterCapability；<br>API声明：options?: Object;<br>差异内容：options?: Object;|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintJob；<br>API声明：jobSubstate: PrintJobSubState;<br>差异内容：jobSubstate: PrintJobSubState;|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：print；<br>API声明： enum PrintDirectionMode<br>差异内容： enum PrintDirectionMode|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintDirectionMode；<br>API声明：DIRECTION_MODE_AUTO = 0<br>差异内容：DIRECTION_MODE_AUTO = 0|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintDirectionMode；<br>API声明：DIRECTION_MODE_PORTRAIT = 1<br>差异内容：DIRECTION_MODE_PORTRAIT = 1|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintDirectionMode；<br>API声明：DIRECTION_MODE_LANDSCAPE = 2<br>差异内容：DIRECTION_MODE_LANDSCAPE = 2|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：print；<br>API声明： enum PrintColorMode<br>差异内容： enum PrintColorMode|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintColorMode；<br>API声明：COLOR_MODE_MONOCHROME = 0<br>差异内容：COLOR_MODE_MONOCHROME = 0|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintColorMode；<br>API声明：COLOR_MODE_COLOR = 1<br>差异内容：COLOR_MODE_COLOR = 1|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：print；<br>API声明： enum PrintDuplexMode<br>差异内容： enum PrintDuplexMode|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintDuplexMode；<br>API声明：DUPLEX_MODE_NONE = 0<br>差异内容：DUPLEX_MODE_NONE = 0|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintDuplexMode；<br>API声明：DUPLEX_MODE_LONG_EDGE = 1<br>差异内容：DUPLEX_MODE_LONG_EDGE = 1|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintDuplexMode；<br>API声明：DUPLEX_MODE_SHORT_EDGE = 2<br>差异内容：DUPLEX_MODE_SHORT_EDGE = 2|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：print；<br>API声明： enum PrintPageType<br>差异内容： enum PrintPageType|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintPageType；<br>API声明：PAGE_ISO_A3 = 0<br>差异内容：PAGE_ISO_A3 = 0|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintPageType；<br>API声明：PAGE_ISO_A4 = 1<br>差异内容：PAGE_ISO_A4 = 1|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintPageType；<br>API声明：PAGE_ISO_A5 = 2<br>差异内容：PAGE_ISO_A5 = 2|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintPageType；<br>API声明：PAGE_ISO_B5 = 3<br>差异内容：PAGE_ISO_B5 = 3|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintPageType；<br>API声明：PAGE_ISO_C5 = 4<br>差异内容：PAGE_ISO_C5 = 4|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintPageType；<br>API声明：PAGE_ISO_DL = 5<br>差异内容：PAGE_ISO_DL = 5|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintPageType；<br>API声明：PAGE_LETTER = 6<br>差异内容：PAGE_LETTER = 6|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintPageType；<br>API声明：PAGE_LEGAL = 7<br>差异内容：PAGE_LEGAL = 7|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintPageType；<br>API声明：PAGE_PHOTO_4X6 = 8<br>差异内容：PAGE_PHOTO_4X6 = 8|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintPageType；<br>API声明：PAGE_PHOTO_5X7 = 9<br>差异内容：PAGE_PHOTO_5X7 = 9|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintPageType；<br>API声明：PAGE_INT_DL_ENVELOPE = 10<br>差异内容：PAGE_INT_DL_ENVELOPE = 10|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintPageType；<br>API声明：PAGE_B_TABLOID = 11<br>差异内容：PAGE_B_TABLOID = 11|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：print；<br>API声明： enum PrintDocumentAdapterState<br>差异内容： enum PrintDocumentAdapterState|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintDocumentAdapterState；<br>API声明：PREVIEW_DESTROY = 0<br>差异内容：PREVIEW_DESTROY = 0|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintDocumentAdapterState；<br>API声明：PRINT_TASK_SUCCEED = 1<br>差异内容：PRINT_TASK_SUCCEED = 1|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintDocumentAdapterState；<br>API声明：PRINT_TASK_FAIL = 2<br>差异内容：PRINT_TASK_FAIL = 2|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintDocumentAdapterState；<br>API声明：PRINT_TASK_CANCEL = 3<br>差异内容：PRINT_TASK_CANCEL = 3|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintDocumentAdapterState；<br>API声明：PRINT_TASK_BLOCK = 4<br>差异内容：PRINT_TASK_BLOCK = 4|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：print；<br>API声明： enum PrintFileCreationState<br>差异内容： enum PrintFileCreationState|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintFileCreationState；<br>API声明：PRINT_FILE_CREATED = 0<br>差异内容：PRINT_FILE_CREATED = 0|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintFileCreationState；<br>API声明：PRINT_FILE_CREATION_FAILED = 1<br>差异内容：PRINT_FILE_CREATION_FAILED = 1|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintFileCreationState；<br>API声明：PRINT_FILE_CREATED_UNRENDERED = 2<br>差异内容：PRINT_FILE_CREATED_UNRENDERED = 2|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintJobSubState；<br>API声明：PRINT_JOB_BLOCK_ACCOUNT_ERROR = 18<br>差异内容：PRINT_JOB_BLOCK_ACCOUNT_ERROR = 18|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintJobSubState；<br>API声明：PRINT_JOB_BLOCK_PRINT_PERMISSION_ERROR = 19<br>差异内容：PRINT_JOB_BLOCK_PRINT_PERMISSION_ERROR = 19|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintJobSubState；<br>API声明：PRINT_JOB_BLOCK_PRINT_COLOR_PERMISSION_ERROR = 20<br>差异内容：PRINT_JOB_BLOCK_PRINT_COLOR_PERMISSION_ERROR = 20|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintJobSubState；<br>API声明：PRINT_JOB_BLOCK_NETWORK_ERROR = 21<br>差异内容：PRINT_JOB_BLOCK_NETWORK_ERROR = 21|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintJobSubState；<br>API声明：PRINT_JOB_BLOCK_SERVER_CONNECTION_ERROR = 22<br>差异内容：PRINT_JOB_BLOCK_SERVER_CONNECTION_ERROR = 22|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintJobSubState；<br>API声明：PRINT_JOB_BLOCK_LARGE_FILE_ERROR = 23<br>差异内容：PRINT_JOB_BLOCK_LARGE_FILE_ERROR = 23|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintJobSubState；<br>API声明：PRINT_JOB_BLOCK_FILE_PARSING_ERROR = 24<br>差异内容：PRINT_JOB_BLOCK_FILE_PARSING_ERROR = 24|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintJobSubState；<br>API声明：PRINT_JOB_BLOCK_SLOW_FILE_CONVERSION = 25<br>差异内容：PRINT_JOB_BLOCK_SLOW_FILE_CONVERSION = 25|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintJobSubState；<br>API声明：PRINT_JOB_RUNNING_UPLOADING_FILES = 26<br>差异内容：PRINT_JOB_RUNNING_UPLOADING_FILES = 26|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：PrintJobSubState；<br>API声明：PRINT_JOB_RUNNING_CONVERTING_FILES = 27<br>差异内容：PRINT_JOB_RUNNING_CONVERTING_FILES = 27|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：print；<br>API声明：function queryPrintJobList(callback: AsyncCallback\<Array\<PrintJob>>): void;<br>差异内容：function queryPrintJobList(callback: AsyncCallback\<Array\<PrintJob>>): void;|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：print；<br>API声明：function queryPrintJobList(): Promise\<Array\<PrintJob>>;<br>差异内容：function queryPrintJobList(): Promise\<Array\<PrintJob>>;|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：print；<br>API声明：function queryPrintJobById(jobId: string, callback: AsyncCallback\<PrintJob>): void;<br>差异内容：function queryPrintJobById(jobId: string, callback: AsyncCallback\<PrintJob>): void;|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：print；<br>API声明：function queryPrintJobById(jobId: string): Promise\<PrintJob>;<br>差异内容：function queryPrintJobById(jobId: string): Promise\<PrintJob>;|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：print；<br>API声明：function startGettingPrintFile(jobId: string, printAttributes: PrintAttributes, fd: number,<br>    onFileStateChanged: Callback\<PrintFileCreationState>): void;<br>差异内容：function startGettingPrintFile(jobId: string, printAttributes: PrintAttributes, fd: number,<br>    onFileStateChanged: Callback\<PrintFileCreationState>): void;|api\@ohos.print.d.ts|
|新增API|NA|文件名：api\@ohos.print.d.ts；<br>类名：print；<br>API声明：function notifyPrintService(jobId: string, type: 'spooler_closed_for_cancelled' \| 'spooler_closed_for_started'): Promise\<void>;<br>差异内容：function notifyPrintService(jobId: string, type: 'spooler_closed_for_cancelled' \| 'spooler_closed_for_started'): Promise\<void>;|api\@ohos.print.d.ts|
|起始版本有变化|文件名：api\@ohos.print.d.ts；<br>类名：print；<br>API声明： interface PrinterRange<br>差异内容：10|文件名：api\@ohos.print.d.ts；<br>类名：print；<br>API声明： interface PrinterRange<br>差异内容：11|api\@ohos.print.d.ts|
|起始版本有变化|文件名：api\@ohos.print.d.ts；<br>类名：PrinterRange；<br>API声明：startPage?: number;<br>差异内容：10|文件名：api\@ohos.print.d.ts；<br>类名：PrinterRange；<br>API声明：startPage?: number;<br>差异内容：11|api\@ohos.print.d.ts|
|起始版本有变化|文件名：api\@ohos.print.d.ts；<br>类名：PrinterRange；<br>API声明：endPage?: number;<br>差异内容：10|文件名：api\@ohos.print.d.ts；<br>类名：PrinterRange；<br>API声明：endPage?: number;<br>差异内容：11|api\@ohos.print.d.ts|
|起始版本有变化|文件名：api\@ohos.print.d.ts；<br>类名：PrinterRange；<br>API声明：pages?: Array\<number>;<br>差异内容：10|文件名：api\@ohos.print.d.ts；<br>类名：PrinterRange；<br>API声明：pages?: Array\<number>;<br>差异内容：11|api\@ohos.print.d.ts|
|起始版本有变化|文件名：api\@ohos.print.d.ts；<br>类名：print；<br>API声明： interface PrintPageSize<br>差异内容：10|文件名：api\@ohos.print.d.ts；<br>类名：print；<br>API声明： interface PrintPageSize<br>差异内容：11|api\@ohos.print.d.ts|
|起始版本有变化|文件名：api\@ohos.print.d.ts；<br>类名：PrintPageSize；<br>API声明：id: string;<br>差异内容：10|文件名：api\@ohos.print.d.ts；<br>类名：PrintPageSize；<br>API声明：id: string;<br>差异内容：11|api\@ohos.print.d.ts|
|起始版本有变化|文件名：api\@ohos.print.d.ts；<br>类名：PrintPageSize；<br>API声明：name: string;<br>差异内容：10|文件名：api\@ohos.print.d.ts；<br>类名：PrintPageSize；<br>API声明：name: string;<br>差异内容：11|api\@ohos.print.d.ts|
|起始版本有变化|文件名：api\@ohos.print.d.ts；<br>类名：PrintPageSize；<br>API声明：width: number;<br>差异内容：10|文件名：api\@ohos.print.d.ts；<br>类名：PrintPageSize；<br>API声明：width: number;<br>差异内容：11|api\@ohos.print.d.ts|
|起始版本有变化|文件名：api\@ohos.print.d.ts；<br>类名：PrintPageSize；<br>API声明：height: number;<br>差异内容：10|文件名：api\@ohos.print.d.ts；<br>类名：PrintPageSize；<br>API声明：height: number;<br>差异内容：11|api\@ohos.print.d.ts|
