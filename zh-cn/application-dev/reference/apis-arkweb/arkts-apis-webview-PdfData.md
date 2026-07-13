# Class (PdfData)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zhang-yinglie-->
<!--Designer: @handyohos-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

PdfData是Web组件用于封装网页生成的PDF数据流的类。当应用需要将Web组件加载的网页内容以PDF格式保存时，通过[WebviewController](./arkts-apis-webview-WebviewController.md)的[createPdf](./arkts-apis-webview-WebviewController.md#createpdf14)方法将网页内容转换为PDF数据流，该方法在回调或Promise中以PdfData对象返回。应用再通过PdfData的pdfArrayBuffer方法获取Uint8Array格式的数据流，结合文件IO接口将数据写入本地PDF文件。

PDF数据生成流程如下图所示：

```mermaid
graph LR
    A[加载Web组件并渲染网页] --> B[调用createPdf生成PDF数据流]
    B --> C[回调或Promise返回PdfData对象]
    C --> D[调用pdfArrayBuffer获取Uint8Array]
    D --> E[通过文件IO接口写入本地PDF文件]
```

PdfData适用于需要离线保存网页内容、生成网页PDF报告等场景。使用时需先加载Web组件并确保网页内容已渲染完成，再调用createPdf生成PDF数据流。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本Class首批接口从API version 14开始支持。
>
> - 示例效果请以真机运行为准。
>
> - 在网页生成PDF过程中，返回的是数据流，由PdfData类封装。

## pdfArrayBuffer<sup>14+</sup>

pdfArrayBuffer(): Uint8Array

获取网页生成的PDF数据流。完整示例代码参考[createPdf](./arkts-apis-webview-WebviewController.md#createpdf14)。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型       | 说明     |
| ---------- | -------- |
| Uint8Array | 网页生成的PDF数据流，可结合文件IO接口将数据写入本地PDF文件。 |
