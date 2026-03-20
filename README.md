# Stuff I Wrote Up While Reading K&R

## Random Stuff To Add To Your `.bashrc` :)
```bash
# -------- C --------
ccr() {
  local file
  file=$(fd -t f -e c | fzf) && gcc "$file" -o "${file%.*}.o" && "./${file%.*}.o"
}

cclr() {
  find . \( -name "*.o" -o -name "a.out" \) -type f -delete
}

# -------- C++ --------
cppr() {
  local file
  file=$(fd -t f -e cpp -e cc -e cxx | fzf) && g++ "$file" -o "${file%.*}.o" && "./${file%.*}.o"
}

cpplr() {
  find . \( -name "*.o" -o -name "a.out" \) -type f -delete
}

alias plz="sudo"
alias fucking="sudo"
alias lss="ls | xargs du -sh"
alias lssf="ls | xargs du -sh | rg"
alias rlss="du -ah . | sort -hr | head -n 10"
```

Make sure either the [GNU Compiler Collection](https://www.gnu.org/) or the [LLVM Project](https://llvm.org/) is installed on your computer. This repo  mostly follows the `-std=c17` standard, with some exceptions in the `/projects` folder.

## If You're Still Somehow Here

This repo is just a compilation of random .c programs I wrote as I trudged my way through K&R's ANSI edition. The organization matches that of the book. Some scripts are close annotated examplars from the book, some are extra programs I wrote for fun.

There's a seperate projects folder for longer programs; these try to use C in a more practical setting.

<img src="https://m.media-amazon.com/images/I/41a4XPmaCpL._SX342_SY445_ML2_.jpg" width="200">

**Reading this book was long overdue...ngl**
