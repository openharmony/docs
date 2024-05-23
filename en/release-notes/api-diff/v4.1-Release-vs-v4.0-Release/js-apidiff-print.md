| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|API added|NA|Class name: print;<br>API declaration: function print(files: Array\<string>, context: Context, callback: AsyncCallback\<PrintTask>): void;<br>Differences: function print(files: Array\<string>, context: Context, callback: AsyncCallback\<PrintTask>): void;|api/@ohos.print.d.ts|
|API added|NA|Class name: print;<br>API declaration: function print(files: Array\<string>, context: Context): Promise\<PrintTask>;<br>Differences: function print(files: Array\<string>, context: Context): Promise\<PrintTask>;|api/@ohos.print.d.ts|
|API added|NA|Class name: print;<br>API declaration: function print(jobName: string, printAdapter: PrintDocumentAdapter, printAttributes: PrintAttributes, context: Context): Promise\<PrintTask>;<br>Differences: function print(jobName: string, printAdapter: PrintDocumentAdapter, printAttributes: PrintAttributes, context: Context): Promise\<PrintTask>;|api/@ohos.print.d.ts|
|API added|NA|Class name: print;<br>API declaration:  interface PrintDocumentAdapter<br>Differences:  interface PrintDocumentAdapter|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintDocumentAdapter;<br>API declaration: onStartLayoutWrite(jobId: string, oldAttrs: PrintAttributes, newAttrs: PrintAttributes, fd: number, writeResultCallback: (jobId: string, writeResult: PrintFileCreationState) => void): void;<br>Differences: onStartLayoutWrite(jobId: string, oldAttrs: PrintAttributes, newAttrs: PrintAttributes, fd: number, writeResultCallback: (jobId: string, writeResult: PrintFileCreationState) => void): void;|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintDocumentAdapter;<br>API declaration: onJobStateChanged(jobId: string, state: PrintDocumentAdapterState): void;<br>Differences: onJobStateChanged(jobId: string, state: PrintDocumentAdapterState): void;|api/@ohos.print.d.ts|
|API added|NA|Class name: print;<br>API declaration:  interface PrintAttributes<br>Differences:  interface PrintAttributes|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintAttributes;<br>API declaration: copyNumber?: number;<br>Differences: copyNumber?: number;|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintAttributes;<br>API declaration: pageRange?: PrintPageRange;<br>Differences: pageRange?: PrintPageRange;|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintAttributes;<br>API declaration: pageSize?: PrintPageSize \| PrintPageType;<br>Differences: pageSize?: PrintPageSize \| PrintPageType;|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintAttributes;<br>API declaration: directionMode?: PrintDirectionMode;<br>Differences: directionMode?: PrintDirectionMode;|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintAttributes;<br>API declaration: colorMode?: PrintColorMode;<br>Differences: colorMode?: PrintColorMode;|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintAttributes;<br>API declaration: duplexMode?: PrintDuplexMode;<br>Differences: duplexMode?: PrintDuplexMode;|api/@ohos.print.d.ts|
|API added|NA|Class name: print;<br>API declaration:  interface PrintPageRange<br>Differences:  interface PrintPageRange|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintPageRange;<br>API declaration: startPage?: number;<br>Differences: startPage?: number;|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintPageRange;<br>API declaration: endPage?: number;<br>Differences: endPage?: number;|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintPageRange;<br>API declaration: pages?: Array\<number>;<br>Differences: pages?: Array\<number>;|api/@ohos.print.d.ts|
|API added|NA|Class name: print;<br>API declaration:  interface PrintPageSize<br>Differences:  interface PrintPageSize|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintPageSize;<br>API declaration: id: string;<br>Differences: id: string;|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintPageSize;<br>API declaration: name: string;<br>Differences: name: string;|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintPageSize;<br>API declaration: width: number;<br>Differences: width: number;|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintPageSize;<br>API declaration: height: number;<br>Differences: height: number;|api/@ohos.print.d.ts|
|API added|NA|Class name: print;<br>API declaration:  enum PrintDirectionMode<br>Differences:  enum PrintDirectionMode|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintDirectionMode;<br>API declaration: DIRECTION_MODE_AUTO = 0<br>Differences: DIRECTION_MODE_AUTO = 0|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintDirectionMode;<br>API declaration: DIRECTION_MODE_PORTRAIT = 1<br>Differences: DIRECTION_MODE_PORTRAIT = 1|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintDirectionMode;<br>API declaration: DIRECTION_MODE_LANDSCAPE = 2<br>Differences: DIRECTION_MODE_LANDSCAPE = 2|api/@ohos.print.d.ts|
|API added|NA|Class name: print;<br>API declaration:  enum PrintColorMode<br>Differences:  enum PrintColorMode|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintColorMode;<br>API declaration: COLOR_MODE_MONOCHROME = 0<br>Differences: COLOR_MODE_MONOCHROME = 0|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintColorMode;<br>API declaration: COLOR_MODE_COLOR = 1<br>Differences: COLOR_MODE_COLOR = 1|api/@ohos.print.d.ts|
|API added|NA|Class name: print;<br>API declaration:  enum PrintDuplexMode<br>Differences:  enum PrintDuplexMode|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintDuplexMode;<br>API declaration: DUPLEX_MODE_NONE = 0<br>Differences: DUPLEX_MODE_NONE = 0|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintDuplexMode;<br>API declaration: DUPLEX_MODE_LONG_EDGE = 1<br>Differences: DUPLEX_MODE_LONG_EDGE = 1|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintDuplexMode;<br>API declaration: DUPLEX_MODE_SHORT_EDGE = 2<br>Differences: DUPLEX_MODE_SHORT_EDGE = 2|api/@ohos.print.d.ts|
|API added|NA|Class name: print;<br>API declaration:  enum PrintPageType<br>Differences:  enum PrintPageType|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintPageType;<br>API declaration: PAGE_ISO_A3 = 0<br>Differences: PAGE_ISO_A3 = 0|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintPageType;<br>API declaration: PAGE_ISO_A4 = 1<br>Differences: PAGE_ISO_A4 = 1|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintPageType;<br>API declaration: PAGE_ISO_A5 = 2<br>Differences: PAGE_ISO_A5 = 2|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintPageType;<br>API declaration: PAGE_JIS_B5 = 3<br>Differences: PAGE_JIS_B5 = 3|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintPageType;<br>API declaration: PAGE_ISO_C5 = 4<br>Differences: PAGE_ISO_C5 = 4|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintPageType;<br>API declaration: PAGE_ISO_DL = 5<br>Differences: PAGE_ISO_DL = 5|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintPageType;<br>API declaration: PAGE_LETTER = 6<br>Differences: PAGE_LETTER = 6|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintPageType;<br>API declaration: PAGE_LEGAL = 7<br>Differences: PAGE_LEGAL = 7|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintPageType;<br>API declaration: PAGE_PHOTO_4X6 = 8<br>Differences: PAGE_PHOTO_4X6 = 8|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintPageType;<br>API declaration: PAGE_PHOTO_5X7 = 9<br>Differences: PAGE_PHOTO_5X7 = 9|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintPageType;<br>API declaration: PAGE_INT_DL_ENVELOPE = 10<br>Differences: PAGE_INT_DL_ENVELOPE = 10|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintPageType;<br>API declaration: PAGE_B_TABLOID = 11<br>Differences: PAGE_B_TABLOID = 11|api/@ohos.print.d.ts|
|API added|NA|Class name: print;<br>API declaration:  enum PrintDocumentAdapterState<br>Differences:  enum PrintDocumentAdapterState|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintDocumentAdapterState;<br>API declaration: PREVIEW_DESTROY = 0<br>Differences: PREVIEW_DESTROY = 0|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintDocumentAdapterState;<br>API declaration: PRINT_TASK_SUCCEED = 1<br>Differences: PRINT_TASK_SUCCEED = 1|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintDocumentAdapterState;<br>API declaration: PRINT_TASK_FAIL = 2<br>Differences: PRINT_TASK_FAIL = 2|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintDocumentAdapterState;<br>API declaration: PRINT_TASK_CANCEL = 3<br>Differences: PRINT_TASK_CANCEL = 3|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintDocumentAdapterState;<br>API declaration: PRINT_TASK_BLOCK = 4<br>Differences: PRINT_TASK_BLOCK = 4|api/@ohos.print.d.ts|
|API added|NA|Class name: print;<br>API declaration:  enum PrintFileCreationState<br>Differences:  enum PrintFileCreationState|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintFileCreationState;<br>API declaration: PRINT_FILE_CREATED = 0<br>Differences: PRINT_FILE_CREATED = 0|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintFileCreationState;<br>API declaration: PRINT_FILE_CREATION_FAILED = 1<br>Differences: PRINT_FILE_CREATION_FAILED = 1|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintFileCreationState;<br>API declaration: PRINT_FILE_CREATED_UNRENDERED = 2<br>Differences: PRINT_FILE_CREATED_UNRENDERED = 2|api/@ohos.print.d.ts|
|Kit changed|NA|BasicServicesKit|api/@ohos.print.d.ts|
