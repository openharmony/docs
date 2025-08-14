# Rdb_DataObserver

## Overview

Defines a struct for the data observer.

**Since**: 11

**Related module**: [RDB](capi-rdb.md)

**Header file**: [relational_store.h](capi-relational-store-h.md)

## Summary

### Member Variables

| Name                                                        | Description                    |
| ------------------------------------------------------------ | ------------------------ |
| void* context                                                | Pointer to the context of the data observer.|
| [Rdb_SubscribeCallback](capi-rdb-rdb-subscribecallback.md) callback | Callback used to return the result.      |
