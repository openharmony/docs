# File Organization


## Directory Structure

Below is the typical directory structure (**entry/src/main/js/Widget**) of a JS service widget.

```
├─widget
│   ├─common
│   │   └─widget.png
│   ├─i18n
│   │   ├─en-US.json
│   │   └─zh-CN.json
│   └─pages
│       └─index
│           ├─index.css
│           ├─index.hml
│           └─index.json  
```

Functions of the files are as follows:

- **.hml** files describe the widget template layout.

- **.css** files describe the page style.

- **.json** files define variables and action events used for a service widget.

Functions of the folders are as follows:

- The **pages** folder stores template pages.

- The **common** folder stores public resource files, such as images.

- The **i18n** folder stores resources in different languages, for example, UI strings and image paths.

## File Access Rules

Application resources can be accessed via an absolute or relative path. In this development framework, an absolute path starts with a slash (/), and a relative path starts with **./** or **../**. The rules are as follows:

- To reference a code file, use a relative path, for example, **../common/style.css**.

- To reference a resource file, use an absolute path, for example, **/common/test.png**.

- Store code files and resource files in the **common** directory and access them in the required fashion.

- In a **.css** file, use the **url()** function to create a URL, for example, **url(/common/test.png)**.

> **NOTE**
>
> When code file A needs to reference code file B:
>
> - If code files A and B are in the same directory, you can use either a relative or absolute path in code file B to reference resource files.
>
> - If code files A and B are in different directories, you must use an absolute path in code file B to reference resource files. The reason is that the directory of code file B changes during Webpack packaging.
>
> - When defining data in a **.json** file, use absolute paths for resource files.

## Configuration Files

If you are developing a widget in the FA model, configure the **config.json** file. For details, see [Overview of Application Configuration Files in FA Model](../../../quick-start/application-configuration-file-overview-fa.md).

If you are developing a widget in the stage model, configure **ExtensionAbility** under **extensionAbilities** in the **module.json5** file. For details, see [Overview of Application Configuration Files in Stage Model](../../../quick-start/application-configuration-file-overview-stage.md).
