# Hard Coding and Concatenation Prevention

## Use Cases

A key part of localization is the translation of resource files. To improve the translation efficiency, avoid hard coding and concatenation during development.

Different from obtaining data from external systems or generating data during operation, hard coding means to directly embedding data, parameters, and constants into programs to implement specific functions. Hard coding content displayed on the UI, including text in images, audios, and subtitles, is prohibited as this can increase the difficulty and workload in localization. In addition, a complete piece of text on the UI should not be concatenated by multiple segments. Concatenation makes it difficult to obtain the complete sentence, resulting in translation errors or semantic errors. For example, in the following figure, when **Rain tomorrow** and **Bring an umbrella** are directly concatenated, a capitalization error will arise.

![image_0000001784263061](figures/image_0000001784263061.png)

## Constraints

1. Avoid using hard coding. Extract the strings to be translated into resource files, separate them from the code, and use dedicated APIs for loading. For details, see [Multilingual Resource Provisioning](./l10n-multilingual-resources.md).

2. Do not directly concatenate strings. If variables (for example, **Video** and **Browser** in **Open Video** and **Open Browser**) are present, use placeholders as the substitute of variables to make the syntax complete.
   Example of a resource placeholder:

   ```ts
   {
     "name": "string1",
     "value": "Open %s"
   }
   ```
