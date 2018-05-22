# c99Demo01

A tiny repo to re-familiarize myself with the `C` programming language; specifically `C99`.

## TODO

  * Fix the following warning:
    ```
    /Applications/CLion.app/Contents/bin/cmake/bin/cmake --build /Users/longr049/CLionProjects/c99Demo01/cmake-build-debug --target c99Demo01 -- -j 4
    -- Configuring done
    -- Generating done
    -- Build files have been written to: /Users/longr049/CLionProjects/c99Demo01/cmake-build-debug
    Scanning dependencies of target c99Demo01
    [ 50%] Building C object CMakeFiles/c99Demo01.dir/src/main.c.o
    /Users/longr049/CLionProjects/c99Demo01/src/main.c:63:21: warning: result of comparison against a string literal is unspecified (use strncmp instead) [-Wstring-compare]
        if (myUser.name == "Suzy Programmer") {
                        ^  ~~~~~~~~~~~~~~~~~
    1 warning generated.
    [100%] Linking C executable c99Demo01
    [100%] Built target c99Demo01
    ```
  * Refactor inline x86 ASM into its own package in `src/pkg/asm`.

## License

Please see [LICENSE.md](LICENSE.md)