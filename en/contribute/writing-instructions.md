# Writing Instructions

This document describes the writing specifications for contributing OpenHarmony documents.

## Naming Specifications

To submit a new document, create a new  **.md**  file in the  **doc**  directory of the project code on Gitee. The file name must be in the  _xxx-xxx_**.md**  format.

For example, a document that describes writing specifications can be named  **write-standard.md**.

## Content Specifications

The content should be concise and intuitive. Introductory documents describe principles, architecture, and design ideas in a concise manner, and operation documents describe key steps to help other developers. Chinese is preferred. It is recommended that both Chinese and English be supported. The OpenHarmony will be updated continuously to ensure the synchronization between Chinese and English.

**Title**

It is recommended that the title have no more than three levels.

Use the verb-object structure in operation documents if possible, and the execution subject should be clearly described. \(e.g., Apply for Privilege\)

**Body**

The following shows the structure of an  **operation document**  for porting.

-   Purpose \(Briefly describe the purpose of the operation, for example, the model of the board to which the port is to be migrated.\)

-   Hardware and software requirements

-   Detailed steps

-   Result verification

    Writing requirements:

    -   The APIs used in steps must be described in the available capabilities at the beginning of the document.
    -   If an operation is optional, specify the optional conditions.
    -   If API calls are required in a step, provide the API, its description, and sample code if any.


**Introductory documents**: The development guide of a feature is used as an example to show the document structure.

-   Overview \(concepts and principles\)

-   Functions \(supported APIs\)

-   Development process \(steps of how to use and develop\)

-   Programming examples \(sample code\)

-   Important notes


**Pictures**

Pictures are stored in the **images**  folder in the directory where the document is stored. For example,

Pictures used in  **OpenHarmony\_DOCUMENTS/docs/quick-start/writing-instructions.md**  are stored in the following directory:

**OpenHarmony\_DOCUMENTS/docs/quick-start/images**

Use relative paths to reference pictures in the document.

> **CAUTION** 
> Use the original pictures to avoid intellectual property infringement risks.

-   Pictures are clear and complete. For example, a flowchart has a start and an end.
-   The graphics has clear logic and are provided with text descriptions. Do not separate the graphics from the text.
-   It is recommended that the image height be about 640 px, the image width be less than or equal to 820 px, the image format be .png, and the image size be less than or equal to 150 KB.
-   The text on pictures should be Chinese in Chinese documents and English in English documents.
-   It is recommended that pictures be named based on the content. Using only a number is difficult for picture inheritance.

> **NOTE:** 
> Reference:
> !\[\]\(./pic/pic-standard.png\)

If a self-made picture is used, refer to the following figure to configure the color. The format can be  **png**,  **jpg**,  **gif**, and so on.

**Figure  1**  Color example

![](figures/color.png "color example")

For screenshots, see the requirements below. If you need to highlight key information in the figure, add a red box or text remarks.

Stroke width: 0.75 pt

Line color: CE0E2D

Chinese font: MicrosoftYaHei

English font: Arial

Font size: 10 pt

**Table**

You can insert a table in  **.md**  documents in the following format:

Input

```
| Tables      | Type          | Note  |
| ----------- |:-------------:| -----:|
| first       | standard      |  None |
| second      | outstanding   |     5 |
| third       | inside        |  with |
```

Output

**Table  1**  Parameters

| Tables |    Type     | Note |
| ------ | :---------: | ---: |
| first  |  standard   | None |
| second | outstanding |    5 |
| third  |   inside    | with |

**Code**

The code example shows how to implement a specific feature. Developers can use the code example to write and debug code. The code requirements are as follows:

-   The logic and syntax of the code are correct.
-   Describe the return values if any.
-   Ensure that key fields are highlighted in bold and that comments are provided for key steps.

