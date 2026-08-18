# Asset Store Kit Glossary

<!--Kit: Asset Store Kit-->
<!--Subsystem: Security-->
<!--Owner: @HarMonkey-->
<!--Designer: @wkr321_ent-->
<!--Tester: @nacyli-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=084bf627297e60b1f406ce34f5b473174466f7b3 translatedAt=2026-07-15T02:43:06.422Z pushedAt=2026-07-15T03:47:21.407Z -->

## A

### Asset

Short sensitive user data, such as passwords, tokens, and bank card numbers. Assets are written by services into the asset storage service and stored in ciphertext form in the Asset Store Kit database. Each asset consists of a plaintext, an alias, and multiple customizable additional attributes.

### AuthToken

A proof of user identity authentication issued by the unified user authentication framework. It is passed together with the [challenge](#challenge) when querying assets that require user authentication, to complete identity verification and authorize access to the asset.

## C

### Challenge

A random value returned by the [preQuery](../../reference/apis-asset-store-kit/js-apis-asset.md#assetprequery) API for user authentication.

## I

### Integrity Protection

A tamper-proof protection mechanism provided for certain attributes of assets (attributes whose names start with **DATA_LABEL_CRITICAL**). Attributes under integrity protection cannot be updated after being written, ensuring that they are not subject to unauthorized tampering.