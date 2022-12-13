# OpenHarmony Secure Test Guide
With reference to industry standards and best practices, this document provides guidelines for secure tests.



## Secure Coding Test

1. Review the code of each module, and ensure that the code complies with the [Coding Style](./code-contribution.md#coding-style).

2. Use a dedicated tool to scan the code and ensure all the alarms are cleared. A secure code scanning tool has been integrated in the OpenHarmony gated check-in.


## Security Design Verification

Review and verify the security design of each module, and ensure that the security design complies with [OpenHarmony Security Design Specifications](./OpenHarmony-security-design-guide.md).



## Security Tests

1. For critical modules, develop graybox and whitebox fuzzing test suites based on the [Fuzzing Test Framework](https://gitee.com/openharmony/test_developertest/tree/master/libs/fuzzlib) and complete the tests.

2. Perform blackbox fuzzing tests on exposed user-mode APIs, including system service APIs, kernel driver APIs, socket network APIs, and more.

3. Use a build scanning tool to check the build option settings. The build files must comply with the OpenHarmony Build Specifications.

4. Use the mainstream vulnerability scanning tools to scan open-source components. Ensure that all the detected vulnerabilities have been fixed according to the vulnerability management process of the community.

