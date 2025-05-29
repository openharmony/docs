# udmf_meta.h


## Overview

Declares the uniform data types.

**File to include**: &lt;database/udmf/udmf_meta.h&gt;

**Library**: libudmf.so

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Since**: 12

**Related module**: [UDMF](_u_d_m_f.md)


## Summary


### Macros

| Name| Description| 
| -------- | -------- |
| [UDMF_META_ENTITY](_u_d_m_f.md#udmf_meta_entity)   "general.entity" | Generic type that represents all physical storage types. It is used to define physical properties of a type.<br>This type is uncategorized.| 
| [UDMF_META_OBJECT](_u_d_m_f.md#udmf_meta_object)   "general.object" | Generic type that represents all logical content types. It is used to define physical properties of a type.<br>This type is uncategorized.| 
| [UDMF_META_COMPOSITE_OBJECT](_u_d_m_f.md#udmf_meta_composite_object)   "general.composite-object" | Generic composite content type. For example, a PDF file that contains text and image.<br>This type belongs to **OBJECT**.| 
| [UDMF_META_TEXT](_u_d_m_f.md#udmf_meta_text)   "general.text" | Generic text type.<br>This type belongs to **OBJECT**.| 
| [UDMF_META_PLAIN_TEXT](_u_d_m_f.md#udmf_meta_plain_text)   "general.plain-text" | Text without specific encoding or identifier.<br>This type belongs to **TEXT**.| 
| [UDMF_META_HTML](_u_d_m_f.md#udmf_meta_html)   "general.html" | HTML.<br>This type belongs to **TEXT**.| 
| [UDMF_META_HYPERLINK](_u_d_m_f.md#udmf_meta_hyperlink)   "general.hyperlink" | Hyperlink.<br>This type belongs to **TEXT**.| 
| [UDMF_META_XML](_u_d_m_f.md#udmf_meta_xml)   "general.xml" | XML.<br>This type belongs to **TEXT**.| 
| [UDMF_META_SOURCE_CODE](_u_d_m_f.md#udmf_meta_source_code)   "general.source-code" | Generic source code type.<br>This type belongs to **PLAIN_TEXT**.| 
| [UDMF_META_SCRIPT](_u_d_m_f.md#udmf_meta_script)   "general.script" | Source code in any scripting language.<br>This type belongs to **SOURCE_CODE**.| 
| [UDMF_META_SHELL_SCRIPT](_u_d_m_f.md#udmf_meta_shell_script)   "general.shell-script" | Shell script.<br>This type belongs to **SCRIPT**.| 
| [UDMF_META_CSH_SCRIPT](_u_d_m_f.md#udmf_meta_csh_script)   "general.csh-script" | C shell script.<br>This type belongs to **SHELL_SCRIPT**.| 
| [UDMF_META_PERL_SCRIPT](_u_d_m_f.md#udmf_meta_perl_script)   "general.perl-script" | Perl script.<br>This type belongs to **SHELL_SCRIPT**.| 
| [UDMF_META_PHP_SCRIPT](_u_d_m_f.md#udmf_meta_php_script)   "general.php-script" | PHP script.<br>This type belongs to **SHELL_SCRIPT**.| 
| [UDMF_META_PYTHON_SCRIPT](_u_d_m_f.md#udmf_meta_python_script)   "general.python-script" | Python script.<br>This type belongs to **SHELL_SCRIPT**.| 
| [UDMF_META_RUBY_SCRIPT](_u_d_m_f.md#udmf_meta_ruby_script)   "general.ruby-script" | Ruby script.<br>This type belongs to **SHELL_SCRIPT**.| 
| [UDMF_META_TYPE_SCRIPT](_u_d_m_f.md#udmf_meta_type_script)   "general.type-script" | TypeScript source code.<br>This type belongs to **SCRIPT**.| 
| [UDMF_META_JAVA_SCRIPT](_u_d_m_f.md#udmf_meta_java_script)   "general.java-script" | JavaScript source code.<br>This type belongs to **SCRIPT**.| 
| [UDMF_META_C_HEADER](_u_d_m_f.md#udmf_meta_c_header)   "general.c-header" | Header file in C.<br>This type belongs to **SOURCE_CODE**.| 
| [UDMF_META_C_SOURCE](_u_d_m_f.md#udmf_meta_c_source)   "general.c-source" | Source code in C.<br>This type belongs to **SOURCE_CODE**.| 
| [UDMF_META_C_PLUS_PLUS_HEADER](_u_d_m_f.md#udmf_meta_c_plus_plus_header)   "general.c-plus-plus-header" | Header file in C++.<br>This type belongs to **SOURCE_CODE**.| 
| [UDMF_META_C_PLUS_PLUS_SOURCE](_u_d_m_f.md#udmf_meta_c_plus_plus_source)   "general.c-plus-plus-source" | Source code in C++.<br>This type belongs to **SOURCE_CODE**.| 
| [UDMF_META_JAVA_SOURCE](_u_d_m_f.md#udmf_meta_java_source)   "general.java-source" | Source code in Java.<br>This type belongs to **SOURCE_CODE**.| 
| [UDMF_META_EBOOK](_u_d_m_f.md#udmf_meta_ebook)   "general.ebook" | Generic eBook file format type.<br>This type belongs to **COMPOSITE_OBJECT**.| 
| [UDMF_META_EPUB](_u_d_m_f.md#udmf_meta_epub)   "general.epub" | Electronic publication (EPUB).<br>This type belongs to **EBOOK**.| 
| [UDMF_META_AZW](_u_d_m_f.md#udmf_meta_azw)   "com.amazon.azw" | AZW.<br>This type belongs to **EBOOK**.| 
| [UDMF_META_AZW3](_u_d_m_f.md#udmf_meta_azw3)   "com.amazon.azw3" | AZW3.<br>This type belongs to **EBOOK**.| 
| [UDMF_META_KFX](_u_d_m_f.md#udmf_meta_kfx)   "com.amazon.kfx" | KFX.<br>This type belongs to **EBOOK**.| 
| [UDMF_META_MOBI](_u_d_m_f.md#udmf_meta_mobi)   "com.amazon.mobi" | MOBI.<br>This type belongs to **EBOOK**.| 
| [UDMF_META_MEDIA](_u_d_m_f.md#udmf_meta_media)   "general.media" | Generic media type.<br>This type belongs to **OBJECT**.| 
| [UDMF_META_IMAGE](_u_d_m_f.md#udmf_meta_image)   "general.image" | Image.<br>This type belongs to **MEDIA**.| 
| [UDMF_META_JPEG](_u_d_m_f.md#udmf_meta_jpeg)   "general.jpeg" | JPEG.<br>This type belongs to **IMAGE**.| 
| [UDMF_META_PNG](_u_d_m_f.md#udmf_meta_png)   "general.png" | PNG.<br>This type belongs to **IMAGE**.| 
| [UDMF_META_RAW_IMAGE](_u_d_m_f.md#udmf_meta_raw_image)   "general.raw-image" | Raw image.<br>This type belongs to **IMAGE**.| 
| [UDMF_META_TIFF](_u_d_m_f.md#udmf_meta_tiff)   "general.tiff" | TIFF.<br>This type belongs to **IMAGE**.| 
| [UDMF_META_BMP](_u_d_m_f.md#udmf_meta_bmp)   "com.microsoft.bmp" | BMP.<br>This type belongs to **IMAGE**.| 
| [UDMF_META_ICO](_u_d_m_f.md#udmf_meta_ico)   "com.microsoft.ico" | Windows icon.<br>This type belongs to **IMAGE**.| 
| [UDMF_META_PHOTOSHOP_IMAGE](_u_d_m_f.md#udmf_meta_photoshop_image)   "com.adobe.photoshop-image" | Adobe Photoshop image.<br>This type belongs to **IMAGE**.| 
| [UDMF_META_AI_IMAGE](_u_d_m_f.md#udmf_meta_ai_image)   "com.adobe.illustrator.ai-image" | Adobe Illustrator image (.ai).<br>This type belongs to **IMAGE**.| 
| [UDMF_META_WORD_DOC](_u_d_m_f.md#udmf_meta_word_doc)   "com.microsoft.word.doc" | Microsoft Word.<br>This type belongs to **COMPOSITE_OBJECT**.| 
| [UDMF_META_EXCEL](_u_d_m_f.md#udmf_meta_excel)   "com.microsoft.excel.xls" | Microsoft Excel.<br>This type belongs to **COMPOSITE_OBJECT**.| 
| [UDMF_META_PPT](_u_d_m_f.md#udmf_meta_ppt)   "com.microsoft.powerpoint.ppt" | Microsoft PowerPoint presentation format.<br>This type belongs to **COMPOSITE_OBJECT**.| 
| [UDMF_META_PDF](_u_d_m_f.md#udmf_meta_pdf)   "com.adobe.pdf" | PDF.<br>This type belongs to **COMPOSITE_OBJECT**.| 
| [UDMF_META_POSTSCRIPT](_u_d_m_f.md#udmf_meta_postscript)   "com.adobe.postscript" | PostScript.<br>This type belongs to **COMPOSITE_OBJECT**.| 
| [UDMF_META_ENCAPSULATED_POSTSCRIPT](_u_d_m_f.md#udmf_meta_encapsulated_postscript)   "com.adobe.encapsulated-postscript" | Encapsulated PostScript.<br>This type belongs to **POSTSCRIPT**.| 
| [UDMF_META_VIDEO](_u_d_m_f.md#udmf_meta_video)   "general.video" | Generic video type.<br>This type belongs to **MEDIA**.| 
| [UDMF_META_AVI](_u_d_m_f.md#udmf_meta_avi)   "general.avi" | AVI.<br>This type belongs to **VIDEO**.| 
| [UDMF_META_MPEG](_u_d_m_f.md#udmf_meta_mpeg)   "general.mpeg" | MPGE-1 or MPGE-2.<br>This type belongs to **VIDEO**.| 
| [UDMF_META_MPEG4](_u_d_m_f.md#udmf_meta_mpeg4)   "general.mpeg-4" | MPGE-4.<br>This type belongs to **VIDEO**.| 
| [UDMF_META_VIDEO_3GPP](_u_d_m_f.md#udmf_meta_video_3gpp)   "general.3gpp" | 3GP (3GPP file format).<br>This type belongs to **VIDEO**.| 
| [UDMF_META_VIDEO_3GPP2](_u_d_m_f.md#udmf_meta_video_3gpp2)   "general.3gpp2" | 3G2 (3GPP2 file format).<br>This type belongs to **VIDEO**.| 
| [UDMF_META_WINDOWS_MEDIA_WM](_u_d_m_f.md#udmf_meta_windows_media_wm)   "com.microsoft.windows-media-wm" | Windows WM format.<br>This type belongs to **VIDEO**.| 
| [UDMF_META_WINDOWS_MEDIA_WMV](_u_d_m_f.md#udmf_meta_windows_media_wmv)   "com.microsoft.windows-media-wmv" | Windows WMV format.<br>This type belongs to **VIDEO**.| 
| [UDMF_META_WINDOWS_MEDIA_WMP](_u_d_m_f.md#udmf_meta_windows_media_wmp)   "com.microsoft.windows-media-wmp" | Windows WMP format.<br>This type belongs to **VIDEO**.| 
| [UDMF_META_AUDIO](_u_d_m_f.md#udmf_meta_audio)   "general.audio" | Generic audio type.<br>This type belongs to **MEDIA**.| 
| [UDMF_META_AAC](_u_d_m_f.md#udmf_meta_aac)   "general.aac" | AAC.<br>This type belongs to **AUDIO**.| 
| [UDMF_META_AIFF](_u_d_m_f.md#udmf_meta_aiff)   "general.aiff" | AIFF.<br>This type belongs to **AUDIO**.| 
| [UDMF_META_ALAC](_u_d_m_f.md#udmf_meta_alac)   "general.alac" | ALAC.<br>This type belongs to **AUDIO**.| 
| [UDMF_META_FLAC](_u_d_m_f.md#udmf_meta_flac)   "general.flac" | FLAC.<br>This type belongs to **AUDIO**.| 
| [UDMF_META_MP3](_u_d_m_f.md#udmf_meta_mp3)   "general.mp3" | MP3.<br>This type belongs to **AUDIO**.| 
| [UDMF_META_OGG](_u_d_m_f.md#udmf_meta_ogg)   "general.ogg" | OGG.<br>This type belongs to **AUDIO**.| 
| [UDMF_META_PCM](_u_d_m_f.md#udmf_meta_pcm)   "general.pcm" | PCM.<br>This type belongs to **AUDIO**.| 
| [UDMF_META_WINDOWS_MEDIA_WMA](_u_d_m_f.md#udmf_meta_windows_media_wma)   "com.microsoft.windows-media-wma" | Windows WMA.<br>This type belongs to **AUDIO**.| 
| [UDMF_META_WAVEFORM_AUDIO](_u_d_m_f.md#udmf_meta_waveform_audio)   "com.microsoft.waveform-audio" | Windows Waveform.<br>This type belongs to **AUDIO**.| 
| [UDMF_META_WINDOWS_MEDIA_WMX](_u_d_m_f.md#udmf_meta_windows_media_wmx)   "com.microsoft.windows-media-wmx" | Windows WMX format.<br>This type belongs to **VIDEO**.| 
| [UDMF_META_WINDOWS_MEDIA_WVX](_u_d_m_f.md#udmf_meta_windows_media_wvx)   "com.microsoft.windows-media-wvx" | Windows WVX format.<br>This type belongs to **VIDEO**.| 
| [UDMF_META_WINDOWS_MEDIA_WAX](_u_d_m_f.md#udmf_meta_windows_media_wax)   "com.microsoft.windows-media-wax" | Windows WAX.<br>This type belongs to **AUDIO**.| 
| [UDMF_META_GENERAL_FILE](_u_d_m_f.md#udmf_meta_general_file)   "general.file" | Generic file type.<br>This type belongs to **ENTITY**.| 
| [UDMF_META_DIRECTORY](_u_d_m_f.md#udmf_meta_directory)   "general.directory" | Generic directory type.<br>This type belongs to **ENTITY**.| 
| [UDMF_META_FOLDER](_u_d_m_f.md#udmf_meta_folder)   "general.folder" | Generic folder type.<br>This type belongs to **DIRECTORY**.| 
| [UDMF_META_SYMLINK](_u_d_m_f.md#udmf_meta_symlink)   "general.symlink" | Generic symbolic type.<br>This type belongs to **ENTITY**.| 
| [UDMF_META_ARCHIVE](_u_d_m_f.md#udmf_meta_archive)   "general.archive" | Generic archive file type.<br>This type belongs to **OBJECT**.| 
| [UDMF_META_BZ2_ARCHIVE](_u_d_m_f.md#udmf_meta_bz2_archive)   "general.bz2-archive" | BZ2.<br>This type belongs to **ARCHIVE**.| 
| [UDMF_META_DISK_IMAGE](_u_d_m_f.md#udmf_meta_disk_image)   "general.disk-image" | Generic type of any file that can be mounted as a volume.<br>This type belongs to **ARCHIVE**.| 
| [UDMF_META_TAR_ARCHIVE](_u_d_m_f.md#udmf_meta_tar_archive)   "general.tar-archive" | TAR.<br>This type belongs to ARCHIVE.| 
| [UDMF_META_ZIP_ARCHIVE](_u_d_m_f.md#udmf_meta_zip_archive)   "general.zip-archive" | ZIP.<br>This type belongs to **ARCHIVE**.| 
| [UDMF_META_JAVA_ARCHIVE](_u_d_m_f.md#udmf_meta_java_archive)   "com.sun.java-archive" | JAR (Java archive).<br>This type belongs to **ARCHIVE** and **EXECUTABLE**.| 
| [UDMF_META_GNU_TAR_ARCHIVE](_u_d_m_f.md#udmf_meta_gnu_tar_archive)   "org.gnu.gnu-tar-archive" | GUN archive.<br>This type belongs to **ARCHIVE**.| 
| [UDMF_META_GNU_ZIP_ARCHIVE](_u_d_m_f.md#udmf_meta_gnu_zip_archive)   "org.gnu.gnu-zip-archive" | GZIP archive.<br>This type belongs to **ARCHIVE**.| 
| [UDMF_META_GNU_ZIP_TAR_ARCHIVE](_u_d_m_f.md#udmf_meta_gnu_zip_tar_archive)   "org.gnu.gnu-zip-tar-archive" | GZIP TAR.<br>This type belongs to **ARCHIVE**.| 
| [UDMF_META_CALENDAR](_u_d_m_f.md#udmf_meta_calendar)   "general.calendar" | Generic calendar type.<br>This type belongs to **OBJECT**.| 
| [UDMF_META_CONTACT](_u_d_m_f.md#udmf_meta_contact)   "general.contact" | Generic contact type.<br>This type belongs to **OBJECT**.| 
| [UDMF_META_DATABASE](_u_d_m_f.md#udmf_meta_database)   "general.database" | Generic database file type.<br>This type belongs to **OBJECT**.| 
| [UDMF_META_MESSAGE](_u_d_m_f.md#udmf_meta_message)   "general.message" | Generic message type.<br>This type belongs to **OBJECT**.| 
| [UDMF_META_VCARD](_u_d_m_f.md#udmf_meta_vcard)   "general.vcard" | Generic electronic business card type.<br>This type belongs to **OBJECT**.| 
| [UDMF_META_NAVIGATION](_u_d_m_f.md#udmf_meta_navigation)   "general.navigation" | Generic navigation data type.<br>This type belongs to **OBJECT**.| 
| [UDMF_META_LOCATION](_u_d_m_f.md#udmf_meta_location)   "general.location" | Location data.<br>This type belongs to **NAVIGATION**.| 
| [UDMF_META_OPENHARMONY_FORM](_u_d_m_f.md#udmf_meta_openharmony_form)   "openharmony.form" | Widget defined for the system.<br>This type belongs to **OBJECT**.| 
| [UDMF_META_OPENHARMONY_APP_ITEM](_u_d_m_f.md#udmf_meta_openharmony_app_item)   "openharmony.app-item" | Home screen icon defined for the system.<br>This type belongs to **OBJECT**.| 
| [UDMF_META_OPENHARMONY_PIXEL_MAP](_u_d_m_f.md#udmf_meta_openharmony_pixel_map)   "openharmony.pixel-map" | Pixel map defined for the system.<br>This type belongs to **IMAGE**.| 
| [UDMF_META_OPENHARMONY_ATOMIC_SERVICE](_u_d_m_f.md#udmf_meta_openharmony_atomic_service)   "openharmony.atomic-service" | Atomic service type defined for the system.<br>This type belongs to **OBJECT**.| 
| [UDMF_META_OPENHARMONY_PACKAGE](_u_d_m_f.md#udmf_meta_openharmony_package)   "openharmony.package" | Package (compressed folder) defined for the system.<br>This type belongs to **DIRECTORY**.| 
| [UDMF_META_OPENHARMONY_HAP](_u_d_m_f.md#udmf_meta_openharmony_hap)   "openharmony.hap" | Ability package defined for the system.<br>This type belongs to **OPENHARMONY_PACKAGE**.| 
| [UDMF_META_SMIL](_u_d_m_f.md#udmf_meta_smil)   "com.real.smil" | Synchronized Multimedia Integration Language (SMIL).<br>This type belongs to **XML**.| 
| [UDMF_META_MARKDOWN](_u_d_m_f.md#udmf_meta_markdown)   "general.markdown" | Markdown.<br>This type belongs to **PLAIN_TEXT**.| 
| [UDMF_META_FAX](_u_d_m_f.md#udmf_meta_fax)   "general.fax" | Generic type of the fax.<br>This type belongs to **IMAGE**.| 
| [UDMF_META_JFX_FAX](_u_d_m_f.md#udmf_meta_jfx_fax)   "com.j2.jfx-fax" | J2 jConnect fax file format.<br>This type belongs to **FAX**.| 
| [UDMF_META_EFX_FAX](_u_d_m_f.md#udmf_meta_efx_fax)   "com.js.efx-fax" | EFX file format.<br>This type belongs to **FAX**.| 
| [UDMF_META_XBITMAP_IMAGE](_u_d_m_f.md#udmf_meta_xbitmap_image)   "general.xbitmap-image" | X BitMAP (XBM) used in the X Window system (X11).<br>This type belongs to **IMAGE**.| 
| [UDMF_META_TGA_IMAGE](_u_d_m_f.md#udmf_meta_tga_image)   "com.truevision.tga-image" | Tagged Graphics (TGA) format.<br>This type belongs to **IMAGE**.| 
| [UDMF_META_SGI_IMAGE](_u_d_m_f.md#udmf_meta_sgi_image)   "com.sgi.sgi-image" | Silicon Graphics image (SGI) format.<br>This type belongs to **IMAGE**.| 
| [UDMF_META_OPENEXR_IMAGE](_u_d_m_f.md#udmf_meta_openexr_image)   "com.ilm.openexr-image" | OpenXR image format.<br>This type belongs to **IMAGE**.| 
| [UDMF_META_FLASHPIX_IMAGE](_u_d_m_f.md#udmf_meta_flashpix_image)   "com.kodak.flashpix.image" | FlashPix image format.<br>This type belongs to **IMAGE**.| 
| [UDMF_META_REALMEDIA](_u_d_m_f.md#udmf_meta_realmedia)   "com.real.realmedia" | RealMedia format.<br>This type belongs to **VIDEO**.| 
| [UDMF_META_AU_AUDIO](_u_d_m_f.md#udmf_meta_au_audio)   "general.au-audio" | AU format.<br>This type belongs to **AUDIO**.| 
| [UDMF_META_AIFC_AUDIO](_u_d_m_f.md#udmf_meta_aifc_audio)   "general.aifc-audio" | AIFC.<br>This type belongs to **AUDIO**.| 
| [UDMF_META_SD2_AUDIO](_u_d_m_f.md#udmf_meta_sd2_audio)   "com.digidesign.sd2-audio" | Digidesign Sound Designer II (SDII).<br>This type belongs to **AUDIO**.| 
| [UDMF_META_REALAUDIO](_u_d_m_f.md#udmf_meta_realaudio)   "com.real.realaudio" | RealAudio.<br>This type belongs to **AUDIO**.| 
| [UDMF_META_OPENXML](_u_d_m_f.md#udmf_meta_openxml)   "org.openxmlformats.openxml" | OpenXML base type.<br>This type belongs to **ARCHIVE**.| 
| [UDMF_META_WORDPROCESSINGML_DOCUMENT](_u_d_m_f.md#udmf_meta_wordprocessingml_document)   "org.openxmlformats.wordprocessingml.document" | WordProcessingML format.<br>This type belongs to **OPENXML** and **COMPOSITE_OBJECT**.| 
| [UDMF_META_SPREADSHEETML_SHEET](_u_d_m_f.md#udmf_meta_spreadsheetml_sheet)   "org.openxmlformats.spreadsheetml.sheet" | SpreadsheetML format.<br>This type belongs to **OPENXML** and **COMPOSITE_OBJECT**.| 
| [UDMF_META_PRESENTATIONML_PRESENTATION](_u_d_m_f.md#udmf_meta_presentationml_presentation)   "org.openxmlformats.presentationml.presentation" | PresentationML format.<br>This type belongs to **OPENXML** and **COMPOSITE_OBJECT**.| 
| [UDMF_META_OPENDOCUMENT](_u_d_m_f.md#udmf_meta_opendocument)   "org.oasis.opendocument" | OpenDocument format for Office applications.<br>This type belongs to **ARCHIVE**.| 
| [UDMF_META_OPENDOCUMENT_TEXT](_u_d_m_f.md#udmf_meta_opendocument_text)   "org.oasis.opendocument.text" | OpenDocument format for word processing (text) documents.<br>This type belongs to **OPENDOCUMENT** and **COMPOSITE_OBJECT**.| 
| [UDMF_META_OPENDOCUMENT_SPREADSHEET](_u_d_m_f.md#udmf_meta_opendocument_spreadsheet)   "org.oasis.opendocument.spreadsheet" | OpenDocument format for spreadsheets.<br>This type belongs to **OPENDOCUMENT** and **COMPOSITE_OBJECT**.| 
| [UDMF_META_OPENDOCUMENT_PRESENTATION](_u_d_m_f.md#udmf_meta_opendocument_presentation)   "org.oasis.opendocument.presentation" | OpenDocument format for presentations.<br>This type belongs to **OPENDOCUMENT** and **COMPOSITE_OBJECT**.| 
| [UDMF_META_OPENDOCUMENT_GRAPHICS](_u_d_m_f.md#udmf_meta_opendocument_graphics)   "org.oasis.opendocument.graphics" | OpenDocument format for graphics.<br>This type belongs to **OPENDOCUMENT** and **COMPOSITE_OBJECT**.| 
| [UDMF_META_OPENDOCUMENT_FORMULA](_u_d_m_f.md#udmf_meta_opendocument_formula)   "org.oasis.opendocument.formula" | OpenDocument format for formula.<br>This type belongs to **OPENDOCUMENT**.| 
| [UDMF_META_STUFFIT_ARCHIVE](_u_d_m_f.md#udmf_meta_stuffit_archive)   "com.allume.stuffit-archive" | Stuffit compression format (stuffit archive).<br>This type belongs to **ARCHIVE**.| 
| [UDMF_META_VCS](_u_d_m_f.md#udmf_meta_vcs)   "general.vcs" | VCalendar (VCS) format.<br>This type belongs to **CALENDAR** and **TEXT**.| 
| [UDMF_META_ICS](_u_d_m_f.md#udmf_meta_ics)   "general.ics" | Internet Calendaring and Scheduling (ICS) format.<br>This type belongs to **CALENDAR** and **TEXT**.| 
| [UDMF_META_EXECUTABLE](_u_d_m_f.md#udmf_meta_executable)   "general.executable" | Generic type of all executable files.<br>This type belongs to **OBJECT**.| 
| [UDMF_META_PORTABLE_EXECUTABLE](_u_d_m_f.md#udmf_meta_portable_executable)   "com.microsoft.portable-executable" | Microsoft Windows portable executable format.<br>This type belongs to **EXECUTABLE**.| 
| [UDMF_META_SUN_JAVA_CLASS](_u_d_m_f.md#udmf_meta_sun_java_class)   "com.sun.java-class" | Java class file format.<br>This type belongs to **EXECUTABLE**.| 
| [UDMF_META_FONT](_u_d_m_f.md#udmf_meta_font)   "general.font" | Basic type of fonts.<br>This type belongs to **OBJECT**.| 
| [UDMF_META_TRUETYPE_FONT](_u_d_m_f.md#udmf_meta_truetype_font)   "general.truetype-font" | TrueType font format.<br>This type belongs to **FONT**.| 
| [UDMF_META_TRUETYPE_COLLECTION_FONT](_u_d_m_f.md#udmf_meta_truetype_collection_font)   "general.truetype-collection-font" | TrueType Collection font format.<br>This type belongs to **FONT**.| 
| [UDMF_META_OPENTYPE_FONT](_u_d_m_f.md#udmf_meta_opentype_font)   "general.opentype-font" | OpenType font format.<br>This type belongs to **FONT**.| 
| [UDMF_META_POSTSCRIPT_FONT](_u_d_m_f.md#udmf_meta_postscript_font)   "com.adobe.postscript-font" | PostScript font format.<br>This type belongs to **FONT**.| 
| [UDMF_META_POSTSCRIPT_PFB_FONT](_u_d_m_f.md#udmf_meta_postscript_pfb_font)   "com.adobe.postscript-pfb-font" | PostScript Font Binary font format.<br>This type belongs to **FONT**.| 
| [UDMF_META_POSTSCRIPT_PFA_FONT](_u_d_m_f.md#udmf_meta_postscript_pfa_font)   "com.adobe.postscript-pfa-font" | Adobe Type 1 font format.<br>This type belongs to **FONT**.| 
| [UDMF_META_OPENHARMONY_HDOC](_u_d_m_f.md#udmf_meta_openharmony_hdoc)   "openharmony.hdoc" | Memo format defined for the system.<br>This type belongs to **COMPOSITE_OBJECT**.| 
| [UDMF_META_OPENHARMONY_HINOTE](_u_d_m_f.md#udmf_meta_openharmony_hinote)   "openharmony.hinote" | Note format defined for the system.<br>This type belongs to **COMPOSITE_OBJECT**.| 
| [UDMF_META_OPENHARMONY_STYLED_STRING](_u_d_m_f.md#udmf_meta_openharmony_styled_string)   "openharmony.styled-string" | Style string type defined for the system.<br>This type belongs to **COMPOSITE_OBJECT**.| 
| [UDMF_META_OPENHARMONY_WANT](_u_d_m_f.md#udmf_meta_openharmony_want)   "openharmony.want" | Want defined for the system.<br>This type belongs to **OBJECT**.| 
| [UDMF_META_GENERAL_FILE_URI](_u_d_m_f.md#udmf_meta_general_file_uri)&nbsp;&nbsp;&nbsp;"general.file-uri" | File address type.<br>This type belongs to **TEXT**.<br>This parameter is available since API version 13.|
| [UDMF_METE_GENERAL_CONTENT_FORM](_u_d_m_f.md#udmf_mete_general_content_form)   "general.content-form" | Content widget type.<br>This type belongs to **OBJECT**.|  
