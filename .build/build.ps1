<#
.DESCRIPTION
Builds Kaitai Struct C++ runtime library and unit tests

Requires:
- MSVC native tools installed and available in the command prompt
- cmake/ctest available (normally installed with MSVC native tools)
- GTest installed, path passed in `-GTestPath`
#>

[CmdletBinding()]
param (
    [Parameter(Mandatory=$true)]
    [string] $GTestPath,
    [Parameter(Mandatory=$false)]
    [string] $EncodingType = "WIN32API"
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

cmake -DCMAKE_PREFIX_PATH="$GTestPath" -DSTRING_ENCODING_TYPE="$EncodingType" ..
cmake --build . --config Debug
cp $GTestPath\debug\bin\*.dll tests\Debug
cp Debug\kaitai_struct_cpp_stl_runtime.dll tests\Debug

Pop-Location
