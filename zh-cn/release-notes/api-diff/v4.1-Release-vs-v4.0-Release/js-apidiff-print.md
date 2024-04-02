| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增API|NA|类名：print；<br>API声明：function print(files: Array\<string>, context: Context, callback: AsyncCallback\<PrintTask>): void;<br>差异内容：function print(files: Array\<string>, context: Context, callback: AsyncCallback\<PrintTask>): void;|api/@ohos.print.d.ts|
|新增API|NA|类名：print；<br>API声明：function print(files: Array\<string>, context: Context): Promise\<PrintTask>;<br>差异内容：function print(files: Array\<string>, context: Context): Promise\<PrintTask>;|api/@ohos.print.d.ts|
|新增API|NA|类名：print；<br>API声明：function print(jobName: string, printAdapter: PrintDocumentAdapter, printAttributes: PrintAttributes, context: Context): Promise\<PrintTask>;<br>差异内容：function print(jobName: string, printAdapter: PrintDocumentAdapter, printAttributes: PrintAttributes, context: Context): Promise\<PrintTask>;|api/@ohos.print.d.ts|
|新增API|NA|类名：print；<br>API声明： interface PrintDocumentAdapter<br>差异内容： interface PrintDocumentAdapter|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintDocumentAdapter；<br>API声明：onStartLayoutWrite(jobId: string, oldAttrs: PrintAttributes, newAttrs: PrintAttributes, fd: number, writeResultCallback: (jobId: string, writeResult: PrintFileCreationState) => void): void;<br>差异内容：onStartLayoutWrite(jobId: string, oldAttrs: PrintAttributes, newAttrs: PrintAttributes, fd: number, writeResultCallback: (jobId: string, writeResult: PrintFileCreationState) => void): void;|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintDocumentAdapter；<br>API声明：onJobStateChanged(jobId: string, state: PrintDocumentAdapterState): void;<br>差异内容：onJobStateChanged(jobId: string, state: PrintDocumentAdapterState): void;|api/@ohos.print.d.ts|
|新增API|NA|类名：print；<br>API声明： interface PrintAttributes<br>差异内容： interface PrintAttributes|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintAttributes；<br>API声明：copyNumber?: number;<br>差异内容：copyNumber?: number;|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintAttributes；<br>API声明：pageRange?: PrintPageRange;<br>差异内容：pageRange?: PrintPageRange;|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintAttributes；<br>API声明：pageSize?: PrintPageSize \| PrintPageType;<br>差异内容：pageSize?: PrintPageSize \| PrintPageType;|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintAttributes；<br>API声明：directionMode?: PrintDirectionMode;<br>差异内容：directionMode?: PrintDirectionMode;|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintAttributes；<br>API声明：colorMode?: PrintColorMode;<br>差异内容：colorMode?: PrintColorMode;|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintAttributes；<br>API声明：duplexMode?: PrintDuplexMode;<br>差异内容：duplexMode?: PrintDuplexMode;|api/@ohos.print.d.ts|
|新增API|NA|类名：print；<br>API声明： interface PrintPageRange<br>差异内容： interface PrintPageRange|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintPageRange；<br>API声明：startPage?: number;<br>差异内容：startPage?: number;|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintPageRange；<br>API声明：endPage?: number;<br>差异内容：endPage?: number;|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintPageRange；<br>API声明：pages?: Array\<number>;<br>差异内容：pages?: Array\<number>;|api/@ohos.print.d.ts|
|新增API|NA|类名：print；<br>API声明： interface PrintPageSize<br>差异内容： interface PrintPageSize|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintPageSize；<br>API声明：id: string;<br>差异内容：id: string;|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintPageSize；<br>API声明：name: string;<br>差异内容：name: string;|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintPageSize；<br>API声明：width: number;<br>差异内容：width: number;|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintPageSize；<br>API声明：height: number;<br>差异内容：height: number;|api/@ohos.print.d.ts|
|新增API|NA|类名：print；<br>API声明： enum PrintDirectionMode<br>差异内容： enum PrintDirectionMode|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintDirectionMode；<br>API声明：DIRECTION_MODE_AUTO = 0<br>差异内容：DIRECTION_MODE_AUTO = 0|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintDirectionMode；<br>API声明：DIRECTION_MODE_PORTRAIT = 1<br>差异内容：DIRECTION_MODE_PORTRAIT = 1|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintDirectionMode；<br>API声明：DIRECTION_MODE_LANDSCAPE = 2<br>差异内容：DIRECTION_MODE_LANDSCAPE = 2|api/@ohos.print.d.ts|
|新增API|NA|类名：print；<br>API声明： enum PrintColorMode<br>差异内容： enum PrintColorMode|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintColorMode；<br>API声明：COLOR_MODE_MONOCHROME = 0<br>差异内容：COLOR_MODE_MONOCHROME = 0|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintColorMode；<br>API声明：COLOR_MODE_COLOR = 1<br>差异内容：COLOR_MODE_COLOR = 1|api/@ohos.print.d.ts|
|新增API|NA|类名：print；<br>API声明： enum PrintDuplexMode<br>差异内容： enum PrintDuplexMode|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintDuplexMode；<br>API声明：DUPLEX_MODE_NONE = 0<br>差异内容：DUPLEX_MODE_NONE = 0|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintDuplexMode；<br>API声明：DUPLEX_MODE_LONG_EDGE = 1<br>差异内容：DUPLEX_MODE_LONG_EDGE = 1|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintDuplexMode；<br>API声明：DUPLEX_MODE_SHORT_EDGE = 2<br>差异内容：DUPLEX_MODE_SHORT_EDGE = 2|api/@ohos.print.d.ts|
|新增API|NA|类名：print；<br>API声明： enum PrintPageType<br>差异内容： enum PrintPageType|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintPageType；<br>API声明：PAGE_ISO_A3 = 0<br>差异内容：PAGE_ISO_A3 = 0|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintPageType；<br>API声明：PAGE_ISO_A4 = 1<br>差异内容：PAGE_ISO_A4 = 1|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintPageType；<br>API声明：PAGE_ISO_A5 = 2<br>差异内容：PAGE_ISO_A5 = 2|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintPageType；<br>API声明：PAGE_JIS_B5 = 3<br>差异内容：PAGE_JIS_B5 = 3|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintPageType；<br>API声明：PAGE_ISO_C5 = 4<br>差异内容：PAGE_ISO_C5 = 4|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintPageType；<br>API声明：PAGE_ISO_DL = 5<br>差异内容：PAGE_ISO_DL = 5|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintPageType；<br>API声明：PAGE_LETTER = 6<br>差异内容：PAGE_LETTER = 6|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintPageType；<br>API声明：PAGE_LEGAL = 7<br>差异内容：PAGE_LEGAL = 7|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintPageType；<br>API声明：PAGE_PHOTO_4X6 = 8<br>差异内容：PAGE_PHOTO_4X6 = 8|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintPageType；<br>API声明：PAGE_PHOTO_5X7 = 9<br>差异内容：PAGE_PHOTO_5X7 = 9|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintPageType；<br>API声明：PAGE_INT_DL_ENVELOPE = 10<br>差异内容：PAGE_INT_DL_ENVELOPE = 10|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintPageType；<br>API声明：PAGE_B_TABLOID = 11<br>差异内容：PAGE_B_TABLOID = 11|api/@ohos.print.d.ts|
|新增API|NA|类名：print；<br>API声明： enum PrintDocumentAdapterState<br>差异内容： enum PrintDocumentAdapterState|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintDocumentAdapterState；<br>API声明：PREVIEW_DESTROY = 0<br>差异内容：PREVIEW_DESTROY = 0|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintDocumentAdapterState；<br>API声明：PRINT_TASK_SUCCEED = 1<br>差异内容：PRINT_TASK_SUCCEED = 1|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintDocumentAdapterState；<br>API声明：PRINT_TASK_FAIL = 2<br>差异内容：PRINT_TASK_FAIL = 2|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintDocumentAdapterState；<br>API声明：PRINT_TASK_CANCEL = 3<br>差异内容：PRINT_TASK_CANCEL = 3|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintDocumentAdapterState；<br>API声明：PRINT_TASK_BLOCK = 4<br>差异内容：PRINT_TASK_BLOCK = 4|api/@ohos.print.d.ts|
|新增API|NA|类名：print；<br>API声明： enum PrintFileCreationState<br>差异内容： enum PrintFileCreationState|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintFileCreationState；<br>API声明：PRINT_FILE_CREATED = 0<br>差异内容：PRINT_FILE_CREATED = 0|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintFileCreationState；<br>API声明：PRINT_FILE_CREATION_FAILED = 1<br>差异内容：PRINT_FILE_CREATION_FAILED = 1|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintFileCreationState；<br>API声明：PRINT_FILE_CREATED_UNRENDERED = 2<br>差异内容：PRINT_FILE_CREATED_UNRENDERED = 2|api/@ohos.print.d.ts|
|kit变更|NA|BasicServicesKit|api/@ohos.print.d.ts|
