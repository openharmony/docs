# @ohos.data.uniformTypeDescriptor (Uniform Data Definition and Description)

The **uniformTypeDescriptor** module abstracts and defines OpenHarmony uniform data types.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import uniformTypeDescriptor from '@ohos.data.uniformTypeDescriptor';
```

## UniformDataType

Enumerates OpenHarmony uniform data types. Some data types are related. For example, the JPEG type belongs to the IMAGE type.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name                        | Value                           | Description                                |
|----------------------------|------------------------------|------------------------------------|
| ENTITY<sup>11+</sup>                       | 'general.entity'                   | Base physical storage type.<br>This type is uncategorized.                         |
| OBJECT<sup>11+</sup>                       | 'general.object'                   | Base logical content type.<br>This type is uncategorized.                         |
| COMPOSITE_OBJECT<sup>11+</sup>                       | 'general.composite-object'                   | Base composite content type. For example, a PDF file that contains text and image.<br>This type belongs to **OBJECT**.                         |
| TEXT                       | 'general.text'                   | Base text type.<br>This type belongs to **OBJECT**.                         |
| PLAIN_TEXT                | 'general.plain-text'             | Text without specific encoding or identifier.<br>This type belongs to **TEXT**.       |
| HTML                  | 'general.html'                   | HTML.<br>This type belongs to **TEXT**.              |
| HYPERLINK         | 'general.hyperlink'              | Hyperlink.<br>This type belongs to **TEXT**.                 |
| XML<sup>11+</sup>    | 'general.xml'                   | XML.<br>This type belongs to **TEXT**.               |
| SOURCE_CODE<sup>11+</sup>                | 'general.source-code'                  | Base source code type.<br>This type belongs to **PLAIN_TEXT**.       |
| SCRIPT<sup>11+</sup>    | 'general.script'                  | Source code in any scripting language.<br>This type belongs to **SOURCE_CODE**.  |
| SHELL_SCRIPT<sup>11+</sup>               | 'general.shell-script'                  | Shell script.<br>This type belongs to **SCRIPT**.           |
| CSH_SCRIPT<sup>11+</sup>      | 'general.csh-script'                 | C shell script.<br>This type belongs to **SHELL_SCRIPT**.   |
| PERL_SCRIPT<sup>11+</sup> |'general.perl-script'               | Perl script.<br>This type belongs to **SHELL_SCRIPT**.      |
| PHP_SCRIPT<sup>11+</sup>         | 'general.php-script'           | PHP script.<br>This type belongs to **SHELL_SCRIPT**.       |
| PYTHON_SCRIPT<sup>11+</sup>        | 'general.python-script'          | Python script.<br>This type belongs to **SHELL_SCRIPT**.    |
| RUBY_SCRIPT<sup>11+</sup>                         | 'general.ruby-script'                   | Ruby script.<br>This type belongs to **SHELL_SCRIPT**.      |
| TYPE_SCRIPT<sup>11+</sup>                        | 'general.type-script'                  | TypeScript source code.<br>This type belongs to **SCRIPT**.|
| JAVA_SCRIPT<sup>11+</sup>                        | 'general.java-script'                  | JavaScript source code.<br>This type belongs to **SCRIPT**.|
| C_HEADER<sup>11+</sup>                        | 'general.c-header'                  | Header file in C.<br>This type belongs to **SOURCE_CODE**.         |
| C_SOURCE<sup>11+</sup>                       | 'general.c-source'                 | Source code in C.<br>This type belongs to **SOURCE_CODE**.         |
| C_PLUS_PLUS_HEADER<sup>11+</sup>             | 'general.c-plus-plus-header'               | Header file in C++.<br>This type belongs to **SOURCE_CODE**.       |
| C_PLUS_PLUS_SOURCE<sup>11+</sup>         | 'general.c-plus-plus-source'           | Source code in C++.<br>This type belongs to **SOURCE_CODE**.       |
| JAVA_SOURCE<sup>11+</sup>        | 'general.java-source'          | Source code in Java.<br>This type belongs to **SOURCE_CODE**.      |
| EBOOK<sup>11+</sup>                         | 'general.ebook'                   | Base eBook file format type.<br>This type belongs to **COMPOSITE_OBJECT**.                    |
| EPUB<sup>11+</sup>                        | 'general.epub'                  | Electronic publication (EPUB).<br>This type belongs to **EBOOK**.    |
| AZW<sup>11+</sup>                        | 'com.amazon.azw'                  | AZW.<br>This type belongs to **EBOOK**.         |
| AZW3<sup>11+</sup>                        | 'com.amazon.azw3'                  | AZW3.<br>This type belongs to **EBOOK**.        |
| KFX<sup>11+</sup>                       | 'com.amazon.kfx'                 | KFX.<br>This type belongs to **EBOOK**.         |
| MOBI<sup>11+</sup>             | 'com.amazon.mobi'               | MOBI.<br>This type belongs to **EBOOK**.        |
| MEDIA<sup>11+</sup>         | 'general.media'           | Base media type.<br>This type belongs to **OBJECT**.                         |
| IMAGE        | 'general.image'          | Image.<br>This type belongs to **MEDIA**.             |
| JPEG<sup>11+</sup>                         | 'general.jpeg'                   | JPEG.<br>This type belongs to **IMAGE**.             |
| PNG<sup>11+</sup>                        | 'general.png'                  | PNG.<br>This type belongs to **IMAGE**.              |
| RAW_IMAGE<sup>11+</sup>                        | 'general.raw-image'                  | Raw image.<br>This type belongs to **IMAGE**.         |
| TIFF<sup>11+</sup>                        | 'general.tiff'                  | TIFF.<br>This type belongs to **IMAGE**.             |
| BMP<sup>11+</sup>                       | 'com.microsoft.bmp'                 | BMP.<br>This type belongs to **IMAGE**.        |
| ICO<sup>11+</sup>             | 'com.microsoft.ico'               | Windows icon.<br>This type belongs to **IMAGE**.        |
| PHOTOSHOP_IMAGE<sup>11+</sup>         | 'com.adobe.photoshop-image'           | Adobe Photoshop image.<br>This type belongs to **IMAGE**.  |
| AI_IMAGE<sup>11+</sup>        | 'com.adobe.illustrator.ai-image'          | Adobe Illustrator image (.ai).<br>This type belongs to **IMAGE**.|
| WORD_DOC<sup>11+</sup>                         | 'com.microsoft.word.doc'                   | Microsoft Word. <br>This type belongs to **COMPOSITE_OBJECT**.               |
| EXCEL<sup>11+</sup>                        | 'com.microsoft.excel.xls'                  | Microsoft Excel. <br>This type belongs to **COMPOSITE_OBJECT**.              |
| PPT<sup>11+</sup>                        | 'com.microsoft.powerpoint.ppt'                  | Microsoft PowerPoint.<br>This type belongs to **COMPOSITE_OBJECT**.       |
| PDF<sup>11+</sup>                        | 'com.adobe.pdf'                  | PDF.<br>This type belongs to **COMPOSITE_OBJECT**.                          |
| POSTSCRIPT<sup>11+</sup>                       | 'com.adobe.postscript'                 | PostScript.<br>This type belongs to **COMPOSITE_OBJECT**.                   |
| ENCAPSULATED_POSTSCRIPT<sup>11+</sup>             | 'com.adobe.encapsulated-postscript'               | Encapsulated PostScript.<br>This type belongs to **POSTSCRIPT**.        |
| VIDEO       | 'general.video'           | Base video type.<br>This type belongs to **MEDIA**.             |
| AVI<sup>11+</sup>        | 'general.avi'          | AVI.<br>This type belongs to **VIDEO**.              |
| MPEG<sup>11+</sup>                         | 'general.mpeg'                   | MPGE-1 or MPGE-2.<br>This type belongs to **VIDEO**.    |
| MPEG4<sup>11+</sup>                        | 'general.mpeg-4'                  | MPGE-4.<br>This type belongs to **VIDEO**.           |
| VIDEO_3GPP<sup>11+</sup>                        | 'general.3gpp'                  | 3GP (3GPP file format).<br>This type belongs to **VIDEO**.             |
| VIDEO_3GPP2<sup>11+</sup>                        | 'general.3gpp2'                  | 3G2 (3GPP2 file format).<br>This type belongs to **VIDEO**.            |
| WINDOWS_MEDIA_WM<sup>11+</sup>                       | 'com.microsoft.windows-media-wm'                 | Windows WM.<br>This type belongs to **VIDEO**.       |
| WINDOWS_MEDIA_WMV<sup>11+</sup>             | 'com.microsoft.windows-media-wmv'               | Windows WMV.<br>This type belongs to **VIDEO**.      |
| WINDOWS_MEDIA_WMP<sup>11+</sup>         | 'com.microsoft.windows-media-wmp'           | Windows WMP.<br>This type belongs to **VIDEO**.      |
| AUDIO       | 'general.audio'          | Base audio type.<br>This type belongs to **MEDIA**.             |
| AAC<sup>11+</sup>                         | 'general.aac'                   | AAC.<br>This type belongs to **AUDIO**.              |
| AIFF<sup>11+</sup>                        | 'general.aiff'                  | AIFF.<br>This type belongs to **AUDIO**.             |
| ALAC<sup>11+</sup>                        | 'general.alac'                  | ALAC.<br>This type belongs to **AUDIO**.             |
| FLAC<sup>11+</sup>                        | 'general.flac'                  | FLAC.<br>This type belongs to **AUDIO**.             |
| MP3<sup>11+</sup>                       | 'general.mp3'                 | MP3.<br>This type belongs to **AUDIO**.              |
| OGG<sup>11+</sup>              | 'general.ogg'               | OGG.<br>This type belongs to **AUDIO**.              |
| PCM<sup>11+</sup>         | 'general.pcm'           | PCM.<br>This type belongs to **AUDIO**.              |
| WINDOWS_MEDIA_WMA<sup>11+</sup>        | 'com.microsoft.windows-media-wma'          | Windows WMA.<br>This type belongs to **AUDIO**.      |
| WAVEFORM_AUDIO<sup>11+</sup>                         | 'com.microsoft.waveform-audio'                   | Windows Waveform.<br>This type belongs to **AUDIO**.        |
| WINDOWS_MEDIA_WMX<sup>11+</sup>                        | 'com.microsoft.windows-media-wmx'                  | Windows WMX.<br>This type belongs to **AUDIO**.      |
| WINDOWS_MEDIA_WVX<sup>11+</sup>                        | 'com.microsoft.windows-media-wvx'                  | Windows WVX.<br>This type belongs to **AUDIO**.      |
| WINDOWS_MEDIA_WAX<sup>11+</sup>                        | 'com.microsoft.windows-media-wax'                  | Windows WAX.<br>This type belongs to **AUDIO**.      |
| FILE                       | 'general.file'                 | Base file type.<br>This type belongs to **ENTITY**.                         |
| DIRECTORY<sup>11+</sup>             | 'general.directory'               | Base directory type.<br>This type belongs to **ENTITY**.                         |
| FOLDER        | 'general.folder'           | Base folder type.<br>This type belongs to **DIRECTORY**.                        |
| SYMLINK<sup>11+</sup>        | 'general.symlink'          | Base symbolic type.<br>This type belongs to **ENTITY**.                       |
| ARCHIVE<sup>11+</sup>                         | 'general.archive'                   | Base archive file type. <br>This type belongs to **OBJECT**.                  |
| BZ2_ARCHIVE<sup>11+</sup>                        | 'general.bz2-archive'                  | BZ2.<br>This type belongs to **ARCHIVE**.          |
| DISK_IMAGE<sup>11+</sup>                        | 'general.disk-image'                  | Base type of any file that can be mounted as a volume.<br>This type belongs to **ARCHIVE**. |
| TAR_ARCHIVE<sup>11+</sup>                        | 'general.tar-archive'                  | TAR.<br>This type belongs to ARCHIVE.          |
| ZIP_ARCHIVE<sup>11+</sup>                       | 'general.zip-archive'                 | ZIP.<br>This type belongs to **ARCHIVE**.          |
| JAVA_ARCHIVE<sup>11+</sup>             | 'com.sun.java-archive'               | JAR (Java archive).<br>This type belongs to **ARCHIVE**.         |
| GNU_TAR_ARCHIVE<sup>11+</sup>         | 'org.gnu.gnu-tar-archive'           | GUN archive.<br>This type belongs to **ARCHIVE**.          |
| GNU_ZIP_ARCHIVE<sup>11+</sup>        | 'org.gnu.gnu-zip-archive'          | GZIP archive.<br>This type belongs to **ARCHIVE**.         |
| GNU_ZIP_TAR_ARCHIVE<sup>11+</sup>                         | 'org.gnu.gnu-zip-tar-archive'                   | GZIP TAR.<br>This type belongs to **ARCHIVE**.      |
| CALENDAR<sup>11+</sup>                        | 'general.calendar'                  | Base calendar type.<br>This type belongs to **OBJECT**.                      |
| CONTACT<sup>11+</sup>                        | 'general.contact'                  | Base contact type.<br>This type belongs to **OBJECT**.                     |
| DATABASE<sup>11+</sup>                        | 'general.database'                  | Base database file type.<br>This type belongs to **OBJECT**.                      |
| MESSAGE<sup>11+</sup>                       | 'general.message'                 | Base message type.<br>This type belongs to **OBJECT**.                      |
| VCARD<sup>11+</sup>             | 'general.vcard'               | Base electronic business card type.<br>This type belongs to **OBJECT**.                    |
| NAVIGATION<sup>11+</sup>         | 'general.navigation'           | Base navigation data type.<br>This type belongs to **OBJECT**.                      |
| LOCATION<sup>11+</sup>        | 'general.location'          | Location data.<br>This type belongs to **NAVIGATION**.           |
| OPENHARMONY_FORM                         | 'openharmony.form'                   | Widget defined by OpenHarmony.<br>This type belongs to **OBJECT**.             |
| OPENHARMONY_APP_ITEM                        | 'openharmony.app-item'                  | Home screen icon defined by OpenHarmony.<br>This type belongs to **OBJECT**.           |
| OPENHARMONY_PIXEL_MAP                        | 'openharmony.pixel-map'                  | Pixel map defined by OpenHarmony.<br>This type belongs to **IMAGE**.            |
| OPENHARMONY_ATOMIC_SERVICE<sup>11+</sup>                        | 'openharmony.atomic-service'                  | Atomic service defined by OpenHarmony.<br>This type belongs to **OBJECT**.            |
| OPENHARMONY_PACKAGE<sup>11+</sup>                        | 'openharmony.package'                  | Package defined by OpenHarmony (compressed directory).<br>This type belongs to **DIRECTORY**.            |
| OPENHARMONY_HAP<sup>11+</sup>                        | 'openharmony.hap'                  | Ability package defined by OpenHarmony.<br>This type belongs to **OPENHARMONY_PACKAGE**.            |

## TypeDescriptor<sup>11+</sup> 

Provides attributes and APIs for describing a uniform data type and its relationship with other uniform data types.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name   | Type                   | Readable| Writable| Description                                                      |
| ------- | ----------------------- | ---- | ---- |----------------------------------------------------------|
| typeId<sup>11+</sup>     | string | Yes  | No  | ID of the uniform data type, which is a value of [UniformDataType](#uniformdatatype).|
| belongingToTypes<sup>11+</sup>  | Array\<string>          | Yes  | No  | Data types to which the uniform data type belongs.                                  |
| description<sup>11+</sup>     | string                  | Yes  | No  | Brief description of the uniform data type.                                           |
| referenceURL<sup>11+</sup>     | string                  | Yes  | No  | URL of the link to the reference (detailed information) of the uniform data type.                           |
| iconFile<sup>11+</sup>     | string                  | Yes  | No  | File path of the default icon for the uniform data type. An empty string means the uniform data type has no default icon. The application can determine whether to use the default icon.                                  |

### belongsTo<sup>11+</sup> 

belongsTo(type: string): boolean

Checks whether this data type belongs to the specified uniform data type.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| type    | string  | Yes   |Uniform data type, which is a value of [UniformDataType](#uniformdatatype).  |

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if this data type belongs to or is the same as the specified uniform data type; returns **false** if they are not related.|

**Example**

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

Checks whether this data type is a lower-level type of the specified uniform data type. For example, **TYPE_SCRIPT** is a lower-level type of **SOURCE_CODE**, and **TYPE_SCRIPT** and **SOURCE_CODE** are lower-level types of **PLAIN_TEXT**.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| type    | string  | Yes   |Uniform data type, which is a value of [UniformDataType](#uniformdatatype).  |

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if this data type is a lower-level type of the specified uniform data type; returns **false** otherwise.|

**Example**

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

Checks whether this data type is a higher-level type of the specified uniform data type. For example, **SOURCE_CODE** is a higher-level type of **TYPE_SCRIPT**, and **PLAIN_TEXT** is a higher-level type of **SOURCE_CODE** and **TYPE_SCRIPT**.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| type    | string  | Yes   |Uniform data type, which is a value of [UniformDataType](#uniformdatatype).  |

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if this data type is a higher-level type of the specified uniform data type; returns **false** otherwise.|

**Example**

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

**Example**

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

Obtains the **TypeDescriptor** object based on the uniform data type ID.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| typeId    | string  | Yes   |ID of the uniform data type.  |

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| [TypeDescriptor](#typedescriptor11) | Returns the **TypeDescriptor** object obtained. If the uniform data type does not exist, **null** is returned.|

**Example**

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
        console.info('type com.adobe.photoshop-image does not exist');
    }
} catch(e) {
    let error: BusinessError = e as BusinessError;
    console.error(`getTypeDescriptor throws an exception. code is ${error.code}, message is ${error.message} `);
}
```

## uniformTypeDescriptor.getUniformDataTypeByFilenameExtension<sup>11+</sup>

getUniformDataTypeByFilenameExtension(filenameExtension: string, belongsTo?: string): string

Obtains the uniform data type ID based on the given file name extension and data type.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| filenameExtension    | string  | Yes   |File name extension.  |
| belongsTo    | string  | No   |ID of the uniform data type to which the target data type belongs. If this parameter is not specified, the uniform data type ID is queried based on the file name extension.  |

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| string | Returns the uniform data type ID obtained. If the uniform data type does not exist, **null** is returned.|

**Example**

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

Obtains the uniform data type ID based on the given MIME type and data type.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| mimeType    | string  | Yes   |MIME type.  |
| belongsTo    | string  | No   |ID of the uniform data type to which the target data type belongs. If this parameter is not specified, the uniform data type ID is queried based on the MIME type.  |

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| string | Returns the uniform data type ID obtained. If the uniform data type does not exist, **null** is returned.|

**Example**

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
