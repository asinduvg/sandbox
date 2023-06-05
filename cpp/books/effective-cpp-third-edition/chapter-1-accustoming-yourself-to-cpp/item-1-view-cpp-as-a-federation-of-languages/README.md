* C++ is a multiparadigm programming language
* Combination of procedural, object-oriented, functional, generic and metaprogramming features
* Consider C++ not as a single language, but as a federation of related languages
  * C - C++ is still based on C. Blocks, statements, the preprocessor, built-in data types, arrays, pointers etc
  * Object-Oriented C++ - C++ is what C with classess was all about: classes (including constructors and destructors). Encapsulation, inheritance, polymorphism, virtual functions (dynamic binding)
  * Template C++ - Generic programming part of C++. Template metaprogramming (TMP). Completely new programming paradigm
  * The STL - Template library

* Pass-by-value is shinning rather than pass-by-reference when it is used in:
  * Built-in (C-like) types
  * For iterators and function objects in STL (modeled on pointers in C)

* Pass-by-reference-to-const is shinning rather than pass-by-value when it is used in:
  * Object-oriented C++.
  * The existence of user-defined constructors and destructors