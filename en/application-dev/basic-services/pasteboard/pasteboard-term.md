# Clipboard Glossary

<!--Kit: Basic Services Kit-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @yangxiaodong41-->
<!--Designer: @guo867-->
<!--Tester: @maxiaorong-->
<!--Adviser: @fang-jinxu-->
<!-- md-trans-meta sourceCommit=60d9d26e148b855695daa12aaed8d7a59c39045c translatedAt=2026-07-28T07:31:44.410Z pushedAt=2026-07-30T12:20:38.121Z -->

## E

### Entry

A data representation form in a clipboard record, corresponding to different formats of the same data. It is used to support multi-format paste scenarios for rich text and multimedia content, as well as cross-app data compatibility transfer.

## M

### MIME Type

Multipurpose Internet Mail Extensions Type, a standard specification used to identify the data format type of clipboard content. In the clipboard, standard types such as text/plain (plain text), text/html (HTML), text/uri (URI), text/want (Want), and pixelMap (pixel map) are defined. Developers can also define custom types (with a length not exceeding 1024 bytes) for specifying and matching data formats during data read/write to ensure correct parsing and processing.

## P

### PixelMap

A data structure type that represents image pixel data. In the clipboard, it serves as the data content of the pixelMap MIME type, used for copying and pasting pictures or image data. It supports cross-app image content transfer and is distinct from binary image data representations in text and URI formats. It can be created and managed through the image.PixelMap API.

## R

### Record

The smallest unit of clipboard data content. It corresponds to different content segments of copied data. It enables a single clipboard content item to carry multiple data formats, supporting complex data copy and paste scenarios. In the C API, it is represented by OH_UdmfRecord, and in the ArkTS API, it is represented by PasteDataRecord.

## U

### URI

Uniform Resource Identifier (URI), a standard string format for identifying file or resource locations. In the clipboard, it serves as the data content of the text/uri MIME type, used for copying and pasting resource references such as file paths and data paths. It supports cross-app transfer of file or data access paths, which is a reference-based transfer method distinct from directly transferring file content. The URI must conform to standard URI format specifications (for example, http://, file://).

## W

### Want

An intent object data structure used for inter-component communication and information transfer in the OpenHarmony system. In the clipboard, it serves as the data content of the text/want MIME type, used for copying and pasting intent data such as component startup parameters and ability navigation information. It supports cross-app component invocation and capability transfer. It is a structured data object containing fields such as bundleName and abilityName, representing structured intent information distinct from plain text.