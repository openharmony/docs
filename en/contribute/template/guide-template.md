# Development Guide Writing Template


> **NOTE**
>
> *1. This template provides the recommended development guide document framework and writing instructions for typical knowledge points. In your writing, complete the development task scenario analysis and development guide outline design based on the specific **solution/feature/function/module**, and then write the content based on this template.*
>
> *2. Do not add any content between level-1 title (marked with #) and level-2 title (marked with ##).*
>
> *3. Delete all the writing instructions in italics from your formal documents.*


## *Example* Overview

*Mandatory. Based on the scenario division of the solution/feature/function/module, you need to provide either "Example Overview" or "Example Task Scenario Overview", or both of them.*

*1. "Example Overview" provides an overview that is common to all task scenarios of this solution/feature/function/module and that developers need to understand. If there is nothing in common, delete it.*

*2. "Example Task Scenario Overview" describes the contents directly related to a task scenario. The knowledge points and key writing points are the same as those in "Example Overview". In this section, you need to introduce this specific task scenario and describe basic concepts, working principles, constraints, and samples that are directly related to the task scenario. If there is no specific task scenario, delete it.*

***[General Instructions for Writing the Development Guide]***

***1. Target audience**: internal and external developers (including product managers). Guidelines for UX designers are usually carried by UX design specifications and are not covered in the development guide. If UX design specifications need to be mentioned in the development guide, use hyperlinks.*

***2. Content positioning**: Introduce what the solution/feature/function/module is, why it is required, and how to design, develop, and release related applications/devices. The development guide aims to help developers learn necessary knowledge and achieve specified task objectives in actual development activities.*

***3. User-oriented****: Always provide developer-concerned, perceptible, and useful content from the perspective of developers.*

***4. Task-oriented****: Focus on actual tasks of developers, and provide complete, correct guidance that is easy to follow.*

*5. This template only provides the basic document framework. You can adjust the content based on the actual requirements.*


### Introduction

*Mandatory.*

***[Developers' Concerns]***

*What is the solution/feature/function/module (definition)? What problems can it solve or what benefits can it bring (purpose/customer benefits - why)? *

***[Key Writing Points]***

- *Provide easy-to-understand and scenario-specific descriptions. Refer to the SCQA method below to introduce the scenarios and characteristics of the solution/feature/function/module.*
  - *S: situation. Introduce a familiar scenario.*
  - *C: complication. Describe the conflict between the situation and requirement.*
  - *Q: question. Ask a question. What can I do in such a case?*
  - *A: answer. Describe the solution.*

- *Visualize abstract concepts. You can provide content from the perspective of consumers for better understanding, for example, scenario effect in UX.*

***[Writing Requirements]***

- *Provide clear content. Avoid vague, obscure, and ambiguous expressions.*

- *Use only necessary terms, acronyms, abbreviations, and proper nouns, and provide explanations or links to the glossary.*

- *Use consistent terms, acronyms, abbreviations, and proper nouns throughout the document.*


### Basic Concepts

*Optional. Describe the basic concepts that are common to all task scenarios.*

***[Developers' Concerns]***

*What are the unique concepts that I need to know when using the solution/feature/function/module?*

***[Key Writing Points]***

- *Provide only the concepts that are mandatory in development tasks.*

- *Describe here concepts used in multiple chapters such as the operation mechanism, restrictions, and development process. If a concept is used only in a chapter, describe the concept in that chapter only.*

- *Do not describe common concepts in the industry. Use common terms in the industry instead of jargon.*

- *If there are logical relationships between concepts, you are advised to use figures to describe the relationships.*

***[Writing Requirements]***

- *Provide clear content. Avoid vague, obscure, and ambiguous expressions.*

- *Use only necessary terms, acronyms, abbreviations, and proper nouns, and provide explanations or links to the glossary.*

- *Use consistent terms, acronyms, abbreviations, and proper nouns throughout the document.*

***[Example]***

Before developing relational databases, you must understand the following basic concepts:

- **RDB**
  

A type of database based on the relational model of data. The RDB stores data in rows and columns. An RDB is also called RDB store.

- **Predicate**

  Property or feature of a data entity, or the relationship between data entities. It is mainly used to define operation conditions.

- **Result set**

  A set of query results used to access the data. You can access the required data in a result set in flexible modes.


### Working Principles

*Optional. Describe the working principles that are common to all task scenarios.*

***[Developers' Concerns]***

*How does the solution/feature/function/module work? What are the API calling and triggering time of key steps? I want to understand its principles for better use and debugging.*

***[Key Writing Points]***

- *If the principle is simple and can be understood from the content under "Basic Concepts", do not provide this section.*

- *Describe only the mechanisms and principles that are visible in the development tasks (use or access). Do not provide internal implementation that is invisible to developers.*

- *If necessary, use sequence diagrams and flowcharts. Ensure that the text description matches the figure description.*

- *Be careful not to disclose internal information.*

***[Writing Requirements]***

- *Provide clear content. Avoid vague, obscure, and ambiguous expressions.*

- *Use only necessary terms, acronyms, abbreviations, and proper nouns, and provide explanations or links to the glossary.*

- *Use consistent terms, acronyms, abbreviations, and proper nouns throughout the document.*

***[Example]***

The distributed data objects are encapsulated into JS objects in distributed in-memory databases, which allows the distributed data objects to be operated in the same way as local variables. The system automatically implements cross-device data synchronization.

**Figure 1** Working mechanism

![how-distributedobject-works](figures/how-distributedobject-works.png)


### Constraints

*Optional. Describe constraints that are common to all task scenarios.*

***[Developers' Concerns]***

*What are the constraints for using the solution/feature/function/module? How well is the solution/feature/function/module implemented? Can it meet my requirements?*

***[Key Writing Points]***

- *Describe perceptible constraints that affect development activities, including but not limited to the following:*
  - ***Function constraints***
     - *Application scope of the solution/feature/function/module (Specify scenarios that are not supported.)*
     - *Specification constraints*
  - ***Operation constraints***
     - *Operations on known issues*
     - *Potentially risky operations (such as performance deterioration)*

- *Describe operations that are prone to errors in the procedure, but not in this section.*

***[Example]***

- Data synchronization can be implemented across devices only for the applications with the same bundleName.

- Each distributed data object occupies 100 KB to 150 KB of memory. Therefore, you are advised not to create too many distributed data objects.

- The maximum size of a distributed data object is 500 KB.


### Samples

*Optional. Provide samples that are common to all task scenarios.*

***[Developers' Concerns]***

*What sample code, codelabs, and demo projects are available?*

***[Key Writing Points]***

*Provide links (generally Gitee links) to the released sample code, codelabs, and demo projects. Do not include project packages into the document as an attachment.*

***[Example]***

The following sample is provided to help you better understand how to develop abilities:

- [Intra- and Inter-page Navigation](https://gitee.com/openharmony/codelabs/tree/master/Ability/StageAbility)


## Setting Up the Environment

*Optional.*

*Based on the analysis and breakdown of a specific task scenario, you can place the environment setup content under "Prerequisites" or "Preparations" and close to the "How to Develop" of the specific scenario.*

*Specify how to prepare the development environment, including software and hardware configuration requirements, tool requirements, and device requirements.*

*Delete this section if no special requirements are involved.*


### Environment Requirements

***[Writing Requirements]***

*Describe the software and hardware configurations required by the development environment so that developers can prepare the environment in advance. You can use subtitles if there is a large amount of content.*

***[Example]***

The following table describes the environment configuration requirements specific to the Hi3861 development board.

  **Table 1** Hi3861 development environment-specific requirements

| Platform Type| Development Tool| Function| How to Obtain|
| -------- | -------- | -------- | -------- |
| Linux server| SCons3.0.4+ | Executes script compilation.| Internet|
| Linux server| build-essential | Provides a basic software package for compilation and building.| Internet|


### Setting Up the Environment

***[Writing Requirements]***

*Describe the procedure for setting up the development environment. If there is a large amount of content, use subtitles, for example, "Setting Up the Basic Build Environment" and "Setting Up the Compilation Tool Environment".*

***[Example]***

1. Start a Linux server.

2. Run the following command to install the tool installation package:
   
   ```
   xxxxx
   ```

3. Run the following command to check whether the tool is successfully installed.
   
   ```
   xxxxx
   ```


### Verifying the Environment

***[Writing Requirements]***

*Optional. Provide the criteria for checking whether the environment is set up successfully. You can also provide the criteria along with the environment setup procedure, as provided in the preceding example.*


## *Example Task Scenario* Development (Use a specific scenario name. If there is only one scenario, use the solution/feature/function/module name.)

*Mandatory.*

***[Developers' Concerns]***

*How do I use or access the solution/feature/function/module?*

***[Key Writing Points]***

*Provide scenarios that are close to actual development scenarios.*

- *Task scenarios are what developers need to use to achieve development objectives.*

- *There can be one or more task scenarios. You can use multiple "Development Guidelines" sections. Follow the hierarchical logic when writing the guidelines, that is, a task scenario -> a subtask scenario -> task logic ("Development Process") -> operation procedure ("How to Develop").*

### *Example Task Scenario* Overview

*Based on the scenario division of the solution/feature/function/module, you can provide either "Example Task Scenario Overview" or "Example Overview", or both of them.*

*1. "Example Overview" provides an overview that is common to all task scenarios of this solution/feature/function/module and that developers need to understand. If there is nothing in common, delete it.*

*2. "Example Task Scenario Overview" describes the contents directly related to a task scenario. The knowledge points and key writing points are the same as those in "Example Overview". In this section, you need to introduce this specific task scenario and describe basic concepts, working principles, constraints, and samples that are directly related to the task scenario. If there is no specific task scenario, delete it.*

### Development Process

***[Key Writing Points]***

- *Optional. If there are many development steps (five or more core operations) or complex logical relationships between steps, provide the development process so that developers can have a panoramic view of the operations to be performed.*

- *Provide flowcharts and tables if necessary.*


### Available APIs

***[Writing Requirements]***

- *Optional. Describe the key APIs in the development steps and provide the API introduction, so that developers can have a general understanding of development.*

- *If there are more than 10 APIs, provide the main APIs only.*

- *Ensure that the APIs and their functions of the corresponding version are supported when the document is released.*

***[Example]***

Certain APIs can be called only by system applications that have been granted the **SystemCapability.Notification.Notification** permission. The APIs use either a callback or promise to return the result. The tables below list the APIs that use a callback, which provide the same functions as their counterparts that use a promise. For details about the APIs, see the [API document](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-notification.md).

**Table 1** APIs for notification enabling

| API                                                      | Description            |
| ------------------------------------------------------------ | ---------------- |
| isNotificationEnabled(bundle: BundleOption, callback: AsyncCallback\<boolean>): void | Checks whether notification is enabled.|
| enableNotification(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void>): void | Sets whether to enable notification.    |


### How to Develop

***[Writing Requirements]***

*Mandatory.*

- *Completeness and Correctness*
  - *Describe the complete development process (for example, steps related to the code, resources, third-party libraries, and application configuration files in the HAP) so that developers can correctly complete the development. Do not omit key configuration operations.*
  - *Ensure that the code snippet provided in the document can be built with the context in DevEco Studio.*
  - *Ensure that the complete sample code provided in the document can be run in DevEco Studio, and the execution result is the same as that described in the document.*

- *Clarity*
  - *Provide a clear execution owner (who), operation purpose (why), operation content (what/how), and scenario (when/where) for each step. Use imperative sentence to describe steps.*
  - *Clearly provide the APIs (if involved) in steps, as well as their usage description and sample code.*
  - *Provide development suggestions or precautions for key steps and sample code (comments for sample code).*
       *Think about what questions may be raised when developers are performing the operations.* *These problems are obstacles to developers.* *Provide support information in the document to help them handle these obstacles.* *Examples of support information:*
     - *Branch selection principle. Provide principles or suggestions for selecting branches and parameters.*
     
     - *Necessary supplementary description. Describe possible special operations, required operation permissions, high efficiency skills, and concise and clear background knowledge.*
     
     - *Precautions. Describe operations that may adversely affect other functions or system performance and reliability, and operations that may cause data loss or security problems.* *Provide this type of information in a style different from that of the body prior to the operation procedure.*
     
     - *Error prevention/correction information. Provide guidance for preventing, locating, or rectifying typical problems that may occur in the development process.* *This type of information can be provided in "How to Develop" or "FAQs", depending on the content amount.*

- *Standardization*
  - *Provide both logically and syntactically correct sample code and write it in a standard manner. Anonymize sensitive information, such as mobile numbers, ID cards, and account names, for example, 186\*\*\*\*\*\*\*\*. Use private IP addresses or a corresponding format, for example, xx.xx.xx.xx and www.example.com, rather than real IP addresses and domain names.*
  - *Provide code that complies with the code indentation requirements. Do not use the **Tab** key to indent code. Instead, use four spaces, to avoid incorrect display.*

**[Example (Excerpt)]**

1. Import the required modules.

   ```javascript
   import formBindingData from '@ohos.application.formBindingData'
   import formInfo from '@ohos.application.formInfo'
   import formProvider from '@ohos.application.formProvider'
   ```
   
2. Implement the lifecycle callbacks of **LifecycleForm**.

   ```javascript
   export default {
       onCreate(want) {
           console.log('FormAbility onCreate');
           // Persistently store widget information for subsequent use, such as widget instance retrieval or update.
           let obj = {
               "title": "titleOnCreate",
               "detail": "detailOnCreate"
           };
           let formData = formBindingData.createFormBindingData(obj);
           return formData;
       },
       onCastToNormal(formId) {
           // Called when the widget host converts the temporary widget into a normal one. The widget provider should do something to respond to the conversion.
           console.log('FormAbility onCastToNormal');
       },
   }
   ```


### Verification

***[Writing Requirements]***

- *Optional. After the development is complete, provide a guide to check whether the operation is successful if there is an independent commissioning and verification operation. The operation procedure is the same as that described in "How to Develop."*

- *Provide only the final service commissioning. You are advised to verify the operation result of each subtask after the development is complete.*


## FAQs

*Optional.*

***[Developers' Concerns]***

*What are the typical problems that may occur in the development process of the solution/feature/function/module? How do I locate and solve these problems?*

***[Key Writing Points]***

*Describe the problems that may occur during the development and the solutions to them.*

- *Delete this section if there are no common problems.*

- *It is recommended that common problems in each task scenario be described in a separate chapter. Common problems related to a single task scenario be described in the corresponding chapter.*



### 1. XX problem (simple problem)

XXX


### 2. XX problem (complex problem)

**Symptom**

XXX

**Possible Causes**

XXX

**Solution**

XXX
