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

OpenHarmony标准化数据类型的枚举定义。标准化数据类型之间存在归属关系，例如JPEG图片类型归属于IMAGE类型。

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

| 名称                         | 值                            | 说明                                 |
|----------------------------|------------------------------|------------------------------------|
| ENTITY<sup>11+</sup>                       | 'general.entity'                   | 所有表示物理存储类型的基类型，无归属类型。                          |
| OBJECT<sup>11+</sup>                       | 'general.object'                   | 所有表示逻辑内容类型的基类型，无归属类型。                          |
| COMPOSITE_OBJECT<sup>11+</sup>                       | 'general.composite-object'                   | 所有组合内容类型（例如PDF文件类型混合了文本和图片类数据）的基类型，归属类型为OBJECT。                          |
| TEXT                       | 'general.text'                   | 所有文本的基类型，归属类型为OBJECT。                          |
| PLAIN_TEXT                | 'general.plain-text'             | 未指定编码的文本类型，没有标识符，归属类型为TEXT。        |
| HTML                  | 'general.html'                   | HTML文本类型，归属类型为TEXT。               |
| HYPERLINK         | 'general.hyperlink'              | 超链接类型，归属类型为TEXT。                  |
| XML<sup>11+</sup>    | 'general.xml'                   | XML文本类型，归属类型为TEXT。                |
| SOURCE_CODE<sup>11+</sup>                | 'general.source-code'                  | 所有源代码的基类型，归属类型为PLAIN_TEXT。        |
| SCRIPT<sup>11+</sup>    | 'general.script'                  | 所有脚本语言源代码的基类型，归属类型为SOURCE_CODE。   |
| SHELL_SCRIPT<sup>11+</sup>               | 'general.shell-script'                  | shell脚本类型，归属类型为SCRIPT。            |    
| CSH_SCRIPT<sup>11+</sup>      | 'general.csh-script'                 | C-shell脚本类型，归属类型为SHELL_SCRIPT。    |
| PERL_SCRIPT<sup>11+</sup> |'general.perl-script'               | Perl脚本类型，归属类型为SHELL_SCRIPT。       |
| PHP_SCRIPT<sup>11+</sup>         | 'general.php-script'           | PHP脚本类型，归属类型为SHELL_SCRIPT。        |
| PYTHON_SCRIPT<sup>11+</sup>        | 'general.python-script'          | Python脚本类型，归属类型为SHELL_SCRIPT。     |
| RUBY_SCRIPT<sup>11+</sup>                         | 'general.ruby-script'                   | Ruby脚本类型，归属类型为SHELL_SCRIPT。       |
| TYPE_SCRIPT<sup>11+</sup>                        | 'general.type-script'                  | TypeScript源代码类型，归属类型为SCRIPT。 |
| JAVA_SCRIPT<sup>11+</sup>                        | 'general.java-script'                  | JavaScript源代码类型，归属类型为SCRIPT。 |
| C_HEADER<sup>11+</sup>                        | 'general.c-header'                  | C头文件类型，归属类型为SOURCE_CODE。          |
| C_SOURCE<sup>11+</sup>                       | 'general.c-source'                 | C源代码类型，归属类型为SOURCE_CODE。          |
| C_PLUS_PLUS_HEADER<sup>11+</sup>             | 'general.c-plus-plus-header'               | C++头文件类型，归属类型为SOURCE_CODE。        |
| C_PLUS_PLUS_SOURCE<sup>11+</sup>         | 'general.c-plus-plus-source'           | C++源代码类型，归属类型为SOURCE_CODE。        |
| JAVA_SOURCE<sup>11+</sup>        | 'general.java-source'          | Java源代码类型，归属类型为SOURCE_CODE。       |
| EBOOK<sup>11+</sup>                         | 'general.ebook'                   | 所有电子书文件格式的基类型，归属类型为COMPOSITE_OBJECT。                     |
| EPUB<sup>11+</sup>                        | 'general.epub'                  | 电子出版物（EPUB）文件格式类型，归属类型为EBOOK。     |
| AZW<sup>11+</sup>                        | 'com.amazon.azw'                  | AZW电子书文件格式类型，归属类型为EBOOK。          |
| AZW3<sup>11+</sup>                        | 'com.amazon.azw3'                  | AZW3电子书文件格式类型，归属类型为EBOOK。         |
| KFX<sup>11+</sup>                       | 'com.amazon.kfx'                 | KFX电子书文件格式类型，归属类型为EBOOK。          |
| MOBI<sup>11+</sup>             | 'com.amazon.mobi'               | MOBI电子书文件格式类型，归属类型为EBOOK。         |
| MEDIA<sup>11+</sup>         | 'general.media'           | 所有媒体的基类型，归属类型为OBJECT。                          |
| IMAGE        | 'general.image'          | 所有图片的基类型，归属类型为MEDIA。              |
| JPEG<sup>11+</sup>                         | 'general.jpeg'                   | JPEG图片类型，归属类型为IMAGE。              |
| PNG<sup>11+</sup>                        | 'general.png'                  | PNG图片类型，归属类型为IMAGE。               |
| RAW_IMAGE<sup>11+</sup>                        | 'general.raw-image'                  | 所有原始图像格式的基类型，归属类型为IMAGE。          |
| TIFF<sup>11+</sup>                        | 'general.tiff'                  | TIFF图片类型，归属类型为IMAGE。              |
| BMP<sup>11+</sup>                       | 'com.microsoft.bmp'                 | WINDOWS位图图像类型，归属类型为IMAGE。         |
| ICO<sup>11+</sup>             | 'com.microsoft.ico'               | WINDOWS图标图像类型，归属类型为IMAGE。         |
| PHOTOSHOP_IMAGE<sup>11+</sup>         | 'com.adobe.photoshop-image'           | Adobe Photoshop图片类型，归属类型为IMAGE。   |
| AI_IMAGE<sup>11+</sup>        | 'com.adobe.illustrator.ai-image'          | Adobe Illustrator图片类型，归属类型为IMAGE。 |
| WORD_DOC<sup>11+</sup>                         | 'com.microsoft.word.doc'                   | Microsoft Word数据类型，归属类型为COMPOSITE_OBJECT。                |
| EXCEL<sup>11+</sup>                        | 'com.microsoft.excel.xls'                  | Microsoft Excel数据类型，归属类型为COMPOSITE_OBJECT。               |
| PPT<sup>11+</sup>                        | 'com.microsoft.powerpoint.ppt'                  | Microsoft PowerPoint演示文稿类型，归属类型为COMPOSITE_OBJECT。        |
| PDF<sup>11+</sup>                        | 'com.adobe.pdf'                  | PDF数据类型，归属类型为COMPOSITE_OBJECT。                           |
| POSTSCRIPT<sup>11+</sup>                       | 'com.adobe.postscript'                 | PostScript数据类型，归属类型为COMPOSITE_OBJECT。                    |
| ENCAPSULATED_POSTSCRIPT<sup>11+</sup>             | 'com.adobe.encapsulated-postscript'               | Encapsulated PostScript类型，归属类型为POSTSCRIPT。         |
| VIDEO       | 'general.video'           | 所有视频的基类型，归属类型为MEDIA。              |
| AVI<sup>11+</sup>        | 'general.avi'          | AVI视频类型，归属类型为VIDEO。               |
| MPEG<sup>11+</sup>                         | 'general.mpeg'                   | MPGE-1或MPGE-2视频类型，归属类型为VIDEO。     |
| MPEG4<sup>11+</sup>                        | 'general.mpeg-4'                  | MPGE-4视频类型，归属类型为VIDEO。            |
| VIDEO_3GPP<sup>11+</sup>                        | 'general.3gpp'                  | 3GPP视频类型，归属类型为VIDEO。              |
| VIDEO_3GPP2<sup>11+</sup>                        | 'general.3gpp2'                  | 3GPP2视频类型，归属类型为VIDEO。             |
| WINDOWS_MEDIA_WM<sup>11+</sup>                       | 'com.microsoft.windows-media-wm'                 | WINDOWS WM视频类型，归属类型为VIDEO。        |
| WINDOWS_MEDIA_WMV<sup>11+</sup>             | 'com.microsoft.windows-media-wmv'               | WINDOWS WMV视频类型，归属类型为VIDEO。       |
| WINDOWS_MEDIA_WMP<sup>11+</sup>         | 'com.microsoft.windows-media-wmp'           | WINDOWS WMP视频类型，归属类型为VIDEO。       |
| AUDIO       | 'general.audio'          | 所有音频的基类型，归属类型为MEDIA。              |
| AAC<sup>11+</sup>                         | 'general.aac'                   | AAC音频类型，归属类型为AUDIO。               |
| AIFF<sup>11+</sup>                        | 'general.aiff'                  | AIFF音频类型，归属类型为AUDIO。              |
| ALAC<sup>11+</sup>                        | 'general.alac'                  | ALAC音频类型，归属类型为AUDIO。              |
| FLAC<sup>11+</sup>                        | 'general.flac'                  | FLAC音频类型，归属类型为AUDIO。              |
| MP3<sup>11+</sup>                       | 'general.mp3'                 | MP3音频类型，归属类型为AUDIO。               |
| OGG<sup>11+</sup>              | 'general.ogg'               | OGG音频类型，归属类型为AUDIO。               |
| PCM<sup>11+</sup>         | 'general.pcm'           | PCM音频类型，归属类型为AUDIO。               |
| WINDOWS_MEDIA_WMA<sup>11+</sup>        | 'com.microsoft.windows-media-wma'          | WINDOWS WMA音频类型，归属类型为AUDIO。       |
| WAVEFORM_AUDIO<sup>11+</sup>                         | 'com.microsoft.waveform-audio'                   | WINDOWS波形音频类型，归属类型为AUDIO。         |
| WINDOWS_MEDIA_WMX<sup>11+</sup>                        | 'com.microsoft.windows-media-wmx'                  | WINDOWS WMX音频类型，归属类型为AUDIO。       |
| WINDOWS_MEDIA_WVX<sup>11+</sup>                        | 'com.microsoft.windows-media-wvx'                  | WINDOWS WVX音频类型，归属类型为AUDIO。       |
| WINDOWS_MEDIA_WAX<sup>11+</sup>                        | 'com.microsoft.windows-media-wax'                  | WINDOWS WAX音频类型，归属类型为AUDIO。       |
| FILE                       | 'general.file'                 | 所有文件的基类型，归属类型为ENTITY。                          |
| DIRECTORY<sup>11+</sup>             | 'general.directory'               | 所有目录的基类型，归属类型为ENTITY。                          |
| FOLDER        | 'general.folder'           | 所有文件夹的基类型，归属类型为DIRECTORY。                         |
| SYMLINK<sup>11+</sup>        | 'general.symlink'          | 所有符号链接的基类型，归属类型为ENTITY。                        |
| ARCHIVE<sup>11+</sup>                         | 'general.archive'                   | 所有文件和目录存档文件的基类型，归属类型为OBJECT。                   |
| BZ2_ARCHIVE<sup>11+</sup>                        | 'general.bz2-archive'                  | BZ2存档文件类型，归属类型为ARCHIVE。           |
| DISK_IMAGE<sup>11+</sup>                        | 'general.disk-image'                  | 所有可作为卷装载项的文件类型的基类型，归属类型为ARCHIVE。  |
| TAR_ARCHIVE<sup>11+</sup>                        | 'general.tar-archive'                  | TAR存档文件类型，归属类型为ARCHIVE。           |
| ZIP_ARCHIVE<sup>11+</sup>                       | 'general.zip-archive'                 | ZIP存档文件类型，归属类型为ARCHIVE。           |
| JAVA_ARCHIVE<sup>11+</sup>             | 'com.sun.java-archive'               | JAVA存档文件类型，归属类型为ARCHIVE。          |
| GNU_TAR_ARCHIVE<sup>11+</sup>         | 'org.gnu.gnu-tar-archive'           | GUN存档文件类型，归属类型为ARCHIVE。           |
| GNU_ZIP_ARCHIVE<sup>11+</sup>        | 'org.gnu.gnu-zip-archive'          | GZIP存档文件类型，归属类型为ARCHIVE。          |
| GNU_ZIP_TAR_ARCHIVE<sup>11+</sup>                         | 'org.gnu.gnu-zip-tar-archive'                   | GZIP TAR存档文件类型，归属类型为ARCHIVE。       |
| CALENDAR<sup>11+</sup>                        | 'general.calendar'                  | 所有日程类数据的基类型，归属类型为OBJECT。                       |
| CONTACT<sup>11+</sup>                        | 'general.contact'                  | 所有联系人类数据的基类型，归属类型为OBJECT。                      |
| DATABASE<sup>11+</sup>                        | 'general.database'                  | 所有数据库文件的基类型，归属类型为OBJECT。                       |
| MESSAGE<sup>11+</sup>                       | 'general.message'                 | 所有消息类数据的基类型，归属类型为OBJECT。                       |
| VCARD<sup>11+</sup>             | 'general.vcard'               | 所有电子名片类数据的基类型，归属类型为OBJECT。                     |
| NAVIGATION<sup>11+</sup>         | 'general.navigation'           | 所有导航类数据的基类型，归属类型为OBJECT。                       |
| LOCATION<sup>11+</sup>        | 'general.location'          | 导航定位类型，归属类型为NAVIGATION。            |
| OPENHARMONY_FORM                         | 'openharmony.form'                   | OpenHarmony系统定义的卡片类型，归属类型为OBJECT。              |
| OPENHARMONY_APP_ITEM                        | 'openharmony.app-item'                  | OpenHarmony系统定义的桌面图标类型，归属类型为OBJECT。            |
| OPENHARMONY_PIXEL_MAP                        | 'openharmony.pixel-map'                  | OpenHarmony系统定义的像素图类型，归属类型为IMAGE。             |
| OPENHARMONY_ATOMIC_SERVICE<sup>11+</sup>                        | 'openharmony.atomic-service'                  | OpenHarmony系统定义的元服务类型，归属类型为OBJECT。             |
| OPENHARMONY_PACKAGE<sup>11+</sup>                        | 'openharmony.package'                  | OpenHarmony系统定义的包（即目录的打包文件），归属类型为DIRECTORY。             |
| OPENHARMONY_HAP<sup>11+</sup>                        | 'openharmony.hap'                  | OpenHarmony系统定义的能力包，归属类型为OPENHARMONY_PACKAGE。             |

## TypeDescriptor<sup>11+</sup> 

标准化数据类型的描述类，它包含了一些属性和方法用于描述标准化数据类型自身以及和其他标准化数据类型之间的归属与层级关系。

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

| 名称    | 类型                    | 可读 | 可写 | 说明                                                       |
| ------- | ----------------------- | ---- | ---- |----------------------------------------------------------|
| typeId<sup>11+</sup>     | string | 是   | 否   | 标准化数据类型的ID（即[UniformDataType](#uniformdatatype)中对应的枚举值）。 |
| belongingToTypes<sup>11+</sup>  | Array\<string>          | 是   | 否   | 标准化数据类型所归属的类型typeId列表。                                   |
| description<sup>11+</sup>     | string                  | 是   | 否   | 标准化数据类型的简要说明。                                            |
| referenceURL<sup>11+</sup>     | string                  | 是   | 否   | 标准化数据类型的参考链接URL，用于描述类型的详细信息。                            |
| iconFile<sup>11+</sup>     | string                  | 是   | 否   | 标准化数据类型的默认图标文件路径，可能为空字符串（即没有默认图标），应用可以自行决定是否使用该默认图标。                                   |

### belongsTo<sup>11+</sup> 

belongsTo(type: string): boolean

判断当前标准化数据类型是否归属于指定的标准化数据类型。

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

**参数：**

| 参数名  | 类型 | 必填  | 说明                    |
| -----  | ------  | ----  | ----------------------- |
| type    | string  | 是    |所指定的标准化数据类型。   |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回true表示当前的标准化数据类型归属于所指定的标准化数据类型，包括所指定类型与当前类型相同的情况；返回false则表示无归属关系。 |

**示例：**

```ts
import uniformTypeDescriptor from '@ohos.data.uniformTypeDescriptor';
import { BusinessError } from '@ohos.base';

try{
    let typeObj : uniformTypeDescriptor.TypeDescriptor = uniformTypeDescriptor.getTypeDescriptor('general.type-script');
    let ret = typeObj.belongsTo('general.plain-text');
    if(ret) {
        console.info('type general.type-script belongs to type general.plain-text');
    }
} catch(e) {
    let error: BusinessError = e as BusinessError;
    console.error(`belongsTo throws an exception. code is ${error.code}, message is ${error.message} `);
}
```

### isLowerLevelType<sup>11+</sup> 

isLowerLevelType(type: string): boolean

判断当前标准化数据类型是否是指定标准化数据类型的低层级类型。例如TYPE_SCRIPT为SOURCE_CODE的低层级类型，TYPE_SCRIPT和SOURCE_CODE为PLAIN_TEXT的低层级类型。

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

**参数：**

| 参数名  | 类型 | 必填  | 说明                    |
| -----  | ------  | ----  | ----------------------- |
| type    | string  | 是    |所指定的标准化数据类型（即[UniformDataType](#uniformdatatype)中对应的枚举值）。   |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回true表示当前的标准化数据类型是所指定标准化数据类型的低层级类型，否则返回false。|

**示例：**

```ts
import uniformTypeDescriptor from '@ohos.data.uniformTypeDescriptor';
import { BusinessError } from '@ohos.base';

try{
    let typeObj : uniformTypeDescriptor.TypeDescriptor = uniformTypeDescriptor.getTypeDescriptor('general.type-script');
    let ret = typeObj.isLowerLevelType('general.plain-text');
    if(ret) {
        console.info('type general.type-script is lower level type of type general.plain-text');
    }
} catch(e) {
    let error: BusinessError = e as BusinessError;
    console.error(`isLowerLevelType throws an exception. code is ${error.code}, message is ${error.message} `);
}
```

### isHigherLevelType<sup>11+</sup> 

isHigherLevelType(type: string): boolean

判断当前标准化数据类型是否是指定标准化数据类型的高层级类型。例如SOURCE_CODE为TYPE_SCRIPT的高层级类型，PLAIN_TEXT为SOURCE_CODE和TYPE_SCRIPT的高层级类型。

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

**参数：**

| 参数名  | 类型 | 必填  | 说明                    |
| -----  | ------  | ----  | ----------------------- |
| type    | string  | 是    |所指定的标准化数据类型（即[UniformDataType](#uniformdatatype)中对应的枚举值）。   |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回true表示当前的标准化数据类型是所指定标准化数据类型的高层级类型，否则返回false。|

**示例：**

```ts
import uniformTypeDescriptor from '@ohos.data.uniformTypeDescriptor';
import { BusinessError } from '@ohos.base';

try{
    let typeObj : uniformTypeDescriptor.TypeDescriptor = uniformTypeDescriptor.getTypeDescriptor('general.plain-text');
    let ret = typeObj.isHigherLevelType('general.type-script');
    if(ret) {
        console.info('type general.plain-text is higher level type of type general.type-script');
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

**示例：**

```ts
import uniformTypeDescriptor from '@ohos.data.uniformTypeDescriptor';
import { BusinessError } from '@ohos.base';

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
| typeId    | string  | 是    |标准化数据类型ID。   |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| [TypeDescriptor](#typedescriptor11) | 返回标准化数据类型描述类对象，如果要查询的标准化数据类型不存在则返回null。|

**示例：**

```ts
import uniformTypeDescriptor from '@ohos.data.uniformTypeDescriptor';
import { BusinessError } from '@ohos.base';

try {
    let typeObj : uniformTypeDescriptor.TypeDescriptor = uniformTypeDescriptor.getTypeDescriptor('com.adobe.photoshop-image');
    if (typeObj) {
        let typeId = typeObj.typeId;
        let belongingToTypes = typeObj.belongingToTypes;
        let description = typeObj.description;
        let referenceURL = typeObj.referenceURL;
        let iconFile = typeObj.iconFile;
        console.info(`typeId: ${typeId}, belongingToTypes: ${belongingToTypes}, description: ${description}, referenceURL: ${referenceURL}, iconFile: ${iconFile}`);
    } else {
        console.info('type does not exist');
    }
} catch(e) {
    let error: BusinessError = e as BusinessError;
    console.error(`getTypeDescriptor throws an exception. code is ${error.code}, message is ${error.message} `);
}
```

## uniformTypeDescriptor.getUniformDataTypeByFilenameExtension<sup>11+</sup>

getUniformDataTypeByFilenameExtension(filenameExtension: string, belongsTo?: string): string

根据给定的文件后缀名和所归属的标准化数据类型查询标准化数据类型的ID。

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

**参数：**

| 参数名  | 类型 | 必填  | 说明                    |
| -----  | ------  | ----  | ----------------------- |
| filenameExtension    | string  | 是    |文件后缀名称。   |
| belongsTo    | string  | 否    |要查询的标准化数据类型所归属类型ID，无默认值，若*********************只按照文件后缀名称查询标准化数据类型ID。   |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| string | 返回与给定文件后缀名以及归属类型ID（如果设置了belongsTo参数）匹配的标准化数据类型ID，如果要查询的标准化数据类型不存在则返回null。|

**示例：**

```ts
import uniformTypeDescriptor from '@ohos.data.uniformTypeDescriptor';
import { BusinessError } from '@ohos.base';

try {
    let typeId = uniformTypeDescriptor.getUniformDataTypeByFilenameExtension('.ts', 'general.plain-text');
    if(typeId) {
        console.info('typeId is general.type-script');
    }
} catch(e) {
    let error: BusinessError = e as BusinessError;
    console.error(`getUniformDataTypeByFilenameExtension throws an exception. code is ${error.code}, message is ${error.message} `);
}
```

## uniformTypeDescriptor.getUniformDataTypeByMIMEType<sup>11+</sup>

getUniformDataTypeByMIMEType(mimeType: string, belongsTo?: string): string

根据给定的MIME类型和所归属的标准化数据类型查询标准化数据类型的ID。

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

**参数：**

| 参数名  | 类型 | 必填  | 说明                    |
| -----  | ------  | ----  | ----------------------- |
| mimeType    | string  | 是    |MIME类型名称。   |
| belongsTo    | string  | 否    |要查询的标准化数据类型所归属类型ID。无默认值，若*********************只按照MIME类型名称查询标准化数据类型ID。   |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| string | 返回与MIME类型名称以及归属类型ID（如果设置了belongsTo参数）匹配的标准化数据类型ID，如果要查询的标准化数据类型不存在则返回null。|

**示例：**

```ts
import uniformTypeDescriptor from '@ohos.data.uniformTypeDescriptor';
import { BusinessError } from '@ohos.base';

try {
    let typeId = uniformTypeDescriptor.getUniformDataTypeByMIMEType('image/jpeg', 'general.image');
    if(typeId) {
        console.info('typeId is general.jpeg');
    }
} catch(e) {
    let error: BusinessError = e as BusinessError;
    console.error(`getUniformDataTypeByMIMEType throws an exception. code is ${error.code}, message is ${error.message} `);
}
```