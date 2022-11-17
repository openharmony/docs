# Introducing Third-Party Open-Source Software

## Purpose

In OpenHarmony, software that meets [The Open Source Definition](https://opensource.org/docs/osd) is recognized as open-source software.
Providing easy-to-use and quality open-source software for developers across the globe from a wide range of backgrounds is an important goal of the OpenHarmony community. To ensure the overall quality of the OpenHarmony project, this guide is specially formulated for the contributors' reference.

## Scope

This guide applies to all third-party open-source software to be introduced to the OpenHarmony project.

## Improvements and Revisions

1. This document is drafted and maintained by the OpenHarmony SIG QA. What you are reading now is the latest version of this document.

2. Any addition, modification, or deletion of the principles mentioned in this document can be traced in the tracing system.
3. The PMC reviews and finalizes the principles after thorough discussion in the community.

## Software Introduction and Introduction Principles

### What Is Software Introduction?

Software introduction refers to the act of introducing a piece of software to the OpenHarmony project to meet certain service requirements of a SIG in OpenHarmony. For details about the software introduction process, see [SIG Management Regulations](https://gitee.com/openharmony/community/tree/master/sig). The entire process must be traceable.

### Basic Principles for Software Introduction

For easier maintenance and evolution, comply with the following principles when introducing third-party open-source software:

1. Make sure the software comes from a clearly defined upstream community.
2. Provide a sound reason for software introduction. If the software to be introduced already exists in the OpenHarmony project, reuse it to avoid maintenance complexity caused by coexistence of multiple versions.
3. Introduce the software in the form of source code, rather than binary files. If a piece of software needs to be introduced in the form of binary files, the PMC should review the request and make a decision.
4. Make sure the software can be correctly built on the OpenHarmony project. If the software has dependency software that has not been introduced, or the running or build of the software depends on a component that cannot be introduced, the SIG-Architecture should review the request and make a decision.
5. Place the software in an independent code repository and name it in the format of **third_party**_**softwareName**, where *softwareName* must be an official name.
6. Retain the directory structure, license, and copyright information of the official code repository of the software. Do not modify the original license and copyright information.
7. Do not introduce any software version that has not been officially released, for example, the Beta version.
8. Do not introduce any software version that has high-risk vulnerabilities and does not provide solutions.
9. If you need to modify the software, place the new code in the software repository and ensure that the new code meets the license requirements of the software. Retain the original license for the modified files, and use the same license for the new files (recommended).
10. Provide the **README.OpenSource** file in the root directory of the software repository. Include the following information in the file: software name, license, license file location, version, upstream community address of the corresponding version, software maintenance owner, function description, and introduction reason.
11. Make sure the software you introduce is under the custody of a domain SIG. In principle, the SIG-Architecture will deny the introduction of a piece of software without the confirmation of the SIG-Compliance and the corresponding domain SIG. When introducing multiple pieces of software at a time, you can ask the PMC to hold a temporary review meeting between SIGs for faster introduction. If you want to introduce a piece of software but fail to meet the preceding requirements, send an email to oh-legal@openatom.io.
12. When software introduction depends on other dependency software, it is not allowed to nest the dependency software in the subdirectory of the software introduction, and all dependency software must be placed in separate repository, and name it in the format of **third_party_*****softwareName***, because nested placement of dependency software may lead to multiple versions of the same software, old versions of security vulnerabilities cannot be fixed in a timely, and will risk the open-source compliance issues.
    - Dependency software is named in the compiled **BUILD.gn** with part name by prefixing the new software introduction name, e.g. part_name = "software_introduction_name_dependency software_name".
    - The inter-component dependencies between software introduction and dependency software are resolved via external_deps.
13. OpenHarmony's archiving directory requirements for third-party software introduction.
    - If you don't have a really good reason to store it elsewhere and under one of the permitted licenses belongs in third_party.
    - For the dedicated third-party software introduction which belongs to the special devboard, and is not suitable introduced into the OpenHarmony platform, you could apply to store it in the following locations, Naming it in the format of **softwareName**, where **softwareName** must be an official name, and create the **README.OpenSource** description file in the corresponding directory; Creating **BUILD.gn** to build it independently to support the automatic collection of open source obligation declaration.

      ```
       device/soc/$(SOC_COMPANY)/third_party
       device/board/$(BOARD_COMPANY)/third_party
       vendor/$(PRODUCT_COMPANY)/third_party
      ```

14. Precompiled binary or toolchain used in the OpenHarmony, the following information needs to be provided.
    - The source code corresponding to the precompiled binary or toolchain, which needs to store the corresponding source code in the OpenHarmony community, and provide the corresponding build guide, and provide open source obligation statement guide;
    - Third-party software introduction for precompiled binary or toolchain, need to meet the principles 1 ~ 13;
    - The [prebuilt toolchain's description documentation](./prebuilts-readme-template.md): including source code acquisition address, build instructions, update methods, archived in the toolchain root directory with the toolchain build;
    - The root directory corresponding to the precompiled binary or toolchain needs to provide notice file of the full open source obligation statement;
    - If the precompiled binary files come from upstream service platform (e.g. npm packages, etc.). We need to provide the following information in the place where the binary is archived, first we need to provide a general description with the name **README**, include the following information: background description of the introduction and official website; next we need to provide an open-source obligation statement file with the name **NOTICE**, include the following information: software name, version, copyrights, and license information of every third-party open-source software.

### Software Introduction Process

#### Check Before Software Introduction

| Check Item| Description|
| :----- | :----- |
| Normalization| Check whether the software exists in the OpenHarmony community. In principle, a piece of software is introduced to the OpenHarmony only once.|
| Source| Check whether the software is downloaded from its official website or source specified on the official website.|
| Community activeness| 1. Do not introduce software from a community or organization that notifies users of software maintenance termination by releasing a bullet, modifying the software repository status, or moving the software repository in a specified directory.<br>2. Do not introduce software from an individual, a small community, or an organization that has not released a version (either official or test version) within two years, does not have a clear version roadmap, or does not respond to any valid bug or pull request in the community.<br>3. Do not introduce software from a community that is not longer maintained or does not respond to any operating status related issue or email for more than half a year.|
| Security vulnerability| 1. Search for disclosed security vulnerabilities in the industry, and check whether solutions are provided if there are high-risk vulnerabilities in the software.|
| Software name| 1. Name the repository in the format of **third_party**_**softwareName**, where **softwareName** must be the same as the official name.<br>2. Do not use the sub-module name of the software as the software name.<br>3. If the software has development libraries in multiple languages, add prefixes such as **python-** to the official software name for standardized management.|
| Official website information| 1. Describe the official website of the software in the request. If there is no official website, provide the project URL on a mainstream code hosting platform. Dot not use the hosting library addresses such as Maven, mvnrepository, and SpringSource.<br>2. Provide the official download address of the software version source package for traceability. If a binary package is required, provide the official download address of the binary package.|
| License| 1. Check whether the software to be introduced has a license.<br>2. Check whether the imported license is consistent with the license of the corresponding version on the official website of the software.<br>3. Exercise caution when introducing open-source software with high-risk licenses. Before introducing the software, fully evaluate the risk and attach the analysis conclusion in the request.|

#### Submitting a Request

Follow the process described in the [SIG Management Regulations](https://gitee.com/openharmony/community/tree/master/sig). In addition, include the following information in the request:

1. Self-check list

| Check Item| Description| Self-Check Result Example|
| :----- | :----- | :----- |
| Software name| Provide the official name of the software and the repository name to which the software is introduced. The repository name is in the format of **third_party**_**softwareName**.| third_party_**softwareName**|
| Official website| Provide the official website link of the software.| <https://softwaresite> |
| Software version| Provide the version number of the software to be introduced. The version number must be an official version number released by the community. Do not modify the version number or introduce a version that is not officially released.| 1.0.0 |
| Software version release date| Provide the official release date of the software version.| 2021.01.01 |
| Software version address| Provide the official download URL of the version. Note that the URL must be able to locate the release package of the specific version.| <https://gitee.com/softwarecodesite/v1.0.0.zip> |
| Software license| Provide the official license name of the version and the relative path of the license file. If there are multiple licenses, list them all and describe their relationship, for example, And, Or, or different licenses for different directories.| Apache-2.0 |
| Software lifecycle| Describe whether the software has an LTS version, how frequent a version is released, code submitted to the community in the last year, issue resolution status, and whether end of maintenance or evolution is notified.| No LTS version; one version released every six months; 10 code submissions in the last six months|
| Security vulnerabilities| List disclosed security vulnerabilities in the software, including the vulnerability number, severity, link, and whether patches or solutions are available.| No disclosed vulnerabilities.|
| Service scenario| Describe the repositories where the software is used and the service scenarios where the software is used.| Used by the static link of the *XX* repository to improve the *YYY* capability.|
| Normalization| Describe whether the likes of the software exist in the OpenHarmony community, what similar software is in the industry, and why the software or version is introduced.| This software has not been introduced to the OpenHarmony community. Similar software in the industry includes B and C. Only this software is license-friendly and has a good ecosystem. Companies such as *X* and *Y* are also using this software.|
| License compatibility| 1. Describe the processes that use the software, the license of each process, and whether these licenses are compatible with the license of the software to be introduced.<br>2. Use the OAT tool to scan the source code of the software. Attach the scanning report (with all found errors rectified) and the **LicenseFile.txt** file in the request.| 1. This software is used in the user-mode *X* process in static link mode. The process is licensed under Apache-2.0, which is consistent with the software license. There is no compatibility issue.<br>2. **Result.txt** generated by the OAT tool and **LicenseFile.txt**<br> |
| Owner| Provide the name of the SIG responsible for the software management and the Gitee username and email address of the maintenance owner.| SIG XXX, James, James@example.com|

Note:

- For details about how to use the OAT tool, see [OSS Audit Tool](https://gitee.com/openharmony-sig/tools_oat). If you have any suggestions on the tool, submit an issue in the community. You can also fork the repository and improve the tool through pull requests.
- In principle, the OAT report should contain no errors. The format is as follows:

```
Invalid File Type Total Count: 0
License Not Compatible Total Count: 0
License Header Invalid Total Count: 0
Copyright Header Invalid Total Count: 0
No License File Total Count: 0
No Readme.OpenSource Total Count: 0
No Readme Total Count: 0
```

- The **LicenseFile.txt** file is located in the **log** directory of the OAT tool running directory. This file records all suspected license files in the scan directory. The format is as follows:

```
third_party_abcde/ LICENSEFILE LICENSE Apache-2.0
third_party_abcde/doc/ LICENSEFILE LICENSE Apache-2.0
```

2. **OAT.xml** file

Confirm the issues found by the OAT tool and configure the **OAT.xml** file. For details, see [OSS Audio Tool](https://gitee.com/openharmony-sig/tools_oat/blob/master/README.md). Attach the file in the request. If no issue needs to be confirmed, you do not have to configure the file.

3. **README.OpenSource** file of the repository. The format is as follows:

```
[
  {
    "Name": "softwarename",
    "License": "Apache-2.0",
    "License File": "LICENSE",
    "Version Number": "1.0.0",
    "Owner": "James@example.com",
    "Upstream URL": "https://gitee.com/softwarecodesite/v1.0.0.zip",
    "Description": "...."
  },
  {
  ...
  }// If there are multiple licenses, list them one by one.
]
```

#### Open source software introduction Review

Refer to the [SIG-Architecture](https://gitee.com/openharmony/community/blob/master/sig/sig-architecture/sig-architecture_cn.md). The SIG-Architecture will arrange the review of the applying of creating new repository.

### License Requirements for Third-Party Open-Source Software

1. The software license must be clearly defined by the [Open Source Initiative (OSI)](https://opensource.org/osd-annotated).
2. The software license must be compatible with the license for the code repository.
3. The following licenses for third-party open-source software are recommended in the OpenHarmony project:

- Apache License 2.0
- Mulan Permissive Software License, Version 2
- BSD 2-clause
- BSD 3-clause
- DOM4J License
- PostgreSQL License
- Eclipse Distribution License 1.0
- MIT
- ISC
- ICU
- University of Illinois/NCSA
- W3C Software License
- zlib/libpng
- Academic Free License 3.0
- Python Software Foundation License
- Python Imaging Library Software License
- Boost Software License Version 1.0
- WTF Public License
- UNICODE, INC. LICENSE AGREEMENT - DATA FILES AND SOFTWARE
- Zope Public License 2.0

4. The following licenses for third-party open-source software are not recommended in the OpenHarmony project:

- GNU GPL 1, 2, 3
- GNU Affero GPL 3
- GNU LGPL 2, 2.1, 3
- QPL
- Sleepycat License
- Server Side Public License (SSPL) version 1
- Code Project Open License (CPOL)
- BSD-4-Clause/BSD-4-Clause (University of California-Specific)
- Facebook BSD+Patents license
- NPL 1.0/NPL 1.1
- The Solipsistic Eclipse Public License
- The "Don't Be A Dick" Public License
- JSON License
- Binary Code License (BCL)
- Intel Simplified Software License
- JSR-275 License
- Microsoft Limited Public License
- Amazon Software License (ASL)
- Java SDK for Satori RTM license
- Redis Source Available License (RSAL)
- Booz Allen Public License
- Creative Commons Non-Commercial
- Sun Community Source License 3.0
- Common Development and Distribution Licenses: CDDL 1.0 and CDDL 1.1
- Common Public License: CPL 1.0
- Eclipse Public License: EPL 1.0
- IBM Public License: IPL 1.0
- Mozilla Public Licenses: MPL 1.0, MPL 1.1, and MPL 2.0
- Sun Public License: SPL 1.0
- Open Software License 3.0
- Erlang Public License
- UnRAR License
- SIL Open Font License
- Ubuntu Font License Version 1.0
- IPA Font License Agreement v1.0
- Ruby License
- Eclipse Public License 2.0: EPL 2.0

If you want to introduce the software that complies with the unrecommended licenses listed in **4** or other licenses that are not mentioned, send an email to oh-legal@openatom.io.

## Software Exit and Exit Principles

### What Is Software Exit?

1. Software exit refers to the process in which a piece of software (project) is removed as requested from the OpenHarmony project according to the principles described in this document.
2. The SIG responsible for the software management should submit an exit topic to the PMC for review.

### Software Exit Principles

When the following two conditions are met, the software exit request is executed immediately, and the corresponding file is directly deleted from the project:

1. The software license is changed or the current version is affected by laws and regulations. Due to legal risks imposed by software license changes, laws, or regulations, the OpenHarmony project cannot continue to integrate the software.
2. Malicious code or serious security risks exist and cannot be fixed by the OpenHarmony community.

In other scenarios, OpenHarmony implements process-based management on software exit.

1. Due to outdated technologies or architecture, the software can no longer meet the requirements of existing scenarios and needs to be replaced by other software.
2. The version integrated by OpenHarmony is too old, and an upgrade to the new version is impossible because of the license of the new version or other legal and regulatory restrictions.
3. For software that comes from well-known communities or organizations, the communities or organizations notify users of the software maintenance termination by releasing bulletins, modifying the software repository status, and moving the software repository to a specified directory.
4. For software that comes from individuals, small communities, or organizations, no version (either official or test versions) is released within two years, no clear version plan is available, or no response is provided to any valid bug or PR for more than half a year.
5. The operating status of the community is not clear, and the community does not respond to any operating status related issue or email for more than half a year or replies that the maintenance is terminated.

If the software meets any of the preceding conditions, the PMC and SIG analyze the dependency and usage of the software in the OpenHarmony community.

1. If a dependency exists in the OpenHarmony community and cannot be removed within a short period of time, it is recommended that the SIG create a branch code repository and proactively perform community maintenance.
2. If no dependency exists in the OpenHarmony community or the dependency can be removed in a short period of time, the responsible SIG removes the software from the OpenHarmony official release and describes the reason and impact of the removal in the corresponding Release Notes.
