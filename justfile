build-full dep-args="" pf-args="":
    just build-deps {{dep-args}}
    just build-printf {{pf-args}}

build-printf *pf-args:
    just setup-printf
    make {{pf-args}}

build-deps *dep-args:
    @echo "Building libft"
    mkdir -pv libft/
    rsync -av --exclude='*' --include-from='.dist-include' ext/lib/libft/ libft/
    make -C libft {{dep-args}}

setup-printf:
    premake5 gmake
    premake5 ecc

dist:
    @echo "Copying libft-files"
    mkdir -pv dist/libft
    rsync -av --exclude='*' --include-from='.dist-include' libft/ dist/libft
    rm -rfv dist/libft/README.md
    @echo "Copying src files for ft_printf"
    mkdir -pv dist/src
    rsync -av --exclude='*' --include-from='.dist-include' src/ dist/src
    @echo "Copying Makefile and README for ft_printf"
    rsync -av --exclude='*' --include-from='.dist-include' . dist/ 

fclean:
    make -f libft/Makefile fclean
    rm -rf libft/
    rm -rf obj/
    rm -rf bin/

fre dep-args="" pf-args="":
    fclean
    build-full {{dep-args}} {{pf-args}}
