# Unified Data Definition Overview

Efficient data interaction is critical for interaction between devices and applications. The Unified Data Management Framework (UDMF) provides unified data definitions for different applications and devices to reduce the costs in application and service data interaction.

The unified data definitions include [uniform type descriptors (UTDs)](uniform-data-type-descriptors.md) and [uniform data structs](uniform-data-structure.md).

- UTD<br>A UTD is used to define data of the same type to eliminate data type ambiguity. It contains information, such as the data type ID and types to which the current data type belongs. UTDs are generally used to filter or identify the data type in file preview and file sharing.


- Uniform data struct<br>A uniform data struct defines the data of a UTD. Uniform data structs allow unified parsing standards to be used in data interaction, which minimizes the adaptation workload. Uniform data structs are used for data interaction across applications and devices, such as, the drag-and-drop operations.