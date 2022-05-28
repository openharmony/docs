# OpenHarmony API Governance Charter

## Introduction

To help the OpenHarmony ecosystem develop and evolve in a healthy and orderly way, this Charter defines the governance process and lifecycle (create, change, deprecate, and delete) of OpenHarmony APIs. It also specifies basic design requirements of OpenHarmony APIs.

This Charter is formulated by the API SIG and approved by the PMC for release. Any revision to this Charter will be released only after being reviewed by the API SIG and approved by the PMC.

## Overview

### Scope and Definition

The OpenHarmony software stack contains multiple roles. Naturally, OpenHarmony APIs have multiple types.

<img src="figures/API-Category.png" width="800" />

Different types of APIs have different compatibility requirements, as described in the table below.

| Type| Prepared By| Used By| Compatibility Requirement| Guarding Method|
|---|---|---|---|---|
| Public API | System and framework| All application developers| 5 API versions| X test suite (XTS)|
| Test API | Test framework| All application developers| 3 API versions| To be built|
| System API |  System and framework|System application developers|Not guaranteed| To be built|
| HDI | HDF| System services| 4 API versions| XTS |
| Driver API | HDF | Driver developers| Not guaranteed| None|
| Inner API | System parts| System parts| Not guaranteed| None|

The APIs are described as follows:

* Public API: APIs provided for all application developers.
* Test API: APIs provided for developers to test their applications.
* System API: APIs provided for privileged system applications. Common applications cannot use these APIs.
* HDI: APIs that describe hardware capabilities.
* Driver API: APIs provided for driver developers.
* Inner API: APIs to implement mutual calling between the system service and framework. They are used only inside the system and do not guarantee compatibility.

### APIs and Programming Languages

OpenHarmony aims to build a next-generation Operating System (OS) for the Internet of Everything (IoE) era. The following programming languages and more can be used:

* C/C++
* JavaScript
* TypeScript

The content described in this Charter is irrelevant to the programming language in use. Regardless of the programming language, APIs must comply with this Charter while meeting the programming language requirements.

## API Governance

### Roles and Responsibilities

|**Role**|**Responsibilities in API Governance**|
| - | - |
|Contributor|Commit API code and design documents.|
|Committer|Review the code and submit a pre-review comment on an API commit.|
|Domain SIG|Comment on the commits of new API code, so the passed commits can be merged. <br/>Submit a pre-review comment on updated API code.|
|API SIG|Comment on updated API code.|
|PMC|Release API version plans. Review amendments of this Charter, revise the terms, and publish this Charter.|

### API Review Process
The API review process is as follows:

<img src="figures/API-Workflow.png" width="800" />

The main process is as follows:

1. Initiate API review and commit code (contributor). If any APIs are added or modified, the contributor must additionally submit an API review application to specify the API requirement source, usage scenario, permission design, and privacy protection design. For details, see "API Review Application Composites" below. To avoid rework, the contributor can send an email to submit the API design document to the committer, domain SIG, and API SIG for pre-review before the formal API review application and code commit.
1. Review code (committer). After the code review is approved, the committer should submit the APIs to the domain SIG. If the API code involves multiple domains, they should be submitted to the committers of the corresponding domains. The next review step can be performed only after all committers review and approve the code.
1. Review APIs (domain SIG). The code of new APIs can be merged only after being reviewed and approved by the domain SIG. If there are changes to existing APIs, the domain SIG should submit them to the API SIG. If the new APIs involve multiple domains, they should be submitted to the SIGs of the corresponding domains. The code can be merged after being reviewed and approved by one of the domain SIGs. If the changed APIs involve multiple domains, they should be submitted to the SIGs of the corresponding domains. The next review step can be performed only after all domain SIGs approve the APIs.
1. Review API changes (owner: API SIG): The code of changed APIs can be merged only after being reviewed and approved by the API SIG.
1. The review is complete.

### API Review Application Composites

If an API is added or changed, the corresponding API review application must be submitted. For details on the application template, see [API Review Template](API-Review-Template.md).

For new APIs, you must:
1. (Mandatory) Describe the requirement source and usage scenario.
1. (Mandatory) Analyze the API as-is and gaps, and describe the necessity of adding or changing APIs.
1. (Mandatory) Describe the API prototype design and usage. (Optional) When necessary, add use examples.
1. (Mandatory) Provide the API permission design.
1. (Mandatory) Clarify the API privacy protection solution and requirements fulfillment.
1. (Mandatory) Submit the corresponding API reference when committing the code. (Optional) When necessary, submit the corresponding developer guide.
1. (Optional) Describe the compatibility, performance, power consumption, reliability, and tests. (If "API Design Requirements" of this Charter are not met, the description must be included.)

For changed APIs, except the preceding operations, you must:
1. (Mandatory) Describe how earlier APIs are handled (deprecated, hidden, or permanently deleted) and compatibility measures for developing applications using old SDKs.
2. (Mandatory) Describe the change impact, substitute APIs, and corresponding application adaptation solution.
3. (Mandatory) Update the ChangeLog file. Update the API-diff file (Mandatory if JS or native API changes are involved.)

## API Design Requirements


### Consistency
1. Concept: Scenario-based service models must be abstracted to form coherent, consistent, and self-consistent OpenHarmony user program models and service concepts.
1. Term: Service terms must be nouns. Multiple nouns with similar semantic meanings are not allowed to represent the same service object. Similarly, to avoid confusion, it is not allowed to use the same noun or linguistically close nouns for different service objects.
1. Operation: Every operation action must be expressed using a unique verb.
1. Parameter sequence: The location and sequence of the same parameter or parameter sequence in multiple APIs must be the same.
1. Mechanism and algorithm: The communication mechanism, calling mode, authentication mechanism, and encryption algorithm must be consistent.
1. API reference, demo, and template style: The layout and usage must be consistent.

### Ease to Use
Design APIs from the perspective of their users rather than providers.
1. Readability: API naming and features must be easy to understand.
1. Ease of use: Provide easy-to-use APIs by reducing unnecessary coupling between APIs, avoiding dependencies on the calling sequence of multiple unrelated APIs, and avoiding calling multiple methods from different packages, modules, or classes at the same time when using a single feature.
1. Avoiding misleading: Provide capabilities complying with user expectations to avoid misuse.
1. Provide required API reference documents.

### Naming
1. Be able to express the capabilities clearly. Use full descriptive words.
1. Avoid misleading. Misleading names are more harmful than ill-stated ones.
1. Use words with clear meaning. Do not use words with common meanings, such as info, data, and object.
1. The larger the scope is, the more precise the naming should be.
1. Eliminate or minimize the use of abbreviations. Common terms in the industry must comply with industry conventions and can be abbreviated.
1. Bundle name/Module name/Namespace prefix convention:
   1. JS API module name: @ohos.\*.
   2. Native API namespace: namespace OHOS.\*.
   3. If external open-source code is referenced, retain the original bundle name, module name, or namespace, or replace the bundle name according to the preceding rules.
1. The bundle name, module name, and namespace must contain 2 to 4 segments. One word is recommended for each segment, and a maximum of two words are allowed.
1. The class name, method name, function name, member variable, and variable name cannot exceed four words.

### Permission Control
1. Completeness: All behaviors across application sandboxes must be limited by permission control.
1. Optimal granularity: One permission protects only one type of object. Developers only need to apply for one permission to access an interface.
1. Clearness: The protected object, permission scope, and sensitivity level must be clearly specified in the permission definition.
1. Minimum scope: A permission is assigned only to applications that have service requirements to minimize permission scope.

### Privacy Protection
1. The response returned from API calling should contain only necessary information.
1. Mobile phone users' personal data cannot be obtained through API calling unless required permissions are assigned by users. 
1. In case that an API is called by multiple applications, if personal data needs to be disclosed to the API to be called, the caller must specify the disclosed data type, data receiver, and data use purpose in the privacy statement.
1. When an API needs to access sensitive user data (such as phone calls, contacts, and media content), the system picker mechanism must be used to prevent the API from accessing the data through sensitive permission application.
1. API openness does not allow unrelated features.

### Documentation
1. The API reference document must be written in English.
1. The API reference document must include the brief and detailed descriptions of modules and packages.
1. The API reference document must include brief descriptions of classes, methods, interfaces, enumerations, and member variables.
1. The API reference document can optionally include detailed descriptions of classes, methods, interfaces, enumerations, and member variables.
1. The API reference document must contain descriptions of all input parameters of every method or interface.
1. If a method or interface has a return value, the API reference document must contain a return value description.
1. If an exception may be thrown during the execution, the API reference document must contain the exception description.
1. The starting version of the API (annotated with @since) must be included.
1. The version of a module or class (annotated with @version) is optionally included.
1. If incompatible API changes are involved, both API-Diff and ChangeLog files must be delivered.

### Compatibility
1. The API compatibility requirements in descending order are as follows: contract compatibility > binary-code compatibility > source-code compatibility.
   1. Source-code compatibility: After version evolution, the existing source code can be compiled properly.
   1. Binary-code compatibility: After version evolution, the existing programs can be linked to and run properly without recompilation.
   1. Contract compatibility: also called semantic compatibility. After version evolution, the original program behaviors remain unchanged.
1. API backward compatibility must meet binary-code compatibility requirements. Exceptions must be reviewed by the API SIG and approved by the PMC. Common API changes that break binary-code compatibility include:
   1. Delete any API elements.
   1. Reduce the visibility of a method. For example, change from protected to private or from public to protected.
   1. Change the class type. For example, change from an abstract class to a non-abstract class, or from an interface class to a non-interface class.
   1. Change the method prototype. For example, change the return value type, input parameter sequence, or input parameter type.
   1. Change the member attributes. For example, change the member attribute from non-final to final or from non-static to static.
1. Do not modify APIs with the same prototype but incompatible features. You can modify APIs by deprecating old APIs and adding new ones with restrictions.
1. Depending on the release type, the API lifecycle and compatibility requirements are as follows:

![](figures/API-Lifecycle.png)

   1. Canary version: API Preview version released at an earlier date, which cannot ensure API stability.
       1. Canary versions are compatible with the previous Release version.
       1. Different Canary versions of the same API version are not required to keep compatible.
   1. Beta version: publicly released beta version, which cannot ensure API stability.
       1. Beta versions are compatible with the previous Release version.
       1. Beta versions are not compatible with the early Canary versions of the same API version.
       1. Different Beta versions of the same API version are not required to keep compatible.
       1. The APIs are frozen after the API Stable version is released. API additions or changes are not allowed for later Beta versions.
   1. Release version: official API release version.
       Released APIs must comply with the contractual commitments made to developers. In principle, incompatible changes cannot be made on released APIs, and deprecation of released APIs is restricted. The basic requirements for deprecating released APIs are as follows:
       1. Add the @deprecated annotation.
       1. Provide substitute APIs.
       1. Retain the deprecated APIs in at least five API versions released since the deprecation.

### Performance
1. Respond in a timely manner to avoid callers waiting. If an API call takes a long time, use an asynchronous API.
2. Pay attention to the impact of the API call timing and frequency on the RAM usage.
3. Pay attention to the impact of the API call timing and frequency on power consumption.
4. Resources must be released in a timely manner when APIs that use resources are called. A fault tolerance mechanism must be provided for abnormal scenarios to ensure timely resource release.

### Power Consumption

1. Evaluate the impact of the API call timing and frequency on power consumption, and perform related design if there is any impact.
2. The power consumption should not deteriorate during version evolution.

### Reliability

1. APIs cannot crash due to external input (such as input parameters, system status, and external data), internal status, or data exceptions. It must return a specific error code or throw a predefined exception.
2. It must be specified whether an API is called synchronously or asynchronously. If an API is called synchronously, specify the timeout duration or allow the caller to set the timeout duration to prevent service response failure caused by call suspension.
3. APIs must support multi-thread reentrant.
4. APIs must meet the idempotence requirement, which means that the same effect should be obtained for one or multiple API call requests with the same service meaning (except that API call depends on external resource changes). For reentrant API call, avoid introducing time-varying factors, such as system ticks, static variables, and global variables without mutual exclusion protection. For repeated call of the same client, **contextID**, **clientToken**, and **sequenceNo** can be used as input parameters.
5. The lifecycle of objects created in APIs must have an end to prevent object resource leakage.
6. The APIs must specify the maximum number of retries allowed after a call failure.

### Testing
1. Automatic API test cases must be delivered for all new APIs.
2. Use a test case for each single scenario. One test case covers a single function of an API, simplifying the code logic of each single test case.
3. The test case execution must be efficient. The execution time of each test case must be limited to milliseconds.
4. Automatic API test cases must be available for all APIs.
5. Assertions with functional logic are required in addition to the capability of throwing exceptions.

### Programming Languages

Regardless of the programming language in use, APIs must comply with the OpenHarmony programming language specifications.
