# Multilingual Resource Provisioning


## Use Cases

When an application is to be launched in multiple countries or regions, the application needs to be localized according to local language and culture requirements. This allows the application to load and display content in such a way that meets the usage habits of local users. The contents loaded on the UI include text, images, audios, and videos. Such contents are called resources. To ensure that the application properly loads the content specific to different countries, locales, and languages, you need to create multiple resource directories to store these resources. When a user runs an application, the system automatically selects and loads the resources that best match the device based on the locale. To better implement application localization, it is recommended that the localized content be separated from the core functions as much as possible and be stored in a resource directory.

The following introduces how to configure resource files and resource matching rules. You only need to focus on resource configuration. After resource files are configured, your application can then access resources based on service requirements. For details, see [Resource Categories and Access](../quick-start/resource-categories-and-access.md#resource-access).


## Resource File Configuration

1. Determine the target locale for localization. For details, see [Locale](i18n-locale-culture.md).

   Prepare resources for the target locale and translate the resources (including strings, media resources, files, images, and audios) into target language. This step takes up most of the workload of the localization process.

2. Create resource directories.

   Resource directories include a default directory (`base` directory) and one or more qualifier directories. The default directory is generated when a project is created. It can be used to store content such as strings, colors, animations, and layouts. Qualifier directories can be customized based on languages and scripts. They are used to store resources such as strings, images, and audios specific to the target locale. An example of a customized qualifier directory is `resources/en_GB-vertical-car-mdpi`.

3. Create resource group directories. Create the corresponding resource group directory according to the resource type. For example, to store media resources, create the `media` directory. The directory structure is `resources/en_GB-vertical-car-mdpi/media`.

4. Create resource files. Place resources such as strings, images, and audios in the corresponding `.json` resource files.

   > **NOTE**
   >   
   > - A best practice of application localization is to separate the localized content from the core functions as much as possible and store the content in a resource directory.
   > 
   > - For details about how to create resource directories, resource group directories, and resource files, see [Resource Categories and Access](../quick-start/resource-categories-and-access.md).


## Resource Matching

Resource matching means to match application resources with the application preferred language list to find a preferred language that best suits application resources. For example, displaying a string involves the following steps:

1. Use the system language to match the resource qualifier directories configured for the application to find the matching qualifier directories.

2. Sort the qualifier directories according to the relevance, search these directories in sequence for the target string resources, and use the qualifier directory where the resources are first found for display.

3. If no string resources matching the preferred language are found, use the second preferred language to repeat the previous step.

4. If no matching string resources are found based on the application preferred language list or system language list, use the default resource directory for display. To avoid build errors and resource loading errors, make sure that resources are configured in the default resource directory of each application.
