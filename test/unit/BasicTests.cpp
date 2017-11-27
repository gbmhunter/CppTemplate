///
/// \file 			BasicTests.cpp
/// \author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
/// \created		2017-11-27
/// \last-modified 	2017-11-27
/// \brief			Basic tests for the Template class.
/// \details
///					See README.rst in repo root dir for more info.

// System includes
#include "gtest/gtest.h"

// 3rd party includes
#include "CppTemplate/Template.hpp"

// User includes
// nothing

using namespace mn::CppTemplate;

namespace {

    class BasicTests : public ::testing::Test {
    protected:

        BasicTests() {
        }

        virtual ~BasicTests() {
        }


    };

    TEST_F(BasicTests, Add) {
        Template myTemplate;
        EXPECT_EQ(3, myTemplate.Add(2, 1));
    }



}  // namespace