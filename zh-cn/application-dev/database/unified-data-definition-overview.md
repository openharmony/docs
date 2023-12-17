# 标准化数据定义概述


## 场景介绍

设备、应用交互的核心在于数据的互通，高效的数据互通基础是共识。为了降低应用/业务数据交互成本，促进数据生态建设，统一数据管理框架提供了
标准化的数据定义作为统一的OpenHarmony数据语言，用于构建跨应用、跨设备的统一数据标准与交互共识。应用可以使用UDMF提供的接口创建和使用这些标准化数据类型。

## 功能介绍

标准化数据定义的具体实现包含如下内容：

- [标准化数据定义与描述](uniform-type-descriptors.md)

  标准化数据定义与描述（Uniform Type Descriptor，简称UTD）基于数据类型是否为常用类型，预先定义了一部分标准数据类型描述符作为
  OpenHarmony的数据类型标准，例如使用‘general.jpeg’作为JPEG图片类型在OpenHarmony系统中的标准描述符，对应的图片文件后缀为‘.jpg’或
  ‘.jpeg’，对应的MIME为‘image/jpeg’。UTD提供了对数据类型的描述信息（如简要说明和默认图标文件路径）并且支持从其他类型体系
  （如文件名后缀和MIME type）转换为UTD标准类型，从而统一了OpenHarmony数据类型标准。

- [应用自定义数据类型](application-defined-data-types.md)

  由于预先定义的UTD标准数据类型无法穷举所有的数据类型，在业务跨应用、跨设备交互过程中，会涉及到非预定义的数据类型。为了解决该问题，
  UTD支持业务声明自定义类型描述符，例如业务自定义的图片类型可以使用“com.company.x-image”作为UTD标识符。

- [具体定义的标准化数据类型](specific-defined-data-types.md)

  针对一些UTD标准化数据类型，为了方便业务使用，我们提供了具体的定义，例如OpenHarmony系统定义的桌面卡片类型（对应的UTD标识符为'openharmony.form'），
  我们明确定义了该类型对应的描述对象以及对象的属性信息。
