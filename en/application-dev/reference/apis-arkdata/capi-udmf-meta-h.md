# udmf_meta.h
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @jcwen-->
<!--Designer: @junathuawei1; @zph000-->
<!--Tester: @lj_liujing; @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

## Overview

Declares the unified data types.

**File to include**: <database/udmf/udmf_meta.h>

**Library**: libudmf.so

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Since**: 12

**Related module**: [UDMF](capi-udmf.md)

## Summary

### Macros

| Name                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| UDMF_META_ENTITY "general.entity"                            | Generic type that represents all physical storage types. It is used to define physical properties of a type.<br>This type is uncategorized.<br>**Since**: 12|
| UDMF_META_OBJECT "general.object"                            | Generic type that represents all logical content types. It is used to define physical properties of a type.<br>This type is uncategorized.<br>**Since**: 12|
| UDMF_META_COMPOSITE_OBJECT "general.composite-object"        | Generic composite content type. For example, a PDF file that contains text and image.<br>This type belongs to **OBJECT**.<br>**Since**: 12|
| UDMF_META_TEXT "general.text"                                | Generic text type.<br>This type belongs to **OBJECT**.<br>**Since**: 12   |
| UDMF_META_PLAIN_TEXT "general.plain-text"                    | Text without specific encoding or identifier.<br>This type belongs to **TEXT**.<br>**Since**: 12|
| UDMF_META_HTML "general.html"                                | HTML.<br>This type belongs to **TEXT**.<br>**Since**: 12         |
| UDMF_META_HYPERLINK "general.hyperlink"                      | Hyperlink.<br>This type belongs to **TEXT**.<br>**Since**: 12           |
| UDMF_META_XML "general.xml"                                  | XML.<br>This type belongs to **TEXT**.<br>**Since**: 12          |
| UDMF_META_SOURCE_CODE "general.source-code"                  | Generic source code type.<br>This type belongs to **PLAIN_TEXT**.<br>**Since**: 12|
| UDMF_META_SCRIPT "general.script"                            | Source code in any scripting language.<br>This type belongs to **SOURCE_CODE**.<br>**Since**: 12|
| UDMF_META_SHELL_SCRIPT "general.shell-script"                | Shell script.<br>This type belongs to **SCRIPT**.<br>**Since**: 12      |
| UDMF_META_CSH_SCRIPT "general.csh-script"                    | C shell script.<br>This type belongs to **SHELL_SCRIPT**.<br>**Since**: 12|
| UDMF_META_PERL_SCRIPT "general.perl-script"                  | Perl script.<br>This type belongs to **SHELL_SCRIPT**.<br>**Since**: 12 |
| UDMF_META_PHP_SCRIPT "general.php-script"                    | PHP script.<br>This type belongs to **SHELL_SCRIPT**.<br>**Since**: 12  |
| UDMF_META_PYTHON_SCRIPT "general.python-script"              | Python script.<br>This type belongs to **SHELL_SCRIPT**.<br>**Since**: 12|
| UDMF_META_RUBY_SCRIPT "general.ruby-script"                  | Ruby script.<br>This type belongs to **SHELL_SCRIPT**.<br>**Since**: 12 |
| UDMF_META_TYPE_SCRIPT "general.type-script"                  | TypeScript source code.<br>This type belongs to **SCRIPT**.<br>**Since**: 12|
| UDMF_META_JAVA_SCRIPT "general.java-script"                  | JavaScript source code.<br>This type belongs to **SCRIPT**.<br>**Since**: 12|
| UDMF_META_C_HEADER "general.c-header"                        | Header file in C.<br>This type belongs to **SOURCE_CODE**.<br>**Since**: 12   |
| UDMF_META_C_SOURCE "general.c-source"                        | Source code in C.<br>This type belongs to **SOURCE_CODE**.<br>**Since**: 12   |
| UDMF_META_C_PLUS_PLUS_HEADER "general.c-plus-plus-header"    | Header file in C++.<br>This type belongs to **SOURCE_CODE**.<br>**Since**: 12 |
| UDMF_META_C_PLUS_PLUS_SOURCE "general.c-plus-plus-source"    | Source code in C++.<br>This type belongs to **SOURCE_CODE**.<br>**Since**: 12 |
| UDMF_META_JAVA_SOURCE "general.java-source"                  | Source code in Java.<br>This type belongs to **SOURCE_CODE**.<br>**Since**: 12|
| UDMF_META_EBOOK "general.ebook"                              | Generic eBook file format type.<br>This type belongs to **COMPOSITE_OBJECT**.<br>**Since**: 12|
| UDMF_META_EPUB "general.epub"                                | Electronic publication (EPUB).<br>This type belongs to **EBOOK**.<br>**Since**: 12|
| UDMF_META_AZW "com.amazon.azw"                               | AZW.<br>This type belongs to **EBOOK**.<br>**Since**: 12|
| UDMF_META_AZW3 "com.amazon.azw3"                             | AZW3.<br>This type belongs to **EBOOK**.<br>**Since**: 12|
| UDMF_META_KFX "com.amazon.kfx"                               | KFX.<br>This type belongs to **EBOOK**.<br>**Since**: 12|
| UDMF_META_MOBI "com.amazon.mobi"                             | MOBI.<br>This type belongs to **EBOOK**.<br>**Since**: 12|
| UDMF_META_MEDIA "general.media"                              | Generic media type.<br>This type belongs to **OBJECT**.<br>**Since**: 12   |
| UDMF_META_IMAGE "general.image"                              | Image.<br>This type belongs to **MEDIA**.<br>**Since**: 12    |
| UDMF_META_JPEG "general.jpeg"                                | JPEG.<br>This type belongs to **IMAGE**.<br>**Since**: 12        |
| UDMF_META_PNG "general.png"                                  | PNG.<br>This type belongs to **IMAGE**.<br>**Since**: 12         |
| UDMF_META_RAW_IMAGE "general.raw-image"                      | Raw image.<br>This type belongs to **IMAGE**.<br>**Since**: 12|
| UDMF_META_TIFF "general.tiff"                                | TIFF.<br>This type belongs to **IMAGE**.<br>**Since**: 12        |
| UDMF_META_BMP "com.microsoft.bmp"                            | BMP.<br>This type belongs to **IMAGE**.<br>**Since**: 12 |
| UDMF_META_ICO "com.microsoft.ico"                            | Windows icon.<br>This type belongs to **IMAGE**.<br>**Since**: 12|
| UDMF_META_PHOTOSHOP_IMAGE "com.adobe.photoshop-image"        | Adobe Photoshop image.<br>This type belongs to **IMAGE**.<br>**Since**: 12|
| UDMF_META_AI_IMAGE "com.adobe.illustrator.ai-image"          | Adobe Illustrator image (.ai).<br>This type belongs to **IMAGE**.<br>**Since**: 12|
| UDMF_META_WORD_DOC "com.microsoft.word.doc"                  | Microsoft Word.<br>This type belongs to **COMPOSITE_OBJECT**.<br>**Since**: 12|
| UDMF_META_EXCEL "com.microsoft.excel.xls"                    | Microsoft Excel.<br>This type belongs to **COMPOSITE_OBJECT**.<br>**Since**: 12|
| UDMF_META_PPT "com.microsoft.powerpoint.ppt"                 | Microsoft PowerPoint presentation format.<br>This type belongs to **COMPOSITE_OBJECT**.<br>**Since**: 12|
| UDMF_META_PDF "com.adobe.pdf"                                | PDF.<br>This type belongs to **COMPOSITE_OBJECT**.<br>**Since**: 12|
| UDMF_META_POSTSCRIPT "com.adobe.postscript"                  | PostScript.<br>This type belongs to **COMPOSITE_OBJECT**.<br>**Since**: 12|
| UDMF_META_ENCAPSULATED_POSTSCRIPT "com.adobe.encapsulated-postscript" | Encapsulated PostScript.<br>This type belongs to **POSTSCRIPT**.<br>**Since**: 12|
| UDMF_META_VIDEO "general.video"                              | Base video type.<br>This type belongs to **MEDIA**.<br>**Since**: 12    |
| UDMF_META_AVI "general.avi"                                  | AVI.<br>This type belongs to **VIDEO**.<br>**Since**: 12         |
| UDMF_META_MPEG "general.mpeg"                                | MPEG-1 or MPEG-2.<br>This type belongs to **VIDEO**.<br>**Since**: 12|
| UDMF_META_MPEG4 "general.mpeg-4"                             | MPEG-4.<br>This type belongs to **VIDEO**.<br>**Since**: 12      |
| UDMF_META_VIDEO_3GPP "general.3gpp"                          | 3GP (3GPP file format).<br>This type belongs to **VIDEO**.<br>**Since**: 12        |
| UDMF_META_VIDEO_3GPP2 "general.3gpp2"                        | 3G2 (3GPP2 file format).<br>This type belongs to **VIDEO**.<br>**Since**: 12       |
| UDMF_META_WINDOWS_MEDIA_WM "com.microsoft.windows-media-wm"  | Windows WM format.<br>This type belongs to **VIDEO**.<br>**Since**: 12  |
| UDMF_META_WINDOWS_MEDIA_WMV "com.microsoft.windows-media-wmv" | Windows WMV format.<br>This type belongs to **VIDEO**.<br>**Since**: 12 |
| UDMF_META_WINDOWS_MEDIA_WMP "com.microsoft.windows-media-wmp" | Windows WMP format.<br>This type belongs to **VIDEO**.<br>**Since**: 12 |
| UDMF_META_AUDIO "general.audio"                              | Generic audio type.<br>This type belongs to **MEDIA**.<br>**Since**: 12    |
| UDMF_META_AAC "general.aac"                                  | AAC.<br>This type belongs to **AUDIO**.<br>**Since**: 12         |
| UDMF_META_AIFF "general.aiff"                                | AIFF.<br>This type belongs to **AUDIO**.<br>**Since**: 12        |
| UDMF_META_ALAC "general.alac"                                | ALAC.<br>This type belongs to **AUDIO**.<br>**Since**: 12        |
| UDMF_META_FLAC "general.flac"                                | FLAC.<br>This type belongs to **AUDIO**.<br>**Since**: 12       |
| UDMF_META_MP3 "general.mp3"                                  | MP3.<br>This type belongs to **AUDIO**.<br>**Since**: 12         |
| UDMF_META_OGG "general.ogg"                                  | OGG.<br>This type belongs to **AUDIO**.<br>**Since**: 12         |
| UDMF_META_PCM "general.pcm"                                  | PCM.<br>This type belongs to **AUDIO**.<br>**Since**: 12         |
| UDMF_META_WINDOWS_MEDIA_WMA "com.microsoft.windows-media-wma" | Windows WMA format.<br>This type belongs to **AUDIO**.<br>**Since**: 12 |
| UDMF_META_WAVEFORM_AUDIO "com.microsoft.waveform-audio"      | Windows Waveform.<br>This type belongs to **AUDIO**.<br>**Since**: 12 |
| UDMF_META_WINDOWS_MEDIA_WMX "com.microsoft.windows-media-wmx" | Windows WMX format.<br>This type belongs to **VIDEO**.<br>**Since**: 12 |
| UDMF_META_WINDOWS_MEDIA_WVX "com.microsoft.windows-media-wvx" | Windows WVX format.<br>This type belongs to **VIDEO**.<br>**Since**: 12 |
| UDMF_META_WINDOWS_MEDIA_WAX "com.microsoft.windows-media-wax" | Windows WAX format.<br>This type belongs to **AUDIO**.<br>**Since**: 12 |
| UDMF_META_GENERAL_FILE "general.file"                        | Generic file type.<br>This type belongs to **ENTITY**.<br>**Since**: 12   |
| UDMF_META_DIRECTORY "general.directory"                      | Generic directory type.<br>This type belongs to **ENTITY**.<br>**Since**: 12   |
| UDMF_META_FOLDER "general.folder"                            | Generic folder type.<br>This type belongs to **DIRECTORY**.<br>**Since**: 12|
| UDMF_META_SYMLINK "general.symlink"                          | Generic symbolic type.<br>This type belongs to **ENTITY**.<br>**Since**: 12|
| UDMF_META_ARCHIVE "general.archive"                          | Generic archive file type.<br>This type belongs to **OBJECT**.<br>**Since**: 12|
| UDMF_META_BZ2_ARCHIVE "general.bz2-archive"                  | BZ2.<br>This type belongs to **ARCHIVE**.<br>**Since**: 12   |
| UDMF_META_DISK_IMAGE "general.disk-image"                    | Generic type of any file that can be mounted as a volume.<br>This type belongs to **ARCHIVE**.<br>**Since**: 12|
| UDMF_META_TAR_ARCHIVE "general.tar-archive"                  | TAR.<br>This type belongs to **ARCHIVE**.<br>**Since**: 12   |
| UDMF_META_ZIP_ARCHIVE "general.zip-archive"                  | ZIP.<br>This type belongs to **ARCHIVE**.<br>**Since**: 12   |
| UDMF_META_JAVA_ARCHIVE "com.sun.java-archive"                | JAR (Java archive).<br>This type belongs to **ARCHIVE** and **EXECUTABLE**.<br>**Since**: 12|
| UDMF_META_GNU_TAR_ARCHIVE "org.gnu.gnu-tar-archive"          | GUN archive.<br>This type belongs to **ARCHIVE**.<br>**Since**: 12   |
| UDMF_META_GNU_ZIP_ARCHIVE "org.gnu.gnu-zip-archive"          | GZIP archive.<br>This type belongs to **ARCHIVE**.<br>**Since**: 12  |
| UDMF_META_GNU_ZIP_TAR_ARCHIVE "org.gnu.gnu-zip-tar-archive"  | GZIP TAR.<br>This type belongs to **ARCHIVE**.<br>**Since**: 12|
| UDMF_META_CALENDAR "general.calendar"                        | Generic calendar type.<br>This type belongs to **OBJECT**.<br>**Since**: 12|
| UDMF_META_CONTACT "general.contact"                          | Generic contact type.<br>This type belongs to **OBJECT**.<br>**Since**: 12|
| UDMF_META_DATABASE "general.database"                        | Generic database file type.<br>This type belongs to **OBJECT**.<br>**Since**: 12|
| UDMF_META_MESSAGE "general.message"                          | Generic message type.<br>This type belongs to **OBJECT**.<br>**Since**: 12|
| UDMF_META_VCARD "general.vcard"                              | Generic electronic business card type.<br>This type belongs to **OBJECT**.<br>**Since**: 12|
| UDMF_META_NAVIGATION "general.navigation"                    | Generic navigation data type.<br>This type belongs to **OBJECT**.<br>**Since**: 12|
| UDMF_META_LOCATION "general.location"                        | Location data.<br>This type belongs to **NAVIGATION**.<br>**Since**: 12   |
| UDMF_META_OPENHARMONY_FORM "openharmony.form"                | Widget defined for the system.<br>This type belongs to **OBJECT**.<br>**Since**: 12 |
| UDMF_META_OPENHARMONY_APP_ITEM "openharmony.app-item"        | Home screen icon defined for the system.<br>This type belongs to **OBJECT**.<br>**Since**: 12|
| UDMF_META_OPENHARMONY_PIXEL_MAP "openharmony.pixel-map"      | Pixel map defined for the system.<br>This type belongs to **IMAGE**.<br>**Since**: 12|
| UDMF_META_OPENHARMONY_ATOMIC_SERVICE "openharmony.atomic-service" | Atomic service type defined for the system.<br>This type belongs to **OBJECT**.<br>**Since**: 12|
| UDMF_META_OPENHARMONY_PACKAGE "openharmony.package"          | Package (compressed folder) defined for the system.<br>This type belongs to **DIRECTORY**.<br>**Since**: 12|
| UDMF_META_OPENHARMONY_HAP "openharmony.hap"                  | Ability package defined for the system.<br>This type belongs to **OPENHARMONY_PACKAGE**.<br>**Since**: 12|
| UDMF_META_SMIL "com.real.smil"                               | Synchronized Multimedia Integration Language (SMIL).<br>This type belongs to **XML**.<br>**Since**: 12|
| UDMF_META_MARKDOWN "general.markdown"                        | Markdown.<br>This type belongs to **PLAIN_TEXT**.<br>**Since**: 12|
| UDMF_META_FAX "general.fax"                                  | Generic type of the fax.<br>This type belongs to **IMAGE**.<br>**Since**: 12  |
| UDMF_META_JFX_FAX "com.j2.jfx-fax"                           | J2 jConnect fax file format.<br>This type belongs to **FAX**.<br>**Since**: 12|
| UDMF_META_EFX_FAX "com.js.efx-fax"                           | EFX file format.<br>This type belongs to **FAX**.<br>**Since**: 12      |
| UDMF_META_XBITMAP_IMAGE "general.xbitmap-image"              | X BitMAP (XBM) used in the X Window system (X11).<br>This type belongs to **IMAGE**.<br>**Since**: 12|
| UDMF_META_TGA_IMAGE "com.truevision.tga-image"               | Tagged Graphics (TGA) format.<br>This type belongs to **IMAGE**.<br>**Since**: 12|
| UDMF_META_SGI_IMAGE "com.sgi.sgi-image"                      | Silicon Graphics image (SGI) format.<br>This type belongs to **IMAGE**.<br>**Since**: 12|
| UDMF_META_OPENEXR_IMAGE "com.ilm.openexr-image"              | OpenXR image format.<br>This type belongs to **IMAGE**.<br>**Since**: 12|
| UDMF_META_FLASHPIX_IMAGE "com.kodak.flashpix.image"          | FlashPix image format.<br>This type belongs to **IMAGE**.<br>**Since**: 12|
| UDMF_META_REALMEDIA "com.real.realmedia"                     | RealMedia format.<br>This type belongs to **VIDEO**.<br>**Since**: 12      |
| UDMF_META_AU_AUDIO "general.au-audio"                        | AU format.<br>This type belongs to **AUDIO**.<br>**Since**: 12          |
| UDMF_META_AIFC_AUDIO "general.aifc-audio"                    | AIFC.<br>This type belongs to **AUDIO**.<br>**Since**: 12    |
| UDMF_META_SD2_AUDIO "com.digidesign.sd2-audio"               | Digidesign Sound Designer II (SDII).<br>This type belongs to **AUDIO**.<br>**Since**: 12|
| UDMF_META_REALAUDIO "com.real.realaudio"                     | RealAudio.<br>This type belongs to **AUDIO**.<br>**Since**: 12   |
| UDMF_META_OPENXML "org.openxmlformats.openxml"               | OpenXML base type.<br>This type belongs to **ARCHIVE**.<br>**Since**: 12     |
| UDMF_META_WORDPROCESSINGML_DOCUMENT "org.openxmlformats.wordprocessingml.document" | WordProcessingML format.<br>This type belongs to **OPENXML** and **COMPOSITE_OBJECT**.<br>**Since**: 12|
| UDMF_META_SPREADSHEETML_SHEET "org.openxmlformats.spreadsheetml.sheet" | SpreadsheetML format.<br>This type belongs to **OPENXML** and **COMPOSITE_OBJECT**.<br>**Since**: 12|
| UDMF_META_PRESENTATIONML_PRESENTATION "org.openxmlformats.presentationml.presentation" | PresentationML format.<br>This type belongs to **OPENXML** and **COMPOSITE_OBJECT**.<br>**Since**: 12|
| UDMF_META_OPENDOCUMENT "org.oasis.opendocument"              | OpenDocument format for Office applications.<br>This type belongs to **ARCHIVE**.<br>**Since**: 12|
| UDMF_META_OPENDOCUMENT_TEXT "org.oasis.opendocument.text"    | OpenDocument format for word processing (text) documents.<br>This type belongs to **OPENDOCUMENT** and **COMPOSITE_OBJECT**.<br>**Since**: 12|
| UDMF_META_OPENDOCUMENT_SPREADSHEET "org.oasis.opendocument.spreadsheet" | OpenDocument format for spreadsheets.<br>This type belongs to **OPENDOCUMENT** and **COMPOSITE_OBJECT**.<br>**Since**: 12|
| UDMF_META_OPENDOCUMENT_PRESENTATION "org.oasis.opendocument.presentation" | OpenDocument format for presentations.<br>This type belongs to **OPENDOCUMENT** and **COMPOSITE_OBJECT**.<br>**Since**: 12|
| UDMF_META_OPENDOCUMENT_GRAPHICS "org.oasis.opendocument.graphics" | OpenDocument format for graphics.<br>This type belongs to **OPENDOCUMENT** and **COMPOSITE_OBJECT**.<br>**Since**: 12|
| UDMF_META_OPENDOCUMENT_FORMULA "org.oasis.opendocument.formula" | OpenDocument format for formula.<br>This type belongs to **OPENDOCUMENT**.<br>**Since**: 12|
| UDMF_META_STUFFIT_ARCHIVE "com.allume.stuffit-archive"       | Stuffit compression format (stuffit archive).<br>This type belongs to **ARCHIVE**.<br>**Since**: 12|
| UDMF_META_VCS "general.vcs"                                  | VCalendar (VCS) format.<br>This type belongs to **CALENDAR** and **TEXT**.<br>**Since**: 12|
| UDMF_META_ICS "general.ics"                                  | Internet Calendaring and Scheduling (ICS) format.<br>This type belongs to **CALENDAR** and **TEXT**.<br>**Since**: 12|
| UDMF_META_EXECUTABLE "general.executable"                    | Generic type of all executable files.<br>This type belongs to **OBJECT**.<br>**Since**: 12|
| UDMF_META_PORTABLE_EXECUTABLE "com.microsoft.portable-executable" | Microsoft Windows portable executable format.<br>This type belongs to **EXECUTABLE**.<br>**Since**: 12|
| UDMF_META_SUN_JAVA_CLASS "com.sun.java-class"                | Java class file format.<br>This type belongs to **EXECUTABLE**.<br>**Since**: 12 |
| UDMF_META_FONT "general.font"                                | Basic type of fonts.<br>This type belongs to **OBJECT**.<br>**Since**: 12|
| UDMF_META_TRUETYPE_FONT "general.truetype-font"              | TrueType font format.<br>This type belongs to **FONT**.<br>**Since**: 12     |
| UDMF_META_TRUETYPE_COLLECTION_FONT "general.truetype-collection-font" | TrueType Collection font format.<br>This type belongs to **FONT**.<br>**Since**: 12|
| UDMF_META_OPENTYPE_FONT "general.opentype-font"              | OpenType font format.<br>This type belongs to **FONT**.<br>**Since**: 12     |
| UDMF_META_POSTSCRIPT_FONT "com.adobe.postscript-font"        | PostScript font format.<br>This type belongs to **FONT**.<br>**Since**: 12   |
| UDMF_META_POSTSCRIPT_PFB_FONT "com.adobe.postscript-pfb-font" | PostScript Font Binary font format.<br>This type belongs to **FONT**.<br>**Since**: 12|
| UDMF_META_POSTSCRIPT_PFA_FONT "com.adobe.postscript-pfa-font" | Adobe Type 1 font format.<br>This type belongs to **FONT**.<br>**Since**: 12|
| UDMF_META_OPENHARMONY_HDOC "openharmony.hdoc"                | Memo format defined for the system.<br>This type belongs to **COMPOSITE_OBJECT**.<br>**Since**: 12|
| UDMF_META_OPENHARMONY_HINOTE "openharmony.hinote"            | Note format defined for the system.<br>This type belongs to **COMPOSITE_OBJECT**.        |
| UDMF_META_OPENHARMONY_STYLED_STRING "openharmony.styled-string" | Style string type defined for the system.<br>This type belongs to **COMPOSITE_OBJECT**.<br>**Since**: 12|
| UDMF_META_OPENHARMONY_WANT "openharmony.want"                | Want defined for the system.<br>This type belongs to **OBJECT**.<br>**Since**: 12 |
| UDMF_META_GENERAL_FILE_URI "general.file-uri"                | File address type.<br>This type belongs to **TEXT**.<br>**Since**: 13         |
| UDMF_METE_GENERAL_CONTENT_FORM "general.content-form"        | Content card type.<br>This type belongs to **OBJECT**.<br>**Since**: 14       |
