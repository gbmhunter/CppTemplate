///
/// \file 				Template.hpp
/// \author 			Geoffrey Hunter (www.mbedded.ninja) <gbmhunter@gmail.com>
/// \edited             n/a
/// \created			2017-11-27
/// \last-modified		2017-11-27
/// \brief 				Contains the Template class.
/// \details
///		See README.md in root dir for more info.

#ifndef MN_CPP_TEMPLATE_TEMPLATE_H_
#define MN_CPP_TEMPLATE_TEMPLATE_H_

// System includes
#include <cstdint>

namespace mn {
    namespace CppTemplate {

        /// \brief      A template class.
        class Template {


        public:

            /// \brief      Adds two numbers together.
            /// \param      num1    First number.
            /// \param      num2    Second number.
            /// \returns    The result of the addition.
            uint32_t Add(uint32_t num1, uint32_t num2);


        private:



        };
    } // namespace CppTemplate
} // namespace mn


#endif // MN_CPP_TEMPLATE_TEMPLATE_H_
