# Chinilla BIP158

![Build](https://github.com/Chinilla-Network/chinillabip158/workflows/Build/badge.svg)
![PyPI](https://img.shields.io/pypi/v/chinillabip158?logo=pypi)
![PyPI - Format](https://img.shields.io/pypi/format/chinillabip158?logo=pypi)
![GitHub](https://img.shields.io/github/license/Chinilla-Network/chinillabip158?logo=Github)

[![Total alerts](https://img.shields.io/lgtm/alerts/g/Chinilla-Network/chinillabip158.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/Chinilla-Network/chinillabip158/alerts/)
[![Language grade: Python](https://img.shields.io/lgtm/grade/python/g/Chinilla-Network/chinillabip158.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/Chinilla-Network/chinillabip158/context:python)
[![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/Chinilla-Network/chinillabip158.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/Chinilla-Network/chinillabip158/context:cpp)

This implements the compact block filter construction in BIP 158. The code is
not used anywhere in the Bitcoin Core code base yet. The next step towards
BIP 157 support would be to create an indexing module similar to TxIndex that
constructs the basic and extended filters for each validated block.

## Install

```bash
python3 -m venv venv
. venv/bin/activate
pip3 install .
```

## Run python tests

```bash
python3 tests/simple_test.py
```

## Installation steps on a fresh OSX image

Install brew:

```bash
ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"

brew install python3  
brew install boost  
```

At this point the only error is can’t find boost_thread lib

The issue is the homebrew boost ships libboost_thread-mt libs but doesn’t
include plain libboost_thread, so clang can’t find it. Interestingly, homebrew
boost does have both plain and -mt files for the libboost_system libraries.

```bash
$ find /usr/local/lib/ | grep boost_thread  
libboost_thread-mt.a  
libboost_thread-mt.dylib  
```

Solution, with no guarantees that this is "the Right Way to do things", but
appears to work fine for the configure stage:

```bash
cd /usr/local/lib  
ln -s libboost_thread-mt.a libboost_thread.a  
ln -s libboost_thread-mt.dylib libboost_thread.dylib  
```

## ci Building

The primary build process for this repository is to use GitHub Actions to
build binary wheels for MacOS, Linux (x64 and aarch64), and Windows and publish
them with a source wheel on PyPi. See `.github/workflows/build.yml`. CMake uses
[FetchContent](https://cmake.org/cmake/help/latest/module/FetchContent.html)
to download [pybind11](https://github.com/pybind/pybind11). Building is then
managed by [cibuildwheel](https://github.com/joerick/cibuildwheel). Further
installation is then available via `pip install chinillabip158` e.g.

## Contributing and workflow

Contributions are welcome and more details are available in chinilla-blockchain's
[CONTRIBUTING.md](https://github.com/Chinilla-Network/chinilla-blockchain/blob/master/CONTRIBUTING.md).

The master branch is usually the currently released latest version on PyPI.
Note that at times chinillabip158 will be ahead of the release version that
chinilla-blockchain requires in it's master/release version in preparation for a
new chinilla-blockchain release. Please branch or fork master and then create a
pull request to the master branch. Linear merging is enforced on master and
merging requires a completed review. PRs will kick off a GitHub actions ci
build and analysis of chinillabip158 at
[lgtm.com](https://lgtm.com/projects/g/Chinilla-Network/chinillabip158/?mode=list).
Please make sure your build is passing and that it does not increase alerts
at lgtm.
