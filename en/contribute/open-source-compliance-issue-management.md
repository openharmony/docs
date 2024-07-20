# Open Source Compliance Issue Management Process
## Issue Classification and Reporting Process
Open source compliance issues are issues related to licenses, copyrights, open source fragment reference, and open source obligation fulfillment. They are classified into public compliance issues and repository-dedicated compliance rectification issues.

- Public compliance issues include but are not limited to the following:
  - Community compliance requirements (including processes, rules, and engineering methods)
  - Open source compliance consulting (including third-party compliance)
  - Community compliance suggestions
  - Compliance issues for which the home modules and code repositories cannot be determined
  - Issues for which compliance or noncompliance cannot be determined (including repository-dedicated issues for which compliance or noncompliance cannot be determined)
  - Other scenarios not included in repository-dedicated issues

- Repository-dedicated compliance rectification issues are specific issues that have been clearly identified as noncompliance in a given repository and require only rectification tasks.
### Public Compliance Issues
If you find any public compliance issue, submit an issue on the [Issues](https://gitee.com/openharmony/community/issues) tab page in the community repository, start the issue title with **[Compliance]**, and provide a detailed description.
### Repository-dedicated Compliance Rectification Issues
If you find any compliance issue in a specific repository, submit an issue on the **Issues** tab page in that repository, start the issue title with **[Compliance]**, and provide a detailed description.

## Issue Labels

Committers of the community repository regularly review public compliance issues, and committers of the respective code repository regularly review repository-dedicated compliance rectification issues.
They will attach the **sig-compliance** label to issues prefixed with **[Compliance]**.

## Issue Management Process
Routine management is carried out for compliance issues based on the OpenHarmony [Issue Dashboard](http://ci.openharmony.cn/quality/issueDashboard). (Compliance issues are filtered based on the **[Compliance]** prefix and **sig-compliance** label). The compliance SIG routinely handles public compliance issues based on regular meetings and routinely checks whether the repository-dedicated compliance rectification issues are resolved before version release.

In principle, public compliance issues should be replied within 14 days after they are submitted. For compliance issues that require urgent handling, send them to the [Compliance SIG leader](https://gitee.com/openharmony/community/blob/8e25fc45b1fa2f51fbfc627f243be415fa31385e/sig/sig-compliance/sig_compliance_cn.md#leader) by email.
<!--no_check-->