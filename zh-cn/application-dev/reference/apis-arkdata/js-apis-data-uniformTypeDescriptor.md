# @ohos.data.uniformTypeDescriptor (标准化数据定义与描述)

本模块对标准化数据类型进行了抽象定义与描述。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import { uniformTypeDescriptor } from '@kit.ArkData';
```

## UniformDataType

标准化数据类型之间存在归属关系，例如JPEG图片类型归属于IMAGE类型。更多预置数据类型参考[UTD预置列表](../../database/uniform-data-type-list.md)。
下表以枚举形式，列举了常用的标准化数据类型定义。

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

| 名称                         | 值                            | 说明                                 |
|----------------------------|------------------------------|------------------------------------|
| ENTITY<sup>11+</sup>                       | 'general.entity'                   | 所有表示物理存储类型的基类型，无归属类型。                          |
| OBJECT<sup>11+</sup>                       | 'general.object'                   | 所有表示逻辑内容类型的基类型，无归属类型。                          |
| COMPOSITE_OBJECT<sup>11+</sup>                       | 'general.composite-object'                   | 所有组合内容类型（例如PDF文件类型混合了文本和图片类数据）的基类型，归属类型为OBJECT。                          |
| TEXT                       | 'general.text'                   | 所有文本的基类型，归属类型为OBJECT。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                          |
| PLAIN_TEXT                | 'general.plain-text'             | 未指定编码的文本类型，没有标识符，归属类型为TEXT。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。        |
| HTML                  | 'general.html'                   | HTML文本类型，归属类型为TEXT。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。               |
| HYPERLINK         | 'general.hyperlink'              | 超链接类型，归属类型为TEXT。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                  |
| XML<sup>11+</sup>    | 'general.xml'                   | XML文本类型，归属类型为TEXT。                |
| XHTML<sup>12+</sup>    | 'general.xhtml'                   | XHTML文本类型，归属类型为XML。                |
| RSS<sup>12+</sup>    | 'general.rss'                   | RSS文本类型，归属类型为XML。                |
| SMIL<sup>12+</sup>                         | 'com.real.smil'                    |  同步多媒体集成语言类型，归属类型为XML文本类型。       |
| SOURCE_CODE<sup>11+</sup>                | 'general.source-code'                  | 所有源代码的基类型，归属类型为TEXT。        |
| SCRIPT<sup>11+</sup>    | 'general.script'                  | 所有脚本语言源代码的基类型，归属类型为SOURCE_CODE。   |
| SHELL_SCRIPT<sup>11+</sup>               | 'general.shell-script'                  | shell脚本类型，归属类型为SCRIPT。            |
| CSH_SCRIPT<sup>11+</sup>      | 'general.csh-script'                 | C-shell脚本类型，归属类型为SHELL_SCRIPT。    |
| PERL_SCRIPT<sup>11+</sup> |'general.perl-script'               | Perl脚本类型，归属类型为SHELL_SCRIPT。       |
| PHP_SCRIPT<sup>11+</sup>         | 'general.php-script'           | PHP脚本类型，归属类型为SHELL_SCRIPT。        |
| PYTHON_SCRIPT<sup>11+</sup>        | 'general.python-script'          | Python脚本类型，归属类型为SHELL_SCRIPT。     |
| RUBY_SCRIPT<sup>11+</sup>                         | 'general.ruby-script'                   | Ruby脚本类型，归属类型为SHELL_SCRIPT。       |
| TYPE_SCRIPT<sup>11+</sup>                        | 'general.type-script'                  | TypeScript源代码类型，归属类型为SOURCE_CODE。 |
| JAVA_SCRIPT<sup>11+</sup>                        | 'general.java-script'                  | JavaScript源代码类型，归属类型为SOURCE_CODE。 |
| CSS<sup>12+</sup>    | 'general.css'                   | CSS样式表类型，归属类型为SCRIPT。                |
| C_HEADER<sup>11+</sup>                        | 'general.c-header'                  | C头文件类型，归属类型为SOURCE_CODE。          |
| C_SOURCE<sup>11+</sup>                       | 'general.c-source'                 | C源代码类型，归属类型为SOURCE_CODE。          |
| C_PLUS_PLUS_HEADER<sup>11+</sup>             | 'general.c-plus-plus-header'               | C++头文件类型，归属类型为SOURCE_CODE。        |
| C_PLUS_PLUS_SOURCE<sup>11+</sup>         | 'general.c-plus-plus-source'           | C++源代码类型，归属类型为SOURCE_CODE。        |
| JAVA_SOURCE<sup>11+</sup>        | 'general.java-source'          | Java源代码类型，归属类型为SOURCE_CODE。       |
| TEX<sup>12+</sup>    | 'general.tex'                   | TEX源代码类型，归属类型为SOURCE_CODE。                |
| MARKDOWN<sup>12+</sup>                         | 'general.markdown'                    | 标记语言文本类型，归属类型为TEXT。       |
| ASC_TEXT<sup>12+</sup>    | 'general.asc-text'                   | ASCII文本类型，归属类型为TEXT。                |
| RICH_TEXT<sup>12+</sup>    | 'general.rich-text'                   | 富文本类型，归属类型为TEXT。                |
| DELIMITED_VALUES_TEXT<sup>12+</sup>    | 'general.delimited-values-text'                   | 所有分隔值文本的基类型，归属类型为TEXT。                |
| COMMA_SEPARATED_VALUES_TEXT<sup>12+</sup>    | 'general.comma-separated-values-text'                   | CSV文本类型，归属类型为DELIMITED_VALUES_TEXT。                |
| TAB_SEPARATED_VALUES_TEXT<sup>12+</sup>    | 'general.tab-separated-values-text'                   | TSV文本类型，归属类型为DELIMITED_VALUES_TEXT。                |
| EBOOK<sup>11+</sup>                         | 'general.ebook'                   | 所有电子书文件格式的基类型，归属类型为COMPOSITE_OBJECT。                     |
| EPUB<sup>11+</sup>                        | 'general.epub'                  | 电子出版物（EPUB）文件格式类型，归属类型为EBOOK。     |
| AZW<sup>11+</sup>                        | 'com.amazon.azw'                  | AZW电子书文件格式类型，归属类型为EBOOK。          |
| AZW3<sup>11+</sup>                        | 'com.amazon.azw3'                  | AZW3电子书文件格式类型，归属类型为EBOOK。         |
| KFX<sup>11+</sup>                       | 'com.amazon.kfx'                 | KFX电子书文件格式类型，归属类型为EBOOK。          |
| MOBI<sup>11+</sup>             | 'com.amazon.mobi'               | MOBI电子书文件格式类型，归属类型为EBOOK。         |
| MEDIA<sup>11+</sup>         | 'general.media'           | 所有媒体的基类型，归属类型为OBJECT。                          |
| IMAGE        | 'general.image'          | 所有图片的基类型，归属类型为MEDIA。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。              |
| JPEG<sup>11+</sup>                         | 'general.jpeg'                   | JPEG图片类型，归属类型为IMAGE。              |
| PNG<sup>11+</sup>                        | 'general.png'                  | PNG图片类型，归属类型为IMAGE。               |
| RAW_IMAGE<sup>11+</sup>                        | 'general.raw-image'                  | 所有原始图像格式的基类型，归属类型为IMAGE。          |
| TIFF<sup>11+</sup>                        | 'general.tiff'                  | TIFF图片类型，归属类型为IMAGE。              |
| BMP<sup>11+</sup>                       | 'com.microsoft.bmp'                 | WINDOWS位图图像类型，归属类型为IMAGE。         |
| ICO<sup>11+</sup>             | 'com.microsoft.ico'               | WINDOWS图标图像类型，归属类型为IMAGE。         |
| PHOTOSHOP_IMAGE<sup>11+</sup>         | 'com.adobe.photoshop-image'           | Adobe Photoshop图片类型，归属类型为IMAGE。   |
| AI_IMAGE<sup>11+</sup>        | 'com.adobe.illustrator.ai-image'          | Adobe Illustrator图片类型，归属类型为IMAGE。 |
| FAX<sup>12+</sup>                         | 'general.fax'                    | 传真图像的基本类型，归属类型为IMAGE。       |
| JFX_FAX<sup>12+</sup>                         | 'com.j2.jfx-fax'                    | J2 jConnect传真文件类型，归属类型为FAX。       |
| EFX_FAX<sup>12+</sup>                         | 'com.js.efx-fax'                    | 电子传真文件类型，归属类型为FAX。       |
| XBITMAP_IMAGE<sup>12+</sup>                         | 'general.xbitmap-image'                    | X Window系统（X11）中使用的位图图像格式，归属类型为IMAGE。       |
| GIF<sup>12+</sup>                         | 'general.gif'                    | GIF图像类型，归属类型为IMAGE。       |
| TGA_IMAGE<sup>12+</sup>                         | 'com.truevision.tga-image'                    | 标签图形（TaggedGraphics）图像类型，归属类型为IMAGE。       |
| SGI_IMAGE<sup>12+</sup>                         | 'com.sgi.sgi-image'                    | 硅图（Silicon Graphics）图像类型，归属类型为IMAGE。       |
| OPENEXR_IMAGE<sup>12+</sup>                         | 'com.ilm.openexr-image'                    | 开放标准的高动态范围图像格式类型，归属类型为IMAGE。       |
| FLASHPIX_IMAGE<sup>12+</sup>                         | 'com.kodak.flashpix.image'                    | FlashPix 图像文件类型，归属类型为IMAGE。       |
| WORD_DOC<sup>11+</sup>                         | 'com.microsoft.word.doc'                   | Microsoft Word数据类型，归属类型为COMPOSITE_OBJECT。                |
| EXCEL<sup>11+</sup>                        | 'com.microsoft.excel.xls'                  | Microsoft Excel数据类型，归属类型为COMPOSITE_OBJECT。               |
| PPT<sup>11+</sup>                        | 'com.microsoft.powerpoint.ppt'                  | Microsoft PowerPoint演示文稿类型，归属类型为COMPOSITE_OBJECT。        |
| WORD_DOT<sup>12+</sup>                         | 'com.microsoft.word.dot'                    | Microsoft Word模板类型，归属类型为COMPOSITE_OBJECT。       |
| POWERPOINT_PPS<sup>12+</sup>                         | 'com.microsoft.powerpoint.pps'                    | Microsoft PowerPoint演示文稿幻灯片放映类型，归属类型为COMPOSITE_OBJECT。       |
| POWERPOINT_POT<sup>12+</sup>                         | 'com.microsoft.powerpoint.pot'                    | Microsoft PowerPoint演示文稿模板类型，归属类型为COMPOSITE_OBJECT。       |
| EXCEL_XLT<sup>12+</sup>                         | 'com.microsoft.excel.xlt'                    | Microsoft Excel模板类型，归属类型为COMPOSITE_OBJECT。       |
| VISIO_VSD<sup>12+</sup>                         | 'com.microsoft.visio.vsd'                    | Microsoft Visio数据类型，归属类型为COMPOSITE_OBJECT。       |
| PDF<sup>11+</sup>                        | 'com.adobe.pdf'                  | PDF数据类型，归属类型为COMPOSITE_OBJECT。                           |
| POSTSCRIPT<sup>11+</sup>                       | 'com.adobe.postscript'                 | PostScript数据类型，归属类型为COMPOSITE_OBJECT。                    |
| ENCAPSULATED_POSTSCRIPT<sup>11+</sup>             | 'com.adobe.encapsulated-postscript'               | Encapsulated PostScript类型，归属类型为POSTSCRIPT。         |
| VIDEO       | 'general.video'           | 所有视频的基类型，归属类型为MEDIA。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。              |
| AVI<sup>11+</sup>        | 'general.avi'          | AVI视频类型，归属类型为VIDEO。               |
| MPEG<sup>11+</sup>                         | 'general.mpeg'                   | MPEG-1或MPEG-2视频类型，归属类型为VIDEO。     |
| MPEG4<sup>11+</sup>                        | 'general.mpeg-4'                  | MPEG-4视频类型，归属类型为VIDEO。            |
| VIDEO_3GPP<sup>11+</sup>                        | 'general.3gpp'                  | 3GPP视频类型，归属类型为VIDEO。              |
| VIDEO_3GPP2<sup>11+</sup>                        | 'general.3gpp2'                  | 3GPP2视频类型，归属类型为VIDEO。             |
| TS<sup>12+</sup>                         | 'general.ts'                    | MPEG-TS类型，归属类型为VIDEO。       |
| MPEGURL_VIDEO<sup>12+</sup>                         | 'general.mpegurl-video'                    | MPEG视频播放列表文件类型，归属类型为VIDEO。       |
| WINDOWS_MEDIA_WM<sup>11+</sup>                       | 'com.microsoft.windows-media-wm'                 | WINDOWS WM视频类型，归属类型为VIDEO。        |
| WINDOWS_MEDIA_WMV<sup>11+</sup>             | 'com.microsoft.windows-media-wmv'               | WINDOWS WMV视频类型，归属类型为VIDEO。       |
| WINDOWS_MEDIA_WMP<sup>11+</sup>         | 'com.microsoft.windows-media-wmp'           | WINDOWS WMP视频类型，归属类型为VIDEO。       |
| WINDOWS_MEDIA_WVX<sup>11+</sup>                        | 'com.microsoft.windows-media-wvx'                  | WINDOWS WVX视频类型，归属类型为VIDEO。       |
| WINDOWS_MEDIA_WMX<sup>11+</sup>                        | 'com.microsoft.windows-media-wmx'                  | WINDOWS WMX视频类型，归属类型为VIDEO。       |
| REALMEDIA<sup>12+</sup>                         | 'com.real.realmedia'                    | 流媒体视频类型，归属类型为VIDEO。       |
| MATROSKA_VIDEO<sup>12+</sup>                         | 'org.matroska.mkv'                    | MKV视频类型，归属类型为VIDEO。       |
| FLASH<sup>12+</sup>                         | 'com.adobe.flash'                    | FLASH视频类型，归属类型为VIDEO。       |
| AUDIO       | 'general.audio'          | 所有音频的基类型，归属类型为MEDIA。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。              |
| AAC<sup>11+</sup>                         | 'general.aac'                   | AAC音频类型，归属类型为AUDIO。               |
| AIFF<sup>11+</sup>                        | 'general.aiff'                  | AIFF音频类型，归属类型为AUDIO。              |
| ALAC<sup>11+</sup>                        | 'general.alac'                  | ALAC音频类型，归属类型为AUDIO。              |
| FLAC<sup>11+</sup>                        | 'general.flac'                  | FLAC音频类型，归属类型为AUDIO。              |
| MP3<sup>11+</sup>                       | 'general.mp3'                 | MP3音频类型，归属类型为AUDIO。               |
| OGG<sup>11+</sup>              | 'general.ogg'               | OGG音频类型，归属类型为AUDIO。               |
| PCM<sup>11+</sup>         | 'general.pcm'           | PCM音频类型，归属类型为AUDIO。               |
| WINDOWS_MEDIA_WMA<sup>11+</sup>        | 'com.microsoft.windows-media-wma'          | WINDOWS WMA音频类型，归属类型为AUDIO。       |
| WAVEFORM_AUDIO<sup>11+</sup>                         | 'com.microsoft.waveform-audio'                   | WINDOWS波形音频类型，归属类型为AUDIO。         |
| WINDOWS_MEDIA_WAX<sup>11+</sup>                        | 'com.microsoft.windows-media-wax'                  | WINDOWS WAX音频类型，归属类型为AUDIO。       |
| AU_AUDIO<sup>12+</sup>                         | 'general.au-audio'                    | Au数据格式，归属类型为AUDIO。       |
| AIFC_AUDIO<sup>12+</sup>                         | 'general.aifc-audio'                    | 音频交换数据类型，归属类型为AUDIO。       |
| MPEGURL_AUDIO<sup>12+</sup>                         | 'general.mpegurl-audio'                    | MPEG音频播放列表文件类型，归属类型为AUDIO。       |
| MPEG_4_AUDIO<sup>12+</sup>                         | 'general.mpeg-4-audio'                    | MPEG-4音频类型，归属类型为AUDIO。       |
| MP2<sup>12+</sup>                         | 'general.mp2'                    | MP2音频类型，归属类型为AUDIO。       |
| MPEG_AUDIO<sup>12+</sup>                         | 'general.mpeg-audio'                    | MPEG音频类型，归属类型为AUDIO。       |
| ULAW_AUDIO<sup>12+</sup>                         | 'general.ulaw-audio'                    | ULAW音频类型，归属类型为AUDIO。       |
| SD2_AUDIO<sup>12+</sup>                         | 'com.digidesign.sd2-audio'                    | 单声道/立体声音频类型（Digidesign Sound Designer II），归属类型为AUDIO。       |
| REALAUDIO<sup>12+</sup>                         | 'com.real.realaudio'                    | RealMedia音频类型，归属类型为AUDIO。       |
| MATROSKA_AUDIO<sup>12+</sup>                         | 'org.matroska.mka'                    | MKA音频类型，归属类型为AUDIO。       |
| FILE                       | 'general.file'                 | 所有文件的基类型，归属类型为ENTITY。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                          |
| DIRECTORY<sup>11+</sup>             | 'general.directory'               | 所有目录的基类型，归属类型为ENTITY。                          |
| FOLDER        | 'general.folder'           | 所有文件夹的基类型，归属类型为DIRECTORY。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                         |
| SYMLINK<sup>11+</sup>        | 'general.symlink'          | 所有符号链接的基类型，归属类型为ENTITY。                        |
| ARCHIVE<sup>11+</sup>                         | 'general.archive'                   | 所有文件和目录存档文件的基类型，归属类型为OBJECT。                   |
| BZ2_ARCHIVE<sup>11+</sup>                        | 'general.bz2-archive'                  | BZ2存档文件类型，归属类型为ARCHIVE。           |
| OPG<sup>12+</sup>                        | 'general.opg'                  | OPG存档文件类型，归属类型为ARCHIVE。           |
| TAZ_ARCHIVE<sup>12+</sup>                        | 'general.taz-archive'                  | TAR压缩文件类型，归属类型为TAR_ARCHIVE。           |
| WEB_ARCHIVE<sup>12+</sup>                        | 'general.web-archive'                  | MHTML网页归档文件类型，归属类型为ARCHIVE。           |
| DISK_IMAGE<sup>11+</sup>                        | 'general.disk-image'                  | 所有可作为卷装载项的文件类型的基类型，归属类型为ARCHIVE。  |
| ISO<sup>12+</sup>                        | 'general.iso'                  | 光盘映像文件类型，归属类型为DISK_IMAGE。  |
| TAR_ARCHIVE<sup>11+</sup>                        | 'general.tar-archive'                  | TAR存档文件类型，归属类型为ARCHIVE。           |
| ZIP_ARCHIVE<sup>11+</sup>                       | 'general.zip-archive'                 | ZIP存档文件类型，归属类型为ARCHIVE。           |
| JAVA_ARCHIVE<sup>11+</sup>             | 'com.sun.java-archive'               | JAVA存档文件类型，归属类型为ARCHIVE和EXECUTABLE。          |
| GNU_TAR_ARCHIVE<sup>11+</sup>         | 'org.gnu.gnu-tar-archive'           | GNU存档文件类型，归属类型为ARCHIVE。           |
| GNU_ZIP_ARCHIVE<sup>11+</sup>        | 'org.gnu.gnu-zip-archive'          | GZIP存档文件类型，归属类型为ARCHIVE。          |
| GNU_ZIP_TAR_ARCHIVE<sup>11+</sup>                         | 'org.gnu.gnu-zip-tar-archive'                   | GZIP TAR存档文件类型，归属类型为ARCHIVE。       |
| OPENXML<sup>12+</sup>                         | 'org.openxmlformats.openxml'                    |   开源XML基类型，归属类型为ARCHIVE。       |
| WORDPROCESSINGML_DOCUMENT<sup>12+</sup>                         | 'org.openxmlformats.wordprocessingml.document'                    | 开源XML文档类型，归属类型为OPENXML和COMPOSITE_OBJECT。       |
| SPREADSHEETML_SHEET<sup>12+</sup>                         | 'org.openxmlformats.spreadsheetml.sheet'                    | 开源XML电子表格类型，归属类型为OPENXML和COMPOSITE_OBJECT。       |
| PRESENTATIONML_PRESENTATION<sup>12+</sup>                         | 'org.openxmlformats.presentationml.presentation'                    | 开源XML演示文稿类型，归属类型为OPENXML和COMPOSITE_OBJECT。       |
| DRAWINGML_VISIO<sup>12+</sup>                         | 'org.openxmlformats.drawingml.visio'                    | 开源XML绘图文件类型，归属类型为OPENXML和COMPOSITE_OBJECT。       |
| DRAWINGML_TEMPLATE<sup>12+</sup>                         | 'org.openxmlformats.drawingml.template'                    | 开源XML绘图模板类型，归属类型为OPENXML和COMPOSITE_OBJECT。       |
| WORDPROCESSINGML_TEMPLATE<sup>12+</sup>                         | 'org.openxmlformats.wordprocessingml.template'                    | 开源XML文档模板类型，归属类型为OPENXML和COMPOSITE_OBJECT。       |
| PRESENTATIONML_TEMPLATE<sup>12+</sup>                         | 'org.openxmlformats.presentationml.template'                    | 开源XML演示文稿模板类型，归属类型为OPENXML和COMPOSITE_OBJECT。       |
| PRESENTATIONML_SLIDESHOW<sup>12+</sup>                         | 'org.openxmlformats.presentationml.slideshow'                    | 开源XML演示文稿幻灯片放映类型，归属类型为OPENXML和COMPOSITE_OBJECT。       |
| SPREADSHEETML_TEMPLATE<sup>12+</sup>                         | 'org.openxmlformats.spreadsheetml.template'                    | 开源XML电子表格模板类型，归属类型为OPENXML和COMPOSITE_OBJECT。       |
| OPENDOCUMENT<sup>12+</sup>                         | 'org.oasis.opendocument'                    | Office应用程序的开源文档类型，归属类型为ARCHIVE。       |
| OPENDOCUMENT_TEXT<sup>12+</sup>                         | 'org.oasis.opendocument.text'                    | 开源文档类型，归属类型为OPENDOCUMENT和COMPOSITE_OBJECT。       |
| OPENDOCUMENT_SPREADSHEET<sup>12+</sup>                         | 'org.oasis.opendocument.spreadsheet'                    | 开源文档电子表格类型，归属类型为OPENDOCUMENT和COMPOSITE_OBJECT。       |
| OPENDOCUMENT_PRESENTATION<sup>12+</sup>                         | 'org.oasis.opendocument.presentation'                    | 开源文档演示类型，归属类型为OPENDOCUMENT和COMPOSITE_OBJECT。       |
| OPENDOCUMENT_GRAPHICS<sup>12+</sup>                         | 'org.oasis.opendocument.graphics'                    | 开源文档图形类型，归属类型为OPENDOCUMENT和COMPOSITE_OBJECT。       |
| OPENDOCUMENT_FORMULA<sup>12+</sup>                         | 'org.oasis.opendocument.formula'                    | 开源文档公式集类型，归属类型为OPENDOCUMENT。       |
| STUFFIT_ARCHIVE<sup>12+</sup>                         | 'com.allume.stuffit-archive'                    | Stuffit压缩格式类型（Stuffit archive），归属类型为ARCHIVE。       |
| RAR_ARCHIVE<sup>12+</sup>                         | 'com.rarlab.rar-archive'                    | WinRAR压缩格式类型，归属类型为ARCHIVE。       |
| SEVEN_ZIP_ARCHIVE<sup>12+</sup>                         | 'org.7-zip.7-zip-archive'                    | 7-zip压缩格式类型，归属类型为ARCHIVE。       |
| CALENDAR<sup>11+</sup>                        | 'general.calendar'                  | 所有日程类数据的基类型，归属类型为OBJECT。                       |
| VCS<sup>12+</sup>                         | 'general.vcs'                    | VCalendar日历数据类型，归属类型为CALENDAR和TEXT。       |
| ICS<sup>12+</sup>                         | 'general.ics'                    | ICalendar日历数据类型，归属类型为CALENDAR和TEXT。       |
| CONTACT<sup>11+</sup>                        | 'general.contact'                  | 所有联系人类数据的基类型，归属类型为OBJECT。                      |
| DATABASE<sup>11+</sup>                        | 'general.database'                  | 所有数据库文件的基类型，归属类型为OBJECT。                       |
| MESSAGE<sup>11+</sup>                       | 'general.message'                 | 所有消息类数据的基类型，归属类型为OBJECT。                       |
| EXECUTABLE<sup>12+</sup>                         | 'general.executable'                    |  所有可执行文件的基类型，归属类型为OBJECT。       |
| PORTABLE_EXECUTABLE<sup>12+</sup>                         | 'com.microsoft.portable-executable'                    | Microsoft Windows应用程序类型，归属类型为EXECUTABLE。       |
| SUN_JAVA_CLASS<sup>12+</sup>                         | 'com.sun.java-class'                    | Java类文件类型，归属类型为EXECUTABLE。       |
| VCARD<sup>11+</sup>             | 'general.vcard'               | 所有电子名片类数据的基类型，归属类型为OBJECT。                     |
| NAVIGATION<sup>11+</sup>         | 'general.navigation'           | 所有导航类数据的基类型，归属类型为OBJECT。                       |
| LOCATION<sup>11+</sup>        | 'general.location'          | 导航定位类型，归属类型为NAVIGATION。            |
| FONT<sup>12+</sup>                         | 'general.font'                    | 所有字体数据类型的基础类型，归属类型为OBJECT。       |
| TRUETYPE_FONT<sup>12+</sup>                         | 'general.truetype-font'                    | TrueType字体类型，归属类型为FONT。       |
| TRUETYPE_COLLECTION_FONT<sup>12+</sup>                         | 'general.truetype-collection-font'                    | TrueType collection字体类型，归属类型为FONT。       |
| OPENTYPE_FONT<sup>12+</sup>                         | 'general.opentype-font'                    | OpenType 字体类型，归属类型为FONT。       |
| POSTSCRIPT_FONT<sup>12+</sup>                         | 'com.adobe.postscript-font'                    | PostScript 字体类型，归属类型为FONT。       |
| POSTSCRIPT_PFB_FONT<sup>12+</sup>                         | 'com.adobe.postscript-pfb-font'                    | PostScript Font Binary字体类型，归属类型为FONT。       |
| POSTSCRIPT_PFA_FONT<sup>12+</sup>                         | 'com.adobe.postscript-pfa-font'                    | Adobe Type 1 字体类型，归属类型为FONT。       |
| OPENHARMONY_FORM                         | 'openharmony.form'                   | 系统定义的卡片类型，归属类型为OBJECT。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。              |
| OPENHARMONY_APP_ITEM                        | 'openharmony.app-item'                  | 系统定义的桌面图标类型，归属类型为OBJECT。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。            |
| OPENHARMONY_PIXEL_MAP                        | 'openharmony.pixel-map'                  | 系统定义的像素图类型，归属类型为IMAGE。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。             |
| OPENHARMONY_ATOMIC_SERVICE<sup>11+</sup>                        | 'openharmony.atomic-service'                  | 系统定义的原子化服务类型，归属类型为OBJECT。             |
| OPENHARMONY_PACKAGE<sup>11+</sup>                        | 'openharmony.package'                  | 系统定义的包（即目录的打包文件），归属类型为DIRECTORY。             |
| OPENHARMONY_HAP<sup>11+</sup>                        | 'openharmony.hap'                  | 系统定义的能力包，归属类型为OPENHARMONY_PACKAGE。             |
| OPENHARMONY_HDOC<sup>12+</sup>                         | 'openharmony.hdoc'                    | 系统定义的备忘录数据类型，归属类型为COMPOSITE_OBJECT。       |
| OPENHARMONY_HINOTE<sup>12+</sup>                         | 'openharmony.hinote'                    | 系统定义的笔记数据类型，归属类型为COMPOSITE_OBJECT。       |
| OPENHARMONY_STYLED_STRING<sup>12+</sup>                         | 'openharmony.styled-string'                    | 系统定义的样式字符串类型，归属类型为COMPOSITE_OBJECT。       |
| OPENHARMONY_WANT<sup>12+</sup>                         | 'openharmony.want'                    | 系统定义的Want类型，归属类型为OBJECT。       |
| OFD<sup>12+</sup>                         | 'general.ofd'                    | 开放版式文档类型，归属类型为COMPOSITE_OBJECT。       |
| CAD<sup>12+</sup>                         | 'general.cad'                    | 所有计算机辅助设计类型的基类型，归属类型为OBJECT。       |
| OCTET_STREAM<sup>12+</sup>                         | 'general.octet-stream'                    | 任意二进制数据类型，归属类型为OBJECT。       |
| FILE_URI<sup>15+</sup>                         | 'general.file-uri'                    | 文件地址类型，归属类型为TEXT。       |
| CONTENT_FORM<sup>15+</sup>                         | 'general.content-form'                    | 内容卡片类型，归属类型为OBJECT。       |


## TypeDescriptor<sup>11+</sup> 

标准化数据类型的描述类，它包含了一些属性和方法用于描述标准化数据类型自身以及和其他标准化数据类型之间的归属与层级关系。

### 属性

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

| 名称    | 类型                    | 只读 | 可选 | 说明                                                       |
| ------- | ----------------------- | ---- | ---- |----------------------------------------------------------|
| typeId<sup>11+</sup>     | string | 是   | 否   | 标准化数据类型的ID（即[UTD列表](#uniformdatatype)中对应的枚举值），也可以是自定义UTD。 |
| belongingToTypes<sup>11+</sup>  | Array\<string>          | 是   | 否   | 标准化数据类型所归属的类型typeId列表。                                   |
| description<sup>11+</sup>     | string                  | 是   | 否   | 标准化数据类型的简要说明。                                            |
| referenceURL<sup>11+</sup>     | string                  | 是   | 否   | 标准化数据类型的参考链接URL，用于描述类型的详细信息。                            |
| iconFile<sup>11+</sup>     | string                  | 是   | 否   | 标准化数据类型的默认图标文件路径，可能为空字符串（即没有默认图标），应用可以自行决定是否使用该默认图标。                                   |
| filenameExtensions<sup>12+</sup>  | Array\<string>          | 是   | 否   | 标准化数据类型所关联的文件名后缀列表。                                   |
| mimeTypes<sup>12+</sup>  | Array\<string>          | 是   | 否   | 标准化数据类型所关联的多用途互联网邮件扩展类型列表。                                   |

### belongsTo<sup>11+</sup> 

belongsTo(type: string): boolean

判断当前标准化数据类型是否归属于指定的标准化数据类型。

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

**参数：**

| 参数名  | 类型 | 必填  | 说明                    |
| -----  | ------  | ----  | ----------------------- |
| type    | string  | 是    |所指定的标准化数据类型（即[UniformDataType](#uniformdatatype)中对应的枚举值）。   |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回true表示当前的标准化数据类型归属于所指定的标准化数据类型，包括所指定类型与当前类型相同的情况；返回false则表示无归属关系。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                |
| ------------ | ------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |

**示例：**

```ts
import { uniformTypeDescriptor } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

try{
    let typeObj : uniformTypeDescriptor.TypeDescriptor = uniformTypeDescriptor.getTypeDescriptor('general.type-script');
    let ret = typeObj.belongsTo('general.source-code');
    if(ret) {
        console.info('type general.type-script belongs to type general.source-code');
    }
} catch(e) {
    let error: BusinessError = e as BusinessError;
    console.error(`belongsTo throws an exception. code is ${error.code}, message is ${error.message} `);
}
```

### isLowerLevelType<sup>11+</sup> 

isLowerLevelType(type: string): boolean

判断当前标准化数据类型是否是指定标准化数据类型的低层级类型。例如TYPE_SCRIPT为SOURCE_CODE的低层级类型，TYPE_SCRIPT和SOURCE_CODE为TEXT的低层级类型。

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

**参数：**

| 参数名  | 类型 | 必填  | 说明                    |
| -----  | ------  | ----  | ----------------------- |
| type    | string  | 是    |所指定的标准化数据类型（即[UniformDataType](#uniformdatatype)中对应的枚举值）。   |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回true表示当前的标准化数据类型是所指定标准化数据类型的低层级类型，否则返回false。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                |
| ------------ | ------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |

**示例：**

```ts
import { uniformTypeDescriptor } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

try{
    let typeObj : uniformTypeDescriptor.TypeDescriptor = uniformTypeDescriptor.getTypeDescriptor('general.type-script');
    let ret = typeObj.isLowerLevelType('general.source-code');
    if(ret) {
        console.info('type general.type-script is lower level type of type general.source-code');
    }
} catch(e) {
    let error: BusinessError = e as BusinessError;
    console.error(`isLowerLevelType throws an exception. code is ${error.code}, message is ${error.message} `);
}
```

### isHigherLevelType<sup>11+</sup> 

isHigherLevelType(type: string): boolean

判断当前标准化数据类型是否是指定标准化数据类型的高层级类型。例如SOURCE_CODE为TYPE_SCRIPT的高层级类型，TEXT为SOURCE_CODE和TYPE_SCRIPT的高层级类型。

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

**参数：**

| 参数名  | 类型 | 必填  | 说明                    |
| -----  | ------  | ----  | ----------------------- |
| type    | string  | 是    |所指定的标准化数据类型（即[UniformDataType](#uniformdatatype)中对应的枚举值）。   |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回true表示当前的标准化数据类型是所指定标准化数据类型的高层级类型，否则返回false。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                |
| ------------ | ------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |

**示例：**

```ts
import { uniformTypeDescriptor } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

try{
    let typeObj : uniformTypeDescriptor.TypeDescriptor = uniformTypeDescriptor.getTypeDescriptor('general.source-code');
    let ret = typeObj.isHigherLevelType('general.type-script');
    if(ret) {
        console.info('type general.source-code is higher level type of type general.type-script');
    }
} catch(e) {
    let error: BusinessError = e as BusinessError;
    console.error(`isHigherLevelType throws an exception. code is ${error.code}, message is ${error.message} `);
}
```

### equals<sup>11+</sup> 

equals(typeDescriptor: TypeDescriptor): boolean

判断指定的标准化数据类型描述类对象的类型ID和当前标准化数据类型描述类对象的类型ID是否相同，即[TypeDescriptor](#typedescriptor11)对象的typeId。

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

**参数：**

| 参数名  | 类型 | 必填  | 说明                    |
| -----  | ------  | ----  | ----------------------- |
| typeDescriptor    | [TypeDescriptor](#typedescriptor11)  | 是    |待比较的标准化数据类型描述类对象。   |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回true表示所比较的标准化数据类型相同；返回false则表示不同。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                |
| ------------ | ------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |

**示例：**

```ts
import { uniformTypeDescriptor } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

try{
    let typeA : uniformTypeDescriptor.TypeDescriptor = uniformTypeDescriptor.getTypeDescriptor('general.type-script');
    let typeB : uniformTypeDescriptor.TypeDescriptor = uniformTypeDescriptor.getTypeDescriptor('general.python-script');
    if(!typeA.equals(typeB)) {
      console.info('typeA is not equal to typeB');
    }
} catch(e) {
    let error: BusinessError = e as BusinessError;
    console.error(`throws an exception. code is ${error.code}, message is ${error.message} `);
}
```

## uniformTypeDescriptor.getTypeDescriptor<sup>11+</sup>

getTypeDescriptor(typeId: string): TypeDescriptor

按给定的标准化数据类型ID查询并返回对应的标准化数据类型描述类对象。

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

**参数：**

| 参数名  | 类型 | 必填  | 说明                    |
| -----  | ------  | ----  | ----------------------- |
| typeId    | string  | 是    |[标准化数据类型ID](../../database/uniform-data-type-list.md#基础类型)。   |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| [TypeDescriptor](#typedescriptor11) | 返回标准化数据类型描述类对象，如果要查询的标准化数据类型不存在则返回null。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                |
| ------------ | ------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |

**示例：**

```ts
import { uniformTypeDescriptor } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let typeObj : uniformTypeDescriptor.TypeDescriptor = uniformTypeDescriptor.getTypeDescriptor('com.adobe.photoshop-image');
    if (typeObj) {
        let typeId = typeObj.typeId;
        let belongingToTypes = typeObj.belongingToTypes;
        let description = typeObj.description;
        let referenceURL = typeObj.referenceURL;
        let iconFile = typeObj.iconFile;
        let filenameExtensions = typeObj.filenameExtensions;
        let mimeTypes = typeObj.mimeTypes;
        console.info(`typeId: ${typeId}, belongingToTypes: ${belongingToTypes}, description: ${description}, referenceURL: ${referenceURL}, iconFile: ${iconFile}, filenameExtensions: ${filenameExtensions}, mimeTypes: ${mimeTypes}`);
    } else {
        console.info('type com.adobe.photoshop-image does not exist');
    }
} catch(e) {
    let error: BusinessError = e as BusinessError;
    console.error(`getTypeDescriptor throws an exception. code is ${error.code}, message is ${error.message} `);
}
```

## uniformTypeDescriptor.getUniformDataTypeByFilenameExtension<sup>11+</sup>

getUniformDataTypeByFilenameExtension(filenameExtension: string, belongsTo?: string): string

根据给定的文件后缀名和所归属的标准化数据类型查询标准化数据类型ID，若有多个符合条件的标准化数据类型ID，则返回第一个。

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

**参数：**

| 参数名  | 类型 | 必填  | 说明                    |
| -----  | ------  | ----  | ----------------------- |
| filenameExtension    | string  | 是    |文件后缀名称。   |
| belongsTo    | string  | 否    |要查询的标准化数据类型所归属类型ID，无默认值，若不传入此参数则只按照文件后缀名称查询[标准化数据类型ID](../../database/uniform-data-type-list.md#基础类型)。   |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| string | 返回与给定文件后缀名以及归属类型ID（如果设置了belongsTo参数）匹配的标准化数据类型ID，如果要查询的标准化数据类型不存在则返回根据入参按指定规则生成的动态类型。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                |
| ------------ | ------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |

**示例：**

```ts
import { uniformTypeDescriptor } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let typeId = uniformTypeDescriptor.getUniformDataTypeByFilenameExtension('.ts', 'general.source-code');
    if(typeId) {
        console.info('typeId is general.type-script');
    }
} catch(e) {
    let error: BusinessError = e as BusinessError;
    console.error(`getUniformDataTypeByFilenameExtension throws an exception. code is ${error.code}, message is ${error.message} `);
}

// 根据“.myts”，“general.plain-text”查不到预置数据类型则按返回根据入参信息生成的动态类型。
try {
    let typeId = uniformTypeDescriptor.getUniformDataTypeByFilenameExtension('.myts', 'general.plain-text');
    if(typeId) {
        console.info('typeId is flex.************');
    }
} catch(e) {
    let error: BusinessError = e as BusinessError;
    console.error(`getUniformDataTypeByFilenameExtension throws an exception. code is ${error.code}, message is ${error.message} `);
}
```

## uniformTypeDescriptor.getUniformDataTypeByMIMEType<sup>11+</sup>

getUniformDataTypeByMIMEType(mimeType: string, belongsTo?: string): string

根据给定的MIME类型和所归属的标准化数据类型查询标准化数据类型ID，若有多个符合条件的标准化数据类型ID，则返回第一个。

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

**参数：**

| 参数名  | 类型 | 必填  | 说明                    |
| -----  | ------  | ----  | ----------------------- |
| mimeType    | string  | 是    |MIME类型名称。   |
| belongsTo    | string  | 否    |要查询的标准化数据类型所归属类型ID。无默认值，若不传入此参数则只按照MIME类型名称查询[标准化数据类型ID](../../database/uniform-data-type-list.md#基础类型)。   |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| string | 返回与MIME类型名称以及归属类型ID（如果设置了belongsTo参数）匹配的标准化数据类型ID，如果要查询的标准化数据类型不存在则返回根据入参按指定规则生成的动态类型。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                |
| ------------ | ------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |

**示例：**

```ts
import { uniformTypeDescriptor } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let typeId = uniformTypeDescriptor.getUniformDataTypeByMIMEType('image/jpeg', 'general.image');
    if(typeId) {
        console.info('typeId is general.jpeg');
    }
} catch(e) {
    let error: BusinessError = e as BusinessError;
    console.error(`getUniformDataTypeByMIMEType throws an exception. code is ${error.code}, message is ${error.message} `);
}

// 根据“image/myimage”, “general.image”查不到预置数据类型则按返回根据入参信息生成的动态类型。
try {
    let typeId = uniformTypeDescriptor.getUniformDataTypeByMIMEType('image/myimage', 'general.image');
    if(typeId) {
        console.info('typeId is flex.************');
    }
} catch(e) {
    let error: BusinessError = e as BusinessError;
    console.error(`getUniformDataTypeByMIMEType throws an exception. code is ${error.code}, message is ${error.message} `);
}
```

## uniformTypeDescriptor.getUniformDataTypesByFilenameExtension<sup>13+</sup>

getUniformDataTypesByFilenameExtension(filenameExtension: string, belongsTo?: string): Array\<string>

根据给定的文件后缀名和所归属的标准化数据类型查询标准化数据类型ID列表。

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

**参数：**

| 参数名  | 类型 | 必填  | 说明                    |
| -----  | ------  | ----  | ----------------------- |
| filenameExtension    | string  | 是    |文件后缀名称。   |
| belongsTo    | string  | 否    |要查询的标准化数据类型所归属类型ID，无默认值，若不传入此参数则只按照文件后缀名称查询[标准化数据类型ID](../../database/uniform-data-type-list.md#基础类型)。   |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| Array\<string> | 返回与给定文件后缀名以及归属类型ID（如果设置了belongsTo参数）匹配的标准化数据类型ID列表，如果要查询的标准化数据类型不存在则返回根据入参按指定规则生成的动态类型列表。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                |
| ------------ | ------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |

**示例：**

```ts
import { uniformTypeDescriptor } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let typeIds = uniformTypeDescriptor.getUniformDataTypesByFilenameExtension('.ts', 'general.source-code');
    for (let typeId of typeIds) {
        console.info(`typeId is ${typeId}`);
    }
} catch(e) {
    let error: BusinessError = e as BusinessError;
    console.error(`getUniformDataTypesByFilenameExtension throws an exception. code is ${error.code}, message is ${error.message} `);
}

// 根据“.myts”，“general.plain-text”查不到预置数据类型则按返回根据入参信息生成的动态类型列表。
try {
    let flexTypeIds = uniformTypeDescriptor.getUniformDataTypesByFilenameExtension('.myts', 'general.plain-text');
    for (let flexTypeId of flexTypeIds) {
        console.info(`typeId is flex type, flex typeId is ${flexTypeId}`);
    }
} catch(e) {
    let error: BusinessError = e as BusinessError;
    console.error(`getUniformDataTypesByFilenameExtension throws an exception. code is ${error.code}, message is ${error.message} `);
}
```

## uniformTypeDescriptor.getUniformDataTypesByMIMEType<sup>13+</sup>

getUniformDataTypesByMIMEType(mimeType: string, belongsTo?: string): Array\<string>

根据给定的MIME类型和所归属的标准化数据类型查询标准化数据类型ID列表。

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

**参数：**

| 参数名  | 类型 | 必填  | 说明                    |
| -----  | ------  | ----  | ----------------------- |
| mimeType    | string  | 是    |MIME类型名称。   |
| belongsTo    | string  | 否    |要查询的标准化数据类型所归属类型ID。无默认值，若不传入此参数则只按照MIME类型名称查询[标准化数据类型ID](../../database/uniform-data-type-list.md#基础类型)。   |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| Array\<string> | 返回与MIME类型名称以及归属类型ID（如果设置了belongsTo参数）匹配的标准化数据类型ID列表，如果要查询的标准化数据类型不存在则返回根据入参按指定规则生成的动态类型列表。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                |
| ------------ | ------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |

**示例：**

```ts
import { uniformTypeDescriptor } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let typeIds = uniformTypeDescriptor.getUniformDataTypesByMIMEType('text/plain', 'general.text');
    for (let typeId of typeIds) {
        console.info(`typeId is ${typeId}`);
    }
} catch(e) {
    let error: BusinessError = e as BusinessError;
    console.error(`getUniformDataTypesByMIMEType throws an exception. code is ${error.code}, message is ${error.message} `);
}

// 根据“image/myimage”, “general.image”查不到预置数据类型则按返回根据入参信息生成的动态类型列表。
try {
    let flexTypeIds = uniformTypeDescriptor.getUniformDataTypesByMIMEType('image/myimage', 'general.image');
    for (let flexTypeId of flexTypeIds) {
        console.info(`typeId is flex type, flex typeId is ${flexTypeId}`);
    }
} catch(e) {
    let error: BusinessError = e as BusinessError;
    console.error(`getUniformDataTypesByMIMEType throws an exception. code is ${error.code}, message is ${error.message} `);
}
```