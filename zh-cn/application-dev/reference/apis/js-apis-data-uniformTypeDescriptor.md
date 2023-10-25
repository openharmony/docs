# @ohos.data.uniformTypeDescriptor (标准化数据定义与描述)

本模块描述OpenHarmony标准化数据类型的抽象定义。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import uniformTypeDescriptor from '@ohos.data.uniformTypeDescriptor';
```

## UniformDataType

OpenHarmony标准化数据类型的枚举定义。

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

| 名称                         | 值                            | 说明        | 归属类型 |
|----------------------------|------------------------------|-----------|-------------------------------------------------------------------------|
| TEXT                       | 'general.text'                   | 所有文本的基本类型。     |TEXT|
| PLAIN_TEXT                 | 'general.plain-text'             | 未指定编码的文本类型，没有标记。等效于MIME类型text/plain    |TEXT|
| HTML                       | 'general.html'                   | HTML文本类型。    |TEXT|
| HYPERLINK                  | 'general.hyperlink'              | 超链接类型。    |TEXT|
| XML                        | 'general.xml'                   | XML文本类型。     |TEXT|
| SOURCE_CODE                      | 'general.source-code'                  | 通用源代码类型。     |PLAIN_TEXT|
| SCRIPT                       | 'general.script'                  | 脚本语言源代码基本类型。     |SOURCE_CODE|
| SHELL_SCRIPT                       | 'general.shell-script'                  | shell脚本类型。 |SCRIPT|    
| CSH_SCRIPT                      | 'general.csh-script'                 | C-shell脚本类型。    |SHELL_SCRIPT|
| PERL_SCRIPT            | 'general.perl-script'               | Perl脚本类型。     |SHELL_SCRIPT|
| PHP_SCRIPT        | 'general.php-script'           | PHP脚本类型。     |SHELL_SCRIPT|
| PYTHON_SCRIPT       | 'general.python-script'          | Python脚本类型。  |SHELL_SCRIPT|
| RUBY_SCRIPT                        | 'general.ruby-script'                   | Ruby脚本类型。     |SHELL_SCRIPT|
| TYPE_SCRIPT                       | 'general.type-script'                  | TypeScript源代码类型。     |SOURCE_CODE|
| JAVA_SCRIPT                       | 'general.java-script'                  | JavaScript源代码类型。     |SOURCE_CODE|
| C_HEADER                       | 'general.c-header'                  | C头文件类型。     |SOURCE_CODE|
| C_SOURCE                      | 'general.c-source'                 | C源代码类型。    |SOURCE_CODE|
| C_PLUS_PLUS_HEADER            | 'general.c-plus-plus-header'               | C++头文件类型。     |SOURCE_CODE|
| C_PLUS_PLUS_SOURCE        | 'general.c-plus-plus-source'           | C++源代码类型。     |SOURCE_CODE|
| JAVA_SOURCE       | 'general.java-source'          | Java源代码类型。  |SOURCE_CODE|
| EBOOK                        | 'general.ebook'                   | 电子书基本类型。     ||
| EPUB                       | 'general.epub'                  | 电子出版物（EPUB）格式类型。     |EBOOK|
| AZW                       | 'com.amazon.azw'                  | AZW电子书类型。     |EBOOK|
| AZW3                       | 'com.amazon.azw3'                  | AZW3电子书类型。     |EBOOK|
| KFX                      | 'com.amazon.kfx'                 | KFX电子书类型。    |EBOOK|
| MOBI            | 'com.amazon.mobi'               | MOBI电子书类型。     |EBOOK|
| MEDIA        | 'general.media'           | 媒体基本类型。     ||
| IMAGE       | 'general.image'          | 图片基本类型。  |MEDIA|
| JPEG                        | 'general.jpeg'                   | JPEG图片类型。     |IMAGE|
| PNG                       | 'general.png'                  | PNG图片类型。     |IMAGE|
| RAW_IMAGE                       | 'general.raw-image'                  | 数码相机原始图像格式基本类型。     |IMAGE|
| TIFF                       | 'general.tiff'                  | TIFF图片类型。     |IMAGE|
| BMP                      | 'com.microsoft.bmp'                 | WINDOWS位图图像类型。    |IMAGE|
| ICO            | 'com.microsoft.ico'               | WINDOWS图标图像类型。     |IMAGE|
| PHOTOSHOP_IMAGE        | 'com.adobe.photoshop-image'           | Adobe Photoshop文档类型。     |IMAGE|
| AI_IMAGE       | 'com.adobe.illustrator.ai-image'          | Adobe Illustrator文档类型。  |IMAGE|
| WORD_DOC                        | 'com.microsoft.word.doc'                   | Microsoft Word数据类型。     ||
| EXCEL                       | 'com.microsoft.excel.xls'                  | Microsoft Excel     ||
| PPT                       | 'com.microsoft.powerpoint.ppt'                  | Microsoft PowerPoint演示文稿类型。     ||
| PDF                       | 'com.adobe.pdf'                  | PDF数据类型。     ||
| POSTSCRIPT                      | 'com.adobe.postscript'                 | PostScript数据类型。    ||
| ENCAPSULATED_POSTSCRIPT            | 'com.adobe.encapsulated-postscript'               | Encapsulated PostScript类型。     ||
| VIDEO        | 'general.video'           | 基本的视频类型。     |MEDIA|
| AVI       | 'general.avi'          | AVI电影类型。  |VIDEO|
| MPEG                        | 'general.mpeg'                   | MPGE-1或MPGE-2内容类型。     |VIDEO|
| MPEG4                       | 'general.mpeg-4'                  | MPGE-4内容类型。     |VIDEO|
| VIDEO_3GPP                       | 'general.3gpp'                  | 3GPP电影类型。     |VIDEO|
| VIDEO_3GPP2                       | 'general.3gpp2'                  | 音频类型。     |VIDEO|
| WINDOWS_MEDIA_WM                      | 'com.microsoft.windows-media-wm'                 | WINDOWS WM视频类型。    |VIDEO|
| WINDOWS_MEDIA_WMV            | 'com.microsoft.windows-media-wmv'               | WINDOWS WMV视频类型。     |VIDEO|
| WINDOWS_MEDIA_WMP        | 'com.microsoft.windows-media-wmp'           | WINDOWS WMP视频类型。     |VIDEO|
| AUDIO       | 'general.audio'          | 音频的基本类型。  |MEDIA|
| AAC                        | 'general.aac'                   | AAC音频类型。     |AUDIO|
| AIFF                       | 'general.aiff'                  | AIFF音频类型。     |AUDIO|
| ALAC                       | 'general.alac'                  | ALAC音频类型。     |AUDIO|
| FLAC                       | 'general.flac'                  | FLAC音频类型。     |AUDIO|
| MP3                      | 'general.mp3'                 | MP3音频类型。    |AUDIO|
| OGG             | 'general.ogg'               | OGG音频类型。     |AUDIO|
| PCM        | 'general.pcm'           | PCM音频类型。     |AUDIO|
| WINDOWS_MEDIA_WMA       | 'com.microsoft.windows-media-wma'          | WINDOWS WMA音频类型。  |AUDIO|
| WAVEFORM_AUDIO                        | 'com.microsoft.waveform-audio'                   | 波形音频类型。     |AUDIO|
| WINDOWS_MEDIA_WMX                       | 'com.microsoft.windows-media-wmx'                  | WINDOWS WMX视频类型。     |AUDIO|
| WINDOWS_MEDIA_WVX                       | 'com.microsoft.windows-media-wvx'                  | WINDOWS WVX视频类型。     |AUDIO|
| WINDOWS_MEDIA_WAX                       | 'com.microsoft.windows-media-wax'                  | WINDOWS WAX视频类型。     |AUDIO|
| FILE                      | 'general.file'                 | 文件基本类型。    ||
| DIRECTORY            | 'general.directory'               | 目录的类型。     ||
| FOLDER        | 'general.folder'           | 文件夹基本类型。     ||
| SYMLINK       | 'general.symlink'          | 符号链接的类型。  ||
| ARCHIVE                        | 'general.archive'                   | 文件和目录存档基本类型。     ||
| BZ2_ARCHIVE                       | 'general.bz2-archive'                  | BZ2存档类型。     |ARCHIVE|
| DISK_IMAGE                       | 'general.disk-image'                  | 可作为卷装载项的基本类型。     |ARCHIVE|
| TAR_ARCHIVE                       | 'general.tar-archive'                  | TAR存档类型。     |ARCHIVE|
| ZIP_ARCHIVE                      | 'general.zip-archive'                 | ZIP存档类型。    |ARCHIVE|
| JAVA_ARCHIVE            | 'com.sun.java-archive'               | JAVA存档类型。     |ARCHIVE|
| GNU_TAR_ARCHIVE        | 'org.gnu.gnu-tar-archive'           | GUN存档类型。     |ARCHIVE|
| GNU_ZIP_ARCHIVE       | 'org.gnu.gnu-zip-archive'          | GZIP存档类型。  |ARCHIVE|
| GNU_ZIP_TAR_ARCHIVE                        | 'org.gnu.gnu-zip-tar-archive'                   | GZIP TAR存档类型。     |ARCHIVE|
| CALENDAR                       | 'general.calendar'                  | 计划事件的基本类型。     ||
| CONTACT                       | 'general.contact'                  | 联系人信息的基本类型。     ||
| DATABASE                       | 'general.database'                  | 数据库基本类型。     ||
| MESSAGE                      | 'general.message'                 | 消息的基本类型。    ||
| VCARD            | 'general.vcard'               | 电子名片的基本类型。     ||
| NAVIGATION        | 'general.navigation'           | 导航的基本类型。     ||
| LOCATION       | 'general.location'          | 导航定位类型。  |NAVIGATION|
| OPENHARMONY_FORM                        | 'openharmony.form'                   | Openharmony系统定义的表单类型。     ||
| OPENHARMONY_APP_ITEM                       | 'openharmony.app-item'                  | Openharmony系统定义的应用项类型。     ||
| OPENHARMONY_PIXEL_MAP                       | 'openharmony.pixel-map'                  | Openharmony系统定义的像素映射类型。     ||
| OPENHARMONY_ATOMIC_SERVICE                       | 'openharmony.atomic-service'                  | Openharmony系统定义的原子服务类型。     ||

## TypeDescriptor 

描述统一数据类型的类，它由描述统一数据类型及其与其他统一数据类型的关系的属性和方法组成。

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

| 名称    | 类型                    | 可读 | 可写 | 说明                       |
| ------- | ----------------------- | ---- | ---- | -------------------------- |
| typeId    | string | 是   | 否   | 表示统一数据类型的类型 ID。           |
| belongingToTypes | Array\<string>          | 是   | 否   | 表示统一数据类型所属的统一数据类型 ID。 |
| description    | string                  | 是   | 否   | 表示统一数据类型的文本说明。         |
| referenceURL    | string                  | 是   | 否   | 统一数据类型的引用 URL，用于描述类型的详细信息。         |

### equals

equals(typeDescriptor: TypeDescriptor): boolean

检查统一类型描述符是否等于给定的统一类型描述符。

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

**参数：**

| 参数名  | 类型 | 必填  | 说明                    |
| -----  | ------  | ----  | ----------------------- |
| TypeDescriptor    | typeDescriptor  | 是    |test。   |

**错误码：**

以下错误码的详细介绍请参见[UDMF错误码](../)。

| **错误码ID** | **错误信息**                             |
| ------------ | ---------------------------------------- |
|     000 | abc.                      |
|     111 | def.   |

**示例：**

```ts


```