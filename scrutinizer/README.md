# Building and running

To compile this project (development and build performed on Void Linux x86-64), ensure the development tools, dependencies and optionally the cross-compilation toolchain for ARM64 are installed:

```bash

sudo xbps-install -S base-devel flex bison cross-x86_64-linux-musl cross-aarch64-linux-musl


```

Build Instructions

Two dedicated shell scripts are provided to facilitate the build process. Ensure these scripts have execution permissions (chmod +x <script_name>) before running.

### 1. Native Build (Host)

Compiles the scrutinizer command-line utility and the libgranska.a static library for x86_64 (statically linked with musl libc).

```bash

./make-x86_64-static

```

### 2. ARM64 Build (Cross-Compilation, static linking of musl, suitable for Android NDK)

Compiles the scrutinizer command-line utility and the libgranska.a static library for aarch64 (statically linked with musl libc).

```bash

./make-aarch64-static

```


## Example run:

```bash
STAVA_LEXICON=data/lib/ TAGGER_LEXICON=data/lex SCRUTINIZER_RULE_FILE=data/swedish.rule ./scrutinizer -Cr data/repr.ptt -s input.txt


### Important notice: Granska expects input files to be encoded in LATIN-1 (ISO-8859-1).
