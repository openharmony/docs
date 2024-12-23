# udmf_meta.h


## 概述

声明统一类型数据信息。

**引用文件：**&lt;database/udmf/udmf_meta.h&gt;

**库：** libudmf.so

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

**起始版本：** 12

**相关模块：**[UDMF](_u_d_m_f.md)


## 汇总


### 宏定义

| 名称 | 描述 | 
| -------- | -------- |
| [UDMF_META_ENTITY](_u_d_m_f.md#udmf_meta_entity)   "general.entity" | 所有表示物理存储类型的基类型，用于描述类型的物理属性，无归属类型。 | 
| [UDMF_META_OBJECT](_u_d_m_f.md#udmf_meta_object)   "general.object" | 所有表示逻辑内容类型的基类型，用于描述类型的功能性特征，无归属类型。 | 
| [UDMF_META_COMPOSITE_OBJECT](_u_d_m_f.md#udmf_meta_composite_object)   "general.composite-object" | 所有组合内容类型（例如PDF文件类型混合了文本和图片类数据）的基类型，归属类型为OBJECT。 | 
| [UDMF_META_TEXT](_u_d_m_f.md#udmf_meta_text)   "general.text" | 所有文本的基类型，归属类型为OBJECT。 | 
| [UDMF_META_PLAIN_TEXT](_u_d_m_f.md#udmf_meta_plain_text)   "general.plain-text" | 未指定编码的文本类型，没有标识符，归属类型为TEXT。 | 
| [UDMF_META_HTML](_u_d_m_f.md#udmf_meta_html)   "general.html" | HTML文本类型，归属类型为TEXT。 | 
| [UDMF_META_HYPERLINK](_u_d_m_f.md#udmf_meta_hyperlink)   "general.hyperlink" | 超链接类型，归属类型为TEXT。 | 
| [UDMF_META_XML](_u_d_m_f.md#udmf_meta_xml)   "general.xml" | XML文本类型，归属类型为TEXT。 | 
| [UDMF_META_SOURCE_CODE](_u_d_m_f.md#udmf_meta_source_code)   "general.source-code" | 所有源代码的基类型，归属类型为PLAIN_TEXT。 | 
| [UDMF_META_SCRIPT](_u_d_m_f.md#udmf_meta_script)   "general.script" | 所有脚本语言源代码的基类型，归属类型为SOURCE_CODE。 | 
| [UDMF_META_SHELL_SCRIPT](_u_d_m_f.md#udmf_meta_shell_script)   "general.shell-script" | Shell脚本类型，归属类型为SCRIPT。 | 
| [UDMF_META_CSH_SCRIPT](_u_d_m_f.md#udmf_meta_csh_script)   "general.csh-script" | C-shell脚本类型，归属类型为SHELL_SCRIPT。 | 
| [UDMF_META_PERL_SCRIPT](_u_d_m_f.md#udmf_meta_perl_script)   "general.perl-script" | Perl脚本类型，归属类型为SHELL_SCRIPT。 | 
| [UDMF_META_PHP_SCRIPT](_u_d_m_f.md#udmf_meta_php_script)   "general.php-script" | PHP脚本类型，归属类型为SHELL_SCRIPT。 | 
| [UDMF_META_PYTHON_SCRIPT](_u_d_m_f.md#udmf_meta_python_script)   "general.python-script" | Python脚本类型，归属类型为SHELL_SCRIPT。 | 
| [UDMF_META_RUBY_SCRIPT](_u_d_m_f.md#udmf_meta_ruby_script)   "general.ruby-script" | Ruby脚本类型，归属类型为SHELL_SCRIPT。 | 
| [UDMF_META_TYPE_SCRIPT](_u_d_m_f.md#udmf_meta_type_script)   "general.type-script" | TypeScript源代码类型，归属类型为SCRIPT。 | 
| [UDMF_META_JAVA_SCRIPT](_u_d_m_f.md#udmf_meta_java_script)   "general.java-script" | JavaScript源代码类型，归属类型为SCRIPT。 | 
| [UDMF_META_C_HEADER](_u_d_m_f.md#udmf_meta_c_header)   "general.c-header" | C头文件类型，归属类型为SOURCE_CODE。 | 
| [UDMF_META_C_SOURCE](_u_d_m_f.md#udmf_meta_c_source)   "general.c-source" | C源代码类型，归属类型为SOURCE_CODE。 | 
| [UDMF_META_C_PLUS_PLUS_HEADER](_u_d_m_f.md#udmf_meta_c_plus_plus_header)   "general.c-plus-plus-header" | C++头文件类型，归属类型为SOURCE_CODE。 | 
| [UDMF_META_C_PLUS_PLUS_SOURCE](_u_d_m_f.md#udmf_meta_c_plus_plus_source)   "general.c-plus-plus-source" | C++源代码类型，归属类型为SOURCE_CODE。 | 
| [UDMF_META_JAVA_SOURCE](_u_d_m_f.md#udmf_meta_java_source)   "general.java-source" | Java源代码类型，归属类型为SOURCE_CODE。 | 
| [UDMF_META_EBOOK](_u_d_m_f.md#udmf_meta_ebook)   "general.ebook" | 所有电子书文件格式的基类型，归属类型为COMPOSITE_OBJECT。 | 
| [UDMF_META_EPUB](_u_d_m_f.md#udmf_meta_epub)   "general.epub" | 电子出版物（EPUB）文件格式类型，归属类型为EBOOK。 | 
| [UDMF_META_AZW](_u_d_m_f.md#udmf_meta_azw)   "com.amazon.azw" | AZW电子书文件格式类型，归属类型为EBOOK。 | 
| [UDMF_META_AZW3](_u_d_m_f.md#udmf_meta_azw3)   "com.amazon.azw3" | AZW3电子书文件格式类型，归属类型为EBOOK。 | 
| [UDMF_META_KFX](_u_d_m_f.md#udmf_meta_kfx)   "com.amazon.kfx" | KFX电子书文件格式类型，归属类型为EBOOK。 | 
| [UDMF_META_MOBI](_u_d_m_f.md#udmf_meta_mobi)   "com.amazon.mobi" | MOBI电子书文件格式类型，归属类型为EBOOK。 | 
| [UDMF_META_MEDIA](_u_d_m_f.md#udmf_meta_media)   "general.media" | 所有媒体的基类型，归属类型为OBJECT。 | 
| [UDMF_META_IMAGE](_u_d_m_f.md#udmf_meta_image)   "general.image" | 所有图片的基类型，归属类型为MEDIA。 | 
| [UDMF_META_JPEG](_u_d_m_f.md#udmf_meta_jpeg)   "general.jpeg" | JPEG图片类型，归属类型为IMAGE。 | 
| [UDMF_META_PNG](_u_d_m_f.md#udmf_meta_png)   "general.png" | PNG图片类型，归属类型为IMAGE。 | 
| [UDMF_META_RAW_IMAGE](_u_d_m_f.md#udmf_meta_raw_image)   "general.raw-image" | 所有原始图像格式的基类型，归属类型为IMAGE。 | 
| [UDMF_META_TIFF](_u_d_m_f.md#udmf_meta_tiff)   "general.tiff" | TIFF图片类型，归属类型为IMAGE。 | 
| [UDMF_META_BMP](_u_d_m_f.md#udmf_meta_bmp)   "com.microsoft.bmp" | WINDOWS位图图像类型，归属类型为IMAGE。 | 
| [UDMF_META_ICO](_u_d_m_f.md#udmf_meta_ico)   "com.microsoft.ico" | WINDOWS图标图像类型，归属类型为IMAGE。 | 
| [UDMF_META_PHOTOSHOP_IMAGE](_u_d_m_f.md#udmf_meta_photoshop_image)   "com.adobe.photoshop-image" | Adobe Photoshop图片类型，归属类型为IMAGE。 | 
| [UDMF_META_AI_IMAGE](_u_d_m_f.md#udmf_meta_ai_image)   "com.adobe.illustrator.ai-image" | Adobe Illustrator图片类型，归属类型为IMAGE。 | 
| [UDMF_META_WORD_DOC](_u_d_m_f.md#udmf_meta_word_doc)   "com.microsoft.word.doc" | Microsoft Word数据类型，归属类型为COMPOSITE_OBJECT。 | 
| [UDMF_META_EXCEL](_u_d_m_f.md#udmf_meta_excel)   "com.microsoft.excel.xls" | Microsoft Excel数据类型，归属类型为COMPOSITE_OBJECT。 | 
| [UDMF_META_PPT](_u_d_m_f.md#udmf_meta_ppt)   "com.microsoft.powerpoint.ppt" | Microsoft PowerPoint演示文稿类型，归属类型为COMPOSITE_OBJECT。 | 
| [UDMF_META_PDF](_u_d_m_f.md#udmf_meta_pdf)   "com.adobe.pdf" | PDF数据类型，归属类型为COMPOSITE_OBJECT。 | 
| [UDMF_META_POSTSCRIPT](_u_d_m_f.md#udmf_meta_postscript)   "com.adobe.postscript" | PostScript数据类型，归属类型为COMPOSITE_OBJECT。 | 
| [UDMF_META_ENCAPSULATED_POSTSCRIPT](_u_d_m_f.md#udmf_meta_encapsulated_postscript)   "com.adobe.encapsulated-postscript" | Encapsulated PostScript类型，归属类型为POSTSCRIPT。 | 
| [UDMF_META_VIDEO](_u_d_m_f.md#udmf_meta_video)   "general.video" | 所有视频的基类型，归属类型为MEDIA。 | 
| [UDMF_META_AVI](_u_d_m_f.md#udmf_meta_avi)   "general.avi" | AVI视频类型，归属类型为VIDEO。 | 
| [UDMF_META_MPEG](_u_d_m_f.md#udmf_meta_mpeg)   "general.mpeg" | MPGE-1或MPGE-2视频类型，归属类型为VIDEO。 | 
| [UDMF_META_MPEG4](_u_d_m_f.md#udmf_meta_mpeg4)   "general.mpeg-4" | MPGE-4视频类型，归属类型为VIDEO。 | 
| [UDMF_META_VIDEO_3GPP](_u_d_m_f.md#udmf_meta_video_3gpp)   "general.3gpp" | 3GPP视频类型，归属类型为VIDEO。 | 
| [UDMF_META_VIDEO_3GPP2](_u_d_m_f.md#udmf_meta_video_3gpp2)   "general.3gpp2" | 3GPP2视频类型，归属类型为VIDEO。 | 
| [UDMF_META_WINDOWS_MEDIA_WM](_u_d_m_f.md#udmf_meta_windows_media_wm)   "com.microsoft.windows-media-wm" | WINDOWS WM视频类型，归属类型为VIDEO。 | 
| [UDMF_META_WINDOWS_MEDIA_WMV](_u_d_m_f.md#udmf_meta_windows_media_wmv)   "com.microsoft.windows-media-wmv" | WINDOWS WMV视频类型，归属类型为VIDEO。 | 
| [UDMF_META_WINDOWS_MEDIA_WMP](_u_d_m_f.md#udmf_meta_windows_media_wmp)   "com.microsoft.windows-media-wmp" | WINDOWS WMP视频类型，归属类型为VIDEO。 | 
| [UDMF_META_AUDIO](_u_d_m_f.md#udmf_meta_audio)   "general.audio" | 所有音频的基类型，归属类型为MEDIA | 
| [UDMF_META_AAC](_u_d_m_f.md#udmf_meta_aac)   "general.aac" | AAC音频类型，归属类型为AUDIO。 | 
| [UDMF_META_AIFF](_u_d_m_f.md#udmf_meta_aiff)   "general.aiff" | AIFF音频类型，归属类型为AUDIO。 | 
| [UDMF_META_ALAC](_u_d_m_f.md#udmf_meta_alac)   "general.alac" | ALAC音频类型，归属类型为AUDIO。 | 
| [UDMF_META_FLAC](_u_d_m_f.md#udmf_meta_flac)   "general.flac" | FLAC音频类型，归属类型为AUDIO。 | 
| [UDMF_META_MP3](_u_d_m_f.md#udmf_meta_mp3)   "general.mp3" | MP3音频类型，归属类型为AUDIO。 | 
| [UDMF_META_OGG](_u_d_m_f.md#udmf_meta_ogg)   "general.ogg" | OGG音频类型，归属类型为AUDIO。 | 
| [UDMF_META_PCM](_u_d_m_f.md#udmf_meta_pcm)   "general.pcm" | PCM音频类型，归属类型为AUDIO。 | 
| [UDMF_META_WINDOWS_MEDIA_WMA](_u_d_m_f.md#udmf_meta_windows_media_wma)   "com.microsoft.windows-media-wma" | WINDOWS WMA音频类型，归属类型为AUDIO。 | 
| [UDMF_META_WAVEFORM_AUDIO](_u_d_m_f.md#udmf_meta_waveform_audio)   "com.microsoft.waveform-audio" | WINDOWS波形音频类型，归属类型为AUDIO。 | 
| [UDMF_META_WINDOWS_MEDIA_WMX](_u_d_m_f.md#udmf_meta_windows_media_wmx)   "com.microsoft.windows-media-wmx" | WINDOWS WMX视频类型，归属类型为VIDEO。 | 
| [UDMF_META_WINDOWS_MEDIA_WVX](_u_d_m_f.md#udmf_meta_windows_media_wvx)   "com.microsoft.windows-media-wvx" | WINDOWS WVX视频类型，归属类型为VIDEO。 | 
| [UDMF_META_WINDOWS_MEDIA_WAX](_u_d_m_f.md#udmf_meta_windows_media_wax)   "com.microsoft.windows-media-wax" | WINDOWS WAX音频类型，归属类型为AUDIO。 | 
| [UDMF_META_GENERAL_FILE](_u_d_m_f.md#udmf_meta_general_file)   "general.file" | 所有文件的基类型，归属类型为ENTITY。 | 
| [UDMF_META_DIRECTORY](_u_d_m_f.md#udmf_meta_directory)   "general.directory" | 所有目录的基类型，归属类型为ENTITY。 | 
| [UDMF_META_FOLDER](_u_d_m_f.md#udmf_meta_folder)   "general.folder" | 所有文件夹的基类型，归属类型为DIRECTORY。 | 
| [UDMF_META_SYMLINK](_u_d_m_f.md#udmf_meta_symlink)   "general.symlink" | 所有符号链接的基类型，归属类型为ENTITY。 | 
| [UDMF_META_ARCHIVE](_u_d_m_f.md#udmf_meta_archive)   "general.archive" | 所有文件和目录存档文件的基类型，归属类型为OBJECT。 | 
| [UDMF_META_BZ2_ARCHIVE](_u_d_m_f.md#udmf_meta_bz2_archive)   "general.bz2-archive" | BZ2存档文件类型，归属类型为ARCHIVE。 | 
| [UDMF_META_DISK_IMAGE](_u_d_m_f.md#udmf_meta_disk_image)   "general.disk-image" | 所有可作为卷装载项的文件类型的基类型，归属类型为ARCHIVE。 | 
| [UDMF_META_TAR_ARCHIVE](_u_d_m_f.md#udmf_meta_tar_archive)   "general.tar-archive" | TAR存档文件类型，归属类型为ARCHIVE。 | 
| [UDMF_META_ZIP_ARCHIVE](_u_d_m_f.md#udmf_meta_zip_archive)   "general.zip-archive" | ZIP存档文件类型，归属类型为ARCHIVE。 | 
| [UDMF_META_JAVA_ARCHIVE](_u_d_m_f.md#udmf_meta_java_archive)   "com.sun.java-archive" | JAVA存档文件类型，归属类型为ARCHIVE和EXECUTABLE。 | 
| [UDMF_META_GNU_TAR_ARCHIVE](_u_d_m_f.md#udmf_meta_gnu_tar_archive)   "org.gnu.gnu-tar-archive" | GUN存档文件类型，归属类型为ARCHIVE。 | 
| [UDMF_META_GNU_ZIP_ARCHIVE](_u_d_m_f.md#udmf_meta_gnu_zip_archive)   "org.gnu.gnu-zip-archive" | GZIP存档文件类型，归属类型为ARCHIVE。 | 
| [UDMF_META_GNU_ZIP_TAR_ARCHIVE](_u_d_m_f.md#udmf_meta_gnu_zip_tar_archive)   "org.gnu.gnu-zip-tar-archive" | GZIP TAR存档文件类型，归属类型为ARCHIVE。 | 
| [UDMF_META_CALENDAR](_u_d_m_f.md#udmf_meta_calendar)   "general.calendar" | 所有日程类数据的基类型，归属类型为OBJECT。 | 
| [UDMF_META_CONTACT](_u_d_m_f.md#udmf_meta_contact)   "general.contact" | 所有联系人类数据的基类型，归属类型为OBJECT。 | 
| [UDMF_META_DATABASE](_u_d_m_f.md#udmf_meta_database)   "general.database" | 所有数据库文件的基类型，归属类型为OBJECT。 | 
| [UDMF_META_MESSAGE](_u_d_m_f.md#udmf_meta_message)   "general.message" | 所有消息类数据的基类型，归属类型为OBJECT。 | 
| [UDMF_META_VCARD](_u_d_m_f.md#udmf_meta_vcard)   "general.vcard" | 所有电子名片类数据的基类型，归属类型为OBJECT。 | 
| [UDMF_META_NAVIGATION](_u_d_m_f.md#udmf_meta_navigation)   "general.navigation" | 所有导航类数据的基类型，归属类型为OBJECT。 | 
| [UDMF_META_LOCATION](_u_d_m_f.md#udmf_meta_location)   "general.location" | 导航定位类型，归属类型为NAVIGATION。 | 
| [UDMF_META_OPENHARMONY_FORM](_u_d_m_f.md#udmf_meta_openharmony_form)   "openharmony.form" | 系统定义的卡片类型，归属类型为OBJECT。 | 
| [UDMF_META_OPENHARMONY_APP_ITEM](_u_d_m_f.md#udmf_meta_openharmony_app_item)   "openharmony.app-item" | 系统定义的桌面图标类型，归属类型为OBJECT。 | 
| [UDMF_META_OPENHARMONY_PIXEL_MAP](_u_d_m_f.md#udmf_meta_openharmony_pixel_map)   "openharmony.pixel-map" | 系统定义的像素图类型，归属类型为IMAGE。 | 
| [UDMF_META_OPENHARMONY_ATOMIC_SERVICE](_u_d_m_f.md#udmf_meta_openharmony_atomic_service)   "openharmony.atomic-service" | 系统定义的原子化服务类型，归属类型为OBJECT。 | 
| [UDMF_META_OPENHARMONY_PACKAGE](_u_d_m_f.md#udmf_meta_openharmony_package)   "openharmony.package" | 系统定义的包（即目录的打包文件），归属类型为DIRECTORY。 | 
| [UDMF_META_OPENHARMONY_HAP](_u_d_m_f.md#udmf_meta_openharmony_hap)   "openharmony.hap" | 系统定义的能力包，归属类型为OPENHARMONY_PACKAGE。 | 
| [UDMF_META_SMIL](_u_d_m_f.md#udmf_meta_smil)   "com.real.smil" | 同步多媒体集成语言类型，归属类型为XML文本类型。 | 
| [UDMF_META_MARKDOWN](_u_d_m_f.md#udmf_meta_markdown)   "general.markdown" | 标记语言文本类型，归属类型为PLAIN_TEXT。 | 
| [UDMF_META_FAX](_u_d_m_f.md#udmf_meta_fax)   "general.fax" | 传真图像的基本类型，归属类型为IMAGE。 | 
| [UDMF_META_JFX_FAX](_u_d_m_f.md#udmf_meta_jfx_fax)   "com.j2.jfx-fax" | J2 jConnect传真文件类型，归属类型为FAX。 | 
| [UDMF_META_EFX_FAX](_u_d_m_f.md#udmf_meta_efx_fax)   "com.js.efx-fax" | 电子传真文件类型，归属类型为FAX。 | 
| [UDMF_META_XBITMAP_IMAGE](_u_d_m_f.md#udmf_meta_xbitmap_image)   "general.xbitmap-image" | X Window系统（X11）中使用的位图图像格式，归属类型为IMAGE。 | 
| [UDMF_META_TGA_IMAGE](_u_d_m_f.md#udmf_meta_tga_image)   "com.truevision.tga-image" | 标签图形（TaggedGraphics）图像类型，归属类型为IMAGE。 | 
| [UDMF_META_SGI_IMAGE](_u_d_m_f.md#udmf_meta_sgi_image)   "com.sgi.sgi-image" | 硅图（Silicon Graphics）图像类型，归属类型为IMAGE。 | 
| [UDMF_META_OPENEXR_IMAGE](_u_d_m_f.md#udmf_meta_openexr_image)   "com.ilm.openexr-image" | 开放标准的高动态范围图像格式类型，归属类型为IMAGE。 | 
| [UDMF_META_FLASHPIX_IMAGE](_u_d_m_f.md#udmf_meta_flashpix_image)   "com.kodak.flashpix.image" | FlashPix图像文件类型，归属类型为IMAGE。 | 
| [UDMF_META_REALMEDIA](_u_d_m_f.md#udmf_meta_realmedia)   "com.real.realmedia" | 流媒体视频类型，归属类型为VIDEO。 | 
| [UDMF_META_AU_AUDIO](_u_d_m_f.md#udmf_meta_au_audio)   "general.au-audio" | Au数据格式，归属类型为AUDIO。 | 
| [UDMF_META_AIFC_AUDIO](_u_d_m_f.md#udmf_meta_aifc_audio)   "general.aifc-audio" | 音频交换数据类型，归属类型为AUDIO。 | 
| [UDMF_META_SD2_AUDIO](_u_d_m_f.md#udmf_meta_sd2_audio)   "com.digidesign.sd2-audio" | 单声道/立体声音频类型（Digidesign Sound Designer II），归属类型为AUDIO。 | 
| [UDMF_META_REALAUDIO](_u_d_m_f.md#udmf_meta_realaudio)   "com.real.realaudio" | RealMedia音频类型，归属类型为AUDIO。 | 
| [UDMF_META_OPENXML](_u_d_m_f.md#udmf_meta_openxml)   "org.openxmlformats.openxml" | 开源XML基类型，归属类型为ARCHIVE。 | 
| [UDMF_META_WORDPROCESSINGML_DOCUMENT](_u_d_m_f.md#udmf_meta_wordprocessingml_document)   "org.openxmlformats.wordprocessingml.document" | 开源XML文档类型，归属类型为OPENXML和COMPOSITE_OBJECT。 | 
| [UDMF_META_SPREADSHEETML_SHEET](_u_d_m_f.md#udmf_meta_spreadsheetml_sheet)   "org.openxmlformats.spreadsheetml.sheet" | 开源XML电子表格类型，归属类型为OPENXML和COMPOSITE_OBJECT。 | 
| [UDMF_META_PRESENTATIONML_PRESENTATION](_u_d_m_f.md#udmf_meta_presentationml_presentation)   "org.openxmlformats.presentationml.presentation" | 开源XML演示文稿类型，归属类型为OPENXML和COMPOSITE_OBJECT。 | 
| [UDMF_META_OPENDOCUMENT](_u_d_m_f.md#udmf_meta_opendocument)   "org.oasis.opendocument" | Office应用程序的开源文档类型，归属类型为ARCHIVE。 | 
| [UDMF_META_OPENDOCUMENT_TEXT](_u_d_m_f.md#udmf_meta_opendocument_text)   "org.oasis.opendocument.text" | 开源文档类型，归属类型为OPENDOCUMENT和COMPOSITE_OBJECT。 | 
| [UDMF_META_OPENDOCUMENT_SPREADSHEET](_u_d_m_f.md#udmf_meta_opendocument_spreadsheet)   "org.oasis.opendocument.spreadsheet" | 开源文档电子表格类型，归属类型为OPENDOCUMENT和COMPOSITE_OBJECT。 | 
| [UDMF_META_OPENDOCUMENT_PRESENTATION](_u_d_m_f.md#udmf_meta_opendocument_presentation)   "org.oasis.opendocument.presentation" | 开源文档演示类型，归属类型为OPENDOCUMENT和COMPOSITE_OBJECT。 | 
| [UDMF_META_OPENDOCUMENT_GRAPHICS](_u_d_m_f.md#udmf_meta_opendocument_graphics)   "org.oasis.opendocument.graphics" | 开源文档图形类型，归属类型为OPENDOCUMENT和COMPOSITE_OBJECT。 | 
| [UDMF_META_OPENDOCUMENT_FORMULA](_u_d_m_f.md#udmf_meta_opendocument_formula)   "org.oasis.opendocument.formula" | 开源文档公式集类型，归属类型为OPENDOCUMENT。 | 
| [UDMF_META_STUFFIT_ARCHIVE](_u_d_m_f.md#udmf_meta_stuffit_archive)   "com.allume.stuffit-archive" | Stuffit压缩格式类型（Stuffit archive），归属类型为ARCHIVE。 | 
| [UDMF_META_VCS](_u_d_m_f.md#udmf_meta_vcs)   "general.vcs" | VCalendar日历数据类型，归属类型为CALENDAR和TEXT。 | 
| [UDMF_META_ICS](_u_d_m_f.md#udmf_meta_ics)   "general.ics" | ICalendar日历数据类型，归属类型为CALENDAR和TEXT。 | 
| [UDMF_META_EXECUTABLE](_u_d_m_f.md#udmf_meta_executable)   "general.executable" | 所有可执行文件的基类型，归属类型为OBJECT。 | 
| [UDMF_META_PORTABLE_EXECUTABLE](_u_d_m_f.md#udmf_meta_portable_executable)   "com.microsoft.portable-executable" | Microsoft Windows应用程序类型，归属类型为EXECUTABLE。 | 
| [UDMF_META_SUN_JAVA_CLASS](_u_d_m_f.md#udmf_meta_sun_java_class)   "com.sun.java-class" | Java类文件类型，归属类型为EXECUTABLE。 | 
| [UDMF_META_FONT](_u_d_m_f.md#udmf_meta_font)   "general.font" | 所有字体数据类型的基础类型，归属类型为OBJECT。 | 
| [UDMF_META_TRUETYPE_FONT](_u_d_m_f.md#udmf_meta_truetype_font)   "general.truetype-font" | TrueType字体类型，归属类型为FONT。 | 
| [UDMF_META_TRUETYPE_COLLECTION_FONT](_u_d_m_f.md#udmf_meta_truetype_collection_font)   "general.truetype-collection-font" | TrueType collection字体类型，归属类型为FONT。 | 
| [UDMF_META_OPENTYPE_FONT](_u_d_m_f.md#udmf_meta_opentype_font)   "general.opentype-font" | OpenType字体类型，归属类型为FONT。 | 
| [UDMF_META_POSTSCRIPT_FONT](_u_d_m_f.md#udmf_meta_postscript_font)   "com.adobe.postscript-font" | PostScript字体类型，归属类型为FONT。 | 
| [UDMF_META_POSTSCRIPT_PFB_FONT](_u_d_m_f.md#udmf_meta_postscript_pfb_font)   "com.adobe.postscript-pfb-font" | PostScript Font Binary字体类型，归属类型为FONT。 | 
| [UDMF_META_POSTSCRIPT_PFA_FONT](_u_d_m_f.md#udmf_meta_postscript_pfa_font)   "com.adobe.postscript-pfa-font" | Adobe Type 1 字体类型，归属类型为FONT。 | 
| [UDMF_META_OPENHARMONY_HDOC](_u_d_m_f.md#udmf_meta_openharmony_hdoc)   "openharmony.hdoc" | 系统定义的备忘录数据类型，归属类型为COMPOSITE_OBJECT。 | 
| [UDMF_META_OPENHARMONY_HINOTE](_u_d_m_f.md#udmf_meta_openharmony_hinote)   "openharmony.hinote" | 系统定义的笔记数据类型，归属类型为COMPOSITE_OBJECT。 | 
| [UDMF_META_OPENHARMONY_STYLED_STRING](_u_d_m_f.md#udmf_meta_openharmony_styled_string)   "openharmony.styled-string" | 系统定义的样式字符串类型，归属类型为COMPOSITE_OBJECT。 | 
| [UDMF_META_OPENHARMONY_WANT](_u_d_m_f.md#udmf_meta_openharmony_want)   "openharmony.want" | 系统定义的Want类型，归属类型为OBJECT。 | 
| [UDMF_META_GENERAL_FILE_URI](_u_d_m_f.md#udmf_meta_general_file_uri)&nbsp;&nbsp;&nbsp;"general.file-uri" | 文件地址类型，归属类型为TEXT。<br/>从API version 13开始支持。 |
| [UDMF_METE_GENERAL_CONTENT_FORM](_u_d_m_f.md#udmf_mete_general_content_form)   "general.content-form" | 内容卡片类型，归属类型为OBJECT。 |  