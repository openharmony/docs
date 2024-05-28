# Uniform Data Types


## When to Use

The Uniform Type Descriptor (UTD) module resolves data type ambiguity in the system, that is, the same data type described in different ways, such as the MIME type and file name extension. For example, the JPG/JPEG image can be represented by image/jpeg, .jpg, .jpeg, or image/picture.

When data of these types is transmitted across applications or devices, the target application or device may fail to identify the data or can process the data after lots of adaptation.

The uniform data types can be classified into [predefined uniform data types](#predefined-uniform-data-types) and [custom uniform data types](#custom-uniform-data-types). In addition, conversion between uniform data types are supported. For example, the file name extension and MIME type can be converted into uniform data types.

Uniform data types can be used in image preview and file sharing.

## Design and Classification Principles

### Hierarchical Structure

Defining data types by MIME type or file name extension may cause loose data type definitions, which

cannot describe the compatibility and inheritance relationships between different types and further increase development complexity in data type processing. For example, in a scenario where a user searches for any type of animal images, loose data type definitions may involve search of any image, video, or audio assets related to animals. To address this problem, we need to define uniform data types in a hierarchical structure.

The data type hierarchies identify the relationship between different data types and the hierarchy they belong to. It helps to organize data in a way that makes it easier to understand, manage, and analyze. For example, when the data to be shared or dragged includes images, videos, and audio clips, the system or application can sort the data by the data type hierarchy, for example, to share or drag photos, videos, or media files as required.

### Classification Principles of Uniform Data Types

The uniform data types can be classified by physical attribute or logic. For details, see [UniformDataType](../reference/apis-arkdata/js-apis-data-uniformTypeDescriptor.md#uniformdatatype).

- For the uniform data types classified by physical attribute, the root node is **general.entity**, which describe the physical attributes of that type, such as file and directory, as shown in **Figure 1**.

- For the uniform data types classified by logic, the root node is **general.object**, which describe the features of that type, such as image and web page, as shown in **Figure 2**.

According to this classification principle, data types can be described from two dimensions. For example, an image can be an image object or a file.

However, not all data formats have two dimensions. For example, **general.calendar** focuses more on the functional description of the calendar object.

**Figure 1** Uniform data type based on physical attributes

![utd_preset_type](figures/utd_preset_type.png)

**Figure 2** Uniform data type based on logical function

![utd_type](figures/utd_type.png)

## Uniform Type Descriptor

A Uniform Type Descriptor (UTD) consists of the following fields:

+ **TypeId**: unique ID of the data type.
+ **BelongingToTypes**: types to which the data type belongs. A data type can belong to multiple types.
+ **Description**: brief description of the data type.
+ **ReferenceURL**: URL of the data type reference, which provides detailed information about the data type.
+ **IconFile**: path of the default icon file for the data type. If the data type has no default icon, it is an empty string. The application can determine whether to use the default icon.

## Predefined Uniform Data Types

The system provides some uniform data types based on common data types, such as **general.audio** for audio files and **general.video** for video files. For details, see [UniformDataType](../reference/apis-arkdata/js-apis-data-uniformTypeDescriptor.md#uniformdatatype).


## Custom Uniform Data Types
You can also customize uniform data types for your application.

Custom uniform data types can inherit existing uniform data types. For example, a custom image type can use **com.company.x-image** as its identifier.

The custom uniform data types of a service can be used by other services after being registered with the system.

### Working Principles

When the custom uniform data types supported by a service are declared, the declaration must contain the hierarchical logic of each data type. For example, the custom UTD **com.company.x-image**, belonging to the **general.image** class. The custom uniform data types are verified to prevent the ring structure between them.

When an application is installed, the custom uniform data types are read and verified. If the verification is successful, the custom uniform data types will be installed on the device. After the application starts, the
custom uniform data types can be read. The custom uniform data types of other applications to be used must also be added to the custom uniform data type configuration file of your application during development.

### Constraints

The fields of a custom UTD must comply with the following requirements:

+ **TypeId**: ID of the custom uniform data type to define. The value must be unique and consist of the application bundle name and data type name. It cannot be left blank. The value can contain digits, uppercase and lowercase letters, hyphens (-), and periods (.).

+ **BelongingToTypes**: types to which this data type belongs. Multiple types are allowed, but the types specified must be existing
  predefined or custom uniform data types. The value cannot be empty or the custom uniform data type itself, or form a ring dependency structure with the existing uniform data types or newly added custom uniform data types.

+ **FilenameExtensions**: file name extensions associated with the custom uniform data type. It can be left blank. One or more file name extensions are allowed. Each file name extension starts with a period (.) and cannot exceed 127 characters.

+ **MIMETypes**: web message data types associated with the custom uniform data type. It can be left blank. One or more MIME types are allowed. Each MIME type cannot exceed 127 characters.

+ **Description**: description of the custom uniform data type. The value cannot exceed 255 characters. It can be left blank.

+ **ReferenceURL**: URL of the data type reference, which provides detailed information about the data type. The value cannot exceed 255 characters. It can be left blank.


### How to Develop

The following walks you through on who to define a custom uniform data type for media files.

1. Create the **utd.json5** file in the **entry\src\main\resources\rawfile\arkdata\utd\** directory of your application, for example, application A.

2. Add a custom uniform data type in the **utd.json5** file.
   ```json
   {
        "UniformDataTypeDeclarations": [
            {
                "TypeId": "com.example.myFirstHap.image",
                "BelongingToTypes": ["general.image"],
                "FilenameExtensions": [".myImage", ".khImage"],
                "MIMETypes": ["application/myImage", "application/khImage"],
                "Description": "My Image.",
                "ReferenceURL": ""
            },
            {
                "TypeId": "com.example.myFirstHap.audio",
                "BelongingToTypes": ["general.audio"],
                "FilenameExtensions": [".myAudio", ".khAudio"],
                "MIMETypes": ["application/myAudio", "application/khAudio"],
                "Description": "My audio.",
                "ReferenceURL": ""
            },
            {
                "TypeId": "com.example.myFirstHap.video",
                "BelongingToTypes": ["general.video"],
                "FilenameExtensions": [".myVideo", ".khVideo"],
                "MIMETypes": ["application/myVideo", "application/khVideo"],
                "Description": "My video.",
                "ReferenceURL": ""
            }
        ]
   }
   ```

3. To enable another application, for example, application B, to use the custom uniform data type of this application, create the **utd.json5** file in the **entry\src\main\resources\rawfile\arkdata\utd\** directory of application B.

   Then, add the following to the **utd.json5** file of application B:

   ```json
   {
       "ReferenceUniformDataTypeDeclarations": [
            {
                "TypeId": "com.example.myFirstHap.image",
                "BelongingToTypes": ["general.image"],
                "FilenameExtensions": [".myImage", ".khImage"],
                "MIMETypes": ["application/myImage", "application/khImage"],
                "Description": "My Image.",
                "ReferenceURL": ""
            }
       ]
   }
   ```

4. You can also create the **utd.json5** template for other applications in DevEco Studio, reference the custom data types of the current application in the template, and customize the data types as required. DevEco Studio verifies the formats of the fields in the **utd.json5** file. The following is an example of the **utd.json5** file.

   ```json
   {
       "UniformDataTypeDeclarations": [
           {
               "TypeId": "com.example.mySecondHap.image",
               "BelongingToTypes": ["com.example.myFirstHap.image"],
               "FilenameExtensions": [".myImageEx", ".khImageEx"],
               "MIMETypes": ["application/my-ImageEx", "application/khImageEx"],
               "Description": "My Image extension.",
               "ReferenceURL": ""
           }
       ]
   }
   ```

## Available APIs

The following table describes the commonly used APIs, which are applicable to both predefined and custom uniform data types. For more information, see [@ohos.data.uniformTypeDescriptor](../reference/apis-arkdata/js-apis-data-uniformTypeDescriptor.md).

| API                                                    | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| UniformDataType                                              | Enumerates the uniform data types. The enums are not provided here.|
| belongsTo(type: string): boolean                             | Checks whether this data type belongs to the specified data type.      |
| isLowerLevelType(type: string): boolean                      | Checks whether this data type is a lower-level type of the specified data type.|
| isHigherLevelType(type: string): boolean                     | Checks whether this data type is a higher-level type of the specified data type.|
| getUniformDataTypeByFilenameExtension(filenameExtension: string, belongsTo?: string): string | Obtains the uniform data type ID based on the given file name extension and data type.|
| getUniformDataTypeByMIMEType(mimeType: string, belongsTo?: string): string | Obtains the uniform data type ID based on the given MIME type and data type.|

## How to Develop

The following walks you through on how to use the APIs.

1. Import the **@ohos.data.uniformTypeDescriptor** module.
2. Obtain the uniform data type based on the file name extension .mp3, and then obtain attributes of the uniform data type.
3. Obtain the uniform data type based on **audio/mp3**, and then obtain attributes of the uniform data type.
4. Compare the data types obtained in the preceding steps to check whether they are the same.
5. Check the relationship between the **general.mp3** type obtained and the existing type **general.audio**.

```ts
// 1. Import the module.
import uniformTypeDescriptor from '@ohos.data.uniformTypeDescriptor';

try {
  // 2. Obtain the uniform data type based on the file name extension .mp3, and then obtain attributes of the uniform data type.
  let fileExtention = '.mp3';
  let typeId1 = uniformTypeDescriptor.getUniformDataTypeByFilenameExtension(fileExtention);
  let typeObj1 = uniformTypeDescriptor.getTypeDescriptor(typeId1);
  console.info('typeId:' + typeObj1.typeId);
  console.info('belongingToTypes:' + typeObj1.belongingToTypes);
  console.info('description:' + typeObj1.description);
  console.info('referenceURL:' + typeObj1.referenceURL);

  // 3. Obtain the uniform data type based on **audio/mp3**, and then obtain attributes of the uniform data type.
  let mineType = 'audio/mp3';
  let typeId2 = uniformTypeDescriptor.getUniformDataTypeByMIMEType(mineType);
  let typeObj2 = uniformTypeDescriptor.getTypeDescriptor(typeId2);
  console.info('typeId:' + typeObj2.typeId);
  console.info('belongingToTypes:' + typeObj2.belongingToTypes);
  console.info('description:' + typeObj2.description);
  console.info('referenceURL:' + typeObj2.referenceURL);

  // 4. Compare the data types to check whether they are the same.
  if (typeObj1 != null && typeObj2 != null) {
    let ret = typeObj1.equals(typeObj2);
    console.info('typeObj1 equals typeObj2, ret:' + ret);
  }

  // 5. Check the relationship between **general.mp3** and **general.audio**.
  if (typeObj1 != null) {
    let ret = typeObj1.belongsTo('general.audio');
    console.info('belongsTo, ret:' + ret);
    let mediaTypeObj = uniformTypeDescriptor.getTypeDescriptor('general.media');
    ret = mediaTypeObj.isHigherLevelType('general.audio'); // Check the relationship between them.
    console.info('isHigherLevelType, ret:' + ret);
  }
} catch (err) {
  console.error('err message:' + err.message + ', err code:' + err.code);
}
```

