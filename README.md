# Stuff I Wrote Up While Reading K&R

## Fun Pieces I've Written So Far

Some stuff I wrote for fun to practice C alongside the code samples in K&R.

- [3D Spinning Cube] (tut/cube.c)

## Random Stuff To Add To Your `.bashrc` :)

```bash
# -------- C --------
# compile n exec
ccr() {
  local file
  file=$(fd -t f -e c | fzf) && gcc "$file" -o "${file%.*}.o" && "./${file%.*}.o"

  # NOTE: uncomment this line if you're using LLVM
  # file=$(fd -t f -e c | fzf) && clang "$file" -o "${file%.*}.o" && "./${file%.*}.o"
}

# clean up output files
cclr() {
  find . \( -name "*.o" -o -name "a.out" \) -type f -delete
}

# -------- C++ --------
# compile n exec
cppr() {
  local file
  file=$(fd -t f -e cpp -e cc -e cxx | fzf) && g++ "$file" -o "${file%.*}.o" && "./${file%.*}.o"

  # file=$(fd -t f -e cpp -e cc -e cxx | fzf) && clang++ "$file" -o "${file%.*}.o" && "./${file%.*}.o"
  # NOTE: uncomment this line if you're using LLVM
}

# clean up output files
cpplr() {
  find . \( -name "*.o" -o -name "a.out" \) -type f -delete
}

# -------- (not so) Useful Aliases --------
alias plz="sudo"                                # you know what this means
alias fucking="sudo"                            # same thing :p
alias lss="ls | xargs du -sh"                   # ls w/ stroage info
alias lssf="ls | xargs du -sh | rg"             # pipes lss into ripgrep
alias rlss="du -ah . | sort -hr | head -n 10"   # hidden files
```

Make sure either the [GNU Compiler Collection](https://www.gnu.org/) or the [LLVM Project](https://llvm.org/) is installed on your computer. This repo  mostly follows the `-std=c17` standard, with some exceptions in the `/projects` folder. Oh, and also install [fzf](https://github.com/junegunn/fzf) if it's somehow not already on your system! :D

Most scripts use the following `.clangd` configuration:

```yaml
CompileFlags:
  Add: [
    "-xc",          # files are .c
    "-std=c17",     # C17 standard
    "Iinclude",     # include the "include" directory
    "-Wall",        # warnings all
    "-Wextra"       # warnings extra
  ]
  Remove: [
    "-W*"           # get rid of warning flag conflicts
  ]

Index:
  Background: Build         # index project in bg

Diagnostics:
  UnusedIncludes: Strict    # highlight unused #include dirs

BasedOnStyle: LLVM          # llvm style

BreakBeforeBraces: Allman   # allman braces
```

Each folder has their respective `.clangd` file in case of changes.

## If You're Still Somehow Here

This repo is just a compilation of random .c programs I wrote as I trudged my way through K&R's ANSI edition. The organization matches that of the book. Some scripts are annotated examplars from the book, some are extra programs I wrote for fun.

There's a seperate projects folder for longer programs; these try to use C in a more practical setting. In general these don't fall into any of the discrete sections, and therefore are in a seperate `/projects` folder instead.

<img src="https://m.media-amazon.com/images/I/41a4XPmaCpL._SX342_SY445_ML2_.jpg" width="200">

**Reading this book was long overdue...ngl**
