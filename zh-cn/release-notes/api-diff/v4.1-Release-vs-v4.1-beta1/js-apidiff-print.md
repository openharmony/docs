| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|属性变更|类名：PrintAttributes；<br>API声明：pageRange?: PrinterRange;<br>差异内容：PrinterRange|类名：PrintAttributes；<br>API声明：pageRange?: PrintPageRange;<br>差异内容：PrintPageRange|api/@ohos.print.d.ts|
|新增API|NA|类名：print；<br>API声明： interface PrintPageRange<br>差异内容： interface PrintPageRange|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintPageRange；<br>API声明：startPage?: number;<br>差异内容：startPage?: number;|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintPageRange；<br>API声明：endPage?: number;<br>差异内容：endPage?: number;|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintPageRange；<br>API声明：pages?: Array\<number>;<br>差异内容：pages?: Array\<number>;|api/@ohos.print.d.ts|
|新增API|NA|类名：PrintPageType；<br>API声明：PAGE_JIS_B5 = 3<br>差异内容：PAGE_JIS_B5 = 3|api/@ohos.print.d.ts|
|删除API|类名：print；<br>API声明： interface PrinterRange<br>差异内容： interface PrinterRange|NA|api/@ohos.print.d.ts|
|删除API|类名：PrinterRange；<br>API声明：startPage?: number;<br>差异内容：startPage?: number;|NA|api/@ohos.print.d.ts|
|删除API|类名：PrinterRange；<br>API声明：endPage?: number;<br>差异内容：endPage?: number;|NA|api/@ohos.print.d.ts|
|删除API|类名：PrinterRange；<br>API声明：pages?: Array\<number>;<br>差异内容：pages?: Array\<number>;|NA|api/@ohos.print.d.ts|
|删除API|类名：PrintPageType；<br>API声明：PAGE_ISO_B5 = 3<br>差异内容：PAGE_ISO_B5 = 3|NA|api/@ohos.print.d.ts|
|kit变更|Basic Services Kit|BasicServicesKit|api/@ohos.print.d.ts|
