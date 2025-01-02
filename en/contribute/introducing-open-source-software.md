# Introducing Open-Source Software

## Purpose

In OpenHarmony, software that meets [The Open Source Definition](https://opensource.org/docs/osd) is recognized as open-source software.
Providing easy-to-use and quality open-source software for developers across the globe from a wide range of backgrounds is an important goal of the OpenHarmony community. To ensure the overall quality of the OpenHarmony project, this guide is specially formulated for your reference.

## Scope

This guide applies to all third-party open-source software to be introduced to the OpenHarmony project.

## Improvements and Revisions

1. This document is drafted and maintained by the OpenHarmony QA SIG. What you are reading now is the latest version of this document.
   
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
4. Make sure the software can be correctly built on the OpenHarmony project. If the software has dependency software that has not been introduced, or the running or build of the software depends on a component that cannot be introduced, the Architecture SIG should review the request and make a decision.
5. Place the software in an independent code repository and name it in the format of third_party_softwareName, where *softwareName* must be an official name.
6. Retain the directory structure, license, and copyright information of the official code repository of the software. Do not modify the original license and copyright information.
7. Do not introduce any software version that has not been officially released, for example, the Beta version.
8. Do not introduce any software version that has high-risk vulnerabilities and does not provide solutions.
9. If you need to modify the software, place the new code in the software repository and ensure that the new code meets the license requirements of the software. Retain the original license for the modified files, and use the same license for the new files (recommended).
10. Provide the **README.OpenSource** file in the root directory of the software repository. Include the following information in the file: software name, license, license file location, version, upstream community address of the corresponding version, software maintenance owner, function description, and introduction reason.
11. Make sure the software you introduce is under the custody of a domain SIG. In principle, the Architecture SIG will reject a software introduction request if it has not been confirmed by the Compliance SIG and the corresponding domain SIG. When introducing multiple pieces of software at a time, you can ask the Architecture SIG to hold a one-off review meeting between SIGs for faster introduction. If you want to introduce a piece of software but fail to meet the preceding requirements, send an email to oh-legal@openatom.io.
12. If the software you introduce depends on other open-source software, do not nest the dependency software in the subdirectory of the software you introduce. Instead, remove all dependency software items from the software you introduce and place them in an independent repository named in the format of **third_party_*****dependencySoftwareName***. If you nest the dependency software, the same software may have multiple versions, security vulnerabilities in earlier versions may fail to be resolved in a timely manner, and open source compliance issues may arise.
    - Prefix the component names of the dependency software in the **BUILD.gn** file with the name of the software you introduce, for example, part_name = "introducedSoftwareName_dependencySoftwareName".
    - The software you introduce and dependency software are built separately. Use **external_deps** to resolve the inter-component dependency between the two pieces of software.
13. Comply with the following requirements when archiving third-party open-source software:
    - In principle, third-party open-source software that meets the OpenHarmony license introduction requirements should be stored in the **third_party** root directory. You can store it in another directory only if you have sufficient reasons.
    - For third-party open-source software that is introduced by the development board and cannot be incorporated into the OpenHarmony system platform, you can request to create a directory with the name of the open-source software and archive the **README.OpenSource** file in the directory. In addition, the software should use the BUILD.gn mode for independent build and support automatic collection of open-source obligation declaration information.

      ```
       device/soc/$(SOC_COMPANY)/third_party
       device/board/$(BOARD_COMPANY)/third_party
       vendor/$(PRODUCT_COMPANY)/third_party
      ```

14. Comply with the following requirements for the precompiled binary or toolchain used in the OpenHarmony platform version or version building:
    - The source code corresponding to the precompiled binary or toolchain must be hosted in the OpenHarmony community, and the corresponding build guide and open-source obligation fulfillment guide must be provided.
    - Open-source third-party software introduced in the precompiled binary or toolchain must comply with principles 1 to 13.
    - The file [Prebuilts for Clang/LLVM-based Tools Used in OpenHarmony](./prebuilts-readme-template.md) provides the methods for obtaining the source code, building the source code, and updating the prebuilts. It is archived to the root directory of the corresponding module with the OpenHarmony version or toolchain.
    - A complete open-source obligation fulfillment statement must be provided in the root directory corresponding to the precompiled binary or toolchain.
    - If the precompiled file comes from a binary file (such as npm) of the upstream community hosting platform, proceed as follows: In the directory where the binary file is archived, place a **README** file to provide the background description and official hosting address, and a **NOTICE** file to provide the open-source obligation fulfillment statement, including the name, version number, and open-source license agreement of each involved open source software.

### Software Introduction Process

#### Check Before Software Introduction

| Check Item| Description|
| :----- | :----- |
| Normalization| 1. Check whether the software exists in the OpenHarmony community. In principle, a piece of software is introduced to the OpenHarmony only once.|
| Source| 1. Check whether the software is downloaded from its official website or source specified on the official website.|
| Community activeness| 1. Do not introduce software from a community or organization that notifies users of software maintenance termination by releasing a bullet, modifying the software repository status, or moving the software repository in a specified directory.<br>2. Do not introduce software from an individual, a small community, or an organization that has not released a version (either official or test version) within two years, does not have a clear version roadmap, or does not respond to any valid bug or pull request in the community.<br>3. Do not introduce software from a community that is not longer maintained or does not respond to any operating status related issue or email for more than half a year.|
| Security vulnerability| 1. Search for disclosed security vulnerabilities in the industry, and check whether solutions are provided if there are high-risk vulnerabilities in the software.|
| Software name| 1. Name the repository in the format of **third_party_*****softwareName***, where *softwareName* must be the same as the official name.<br>2. Do not use the sub-module name of the software as the software name.<br>3. If the software has development libraries in multiple languages, add prefixes such as **python-** to the official software name for standardized management.|
| Official website information| 1. Describe the official website of the software in the request. If there is no official website, provide the project URL on a mainstream code hosting platform. Dot not use the hosting library addresses such as Maven, mvnrepository, and SpringSource.<br>2. Provide the official download address of the software version source package for traceability. If a binary package is required, provide the official download address of the binary package.|
| License| 1. Check whether the software to be introduced has a license.<br>2. Check whether the imported license is consistent with the license of the corresponding version on the official website of the software.<br>3. Exercise caution when introducing open-source software with high-risk licenses. Before introducing the software, fully evaluate the risk and attach the analysis conclusion in the request.|

#### Submitting a Request

Follow the process described in the [SIG Management Regulations](https://gitee.com/openharmony/community/tree/master/sig). In addition, include the following information in the request:

1. Self-check list

| Check Item| Description| Self-Check Result Example|
| :----- | :----- | :----- |
| Software name| Provide the official name of the software and the repository name to which the software is introduced. The repository name is in the format of **third_party_*****softwareName***.| third_party_**softwarename** |
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
| Owner| Provide the name of the SIG responsible for the software management and the Gitee username and email address of the maintenance owner.| SIG XXX, username, username@example.com|

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

3. The content of the README.OpenSource file in this repository can refer to: [README.OpenSource Configuration File Example](readme.opensource_design_specification_document_and_usage_guide.md).

#### Reviewing New Third-Party Open-Source Software

The [Architecture SIG](https://gitee.com/openharmony/community/blob/master/sig/sig_architecture/sig_architecture.md) will arrange the construction and review of the repository.

### License Requirements for Third-Party Open-Source Software

For details, see [Licenses and Special License Review](licenses-and-special-license-review.md).

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
