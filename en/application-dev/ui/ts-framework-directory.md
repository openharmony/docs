# Directory Structure


The following figure shows the typical directory structure of the **ets** module (in **entry/src/main**) for an application with feature abilities (FAs).


![en-us_image_0000001222967752](figures/en-us_image_0000001222967752.png)


The **ets** directory contains the following files:


**.ets** files: Extended TypeScript (eTS) files that describe the UI layouts, styles, event interactions, and page logics.

Functions of the folders and files are as follows:

- The **app.ets** file manages global application logics and lifecycles.

- The **pages** directory stores all pages.

- The **common** directory stores common code files, such as files of custom components and public methods.


> **NOTE**
>
> - For details about the **resources** directory in **src/main**, see [Resource File Categories](ui-ts-basic-resource-file-categories.md).
>- TypeScript and JavaScript files can be imported as page files.

"js" tag configuration:

Configure the **"js"** tag in the configuration file of your application. The **"js"** tag contains the instance name, page route, and window configuration information.


> **NOTE**
>
>  For details about the **"js"** tag in the FA model, see [Table 22 Internal structure of the js attribute](../quick-start/package-structure.md#internal-structure-of-the-js-attribute).
>
>  For details about the **"js"** tag in the stage model, see [Table 3 Internal structure of the module tag](../quick-start/stage-structure.md#internal-structure-of-the-module-tag).
