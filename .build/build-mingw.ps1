<#
.DESCRIPTION
Builds Kaitai Struct C++ runtime library and unit tests on Windows using MinGW

Requires:
- MinGW installed and available in the command prompt
- cmake/ctest available
- GTest installed, path passed in `-GTestPath`
#>

[CmdletBinding()]
param (
    [Parameter(Mandatory=$true)]
    [string] $GTestPath
)

# Standard boilerplate
Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"
$PSDefaultParameterValues['*:ErrorAction']='Stop'

# Go to repo root
$repoRoot = (Resolve-Path "$PSScriptRoot\..").Path
Push-Location $repoRoot

$null = New-Item build -ItemType Directory -Force
cd build

cmake -DCMAKE_PREFIX_PATH="$GTestPath" -DSTRING_ENCODING_TYPE=NONE -G "MinGW Makefiles" ..
cmake --build . --config Debug

# MinGW Makefiles build generates the following output:
#
# - build/libkaitai_struct_cpp_stl_runtime.dll
# - build/libkaitai_struct_cpp_stl_runtime.dll.a
# - build/tests/unittest.exe
#
# unittest.exe links dynamically against GTest DLLs and `libkaitai_struct_cpp_stl_runtime.dll`, and it
# will need all of them in same directory as .exe to run it, so we copy it.

cp $GTestPath\debug\bin\*.dll tests
cp libkaitai_struct_cpp_stl_runtime.dll tests\unittest.exe

Pop-Location
