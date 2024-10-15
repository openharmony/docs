# UDMF


## 概述

统一数据管理框架旨在定义数据跨应用、跨设备以及跨平台过程中的各项标准， 提供统一的OpenHarmony数据语言和标准化的数据接入与读取通路。

**起始版本：** 12

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [udmf.h](udmf_8h.md) | 提供访问统一数据管理框架数据的接口、数据结构、枚举类型。 引用文件：&lt;database/udmf/udmf.h&gt; | 
| [udmf_err_code.h](udmf__err__code_8h.md) | 声明统一数据管理框架错误码信息。 引用文件：&lt;database/udmf/udmf_err_code.h&gt; | 
| [udmf_meta.h](udmf__meta_8h.md) | 声明统一类型数据信息。 引用文件：&lt;database/udmf/udmf_meta.h&gt; | 
| [uds.h](uds_8h.md) | 提供标准化数据结构相关接口函数、结构体定义。 引用文件：&lt;database/udmf/uds.h&gt; | 
| [utd.h](utd_8h.md) | 提供标准化数据类型描述相关接口和数据结构。 引用文件：&lt;database/udmf/utd.h&gt; | 


### 宏定义

| 名称 | 描述 | 
| -------- | -------- |
| [UDMF_KEY_BUFFER_LEN](#udmf_key_buffer_len)   (512) | 统一数据对象唯一标识符最小空间长度。 | 
| [UDMF_META_ENTITY](#udmf_meta_entity)   "general.entity" | 所有表示物理存储类型的基类型，用于描述类型的物理属性，无归属类型。 | 
| [UDMF_META_OBJECT](#udmf_meta_object)   "general.object" | 所有表示逻辑内容类型的基类型，用于描述类型的功能性特征，无归属类型。 | 
| [UDMF_META_COMPOSITE_OBJECT](#udmf_meta_composite_object)   "general.composite-object" | 所有组合内容类型（例如PDF文件类型混合了文本和图片类数据）的基类型，归属类型为OBJECT。 | 
| [UDMF_META_TEXT](#udmf_meta_text)   "general.text" | 所有文本的基类型，归属类型为OBJECT。 | 
| [UDMF_META_PLAIN_TEXT](#udmf_meta_plain_text)   "general.plain-text" | 未指定编码的文本类型，没有标识符，归属类型为TEXT。 | 
| [UDMF_META_HTML](#udmf_meta_html)   "general.html" | HTML文本类型，归属类型为TEXT。 | 
| [UDMF_META_HYPERLINK](#udmf_meta_hyperlink)   "general.hyperlink" | 超链接类型，归属类型为TEXT。 | 
| [UDMF_META_XML](#udmf_meta_xml)   "general.xml" | XML文本类型，归属类型为TEXT。 | 
| [UDMF_META_SOURCE_CODE](#udmf_meta_source_code)   "general.source-code" | 所有源代码的基类型，归属类型为PLAIN_TEXT。 | 
| [UDMF_META_SCRIPT](#udmf_meta_script)   "general.script" | 所有脚本语言源代码的基类型，归属类型为SOURCE_CODE。 | 
| [UDMF_META_SHELL_SCRIPT](#udmf_meta_shell_script)   "general.shell-script" | Shell脚本类型，归属类型为SCRIPT。 | 
| [UDMF_META_CSH_SCRIPT](#udmf_meta_csh_script)   "general.csh-script" | C-shell脚本类型，归属类型为SHELL_SCRIPT。 | 
| [UDMF_META_PERL_SCRIPT](#udmf_meta_perl_script)   "general.perl-script" | Perl脚本类型，归属类型为SHELL_SCRIPT。 | 
| [UDMF_META_PHP_SCRIPT](#udmf_meta_php_script)   "general.php-script" | PHP脚本类型，归属类型为SHELL_SCRIPT。 | 
| [UDMF_META_PYTHON_SCRIPT](#udmf_meta_python_script)   "general.python-script" | Python脚本类型，归属类型为SHELL_SCRIPT。 | 
| [UDMF_META_RUBY_SCRIPT](#udmf_meta_ruby_script)   "general.ruby-script" | Ruby脚本类型，归属类型为SHELL_SCRIPT。 | 
| [UDMF_META_TYPE_SCRIPT](#udmf_meta_type_script)   "general.type-script" | TypeScript源代码类型，归属类型为SCRIPT。 | 
| [UDMF_META_JAVA_SCRIPT](#udmf_meta_java_script)   "general.java-script" | JavaScript源代码类型，归属类型为SCRIPT。 | 
| [UDMF_META_C_HEADER](#udmf_meta_c_header)   "general.c-header" | C头文件类型，归属类型为SOURCE_CODE。 | 
| [UDMF_META_C_SOURCE](#udmf_meta_c_source)   "general.c-source" | C源代码类型，归属类型为SOURCE_CODE。 | 
| [UDMF_META_C_PLUS_PLUS_HEADER](#udmf_meta_c_plus_plus_header)   "general.c-plus-plus-header" | C++头文件类型，归属类型为SOURCE_CODE。 | 
| [UDMF_META_C_PLUS_PLUS_SOURCE](#udmf_meta_c_plus_plus_source)   "general.c-plus-plus-source" | C++源代码类型，归属类型为SOURCE_CODE。 | 
| [UDMF_META_JAVA_SOURCE](#udmf_meta_java_source)   "general.java-source" | Java源代码类型，归属类型为SOURCE_CODE。 | 
| [UDMF_META_EBOOK](#udmf_meta_ebook)   "general.ebook" | 所有电子书文件格式的基类型，归属类型为COMPOSITE_OBJECT。 | 
| [UDMF_META_EPUB](#udmf_meta_epub)   "general.epub" | 电子出版物（EPUB）文件格式类型，归属类型为EBOOK。 | 
| [UDMF_META_AZW](#udmf_meta_azw)   "com.amazon.azw" | AZW电子书文件格式类型，归属类型为EBOOK。 | 
| [UDMF_META_AZW3](#udmf_meta_azw3)   "com.amazon.azw3" | AZW3电子书文件格式类型，归属类型为EBOOK。 | 
| [UDMF_META_KFX](#udmf_meta_kfx)   "com.amazon.kfx" | KFX电子书文件格式类型，归属类型为EBOOK。 | 
| [UDMF_META_MOBI](#udmf_meta_mobi)   "com.amazon.mobi" | MOBI电子书文件格式类型，归属类型为EBOOK。 | 
| [UDMF_META_MEDIA](#udmf_meta_media)   "general.media" | 所有媒体的基类型，归属类型为OBJECT。 | 
| [UDMF_META_IMAGE](#udmf_meta_image)   "general.image" | 所有图片的基类型，归属类型为MEDIA。 | 
| [UDMF_META_JPEG](#udmf_meta_jpeg)   "general.jpeg" | JPEG图片类型，归属类型为IMAGE。 | 
| [UDMF_META_PNG](#udmf_meta_png)   "general.png" | PNG图片类型，归属类型为IMAGE。 | 
| [UDMF_META_RAW_IMAGE](#udmf_meta_raw_image)   "general.raw-image" | 所有原始图像格式的基类型，归属类型为IMAGE。 | 
| [UDMF_META_TIFF](#udmf_meta_tiff)   "general.tiff" | TIFF图片类型，归属类型为IMAGE。 | 
| [UDMF_META_BMP](#udmf_meta_bmp)   "com.microsoft.bmp" | WINDOWS位图图像类型，归属类型为IMAGE。 | 
| [UDMF_META_ICO](#udmf_meta_ico)   "com.microsoft.ico" | WINDOWS图标图像类型，归属类型为IMAGE。 | 
| [UDMF_META_PHOTOSHOP_IMAGE](#udmf_meta_photoshop_image)   "com.adobe.photoshop-image" | Adobe Photoshop图片类型，归属类型为IMAGE。 | 
| [UDMF_META_AI_IMAGE](#udmf_meta_ai_image)   "com.adobe.illustrator.ai-image" | Adobe Illustrator图片类型，归属类型为IMAGE。 | 
| [UDMF_META_WORD_DOC](#udmf_meta_word_doc)   "com.microsoft.word.doc" | Microsoft Word数据类型，归属类型为COMPOSITE_OBJECT。 | 
| [UDMF_META_EXCEL](#udmf_meta_excel)   "com.microsoft.excel.xls" | Microsoft Excel数据类型，归属类型为COMPOSITE_OBJECT。 | 
| [UDMF_META_PPT](#udmf_meta_ppt)   "com.microsoft.powerpoint.ppt" | Microsoft PowerPoint演示文稿类型，归属类型为COMPOSITE_OBJECT。 | 
| [UDMF_META_PDF](#udmf_meta_pdf)   "com.adobe.pdf" | PDF数据类型，归属类型为COMPOSITE_OBJECT。 | 
| [UDMF_META_POSTSCRIPT](#udmf_meta_postscript)   "com.adobe.postscript" | PostScript数据类型，归属类型为COMPOSITE_OBJECT。 | 
| [UDMF_META_ENCAPSULATED_POSTSCRIPT](#udmf_meta_encapsulated_postscript)   "com.adobe.encapsulated-postscript" | Encapsulated PostScript类型，归属类型为POSTSCRIPT。 | 
| [UDMF_META_VIDEO](#udmf_meta_video)   "general.video" | 所有视频的基类型，归属类型为MEDIA。 | 
| [UDMF_META_AVI](#udmf_meta_avi)   "general.avi" | AVI视频类型，归属类型为VIDEO。 | 
| [UDMF_META_MPEG](#udmf_meta_mpeg)   "general.mpeg" | MPGE-1或MPGE-2视频类型，归属类型为VIDEO。 | 
| [UDMF_META_MPEG4](#udmf_meta_mpeg4)   "general.mpeg-4" | MPGE-4视频类型，归属类型为VIDEO。 | 
| [UDMF_META_VIDEO_3GPP](#udmf_meta_video_3gpp)   "general.3gpp" | 3GPP视频类型，归属类型为VIDEO。 | 
| [UDMF_META_VIDEO_3GPP2](#udmf_meta_video_3gpp2)   "general.3gpp2" | 3GPP2视频类型，归属类型为VIDEO。 | 
| [UDMF_META_WINDOWS_MEDIA_WM](#udmf_meta_windows_media_wm)   "com.microsoft.windows-media-wm" | WINDOWS WM视频类型，归属类型为VIDEO。 | 
| [UDMF_META_WINDOWS_MEDIA_WMV](#udmf_meta_windows_media_wmv)   "com.microsoft.windows-media-wmv" | WINDOWS WMV视频类型，归属类型为VIDEO。 | 
| [UDMF_META_WINDOWS_MEDIA_WMP](#udmf_meta_windows_media_wmp)   "com.microsoft.windows-media-wmp" | WINDOWS WMP视频类型，归属类型为VIDEO。 | 
| [UDMF_META_AUDIO](#udmf_meta_audio)   "general.audio" | 所有音频的基类型，归属类型为MEDIA | 
| [UDMF_META_AAC](#udmf_meta_aac)   "general.aac" | AAC音频类型，归属类型为AUDIO。 | 
| [UDMF_META_AIFF](#udmf_meta_aiff)   "general.aiff" | AIFF音频类型，归属类型为AUDIO。 | 
| [UDMF_META_ALAC](#udmf_meta_alac)   "general.alac" | ALAC音频类型，归属类型为AUDIO。 | 
| [UDMF_META_FLAC](#udmf_meta_flac)   "general.flac" | FLAC音频类型，归属类型为AUDIO。 | 
| [UDMF_META_MP3](#udmf_meta_mp3)   "general.mp3" | MP3音频类型，归属类型为AUDIO。 | 
| [UDMF_META_OGG](#udmf_meta_ogg)   "general.ogg" | OGG音频类型，归属类型为AUDIO。 | 
| [UDMF_META_PCM](#udmf_meta_pcm)   "general.pcm" | PCM音频类型，归属类型为AUDIO。 | 
| [UDMF_META_WINDOWS_MEDIA_WMA](#udmf_meta_windows_media_wma)   "com.microsoft.windows-media-wma" | WINDOWS WMA音频类型，归属类型为AUDIO。 | 
| [UDMF_META_WAVEFORM_AUDIO](#udmf_meta_waveform_audio)   "com.microsoft.waveform-audio" | WINDOWS波形音频类型，归属类型为AUDIO。 | 
| [UDMF_META_WINDOWS_MEDIA_WMX](#udmf_meta_windows_media_wmx)   "com.microsoft.windows-media-wmx" | WINDOWS WMX视频类型，归属类型为VIDEO。 | 
| [UDMF_META_WINDOWS_MEDIA_WVX](#udmf_meta_windows_media_wvx)   "com.microsoft.windows-media-wvx" | WINDOWS WVX视频类型，归属类型为VIDEO。 | 
| [UDMF_META_WINDOWS_MEDIA_WAX](#udmf_meta_windows_media_wax)   "com.microsoft.windows-media-wax" | WINDOWS WAX音频类型，归属类型为AUDIO。 | 
| [UDMF_META_GENERAL_FILE](#udmf_meta_general_file)   "general.file" | 所有文件的基类型，归属类型为ENTITY。 | 
| [UDMF_META_DIRECTORY](#udmf_meta_directory)   "general.directory" | 所有目录的基类型，归属类型为ENTITY。 | 
| [UDMF_META_FOLDER](#udmf_meta_folder)   "general.folder" | 所有文件夹的基类型，归属类型为DIRECTORY。 | 
| [UDMF_META_SYMLINK](#udmf_meta_symlink)   "general.symlink" | 所有符号链接的基类型，归属类型为ENTITY。 | 
| [UDMF_META_ARCHIVE](#udmf_meta_archive)   "general.archive" | 所有文件和目录存档文件的基类型，归属类型为OBJECT。 | 
| [UDMF_META_BZ2_ARCHIVE](#udmf_meta_bz2_archive)   "general.bz2-archive" | BZ2存档文件类型，归属类型为ARCHIVE。 | 
| [UDMF_META_DISK_IMAGE](#udmf_meta_disk_image)   "general.disk-image" | 所有可作为卷装载项的文件类型的基类型，归属类型为ARCHIVE。 | 
| [UDMF_META_TAR_ARCHIVE](#udmf_meta_tar_archive)   "general.tar-archive" | TAR存档文件类型，归属类型为ARCHIVE。 | 
| [UDMF_META_ZIP_ARCHIVE](#udmf_meta_zip_archive)   "general.zip-archive" | ZIP存档文件类型，归属类型为ARCHIVE。 | 
| [UDMF_META_JAVA_ARCHIVE](#udmf_meta_java_archive)   "com.sun.java-archive" | JAVA存档文件类型，归属类型为ARCHIVE和EXECUTABLE。 | 
| [UDMF_META_GNU_TAR_ARCHIVE](#udmf_meta_gnu_tar_archive)   "org.gnu.gnu-tar-archive" | GUN存档文件类型，归属类型为ARCHIVE。 | 
| [UDMF_META_GNU_ZIP_ARCHIVE](#udmf_meta_gnu_zip_archive)   "org.gnu.gnu-zip-archive" | GZIP存档文件类型，归属类型为ARCHIVE。 | 
| [UDMF_META_GNU_ZIP_TAR_ARCHIVE](#udmf_meta_gnu_zip_tar_archive)   "org.gnu.gnu-zip-tar-archive" | GZIP TAR存档文件类型，归属类型为ARCHIVE。 | 
| [UDMF_META_CALENDAR](#udmf_meta_calendar)   "general.calendar" | 所有日程类数据的基类型，归属类型为OBJECT。 | 
| [UDMF_META_CONTACT](#udmf_meta_contact)   "general.contact" | 所有联系人类数据的基类型，归属类型为OBJECT。 | 
| [UDMF_META_DATABASE](#udmf_meta_database)   "general.database" | 所有数据库文件的基类型，归属类型为OBJECT。 | 
| [UDMF_META_MESSAGE](#udmf_meta_message)   "general.message" | 所有消息类数据的基类型，归属类型为OBJECT。 | 
| [UDMF_META_VCARD](#udmf_meta_vcard)   "general.vcard" | 所有电子名片类数据的基类型，归属类型为OBJECT。 | 
| [UDMF_META_NAVIGATION](#udmf_meta_navigation)   "general.navigation" | 所有导航类数据的基类型，归属类型为OBJECT。 | 
| [UDMF_META_LOCATION](#udmf_meta_location)   "general.location" | 导航定位类型，归属类型为NAVIGATION。 | 
| [UDMF_META_OPENHARMONY_FORM](#udmf_meta_openharmony_form)   "openharmony.form" | 系统定义的卡片类型，归属类型为OBJECT。 | 
| [UDMF_META_OPENHARMONY_APP_ITEM](#udmf_meta_openharmony_app_item)   "openharmony.app-item" | 系统定义的桌面图标类型，归属类型为OBJECT。 | 
| [UDMF_META_OPENHARMONY_PIXEL_MAP](#udmf_meta_openharmony_pixel_map)   "openharmony.pixel-map" | 系统定义的像素图类型，归属类型为IMAGE。 | 
| [UDMF_META_OPENHARMONY_ATOMIC_SERVICE](#udmf_meta_openharmony_atomic_service)   "openharmony.atomic-service" | 系统定义的原子化服务类型，归属类型为OBJECT。 | 
| [UDMF_META_OPENHARMONY_PACKAGE](#udmf_meta_openharmony_package)   "openharmony.package" | 系统定义的包（即目录的打包文件），归属类型为DIRECTORY。 | 
| [UDMF_META_OPENHARMONY_HAP](#udmf_meta_openharmony_hap)   "openharmony.hap" | 系统定义的能力包，归属类型为OPENHARMONY_PACKAGE。 | 
| [UDMF_META_SMIL](#udmf_meta_smil)   "com.real.smil" | 同步多媒体集成语言类型，归属类型为XML文本类型。 | 
| [UDMF_META_MARKDOWN](#udmf_meta_markdown)   "general.markdown" | 标记语言文本类型，归属类型为PLAIN_TEXT。 | 
| [UDMF_META_FAX](#udmf_meta_fax)   "general.fax" | 传真图像的基本类型，归属类型为IMAGE。 | 
| [UDMF_META_JFX_FAX](#udmf_meta_jfx_fax)   "com.j2.jfx-fax" | J2 jConnect传真文件类型，归属类型为FAX。 | 
| [UDMF_META_EFX_FAX](#udmf_meta_efx_fax)   "com.js.efx-fax" | 电子传真文件类型，归属类型为FAX。 | 
| [UDMF_META_XBITMAP_IMAGE](#udmf_meta_xbitmap_image)   "general.xbitmap-image" | X Window系统（X11）中使用的位图图像格式，归属类型为IMAGE。 | 
| [UDMF_META_TGA_IMAGE](#udmf_meta_tga_image)   "com.truevision.tga-image" | 标签图形（TaggedGraphics）图像类型，归属类型为IMAGE。 | 
| [UDMF_META_SGI_IMAGE](#udmf_meta_sgi_image)   "com.sgi.sgi-image" | 硅图（Silicon Graphics）图像类型，归属类型为IMAGE。 | 
| [UDMF_META_OPENEXR_IMAGE](#udmf_meta_openexr_image)   "com.ilm.openexr-image" | 开放标准的高动态范围图像格式类型，归属类型为IMAGE。 | 
| [UDMF_META_FLASHPIX_IMAGE](#udmf_meta_flashpix_image)   "com.kodak.flashpix.image" | FlashPix图像文件类型，归属类型为IMAGE。 | 
| [UDMF_META_REALMEDIA](#udmf_meta_realmedia)   "com.real.realmedia" | 流媒体视频类型，归属类型为VIDEO。 | 
| [UDMF_META_AU_AUDIO](#udmf_meta_au_audio)   "general.au-audio" | Au数据格式，归属类型为AUDIO。 | 
| [UDMF_META_AIFC_AUDIO](#udmf_meta_aifc_audio)   "general.aifc-audio" | 音频交换数据类型，归属类型为AUDIO。 | 
| [UDMF_META_SD2_AUDIO](#udmf_meta_sd2_audio)   "com.digidesign.sd2-audio" | 单声道/立体声音频类型（Digidesign Sound Designer II），归属类型为AUDIO。 | 
| [UDMF_META_REALAUDIO](#udmf_meta_realaudio)   "com.real.realaudio" | RealMedia音频类型，归属类型为AUDIO。 | 
| [UDMF_META_OPENXML](#udmf_meta_openxml)   "org.openxmlformats.openxml" | 开源XML基类型，归属类型为ARCHIVE。 | 
| [UDMF_META_WORDPROCESSINGML_DOCUMENT](#udmf_meta_wordprocessingml_document)   "org.openxmlformats.wordprocessingml.document" | 开源XML文档类型，归属类型为OPENXML和COMPOSITE_OBJECT。 | 
| [UDMF_META_SPREADSHEETML_SHEET](#udmf_meta_spreadsheetml_sheet)   "org.openxmlformats.spreadsheetml.sheet" | 开源XML电子表格类型，归属类型为OPENXML和COMPOSITE_OBJECT。 | 
| [UDMF_META_PRESENTATIONML_PRESENTATION](#udmf_meta_presentationml_presentation)   "org.openxmlformats.presentationml.presentation" | 开源XML演示文稿类型，归属类型为OPENXML和COMPOSITE_OBJECT。 | 
| [UDMF_META_OPENDOCUMENT](#udmf_meta_opendocument)   "org.oasis.opendocument" | Office应用程序的开源文档类型，归属类型为ARCHIVE。 | 
| [UDMF_META_OPENDOCUMENT_TEXT](#udmf_meta_opendocument_text)   "org.oasis.opendocument.text" | 开源文档类型，归属类型为OPENDOCUMENT和COMPOSITE_OBJECT。 | 
| [UDMF_META_OPENDOCUMENT_SPREADSHEET](#udmf_meta_opendocument_spreadsheet)   "org.oasis.opendocument.spreadsheet" | 开源文档电子表格类型，归属类型为OPENDOCUMENT和COMPOSITE_OBJECT。 | 
| [UDMF_META_OPENDOCUMENT_PRESENTATION](#udmf_meta_opendocument_presentation)   "org.oasis.opendocument.presentation" | 开源文档演示类型，归属类型为OPENDOCUMENT和COMPOSITE_OBJECT。 | 
| [UDMF_META_OPENDOCUMENT_GRAPHICS](#udmf_meta_opendocument_graphics)   "org.oasis.opendocument.graphics" | 开源文档图形类型，归属类型为OPENDOCUMENT和COMPOSITE_OBJECT。 | 
| [UDMF_META_OPENDOCUMENT_FORMULA](#udmf_meta_opendocument_formula)   "org.oasis.opendocument.formula" | 开源文档公式集类型，归属类型为OPENDOCUMENT。 | 
| [UDMF_META_STUFFIT_ARCHIVE](#udmf_meta_stuffit_archive)   "com.allume.stuffit-archive" | Stuffit压缩格式类型（Stuffit archive），归属类型为ARCHIVE。 | 
| [UDMF_META_VCS](#udmf_meta_vcs)   "general.vcs" | VCalendar日历数据类型，归属类型为CALENDAR和TEXT。 | 
| [UDMF_META_ICS](#udmf_meta_ics)   "general.ics" | ICalendar日历数据类型，归属类型为CALENDAR和TEXT。 | 
| [UDMF_META_EXECUTABLE](#udmf_meta_executable)   "general.executable" | 所有可执行文件的基类型，归属类型为OBJECT。 | 
| [UDMF_META_PORTABLE_EXECUTABLE](#udmf_meta_portable_executable)   "com.microsoft.portable-executable" | Microsoft Windows应用程序类型，归属类型为EXECUTABLE。 | 
| [UDMF_META_SUN_JAVA_CLASS](#udmf_meta_sun_java_class)   "com.sun.java-class" | Java类文件类型，归属类型为EXECUTABLE。 | 
| [UDMF_META_FONT](#udmf_meta_font)   "general.font" | 所有字体数据类型的基础类型，归属类型为OBJECT。 | 
| [UDMF_META_TRUETYPE_FONT](#udmf_meta_truetype_font)   "general.truetype-font" | TrueType字体类型，归属类型为FONT。 | 
| [UDMF_META_TRUETYPE_COLLECTION_FONT](#udmf_meta_truetype_collection_font)   "general.truetype-collection-font" | TrueType collection字体类型，归属类型为FONT。 | 
| [UDMF_META_OPENTYPE_FONT](#udmf_meta_opentype_font)   "general.opentype-font" | OpenType字体类型，归属类型为FONT。 | 
| [UDMF_META_POSTSCRIPT_FONT](#udmf_meta_postscript_font)   "com.adobe.postscript-font" | PostScript字体类型，归属类型为FONT。 | 
| [UDMF_META_POSTSCRIPT_PFB_FONT](#udmf_meta_postscript_pfb_font)   "com.adobe.postscript-pfb-font" | PostScript Font Binary字体类型，归属类型为FONT。 | 
| [UDMF_META_POSTSCRIPT_PFA_FONT](#udmf_meta_postscript_pfa_font)   "com.adobe.postscript-pfa-font" | Adobe Type 1 字体类型，归属类型为FONT。 | 
| [UDMF_META_OPENHARMONY_HDOC](#udmf_meta_openharmony_hdoc)   "openharmony.hdoc" | 系统定义的备忘录数据类型，归属类型为COMPOSITE_OBJECT。 | 
| [UDMF_META_OPENHARMONY_HINOTE](#udmf_meta_openharmony_hinote)   "openharmony.hinote" | 系统定义的笔记数据类型，归属类型为COMPOSITE_OBJECT。 | 
| [UDMF_META_OPENHARMONY_STYLED_STRING](#udmf_meta_openharmony_styled_string)   "openharmony.styled-string" | 系统定义的样式字符串类型，归属类型为COMPOSITE_OBJECT。 | 
| [UDMF_META_OPENHARMONY_WANT](#udmf_meta_openharmony_want)   "openharmony.want" | 系统定义的Want类型，归属类型为OBJECT。 | 
| [UDMF_META_GENERAL_FILE_URI](#udmf_meta_general_file_uri)   "general.file-uri" | 文件地址类型，归属类型为TEXT。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [Udmf_Intention](#udmf_intention) [Udmf_Intention](#udmf_intention) | 描述UDMF数据通路枚举类型。 | 
| typedef enum [Udmf_ShareOption](#udmf_shareoption) [Udmf_ShareOption](#udmf_shareoption) | UDMF支持的设备内使用范围类型枚举。 | 
| typedef struct [OH_UdmfData](#oh_udmfdata) [OH_UdmfData](#oh_udmfdata) | 定义统一数据对象数据结构。 | 
| typedef struct [OH_UdmfRecord](#oh_udmfrecord) [OH_UdmfRecord](#oh_udmfrecord) | 定义统一数据对象中记录数据的数据结构，称为数据记录。 | 
| typedef struct [OH_UdmfRecordProvider](#oh_udmfrecordprovider) [OH_UdmfRecordProvider](#oh_udmfrecordprovider) | 定义统一数据对象中的数据提供者。 | 
| typedef struct [OH_UdmfProperty](#oh_udmfproperty) [OH_UdmfProperty](#oh_udmfproperty) | 定义统一数据对象中数据记录的属性结构。 | 
| typedef void(\* [UdmfData_Finalize](#udmfdata_finalize)) (void \*context) | 定义用于释放上下文的回调函数，统一数据提供者对象销毁时触发。 | 
| typedef void \*(\* [OH_UdmfRecordProvider_GetData](#oh_udmfrecordprovider_getdata)) (void \*context, const char \*type) | 定义用于按类型获取数据的回调函数。 当从OH_UdmfRecord中获取数据时，会触发此回调函数，得到的数据就是这个回调函数返回的数据。 | 
| typedef enum [Udmf_ErrCode](#udmf_errcode) [Udmf_ErrCode](#udmf_errcode) | 错误码信息。 | 
| typedef struct [OH_UdsPlainText](#oh_udsplaintext) [OH_UdsPlainText](#oh_udsplaintext) | 描述纯文本类型数据的统一数据结构。 | 
| typedef struct [OH_UdsHyperlink](#oh_udshyperlink) [OH_UdsHyperlink](#oh_udshyperlink) | 描述超链接类型的统一数据结构。 | 
| typedef struct [OH_UdsHtml](#oh_udshtml) [OH_UdsHtml](#oh_udshtml) | 描述超文本标记语言类型的统一数据结构。 | 
| typedef struct [OH_UdsAppItem](#oh_udsappitem) [OH_UdsAppItem](#oh_udsappitem) | 描述桌面图标类型的统一数据结构。 | 
| typedef struct [OH_UdsFileUri](#oh_udsfileuri) [OH_UdsFileUri](#oh_udsfileuri) | 描述文件Uri类型的统一数据结构。 | 
| typedef struct [OH_UdsPixelMap](#oh_udspixelmap) [OH_UdsPixelMap](#oh_udspixelmap) | 描述像素图片类型的统一数据结构。 | 
| typedef struct [OH_UdsArrayBuffer](#oh_udsarraybuffer) [OH_UdsArrayBuffer](#oh_udsarraybuffer) | 描述ArrayBuffer类型的统一数据结构。 | 
| typedef struct [OH_Utd](#oh_utd) [OH_Utd](#oh_utd) | 统一数据类型描述符。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [Udmf_Intention](#udmf_intention-1) { UDMF_INTENTION_DRAG, UDMF_INTENTION_PASTEBOARD } | 描述UDMF数据通路枚举类型。 | 
| [Udmf_ShareOption](#udmf_shareoption-1) { SHARE_OPTIONS_INVALID, SHARE_OPTIONS_IN_APP, SHARE_OPTIONS_CROSS_APP } | UDMF支持的设备内使用范围类型枚举。 | 
| [Udmf_ErrCode](#udmf_errcode-1) { UDMF_E_OK = 0, UDMF_ERR = 20400000, UDMF_E_INVALID_PARAM = (UDMF_ERR + 1) } | 错误码信息。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_UdmfData](#oh_udmfdata) \* [OH_UdmfData_Create](#oh_udmfdata_create) () | 创建统一数据对象[OH_UdmfData](#oh_udmfdata)指针及实例对象。 当不再需要使用指针时，请使用[OH_UdmfData_Destroy](#oh_udmfdata_destroy)销毁实例对象，否则会导致内存泄漏。 | 
| void [OH_UdmfData_Destroy](#oh_udmfdata_destroy) ([OH_UdmfData](#oh_udmfdata) \*pThis) | 销毁统一数据对象[OH_UdmfData](#oh_udmfdata)指针指向的实例对象。 | 
| int [OH_UdmfData_AddRecord](#oh_udmfdata_addrecord) ([OH_UdmfData](#oh_udmfdata) \*pThis, [OH_UdmfRecord](#oh_udmfrecord) \*record) | 添加一个数据记录[OH_UdmfRecord](#oh_udmfrecord)到统一数据对象[OH_UdmfData](#oh_udmfdata)中。 | 
| bool [OH_UdmfData_HasType](#oh_udmfdata_hastype) ([OH_UdmfData](#oh_udmfdata) \*pThis, const char \*type) | 检查统一数据对象[OH_UdmfData](#oh_udmfdata)中是否存在指定类型。 | 
| char \*\* [OH_UdmfData_GetTypes](#oh_udmfdata_gettypes) ([OH_UdmfData](#oh_udmfdata) \*pThis, unsigned int \*count) | 获取统一数据对象[OH_UdmfData](#oh_udmfdata)中包含的所有类型结果集。 | 
| [OH_UdmfRecord](#oh_udmfrecord) \*\* [OH_UdmfData_GetRecords](#oh_udmfdata_getrecords) ([OH_UdmfData](#oh_udmfdata) \*pThis, unsigned int \*count) | 获取统一数据对象[OH_UdmfData](#oh_udmfdata)中包含的所有记录结果集。 | 
| [OH_UdmfRecordProvider](#oh_udmfrecordprovider) \* [OH_UdmfRecordProvider_Create](#oh_udmfrecordprovider_create) () | 创建一个统一数据提供者[OH_UdmfRecordProvider](#oh_udmfrecordprovider)指针及实例对象。 当不再需要使用指针时，请使用[OH_UdmfRecordProvider_Destroy](#oh_udmfrecordprovider_destroy)销毁实例对象，否则会导致内存泄漏。 | 
| int [OH_UdmfRecordProvider_Destroy](#oh_udmfrecordprovider_destroy) ([OH_UdmfRecordProvider](#oh_udmfrecordprovider) \*provider) | 销毁统一数据提供者[OH_UdmfRecordProvider](#oh_udmfrecordprovider)指针指向的实例对象。 | 
| int [OH_UdmfRecordProvider_SetData](#oh_udmfrecordprovider_setdata) ([OH_UdmfRecordProvider](#oh_udmfrecordprovider) \*provider, void \*context, const [OH_UdmfRecordProvider_GetData](#oh_udmfrecordprovider_getdata) callback, const [UdmfData_Finalize](#udmfdata_finalize) finalize) | 设置统一数据提供者的数据提供回调函数。 | 
| [OH_UdmfRecord](#oh_udmfrecord) \* [OH_UdmfRecord_Create](#oh_udmfrecord_create) () | 创建统一数据记录[OH_UdmfRecord](#oh_udmfrecord)指针及实例对象。 当不再需要使用指针时，请使用[OH_UdmfRecord_Destroy](#oh_udmfrecord_destroy)销毁实例对象，否则会导致内存泄漏。 | 
| void [OH_UdmfRecord_Destroy](#oh_udmfrecord_destroy) ([OH_UdmfRecord](#oh_udmfrecord) \*pThis) | 销毁统一数据记录[OH_UdmfRecord](#oh_udmfrecord)指针指向的实例对象。 | 
| int [OH_UdmfRecord_AddGeneralEntry](#oh_udmfrecord_addgeneralentry) ([OH_UdmfRecord](#oh_udmfrecord) \*pThis, const char \*typeId, unsigned char \*entry, unsigned int count) | 添加用户自定义的通用数据至统一数据记录[OH_UdmfRecord](#oh_udmfrecord)中。 | 
| int [OH_UdmfRecord_AddPlainText](#oh_udmfrecord_addplaintext) ([OH_UdmfRecord](#oh_udmfrecord) \*pThis, [OH_UdsPlainText](#oh_udsplaintext) \*plainText) | 增加纯文本类型[OH_UdsPlainText](#oh_udsplaintext)数据至统一数据记录[OH_UdmfRecord](#oh_udmfrecord)中。 | 
| int [OH_UdmfRecord_AddHyperlink](#oh_udmfrecord_addhyperlink) ([OH_UdmfRecord](#oh_udmfrecord) \*pThis, [OH_UdsHyperlink](#oh_udshyperlink) \*hyperlink) | 增加超链接类型[OH_UdsHyperlink](#oh_udshyperlink)数据至统一数据记录[OH_UdmfRecord](#oh_udmfrecord)中。 | 
| int [OH_UdmfRecord_AddHtml](#oh_udmfrecord_addhtml) ([OH_UdmfRecord](#oh_udmfrecord) \*pThis, [OH_UdsHtml](#oh_udshtml) \*html) | 增加超文本标记语言类型[OH_UdsHtml](#oh_udshtml)数据至统一数据记录[OH_UdmfRecord](#oh_udmfrecord)中。 | 
| int [OH_UdmfRecord_AddAppItem](#oh_udmfrecord_addappitem) ([OH_UdmfRecord](#oh_udmfrecord) \*pThis, [OH_UdsAppItem](#oh_udsappitem) \*appItem) | 增加桌面图标类型[OH_UdsAppItem](#oh_udsappitem)数据至统一数据记录[OH_UdmfRecord](#oh_udmfrecord)中。 | 
| int [OH_UdmfRecord_AddFileUri](#oh_udmfrecord_addfileuri) ([OH_UdmfRecord](#oh_udmfrecord) \*pThis, [OH_UdsFileUri](#oh_udsfileuri) \*fileUri) | 增加文件Uri类型[OH_UdsFileUri](#oh_udsfileuri)数据至统一数据记录[OH_UdmfRecord](#oh_udmfrecord)中。 | 
| int [OH_UdmfRecord_AddPixelMap](#oh_udmfrecord_addpixelmap) ([OH_UdmfRecord](#oh_udmfrecord) \*pThis, [OH_UdsPixelMap](#oh_udspixelmap) \*pixelMap) | 增加像素图片类型[OH_UdsPixelMap](#oh_udspixelmap)数据至统一数据记录[OH_UdmfRecord](#oh_udmfrecord)中。 | 
| int [OH_UdmfRecord_AddArrayBuffer](#oh_udmfrecord_addarraybuffer) ([OH_UdmfRecord](#oh_udmfrecord) \*record, const char \*type, [OH_UdsArrayBuffer](#oh_udsarraybuffer) \*buffer) | 增加一个ArrayBuffer类型[OH_UdsArrayBuffer](#oh_udsarraybuffer)的数据至统一数据记录[OH_UdmfRecord](#oh_udmfrecord)中。 | 
| char \*\* [OH_UdmfRecord_GetTypes](#oh_udmfrecord_gettypes) ([OH_UdmfRecord](#oh_udmfrecord) \*pThis, unsigned int \*count) | 获取统一数据记录[OH_UdmfRecord](#oh_udmfrecord)中所有类型的结果集。 | 
| int [OH_UdmfRecord_GetGeneralEntry](#oh_udmfrecord_getgeneralentry) ([OH_UdmfRecord](#oh_udmfrecord) \*pThis, const char \*typeId, unsigned char \*\*entry, unsigned int \*count) | 获取统一数据记录[OH_UdmfRecord](#oh_udmfrecord)中的特定类型的数据结果集。 | 
| int [OH_UdmfRecord_GetPlainText](#oh_udmfrecord_getplaintext) ([OH_UdmfRecord](#oh_udmfrecord) \*pThis, [OH_UdsPlainText](#oh_udsplaintext) \*plainText) | 从统一数据记录[OH_UdmfRecord](#oh_udmfrecord)中获取纯文本类型[OH_UdsPlainText](#oh_udsplaintext)数据。 | 
| int [OH_UdmfRecord_GetHyperlink](#oh_udmfrecord_gethyperlink) ([OH_UdmfRecord](#oh_udmfrecord) \*pThis, [OH_UdsHyperlink](#oh_udshyperlink) \*hyperlink) | 从统一数据记录[OH_UdmfRecord](#oh_udmfrecord)中获取超链接类型[OH_UdsHyperlink](#oh_udshyperlink)数据。 | 
| int [OH_UdmfRecord_GetHtml](#oh_udmfrecord_gethtml) ([OH_UdmfRecord](#oh_udmfrecord) \*pThis, [OH_UdsHtml](#oh_udshtml) \*html) | 从统一数据记录[OH_UdmfRecord](#oh_udmfrecord)中获取超文本标记语言类型[OH_UdsHtml](#oh_udshtml)数据。 | 
| int [OH_UdmfRecord_GetAppItem](#oh_udmfrecord_getappitem) ([OH_UdmfRecord](#oh_udmfrecord) \*pThis, [OH_UdsAppItem](#oh_udsappitem) \*appItem) | 从统一数据记录[OH_UdmfRecord](#oh_udmfrecord)中获取桌面图标类型[OH_UdsAppItem](#oh_udsappitem)数据。 | 
| int [OH_UdmfRecord_SetProvider](#oh_udmfrecord_setprovider) ([OH_UdmfRecord](#oh_udmfrecord) \*pThis, const char \*const \*types, unsigned int count, [OH_UdmfRecordProvider](#oh_udmfrecordprovider) \*provider) | 将指定类型的统一数据提供者[OH_UdmfRecordProvider](#oh_udmfrecordprovider)设置至统一数据记录[OH_UdmfRecord](#oh_udmfrecord)中。 | 
| int [OH_UdmfRecord_GetFileUri](#oh_udmfrecord_getfileuri) ([OH_UdmfRecord](#oh_udmfrecord) \*pThis, [OH_UdsFileUri](#oh_udsfileuri) \*fileUri) | 从统一数据记录[OH_UdmfRecord](#oh_udmfrecord)中获取文件Uri类型[OH_UdsFileUri](#oh_udsfileuri)数据。 | 
| int [OH_UdmfRecord_GetPixelMap](#oh_udmfrecord_getpixelmap) ([OH_UdmfRecord](#oh_udmfrecord) \*pThis, [OH_UdsPixelMap](#oh_udspixelmap) \*pixelMap) | 从统一数据记录[OH_UdmfRecord](#oh_udmfrecord)中获取像素图片类型[OH_UdsPixelMap](#oh_udspixelmap)数据。 | 
| int [OH_UdmfRecord_GetArrayBuffer](#oh_udmfrecord_getarraybuffer) ([OH_UdmfRecord](#oh_udmfrecord) \*record, const char \*type, [OH_UdsArrayBuffer](#oh_udsarraybuffer) \*buffer) | 从统一数据记录[OH_UdmfRecord](#oh_udmfrecord)中获取ArrayBuffer类型[OH_UdsArrayBuffer](#oh_udsarraybuffer)数据。 | 
| int [OH_UdmfData_GetPrimaryPlainText](#oh_udmfdata_getprimaryplaintext) ([OH_UdmfData](#oh_udmfdata) \*data, [OH_UdsPlainText](#oh_udsplaintext) \*plainText) | 从统一数据对象[OH_UdmfData](#oh_udmfdata)中获取第一个纯文本类型[OH_UdsPlainText](#oh_udsplaintext)数据。 | 
| int [OH_UdmfData_GetPrimaryHtml](#oh_udmfdata_getprimaryhtml) ([OH_UdmfData](#oh_udmfdata) \*data, [OH_UdsHtml](#oh_udshtml) \*html) | 从统一数据对象[OH_UdmfData](#oh_udmfdata)中获取第一个超文本标记语言类型[OH_UdsHtml](#oh_udshtml)数据。 | 
| int [OH_UdmfData_GetRecordCount](#oh_udmfdata_getrecordcount) ([OH_UdmfData](#oh_udmfdata) \*data) | 获取统一数据对象[OH_UdmfData](#oh_udmfdata)中包含的所有记录数量。 | 
| [OH_UdmfRecord](#oh_udmfrecord) \* [OH_UdmfData_GetRecord](#oh_udmfdata_getrecord) ([OH_UdmfData](#oh_udmfdata) \*data, unsigned int index) | 获取统一数据对象[OH_UdmfData](#oh_udmfdata)中指定位置的数据记录。 | 
| bool [OH_UdmfData_IsLocal](#oh_udmfdata_islocal) ([OH_UdmfData](#oh_udmfdata) \*data) | 检查统一数据对象[OH_UdmfData](#oh_udmfdata)是否是来自本端设备的数据。 | 
| [OH_UdmfProperty](#oh_udmfproperty) \* [OH_UdmfProperty_Create](#oh_udmfproperty_create) ([OH_UdmfData](#oh_udmfdata) \*unifiedData) | 创建统一数据对象中数据记录属性[OH_UdmfProperty](#oh_udmfproperty)指针及实例对象。 当不再需要使用指针时，请使用[OH_UdmfProperty_Destroy](#oh_udmfproperty_destroy)销毁实例对象，否则会导致内存泄漏。 | 
| void [OH_UdmfProperty_Destroy](#oh_udmfproperty_destroy) ([OH_UdmfProperty](#oh_udmfproperty) \*pThis) | 销毁数据属性[OH_UdmfProperty](#oh_udmfproperty)指针指向的实例对象。 | 
| const char \* [OH_UdmfProperty_GetTag](#oh_udmfproperty_gettag) ([OH_UdmfProperty](#oh_udmfproperty) \*pThis) | 从数据属性[OH_UdmfProperty](#oh_udmfproperty)中获取用户自定义标签值。 | 
| int64_t [OH_UdmfProperty_GetTimestamp](#oh_udmfproperty_gettimestamp) ([OH_UdmfProperty](#oh_udmfproperty) \*pThis) | 从数据属性[OH_UdmfProperty](#oh_udmfproperty)中获取时间戳。 | 
| [Udmf_ShareOption](#udmf_shareoption)[OH_UdmfProperty_GetShareOption](#oh_udmfproperty_getshareoption) ([OH_UdmfProperty](#oh_udmfproperty) \*pThis) | 从数据属性[OH_UdmfProperty](#oh_udmfproperty)中获取设备内适用范围属性。 | 
| int [OH_UdmfProperty_GetExtrasIntParam](#oh_udmfproperty_getextrasintparam) ([OH_UdmfProperty](#oh_udmfproperty) \*pThis, const char \*key, int defaultValue) | 从数据属性[OH_UdmfProperty](#oh_udmfproperty)中获取自定义的附加整型参数。 | 
| const char \* [OH_UdmfProperty_GetExtrasStringParam](#oh_udmfproperty_getextrasstringparam) ([OH_UdmfProperty](#oh_udmfproperty) \*pThis, const char \*key) | 从数据属性[OH_UdmfProperty](#oh_udmfproperty)中获取自定义的附加字符串参数。 | 
| int [OH_UdmfProperty_SetTag](#oh_udmfproperty_settag) ([OH_UdmfProperty](#oh_udmfproperty) \*pThis, const char \*tag) | 设置数据属性[OH_UdmfProperty](#oh_udmfproperty)的自定义标签值。 | 
| int [OH_UdmfProperty_SetShareOption](#oh_udmfproperty_setshareoption) ([OH_UdmfProperty](#oh_udmfproperty) \*pThis, [Udmf_ShareOption](#udmf_shareoption) option) | 设置数据属性[OH_UdmfProperty](#oh_udmfproperty)的设备内适用范围**OH_Udmf_ShareOption**参数。 | 
| int [OH_UdmfProperty_SetExtrasIntParam](#oh_udmfproperty_setextrasintparam) ([OH_UdmfProperty](#oh_udmfproperty) \*pThis, const char \*key, int param) | 设置数据属性[OH_UdmfProperty](#oh_udmfproperty)的附加整型参数。 | 
| int [OH_UdmfProperty_SetExtrasStringParam](#oh_udmfproperty_setextrasstringparam) ([OH_UdmfProperty](#oh_udmfproperty) \*pThis, const char \*key, const char \*param) | 设置数据属性[OH_UdmfProperty](#oh_udmfproperty)的附加字符串参数。 | 
| int [OH_Udmf_GetUnifiedData](#oh_udmf_getunifieddata) (const char \*key, [Udmf_Intention](#udmf_intention) intention, [OH_UdmfData](#oh_udmfdata) \*unifiedData) | 从统一数据管理框架数据库中获取统一数据对象[OH_UdmfData](#oh_udmfdata)数据。 | 
| int [OH_Udmf_SetUnifiedData](#oh_udmf_setunifieddata) ([Udmf_Intention](#udmf_intention) intention, [OH_UdmfData](#oh_udmfdata) \*unifiedData, char \*key, unsigned int keyLen) | 从统一数据管理框架数据库中写入统一数据对象[OH_UdmfData](#oh_udmfdata)数据。 | 
| [OH_UdsPlainText](#oh_udsplaintext) \* [OH_UdsPlainText_Create](#oh_udsplaintext_create) () | 创建纯文本类型[OH_UdsPlainText](#oh_udsplaintext)指针及实例对象。 当不再需要使用指针时，请使用[OH_UdsPlainText_Destroy](#oh_udsplaintext_destroy)销毁实例对象，否则会导致内存泄漏。 | 
| void [OH_UdsPlainText_Destroy](#oh_udsplaintext_destroy) ([OH_UdsPlainText](#oh_udsplaintext) \*pThis) | 销毁纯文本类型数据[OH_UdsPlainText](#oh_udsplaintext)指针指向的实例对象。 | 
| const char \* [OH_UdsPlainText_GetType](#oh_udsplaintext_gettype) ([OH_UdsPlainText](#oh_udsplaintext) \*pThis) | 从纯文本类型[OH_UdsPlainText](#oh_udsplaintext)中获取类型ID。 | 
| const char \* [OH_UdsPlainText_GetContent](#oh_udsplaintext_getcontent) ([OH_UdsPlainText](#oh_udsplaintext) \*pThis) | 从纯文本类型[OH_UdsPlainText](#oh_udsplaintext)中获取纯文本内容信息。 | 
| const char \* [OH_UdsPlainText_GetAbstract](#oh_udsplaintext_getabstract) ([OH_UdsPlainText](#oh_udsplaintext) \*pThis) | 从纯文本类型[OH_UdsPlainText](#oh_udsplaintext)中获取纯文本摘要信息。 | 
| int [OH_UdsPlainText_SetContent](#oh_udsplaintext_setcontent) ([OH_UdsPlainText](#oh_udsplaintext) \*pThis, const char \*content) | 设置纯文本类型[OH_UdsPlainText](#oh_udsplaintext)中的纯文本内容参数。 | 
| int [OH_UdsPlainText_SetAbstract](#oh_udsplaintext_setabstract) ([OH_UdsPlainText](#oh_udsplaintext) \*pThis, const char \*abstract) | 设置纯文本类型[OH_UdsPlainText](#oh_udsplaintext)中的纯文本摘要参数。 | 
| [OH_UdsHyperlink](#oh_udshyperlink) \* [OH_UdsHyperlink_Create](#oh_udshyperlink_create) () | 创建超链接类型[OH_UdsHyperlink](#oh_udshyperlink)指针及实例对象。 当不再需要使用指针时，请使用[OH_UdsHyperlink_Destroy](#oh_udshyperlink_destroy)销毁实例对象，否则会导致内存泄漏。 | 
| void [OH_UdsHyperlink_Destroy](#oh_udshyperlink_destroy) ([OH_UdsHyperlink](#oh_udshyperlink) \*pThis) | 销毁超链接类型[OH_UdsHyperlink](#oh_udshyperlink)指针指向的实例对象。 | 
| const char \* [OH_UdsHyperlink_GetType](#oh_udshyperlink_gettype) ([OH_UdsHyperlink](#oh_udshyperlink) \*pThis) | 从超链接类型[OH_UdsHyperlink](#oh_udshyperlink)中获取类型ID。 | 
| const char \* [OH_UdsHyperlink_GetUrl](#oh_udshyperlink_geturl) ([OH_UdsHyperlink](#oh_udshyperlink) \*pThis) | 从超链接类型[OH_UdsHyperlink](#oh_udshyperlink)中获取URL参数。 | 
| const char \* [OH_UdsHyperlink_GetDescription](#oh_udshyperlink_getdescription) ([OH_UdsHyperlink](#oh_udshyperlink) \*pThis) | 从超链接类型[OH_UdsHyperlink](#oh_udshyperlink)中获取描述参数。 | 
| int [OH_UdsHyperlink_SetUrl](#oh_udshyperlink_seturl) ([OH_UdsHyperlink](#oh_udshyperlink) \*pThis, const char \*url) | 设置超链接类型[OH_UdsHyperlink](#oh_udshyperlink)实例中URL参数。 | 
| int [OH_UdsHyperlink_SetDescription](#oh_udshyperlink_setdescription) ([OH_UdsHyperlink](#oh_udshyperlink) \*pThis, const char \*description) | 设置超链接类型[OH_UdsHyperlink](#oh_udshyperlink)实例中描述参数。 | 
| [OH_UdsHtml](#oh_udshtml) \* [OH_UdsHtml_Create](#oh_udshtml_create) () | 创建超文本标记语言类型[OH_UdsHtml](#oh_udshtml)指针及实例对象。 当不再需要使用指针时，请使用[OH_UdsHtml_Destroy](#oh_udshtml_destroy)销毁实例对象，否则会导致内存泄漏。 | 
| void [OH_UdsHtml_Destroy](#oh_udshtml_destroy) ([OH_UdsHtml](#oh_udshtml) \*pThis) | 销毁超文本标记语言类型[OH_UdsHtml](#oh_udshtml)指针指向的实例对象。 | 
| const char \* [OH_UdsHtml_GetType](#oh_udshtml_gettype) ([OH_UdsHtml](#oh_udshtml) \*pThis) | 获取超文本标记语言类型[OH_UdsHtml](#oh_udshtml)对象中类型ID。 | 
| const char \* [OH_UdsHtml_GetContent](#oh_udshtml_getcontent) ([OH_UdsHtml](#oh_udshtml) \*pThis) | 获取超文本标记语言类型[OH_UdsHtml](#oh_udshtml)对象中HTML格式内容参数。 | 
| const char \* [OH_UdsHtml_GetPlainContent](#oh_udshtml_getplaincontent) ([OH_UdsHtml](#oh_udshtml) \*pThis) | 获取超文本标记语言类型[OH_UdsHtml](#oh_udshtml)对象中的纯文本内容参数。 | 
| int [OH_UdsHtml_SetContent](#oh_udshtml_setcontent) ([OH_UdsHtml](#oh_udshtml) \*pThis, const char \*content) | 设置超文本标记语言类型[OH_UdsHtml](#oh_udshtml)中的HTML格式内容参数。 | 
| int [OH_UdsHtml_SetPlainContent](#oh_udshtml_setplaincontent) ([OH_UdsHtml](#oh_udshtml) \*pThis, const char \*plainContent) | 设置超文本标记语言类型[OH_UdsHtml](#oh_udshtml)中的纯文本内容参数。 | 
| [OH_UdsAppItem](#oh_udsappitem) \* [OH_UdsAppItem_Create](#oh_udsappitem_create) () | 创建桌面图标类型[OH_UdsAppItem](#oh_udsappitem)指针及实例对象。 当不再需要使用指针时，请使用[OH_UdsAppItem_Destroy](#oh_udsappitem_destroy)销毁实例对象，否则会导致内存泄漏。 | 
| void [OH_UdsAppItem_Destroy](#oh_udsappitem_destroy) ([OH_UdsAppItem](#oh_udsappitem) \*pThis) | 销毁桌面图标类型[OH_UdsAppItem](#oh_udsappitem)指针指向的实例对象。 | 
| const char \* [OH_UdsAppItem_GetType](#oh_udsappitem_gettype) ([OH_UdsAppItem](#oh_udsappitem) \*pThis) | 从桌面图标类型[OH_UdsAppItem](#oh_udsappitem)实例获取类型ID。 | 
| const char \* [OH_UdsAppItem_GetId](#oh_udsappitem_getid) ([OH_UdsAppItem](#oh_udsappitem) \*pThis) | 从桌面图标类型[OH_UdsAppItem](#oh_udsappitem)实例中获取应用ID。 | 
| const char \* [OH_UdsAppItem_GetName](#oh_udsappitem_getname) ([OH_UdsAppItem](#oh_udsappitem) \*pThis) | 从桌面图标类型[OH_UdsAppItem](#oh_udsappitem)实例中获取应用名称。 | 
| const char \* [OH_UdsAppItem_GetIconId](#oh_udsappitem_geticonid) ([OH_UdsAppItem](#oh_udsappitem) \*pThis) | 从桌面图标类型[OH_UdsAppItem](#oh_udsappitem)实例中获取图片ID。 | 
| const char \* [OH_UdsAppItem_GetLabelId](#oh_udsappitem_getlabelid) ([OH_UdsAppItem](#oh_udsappitem) \*pThis) | 从桌面图标类型[OH_UdsAppItem](#oh_udsappitem)实例中获取标签ID。 | 
| const char \* [OH_UdsAppItem_GetBundleName](#oh_udsappitem_getbundlename) ([OH_UdsAppItem](#oh_udsappitem) \*pThis) | 从桌面图标类型[OH_UdsAppItem](#oh_udsappitem)实例中获取bundle名称。 | 
| const char \* [OH_UdsAppItem_GetAbilityName](#oh_udsappitem_getabilityname) ([OH_UdsAppItem](#oh_udsappitem) \*pThis) | 从桌面图标类型[OH_UdsAppItem](#oh_udsappitem)实例中ability名称。 | 
| int [OH_UdsAppItem_SetId](#oh_udsappitem_setid) ([OH_UdsAppItem](#oh_udsappitem) \*pThis, const char \*appId) | 设置桌面图标类型[OH_UdsAppItem](#oh_udsappitem)对象的应用ID。 | 
| int [OH_UdsAppItem_SetName](#oh_udsappitem_setname) ([OH_UdsAppItem](#oh_udsappitem) \*pThis, const char \*appName) | 设置桌面图标类型[OH_UdsAppItem](#oh_udsappitem)对象的应用名称。 | 
| int [OH_UdsAppItem_SetIconId](#oh_udsappitem_seticonid) ([OH_UdsAppItem](#oh_udsappitem) \*pThis, const char \*appIconId) | 设置桌面图标类型[OH_UdsAppItem](#oh_udsappitem)对象的图片ID。 | 
| int [OH_UdsAppItem_SetLabelId](#oh_udsappitem_setlabelid) ([OH_UdsAppItem](#oh_udsappitem) \*pThis, const char \*appLabelId) | 设置桌面图标类型[OH_UdsAppItem](#oh_udsappitem)对象的标签ID。 | 
| int [OH_UdsAppItem_SetBundleName](#oh_udsappitem_setbundlename) ([OH_UdsAppItem](#oh_udsappitem) \*pThis, const char \*bundleName) | 设置桌面图标类型[OH_UdsAppItem](#oh_udsappitem)对象的bundle名称。 | 
| int [OH_UdsAppItem_SetAbilityName](#oh_udsappitem_setabilityname) ([OH_UdsAppItem](#oh_udsappitem) \*pThis, const char \*abilityName) | 设置桌面图标类型[OH_UdsAppItem](#oh_udsappitem)对象的ability名称。 | 
| [OH_UdsFileUri](#oh_udsfileuri) \* [OH_UdsFileUri_Create](#oh_udsfileuri_create) () | 创建文件Uri类型[OH_UdsFileUri](#oh_udsfileuri)的实例对象以及指向它的指针。 当不再需要使用指针时，请使用[OH_UdsFileUri_Destroy](#oh_udsfileuri_destroy)销毁实例对象，否则会导致内存泄漏。 | 
| void [OH_UdsFileUri_Destroy](#oh_udsfileuri_destroy) ([OH_UdsFileUri](#oh_udsfileuri) \*pThis) | 销毁文件Uri类型[OH_UdsFileUri](#oh_udsfileuri)的实例对象。 | 
| const char \* [OH_UdsFileUri_GetType](#oh_udsfileuri_gettype) ([OH_UdsFileUri](#oh_udsfileuri) \*pThis) | 从文件Uri类型[OH_UdsFileUri](#oh_udsfileuri)实例中获取类型ID。 | 
| const char \* [OH_UdsFileUri_GetFileUri](#oh_udsfileuri_getfileuri) ([OH_UdsFileUri](#oh_udsfileuri) \*pThis) | 从文件Uri类型[OH_UdsFileUri](#oh_udsfileuri)实例中获取文件Uri。 | 
| const char \* [OH_UdsFileUri_GetFileType](#oh_udsfileuri_getfiletype) ([OH_UdsFileUri](#oh_udsfileuri) \*pThis) | 从文件Uri类型[OH_UdsFileUri](#oh_udsfileuri)实例中获取文件类型。 | 
| int [OH_UdsFileUri_SetFileUri](#oh_udsfileuri_setfileuri) ([OH_UdsFileUri](#oh_udsfileuri) \*pThis, const char \*fileUri) | 设置文件Uri类型[OH_UdsFileUri](#oh_udsfileuri)对象的Uri信息。 | 
| int [OH_UdsFileUri_SetFileType](#oh_udsfileuri_setfiletype) ([OH_UdsFileUri](#oh_udsfileuri) \*pThis, const char \*fileType) | 设置文件Uri类型[OH_UdsFileUri](#oh_udsfileuri)对象的文件类型。 | 
| [OH_UdsPixelMap](#oh_udspixelmap) \* [OH_UdsPixelMap_Create](#oh_udspixelmap_create) () | 创建像素图片类型[OH_UdsPixelMap](#oh_udspixelmap)的实例对象以及指向它的指针。 当不再需要使用指针时，请使用[OH_UdsPixelMap_Destroy](#oh_udspixelmap_destroy)销毁实例对象，否则会导致内存泄漏。 | 
| void [OH_UdsPixelMap_Destroy](#oh_udspixelmap_destroy) ([OH_UdsPixelMap](#oh_udspixelmap) \*pThis) | 销毁像素图片类型[OH_UdsPixelMap](#oh_udspixelmap)的实例对象。 | 
| const char \* [OH_UdsPixelMap_GetType](#oh_udspixelmap_gettype) ([OH_UdsPixelMap](#oh_udspixelmap) \*pThis) | 从像素图片类型[OH_UdsPixelMap](#oh_udspixelmap)实例中获取类型ID。 | 
| void [OH_UdsPixelMap_GetPixelMap](#oh_udspixelmap_getpixelmap) ([OH_UdsPixelMap](#oh_udspixelmap) \*pThis, OH_PixelmapNative \*pixelmapNative) | 从像素图片类型[OH_UdsPixelMap](#oh_udspixelmap)实例中获取像素图片**OH_PixelmapNative**实例的指针。 | 
| int [OH_UdsPixelMap_SetPixelMap](#oh_udspixelmap_setpixelmap) ([OH_UdsPixelMap](#oh_udspixelmap) \*pThis, OH_PixelmapNative \*pixelmapNative) | 设置像素图片类型[OH_UdsPixelMap](#oh_udspixelmap)对象的像素图片内容。 | 
| [OH_UdsArrayBuffer](#oh_udsarraybuffer) \* [OH_UdsArrayBuffer_Create](#oh_udsarraybuffer_create) () | 创建ArrayBuffer类型[OH_UdsArrayBuffer](#oh_udsarraybuffer)的实例对象以及指向它的指针。 当不再需要使用指针时，请使用[OH_UdsArrayBuffer_Destroy](#oh_udsarraybuffer_destroy)销毁实例对象，否则会导致内存泄漏。 | 
| int [OH_UdsArrayBuffer_Destroy](#oh_udsarraybuffer_destroy) ([OH_UdsArrayBuffer](#oh_udsarraybuffer) \*buffer) | 销毁ArrayBuffer类型[OH_UdsArrayBuffer](#oh_udsarraybuffer)的实例对象。 | 
| int [OH_UdsArrayBuffer_SetData](#oh_udsarraybuffer_setdata) ([OH_UdsArrayBuffer](#oh_udsarraybuffer) \*buffer, unsigned char \*data, unsigned int len) | 设置ArrayBuffer类型[OH_UdsArrayBuffer](#oh_udsarraybuffer)对象的数据内容。 | 
| int [OH_UdsArrayBuffer_GetData](#oh_udsarraybuffer_getdata) ([OH_UdsArrayBuffer](#oh_udsarraybuffer) \*buffer, unsigned char \*\*data, unsigned int \*len) | 从ArrayBuffer类型[OH_UdsArrayBuffer](#oh_udsarraybuffer)实例中获取用户自定义的ArrayBuffer数据内容。 | 
| [OH_Utd](#oh_utd) \* [OH_Utd_Create](#oh_utd_create) (const char \*typeId) | 创建统一数据类型[OH_Utd](#oh_utd)指针及实例对象。 | 
| void [OH_Utd_Destroy](#oh_utd_destroy) ([OH_Utd](#oh_utd) \*pThis) | 销毁统一数据类型[OH_Utd](#oh_utd)指针指向的实例对象。 | 
| const char \* [OH_Utd_GetTypeId](#oh_utd_gettypeid) ([OH_Utd](#oh_utd) \*pThis) | 获取统一数据类型[OH_Utd](#oh_utd)中的类型ID。 | 
| const char \* [OH_Utd_GetDescription](#oh_utd_getdescription) ([OH_Utd](#oh_utd) \*pThis) | 获取统一数据类型[OH_Utd](#oh_utd)中的描述信息。 | 
| const char \* [OH_Utd_GetReferenceUrl](#oh_utd_getreferenceurl) ([OH_Utd](#oh_utd) \*pThis) | 获取统一数据类型[OH_Utd](#oh_utd)中的URL信息。 | 
| const char \* [OH_Utd_GetIconFile](#oh_utd_geticonfile) ([OH_Utd](#oh_utd) \*pThis) | 获取统一数据类型[OH_Utd](#oh_utd)中的默认图标文件路径。 | 
| const char \*\* [OH_Utd_GetBelongingToTypes](#oh_utd_getbelongingtotypes) ([OH_Utd](#oh_utd) \*pThis, unsigned int \*count) | 获取统一数据类型[OH_Utd](#oh_utd)中的归属关系结果集。 | 
| const char \*\* [OH_Utd_GetFilenameExtensions](#oh_utd_getfilenameextensions) ([OH_Utd](#oh_utd) \*pThis, unsigned int \*count) | 获取统一数据类型[OH_Utd](#oh_utd)所关联的的文件名后缀结果集。 | 
| const char \*\* [OH_Utd_GetMimeTypes](#oh_utd_getmimetypes) ([OH_Utd](#oh_utd) \*pThis, unsigned int \*count) | 获取[OH_Utd](#oh_utd)所关联的MIME类型结果集。 | 
| const char \*\* [OH_Utd_GetTypesByFilenameExtension](#oh_utd_gettypesbyfilenameextension) (const char \*extension, unsigned int \*count) | 通过文件名后缀获取关联的统一标准数据描述类型结果集。 | 
| const char \*\* [OH_Utd_GetTypesByMimeType](#oh_utd_gettypesbymimetype) (const char \*mimeType, unsigned int \*count) | 通过MIME类型获取所关联的标准数据类型结果集。 | 
| bool [OH_Utd_BelongsTo](#oh_utd_belongsto) (const char \*srcTypeId, const char \*destTypeId) | 判断两个标准化数据描述类型是否存在归属关系。 | 
| bool [OH_Utd_IsLower](#oh_utd_islower) (const char \*srcTypeId, const char \*destTypeId) | 判断原标准化数据类型是否是目标标准化数据类型的低层级类型。 例如TYPE_SCRIPT为SOURCE_CODE的低层级类型，TYPE_SCRIPT和SOURCE_CODE为PLAIN_TEXT的低层级类型。 | 
| bool [OH_Utd_IsHigher](#oh_utd_ishigher) (const char \*srcTypeId, const char \*destTypeId) | 判断原标准化数据类型是否是目标标准化数据类型的高层级类型。 例如SOURCE_CODE为TYPE_SCRIPT的高层级类型，PLAIN_TEXT为SOURCE_CODE和TYPE_SCRIPT的高层级类型。 | 
| bool [OH_Utd_Equals](#oh_utd_equals) ([OH_Utd](#oh_utd) \*utd1, [OH_Utd](#oh_utd) \*utd2) | 判断两个标准化数据描述类型是否相等。 | 
| void [OH_Utd_DestroyStringList](#oh_utd_destroystringlist) (const char \*\*list, unsigned int count) | 销毁标准数据描述类型结果集字符串列表。 | 


## 宏定义说明


### UDMF_KEY_BUFFER_LEN

```
#define UDMF_KEY_BUFFER_LEN   (512)
```

**描述**

统一数据对象唯一标识符最小空间长度。

**起始版本：** 12


### UDMF_META_AAC

```
#define UDMF_META_AAC   "general.aac"
```

**描述**

AAC音频类型，归属类型为AUDIO。

**起始版本：** 12


### UDMF_META_AI_IMAGE

```
#define UDMF_META_AI_IMAGE   "com.adobe.illustrator.ai-image"
```

**描述**

Adobe Illustrator图片类型，归属类型为IMAGE。

**起始版本：** 12


### UDMF_META_AIFC_AUDIO

```
#define UDMF_META_AIFC_AUDIO   "general.aifc-audio"
```

**描述**

音频交换数据类型，归属类型为AUDIO。

**起始版本：** 12


### UDMF_META_AIFF

```
#define UDMF_META_AIFF   "general.aiff"
```

**描述**

AIFF音频类型，归属类型为AUDIO。

**起始版本：** 12


### UDMF_META_ALAC

```
#define UDMF_META_ALAC   "general.alac"
```

**描述**

ALAC音频类型，归属类型为AUDIO。

**起始版本：** 12


### UDMF_META_ARCHIVE

```
#define UDMF_META_ARCHIVE   "general.archive"
```

**描述**

所有文件和目录存档文件的基类型，归属类型为OBJECT。

**起始版本：** 12


### UDMF_META_AU_AUDIO

```
#define UDMF_META_AU_AUDIO   "general.au-audio"
```

**描述**

Au数据格式，归属类型为AUDIO。

**起始版本：** 12


### UDMF_META_AUDIO

```
#define UDMF_META_AUDIO   "general.audio"
```

**描述**

所有音频的基类型，归属类型为MEDIA

**起始版本：** 12


### UDMF_META_AVI

```
#define UDMF_META_AVI   "general.avi"
```

**描述**

AVI视频类型，归属类型为VIDEO。

**起始版本：** 12


### UDMF_META_AZW

```
#define UDMF_META_AZW   "com.amazon.azw"
```

**描述**

AZW电子书文件格式类型，归属类型为EBOOK。

**起始版本：** 12


### UDMF_META_AZW3

```
#define UDMF_META_AZW3   "com.amazon.azw3"
```

**描述**

AZW3电子书文件格式类型，归属类型为EBOOK。

**起始版本：** 12


### UDMF_META_BMP

```
#define UDMF_META_BMP   "com.microsoft.bmp"
```

**描述**

WINDOWS位图图像类型，归属类型为IMAGE。

**起始版本：** 12


### UDMF_META_BZ2_ARCHIVE

```
#define UDMF_META_BZ2_ARCHIVE   "general.bz2-archive"
```

**描述**

BZ2存档文件类型，归属类型为ARCHIVE。

**起始版本：** 12


### UDMF_META_C_HEADER

```
#define UDMF_META_C_HEADER   "general.c-header"
```

**描述**

C头文件类型，归属类型为SOURCE_CODE。

**起始版本：** 12


### UDMF_META_C_PLUS_PLUS_HEADER

```
#define UDMF_META_C_PLUS_PLUS_HEADER   "general.c-plus-plus-header"
```

**描述**

C++头文件类型，归属类型为SOURCE_CODE。

**起始版本：** 12


### UDMF_META_C_PLUS_PLUS_SOURCE

```
#define UDMF_META_C_PLUS_PLUS_SOURCE   "general.c-plus-plus-source"
```

**描述**

C++源代码类型，归属类型为SOURCE_CODE。

**起始版本：** 12


### UDMF_META_C_SOURCE

```
#define UDMF_META_C_SOURCE   "general.c-source"
```

**描述**

C源代码类型，归属类型为SOURCE_CODE。

**起始版本：** 12


### UDMF_META_CALENDAR

```
#define UDMF_META_CALENDAR   "general.calendar"
```

**描述**

所有日程类数据的基类型，归属类型为OBJECT。

**起始版本：** 12


### UDMF_META_COMPOSITE_OBJECT

```
#define UDMF_META_COMPOSITE_OBJECT   "general.composite-object"
```

**描述**

所有组合内容类型（例如PDF文件类型混合了文本和图片类数据）的基类型，归属类型为OBJECT。

**起始版本：** 12


### UDMF_META_CONTACT

```
#define UDMF_META_CONTACT   "general.contact"
```

**描述**

所有联系人类数据的基类型，归属类型为OBJECT。

**起始版本：** 12


### UDMF_META_CSH_SCRIPT

```
#define UDMF_META_CSH_SCRIPT   "general.csh-script"
```

**描述**

C-shell脚本类型，归属类型为SHELL_SCRIPT。

**起始版本：** 12


### UDMF_META_DATABASE

```
#define UDMF_META_DATABASE   "general.database"
```

**描述**

所有数据库文件的基类型，归属类型为OBJECT。

**起始版本：** 12


### UDMF_META_DIRECTORY

```
#define UDMF_META_DIRECTORY   "general.directory"
```

**描述**

所有目录的基类型，归属类型为ENTITY。

**起始版本：** 12


### UDMF_META_DISK_IMAGE

```
#define UDMF_META_DISK_IMAGE   "general.disk-image"
```

**描述**

所有可作为卷装载项的文件类型的基类型，归属类型为ARCHIVE。

**起始版本：** 12


### UDMF_META_EBOOK

```
#define UDMF_META_EBOOK   "general.ebook"
```

**描述**

所有电子书文件格式的基类型，归属类型为COMPOSITE_OBJECT。

**起始版本：** 12


### UDMF_META_EFX_FAX

```
#define UDMF_META_EFX_FAX   "com.js.efx-fax"
```

**描述**

电子传真文件类型，归属类型为FAX。

**起始版本：** 12


### UDMF_META_ENCAPSULATED_POSTSCRIPT

```
#define UDMF_META_ENCAPSULATED_POSTSCRIPT   "com.adobe.encapsulated-postscript"
```

**描述**

Encapsulated PostScript类型，归属类型为POSTSCRIPT。

**起始版本：** 12


### UDMF_META_ENTITY

```
#define UDMF_META_ENTITY   "general.entity"
```

**描述**

所有表示物理存储类型的基类型，用于描述类型的物理属性，无归属类型。

**起始版本：** 12


### UDMF_META_EPUB

```
#define UDMF_META_EPUB   "general.epub"
```

**描述**

电子出版物（EPUB）文件格式类型，归属类型为EBOOK。

**起始版本：** 12


### UDMF_META_EXCEL

```
#define UDMF_META_EXCEL   "com.microsoft.excel.xls"
```

**描述**

Microsoft Excel数据类型，归属类型为COMPOSITE_OBJECT。

**起始版本：** 12


### UDMF_META_EXECUTABLE

```
#define UDMF_META_EXECUTABLE   "general.executable"
```

**描述**

所有可执行文件的基类型，归属类型为OBJECT。

**起始版本：** 12


### UDMF_META_FAX

```
#define UDMF_META_FAX   "general.fax"
```

**描述**

传真图像的基本类型，归属类型为IMAGE。

**起始版本：** 12


### UDMF_META_FLAC

```
#define UDMF_META_FLAC   "general.flac"
```

**描述**

FLAC音频类型，归属类型为AUDIO。

**起始版本：** 12


### UDMF_META_FLASHPIX_IMAGE

```
#define UDMF_META_FLASHPIX_IMAGE   "com.kodak.flashpix.image"
```

**描述**

FlashPix图像文件类型，归属类型为IMAGE。

**起始版本：** 12


### UDMF_META_FOLDER

```
#define UDMF_META_FOLDER   "general.folder"
```

**描述**

所有文件夹的基类型，归属类型为DIRECTORY。

**起始版本：** 12


### UDMF_META_FONT

```
#define UDMF_META_FONT   "general.font"
```

**描述**

所有字体数据类型的基础类型，归属类型为OBJECT。

**起始版本：** 12


### UDMF_META_GENERAL_FILE

```
#define UDMF_META_GENERAL_FILE   "general.file"
```

**描述**

所有文件的基类型，归属类型为ENTITY。

**起始版本：** 12


### UDMF_META_GENERAL_FILE_URI

```
#define UDMF_META_GENERAL_FILE_URI   "general.file-uri"
```

**描述**

文件地址类型，归属类型为TEXT。

**起始版本：** 13


### UDMF_META_GNU_TAR_ARCHIVE

```
#define UDMF_META_GNU_TAR_ARCHIVE   "org.gnu.gnu-tar-archive"
```

**描述**

GUN存档文件类型，归属类型为ARCHIVE。

**起始版本：** 12


### UDMF_META_GNU_ZIP_ARCHIVE

```
#define UDMF_META_GNU_ZIP_ARCHIVE   "org.gnu.gnu-zip-archive"
```

**描述**

GZIP存档文件类型，归属类型为ARCHIVE。

**起始版本：** 12


### UDMF_META_GNU_ZIP_TAR_ARCHIVE

```
#define UDMF_META_GNU_ZIP_TAR_ARCHIVE   "org.gnu.gnu-zip-tar-archive"
```

**描述**

GZIP TAR存档文件类型，归属类型为ARCHIVE。

**起始版本：** 12


### UDMF_META_HTML

```
#define UDMF_META_HTML   "general.html"
```

**描述**

HTML文本类型，归属类型为TEXT。

**起始版本：** 12


### UDMF_META_HYPERLINK

```
#define UDMF_META_HYPERLINK   "general.hyperlink"
```

**描述**

超链接类型，归属类型为TEXT。

**起始版本：** 12


### UDMF_META_ICO

```
#define UDMF_META_ICO   "com.microsoft.ico"
```

**描述**

WINDOWS图标图像类型，归属类型为IMAGE。

**起始版本：** 12


### UDMF_META_ICS

```
#define UDMF_META_ICS   "general.ics"
```

**描述**

ICalendar日历数据类型，归属类型为CALENDAR和TEXT。

**起始版本：** 12


### UDMF_META_IMAGE

```
#define UDMF_META_IMAGE   "general.image"
```

**描述**

所有图片的基类型，归属类型为MEDIA。

**起始版本：** 12


### UDMF_META_JAVA_ARCHIVE

```
#define UDMF_META_JAVA_ARCHIVE   "com.sun.java-archive"
```

**描述**

JAVA存档文件类型，归属类型为ARCHIVE和EXECUTABLE。

**起始版本：** 12


### UDMF_META_JAVA_SCRIPT

```
#define UDMF_META_JAVA_SCRIPT   "general.java-script"
```

**描述**

JavaScript源代码类型，归属类型为SCRIPT。

**起始版本：** 12


### UDMF_META_JAVA_SOURCE

```
#define UDMF_META_JAVA_SOURCE   "general.java-source"
```

**描述**

Java源代码类型，归属类型为SOURCE_CODE。

**起始版本：** 12


### UDMF_META_JFX_FAX

```
#define UDMF_META_JFX_FAX   "com.j2.jfx-fax"
```

**描述**

J2 jConnect传真文件类型，归属类型为FAX。

**起始版本：** 12


### UDMF_META_JPEG

```
#define UDMF_META_JPEG   "general.jpeg"
```

**描述**

JPEG图片类型，归属类型为IMAGE。

**起始版本：** 12


### UDMF_META_KFX

```
#define UDMF_META_KFX   "com.amazon.kfx"
```

**描述**

KFX电子书文件格式类型，归属类型为EBOOK。

**起始版本：** 12


### UDMF_META_LOCATION

```
#define UDMF_META_LOCATION   "general.location"
```

**描述**

导航定位类型，归属类型为NAVIGATION。

**起始版本：** 12


### UDMF_META_MARKDOWN

```
#define UDMF_META_MARKDOWN   "general.markdown"
```

**描述**

标记语言文本类型，归属类型为PLAIN_TEXT。

**起始版本：** 12


### UDMF_META_MEDIA

```
#define UDMF_META_MEDIA   "general.media"
```

**描述**

所有媒体的基类型，归属类型为OBJECT。

**起始版本：** 12


### UDMF_META_MESSAGE

```
#define UDMF_META_MESSAGE   "general.message"
```

**描述**

所有消息类数据的基类型，归属类型为OBJECT。

**起始版本：** 12


### UDMF_META_MOBI

```
#define UDMF_META_MOBI   "com.amazon.mobi"
```

**描述**

MOBI电子书文件格式类型，归属类型为EBOOK。

**起始版本：** 12


### UDMF_META_MP3

```
#define UDMF_META_MP3   "general.mp3"
```

**描述**

MP3音频类型，归属类型为AUDIO。

**起始版本：** 12


### UDMF_META_MPEG

```
#define UDMF_META_MPEG   "general.mpeg"
```

**描述**

MPGE-1或MPGE-2视频类型，归属类型为VIDEO。

**起始版本：** 12


### UDMF_META_MPEG4

```
#define UDMF_META_MPEG4   "general.mpeg-4"
```

**描述**

MPGE-4视频类型，归属类型为VIDEO。

**起始版本：** 12


### UDMF_META_NAVIGATION

```
#define UDMF_META_NAVIGATION   "general.navigation"
```

**描述**

所有导航类数据的基类型，归属类型为OBJECT。

**起始版本：** 12


### UDMF_META_OBJECT

```
#define UDMF_META_OBJECT   "general.object"
```

**描述**

所有表示逻辑内容类型的基类型，用于描述类型的功能性特征，无归属类型。

**起始版本：** 12


### UDMF_META_OGG

```
#define UDMF_META_OGG   "general.ogg"
```

**描述**

OGG音频类型，归属类型为AUDIO。

**起始版本：** 12


### UDMF_META_OPENDOCUMENT

```
#define UDMF_META_OPENDOCUMENT   "org.oasis.opendocument"
```

**描述**

Office应用程序的开源文档类型，归属类型为ARCHIVE。

**起始版本：** 12


### UDMF_META_OPENDOCUMENT_FORMULA

```
#define UDMF_META_OPENDOCUMENT_FORMULA   "org.oasis.opendocument.formula"
```

**描述**

开源文档公式集类型，归属类型为OPENDOCUMENT。

**起始版本：** 12


### UDMF_META_OPENDOCUMENT_GRAPHICS

```
#define UDMF_META_OPENDOCUMENT_GRAPHICS   "org.oasis.opendocument.graphics"
```

**描述**

开源文档图形类型，归属类型为OPENDOCUMENT和COMPOSITE_OBJECT。

**起始版本：** 12


### UDMF_META_OPENDOCUMENT_PRESENTATION

```
#define UDMF_META_OPENDOCUMENT_PRESENTATION   "org.oasis.opendocument.presentation"
```

**描述**

开源文档演示类型，归属类型为OPENDOCUMENT和COMPOSITE_OBJECT。

**起始版本：** 12


### UDMF_META_OPENDOCUMENT_SPREADSHEET

```
#define UDMF_META_OPENDOCUMENT_SPREADSHEET   "org.oasis.opendocument.spreadsheet"
```

**描述**

开源文档电子表格类型，归属类型为OPENDOCUMENT和COMPOSITE_OBJECT。

**起始版本：** 12


### UDMF_META_OPENDOCUMENT_TEXT

```
#define UDMF_META_OPENDOCUMENT_TEXT   "org.oasis.opendocument.text"
```

**描述**

开源文档类型，归属类型为OPENDOCUMENT和COMPOSITE_OBJECT。

**起始版本：** 12


### UDMF_META_OPENEXR_IMAGE

```
#define UDMF_META_OPENEXR_IMAGE   "com.ilm.openexr-image"
```

**描述**

开放标准的高动态范围图像格式类型，归属类型为IMAGE。

**起始版本：** 12


### UDMF_META_OPENHARMONY_APP_ITEM

```
#define UDMF_META_OPENHARMONY_APP_ITEM   "openharmony.app-item"
```

**描述**

系统定义的桌面图标类型，归属类型为OBJECT。

**起始版本：** 12


### UDMF_META_OPENHARMONY_ATOMIC_SERVICE

```
#define UDMF_META_OPENHARMONY_ATOMIC_SERVICE   "openharmony.atomic-service"
```

**描述**

系统定义的原子化服务类型，归属类型为OBJECT。

**起始版本：** 12


### UDMF_META_OPENHARMONY_FORM

```
#define UDMF_META_OPENHARMONY_FORM   "openharmony.form"
```

**描述**

系统定义的卡片类型，归属类型为OBJECT。

**起始版本：** 12


### UDMF_META_OPENHARMONY_HAP

```
#define UDMF_META_OPENHARMONY_HAP   "openharmony.hap"
```

**描述**

系统定义的能力包，归属类型为OPENHARMONY_PACKAGE。

**起始版本：** 12


### UDMF_META_OPENHARMONY_HDOC

```
#define UDMF_META_OPENHARMONY_HDOC   "openharmony.hdoc"
```

**描述**

系统定义的备忘录数据类型，归属类型为COMPOSITE_OBJECT。

**起始版本：** 12


### UDMF_META_OPENHARMONY_HINOTE

```
#define UDMF_META_OPENHARMONY_HINOTE   "openharmony.hinote"
```

**描述**

系统定义的笔记数据类型，归属类型为COMPOSITE_OBJECT。

**起始版本：** 12


### UDMF_META_OPENHARMONY_PACKAGE

```
#define UDMF_META_OPENHARMONY_PACKAGE   "openharmony.package"
```

**描述**

系统定义的包（即目录的打包文件），归属类型为DIRECTORY。

**起始版本：** 12


### UDMF_META_OPENHARMONY_PIXEL_MAP

```
#define UDMF_META_OPENHARMONY_PIXEL_MAP   "openharmony.pixel-map"
```

**描述**

系统定义的像素图类型，归属类型为IMAGE。

**起始版本：** 12


### UDMF_META_OPENHARMONY_STYLED_STRING

```
#define UDMF_META_OPENHARMONY_STYLED_STRING   "openharmony.styled-string"
```

**描述**

系统定义的样式字符串类型，归属类型为COMPOSITE_OBJECT。

**起始版本：** 12


### UDMF_META_OPENHARMONY_WANT

```
#define UDMF_META_OPENHARMONY_WANT   "openharmony.want"
```

**描述**

系统定义的Want类型，归属类型为OBJECT。

**起始版本：** 12


### UDMF_META_OPENTYPE_FONT

```
#define UDMF_META_OPENTYPE_FONT   "general.opentype-font"
```

**描述**

OpenType字体类型，归属类型为FONT。

**起始版本：** 12


### UDMF_META_OPENXML

```
#define UDMF_META_OPENXML   "org.openxmlformats.openxml"
```

**描述**

开源XML基类型，归属类型为ARCHIVE。

**起始版本：** 12


### UDMF_META_PCM

```
#define UDMF_META_PCM   "general.pcm"
```

**描述**

PCM音频类型，归属类型为AUDIO。

**起始版本：** 12


### UDMF_META_PDF

```
#define UDMF_META_PDF   "com.adobe.pdf"
```

**描述**

PDF数据类型，归属类型为COMPOSITE_OBJECT。

**起始版本：** 12


### UDMF_META_PERL_SCRIPT

```
#define UDMF_META_PERL_SCRIPT   "general.perl-script"
```

**描述**

Perl脚本类型，归属类型为SHELL_SCRIPT。

**起始版本：** 12


### UDMF_META_PHOTOSHOP_IMAGE

```
#define UDMF_META_PHOTOSHOP_IMAGE   "com.adobe.photoshop-image"
```

**描述**

Adobe Photoshop图片类型，归属类型为IMAGE。

**起始版本：** 12


### UDMF_META_PHP_SCRIPT

```
#define UDMF_META_PHP_SCRIPT   "general.php-script"
```

**描述**

PHP脚本类型，归属类型为SHELL_SCRIPT。

**起始版本：** 12


### UDMF_META_PLAIN_TEXT

```
#define UDMF_META_PLAIN_TEXT   "general.plain-text"
```

**描述**

未指定编码的文本类型，没有标识符，归属类型为TEXT。

**起始版本：** 12


### UDMF_META_PNG

```
#define UDMF_META_PNG   "general.png"
```

**描述**

PNG图片类型，归属类型为IMAGE。

**起始版本：** 12


### UDMF_META_PORTABLE_EXECUTABLE

```
#define UDMF_META_PORTABLE_EXECUTABLE   "com.microsoft.portable-executable"
```

**描述**

Microsoft Windows应用程序类型，归属类型为EXECUTABLE。

**起始版本：** 12


### UDMF_META_POSTSCRIPT

```
#define UDMF_META_POSTSCRIPT   "com.adobe.postscript"
```

**描述**

PostScript数据类型，归属类型为COMPOSITE_OBJECT。

**起始版本：** 12


### UDMF_META_POSTSCRIPT_FONT

```
#define UDMF_META_POSTSCRIPT_FONT   "com.adobe.postscript-font"
```

**描述**

PostScript字体类型，归属类型为FONT。

**起始版本：** 12


### UDMF_META_POSTSCRIPT_PFA_FONT

```
#define UDMF_META_POSTSCRIPT_PFA_FONT   "com.adobe.postscript-pfa-font"
```

**描述**

Adobe Type 1 字体类型，归属类型为FONT。

**起始版本：** 12


### UDMF_META_POSTSCRIPT_PFB_FONT

```
#define UDMF_META_POSTSCRIPT_PFB_FONT   "com.adobe.postscript-pfb-font"
```

**描述**

PostScript Font Binary字体类型，归属类型为FONT。

**起始版本：** 12


### UDMF_META_PPT

```
#define UDMF_META_PPT   "com.microsoft.powerpoint.ppt"
```

**描述**

Microsoft PowerPoint演示文稿类型，归属类型为COMPOSITE_OBJECT。

**起始版本：** 12


### UDMF_META_PRESENTATIONML_PRESENTATION

```
#define UDMF_META_PRESENTATIONML_PRESENTATION   "org.openxmlformats.presentationml.presentation"
```

**描述**

开源XML演示文稿类型，归属类型为OPENXML和COMPOSITE_OBJECT。

**起始版本：** 12


### UDMF_META_PYTHON_SCRIPT

```
#define UDMF_META_PYTHON_SCRIPT   "general.python-script"
```

**描述**

Python脚本类型，归属类型为SHELL_SCRIPT。

**起始版本：** 12


### UDMF_META_RAW_IMAGE

```
#define UDMF_META_RAW_IMAGE   "general.raw-image"
```

**描述**

所有原始图像格式的基类型，归属类型为IMAGE。

**起始版本：** 12


### UDMF_META_REALAUDIO

```
#define UDMF_META_REALAUDIO   "com.real.realaudio"
```

**描述**

RealMedia音频类型，归属类型为AUDIO。

**起始版本：** 12


### UDMF_META_REALMEDIA

```
#define UDMF_META_REALMEDIA   "com.real.realmedia"
```

**描述**

流媒体视频类型，归属类型为VIDEO。

**起始版本：** 12


### UDMF_META_RUBY_SCRIPT

```
#define UDMF_META_RUBY_SCRIPT   "general.ruby-script"
```

**描述**

Ruby脚本类型，归属类型为SHELL_SCRIPT。

**起始版本：** 12


### UDMF_META_SCRIPT

```
#define UDMF_META_SCRIPT   "general.script"
```

**描述**

所有脚本语言源代码的基类型，归属类型为SOURCE_CODE。

**起始版本：** 12


### UDMF_META_SD2_AUDIO

```
#define UDMF_META_SD2_AUDIO   "com.digidesign.sd2-audio"
```

**描述**

单声道/立体声音频类型（Digidesign Sound Designer II），归属类型为AUDIO。

**起始版本：** 12


### UDMF_META_SGI_IMAGE

```
#define UDMF_META_SGI_IMAGE   "com.sgi.sgi-image"
```

**描述**

硅图（Silicon Graphics）图像类型，归属类型为IMAGE。

**起始版本：** 12


### UDMF_META_SHELL_SCRIPT

```
#define UDMF_META_SHELL_SCRIPT   "general.shell-script"
```

**描述**

Shell脚本类型，归属类型为SCRIPT。

**起始版本：** 12


### UDMF_META_SMIL

```
#define UDMF_META_SMIL   "com.real.smil"
```

**描述**

同步多媒体集成语言类型，归属类型为XML文本类型。

**起始版本：** 12


### UDMF_META_SOURCE_CODE

```
#define UDMF_META_SOURCE_CODE   "general.source-code"
```

**描述**

所有源代码的基类型，归属类型为PLAIN_TEXT。

**起始版本：** 12


### UDMF_META_SPREADSHEETML_SHEET

```
#define UDMF_META_SPREADSHEETML_SHEET   "org.openxmlformats.spreadsheetml.sheet"
```

**描述**

开源XML电子表格类型，归属类型为OPENXML和COMPOSITE_OBJECT。

**起始版本：** 12


### UDMF_META_STUFFIT_ARCHIVE

```
#define UDMF_META_STUFFIT_ARCHIVE   "com.allume.stuffit-archive"
```

**描述**

Stuffit压缩格式类型（Stuffit archive），归属类型为ARCHIVE。

**起始版本：** 12


### UDMF_META_SUN_JAVA_CLASS

```
#define UDMF_META_SUN_JAVA_CLASS   "com.sun.java-class"
```

**描述**

Java类文件类型，归属类型为EXECUTABLE。

**起始版本：** 12


### UDMF_META_SYMLINK

```
#define UDMF_META_SYMLINK   "general.symlink"
```

**描述**

所有符号链接的基类型，归属类型为ENTITY。

**起始版本：** 12


### UDMF_META_TAR_ARCHIVE

```
#define UDMF_META_TAR_ARCHIVE   "general.tar-archive"
```

**描述**

TAR存档文件类型，归属类型为ARCHIVE。

**起始版本：** 12


### UDMF_META_TEXT

```
#define UDMF_META_TEXT   "general.text"
```

**描述**

所有文本的基类型，归属类型为OBJECT。

**起始版本：** 12


### UDMF_META_TGA_IMAGE

```
#define UDMF_META_TGA_IMAGE   "com.truevision.tga-image"
```

**描述**

标签图形（TaggedGraphics）图像类型，归属类型为IMAGE。

**起始版本：** 12


### UDMF_META_TIFF

```
#define UDMF_META_TIFF   "general.tiff"
```

**描述**

TIFF图片类型，归属类型为IMAGE。

**起始版本：** 12


### UDMF_META_TRUETYPE_COLLECTION_FONT

```
#define UDMF_META_TRUETYPE_COLLECTION_FONT   "general.truetype-collection-font"
```

**描述**

TrueType collection字体类型，归属类型为FONT。

**起始版本：** 12


### UDMF_META_TRUETYPE_FONT

```
#define UDMF_META_TRUETYPE_FONT   "general.truetype-font"
```

**描述**

TrueType字体类型，归属类型为FONT。

**起始版本：** 12


### UDMF_META_TYPE_SCRIPT

```
#define UDMF_META_TYPE_SCRIPT   "general.type-script"
```

**描述**

TypeScript源代码类型，归属类型为SCRIPT。

**起始版本：** 12


### UDMF_META_VCARD

```
#define UDMF_META_VCARD   "general.vcard"
```

**描述**

所有电子名片类数据的基类型，归属类型为OBJECT。

**起始版本：** 12


### UDMF_META_VCS

```
#define UDMF_META_VCS   "general.vcs"
```

**描述**

VCalendar日历数据类型，归属类型为CALENDAR和TEXT。

**起始版本：** 12


### UDMF_META_VIDEO

```
#define UDMF_META_VIDEO   "general.video"
```

**描述**

所有视频的基类型，归属类型为MEDIA。

**起始版本：** 12


### UDMF_META_VIDEO_3GPP

```
#define UDMF_META_VIDEO_3GPP   "general.3gpp"
```

**描述**

3GPP视频类型，归属类型为VIDEO。

**起始版本：** 12


### UDMF_META_VIDEO_3GPP2

```
#define UDMF_META_VIDEO_3GPP2   "general.3gpp2"
```

**描述**

3GPP2视频类型，归属类型为VIDEO。

**起始版本：** 12


### UDMF_META_WAVEFORM_AUDIO

```
#define UDMF_META_WAVEFORM_AUDIO   "com.microsoft.waveform-audio"
```

**描述**

WINDOWS波形音频类型，归属类型为AUDIO。

**起始版本：** 12


### UDMF_META_WINDOWS_MEDIA_WAX

```
#define UDMF_META_WINDOWS_MEDIA_WAX   "com.microsoft.windows-media-wax"
```

**描述**

WINDOWS WAX音频类型，归属类型为AUDIO。

**起始版本：** 12


### UDMF_META_WINDOWS_MEDIA_WM

```
#define UDMF_META_WINDOWS_MEDIA_WM   "com.microsoft.windows-media-wm"
```

**描述**

WINDOWS WM视频类型，归属类型为VIDEO。

**起始版本：** 12


### UDMF_META_WINDOWS_MEDIA_WMA

```
#define UDMF_META_WINDOWS_MEDIA_WMA   "com.microsoft.windows-media-wma"
```

**描述**

WINDOWS WMA音频类型，归属类型为AUDIO。

**起始版本：** 12


### UDMF_META_WINDOWS_MEDIA_WMP

```
#define UDMF_META_WINDOWS_MEDIA_WMP   "com.microsoft.windows-media-wmp"
```

**描述**

WINDOWS WMP视频类型，归属类型为VIDEO。

**起始版本：** 12


### UDMF_META_WINDOWS_MEDIA_WMV

```
#define UDMF_META_WINDOWS_MEDIA_WMV   "com.microsoft.windows-media-wmv"
```

**描述**

WINDOWS WMV视频类型，归属类型为VIDEO。

**起始版本：** 12


### UDMF_META_WINDOWS_MEDIA_WMX

```
#define UDMF_META_WINDOWS_MEDIA_WMX   "com.microsoft.windows-media-wmx"
```

**描述**

WINDOWS WMX视频类型，归属类型为VIDEO。

**起始版本：** 12


### UDMF_META_WINDOWS_MEDIA_WVX

```
#define UDMF_META_WINDOWS_MEDIA_WVX   "com.microsoft.windows-media-wvx"
```

**描述**

WINDOWS WVX视频类型，归属类型为VIDEO。

**起始版本：** 12


### UDMF_META_WORD_DOC

```
#define UDMF_META_WORD_DOC   "com.microsoft.word.doc"
```

**描述**

Microsoft Word数据类型，归属类型为COMPOSITE_OBJECT。

**起始版本：** 12


### UDMF_META_WORDPROCESSINGML_DOCUMENT

```
#define UDMF_META_WORDPROCESSINGML_DOCUMENT   "org.openxmlformats.wordprocessingml.document"
```

**描述**

开源XML文档类型，归属类型为OPENXML和COMPOSITE_OBJECT。

**起始版本：** 12


### UDMF_META_XBITMAP_IMAGE

```
#define UDMF_META_XBITMAP_IMAGE   "general.xbitmap-image"
```

**描述**

X Window系统（X11）中使用的位图图像格式，归属类型为IMAGE。

**起始版本：** 12


### UDMF_META_XML

```
#define UDMF_META_XML   "general.xml"
```

**描述**

XML文本类型，归属类型为TEXT。

**起始版本：** 12


### UDMF_META_ZIP_ARCHIVE

```
#define UDMF_META_ZIP_ARCHIVE   "general.zip-archive"
```

**描述**

ZIP存档文件类型，归属类型为ARCHIVE。

**起始版本：** 12


## 类型定义说明


### OH_UdmfData

```
typedef struct OH_UdmfData OH_UdmfData
```

**描述**

定义统一数据对象数据结构。

**起始版本：** 12


### OH_UdmfProperty

```
typedef struct OH_UdmfProperty OH_UdmfProperty
```

**描述**

定义统一数据对象中数据记录的属性结构。

**起始版本：** 12


### OH_UdmfRecord

```
typedef struct OH_UdmfRecord OH_UdmfRecord
```

**描述**

定义统一数据对象中记录数据的数据结构，称为数据记录。

**起始版本：** 12


### OH_UdmfRecordProvider

```
typedef struct OH_UdmfRecordProvider OH_UdmfRecordProvider
```

**描述**

定义统一数据对象中的数据提供者。

**起始版本：** 13


### OH_UdmfRecordProvider_GetData

```
typedef void*(* OH_UdmfRecordProvider_GetData) (void *context, const char *type)
```

**描述**

定义用于按类型获取数据的回调函数。 当从OH_UdmfRecord中获取数据时，会触发此回调函数，得到的数据就是这个回调函数返回的数据。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| context | 用[OH_UdmfRecordProvider_SetData](#oh_udmfrecordprovider_setdata)设置的上下文指针。 | 
| type | 要获取的数据类型。详细类型信息见[udmf_meta.h](udmf__meta_8h.md)。 | 

**返回：**

需要返回一个标准化数据。


### OH_UdsAppItem

```
typedef struct OH_UdsAppItem OH_UdsAppItem
```

**描述**

描述桌面图标类型的统一数据结构。

**起始版本：** 12


### OH_UdsArrayBuffer

```
typedef struct OH_UdsArrayBuffer OH_UdsArrayBuffer
```

**描述**

描述ArrayBuffer类型的统一数据结构。

**起始版本：** 13


### OH_UdsFileUri

```
typedef struct OH_UdsFileUri OH_UdsFileUri
```

**描述**

描述文件Uri类型的统一数据结构。

**起始版本：** 13


### OH_UdsHtml

```
typedef struct OH_UdsHtml OH_UdsHtml
```

**描述**

描述超文本标记语言类型的统一数据结构。

**起始版本：** 12


### OH_UdsHyperlink

```
typedef struct OH_UdsHyperlink OH_UdsHyperlink
```

**描述**

描述超链接类型的统一数据结构。

**起始版本：** 12


### OH_UdsPixelMap

```
typedef struct OH_UdsPixelMap OH_UdsPixelMap
```

**描述**

描述像素图片类型的统一数据结构。

**起始版本：** 13


### OH_UdsPlainText

```
typedef struct OH_UdsPlainText OH_UdsPlainText
```

**描述**

描述纯文本类型数据的统一数据结构。

**起始版本：** 12


### OH_Utd

```
typedef struct OH_Utd OH_Utd
```

**描述**

统一数据类型描述符。

**起始版本：** 12


### Udmf_ErrCode

```
typedef enum Udmf_ErrCode Udmf_ErrCode
```

**描述**

错误码信息。

**起始版本：** 12


### Udmf_Intention

```
typedef enum Udmf_Intention Udmf_Intention
```

**描述**

描述UDMF数据通路枚举类型。

**起始版本：** 12


### Udmf_ShareOption

```
typedef enum Udmf_ShareOption Udmf_ShareOption
```

**描述**

UDMF支持的设备内使用范围类型枚举。

**起始版本：** 12


### UdmfData_Finalize

```
typedef void(* UdmfData_Finalize) (void *context)
```

**描述**

定义用于释放上下文的回调函数，统一数据提供者对象销毁时触发。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| context | 要释放的上下文指针。 | 


## 枚举类型说明


### Udmf_ErrCode

```
enum Udmf_ErrCode
```

**描述**

错误码信息。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| UDMF_E_OK | 执行成功。 | 
| UDMF_ERR | 通用错误 | 
| UDMF_E_INVALID_PARAM | 非法参数。 | 


### Udmf_Intention

```
enum Udmf_Intention
```

**描述**

描述UDMF数据通路枚举类型。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| UDMF_INTENTION_DRAG | 拖拽数据通路。 | 
| UDMF_INTENTION_PASTEBOARD | 剪贴板数据通路。 | 


### Udmf_ShareOption

```
enum Udmf_ShareOption
```

**描述**

UDMF支持的设备内使用范围类型枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| SHARE_OPTIONS_INVALID | 表示不合法的使用范围类型。 | 
| SHARE_OPTIONS_IN_APP | 表示允许在本设备同应用内使用。 | 
| SHARE_OPTIONS_CROSS_APP | 表示允许在本设备内跨应用使用。 | 


## 函数说明


### OH_Udmf_GetUnifiedData()

```
int OH_Udmf_GetUnifiedData (const char* key, Udmf_Intention intention, OH_UdmfData* unifiedData )
```

**描述**

从统一数据管理框架数据库中获取统一数据对象[OH_UdmfData](#oh_udmfdata)数据。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| key | 表示数据库存储的唯一标识符。 | 
| intention | 表示数据通路类型[Udmf_Intention](#udmf_intention)。 | 
| unifiedData | 该参数是输出参数，获取到的统一数据对象[OH_UdmfData](#oh_udmfdata)会写入该变量。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdmfProperty](#oh_udmfproperty)

[Udmf_Intention](#udmf_intention)

[Udmf_ErrCode](#udmf_errcode)


### OH_Udmf_SetUnifiedData()

```
int OH_Udmf_SetUnifiedData (Udmf_Intention intention, OH_UdmfData* unifiedData, char* key, unsigned int keyLen )
```

**描述**

从统一数据管理框架数据库中写入统一数据对象[OH_UdmfData](#oh_udmfdata)数据。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| intention | 表示数据通路类型[Udmf_Intention](#udmf_intention)。 | 
| unifiedData | 表示统一数据对象[OH_UdmfData](#oh_udmfdata)数据。 | 
| key | 表示成功将数据设置到数据库后对应数据的唯一标识符。 | 
| keyLen | 表示唯一标识符参数的空间大小，内存大小不小于512字节。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdmfProperty](#oh_udmfproperty)

[Udmf_Intention](#udmf_intention)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfData_AddRecord()

```
int OH_UdmfData_AddRecord (OH_UdmfData* pThis, OH_UdmfRecord* record )
```

**描述**

添加一个数据记录[OH_UdmfRecord](#oh_udmfrecord)到统一数据对象[OH_UdmfData](#oh_udmfdata)中。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向统一数据对象[OH_UdmfData](#oh_udmfdata)实例的指针。 | 
| record | 表示指向统一数据记录[OH_UdmfRecord](#oh_udmfrecord)实例的指针。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdmfData](#oh_udmfdata)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfData_Create()

```
OH_UdmfData* OH_UdmfData_Create ()
```

**描述**

创建统一数据对象[OH_UdmfData](#oh_udmfdata)指针及实例对象。 当不再需要使用指针时，请使用[OH_UdmfData_Destroy](#oh_udmfdata_destroy)销毁实例对象，否则会导致内存泄漏。

**起始版本：** 12

**返回：**

执行成功则返回一个指向统一数据对象[OH_UdmfData](#oh_udmfdata)实例对象的指针，否则返回nullptr。

**参见：**

[OH_UdmfData](#oh_udmfdata)


### OH_UdmfData_Destroy()

```
void OH_UdmfData_Destroy (OH_UdmfData* pThis)
```

**描述**

销毁统一数据对象[OH_UdmfData](#oh_udmfdata)指针指向的实例对象。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向统一数据对象[OH_UdmfData](#oh_udmfdata)实例的指针。 | 

**参见：**

[OH_UdmfData](#oh_udmfdata)


### OH_UdmfData_GetPrimaryHtml()

```
int OH_UdmfData_GetPrimaryHtml (OH_UdmfData* data, OH_UdsHtml* html )
```

**描述**

从统一数据对象[OH_UdmfData](#oh_udmfdata)中获取第一个超文本标记语言类型[OH_UdsHtml](#oh_udshtml)数据。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| data | 表示指向统一数据对象[OH_UdmfData](#oh_udmfdata)实例的指针。 | 
| html | 该参数是输出参数，表示指向超文本标记语言类型[OH_UdsHtml](#oh_udshtml)实例的指针。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdmfData](#oh_udmfdata)

[OH_UdsHtml](#oh_udshtml)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfData_GetPrimaryPlainText()

```
int OH_UdmfData_GetPrimaryPlainText (OH_UdmfData* data, OH_UdsPlainText* plainText )
```

**描述**

从统一数据对象[OH_UdmfData](#oh_udmfdata)中获取第一个纯文本类型[OH_UdsPlainText](#oh_udsplaintext)数据。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| data | 表示指向统一数据对象[OH_UdmfData](#oh_udmfdata)实例的指针。 | 
| plainText | 该参数是输出参数，表示指向纯文本类型[OH_UdsPlainText](#oh_udsplaintext)实例的指针。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdmfData](#oh_udmfdata)

[OH_UdsPlainText](#oh_udsplaintext)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfData_GetRecord()

```
OH_UdmfRecord* OH_UdmfData_GetRecord (OH_UdmfData* data, unsigned int index )
```

**描述**

获取统一数据对象[OH_UdmfData](#oh_udmfdata)中指定位置的数据记录。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| data | 表示指向统一数据对象[OH_UdmfData](#oh_udmfdata)实例的指针。 | 
| index | 表示要获取的统一数据记录[OH_UdmfRecord](#oh_udmfrecord)在统一数据对象[OH_UdmfData](#oh_udmfdata)中的下标。 | 

**返回：**

执行成功时返回统一数据记录[OH_UdmfRecord](#oh_udmfrecord)实例对象的指针，否则返回nullptr。

**参见：**

[OH_UdmfData](#oh_udmfdata)


### OH_UdmfData_GetRecordCount()

```
int OH_UdmfData_GetRecordCount (OH_UdmfData* data)
```

**描述**

获取统一数据对象[OH_UdmfData](#oh_udmfdata)中包含的所有记录数量。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| 表示指向统一数据对象{ |  | 


### OH_UdmfData_GetRecords()

```
OH_UdmfRecord** OH_UdmfData_GetRecords (OH_UdmfData* pThis, unsigned int* count )
```

**描述**

获取统一数据对象[OH_UdmfData](#oh_udmfdata)中包含的所有记录结果集。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向统一数据对象[OH_UdmfData](#oh_udmfdata)实例的指针。 | 
| count | 该参数是输出参数，结果集中的记录数量会写入该变量。 | 

**返回：**

执行成功时返回统一数据记录[OH_UdmfRecord](#oh_udmfrecord)结果集，否则返回nullptr。

**参见：**

[OH_UdmfData](#oh_udmfdata)

[OH_UdmfRecord](#oh_udmfrecord)


### OH_UdmfData_GetTypes()

```
char** OH_UdmfData_GetTypes (OH_UdmfData* pThis, unsigned int* count )
```

**描述**

获取统一数据对象[OH_UdmfData](#oh_udmfdata)中包含的所有类型结果集。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向统一数据对象[OH_UdmfData](#oh_udmfdata)实例的指针。 | 
| count | 该参数是输出参数，结果集中的类型数量会写入该变量。 | 

**返回：**

执行成功时返回统一数据对象的类型结果集，否则返回nullptr。

**参见：**

[OH_UdmfData](#oh_udmfdata)


### OH_UdmfData_HasType()

```
bool OH_UdmfData_HasType (OH_UdmfData* pThis, const char* type )
```

**描述**

检查统一数据对象[OH_UdmfData](#oh_udmfdata)中是否存在指定类型。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向统一数据对象[OH_UdmfData](#oh_udmfdata)实例的指针。 | 
| type | 表示指定类型的字符串指针。 | 

**返回：**

返回查找类型的状态。返回false表示不存在指定类型，返回true表示存在指定类型。

**参见：**

[OH_UdmfData](#oh_udmfdata)


### OH_UdmfData_IsLocal()

```
bool OH_UdmfData_IsLocal (OH_UdmfData* data)
```

**描述**

检查统一数据对象[OH_UdmfData](#oh_udmfdata)是否是来自本端设备的数据。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| data | 表示指向统一数据对象[OH_UdmfData](#oh_udmfdata)实例的指针。 | 

**返回：**

返回数据是否是来自本端设备。返回true表示来自本端设备，返回false表示来自远端设备。

**参见：**

[OH_UdmfData](#oh_udmfdata)


### OH_UdmfProperty_Create()

```
OH_UdmfProperty* OH_UdmfProperty_Create (OH_UdmfData* unifiedData)
```

**描述**

创建统一数据对象中数据记录属性[OH_UdmfProperty](#oh_udmfproperty)指针及实例对象。 当不再需要使用指针时，请使用[OH_UdmfProperty_Destroy](#oh_udmfproperty_destroy)销毁实例对象，否则会导致内存泄漏。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| unifiedData | 表示指向统一数据对象[OH_UdmfData](#oh_udmfdata)实例的指针。 | 

**返回：**

执行成功则返回一个指向属性[OH_UdmfProperty](#oh_udmfproperty)实例对象的指针，否则返回nullptr。

**参见：**

[OH_UdmfData](#oh_udmfdata)

[OH_UdmfProperty](#oh_udmfproperty)


### OH_UdmfProperty_Destroy()

```
void OH_UdmfProperty_Destroy (OH_UdmfProperty* pThis)
```

**描述**

销毁数据属性[OH_UdmfProperty](#oh_udmfproperty)指针指向的实例对象。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向数据属性[OH_UdmfProperty](#oh_udmfproperty)实例的指针。 | 

**参见：**

[OH_UdmfProperty](#oh_udmfproperty)


### OH_UdmfProperty_GetExtrasIntParam()

```
int OH_UdmfProperty_GetExtrasIntParam (OH_UdmfProperty* pThis, const char* key, int defaultValue )
```

**描述**

从数据属性[OH_UdmfProperty](#oh_udmfproperty)中获取自定义的附加整型参数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向数据属性[OH_UdmfProperty](#oh_udmfproperty)实例的指针。 | 
| key | 表示键值对的键。 | 
| defaultValue | 用于用户自行设置获取值失败时的默认值。 | 

**返回：**

执行成功返回指定的键关联的整型值，否则返回用户设置的默认值defaultValue。

**参见：**

[OH_UdmfProperty](#oh_udmfproperty)


### OH_UdmfProperty_GetExtrasStringParam()

```
const char* OH_UdmfProperty_GetExtrasStringParam (OH_UdmfProperty* pThis, const char* key )
```

**描述**

从数据属性[OH_UdmfProperty](#oh_udmfproperty)中获取自定义的附加字符串参数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向数据属性[OH_UdmfProperty](#oh_udmfproperty)实例的指针。 | 
| key | 表示键值对的键。 | 

**返回：**

执行成功时返回指定的键关联的字符串值的指针，否则返回nullptr。

**参见：**

[OH_UdmfProperty](#oh_udmfproperty)


### OH_UdmfProperty_GetShareOption()

```
Udmf_ShareOption OH_UdmfProperty_GetShareOption (OH_UdmfProperty* pThis)
```

**描述**

从数据属性[OH_UdmfProperty](#oh_udmfproperty)中获取设备内适用范围属性。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向数据属性[OH_UdmfProperty](#oh_udmfproperty)实例的指针。 | 

**返回：**

返回设备内适用范围属性[Udmf_ShareOption](#udmf_shareoption)值。

**参见：**

[OH_UdmfProperty](#oh_udmfproperty)

[Udmf_ShareOption](#udmf_shareoption)


### OH_UdmfProperty_GetTag()

```
const char* OH_UdmfProperty_GetTag (OH_UdmfProperty* pThis)
```

**描述**

从数据属性[OH_UdmfProperty](#oh_udmfproperty)中获取用户自定义标签值。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向数据属性[OH_UdmfProperty](#oh_udmfproperty)实例的指针。 | 

**返回：**

执行成功时返回自定义标签值的字符串指针，否则返回nullptr。

**参见：**

[OH_UdmfProperty](#oh_udmfproperty)


### OH_UdmfProperty_GetTimestamp()

```
int64_t OH_UdmfProperty_GetTimestamp (OH_UdmfProperty* pThis)
```

**描述**

从数据属性[OH_UdmfProperty](#oh_udmfproperty)中获取时间戳。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向数据属性[OH_UdmfProperty](#oh_udmfproperty)实例的指针。 | 

**返回：**

返回时间戳值。

**参见：**

[OH_UdmfProperty](#oh_udmfproperty)


### OH_UdmfProperty_SetExtrasIntParam()

```
int OH_UdmfProperty_SetExtrasIntParam (OH_UdmfProperty* pThis, const char* key, int param )
```

**描述**

设置数据属性[OH_UdmfProperty](#oh_udmfproperty)的附加整型参数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向[OH_UdmfRecord](#oh_udmfrecord)实例的指针。 | 
| key | 表示键值对的键。 | 
| param | 表示键值对的值。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdmfProperty](#oh_udmfproperty)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfProperty_SetExtrasStringParam()

```
int OH_UdmfProperty_SetExtrasStringParam (OH_UdmfProperty* pThis, const char* key, const char* param )
```

**描述**

设置数据属性[OH_UdmfProperty](#oh_udmfproperty)的附加字符串参数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向数据属性[OH_UdmfRecord](#oh_udmfrecord)实例的指针。 | 
| key | 表示键值对的键。 | 
| param | 表示键值对的值。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdmfProperty](#oh_udmfproperty)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfProperty_SetShareOption()

```
int OH_UdmfProperty_SetShareOption (OH_UdmfProperty* pThis, Udmf_ShareOption option )
```

**描述**

设置数据属性[OH_UdmfProperty](#oh_udmfproperty)的设备内适用范围**OH_Udmf_ShareOption**参数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向数据属性[OH_UdmfProperty](#oh_udmfproperty)实例的指针。 | 
| option | 表示设备内适用范围[Udmf_ShareOption](#udmf_shareoption)参数。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdmfProperty](#oh_udmfproperty)

[Udmf_ShareOption](#udmf_shareoption)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfProperty_SetTag()

```
int OH_UdmfProperty_SetTag (OH_UdmfProperty* pThis, const char* tag )
```

**描述**

设置数据属性[OH_UdmfProperty](#oh_udmfproperty)的自定义标签值。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向数据属性[OH_UdmfProperty](#oh_udmfproperty)实例的指针。 | 
| tag | 表示自定义标签值。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdmfProperty](#oh_udmfproperty)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecord_AddAppItem()

```
int OH_UdmfRecord_AddAppItem (OH_UdmfRecord* pThis, OH_UdsAppItem* appItem )
```

**描述**

增加桌面图标类型[OH_UdsAppItem](#oh_udsappitem)数据至统一数据记录[OH_UdmfRecord](#oh_udmfrecord)中。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向统一数据记录[OH_UdmfRecord](#oh_udmfrecord)实例的指针。 | 
| appItem | 表示指向桌面图标类型[OH_UdsAppItem](#oh_udsappitem)实例的指针。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdmfRecord](#oh_udmfrecord)

[OH_UdsAppItem](#oh_udsappitem)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecord_AddArrayBuffer()

```
int OH_UdmfRecord_AddArrayBuffer (OH_UdmfRecord* record, const char* type, OH_UdsArrayBuffer* buffer )
```

**描述**

增加一个ArrayBuffer类型[OH_UdsArrayBuffer](#oh_udsarraybuffer)的数据至统一数据记录[OH_UdmfRecord](#oh_udmfrecord)中。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| record | 表示指向统一数据记录[OH_UdmfRecord](#oh_udmfrecord)实例的指针。 | 
| type | 表示自定义的ArrayBuffer数据的数据类型标识，不可与已有的数据类型标识重复。 | 
| buffer | 表示指向ArrayBuffer类型[OH_UdsArrayBuffer](#oh_udsarraybuffer)实例的指针。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdmfRecord](#oh_udmfrecord)

[OH_UdsArrayBuffer](#oh_udsarraybuffer)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecord_AddFileUri()

```
int OH_UdmfRecord_AddFileUri (OH_UdmfRecord* pThis, OH_UdsFileUri* fileUri )
```

**描述**

增加文件Uri类型[OH_UdsFileUri](#oh_udsfileuri)数据至统一数据记录[OH_UdmfRecord](#oh_udmfrecord)中。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向统一数据记录[OH_UdmfRecord](#oh_udmfrecord)实例的指针。 | 
| fileUri | 表示指向文件Uri类型[OH_UdsFileUri](#oh_udsfileuri)实例的指针。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdmfRecord](#oh_udmfrecord)

[OH_UdsFileUri](#oh_udsfileuri)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecord_AddGeneralEntry()

```
int OH_UdmfRecord_AddGeneralEntry (OH_UdmfRecord* pThis, const char* typeId, unsigned char* entry, unsigned int count )
```

**描述**

添加用户自定义的通用数据至统一数据记录[OH_UdmfRecord](#oh_udmfrecord)中。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向统一数据记录[OH_UdmfRecord](#oh_udmfrecord)实例的指针。 | 
| typeId | 表示数据类型标识。 | 
| entry | 表示用户自定义数据。 | 
| count | 表示用户自定义数据的大小。数据大小不超过4KB。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdmfRecord](#oh_udmfrecord)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecord_AddHtml()

```
int OH_UdmfRecord_AddHtml (OH_UdmfRecord* pThis, OH_UdsHtml* html )
```

**描述**

增加超文本标记语言类型[OH_UdsHtml](#oh_udshtml)数据至统一数据记录[OH_UdmfRecord](#oh_udmfrecord)中。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向统一数据记录[OH_UdmfRecord](#oh_udmfrecord)实例的指针。 | 
| html | 表示指向超文本标记语言类型[OH_UdsHtml](#oh_udshtml)实例的指针。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdmfRecord](#oh_udmfrecord)

[OH_UdsHtml](#oh_udshtml)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecord_AddHyperlink()

```
int OH_UdmfRecord_AddHyperlink (OH_UdmfRecord* pThis, OH_UdsHyperlink* hyperlink )
```

**描述**

增加超链接类型[OH_UdsHyperlink](#oh_udshyperlink)数据至统一数据记录[OH_UdmfRecord](#oh_udmfrecord)中。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向统一数据记录[OH_UdmfRecord](#oh_udmfrecord)实例的指针。 | 
| hyperlink | 表示指向超链接类型[OH_UdsHyperlink](#oh_udshyperlink)实例的指针。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdmfRecord](#oh_udmfrecord)

[OH_UdsHyperlink](#oh_udshyperlink)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecord_AddPixelMap()

```
int OH_UdmfRecord_AddPixelMap (OH_UdmfRecord* pThis, OH_UdsPixelMap* pixelMap )
```

**描述**

增加像素图片类型[OH_UdsPixelMap](#oh_udspixelmap)数据至统一数据记录[OH_UdmfRecord](#oh_udmfrecord)中。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向统一数据记录[OH_UdmfRecord](#oh_udmfrecord)实例的指针。 | 
| pixelMap | 表示指向像素图片类型[OH_UdsPixelMap](#oh_udspixelmap)实例的指针。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdmfRecord](#oh_udmfrecord)

[OH_UdsPixelMap](#oh_udspixelmap)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecord_AddPlainText()

```
int OH_UdmfRecord_AddPlainText (OH_UdmfRecord* pThis, OH_UdsPlainText* plainText )
```

**描述**

增加纯文本类型[OH_UdsPlainText](#oh_udsplaintext)数据至统一数据记录[OH_UdmfRecord](#oh_udmfrecord)中。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向统一数据记录[OH_UdmfRecord](#oh_udmfrecord)实例的指针。 | 
| plainText | 表示指向纯文本类型[OH_UdsPlainText](#oh_udsplaintext)实例的指针。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdmfRecord](#oh_udmfrecord)

[OH_UdsPlainText](#oh_udsplaintext)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecord_Create()

```
OH_UdmfRecord* OH_UdmfRecord_Create ()
```

**描述**

创建统一数据记录[OH_UdmfRecord](#oh_udmfrecord)指针及实例对象。 当不再需要使用指针时，请使用[OH_UdmfRecord_Destroy](#oh_udmfrecord_destroy)销毁实例对象，否则会导致内存泄漏。

**起始版本：** 12

**返回：**

执行成功则返回一个指向统一数据记录[OH_UdmfRecord](#oh_udmfrecord)实例对象的指针，否则返回nullptr。

**参见：**

[OH_UdmfRecord](#oh_udmfrecord)


### OH_UdmfRecord_Destroy()

```
void OH_UdmfRecord_Destroy (OH_UdmfRecord* pThis)
```

**描述**

销毁统一数据记录[OH_UdmfRecord](#oh_udmfrecord)指针指向的实例对象。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向统一数据对象[OH_UdmfRecord](#oh_udmfrecord)实例的指针。 | 

**参见：**

[OH_UdmfRecord](#oh_udmfrecord)


### OH_UdmfRecord_GetAppItem()

```
int OH_UdmfRecord_GetAppItem (OH_UdmfRecord* pThis, OH_UdsAppItem* appItem )
```

**描述**

从统一数据记录[OH_UdmfRecord](#oh_udmfrecord)中获取桌面图标类型[OH_UdsAppItem](#oh_udsappitem)数据。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向统一数据记录[OH_UdmfRecord](#oh_udmfrecord)实例的指针。 | 
| appItem | 该参数是输出参数，表示指向桌面图标类型[OH_UdsAppItem](#oh_udsappitem)实例的指针。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdmfRecord](#oh_udmfrecord)

[OH_UdsAppItem](#oh_udsappitem)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecord_GetArrayBuffer()

```
int OH_UdmfRecord_GetArrayBuffer (OH_UdmfRecord* record, const char* type, OH_UdsArrayBuffer* buffer )
```

**描述**

从统一数据记录[OH_UdmfRecord](#oh_udmfrecord)中获取ArrayBuffer类型[OH_UdsArrayBuffer](#oh_udsarraybuffer)数据。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| record | 表示指向统一数据记录[OH_UdmfRecord](#oh_udmfrecord)实例的指针。 | 
| type | 表示要获取的ArrayBuffer类型数据的数据类型标识。 | 
| buffer | 该参数是输出参数，表示指向ArrayBuffer类型[OH_UdsArrayBuffer](#oh_udsarraybuffer)实例的指针。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdmfRecord](#oh_udmfrecord)

[OH_UdsArrayBuffer](#oh_udsarraybuffer)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecord_GetFileUri()

```
int OH_UdmfRecord_GetFileUri (OH_UdmfRecord* pThis, OH_UdsFileUri* fileUri )
```

**描述**

从统一数据记录[OH_UdmfRecord](#oh_udmfrecord)中获取文件Uri类型[OH_UdsFileUri](#oh_udsfileuri)数据。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向统一数据记录[OH_UdmfRecord](#oh_udmfrecord)实例的指针。 | 
| fileUri | 该参数是输出参数，表示指向文件Uri类型[OH_UdsFileUri](#oh_udsfileuri)实例的指针。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdmfRecord](#oh_udmfrecord)

[OH_UdsFileUri](#oh_udsfileuri)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecord_GetGeneralEntry()

```
int OH_UdmfRecord_GetGeneralEntry (OH_UdmfRecord* pThis, const char* typeId, unsigned char** entry, unsigned int* count )
```

**描述**

获取统一数据记录[OH_UdmfRecord](#oh_udmfrecord)中的特定类型的数据结果集。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向统一数据记录[OH_UdmfRecord](#oh_udmfrecord)实例的指针。 | 
| typeId | 表示数据类型标识。 | 
| entry | 该参数是输出参数，结果集中数据的具体信息会写入该变量。 | 
| count | 该参数是输出参数，结果集中的数据长度会写入该变量。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdmfRecord](#oh_udmfrecord)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecord_GetHtml()

```
int OH_UdmfRecord_GetHtml (OH_UdmfRecord* pThis, OH_UdsHtml* html )
```

**描述**

从统一数据记录[OH_UdmfRecord](#oh_udmfrecord)中获取超文本标记语言类型[OH_UdsHtml](#oh_udshtml)数据。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向统一数据记录[OH_UdmfRecord](#oh_udmfrecord)实例的指针。 | 
| html | 该参数是输出参数，表示指向超文本标记语言类型[OH_UdsHtml](#oh_udshtml)实例的指针。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdmfRecord](#oh_udmfrecord)

[OH_UdsHtml](#oh_udshtml)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecord_GetHyperlink()

```
int OH_UdmfRecord_GetHyperlink (OH_UdmfRecord* pThis, OH_UdsHyperlink* hyperlink )
```

**描述**

从统一数据记录[OH_UdmfRecord](#oh_udmfrecord)中获取超链接类型[OH_UdsHyperlink](#oh_udshyperlink)数据。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向统一数据记录[OH_UdmfRecord](#oh_udmfrecord)实例的指针。 | 
| hyperlink | 该参数是输出参数，表示指向超链接类型[OH_UdsHyperlink](#oh_udshyperlink)实例的指针。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdmfRecord](#oh_udmfrecord)

[OH_UdsHyperlink](#oh_udshyperlink)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecord_GetPixelMap()

```
int OH_UdmfRecord_GetPixelMap (OH_UdmfRecord* pThis, OH_UdsPixelMap* pixelMap )
```

**描述**

从统一数据记录[OH_UdmfRecord](#oh_udmfrecord)中获取像素图片类型[OH_UdsPixelMap](#oh_udspixelmap)数据。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向统一数据记录[OH_UdmfRecord](#oh_udmfrecord)实例的指针。 | 
| pixelMap | 该参数是输出参数，表示指向像素图片类型[OH_UdsPixelMap](#oh_udspixelmap)实例的指针。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdmfRecord](#oh_udmfrecord)

[OH_UdsPixelMap](#oh_udspixelmap)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecord_GetPlainText()

```
int OH_UdmfRecord_GetPlainText (OH_UdmfRecord* pThis, OH_UdsPlainText* plainText )
```

**描述**

从统一数据记录[OH_UdmfRecord](#oh_udmfrecord)中获取纯文本类型[OH_UdsPlainText](#oh_udsplaintext)数据。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向统一数据记录[OH_UdmfRecord](#oh_udmfrecord)实例的指针。 | 
| plainText | 该参数是输出参数，表示指向纯文本类型[OH_UdsPlainText](#oh_udsplaintext)实例的指针。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdmfRecord](#oh_udmfrecord)

[OH_UdsPlainText](#oh_udsplaintext)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecord_GetTypes()

```
char** OH_UdmfRecord_GetTypes (OH_UdmfRecord* pThis, unsigned int* count )
```

**描述**

获取统一数据记录[OH_UdmfRecord](#oh_udmfrecord)中所有类型的结果集。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向统一数据记录[OH_UdmfRecord](#oh_udmfrecord)实例的指针。 | 
| count | 该参数是输出参数，结果集中的类型数量会写入该变量。 | 

**返回：**

执行成功时返回类型列表，否则返回nullptr。

**参见：**

[OH_UdmfRecord](#oh_udmfrecord)


### OH_UdmfRecord_SetProvider()

```
int OH_UdmfRecord_SetProvider (OH_UdmfRecord* pThis, const char* const* types, unsigned int count, OH_UdmfRecordProvider* provider )
```

**描述**

将指定类型的统一数据提供者[OH_UdmfRecordProvider](#oh_udmfrecordprovider)设置至统一数据记录[OH_UdmfRecord](#oh_udmfrecord)中。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向统一数据记录[OH_UdmfRecord](#oh_udmfrecord)实例的指针。 | 
| types | 表示一组指定的要提供的数据类型。 | 
| count | 表示指定的数据类型的数量。 | 
| provider | 表示指向统一数据提供者对象[OH_UdmfRecordProvider](#oh_udmfrecordprovider)实例的指针。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdmfRecord](#oh_udmfrecord)

[OH_UdmfRecordProvider](#oh_udmfrecordprovider)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecordProvider_Create()

```
OH_UdmfRecordProvider* OH_UdmfRecordProvider_Create ()
```

**描述**

创建一个统一数据提供者[OH_UdmfRecordProvider](#oh_udmfrecordprovider)指针及实例对象。 当不再需要使用指针时，请使用[OH_UdmfRecordProvider_Destroy](#oh_udmfrecordprovider_destroy)销毁实例对象，否则会导致内存泄漏。

**起始版本：** 13

**返回：**

执行成功时返回一个指向统一数据提供者[OH_UdmfRecordProvider](#oh_udmfrecordprovider)实例对象的指针，否则返回nullptr。

**参见：**

[OH_UdmfRecordProvider](#oh_udmfrecordprovider)


### OH_UdmfRecordProvider_Destroy()

```
int OH_UdmfRecordProvider_Destroy (OH_UdmfRecordProvider* provider)
```

**描述**

销毁统一数据提供者[OH_UdmfRecordProvider](#oh_udmfrecordprovider)指针指向的实例对象。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| provider | 表示指向统一数据提供者对象[OH_UdmfRecordProvider](#oh_udmfrecordprovider)实例的指针。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdmfRecordProvider](#oh_udmfrecordprovider)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdmfRecordProvider_SetData()

```
int OH_UdmfRecordProvider_SetData (OH_UdmfRecordProvider* provider, void* context, const OH_UdmfRecordProvider_GetData callback, const UdmfData_Finalize finalize )
```

**描述**

设置统一数据提供者的数据提供回调函数。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| provider | 指向统一数据提供者[OH_UdmfRecordProvider](#oh_udmfrecordprovider)实例对象的指针。 | 
| context | 上下文指针，将作为第一个参数传入[OH_UdmfRecordProvider_GetData](#oh_udmfrecordprovider_getdata)。 | 
| callback | 获取数据的回调函数。详见：[OH_UdmfRecordProvider_GetData](#oh_udmfrecordprovider_getdata)。 | 
| finalize | 可选的回调函数，可以用于统一数据提供者销毁时释放上下文数据。详见：[UdmfData_Finalize](#udmfdata_finalize)。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdmfRecordProvider](#oh_udmfrecordprovider)

[OH_UdmfRecordProvider_GetData](#oh_udmfrecordprovider_getdata)

[UdmfData_Finalize](#udmfdata_finalize)[Udmf_ErrCode](#udmf_errcode)


### OH_UdsAppItem_Create()

```
OH_UdsAppItem* OH_UdsAppItem_Create ()
```

**描述**

创建桌面图标类型[OH_UdsAppItem](#oh_udsappitem)指针及实例对象。 当不再需要使用指针时，请使用[OH_UdsAppItem_Destroy](#oh_udsappitem_destroy)销毁实例对象，否则会导致内存泄漏。

**起始版本：** 12

**返回：**

执行成功返则回一个指向桌面图标类型[OH_UdsAppItem](#oh_udsappitem)实例对象的指针，否则返回nullptr。

**参见：**

[OH_UdsAppItem](#oh_udsappitem)


### OH_UdsAppItem_Destroy()

```
void OH_UdsAppItem_Destroy (OH_UdsAppItem* pThis)
```

**描述**

销毁桌面图标类型[OH_UdsAppItem](#oh_udsappitem)指针指向的实例对象。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示一个指向桌面图标类型[OH_UdsAppItem](#oh_udsappitem)对象的指针。 | 

**参见：**

[OH_UdsAppItem](#oh_udsappitem)


### OH_UdsAppItem_GetAbilityName()

```
const char* OH_UdsAppItem_GetAbilityName (OH_UdsAppItem* pThis)
```

**描述**

从桌面图标类型[OH_UdsAppItem](#oh_udsappitem)实例中ability名称。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示一个指向桌面图标类型[OH_UdsAppItem](#oh_udsappitem)对象的指针。 | 

**返回：**

输入有效入参时返回ability名称的字符串指针，否则返回nullptr。

**参见：**

[OH_UdsAppItem](#oh_udsappitem)


### OH_UdsAppItem_GetBundleName()

```
const char* OH_UdsAppItem_GetBundleName (OH_UdsAppItem* pThis)
```

**描述**

从桌面图标类型[OH_UdsAppItem](#oh_udsappitem)实例中获取bundle名称。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示一个指向桌面图标类型[OH_UdsAppItem](#oh_udsappitem)对象的指针。 | 

**返回：**

输入有效入参时返回bundle名称的字符串指针，否则返回nullptr。

**参见：**

[OH_UdsAppItem](#oh_udsappitem)


### OH_UdsAppItem_GetIconId()

```
const char* OH_UdsAppItem_GetIconId (OH_UdsAppItem* pThis)
```

**描述**

从桌面图标类型[OH_UdsAppItem](#oh_udsappitem)实例中获取图片ID。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示一个指向桌面图标类型[OH_UdsAppItem](#oh_udsappitem)对象的指针。 | 

**返回：**

输入有效入参时返回图片ID的字符串指针，否则返回nullptr。

**参见：**

[OH_UdsAppItem](#oh_udsappitem)


### OH_UdsAppItem_GetId()

```
const char* OH_UdsAppItem_GetId (OH_UdsAppItem* pThis)
```

**描述**

从桌面图标类型[OH_UdsAppItem](#oh_udsappitem)实例中获取应用ID。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示一个指向桌面图标类型[OH_UdsAppItem](#oh_udsappitem)对象的指针。 | 

**返回：**

输入有效入参时返回应用ID的字符串指针，否则返回nullptr。

**参见：**

[OH_UdsAppItem](#oh_udsappitem)


### OH_UdsAppItem_GetLabelId()

```
const char* OH_UdsAppItem_GetLabelId (OH_UdsAppItem* pThis)
```

**描述**

从桌面图标类型[OH_UdsAppItem](#oh_udsappitem)实例中获取标签ID。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示一个指向桌面图标类型[OH_UdsAppItem](#oh_udsappitem)对象的指针。 | 

**返回：**

输入有效入参时返回标签ID的字符串指针，否则返回nullptr。

**参见：**

[OH_UdsAppItem](#oh_udsappitem)


### OH_UdsAppItem_GetName()

```
const char* OH_UdsAppItem_GetName (OH_UdsAppItem* pThis)
```

**描述**

从桌面图标类型[OH_UdsAppItem](#oh_udsappitem)实例中获取应用名称。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示一个指向桌面图标类型[OH_UdsAppItem](#oh_udsappitem)对象的指针。 | 

**返回：**

输入有效入参时返回应用名称的字符串指针，否则返回nullptr。

**参见：**

[OH_UdsAppItem](#oh_udsappitem)


### OH_UdsAppItem_GetType()

```
const char* OH_UdsAppItem_GetType (OH_UdsAppItem* pThis)
```

**描述**

从桌面图标类型[OH_UdsAppItem](#oh_udsappitem)实例获取类型ID。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示一个指向桌面图标类型[OH_UdsAppItem](#oh_udsappitem)对象的指针。 | 

**返回：**

输入有效入参时返回类型ID的字符串指针，否则返回nullptr。

**参见：**

[OH_UdsAppItem](#oh_udsappitem)


### OH_UdsAppItem_SetAbilityName()

```
int OH_UdsAppItem_SetAbilityName (OH_UdsAppItem* pThis, const char* abilityName )
```

**描述**

设置桌面图标类型[OH_UdsAppItem](#oh_udsappitem)对象的ability名称。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示一个指向桌面图标类型[OH_UdsAppItem](#oh_udsappitem)对象的指针。 | 
| abilityName | 表示ability名称。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdsAppItem](#oh_udsappitem)


### OH_UdsAppItem_SetBundleName()

```
int OH_UdsAppItem_SetBundleName (OH_UdsAppItem* pThis, const char* bundleName )
```

**描述**

设置桌面图标类型[OH_UdsAppItem](#oh_udsappitem)对象的bundle名称。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示一个指向桌面图标类型[OH_UdsAppItem](#oh_udsappitem)对象的指针。 | 
| bundleName | 表示bundle名称。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdsAppItem](#oh_udsappitem)


### OH_UdsAppItem_SetIconId()

```
int OH_UdsAppItem_SetIconId (OH_UdsAppItem* pThis, const char* appIconId )
```

**描述**

设置桌面图标类型[OH_UdsAppItem](#oh_udsappitem)对象的图片ID。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示一个指向桌面图标类型[OH_UdsAppItem](#oh_udsappitem)对象的指针。 | 
| appIconId | 表示图片ID。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdsAppItem](#oh_udsappitem)


### OH_UdsAppItem_SetId()

```
int OH_UdsAppItem_SetId (OH_UdsAppItem* pThis, const char* appId )
```

**描述**

设置桌面图标类型[OH_UdsAppItem](#oh_udsappitem)对象的应用ID。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示一个指向桌面图标类型[OH_UdsAppItem](#oh_udsappitem)对象的指针。 | 
| appId | 表示应用ID。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdsAppItem](#oh_udsappitem)


### OH_UdsAppItem_SetLabelId()

```
int OH_UdsAppItem_SetLabelId (OH_UdsAppItem* pThis, const char* appLabelId )
```

**描述**

设置桌面图标类型[OH_UdsAppItem](#oh_udsappitem)对象的标签ID。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示一个指向桌面图标类型[OH_UdsAppItem](#oh_udsappitem)对象的指针。 | 
| appLabelId | 表示标签ID。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdsAppItem](#oh_udsappitem)


### OH_UdsAppItem_SetName()

```
int OH_UdsAppItem_SetName (OH_UdsAppItem* pThis, const char* appName )
```

**描述**

设置桌面图标类型[OH_UdsAppItem](#oh_udsappitem)对象的应用名称。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示一个指向桌面图标类型[OH_UdsAppItem](#oh_udsappitem)对象的指针。 | 
| appName | 表示应用名称。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdsAppItem](#oh_udsappitem)


### OH_UdsArrayBuffer_Create()

```
OH_UdsArrayBuffer* OH_UdsArrayBuffer_Create ()
```

**描述**

创建ArrayBuffer类型[OH_UdsArrayBuffer](#oh_udsarraybuffer)的实例对象以及指向它的指针。 当不再需要使用指针时，请使用[OH_UdsArrayBuffer_Destroy](#oh_udsarraybuffer_destroy)销毁实例对象，否则会导致内存泄漏。

**起始版本：** 13

**返回：**

执行成功则返回一个指向ArrayBuffer类型[OH_UdsArrayBuffer](#oh_udsarraybuffer)实例对象的指针，否则返回nullptr。

**参见：**

[OH_UdsArrayBuffer](#oh_udsarraybuffer)


### OH_UdsArrayBuffer_Destroy()

```
int OH_UdsArrayBuffer_Destroy (OH_UdsArrayBuffer* buffer)
```

**描述**

销毁ArrayBuffer类型[OH_UdsArrayBuffer](#oh_udsarraybuffer)的实例对象。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| buffer | 表示指向ArrayBuffer类型[OH_UdsArrayBuffer](#oh_udsarraybuffer)实例的指针。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdsArrayBuffer](#oh_udsarraybuffer)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdsArrayBuffer_GetData()

```
int OH_UdsArrayBuffer_GetData (OH_UdsArrayBuffer* buffer, unsigned char** data, unsigned int* len )
```

**描述**

从ArrayBuffer类型[OH_UdsArrayBuffer](#oh_udsarraybuffer)实例中获取用户自定义的ArrayBuffer数据内容。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| buffer | 表示指向ArrayBuffer类型[OH_UdsArrayBuffer](#oh_udsarraybuffer)实例的指针。 | 
| data | 该参数是输出参数，表示用户自定义的ArrayBuffer数据。 | 
| len | 该参数是输出参数，表示用户自定义的ArrayBuffer数据的大小。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdsArrayBuffer](#oh_udsarraybuffer)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdsArrayBuffer_SetData()

```
int OH_UdsArrayBuffer_SetData (OH_UdsArrayBuffer* buffer, unsigned char* data, unsigned int len )
```

**描述**

设置ArrayBuffer类型[OH_UdsArrayBuffer](#oh_udsarraybuffer)对象的数据内容。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| buffer | 表示指向ArrayBuffer类型[OH_UdsArrayBuffer](#oh_udsarraybuffer)实例的指针。 | 
| data | 表示用户自定义的ArrayBuffer数据。 | 
| len | 表示用户自定义的ArrayBuffer数据的大小。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdsArrayBuffer](#oh_udsarraybuffer)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdsFileUri_Create()

```
OH_UdsFileUri* OH_UdsFileUri_Create ()
```

**描述**

创建文件Uri类型[OH_UdsFileUri](#oh_udsfileuri)的实例对象以及指向它的指针。 当不再需要使用指针时，请使用[OH_UdsFileUri_Destroy](#oh_udsfileuri_destroy)销毁实例对象，否则会导致内存泄漏。

**起始版本：** 13

**返回：**

执行成功则返回一个指向文件Uri类型[OH_UdsFileUri](#oh_udsfileuri)实例对象的指针，否则返回nullptr。

**参见：**

[OH_UdsFileUri](#oh_udsfileuri)


### OH_UdsFileUri_Destroy()

```
void OH_UdsFileUri_Destroy (OH_UdsFileUri* pThis)
```

**描述**

销毁文件Uri类型[OH_UdsFileUri](#oh_udsfileuri)的实例对象。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向文件Uri类型[OH_UdsFileUri](#oh_udsfileuri)实例的指针。 | 

**参见：**

[OH_UdsFileUri](#oh_udsfileuri)


### OH_UdsFileUri_GetFileType()

```
const char* OH_UdsFileUri_GetFileType (OH_UdsFileUri* pThis)
```

**描述**

从文件Uri类型[OH_UdsFileUri](#oh_udsfileuri)实例中获取文件类型。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向文件Uri类型[OH_UdsFileUri](#oh_udsfileuri)实例的指针。 | 

**返回：**

输入有效入参时返回文件类型的字符串指针，否则返回nullptr。

**参见：**

[OH_UdsFileUri](#oh_udsfileuri)


### OH_UdsFileUri_GetFileUri()

```
const char* OH_UdsFileUri_GetFileUri (OH_UdsFileUri* pThis)
```

**描述**

从文件Uri类型[OH_UdsFileUri](#oh_udsfileuri)实例中获取文件Uri。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向文件Uri类型[OH_UdsFileUri](#oh_udsfileuri)实例的指针。 | 

**返回：**

输入有效入参时返回文件Uri的字符串指针，否则返回nullptr。

**参见：**

[OH_UdsFileUri](#oh_udsfileuri)


### OH_UdsFileUri_GetType()

```
const char* OH_UdsFileUri_GetType (OH_UdsFileUri* pThis)
```

**描述**

从文件Uri类型[OH_UdsFileUri](#oh_udsfileuri)实例中获取类型ID。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向文件Uri类型[OH_UdsFileUri](#oh_udsfileuri)实例的指针。 | 

**返回：**

输入有效入参时返回类型ID的字符串指针，否则返回nullptr。

**参见：**

[OH_UdsFileUri](#oh_udsfileuri)


### OH_UdsFileUri_SetFileType()

```
int OH_UdsFileUri_SetFileType (OH_UdsFileUri* pThis, const char* fileType )
```

**描述**

设置文件Uri类型[OH_UdsFileUri](#oh_udsfileuri)对象的文件类型。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向文件Uri类型[OH_UdsFileUri](#oh_udsfileuri)实例的指针。 | 
| fileType | 表示文件类型。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdsFileUri](#oh_udsfileuri)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdsFileUri_SetFileUri()

```
int OH_UdsFileUri_SetFileUri (OH_UdsFileUri* pThis, const char* fileUri )
```

**描述**

设置文件Uri类型[OH_UdsFileUri](#oh_udsfileuri)对象的Uri信息。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向文件Uri类型[OH_UdsFileUri](#oh_udsfileuri)实例的指针。 | 
| fileUri | 表示文件Uri。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdsFileUri](#oh_udsfileuri)

[Udmf_ErrCode](#udmf_errcode)


### OH_UdsHtml_Create()

```
OH_UdsHtml* OH_UdsHtml_Create ()
```

**描述**

创建超文本标记语言类型[OH_UdsHtml](#oh_udshtml)指针及实例对象。 当不再需要使用指针时，请使用[OH_UdsHtml_Destroy](#oh_udshtml_destroy)销毁实例对象，否则会导致内存泄漏。

**起始版本：** 12

**返回：**

执行成功则返回一个指向超文本标记语言类型[OH_UdsHtml](#oh_udshtml)实例对象的指针，否则返回nullptr。

**参见：**

[OH_UdsHtml](#oh_udshtml)


### OH_UdsHtml_Destroy()

```
void OH_UdsHtml_Destroy (OH_UdsHtml* pThis)
```

**描述**

销毁超文本标记语言类型[OH_UdsHtml](#oh_udshtml)指针指向的实例对象。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向超文本标记语言类型[OH_UdsHtml](#oh_udshtml)实例的指针。 | 

**参见：**

[OH_UdsHtml](#oh_udshtml)


### OH_UdsHtml_GetContent()

```
const char* OH_UdsHtml_GetContent (OH_UdsHtml* pThis)
```

**描述**

获取超文本标记语言类型[OH_UdsHtml](#oh_udshtml)对象中HTML格式内容参数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向超文本标记语言类型[OH_UdsHtml](#oh_udshtml)实例的指针。 | 

**返回：**

输入有效入参时返回HTML格式内容的字符串指针，否则返回nullptr。

**参见：**

[OH_UdsHtml](#oh_udshtml)


### OH_UdsHtml_GetPlainContent()

```
const char* OH_UdsHtml_GetPlainContent (OH_UdsHtml* pThis)
```

**描述**

获取超文本标记语言类型[OH_UdsHtml](#oh_udshtml)对象中的纯文本内容参数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向超文本标记语言类型[OH_UdsHtml](#oh_udshtml)实例的指针。 | 

**返回：**

输入有效入参时返回纯文本内容的字符串指针，否则返回nullptr。

**参见：**

[OH_UdsHtml](#oh_udshtml)


### OH_UdsHtml_GetType()

```
const char* OH_UdsHtml_GetType (OH_UdsHtml* pThis)
```

**描述**

获取超文本标记语言类型[OH_UdsHtml](#oh_udshtml)对象中类型ID。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向超文本标记语言类型[OH_UdsHtml](#oh_udshtml)实例的指针。 | 

**返回：**

输入有效入参时返回类型ID的字符串指针，否则返回nullptr。

**参见：**

[OH_UdsHtml](#oh_udshtml)


### OH_UdsHtml_SetContent()

```
int OH_UdsHtml_SetContent (OH_UdsHtml* pThis, const char* content )
```

**描述**

设置超文本标记语言类型[OH_UdsHtml](#oh_udshtml)中的HTML格式内容参数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向超文本标记语言类型[OH_UdsHtml](#oh_udshtml)实例的指针。 | 
| content | 表示HTML格式内容参数。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdsHtml](#oh_udshtml)


### OH_UdsHtml_SetPlainContent()

```
int OH_UdsHtml_SetPlainContent (OH_UdsHtml* pThis, const char* plainContent )
```

**描述**

设置超文本标记语言类型[OH_UdsHtml](#oh_udshtml)中的纯文本内容参数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向超文本标记语言类型[OH_UdsHtml](#oh_udshtml)实例的指针。 | 
| plainContent | 表示纯文本内容参数。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdsHtml](#oh_udshtml)


### OH_UdsHyperlink_Create()

```
OH_UdsHyperlink* OH_UdsHyperlink_Create ()
```

**描述**

创建超链接类型[OH_UdsHyperlink](#oh_udshyperlink)指针及实例对象。 当不再需要使用指针时，请使用[OH_UdsHyperlink_Destroy](#oh_udshyperlink_destroy)销毁实例对象，否则会导致内存泄漏。

**起始版本：** 12

**返回：**

执行则成功返回一个指向超链接类型[OH_UdsHyperlink](#oh_udshyperlink)实例对象的指针，否则返回nullptr。

**参见：**

[OH_UdsHyperlink](#oh_udshyperlink)


### OH_UdsHyperlink_Destroy()

```
void OH_UdsHyperlink_Destroy (OH_UdsHyperlink* pThis)
```

**描述**

销毁超链接类型[OH_UdsHyperlink](#oh_udshyperlink)指针指向的实例对象。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向超链接类型[OH_UdsHyperlink](#oh_udshyperlink)实例的指针。 | 

**参见：**

[OH_UdsHyperlink](#oh_udshyperlink)


### OH_UdsHyperlink_GetDescription()

```
const char* OH_UdsHyperlink_GetDescription (OH_UdsHyperlink* pThis)
```

**描述**

从超链接类型[OH_UdsHyperlink](#oh_udshyperlink)中获取描述参数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向超链接类型[OH_UdsHyperlink](#oh_udshyperlink)实例的指针。 | 

**返回：**

输入有效入参时返回描述参数的字符串指针，否则返回nullptr。

**参见：**

[OH_UdsHyperlink](#oh_udshyperlink)


### OH_UdsHyperlink_GetType()

```
const char* OH_UdsHyperlink_GetType (OH_UdsHyperlink* pThis)
```

**描述**

从超链接类型[OH_UdsHyperlink](#oh_udshyperlink)中获取类型ID。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向超链接类型[OH_UdsHyperlink](#oh_udshyperlink)实例的指针。 | 

**返回：**

输入有效入参时返回类型ID的字符串指针，否则返回nullptr。

**参见：**

[OH_UdsHyperlink](#oh_udshyperlink)


### OH_UdsHyperlink_GetUrl()

```
const char* OH_UdsHyperlink_GetUrl (OH_UdsHyperlink* pThis)
```

**描述**

从超链接类型[OH_UdsHyperlink](#oh_udshyperlink)中获取URL参数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向超链接类型[OH_UdsHyperlink](#oh_udshyperlink)实例的指针。 | 

**返回：**

输入有效入参时返回URL参数的字符串指针，否则返回nullptr。

**参见：**

[OH_UdsHyperlink](#oh_udshyperlink)


### OH_UdsHyperlink_SetDescription()

```
int OH_UdsHyperlink_SetDescription (OH_UdsHyperlink* pThis, const char* description )
```

**描述**

设置超链接类型[OH_UdsHyperlink](#oh_udshyperlink)实例中描述参数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向超链接类型[OH_UdsHyperlink](#oh_udshyperlink)实例的指针。 | 
| description | 表示描述信息。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdsHyperlink](#oh_udshyperlink)


### OH_UdsHyperlink_SetUrl()

```
int OH_UdsHyperlink_SetUrl (OH_UdsHyperlink* pThis, const char* url )
```

**描述**

设置超链接类型[OH_UdsHyperlink](#oh_udshyperlink)实例中URL参数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向超链接类型[OH_UdsHyperlink](#oh_udshyperlink)实例的指针。 | 
| url | 表示URL参数。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdsHyperlink](#oh_udshyperlink)


### OH_UdsPixelMap_Create()

```
OH_UdsPixelMap* OH_UdsPixelMap_Create ()
```

**描述**

创建像素图片类型[OH_UdsPixelMap](#oh_udspixelmap)的实例对象以及指向它的指针。 当不再需要使用指针时，请使用[OH_UdsPixelMap_Destroy](#oh_udspixelmap_destroy)销毁实例对象，否则会导致内存泄漏。

**起始版本：** 13

**返回：**

执行成功则返回一个指向像素图片类型[OH_UdsPixelMap](#oh_udspixelmap)实例对象的指针，否则返回nullptr。

**参见：**

[OH_UdsPixelMap](#oh_udspixelmap)


### OH_UdsPixelMap_Destroy()

```
void OH_UdsPixelMap_Destroy (OH_UdsPixelMap* pThis)
```

**描述**

销毁像素图片类型[OH_UdsPixelMap](#oh_udspixelmap)的实例对象。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向像素图片类型[OH_UdsPixelMap](#oh_udspixelmap)实例的指针。 | 

**参见：**

[OH_UdsPixelMap](#oh_udspixelmap)


### OH_UdsPixelMap_GetPixelMap()

```
void OH_UdsPixelMap_GetPixelMap (OH_UdsPixelMap* pThis, OH_PixelmapNative* pixelmapNative )
```

**描述**

从像素图片类型[OH_UdsPixelMap](#oh_udspixelmap)实例中获取像素图片OH_PixelmapNative实例的指针。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向像素图片类型[OH_UdsPixelMap](#oh_udspixelmap)实例的指针。 | 
| pixelmapNative | 该参数是输出参数，表示指向像素图片**OH_PixelmapNative**实例的指针。 | 

**参见：**

[OH_UdsPixelMap](#oh_udspixelmap)

OH_PixelmapNative


### OH_UdsPixelMap_GetType()

```
const char* OH_UdsPixelMap_GetType (OH_UdsPixelMap* pThis)
```

**描述**

从像素图片类型[OH_UdsPixelMap](#oh_udspixelmap)实例中获取类型ID。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向像素图片类型[OH_UdsPixelMap](#oh_udspixelmap)实例的指针。 | 

**返回：**

输入有效入参时返回类型ID的字符串指针，否则返回nullptr。

**参见：**

[OH_UdsPixelMap](#oh_udspixelmap)


### OH_UdsPixelMap_SetPixelMap()

```
int OH_UdsPixelMap_SetPixelMap (OH_UdsPixelMap* pThis, OH_PixelmapNative* pixelmapNative )
```

**描述**

设置像素图片类型[OH_UdsPixelMap](#oh_udspixelmap)对象的像素图片内容。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向像素图片类型[OH_UdsPixelMap](#oh_udspixelmap)实例的指针。 | 
| pixelmapNative | 表示指向像素图片OH_PixelmapNative实例的指针 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdsPixelMap](#oh_udspixelmap)

OH_PixelmapNative

[Udmf_ErrCode](#udmf_errcode)


### OH_UdsPlainText_Create()

```
OH_UdsPlainText* OH_UdsPlainText_Create ()
```

**描述**

创建纯文本类型[OH_UdsPlainText](#oh_udsplaintext)指针及实例对象。 当不再需要使用指针时，请使用[OH_UdsPlainText_Destroy](#oh_udsplaintext_destroy)销毁实例对象，否则会导致内存泄漏。

**起始版本：** 12

**返回：**

执行成功则返回一个指向纯文本类型[OH_UdsPlainText](#oh_udsplaintext)实例对象的指针，否则返回nullptr。

**参见：**

[OH_UdsPlainText](#oh_udsplaintext)


### OH_UdsPlainText_Destroy()

```
void OH_UdsPlainText_Destroy (OH_UdsPlainText* pThis)
```

**描述**

销毁纯文本类型数据[OH_UdsPlainText](#oh_udsplaintext)指针指向的实例对象。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向[OH_UdsPlainText](#oh_udsplaintext)实例的指针。 | 

**参见：**

[OH_UdsPlainText](#oh_udsplaintext)


### OH_UdsPlainText_GetAbstract()

```
const char* OH_UdsPlainText_GetAbstract (OH_UdsPlainText* pThis)
```

**描述**

从纯文本类型[OH_UdsPlainText](#oh_udsplaintext)中获取纯文本摘要信息。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向纯文本类型[OH_UdsPlainText](#oh_udsplaintext)实例的指针。 | 

**返回：**

输入有效入参时返回纯文本摘要信息的字符串指针，否则返回nullptr。

**参见：**

[OH_UdsPlainText](#oh_udsplaintext)


### OH_UdsPlainText_GetContent()

```
const char* OH_UdsPlainText_GetContent (OH_UdsPlainText* pThis)
```

**描述**

从纯文本类型[OH_UdsPlainText](#oh_udsplaintext)中获取纯文本内容信息。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向纯文本类型[OH_UdsPlainText](#oh_udsplaintext)实例的指针。 | 

**返回：**

输入有效入参时返回纯文本内容信息的字符串指针，否则返回nullptr。

**参见：**

[OH_UdsPlainText](#oh_udsplaintext)


### OH_UdsPlainText_GetType()

```
const char* OH_UdsPlainText_GetType (OH_UdsPlainText* pThis)
```

**描述**

从纯文本类型[OH_UdsPlainText](#oh_udsplaintext)中获取类型ID。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向纯文本类型[OH_UdsPlainText](#oh_udsplaintext)实例的指针。 | 

**返回：**

输入有效入参时返回类型ID的字符串指针，否则返回nullptr。

**参见：**

[OH_UdsPlainText](#oh_udsplaintext)


### OH_UdsPlainText_SetAbstract()

```
int OH_UdsPlainText_SetAbstract (OH_UdsPlainText* pThis, const char* abstract )
```

**描述**

设置纯文本类型[OH_UdsPlainText](#oh_udsplaintext)中的纯文本摘要参数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向纯文本类型[OH_UdsPlainText](#oh_udsplaintext)实例的指针。 | 
| abstract | 表示纯文本摘要参数。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdsPlainText](#oh_udsplaintext)


### OH_UdsPlainText_SetContent()

```
int OH_UdsPlainText_SetContent (OH_UdsPlainText* pThis, const char* content )
```

**描述**

设置纯文本类型[OH_UdsPlainText](#oh_udsplaintext)中的纯文本内容参数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向纯文本类型[OH_UdsPlainText](#oh_udsplaintext)实例的指针。 | 
| content | 表示纯文本内容参数。 | 

**返回：**

返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](#udmf_errcode)。 若返回UDMF_E_OK，表示执行成功。 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。

**参见：**

[OH_UdsPlainText](#oh_udsplaintext)


### OH_Utd_BelongsTo()

```
bool OH_Utd_BelongsTo (const char* srcTypeId, const char* destTypeId )
```

**描述**

判断两个标准化数据描述类型是否存在归属关系。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| srcTypeId | 表示原标准化数据类型。 | 
| destTypeId | 表示目标标准化数据类型。 | 

**返回：**

false表示原类型不属于目标类型；true表示原类型属于目标类型。


### OH_Utd_Create()

```
OH_Utd* OH_Utd_Create (const char* typeId)
```

**描述**

创建统一数据类型[OH_Utd](#oh_utd)指针及实例对象。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| typeId | 表示统一数据类型ID。 | 

**返回：**

执行成功则返回一个指向统一数据类型[OH_Utd](#oh_utd)实例对象的指针，否则返回nullptr。 当不再需要使用指针时，请使用[OH_Utd_Destroy](#oh_utd_destroy)销毁实例对象，否则会导致内存泄漏。

**参见：**

[OH_Utd](#oh_utd)


### OH_Utd_Destroy()

```
void OH_Utd_Destroy (OH_Utd* pThis)
```

**描述**

销毁统一数据类型[OH_Utd](#oh_utd)指针指向的实例对象。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示指向统一数据类型[OH_Utd](#oh_utd)实例的指针。 | 

**参见：**

[OH_Utd](#oh_utd)


### OH_Utd_DestroyStringList()

```
void OH_Utd_DestroyStringList (const char** list, unsigned int count )
```

**描述**

销毁标准数据描述类型结果集字符串列表。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| list | 表示字符串列表指针。 | 
| count | 表示字符串列表list参数中的列表长度。 | 


### OH_Utd_Equals()

```
bool OH_Utd_Equals (OH_Utd* utd1, OH_Utd* utd2 )
```

**描述**

判断两个标准化数据描述类型是否相等。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| desc1 | 表示一个指向标准化数据描述类型[OH_Utd](#oh_utd)对象的指针。 | 
| desc2 | 表示一个指向标准化数据描述类型[OH_Utd](#oh_utd)对象的指针。 | 

**返回：**

false表示两种类型不相等；true表示两种类型相等。


### OH_Utd_GetBelongingToTypes()

```
const char** OH_Utd_GetBelongingToTypes (OH_Utd* pThis, unsigned int* count )
```

**描述**

获取统一数据类型[OH_Utd](#oh_utd)中的归属关系结果集。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示一个指向统一数据类型[OH_Utd](#oh_utd)对象的指针。 | 
| count | 该参数是输出参数，结果集中的类型数量会写入该变量。 | 

**返回：**

当入参有效时返回归属关系结果集的字符串指针列表，否则返回nullptr。

**参见：**

[OH_Utd](#oh_utd)


### OH_Utd_GetDescription()

```
const char* OH_Utd_GetDescription (OH_Utd* pThis)
```

**描述**

获取统一数据类型[OH_Utd](#oh_utd)中的描述信息。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示一个指向统一数据类型[OH_Utd](#oh_utd)对象的指针。 | 

**返回：**

当入参有效时返回指向描述信息的字符串指针，否则返回nullptr。

**参见：**

[OH_Utd](#oh_utd)


### OH_Utd_GetFilenameExtensions()

```
const char** OH_Utd_GetFilenameExtensions (OH_Utd* pThis, unsigned int* count )
```

**描述**

获取统一数据类型[OH_Utd](#oh_utd)所关联的的文件名后缀结果集。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示一个指向统一数据类型[OH_Utd](#oh_utd)对象的指针。 | 
| count | 该参数是输出参数，结果集中的文件后缀名数量会写入该变量。 | 

**返回：**

当入参有效时返回文件文件名后缀结果集的字符串指针列表，否则返回nullptr。

**参见：**

[OH_Utd](#oh_utd)


### OH_Utd_GetIconFile()

```
const char* OH_Utd_GetIconFile (OH_Utd* pThis)
```

**描述**

获取统一数据类型[OH_Utd](#oh_utd)中的默认图标文件路径。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示一个指向统一数据类型[OH_Utd](#oh_utd)对象的指针。 | 

**返回：**

当入参有效时返回指向默认图标文件路径的字符串指针，否则返回nullptr。

**参见：**

[OH_Utd](#oh_utd)


### OH_Utd_GetMimeTypes()

```
const char** OH_Utd_GetMimeTypes (OH_Utd* pThis, unsigned int* count )
```

**描述**

获取[OH_Utd](#oh_utd)所关联的MIME类型结果集。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示一个指向统一数据类型[OH_Utd](#oh_utd)对象的指针。 | 
| count | 该参数是输出参数，结果集中的MIME类型数量会写入该变量。 | 

**返回：**

当入参有效时返回MIME类型结果集的字符串指针列表，否则返回nullptr。

**参见：**

[OH_Utd](#oh_utd)


### OH_Utd_GetReferenceUrl()

```
const char* OH_Utd_GetReferenceUrl (OH_Utd* pThis)
```

**描述**

获取统一数据类型[OH_Utd](#oh_utd)中的URL信息。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示一个指向统一数据类型[OH_Utd](#oh_utd)对象的指针。 | 

**返回：**

当入参有效时返回指向URL信息的字符串指针，否则返回nullptr。

**参见：**

[OH_Utd](#oh_utd)


### OH_Utd_GetTypeId()

```
const char* OH_Utd_GetTypeId (OH_Utd* pThis)
```

**描述**

获取统一数据类型[OH_Utd](#oh_utd)中的类型ID。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pThis | 表示一个指向统一数据类型[OH_Utd](#oh_utd)对象的指针。 | 

**返回：**

当入参有效时返回指向类型ID的字符串指针，否则返回nullptr。

**参见：**

[OH_Utd](#oh_utd)


### OH_Utd_GetTypesByFilenameExtension()

```
const char** OH_Utd_GetTypesByFilenameExtension (const char* extension, unsigned int* count )
```

**描述**

通过文件名后缀获取关联的统一标准数据描述类型结果集。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| extension | 表示文件名后缀。 | 
| count | 该参数是输出参数，结果集中的类型数量会写入该变量。 | 

**返回：**

返回标准数据描述类型结果集字符串列表。 当不再需要使用指针时，请及时使用[OH_Utd_DestroyStringList](#oh_utd_destroystringlist)销毁对应的实例，否则会导致内存泄漏。


### OH_Utd_GetTypesByMimeType()

```
const char** OH_Utd_GetTypesByMimeType (const char* mimeType, unsigned int* count )
```

**描述**

通过MIME类型获取所关联的标准数据类型结果集。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mimeType | 表示MIME类型字符串。 | 
| count | 该参数是输出参数，结果集中的类型数量会写入该变量。 | 

**返回：**

返回标准数据描述类型结果集字符串列表。 当不再需要使用指针时，请及时使用[OH_Utd_DestroyStringList](#oh_utd_destroystringlist)销毁对应的实例，否则会导致内存泄漏。


### OH_Utd_IsHigher()

```
bool OH_Utd_IsHigher (const char* srcTypeId, const char* destTypeId )
```

**描述**

判断原标准化数据类型是否是目标标准化数据类型的高层级类型。 例如SOURCE_CODE为TYPE_SCRIPT的高层级类型，PLAIN_TEXT为SOURCE_CODE和TYPE_SCRIPT的高层级类型。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| srcTypeId | 表示原标准化数据类型。 | 
| destTypeId | 表示目标标准化数据类型。 | 

**返回：**

false表示原类型不高于目标类型；true表示原类型高于目标类型。


### OH_Utd_IsLower()

```
bool OH_Utd_IsLower (const char* srcTypeId, const char* destTypeId )
```

**描述**

判断原标准化数据类型是否是目标标准化数据类型的低层级类型。 例如TYPE_SCRIPT为SOURCE_CODE的低层级类型，TYPE_SCRIPT和SOURCE_CODE为PLAIN_TEXT的低层级类型。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| srcTypeId | 表示原标准化数据类型。 | 
| destTypeId | 表示目标标准化数据类型。 | 

**返回：**

false表示原类型不低于目标类型；true表示原类型低于目标类型。