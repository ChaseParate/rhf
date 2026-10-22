#ifndef NW4R_LYT_MATERIAL_H
#define NW4R_LYT_MATERIAL_H

#include <revolution/types.h>
#include <revolution/GX.h>
#include <nw4r/lyt/types.h>
#include <nw4r/ut/Color.h>
#include <nw4r/db/assert.h>

namespace nw4r {
namespace lyt {

namespace detail {

struct BitGXNums {
    u32 texMap:4;
    u32 texSRT:4;
    u32 texCoordGen:4;
    u32 indSRT:2;
    u32 indStage:2;
    u32 tevSwap:1;
    u32 tevStage:5;
    u32 chanCtrl:1;
    u32 matCol:1;
    u32 alpComp:1;
    u32 blendMode:1;
};

} // namespace detail

class TexMap {
public:
    TexMap() {
        SetImage(NULL);
        SetSize(0, 0);
        SetTexelFormat(GX_TF_I4);
        SetWrapMode(GX_CLAMP, GX_CLAMP);
        SetMipMap(false);
        SetFilter(GX_LINEAR, GX_LINEAR);
        SetLOD(0.0f, 0.0f);
        SetLODBias(0.0f);
        SetBiasClampEnable(false);
        SetEdgeLODEnable(false);
        SetAnisotropy(GX_ANISO_1);
        SetPalette(NULL);
        SetPaletteFormat(GX_TL_IA8);
        SetPaletteEntryNum(0);
    }

    explicit TexMap(const GXTexObj& texObj) {
        Set(texObj);
        SetPalette(NULL);
        SetPaletteFormat(GX_TL_IA8);
        SetPaletteEntryNum(0);
    }

    void Set(const GXTexObj& texObj);

    void SetImage(void *image) { mImage = image; }
    void SetPalette(void *palette) { mPalette = palette; }
    void SetSize(u16 width, u16 height) {
        mWidth = width;
        mHeight = height;
    }
    void SetLOD(f32 minLOD, f32 maxLOD) {
        mMinLOD = minLOD;
        mMaxLOD = maxLOD;
    }
    void SetLODBias(f32 bias) { mLODBias = static_cast<u16>(bias * 256.0f); }
    void SetPaletteEntryNum(u16 entryNum) { mPaletteEntryNum = entryNum; }
    void SetTexelFormat(GXTexFmt format) { mBits.textureFormat = format; }
    void SetMipMap(bool mipmap) { mBits.mipmap = mipmap; }
    void SetWrapMode(GXTexWrapMode wrapS, GXTexWrapMode wrapT) {
        mBits.wrapS = wrapS;
        mBits.wrapT = wrapT;
    }
    void SetFilter(GXTexFilter minFilter, GXTexFilter magFilter) {
        mBits.minFilter = minFilter;
        mBits.magFilter = magFilter;
    }
    void SetBiasClampEnable(bool enable) { mBits.biasClampEnable = enable; }
    void SetEdgeLODEnable(bool enable) { mBits.edgeLODEnable = enable; }
    void SetAnisotropy(GXAnisotropy anisotropy) { mBits.anisotropy = anisotropy; }
    void SetPaletteFormat(GXTlutFmt format) { mBits.paletteFormat = format; }

private:
    void *mImage;
    void *mPalette;
    u16 mWidth;
    u16 mHeight;
    f32 mMinLOD;
    f32 mMaxLOD;
    u16 mLODBias;
    u16 mPaletteEntryNum;
    struct {
        u32 textureFormat : 4;
        u32 mipmap : 1;
        u32 wrapS : 2;
        u32 wrapT : 2;
        u32 minFilter : 3;
        u32 magFilter : 1;
        u32 biasClampEnable : 1;
        u32 edgeLODEnable : 1;
        u32 anisotropy : 2;
        u32 paletteFormat : 2;
    } mBits;
};

class Material {
public:
    virtual ~Material();

    const TexMap &GetTexMap(u8 texMapIdx) const {
        NW4R_ASSERT(texMapIdx < mGXMemNum.texMap, 121);
        return GetTexMapAry()[texMapIdx];
    }
    void SetTexMap(u8 texMapIdx, const TexMap &texMap) {
        NW4R_ASSERT(texMapIdx < mGXMemNum.texMap, 136);
        GetTexMapAry()[texMapIdx] = texMap;
    }

    nw4r::lyt::TexMap *GetTexMapAry();
    const nw4r::lyt::TexMap *GetTexMapAry() const;

protected:
    ut::LinkList<AnimationLink, offsetof(AnimationLink, mLink)> mAnimList;
    GXColorS10 mTevCols[3];
    ut::Color mTevKCols[4];
    detail::BitGXNums mGXMemCap;
    detail::BitGXNums mGXMemNum;
    void *mpGXMem;
    char mName[16 + 4 + 1];
    u8 mbUserAllocated;
    u8 mPadding[2];
};

} // namespace lyt
} // namespace nw4r

#endif
