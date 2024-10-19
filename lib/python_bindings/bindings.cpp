#include <pybind11/pybind11.h>
#include "../src/gtcv_objects.h"
#include "../src/gtcv_signal.h"

namespace py = pybind11;

PYBIND11_MODULE(gtcv, m) {
    m.attr("GTCV_API_VERSION_MAJOR") = GTCV_API_VERSION_MAJOR; 
    m.attr("GTCV_API_VERSION_MINOR") = GTCV_API_VERSION_MINOR;
    m.attr("GTCV_API_VERSION_PATCH") = GTCV_API_VERSION_PATCH;
    m.attr("GTCV_API_VERSION") = GTCV_API_VERSION;

    py::class_<Signal>(m, "Signal")
        .def(py::init<>())
        .def("init", &signal_init)
        .def("free", &free_signal)
        .def("expand_slots", &expand_slots)
        .def("connect_slot", &connect_slot)
        .def("disconnect_slot", &disconnect_slot)
        .def("emit_signal", &emit_signal);
}