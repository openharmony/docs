# Reading and Editing Image XMP Metadata

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=2e8346d7d81ec4d3e0c3f3b74659b82257d07b17 translatedAt=2026-08-11T01:49:04.635Z pushedAt=2026-08-11T10:07:40.864Z -->

Extensible Metadata Platform (XMP) is a standard format for describing metadata of digital resources such as images, documents, and audio files. Based on XML, it allows rich descriptive information to be added to resources and supports custom namespaces and extensions. XMP metadata is typically embedded in images of formats such as JPEG, PNG, GIF, DNG, and TIFF.

Starting from API version 26.0.0, Image Kit supports reading XMP metadata from images in JPEG, PNG, GIF, DNG, and TIFF formats, and also supports editing XMP metadata for images in JPEG, PNG, and GIF formats.

## How to Develop

Obtain the image, create an `ImageSource` (optional), then obtain the `XMPMetadata` object, and use XMP path syntax to read and write tags. For XMP metadata operation methods, see [XMPMetadata](../../reference/apis-image-kit/arkts-apis-image-XMPMetadata.md).

1. Import the required modules.

   <!-- @[xmp_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/XMPUtility.ets) -->

   ``` TypeScript
   // Import the required modules.
   import { image } from '@kit.ImageKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. Obtain the `XMPMetadata` object.

   Before using XMP metadata APIs, you need to obtain an [XMPMetadata](../../reference/apis-image-kit/arkts-apis-image-XMPMetadata.md) instance. The following methods are supported:

   - Method 1: Manually create a `XMPMetadata` object. This applies to scenarios where you need to construct brand-new XMP metadata.

     <!-- @[create_xmp_metadata](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/XMPUtility.ets) -->

     ``` TypeScript
     async createXMPMetadata(): Promise<image.XMPMetadata> {
       let xmpMetadata = new image.XMPMetadata();
       console.info('Succeeded in creating XMPMetadata.');
       return xmpMetadata;
     }
     ```

   - Method 2: Read the XMP metadata from an image through `ImageSource`. This applies to scenarios where you need to read or modify the XMP metadata in an existing image.<br>You are advised to use the [readImageMetadataByType](../../reference/apis-image-kit/arkts-apis-image-ImageSource.md#readimagemetadatabytype24) API to obtain XMP metadata. You can directly pass `MetadataType.XMP_METADATA` to precisely retrieve XMP-type metadata, avoiding reading other irrelevant metadata.

     <!-- @[read_xmp_metadata_from_image](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/XMPUtility.ets) -->

     ``` TypeScript
     async readXMPMetadataFromImage(imageSource: image.ImageSource): Promise<image.XMPMetadata | undefined> {
       let types: image.MetadataType[] = [image.MetadataType.XMP_METADATA];
       try {
         let metaData: image.ImageMetadata = await imageSource.readImageMetadataByType(types);
         if (metaData != undefined && metaData.xmpMetadata != undefined) {
           // Successfully obtained the XMPMetadata object.
           let xmpMetadata = metaData.xmpMetadata;
           console.info('Succeeded in reading XMP metadata from image.');
           return xmpMetadata;
         }
         console.info('Failed to read XMP metadata from image.');
         return undefined;
       } catch (error) {
         console.error(`Failed to read XMP metadata. code is ${(error as BusinessError).code}, message is ${(error as BusinessError).message}`);
         return undefined;
       }
     }
     ```

3. Edit the XMP metadata.

   After locating the target tag using an XMP path, call the corresponding method to edit it. For example, use [setValue](../../reference/apis-image-kit/arkts-apis-image-XMPMetadata.md#setvalue) to set a tag value, [getTag](../../reference/apis-image-kit/arkts-apis-image-XMPMetadata.md#gettag) to obtain a tag value, and [removeTag](../../reference/apis-image-kit/arkts-apis-image-XMPMetadata.md#removetag) to delete a tag.

   <!-- @[operate_xmp_metadata](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/XMPUtility.ets) -->

   ``` TypeScript
   async operateXMPMetadata(xmpMetadata: image.XMPMetadata): Promise<void> {
     try {
       // Set the value of the xmp:title tag.
       await xmpMetadata.setValue(`${image.XMP_BASIC.prefix}:title`, image.XMPTagType.STRING, 'My Title');
   
       // Obtain the tag at the xmp:title path.
       let tag: image.XMPTag | null = await xmpMetadata.getTag(`${image.XMP_BASIC.prefix}:title`);
       console.info(`${image.XMP_BASIC.prefix}:title: ${tag?.value}`);
   
       // Delete the xmp:title tag.
       await xmpMetadata.removeTag(`${image.XMP_BASIC.prefix}:title`);
     } catch (error) {
       console.error(`Failed to operate XMP tags. code is ${(error as BusinessError).code}, message is ${(error as BusinessError).message}`);
     }
   }
   ```

4. Write the edited XMP metadata back to the image.

   The edited `XMPMetadata` object can be written back to the image file through [writeImageMetadata](../../reference/apis-image-kit/arkts-apis-image-ImageSource.md#writeimagemetadata23).

   > **NOTE**
   >
   > DNG and TIFF images do not support writing XMP metadata back to the image file.

   <!-- @[write_xmp_metadata_to_image](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/XMPUtility.ets) -->

   ``` TypeScript
   async writeXMPMetadataToImage(imageSource: image.ImageSource, xmpMetadata: image.XMPMetadata): Promise<void> {
     try {
       // Write the modified ImageMetadata (containing XMPMetadata) back to the image.
       let metaData: image.ImageMetadata = { xmpMetadata: xmpMetadata } as image.ImageMetadata;
       await imageSource.writeImageMetadata(metaData);
       console.info('Succeeded in writing XMP metadata to image.');
     } catch (error) {
       console.error(`Failed to write XMP metadata. code is ${(error as BusinessError).code}, message is ${(error as BusinessError).message}`);
     }
   }
   ```

## XMP Path Syntax

An XMP path is composed of the following syntax constructs. When using APIs such as [getTag](../../reference/apis-image-kit/arkts-apis-image-XMPMetadata.md#gettag), [setValue](../../reference/apis-image-kit/arkts-apis-image-XMPMetadata.md#setvalue), and [removeTag](../../reference/apis-image-kit/arkts-apis-image-XMPMetadata.md#removetag), you must specify the target tag through an XMP path.

### Basic Property Path

Use `":"` to separate the namespace prefix from the tag name, to locate a specific tag under a given namespace.

> **NOTE**
>
> - When using standard namespaces (such as `xmp`, `dc`, `exif`, etc.), no additional registration is required. Image Kit supports, but is not limited to, the standard namespaces defined in [Constants](../../reference/apis-image-kit/arkts-apis-image-c.md#constants-1).
> - When using a custom namespace, you must first register it via [registerXMPNamespace](../../reference/apis-image-kit/arkts-apis-image-XMPMetadata.md#registerxmpnamespace).

**Example**

<!-- @[set_and_get_basic_tag](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/XMPUtility.ets) -->

``` TypeScript
async setAndGetBasicTag(xmpMetadata: image.XMPMetadata): Promise<void> {
  try {
    // Set the value of the xmp:title tag, with the type as string and the value as 'My Title'.
    await xmpMetadata.setValue(`${image.XMP_BASIC.prefix}:title`, image.XMPTagType.STRING, 'My Title');

    // Obtain the tag at the xmp:title path.
    let tag: image.XMPTag | null = await xmpMetadata.getTag(`${image.XMP_BASIC.prefix}:title`);
    console.info(`${image.XMP_BASIC.prefix}:title: ${tag?.value}`);
  } catch (error) {
    console.error(`Failed to set or get basic tag. code is ${(error as BusinessError).code}, message is ${(error as BusinessError).message}`);
  }
}
```

### Array Index

Use `"[]"` with an index value to locate elements in an array. The index starts counting from 1 (1 represents the first element). Alternatively, use `"last()"` to access the last element.

> **NOTE**
>
> Before using an array index to add array elements, ensure that an array container node has been created. Use `setValue` to set the array path to the `UNORDERED_ARRAY`, `ORDERED_ARRAY`, `ALTERNATE_ARRAY`, or `ALTERNATE_TEXT` type to create an array container.

**Example 1: Creating an array container and adding elements**

The following example assumes that the custom namespace `book` has been registered. If it has not been registered yet, call [registerXMPNamespace](../../reference/apis-image-kit/arkts-apis-image-XMPMetadata.md#registerxmpnamespace) to complete the registration first.

<!-- @[create_array_and_add_elements](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/XMPUtility.ets) -->

``` TypeScript
async createArrayAndAddElements(xmpMetadata: image.XMPMetadata): Promise<void> {
  try {
    // Create an unordered array container.
    await xmpMetadata.setValue('book:fruits', image.XMPTagType.UNORDERED_ARRAY, undefined);

    // Add multiple elements to the array. The array index starts from 1.
    let fruits: string[] = ['apple', 'banana'];
    for (let i = 0; i < fruits.length; i++) {
      await xmpMetadata.setValue(`book:fruits[${i + 1}]`, image.XMPTagType.STRING, fruits[i]);
    }
    console.info('Succeeded in creating array and adding elements.');
  } catch (error) {
    console.error(`Failed to create array or add elements. code is ${(error as BusinessError).code}, message is ${(error as BusinessError).message}`);
  }
}
```

**Example 2: Obtaining an array element by index**

The following example assumes that the custom namespace `book` has been registered. If it has not been registered yet, call [registerXMPNamespace](../../reference/apis-image-kit/arkts-apis-image-XMPMetadata.md#registerxmpnamespace) to complete the registration first.

<!-- @[get_array_elements](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/XMPUtility.ets) -->

``` TypeScript
async getArrayElements(xmpMetadata: image.XMPMetadata): Promise<void> {
  try {
    // Obtain the second element.
    let tag2: image.XMPTag | null = await xmpMetadata.getTag('book:fruits[2]');
    console.info(`book:fruits[2]: ${tag2?.value}`);

    // Obtain the last element.
    let lastTag: image.XMPTag | null = await xmpMetadata.getTag('book:fruits[last()]');
    console.info(`book:fruits[last()]: ${lastTag?.value}`);
  } catch (error) {
    console.error(`Failed to get array elements. code is ${(error as BusinessError).code}, message is ${(error as BusinessError).message}`);
  }
}
```

### Structure Members

Use `"/"` to specify a structure member. When a tag is of the `STRUCTURE` type, you can use this syntax to access its child members.

> **NOTE**
>
> Before adding child members using a structure member path, you must first create the structure parent node. Use `setValue` to set the `STRUCTURE` type for the structure path, which creates the structure container.

**Example: Creating a structure parent node and operating on members**

The following example assumes that the custom namespace `book` has been registered. If it has not been registered yet, call [registerXMPNamespace](../../reference/apis-image-kit/arkts-apis-image-XMPMetadata.md#registerxmpnamespace) to complete the registration first.

<!-- @[create_struct_and_operate_members](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/XMPUtility.ets) -->

``` TypeScript
async createStructAndOperateMembers(xmpMetadata: image.XMPMetadata): Promise<void> {
  try {
    // Create the structure parent node.
    await xmpMetadata.setValue('book:parentNode', image.XMPTagType.STRUCTURE, undefined);

    // Add structure members.
    let members: Record<string, string> = {
      'child1': 'child1 value',
      'child2': 'child2 value'
    };
    for (const entry of Object.entries(members)) {
      await xmpMetadata.setValue(`book:parentNode/book:${entry[0]}`, image.XMPTagType.STRING, entry[1]);
    }

    // Obtain the value of a structure member.
    let childTag: image.XMPTag | null = await xmpMetadata.getTag('book:parentNode/book:child1');
    console.info(`book:parentNode/book:child1: ${childTag?.value}`);
  } catch (error) {
    console.error(`Failed to operate structure members. code is ${(error as BusinessError).code}, message is ${(error as BusinessError).message}`);
  }
}
```

### Accessing Qualifiers

Use `"/?"` to specify a qualifier. A qualifier provides additional descriptive information for a main tag and is also commonly used to access the language attribute of elements in a multilingual text array.

> **NOTE**
>
> Before adding a qualifier using a qualifier path, you must first create the main tag. You can create the main tag by calling `setValue` to set an appropriate type for the main tag path.

**Example 1: Setting and obtaining a qualifier value**

The following example assumes that the custom namespace `book` has been registered. If it has not been registered yet, call [registerXMPNamespace](../../reference/apis-image-kit/arkts-apis-image-XMPMetadata.md#registerxmpnamespace) to complete the registration first.

<!-- @[set_and_get_qualifier](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/XMPUtility.ets) -->

``` TypeScript
async setAndGetQualifierValue(xmpMetadata: image.XMPMetadata): Promise<void> {
  try {
    // Set the main tag book:bookTitle
    await xmpMetadata.setValue('book:bookTitle', image.XMPTagType.STRING, 'My Book Title');
    // Add the qualifier book:lastUpdated to the main tag.
    await xmpMetadata.setValue('book:bookTitle/?book:lastUpdated', image.XMPTagType.STRING, '2024-01-15');
    console.info('Succeeded in setting tag and qualifier.');

    // Obtain the value of the qualifier.
    let qualifierTag: image.XMPTag | null = await xmpMetadata.getTag('book:bookTitle/?book:lastUpdated');
    console.info(`book:bookTitle/?book:lastUpdated: ${qualifierTag?.value}`);
  } catch (error) {
    console.error(`Failed to operate qualifier. code is ${(error as BusinessError).code}, message is ${(error as BusinessError).message}`);
  }
}
```

**Example 2: Setting a language qualifier for multilingual text**

Multilingual text (language alternative array) is essentially an array of type `ALTERNATE_TEXT`. Before adding elements, you must first create the array container. Additionally, each element **must** specify a language via the `"xml:lang"` qualifier; otherwise, serialization will fail, preventing the data from being written back to the file.

<!-- @[set_language_qualifier](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/XMPUtility.ets) -->

``` TypeScript
async setLanguageQualifier(xmpMetadata: image.XMPMetadata): Promise<void> {
  try {
    // Create a language alternative array container.
    await xmpMetadata.setValue(`${image.DUBLIN_CORE.prefix}:title`, image.XMPTagType.ALTERNATE_TEXT, undefined);

    // Add the first multilingual text element and set its language qualifier.
    await xmpMetadata.setValue(`${image.DUBLIN_CORE.prefix}:title[1]`, image.XMPTagType.STRING, 'Hello');
    await xmpMetadata.setValue(`${image.DUBLIN_CORE.prefix}:title[1]/?xml:lang`, image.XMPTagType.STRING, 'en-US');

    // Add the second multilingual text element and its language qualifier.
    await xmpMetadata.setValue(`${image.DUBLIN_CORE.prefix}:title[2]`, image.XMPTagType.STRING, 'Hello');
    await xmpMetadata.setValue(`${image.DUBLIN_CORE.prefix}:title[2]/?xml:lang`, image.XMPTagType.STRING, 'zh-CN');

    // Obtain the language qualifier of the first element.
    let langTag: image.XMPTag | null = await xmpMetadata.getTag(`${image.DUBLIN_CORE.prefix}:title[1]/?xml:lang`);
    console.info(`dc:title[1]/?xml:lang: ${langTag?.value}`);
  } catch (error) {
    console.error(`Failed to set language qualifier. code is ${(error as BusinessError).code}, message is ${(error as BusinessError).message}`);
  }
}
```

### Namespace Prefix (Supported Only by rootPath)

Specify only the namespace prefix to enumerate all tags under that namespace.

> **NOTE**
>
> This syntax is applicable only to the `rootPath` parameter of the [enumerateTags](../../reference/apis-image-kit/arkts-apis-image-XMPMetadata.md#enumeratetags) and [getTags](../../reference/apis-image-kit/arkts-apis-image-XMPMetadata.md#gettags) APIs.

**Example**

<!-- @[enumerate_namespace_tags](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/XMPUtility.ets) -->

``` TypeScript
async enumerateNamespaceTags(xmpMetadata: image.XMPMetadata): Promise<void> {
  try {
    // Iterate over all fields in the Dublin Core namespace.
    xmpMetadata.enumerateTags((path: string, tag: image.XMPTag): boolean => {
      console.info(`path: ${path}, name: ${tag.name}, value: ${tag.value}`);
      return true;  // Return true to continue iteration.
    }, `${image.DUBLIN_CORE.prefix}`, { isRecursive: true, onlyQualifier: false });
    console.info('Succeeded in enumerating namespace tags.');
  } catch (error) {
    console.error(`Failed to enumerate namespace tags. code is ${(error as BusinessError).code}, message is ${(error as BusinessError).message}`);
  }
}
```