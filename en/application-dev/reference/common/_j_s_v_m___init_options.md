# JSVM_InitOptions


## Overview

Options for initializing a JavaScript VM.

**Since**: 11

**Related module**: [JSVM](_j_s_v_m.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| const intptr_t \* [externalReferences](#externalreferences) | Optional. A raw address array with a nullptr at the end in the embedder, which can be matched by the VM during serialization and can be used for deserialization. This array and its contents must remain valid throughout the lifecycle of the VM instance. | 
| int \* [argc](#argc) | VM flag. If **removeFlags** is **true**, the identified flags are removed from (argc, argv). Note that these flags are now only available to V8 VMs. They are mainly used for development. Do not use them in the production environment because they may not take effect if the VM is different from the development environment. | 
| char \*\* [argv](#argv) | argv. | 
| bool [removeFlags](#removeflags) | Whether to remove flags. | 


## Member Variable Description


### argc

```
int* JSVM_InitOptions::argc
```
**Description**
VM flag. If **removeFlags** is **true**, the identified flags are removed from (argc, argv). Note that these flags are now only available to V8 VMs. They are mainly used for development. Do not use them in the production environment because they may not take effect if the VM is different from the development environment.


### argv

```
char** JSVM_InitOptions::argv
```
**Description**
argv.


### externalReferences

```
const intptr_t* JSVM_InitOptions::externalReferences
```
**Description**
Optional. A raw address array with a nullptr at the end in the embedder, which can be matched by the VM during serialization and can be used for deserialization. This array and its contents must remain valid throughout the lifecycle of the VM instance.


### removeFlags

```
bool JSVM_InitOptions::removeFlags
```
**Description**
Whether to remove flags.
