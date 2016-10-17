/*
   _____ __                                    __  ___                            __ 
  / ___// /_____  _________ _____ ____        /  |/  /___  ____ _____ ___  ____  / /_
  \__ \/ __/ __ \/ ___/ __ `/ __ `/ _ \______/ /|_/ / __ \/ __ `/ __ `__ \/ __ \/ __/
 ___/ / /_/ /_/ / /  / /_/ / /_/ /  __/_____/ /  / / / / / /_/ / / / / / / / / / /_  
/____/\__/\____/_/   \__,_/\__, /\___/     /_/  /_/_/ /_/\__, /_/ /_/ /_/_/ /_/\__/  
                          /____/                        /____/                       

		Author: Nick Dekker

		Unit test.
*/

#include "../src/ConfigFactory.hxx"

#include "../lib/gtest/includes/gtest/gtest.h"

// Test empty input of config file json
TEST(ConfigParseTest, HandlesEmptyInput) {
  EXPECT_EQ(nullptr, parseModuleJson(json));
}
