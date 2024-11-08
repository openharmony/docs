# 标准化数据定义概述

设备、应用交互的核心在于数据的互通，高效的数据互通基础是共识。为了降低应用/业务数据交互成本，促进数据生态建设，统一数据管理框架（UDMF）提供了标准化数据定义作为统一的OpenHarmony数据语言，用于构建跨应用、跨设备的统一数据标准与交互共识。

UDMF标准化数据定义包括[标准化数据类型](uniform-data-type-descriptors.md)和[标准化数据结构](uniform-data-structure.md)。

**标准化数据类型**：主要针对同一种数据类型，提供统一定义，即标准数据类型描述符，定义了包括标识数据类型的ID、类型归属关系等相关信息，用于解决OpenHarmony系统中的类型模糊问题。一般用于过滤或者识别某一种数据类型的场景，比如文件预览、文件分享等。

**标准化数据结构**：主要针对部分标准化数据类型定义了统一的数据内容结构，并明确了对应的描述信息。应用间使用标准化数据结构进行数据交互后，将遵从统一的解析标准，可有效减少适配相关的工作量。一般用于跨应用跨设备间的数据交互，比如拖拽。

## 相关实例

针对标准化数据定义的开发，有以下相关实例可供参考：

- [标准化数据定义与描述（ArkTS）（API11）](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-5.0.0-Release/code/BasicFeature/DataManagement/UDMF/UniformTypeDescriptor/UTDType)