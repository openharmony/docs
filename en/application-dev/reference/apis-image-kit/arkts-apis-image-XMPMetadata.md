# Class (XMPMetadata)
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

Extensible Metadata Platform (XMP) metadata.

**Since:** 26.0.0

## Modules to Import

```ts
import { image } from '@kit.ImageKit';
```

## XMP Path Syntax

XMP paths are used to locate specific tags in metadata. A path is composed of a combination of the following syntactic components.

| Syntax Category| Description| Example|
| --- | --- | --- |
| Basic property path	| Use `:` to separate the namespace prefix and the tag name.| `dc:title` indicates the **title** field in the Dublin Core namespace.|
| Array index| Use `[]` with a 1-based index to locate an element, or use `[]` to access the last element.| `dc:subject[2]` indicates the second element, and `dc:subject[last()]` indicates the last element.|
| Struct member| Use `/` to specify a member of a struct.| `exif:Flash/exif:Fired` indicates the Fired member of the **exif:Flash** field.|
| Qualifier access| Use `/?` to specify a qualifier. It is also commonly used to access the language attribute of elements in a multilingual text array.| `dc:title/?book:lastUpdated` indicates the **book:lastUpdated** qualifier of **title**, and `dc:title[1]/?xml:lang` indicates the language qualifier of the first multilingual text element.|
| Namespace prefix<br>(supported only in **rootPath**)| Specify only the namespace prefix to traverse all tags under that namespace.| `dc` is used to traverse all fields under the Dublin Core namespace.|

## registerXMPNamespace

registerXMPNamespace(xmpNamespace: XMPNamespace): Promise\<void>

Registers a specified namespace. This API uses a promise to return the result.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Image.Core

**Parameters**

| Name      | Type                                               | Mandatory| Description        |
| ------------ | -------------------------------------------------- | ---- | ------------ |
| xmpNamespace | [XMPNamespace](arkts-apis-image-i.md#xmpnamespace) | Yes  | XMP namespace.|

**Return value**

| Type          | Description                    |
| -------------- | ----------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message         |
| ------- | ----------------- |
| 7600206 | Invalid argument. Possible causes: <br>1. Invalid namespace format. <br>2. The uri is already registered. <br>3. The prefix is already registered. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function RegisterNamespacePrefix() {
  try {
    let xmpMetadata = new image.XMPMetadata();
    // Register a custom namespace. After the registration, you can use the prefix to create tags.
    let xmpNamespace: image.XMPNamespace = {uri: "urn:example:book:1.0", prefix: "book"};
    await xmpMetadata.registerXMPNamespace(xmpNamespace);
    console.info('Succeeded in registering namespace prefix.');
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`Failed to register namespace prefix! code is ${err.code}, message is ${err.message}`);
  }
}
```

## setValue

setValue(path: string, type: XMPTagType, value?: string): Promise\<void>

Sets the type and value for the XMP tag at the specified path. This API uses a promise to return the result.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type   | Mandatory| Description        |
| ------ | ------ | ---- | ------------ |
| path   | string | Yes  | Path of the target XMP tag. For details about the path syntax, see [XMP Path Syntax](#xmp-path-syntax).|
| type   | [XMPTagType](arkts-apis-image-e.md#xmptagtype) | Yes  | XMP tag type.|
| value  | string | No  | XMP tag value. The default value is an empty string.|

**Return value**

| Type          | Description                    |
| -------------- | ----------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message         |
| ------- | ----------------- |
| 7600206 | Invalid argument. Possible causes: <br>1. Namespace is not registered. <br>2. The path syntax is invalid. <br>3. The path does not match the type. <br>4. The value is invalid for the type. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function SetValue() {
  try {
    let xmpMetadata = new image.XMPMetadata();
    // Set the value of the xmp:title tag. The value is a string and is set to 'My Title'.
    // xmp is a built-in namespace and can be used without registration.
    await xmpMetadata.setValue(`${image.XMP_BASIC.prefix}:title`, image.XMPTagType.STRING, 'My Title');
    console.info('Succeeded in setting XMP tag value.');
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`Failed to set XMP tag value! code is ${err.code}, message is ${err.message}`);
  }
}
```

## getTag

getTag(path: string): Promise\<XMPTag | null>

Obtains a single XMP tag at the specified path. This API uses a promise to return the result.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type   | Mandatory| Description        |
| ------ | ------ | ---- | ------------ |
| path   | string | Yes  | Path of the target XMP tag. For details about the path syntax, see [XMP Path Syntax](#xmp-path-syntax).|

**Return value**

| Type                                                    | Description                                                    |
| -------------------------------------------------------- | ------------------------------------------------------- |
| Promise\<[XMPTag](arkts-apis-image-i.md#xmptag) \| null> | Promise used to return the XMP tag at the specified path. If the operation fails, **null** is returned.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message         |
| ------- | ----------------- |
| 7600206 | Invalid argument. Possible causes: <br>1. Namespace is not registered. <br>2. The path syntax is invalid. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function GetTag() {
  try {
    let xmpMetadata = new image.XMPMetadata();
    await xmpMetadata.setValue(`${image.XMP_BASIC.prefix}:title`, image.XMPTagType.STRING, 'My Title');
    // Obtain the tag at the XMP path xmp:title.
    let tag: image.XMPTag | null = await xmpMetadata.getTag(`${image.XMP_BASIC.prefix}:title`);
    console.info(`Succeeded in getting an XMP tag. ${image.XMP_BASIC.prefix}:title: ${tag?.value}.`);
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`Failed to get an XMP tag. Code: ${err.code}, message: ${err.message}.`);
  }
}
```

## removeTag

removeTag(path: string): Promise\<void>

Deletes the XMP tag at the specified path. This API uses a promise to return the result.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type   | Mandatory| Description        |
| ------ | ------ | ---- | ------------ |
| path   | string | Yes  | Path of the target XMP tag. For details about the path syntax, see [XMP Path Syntax](#xmp-path-syntax).|

**Return value**

| Type          | Description                    |
| -------------- | ----------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message         |
| ------- | ----------------- |
| 7600206 | Invalid argument. Possible causes: <br>1. Namespace is not registered. <br>2. The path syntax is invalid. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function RemoveTag() {
  try {
    let xmpMetadata = new image.XMPMetadata();
    await xmpMetadata.setValue(`${image.XMP_BASIC.prefix}:title`, image.XMPTagType.STRING, 'My Title');
    await xmpMetadata.removeTag(`${image.XMP_BASIC.prefix}:title`);
    // Obtain the tag to check whether it has been removed. If the node does not exist, null is returned.
    let tag: image.XMPTag | null = await xmpMetadata.getTag(`${image.XMP_BASIC.prefix}:title`);
    console.info(`Succeeded in removing an XMP tag. ${image.XMP_BASIC.prefix}:title exists after remove: ${tag !== null}.`);
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`Failed to remove an XMP tag. Code: ${err.code}, message: ${err.message}.`);
  }
}
```

## enumerateTags

enumerateTags(callback: (path: string, tag: XMPTag) => boolean, rootPath?: string, options?: XMPEnumerateOptions): void

Enumerates all XMP tags under the specified path.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                                                                   | Mandatory| Description                              |
| -------- | ---------------------------------------------------------------------- | ---- | --------------------------------- |
| callback | (path: string, tag: [XMPTag](arkts-apis-image-i.md#xmptag)) => boolean | Yes  | Synchronous callback used to return the result.<br>A return value of **true** indicates that traversal continues, while **false** indicates that traversal stops.<br>The **path** parameter is the unique path identifier of a tag, following the [XMP path syntax](#xmp-path-syntax). The **tag** parameter is the data representation of the corresponding tag.             |
| rootPath | string                                                                 | No  | Start node for traversal. By default, traversal starts from the root node. For details about the path syntax, see [XMP Path Syntax](#xmp-path-syntax).|
| options  | [XMPEnumerateOptions](arkts-apis-image-i.md#xmpenumerateoptions)         | No  | Traversal options.<br>Default behavior: Only direct child nodes are traversed, and both normal nodes and qualifiers are returned.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message         |
| ------- | ----------------- |
| 7600206 | Invalid argument. Possible causes: <br>1. Namespace is not registered. <br>2. The rootPath syntax is invalid. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function EnumerateTags(imageSourceObj: image.ImageSource) {
  // Read metadata of the XMP type.
  let types: image.MetadataType[] = [image.MetadataType.XMP_METADATA];
  await imageSourceObj.readImageMetadataByType(types).then((metaData: image.ImageMetadata) => {
    if (metaData != undefined && metaData.xmpMetadata != undefined) {
      try {
        // Obtain all XMP tags recursively, including both normal nodes and qualifiers.
        metaData.xmpMetadata.enumerateTags((path: string, tag: image.XMPTag): boolean => {
          // Print the tag path, name, and value.
          console.info(`Succeeded in enumerating an XMP tag. Path: ${path}, name: ${tag.name}, value: ${tag.value}.`);
          return true;  // Return true to continue the traversal.
        }, undefined, { isRecursive: true, onlyQualifier: false });
      } catch (error) {
        let err: BusinessError = error as BusinessError;
        console.error(`Failed to enumerate XMP tags. Code: ${err.code}, message: ${err.message}.`);
      }
    }
  }).catch((error: BusinessError) => {
    console.error(`Failed to read image metadata by type. Code: ${error.code}, message: ${error.message}.`);
  })
}
```

## getTags

getTags(rootPath?: string, options?: XMPEnumerateOptions): Promise\<Record\<string, XMPTag>>

Obtains the XMP tags and their subtags under the specified path. This API uses a promise to return the result.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                                                           | Mandatory| Description                          |
| -------- | -------------------------------------------------------------- | ---- | ----------------------------- |
| rootPath | string                                                         | No  | Start node for traversal. By default, traversal starts from the root node. For details about the path syntax, see [XMP Path Syntax](#xmp-path-syntax).|
| options  | [XMPEnumerateOptions](arkts-apis-image-i.md#xmpenumerateoptions) | No  | Traversal options.<br>Default behavior: Only direct child nodes are traversed, and both normal nodes and qualifiers are returned.|

**Return value**

| Type          | Description                    |
| -------------- | ----------------------- |
| Promise\<Record\<string, [XMPTag](arkts-apis-image-i.md#xmptag)>> | Promise used to return the XMP tag set.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message         |
| ------- | ----------------- |
| 7600206 | Invalid argument. Possible causes: <br>1. Namespace is not registered. <br>2. The rootPath syntax is invalid. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function GetTags(imageSourceObj: image.ImageSource) {
  // Read metadata of the XMP type.
  let types: image.MetadataType[] = [image.MetadataType.XMP_METADATA];
  await imageSourceObj.readImageMetadataByType(types).then(async (metaData: image.ImageMetadata) => {
    if (metaData != undefined && metaData.xmpMetadata != undefined) {
      try {
        // Obtain all XMP tags recursively, including both normal nodes and qualifiers.
        let tags: Record<string, image.XMPTag> =
          await metaData.xmpMetadata.getTags(undefined, { isRecursive: true, onlyQualifier: false });
        console.info(`Succeeded in getting XMP tags. Count: ${Object.keys(tags).length}, data: ${JSON.stringify(tags)}.`);
      } catch (error) {
        let err: BusinessError = error as BusinessError;
        console.error(`Failed to get XMP tags. Code: ${err.code}, message: ${err.message}.`);
      }
    }
  }).catch((error: BusinessError) => {
    console.error(`Failed to read image metadata by type. Code: ${error.code}, message: ${error.message}.`);
  })
}
```

## getBlob

getBlob(): Promise\<ArrayBuffer>

Obtains the XMP metadata as binary data. This API uses a promise to return the result.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Image.Core

**Return value**

| Type                 | Description                                  |
| --------------------- | ------------------------------------- |
| Promise\<ArrayBuffer> | Promise used to return the binary data of the XMP metadata.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message         |
| ------- | ----------------- |
| 7600301 | Memory alloc failed. |
| 7600302 | Memory copy failed.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function GetBlob(imageSourceObj: image.ImageSource) {
  // Read metadata of the XMP type.
  let types: image.MetadataType[] = [image.MetadataType.XMP_METADATA];
  await imageSourceObj.readImageMetadataByType(types).then(async (metaData: image.ImageMetadata) => {
    if (metaData != undefined && metaData.xmpMetadata != undefined) {
      try {
        let blob: ArrayBuffer = await metaData.xmpMetadata.getBlob();
        console.info(`Succeeded in getting an XMP blob. Length: ${blob.byteLength}.`);
      } catch (error) {
        let err: BusinessError = error as BusinessError;
        console.error(`Failed to get an XMP blob. Code: ${err.code}, message: ${err.message}.`);
      }
    }
  }).catch((error: BusinessError) => {
    console.error(`Failed to read image metadata by type. Code: ${error.code}, message: ${error.message}.`);
  })
}
```

## setBlob

setBlob(buffer: ArrayBuffer): Promise\<void>

Replaces the current XMP metadata with binary data. This API uses a promise to return the result.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type        | Mandatory| Description               |
| ------ | ----------- | ---- | ------------------ |
| buffer | ArrayBuffer | Yes  | Binary data used to replace the XMP metadata.|

**Return value**

| Type          | Description                    |
| -------------- | ----------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message         |
| ------- | ----------------- |
| 7600206 | Invalid argument. Possible causes: <br>1. The buffer is empty or invalid. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function SetBlob(imageSourceObj: image.ImageSource) {
  // Read metadata of the XMP type.
  let types: image.MetadataType[] = [image.MetadataType.XMP_METADATA];
  await imageSourceObj.readImageMetadataByType(types).then(async (metaData: image.ImageMetadata) => {
    if (metaData != undefined && metaData.xmpMetadata != undefined) {
      try {
        let blob: ArrayBuffer = await metaData.xmpMetadata.getBlob();
        // Fill back with raw binary data to verify the availability of the setBlob API.
        await metaData.xmpMetadata.setBlob(blob);
        let newBlob: ArrayBuffer = await metaData.xmpMetadata.getBlob();
        console.info(`Succeeded in setting an XMP blob. New length: ${newBlob.byteLength}.`);
      } catch (error) {
        let err: BusinessError = error as BusinessError;
        console.error(`Failed to set an XMP blob. Code: ${err.code}, message: ${err.message}.`);
      }
    }
  }).catch((error: BusinessError) => {
    console.error(`Failed to read image metadata by type. Code: ${error.code}, message: ${error.message}.`);
  })
}
```
