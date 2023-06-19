# Licenses and Special License Review

## Purpose

This document lists the acceptable licenses for the code used in the OpenHarmony community. It also describes the review process and rules for special licenses.

## Scope

This document applies only to the code distributed in the OpenHarmony community. It does not apply to the scenario where the OpenHarmony project is used by individuals or enterprises to develop new products, or the scenario where third-party open-source software is distributed independently

## Definition

OpenHarmony is an open-source project launched by the OpenAtom Foundation. The purpose of this project is to build an open, distributed operating system (OS) framework for smart IoT devices in the full-scenario, full-connectivity, and full-intelligence era. 

The OpenHarmony project is hosted on the website https://gitee.com/openharmony.

Code contributed: A contributor commits copyrighted code to the OpenHarmony project, and the project further distributes the code on the hosted website.

Third-party dependency: A third-party open source code that the OpenHarmony project depends. It will be further distributed by the project on the hosted address.

##  License Trustlist for Code Contributed

In principle, the code contributed to the OpenHarmony project must be source code, and its distribution must be carried out under an open source license approved by the Open Source Initiative (OSI).

It is recommended that the code contributed to the OpenHarmony project be distributed using a license in the license trustlist, which includes:

- Apache License 2.0 (Apache-2.0) (applicable to user-mode code)
- 3-clause BSD License (BSD-3-Clause) (applicable to LiteOS kernel code)
- GNU General Public License version 2 (GPL-2.0) (applicable to Linux kernel code)

##  Licenses for Third-Party Dependencies

In addition to the code contributed, the OpenHarmony project may introduce or depend on third-party open source software, which uses a variety of licenses. To ensure the open source attributes, the dependent third-party open source software must have clearly defined upstream open source communities, and the introduction of the third-party open source software does not cause legal issues related to license compatibility.

### Licenses for Acceptable Third-Party Dependencies

Licenses compatible with Apache License 2.0 can be accepted. The OpenHarmony project recommends that third-party dependencies using the following licenses be preferentially accepted:

- Academic Free License 3.0 (AFL-3.0)

- Apache License 2.0 (Apache-2.0)

- Apache Software License 1.1. Including variants:

  - PHP License 3.01
  - MX4J License

- Boost Software License (BSL-1.0)

- BSD License:

  - 3-clause BSD License
  - 2-clause BSD License
  - DOM4J License
  - PostgreSQL License

- ISC

- ICU

- MIT License (MIT) / X11

- MIT No Attribution License (MIT-0)

- Mulan Permissive Software License v2 (MulanPSL-2.0)

- The Unlicense

- W3C License (W3C)

- University of Illinois/NCSA

- X.Net

- zlib/libpng

- FSF autoconf license

- DejaVu Fonts (Bitstream Vera/Arev licenses)

- OOXML XSD ECMA License

- Microsoft Public License (MsPL)

- Python Software Foundation License

- Python Imaging Library Software License

- Adobe Postcript(R) AFM files

- Boost Software License Version 1.0

- WTF Public License

- The Romantic WTF public license

- UNICODE, INC. LICENSE AGREEMENT - DATA FILES AND SOFTWARE

- Zope Public License 2.0

- ACE license

- Oracle Universal Permissive License (UPL) Version 1.0

- Open Grid Forum License

- Google "Additional IP Rights Grant  (Patents)" file

- Historical Permission Notice and Disclaimer

### Licenses for Unacceptable Third-Party Dependencies

In principle, the OpenHarmony project will not accept third-party dependencies that use the following licenses, since these licenses do not support commercial use or contain unreasonable restrictions or obligations:

- Intel Simplified Software License
- JSR-275 License
- Microsoft Limited Public License
- Amazon Software License (ASL)
- Java SDK for Satori RTM  license
- Redis Source Available License (RSAL)
- Booz Allen Public License
- Confluent Community License Version 1.0
- Any license including the Commons Clause License Condition v1.0
- Creative Commons Non-Commercial variants
- Sun Community Source License 3.0
- GNU GPL 3
- GNU Affero GPL 3
- BSD-4-Clause/BSD-4-Clause (University of California-Specific)    
- Facebook BSD+Patents license
- NPL 1.0/NPL 1.1
- The Solipsistic Eclipse Public License 
- The "Don't Be A Dick" Public License
- JSON License

## Rules for Introducing Special Licenses

The OpenHarmony project accepts code contributed and third-party dependencies that use a license in their respective license trustlist. To accept the code or third-party dependency that uses a special license (a license not in the trustlist), a special license review must be carried out by the OpenHarmony project and related rules must be complied with.

### Special License Review Process

#### Organizing a Special License Review

The OpenHarmony compliance SIG is responsible for organizing the special license review. At least the PMC representative, legal affairs representative, and compliance SIG representative are required to participate in the review.

#### Triggering a Special License Review

If your software module or code plans to use a special license, proactively provide a review request to the compliance SIG.

The review request must include at least the following information: software module name, service scenario description, names of involved special licenses and related information (licenses used for direct and indirect dependencies in the third-party dependency introduction scenario), and code check reports (such as OAT scanning reports) provided by the license compliance scanning tool.

The compliance SIG regularly summarizes the gated check-in results, obtains the software modules that use special licenses, and organizes reviews.

Based on the tool check results, the compliance SIG can organize a special license review if it finds that the code will use a special license (a non-trustlist license is used for a third-party dependency, a dedicated license is used for the code contributed, or only binary code or object code is provided).

#### Conclusion of Special License Review

For software modules that use special licenses in the OpenHarmony project, passing the special license review is a prerequisite for theirs code compliance check, and the review conclusion is a prerequisite for the exit review/incubation graduation review carried out by the OpenHarmony QA SIG. Software modules that fail the special license review cannot be incorporated into the OpenHarmony trunk.

### Special License Review Rules

- **Rule 1**: Apache License 2.0 is preferred for user-mode code to ensure license normalization. If a license other than Apache License 2.0 is used, a proper reason is required. If a special license is required for user-mode code, a license with open source obligations should be avoided.

- **Rule 2**: The special licenses used by the code contributed or third-party dependencies should meet the basic distribution and compatibility principles of the open source licenses. That is, the special licenses should support downstream users to distribute related code, and they should not be incompatible with the licenses used by the existing code in the project.

- **Rule 3**: The special licenses used by the code contributed or third-party dependencies should not contain unreasonable restrictions (such as commercial restrictions, domain restrictions, discrimination against special technical domains, or product-specific restrictions) or open source license obligations that cannot be fulfilled or are difficult to fulfill.

- **Rule 4**: The introduction of third-party dependencies should not affect or change the existing licenses of the related code.

- **Rule 5**: The non-source code (binary code or object code), if involved, should use an open source license and meet the preceding rules. The use of a self-prepared license should be approved by the PMC and further reviewed and approved by the OpenHarmony legal compliance team. (In principle, only special licenses for algorithms and special implementation related to necessary hardware, such as GPU, Wi-Fi firmware, and hardware codec algorithms, can be accepted.)
