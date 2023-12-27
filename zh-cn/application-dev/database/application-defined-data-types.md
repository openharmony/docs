# 应用自定义数据类型


## 场景介绍

由于预先定义的UTD标准数据类型无法穷举所有的数据类型，在业务跨应用、跨设备交互过程中，会涉及到非预定义的数据类型。为了解决该问题，
UTD支持业务声明自定义类型描述符，例如业务自定义的图片类型可以使用“com.company.x-image”作为UTD标识符。

自定义类型标识符与标准数据类型描述符为互补关系，业务可以将自定义类型标识符注册到系统中，这样其他业务在需要使用时可以引用，进而实现
鸿蒙生态内自定义数据类型的共享与统一。

## 自定义数据类型工作原理

同时，基于标准类型的层级结构，业务声明自己支持的数据类型标识符时，需要声明该类型标识符的层级逻辑，例如业务自定义图片类型UTD标识符
com.company.x-image，并归属到general.image类中。UTD框架会检验自定义类型标识符，确保归属关系中不出现环状结构。

应用安装时，UTD会读取应用中自定义的数据类型进行安装，校验自定义类型数据符合约束条件后，应用自定义数据类型将被安装到设备中。应用启动
后能正常读取到应用自定义数据类型。如果引用其他应用定义的自定义数据类型，需要在应用开发时一并写入自定义数据类型配置文件中。

## 约束限制
+ **typeId：** 定义标准化数据类型的ID，该ID具有唯一性，由应用bundleName + 具体类型名组成，不可缺省，允许包含数字、大小写字母、-和.。

+ **belongingToTypes：** 定义标准化数据类型的归属关系，即该标准化数据类型归属于哪个更高层级的类型，所属类型可以为多个，但是必须为已存在的数据
类型（标准化数据类型预置类型或其他新增自定义数据类型），不能为应用自定义类型本身，不能为空，且与现有标准化数据类型、其他新增自定义数据类型不能形成
环行依赖，不可缺省。

+ **FilenameExtensions：** 应用自定义标准化数据类型所关联的文件后缀，可以为多个，每个后缀为以.开头且长度不超过127的字符串，可以缺省。

+ **mimeTypes：** 应用自定义标准化数据类型所关联的web消息数据类型，可以为多个，每个类型为长度不超过127的字符串，可以缺省。

+ **description：** 应用自定义标准化数据类型的简要说明，长度不超过255的字符串，可以缺省。

+ **referenceURL：** 应用自定义标准化数据类型的参考链接URL，用于描述类型的详细信息，长度不超过255的字符串类型，可以缺省。


## 开发步骤

下面以新增媒体类文件类型场景为例，说明如何自定义UTD标准化数据类型。

1. 在entry\src\main\resources\rawfile\arkdata\utd\目录下新增utd_adt.json。
2. 第一个应用在配置文件内新增所需的自定义数据类型。
   ```json
    "UniformDataTypeDeclarations": [
        {
            "typeId": "com.example.myFirstHap.image",
            "belongingToTypes": ["general.image"],
            "FilenameExtensions": [".myImage", ".khImage"],
            "mimeTypes": ["application/myImage", "application/khImage"],
            "description": "My Image.",
            "referenceURL": ""
        },
        {
            "typeId": "com.example.myFirstHap.audio",
            "belongingToTypes": ["general.audio"],
            "FilenameExtensions": [".myAudio", ".khAudio"],
            "mimeTypes": ["application/myAudio", "application/khAudio"],
            "description": "My audio.",
            "referenceURL": ""
        },
        {
            "typeId": "com.example.myFirstHap.video",
            "belongingToTypes": ["general.video"],
            "FilenameExtensions": [".myVideo", ".khVideo"],
            "mimeTypes": ["application/myVideo", "application/khVideo"],
            "description": "My video.",
            "referenceURL": ""
        }
    ]
   ```
3. 如果第二个应用要使用第一个应用内自定义数据类型，需要在配置文件utd_adt.json中进行声明。
   ```json
    "UniformDataTypeDeclarations": [
        {
            "typeId": "com.example.mySecondHap.image",
            "belongingToTypes": ["com.example.myFirstHap.image"],
            "FilenameExtensions": [".myImageEx", ".khImageEx"],
            "mimeTypes": ["application/my-ImageEx", "application/khImageEx"],
            "description": "My Image extension.",
            "referenceURL": ""
        }
    ],
    "ReferenceUniformDataTypeDeclarations": [
        {
            "typeId": "com.example.myFirstHap.image",
            "belongingToTypes": ["general.image"],
            "FilenameExtensions": [".myImage", ".khImage"],
            "mimeTypes": ["application/myImage", "application/khImage"],
            "description": "My Image.",
            "referenceURL": ""
        }
    ]
   ```
4. 应用自定义类型使用，参考[标准化数据定义与描述中的开发步骤](uniform-type-descriptors.md#开发步骤)。

