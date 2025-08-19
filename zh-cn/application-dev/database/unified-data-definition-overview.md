# 标准化数据定义概述
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @jcwen-->
<!--Designer: @junathuawei1; @zph000-->
<!--Tester: @lj_liujing; @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

设备、应用交互的核心在于数据的互通，高效的数据互通基础是共识。为了降低应用/业务数据交互成本，促进数据生态建设，统一数据管理框架（UDMF）提供了标准化数据定义作为统一的OpenHarmony数据语言，用于构建跨应用、跨设备的统一数据标准与交互共识。

UDMF标准化数据定义包括[标准化数据类型](uniform-data-type-descriptors.md)和[标准化数据结构](uniform-data-structure.md)。

## 基本概念

### 标准化数据类型

主要针对同一种数据类型，提供统一定义，即标准数据类型描述符，定义了包括标识数据类型的ID、类型归属关系等相关信息，用于解决OpenHarmony系统中的类型模糊问题。一般用于过滤或者识别某一种数据类型的场景，比如文件预览、文件分享等。

### 标准化数据结构

主要针对部分标准化数据类型定义了统一的数据内容结构，并明确了对应的描述信息。应用间使用标准化数据结构进行数据交互后，将遵从统一的解析标准，可有效减少适配相关的工作量。一般用于跨应用跨设备间的数据交互，比如拖拽。

### 多样式数据

在设备、应用交互过程中，一次交互会存在多条记录，每条记录可能存在不同的表达形式（我们称这种表达形式为样式），因此提出了多样式数据概念。在交互过程中，数据提供方提供记录的不同数据样式，数据使用方获取到数据后，根据业务需要从记录中获取样式数据。

![multi-entry-structure](figures/multi-entry-structrue.PNG)

在上图中，不同的UnifiedRecord表示不同的记录，不同记录之间承载的内容是不一致的；在同一个UnifiedRecord中，同一内容以不同的样式存储，丰富了数据的表现形式。

## 相关实例

针对标准化数据定义的开发，有以下相关实例可供参考：

- [标准化数据定义与描述（ArkTS）（API11）](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DataManagement/UDMF/UniformTypeDescriptor/UTDType)