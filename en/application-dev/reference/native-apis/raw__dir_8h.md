# raw_dir.h


## Overview

Provides functions for operating rawfile directories.

These functions include traversing and closing rawfile directories.

**Since:**
8

**Related Modules:**

[Rawfile](rawfile.md)


## Summary


### Types

| Name | Description | 
| -------- | -------- |
| [RawDir](rawfile.md#rawdir) | Provides the function of accessing rawfile directories.  | 


### Functions

| Name | Description | 
| -------- | -------- |
| [OH_ResourceManager_GetRawFileName](rawfile.md#oh_resourcemanager_getrawfilename) ([RawDir](rawfile.md#rawdir) \*rawDir, int index) | Obtains the rawfile name via an index.  | 
| [OH_ResourceManager_GetRawFileCount](rawfile.md#oh_resourcemanager_getrawfilecount) ([RawDir](rawfile.md#rawdir) \*rawDir) |Obtains the number of rawfiles in [RawDir](rawfile.md#rawdir).  | 
| [OH_ResourceManager_CloseRawDir](rawfile.md#oh_resourcemanager_closerawdir) ([RawDir](rawfile.md#rawdir) \*rawDir) | Closes an opened [RawDir](rawfile.md#rawdir) and releases all associated resources.  | 
