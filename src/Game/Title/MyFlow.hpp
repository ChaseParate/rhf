#ifndef GAME_TITLE_MYFLOW_HPP
#define GAME_TITLE_MYFLOW_HPP

#include <revolution/types.h>

#include "ExFlow.hpp"

#include "Title/SceneTitle.hpp"

#include "GameManager.hpp"

namespace Title {

class CMyFlow : public CExFlow {
public:
    virtual ~CMyFlow(void);
    virtual void _14(void);
    virtual bool _1C(u32 opcode, u32 arg0, const s32 *args);

    CMyFlow(const TickFlowCode *code, f32 initRest) :
        CExFlow(code, initRest)
    {
        mScene = gGameManager->getCurrentScene<CSceneTitle>();
    }

    TICKFLOW_DECL_CREATE_FN()

private:
    CSceneTitle *mScene;
};

} // namespace Title

#endif
