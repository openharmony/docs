# OpenHarmony API Design Specifications

**Change History**

| Version          | Prepared By               | Release Date      | Description  |
| -------------- | ------------------- | ---------- | ---------- |
| v0.1| OpenHarmony API SIG | November 2022| Trial version.|

## Purpose

An API is a definition provided by a software implementer for developers on the programming UI to reflect the capability scope of a software entity.

The quality of APIs greatly affects developer experience.

To deliver a sound developer experience and promote the healthy development of the OpenHarmony ecosystem, the API SIG formulates the OpenHarmony API design specifications.

## Scope

OpenHarmony APIs are classified into public APIs (open to third-party applications) and system APIs (available only for system applications).

The design specifications are effective for both types of APIs, regardless of the programming language in use.

For details about the API classification, see [OpenHarmony API Governance Charter](OpenHarmony-API-governance.md).

## API Design Objectives

A good API design must meet the following requirements:

* Operational: An API must be able to implement the capability it claims to offer. This is the fundamental requirement.
* Expressive: By calling an API, the caller can clearly express what they want to do.
* Simple: An API must be easy to learn and use, and not prone to errors.
* Predictable: An API must always complete its mission according to the definition. If the definition does not contain errors or exceptions, no error or exception should occur regardless of how many times the API is called. If an error or a failure may occur, describe the error or failure in the definition and return the corresponding error at the correct time.

You must understand the following when designing APIs:

* The stability and consistency of APIs take precedence over the API quantity.
* A better API name is the one that is easy to understand, not a shorter one.
* APIs should be encapsulated to prevent too much information from being exposed.

From the perspective of developers, a well-designed API has different features in different phrases.

* In the learning phase
  * Easy to understand
  * Easy to use
* In the development phase
  * Expressive
  * Simple
  * Predictable
* In the maintenance phase
  * Stable
  * Easy to maintain

## API Design Overview

To make the rules as universal as possible, the specifications do not involve programming language differences or coding specifications. You need to comply with the corresponding requirements for them.

This document provides pre-release review specifications and post-release evaluation specifications.

* The pre-release review specifications are the basic requirements for APIs. Any API must meet these requirements before passing the release review.
* The post-release evaluation specifications require the API providers to keep an eye on the APIs after they are published. Even though an API has met all the pre-release review specifications, it may not be perfect. On-time review after the release helps further improve the API quality.

The following lists all the rules that you should comply with during API design. The list is provided for quick indexing, and the detailed description is provided in the following sections.

Every OpenHarmony API provider should be familiar with these rules.

### Pre-release Review Specifications

* Usability
  * Rule 1: Coding rules compliant
  * Rule 2: Grammatically correct
  * Rule 3: Proper use of abbreviations
  * Rule 4: Accurate use of words in pairs
  * Rule 5: Accurate use of design or architecture patterns
  * Rule 6: No controversial names
  * Rule 7: Appropriate parameter types
  * Rule 8: Appropriate parameter quantity
  * Rule 9: Appropriate parameter sequence
  * Rule 10: Complete return value definition
  * Rule 11: Appropriate exception definition
  * Rule 12: Positive expressions
  * Rule 13: Reducing the possibility of errors
  * Rule 14: No sequential coupling
  * Rule 15: Accurate logic expression
  * Rule 16: Encapsulation welcomed
  * Rule 17: Single responsibility
* Availability
  * Rule 18: Reliability
  * Rule 19: Complete functionalities
  * Rule 20: Permission and privacy protection
  * Rule 21: Concurrent environment
  * Rule 22: Resource management closure
  * Rule 23: Retry logic
  * Rule 24: Idempotence requirements
  * Rule 25: Device universality
* Consistency
  * Rule 26: Consistent terms and concepts
  * Rule 27: Consistent inter-device behavior
  * Rule 28: Consistent version evolution
  * Rule 29: Consistent naming style
  * Rule 30: Consistent parameter sequence
  * Rule 31: Consistent synchronous/asynchronous style
* Compatibility
  * Rule 32: Version compatibility
  * Rule 33: Backward binary-code compatibility
* API references
  * Rule 34: Basic descriptions for modules, namespaces, classes, and functions
  * Rule 35: Clear description of use cases
  * Rule 36: Accurate API description
  * Rule 37: Accurate parameter description
  * Rule 38: Accurate return value/exception description
  * Rule 39: Complete meta information
  * Rule 40: Consistent style
* Organization mode
  * Rule 41: Reasonable layering
  * Rule 42: Proper module division
  * Rule 43: API reference document available (as part of the API)
* Quality related
  * Rule 44: Performance requirements met
  * Rule 45: Proper power consumption
  * Rule 46: Testable
  * Rule 47: Environmentally adaptable

### Post-release Evaluation Specifications

* Stability
  * Rule 48: Minimized rate for deprecated or changed APIs
* Security
  * Rule 49: No abuse of APIs
  * Rule 50: No exploitation of APIs
* Maintainability
  * Rule 51: Evolution support
  * Rule 52: Consistent behavior after feature expansion
  * Rule 53: Documents updated accordingly
* Irreplaceability
  * Rule 54: Orthogonal design
* Feedback from developers
  * Rule 55: Developer feedback noticed

## Description of Pre-release Review Specifications

### Usability

Usability should be considered in any design. During the design of OpenHarmony APIs, consider usability from the following aspects:

#### Naming

* **Rule 1: Coding rules compliant**

The definition of an API must comply with the coding rules of the project to which the API belongs, for example, the rules for uppercase and lowercase letters, underscores (_), hyphens (-), and prefixes.

You can refer to the following coding rules for the OpenHarmony project:

* [JavaScript Coding Style Guide](../contribute/OpenHarmony-JavaScript-coding-style-guide.md)
* [C Coding Style Guide](../contribute/OpenHarmony-c-coding-style-guide.md)
* [C++ Coding Style Guide](../contribute/OpenHarmony-cpp-coding-style-guide.md)
* [C&C++ Secure Coding Guide](../contribute/OpenHarmony-c-cpp-secure-coding-guide.md)
* [HDF Driver Coding Guide](../contribute/OpenHarmony-hdf-coding-guide.md)
* **Rule 2: Grammatically correct**

API names must be in English. Generally, a class is named using a noun, for example, **exampleManager**, **exampleService**, and **exampleAnimation**. A function is named using a verb or verb-object structure, for example, **start()**, **createUser()**, and **startBoot()**.

It is incorrect to name a class **Start** or a function **ball()**.

In terms of verbs, use transitive verbs, intransitive verbs, and verb tenses correctly. For example, you can name events **transferStarted()** and **renderDone()**.

* **Rule 3: Proper use of abbreviations**

Avoid abbreviations as much as possible, as abbreviations are difficult to understand or even cause misunderstanding.

Use only abbreviations that are well known. Do not make your own abbreviations.

* **Rule 4: Accurate use of words in pairs**

Many words can be used to express the same meaning. The table below lists some examples.

| Word | Synonym                                            |
| ----- | -------------------------------------------------- |
| send  | deliver, dispatch, announce, distribute, route     |
| find  | search, extract, locate, recover                   |
| start | launch, create, begin, open                        |
| make  | create, set up, build, generate, compose, add, new |

When naming APIs, try to use words in pairs, rather than any synonym.

For example, if **add** is used for an API name, **remove** is a better option than **destroy** for its counterpart; if **increase** is used, **decrease** is a better option that **reduce**.

The table below lists common words in pairs that can be used in API names.

| Word    | Counterpart    |
| -------- | -------- |
| add      | remove   |
| increase | decrease |
| open     | close    |
| begin    | end      |
| insert   | delete   |
| show     | hide     |
| create   | destroy  |
| lock     | unlock   |
| source   | target   |
| first    | last     |
| min      | max      |
| start    | stop     |
| get      | set      |
| next     | previous |
| up       | down     |
| new      | old      |

* **Rule 5: Accurate use of design or architecture patterns**

The design or architecture pattern is actually the jargon of the software industry. Use them correctly to avoid misunderstanding.

If your API contains words such as **Strategy**, **Builder**, **Factory**, and **Singleton**, make sure you understand these design patterns accurately and use them correctly.

When your API uses a specific pattern, use the terms defined in that pattern. Do not change the world class or sequence.

* **Rule 6: No controversial names**

Do not use controversial names, including but not limited to any words that violate the laws and regulations, cause religious disputes, or lead to racial discrimination, as well as dirty words.

Considering that OpenHarmony is designed to empower a variety of industries, you need to pay more attention when deciding whether a name is controversial.

#### Parameters

* **Rule 7: Appropriate parameter types**

Typically, it is better to use class type parameters than simple type parameters.

For example, the following APIs seem to be fine at first glance:

* `addPerson(string id, string name, int age)`
* `removePerson(string id, string name, int age)`
* `modifyPerson(string id, string name, int age)`

However, they are not friendly for expansion. If you define the parameters using the class type **Person**, it would be easy to add new parameters. What's more, you do not need to make any changes to the APIs.

Class type parameters reduce the parameter quantity in an API, thereby making the API easy to be remembered.

* **Rule 8: Appropriate parameter quantity**

Use 7 or less parameters in an API. In most cases, use 3 to 5 parameters in an API, for easy of use.

The number of parameters in an API should not exceed 10 in any case. If an API contains more than 10 parameters, the possible cause is that the type is not well encapsulated or the API implementation logic is too complex. If this is the case, consider to use another form.

* **Rule 9: Appropriate parameter sequence**

In some programming languages, parameters in an API are often organized in the order of input parameters followed by output parameters.

If you further sort the parameters based on their logical relationship and importance, it is easier for developers to memorize and use the parameters.

You should place optional parameters after mandatory parameters, and place callback functions at the end. For example, in the **fs.readFile** API, the **path** parameter is mandatory, and **encoding** and **flag** have default values.

```js
fs.readFile(path[, options], callback)
```

```js
fs.readFile('/etc/passwd', (err, data) => {
  if (err) throw err;
  console.log(data);
});

fs.readFile('/etc/passwd', {
    encoding: 'utf-8',
    flag: 'r+'
}, (err, data) => {
  if (err) throw err;
  console.log(data);
});
```

#### Return Values

* **Rule 10: Complete return value definition**

The definition of return values must be complete. This means that you need to consider exceptions in addition to normal situations so developers will be able to handle the exceptions.

Example:

* For a return value of the number type, define the value range and the situation in which an extreme value occurs.
* For a return value of the Boolean type, define when **true** and **false** will be returned.
* For a return value of the array or set type, define when **null** or an empty set will be returned.
* For a return value of the enum type, define when each enumerated value will be returned.
* **Rule 11: Appropriate exception definition**

An exception is returned when, for example, an input parameter is invalid or the API implementation logic is incorrect.

For the same module or service, there should be a unified definition for the situations in which an error value will be returned and an exception will be thrown.

In addition, the same exception type should be used for the same exception.

Consistency greatly reduces the difficulty in using the API and the probability of errors.

#### Others

You are advised to adhere to the following rules to make your APIs easy to use.

* **Rule 12: Positive expressions**

Positive expressions enable developers to think less.

When naming APIs, use positive words instead of negative ones.  

The following is a counter example:

```js
if (!isNotAccessible() || !isNotWritable() || !isNotPrintable())
```

The following is recommended:

```js
if (isAccessible() && isWritable() && isPrintable())
```

* **Rule 13: Reducing the possibility of errors**

Most API use errors are caused by parameter passing errors.

For example, for the following function, both the second and third parameters are Boolean values. When calling the function, developers may find it difficult to remember the parameter values correctly.

```js
declare function findString(text: string, isForward: boolean, isCaseSensitive: boolean): string;
```

You can define enums to reduce the difficulty.

```js
enum SearchDirection {
    FORWARD,
    BACKWARD
}; 

enum CaseSensitivity {
    SENSITIVE,
    INSENSITIVE
}; 

declare function findString(text: string, direction: SearchDirection, sensitivity: CaseSensitivity): string;
```

The use of enums instead of Boolean values and integers helps reduce the possibility of API use errors.

Combining multiple parameters into a type also reduces the possibility of parameter passing errors.

* **Rule 14: No sequential coupling**

Ensure high cohesion and low coupling during software design, especially for large projects.

Coupling indicates the dependency between software modules. A too deep coupling often means a poor architecture design.

According to the static software structure or hierarchical architecture diagram, if there are few dependencies between modules but obvious API calling directions between upper and lower layers, it is a good design. On the contrary, if there are complex inter-module dependencies or call chains with opposite directions between the upper and lower layers, the structure is poor.

Among all the types of coupling, sequential coupling must be noted for APIs. Sequential coupling means that the APIs in a class must be called in a specific sequence in order to work properly.

The following is an example of sequential coupling:

```js
doSomethingFirst()
doSomethingSecond()
doSomethingThird()
```

Sequential coupling poses high requirements on the callers and is prone to incorrect use.

To avoid sequential coupling, you can use the **template method** design pattern.

* **Rule 15: Accurate logic expression**

Some APIs, for example, **getUserAccount()**, are used to query information, whereas others, for example, **createUserAccount()**, are used to modify data.

Never use an API that seems to be used for query to carry out data modification. It will confuse developers.

The name of an API should express everything it does, with no concealing. Only in this way can it be easier for developers to understand what the API does when reading the code.

If an API implements too many features and cannot be named in a few words, it usually means that you should split the API into multiple APIs, to make it cohesive enough.

Do not assume that developers have the same background information as you do.

For example, you may name a field **language** and believe all the readers know that you are talking about the programming language. In fact, someone might wonder whether you are talking about the language of speech. Name it **programmingLanguage** will eliminate the misunderstanding.

However, do not go to another extreme. If the class name or namespace name contains a prefix, do not repeat it in the function.  

* **Rule 16: Encapsulation welcomed**

Encapsulation is a key concept in object-oriented programming.

Encapsulation means that system capabilities should be encapsulated as simple APIs, with implementation details hidden as much as possible.

It is like an iceberg. No matter how large the portion submerged in water is, the visible portion above water should be small enough and concise enough. This is a user-friendly interface.

Encapsulation makes it easy for developers to use, while making fewer errors. For example, an electronic engineer connects all the electric wires in the room and leaves only one button to users. This is a good encapsulation. It prevents users from the need to understand the complex circuit structure and protect them from electric shocks.

* **Rule 17: Single responsibility**

An API should try to do only one thing (a single core responsibility) as much as possible. Example:

```js
// Not recommended
view.fetchDataAndRender(url, templete);

// Recommended
let data = view.dataManager.fetchData(url);
view.render(data, templete);
```

Single responsibility enables developers to use APIs in the minimum unit as required. It also enables developers to encapsulate the service logic based on their service requirements.

In some cases, the rule "single responsibility" may conflict with "encapsulation welcomed". For example, if there are many APIs with a single capability, developers have to notice the calling details for each API.

If this is the case, determine the level of the capability provided by your API based on the encapsulation level. To provide the capability for a high-level caller, you can encapsulate the APIs. To provide the capability for a low-level caller, you can provide separate APIs.

### Availability

* **Rule 18: Reliability**

The APIs provided by the operating system must be fully reliable.

Reliability does not mean that every call has to be successful. If resources are used up, providing a proper return value or exception is also an implementation of reliability.

For every API, all the possible situations must be accurately defined, and the work should be completed according to the defined behavior in the corresponding situation.

Unreliable behavior includes failure to return a value as scheduled or causing application exceptions for no reason.

* **Rule 19: Complete functionalities**

When planning a feature or capability, consider the completeness of functionalities. For example, a process should not be interrupted or an option should not be missing within the supported scope. This requires you to perform sufficient verification and deduction when designing the APIs.

Even if the comprehensive features of an operating system are gradually provided through a series of iterations across years, every specific version should provide closed and self-consistent capabilities. To achieve this goal, you must define clear boundaries for each iteration.

* **Rule 20: Permission and privacy protection**

Permission control and data protection must be provided for any API that involves user data or user privacy.

Comply with the following principles for permission control:

1. Completeness: All behaviors across application sandboxes must be limited by permission control.
2. Optimal granularity: One permission protects only one type of object. Developers only need to apply for the permission of the minimum granularity to access an API.
3. Clearness: The protected object, permission scope, and sensitivity level must be clearly specified in the permission definition.
4. Minimum scope: A permission is assigned only to applications that have service requirements.

Comply with the following principles for privacy protection:

1. The return value should contain only necessary information.
2. The API calling should not obtain or collect users' personal data, unless required permissions are assigned by users. 
3. In case that an API is called by multiple applications, if personal data needs to be disclosed to the callee, the caller must specify the disclosed data type, data receiver, and data use purpose in the privacy statement.
4. When an API needs to access sensitive user data (such as calls, contacts, and media content), the system picker mechanism must be used to prevent the API from accessing the data through sensitive permission application.
5. Open APIs should not contain unrelated features.

* **Rule 21: Concurrent environment**

The OpenHarmony APIs do not require all threads to be safe, considering the extremely high cost (for example, program complexity and performance impact). You only need to select the APIs as required.

APIs dedicated for concurrent environments must be properly designed and described.

In the internal implementation of an API, thread safety issues should be solved as much as possible.

* **Rule 22: Resource management closure**

If an API requests dynamic resources, resource release should also be considered.

If the requested resources are returned to the caller, an API must be provided for the caller to release the resources.

If the requested resources are not directly returned to the caller, consider the resource lifecycle and release timing in the API.

If there is an upper limit for resource usage, describe it clearly and provide an API to check whether the upper limit is reached.

Pay special attention to the time for releasing exclusive resources.

* **Rule 23: Retry logic**

For APIs that may encounter calling failures, provide a retry mechanism. For example, for the scenario in which a process cannot obtain an exclusive resource (such as camera) that is already occupied by another, provide an API to query whether the resource is available.

To prevent repeated attempts, you can provide a listener.

Specify the maximum number of retries allowed after the API call failure.

* **Rule 24: Idempotence requirements**

In mathematics, the idempotent function expression is **f(x) = f(f(x))**. For example, the function for calculating the absolute value, that is, **abs(x) = abs(abs(x))**, is idempotent.

In computer science, idempotence indicates that one or more requests for a resource should have the same effect.

From the perspective of APIs, the effect of calling the API once to open a file should be the same as the effect of calling the API multiple times to open the file. Similarly, the effect of calling the API once to close a file should be the same as the effect of calling the API multiple times to close the file.

* **Rule 25: Device universality**

OpenHarmony is designed for various types of devices.

The API design should meet the device universality requirements. Example:

* For UI components, consider the size of different screens.
* For data storage, consider the size of different storage devices.
* For user input events, consider different user interaction modes, such as touches, voice, and keys.

Certain APIs are available only for specific devices. Example:

* Health sensor APIs are available only for wearables.
* Vehicle control APIs are available only for telematics devices.

You can calibrate the API application scenarios by referring to [SysCap](../application-dev/reference/syscap.md).

### Consistency

* **Rule 26: Consistent terms and concepts**

For purposes of easy understanding, use consistent terms and concepts in API names and descriptions. Avoid jargon. Abstract scenario-specific service models to form coherent and consistent OpenHarmony concepts.

In this regard, observe the following principles:

1. Use a single term for each concept.
2. Terms should be appropriate, explainable, and easy to understand.
4. The definition of terms should be accurate and unambiguous.
5. Common terms in the industry should not be redefined and should be used by following the industry practices.

In general, use terms already defined in [OpenHarmony Glossary](../glossary.md). If necessary, you can add terms to the glossary.

* **Rule 27: Consistent inter-device behavior**

By default, an API should behavior the same between devices of different types.

If the behavior will be different because of the device types, clearly describe the differences and provide a check mechanism.

* **Rule 28: Consistent version evolution**

By default, every API should provide consistent behavior in different versions. If an API change will cause behavior incompatibility, the minimum requirement is to distinguish the target version of the applications.

Simply speaking, API behavior changes should not affect developed applications.

* **Rule 29: Consistent naming style**

Accurate API names do not always mean consistency. For example, words with similar meanings, such as **picture** and **image**, and **path** and **URL**, are often seen in the same set of APIs. You should use the same name when referring to the same object.

For example, the following APIs, which are used to obtain media assets, have different naming styles:

```js
declare function getMediaAsserts(): Array<MediaAssert>;
declare function getAudios(): Array<AudioAssert>;
declare function getVideos(): Array<VideoAssert>;
declare function getImages(): Array<ImageAssert>;
```

They should be named as follows:

```js
function getMediaAsserts(): Array<MediaAssert>;
function getAudioAsserts(): Array<AudioAssert>;
function getVideoAsserts(): Array<VideoAssert>;
function getImageAsserts(): Array<ImageAssert>;
```

* **Rule 30: Consistent parameter sequence**

The same parameter sequence should be used for APIs in the same namespace or module.

For example, there is no restriction on the sequence of **deviceId** and **missionId** in a single API, but their sequence in the APIs of a module must be the same.

```js
function getMissionInfo(deviceId: string, missionId: number): Promise<MissionInfo>;
function getMissionSnapShot(deviceId: string, missionId: number): Promise<MissionSnapshot>;

// Correct
function getLowResolutionMissionSnapShot(deviceId: string, missionId: number): Promise<MissionSnapshot>;

// Incorrect
function getLowResolutionMissionSnapShot(missionId: number, deviceId: string): Promise<MissionSnapshot>;
```

* **Rule 31: Consistent synchronous/asynchronous style**

Asynchronous APIs should be able to be determined based on input parameters and return values. They should use the same style. Example:

```javascript
// Callback mode
function getDefaultDisplay(callback: AsyncCallback<Display>): void;
// Promise mode
function getDefaultDisplay(): Promise<Display>;
```

If both synchronous and asynchronous APIs are provided, you can add the suffix **Sync** to the synchronization API name for better distinguishing. Example:

```js
function getDefaultDisplaySync(): Display;
```

If only the synchronization API is provided and the return value is not **void**, you do not need to add the suffix. Example:

```js
function registerMissionListener(listener: MissionListener): number;
```

### Compatibility

* **Rule 32: Version compatibility**

Carry out full planning and all-round consideration at the very beginning, since API changes pose a high cost. However, you must notice that API changes are inevitable during system development.

API changes must be backward compatible. After an API is deprecated, mark the API **deprecated** in the source code and reference document, and provide the new counterpart.

Retain the deprecated APIs in at least five API versions released since the deprecation. After five versions, you can delete the deprecated APIs after providing obvious notifications to developers and leaving sufficient time for them to modify the applications.

* **Rule 33: Backward binary-code compatibility**

Binary-code compatibility means that an existing program can be linked to and run properly without recompilation after version evolution. It ensures that the memory layout of an instance does not change in the case of a version update.

Common C++ API changes that cause binary-code incompatibility include:

1. Deleting any API elements
2. Adding a virtual function
3. Changing the inheritance of a class
4. Changing the declaration sequence of virtual functions
5. Adding a non-static member variable
6. Changing the declaration sequence of non-static member variables

In terms of binary-code compatibility, C APIs have inherent advantages over C++ APIs. Therefore, you are advised to define native APIs using C.

### API References

API references are used to carry API information. Their quality is vital for the ecosystem development.

* **Rule 34: Basic descriptions for modules, namespaces, classes, and functions**

A basic description must be provided for each module, namespace, class, and function.

A detailed description must be provided for key modules and complex modules.

The description should be in English.

* **Rule 35: Clear description of use cases**

Sample code must be provided for all APIs, and common application scenarios must be covered.

A detailed application scenario description should be provided for complex APIs. You can provide a link to the tutorial that exhibits how to use the API.

* **Rule 36: Accurate API description**

There should be no typos in the API description.

All code samples must be able to run properly. If the behavior of an API varies in different versions, describe the differences.

Mark deprecated APIs and provide the counterparts.

* **Rule 37: Accurate parameter description**

Each parameter in an API must be clearly described. Example:

* For a non-simple type, specify whether the parameter can be null.
* For an enum type, describe the use case of each enumerated value.
* For an optional parameter, specify when the caller needs to pass the parameter and when to ignore the parameter.

**Rule 38: Accurate return value/exception description**

If an API has a return value or an exception, describe them in the API reference. Example:

```js
/**
 * Sync function of rename.
 * @param {string} path - path.
 * @returns {void} rmdir success.
 * @throws {BusinessError} 401 - if type of path is not string.
 * @throws {BusinessError} 201 - if permission denied.
 * @syscap SystemCapability.FileManagement.File.FileIO
 * @since 7
 */
declare function rmdirSync(path: string): void;
```

* **Rule 39: Complete meta information**

The API reference must contain basic meta information, such as **@syscap** and **@since**.

The meta information describes the basic information about an API. The tool and SDK will use the information to perform corresponding processing, for example, displaying a message for a deprecated API.

* **Rule 40: Consistent style**

The API reference document must use consistent style, for example, bold text and image colors.

### Organization Mode

* **Rule 41: Reasonable layering**

An operating system is usually structured in a hierarchical model, and each layer solves different levels of problems.

You need to consider layering during API design.

For example, in the construction industry, all buildings have walls and doors, the walls are made of bricks, and the doors are made of wood. There are abstract layers as follows:

* The first layer is raw materials, including cement, sand, and wood.
* The second layer is building elements constructed from raw materials. Examples of building elements are doors, windows, and walls.
* The third floor is the type of room, for example, bedroom, bathroom, and living room.
* The top floor is a variety of buildings for different purposes, such as hotels and apartments.

Each layer has its own concepts to consider and problems to solve. Think carefully about the layer that your API targets.

* **Rule 42: Proper module division**

In addition to horizontal layering, you should pay attention to vertical layering, that is, module division. OpenHarmony APIs are organized in the form of namespaces. A namespace usually corresponds to a module.

A smaller subsystem can provide only one namespace and have all the APIs in this namespace. A large subsystem can provide multiple namespaces.

* **Rule 43: API reference document available (as part of the API)**

When talking about the APIs provided for developers, we mean not only programming interfaces, but also anything that can be exposed.

The API reference document is one that exposed. It should be managed according to the same rules as the APIs.

### Quality Related

* **Rule 44: Performance requirements met**

The APIs provided by an operating system may be used by all upper-layer applications. They must meet performance requirements in practice.

The following lists some requirements:

1. Respond in a timely manner to avoid callers waiting. If an API call takes a long time, use an asynchronous API.
2. Use the shared memory and message queue when a large amount of data needs to be transmitted.
3. Minimize the number of new process entities.
4. Release resources in a timely manner. A fault tolerance mechanism must be provided for abnormal scenarios to ensure timely resource release.

* **Rule 45: Proper power consumption**

OpenHarmony was designed for different types of devices, most of which were passive devices. Therefore, power consumption must be considered during API design.

During the implementation of each function or mechanism, consider power consumption. Provide a detailed description for high power consumption APIs and offer guidance on how to use them.

Provide a mechanism to prevent APIs from consuming power heavily. For example, after the device screen is locked or the application is switched to the background, stop the high power consumption behavior.

Ensure that power consumption does not deteriorate during version evolution.

* **Rule 46: Testable**

Provide complete automatic test cases to:

1. Quick detect faults during API development to improve API quality.
2. Ensure that code modification does not affect existing functionalities during version iteration.
3. Ensure backward compatibility of APIs.

An OpenHarmony API must meet the following requirements:

1. Automatic API test cases must be delivered for all new APIs.
2. Use a test case for each single scenario. One test case covers a single functionality of an API, simplifying the code logic of each single test case.
3. The test case execution must be efficient. The execution time of each test case must be limited to milliseconds.
4. Automatic API test cases must be available for all APIs.
5. Assertions with functional logic are required in addition to the capability of throwing exceptions.

* **Rule 47: Environmentally adaptable**

To support user personality features, an operating system usually provides environment customization capabilities, such as language, light/dark theme, and font size.

For related APIs, if developers do not pass specified parameters, the results in the corresponding environment should be returned based on the environment in use.

## Description of Post-Release Evaluation Specifications

Even though all the pre-release rules have been satisfied, some issues might be detected during API use.

It does not mean that these issues do not need to be considered during API design.

On the contrary, you should carry out full considerations during the design to prevent these issues from occurring after the API release.

If issues related to the following rules occur after the API release, the API quality is not good.

### Stability

* **Rule 48: Minimized rate for deprecated or changed APIs**

For an API, stability is the most important attribute.

API deprecation and behavior changes greatly reduce maintenance efficiency of developers, especially when multiple device types and system versions are involved.

Designing an API with long-term stability and continuous compatibility is the goal of every API designer.

The API deprecation rate and change rate are inversely proportional to the API quality to some extent.

### Security

* **Rule 49: No abuse of APIs**

All APIs should be designed to prevent themselves from being abused. Abuse means that the use of an API exceeds the expected limit, either in quantity or scope.

For example, the capability for accessing user data (such as **Gallery** and **Contacts**) or running in the background for a long time may be abused.

To prevent abuse in terms of quantity, use one-time authorization.

To prevent abuse in terms of scope, perform restrictions based on the caller identity.

No matter what mechanism is used, describe it in the API reference. In the case of excessive abuse, notify the caller through a specific return value.

* **Rule 50: No exploitation of APIs**

Exploitation means that the use of an API causes negative impact, for example, system attacks.

If a system problem occurs when an API or a combination of APIs is called, regardless of how they are called, there are defects in the API.

It is forbidden to use an API if it (in any case) can be called to crash the system, prevent the system from working, or steal user data. You should consider all possible calling scenarios to avoid extreme situations.

### Maintainability

* **Rule 51: Evolution support**

A large feature of the operating system may take years to complete. This requires you to consider scalability during API design.

If a group of new APIs are added to the new version and the original APIs are deprecated, the API design is poor. This situation should be avoided.

* **Rule 52: Consistent behavior after feature expansion**

With the system evolution, it is common that new parameters are added to APIs or new options are added to parameters.

It is important to keep API behavior consistent. The original behavior should not be damaged by the introduction of new scenarios.

If the behavior has to be changed, only the applications using the new version provide the new behavior. The behavior of applications using the old version remains unchanged.

* **Rule 53: Documents updated accordingly**

When updating the API implementation, update the API reference document accordingly. From the perspective of compatibility, the original behavior should not be changed. New functionalities should be implemented by new APIs.

However, you can change the behavior of an existing API in the following cases:

1. The change is made to rectify the defect.
2. The change is made to improve performance or reduce power consumption.
3. The change is made to provide new features or scenarios, without affecting the original feature or scenario logic.

Describe the first and second cases in the Release Notes, and describe the third case in the API reference document.

### Irreplaceability

* **Rule 54: Orthogonal design**

Orthogonality means that APIs should not overlap.

For example, if an API provides the capability of creating a user account, whereas another API provides the capability of creating a user and logging in to the system, the orthogonality rule is not satisfied. You can change the logic of the second API so it provides the login capability only.

If you draw API capabilities one by one, there should be no overlap between these graphs. For APIs at the same layer, it is not allowed that an API provides capabilities A, B, and C, whereas another API provides capabilities B, C, and D.

To facilitate invocation, some APIs can be combined into a higher-level API. This uses different abstraction levels, not an overlap at the same layer.

### Feedback from Developers

* **Rule 55: Developer feedback noticed**

A released API may have defects detected, even after going through the trial phase.

Therefore, you should continue to notice the feedback from developers after the API release.

The following types of feedback may be possible:

* Requirements: Developers ask for new APIs to provide capabilities. You can plan these requirements in later versions.
* Defects related to API behavior: The behavior of an API is inconsistent with that described in the reference document. This defect should be fixed as soon as possible. If the inconsistency is caused by incorrect description in the reference document, correct the document.
* Inappropriate API design: The name or parameter setting of an API has defects. In this case, develop a new API to replace the defective API.

In some cases, you may need to change the behavior of a published API. Note that behavior changes take effect only on new applications. The behavior can be determined based on the target API version of the application.

In the worst case, you may need to deprecate an existing API and use a new one.
