build-deps *dep-args:
    @echo "Building libft"
    rsync -av --include-from='.dist-include' --exclude='*' ext/lib/libft/ libft/
    make -f libft/Makefile  {{dep-args}}

build-printf *pf-args:
    premake5 gmake
    make {{pf-args}}

build-full dep-args="" pf-args="":
    build-deps {{dep-args}}
    build-printf {{pf-args}}

dist:
    @echo "Copying libft-files"
    rsync -av --include-from='.dist-include' --exclude='*' libft/ dist/libft
    rm -rf dist/libft/README.md
    @echo "Copying src files for ft_printf"
    rsync -av --include-from='.dist-include' --exclude='*' src/ dist/src
    @echo "Copying Makefile and README for ft_printf"
    rsync -av --include-from='.dist-include' --exclude='*' . dist/ 

fclean:
    make -f libft/Makefile fclean
    rm -rf libft/
    rm -rf obj/
    rm -rf bin/

fre dep-args="" pf-args="":
    fclean
    build-full {{dep-args}} {{pf-args}}
