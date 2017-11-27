///
/// \file 				Template.cpp
/// \author 			Geoffrey Hunter (www.mbedded.ninja) <gbmhunter@gmail.com>
/// \edited             n/a
/// \created			2017-11-27
/// \last-modified		2017-11-27
/// \brief 				Contains the Template class.
/// \details
///		See README.md in root dir for more info.

#include <cstdint>

#include "CppTemplate/Template.hpp"

namespace mn {
    namespace CppTemplate {

        uint32_t Template::Add(uint32_t num1, uint32_t num2) {
            return num1 + num2;
        }

    } // namespace CppTemplate
} // namespace mn