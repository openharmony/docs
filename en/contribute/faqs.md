# FAQs<a name="EN-US_TOPIC_0000001053622377"></a>

[How Do I Create PRs at the Same Time If Multiple Code Repositories Have Compilation Dependencies?](#section169732563435)

[Sign-off-by Operations](#section-sign-off)

[Handling Exceptions of DCO Verification](#section-dco)

[Rollback](#section479422315253)

[Resolving Merge Conflicts](#section94417232274)

## How Do I Create PRs at the Same Time If Multiple Code Repositories Have Compilation Dependencies?<a name="section169732563435"></a>

During the development of the operating system \(OS\), it is common that multiple code repositories have compilation dependencies. Therefore, the PRs need to be created and merged at the same time. For this reason, Gitee uses issues as the association identifiers for code repositories with dependency dependencies to commit the PRs. Follow the operations below:

1. Create an issue in any of the code repositories.
2. Associate PRs need to be built and merged at the same time with the issue. For details, visit  [https://gitee.com/help/articles/4142](https://gitee.com/help/articles/4142).
3. After the build is triggered, the build center identifies the PRs associated with the same issue, downloads the build, and merges the PRs into the code library after the code is approved.

## Sign-off-by Operations<a name="section-sign-off"></a>

#### How to Add signoff Records in Commits?

Execute the **git commit -s **or **git commit –signo** command to submit signoff records.

#### How to Add a signoff record to the Previous Commit?

Execute the **git commit --amend --signoff** command.

For more options about commit, see [https://](https://git-scm.com/docs/git-commit)[git-scm.com/docs/git-commit](https://git-scm.com/docs/git-commit).

## Handling Exceptions of DCO Verification<a name="section-dco"></a>

After developers submit Pull Request, commenting "**start build**" in the PR will trigger the gated commit. In this sense, you should consider:

1. Whether the DCO is signed.
2. Whether the commits contain Signed-off-by information.

The possible causes for a verification failure include:

1. The DCO is not signed. The following messages will be displayed:

   ```
   The following commit users do not signed the DCO:

   •345612

   •213123
   ```

   **Solution**

   Click [https://dco.openharmony.io/sign/Z2l0ZWUlMkZvcGVuX2hhcm1vbnk=) to sign the DCO or check the signing status. 

   Enter **check dco** in the Pull Requests comment box and click **Comment**. The system will check the DCO signing status again.

2. The commits do not contain Signed-off-by information. The following messages will be displayed:

   ```
   The following commits do not contain Sign-off-by information:

   •345612

   •213123
   ```

   **Solution**

   Add the Sign-off-by information by referring to **Sign-off-by Operations**.

   Enter **check dco** in the Pull Requests comment box and click **Comment**. The system will check the DCO signing status again.

## Rollback<a name="section479422315253"></a>

Visit  [https://gitee.com/help/articles/4195](https://gitee.com/help/articles/4195).

## Resolving Merge Conflicts<a name="section94417232274"></a>

Visit  [https://gitee.com/help/articles/4194](https://gitee.com/help/articles/4194).

