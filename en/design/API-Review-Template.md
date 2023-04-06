# Review Application for the <ApiName\> API in the OpenHarmony <SubsystemName\> Subsystem

## Background

* API type: [Public API | System API | Test API | HDI]
* API requirement source:
* API usage scenario:
* Belonging subsystem:
* Expected API release version:
* Contributor:
* Number of APIs involved in this review:

| Change Type| Quantity| Programming Language|
|---|---|---|
| Added|  |  |
| Behavior changed| |
| Deprecated| | |
| Deleted| | |

## API Description

### Necessity of the Changes

> Based on the as-is and gap analysis, describe what the application scenarios and benefits of the APIs are.

### Feature Overview

> Describe features implemented by the APIs.

## Review Conclusion

### Review Conclusion from Committers

### Review Conclusion from Domain SIGs

## Self-Check Table

| Self-Check Item| Self-Check Result|
|---|---|
| Is the spelling check completed?|  |
| Are coding specifications complied with?| |
| Are parts of speech (noun, adjective, adverb) used correctly?| |
| Does the API name fully describe the API logic?| |
|Is the number of API parameters appropriate? (Generally, there should be fewer than 7 parameters.)| |
|Are abbreviations properly used? (Abbreviations used should be well known.)| |
|Is it really that the caller of a void API does not need a return value?| |
|Is the inheritance system appropriate? Does every method of a parent class apply to its child classes?| |
|Are all possible error states included and defined?| |
| Is the group of antonyms used correctly, for example: <br/>add/remove, create/destroy, insert/delete, start/stop, begin/end,<br/>send/receive, up/down, show/hide, open/close, source/target,<br/>source/destination, increase/decrease, first/last, next/previous| |
|Are the description and semantic hierarchy of new APIs consistent with those of existing APIs in the same module?| |
| Are asynchronous counterparts needed for synchronous APIs?| |
| Are all the public APIs truly required by developers?| |

## API Description

> Enter the code commit address.

* Code address:

## API Permission Design

> Specify whether developers need to apply for certain permissions to use the APIs.

## API Privacy Protection Design

> If user privacy data is involved, privacy protection must be considered.

## Developer Guide

> Optional.

## API Code Example

> Select either of the following:

* Code address:
* Code snippet:

## API Updates

> Only required for existing APIs.

### Behavior Change

> The API behavior change indicates that the API only has its behavior changed.
> The new API behavior must be released in a new version. You should not change the API behavior without releasing a new version (except for defect rectification).

#### Related APIs

#### Reason for the Change

### Deprecated APIs

> Add the `@deprecated` annotation to the description of deprecated APIs (including JS, TS, C, and C++ APIs).

#### Related APIs

> State the version from which the API is annotated by `@deprecated`.

#### Reason for Deprecation

#### Substitute APIs

> List the APIs provided to substitute the deprecated ones. If there are no substitute APIs provided, describe the reason.

### Deleted APIs

> An API can be deleted only after five API versions have been released since it is marked as deprecated.

#### Related APIs

#### Reason for Deletion

#### Substitute APIs

> List the APIs provided to substitute the deleted ones. If there are no substitute APIs provided, describe the reason.

## DFX

### Compatibility

### Performance

### Power Consumption

### Reliability

### Testability

> Automatic API test cases must be delivered for all APIs.

## Review Conclusion

* Reviewed on:
* Reviewers:
* Review conclusion: [Pass | Fail]
* Review meeting minutes:
