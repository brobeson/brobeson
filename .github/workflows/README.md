# Reusable Workflows

This repository contains a collection of reusable workflows.
See [GitHub's _Reusing workflows_ documentation](https://docs.github.com/en/actions/using-workflows/reusing-workflows) for complete details about how to use these workflows in your repositories.

## Support Files

This workflow ensures quality control of project support files.
These are files such as Markdown documentation, and JSON and YAML tool configuration files.

```yaml
name: Build & Test
on:
  workflow_dispatch:
  pull_request:
  push:
jobs:
  staticAnalysis:
    name: Code Quality
    uses: brobeson/brobeson/.github/workflows/support_files.yaml@main
```

This workflow ensures high quality project support files.
It runs these jobs:

### Spell Check

Run [CSpell](https://cspell.org/) on all files in the repository except your _.git/_ directory.
Use a [CSpell configuration](https://cspell.org/configuration/) in your repository to control the spell check behavior.

> [!NOTE]
> Add CSpell to your IDE to reduce the probability of this job finding errors.
> If you use [VS Code](https://code.visualstudio.com/), you can use the [Code Spell Checker extension](https://marketplace.visualstudio.com/items?itemName=streetsidesoftware.code-spell-checker).

<https://github.com/brobeson/brobeson/blob/1dbdbef3b0fe35b6586e9c05a661fc9263059643/.github/workflows/support_files.yaml#L13-L21>

### Lint

Run [Markdownlint](https://github.com/DavidAnson/markdownlint) on all Markdown files in the repository.

<https://github.com/brobeson/brobeson/blob/1dbdbef3b0fe35b6586e9c05a661fc9263059643/.github/workflows/support_files.yaml#L29-L34>

### Formatting

Run [Prettier](https://prettier.io) on all Markdown, YAML, JSON, and TypeScript files in the repository.

> [!IMPORTANT]
> This does not attempt to modify any files.
> It just reports incorrectly formatted files.

<https://github.com/brobeson/brobeson/blob/1dbdbef3b0fe35b6586e9c05a661fc9263059643/.github/workflows/support_files.yaml#L42-L47>
