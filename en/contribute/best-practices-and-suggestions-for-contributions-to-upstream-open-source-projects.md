# Best Practices and Suggestions for Contributions to Upstream Open-Source Projects

## Upstream First
During feature development, software versions in OpenHarmony community may introduce third-party open-source software as part of themselves. For details, see [Introducing Open-Source Software](introducing-open-source-software.md).

To maintain the third-party open-source software introduced, you are advised to use the best practice in the industry, **Upstream First**.

## Maintenance of Third-Party Open-Source Software

Preferentially incorporate bugfixes and new features into the upstream communities to reduce the fork differences and reduce the risk of technical debt caused by the incremental content. After the incorporation, upgrade the third-party open-source software in the OpenHarmony community.

If you are required to incorporate the content first into the OpenHarmony code repository due to reasons such as the version pace, make a reasonable plan for incorporating the content to the upstream as much as possible (except for the content that cannot be accepted by the upstream after evaluation).

You may be required to sign the Developer Certificate of Origin (DCO), Contributor License Agreement (CLA), or other documents when contributing to an upstream community. As the copyright of related code belongs to yourself or your organization, you are advised to consult the legal affairs department of your organization for legal issues. If you have any questions, contact OpenHarmony [GLA](https://www.openharmony.cn/GLA).

## Security Vulnerability Handling Requirements for Open-Source Projects
For details about security-related activities, such as fixing vulnerabilities in third-party open-source software, see [OpenHarmony Security Vulnerability Handling Process](https://www.openharmony.cn/security/vulnerability-process).
