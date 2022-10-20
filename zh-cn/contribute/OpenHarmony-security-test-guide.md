# OpenHarmony安全测试规范
本文档主要参考业界安全测试标准和最佳实践，提供OpenHarmony安全测试规范，用于指导开发人员/测试人员进行安全测试。



## 安全编码测试

1、各模块依据[OpenHarmony安全编码规范](https://gitee.com/openharmony/docs/blob/master/zh-cn/contribute/OpenHarmony-c-cpp-secure-coding-guide.md)，进行代码安全检视。

2、使用安全编码扫描工具扫描测试，扫描告警结果清零。OpenHarmony代码门禁已集成安全编码扫描工具。


## 安全设计验证

1、各模块依据[OpenHarmony安全设计规范](https://gitee.com/openharmony/docs/blob/master/zh-cn/contribute/OpenHarmony-security-design-guide.md)，结合业务完成安全设计自检验证。



## 安全测试工具扫描

1、针对高风险模块，开发人员需要依据[Fuzz测试框架](https://gitee.com/openharmony/test_developertest/tree/master/libs/fuzzlib)开发灰白盒Fuzz测试套，并完成灰白盒Fuzz测试。

2、针对暴露用户态接口进行黑盒Fuzz，包括但不限于系统服务接口、内核驱动接口、socket网络接口。

3、依据[OpenHarmony编译规范](https://gitee.com/openharmony/community/blob/master/sig/sig-buildsystem/%E7%BC%96%E8%AF%91%E8%A7%84%E8%8C%83.md)，使用编译选项扫描工具检查文件编译选项开启情况。

4、针对开源组件使用业界漏洞扫描工具扫描，开源组件漏洞均已按照社区漏洞管理流程修复。