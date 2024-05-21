| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Attribute changed|Class name: PrintAttributes;<br>API declaration: pageRange?: PrinterRange;<br>Differences: PrinterRange|Class name: PrintAttributes;<br>API declaration: pageRange?: PrintPageRange;<br>Differences: PrintPageRange|api/@ohos.print.d.ts|
|API added|NA|Class name: print;<br>API declaration:  interface PrintPageRange<br>Differences:  interface PrintPageRange|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintPageRange;<br>API declaration: startPage?: number;<br>Differences: startPage?: number;|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintPageRange;<br>API declaration: endPage?: number;<br>Differences: endPage?: number;|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintPageRange;<br>API declaration: pages?: Array\<number>;<br>Differences: pages?: Array\<number>;|api/@ohos.print.d.ts|
|API added|NA|Class name: PrintPageType;<br>API declaration: PAGE_JIS_B5 = 3<br>Differences: PAGE_JIS_B5 = 3|api/@ohos.print.d.ts|
|API deleted|Class name: print;<br>API declaration:  interface PrinterRange<br>Differences:  interface PrinterRange|NA|api/@ohos.print.d.ts|
|API deleted|Class name: PrinterRange;<br>API declaration: startPage?: number;<br>Differences: startPage?: number;|NA|api/@ohos.print.d.ts|
|API deleted|Class name: PrinterRange;<br>API declaration: endPage?: number;<br>Differences: endPage?: number;|NA|api/@ohos.print.d.ts|
|API deleted|Class name: PrinterRange;<br>API declaration: pages?: Array\<number>;<br>Differences: pages?: Array\<number>;|NA|api/@ohos.print.d.ts|
|API deleted|Class name: PrintPageType;<br>API declaration: PAGE_ISO_B5 = 3<br>Differences: PAGE_ISO_B5 = 3|NA|api/@ohos.print.d.ts|
|Kit changed|Basic Services Kit|BasicServicesKit|api/@ohos.print.d.ts|
