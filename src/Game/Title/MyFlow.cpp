#include "Title/MyFlow.hpp"

#include "Title/MyFlowDecl.hpp"

#include "Title/MyChecker.hpp"
#include "Title/MyLayoutF.hpp"
#include "Title/MyLayoutT.hpp"

#include "InputCheckManager.hpp"
#include "LayoutManager.hpp"

TICKFLOW_IMPL_CREATE_FN(Title::CMyFlow)

Title::CMyFlow::~CMyFlow(void) {}

bool Title::CMyFlow::_1C(u32 opcode, u32 arg0, const s32 *args) {
    switch (opcode) {
    case TF_TITLE_200: {
        CMyChecker *checker = gInputCheckManager->makeNew<CMyChecker>();
        gInputCheckManager->fn_801E9158(checker, true);
    } break;

    case TF_TITLE_201: {
        gLayoutManager->getLayout<CMyLayoutT>(0)->playAnimFromBeginForward(args[0]);
    } break;

    case TF_TITLE_202: {
        if (arg0 == 0) {
            mScene->showTitleGirl();
        } else if (arg0 == 1) {
            mScene->playTitleGirlAnim(static_cast<u16>(args[0]));
        }
    } break;

    case TF_TITLE_203: {
        if (arg0 == 0) {
            mCondvar = mScene->unk34;
        }
    } break;

    case TF_TITLE_204: {
        if (arg0 == 0) {
            mScene->unk94 = args[0] != 0;
        }
    } break;

    default:
        return this->CExFlow::_1C(opcode, arg0, args);
    }

    return false;
}

void Title::CMyFlow::_14(void) {
    this->~CMyFlow();
}
