# This script requires at least PowerShell 7.4 to run, as it relies on support
# for the `$PSNativeCommandUseErrorActionPreference` variable for proper error
# handling.
#Requires -Version 7.4

<#
.DESCRIPTION
Builds Kaitai Struct C++ runtime library and unit tests

Requires:
- PowerShell 7.4 or later
- MSVC native tools installed and available in the command prompt
- cmake/ctest available (normally installed with MSVC native tools)
- GTest installed, path passed in `-GTestPath`
#>

[CmdletBinding(PositionalBinding=$false)]
param (
    [Parameter(Mandatory=$true)]
    [string] $GTestPath,

    [Parameter(Mandatory=$false)]
    [string] $EncodingType = "WIN32API",

    [Parameter(ValueFromRemainingArguments=$true)]
    [string[]] $ExtraArgs
)

# Standard boilerplate
Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'
$PSDefaultParameterValues['*:ErrorAction'] = 'Stop'
# Treat non-zero exit codes from native commands as standard PowerShell errors.
$PSNativeCommandUseErrorActionPreference = $true

# Go to repo root
$repoRoot = (Resolve-Path "$PSScriptRoot\..").Path
Push-Location $repoRoot

try {
    $null = New-Item -Path build -ItemType Directory -Force
    cd build

    $env:VERBOSE = '1'
    cmake -DCMAKE_PREFIX_PATH="$GTestPath" -DSTRING_ENCODING_TYPE="$EncodingType" .. @ExtraArgs
    cmake --build . --config Debug
    cp $GTestPath\debug\bin\*.dll tests\Debug
    cp Debug\kaitai_struct_cpp_stl_runtime.dll tests\Debug
} finally {
    Pop-Location
}
