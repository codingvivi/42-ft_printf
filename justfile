build *args:
    premake5 gmake
    make {{args}}
    rsync -av --include-from='.turnin-include' --exclude='*' . turnin/

turnin-sync:
    rsync -av --include-from='.turnin-include' --exclude='*' . turnin/
