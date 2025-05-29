# @ohos.data.uniformTypeDescriptor (Uniform Data Definition and Description)

The **uniformTypeDescriptor** module abstracts and defines uniform data types.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import { uniformTypeDescriptor } from '@kit.ArkData';
```

## UniformDataType

Enumerates the uniform data types. Some data types are related. For example, the JPEG type belongs to the IMAGE type. For more preset data types, see [Preset UTD List](../../database/uniform-data-type-list.md).
 

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name                        | Value                           | Description                                |
|----------------------------|------------------------------|------------------------------------|
| ENTITY<sup>11+</sup>                       | 'general.entity'                   | Generic physical storage type.<br>This type is uncategorized.                         |
| OBJECT<sup>11+</sup>                       | 'general.object'                   | Generic logical content type.<br>This type is uncategorized.                         |
| COMPOSITE_OBJECT<sup>11+</sup>                       | 'general.composite-object'                   | Generic composite content type. For example, a PDF file that contains text and image.<br>This type belongs to **OBJECT**.                         |
| TEXT                       | 'general.text'                   | Generic text type.<br>This type belongs to **OBJECT**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                         |
| PLAIN_TEXT                | 'general.plain-text'             | Text without specific encoding or identifier.<br>This type belongs to **TEXT**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.       |
| HTML                  | 'general.html'                   | HTML.<br>This type belongs to **TEXT**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.              |
| HYPERLINK         | 'general.hyperlink'              | Hyperlink.<br>This type belongs to **TEXT**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                 |
| XML<sup>11+</sup>    | 'general.xml'                   | XML.<br>This type belongs to **TEXT**.               |
| XHTML<sup>12+</sup>    | 'general.xhtml'                   | XHTML.<br>This type belongs to **XML**.               |
| RSS<sup>12+</sup>    | 'general.rss'                   | RSS.<br>This type belongs to **XML**.               |
| SMIL<sup>12+</sup>                         | 'com.real.smil'                    |  Synchronized Multimedia Integration Language (SMIL).<br>This type belongs to **XML**.      |
| SOURCE_CODE<sup>11+</sup>                | 'general.source-code'                  | Generic source code type.<br>This type belongs to **TEXT**.       |
| SCRIPT<sup>11+</sup>    | 'general.script'                  | Source code in any scripting language.<br>This type belongs to **SOURCE_CODE**.  |
| SHELL_SCRIPT<sup>11+</sup>               | 'general.shell-script'                  | Shell script.<br>This type belongs to **SCRIPT**.           |
| CSH_SCRIPT<sup>11+</sup>      | 'general.csh-script'                 | C shell script.<br>This type belongs to **SHELL_SCRIPT**.   |
| PERL_SCRIPT<sup>11+</sup> |'general.perl-script'               | Perl script.<br>This type belongs to **SHELL_SCRIPT**.      |
| PHP_SCRIPT<sup>11+</sup>         | 'general.php-script'           | PHP script.<br>This type belongs to **SHELL_SCRIPT**.       |
| PYTHON_SCRIPT<sup>11+</sup>        | 'general.python-script'          | Python script.<br>This type belongs to **SHELL_SCRIPT**.    |
| RUBY_SCRIPT<sup>11+</sup>                         | 'general.ruby-script'                   | Ruby script.<br>This type belongs to **SHELL_SCRIPT**.      |
| TYPE_SCRIPT<sup>11+</sup>                        | 'general.type-script'                  | TypeScript source code.<br>This type belongs to **SOURCE_CODE**.|
| JAVA_SCRIPT<sup>11+</sup>                        | 'general.java-script'                  | JavaScript source code.<br>This type belongs to **SOURCE_CODE**.|
| CSS<sup>12+</sup>    | 'general.css'                   | CSS.<br>This type belongs to **SCRIPT**.               |
| C_HEADER<sup>11+</sup>                        | 'general.c-header'                  | Header file in C.<br>This type belongs to **SOURCE_CODE**.         |
| C_SOURCE<sup>11+</sup>                       | 'general.c-source'                 | Source code in C.<br>This type belongs to **SOURCE_CODE**.         |
| C_PLUS_PLUS_HEADER<sup>11+</sup>             | 'general.c-plus-plus-header'               | Header file in C++.<br>This type belongs to **SOURCE_CODE**.       |
| C_PLUS_PLUS_SOURCE<sup>11+</sup>         | 'general.c-plus-plus-source'           | Source code in C++.<br>This type belongs to **SOURCE_CODE**.       |
| JAVA_SOURCE<sup>11+</sup>        | 'general.java-source'          | Source code in Java.<br>This type belongs to **SOURCE_CODE**.      |
| TEX<sup>12+</sup>    | 'general.tex'                   | Source code in TEX format.<br>This type belongs to **SOURCE_CODE**.               |
| MARKDOWN<sup>12+</sup>                         | 'general.markdown'                    | Markdown.<br>This type belongs to **TEXT**.      |
| ASC_TEXT<sup>12+</sup>    | 'general.asc-text'                   | ASCII.<br>This type belongs to **TEXT**.               |
| RICH_TEXT<sup>12+</sup>    | 'general.rich-text'                   | Rich text.<br>This type belongs to **TEXT**.               |
| DELIMITED_VALUES_TEXT<sup>12+</sup>    | 'general.delimited-values-text'                   | Generic type of all delimited value texts.<br>This type belongs to **TEXT**.               |
| COMMA_SEPARATED_VALUES_TEXT<sup>12+</sup>    | 'general.comma-separated-values-text'                   | Comma-separated values (CSV).<br>This type belongs to **DELIMITED_VALUES_TEXT**.               |
| TAB_SEPARATED_VALUES_TEXT<sup>12+</sup>    | 'general.tab-separated-values-text'                   | Tab-separated values (TSV).<br>This type belongs to **DELIMITED_VALUES_TEXT**.               |
| EBOOK<sup>11+</sup>                         | 'general.ebook'                   | Generic eBook file format type.<br>This type belongs to **COMPOSITE_OBJECT**.                    |
| EPUB<sup>11+</sup>                        | 'general.epub'                  | Electronic publication (EPUB).<br>This type belongs to **EBOOK**.    |
| AZW<sup>11+</sup>                        | 'com.amazon.azw'                  | AZW.<br>This type belongs to **EBOOK**.         |
| AZW3<sup>11+</sup>                        | 'com.amazon.azw3'                  | AZW3.<br>This type belongs to **EBOOK**.        |
| KFX<sup>11+</sup>                       | 'com.amazon.kfx'                 | KFX.<br>This type belongs to **EBOOK**.         |
| MOBI<sup>11+</sup>             | 'com.amazon.mobi'               | MOBI.<br>This type belongs to **EBOOK**.        |
| MEDIA<sup>11+</sup>         | 'general.media'           | Generic media type.<br>This type belongs to **OBJECT**.                         |
| IMAGE        | 'general.image'          | Image.<br>This type belongs to **MEDIA**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.             |
| JPEG<sup>11+</sup>                         | 'general.jpeg'                   | JPEG.<br>This type belongs to **IMAGE**.             |
| PNG<sup>11+</sup>                        | 'general.png'                  | PNG.<br>This type belongs to **IMAGE**.              |
| RAW_IMAGE<sup>11+</sup>                        | 'general.raw-image'                  | Raw image.<br>This type belongs to **IMAGE**.         |
| TIFF<sup>11+</sup>                        | 'general.tiff'                  | TIFF.<br>This type belongs to **IMAGE**.             |
| BMP<sup>11+</sup>                       | 'com.microsoft.bmp'                 | BMP.<br>This type belongs to **IMAGE**.        |
| ICO<sup>11+</sup>             | 'com.microsoft.ico'               | Windows icon.<br>This type belongs to **IMAGE**.        |
| PHOTOSHOP_IMAGE<sup>11+</sup>         | 'com.adobe.photoshop-image'           | Adobe Photoshop image.<br>This type belongs to **IMAGE**.  |
| AI_IMAGE<sup>11+</sup>        | 'com.adobe.illustrator.ai-image'          | Adobe Illustrator image (.ai).<br>This type belongs to **IMAGE**.|
| FAX<sup>12+</sup>                         | 'general.fax'                    | Generic type of the fax.<br>This type belongs to **IMAGE**.      |
| JFX_FAX<sup>12+</sup>                         | 'com.j2.jfx-fax'                    | J2 jConnect fax file format.<br>This type belongs to **FAX**.      |
| EFX_FAX<sup>12+</sup>                         | 'com.js.efx-fax'                    | EFX file format.<br>This type belongs to **FAX**.      |
| XBITMAP_IMAGE<sup>12+</sup>                         | 'general.xbitmap-image'                    | X BitMAP (XBM) used in the X Window system (X11).<br>This type belongs to **IMAGE**.      |
| GIF<sup>12+</sup>                         | 'general.gif'                    | GIF.<br>This type belongs to **IMAGE**.      |
| TGA_IMAGE<sup>12+</sup>                         | 'com.truevision.tga-image'                    | Tagged Graphics (TGA) format.<br>This type belongs to **IMAGE**.      |
| SGI_IMAGE<sup>12+</sup>                         | 'com.sgi.sgi-image'                    | Silicon Graphics image (SGI) format.<br>This type belongs to **IMAGE**.      |
| OPENEXR_IMAGE<sup>12+</sup>                         | 'com.ilm.openexr-image'                    | OpenXR image format.<br>This type belongs to **IMAGE**.      |
| FLASHPIX_IMAGE<sup>12+</sup>                         | 'com.kodak.flashpix.image'                    | FlashPix image format.<br>This type belongs to **IMAGE**.      |
| WORD_DOC<sup>11+</sup>                         | 'com.microsoft.word.doc'                   | Microsoft Word.<br>This type belongs to **COMPOSITE_OBJECT**.               |
| EXCEL<sup>11+</sup>                        | 'com.microsoft.excel.xls'                  | Microsoft Excel.<br>This type belongs to **COMPOSITE_OBJECT**.              |
| PPT<sup>11+</sup>                        | 'com.microsoft.powerpoint.ppt'                  | Microsoft PowerPoint presentation format.<br>This type belongs to **COMPOSITE_OBJECT**.       |
| WORD_DOT<sup>12+</sup>                         | 'com.microsoft.word.dot'                    | Microsoft Word template.<br>This type belongs to **COMPOSITE_OBJECT**.      |
| POWERPOINT_PPS<sup>12+</sup>                         | 'com.microsoft.powerpoint.pps'                    | Microsoft PowerPoint slide show format.<br>This type belongs to **COMPOSITE_OBJECT**.      |
| POWERPOINT_POT<sup>12+</sup>                         | 'com.microsoft.powerpoint.pot'                    | Microsoft PowerPoint template.<br>This type belongs to **COMPOSITE_OBJECT**.      |
| EXCEL_XLT<sup>12+</sup>                         | 'com.microsoft.excel.xlt'                    | Microsoft Excel template.<br>This type belongs to **COMPOSITE_OBJECT**.      |
| VISIO_VSD<sup>12+</sup>                         | 'com.microsoft.visio.vsd'                    | Microsoft Visio.<br>This type belongs to **COMPOSITE_OBJECT**.      |
| PDF<sup>11+</sup>                        | 'com.adobe.pdf'                  | PDF.<br>This type belongs to **COMPOSITE_OBJECT**.                          |
| POSTSCRIPT<sup>11+</sup>                       | 'com.adobe.postscript'                 | PostScript.<br>This type belongs to **COMPOSITE_OBJECT**.                   |
| ENCAPSULATED_POSTSCRIPT<sup>11+</sup>             | 'com.adobe.encapsulated-postscript'               | Encapsulated PostScript.<br>This type belongs to **POSTSCRIPT**.        |
| VIDEO       | 'general.video'           | Generic video type.<br>This type belongs to **MEDIA**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.             |
| AVI<sup>11+</sup>        | 'general.avi'          | AVI.<br>This type belongs to **VIDEO**.              |
| MPEG<sup>11+</sup>                         | 'general.mpeg'                   | MPEG-1 or MPEG-2.<br>This type belongs to **VIDEO**.    |
| MPEG4<sup>11+</sup>                        | 'general.mpeg-4'                  | MPEG-4.<br>This type belongs to **VIDEO**.           |
| VIDEO_3GPP<sup>11+</sup>                        | 'general.3gpp'                  | 3GP (3GPP file format).<br>This type belongs to **VIDEO**.             |
| VIDEO_3GPP2<sup>11+</sup>                        | 'general.3gpp2'                  | 3G2 (3GPP2 file format).<br>This type belongs to **VIDEO**.            |
| TS<sup>12+</sup>                         | 'general.ts'                    | MPEG-TS.<br>This type belongs to **VIDEO**.      |
| MPEGURL_VIDEO<sup>12+</sup>                         | 'general.mpegurl-video'                    | MPEG video playlist format.<br>This type belongs to **VIDEO**.      |
| WINDOWS_MEDIA_WM<sup>11+</sup>                       | 'com.microsoft.windows-media-wm'                 | Windows WM format.<br>This type belongs to **VIDEO**.       |
| WINDOWS_MEDIA_WMV<sup>11+</sup>             | 'com.microsoft.windows-media-wmv'               | Windows WMV format.<br>This type belongs to **VIDEO**.      |
| WINDOWS_MEDIA_WMP<sup>11+</sup>         | 'com.microsoft.windows-media-wmp'           | Windows WMP format.<br>This type belongs to **VIDEO**.      |
| WINDOWS_MEDIA_WVX<sup>11+</sup>                        | 'com.microsoft.windows-media-wvx'                  | Windows WVX format.<br>This type belongs to **VIDEO**.      |
| WINDOWS_MEDIA_WMX<sup>11+</sup>                        | 'com.microsoft.windows-media-wmx'                  | Windows WMX format.<br>This type belongs to **VIDEO**.      |
| REALMEDIA<sup>12+</sup>                         | 'com.real.realmedia'                    | RealMedia format.<br>This type belongs to **VIDEO**.      |
| MATROSKA_VIDEO<sup>12+</sup>                         | 'org.matroska.mkv'                    | MKV.<br>This type belongs to **VIDEO**.      |
| FLASH<sup>12+</sup>                         | 'com.adobe.flash'                    | Flash.<br>This type belongs to **VIDEO**.      |
| AUDIO       | 'general.audio'          | Generic audio type.<br>This type belongs to **MEDIA**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.             |
| AAC<sup>11+</sup>                         | 'general.aac'                   | AAC.<br>This type belongs to **AUDIO**.              |
| AIFF<sup>11+</sup>                        | 'general.aiff'                  | AIFF.<br>This type belongs to **AUDIO**.             |
| ALAC<sup>11+</sup>                        | 'general.alac'                  | ALAC.<br>This type belongs to **AUDIO**.             |
| FLAC<sup>11+</sup>                        | 'general.flac'                  | FLAC.<br>This type belongs to **AUDIO**.             |
| MP3<sup>11+</sup>                       | 'general.mp3'                 | MP3.<br>This type belongs to **AUDIO**.              |
| OGG<sup>11+</sup>              | 'general.ogg'               | OGG.<br>This type belongs to **AUDIO**.              |
| PCM<sup>11+</sup>         | 'general.pcm'           | PCM.<br>This type belongs to **AUDIO**.              |
| WINDOWS_MEDIA_WMA<sup>11+</sup>        | 'com.microsoft.windows-media-wma'          | Windows WMA.<br>This type belongs to **AUDIO**.      |
| WAVEFORM_AUDIO<sup>11+</sup>                         | 'com.microsoft.waveform-audio'                   | Windows Waveform.<br>This type belongs to **AUDIO**.        |
| WINDOWS_MEDIA_WAX<sup>11+</sup>                        | 'com.microsoft.windows-media-wax'                  | Windows WAX.<br>This type belongs to **AUDIO**.      |
| AU_AUDIO<sup>12+</sup>                         | 'general.au-audio'                    | AU format.<br>This type belongs to **AUDIO**.      |
| AIFC_AUDIO<sup>12+</sup>                         | 'general.aifc-audio'                    | AIFC.<br>This type belongs to **AUDIO**.      |
| MPEGURL_AUDIO<sup>12+</sup>                         | 'general.mpegurl-audio'                    | MPEG audio playlist format.<br>This type belongs to **AUDIO**.      |
| MPEG_4_AUDIO<sup>12+</sup>                         | 'general.mpeg-4-audio'                    | MPEG-4.<br>This type belongs to **AUDIO**.      |
| MP2<sup>12+</sup>                         | 'general.mp2'                    | MP2.<br>This type belongs to **AUDIO**.      |
| MPEG_AUDIO<sup>12+</sup>                         | 'general.mpeg-audio'                    | MPEG audio format.<br>This type belongs to **AUDIO**.      |
| ULAW_AUDIO<sup>12+</sup>                         | 'general.ulaw-audio'                    | ULAW.<br>This type belongs to **AUDIO**.      |
| SD2_AUDIO<sup>12+</sup>                         | 'com.digidesign.sd2-audio'                    | Digidesign Sound Designer II (SDII).<br>This type belongs to **AUDIO**.      |
| REALAUDIO<sup>12+</sup>                         | 'com.real.realaudio'                    | RealAudio.<br>This type belongs to **AUDIO**.      |
| MATROSKA_AUDIO<sup>12+</sup>                         | 'org.matroska.mka'                    | MKA.<br>This type belongs to **AUDIO**.      |
| FILE                       | 'general.file'                 | Generic file type.<br>This type belongs to **ENTITY**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                         |
| DIRECTORY<sup>11+</sup>             | 'general.directory'               | Generic directory type.<br>This type belongs to **ENTITY**.                         |
| FOLDER        | 'general.folder'           | Generic folder type.<br>This type belongs to **DIRECTORY**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                        |
| SYMLINK<sup>11+</sup>        | 'general.symlink'          | Generic symbolic type.<br>This type belongs to **ENTITY**.                       |
| ARCHIVE<sup>11+</sup>                         | 'general.archive'                   | Generic archive file type.<br>This type belongs to **OBJECT**.                  |
| BZ2_ARCHIVE<sup>11+</sup>                        | 'general.bz2-archive'                  | BZ2.<br>This type belongs to **ARCHIVE**.          |
| OPG<sup>12+</sup>                        | 'general.opg'                  | OPG.<br>This type belongs to **ARCHIVE**.          |
| TAZ_ARCHIVE<sup>12+</sup>                        | 'general.taz-archive'                  | TAR.<br>This type belongs to **TAR_ARCHIVE**.          |
| WEB_ARCHIVE<sup>12+</sup>                        | 'general.web-archive'                  | MHTML format for web page archiving.<br>This type belongs to **ARCHIVE**.          |
| DISK_IMAGE<sup>11+</sup>                        | 'general.disk-image'                  | Generic type of any file that can be mounted as a volume.<br>This type belongs to **ARCHIVE**. |
| ISO<sup>12+</sup>                        | 'general.iso'                  | ISO image (optical disk image) format.<br>This type belongs to **DISK_IMAGE**. |
| TAR_ARCHIVE<sup>11+</sup>                        | 'general.tar-archive'                  | TAR.<br>This type belongs to ARCHIVE.          |
| ZIP_ARCHIVE<sup>11+</sup>                       | 'general.zip-archive'                 | ZIP.<br>This type belongs to **ARCHIVE**.          |
| JAVA_ARCHIVE<sup>11+</sup>             | 'com.sun.java-archive'               | JAR (Java archive).<br>This type belongs to **ARCHIVE** and **EXECUTABLE**.         |
| GNU_TAR_ARCHIVE<sup>11+</sup>         | 'org.gnu.gnu-tar-archive'           | GNU.<br>This type belongs to **ARCHIVE**.          |
| GNU_ZIP_ARCHIVE<sup>11+</sup>        | 'org.gnu.gnu-zip-archive'          | GZIP archive.<br>This type belongs to **ARCHIVE**.         |
| GNU_ZIP_TAR_ARCHIVE<sup>11+</sup>                         | 'org.gnu.gnu-zip-tar-archive'                   | GZIP TAR.<br>This type belongs to **ARCHIVE**.      |
| OPENXML<sup>12+</sup>                         | 'org.openxmlformats.openxml'                    |   OpenXML base type.<br>This type belongs to **ARCHIVE**.      |
| WORDPROCESSINGML_DOCUMENT<sup>12+</sup>                         | 'org.openxmlformats.wordprocessingml.document'                    | WordProcessingML format.<br>This type belongs to **OPENXML** and **COMPOSITE_OBJECT**.      |
| SPREADSHEETML_SHEET<sup>12+</sup>                         | 'org.openxmlformats.spreadsheetml.sheet'                    | SpreadsheetML format.<br>This type belongs to **OPENXML** and **COMPOSITE_OBJECT**.      |
| PRESENTATIONML_PRESENTATION<sup>12+</sup>                         | 'org.openxmlformats.presentationml.presentation'                    | PresentationML format.<br>This type belongs to **OPENXML** and **COMPOSITE_OBJECT**.      |
| DRAWINGML_VISIO<sup>12+</sup>                         | 'org.openxmlformats.drawingml.visio'                    | DrawingML file format of Office Open XML (OOXML).<br>This type belongs to **OPENXML** and **COMPOSITE_OBJECT**.      |
| DRAWINGML_TEMPLATE<sup>12+</sup>                         | 'org.openxmlformats.drawingml.template'                    | DrawingML template format of OOXML.<br>This type belongs to **OPENXML** and **COMPOSITE_OBJECT**.      |
| WORDPROCESSINGML_TEMPLATE<sup>12+</sup>                         | 'org.openxmlformats.wordprocessingml.template'                    | WordProcessingML template format of OOXML.<br>This type belongs to **OPENXML** and **COMPOSITE_OBJECT**.      |
| PRESENTATIONML_TEMPLATE<sup>12+</sup>                         | 'org.openxmlformats.presentationml.template'                    | PresentationML template format of OOXML.<br>This type belongs to **OPENXML** and **COMPOSITE_OBJECT**.      |
| PRESENTATIONML_SLIDESHOW<sup>12+</sup>                         | 'org.openxmlformats.presentationml.slideshow'                    | PresentationML slide show format of OOXML.<br>This type belongs to **OPENXML** and **COMPOSITE_OBJECT**.      |
| SPREADSHEETML_TEMPLATE<sup>12+</sup>                         | 'org.openxmlformats.spreadsheetml.template'                    | SpreadsheetML template format of OOXML.<br>This type belongs to **OPENXML** and **COMPOSITE_OBJECT**.      |
| OPENDOCUMENT<sup>12+</sup>                         | 'org.oasis.opendocument'                    | OpenDocument format for Office applications.<br>This type belongs to **ARCHIVE**.      |
| OPENDOCUMENT_TEXT<sup>12+</sup>                         | 'org.oasis.opendocument.text'                    | OpenDocument format for word processing (text) documents.<br>This type belongs to **OPENDOCUMENT** and **COMPOSITE_OBJECT**.      |
| OPENDOCUMENT_SPREADSHEET<sup>12+</sup>                         | 'org.oasis.opendocument.spreadsheet'                    | OpenDocument format for spreadsheets.<br>This type belongs to **OPENDOCUMENT** and **COMPOSITE_OBJECT**.      |
| OPENDOCUMENT_PRESENTATION<sup>12+</sup>                         | 'org.oasis.opendocument.presentation'                    | OpenDocument format for presentations.<br>This type belongs to **OPENDOCUMENT** and **COMPOSITE_OBJECT**.      |
| OPENDOCUMENT_GRAPHICS<sup>12+</sup>                         | 'org.oasis.opendocument.graphics'                    | OpenDocument format for graphics.<br>This type belongs to **OPENDOCUMENT** and **COMPOSITE_OBJECT**.      |
| OPENDOCUMENT_FORMULA<sup>12+</sup>                         | 'org.oasis.opendocument.formula'                    | OpenDocument format for formula.<br>This type belongs to **OPENDOCUMENT**.      |
| STUFFIT_ARCHIVE<sup>12+</sup>                         | 'com.allume.stuffit-archive'                    | Stuffit compression format (stuffit archive).<br>This type belongs to **ARCHIVE**.      |
| RAR_ARCHIVE<sup>12+</sup>                         | 'com.rarlab.rar-archive'                    | WinRAR.<br>This type belongs to **ARCHIVE**.      |
| SEVEN_ZIP_ARCHIVE<sup>12+</sup>                         | 'org.7-zip.7-zip-archive'                    | 7-Zip.<br>This type belongs to **ARCHIVE**.      |
| CALENDAR<sup>11+</sup>                        | 'general.calendar'                  | Generic calendar type.<br>This type belongs to **OBJECT**.                      |
| VCS<sup>12+</sup>                         | 'general.vcs'                    | VCalendar (VCS) format.<br>This type belongs to **CALENDAR** and **TEXT**.      |
| ICS<sup>12+</sup>                         | 'general.ics'                    | Internet Calendaring and Scheduling (ICS) format.<br>This type belongs to **CALENDAR** and **TEXT**.      |
| CONTACT<sup>11+</sup>                        | 'general.contact'                  | Generic contact type.<br>This type belongs to **OBJECT**.                     |
| DATABASE<sup>11+</sup>                        | 'general.database'                  | Generic database file type.<br>This type belongs to **OBJECT**.                      |
| MESSAGE<sup>11+</sup>                       | 'general.message'                 | Generic message type.<br>This type belongs to **OBJECT**.                      |
| EXECUTABLE<sup>12+</sup>                         | 'general.executable'                    |  Generic type of all executable files.<br>This type belongs to **OBJECT**.      |
| PORTABLE_EXECUTABLE<sup>12+</sup>                         | 'com.microsoft.portable-executable'                    | Microsoft Windows portable executable format.<br>This type belongs to **EXECUTABLE**.      |
| SUN_JAVA_CLASS<sup>12+</sup>                         | 'com.sun.java-class'                    | Java class file format.<br>This type belongs to **EXECUTABLE**.      |
| VCARD<sup>11+</sup>             | 'general.vcard'               | Generic electronic business card type.<br>This type belongs to **OBJECT**.                    |
| NAVIGATION<sup>11+</sup>         | 'general.navigation'           | Generic navigation data type.<br>This type belongs to **OBJECT**.                      |
| LOCATION<sup>11+</sup>        | 'general.location'          | Location data.<br>This type belongs to **NAVIGATION**.           |
| FONT<sup>12+</sup>                         | 'general.font'                    | Basic type of fonts.<br>This type belongs to **OBJECT**.      |
| TRUETYPE_FONT<sup>12+</sup>                         | 'general.truetype-font'                    | TrueType font format.<br>This type belongs to **FONT**.      |
| TRUETYPE_COLLECTION_FONT<sup>12+</sup>                         | 'general.truetype-collection-font'                    | TrueType Collection font format.<br>This type belongs to **FONT**.      |
| OPENTYPE_FONT<sup>12+</sup>                         | 'general.opentype-font'                    | OpenType font format.<br>This type belongs to **FONT**.      |
| POSTSCRIPT_FONT<sup>12+</sup>                         | 'com.adobe.postscript-font'                    | PostScript font format.<br>This type belongs to **FONT**.      |
| POSTSCRIPT_PFB_FONT<sup>12+</sup>                         | 'com.adobe.postscript-pfb-font'                    | PostScript Font Binary font format.<br>This type belongs to **FONT**.      |
| POSTSCRIPT_PFA_FONT<sup>12+</sup>                         | 'com.adobe.postscript-pfa-font'                    | Adobe Type 1 font format.<br>This type belongs to **FONT**.      |
| OPENHARMONY_FORM                         | 'openharmony.form'                   | Widget defined for the system.<br>This type belongs to **OBJECT**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.             |
| OPENHARMONY_APP_ITEM                        | 'openharmony.app-item'                  | Home screen icon defined for the system.<br>This type belongs to **OBJECT**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.           |
| OPENHARMONY_PIXEL_MAP                        | 'openharmony.pixel-map'                  | Pixel map defined for the system.<br>This type belongs to **IMAGE**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.            |
| OPENHARMONY_ATOMIC_SERVICE<sup>11+</sup>                        | 'openharmony.atomic-service'                  | Atomic service type defined for the system.<br>This type belongs to **OBJECT**.            |
| OPENHARMONY_PACKAGE<sup>11+</sup>                        | 'openharmony.package'                  | Package (compressed folder) defined for the system.<br>This type belongs to **DIRECTORY**.            |
| OPENHARMONY_HAP<sup>11+</sup>                        | 'openharmony.hap'                  | Ability package defined for the system.<br>This type belongs to **OPENHARMONY_PACKAGE**.            |
| OPENHARMONY_HDOC<sup>12+</sup>                         | 'openharmony.hdoc'                    | Memo format defined for the system.<br>This type belongs to **COMPOSITE_OBJECT**.      |
| OPENHARMONY_HINOTE<sup>12+</sup>                         | 'openharmony.hinote'                    | Note format defined for the system.<br>This type belongs to **COMPOSITE_OBJECT**.      |
| OPENHARMONY_STYLED_STRING<sup>12+</sup>                         | 'openharmony.styled-string'                    | Style string type defined for the system.<br>This type belongs to **COMPOSITE_OBJECT**.      |
| OPENHARMONY_WANT<sup>12+</sup>                         | 'openharmony.want'                    | Want defined for the system.<br>This type belongs to **OBJECT**.      |
| OFD<sup>12+</sup>                         | 'general.ofd'                    | Open Fixed-layout Document (OFD).<br>This type belongs to **COMPOSITE_OBJECT**.      |
| CAD<sup>12+</sup>                         | 'general.cad'                    | Generic type of all computer-aided design types.<br>This type belongs to **OBJECT**.      |
| OCTET_STREAM<sup>12+</sup>                         | 'general.octet-stream'                    | Any binary data type.<br>This type belongs to **OBJECT**.      |
| FILE_URI<sup>15+</sup>                         | 'general.file-uri'                    | File address type.<br>This type belongs to **TEXT**.      |
| CONTENT_FORM<sup>15+</sup>                         | 'general.content-form'                    | Content widget type.<br>This type belongs to **OBJECT**.      |


## TypeDescriptor<sup>11+</sup> 

Represents a class for defining a uniform data type. It provides properties and methods for describing a uniform data type and its relationship with other uniform data types.

### Properties

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name   | Type                   | Readable| Writable| Description                                                      |
| ------- | ----------------------- | ---- | ---- |----------------------------------------------------------|
| typeId<sup>11+</sup>     | string | Yes  | No  | ID of the uniform data type, which is a value of [UniformDataType](#uniformdatatype).|
| belongingToTypes<sup>11+</sup>  | Array\<string>          | Yes  | No  | Data types to which the uniform data type belongs.                                  |
| description<sup>11+</sup>     | string                  | Yes  | No  | Brief description of the uniform data type.                                           |
| referenceURL<sup>11+</sup>     | string                  | Yes  | No  | URL of the link to the reference (detailed information) of the uniform data type.                           |
| iconFile<sup>11+</sup>     | string                  | Yes  | No  | File path of the default icon for the uniform data type. An empty string means the uniform data type has no default icon. The application can determine whether to use the default icon.                                  |
| filenameExtensions<sup>12+</sup>  | Array\<string>          | Yes  | No  | List of file name extensions associated with the uniform data type.                                  |
| mimeTypes<sup>12+</sup>  | Array\<string>          | Yes  | No  | List of MIME types associated with the uniform data type.                                  |

### belongsTo<sup>11+</sup> 

belongsTo(type: string): boolean

Checks whether this data type belongs to the specified uniform data type.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| type    | string  | Yes   |Uniform data type specified, which is a value of [UniformDataType](#uniformdatatype).  |

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if the data type belongs to or is the same as the specified uniform data type; returns **false** if they are not related.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |

**Example**

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

Checks whether this data type is a lower-level type of the specified uniform data type. For example, **TYPE_SCRIPT** is a lower-level type of **SOURCE_CODE**, and **TYPE_SCRIPT** and **SOURCE_CODE** are lower-level types of **TEXT**.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| type    | string  | Yes   |Uniform data type specified, which is a value of [UniformDataType](#uniformdatatype).  |

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if the data type is a lower-level type of the specified uniform data type; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |

**Example**

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

Checks whether this data type is a higher-level type of the specified uniform data type. For example, **SOURCE_CODE** is a higher-level type of **TYPE_SCRIPT**, and **TEXT** is a higher-level type of **SOURCE_CODE** and **TYPE_SCRIPT**.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| type    | string  | Yes   |Uniform data type specified, which is a value of [UniformDataType](#uniformdatatype).  |

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if the data type is a higher-level type of the specified uniform data type; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |

**Example**

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

Checks whether this data type is the same as the specified uniform data type. That is, compares **typeId**s of two [TypeDescriptor](#typedescriptor11) objects.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| typeDescriptor    | [TypeDescriptor](#typedescriptor11)  | Yes   |Uniform data type to compare.  |

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if the type IDs are the same; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |

**Example**

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

Obtains the **TypeDescriptor** object based on the uniform data type ID.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| typeId    | string  | Yes   |[Uniform data type ID](../../database/uniform-data-type-list.md#generic-utds).  |

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| [TypeDescriptor](#typedescriptor11) | **TypeDescriptor** object obtained. If the uniform data type does not exist, **null** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |

**Example**

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

Obtains the uniform data type ID based on the given file name extension and data type. If there are multiple uniform data type IDs matching the conditions, the first one is returned.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| filenameExtension    | string  | Yes   |File name extension.  |
| belongsTo    | string  | No   |ID of the uniform data type, to which the data type to be obtained belongs. If this parameter is not specified, the [uniform data type ID](../../database/uniform-data-type-list.md#generic-utds) is queried based on the file name extension.  |

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| string | ID of the uniform data type that matches the specified file name extension and **belongsTo** (if specified). If no match is found, the data type dynamically generated based on the rules specified by the input parameters is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |

**Example**

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

// If no uniform data type ID is found based on ".myts" and "general.plain-text", the type generated based on the input parameters is returned.
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

Obtains the uniform data type ID based on the given MIME type and data type. If there are multiple uniform data type IDs matching the conditions, the first one is returned.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| mimeType    | string  | Yes   |MIME type.  |
| belongsTo    | string  | No   |ID of the uniform data type, to which the data type to be obtained belongs. This parameter has no default value. If it is not specified, the uniform data type ID (../../database/uniform-data-type-list.md#generic-utds) is queried based on the specified MIME type.  |

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| string | ID of the uniform data type that matches the specified MIME type and **belongsTo** (if specified). If no match is found, the data type dynamically generated based on the rules specified by the input parameters is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |

**Example**

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

// If no uniform data type ID is found based on "image/myimage" and "general.image", the type generated based on the input parameters is returned.
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

Obtains the uniform data type IDs based on the given file name extension and data type.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| filenameExtension    | string  | Yes   |File name extension.  |
| belongsTo    | string  | No   |ID of the uniform data type, to which the data type to be obtained belongs. If this parameter is not specified, the [uniform data type ID](../../database/uniform-data-type-list.md#generic-utds) is queried based on the file name extension.  |

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| Array\<string> | Uniform data type IDs that match the specified file name extension and **belongsTo** (if specified). If no match is found, the data types dynamically generated based on the rules specified by the input parameters are returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |

**Example**

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

// If no uniform data type ID is found based on ".myts" and "general.plain-text", the types generated based on the input parameters are returned.
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

Obtains the uniform data type IDs based on the given MIME type and data type.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| mimeType    | string  | Yes   |MIME type.  |
| belongsTo    | string  | No   |ID of the uniform data type, to which the data type to be obtained belongs. This parameter has no default value. If it is not specified, the uniform data type ID (../../database/uniform-data-type-list.md#generic-utds) is queried based on the specified MIME type.  |

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| Array\<string> | Uniform data type IDs that match the specified MIME type and **belongsTo** (if specified). If no match is found, the data types dynamically generated based on the rules specified by the input parameters are returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |

**Example**

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

// If no uniform data type ID is found based on "image/myimage" and "general.image", the types generated based on the input parameters are returned.
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
