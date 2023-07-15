#  OpenHarmony Security Test Guide

With reference to industry standards and best practices, this document provides specifications for security tests of the OpenHarmony project.

## Security Test Content

- Review the code of each module according to [OpenHarmony C&C++ Secure Coding Guide](OpenHarmony-c-cpp-secure-coding-guide.md) and fix all issues found in the review.

- Use the OpenHarmony gated check-in to scan your code and clear all alarms.

- Use the compilation option scanning tool to scan your binary file and ensure that the settings of all the compilation options comply with the OpenHarmony Compilation Specifications.

- For the module that receives and processes user-mode parameters, develop gray-box and white-box fuzz testing suites according to the [Fuzz Testing Guide](https://gitee.com/openharmony/test_developertest/tree/master/libs/fuzzlib) and complete the tests.

- Use mainstream vulnerability scanning tools to scan open-source components. Ensure that all the detected vulnerabilities have been fixed according to the vulnerability management process of the community.

- Perform consistency check of the released versions, and check that the [released version images](../release-notes/Readme.md) provide the SAH-256 checksum.

- Complete the security design self-check for each module according to [OpenHarmony Security Design Specifications](OpenHarmony-security-design-guide.md). Ensure that all design issues found in the self-check have been fixed.

- Use mainstream viruses scanning software to scan software packages. Ensure that all virus detected have been removed or confirmed as false alarms.

- Search for ".cer" and ".pem" or keyword such as "PRIVATE KEY" to find the certificate key, and check that the certificate key is within the validity period and the encryption algorithm meets [encryption algorithm requirements](OpenHarmony-security-design-guide.md#3-encryption). Ensure that all certificate key issues have been resolved.

- Perform black-box fuzz testing on exposed user-mode APIs, including system service APIs, kernel driver APIs, socket APIs, and more.


>**NOTE**
>
>The preceding requirements apply to all new and inherited features.

## Security Test Completion Requirements

The mandatory security test performed before version release is complete only when:

- All the security tests mentioned in [Security Test Content](#security-test-content) are complete.

- All security issues have been closed.

## Security Test Report Template

- The security test report must contain the security test results in [Security Test Content](#security-test-content) and pending security issues.
- The version security test report is released with the entire test report of the version, instead of being released and archived separately.
