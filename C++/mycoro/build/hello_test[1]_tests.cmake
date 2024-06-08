add_test([=[PromiseErasedTest.YieldValueTest]=]  [==[/home/wujing/projects/Learn/C++/mycoro/build/hello_test]==] [==[--gtest_filter=PromiseErasedTest.YieldValueTest]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[PromiseErasedTest.YieldValueTest]=]  PROPERTIES WORKING_DIRECTORY [==[/home/wujing/projects/Learn/C++/mycoro/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  hello_test_TESTS PromiseErasedTest.YieldValueTest)
