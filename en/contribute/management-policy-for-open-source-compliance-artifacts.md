# Management Policy for Open-Source Compliance Artifacts

## Overview
When introducing, using, and redistributing third-party open-source software, you must fulfill open-source obligations in the software license. Common open-source obligations are classified into obligations to declare the use of open-source software, obligations to declare the code open-source, and obligations to declare modifications to the code. Deliverables required for fulfilling open-source obligations are collectively referred to as open-source compliance artifacts. This document focuses on the specifications for these artifacts in the OpenHarmony community.

## Managing Artifacts for Declaring the Use of Software
The common method in the industry for declaring the use of a piece of open-source software is to provide a **NOTICE** file with the version release. The **NOTICE** file specifies the name, copyright, and license information of the open-source software used, as well as a disclaimer.

### Usage Scenarios of NOTICE

If the binary file contains third-party open-source software, provide a file named **NOTICE** to declare the use of the software.

### Requirements on the NOTICE Content

The **NOTICE** file must describe all third-party open-source software used in the code, including their names, software versions, copyrights, and license information in plain text.

### Generation Rules for NOTICE 

See [Automatic Generation and Collection Policy of OpenHarmony Open-Source Software NOTICE](https://gitee.com/openharmony/build/blob/master/docs/%E5%BC%80%E6%BA%90%E8%BD%AF%E4%BB%B6Notice%E6%94%B6%E9%9B%86%E7%AD%96%E7%95%A5%E8%AF%B4%E6%98%8E.md).

### Storage Location of NOTICE

#### For OS Device Images

- The **NOTICE** file is stored as **NOTICE.txt** under **system.img > system/etc** in the standard device OS image package ( .tar file).

- The **NOTICE** file is stored as **NOTICE.txt** under **/system/etc** in the system.

#### For Applications
The **NOTICE** file is usually stored in the top directory of the release folder or compressed package. For a .jar file, the **NOTICE** is generally stored in the **META-INF** directory.

### Lifecycle of NOTICE
The lifecycle of the **NOTICE** file is the same as that of the binary file. According to the [OpenHarmony Version Lifecycle Rules](https://gitee.com/openharmony/release-management/blob/master/openHarmony-version-lifecycle-management.md), the lifecycle of the **NOTICE** file matches that of the LTS and Release versions.

### NOTICE Template

A complete **NOTICE** file should contain the following content:

```
OPEN SOURCE SOFTWARE NOTICE

Please note we provide an open source software notice for the third party open source software along with this software and/or this software component (in the following just "this SOFTWARE"). The open source software licenses are granted by the respective right holders.

Warranty Disclaimer
THE OPEN SOURCE SOFTWARE IN THIS PRODUCT IS DISTRIBUTED IN THE HOPE THAT IT WILL BE USEFUL, BUT WITHOUT ANY WARRANTY, WITHOUT EVEN THE IMPLIED WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE. SEE THE APPLICABLE LICENSES FOR MORE DETAILS.

Copyright Notice and License Texts
----------------------------------------------------------------------

Software: XXXX vXX

Copyright notice:
Copyright 2023 XXXX Co. LTD  
Copyright 2022 XXXX Co. LTD  
License: Apache License 2.0

                                 Apache License
                           Version 2.0, January 2004
                        http://www.apache.org/licenses/

   TERMS AND CONDITIONS FOR USE, REPRODUCTION, AND DISTRIBUTION

   1. Definitions.

      "License" shall mean the terms and conditions for use, reproduction,
      and distribution as defined by Sections 1 through 9 of this document.

      "Licensor" shall mean the copyright owner or entity authorized by
      the copyright owner that is granting the License.

      "Legal Entity" shall mean the union of the acting entity and all
      other entities that control, are controlled by, or are under common
      control with that entity. For the purposes of this definition,
      "control" means (i) the power, direct or indirect, to cause the
      direction or management of such entity, whether by contract or
      otherwise, or (ii) ownership of fifty percent (50%) or more of the
      outstanding shares, or (iii) beneficial ownership of such entity.

      "You" (or "Your") shall mean an individual or Legal Entity
      exercising permissions granted by this License.

      "Source" form shall mean the preferred form for making modifications,
      including but not limited to software source code, documentation
      source, and configuration files.

      "Object" form shall mean any form resulting from mechanical
      transformation or translation of a Source form, including but
      not limited to compiled object code, generated documentation,
      and conversions to other media types.

      "Work" shall mean the work of authorship, whether in Source or
      Object form, made available under the License, as indicated by a
      copyright notice that is included in or attached to the work
      (an example is provided in the Appendix below).

      "Derivative Works" shall mean any work, whether in Source or Object
      form, that is based on (or derived from) the Work and for which the
      editorial revisions, annotations, elaborations, or other modifications
      represent, as a whole, an original work of authorship. For the purposes
      of this License, Derivative Works shall not include works that remain
      separable from, or merely link (or bind by name) to the interfaces of,
      the Work and Derivative Works thereof.

      "Contribution" shall mean any work of authorship, including
      the original version of the Work and any modifications or additions
      to that Work or Derivative Works thereof, that is intentionally
      submitted to Licensor for inclusion in the Work by the copyright owner
      or by an individual or Legal Entity authorized to submit on behalf of
      the copyright owner. For the purposes of this definition, "submitted"
      means any form of electronic, verbal, or written communication sent
      to the Licensor or its representatives, including but not limited to
      communication on electronic mailing lists, source code control systems,
      and issue tracking systems that are managed by, or on behalf of, the
      Licensor for the purpose of discussing and improving the Work, but
      excluding communication that is conspicuously marked or otherwise
      designated in writing by the copyright owner as "Not a Contribution."

      "Contributor" shall mean Licensor and any individual or Legal Entity
      on behalf of whom a Contribution has been received by Licensor and
      subsequently incorporated within the Work.

   2. Grant of Copyright License. Subject to the terms and conditions of
      this License, each Contributor hereby grants to You a perpetual,
      worldwide, non-exclusive, no-charge, royalty-free, irrevocable
      copyright license to reproduce, prepare Derivative Works of,
      publicly display, publicly perform, sublicense, and distribute the
      Work and such Derivative Works in Source or Object form.

   3. Grant of Patent License. Subject to the terms and conditions of
      this License, each Contributor hereby grants to You a perpetual,
      worldwide, non-exclusive, no-charge, royalty-free, irrevocable
      (except as stated in this section) patent license to make, have made,
      use, offer to sell, sell, import, and otherwise transfer the Work,
      where such license applies only to those patent claims licensable
      by such Contributor that are necessarily infringed by their
      Contribution(s) alone or by combination of their Contribution(s)
      with the Work to which such Contribution(s) was submitted. If You
      institute patent litigation against any entity (including a
      cross-claim or counterclaim in a lawsuit) alleging that the Work
      or a Contribution incorporated within the Work constitutes direct
      or contributory patent infringement, then any patent licenses
      granted to You under this License for that Work shall terminate
      as of the date such litigation is filed.

   4. Redistribution. You may reproduce and distribute copies of the
      Work or Derivative Works thereof in any medium, with or without
      modifications, and in Source or Object form, provided that You
      meet the following conditions:

      (a) You must give any other recipients of the Work or
          Derivative Works a copy of this License; and

      (b) You must cause any modified files to carry prominent notices
          stating that You changed the files; and

      (c) You must retain, in the Source form of any Derivative Works
          that You distribute, all copyright, patent, trademark, and
          attribution notices from the Source form of the Work,
          excluding those notices that do not pertain to any part of
          the Derivative Works; and

      (d) If the Work includes a "NOTICE" text file as part of its
          distribution, then any Derivative Works that You distribute must
          include a readable copy of the attribution notices contained
          within such NOTICE file, excluding those notices that do not
          pertain to any part of the Derivative Works, in at least one
          of the following places: within a NOTICE text file distributed
          as part of the Derivative Works; within the Source form or
          documentation, if provided along with the Derivative Works; or,
          within a display generated by the Derivative Works, if and
          wherever such third-party notices normally appear. The contents
          of the NOTICE file are for informational purposes only and
          do not modify the License. You may add Your own attribution
          notices within Derivative Works that You distribute, alongside
          or as an addendum to the NOTICE text from the Work, provided
          that such additional attribution notices cannot be construed
          as modifying the License.

      You may add Your own copyright statement to Your modifications and
      may provide additional or different license terms and conditions
      for use, reproduction, or distribution of Your modifications, or
      for any such Derivative Works as a whole, provided Your use,
      reproduction, and distribution of the Work otherwise complies with
      the conditions stated in this License.

   5. Submission of Contributions. Unless You explicitly state otherwise,
      any Contribution intentionally submitted for inclusion in the Work
      by You to the Licensor shall be under the terms and conditions of
      this License, without any additional terms or conditions.
      Notwithstanding the above, nothing herein shall supersede or modify
      the terms of any separate license agreement you may have executed
      with Licensor regarding such Contributions.

   6. Trademarks. This License does not grant permission to use the trade
      names, trademarks, service marks, or product names of the Licensor,
      except as required for reasonable and customary use in describing the
      origin of the Work and reproducing the content of the NOTICE file.

   7. Disclaimer of Warranty. Unless required by applicable law or
      agreed to in writing, Licensor provides the Work (and each
      Contributor provides its Contributions) on an "AS IS" BASIS,
      WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
      implied, including, without limitation, any warranties or conditions
      of TITLE, NON-INFRINGEMENT, MERCHANTABILITY, or FITNESS FOR A
      PARTICULAR PURPOSE. You are solely responsible for determining the
      appropriateness of using or redistributing the Work and assume any
      risks associated with Your exercise of permissions under this License.

   8. Limitation of Liability. In no event and under no legal theory,
      whether in tort (including negligence), contract, or otherwise,
      unless required by applicable law (such as deliberate and grossly
      negligent acts) or agreed to in writing, shall any Contributor be
      liable to You for damages, including any direct, indirect, special,
      incidental, or consequential damages of any character arising as a
      result of this License or out of the use or inability to use the
      Work (including but not limited to damages for loss of goodwill,
      work stoppage, computer failure or malfunction, or any and all
      other commercial damages or losses), even if such Contributor
      has been advised of the possibility of such damages.

   9. Accepting Warranty or Additional Liability. While redistributing
      the Work or Derivative Works thereof, You may choose to offer,
      and charge a fee for, acceptance of support, warranty, indemnity,
      or other liability obligations and/or rights consistent with this
      License. However, in accepting such obligations, You may act only
      on Your own behalf and on Your sole responsibility, not on behalf
      of any other Contributor, and only if You agree to indemnify,
      defend, and hold each Contributor harmless for any liability
      incurred by, or claims asserted against, such Contributor by reason
      of your accepting any such warranty or additional liability.

   END OF TERMS AND CONDITIONS

```


## Managing Artifacts for Declaring Code Open-Source

The code released in the OpenHarmony community is automatically open-sourced, and therefore no additional open-source software package is required. The tool described in [Generating an Open-Source Software Package](https://gitee.com/openharmony/build/blob/master/docs/%E7%94%9F%E6%88%90%E5%BC%80%E6%BA%90%E8%BD%AF%E4%BB%B6%E5%8C%85.md) enables automatic generation of the open-source software packages involved in OpenHarmony during the integration of downstream products. It also provides the reference implementation. The OpenHarmony community is not responsible for the fulfillment of open-source obligations of downstream products.

The obligations specified in the license clauses must be fulfilled. For example, the open-source code can be compiled, and the compilation result is consistent with the open-source part in the distributed software artifact; a build guide is included in the open-source software package to describe the build environment, tools, and operation procedures.


## Managing Artifacts for Declaring Modifications to Software

According to some open-source license clauses, after modifying a piece of open-source software, you must declare the modification time, modified code, and modified files.

If an existing file of the open-source software is modified, attach the modification statement to the header of the modified file. For details, see the following template.

```
*  20XX.XX.XX - XXXXX (modification time and brief description of the modification)
                 Copyright(c)20XX. XXXXXXX (Copyright statement of the modifier, with the year when the modification occurs.)
```

If a file is added to the open-source software, attach the copyright statement of the new contributor, license, and disclaimer to the file header.