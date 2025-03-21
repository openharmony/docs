# UDMF


## Overview

The Unified Data Management Framework (UDMF) defines standards for data management across applications, devices, and platforms, and provides a unified OpenHarmony data language and standard data access channels.

**Since**: 12

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [udmf.h](udmf_8h.md) | Defines the APIs, data structs, and enums for accessing the UDMF. <br/>File to include: &lt;database/udmf/udmf.h&gt; |
| [udmf_err_code.h](udmf__err__code_8h.md) | Declares the error codes used in the UDMF. <br/>File to include: &lt;database/udmf/udmf_err_code.h&gt; |
| [udmf_meta.h](udmf__meta_8h.md) | Declares the uniform data types. <br/>File to include: &lt;database/udmf/udmf_meta.h&gt; |
| [uds.h](uds_8h.md) | Defines the APIs and structs related to the uniform data structs. <br/>File to include: &lt;database/udmf/uds.h&gt; |
| [utd.h](utd_8h.md) | Defines APIs and structs related to the Uniform Type Descriptors (UTDs). <br/>File to include: &lt;database/udmf/utd.h&gt; |


### Macros

| Name| Description|
| -------- | -------- |
| [UDMF_KEY_BUFFER_LEN](#udmf_key_buffer_len)   (512) | Minimum length of the buffer that holds the key (unique identifier) of a uniform data object.|
| [UDMF_META_ENTITY](#udmf_meta_entity)   "general.entity" | Generic type that represents all physical storage types. It is used to define physical properties of a type.<br>This type is uncategorized.|
| [UDMF_META_OBJECT](#udmf_meta_object)   "general.object" | Generic type that represents all logical content types. It is used to define physical properties of a type.<br>This type is uncategorized.|
| [UDMF_META_COMPOSITE_OBJECT](#udmf_meta_composite_object)   "general.composite-object" | Generic composite content type. For example, a PDF file that contains text and image.<br>This type belongs to **OBJECT**.|
| [UDMF_META_TEXT](#udmf_meta_text)   "general.text" | Generic text type.<br>This type belongs to **OBJECT**.|
| [UDMF_META_PLAIN_TEXT](#udmf_meta_plain_text)   "general.plain-text" | Text without specific encoding or identifier.<br>This type belongs to **TEXT**.|
| [UDMF_META_HTML](#udmf_meta_html)   "general.html" | HTML.<br>This type belongs to **TEXT**.|
| [UDMF_META_HYPERLINK](#udmf_meta_hyperlink)   "general.hyperlink" | Hyperlink.<br>This type belongs to **TEXT**.|
| [UDMF_META_XML](#udmf_meta_xml)   "general.xml" | XML.<br>This type belongs to **TEXT**.|
| [UDMF_META_SOURCE_CODE](#udmf_meta_source_code)   "general.source-code" | Generic source code type.<br>This type belongs to **PLAIN_TEXT**.|
| [UDMF_META_SCRIPT](#udmf_meta_script)   "general.script" | Source code in any scripting language.<br>This type belongs to **SOURCE_CODE**.|
| [UDMF_META_SHELL_SCRIPT](#udmf_meta_shell_script)   "general.shell-script" | Shell script.<br>This type belongs to **SCRIPT**.|
| [UDMF_META_CSH_SCRIPT](#udmf_meta_csh_script)   "general.csh-script" | C shell script.<br>This type belongs to **SHELL_SCRIPT**.|
| [UDMF_META_PERL_SCRIPT](#udmf_meta_perl_script)   "general.perl-script" | Perl script.<br>This type belongs to **SHELL_SCRIPT**.|
| [UDMF_META_PHP_SCRIPT](#udmf_meta_php_script)   "general.php-script" | PHP script.<br>This type belongs to **SHELL_SCRIPT**.|
| [UDMF_META_PYTHON_SCRIPT](#udmf_meta_python_script)   "general.python-script" | Python script.<br>This type belongs to **SHELL_SCRIPT**.|
| [UDMF_META_RUBY_SCRIPT](#udmf_meta_ruby_script)   "general.ruby-script" | Ruby script.<br>This type belongs to **SHELL_SCRIPT**.|
| [UDMF_META_TYPE_SCRIPT](#udmf_meta_type_script)   "general.type-script" | TypeScript source code.<br>This type belongs to **SCRIPT**.|
| [UDMF_META_JAVA_SCRIPT](#udmf_meta_java_script)   "general.java-script" | JavaScript source code.<br>This type belongs to **SCRIPT**.|
| [UDMF_META_C_HEADER](#udmf_meta_c_header)   "general.c-header" | Header file in C.<br>This type belongs to **SOURCE_CODE**.|
| [UDMF_META_C_SOURCE](#udmf_meta_c_source)   "general.c-source" | Source code in C.<br>This type belongs to **SOURCE_CODE**.|
| [UDMF_META_C_PLUS_PLUS_HEADER](#udmf_meta_c_plus_plus_header)   "general.c-plus-plus-header" | Header file in C++.<br>This type belongs to **SOURCE_CODE**.|
| [UDMF_META_C_PLUS_PLUS_SOURCE](#udmf_meta_c_plus_plus_source)   "general.c-plus-plus-source" | Source code in C++.<br>This type belongs to **SOURCE_CODE**.|
| [UDMF_META_JAVA_SOURCE](#udmf_meta_java_source)   "general.java-source" | Source code in Java.<br>This type belongs to **SOURCE_CODE**.|
| [UDMF_META_EBOOK](#udmf_meta_ebook)   "general.ebook" | Generic eBook file format type.<br>This type belongs to **COMPOSITE_OBJECT**.|
| [UDMF_META_EPUB](#udmf_meta_epub)   "general.epub" | Electronic publication (EPUB).<br>This type belongs to **EBOOK**.|
| [UDMF_META_AZW](#udmf_meta_azw)   "com.amazon.azw" | AZW.<br>This type belongs to **EBOOK**.|
| [UDMF_META_AZW3](#udmf_meta_azw3)   "com.amazon.azw3" | AZW3.<br>This type belongs to **EBOOK**.|
| [UDMF_META_KFX](#udmf_meta_kfx)   "com.amazon.kfx" | KFX.<br>This type belongs to **EBOOK**.|
| [UDMF_META_MOBI](#udmf_meta_mobi)   "com.amazon.mobi" | MOBI.<br>This type belongs to **EBOOK**.|
| [UDMF_META_MEDIA](#udmf_meta_media)   "general.media" | Generic media type.<br>This type belongs to **OBJECT**.|
| [UDMF_META_IMAGE](#udmf_meta_image)   "general.image" | Image.<br>This type belongs to **MEDIA**.|
| [UDMF_META_JPEG](#udmf_meta_jpeg)   "general.jpeg" | JPEG.<br>This type belongs to **IMAGE**.|
| [UDMF_META_PNG](#udmf_meta_png)   "general.png" | PNG.<br>This type belongs to **IMAGE**.|
| [UDMF_META_RAW_IMAGE](#udmf_meta_raw_image)   "general.raw-image" | Raw image.<br>This type belongs to **IMAGE**.|
| [UDMF_META_TIFF](#udmf_meta_tiff)   "general.tiff" | TIFF.<br>This type belongs to **IMAGE**.|
| [UDMF_META_BMP](#udmf_meta_bmp)   "com.microsoft.bmp" | BMP.<br>This type belongs to **IMAGE**.|
| [UDMF_META_ICO](#udmf_meta_ico)   "com.microsoft.ico" | Windows icon.<br>This type belongs to **IMAGE**.|
| [UDMF_META_PHOTOSHOP_IMAGE](#udmf_meta_photoshop_image)   "com.adobe.photoshop-image" | Adobe Photoshop image.<br>This type belongs to **IMAGE**.|
| [UDMF_META_AI_IMAGE](#udmf_meta_ai_image)   "com.adobe.illustrator.ai-image" | Adobe Illustrator image (.ai).<br>This type belongs to **IMAGE**.|
| [UDMF_META_WORD_DOC](#udmf_meta_word_doc)   "com.microsoft.word.doc" | Microsoft Word.<br>This type belongs to **COMPOSITE_OBJECT**.|
| [UDMF_META_EXCEL](#udmf_meta_excel)   "com.microsoft.excel.xls" | Microsoft Excel.<br>This type belongs to **COMPOSITE_OBJECT**.|
| [UDMF_META_PPT](#udmf_meta_ppt)   "com.microsoft.powerpoint.ppt" | Microsoft PowerPoint presentation format.<br>This type belongs to **COMPOSITE_OBJECT**.|
| [UDMF_META_PDF](#udmf_meta_pdf)   "com.adobe.pdf" | PDF.<br>This type belongs to **COMPOSITE_OBJECT**.|
| [UDMF_META_POSTSCRIPT](#udmf_meta_postscript)   "com.adobe.postscript" | PostScript.<br>This type belongs to **COMPOSITE_OBJECT**.|
| [UDMF_META_ENCAPSULATED_POSTSCRIPT](#udmf_meta_encapsulated_postscript)   "com.adobe.encapsulated-postscript" | Encapsulated PostScript.<br>This type belongs to **POSTSCRIPT**.|
| [UDMF_META_VIDEO](#udmf_meta_video)   "general.video" | Generic video type.<br>This type belongs to **MEDIA**.|
| [UDMF_META_AVI](#udmf_meta_avi)   "general.avi" | AVI.<br>This type belongs to **VIDEO**.|
| [UDMF_META_MPEG](#udmf_meta_mpeg)   "general.mpeg" | MPGE-1 or MPGE-2.<br>This type belongs to **VIDEO**.|
| [UDMF_META_MPEG4](#udmf_meta_mpeg4)   "general.mpeg-4" | MPGE-4.<br>This type belongs to **VIDEO**.|
| [UDMF_META_VIDEO_3GPP](#udmf_meta_video_3gpp)   "general.3gpp" | 3GP (3GPP file format).<br>This type belongs to **VIDEO**.|
| [UDMF_META_VIDEO_3GPP2](#udmf_meta_video_3gpp2)   "general.3gpp2" | 3G2 (3GPP2 file format).<br>This type belongs to **VIDEO**.|
| [UDMF_META_WINDOWS_MEDIA_WM](#udmf_meta_windows_media_wm)   "com.microsoft.windows-media-wm" | Windows WM format.<br>This type belongs to **VIDEO**.|
| [UDMF_META_WINDOWS_MEDIA_WMV](#udmf_meta_windows_media_wmv)   "com.microsoft.windows-media-wmv" | Windows WMV format.<br>This type belongs to **VIDEO**.|
| [UDMF_META_WINDOWS_MEDIA_WMP](#udmf_meta_windows_media_wmp)   "com.microsoft.windows-media-wmp" | Windows WMP format.<br>This type belongs to **VIDEO**.|
| [UDMF_META_AUDIO](#udmf_meta_audio)   "general.audio" | Generic audio type.<br>This type belongs to **MEDIA**.|
| [UDMF_META_AAC](#udmf_meta_aac)   "general.aac" | AAC.<br>This type belongs to **AUDIO**.|
| [UDMF_META_AIFF](#udmf_meta_aiff)   "general.aiff" | AIFF.<br>This type belongs to **AUDIO**.|
| [UDMF_META_ALAC](#udmf_meta_alac)   "general.alac" | ALAC.<br>This type belongs to **AUDIO**.|
| [UDMF_META_FLAC](#udmf_meta_flac)   "general.flac" | FLAC.<br>This type belongs to **AUDIO**.|
| [UDMF_META_MP3](#udmf_meta_mp3)   "general.mp3" | MP3.<br>This type belongs to **AUDIO**.|
| [UDMF_META_OGG](#udmf_meta_ogg)   "general.ogg" | OGG.<br>This type belongs to **AUDIO**.|
| [UDMF_META_PCM](#udmf_meta_pcm)   "general.pcm" | PCM.<br>This type belongs to **AUDIO**.|
| [UDMF_META_WINDOWS_MEDIA_WMA](#udmf_meta_windows_media_wma)   "com.microsoft.windows-media-wma" | Windows WMA.<br>This type belongs to **AUDIO**.|
| [UDMF_META_WAVEFORM_AUDIO](#udmf_meta_waveform_audio)   "com.microsoft.waveform-audio" | Windows Waveform.<br>This type belongs to **AUDIO**.|
| [UDMF_META_WINDOWS_MEDIA_WMX](#udmf_meta_windows_media_wmx)   "com.microsoft.windows-media-wmx" | Windows WMX format.<br>This type belongs to **VIDEO**.|
| [UDMF_META_WINDOWS_MEDIA_WVX](#udmf_meta_windows_media_wvx)   "com.microsoft.windows-media-wvx" | Windows WVX format.<br>This type belongs to **VIDEO**.|
| [UDMF_META_WINDOWS_MEDIA_WAX](#udmf_meta_windows_media_wax)   "com.microsoft.windows-media-wax" | Windows WAX.<br>This type belongs to **AUDIO**.|
| [UDMF_META_GENERAL_FILE](#udmf_meta_general_file)   "general.file" | Generic file type.<br>This type belongs to **ENTITY**.|
| [UDMF_META_DIRECTORY](#udmf_meta_directory)   "general.directory" | Generic directory type.<br>This type belongs to **ENTITY**.|
| [UDMF_META_FOLDER](#udmf_meta_folder)   "general.folder" | Generic folder type.<br>This type belongs to **DIRECTORY**.|
| [UDMF_META_SYMLINK](#udmf_meta_symlink)   "general.symlink" | Generic symbolic type.<br>This type belongs to **ENTITY**.|
| [UDMF_META_ARCHIVE](#udmf_meta_archive)   "general.archive" | Generic archive file type.<br>This type belongs to **OBJECT**.|
| [UDMF_META_BZ2_ARCHIVE](#udmf_meta_bz2_archive)   "general.bz2-archive" | BZ2.<br>This type belongs to **ARCHIVE**.|
| [UDMF_META_DISK_IMAGE](#udmf_meta_disk_image)   "general.disk-image" | Generic type of any file that can be mounted as a volume.<br>This type belongs to **ARCHIVE**.|
| [UDMF_META_TAR_ARCHIVE](#udmf_meta_tar_archive)   "general.tar-archive" | TAR.<br>This type belongs to ARCHIVE.|
| [UDMF_META_ZIP_ARCHIVE](#udmf_meta_zip_archive)   "general.zip-archive" | ZIP.<br>This type belongs to **ARCHIVE**.|
| [UDMF_META_JAVA_ARCHIVE](#udmf_meta_java_archive)   "com.sun.java-archive" | JAR (Java archive).<br>This type belongs to **ARCHIVE** and **EXECUTABLE**.|
| [UDMF_META_GNU_TAR_ARCHIVE](#udmf_meta_gnu_tar_archive)   "org.gnu.gnu-tar-archive" | GUN archive.<br>This type belongs to **ARCHIVE**.|
| [UDMF_META_GNU_ZIP_ARCHIVE](#udmf_meta_gnu_zip_archive)   "org.gnu.gnu-zip-archive" | GZIP archive.<br>This type belongs to **ARCHIVE**.|
| [UDMF_META_GNU_ZIP_TAR_ARCHIVE](#udmf_meta_gnu_zip_tar_archive)   "org.gnu.gnu-zip-tar-archive" | GZIP TAR.<br>This type belongs to **ARCHIVE**.|
| [UDMF_META_CALENDAR](#udmf_meta_calendar)   "general.calendar" | Generic calendar type.<br>This type belongs to **OBJECT**.|
| [UDMF_META_CONTACT](#udmf_meta_contact)   "general.contact" | Generic contact type.<br>This type belongs to **OBJECT**.|
| [UDMF_META_DATABASE](#udmf_meta_database)   "general.database" | Generic database file type.<br>This type belongs to **OBJECT**.|
| [UDMF_META_MESSAGE](#udmf_meta_message)   "general.message" | Generic message type.<br>This type belongs to **OBJECT**.|
| [UDMF_META_VCARD](#udmf_meta_vcard)   "general.vcard" | Generic electronic business card type.<br>This type belongs to **OBJECT**.|
| [UDMF_META_NAVIGATION](#udmf_meta_navigation)   "general.navigation" | Generic navigation data type.<br>This type belongs to **OBJECT**.|
| [UDMF_META_LOCATION](#udmf_meta_location)   "general.location" | Location data.<br>This type belongs to **NAVIGATION**.|
| [UDMF_META_OPENHARMONY_FORM](#udmf_meta_openharmony_form)   "openharmony.form" | Widget defined for the system.<br>This type belongs to **OBJECT**.|
| [UDMF_META_OPENHARMONY_APP_ITEM](#udmf_meta_openharmony_app_item)   "openharmony.app-item" | Home screen icon defined for the system.<br>This type belongs to **OBJECT**.|
| [UDMF_META_OPENHARMONY_PIXEL_MAP](#udmf_meta_openharmony_pixel_map)   "openharmony.pixel-map" | Pixel map defined for the system.<br>This type belongs to **IMAGE**.|
| [UDMF_META_OPENHARMONY_ATOMIC_SERVICE](#udmf_meta_openharmony_atomic_service)   "openharmony.atomic-service" | Atomic service type defined for the system.<br>This type belongs to **OBJECT**.|
| [UDMF_META_OPENHARMONY_PACKAGE](#udmf_meta_openharmony_package)   "openharmony.package" | Package (compressed folder) defined for the system.<br>This type belongs to **DIRECTORY**.|
| [UDMF_META_OPENHARMONY_HAP](#udmf_meta_openharmony_hap)   "openharmony.hap" | Ability package defined for the system.<br>This type belongs to **OPENHARMONY_PACKAGE**.|
| [UDMF_META_SMIL](#udmf_meta_smil)   "com.real.smil" | Synchronized Multimedia Integration Language (SMIL).<br>This type belongs to **XML**.|
| [UDMF_META_MARKDOWN](#udmf_meta_markdown)   "general.markdown" | Markdown.<br>This type belongs to **PLAIN_TEXT**.|
| [UDMF_META_FAX](#udmf_meta_fax)   "general.fax" | Generic type of the fax.<br>This type belongs to **IMAGE**.|
| [UDMF_META_JFX_FAX](#udmf_meta_jfx_fax)   "com.j2.jfx-fax" | J2 jConnect fax file format.<br>This type belongs to **FAX**.|
| [UDMF_META_EFX_FAX](#udmf_meta_efx_fax)   "com.js.efx-fax" | EFX file format.<br>This type belongs to **FAX**.|
| [UDMF_META_XBITMAP_IMAGE](#udmf_meta_xbitmap_image)   "general.xbitmap-image" | X BitMAP (XBM) used in the X Window system (X11).<br>This type belongs to **IMAGE**.|
| [UDMF_META_TGA_IMAGE](#udmf_meta_tga_image)   "com.truevision.tga-image" | Tagged Graphics (TGA) format.<br>This type belongs to **IMAGE**.|
| [UDMF_META_SGI_IMAGE](#udmf_meta_sgi_image)   "com.sgi.sgi-image" | Silicon Graphics image (SGI) format.<br>This type belongs to **IMAGE**.|
| [UDMF_META_OPENEXR_IMAGE](#udmf_meta_openexr_image)   "com.ilm.openexr-image" | OpenXR image format.<br>This type belongs to **IMAGE**.|
| [UDMF_META_FLASHPIX_IMAGE](#udmf_meta_flashpix_image)   "com.kodak.flashpix.image" | FlashPix image format.<br>This type belongs to **IMAGE**.|
| [UDMF_META_REALMEDIA](#udmf_meta_realmedia)   "com.real.realmedia" | RealMedia format.<br>This type belongs to **VIDEO**.|
| [UDMF_META_AU_AUDIO](#udmf_meta_au_audio)   "general.au-audio" | AU format.<br>This type belongs to **AUDIO**.|
| [UDMF_META_AIFC_AUDIO](#udmf_meta_aifc_audio)   "general.aifc-audio" | AIFC.<br>This type belongs to **AUDIO**.|
| [UDMF_META_SD2_AUDIO](#udmf_meta_sd2_audio)   "com.digidesign.sd2-audio" | Digidesign Sound Designer II (SDII).<br>This type belongs to **AUDIO**.|
| [UDMF_META_REALAUDIO](#udmf_meta_realaudio)   "com.real.realaudio" | RealAudio.<br>This type belongs to **AUDIO**.|
| [UDMF_META_OPENXML](#udmf_meta_openxml)   "org.openxmlformats.openxml" | OpenXML base type.<br>This type belongs to **ARCHIVE**.|
| [UDMF_META_WORDPROCESSINGML_DOCUMENT](#udmf_meta_wordprocessingml_document)   "org.openxmlformats.wordprocessingml.document" | WordProcessingML format.<br>This type belongs to **OPENXML** and **COMPOSITE_OBJECT**.|
| [UDMF_META_SPREADSHEETML_SHEET](#udmf_meta_spreadsheetml_sheet)   "org.openxmlformats.spreadsheetml.sheet" | SpreadsheetML format.<br>This type belongs to **OPENXML** and **COMPOSITE_OBJECT**.|
| [UDMF_META_PRESENTATIONML_PRESENTATION](#udmf_meta_presentationml_presentation)   "org.openxmlformats.presentationml.presentation" | PresentationML format.<br>This type belongs to **OPENXML** and **COMPOSITE_OBJECT**.|
| [UDMF_META_OPENDOCUMENT](#udmf_meta_opendocument)   "org.oasis.opendocument" | OpenDocument format for Office applications.<br>This type belongs to **ARCHIVE**.|
| [UDMF_META_OPENDOCUMENT_TEXT](#udmf_meta_opendocument_text)   "org.oasis.opendocument.text" | OpenDocument format for word processing (text) documents.<br>This type belongs to **OPENDOCUMENT** and **COMPOSITE_OBJECT**.|
| [UDMF_META_OPENDOCUMENT_SPREADSHEET](#udmf_meta_opendocument_spreadsheet)   "org.oasis.opendocument.spreadsheet" | OpenDocument format for spreadsheets.<br>This type belongs to **OPENDOCUMENT** and **COMPOSITE_OBJECT**.|
| [UDMF_META_OPENDOCUMENT_PRESENTATION](#udmf_meta_opendocument_presentation)   "org.oasis.opendocument.presentation" | OpenDocument format for presentations.<br>This type belongs to **OPENDOCUMENT** and **COMPOSITE_OBJECT**.|
| [UDMF_META_OPENDOCUMENT_GRAPHICS](#udmf_meta_opendocument_graphics)   "org.oasis.opendocument.graphics" | OpenDocument format for graphics.<br>This type belongs to **OPENDOCUMENT** and **COMPOSITE_OBJECT**.|
| [UDMF_META_OPENDOCUMENT_FORMULA](#udmf_meta_opendocument_formula)   "org.oasis.opendocument.formula" | OpenDocument format for formula.<br>This type belongs to **OPENDOCUMENT**.|
| [UDMF_META_STUFFIT_ARCHIVE](#udmf_meta_stuffit_archive)   "com.allume.stuffit-archive" | Stuffit compression format (stuffit archive).<br>This type belongs to **ARCHIVE**.|
| [UDMF_META_VCS](#udmf_meta_vcs)   "general.vcs" | VCalendar (VCS) format.<br>This type belongs to **CALENDAR** and **TEXT**.|
| [UDMF_META_ICS](#udmf_meta_ics)   "general.ics" | Internet Calendaring and Scheduling (ICS) format.<br>This type belongs to **CALENDAR** and **TEXT**.|
| [UDMF_META_EXECUTABLE](#udmf_meta_executable)   "general.executable" | Generic type of all executable files.<br>This type belongs to **OBJECT**.|
| [UDMF_META_PORTABLE_EXECUTABLE](#udmf_meta_portable_executable)   "com.microsoft.portable-executable" | Microsoft Windows portable executable format.<br>This type belongs to **EXECUTABLE**.|
| [UDMF_META_SUN_JAVA_CLASS](#udmf_meta_sun_java_class)   "com.sun.java-class" | Java class file format.<br>This type belongs to **EXECUTABLE**.|
| [UDMF_META_FONT](#udmf_meta_font)   "general.font" | Basic type of fonts.<br>This type belongs to **OBJECT**.|
| [UDMF_META_TRUETYPE_FONT](#udmf_meta_truetype_font)   "general.truetype-font" | TrueType font format.<br>This type belongs to **FONT**.|
| [UDMF_META_TRUETYPE_COLLECTION_FONT](#udmf_meta_truetype_collection_font)   "general.truetype-collection-font" | TrueType Collection font format.<br>This type belongs to **FONT**.|
| [UDMF_META_OPENTYPE_FONT](#udmf_meta_opentype_font)   "general.opentype-font" | OpenType font format.<br>This type belongs to **FONT**.|
| [UDMF_META_POSTSCRIPT_FONT](#udmf_meta_postscript_font)   "com.adobe.postscript-font" | PostScript font format.<br>This type belongs to **FONT**.|
| [UDMF_META_POSTSCRIPT_PFB_FONT](#udmf_meta_postscript_pfb_font)   "com.adobe.postscript-pfb-font" | PostScript Font Binary font format.<br>This type belongs to **FONT**.|
| [UDMF_META_POSTSCRIPT_PFA_FONT](#udmf_meta_postscript_pfa_font)   "com.adobe.postscript-pfa-font" | Adobe Type 1 font format.<br>This type belongs to **FONT**.|
| [UDMF_META_OPENHARMONY_HDOC](#udmf_meta_openharmony_hdoc)   "openharmony.hdoc" | Memo format defined for the system.<br>This type belongs to **COMPOSITE_OBJECT**.|
| [UDMF_META_OPENHARMONY_HINOTE](#udmf_meta_openharmony_hinote)   "openharmony.hinote" | Note format defined for the system.<br>This type belongs to **COMPOSITE_OBJECT**.|
| [UDMF_META_OPENHARMONY_STYLED_STRING](#udmf_meta_openharmony_styled_string)   "openharmony.styled-string" | Style string type defined for the system.<br>This type belongs to **COMPOSITE_OBJECT**.|
| [UDMF_META_OPENHARMONY_WANT](#udmf_meta_openharmony_want)   "openharmony.want" | Want defined for the system.<br>This type belongs to **OBJECT**.|
| [UDMF_META_GENERAL_FILE_URI](#udmf_meta_general_file_uri)   "general.file-uri" | File address type.<br>This type belongs to **TEXT**.|
| [UDMF_METE_GENERAL_CONTENT_FORM](#udmf_mete_general_content_form)   "general.content-form" | Content widget type.<br>This type belongs to **OBJECT**.|

### Types

| Name| Description|
| -------- | -------- |
| typedef enum [Udmf_Intention](#udmf_intention) [Udmf_Intention](#udmf_intention) | Defines an enum for UDMF data channels.|
| typedef enum [Udmf_ShareOption](#udmf_shareoption) [Udmf_ShareOption](#udmf_shareoption) | Defines an enum for the scopes of the uniform data to be used on a device.|
| typedef struct [OH_UdmfData](#oh_udmfdata) [OH_UdmfData](#oh_udmfdata) | Defines a struct for a uniform data object.|
| typedef struct [OH_UdmfRecord](#oh_udmfrecord) [OH_UdmfRecord](#oh_udmfrecord) | Defines a struct for a data record in a uniform data object.|
| typedef struct [OH_UdmfRecordProvider](#oh_udmfrecordprovider) [OH_UdmfRecordProvider](#oh_udmfrecordprovider) | Defines a struct for the data record provider in a uniform data object.|
| typedef struct [OH_UdmfProperty](#oh_udmfproperty) [OH_UdmfProperty](#oh_udmfproperty) | Defines a struct for a data record property in a uniform data object.|
| typedef void(\* [UdmfData_Finalize](#udmfdata_finalize)) (void \*context) | Defines a callback function used to release the context. This callback is invoked when the **OH_UdmfRecordProvider** instance is destroyed.|
| typedef void \*(\* [OH_UdmfRecordProvider_GetData](#oh_udmfrecordprovider_getdata)) (void \*context, const char \*type) | Defines a callback function used to obtain data by type. This callback will be invoked to return the data obtained from **OH_UdmfRecord**.|
| typedef enum [Udmf_ErrCode](#udmf_errcode) [Udmf_ErrCode](#udmf_errcode) | Defines an enum for error codes.|
| typedef struct [OH_UdsPlainText](#oh_udsplaintext) [OH_UdsPlainText](#oh_udsplaintext) | Defines a struct for the uniform data of the plain text type.|
| typedef struct [OH_UdsHyperlink](#oh_udshyperlink) [OH_UdsHyperlink](#oh_udshyperlink) | Defines a struct for the uniform data of the hyperlink type.|
| typedef struct [OH_UdsHtml](#oh_udshtml) [OH_UdsHtml](#oh_udshtml) | Defines a struct for the uniform data of the Hypertext Markup Language (HTML) type.|
| typedef struct [OH_UdsAppItem](#oh_udsappitem) [OH_UdsAppItem](#oh_udsappitem) | Defines a struct for the uniform data of the home screen icon type.|
| typedef struct [OH_UdsFileUri](#oh_udsfileuri) [OH_UdsFileUri](#oh_udsfileuri) | Defines a struct for the file URI type.|
| typedef struct [OH_UdsPixelMap](#oh_udspixelmap) [OH_UdsPixelMap](#oh_udspixelmap) | Defines a struct for the pixel map type.|
| typedef struct [OH_UdsArrayBuffer](#oh_udsarraybuffer) [OH_UdsArrayBuffer](#oh_udsarraybuffer) | Defines a struct for the ArrayBuffer type.|
| typedef struct [OH_Utd](#oh_utd) [OH_Utd](#oh_utd) | Defines a struct for a Uniform Type Descriptor (UTD).|
| typedef struct [OH_UdsContentForm](#oh_udscontentform) [OH_UdsContentForm](#oh_udscontentform) | Defines a struct for the uniform data of the content widget type.|
| typedef enum [Udmf_ListenerStatus](#udmf_listenerstatus) [Udmf_ListenerStatus](#udmf_listenerstatus) | Defines an enum for the status codes returned when data is obtained asynchronously.|
| typedef enum [Udmf_FileConflictOptions](#udmf_fileconflictoptions) [Udmf_FileConflictOptions](#udmf_fileconflictoptions) | Defines an enum for the options used to resolve file copy conflicts.|
| typedef enum [Udmf_ProgressIndicator](#udmf_progressindicator) [Udmf_ProgressIndicator](#udmf_progressindicator) | Defines an enum for the progress indicator options.|
| typedef struct [OH_Udmf_ProgressInfo](#oh_udmf_progressinfo) [OH_Udmf_ProgressInfo](#oh_udmf_progressinfo) | Defines a struct for progress information.|
| typedef struct [OH_UdmfGetDataParams](#oh_udmfgetdataparams) [OH_UdmfGetDataParams](#oh_udmfgetdataparams) | Defines a struct for parameters used to obtain UDMF data asynchronously.|
| typedef void(\* [OH_Udmf_DataProgressListener](#oh_udmf_dataprogresslistener)) ([OH_Udmf_ProgressInfo](#oh_udmf_progressinfo) \*progressInfo, [OH_UdmfData](#oh_udmfdata) \*data) | Defines the callback used to return the data retrieval progress information and data obtained.<br>A null pointer is returned if the progress is not 100. The data obtained is returned only when the progress reaches 100.|

### Enums

| Name| Description|
| -------- | -------- |
| [Udmf_Intention](#udmf_intention) { UDMF_INTENTION_DRAG, UDMF_INTENTION_PASTEBOARD } | Enumerates the UDMF data channel types. |
| [Udmf_ShareOption](#udmf_shareoption-1) { SHARE_OPTIONS_INVALID, SHARE_OPTIONS_IN_APP, SHARE_OPTIONS_CROSS_APP } | Enumerates the scopes of the uniform data to be used on a device. |
| [Udmf_ErrCode](#udmf_errcode-1) { UDMF_E_OK = 0, UDMF_ERR = 20400000, UDMF_E_INVALID_PARAM = (UDMF_ERR + 1) } | Enumerates the error codes.|
| [Udmf_ListenerStatus](#udmf_listenerstatus-1) {<br>UDMF_FINISHED = 0, UDMF_PROCESSING, UDMF_CANCELED, UDMF_INNER_ERROR = 200,<br>UDMF_INVALID_PARAMETERS, UDMF_DATA_NOT_FOUND, UDMF_SYNC_FAILED, UDMF_COPY_FILE_FAILED<br>} | Enumerates the status codes returned when data is obtained asynchronously.|
| [Udmf_FileConflictOptions](#udmf_fileconflictoptions-1) { UDMF_OVERWRITE = 0, UDMF_SKIP = 1 } | Enumerates the options used to resolve file copy conflicts.|
| [Udmf_ProgressIndicator](#udmf_progressindicator-1) { UDMF_NONE = 0, UDMF_DEFAULT = 1 } | Enumerates the progress indicator options.|


### Functions

| Name| Description|
| -------- | -------- |
| int [OH_UdmfProgressInfo_GetProgress](#oh_udmfprogressinfo_getprogress) ([OH_Udmf_ProgressInfo](#oh_udmf_progressinfo) \*progressInfo) | Obtains the progress information from [OH_Udmf_ProgressInfo](#oh_udmf_progressinfo).|
| int [OH_UdmfProgressInfo_GetStatus](#oh_udmfprogressinfo_getstatus) ([OH_Udmf_ProgressInfo](#oh_udmf_progressinfo) \*progressInfo) | Obtains the status information from [OH_Udmf_ProgressInfo](#oh_udmf_progressinfo).|
| [OH_UdmfGetDataParams](#oh_udmfgetdataparams) \* [OH_UdmfGetDataParams_Create](#oh_udmfgetdataparams_create) () | Creates an [OH_UdmfGetDataParams](#oh_udmfgetdataparams) instance for asynchronously obtaining UDMF data.<br>If this pointer is no longer required, use [OH_UdmfGetDataParams_Destroy](#oh_udmfgetdataparams_destroy) to destroy it. Otherwise, memory leaks may occur.|
| void [OH_UdmfGetDataParams_Destroy](#oh_udmfgetdataparams_destroy) ([OH_UdmfGetDataParams](#oh_udmfgetdataparams) \*pThis) | Destroys an [OH_UdmfGetDataParams](#oh_udmfgetdataparams) instance.|
| void [OH_UdmfGetDataParams_SetDestUri](#oh_udmfgetdataparams_setdesturi) ([OH_UdmfGetDataParams](#oh_udmfgetdataparams) \*params, const char \*destUri) | Sets the destination directory in an [OH_UdmfGetDataParams](#oh_udmfgetdataparams) instance.<br>If the destination directory is set, data of the file type will be copied to the specified directory. The file type data obtained in the callback will be replaced with the URI of the destination directory.<br>If the destination directory is not specified, the file will not be copied. The file type data obtained in the callback is the URI of the source directory.<br>If the application involves complex file processing or files need to be copied to multiple directories, you are advised to leave this parameter unspecified and let the application to handle the file copy.|
| void [OH_UdmfGetDataParams_SetFileConflictOptions](#oh_udmfgetdataparams_setfileconflictoptions) ([OH_UdmfGetDataParams](#oh_udmfgetdataparams) \*params, const [Udmf_FileConflictOptions](#udmf_fileconflictoptions) options) | Sets the policy for resolving file conflicts in an [OH_UdmfGetDataParams](#oh_udmfgetdataparams) instance.|
| void [OH_UdmfGetDataParams_SetProgressIndicator](#oh_udmfgetdataparams_setprogressindicator) ([OH_UdmfGetDataParams](#oh_udmfgetdataparams) \*params, const [Udmf_ProgressIndicator](#udmf_progressindicator) progressIndicator) | Sets the progress indicator in an [OH_UdmfGetDataParams](#oh_udmfgetdataparams) instance.|
| void [OH_UdmfGetDataParams_SetDataProgressListener](#oh_udmfgetdataparams_setdataprogresslistener) ([OH_UdmfGetDataParams](#oh_udmfgetdataparams) \*params, const [OH_Udmf_DataProgressListener](#oh_udmf_dataprogresslistener) dataProgressListener) | Sets the callback used to return the data obtained in an [OH_UdmfGetDataParams](#oh_udmfgetdataparams) instance.|
| int [OH_UdmfRecord_AddContentForm](#oh_udmfrecord_addcontentform) ([OH_UdmfRecord](#oh_udmfrecord) \*pThis, [OH_UdsContentForm](#oh_udscontentform) \*contentForm) | Adds data of the [OH_UdsContentForm](#oh_udscontentform) type to an [OH_UdmfRecord](#oh_udmfrecord) instance.|
| int [OH_UdmfRecord_GetContentForm](#oh_udmfrecord_getcontentform) ([OH_UdmfRecord](#oh_udmfrecord) \*pThis, [OH_UdsContentForm](#oh_udscontentform) \*contentForm) | Obtains data of the [OH_UdsContentForm](#oh_udscontentform) type from an [OH_UdmfRecord](#oh_udmfrecord) instance.|
| [OH_UdsContentForm](#oh_udscontentform) \* [OH_UdsContentForm_Create](#oh_udscontentform_create) () | Creates an [OH_UdsContentForm](#oh_udscontentform) instance and a pointer to it.|
| void [OH_UdsContentForm_Destroy](#oh_udscontentform_destroy) ([OH_UdsContentForm](#oh_udscontentform) \*pThis) | Destroys an [OH_UdsContentForm](#oh_udscontentform) instance.|
| const char \* [OH_UdsContentForm_GetType](#oh_udscontentform_gettype) ([OH_UdsContentForm](#oh_udscontentform) \*pThis) | Obtains the type ID from an [OH_UdsContentForm](#oh_udscontentform) instance.|
| int [OH_UdsContentForm_GetThumbData](#oh_udscontentform_getthumbdata) ([OH_UdsContentForm](#oh_udscontentform) \*pThis, unsigned char \*\*thumbData, unsigned int \*len) | Obtains image data from an [OH_UdsContentForm](#oh_udscontentform) instance.|
| const char \* [OH_UdsContentForm_GetDescription](#oh_udscontentform_getdescription) ([OH_UdsContentForm](#oh_udscontentform) \*pThis) | Obtains the description from an [OH_UdsContentForm](#oh_udscontentform) instance.|
| const char \* [OH_UdsContentForm_GetTitle](#oh_udscontentform_gettitle) ([OH_UdsContentForm](#oh_udscontentform) \*pThis) | Obtains the title from an [OH_UdsContentForm](#oh_udscontentform) instance.|
| int [OH_UdsContentForm_GetAppIcon](#oh_udscontentform_getappicon) ([OH_UdsContentForm](#oh_udscontentform) \*pThis, unsigned char \*\*appIcon, unsigned int \*len) | Obtains the application icon data from an [OH_UdsContentForm](#oh_udscontentform) instance.|
| const char \* [OH_UdsContentForm_GetAppName](#oh_udscontentform_getappname) ([OH_UdsContentForm](#oh_udscontentform) \*pThis) | Obtains the application name from an [OH_UdsContentForm](#oh_udscontentform) instance.|
| const char \* [OH_UdsContentForm_GetLinkUri](#oh_udscontentform_getlinkuri) ([OH_UdsContentForm](#oh_udscontentform) \*pThis) | Obtains the hyperlink information from an [OH_UdsContentForm](#oh_udscontentform) instance.|
| int [OH_UdsContentForm_SetThumbData](#oh_udscontentform_setthumbdata) ([OH_UdsContentForm](#oh_udscontentform) \*pThis, const unsigned char \*thumbData, unsigned int len) | Sets the image data for an [OH_UdsContentForm](#oh_udscontentform) instance.|
| int [OH_UdsContentForm_SetDescription](#oh_udscontentform_setdescription) ([OH_UdsContentForm](#oh_udscontentform) \*pThis, const char \*description) | Sets the description for an [OH_UdsContentForm](#oh_udscontentform) instance.|
| int [OH_UdsContentForm_SetTitle](#oh_udscontentform_settitle) ([OH_UdsContentForm](#oh_udscontentform) \*pThis, const char \*title) | Sets the title for an [OH_UdsContentForm](#oh_udscontentform) instance.|
| int [OH_UdsContentForm_SetAppIcon](#oh_udscontentform_setappicon) ([OH_UdsContentForm](#oh_udscontentform) \*pThis, const unsigned char \*appIcon, unsigned int len) | Sets the application icon data for an [OH_UdsContentForm](#oh_udscontentform) instance.|
| int [OH_UdsContentForm_SetAppName](#oh_udscontentform_setappname) ([OH_UdsContentForm](#oh_udscontentform) \*pThis, const char \*appName) | Sets the application name for an [OH_UdsContentForm](#oh_udscontentform) instance.|
| int [OH_UdsContentForm_SetLinkUri](#oh_udscontentform_setlinkuri) ([OH_UdsContentForm](#oh_udscontentform) \*pThis, const char \*linkUri) | Sets the hyperlink data for an [OH_UdsContentForm](#oh_udscontentform) instance.|
| [OH_UdmfData](#oh_udmfdata) \* [OH_UdmfData_Create](#oh_udmfdata_create) () | Creates an [OH_UdmfData](#oh_udmfdata) instance and a pointer to it. If this pointer is no longer required, use [OH_UdmfData_Destroy](#oh_udmfdata_destroy) to destroy it. Otherwise, memory leaks may occur.|
| void [OH_UdmfData_Destroy](#oh_udmfdata_destroy) ([OH_UdmfData](#oh_udmfdata) \*pThis) | Destroys an [OH_UdmfData](#oh_udmfdata) instance.|
| int [OH_UdmfData_AddRecord](#oh_udmfdata_addrecord) ([OH_UdmfData](#oh_udmfdata) \*pThis, [OH_UdmfRecord](#oh_udmfrecord) \*record) | Adds an [OH_UdmfRecord](#oh_udmfrecord) to an [OH_UdmfData](#oh_udmfdata) instance.|
| bool [OH_UdmfData_HasType](#oh_udmfdata_hastype) ([OH_UdmfData](#oh_udmfdata) \*pThis, const char \*type) | Checks whether the specified type exists in an [OH_UdmfData](#oh_udmfdata) instance.|
| char \*\* [OH_UdmfData_GetTypes](#oh_udmfdata_gettypes) ([OH_UdmfData](#oh_udmfdata) \*pThis, unsigned int \*count) | Obtains all data types in an [OH_UdmfData](#oh_udmfdata) instance.|
| [OH_UdmfRecord](#oh_udmfrecord) \*\* [OH_UdmfData_GetRecords](#oh_udmfdata_getrecords) ([OH_UdmfData](#oh_udmfdata) \*pThis, unsigned int \*count) | Obtains all records contained in an [OH_UdmfData](#oh_udmfdata) instance.|
| [OH_UdmfRecordProvider](#oh_udmfrecordprovider) \* [OH_UdmfRecordProvider_Create](#oh_udmfrecordprovider_create) () | Creates an [OH_UdmfRecordProvider](#oh_udmfrecordprovider) instance and a pointer to it. If this pointer is no longer required, use [OH_UdmfRecordProvider_Destroy](#oh_udmfrecordprovider_destroy) to destroy it. Otherwise, memory leaks may occur.|
| int [OH_UdmfRecordProvider_Destroy](#oh_udmfrecordprovider_destroy) ([OH_UdmfRecordProvider](#oh_udmfrecordprovider) \*provider) | Destroys an [OH_UdmfRecordProvider](#oh_udmfrecordprovider) instance.|
| int [OH_UdmfRecordProvider_SetData](#oh_udmfrecordprovider_setdata) ([OH_UdmfRecordProvider](#oh_udmfrecordprovider) \*provider, void \*context, const [OH_UdmfRecordProvider_GetData](#oh_udmfrecordprovider_getdata) callback, const [UdmfData_Finalize](#udmfdata_finalize) finalize) | Sets a callback for an **OH_UdmfRecordProvider** instance to provide data.|
| [OH_UdmfRecord](#oh_udmfrecord) \* [OH_UdmfRecord_Create](#oh_udmfrecord_create) () | Creates an [OH_UdmfRecord](#oh_udmfrecord) instance and a pointer to it. If this pointer is no longer required, use [OH_UdmfRecord_Destroy](#oh_udmfrecord_destroy) to destroy it. Otherwise, memory leaks may occur.|
| void [OH_UdmfRecord_Destroy](#oh_udmfrecord_destroy) ([OH_UdmfRecord](#oh_udmfrecord) \*pThis) | Destroys an [OH_UdmfRecord](#oh_udmfrecord) instance.|
| int [OH_UdmfRecord_AddGeneralEntry](#oh_udmfrecord_addgeneralentry) ([OH_UdmfRecord](#oh_udmfrecord) \*pThis, const char \*typeId, unsigned char \*entry, unsigned int count) | Adds customized uniform data to an [OH_UdmfRecord](#oh_udmfrecord) instance.|
| int [OH_UdmfRecord_AddPlainText](#oh_udmfrecord_addplaintext) ([OH_UdmfRecord](#oh_udmfrecord) \*pThis, [OH_UdsPlainText](#oh_udsplaintext) \*plainText) | Adds data of the [OH_UdsPlainText](#oh_udsplaintext) type to an [OH_UdmfRecord](#oh_udmfrecord) instance.|
| int [OH_UdmfRecord_AddHyperlink](#oh_udmfrecord_addhyperlink) ([OH_UdmfRecord](#oh_udmfrecord) \*pThis, [OH_UdsHyperlink](#oh_udshyperlink) \*hyperlink) | Adds data of the hyperlink type [OH_UdsHyperlink](#oh_udshyperlink) type to an [OH_UdmfRecord](#oh_udmfrecord) instance.|
| int [OH_UdmfRecord_AddHtml](#oh_udmfrecord_addhtml) ([OH_UdmfRecord](#oh_udmfrecord) \*pThis, [OH_UdsHtml](#oh_udshtml) \*html) | Adds data of the [OH_UdsHtml](#oh_udshtml) type to an [OH_UdmfRecord](#oh_udmfrecord) instance.|
| int [OH_UdmfRecord_AddAppItem](#oh_udmfrecord_addappitem) ([OH_UdmfRecord](#oh_udmfrecord) \*pThis, [OH_UdsAppItem](#oh_udsappitem) \*appItem) | Adds data of the [OH_UdsAppItem](#oh_udsappitem) type to an [OH_UdmfRecord](#oh_udmfrecord) instance.|
| int [OH_UdmfRecord_AddFileUri](#oh_udmfrecord_addfileuri) ([OH_UdmfRecord](#oh_udmfrecord) \*pThis, [OH_UdsFileUri](#oh_udsfileuri) \*fileUri) | Adds a data record of the [OH_UdsFileUri](#oh_udsfileuri) type to an [OH_UdmfRecord](#oh_udmfrecord) instance.|
| int [OH_UdmfRecord_AddPixelMap](#oh_udmfrecord_addpixelmap) ([OH_UdmfRecord](#oh_udmfrecord) \*pThis, [OH_UdsPixelMap](#oh_udspixelmap) \*pixelMap) | Adds a data record of the [OH_UdsPixelMap](#oh_udspixelmap) type to an [OH_UdmfRecord](#oh_udmfrecord) instance.|
| int [OH_UdmfRecord_AddArrayBuffer](#oh_udmfrecord_addarraybuffer) ([OH_UdmfRecord](#oh_udmfrecord) \*record, const char \*type, [OH_UdsArrayBuffer](#oh_udsarraybuffer) \*buffer) | Adds a data record of the [OH_UdsArrayBuffer](#oh_udsarraybuffer) type to an [OH_UdmfRecord](#oh_udmfrecord) instance.|
| char \*\* [OH_UdmfRecord_GetTypes](#oh_udmfrecord_gettypes) ([OH_UdmfRecord](#oh_udmfrecord) \*pThis, unsigned int \*count) | Obtains all data types in an [OH_UdmfRecord](#oh_udmfrecord) instance.|
| int [OH_UdmfRecord_GetGeneralEntry](#oh_udmfrecord_getgeneralentry) ([OH_UdmfRecord](#oh_udmfrecord) \*pThis, const char \*typeId, unsigned char \*\*entry, unsigned int \*count) | Obtains the data of the specified type in an [OH_UdmfRecord](#oh_udmfrecord) instance.|
| int [OH_UdmfRecord_GetPlainText](#oh_udmfrecord_getplaintext) ([OH_UdmfRecord](#oh_udmfrecord) \*pThis, [OH_UdsPlainText](#oh_udsplaintext) \*plainText) | Obtains [OH_UdsPlainText](#oh_udsplaintext) data from an [OH_UdmfRecord](#oh_udmfrecord) instance.|
| int [OH_UdmfRecord_GetHyperlink](#oh_udmfrecord_gethyperlink) ([OH_UdmfRecord](#oh_udmfrecord) \*pThis, [OH_UdsHyperlink](#oh_udshyperlink) \*hyperlink) | Obtains [OH_UdsHyperlink](#oh_udshyperlink) data from an [OH_UdmfRecord](#oh_udmfrecord) instance.|
| int [OH_UdmfRecord_GetHtml](#oh_udmfrecord_gethtml) ([OH_UdmfRecord](#oh_udmfrecord) \*pThis, [OH_UdsHtml](#oh_udshtml) \*html) | Obtains [OH_UdsHtml](#oh_udshtml) data from an [OH_UdmfRecord](#oh_udmfrecord) instance.|
| int [OH_UdmfRecord_GetAppItem](#oh_udmfrecord_getappitem) ([OH_UdmfRecord](#oh_udmfrecord) \*pThis, [OH_UdsAppItem](#oh_udsappitem) \*appItem) | Obtains [OH_UdsAppItem](#oh_udsappitem) data from an [OH_UdmfRecord](#oh_udmfrecord) instance.|
| int [OH_UdmfRecord_SetProvider](#oh_udmfrecord_setprovider) ([OH_UdmfRecord](#oh_udmfrecord) \*pThis, const char \*const \*types, unsigned int count, [OH_UdmfRecordProvider](#oh_udmfrecordprovider) \*provider) | Sets the [OH_UdmfRecordProvider](#oh_udmfrecordprovider) in an [OH_UdmfRecord](#oh_udmfrecord) instance.|
| int [OH_UdmfRecord_GetFileUri](#oh_udmfrecord_getfileuri) ([OH_UdmfRecord](#oh_udmfrecord) \*pThis, [OH_UdsFileUri](#oh_udsfileuri) \*fileUri) | Obtains the [OH_UdsFileUri](#oh_udsfileuri) data from an [OH_UdmfRecord](#oh_udmfrecord) instance.|
| int [OH_UdmfRecord_GetPixelMap](#oh_udmfrecord_getpixelmap) ([OH_UdmfRecord](#oh_udmfrecord) \*pThis, [OH_UdsPixelMap](#oh_udspixelmap) \*pixelMap) | Obtains the [OH_UdsPixelMap](#oh_udspixelmap) data from an [OH_UdmfRecord](#oh_udmfrecord) instance.|
| int [OH_UdmfRecord_GetArrayBuffer](#oh_udmfrecord_getarraybuffer) ([OH_UdmfRecord](#oh_udmfrecord) \*record, const char \*type, [OH_UdsArrayBuffer](#oh_udsarraybuffer) \*buffer) | Obtains the [OH_UdsArrayBuffer](#oh_udsarraybuffer) data from an [OH_UdmfRecord](#oh_udmfrecord) instance.|
| int [OH_UdmfData_GetPrimaryPlainText](#oh_udmfdata_getprimaryplaintext) ([OH_UdmfData](#oh_udmfdata) \*data, [OH_UdsPlainText](#oh_udsplaintext) \*plainText) | Obtains the first [OH_UdsPlainText](#oh_udsplaintext) data from an [OH_UdmfData](#oh_udmfdata) instance.|
| int [OH_UdmfData_GetPrimaryHtml](#oh_udmfdata_getprimaryhtml) ([OH_UdmfData](#oh_udmfdata) \*data, [OH_UdsHtml](#oh_udshtml) \*html) | Obtains the first [OH_UdsHtml](#oh_udshtml) data from an [OH_UdmfData](#oh_udmfdata) instance.|
| int [OH_UdmfData_GetRecordCount](#oh_udmfdata_getrecordcount) ([OH_UdmfData](#oh_udmfdata) \*data) | Obtains the number of data records contained in an [OH_UdmfData](#oh_udmfdata) instance.|
| [OH_UdmfRecord](#oh_udmfrecord) \* [OH_UdmfData_GetRecord](#oh_udmfdata_getrecord) ([OH_UdmfData](#oh_udmfdata) \*data, unsigned int index) | Obtains the specified data record from an [OH_UdmfData](#oh_udmfdata) instance.|
| bool [OH_UdmfData_IsLocal](#oh_udmfdata_islocal) ([OH_UdmfData](#oh_udmfdata) \*data) | Checks whether an [OH_UdmfData](#oh_udmfdata) instance is from the local device.|
| [OH_UdmfProperty](#oh_udmfproperty) \* [OH_UdmfProperty_Create](#oh_udmfproperty_create) ([OH_UdmfData](#oh_udmfdata) \*unifiedData) | Creates an [OH_UdmfProperty](#oh_udmfproperty) instance and a pointer to it. If this pointer is no longer required, use [OH_UdmfProperty_Destroy](#oh_udmfproperty_destroy) to destroy it. Otherwise, memory leaks may occur.|
| void [OH_UdmfProperty_Destroy](#oh_udmfproperty_destroy) ([OH_UdmfProperty](#oh_udmfproperty) \*pThis) | Destroys an [OH_UdmfProperty](#oh_udmfproperty) instance.|
| const char \* [OH_UdmfProperty_GetTag](#oh_udmfproperty_gettag) ([OH_UdmfProperty](#oh_udmfproperty) \*pThis) | Obtains the custom tag value from an [OH_UdmfProperty](#oh_udmfproperty) instance.|
| int64_t [OH_UdmfProperty_GetTimestamp](#oh_udmfproperty_gettimestamp) ([OH_UdmfProperty](#oh_udmfproperty) \*pThis) | Obtains the timestamp from an [OH_UdmfProperty](#oh_udmfproperty) instance.|
| [Udmf_ShareOption](#udmf_shareoption) [OH_UdmfProperty_GetShareOption](#oh_udmfproperty_getshareoption) ([OH_UdmfProperty](#oh_udmfproperty) \*pThis) | Obtains the share option from an [OH_UdmfProperty](#oh_udmfproperty) instance.|
| int [OH_UdmfProperty_GetExtrasIntParam](#oh_udmfproperty_getextrasintparam) ([OH_UdmfProperty](#oh_udmfproperty) \*pThis, const char \*key, int defaultValue) | Obtains the customized extra integer parameter from an [OH_UdmfProperty](#oh_udmfproperty) instance.|
| const char \* [OH_UdmfProperty_GetExtrasStringParam](#oh_udmfproperty_getextrasstringparam) ([OH_UdmfProperty](#oh_udmfproperty) \*pThis, const char \*key) | Obtains the customized extra string parameter from an [OH_UdmfProperty](#oh_udmfproperty) instance.|
| int [OH_UdmfProperty_SetTag](#oh_udmfproperty_settag) ([OH_UdmfProperty](#oh_udmfproperty) \*pThis, const char \*tag) | Sets the tag value for an [OH_UdmfProperty](#oh_udmfproperty) instance.|
| int [OH_UdmfProperty_SetShareOption](#oh_udmfproperty_setshareoption) ([OH_UdmfProperty](#oh_udmfproperty) \*pThis, [Udmf_ShareOption](#udmf_shareoption) option) | Sets the share option for an [OH_UdmfProperty](#oh_udmfproperty) instance.|
| int [OH_UdmfProperty_SetExtrasIntParam](#oh_udmfproperty_setextrasintparam) ([OH_UdmfProperty](#oh_udmfproperty) \*pThis, const char \*key, int param) | Sets the extra integer parameter for an [OH_UdmfProperty](#oh_udmfproperty) instance.|
| int [OH_UdmfProperty_SetExtrasStringParam](#oh_udmfproperty_setextrasstringparam) ([OH_UdmfProperty](#oh_udmfproperty) \*pThis, const char \*key, const char \*param) | Sets the extra string parameter for an [OH_UdmfProperty](#oh_udmfproperty) instance.|
| int [OH_Udmf_GetUnifiedData](#oh_udmf_getunifieddata) (const char \*key, [Udmf_Intention](#udmf_intention) intention, [OH_UdmfData](#oh_udmfdata) \*unifiedData) | Obtains an [OH_UdmfData](#oh_udmfdata) instance from the UDMF database.|
| int [OH_Udmf_SetUnifiedData](#oh_udmf_setunifieddata) ([Udmf_Intention](#udmf_intention) intention, [OH_UdmfData](#oh_udmfdata) \*unifiedData, char \*key, unsigned int keyLen) | Sets an [OH_UdmfData](#oh_udmfdata) instance in the UDMF database.|
| [OH_UdsPlainText](#oh_udsplaintext) \* [OH_UdsPlainText_Create](#oh_udsplaintext_create) () | Creates an [OH_UdsPlainText](#oh_udsplaintext) instance and a pointer to it. If this pointer is no longer required, use [OH_UdsPlainText_Destroy](#oh_udsplaintext_destroy) to destroy it. Otherwise, memory leaks may occur.|
| void [OH_UdsPlainText_Destroy](#oh_udsplaintext_destroy) ([OH_UdsPlainText](#oh_udsplaintext) \*pThis) | Destroys an [OH_UdsPlainText](#oh_udsplaintext) instance.|
| const char \* [OH_UdsPlainText_GetType](#oh_udsplaintext_gettype) ([OH_UdsPlainText](#oh_udsplaintext) \*pThis) | Obtains the type ID from an [OH_UdsPlainText](#oh_udsplaintext) instance.|
| const char \* [OH_UdsPlainText_GetContent](#oh_udsplaintext_getcontent) ([OH_UdsPlainText](#oh_udsplaintext) \*pThis) | Obtains the plaintext from an [OH_UdsPlainText](#oh_udsplaintext) instance.|
| const char \* [OH_UdsPlainText_GetAbstract](#oh_udsplaintext_getabstract) ([OH_UdsPlainText](#oh_udsplaintext) \*pThis) | Obtains the abstract from an [OH_UdsPlainText](#oh_udsplaintext) instance.|
| int [OH_UdsPlainText_SetContent](#oh_udsplaintext_setcontent) ([OH_UdsPlainText](#oh_udsplaintext) \*pThis, const char \*content) | Sets the plaintext for an [OH_UdsPlainText](#oh_udsplaintext) instance.|
| int [OH_UdsPlainText_SetAbstract](#oh_udsplaintext_setabstract) ([OH_UdsPlainText](#oh_udsplaintext) \*pThis, const char \*abstract) | Sets the abstract for an [OH_UdsPlainText](#oh_udsplaintext) instance.|
| [OH_UdsHyperlink](#oh_udshyperlink) \* [OH_UdsHyperlink_Create](#oh_udshyperlink_create) () | Creates an [OH_UdsHyperlink](#oh_udshyperlink) instance and a pointer to it. If this pointer is no longer required, use [OH_UdsHyperlink_Destroy](#oh_udshyperlink_destroy) to destroy it. Otherwise, memory leaks may occur.|
| void [OH_UdsHyperlink_Destroy](#oh_udshyperlink_destroy) ([OH_UdsHyperlink](#oh_udshyperlink) \*pThis) | Destroys an [OH_UdsHyperlink](#oh_udshyperlink) instance.|
| const char \* [OH_UdsHyperlink_GetType](#oh_udshyperlink_gettype) ([OH_UdsHyperlink](#oh_udshyperlink) \*pThis) | Obtains the type ID from an [OH_UdsHyperlink](#oh_udshyperlink) instance.|
| const char \* [OH_UdsHyperlink_GetUrl](#oh_udshyperlink_geturl) ([OH_UdsHyperlink](#oh_udshyperlink) \*pThis) | Obtains the URL from an [OH_UdsHyperlink](#oh_udshyperlink) instance.|
| const char \* [OH_UdsHyperlink_GetDescription](#oh_udshyperlink_getdescription) ([OH_UdsHyperlink](#oh_udshyperlink) \*pThis) | Obtains the description from an [OH_UdsHyperlink](#oh_udshyperlink) instance.|
| int [OH_UdsHyperlink_SetUrl](#oh_udshyperlink_seturl) ([OH_UdsHyperlink](#oh_udshyperlink) \*pThis, const char \*url) | Sets the URL for an [OH_UdsHyperlink](#oh_udshyperlink) instance.|
| int [OH_UdsHyperlink_SetDescription](#oh_udshyperlink_setdescription) ([OH_UdsHyperlink](#oh_udshyperlink) \*pThis, const char \*description) | Sets the description for an [OH_UdsHyperlink](#oh_udshyperlink) instance.|
| [OH_UdsHtml](#oh_udshtml) \* [OH_UdsHtml_Create](#oh_udshtml_create) () | Creates an [OH_UdsHtml](#oh_udshtml) instance and a pointer to it. If this pointer is no longer required, use [OH_UdsHtml_Destroy](#oh_udshtml_destroy) to destroy it. Otherwise, memory leaks may occur.|
| void [OH_UdsHtml_Destroy](#oh_udshtml_destroy) ([OH_UdsHtml](#oh_udshtml) \*pThis) | Destroys an [OH_UdsHtml](#oh_udshtml) instance.|
| const char \* [OH_UdsHtml_GetType](#oh_udshtml_gettype) ([OH_UdsHtml](#oh_udshtml) \*pThis) | Obtains the type ID from an [OH_UdsHtml](#oh_udshtml) instance.|
| const char \* [OH_UdsHtml_GetContent](#oh_udshtml_getcontent) ([OH_UdsHtml](#oh_udshtml) \*pThis) | Obtains the HTML content from an [OH_UdsHtml](#oh_udshtml) instance.|
| const char \* [OH_UdsHtml_GetPlainContent](#oh_udshtml_getplaincontent) ([OH_UdsHtml](#oh_udshtml) \*pThis) | Obtains the plaintext from an [OH_UdsHtml](#oh_udshtml) instance.|
| int [OH_UdsHtml_SetContent](#oh_udshtml_setcontent) ([OH_UdsHtml](#oh_udshtml) \*pThis, const char \*content) | Sets the HTML content for an [OH_UdsHtml](#oh_udshtml) instance.|
| int [OH_UdsHtml_SetPlainContent](#oh_udshtml_setplaincontent) ([OH_UdsHtml](#oh_udshtml) \*pThis, const char \*plainContent) | Sets the plaintext for an [OH_UdsHtml](#oh_udshtml) instance.|
| [OH_UdsAppItem](#oh_udsappitem) \* [OH_UdsAppItem_Create](#oh_udsappitem_create) () | Creates an [OH_UdsAppItem](#oh_udsappitem) instance and a pointer to it. If this pointer is no longer required, use [OH_UdsAppItem_Destroy](#oh_udsappitem_destroy) to destroy it. Otherwise, memory leaks may occur.|
| void [OH_UdsAppItem_Destroy](#oh_udsappitem_destroy) ([OH_UdsAppItem](#oh_udsappitem) \*pThis) | Destroys an [OH_UdsAppItem](#oh_udsappitem) instance.|
| const char \* [OH_UdsAppItem_GetType](#oh_udsappitem_gettype) ([OH_UdsAppItem](#oh_udsappitem) \*pThis) | Obtains the type ID from an [OH_UdsAppItem](#oh_udsappitem) instance.|
| const char \* [OH_UdsAppItem_GetId](#oh_udsappitem_getid) ([OH_UdsAppItem](#oh_udsappitem) \*pThis) | Obtains the application ID from an [OH_UdsAppItem](#oh_udsappitem) instance.|
| const char \* [OH_UdsAppItem_GetName](#oh_udsappitem_getname) ([OH_UdsAppItem](#oh_udsappitem) \*pThis) | Obtains the application name from an [OH_UdsAppItem](#oh_udsappitem) instance.|
| const char \* [OH_UdsAppItem_GetIconId](#oh_udsappitem_geticonid) ([OH_UdsAppItem](#oh_udsappitem) \*pThis) | Obtains the application icon ID from an [OH_UdsAppItem](#oh_udsappitem) instance.|
| const char \* [OH_UdsAppItem_GetLabelId](#oh_udsappitem_getlabelid) ([OH_UdsAppItem](#oh_udsappitem) \*pThis) | Obtains the application label ID from an [OH_UdsAppItem](#oh_udsappitem) instance.|
| const char \* [OH_UdsAppItem_GetBundleName](#oh_udsappitem_getbundlename) ([OH_UdsAppItem](#oh_udsappitem) \*pThis) | Obtains the bundle name from an [OH_UdsAppItem](#oh_udsappitem) instance.|
| const char \* [OH_UdsAppItem_GetAbilityName](#oh_udsappitem_getabilityname) ([OH_UdsAppItem](#oh_udsappitem) \*pThis) | Obtains the ability name from an [OH_UdsAppItem](#oh_udsappitem) instance.|
| int [OH_UdsAppItem_SetId](#oh_udsappitem_setid) ([OH_UdsAppItem](#oh_udsappitem) \*pThis, const char \*appId) | Sets the application ID for an [OH_UdsAppItem](#oh_udsappitem) instance.|
| int [OH_UdsAppItem_SetName](#oh_udsappitem_setname) ([OH_UdsAppItem](#oh_udsappitem) \*pThis, const char \*appName) | Sets the application name for an [OH_UdsAppItem](#oh_udsappitem) instance.|
| int [OH_UdsAppItem_SetIconId](#oh_udsappitem_seticonid) ([OH_UdsAppItem](#oh_udsappitem) \*pThis, const char \*appIconId) | Sets the application icon ID for an [OH_UdsAppItem](#oh_udsappitem) instance.|
| int [OH_UdsAppItem_SetLabelId](#oh_udsappitem_setlabelid) ([OH_UdsAppItem](#oh_udsappitem) \*pThis, const char \*appLabelId) | Sets the application label ID for an [OH_UdsAppItem](#oh_udsappitem) instance.|
| int [OH_UdsAppItem_SetBundleName](#oh_udsappitem_setbundlename) ([OH_UdsAppItem](#oh_udsappitem) \*pThis, const char \*bundleName) | Sets the bundle name for an [OH_UdsAppItem](#oh_udsappitem) instance.|
| int [OH_UdsAppItem_SetAbilityName](#oh_udsappitem_setabilityname) ([OH_UdsAppItem](#oh_udsappitem) \*pThis, const char \*abilityName) | Sets the ability name for an [OH_UdsAppItem](#oh_udsappitem) instance.|
| [OH_UdsFileUri](#oh_udsfileuri) \* [OH_UdsFileUri_Create](#oh_udsfileuri_create) () | Creates an [OH_UdsFileUri](#oh_udsfileuri) instance and a pointer to it. If this pointer is no longer required, use [OH_UdsFileUri_Destroy](#oh_udsfileuri_destroy) to destroy it. Otherwise, memory leaks may occur.|
| void [OH_UdsFileUri_Destroy](#oh_udsfileuri_destroy) ([OH_UdsFileUri](#oh_udsfileuri) \*pThis) | Destroys an [OH_UdsFileUri](#oh_udsfileuri) instance.|
| const char \* [OH_UdsFileUri_GetType](#oh_udsfileuri_gettype) ([OH_UdsFileUri](#oh_udsfileuri) \*pThis) | Obtains the type ID from an [OH_UdsFileUri](#oh_udsfileuri) instance.|
| const char \* [OH_UdsFileUri_GetFileUri](#oh_udsfileuri_getfileuri) ([OH_UdsFileUri](#oh_udsfileuri) \*pThis) | Obtains the file URI from an [OH_UdsFileUri](#oh_udsfileuri) instance.|
| const char \* [OH_UdsFileUri_GetFileType](#oh_udsfileuri_getfiletype) ([OH_UdsFileUri](#oh_udsfileuri) \*pThis) | Obtains the file type from an [OH_UdsFileUri](#oh_udsfileuri) instance.|
| int [OH_UdsFileUri_SetFileUri](#oh_udsfileuri_setfileuri) ([OH_UdsFileUri](#oh_udsfileuri) \*pThis, const char \*fileUri) | Sets the URI information for an [OH_UdsFileUri](#oh_udsfileuri) instance.|
| int [OH_UdsFileUri_SetFileType](#oh_udsfileuri_setfiletype) ([OH_UdsFileUri](#oh_udsfileuri) \*pThis, const char \*fileType) | Sets the file type for an [OH_UdsFileUri](#oh_udsfileuri) instance.|
| [OH_UdsPixelMap](#oh_udspixelmap) \* [OH_UdsPixelMap_Create](#oh_udspixelmap_create) () | Creates an [OH_UdsPixelMap](#oh_udspixelmap) instance and a pointer to it. If this pointer is no longer required, use [OH_UdsPixelMap_Destroy](#oh_udspixelmap_destroy) to destroy it. Otherwise, memory leaks may occur.|
| void [OH_UdsPixelMap_Destroy](#oh_udspixelmap_destroy) ([OH_UdsPixelMap](#oh_udspixelmap) \*pThis) | Destroys an [OH_UdsPixelMap](#oh_udspixelmap) instance.|
| const char \* [OH_UdsPixelMap_GetType](#oh_udspixelmap_gettype) ([OH_UdsPixelMap](#oh_udspixelmap) \*pThis) | Obtains the type ID from an [OH_UdsPixelMap](#oh_udspixelmap) instance.|
| void [OH_UdsPixelMap_GetPixelMap](#oh_udspixelmap_getpixelmap) ([OH_UdsPixelMap](#oh_udspixelmap) \*pThis, OH_PixelmapNative \*pixelmapNative) | Obtains the pointer to the **OH_PixelmapNative** instance from an [OH_UdsPixelMap](#oh_udspixelmap) instance.|
| int [OH_UdsPixelMap_SetPixelMap](#oh_udspixelmap_setpixelmap) ([OH_UdsPixelMap](#oh_udspixelmap) \*pThis, OH_PixelmapNative \*pixelmapNative) | Sets the pixel map content for an [OH_UdsPixelMap](#oh_udspixelmap) instance.|
| [OH_UdsArrayBuffer](#oh_udsarraybuffer) \* [OH_UdsArrayBuffer_Create](#oh_udsarraybuffer_create) () | Creates an [OH_UdsArrayBuffer](#oh_udsarraybuffer) instance and a pointer to it. If this pointer is no longer required, use [OH_UdsArrayBuffer_Destroy](#oh_udsarraybuffer_destroy) to destroy it. Otherwise, memory leaks may occur.|
| int [OH_UdsArrayBuffer_Destroy](#oh_udsarraybuffer_destroy) ([OH_UdsArrayBuffer](#oh_udsarraybuffer) \*buffer) | Destroys an [OH_UdsArrayBuffer](#oh_udsarraybuffer) instance.|
| int [OH_UdsArrayBuffer_SetData](#oh_udsarraybuffer_setdata) ([OH_UdsArrayBuffer](#oh_udsarraybuffer) \*buffer, unsigned char \*data, unsigned int len) | Sets an [OH_UdsArrayBuffer](#oh_udsarraybuffer) instance.|
| int [OH_UdsArrayBuffer_GetData](#oh_udsarraybuffer_getdata) ([OH_UdsArrayBuffer](#oh_udsarraybuffer) \*buffer, unsigned char \*\*data, unsigned int \*len) | Obtains the custom ArrayBuffer data from an [OH_UdsArrayBuffer](#oh_udsarraybuffer) instance.|
| [OH_Utd](#oh_utd) \* [OH_Utd_Create](#oh_utd_create) (const char \*typeId) | Creates an [OH_Utd](#oh_utd) instance and a pointer to it.|
| void [OH_Utd_Destroy](#oh_utd_destroy) ([OH_Utd](#oh_utd) \*pThis) | Destroys an [OH_Utd](#oh_utd) instance.|
| const char \* [OH_Utd_GetTypeId](#oh_utd_gettypeid) ([OH_Utd](#oh_utd) \*pThis) | Obtains the type ID from an [OH_Utd](#oh_utd) instance.|
| const char \* [OH_Utd_GetDescription](#oh_utd_getdescription) ([OH_Utd](#oh_utd) \*pThis) | Obtains the description from an [OH_Utd](#oh_utd) instance.|
| const char \* [OH_Utd_GetReferenceUrl](#oh_utd_getreferenceurl) ([OH_Utd](#oh_utd) \*pThis) | Obtains the URL from an [OH_Utd](#oh_utd) instance.|
| const char \* [OH_Utd_GetIconFile](#oh_utd_geticonfile) ([OH_Utd](#oh_utd) \*pThis) | Obtains the path of the default icon file from an [OH_Utd](#oh_utd) instance.|
| const char \*\* [OH_Utd_GetBelongingToTypes](#oh_utd_getbelongingtotypes) ([OH_Utd](#oh_utd) \*pThis, unsigned int \*count) | Obtains the relationships between the data in an [OH_Utd](#oh_utd) instance.|
| const char \*\* [OH_Utd_GetFilenameExtensions](#oh_utd_getfilenameextensions) ([OH_Utd](#oh_utd) \*pThis, unsigned int \*count) | Obtains the file name extensions associated with an [OH_Utd](#oh_utd) instance.|
| const char \*\* [OH_Utd_GetMimeTypes](#oh_utd_getmimetypes) ([OH_Utd](#oh_utd) \*pThis, unsigned int \*count) | Obtains the MIME types associated with an [OH_Utd](#oh_utd) instance.|
| const char \*\* [OH_Utd_GetTypesByFilenameExtension](#oh_utd_gettypesbyfilenameextension) (const char \*extension, unsigned int \*count) | Obtains the uniform data types based on the file name extensions.|
| const char \*\* [OH_Utd_GetTypesByMimeType](#oh_utd_gettypesbymimetype) (const char \*mimeType, unsigned int \*count) | Obtains the uniform data types based on the MIME types.|
| bool [OH_Utd_BelongsTo](#oh_utd_belongsto) (const char \*srcTypeId, const char \*destTypeId) | Checks whether a UTD belongs to the target UTD.|
| bool [OH_Utd_IsLower](#oh_utd_islower) (const char \*srcTypeId, const char \*destTypeId) | Checks whether a UTD is a lower-level type of the target UTD. For example, **TYPE_SCRIPT** is a lower-level type of **SOURCE_CODE**, and **TYPE_SCRIPT** and **SOURCE_CODE** are lower-level types of **PLAIN_TEXT**.|
| bool [OH_Utd_IsHigher](#oh_utd_ishigher) (const char \*srcTypeId, const char \*destTypeId) | Checks whether a UTD is a higher-level type of the target UTD. For example, **SOURCE_CODE** is a higher-level type of **TYPE_SCRIPT**, and **PLAIN_TEXT** is a higher-level type of **SOURCE_CODE** and **TYPE_SCRIPT**.|
| bool [OH_Utd_Equals](#oh_utd_equals) ([OH_Utd](#oh_utd) \*utd1, [OH_Utd](#oh_utd) \*utd2) | Checks whether two UTDs are the same.|
| void [OH_Utd_DestroyStringList](#oh_utd_destroystringlist) (const char \*\*list, unsigned int count) | Destroys a UTD string list.|


## Macro Description

### UDMF_METE_GENERAL_CONTENT_FORM

```
#define UDMF_METE_GENERAL_CONTENT_FORM   "general.content-form"
```

**Description**

Defines the content widget type.<br>This type belongs to **OBJECT**.

**Since**: 14

### UDMF_KEY_BUFFER_LEN

```
#define UDMF_KEY_BUFFER_LEN   (512)
```

**Description**

Specifies the minimum length of the buffer that holds the key (unique identifier) of a uniform data object.

**Since**: 12


### UDMF_META_AAC

```
#define UDMF_META_AAC   "general.aac"
```

**Description**

Indicates AAC, which belongs to **AUDIO**.

**Since**: 12


### UDMF_META_AI_IMAGE

```
#define UDMF_META_AI_IMAGE   "com.adobe.illustrator.ai-image"
```

**Description**

Indicates adobe Illustrator image (.ai), which belongs to **IMAGE**.

**Since**: 12


### UDMF_META_AIFC_AUDIO

```
#define UDMF_META_AIFC_AUDIO   "general.aifc-audio"
```

**Description**

Indicates AIFC, which belongs to **AUDIO**.

**Since**: 12


### UDMF_META_AIFF

```
#define UDMF_META_AIFF   "general.aiff"
```

**Description**

Indicates AIFF, which belongs to **AUDIO**.

**Since**: 12


### UDMF_META_ALAC

```
#define UDMF_META_ALAC   "general.alac"
```

**Description**

Indicates ALAC, which belongs to **AUDIO**.

**Since**: 12


### UDMF_META_ARCHIVE

```
#define UDMF_META_ARCHIVE   "general.archive"
```

**Description**

Indicates the generic archive file type, which belongs to **OBJECT**.

**Since**: 12


### UDMF_META_AU_AUDIO

```
#define UDMF_META_AU_AUDIO   "general.au-audio"
```

**Description**

Indicates the AU format, which belongs to **AUDIO**.

**Since**: 12


### UDMF_META_AUDIO

```
#define UDMF_META_AUDIO   "general.audio"
```

**Description**

Indicates the generic audio type, which belongs to **MEDIA**.

**Since**: 12


### UDMF_META_AVI

```
#define UDMF_META_AVI   "general.avi"
```

**Description**

Indicates AVI, which belongs to **VIDEO**.

**Since**: 12


### UDMF_META_AZW

```
#define UDMF_META_AZW   "com.amazon.azw"
```

**Description**

Indicates AZW, which belongs to **EBOOK**.

**Since**: 12


### UDMF_META_AZW3

```
#define UDMF_META_AZW3   "com.amazon.azw3"
```

**Description**

Indicates AZW3, which belongs to **EBOOK**.

**Since**: 12


### UDMF_META_BMP

```
#define UDMF_META_BMP   "com.microsoft.bmp"
```

**Description**

Indicates BMP, which belongs to **IMAGE**.

**Since**: 12


### UDMF_META_BZ2_ARCHIVE

```
#define UDMF_META_BZ2_ARCHIVE   "general.bz2-archive"
```

**Description**

Indicates BZ2, which belongs to **ARCHIVE**.

**Since**: 12


### UDMF_META_C_HEADER

```
#define UDMF_META_C_HEADER   "general.c-header"
```

**Description**

Indicates a header file in C, which belongs to **SOURCE_CODE**.

**Since**: 12


### UDMF_META_C_PLUS_PLUS_HEADER

```
#define UDMF_META_C_PLUS_PLUS_HEADER   "general.c-plus-plus-header"
```

**Description**

Indicates a header file in C++, which belongs to **SOURCE_CODE**.

**Since**: 12


### UDMF_META_C_PLUS_PLUS_SOURCE

```
#define UDMF_META_C_PLUS_PLUS_SOURCE   "general.c-plus-plus-source"
```

**Description**

Indicates the source code in C++, which belongs to **SOURCE_CODE**.

**Since**: 12


### UDMF_META_C_SOURCE

```
#define UDMF_META_C_SOURCE   "general.c-source"
```

**Description**

Indicates the source code in C, which belongs to **SOURCE_CODE**.

**Since**: 12


### UDMF_META_CALENDAR

```
#define UDMF_META_CALENDAR   "general.calendar"
```

**Description**

Indicates the generic calendar type, which belongs to **OBJECT**.

**Since**: 12


### UDMF_META_COMPOSITE_OBJECT

```
#define UDMF_META_COMPOSITE_OBJECT   "general.composite-object"
```

**Description**

Indicates the generic composite content type. For example, a PDF file that contains text and image. This type belongs to **OBJECT**.

**Since**: 12


### UDMF_META_CONTACT

```
#define UDMF_META_CONTACT   "general.contact"
```

**Description**

Indicates the generic contact type. This type belongs to **OBJECT**.

**Since**: 12


### UDMF_META_CSH_SCRIPT

```
#define UDMF_META_CSH_SCRIPT   "general.csh-script"
```

**Description**

Indicates a C shell script, which belongs to **SHELL_SCRIPT**.

**Since**: 12


### UDMF_META_DATABASE

```
#define UDMF_META_DATABASE   "general.database"
```

**Description**

Indicates the generic database file type, which belongs to **OBJECT**.

**Since**: 12


### UDMF_META_DIRECTORY

```
#define UDMF_META_DIRECTORY   "general.directory"
```

**Description**

Indicates the generic directory type, which belongs to **ENTITY**.

**Since**: 12


### UDMF_META_DISK_IMAGE

```
#define UDMF_META_DISK_IMAGE   "general.disk-image"
```

**Description**

Indicates the generic type of any file that can be mounted as a volume. This type belongs to **ARCHIVE**.

**Since**: 12


### UDMF_META_EBOOK

```
#define UDMF_META_EBOOK   "general.ebook"
```

**Description**

Indicates the generic eBook file format, which belongs to **COMPOSITE_OBJECT**.

**Since**: 12


### UDMF_META_EFX_FAX

```
#define UDMF_META_EFX_FAX   "com.js.efx-fax"
```

**Description**

Indicates the EFX file format, which belongs to **FAX**.

**Since**: 12


### UDMF_META_ENCAPSULATED_POSTSCRIPT

```
#define UDMF_META_ENCAPSULATED_POSTSCRIPT   "com.adobe.encapsulated-postscript"
```

**Description**

Indicates encapsulated PostScript, which belongs to **POSTSCRIPT**.

**Since**: 12


### UDMF_META_ENTITY

```
#define UDMF_META_ENTITY   "general.entity"
```

**Description**

Indicates the generic type that represents all physical storage types. It is used to define physical properties of a type. This type is uncategorized.

**Since**: 12


### UDMF_META_EPUB

```
#define UDMF_META_EPUB   "general.epub"
```

**Description**

Indicates EPUB, which belongs to **EBOOK**.

**Since**: 12


### UDMF_META_EXCEL

```
#define UDMF_META_EXCEL   "com.microsoft.excel.xls"
```

**Description**

Indicates Microsoft Excel, which belongs to **COMPOSITE_OBJECT**.

**Since**: 12


### UDMF_META_EXECUTABLE

```
#define UDMF_META_EXECUTABLE   "general.executable"
```

**Description**

Indicates the generic type of all executable files, which belongs to **OBJECT**.

**Since**: 12


### UDMF_META_FAX

```
#define UDMF_META_FAX   "general.fax"
```

**Description**

Indicates the generic fax type, which belongs to **IMAGE**.

**Since**: 12


### UDMF_META_FLAC

```
#define UDMF_META_FLAC   "general.flac"
```

**Description**

Indicates FLAC, which belongs to **AUDIO**.

**Since**: 12


### UDMF_META_FLASHPIX_IMAGE

```
#define UDMF_META_FLASHPIX_IMAGE   "com.kodak.flashpix.image"
```

**Description**

Indicates the FlashPix image format, which belongs to **IMAGE**.

**Since**: 12


### UDMF_META_FOLDER

```
#define UDMF_META_FOLDER   "general.folder"
```

**Description**

Indicates the generic folder type, which belongs to **DIRECTORY**.

**Since**: 12


### UDMF_META_FONT

```
#define UDMF_META_FONT   "general.font"
```

**Description**

Indicates the generic font type, which belongs to **OBJECT**.

**Since**: 12


### UDMF_META_GENERAL_FILE

```
#define UDMF_META_GENERAL_FILE   "general.file"
```

**Description**

Indicates the generic file type, which belongs to **ENTITY**.

**Since**: 12


### UDMF_META_GENERAL_FILE_URI

```
#define UDMF_META_GENERAL_FILE_URI   "general.file-uri"
```

**Description**

Indicates the file address type, which belongs to **TEXT**.

**Since**: 13


### UDMF_META_GNU_TAR_ARCHIVE

```
#define UDMF_META_GNU_TAR_ARCHIVE   "org.gnu.gnu-tar-archive"
```

**Description**

Indicates GUN archive, which belongs to **ARCHIVE**.

**Since**: 12


### UDMF_META_GNU_ZIP_ARCHIVE

```
#define UDMF_META_GNU_ZIP_ARCHIVE   "org.gnu.gnu-zip-archive"
```

**Description**

Indicates GZIP archive, which belongs to **ARCHIVE**.

**Since**: 12


### UDMF_META_GNU_ZIP_TAR_ARCHIVE

```
#define UDMF_META_GNU_ZIP_TAR_ARCHIVE   "org.gnu.gnu-zip-tar-archive"
```

**Description**

Indicates GZIP TAR, which belongs to **ARCHIVE**.

**Since**: 12


### UDMF_META_HTML

```
#define UDMF_META_HTML   "general.html"
```

**Description**

Indicates HTML, which belongs to **TEXT**.

**Since**: 12


### UDMF_META_HYPERLINK

```
#define UDMF_META_HYPERLINK   "general.hyperlink"
```

**Description**

Indicates Hyperlink, which belongs to **TEXT**.

**Since**: 12


### UDMF_META_ICO

```
#define UDMF_META_ICO   "com.microsoft.ico"
```

**Description**

Indicates Windows icon type, which belongs to **IMAGE**.

**Since**: 12


### UDMF_META_ICS

```
#define UDMF_META_ICS   "general.ics"
```

**Description**

Indicates the ICS format, which belongs to **CALENDAR** and **TEXT**.

**Since**: 12


### UDMF_META_IMAGE

```
#define UDMF_META_IMAGE   "general.image"
```

**Description**

Indicates the generic image type, which belongs to **MEDIA**.

**Since**: 12


### UDMF_META_JAVA_ARCHIVE

```
#define UDMF_META_JAVA_ARCHIVE   "com.sun.java-archive"
```

**Description**

Indicates JAR (Java archive), which belongs to **ARCHIVE** and **EXECUTABLE**.

**Since**: 12


### UDMF_META_JAVA_SCRIPT

```
#define UDMF_META_JAVA_SCRIPT   "general.java-script"
```

**Description**

Indicates JavaScript source code, which belongs to **SCRIPT**.

**Since**: 12


### UDMF_META_JAVA_SOURCE

```
#define UDMF_META_JAVA_SOURCE   "general.java-source"
```

**Description**

Indicates Java source code, which belongs to **SOURCE_CODE**.

**Since**: 12


### UDMF_META_JFX_FAX

```
#define UDMF_META_JFX_FAX   "com.j2.jfx-fax"
```

**Description**

Indicates the J2 jConnect fax file format, which belongs to **FAX**.

**Since**: 12


### UDMF_META_JPEG

```
#define UDMF_META_JPEG   "general.jpeg"
```

**Description**

Indicates JPEG, which belongs to **IMAGE**.

**Since**: 12


### UDMF_META_KFX

```
#define UDMF_META_KFX   "com.amazon.kfx"
```

**Description**

Indicates KFX, which belongs to **EBOOK**.

**Since**: 12


### UDMF_META_LOCATION

```
#define UDMF_META_LOCATION   "general.location"
```

**Description**

Indicates location data type, which belongs to **NAVIGATION**.

**Since**: 12


### UDMF_META_MARKDOWN

```
#define UDMF_META_MARKDOWN   "general.markdown"
```

**Description**

Indicates Markdown, which belongs to **PLAIN_TEXT**.

**Since**: 12


### UDMF_META_MEDIA

```
#define UDMF_META_MEDIA   "general.media"
```

**Description**

Indicates the generic media type, which belongs to **OBJECT**.

**Since**: 12


### UDMF_META_MESSAGE

```
#define UDMF_META_MESSAGE   "general.message"
```

**Description**

Indicates the generic message type, which belongs to **OBJECT**.

**Since**: 12


### UDMF_META_MOBI

```
#define UDMF_META_MOBI   "com.amazon.mobi"
```

**Description**

Indicates MOBI, which belongs to **EBOOK**.

**Since**: 12


### UDMF_META_MP3

```
#define UDMF_META_MP3   "general.mp3"
```

**Description**

Indicates MP3, which belongs to **AUDIO**.

**Since**: 12


### UDMF_META_MPEG

```
#define UDMF_META_MPEG   "general.mpeg"
```

**Description**

Indicates MPGE-1 or MPGE-2, which belongs to **VIDEO**.

**Since**: 12


### UDMF_META_MPEG4

```
#define UDMF_META_MPEG4   "general.mpeg-4"
```

**Description**

Indicates MPGE-4, which belongs to **VIDEO**.

**Since**: 12


### UDMF_META_NAVIGATION

```
#define UDMF_META_NAVIGATION   "general.navigation"
```

**Description**

Generic navigation data type.<br>This type belongs to **OBJECT**.

**Since**: 12


### UDMF_META_OBJECT

```
#define UDMF_META_OBJECT   "general.object"
```

**Description**

Indicates the generic type that represents all logical content types. It is used to describe the functional features of a type. This type is uncategorized.

**Since**: 12


### UDMF_META_OGG

```
#define UDMF_META_OGG   "general.ogg"
```

**Description**

OGG.<br>This type belongs to **AUDIO**.

**Since**: 12


### UDMF_META_OPENDOCUMENT

```
#define UDMF_META_OPENDOCUMENT   "org.oasis.opendocument"
```

**Description**

OpenDocument format for Office applications.<br>This type belongs to **ARCHIVE**.

**Since**: 12


### UDMF_META_OPENDOCUMENT_FORMULA

```
#define UDMF_META_OPENDOCUMENT_FORMULA   "org.oasis.opendocument.formula"
```

**Description**

OpenDocument format for formula.<br>This type belongs to **OPENDOCUMENT**.

**Since**: 12


### UDMF_META_OPENDOCUMENT_GRAPHICS

```
#define UDMF_META_OPENDOCUMENT_GRAPHICS   "org.oasis.opendocument.graphics"
```

**Description**

OpenDocument format for graphics.<br>This type belongs to **OPENDOCUMENT** and **COMPOSITE_OBJECT**.

**Since**: 12


### UDMF_META_OPENDOCUMENT_PRESENTATION

```
#define UDMF_META_OPENDOCUMENT_PRESENTATION   "org.oasis.opendocument.presentation"
```

**Description**

OpenDocument format for presentations.<br>This type belongs to **OPENDOCUMENT** and **COMPOSITE_OBJECT**.

**Since**: 12


### UDMF_META_OPENDOCUMENT_SPREADSHEET

```
#define UDMF_META_OPENDOCUMENT_SPREADSHEET   "org.oasis.opendocument.spreadsheet"
```

**Description**

OpenDocument format for spreadsheets.<br>This type belongs to **OPENDOCUMENT** and **COMPOSITE_OBJECT**.

**Since**: 12


### UDMF_META_OPENDOCUMENT_TEXT

```
#define UDMF_META_OPENDOCUMENT_TEXT   "org.oasis.opendocument.text"
```

**Description**

OpenDocument format for word processing (text) documents.<br>This type belongs to **OPENDOCUMENT** and **COMPOSITE_OBJECT**.

**Since**: 12


### UDMF_META_OPENEXR_IMAGE

```
#define UDMF_META_OPENEXR_IMAGE   "com.ilm.openexr-image"
```

**Description**

OpenXR image format.<br>This type belongs to **IMAGE**.

**Since**: 12


### UDMF_META_OPENHARMONY_APP_ITEM

```
#define UDMF_META_OPENHARMONY_APP_ITEM   "openharmony.app-item"
```

**Description**

Home screen icon defined for the system.<br>This type belongs to **OBJECT**.

**Since**: 12


### UDMF_META_OPENHARMONY_ATOMIC_SERVICE

```
#define UDMF_META_OPENHARMONY_ATOMIC_SERVICE   "openharmony.atomic-service"
```

**Description**

Atomic service type defined for the system.<br>This type belongs to **OBJECT**.

**Since**: 12


### UDMF_META_OPENHARMONY_FORM

```
#define UDMF_META_OPENHARMONY_FORM   "openharmony.form"
```

**Description**

Widget defined for the system.<br>This type belongs to **OBJECT**.

**Since**: 12


### UDMF_META_OPENHARMONY_HAP

```
#define UDMF_META_OPENHARMONY_HAP   "openharmony.hap"
```

**Description**

Ability package defined for the system.<br>This type belongs to **OPENHARMONY_PACKAGE**.

**Since**: 12


### UDMF_META_OPENHARMONY_HDOC

```
#define UDMF_META_OPENHARMONY_HDOC   "openharmony.hdoc"
```

**Description**

Memo format defined for the system.<br>This type belongs to **COMPOSITE_OBJECT**.

**Since**: 12


### UDMF_META_OPENHARMONY_HINOTE

```
#define UDMF_META_OPENHARMONY_HINOTE   "openharmony.hinote"
```

**Description**

Note format defined for the system.<br>This type belongs to **COMPOSITE_OBJECT**.

**Since**: 12


### UDMF_META_OPENHARMONY_PACKAGE

```
#define UDMF_META_OPENHARMONY_PACKAGE   "openharmony.package"
```

**Description**

Package (compressed folder) defined for the system.<br>This type belongs to **DIRECTORY**.

**Since**: 12


### UDMF_META_OPENHARMONY_PIXEL_MAP

```
#define UDMF_META_OPENHARMONY_PIXEL_MAP   "openharmony.pixel-map"
```

**Description**

Pixel map defined for the system.<br>This type belongs to **IMAGE**.

**Since**: 12


### UDMF_META_OPENHARMONY_STYLED_STRING

```
#define UDMF_META_OPENHARMONY_STYLED_STRING   "openharmony.styled-string"
```

**Description**

Style string type defined for the system.<br>This type belongs to **COMPOSITE_OBJECT**.

**Since**: 12


### UDMF_META_OPENHARMONY_WANT

```
#define UDMF_META_OPENHARMONY_WANT   "openharmony.want"
```

**Description**

Want defined for the system.<br>This type belongs to **OBJECT**.

**Since**: 12


### UDMF_META_OPENTYPE_FONT

```
#define UDMF_META_OPENTYPE_FONT   "general.opentype-font"
```

**Description**

Indicates the OpenType font format, which belongs to **FONT**.

**Since**: 12


### UDMF_META_OPENXML

```
#define UDMF_META_OPENXML   "org.openxmlformats.openxml"
```

**Description**

Indicates OpenXML, which belongs to **ARCHIVE**.

**Since**: 12


### UDMF_META_PCM

```
#define UDMF_META_PCM   "general.pcm"
```

**Description**

Indicates PCM, which belongs to **AUDIO**.

**Since**: 12


### UDMF_META_PDF

```
#define UDMF_META_PDF   "com.adobe.pdf"
```

**Description**

Indicates PDF, which belongs to **COMPOSITE_OBJECT**.

**Since**: 12


### UDMF_META_PERL_SCRIPT

```
#define UDMF_META_PERL_SCRIPT   "general.perl-script"
```

**Description**

Indicates a Perl script, which belongs to **SHELL_SCRIPT**.

**Since**: 12


### UDMF_META_PHOTOSHOP_IMAGE

```
#define UDMF_META_PHOTOSHOP_IMAGE   "com.adobe.photoshop-image"
```

**Description**

Indicates an Adobe Photoshop image, which belongs to **IMAGE**.

**Since**: 12


### UDMF_META_PHP_SCRIPT

```
#define UDMF_META_PHP_SCRIPT   "general.php-script"
```

**Description**

Indicates a PHP script, which belongs to **SHELL_SCRIPT**.

**Since**: 12


### UDMF_META_PLAIN_TEXT

```
#define UDMF_META_PLAIN_TEXT   "general.plain-text"
```

**Description**

Indicates text without specific encoding or identifier, which belongs to **TEXT**.

**Since**: 12


### UDMF_META_PNG

```
#define UDMF_META_PNG   "general.png"
```

**Description**

Indicates PNG, which belongs to **IMAGE**.

**Since**: 12


### UDMF_META_PORTABLE_EXECUTABLE

```
#define UDMF_META_PORTABLE_EXECUTABLE   "com.microsoft.portable-executable"
```

**Description**

Indicates the Microsoft Windows portable executable format, which belongs to **EXECUTABLE**.

**Since**: 12


### UDMF_META_POSTSCRIPT

```
#define UDMF_META_POSTSCRIPT   "com.adobe.postscript"
```

**Description**

Indicates PostScript, which belongs to **COMPOSITE_OBJECT**.

**Since**: 12


### UDMF_META_POSTSCRIPT_FONT

```
#define UDMF_META_POSTSCRIPT_FONT   "com.adobe.postscript-font"
```

**Description**

Indicates the PostScript font format, which belongs to **FONT**.

**Since**: 12


### UDMF_META_POSTSCRIPT_PFA_FONT

```
#define UDMF_META_POSTSCRIPT_PFA_FONT   "com.adobe.postscript-pfa-font"
```

**Description**

Indicates Adobe Type 1 font format, which belongs to **FONT**.

**Since**: 12


### UDMF_META_POSTSCRIPT_PFB_FONT

```
#define UDMF_META_POSTSCRIPT_PFB_FONT   "com.adobe.postscript-pfb-font"
```

**Description**

Indicates PostScript Font Binary font format, which belongs to **FONT**.

**Since**: 12


### UDMF_META_PPT

```
#define UDMF_META_PPT   "com.microsoft.powerpoint.ppt"
```

**Description**

Indicates Microsoft PowerPoint presentation format, which belongs to **COMPOSITE_OBJECT**.

**Since**: 12


### UDMF_META_PRESENTATIONML_PRESENTATION

```
#define UDMF_META_PRESENTATIONML_PRESENTATION   "org.openxmlformats.presentationml.presentation"
```

**Description**

Indicates PresentationML format, which belongs to **OPENXML** and **COMPOSITE_OBJECT**.

**Since**: 12


### UDMF_META_PYTHON_SCRIPT

```
#define UDMF_META_PYTHON_SCRIPT   "general.python-script"
```

**Description**

Indicates a Python script, which belongs to **SHELL_SCRIPT**.

**Since**: 12


### UDMF_META_RAW_IMAGE

```
#define UDMF_META_RAW_IMAGE   "general.raw-image"
```

**Description**

Indicates a raw image, which belongs to **IMAGE**.

**Since**: 12


### UDMF_META_REALAUDIO

```
#define UDMF_META_REALAUDIO   "com.real.realaudio"
```

**Description**

Indicates RealAudio, which belongs to **AUDIO**.

**Since**: 12


### UDMF_META_REALMEDIA

```
#define UDMF_META_REALMEDIA   "com.real.realmedia"
```

**Description**

Indicates RealMedia format, which belongs to **VIDEO**.

**Since**: 12


### UDMF_META_RUBY_SCRIPT

```
#define UDMF_META_RUBY_SCRIPT   "general.ruby-script"
```

**Description**

Indicates a Ruby script, which belongs to **SHELL_SCRIPT**.

**Since**: 12


### UDMF_META_SCRIPT

```
#define UDMF_META_SCRIPT   "general.script"
```

**Description**

Indicates the source code in any scripting language, which belongs to **SOURCE_CODE**.

**Since**: 12


### UDMF_META_SD2_AUDIO

```
#define UDMF_META_SD2_AUDIO   "com.digidesign.sd2-audio"
```

**Description**

Indicates SDII, which belongs to **AUDIO**.

**Since**: 12


### UDMF_META_SGI_IMAGE

```
#define UDMF_META_SGI_IMAGE   "com.sgi.sgi-image"
```

**Description**

Indicates SGI format, which belongs to **IMAGE**.

**Since**: 12


### UDMF_META_SHELL_SCRIPT

```
#define UDMF_META_SHELL_SCRIPT   "general.shell-script"
```

**Description**

Indicates a Shell script, which belongs to **SCRIPT**.

**Since**: 12


### UDMF_META_SMIL

```
#define UDMF_META_SMIL   "com.real.smil"
```

**Description**

Indicates SMIL, which belongs to **XML**.

**Since**: 12


### UDMF_META_SOURCE_CODE

```
#define UDMF_META_SOURCE_CODE   "general.source-code"
```

**Description**

Indicates the generic source code type, which belongs to **PLAIN_TEXT**.

**Since**: 12


### UDMF_META_SPREADSHEETML_SHEET

```
#define UDMF_META_SPREADSHEETML_SHEET   "org.openxmlformats.spreadsheetml.sheet"
```

**Description**

Indicates the SpreadsheetML format, which belongs to **OPENXML** and **COMPOSITE_OBJECT**.

**Since**: 12


### UDMF_META_STUFFIT_ARCHIVE

```
#define UDMF_META_STUFFIT_ARCHIVE   "com.allume.stuffit-archive"
```

**Description**

Indicates the Stuffit compression format (stuffit archive), which belongs to **ARCHIVE**.

**Since**: 12


### UDMF_META_SUN_JAVA_CLASS

```
#define UDMF_META_SUN_JAVA_CLASS   "com.sun.java-class"
```

**Description**

Indicates the Java class file format, which belongs to **EXECUTABLE**.

**Since**: 12


### UDMF_META_SYMLINK

```
#define UDMF_META_SYMLINK   "general.symlink"
```

**Description**

Indicates the generic symbolic type, which belongs to **ENTITY**.

**Since**: 12


### UDMF_META_TAR_ARCHIVE

```
#define UDMF_META_TAR_ARCHIVE   "general.tar-archive"
```

**Description**

Indicates TAR, which belongs to ARCHIVE.

**Since**: 12


### UDMF_META_TEXT

```
#define UDMF_META_TEXT   "general.text"
```

**Description**

Indicates the generic text type, which belongs to **OBJECT**.

**Since**: 12


### UDMF_META_TGA_IMAGE

```
#define UDMF_META_TGA_IMAGE   "com.truevision.tga-image"
```

**Description**

Indicates TGA, which belongs to **IMAGE**.

**Since**: 12


### UDMF_META_TIFF

```
#define UDMF_META_TIFF   "general.tiff"
```

**Description**

Indicates TIFF, which belongs to **IMAGE**.

**Since**: 12


### UDMF_META_TRUETYPE_COLLECTION_FONT

```
#define UDMF_META_TRUETYPE_COLLECTION_FONT   "general.truetype-collection-font"
```

**Description**

Indicates the TrueType Collection font format, which belongs to **FONT**.

**Since**: 12


### UDMF_META_TRUETYPE_FONT

```
#define UDMF_META_TRUETYPE_FONT   "general.truetype-font"
```

**Description**

Indicates the TrueType font format, which belongs to **FONT**.

**Since**: 12


### UDMF_META_TYPE_SCRIPT

```
#define UDMF_META_TYPE_SCRIPT   "general.type-script"
```

**Description**

Indicates TypeScript source code, which belongs to **SCRIPT**.

**Since**: 12


### UDMF_META_VCARD

```
#define UDMF_META_VCARD   "general.vcard"
```

**Description**

Indicates the generic electronic business card type, which belongs to **OBJECT**.

**Since**: 12


### UDMF_META_VCS

```
#define UDMF_META_VCS   "general.vcs"
```

**Description**

Indicates the VCS format, which belongs to **CALENDAR** and **TEXT**.

**Since**: 12


### UDMF_META_VIDEO

```
#define UDMF_META_VIDEO   "general.video"
```

**Description**

Indicates the generic video type, which belongs to **MEDIA**.

**Since**: 12


### UDMF_META_VIDEO_3GPP

```
#define UDMF_META_VIDEO_3GPP   "general.3gpp"
```

**Description**

Indicates 3GP (3GPP file format), which belongs to **VIDEO**.

**Since**: 12


### UDMF_META_VIDEO_3GPP2

```
#define UDMF_META_VIDEO_3GPP2   "general.3gpp2"
```

**Description**

Indicates 3G2 (3GPP2 file format), which belongs to **VIDEO**.

**Since**: 12


### UDMF_META_WAVEFORM_AUDIO

```
#define UDMF_META_WAVEFORM_AUDIO   "com.microsoft.waveform-audio"
```

**Description**

Indicates Windows Waveform, which belongs to **AUDIO**.

**Since**: 12


### UDMF_META_WINDOWS_MEDIA_WAX

```
#define UDMF_META_WINDOWS_MEDIA_WAX   "com.microsoft.windows-media-wax"
```

**Description**

Indicates Windows WAX, which belongs to **AUDIO**.

**Since**: 12


### UDMF_META_WINDOWS_MEDIA_WM

```
#define UDMF_META_WINDOWS_MEDIA_WM   "com.microsoft.windows-media-wm"
```

**Description**

Indicates Windows WM format, which belongs to **VIDEO**.

**Since**: 12


### UDMF_META_WINDOWS_MEDIA_WMA

```
#define UDMF_META_WINDOWS_MEDIA_WMA   "com.microsoft.windows-media-wma"
```

**Description**

Indicates Windows WMA, which belongs to **AUDIO**.

**Since**: 12


### UDMF_META_WINDOWS_MEDIA_WMP

```
#define UDMF_META_WINDOWS_MEDIA_WMP   "com.microsoft.windows-media-wmp"
```

**Description**

Indicates Windows WMP, which belongs to **VIDEO**.

**Since**: 12


### UDMF_META_WINDOWS_MEDIA_WMV

```
#define UDMF_META_WINDOWS_MEDIA_WMV   "com.microsoft.windows-media-wmv"
```

**Description**

Indicates Windows WMV, which belongs to **VIDEO**.

**Since**: 12


### UDMF_META_WINDOWS_MEDIA_WMX

```
#define UDMF_META_WINDOWS_MEDIA_WMX   "com.microsoft.windows-media-wmx"
```

**Description**

Indicates Windows WMX, which belongs to **VIDEO**.

**Since**: 12


### UDMF_META_WINDOWS_MEDIA_WVX

```
#define UDMF_META_WINDOWS_MEDIA_WVX   "com.microsoft.windows-media-wvx"
```

**Description**

Indicates Windows WVX, which belongs to **VIDEO**.

**Since**: 12


### UDMF_META_WORD_DOC

```
#define UDMF_META_WORD_DOC   "com.microsoft.word.doc"
```

**Description**

Indicates Microsoft Word, which belongs to **COMPOSITE_OBJECT**.

**Since**: 12


### UDMF_META_WORDPROCESSINGML_DOCUMENT

```
#define UDMF_META_WORDPROCESSINGML_DOCUMENT   "org.openxmlformats.wordprocessingml.document"
```

**Description**

Indicates WordProcessingML format, which belongs to **OPENXML** and **COMPOSITE_OBJECT**.

**Since**: 12


### UDMF_META_XBITMAP_IMAGE

```
#define UDMF_META_XBITMAP_IMAGE   "general.xbitmap-image"
```

**Description**

Indicates X BitMAP (XBM) used in the X Window system (X11), which belongs to **IMAGE**.

**Since**: 12


### UDMF_META_XML

```
#define UDMF_META_XML   "general.xml"
```

**Description**

Indicates XML, which belongs to **TEXT**.

**Since**: 12


### UDMF_META_ZIP_ARCHIVE

```
#define UDMF_META_ZIP_ARCHIVE   "general.zip-archive"
```

**Description**

Indicates ZIP, which belongs to **ARCHIVE**.

**Since**: 12


## Type Description


### Udmf_ListenerStatus

```
typedef enum Udmf_ListenerStatusUdmf_ListenerStatus
```

**Description**

Defines an enum for the status codes returned when data is obtained asynchronously.

**Since**: 15


### Udmf_FileConflictOptions

```
typedef enum Udmf_FileConflictOptionsUdmf_FileConflictOptions
```

**Description**

Defines an enum for the options used to resolve file copy conflicts.

**Since**: 15

### Udmf_ProgressIndicator

```
typedef enum Udmf_ProgressIndicatorUdmf_ProgressIndicator
```

**Description**

Defines an enum for progress indicator options. You can use the default progress indicator as required.

**Since**: 15

### OH_Udmf_ProgressInfo

```
typedef struct OH_Udmf_ProgressInfoOH_Udmf_ProgressInfo
```

**Description**

Defines a struct for progress information.

**Since**: 15

### OH_UdmfGetDataParams

```
typedef struct OH_UdmfGetDataParamsOH_UdmfGetDataParams
```

**Description**

Defines a struct for the parameters used to obtain UDMF data asynchronously.

**Since**: 15

### OH_Udmf_DataProgressListener

```
typedef void(* OH_Udmf_DataProgressListener) (OH_Udmf_ProgressInfo *progressInfo, OH_UdmfData *data)
```

**Description**

Defines the callback used to return the data retrieval progress information and data obtained.

A null pointer is returned if the progress is not 100. The data obtained is returned only when the progress reaches 100.

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| progressInfo | Progress information obtained.|
| data | Data obtained.|


### OH_UdsContentForm

```
typedef struct OH_UdsContentForm OH_UdsContentForm
```

**Description**

Defines a struct for the uniform data of the content widget type.

**Since**: 14

### OH_UdmfData

```
typedef struct OH_UdmfData OH_UdmfData
```

**Description**

Defines a struct for a uniform data object.

**Since**: 12


### OH_UdmfProperty

```
typedef struct OH_UdmfProperty OH_UdmfProperty
```

**Description**

Defines a struct for a data record property in a uniform data object.

**Since**: 12


### OH_UdmfRecord

```
typedef struct OH_UdmfRecord OH_UdmfRecord
```

**Description**

Defines a struct for a data record in a uniform data object.

**Since**: 12


### OH_UdmfRecordProvider

```
typedef struct OH_UdmfRecordProvider OH_UdmfRecordProvider
```

**Description**

Represents the data record provider in a uniform data object.

**Since**: 13


### OH_UdmfRecordProvider_GetData

```
typedef void*(* OH_UdmfRecordProvider_GetData) (void *context, const char *type)
```

**Description**

Defines a callback function used to obtain data by type. This callback will be invoked to return the data obtained from **OH_UdmfRecord**.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| context | Pointer to the context set by [OH_UdmfRecordProvider_SetData](#oh_udmfrecordprovider_setdata).|
| type | Pointer to the type of the data to obtain. For details, see [udmf_meta.h](udmf__meta_8h.md).|

**Returns**

Uniform data obtained.


### OH_UdsAppItem

```
typedef struct OH_UdsAppItem OH_UdsAppItem
```

**Description**

Defines a struct for the uniform data of the home screen icon type.

**Since**: 12


### OH_UdsArrayBuffer

```
typedef struct OH_UdsArrayBuffer OH_UdsArrayBuffer
```

**Description**

Defines a struct for the ArrayBuffer type.

**Since**: 13


### OH_UdsFileUri

```
typedef struct OH_UdsFileUri OH_UdsFileUri
```

**Description**

Defines a struct for the file URI type.

**Since**: 13


### OH_UdsHtml

```
typedef struct OH_UdsHtml OH_UdsHtml
```

**Description**

Defines a struct for the uniform data of the Hypertext Markup Language (HTML) type.

**Since**: 12


### OH_UdsHyperlink

```
typedef struct OH_UdsHyperlink OH_UdsHyperlink
```

**Description**

Defines a struct for the uniform data of the hyperlink type.

**Since**: 12


### OH_UdsPixelMap

```
typedef struct OH_UdsPixelMap OH_UdsPixelMap
```

**Description**

Defines a struct for the pixel map type.

**Since**: 13


### OH_UdsPlainText

```
typedef struct OH_UdsPlainText OH_UdsPlainText
```

**Description**

Defines a struct for the uniform data of the plaintext type.

**Since**: 12


### OH_Utd

```
typedef struct OH_Utd OH_Utd
```

**Description**

Defines a struct for a UTD.

**Since**: 12


### Udmf_ErrCode

```
typedef enum Udmf_ErrCode Udmf_ErrCode
```

**Description**

Defines an enum for error codes.

**Since**: 12


### Udmf_Intention

```
typedef enum Udmf_Intention Udmf_Intention
```

**Description**

Defines an enum for UDMF data channel types.

**Since**: 12


### Udmf_ShareOption

```
typedef enum Udmf_ShareOption Udmf_ShareOption
```

**Description**

Defines an enum for the scopes of the uniform data to be used on a device.

**Since**: 12


### UdmfData_Finalize

```
typedef void(* UdmfData_Finalize) (void *context)
```

**Description**

Defines a callback function used to release the context. This callback is invoked when the **OH_UdmfRecordProvider** instance is destroyed.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| context | Pointer to the context to release.|


## Enum Description

### Udmf_ListenerStatus

```
enum Udmf_ListenerStatus
```

**Description**

Enumerates the status codes returned when data is obtained asynchronously.

**Since**: 15

| Value| Description|
| -------- | -------- |
| UDMF_FINISHED | Data is obtained successfully.|
| UDMF_PROCESSING | The data retrieval task is being processed.|
| UDMF_CANCELED | The data retrieval task is canceled.|
| UDMF_INNER_ERROR | An internal error occurs.|
| UDMF_INVALID_PARAMETERS | Invalid parameters are detected.|
| UDMF_DATA_NOT_FOUND | No data is obtained.|
| UDMF_SYNC_FAILED | An error occurs during data synchronization.|
| UDMF_COPY_FILE_FAILED | Failed to copy the file.|

### Udmf_FileConflictOptions

```
enum Udmf_FileConflictOptions
```

**Description**

Enumerates the options used to resolve file copy conflicts.

**Since**: 15

| Value| Description|
| -------- | -------- |
| UDMF_OVERWRITE | Overwrite the file with the same name in the destination directory. This is the default value.|
| UDMF_SKIP | Skip the file if there is a file with the same name in the destination directory.|

### Udmf_ProgressIndicator

```
enum Udmf_ProgressIndicator
```

**Description**

Enumerates the progress indicator options. You can use the default progress indicator as required.

**Since**: 15

| Value| Description|
| -------- | -------- |
| UDMF_NONE | Do not use the default progress indicator.|
| UDMF_DEFAULT | Use the default progress indicator. If data is obtained within 500 ms, the default progress bar is not started.|

### Udmf_ErrCode

```
enum Udmf_ErrCode
```

**Description**

Enumerates the error codes.

**Since**: 12

| Value| Description|
| -------- | -------- |
| UDMF_E_OK | The operation is successful.|
| UDMF_ERR | Common error.|
| UDMF_E_INVALID_PARAM | Invalid parameter.|


### Udmf_Intention

```
enum Udmf_Intention
```

**Description**

Enumerates the UDMF data channel types.

**Since**: 12

| Value| Description|
| -------- | -------- |
| UDMF_INTENTION_DRAG | Channel for dragging data.|
| UDMF_INTENTION_PASTEBOARD | Channel for clipboard data.|


### Udmf_ShareOption

```
enum Udmf_ShareOption
```

**Description**

Enumerates the scopes of the uniform data to be used on a device.

**Since**: 12

| Value| Description|
| -------- | -------- |
| SHARE_OPTIONS_INVALID | Invalid use.|
| SHARE_OPTIONS_IN_APP | Use the uniform data only in the same application of a device.|
| SHARE_OPTIONS_CROSS_APP | Use the uniform data across applications of a device.|


## Function Description

### OH_UdmfProgressInfo_GetProgress()

```
int OH_UdmfProgressInfo_GetProgress (OH_Udmf_ProgressInfo* progressInfo)
```

**Description**

Obtains the progress information from [OH_Udmf_ProgressInfo](#oh_udmf_progressinfo).

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| progressInfo | [OH_Udmf_ProgressInfo](#oh_udmf_progressinfo).|

**Returns**

Progress obtained, in percentage.

**See**

[OH_Udmf_ProgressInfo](#oh_udmf_progressinfo)

### OH_UdmfProgressInfo_GetStatus()

```
int OH_UdmfProgressInfo_GetStatus (OH_Udmf_ProgressInfo* progressInfo)
```

**Description**

Obtains the status information from [OH_Udmf_ProgressInfo](#oh_udmf_progressinfo).

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| progressInfo | [OH_Udmf_ProgressInfo](#oh_udmf_progressinfo).|

**Returns**

Status information obtained.

**See**

[OH_Udmf_ProgressInfo](#oh_udmf_progressinfo)

[Udmf_ListenerStatus](#udmf_listenerstatus)

### OH_UdmfGetDataParams_Create()

```
OH_UdmfGetDataParams* OH_UdmfGetDataParams_Create ()
```

### OH_UdmfGetDataParams_Destroy()

```
void OH_UdmfGetDataParams_Destroy (OH_UdmfGetDataParams* pThis)
```

**Description**

Destroys an [OH_UdmfGetDataParams](#oh_udmfgetdataparams) instance.

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdmfGetDataParams] (#oh_udmfgetdataparams) instance to destroy.|

**See**

[OH_UdmfGetDataParams](#oh_udmfgetdataparams)


**Description**

Creates an [OH_UdmfGetDataParams](#oh_udmfgetdataparams) instance for asynchronously obtaining UDMF data.

If this pointer is no longer required, use [OH_UdmfGetDataParams_Destroy](#oh_udmfgetdataparams_destroy) to destroy it. Otherwise, memory leaks may occur.

**Since**: 15

**Returns**

Returns a pointer to the [OH_UdmfGetDataParams](#oh_udmfgetdataparams) instance created if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdmfGetDataParams](#oh_udmfgetdataparams)

### OH_UdmfGetDataParams_SetDestUri()

```
void OH_UdmfGetDataParams_SetDestUri (OH_UdmfGetDataParams* params, const char* destUri )
```

**Description**

Sets the destination directory in an [OH_UdmfGetDataParams](#oh_udmfgetdataparams) instance.

If the destination directory is set, data of the file type will be copied to the specified directory. The file type data obtained in the callback will be replaced with the URI of the destination directory.

If the destination directory is not specified, the file will not be copied. The file type data obtained in the callback is the URI of the source directory.

If the application involves complex file processing or files need to be copied to multiple directories, you are advised to leave this parameter unspecified and let the application to handle the file copy.

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| params | Pointer to the target [OH_UdmfGetDataParams](#oh_udmfgetdataparams) instance.|
| destUri | Destination directory to set.|

**See**

[OH_UdmfGetDataParams](#oh_udmfgetdataparams)

### OH_UdmfGetDataParams_SetFileConflictOptions()

```
void OH_UdmfGetDataParams_SetFileConflictOptions (OH_UdmfGetDataParams* params, const Udmf_FileConflictOptions options )
```

**Description**

Sets the policy for resolving file conflicts in an [OH_UdmfGetDataParams](#oh_udmfgetdataparams) instance.

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| params | Pointer to the target [OH_UdmfGetDataParams](#oh_udmfgetdataparams) instance.|
| options | Policy to set.|

**See**

[OH_UdmfGetDataParams](#oh_udmfgetdataparams)

[Udmf_FileConflictOptions](#udmf_fileconflictoptions)

### OH_UdmfGetDataParams_SetProgressIndicator()

```
void OH_UdmfGetDataParams_SetProgressIndicator (OH_UdmfGetDataParams* params, const Udmf_ProgressIndicator progressIndicator )
```

**Description**

Sets the progress indicator in an [OH_UdmfGetDataParams](#oh_udmfgetdataparams) instance.

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| params | Pointer to the target [OH_UdmfGetDataParams](#oh_udmfgetdataparams) instance.|
| progressIndicator | Whether to use the default progress indicator.|

**See**

[OH_UdmfGetDataParams](#oh_udmfgetdataparams)

[Udmf_ProgressIndicator](#udmf_progressindicator)

### OH_UdmfGetDataParams_SetDataProgressListener()

```
void OH_UdmfGetDataParams_SetDataProgressListener (OH_UdmfGetDataParams* params, const OH_Udmf_DataProgressListener dataProgressListener )
```

**Description**

Sets the callback used to return the data obtained in an [OH_UdmfGetDataParams](#oh_udmfgetdataparams) instance.

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| params | Pointer to the target [OH_UdmfGetDataParams](#oh_udmfgetdataparams) instance.|
| dataProgressListener | Callback to set.|

**See**

[OH_UdmfGetDataParams](#oh_udmfgetdataparams)

[OH_Udmf_DataProgressListener](#oh_udmf_dataprogresslistener)

### OH_UdmfRecord_AddContentForm()

```
int OH_UdmfRecord_AddContentForm (OH_UdmfRecord* pThis, OH_UdsContentForm* contentForm )
```

**Description**

Adds data of the [OH_UdsContentForm](#oh_udscontentform) type to an [OH_UdmfRecord](#oh_udmfrecord) instance.

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdmfRecord](#oh_udmfrecord) instance.|
| contentForm | Pointer to the [OH_UdsContentForm](#oh_udscontentform) instance to add.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdmfRecord](#oh_udmfrecord)

[OH_UdsContentForm](#oh_udscontentform)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecord_GetContentForm()

```
int OH_UdmfRecord_GetContentForm (OH_UdmfRecord* pThis, OH_UdsContentForm* contentForm )
```

**Description**

Obtains data of the [OH_UdsContentForm](#oh_udscontentform) type from an [OH_UdmfRecord](#oh_udmfrecord) instance.

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdmfRecord](#oh_udmfrecord) instance.|
| contentForm | Pointer to the [OH_UdsContentForm](#oh_udscontentform) instance obtained.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdmfRecord](#oh_udmfrecord)

[OH_UdsContentForm](#oh_udscontentform)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdsContentForm_Create()

```
OH_UdsContentForm* OH_UdsContentForm_Create ()
```

**Description**

Creates an [OH_UdsContentForm](#oh_udscontentform) instance and a pointer to it.

**Since**: 14

**Returns**

Returns a pointer to the [OH_UdsContentForm](#oh_udscontentform) instance created if the operation is successful; return **nullptr** otherwise.

**See**

[OH_UdsContentForm](#oh_udscontentform)


### OH_UdsContentForm_Destroy()

```
void OH_UdsContentForm_Destroy (OH_UdsContentForm* pThis)
```

**Description**

Destroys an [OH_UdsContentForm](#oh_udscontentform) instance.

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdsContentForm](#oh_udscontentform) instance to destroy.|

**See**

[OH_UdsContentForm](#oh_udscontentform)


### OH_UdsContentForm_GetAppIcon()

```
int OH_UdsContentForm_GetAppIcon (OH_UdsContentForm* pThis, unsigned char** appIcon, unsigned int* len )
```

**Description**

Obtains the application icon data from an [OH_UdsContentForm](#oh_udscontentform) instance.

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the target [OH_UdsContentForm](#oh_udscontentform) instance.|
| appIcon | Double pointer to the binary application icon data obtained.|
| len | Pointer to the length of the binary application icon data obtained.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in. <br>Returns **UDMF_ERR** if an internal system error occurs.

**See**

[OH_UdsContentForm](#oh_udscontentform)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdsContentForm_GetAppName()

```
const char* OH_UdsContentForm_GetAppName (OH_UdsContentForm* pThis)
```

**Description**

Obtains the application name from an [OH_UdsContentForm](#oh_udscontentform) instance.

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the target [OH_UdsContentForm](#oh_udscontentform) instance.|

**Returns**

Returns the pointer to the application name obtained if the operation is successful; returns <b>nullptr</b> otherwise.

**See**

[OH_UdsContentForm](#oh_udscontentform)


### OH_UdsContentForm_GetDescription()

```
const char* OH_UdsContentForm_GetDescription (OH_UdsContentForm* pThis)
```

**Description**

Obtains the description from an [OH_UdsContentForm](#oh_udscontentform) instance.

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the target [OH_UdsContentForm](#oh_udscontentform) instance.|

**Returns**

Returns the pointer to the description string obtained if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdsContentForm](#oh_udscontentform)


### OH_UdsContentForm_GetLinkUri()

```
const char* OH_UdsContentForm_GetLinkUri (OH_UdsContentForm* pThis)
```

**Description**

Obtains the hyperlink information from an [OH_UdsContentForm](#oh_udscontentform) instance.

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the target [OH_UdsContentForm](#oh_udscontentform) instance.|

**Returns**

Returns the pointer to the hyperlink obtained if the operation is successful; returns <b>nullptr</b> otherwise.

**See**

[OH_UdsContentForm](#oh_udscontentform)


### OH_UdsContentForm_GetThumbData()

```
int OH_UdsContentForm_GetThumbData (OH_UdsContentForm* pThis, unsigned char** thumbData, unsigned int* len )
```

**Description**

Obtains image data from an [OH_UdsContentForm](#oh_udscontentform) instance.

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the target [OH_UdsContentForm](#oh_udscontentform) instance.|
| thumbData | Double pointer to the binary image data obtained.|
| len | Pointer to the length of the binary image data obtained.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in. <br>Returns **UDMF_ERR** if an internal system error occurs.

**See**

[OH_UdsContentForm](#oh_udscontentform)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdsContentForm_GetTitle()

```
const char* OH_UdsContentForm_GetTitle (OH_UdsContentForm* pThis)
```

**Description**

Obtains the title from an [OH_UdsContentForm](#oh_udscontentform) instance.

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the target [OH_UdsContentForm](#oh_udscontentform) instance.|

**Returns**

Returns the pointer to the title string obtained if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdsContentForm](#oh_udscontentform)


### OH_UdsContentForm_GetType()

```
const char* OH_UdsContentForm_GetType (OH_UdsContentForm* pThis)
```

**Description**

Obtains the type ID from an [OH_UdsContentForm](#oh_udscontentform) instance.

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the target [OH_UdsContentForm](#oh_udscontentform) instance.|

**Returns**

Returns a pointer to the type ID obtained if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdsContentForm](#oh_udscontentform)


### OH_UdsContentForm_SetAppIcon()

```
int OH_UdsContentForm_SetAppIcon (OH_UdsContentForm* pThis, const unsigned char* appIcon, unsigned int len )
```

**Description**

Sets the application icon data for an [OH_UdsContentForm](#oh_udscontentform) instance.

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the target [OH_UdsContentForm](#oh_udscontentform) instance.|
| appIcon | Pointer to the binary application icon data to set.|
| len | Length of the binary application icon data to set.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdsContentForm](#oh_udscontentform)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdsContentForm_SetAppName()

```
int OH_UdsContentForm_SetAppName (OH_UdsContentForm* pThis, const char* appName )
```

**Description**

Sets the application name for an [OH_UdsContentForm](#oh_udscontentform) instance.

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the target [OH_UdsContentForm](#oh_udscontentform) instance.|
| appName | Pointer to the application name to set.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdsContentForm](#oh_udscontentform)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdsContentForm_SetDescription()

```
int OH_UdsContentForm_SetDescription (OH_UdsContentForm* pThis, const char* description )
```

**Description**

Sets the description for an [OH_UdsContentForm](#oh_udscontentform) instance.

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the target [OH_UdsContentForm](#oh_udscontentform) instance.|
| description | Pointer to the description to set.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdsContentForm](#oh_udscontentform)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdsContentForm_SetLinkUri()

```
int OH_UdsContentForm_SetLinkUri (OH_UdsContentForm* pThis, const char* linkUri )
```

**Description**

Sets the hyperlink data for an [OH_UdsContentForm](#oh_udscontentform) instance.

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the target [OH_UdsContentForm](#oh_udscontentform) instance.|
| linkUri | Pointer to the hyperlink to set.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdsContentForm](#oh_udscontentform)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdsContentForm_SetThumbData()

```
int OH_UdsContentForm_SetThumbData (OH_UdsContentForm* pThis, const unsigned char* thumbData, unsigned int len )
```

**Description**

Sets the image data for an [OH_UdsContentForm](#oh_udscontentform) instance.

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the target [OH_UdsContentForm](#oh_udscontentform) instance.|
| thumbData | Pointer to the binary image data to set.|
| len | Length of the binary image data to set.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdsContentForm](#oh_udscontentform)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdsContentForm_SetTitle()

```
int OH_UdsContentForm_SetTitle (OH_UdsContentForm* pThis, const char* title )
```

**Description**

Sets the title for an [OH_UdsContentForm](#oh_udscontentform) instance.

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the target [OH_UdsContentForm](#oh_udscontentform) instance.|
| title | Pointer to the title to set.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdsContentForm](#oh_udscontentform)

[Udmf_ErrCode](#udmf_errcode)


### OH_Udmf_GetUnifiedData()

```
int OH_Udmf_GetUnifiedData (const char* key, Udmf_Intention intention, OH_UdmfData* unifiedData )
```

**Description**

Obtains an [OH_UdmfData](#oh_udmfdata) instance from the UDMF database.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| key | Pointer to the identifier of the data in the database.|
| intention | Type of the data channel. For details, see [Udmf_Intent]( #udmf_intention).|
| unifiedData | Pointer to the [OH_UdmfData](#oh_udmfdata) obtained.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdmfProperty](#oh_udmfproperty)

[Udmf_Intention](#udmf_intention)

[Udmf_ErrCode](#udmf_errcode)


### OH_Udmf_SetUnifiedData()

```
int OH_Udmf_SetUnifiedData (Udmf_Intention intention, OH_UdmfData* unifiedData, char* key, unsigned int keyLen )
```

**Description**

Sets an [OH_UdmfData](#oh_udmfdata) instance in the UDMF database.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| intention | Type of the data channel. For details, see [Udmf_Intent]( #udmf_intention).|
| unifiedData | Pointer to the [OH_UdmfData](#oh_udmfdata) data to set.|
| key | Pointer to the key that uniquely identifies the data in the database.|
| keyLen | Length of the key. The memory size must be greater than or equal to 512 bytes.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdmfProperty](#oh_udmfproperty)

[Udmf_Intention](#udmf_intention)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfData_AddRecord()

```
int OH_UdmfData_AddRecord (OH_UdmfData* pThis, OH_UdmfRecord* record )
```

**Description**

Adds an [OH_UdmfRecord](#oh_udmfrecord) to an [OH_UdmfData](#oh_udmfdata) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdmfData](#oh_udmfdata) instance.|
| record | Pointer to the [OH_UdmfRecord](#oh_udmfrecord) instance.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdmfData](#oh_udmfdata)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfData_Create()

```
OH_UdmfData* OH_UdmfData_Create ()
```

**Description**

Creates an [OH_UdmfData](#oh_udmfdata) instance and a pointer to it. If this pointer is no longer required, use [OH_UdmfData_Destroy](#oh_udmfdata_destroy) to destroy it. Otherwise, memory leaks may occur.

**Since**: 12

**Returns**

Returns a pointer to the [OH_UdmfData](#oh_udmfdata) instance created if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdmfData](#oh_udmfdata)


### OH_UdmfData_Destroy()

```
void OH_UdmfData_Destroy (OH_UdmfData* pThis)
```

**Description**

Destroys an [OH_UdmfData](#oh_udmfdata) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdmfData](#oh_udmfdata) instance to destroy.|

**See**

[OH_UdmfData](#oh_udmfdata)


### OH_UdmfData_GetPrimaryHtml()

```
int OH_UdmfData_GetPrimaryHtml (OH_UdmfData* data, OH_UdsHtml* html )
```

**Description**

Obtains the first [OH_UdsHtml](#oh_udshtml) data from an [OH_UdmfData](#oh_udmfdata) instance.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| data | Pointer to the [OH_UdmfData](#oh_udmfdata) instance.|
| html | Pointer to the [OH_UdsHtml](#oh_udshtml) data obtained.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdmfData](#oh_udmfdata)

[OH_UdsHtml](#oh_udshtml)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfData_GetPrimaryPlainText()

```
int OH_UdmfData_GetPrimaryPlainText (OH_UdmfData* data, OH_UdsPlainText* plainText )
```

**Description**

Obtains the first [OH_UdsPlainText](#oh_udsplaintext) data from an [OH_UdmfData](#oh_udmfdata) instance.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| data | Pointer to the [OH_UdmfData](#oh_udmfdata) instance.|
| plainText | Pointer to the [OH_UdsPlainText](#oh_udsplaintext) data obtained.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdmfData](#oh_udmfdata)

[OH_UdsPlainText](#oh_udsplaintext)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfData_GetRecord()

```
OH_UdmfRecord* OH_UdmfData_GetRecord (OH_UdmfData* data, unsigned int index )
```

**Description**

Obtains the specified data record from an [OH_UdmfData](#oh_udmfdata) instance.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| data | Pointer to the [OH_UdmfData](#oh_udmfdata) instance.|
| index | Index of the [OH_UdmfRecord]( #oh_udmfrecord) in the OH_UdmfData]( #oh_udmfdata) instance.|

**Returns**

Returns a pointer to the [OH_UdmfRecord](#oh_udmfrecord) instance obtained if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdmfData](#oh_udmfdata)


### OH_UdmfData_GetRecordCount()

```
int OH_UdmfData_GetRecordCount (OH_UdmfData* data)
```

**Description**

Obtains the number of data records contained in an [OH_UdmfData](#oh_udmfdata) instance.

**Parameters**

| Name| Description|
| -------- | -------- |
| data | Pointer to the target [OH_UdmfData](#oh_udmfdata) instance. |


### OH_UdmfData_GetRecords()

```
OH_UdmfRecord** OH_UdmfData_GetRecords (OH_UdmfData* pThis, unsigned int* count )
```

**Description**

Obtains all records contained in an [OH_UdmfData](#oh_udmfdata) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the target [OH_UdmfData](#oh_udmfdata) instance.|
| count | Pointer to the number of records obtained.|

**Returns**

Returns [OH_UdmfRecord](#oh_udmfrecord) obtained if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdmfData](#oh_udmfdata)

[OH_UdmfRecord](#oh_udmfrecord)


### OH_UdmfData_GetTypes()

```
char** OH_UdmfData_GetTypes (OH_UdmfData* pThis, unsigned int* count )
```

**Description**

Obtains all data types in an [OH_UdmfData](#oh_udmfdata) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the target [OH_UdmfData](#oh_udmfdata) instance.|
| count | Pointer to the number of data types obtained.|

**Returns**

Returns the data types obtained if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdmfData](#oh_udmfdata)


### OH_UdmfData_HasType()

```
bool OH_UdmfData_HasType (OH_UdmfData* pThis, const char* type )
```

**Description**

Checks whether the specified type exists in an [OH_UdmfData](#oh_udmfdata) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the target [OH_UdmfData](#oh_udmfdata) instance.|
| type | Pointer to the type to check.|

**Returns**

Returns **true** if the data type exists; returns **false** otherwise.

**See**

[OH_UdmfData](#oh_udmfdata)


### OH_UdmfData_IsLocal()

```
bool OH_UdmfData_IsLocal (OH_UdmfData* data)
```

**Description**

Checks whether an [OH_UdmfData](#oh_udmfdata) instance is from the local device.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| data | Pointer to the [OH_UdmfData](#oh_udmfdata) instance.|

**Returns**

Returns **true** if the data is from the local device; returns **false** otherwise.

**See**

[OH_UdmfData](#oh_udmfdata)


### OH_UdmfProperty_Create()

```
OH_UdmfProperty* OH_UdmfProperty_Create (OH_UdmfData* unifiedData)
```

**Description**

Creates an [OH_UdmfProperty](#oh_udmfproperty) instance and a pointer to it. If this pointer is no longer required, use [OH_UdmfProperty_Destroy](#oh_udmfproperty_destroy) to destroy it. Otherwise, memory leaks may occur.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| unifiedData | Pointer to the [OH_UdmfData](#oh_udmfdata) instance.|

**Returns**

Returns a pointer to the [OH_UdmfProperty](#oh_udmfproperty) instance created if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdmfData](#oh_udmfdata)

[OH_UdmfProperty](#oh_udmfproperty)


### OH_UdmfProperty_Destroy()

```
void OH_UdmfProperty_Destroy (OH_UdmfProperty* pThis)
```

**Description**

Destroys an [OH_UdmfProperty](#oh_udmfproperty) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdmfProperty](#oh_udmfproperty) instance to destroy.|

**See**

[OH_UdmfProperty](#oh_udmfproperty)


### OH_UdmfProperty_GetExtrasIntParam()

```
int OH_UdmfProperty_GetExtrasIntParam (OH_UdmfProperty* pThis, const char* key, int defaultValue )
```

**Description**

Obtains the customized extra integer parameter from an [OH_UdmfProperty](#oh_udmfproperty) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdmfProperty](#oh_udmfproperty) instance.|
| key | Pointer to the key of the parameter to obtain.|
| defaultValue | Default value to be returned if the parameter fails to be obtained.|

**Returns**

Returns the integer value obtained if the operation is successful; returns **defaultValue** if the operation fails.

**See**

[OH_UdmfProperty](#oh_udmfproperty)


### OH_UdmfProperty_GetExtrasStringParam()

```
const char* OH_UdmfProperty_GetExtrasStringParam (OH_UdmfProperty* pThis, const char* key )
```

**Description**

Obtains the customized extra string parameter from an [OH_UdmfProperty](#oh_udmfproperty) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdmfProperty](#oh_udmfproperty) instance.|
| key | Pointer to the key of the parameter to obtain.|

**Returns**

Returns a pointer to the string value obtained if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdmfProperty](#oh_udmfproperty)


### OH_UdmfProperty_GetShareOption()

```
Udmf_ShareOption OH_UdmfProperty_GetShareOption (OH_UdmfProperty* pThis)
```

**Description**

Obtains the share option from an [OH_UdmfProperty](#oh_udmfproperty) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdmfProperty](#oh_udmfproperty) instance.|

**Returns**

Returns the [Udmf_ShareOption](#udmf_shareoption) obtained.

**See**

[OH_UdmfProperty](#oh_udmfproperty)

[Udmf_ShareOption](#udmf_shareoption)


### OH_UdmfProperty_GetTag()

```
const char* OH_UdmfProperty_GetTag (OH_UdmfProperty* pThis)
```

**Description**

Obtains the custom tag value from an [OH_UdmfProperty](#oh_udmfproperty) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdmfProperty](#oh_udmfproperty) instance.|

**Returns**

Returns a pointer to the custom tag value obtained if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdmfProperty](#oh_udmfproperty)


### OH_UdmfProperty_GetTimestamp()

```
int64_t OH_UdmfProperty_GetTimestamp (OH_UdmfProperty* pThis)
```

**Description**

Obtains the timestamp from an [OH_UdmfProperty](#oh_udmfproperty) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdmfProperty](#oh_udmfproperty) instance.|

**Returns**

Returns the timestamp obtained.

**See**

[OH_UdmfProperty](#oh_udmfproperty)


### OH_UdmfProperty_SetExtrasIntParam()

```
int OH_UdmfProperty_SetExtrasIntParam (OH_UdmfProperty* pThis, const char* key, int param )
```

**Description**

Sets the extra integer parameter for an [OH_UdmfProperty](#oh_udmfproperty) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdmfRecord](#oh_udmfrecord) instance.|
| key | Pointer to the key of the parameter to set.|
| param | Parameter value to set.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdmfProperty](#oh_udmfproperty)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfProperty_SetExtrasStringParam()

```
int OH_UdmfProperty_SetExtrasStringParam (OH_UdmfProperty* pThis, const char* key, const char* param )
```

**Description**

Sets the extra string parameter for an [OH_UdmfProperty](#oh_udmfproperty) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdmfRecord](#oh_udmfrecord) instance.|
| key | Pointer to the key of the parameter to set.|
| param | Parameter value to set.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdmfProperty](#oh_udmfproperty)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfProperty_SetShareOption()

```
int OH_UdmfProperty_SetShareOption (OH_UdmfProperty* pThis, Udmf_ShareOption option )
```

**Description**

Sets the share option for an [OH_UdmfProperty](#oh_udmfproperty) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdmfProperty](#oh_udmfproperty) instance.|
| option | [Udmf_ShareOption](#udmf_shareoption) to set.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdmfProperty](#oh_udmfproperty)

[Udmf_ShareOption](#udmf_shareoption)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfProperty_SetTag()

```
int OH_UdmfProperty_SetTag (OH_UdmfProperty* pThis, const char* tag )
```

**Description**

Sets the tag value for an [OH_UdmfProperty](#oh_udmfproperty) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdmfProperty](#oh_udmfproperty) instance.|
| tag | Pointer to the tag value to set.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdmfProperty](#oh_udmfproperty)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecord_AddAppItem()

```
int OH_UdmfRecord_AddAppItem (OH_UdmfRecord* pThis, OH_UdsAppItem* appItem )
```

**Description**

Adds data of the [OH_UdsAppItem](#oh_udsappitem) type to an [OH_UdmfRecord](#oh_udmfrecord) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdmfRecord](#oh_udmfrecord) instance.|
| appItem | Pointer to the [OH_UdsAppItem](#oh_udsappitem) instance to add.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdmfRecord](#oh_udmfrecord)

[OH_UdsAppItem](#oh_udsappitem)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecord_AddArrayBuffer()

```
int OH_UdmfRecord_AddArrayBuffer (OH_UdmfRecord* record, const char* type, OH_UdsArrayBuffer* buffer )
```

**Description**

Adds a data record of the [OH_UdsArrayBuffer](#oh_udsarraybuffer) type to an [OH_UdmfRecord](#oh_udmfrecord) instance.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| record | Pointer to the [OH_UdmfRecord](#oh_udmfrecord) instance.|
| type | Pointer to the ArrayBuffer type ID, which must be unique.|
| buffer | Pointer to the [OH_UdsArrayBuffer]( #oh_udsarraybuffer) instance.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdmfRecord](#oh_udmfrecord)

[OH_UdsArrayBuffer](#oh_udsarraybuffer)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecord_AddFileUri()

```
int OH_UdmfRecord_AddFileUri (OH_UdmfRecord* pThis, OH_UdsFileUri* fileUri )
```

**Description**

Adds a data record of the [OH_UdsFileUri](#oh_udsfileuri) type to an [OH_UdmfRecord](#oh_udmfrecord) instance.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdmfRecord](#oh_udmfrecord) instance.|
| fileUri | Pointer to the [OH_UdsFileUri]( #oh_udsfileuri) instance.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdmfRecord](#oh_udmfrecord)

[OH_UdsFileUri](#oh_udsfileuri)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecord_AddGeneralEntry()

```
int OH_UdmfRecord_AddGeneralEntry (OH_UdmfRecord* pThis, const char* typeId, unsigned char* entry, unsigned int count )
```

**Description**

Adds customized uniform data to an [OH_UdmfRecord](#oh_udmfrecord) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdmfRecord](#oh_udmfrecord) instance.|
| typeId | Pointer to the data type ID.|
| entry | Pointer to the customized data to add.|
| count | Size of customized data to add. The data size cannot exceed 4 KB.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdmfRecord](#oh_udmfrecord)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecord_AddHtml()

```
int OH_UdmfRecord_AddHtml (OH_UdmfRecord* pThis, OH_UdsHtml* html )
```

**Description**

Adds data of the [OH_UdsHtml](#oh_udshtml) type to an [OH_UdmfRecord](#oh_udmfrecord) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdmfRecord](#oh_udmfrecord) instance.|
| html | Pointer to the [OH_UdsHtml](#oh_udshtml) instance to add.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdmfRecord](#oh_udmfrecord)

[OH_UdsHtml](#oh_udshtml)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecord_AddHyperlink()

```
int OH_UdmfRecord_AddHyperlink (OH_UdmfRecord* pThis, OH_UdsHyperlink* hyperlink )
```

**Description**

Adds data of the hyperlink type [OH_UdsHyperlink](#oh_udshyperlink) type to an [OH_UdmfRecord](#oh_udmfrecord) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdmfRecord](#oh_udmfrecord) instance.|
| hyperlink | Pointer to the [OH_UdsHyperlink](#oh_udshyperlink) instance to add.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdmfRecord](#oh_udmfrecord)

[OH_UdsHyperlink](#oh_udshyperlink)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecord_AddPixelMap()

```
int OH_UdmfRecord_AddPixelMap (OH_UdmfRecord* pThis, OH_UdsPixelMap* pixelMap )
```

**Description**

Adds a data record of the [OH_UdsPixelMap](#oh_udspixelmap) type to an [OH_UdmfRecord](#oh_udmfrecord) instance.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdmfRecord](#oh_udmfrecord) instance.|
| pixelMap | Pointer to the [OH_UdsPixelMap]( #oh_udspixelmap) instance.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdmfRecord](#oh_udmfrecord)

[OH_UdsPixelMap](#oh_udspixelmap)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecord_AddPlainText()

```
int OH_UdmfRecord_AddPlainText (OH_UdmfRecord* pThis, OH_UdsPlainText* plainText )
```

**Description**

Adds data of the [OH_UdsPlainText](#oh_udsplaintext) type to an [OH_UdmfRecord](#oh_udmfrecord) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdmfRecord](#oh_udmfrecord) instance.|
| plainText | Pointer to the [OH_UdsPlainText](#oh_udsplaintext) instance to add.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdmfRecord](#oh_udmfrecord)

[OH_UdsPlainText](#oh_udsplaintext)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecord_Create()

```
OH_UdmfRecord* OH_UdmfRecord_Create ()
```

**Description**

Creates an [OH_UdmfRecord](#oh_udmfrecord) instance and a pointer to it. If this pointer is no longer required, use [OH_UdmfRecord_Destroy](#oh_udmfrecord_destroy) to destroy it. Otherwise, memory leaks may occur.

**Since**: 12

**Returns**

Returns a pointer to the [OH_UdmfRecord](#oh_udmfrecord) instance created if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdmfRecord](#oh_udmfrecord)


### OH_UdmfRecord_Destroy()

```
void OH_UdmfRecord_Destroy (OH_UdmfRecord* pThis)
```

**Description**

Destroys an [OH_UdmfRecord](#oh_udmfrecord) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdmfRecord](#oh_udmfrecord) instance to destroy.|

**See**

[OH_UdmfRecord](#oh_udmfrecord)


### OH_UdmfRecord_GetAppItem()

```
int OH_UdmfRecord_GetAppItem (OH_UdmfRecord* pThis, OH_UdsAppItem* appItem )
```

**Description**

Obtains [OH_UdsAppItem](#oh_udsappitem) data from an [OH_UdmfRecord](#oh_udmfrecord) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdmfRecord](#oh_udmfrecord) instance.|
| appItem | Pointer to the [OH_UdsAppItem](#oh_udsappitem) instance obtained.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdmfRecord](#oh_udmfrecord)

[OH_UdsAppItem](#oh_udsappitem)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecord_GetArrayBuffer()

```
int OH_UdmfRecord_GetArrayBuffer (OH_UdmfRecord* record, const char* type, OH_UdsArrayBuffer* buffer )
```

**Description**

Obtains the [OH_UdsArrayBuffer](#oh_udsarraybuffer) data from an [OH_UdmfRecord](#oh_udmfrecord) instance.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| record | Pointer to the [OH_UdmfRecord](#oh_udmfrecord) instance.|
| type | Pointer to the data type ID of the ArrayBuffer data to obtain.|
| buffer | Pointer to the [OH_UdsArrayBuffer]( #oh_udsarraybuffer) data obtained.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdmfRecord](#oh_udmfrecord)

[OH_UdsArrayBuffer](#oh_udsarraybuffer)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecord_GetFileUri()

```
int OH_UdmfRecord_GetFileUri (OH_UdmfRecord* pThis, OH_UdsFileUri* fileUri )
```

**Description**

Obtains the [OH_UdsFileUri](#oh_udsfileuri) data from an [OH_UdmfRecord](#oh_udmfrecord) instance.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdmfRecord](#oh_udmfrecord) instance.|
| fileUri | Pointer to the [OH_UdsFileUri]( #oh_udsfileuri) data obtained.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdmfRecord](#oh_udmfrecord)

[OH_UdsFileUri](#oh_udsfileuri)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecord_GetGeneralEntry()

```
int OH_UdmfRecord_GetGeneralEntry (OH_UdmfRecord* pThis, const char* typeId, unsigned char** entry, unsigned int* count )
```

**Description**

Obtains the data of the specified type in an [OH_UdmfRecord](#oh_udmfrecord) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdmfRecord](#oh_udmfrecord) instance.|
| typeId | Pointer to the data type ID.|
| entry | Double pointer to the data obtained.|
| count | Length of the data obtained.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdmfRecord](#oh_udmfrecord)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecord_GetHtml()

```
int OH_UdmfRecord_GetHtml (OH_UdmfRecord* pThis, OH_UdsHtml* html )
```

**Description**

Obtains [OH_UdsHtml](#oh_udshtml) data from an [OH_UdmfRecord](#oh_udmfrecord) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdmfRecord](#oh_udmfrecord) instance.|
| html | Pointer to the [OH_UdsHtml](#oh_udshtml) data obtained.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdmfRecord](#oh_udmfrecord)

[OH_UdsHtml](#oh_udshtml)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecord_GetHyperlink()

```
int OH_UdmfRecord_GetHyperlink (OH_UdmfRecord* pThis, OH_UdsHyperlink* hyperlink )
```

**Description**

Obtains [OH_UdsHyperlink](#oh_udshyperlink) data from an [OH_UdmfRecord](#oh_udmfrecord) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdmfRecord](#oh_udmfrecord) instance.|
| hyperlink | Pointer to the [OH_UdsHyperlink](#oh_udshyperlink) data obtained.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdmfRecord](#oh_udmfrecord)

[OH_UdsHyperlink](#oh_udshyperlink)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecord_GetPixelMap()

```
int OH_UdmfRecord_GetPixelMap (OH_UdmfRecord* pThis, OH_UdsPixelMap* pixelMap )
```

**Description**

Obtains the [OH_UdsPixelMap](#oh_udspixelmap) data from an [OH_UdmfRecord](#oh_udmfrecord) instance.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdmfRecord](#oh_udmfrecord) instance.|
| pixelMap | Pointer to the [OH_UdsPixelMap]( #oh_udspixelmap) data obtained.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdmfRecord](#oh_udmfrecord)

[OH_UdsPixelMap](#oh_udspixelmap)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecord_GetPlainText()

```
int OH_UdmfRecord_GetPlainText (OH_UdmfRecord* pThis, OH_UdsPlainText* plainText )
```

**Description**

Obtains [OH_UdsPlainText](#oh_udsplaintext) data from an [OH_UdmfRecord](#oh_udmfrecord) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdmfRecord](#oh_udmfrecord) instance.|
| plainText | Pointer to the [OH_UdsPlainText](#oh_udsplaintext) data obtained.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdmfRecord](#oh_udmfrecord)

[OH_UdsPlainText](#oh_udsplaintext)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecord_GetTypes()

```
char** OH_UdmfRecord_GetTypes (OH_UdmfRecord* pThis, unsigned int* count )
```

**Description**

Obtains all data types in an [OH_UdmfRecord](#oh_udmfrecord) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdmfRecord](#oh_udmfrecord) instance.|
| count | Pointer to the number of data types obtained.|

**Returns**

Returns a list of data types obtained if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdmfRecord](#oh_udmfrecord)


### OH_UdmfRecord_SetProvider()

```
int OH_UdmfRecord_SetProvider (OH_UdmfRecord* pThis, const char* const* types, unsigned int count, OH_UdmfRecordProvider* provider )
```

**Description**

Sets the [OH_UdmfRecordProvider](#oh_udmfrecordprovider) in an [OH_UdmfRecord](#oh_udmfrecord) instance.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdmfRecord](#oh_udmfrecord) instance.|
| types | Pointer to the data types to be provided.|
| count | Number of the data types.|
| provider | Pointer to the [OH_UdmfRecordProvider]( #oh_udmfrecordprovider) instance to set.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdmfRecord](#oh_udmfrecord)

[OH_UdmfRecordProvider](#oh_udmfrecordprovider)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecordProvider_Create()

```
OH_UdmfRecordProvider* OH_UdmfRecordProvider_Create ()
```

**Description**

Creates an [OH_UdmfRecordProvider](#oh_udmfrecordprovider) instance and a pointer to it. If this pointer is no longer required, use [OH_UdmfRecordProvider_Destroy](#oh_udmfrecordprovider_destroy) to destroy it. Otherwise, memory leaks may occur.

**Since**: 13

**Returns**

Returns a pointer to the [OH_UdmfRecordProvider](#oh_udmfrecordprovider) instance created if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdmfRecordProvider](#oh_udmfrecordprovider)


### OH_UdmfRecordProvider_Destroy()

```
int OH_UdmfRecordProvider_Destroy (OH_UdmfRecordProvider* provider)
```

**Description**

Destroys an [OH_UdmfRecordProvider](#oh_udmfrecordprovider) instance.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| provider | Pointer to the [OH_UdmfRecordProvider](#oh_udmfrecordprovider) instance to destroy.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdmfRecordProvider](#oh_udmfrecordprovider)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecordProvider_SetData()

```
int OH_UdmfRecordProvider_SetData (OH_UdmfRecordProvider* provider, void* context, const OH_UdmfRecordProvider_GetData callback, const UdmfData_Finalize finalize )
```

**Description**

Sets a callback for an **OH_UdmfRecordProvider** instance to provide data.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| provider | Pointer to the target [OH_UdmfRecordProvider](#oh_udmfrecordprovider) instance.|
| context | Pointer to the context, which is passed as the first parameter to [OH_UdmfRecordProvider_GetData](#oh_udmfrecordprovider_getdata).|
| callback | Callback used to obtain data. For details, see [OH_UdmfRecordProvider_GetData](#oh_udmfrecordprovider_getdata).|
| finalize | Optional callback used to release the context data when the **OH_UdmfRecordProvider** instance is destroyed. For details, see [UdmfData_Finalize](#udmfdata_finalize).|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdmfRecordProvider](#oh_udmfrecordprovider)

[OH_UdmfRecordProvider_GetData](#oh_udmfrecordprovider_getdata)

[UdmfData_Finalize](#udmfdata_finalize) [Udmf_ErrCode](#udmf_errcode)


### OH_UdsAppItem_Create()

```
OH_UdsAppItem* OH_UdsAppItem_Create ()
```

**Description**

Creates an [OH_UdsAppItem](#oh_udsappitem) instance and a pointer to it. If this pointer is no longer required, use [OH_UdsAppItem_Destroy](#oh_udsappitem_destroy) to destroy it. Otherwise, memory leaks may occur.

**Since**: 12

**Returns**

Returns a pointer to the [OH_UdsAppItem](#oh_udsappitem) data obtained; returns **nullptr** otherwise.

**See**

[OH_UdsAppItem](#oh_udsappitem)


### OH_UdsAppItem_Destroy()

```
void OH_UdsAppItem_Destroy (OH_UdsAppItem* pThis)
```

**Description**

Destroys an [OH_UdsAppItem](#oh_udsappitem) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdsAppItem](#oh_udsappitem) instance to destroy.|

**See**

[OH_UdsAppItem](#oh_udsappitem)


### OH_UdsAppItem_GetAbilityName()

```
const char* OH_UdsAppItem_GetAbilityName (OH_UdsAppItem* pThis)
```

**Description**

Obtains the ability name from an [OH_UdsAppItem](#oh_udsappitem) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdsAppItem](#oh_udsappitem) instance.|

**Returns**

Returns a pointer to the ability name obtained if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdsAppItem](#oh_udsappitem)


### OH_UdsAppItem_GetBundleName()

```
const char* OH_UdsAppItem_GetBundleName (OH_UdsAppItem* pThis)
```

**Description**

Obtains the bundle name from an [OH_UdsAppItem](#oh_udsappitem) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdsAppItem](#oh_udsappitem) instance.|

**Returns**

Returns a pointer to the bundle name obtained if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdsAppItem](#oh_udsappitem)


### OH_UdsAppItem_GetIconId()

```
const char* OH_UdsAppItem_GetIconId (OH_UdsAppItem* pThis)
```

**Description**

Obtains the application icon ID from an [OH_UdsAppItem](#oh_udsappitem) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdsAppItem](#oh_udsappitem) instance.|

**Returns**

Returns a pointer to the application icon ID obtained if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdsAppItem](#oh_udsappitem)


### OH_UdsAppItem_GetId()

```
const char* OH_UdsAppItem_GetId (OH_UdsAppItem* pThis)
```

**Description**

Obtains the application ID from an [OH_UdsAppItem](#oh_udsappitem) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdsAppItem](#oh_udsappitem) instance.|

**Returns**

Returns a pointer to the application ID obtained if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdsAppItem](#oh_udsappitem)


### OH_UdsAppItem_GetLabelId()

```
const char* OH_UdsAppItem_GetLabelId (OH_UdsAppItem* pThis)
```

**Description**

Obtains the application label ID from an [OH_UdsAppItem](#oh_udsappitem) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdsAppItem](#oh_udsappitem) instance.|

**Returns**

Returns a pointer to the application label ID obtained if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdsAppItem](#oh_udsappitem)


### OH_UdsAppItem_GetName()

```
const char* OH_UdsAppItem_GetName (OH_UdsAppItem* pThis)
```

**Description**

Obtains the application name from an [OH_UdsAppItem](#oh_udsappitem) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdsAppItem](#oh_udsappitem) instance.|

**Returns**

Returns a pointer to the application name obtained if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdsAppItem](#oh_udsappitem)


### OH_UdsAppItem_GetType()

```
const char* OH_UdsAppItem_GetType (OH_UdsAppItem* pThis)
```

**Description**

Obtains the type ID from an [OH_UdsAppItem](#oh_udsappitem) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdsAppItem](#oh_udsappitem) instance.|

**Returns**

Returns a pointer to the type ID obtained if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdsAppItem](#oh_udsappitem)


### OH_UdsAppItem_SetAbilityName()

```
int OH_UdsAppItem_SetAbilityName (OH_UdsAppItem* pThis, const char* abilityName )
```

**Description**

Sets the ability name for an [OH_UdsAppItem](#oh_udsappitem) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdsAppItem](#oh_udsappitem) instance.|
| abilityName | Pointer to the ability name to set.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdsAppItem](#oh_udsappitem)


### OH_UdsAppItem_SetBundleName()

```
int OH_UdsAppItem_SetBundleName (OH_UdsAppItem* pThis, const char* bundleName )
```

**Description**

Sets the bundle name for an [OH_UdsAppItem](#oh_udsappitem) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdsAppItem](#oh_udsappitem) instance.|
| bundleName | Pointer to the bundle name to set.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdsAppItem](#oh_udsappitem)


### OH_UdsAppItem_SetIconId()

```
int OH_UdsAppItem_SetIconId (OH_UdsAppItem* pThis, const char* appIconId )
```

**Description**

Sets the application icon ID for an [OH_UdsAppItem](#oh_udsappitem) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdsAppItem](#oh_udsappitem) instance.|
| appIconId | Pointer to the application icon ID to set.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdsAppItem](#oh_udsappitem)


### OH_UdsAppItem_SetId()

```
int OH_UdsAppItem_SetId (OH_UdsAppItem* pThis, const char* appId )
```

**Description**

Sets the application ID for an [OH_UdsAppItem](#oh_udsappitem) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdsAppItem](#oh_udsappitem) instance.|
| appId | Pointer to the application ID to set.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdsAppItem](#oh_udsappitem)


### OH_UdsAppItem_SetLabelId()

```
int OH_UdsAppItem_SetLabelId (OH_UdsAppItem* pThis, const char* appLabelId )
```

**Description**

Sets the application label ID for an [OH_UdsAppItem](#oh_udsappitem) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdsAppItem](#oh_udsappitem) instance.|
| appLabelId | Pointer to the application label ID to set.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdsAppItem](#oh_udsappitem)


### OH_UdsAppItem_SetName()

```
int OH_UdsAppItem_SetName (OH_UdsAppItem* pThis, const char* appName )
```

**Description**

Sets the application name for an [OH_UdsAppItem](#oh_udsappitem) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdsAppItem](#oh_udsappitem) instance.|
| appName | Pointer to the application name to set.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdsAppItem](#oh_udsappitem)


### OH_UdsArrayBuffer_Create()

```
OH_UdsArrayBuffer* OH_UdsArrayBuffer_Create ()
```

**Description**

Creates an [OH_UdsArrayBuffer](#oh_udsarraybuffer) instance and a pointer to it. If this pointer is no longer required, use [OH_UdsArrayBuffer_Destroy](#oh_udsarraybuffer_destroy) to destroy it. Otherwise, memory leaks may occur.

**Since**: 13

**Returns**

Returns a pointer to the [OH_UdsArrayBuffer]( #oh_udsarraybuffer) instance created if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdsArrayBuffer](#oh_udsarraybuffer)


### OH_UdsArrayBuffer_Destroy()

```
int OH_UdsArrayBuffer_Destroy (OH_UdsArrayBuffer* buffer)
```

**Description**

Destroys an [OH_UdsArrayBuffer](#oh_udsarraybuffer) instance.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| buffer | Pointer to the [OH_UdsArrayBuffer]( #oh_udsarraybuffer) instance.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdsArrayBuffer](#oh_udsarraybuffer)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdsArrayBuffer_GetData()

```
int OH_UdsArrayBuffer_GetData (OH_UdsArrayBuffer* buffer, unsigned char** data, unsigned int* len )
```

**Description**

Obtains the custom ArrayBuffer data from an [OH_UdsArrayBuffer](#oh_udsarraybuffer) instance.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| buffer | Pointer to the target [OH_UdsArrayBuffer](#oh_udsarraybuffer) instance.|
| data | Double pointer to the ArrayBuffer data obtained.|
| len | Pointer to the length of the ArrayBuffer data obtained.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdsArrayBuffer](#oh_udsarraybuffer)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdsArrayBuffer_SetData()

```
int OH_UdsArrayBuffer_SetData (OH_UdsArrayBuffer* buffer, unsigned char* data, unsigned int len )
```

**Description**

Sets an [OH_UdsArrayBuffer](#oh_udsarraybuffer) instance.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| buffer | Pointer to the target [OH_UdsArrayBuffer](#oh_udsarraybuffer) instance.|
| data | Pointer to the ArrayBuffer data to set.|
| len | Length of the ArrayBuffer data to set.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdsArrayBuffer](#oh_udsarraybuffer)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdsFileUri_Create()

```
OH_UdsFileUri* OH_UdsFileUri_Create ()
```

**Description**

Creates an [OH_UdsFileUri](#oh_udsfileuri) instance and a pointer to it. If this pointer is no longer required, use [OH_UdsFileUri_Destroy](#oh_udsfileuri_destroy) to destroy it. Otherwise, memory leaks may occur.

**Since**: 13

**Returns**

Returns a pointer to the [OH_UdsFileUri](#oh_udsfileuri) instance created if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdsFileUri](#oh_udsfileuri)


### OH_UdsFileUri_Destroy()

```
void OH_UdsFileUri_Destroy (OH_UdsFileUri* pThis)
```

**Description**

Destroys an [OH_UdsFileUri](#oh_udsfileuri) instance.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdsFileUri]( #oh_udsfileuri) instance to destroy.|

**See**

[OH_UdsFileUri](#oh_udsfileuri)


### OH_UdsFileUri_GetFileType()

```
const char* OH_UdsFileUri_GetFileType (OH_UdsFileUri* pThis)
```

**Description**

Obtains the file type from an [OH_UdsFileUri](#oh_udsfileuri) instance.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the target [OH_UdsFileUri]( #oh_udsfileuri) instance.|

**Returns**

Returns a pointer to the file type obtained if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdsFileUri](#oh_udsfileuri)


### OH_UdsFileUri_GetFileUri()

```
const char* OH_UdsFileUri_GetFileUri (OH_UdsFileUri* pThis)
```

**Description**

Obtains the file URI from an [OH_UdsFileUri](#oh_udsfileuri) instance.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the target [OH_UdsFileUri]( #oh_udsfileuri) instance.|

**Returns**

Returns a pointer to the file URI obtained if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdsFileUri](#oh_udsfileuri)


### OH_UdsFileUri_GetType()

```
const char* OH_UdsFileUri_GetType (OH_UdsFileUri* pThis)
```

**Description**

Obtains the type ID from an [OH_UdsFileUri](#oh_udsfileuri) instance.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the target [OH_UdsFileUri]( #oh_udsfileuri) instance.|

**Returns**

Returns a pointer to the type ID obtained if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdsFileUri](#oh_udsfileuri)


### OH_UdsFileUri_SetFileType()

```
int OH_UdsFileUri_SetFileType (OH_UdsFileUri* pThis, const char* fileType )
```

**Description**

Sets the file type for an [OH_UdsFileUri](#oh_udsfileuri) instance.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the target [OH_UdsFileUri]( #oh_udsfileuri) instance.|
| fileType | Pointer to the file type to set.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdsFileUri](#oh_udsfileuri)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdsFileUri_SetFileUri()

```
int OH_UdsFileUri_SetFileUri (OH_UdsFileUri* pThis, const char* fileUri )
```

**Description**

Sets the URI information for an [OH_UdsFileUri](#oh_udsfileuri) instance.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the target [OH_UdsFileUri]( #oh_udsfileuri) instance.|
| fileUri | Pointer to the file URI to set.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdsFileUri](#oh_udsfileuri)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdsHtml_Create()

```
OH_UdsHtml* OH_UdsHtml_Create ()
```

**Description**

Creates an [OH_UdsHtml](#oh_udshtml) instance and a pointer to it. If this pointer is no longer required, use [OH_UdsHtml_Destroy](#oh_udshtml_destroy) to destroy it. Otherwise, memory leaks may occur.

**Since**: 12

**Returns**

Returns a pointer to the [OH_UdsHtml](#oh_udshtml) instance created if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdsHtml](#oh_udshtml)


### OH_UdsHtml_Destroy()

```
void OH_UdsHtml_Destroy (OH_UdsHtml* pThis)
```

**Description**

Destroys an [OH_UdsHtml](#oh_udshtml) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdsHtml](#oh_udshtml) instance to destroy.|

**See**

[OH_UdsHtml](#oh_udshtml)


### OH_UdsHtml_GetContent()

```
const char* OH_UdsHtml_GetContent (OH_UdsHtml* pThis)
```

**Description**

Obtains the HTML content from an [OH_UdsHtml](#oh_udshtml) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdsHtml](#oh_udshtml) instance.|

**Returns**

Returns a pointer to the HTML content obtained if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdsHtml](#oh_udshtml)


### OH_UdsHtml_GetPlainContent()

```
const char* OH_UdsHtml_GetPlainContent (OH_UdsHtml* pThis)
```

**Description**

Obtains the plaintext from an [OH_UdsHtml](#oh_udshtml) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdsHtml](#oh_udshtml) instance.|

**Returns**

Returns a pointer to the plaintext obtained if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdsHtml](#oh_udshtml)


### OH_UdsHtml_GetType()

```
const char* OH_UdsHtml_GetType (OH_UdsHtml* pThis)
```

**Description**

Obtains the type ID from an [OH_UdsHtml](#oh_udshtml) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdsHtml](#oh_udshtml) instance.|

**Returns**

Returns a pointer to the type ID obtained if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdsHtml](#oh_udshtml)


### OH_UdsHtml_SetContent()

```
int OH_UdsHtml_SetContent (OH_UdsHtml* pThis, const char* content )
```

**Description**

Sets the HTML content for an [OH_UdsHtml](#oh_udshtml) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdsHtml](#oh_udshtml) instance.|
| content | Pointer to the content in HTML format to set.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdsHtml](#oh_udshtml)


### OH_UdsHtml_SetPlainContent()

```
int OH_UdsHtml_SetPlainContent (OH_UdsHtml* pThis, const char* plainContent )
```

**Description**

Sets the plaintext for an [OH_UdsHtml](#oh_udshtml) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdsHtml](#oh_udshtml) instance.|
| plainContent | Pointer to the plain text content to set.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdsHtml](#oh_udshtml)


### OH_UdsHyperlink_Create()

```
OH_UdsHyperlink* OH_UdsHyperlink_Create ()
```

**Description**

Creates an [OH_UdsHyperlink](#oh_udshyperlink) instance and a pointer to it. If this pointer is no longer required, use [OH_UdsHyperlink_Destroy](#oh_udshyperlink_destroy) to destroy it. Otherwise, memory leaks may occur.

**Since**: 12

**Returns**

Returns a pointer to the [OH_UdsHyperlink](#oh_udshyperlink) instance created if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdsHyperlink](#oh_udshyperlink)


### OH_UdsHyperlink_Destroy()

```
void OH_UdsHyperlink_Destroy (OH_UdsHyperlink* pThis)
```

**Description**

Destroys an [OH_UdsHyperlink](#oh_udshyperlink) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdsHyperlink](#oh_udshyperlink) instance to destroy.|

**See**

[OH_UdsHyperlink](#oh_udshyperlink)


### OH_UdsHyperlink_GetDescription()

```
const char* OH_UdsHyperlink_GetDescription (OH_UdsHyperlink* pThis)
```

**Description**

Obtains the description from an [OH_UdsHyperlink](#oh_udshyperlink) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdsHyperlink](#oh_udshyperlink) instance.|

**Returns**

Returns a pointer to the description obtained if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdsHyperlink](#oh_udshyperlink)


### OH_UdsHyperlink_GetType()

```
const char* OH_UdsHyperlink_GetType (OH_UdsHyperlink* pThis)
```

**Description**

Obtains the type ID from an [OH_UdsHyperlink](#oh_udshyperlink) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdsHyperlink](#oh_udshyperlink) instance.|

**Returns**

Returns a pointer to the type ID obtained if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdsHyperlink](#oh_udshyperlink)


### OH_UdsHyperlink_GetUrl()

```
const char* OH_UdsHyperlink_GetUrl (OH_UdsHyperlink* pThis)
```

**Description**

Obtains the URL from an [OH_UdsHyperlink](#oh_udshyperlink) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdsHyperlink](#oh_udshyperlink) instance.|

**Returns**

Returns a pointer to the URL obtained if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdsHyperlink](#oh_udshyperlink)


### OH_UdsHyperlink_SetDescription()

```
int OH_UdsHyperlink_SetDescription (OH_UdsHyperlink* pThis, const char* description )
```

**Description**

Sets the description for an [OH_UdsHyperlink](#oh_udshyperlink) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdsHyperlink](#oh_udshyperlink) instance.|
| description | Pointer to the description to set.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdsHyperlink](#oh_udshyperlink)


### OH_UdsHyperlink_SetUrl()

```
int OH_UdsHyperlink_SetUrl (OH_UdsHyperlink* pThis, const char* url )
```

**Description**

Sets the URL for an [OH_UdsHyperlink](#oh_udshyperlink) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdsHyperlink](#oh_udshyperlink) instance.|
| url | Pointer to the URL to set.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdsHyperlink](#oh_udshyperlink)


### OH_UdsPixelMap_Create()

```
OH_UdsPixelMap* OH_UdsPixelMap_Create ()
```

**Description**

Creates an [OH_UdsPixelMap](#oh_udspixelmap) instance and a pointer to it. If this pointer is no longer required, use [OH_UdsPixelMap_Destroy](#oh_udspixelmap_destroy) to destroy it. Otherwise, memory leaks may occur.

**Since**: 13

**Returns**

Returns a pointer to the [OH_UdsPixelMap](#oh_udspixelmap) instance created if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdsPixelMap](#oh_udspixelmap)


### OH_UdsPixelMap_Destroy()

```
void OH_UdsPixelMap_Destroy (OH_UdsPixelMap* pThis)
```

**Description**

Destroys an [OH_UdsPixelMap](#oh_udspixelmap) instance.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdsPixelMap]( #oh_udspixelmap) instance to destroy.|

**See**

[OH_UdsPixelMap](#oh_udspixelmap)


### OH_UdsPixelMap_GetPixelMap()

```
void OH_UdsPixelMap_GetPixelMap (OH_UdsPixelMap* pThis, OH_PixelmapNative* pixelmapNative )
```

**Description**

Obtains the pointer to the **OH_PixelmapNative** instance from an [OH_UdsPixelMap](#oh_udspixelmap) instance.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the target [OH_UdsPixelMap]( #oh_udspixelmap) instance.|
| pixelmapNative | Pointer to the **OH_PixelmapNative** instance obtained.|

**See**

[OH_UdsPixelMap](#oh_udspixelmap)

OH_PixelmapNative


### OH_UdsPixelMap_GetType()

```
const char* OH_UdsPixelMap_GetType (OH_UdsPixelMap* pThis)
```

**Description**

Obtains the type ID from an [OH_UdsPixelMap](#oh_udspixelmap) instance.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the target [OH_UdsPixelMap]( #oh_udspixelmap) instance.|

**Returns**

Returns a pointer to the type ID obtained if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdsPixelMap](#oh_udspixelmap)


### OH_UdsPixelMap_SetPixelMap()

```
int OH_UdsPixelMap_SetPixelMap (OH_UdsPixelMap* pThis, OH_PixelmapNative* pixelmapNative )
```

**Description**

Sets the pixel map content for an [OH_UdsPixelMap](#oh_udspixelmap) instance.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the target [OH_UdsPixelMap]( #oh_udspixelmap) instance.|
| pixelmapNative | Pointer to the **OH_PixelmapNative** instance.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdsPixelMap](#oh_udspixelmap)

OH_PixelmapNative

[Udmf_ErrCode](#udmf_errcode)


### OH_UdsPlainText_Create()

```
OH_UdsPlainText* OH_UdsPlainText_Create ()
```

**Description**

Creates an [OH_UdsPlainText](#oh_udsplaintext) instance and a pointer to it. If this pointer is no longer required, use [OH_UdsPlainText_Destroy](#oh_udsplaintext_destroy) to destroy it. Otherwise, memory leaks may occur.

**Since**: 12

**Returns**

Returns a pointer to the [OH_UdsPlainText](#oh_udsplaintext) instance created if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdsPlainText](#oh_udsplaintext)


### OH_UdsPlainText_Destroy()

```
void OH_UdsPlainText_Destroy (OH_UdsPlainText* pThis)
```

**Description**

Destroys an [OH_UdsPlainText](#oh_udsplaintext) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdsPlainText](#oh_udsplaintext) instance to destroy.|

**See**

[OH_UdsPlainText](#oh_udsplaintext)


### OH_UdsPlainText_GetAbstract()

```
const char* OH_UdsPlainText_GetAbstract (OH_UdsPlainText* pThis)
```

**Description**

Obtains the abstract from an [OH_UdsPlainText](#oh_udsplaintext) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdsPlainText](#oh_udsplaintext) instance.|

**Returns**

Returns a pointer to the abstract information obtained if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdsPlainText](#oh_udsplaintext)


### OH_UdsPlainText_GetContent()

```
const char* OH_UdsPlainText_GetContent (OH_UdsPlainText* pThis)
```

**Description**

Obtains the plaintext from an [OH_UdsPlainText](#oh_udsplaintext) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdsPlainText](#oh_udsplaintext) instance.|

**Returns**

Returns a pointer to the plaintext obtained if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdsPlainText](#oh_udsplaintext)


### OH_UdsPlainText_GetType()

```
const char* OH_UdsPlainText_GetType (OH_UdsPlainText* pThis)
```

**Description**

Obtains the type ID from an [OH_UdsPlainText](#oh_udsplaintext) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdsPlainText](#oh_udsplaintext) instance.|

**Returns**

Returns a pointer to the type ID obtained if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_UdsPlainText](#oh_udsplaintext)


### OH_UdsPlainText_SetAbstract()

```
int OH_UdsPlainText_SetAbstract (OH_UdsPlainText* pThis, const char* abstract )
```

**Description**

Sets the abstract for an [OH_UdsPlainText](#oh_udsplaintext) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdsPlainText](#oh_udsplaintext) instance.|
| abstract | Pointer to the abstract to set.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdsPlainText](#oh_udsplaintext)


### OH_UdsPlainText_SetContent()

```
int OH_UdsPlainText_SetContent (OH_UdsPlainText* pThis, const char* content )
```

**Description**

Sets the plaintext content for an [OH_UdsPlainText](#oh_udsplaintext) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_UdsPlainText](#oh_udsplaintext) instance.|
| content | Pointer to the plaintext content to set.|

**Returns**

Returns a [Udmf_ErrCode](#udmf_errcode). <br>Returns **UDMF_E_OK** if the operation is successful. <br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.

**See**

[OH_UdsPlainText](#oh_udsplaintext)


### OH_Utd_BelongsTo()

```
bool OH_Utd_BelongsTo (const char* srcTypeId, const char* destTypeId )
```

**Description**

Checks whether a UTD belongs to the target UTD.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| srcTypeId | Pointer to the UTD to check. |
| destTypeId | Pointer to the target UTD.|

**Returns**

Returns **true** if the UTD belongs to the target UTD; returns **false** otherwise.


### OH_Utd_Create()

```
OH_Utd* OH_Utd_Create (const char* typeId)
```

**Description**

Creates an [OH_Utd](#oh_utd) instance and a pointer to it.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| typeId | Pointer to the type ID of the instance to create.|

**Returns**

Returns a pointer to the [OH_Utd](#oh_utd) instance created if the operation is successful; returns **nullptr** otherwise. If this pointer is no longer required, use [OH_Utd_Destroy](#oh_utd_destroy) to destroy it. Otherwise, memory leaks may occur.

**See**

[OH_Utd](#oh_utd)


### OH_Utd_Destroy()

```
void OH_Utd_Destroy (OH_Utd* pThis)
```

**Description**

Destroys an [OH_Utd](#oh_utd) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_Utd](#oh_utd) instance to destroy.|

**See**

[OH_Utd](#oh_utd)


### OH_Utd_DestroyStringList()

```
void OH_Utd_DestroyStringList (const char** list, unsigned int count )
```

**Description**

Destroys a UTD list.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| list | Double pointer to the UTD list to destroy.|
| count | Length of the UTD list.|


### OH_Utd_Equals()

```
bool OH_Utd_Equals (OH_Utd* utd1, OH_Utd* utd2 )
```

**Description**

Checks whether two UTDs are the same.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| desc1 | Pointer to one [OH_Utd](#oh_utd) instance to compare.|
| desc2 | Pointer to the other [OH_Utd](#oh_utd) instance to compare.|

**Returns**

Returns **true** if the two instances are the same; returns **false** otherwise.


### OH_Utd_GetBelongingToTypes()

```
const char** OH_Utd_GetBelongingToTypes (OH_Utd* pThis, unsigned int* count )
```

**Description**

Obtains the relationships between the data in an [OH_Utd](#oh_utd) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_Utd](#oh_utd) instance.|
| count | Pointer to the number of data types obtained.|

**Returns**

Returns a pointer to the relationship information obtained if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_Utd](#oh_utd)


### OH_Utd_GetDescription()

```
const char* OH_Utd_GetDescription (OH_Utd* pThis)
```

**Description**

Obtains the description from an [OH_Utd](#oh_utd) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_Utd](#oh_utd) instance.|

**Returns**

Returns a pointer to the description obtained if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_Utd](#oh_utd)


### OH_Utd_GetFilenameExtensions()

```
const char** OH_Utd_GetFilenameExtensions (OH_Utd* pThis, unsigned int* count )
```

**Description**

Obtains the file name extensions associated with an [OH_Utd](#oh_utd) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_Utd](#oh_utd) instance.|
| count | Pointer to the number of file name extensions obtained.|

**Returns**

Returns a pointer to the file name extensions obtained if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_Utd](#oh_utd)


### OH_Utd_GetIconFile()

```
const char* OH_Utd_GetIconFile (OH_Utd* pThis)
```

**Description**

Obtains the path of the default icon file from an [OH_Utd](#oh_utd) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_Utd](#oh_utd) instance.|

**Returns**

Returns a pointer to the path of the default icon file obtained if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_Utd](#oh_utd)


### OH_Utd_GetMimeTypes()

```
const char** OH_Utd_GetMimeTypes (OH_Utd* pThis, unsigned int* count )
```

**Description**

Obtains the MIME types associated with an [OH_Utd](#oh_utd) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_Utd](#oh_utd) instance.|
| count | Pointer to the number of MIME types obtained.|

**Returns**

Returns a pointer to the MIME types obtained if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_Utd](#oh_utd)


### OH_Utd_GetReferenceUrl()

```
const char* OH_Utd_GetReferenceUrl (OH_Utd* pThis)
```

**Description**

Obtains the URL from an [OH_Utd](#oh_utd) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_Utd](#oh_utd) instance.|

**Returns**

Returns a pointer to the URL obtained if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_Utd](#oh_utd)


### OH_Utd_GetTypeId()

```
const char* OH_Utd_GetTypeId (OH_Utd* pThis)
```

**Description**

Obtains the type ID from an [OH_Utd](#oh_utd) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pThis | Pointer to the [OH_Utd](#oh_utd) instance.|

**Returns**

Returns a pointer to the type ID obtained if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_Utd](#oh_utd)


### OH_Utd_GetTypesByFilenameExtension()

```
const char** OH_Utd_GetTypesByFilenameExtension (const char* extension, unsigned int* count )
```

**Description**

Obtains the uniform data types based on the file name extensions.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| extension | Pointer to the file name extensions.|
| count | Pointer to the number of data types obtained.|

**Returns**

Returns a pointer to the uniform data types obtained. If it is no longer required, use [OH_Utd_DestroyStringList](#oh_utd_destroystringlist) to destroy it. Otherwise, memory leakage occurs.


### OH_Utd_GetTypesByMimeType()

```
const char** OH_Utd_GetTypesByMimeType (const char* mimeType, unsigned int* count )
```

**Description**

Obtains the uniform data types based on the MIME types.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| mimeType | Pointer to the MIME types.|
| count | Pointer to the number of data types obtained.|

**Returns**

Returns a pointer to the uniform data types obtained. If it is no longer required, use [OH_Utd_DestroyStringList](#oh_utd_destroystringlist) to destroy it. Otherwise, memory leakage occurs.


### OH_Utd_IsHigher()

```
bool OH_Utd_IsHigher (const char* srcTypeId, const char* destTypeId )
```

**Description**

Checks whether a UTD is a higher-level type of the target UTD. For example, **SOURCE_CODE** is a higher-level type of **TYPE_SCRIPT**, and **PLAIN_TEXT** is a higher-level type of **SOURCE_CODE** and **TYPE_SCRIPT**.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| srcTypeId | Pointer to the UTD to check. |
| destTypeId | Pointer to the target UTD.|

**Returns**

Returns **true** if the UTD is a higher-level type of the target UTD; returns **false** otherwise.


### OH_Utd_IsLower()

```
bool OH_Utd_IsLower (const char* srcTypeId, const char* destTypeId )
```

**Description**

Checks whether a UTD is a lower-level type of the target UTD. For example, **TYPE_SCRIPT** is a lower-level type of **SOURCE_CODE**, and **TYPE_SCRIPT** and **SOURCE_CODE** are lower-level types of **PLAIN_TEXT**.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| srcTypeId | Pointer to the UTD to check. |
| destTypeId | Pointer to the target UTD.|

**Returns**

Returns **true** if the UTD is a lower-level type of the target UTD; returns **false** otherwise.
