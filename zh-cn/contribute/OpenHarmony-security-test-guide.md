#  OpenHarmony安全测试规范

本文档主要参考业界安全测试标准和最佳实践，提供OpenHarmony安全测试规范，用于指导开发人员/测试人员进行安全测试。

## 1 安全测试内容

1、各模块依据[OpenHarmony C&C++安全编程指南](OpenHarmony-c-cpp-secure-coding-guide.md)，进行代码安全检视，检视问题均需要修复。

2、通过OpenHarmony代码门禁安全扫描工具测试，扫描告警结果清零。

3、依据[OpenHarmony编译规范](https://gitee.com/openharmony/community/blob/master/sig/sig_buildsystem/%E7%BC%96%E8%AF%91%E8%A7%84%E8%8C%83.md)，使用编译选项扫描工具检查二进制文件编译选项开启情况，二进制文件编译选项均需要符合规范要求。

4、针对接收并处理用户态参数模块，开发人员需依据[Fuzz测试框架](https://gitee.com/openharmony/test_developertest/tree/master/libs/fuzzlib)开发灰白盒Fuzz测试套，并完成灰白盒Fuzz测试验证。

5、针对开源组件使用业界漏洞扫描工具扫描，开源组件漏洞均已按照社区漏洞管理流程修复。

6、针对发布版本进行一致性验证，在[版本发布网站](../release-notes/Readme.md)中检查版本镜像是否提供SAH256校验码。

7、各模块依据[OpenHarmony安全设计规范](OpenHarmony-security-design-guide.md)，结合业务完成安全设计自检验证，自检设计问题均需要修复。

8、使用主流病毒扫描软件扫描软件包，病毒扫描结果均修复或确认为工具误报。

9、在代码中搜索“.cer”、“.pem”等证书秘钥格式或者“PRIVATE KEY”等证书秘钥证书关键词找到证书秘钥，检查证书秘钥是否在有效期内，加密算法是否符合[加密算法要求](OpenHarmony-security-design-guide.md#3加密)，证书秘钥问题均需要修复。

10、针对暴露用户态接口进行黑盒Fuzz，包括但不限于系统服务接口、内核驱动接口、socket网络接口。

>说明：上述要求不区分继承特性及新需求。

## 2 安全测试完成要求

版本发布前需进行安全测试，安全测试完成标准如下：

1、上述章节中各项安全测试内容执行完成。

2、安全问题均已关闭。

## 3 安全测试报告模板

1、安全测试报告需包含第1章节安全测试各项结果，需包含未关闭安全问题情况。

2、版本安全测试报告无需单独发布和归档，随版本整体测试报告发布。