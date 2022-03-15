# Overview of Distributed Call Chain Tracing

hiTraceChain is a lightweight implementation of the cloud-based distributed call chain tracing. It allows applications to trace cross-thread, cross-process, and cross-device service calls.

## Basic Concepts

- **chainId**

  Distributed call chain tracing ID, which is a part of **HiTraceId** and is used to identify the service process being traced.

## Working Principles

The hiTraceChain module generates a unique **chainId** for a service process and passes it to various information (including application events, system time, and logs) specific to the service process. During debugging and fault locating, you can use the unique **chainId** to quickly correlate various information related to the service process.

## Constraints

All APIs provided by the hiTraceChain module work in synchronous mode.
