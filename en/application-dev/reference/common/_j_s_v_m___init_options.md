# JSVM_InitOptions


## Overview

Initialization option, which is used to initialize the JavaScript virtual machine.

**Since**: 11

Related module: [JSVM](_j_s_v_m.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| const intptr_t \* [externalReferences](#externalreferences) | In this case, the parameter is optional. An optional nullptr-terminated array of original addresses in the embedder that the virtual machine can match during serialization and can be used for deserialization. This array and its contents must remain valid throughout the lifecycle of the virtual machine instance. | 
| int \* [argc](#argc) | Specifies the flag of a VM. If removeFlags is true, the identified flags are removed from (argc, argv). Note that these flags are currently limited to V8 VMs. They are mainly used for development. Do not use them in a production environment, because if the virtual machine is different from the development environment, they may not take effect. | 
| char \*\* [argv](#argv) | argv .  | 
| bool [removeFlags](#removeflags) | Deletion flag. | 


## Member Variable Description


### argc

```
int* JSVM_InitOptions::argc
```
**Description**
Specifies the flag of a VM. If removeFlags is true, the identified flags are removed from (argc, argv). Note that these flags are currently limited to V8 VMs. They are mainly used for development. Do not use them in a production environment, because if the virtual machine is different from the development environment, they may not take effect.


### argv

```
char** JSVM_InitOptions::argv
```
**Description**
argv .


### externalReferences

```
const intptr_t* JSVM_InitOptions::externalReferences
```
**Description**
In this case, the parameter is optional. An optional nullptr-terminated array of original addresses in the embedder that the virtual machine can match during serialization and can be used for deserialization. This array and its contents must remain valid throughout the lifecycle of the virtual machine instance.


### removeFlags

```
bool JSVM_InitOptions::removeFlags
```
**Description**
Deletion flag.
