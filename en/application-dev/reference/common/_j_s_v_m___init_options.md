# JSVM_InitOptions

## Overview

Initialization options for the JavaScript Virtual Machine.

**Starting Version:** 11

**Related Module:** [JSVM](_j_s_v_m.md)

## Summary

### Member Variables

| Name                                                       | Description                                                  |
| ---------------------------------------------------------- | ------------------------------------------------------------ |
| const intptr_t * [externalReferences](#externalreferences) | Optional. An array of raw addresses in the embedder, which is optional and terminated with a nullptr, that the virtual machine can match during serialization and can be used for deserialization. This array and its contents must remain valid for the entire lifetime of the virtual machine instance. |
| int * [argc](#argc)                                        | The flags of the virtual machine. If removeFlags is true, the recognized flags will be removed from (argc, argv). Please note that these flags are currently limited to the V8 virtual machine. They are mainly used for development. Do not use them in a production environment, as they may not work if the virtual machine is different from the development environment. |
| char ** [argv](#argv)                                      | The argument vector for the virtual machine.                 |
| bool [removeFlags](#removeflags)                           | Flag to remove recognized flags from (argc, argv).           |

## Description of Struct Member Variables

### argc

```
int* JSVM_InitOptions::argc
```
**Description**
The flags of the virtual machine. If removeFlags is true, the recognized flags will be removed from (argc, argv). Please note that these flags are currently limited to the V8 virtual machine. They are mainly used for development and should not be used in a production environment, as they may not function if the virtual machine differs from the development environment.

### argv

```
char** JSVM_InitOptions::argv
```
**Description**
The argument vector for the virtual machine.

### externalReferences

```
const intptr_t* JSVM_InitOptions::externalReferences
```
**Description**
Optional. An array of raw addresses in the embedder, terminated with a nullptr, that the virtual machine can match during serialization and can be used for deserialization. This array and its contents must remain valid for the entire lifetime of the virtual machine instance.

### removeFlags

```
bool JSVM_InitOptions::removeFlags
```
**Description**
A flag indicating whether to remove recognized flags from (argc, argv).