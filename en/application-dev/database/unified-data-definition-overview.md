# Unified Data Definition Overview

Efficient data interaction is critical for interaction between devices and applications. The Unified Data Management Framework (UDMF) provides unified data definitions for different applications and devices to reduce the costs in application and service data interaction.

The unified data definitions include [uniform data types](uniform-data-type-descriptors.md) and [uniform data structs](uniform-data-structure.md).

Uniform data type: defines the data of the same type via the Uniform Type Descriptor (UTD) to eliminate data type ambiguity. The UTD defines information, such as the data type ID and types to which the current data type belongs. The uniform data type is generally used to filter or identify the data type in scenarios, such as file preview and file sharing.

Uniform data struct: struct of a specific uniform data type. The use of uniform data structs enables unified parsing standards to be used in data interaction, which minimizes the adaptation workload. Uniform data structs are used for data interaction across applications and devices, such as, the drag-and-drop operations.

