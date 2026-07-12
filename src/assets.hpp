#ifndef ASSETS_HPP
#define ASSETS_HPP

#include <raylib/raylib.h>

struct Assets
{
    static Texture2D tileBlankPng;

    static Texture2D tileNormalPng;

    static Texture2D tileStartPng;

    static Texture2D tileEndAllPng;
    static Texture2D tileEndVioletPng;
    static Texture2D tileEndBluePng;
    static Texture2D tileEndGreenPng;
    static Texture2D tileEndYellowPng;
    static Texture2D tileEndRedPng;

    static Texture2D tileAssignAllPng;
    static Texture2D tileAssignVioletPng;
    static Texture2D tileAssignBluePng;
    static Texture2D tileAssignGreenPng;
    static Texture2D tileAssignYellowPng;
    static Texture2D tileAssignRedPng;

    static Texture2D tileIncrementPng;
    static Texture2D tileDecrementPng;

    static Texture2D tileLockPng;
    static Texture2D tileKeyPng;

    static Texture2D tileSplitVioletllPng;
    static Texture2D tileSplitVioletlPng;
    static Texture2D tileSplitVioletrPng;
    static Texture2D tileSplitVioletrrPng;

    static Texture2D tileSplitBluellPng;
    static Texture2D tileSplitBluelPng;
    static Texture2D tileSplitBluerPng;
    static Texture2D tileSplitBluerrPng;

    static Texture2D tileSplitGreenllPng;
    static Texture2D tileSplitGreenlPng;
    static Texture2D tileSplitGreenrPng;
    static Texture2D tileSplitGreenrrPng;

    static Texture2D tileSplitYellowllPng;
    static Texture2D tileSplitYellowlPng;
    static Texture2D tileSplitYellowrPng;
    static Texture2D tileSplitYellowrrPng;

    static Texture2D tileSplitRedllPng;
    static Texture2D tileSplitRedlPng;
    static Texture2D tileSplitRedrPng;
    static Texture2D tileSplitRedrrPng;

    static void Load();
};

#endif