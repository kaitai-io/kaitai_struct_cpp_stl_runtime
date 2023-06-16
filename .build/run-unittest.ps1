<#
.DESCRIPTION
Runs unit tests on Windows
#>

# Standard boilerplate
Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"
$PSDefaultParameterValues['*:ErrorAction']='Stop'

# Go to repo root
$repoRoot = (Resolve-Path "$PSScriptRoot\..").Path
Push-Location $repoRoot

cd build

# Use ctest
#ctest -C Debug --output-on-failure

# Run gtest-generated binary directly, produces more detailed output
if (Test-Path './tests/Debug/unittest.exe') {
    ./tests/Debug/unittest.exe
} elseif (Test-Path './tests/unittest.exe') {
    ./tests/unittest.exe
} else {
    Write-Error "Unable to find the unittest executable."
    exit 1
}

Pop-Location
