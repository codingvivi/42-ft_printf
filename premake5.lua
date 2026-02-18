require "ext/build/premake-ecc/ecc"

workspace "42-ft_printf Workspace"
    configurations {"Release", "Debug"}
    platforms { "Dev", "42" }
    toolset "clang"

    buildoptions {"-Wall", "-Werror", "-Wextra"}

    filter "platforms:Dev"
        architecture "ARM64"
        system "linux"

    filter "platforms:42"
        architecture "x86_64"
        system "linux"
        buildoptions { "--target=x86_64-linux-gnu" }
        linkoptions { "--target=x86_64-linux-gnu", "-fuse-ld=lld" }

    filter "configurations:Debug"
        buildoptions {"-g"}

project "42-ft_printf"
    kind "StaticLib"
    language "C"

    -- Update paths to the new subdirectory
    files {
        "src/*.c",
        "src/*.h",
        "libft/libft.a"
    }

    -- so the library itself can find its own header
    includedirs { "src" }

-- project "test_runner"
--     kind "ConsoleApp"
--     language "C"

--     files { "tests/main.c" }

--     -- allows main.c to use #include "get_next_line.h"
--     includedirs { "src" }
--     links { "42-ft_printf" }


