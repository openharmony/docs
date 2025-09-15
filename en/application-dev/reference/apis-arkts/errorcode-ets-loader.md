# Compilation Toolchain Error Codes
<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @aftott-->
<!--Designer: @hufeng20-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @foryourself-->

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 10311001 Failed to Import ArkTS Files

**Error Message**

Importing ArkTS files in JS and TS files is forbidden.

**Description**

It is forbidden to import ArkTS files to JS or TS files.

**Possible Causes**

ArkTS files have been imported in JS and TS files.

**Solution**

Remove the import statements for ArkTS files from JS and TS files.

## 10311002 Failed to Parse OhmUrl

**Error Message**

Failed to resolve OhmUrl. Failed to get a resolved OhmUrl for `${filePath}` imported by `${importerFile}`.

**Description**

Failed to resolve OhmUrl. Failed to obtain the parsed OhmUrl for ${filePath} imported by ${importerFile}.

**Possible Causes**

The ${pkgName} module to which ${filePath} belongs is configured incorrectly.

**Solution**

1. Make sure the ${pkgName} module is correctly configured in the ${filePath} file.
2. Make sure the file name is correct, including its case sensitivity.

## 10311003 Failed to Obtain the Kit Configuration File

**Error Message**

Kit `${moduleRequest}` has no corresponding config file in ArkTS SDK.

**Description**

The ${moduleRequest} kit does not have the corresponding configuration file in the ArkTS SDK.

**Possible Causes**

1. The APIs of the kit are inconsistent with those in the SDK.
2. The APIs of the kit are modified locally.

**Solution**

1. Make sure the kit API you are importing is consistent with the SDK version you are using, and the kit APIs are not modified locally.
2. For details about the kit APIs, see <!--RP1-->[API Reference Document Description](../development-intro-api.md).<!--RP1End-->

## 10311005 Incorrect Kit Identifier

**Error Message**

Identifier `${this.importName}` comes from `${this.symbol.source}` which can not be imported in .ts file.

**Description**

The identifier ${this.importName} comes from ${this.symbol.source}. This identifier cannot be imported to a .ts file.

**Possible Causes**

An ArkTS file of the kit is imported to the TS file.

**Solution**

Remove the import statement or change the file name extension to .ets.

## 10311006 Failed to Export Imported Names from the Kit

**Error Message**

`${importName}` is not exported from Kit `${KitInfo.getCurrentKitName()}`.

**Description**

Kit ${importName} is not exported from ${KitInfo.getCurrentKitName()}.

**Possible Causes**

1. The APIs of the kit are inconsistent with those in the SDK.
2. The APIs of the kit are modified locally.

**Solution**

1. Make sure the kit API you are importing is consistent with the SDK version you are using, and the kit APIs are not modified locally.
2. For details about the kit APIs, see <!--RP1-->[API Reference Document Description](../development-intro-api.md).<!--RP1End-->

## 10311007 Failed to Import or Export Kit Namespaces

**Error Message**

Namespace import or export of Kit is not supported currently.

**Description**

Currently, the namespace of a kit cannot be imported or exported.

**Possible Causes**

The file uses the namespace of the kit for import or export.

**Solution**

Replace the namespace import or export of the kit with a named import or export. Example: `import * as ArkTS from "@kit.ArkUI";` -> `import { AlertDialog } from "@kit.ArkUI";`;

## 10311008 Kit Empty Import Error

**Error Message**

Can not use empty import(side-effect import) statement with Kit `${(kitNode.moduleSpecifier as ts.StringLiteral).text.replace(/'|"/g, '')}`.

**Description**

Empty import (side-effect import) statements cannot be used in Kit `${(kitNode.moduleSpecifier as ts.StringLiteral).text.replace(/'|"/g, '')}`.

**Possible Causes**

The empty import (side-effect import) statement of the kit is used in the file.

**Solution**

Specify the symbol to be imported. Example: `import "@kit.ArkUI";` -> `import { lang } from "@kit.ArkUI";`

## 10311009 es2abc Execution Error

**Error Message**

Failed to execute es2abc.

**Description**

es2abc fails to be executed.

**Possible Causes**

An error occurred during the execution of es2abc.

**Solution**

Rectify the fault by referring to [es2abc Compiler Error Codes](./errorcode-es2abc.md).

## 10311010 Lazy Import Re-export Error

**Error Message**

`${elementText}` of lazy-import is re-export.

**Description**

The lazy import of ${elementText} is re-exported.

**Possible Causes**

The lazy-imported ${elementText} lazy-imported is exported again.

**Solution**

1. Make sure lazily loaded named bindings are not re-exported.
2. Check whether **autoLazyImport** is enabled.
