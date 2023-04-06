# OpenHarmony Part Design Guide

## About This Document

For easy software design and management, OpenHarmony decouples software from physical components, parts, and modules. A **component** can be independently deployed and reused at the binary level. A **part** can be independently developed, built, and tested. A **module** can be reused at the code level.

OpenHarmony abstracts system capabilities as parts, so you can assemble and configure these parts to customize an OS for different devices.

## Part Definition

A part is the basic unit of system capabilities. Divided based on source code, every part has independent files and directories, and can be instantiated into libraries or executable files on different devices.

## Part Division

Observe the following rules for part classification:

- A part must have an independent code directory for compiling libraries or executable files.

- A part must be able to be independently deployed in the small system or standard system. Optional parts can be tailored without causing system exceptions.

- Functions of a part must be able to be independently tested and verified.

A part always belongs to a specific subsystem. A subsystem is a logical concept and consists of specific parts.

Note the following:

- External APIs provided by a part must be the same regardless of whether the configurable features of the part are configured.

- Dependent third-party open source software libraries and parts that provide basic capabilities are called **dependent parts**, which must be deployed with other parts.

- If a part can be split into smaller functional modules and provide APIs for applications, these modules are called **child parts**, which must be deployed with the parent part. A child part depends on a parent part, but a parent part does not depend on a child part.

## Basic Principles

Comply with the following rules and recommendations during parts design and development:

**Rule 1.1** Parts must be developed individually to ensure decoupling and independence.

**Rule 1.2** Parts must be managed in a decentralized manner. The dependency between parts must be simple, clear, and reasonable.

**Rule 1.3** Reverse dependency and cyclic dependency between parts are prohibited. Lower-layer parts must not depend on upper-layer parts.

**Rule 1.4** It is prohibited that the implementation of a part depends on a specific development board or product form.

**Rule 1.5** APIs provided by a part must be stable and compatible. Changes to released APIs are prohibited.

**Rec 1.1** Parts should support automated build and verification.

## Naming Rules

#### **Part Name**

The name must reflect the key function of a part and must be globally unique in the system. It can contain a maximum of 63 characters and must be in the unix\_like style, where only lowercase letters separated by underscores (\_) are used.

#### **Repository Name**

The part repository is named in the format of <Subsystem\>\_<Part\>. For example, the repository name of the storage service part in the file management subsystem is **filemanagement\_storage\_service**. The repository name can contain a maximum of 100 characters.

> Note:
>
> 1. In principle, there is a one-to-one mapping between parts and repositories. In some cases, multiple parts can share a repository, but they must have independent directories.
>
> 2. For a third-party open source part, use the original name with the prefix **third\_party**. All third-party open source parts are stored in the **third\_party** directory.
>
> 3. The subsystem names in the repository name and path should not contain underscores (\_).

#### **Path**

The part name must be in the format of <Domain\>/<Subsystem\>/<Part\>, for example, **foundation/filemanagement/storage_service**.

#### **Part Directory Structure**

```xml
├── interfaces          # APIs
│   ├── kits			# Application APIs (optional)
│   │    ├── js			# JS APIs (optional)
│   │    └── native  	# C/C++ APIs (optional)
│   └── inner_api       # Internal APIs of parts
├── frameworks          # Implementation of the part without independent processes (optional)
│   ├── native          # C/C++ API implementation (optional)
│   └── js              # JS API implementation (optional)
│        ├── napi       # Native API implementation (optional)
│        ├── builtin	# Specific to LiteOS-M (optional)
│        └── plugin     # Specific to ArkUI (optional)
├── services            # Implementation of parts with independent processes (optional)
├── test                # Test code (mandatory)
├── BUILD.gn            # Entry to build (mandatory)
└── bundle.json         # Part description file (mandatory)
```

## Adding, Deleting, or Modifying Parts

The addition, deletion, and modification of parts must be reviewed by the architecture SIG and [related domain SIGs](https://gitee.com/openharmony/community/blob/master/sig/sigs_subsystem_list.md). The review process is as follows:

1. Prepare the following part attribute review form.

Table 1 Part attribute review form

| Part Attribute | Description |
| ------------ | ------------------------------------------------------------ |
| Part name | The name must reflect the key function of a part and must be globally unique in the system. The name can contain a maximum of 63 characters and must be in the unix\_like style, where only lowercase letters separated by underscores (\_) are used. |
| Subsystem | Subsystem to which the part belongs. |
| Function description | Brief description of the functions of the part in one or two sentences. |
| Configurable features | Features that can be configured externally. |
| Applicable systems | Mini system, small system, standard system, or their combinations. |
| Source code directory | Root directory of the source code of the part. |
| ROM          | ROM baseline value of the part. |
| RAM          | RAM baseline value of the part. |
| Dependencies | Parts and open source software on which the part depends. |


2. Send an email to the architecture SIG (dev@openharmony.io) and the [related domain SIG leaders](https://gitee.com/openharmony/community/blob/master/sig/sigs_subsystem_list.md) for review. Use "Application for Adding/Deleting/Modifying OpenHarmony Parts" as the email subject, and include the filled-in **Table 1 Part Attribute Review Form** in the email body.

> Note: 
>
> For modified parts, provide a before and after comparison of the part attributes. For deleted parts, provide the plan for stopping part maintenance. Exercise caution when deleting or modifying parts and evaluate the impact on existing versions.

3. After the review is passed, create a part repository and modify the manifest according to [SIG Management Regulations](https://gitee.com/openharmony/community/blob/master/sig/README-EN.md). After the SIG is incubated, incorporate it into the main code library of OpenHarmony.
