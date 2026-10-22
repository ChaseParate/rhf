#include "Title/MyChecker.hpp"

u32 Title::CMyChecker::_24(u32 arg) {
    mScene->fn_800925C0(arg, 0);
    return true;
}

u32 Title::CMyChecker::_28(u32 arg) {
    mScene->fn_800925C0(arg, 1);
    return true;
}

u32 Title::CMyChecker::_2C(void) {
    return true;
}

u32 Title::CMyChecker::_30(u32 arg) {
    mScene->fn_800925C0(arg, 2);
    return true;
}

Title::CMyChecker::~CMyChecker(void) {}

void Title::CMyChecker::_14(void) {
    this->~CMyChecker();
}
