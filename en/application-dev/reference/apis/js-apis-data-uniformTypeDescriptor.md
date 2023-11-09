# @ohos.data.uniformTypeDescriptor (Standard Data Definition)

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
| TEXT                       | 'general.text'                   | Base text type.                         |
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
| TYPE_SCRIPT<sup>11+</sup>                        | 'general.type-script'                  | TypeScript source code.<br>This type belongs to **SOURCE_CODE**.|
| JAVA_SCRIPT<sup>11+</sup>                        | 'general.java-script'                  | JavaScript source code.<br>This type belongs to **SOURCE_CODE**.|
| C_HEADER<sup>11+</sup>                        | 'general.c-header'                  | Header file in C.<br>This type belongs to **SOURCE_CODE**.         |
| C_SOURCE<sup>11+</sup>                       | 'general.c-source'                 | Source code in C.<br>This type belongs to **SOURCE_CODE**.         |
| C_PLUS_PLUS_HEADER<sup>11+</sup>             | 'general.c-plus-plus-header'               | Header file in C++.<br>This type belongs to **SOURCE_CODE**.       |
| C_PLUS_PLUS_SOURCE<sup>11+</sup>         | 'general.c-plus-plus-source'           | Source code in C++.<br>This type belongs to **SOURCE_CODE**.       |
| JAVA_SOURCE<sup>11+</sup>        | 'general.java-source'          | Source code in Java.<br>This type belongs to **SOURCE_CODE**.      |
| EBOOK<sup>11+</sup>                         | 'general.ebook'                   | Base eBook format type.                    |
| EPUB<sup>11+</sup>                        | 'general.epub'                  | Electronic publication (EPUB).<br>This type belongs to **EBOOK**.    |
| AZW<sup>11+</sup>                        | 'com.amazon.azw'                  | AZW.<br>This type belongs to **EBOOK**.         |
| AZW3<sup>11+</sup>                        | 'com.amazon.azw3'                  | AZW3.<br>This type belongs to **EBOOK**.        |
| KFX<sup>11+</sup>                       | 'com.amazon.kfx'                 | KFX.<br>This type belongs to **EBOOK**.         |
| MOBI<sup>11+</sup>             | 'com.amazon.mobi'               | MOBI.<br>This type belongs to **EBOOK**.        |
| MEDIA<sup>11+</sup>         | 'general.media'           | Base media type.                         |
| IMAGE        | 'general.image'          | Image.<br>This type belongs to **MEDIA**.             |
| JPEG<sup>11+</sup>                         | 'general.jpeg'                   | JPEG.<br>This type belongs to **IMAGE**.             |
| PNG<sup>11+</sup>                        | 'general.png'                  | PNG.<br>This type belongs to **IMAGE**.              |
| RAW_IMAGE<sup>11+</sup>                        | 'general.raw-image'                  | Raw image.<br>This type belongs to **IMAGE**.         |
| TIFF<sup>11+</sup>                        | 'general.tiff'                  | TIFF.<br>This type belongs to **IMAGE**.             |
| BMP<sup>11+</sup>                       | 'com.microsoft.bmp'                 | BMP.<br>This type belongs to **IMAGE**.        |
| ICO<sup>11+</sup>             | 'com.microsoft.ico'               | Windows icon.<br>This type belongs to **IMAGE**.        |
| PHOTOSHOP_IMAGE<sup>11+</sup>         | 'com.adobe.photoshop-image'           | Adobe Photoshop image.<br>This type belongs to **IMAGE**.  |
| AI_IMAGE<sup>11+</sup>        | 'com.adobe.illustrator.ai-image'          | Adobe Illustrator image (.ai).<br>This type belongs to **IMAGE**.|
| WORD_DOC<sup>11+</sup>                         | 'com.microsoft.word.doc'                   | Microsoft Word.               |
| EXCEL<sup>11+</sup>                        | 'com.microsoft.excel.xls'                  | Microsoft Excel.              |
| PPT<sup>11+</sup>                        | 'com.microsoft.powerpoint.ppt'                  | Microsoft PowerPoint.       |
| PDF<sup>11+</sup>                        | 'com.adobe.pdf'                  | PDF.                          |
| POSTSCRIPT<sup>11+</sup>                       | 'com.adobe.postscript'                 | PostScript.                   |
| ENCAPSULATED_POSTSCRIPT<sup>11+</sup>             | 'com.adobe.encapsulated-postscript'               | Encapsulated PostScript.        |
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
| FILE                       | 'general.file'                 | File.                         |
| DIRECTORY<sup>11+</sup>             | 'general.directory'               | Directory.                         |
| FOLDER        | 'general.folder'           | Folder.                        |
| SYMLINK<sup>11+</sup>        | 'general.symlink'          | Symlink.                       |
| ARCHIVE<sup>11+</sup>                         | 'general.archive'                   | Base archive type.                  |
| BZ2_ARCHIVE<sup>11+</sup>                        | 'general.bz2-archive'                  | BZ2.<br>This type belongs to **ARCHIVE**.          |
| DISK_IMAGE<sup>11+</sup>                        | 'general.disk-image'                  | Type of any file that can be mounted as a volume.<br>This type belongs to ARCHIVE. |
| TAR_ARCHIVE<sup>11+</sup>                        | 'general.tar-archive'                  | TAR.<br>This type belongs to ARCHIVE.          |
| ZIP_ARCHIVE<sup>11+</sup>                       | 'general.zip-archive'                 | ZIP.<br>This type belongs to **ARCHIVE**.          |
| JAVA_ARCHIVE<sup>11+</sup>             | 'com.sun.java-archive'               | JAR (Java archive).<br>This type belongs to **ARCHIVE**.         |
| GNU_TAR_ARCHIVE<sup>11+</sup>         | 'org.gnu.gnu-tar-archive'           | GUN archive.<br>This type belongs to **ARCHIVE**.          |
| GNU_ZIP_ARCHIVE<sup>11+</sup>        | 'org.gnu.gnu-zip-archive'          | GZIP archive.<br>This type belongs to **ARCHIVE**.         |
| GNU_ZIP_TAR_ARCHIVE<sup>11+</sup>                         | 'org.gnu.gnu-zip-tar-archive'                   | GZIP TAR.<br>This type belongs to **ARCHIVE**.      |
| CALENDAR<sup>11+</sup>                        | 'general.calendar'                  | Calendar.                      |
| CONTACT<sup>11+</sup>                        | 'general.contact'                  | Contact.                     |
| DATABASE<sup>11+</sup>                        | 'general.database'                  | Database.                      |
| MESSAGE<sup>11+</sup>                       | 'general.message'                 | Message.                      |
| VCARD<sup>11+</sup>             | 'general.vcard'               | vCard.                    |
| NAVIGATION<sup>11+</sup>         | 'general.navigation'           | Base navigation type.                      |
| LOCATION<sup>11+</sup>        | 'general.location'          | Location data.<br>This type belongs to **NAVIGATION**.           |
| OPENHARMONY_FORM                         | 'openharmony.form'                   | Widget defined by OpenHarmony.             |
| OPENHARMONY_APP_ITEM                        | 'openharmony.app-item'                  | Home screen icon defined by OpenHarmony.           |
| OPENHARMONY_PIXEL_MAP                        | 'openharmony.pixel-map'                  | Pixel map defined by OpenHarmony.            |
| OPENHARMONY_ATOMIC_SERVICE<sup>11+</sup>                        | 'openharmony.atomic-service'                  | Atomic service defined by OpenHarmony.            |


## TypeDescriptor<sup>11+</sup> 

Provides attributes and APIs for describing a uniform data type and its relationship with other uniform data types.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name   | Type                   | Readable| Writable| Description                                                      |
| ------- | ----------------------- | ---- | ---- |----------------------------------------------------------|
| typeId<sup>11+</sup>     | string | Yes  | No  | ID of the uniform data type, which is an enum of [UniformDataType](#uniformdatatype).|
| belongingToTypes<sup>11+</sup>  | Array\<string>          | Yes  | No  | Data types to which the uniform data type belongs.                                  |
| description<sup>11+</sup>     | string                  | Yes  | No  | Brief description of the uniform data type.                                           |
| referenceURL<sup>11+</sup>     | string                  | Yes  | No  | URL of the link to the reference (detailed information) of the uniform data type.                           |
| iconFile<sup>11+</sup>     | string                  | Yes  | No  | File path of the default icon for the uniform data type. An empty string means the uniform data type has no default icon. The application can determine whether to use the default icon.                                       |

### equals<sup>11+</sup> 

equals(typeDescriptor: TypeDescriptor): boolean

Checks whether this uniform data type is the same as the specified uniform data type. That is, compares **typeId**s of two [TypeDescriptor](#typedescriptor11) objects.

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
      console.info(`typeA is not equal to typeB`);
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
| [TypeDescriptor](#typedescriptor11) | **TypeDescriptor** object obtained.|

**Example**

```ts
import uniformTypeDescriptor from '@ohos.data.uniformTypeDescriptor';
import { BusinessError } from '@ohos.base';

try {
    let typeObj : uniformTypeDescriptor.TypeDescriptor = uniformTypeDescriptor.getTypeDescriptor('com.adobe.photoshop-image');
    let typeId = typeObj.typeId;
    let belongingToTypes = typeObj.belongingToTypes;
    let description = typeObj.description;
    let referenceURL = typeObj.referenceURL;
    let iconFile = typeObj.iconFile;
    console.info('typeId: ' + typeId + ', belongingToTypes: ' + belongingToTypes + ', description: ' + description + ', referenceURL: ' + referenceURL + ', iconFile: ' + iconFile);
} catch(e) {
    let error: BusinessError = e as BusinessError;
    console.error(`getTypeDescriptor throws an exception. code is ${error.code}, message is ${error.message} `);
}
```
