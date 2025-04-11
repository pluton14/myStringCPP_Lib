#include "pybind11/pybind11.h"
#include "my_string.h"

using std::string;
namespace py = pybind11;
PYBIND11_MODULE(my_string, m){
	py::class_<my_string>(m, "my_string")
		.def(py::init())
		.def(py::init<const char*>())
		.def(py::init<const string&>())
		.def(py::init<const char*, int>())
		.def(py::init<int, char>())
		.def(py::init<my_string&>())

		.def("__add__", static_cast<my_string & (my_string::*)(const my_string&)>(&my_string::operator+), py::return_value_policy::reference)
		.def("__add__", static_cast<my_string & (my_string::*)(const char*)>(&my_string::operator+), py::return_value_policy::reference)
		.def("__add__", static_cast<my_string & (my_string::*)(const std::string&)>(&my_string::operator+), py::return_value_policy::reference)

		.def("__iadd__", static_cast<my_string & (my_string::*)(const my_string&)>(&my_string::operator+=), py::return_value_policy::reference)
		.def("__iadd__", static_cast<my_string & (my_string::*)(const char*)>(&my_string::operator+=), py::return_value_policy::reference)
		.def("__iadd__", static_cast<my_string & (my_string::*)(const string&)>(&my_string::operator+=), py::return_value_policy::reference)

		.def("__getitem__", static_cast<char& (my_string::*)(const int)>(&my_string::operator[]), py::return_value_policy::reference)

		.def("__eq__", static_cast<bool (my_string::*)(const my_string&)>(&my_string::operator==), py::return_value_policy::reference)
		.def("__ne__", static_cast<bool (my_string::*)(const my_string&)>(&my_string::operator!=), py::return_value_policy::reference)
		.def("__gt__", static_cast<bool (my_string::*)(const my_string&)>(&my_string::operator>), py::return_value_policy::reference)
		.def("__ge__", static_cast<bool (my_string::*)(const my_string&)>(&my_string::operator>=), py::return_value_policy::reference)
		.def("__lt__", static_cast<bool (my_string::*)(const my_string&)>(&my_string::operator<), py::return_value_policy::reference)
		.def("__le__", static_cast<bool (my_string::*)(const my_string&)>(&my_string::operator<=), py::return_value_policy::reference)
		.def("__getitem__", static_cast<char& (my_string::*)(const int)>(&my_string::operator[]), py::return_value_policy::reference)

		.def("c_str", &my_string::c_str)
		.def("data", &my_string::data)
		.def("__len__", &my_string::length)
		.def("length", &my_string::length)
		.def("size", &my_string::size)
		.def("empty", &my_string::empty)
		.def("capacity", &my_string::capacity)
		.def("shrink_to_fit", &my_string::shrink_to_fit)
		.def("clear", &my_string::clear)

		.def("__str__", &my_string::c_str) // operator<<
		.def("__repr__", &my_string::c_str) // operator>>

		.def("insert", static_cast<void (my_string::*)(int, int, char)>(&my_string::insert))
		.def("insert", static_cast<void (my_string::*)(int, const char*)>(&my_string::insert))
		.def("insert", static_cast<void (my_string::*)(int, const char*, int)>(&my_string::insert))
		.def("insert", static_cast<void (my_string::*)(int, const string&)>(&my_string::insert))
		.def("insert", static_cast<void (my_string::*)(int, const string&, int)>(&my_string::insert))

		.def("erase", &my_string::erase)

		.def("append", static_cast<void (my_string::*)(const int, const char)>(&my_string::append))
		.def("append", static_cast<void (my_string::*)(const char*)>(&my_string::append))
		.def("append", static_cast<void (my_string::*)(const char*, const int, const int)>(&my_string::append))
		.def("append", static_cast<void (my_string::*)(const string&)>(&my_string::append))
		.def("append", static_cast<void (my_string::*)(const string&, const int, const int)>(&my_string::append))

		.def("replace", static_cast<void (my_string::*)(const int, const int, const char*)>(&my_string::replace))
		.def("replace", static_cast<void (my_string::*)(const int, const int, const std::string&)>(&my_string::replace))

		.def("substr", static_cast<my_string & (my_string::*)(const int)>(&my_string::substr), py::return_value_policy::reference)
		.def("substr", static_cast<my_string & (my_string::*)(const int, const int)>(&my_string::substr), py::return_value_policy::reference)

		.def("find", static_cast<int(my_string::*)(const char*)>(&my_string::find))
		.def("find", static_cast<int(my_string::*)(const char*, const int)>(&my_string::find))
		.def("find", static_cast<int(my_string::*)(const string&)>(&my_string::find))
		.def("find", static_cast<int(my_string::*)(const string&, const int)>(&my_string::find));
}
