# @ohos.data.uniformTypeDescriptor (标准化数据定义与描述)

本模块对OpenHarmony标准化数据类型进行了抽象定义与描述。

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

| 名称                         | 值                            |     说明 |
|----------------------------|------------------------------|-------------------------------------------------------------------------|
| TEXT                       | 'general.text'                   | 所有文本的基本类型。|
| PLAIN_TEXT                | 'general.plain-text'             | 未指定编码的文本类型，没有标记。等效于MIME类型text/plain，归属类型为TEXT。|
| HTML                  | 'general.html'                   | HTML文本类型， 归属类型为TEXT。|
| HYPERLINK         | 'general.hyperlink'              | 超链接类型， 归属类型为TEXT。|
| XML<sup>11+</sup>    | 'general.xml'                   | XML文本类型， 归属类型为TEXT。|
| SOURCE_CODE<sup>11+</sup>                | 'general.source-code'                  |     通用源代码类型， 归属类型为PLAIN_TEXT。|
| SCRIPT<sup>11+</sup>    | 'general.script'                  |      脚本语言源代码基本类型， 归属类型为SOURCE_CODE。|
| SHELL_SCRIPT<sup>11+</sup>               | 'general.shell-script'                  |  shell脚本类型， 归属类型为SCRIPT。|    
| CSH_SCRIPT<sup>11+</sup>      | 'general.csh-script'                 | C-shell脚本类型， 归属类型为SHELL_SCRIPT。|
| PERL_SCRIPT<sup>11+</sup> |'general.perl-script'               |     Perl脚本类型， 归属类型为SHELL_SCRIPT。|
| PHP_SCRIPT<sup>11+</sup>         | 'general.php-script'           |     PHP脚本类型， 归属类型为SHELL_SCRIPT。|
| PYTHON_SCRIPT<sup>11+</sup>        | 'general.python-script'          |  Python脚本类型， 归属类型为SHELL_SCRIPT。|
| RUBY_SCRIPT<sup>11+</sup>                         | 'general.ruby-script'                   |     Ruby脚本类型， 归属类型为SHELL_SCRIPT。|
| TYPE_SCRIPT<sup>11+</sup>                        | 'general.type-script'                  |    TypeScript源代码类型， 归属类型为SOURCE_CODE。|
| JAVA_SCRIPT<sup>11+</sup>                        | 'general.java-script'                  |    JavaScript源代码类型， 归属类型为SOURCE_CODE。|
| C_HEADER<sup>11+</sup>                        | 'general.c-header'                  |      C头文件类型， 归属类型为SOURCE_CODE。|
| C_SOURCE<sup>11+</sup>                       | 'general.c-source'                 |     C源代码类型， 归属类型为SOURCE_CODE。|
| C_PLUS_PLUS_HEADER<sup>11+</sup>             | 'general.c-plus-plus-header'               |      C++头文件类型， 归属类型为SOURCE_CODE。|
| C_PLUS_PLUS_SOURCE<sup>11+</sup>         | 'general.c-plus-plus-source'           |     C++源代码类型， 归属类型为SOURCE_CODE。|
| JAVA_SOURCE<sup>11+</sup>        | 'general.java-source'          |  Java源代码类型， 归属类型为SOURCE_CODE。|
| EBOOK<sup>11+</sup>                         | 'general.ebook'                   |      电子书基本类型。|
| EPUB<sup>11+</sup>                        | 'general.epub'                  |     电子出版物（EPUB）格式类型， 归属类型为EBOOK。|
| AZW<sup>11+</sup>                        | 'com.amazon.azw'                  |   AZW电子书类型， 归属类型为EBOOK。|
| AZW3<sup>11+</sup>                        | 'com.amazon.azw3'                  |    AZW3电子书类型， 归属类型为EBOOK。|
| KFX<sup>11+</sup>                       | 'com.amazon.kfx'                 |    KFX电子书类型， 归属类型为EBOOK。|
| MOBI<sup>11+</sup>             | 'com.amazon.mobi'               |    MOBI电子书类型， 归属类型为EBOOK。|
| MEDIA<sup>11+</sup>         | 'general.media'           |      媒体基本类型。|
| IMAGE        | 'general.image'          |  图片基本类型， 归属类型为MEDIA。|
| JPEG<sup>11+</sup>                         | 'general.jpeg'                   |     JPEG图片类型， 归属类型为IMAGE。|
| PNG<sup>11+</sup>                        | 'general.png'                  |      PNG图片类型， 归属类型为IMAGE。|
| RAW_IMAGE<sup>11+</sup>                        | 'general.raw-image'                  |      数码相机原始图像格式基本类型， 归属类型为IMAGE。|
| TIFF<sup>11+</sup>                        | 'general.tiff'                  |     TIFF图片类型， 归属类型为IMAGE。|
| BMP<sup>11+</sup>                       | 'com.microsoft.bmp'                 |     WINDOWS位图图像类型， 归属类型为IMAGE。|
| ICO<sup>11+</sup>             | 'com.microsoft.ico'               |     WINDOWS图标图像类型， 归属类型为IMAGE。|
| PHOTOSHOP_IMAGE<sup>11+</sup>         | 'com.adobe.photoshop-image'           |     Adobe Photoshop文档类型， 归属类型为IMAGE。|
| AI_IMAGE<sup>11+</sup>        | 'com.adobe.illustrator.ai-image'          |   Adobe Illustrator文档类型， 归属类型为IMAGE。|
| WORD_DOC<sup>11+</sup>                         | 'com.microsoft.word.doc'                   |      Microsoft Word数据类型。|
| EXCEL<sup>11+</sup>                        | 'com.microsoft.excel.xls'                  |    Microsoft Excel数据类型。 |
| PPT<sup>11+</sup>                        | 'com.microsoft.powerpoint.ppt'                  |      Microsoft PowerPoint演示文稿类型。|
| PDF<sup>11+</sup>                        | 'com.adobe.pdf'                  |      PDF数据类型。|
| POSTSCRIPT<sup>11+</sup>                       | 'com.adobe.postscript'                 |     PostScript数据类型。|
| ENCAPSULATED_POSTSCRIPT<sup>11+</sup>             | 'com.adobe.encapsulated-postscript'               |      Encapsulated PostScript类型。|
| VIDEO       | 'general.video'           |   基本的视频类型， 归属类型为MEDIA。|
| AVI<sup>11+</sup>        | 'general.avi'          |  AVI电影类型， 归属类型为VIDEO。|
| MPEG<sup>11+</sup>                         | 'general.mpeg'                   |    MPGE-1或MPGE-2内容类型， 归属类型为VIDEO。|
| MPEG4<sup>11+</sup>                        | 'general.mpeg-4'                  |      MPGE-4内容类型， 归属类型为VIDEO。|
| VIDEO_3GPP<sup>11+</sup>                        | 'general.3gpp'                  |     3GPP电影类型， 归属类型为VIDEO。|
| VIDEO_3GPP2<sup>11+</sup>                        | 'general.3gpp2'                  |     音频类型， 归属类型为VIDEO。|
| WINDOWS_MEDIA_WM<sup>11+</sup>                       | 'com.microsoft.windows-media-wm'                 |   WINDOWS WM视频类型， 归属类型为VIDEO。|
| WINDOWS_MEDIA_WMV<sup>11+</sup>             | 'com.microsoft.windows-media-wmv'               |     WINDOWS WMV视频类型， 归属类型为VIDEO。|
| WINDOWS_MEDIA_WMP<sup>11+</sup>         | 'com.microsoft.windows-media-wmp'           |    WINDOWS WMP视频类型， 归属类型为VIDEO。|
| AUDIO       | 'general.audio'          |  音频的基本类型， 归属类型为MEDIA。|
| AAC<sup>11+</sup>                         | 'general.aac'                   |     AAC音频类型， 归属类型为AUDIO。|
| AIFF<sup>11+</sup>                        | 'general.aiff'                  |     AIFF音频类型， 归属类型为AUDIO。|
| ALAC<sup>11+</sup>                        | 'general.alac'                  |     ALAC音频类型， 归属类型为AUDIO。|
| FLAC<sup>11+</sup>                        | 'general.flac'                  |     FLAC音频类型， 归属类型为AUDIO。|
| MP3<sup>11+</sup>                       | 'general.mp3'                 |     MP3音频类型， 归属类型为AUDIO。|
| OGG<sup>11+</sup>              | 'general.ogg'               |      OGG音频类型， 归属类型为AUDIO。|
| PCM<sup>11+</sup>         | 'general.pcm'           |     PCM音频类型， 归属类型为AUDIO。|
| WINDOWS_MEDIA_WMA<sup>11+</sup>        | 'com.microsoft.windows-media-wma'          | WINDOWS WMA音频类型， 归属类型为AUDIO。|
| WAVEFORM_AUDIO<sup>11+</sup>                         | 'com.microsoft.waveform-audio'                   |    波形音频类型， 归属类型为AUDIO。|
| WINDOWS_MEDIA_WMX<sup>11+</sup>                        | 'com.microsoft.windows-media-wmx'                  |     WINDOWS WMX视频类型， 归属类型为AUDIO。|
| WINDOWS_MEDIA_WVX<sup>11+</sup>                        | 'com.microsoft.windows-media-wvx'                  |     WINDOWS WVX视频类型， 归属类型为AUDIO。|
| WINDOWS_MEDIA_WAX<sup>11+</sup>                        | 'com.microsoft.windows-media-wax'                  |     WINDOWS WAX视频类型， 归属类型为AUDIO。|
| FILE                       | 'general.file'                 |     文件基本类型。|
| DIRECTORY<sup>11+</sup>             | 'general.directory'               |      目录的类型。|
| FOLDER        | 'general.folder'           |      文件夹基本类型。|
| SYMLINK<sup>11+</sup>        | 'general.symlink'          |   符号链接的类型。|
| ARCHIVE<sup>11+</sup>                         | 'general.archive'                   |      文件和目录存档基本类型。|
| BZ2_ARCHIVE<sup>11+</sup>                        | 'general.bz2-archive'                  |     BZ2存档类型， 归属类型为ARCHIVE。|
| DISK_IMAGE<sup>11+</sup>                        | 'general.disk-image'                  |      可作为卷装载项的基本类型， 归属类型为ARCHIVE。|
| TAR_ARCHIVE<sup>11+</sup>                        | 'general.tar-archive'                  |     TAR存档类型， 归属类型为ARCHIVE。|
| ZIP_ARCHIVE<sup>11+</sup>                       | 'general.zip-archive'                 |     ZIP存档类型， 归属类型为ARCHIVE。|
| JAVA_ARCHIVE<sup>11+</sup>             | 'com.sun.java-archive'               |      JAVA存档类型， 归属类型为ARCHIVE。|
| GNU_TAR_ARCHIVE<sup>11+</sup>         | 'org.gnu.gnu-tar-archive'           |     GUN存档类型， 归属类型为ARCHIVE。|
| GNU_ZIP_ARCHIVE<sup>11+</sup>        | 'org.gnu.gnu-zip-archive'          |  GZIP存档类型， 归属类型为ARCHIVE。|
| GNU_ZIP_TAR_ARCHIVE<sup>11+</sup>                         | 'org.gnu.gnu-zip-tar-archive'                   |     GZIP TAR存档类型，归属类型为ARCHIVE。|
| CALENDAR<sup>11+</sup>                        | 'general.calendar'                  |      计划事件的基本类型。|
| CONTACT<sup>11+</sup>                        | 'general.contact'                  |      联系人信息的基本类型。|
| DATABASE<sup>11+</sup>                        | 'general.database'                  |      数据库基本类型。|
| MESSAGE<sup>11+</sup>                       | 'general.message'                 |     消息的基本类型。|
| VCARD<sup>11+</sup>             | 'general.vcard'               |      电子名片的基本类型。|
| NAVIGATION<sup>11+</sup>         | 'general.navigation'           |      导航的基本类型。|
| LOCATION<sup>11+</sup>        | 'general.location'          |  导航定位类型，归属类型为NAVIGATION。|
| OPENHARMONY_FORM                         | 'openharmony.form'                   |      OpenHarmony系统定义的表单类型。|
| OPENHARMONY_APP_ITEM                        | 'openharmony.app-item'                  |      OpenHarmony系统定义的应用项类型。|
| OPENHARMONY_PIXEL_MAP                        | 'openharmony.pixel-map'                  |      OpenHarmony系统定义的像素映射类型。|
| OPENHARMONY_ATOMIC_SERVICE<sup>11+</sup>                        | 'openharmony.atomic-service'                  |      OpenHarmony系统定义的原子服务类型。|


## TypeDescriptor<sup>11+</sup> 

描述标准化数据类型的类，它描述了标准化数据类型以及与其他相关标准化数据类型的属性和方法

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

| 名称    | 类型                    | 可读 | 可写 | 说明                       |
| ------- | ----------------------- | ---- | ---- | -------------------------- |
| typeId<sup>11+</sup>     | string | 是   | 否   | 表示标准化数据类型的ID（名称）。           |
| belongingToTypes<sup>11+</sup>  | Array\<string>          | 是   | 否   | 表示标准化数据类型所归属类型的值。 |
| description<sup>11+</sup>     | string                  | 是   | 否   | 表示标准化数据类型的简要说明。         |
| referenceURL<sup>11+</sup>     | string                  | 是   | 否   | 标准化数据类型的详细描述，用于描述类型的详细信息。         |
| iconFile<sup>11+</sup>     | string                  | 是   | 否   | 标准化数据类型中默认图标文件的路径。         |

### equals<sup>11+</sup> 

equals(typeDescriptor: TypeDescriptor): boolean

通过描述标准化数据类型的对象[TypeDescriptor](#typedescriptor11)检查两个标准化数据类型是否相同。

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

**参数：**

| 参数名  | 类型 | 必填  | 说明                    |
| -----  | ------  | ----  | ----------------------- |
| typeDescriptor    | [TypeDescriptor](#typedescriptor11)  | 是    |比较两个标准化数据类型是否相同。   |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回true表示所比较的标准化数据类型相同；返回false则表示不同。 |

**示例：**

```ts
import uniformTypeDescriptor from './@ohos.data.uniformTypeDescriptor';
import { BusinessError } from '@ohos.base';

try{
    let typeA : uniformTypeDescriptor.TypeDescriptor = uniformTypeDescriptor.getTypeDescriptor('general.type-script');
    let typeB : uniformTypeDescriptor.TypeDescriptor = uniformTypeDescriptor.getTypeDescriptor('general.python-script');
    if(!typeA.equals(typeB)) {
      console.info(`typeA is not equal to typeB`);
  }
} catch(e) {
    let error: BusinessError = e as BusinessError;
    console.error(`throws an exception. code is ${error.code}, message is ${error.message} `);
}
```

## uniformTypeDescriptor.getTypeDescriptor<sup>11+</sup>

getTypeDescriptor(typeId: string): TypeDescriptor

按给定的标准化数据类型ID查询并返回对应的标准化数据类型的属性描述信息。

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

**参数：**

| 参数名  | 类型 | 必填  | 说明                    |
| -----  | ------  | ----  | ----------------------- |
| typeId    | string  | 是    |标准化数据类型ID。   |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| [TypeDescriptor](#typedescriptor11) | 返回某标准化数据类型的属性描述信息。 |

**示例：**

```ts
import uniformTypeDescriptor from './@ohos.data.uniformTypeDescriptor';
import { BusinessError } from '@ohos.base';

try {
    let typeObj : uniformTypeDescriptor.TypeDescriptor = uniformTypeDescriptor.getTypeDescriptor('com.adobe.photoshop-image');
    let typeId = typeObj.typeId;
    let belongingToTypes = typeObj.belongingToTypes;
    let description = typeObj.description;
    let referenceURL = typeObj.referenceURL;
    let iconFile = typeObj.iconFile;
    console.info('typeId: ' + typeId + ', ' + Object.prototype.toString.call(typeId) + ', belongingToTypes: ' + belongingToTypes + ', ' + Object.prototype.toString.call(belongingToTypes));
    console.info(TAG, 'description: ' + description + ', ' + Object.prototype.toString.call(description));
    console.info(TAG, 'referenceURL: ' + referenceURL + ', ' + Object.prototype.toString.call(referenceURL) + ', iconFile: ' + iconFile + ', ' + Object.prototype.toString.call(iconFile));
} catch(e) {
    let error: BusinessError = e as BusinessError;
    console.error(`getTypeDescriptor throws an exception. code is ${error.code}, message is ${error.message} `);
}
```