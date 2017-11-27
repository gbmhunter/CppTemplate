///
/// \file 				main.cpp
/// \author 			Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
/// \edited             n/a
/// \created			2017-11-27
/// \last-modified		2017-11-27
/// \brief 				Contains the main entry point for the unit tests.
/// \details
///		See README.md in root dir for more info.

// System includes
#include "gtest/gtest.h"

// User includes
// nothing


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
  	return RUN_ALL_TESTS();
}