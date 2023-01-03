#include "MyStack.h"
#include <iostream>
#include <gtest/gtest.h>

struct MyStackTestFrontBackParam {
    std::list<int> stacka;
    std::list<int> stackb;
    int result;
};

struct MyStackTestLParam {
    std::list<int> stacka;
    std::list<int> stackb;
    std::list<int> result;
};


/*TEST DE FRONT ET BACK*/

class MyStackTestFrontP:public ::testing::TestWithParam<MyStackTestFrontBackParam>{};

TEST_P(MyStackTestFrontP, TestFront){
    MyStackTestFrontBackParam params = GetParam();

    MyStack stack;
    stack.setMyStackA(params.stacka);
    EXPECT_EQ(stack.front_a(), params.result);

    stack.setMyStackB(params.stacka);
    EXPECT_EQ(stack.front_b(), params.result);

}


INSTANTIATE_TEST_SUITE_P(
    MyStackTests, MyStackTestFrontP,
    ::testing::Values(
        MyStackTestFrontBackParam{
            std::list<int> ({1, 2, 3}),
            std::list<int> ({1, 2, 3}),
            1
        },
         MyStackTestFrontBackParam{
            std::list<int> ({1}),
            std::list<int> ({2}),
            1
        },
        MyStackTestFrontBackParam{
            std::list<int> ({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}),
            std::list<int> ({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}),
            1
        },
        MyStackTestFrontBackParam{
            std::list<int> ({}),
            std::list<int> ({}),
            0 // DEVRA RETOURNER UNE EXCEPTION
        }
    )
);

class MyStackTestBackP:public ::testing::TestWithParam<MyStackTestFrontBackParam>{};

TEST_P(MyStackTestBackP, TestFront){
    MyStackTestFrontBackParam params = GetParam();

    MyStack stack;
    stack.setMyStackA(params.stacka);
    EXPECT_EQ(stack.back_a(), params.result);

    stack.setMyStackA(params.stackb);
    EXPECT_EQ(stack.back_b(), params.result);

}


INSTANTIATE_TEST_SUITE_P(
    MyStackTests, MyStackTestBackP,
    ::testing::Values(
        MyStackTestFrontBackParam{
            std::list<int> ({1, 2, 3}),
            std::list<int> ({1, 2, 3}),
            3
        },
         MyStackTestFrontBackParam{
            std::list<int> ({1}),
            std::list<int> ({2}),
            1
        },
        MyStackTestFrontBackParam{
            std::list<int> ({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}),
            std::list<int> ({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}),
            10
        },
        MyStackTestFrontBackParam{
            std::list<int> ({}),
            std::list<int> ({}),
            0 // DEVRA RETOURNER UNE EXCEPTION
        }
    )
);

/*TEST DE SWITCH, PUT, REVERT, REVERT REVERT*/

class MyStackTestSaP:public ::testing::TestWithParam<MyStackTestLParam>{};

TEST_P(MyStackTestSaP, TestFront){
    MyStackTestLParam params = GetParam();

    MyStack stack;
    stack.setMyStackA(params.stacka);
    EXPECT_EQ(stack.sa(), params.result);

    stack.setMyStackA(params.stackb);
    EXPECT_EQ(stack.sb(), params.result);

}


INSTANTIATE_TEST_SUITE_P(
    MyStackTests, MyStackTestBackP,
    ::testing::Values(
        MyStackTestLParam{
            std::list<int> ({1, 2, 3}),
            std::list<int> ({1, 2, 3}),
            std::list<int> ({2, 1, 3})
            
        },
         MyStackTestLParam{
            std::list<int> ({1}),
            std::list<int> ({2}),
            std::list<int> ({2, 1, 3})
        },
        MyStackTestLParam{
            std::list<int> ({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}),
            std::list<int> ({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}),
            std::list<int> ({2, 1, 3, 4, 5, 6, 7, 8, 9, 10})
        },
        MyStackTestLParam{
            std::list<int> ({}),
            std::list<int> ({}),
            std::list<int> ({}) // DEVRA RETOURNER UNE EXCEPTION
        }
    )
);
