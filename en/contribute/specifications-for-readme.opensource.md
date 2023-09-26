# Specifications for README.OpenSource

## Purpose

To better trace the original information about third-party open-source software, the following principle is stipulated in [Introducing Open-Source Software](introducing-open-source-software.md): "Provide the **README.OpenSource** file in the root directory of the software repository. Include the following information in the file: software name, license, license file location, version, upstream community address of the corresponding version, software maintenance owner, function description, and introduction reason." However, developers often raise questions about how to write a **README.OpenSource** file. This document aims to standardize the writing requirements of the **README.OpenSource** file. In the near future, the **README.OpenSource** file can be automatically generated based on the imported information during the introduction of the third-party open-source software.

## Scope

This document applies to all contributors to the OpenHarmony community, especially when they want to introduce third-party open-source software to an OpenHarmony project.

## Improvements and Revisions

- This document is drafted and maintained by the OpenHarmony Compliance SIG. What you are reading now is the latest version of this document.
- Any addition, modification, or deletion of the specifications mentioned in this document can be traced in the tracing system.
- The PMC reviews and finalizes the specifications after thorough discussion in the community.

## Rules for Fields in README.OpenSource
README.OpenSource example

```
[
    {
        "Name": "linux",                   # Full name of the upstream open-source software
        "License": "GPL-2.0+",             # License information contained in the upstream open-source software
        "License File": "COPYING",         # Path of the license file
        "Version Number": "5.10.93",       # Version of the upstream open-source software
        "Owner": "xxx@xxx.com",            # Maintenance personnel and email address of the open-source software in the OpenHarmony community
        "Upstream URL": "https://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git/snapshot/linux-5.10.93.tar.gz",   # URL of the upstream open-source software package
        "Description": "XXXXXXX"           # Description of the upstream open-source software
    },
    {
        ...
    }
]
```

- **Name**: full name of the upstream open-source software, of which the source code is contained in the current code repository. If there are multiple pieces of software, describe them one by one in a pair of braces ({}). Each pair contains a group of metadata about the open-source software.

  > **NOTE**
  >
  > Assume that software A depends on software B. If the source code of software B is stored in the repository of software A (A and B form an include dependency tree), both software A and B must be declared. If a dedicated code repository has been created for software B under the OpenHarmony community and GN is used to specify the dependencies through code repository directories during build (A and B form a build dependency tree), you do not need to declare software B.

- **License**: Use the standard short identifier provided in the SPDX License List. Include one license only. If either license can be used, specify the license selected. If the code repository uses multiple licenses, describe them one by one in a pair of braces ({}).

- **License File**: path of the license file relative to the root directory of the code repository, including the file name. If there are multiple license files, the rules are the same as those for the **License** field.

- **Version Number**: officially released version number of the open-source software. The version number must be the same as the text of the upstream version number.

- **Owner**: maintenance personnel of the open-source software in the OpenHarmony code repository, not the author of the software.

- **Upstream URL**: URL of the source package of the upstream software.

- **Description**: brief description about the open-source software.