# Programming Style & Standard

## Style

### Use active voice.

When writing documentation, Git commits, etc., prefer active voice.
There are occasions when passive voice is more concise that active voice, but use active voice for most sentences.

```markdown
When the Start button is clicked by the user...  <!-- poor -->

When the user clicks the Start button...         <!-- good -->
```

### Use imperative sentences.

When writing documetation, Git commits, etc., use [imperative sentences](https://www.grammarly.com/blog/sentences/imperative-sentences/).

```c++
/// \brief This function adds two vectors together.   (poor)
vec3 operator+(const vec3& v, const vec3& w);
  
/// \brief Add two vectors.                           (good)
vec3 operator+(const vec3& v, const vec3& w);
```

```md
1. The developer should run `cmake --build .` to build the software.  <!-- poor -->

1. Run `cmake --build .` to build the software.                       <!-- good -->
```

### Use a spell checker.

Spell checkers exist for source code.
My preferred tool is [CSpell](https://cspell.org/), but any spell checker should work.

> [!important]
> Spell checking isn't just about typos in documentation.
> I've actually found bugs by running a spell checker at work.

### Use formatting tools

Ensure consistent formatting with tool automation.

| Tool | Language |
| :------- | :--- |
| [clang-format](https://clang.llvm.org/docs/ClangFormat.html) | C++ |
| [shfmt](https://webinstall.dev/shfmt/) | Bash scripts |
| [Prettier](https://prettier.io/) | JSON, Markdown, YAML |

### Case

Follow industry standards for a particular language or technology.
Some examples are

- Bash scripts: `UPPER_SNAKE_CASE`
- Python: Follow [PEP 8](https://peps.python.org/pep-0008/)
- CMake: `UPPER_SNAKE_CASE` for variables and `lower_snake_case` for functions & macros

## Documentation

1. Prefer Markdown.
   ReStructured text and ASCII Doc are OK when necessary.
1. Write one sentence per line.
   This makes diffs easier to review because whole paragraphs don't reflow.

## C++

### Adhere to the [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines).

### Document linter suppressions.

Document inline static and dynamic analysis suppressions with a comment.
The comment must explain why the suppression is necessary.

- Poor
  ```c++
  enum class color {
    // 100 color enumerators...
  };
  std::string to_string(const color c) {
    // #lizard-forgives
    switch (c) {
      // 100 case statements...
    }
  }
  ```
- Good
  ```c++
  enum class color {
    // 100 color enumerators...
  };
  std::string to_string(const color c) {
    // #lizard-forgives
    // There aren't other implementations that reduce
    // the cyclomatic complexity. Also, each case is
    // short and easy to read.
    switch (c) {
      // 100 case statements...
    }
  }
  ```

### Limit the scope of inline suppressions

Limit the checks that a suppression applies to and limit the code that a suppression applies to.

- Poor - This suppresses all clang-tidy checks on the suppressed line.
  ```c++
  void call_a_c_function(const std::string& s) {
    c_function(s.c_str(), s.size());  // NOLINT
  }
  ```
- Poor - This suppresses checks for an entire function.
  ```c++
  // NOLINTBEGIN
  void call_c_function(const std::string& s) {
    c_function(s.c_str(), s.size());
  }
  // NOLINTEND
- Good - This limits the suppression to one specifici issue.
  ```c++
  void call_c_functon(const std::string& s) {
    // NOLINTNEXTLINE(cppcoreguidelines-avoid-pointer-arithmetic)
    c_function(s.c_str(), s.size());
  }
  ```
