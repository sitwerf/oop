add_test([=[NormalTemper.IntKnownValues]=]  [==[/Users/olesaagafonova/Documents/C++/oop/sem05/build/tests/tests_app]==] [==[--gtest_filter=NormalTemper.IntKnownValues]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[NormalTemper.IntKnownValues]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/Users/olesaagafonova/Documents/C++/oop/sem05/tests/test.cpp:5]==]
    WORKING_DIRECTORY [==[/Users/olesaagafonova/Documents/C++/oop/sem05/build/tests]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[NormalTemper.DoubleKnownValues]=]  [==[/Users/olesaagafonova/Documents/C++/oop/sem05/build/tests/tests_app]==] [==[--gtest_filter=NormalTemper.DoubleKnownValues]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[NormalTemper.DoubleKnownValues]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/Users/olesaagafonova/Documents/C++/oop/sem05/tests/test.cpp:12]==]
    WORKING_DIRECTORY [==[/Users/olesaagafonova/Documents/C++/oop/sem05/build/tests]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[ModifiedTemper.ResultInRange]=]  [==[/Users/olesaagafonova/Documents/C++/oop/sem05/build/tests/tests_app]==] [==[--gtest_filter=ModifiedTemper.ResultInRange]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[ModifiedTemper.ResultInRange]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/Users/olesaagafonova/Documents/C++/oop/sem05/tests/test.cpp:19]==]
    WORKING_DIRECTORY [==[/Users/olesaagafonova/Documents/C++/oop/sem05/build/tests]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[FailDemo.ExpectContinues]=]  [==[/Users/olesaagafonova/Documents/C++/oop/sem05/build/tests/tests_app]==] [==[--gtest_filter=FailDemo.DISABLED_ExpectContinues]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[FailDemo.ExpectContinues]=]
  PROPERTIES
    DISABLED YES
    DEF_SOURCE_LINE [==[/Users/olesaagafonova/Documents/C++/oop/sem05/tests/test.cpp:29]==]
    WORKING_DIRECTORY [==[/Users/olesaagafonova/Documents/C++/oop/sem05/build/tests]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[FailDemo.AssertStops]=]  [==[/Users/olesaagafonova/Documents/C++/oop/sem05/build/tests/tests_app]==] [==[--gtest_filter=FailDemo.DISABLED_AssertStops]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[FailDemo.AssertStops]=]
  PROPERTIES
    DISABLED YES
    DEF_SOURCE_LINE [==[/Users/olesaagafonova/Documents/C++/oop/sem05/tests/test.cpp:36]==]
    WORKING_DIRECTORY [==[/Users/olesaagafonova/Documents/C++/oop/sem05/build/tests]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
set(tests_app_TESTS [==[NormalTemper.IntKnownValues]==] [==[NormalTemper.DoubleKnownValues]==] [==[ModifiedTemper.ResultInRange]==] [==[FailDemo.ExpectContinues]==] [==[FailDemo.AssertStops]==])
