granska
=======

The KTH text scrutinizer Granska

## Credits & Sources
### 1. Software Engines

####    Granska (Grammar Checker): Originally developed at KTH (NADA/TCS) by Jonas Bigert, Ola Knutsson, and Viggo Kann.

        Original Source: 
        ```@inproceedings{granska, author = {Richard Domeij and Ola Knutsson and Johan Carlberger and Viggo Kann}, title = {Granska -- an efficient hybrid system for {Swedish} grammar checking}, booktitle = "Proceedings of Nodalida '99", pages = {49--56}, address = "Trondheim, Norway", year = "2000"} ```
        https://www.csc.kth.se/tcs/projects/granska/

####    Stava (Spellchecker): A high-performance Swedish spellchecker based on Bloom filters and suffix rules, developed by Viggo Kann.

        Original Source: 
        ```@article{stava, title={Detection of spelling errors in {Swedish} not using a word list en clair}, author={Rickard Domeij and Joachim Hollman and Viggo Kann}, journal={Journal of Quantitative Linguistics}, volume="1", pages="195--201", year=1994 } ```
        https://skrutten.csc.kth.se/tools/

        Codebase forked from: https://github.com/viggokann/granska

### 2. Linguistic Data Files

#### The logic in this repository relies on the following data files provided by the original authors, from https://skrutten.csc.kth.se/tools/:

- Swedish Rules (https://skrutten.csc.kth.se/tools/src/rulesForGrammarChecking and https://skrutten.csc.kth.se/tools/src/rulesForParsing): A comprehensive set of deterministic and probabilistic Swedish grammar rules.

- Tag Lexicon (https://skrutten.csc.kth.se/tools/src/lex.tar.gz): Tagger data based on the SUC (Stockholm-Umeå Corpus) tagset.

- Stava Lexicons (https://skrutten.csc.kth.se/tools/src/GPLstava_lib.tgz): Core Swedish suffix rules and word lists.

- Representatives (https://skrutten.csc.kth.se/tools/src/repr.ptt).

# 3. Modifications

#### To make this legacy codebase run on modern systems and prepare it for Android deployment, the following changes were implemented:

- 64-bit Architecture Support: Patched numerous pointer-to-integer truncations in tagger/, scrut/, and prob/ modules. Replaced unsafe (int) and (long) casts with intptr_t and uintptr_t.

- Xerces-C++ Dependency Removal: Stripped heavy Apache Xerces XML dependencies via -DNO_XML_SUPPORT and -DNO_ANNOT_FROM_FILE to allow for lightweight static linking.

- Modern C++ Compliance: Resolved strcmp namespace issues, fixed misleading indentation warnings, and updated string literal handling to satisfy G++ 14+ standards.

- Binary Pointer Fixes: Modified lexicon.cpp and morfs.cpp to correctly handle 8-byte pointer offsets in .fast binary files.

- Fixed the encoding of various data files

# 4. License

As the original source components are licensed under the GNU General Public License (GPL), this modernized version is also released under GPLv2 (or later).
