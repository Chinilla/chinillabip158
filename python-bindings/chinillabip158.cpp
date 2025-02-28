// Copyright 2018 Chinilla Network Inc

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//    http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/operators.h>

#include "PyBIP158.h"

namespace py = pybind11;

PYBIND11_MODULE(chinillabip158, mod) {
    py::class_<PyBIP158, std::shared_ptr<PyBIP158>> clsPyBIP158(mod, "PyBIP158");
    
    clsPyBIP158.def(py::init<std::vector< std::vector< unsigned char > >&>());
    clsPyBIP158.def(py::init< std::vector< unsigned char > &>());
    clsPyBIP158.def("GetEncoded",(const std::vector< unsigned char >& (PyBIP158::*)()) &PyBIP158::GetEncoded);
    clsPyBIP158.def("Match", (bool (PyBIP158::*)(std::vector< unsigned char >&)) &PyBIP158::Match);
    clsPyBIP158.def("MatchAny", (bool (PyBIP158::*)(std::vector< std::vector< unsigned char > >&)) &PyBIP158::MatchAny);
}
