# 剪贴板术语
<!--Kit: Basic Services Kit-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @yangxiaodong41-->
<!--Designer: @zhusiyuan2-->
<!--Tester: @maxiaorong-->
<!--Adviser: @fang-jinxu-->

## E

### Entry；数据条目

剪贴板记录中的一种数据表示形式，对应同一份数据的不同格式，用于支持富文本、多媒体内容的多格式粘贴场景以及应用间的数据兼容性传递。

## M

### MIME Type；MIME类型

多用途互联网邮件扩展类型(Multipurpose Internet Mail Extensions Type)，用于标识剪贴板数据格式类型的标准规范。在剪贴板中定义了text/plain(纯文本)、text/html(HTML)、text/uri(URI)、text/want(Want)、pixelMap(像素图)等标准类型，开发者也可自定义类型(长度不超过1024字节)，用于数据读写时指定和匹配数据格式以确保正确的解析处理。

## P

### PixelMap；像素图

表示图像像素数据的数据结构类型。在剪贴板中作为pixelMap MIME类型的数据内容，用于复制粘贴图片或图像数据，支持跨应用的图片内容传递，区别于文本和URI格式的二进制图像数据表示，可通过image.PixelMap接口创建和管理。

## R

### Record；记录

剪贴板数据内容的最小组成单元。对应复制数据的不同内容片段。用于支持单一剪贴板内容承载多种数据格式，实现复杂数据的复制粘贴场景。在C API中通过OH_UdmfRecord表示，在ArkTS API中通过PasteDataRecord表示。

## U

### URI；统一资源标识符

统一资源标识符(Uniform Resource Identifier)，用于标识文件或资源位置的标准字符串格式。在剪贴板中作为text/uri MIME类型的数据内容，用于复制粘贴文件路径、数据路径等资源引用，支持跨应用传递文件或数据的访问路径，区别于直接传递文件内容的引用传递方式，需符合标准URI格式规范（如http://、file://等）。

## W

### Want；意图对象

OpenHarmony系统中用于组件间通信和信息传递的意图对象数据结构。在剪贴板中作为text/want MIME类型的数据内容，用于复制粘贴组件启动参数、能力跳转信息等意图数据，支持跨应用的组件调用和能力传递，包含bundleName、abilityName等字段的结构化数据对象，区别于纯文本的结构化意图信息表示。