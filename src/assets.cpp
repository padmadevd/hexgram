#include "assets.hpp"
#include "raylib/raylib.h"

Texture2D Assets::tileBlankPng{0};

Texture2D Assets::tileNormalPng{0};

Texture2D Assets::tileStartPng{0};

Texture2D Assets::tileEndAllPng{0};
Texture2D Assets::tileEndVioletPng{0};
Texture2D Assets::tileEndBluePng{0};
Texture2D Assets::tileEndGreenPng{0};
Texture2D Assets::tileEndYellowPng{0};
Texture2D Assets::tileEndRedPng{0};

Texture2D Assets::tileAssignAllPng{0};
Texture2D Assets::tileAssignVioletPng{0};
Texture2D Assets::tileAssignBluePng{0};
Texture2D Assets::tileAssignGreenPng{0};
Texture2D Assets::tileAssignYellowPng{0};
Texture2D Assets::tileAssignRedPng{0};

Texture2D Assets::tileIncrementPng{0};
Texture2D Assets::tileDecrementPng{0};

Texture2D Assets::tileLockPng{0};
Texture2D Assets::tileKeyPng{0};

Texture2D Assets::tileSplitVioletllPng{0};
Texture2D Assets::tileSplitVioletlPng{0};
Texture2D Assets::tileSplitVioletrPng{0};
Texture2D Assets::tileSplitVioletrrPng{0};

Texture2D Assets::tileSplitBluellPng{0};
Texture2D Assets::tileSplitBluelPng{0};
Texture2D Assets::tileSplitBluerPng{0};
Texture2D Assets::tileSplitBluerrPng{0};

Texture2D Assets::tileSplitGreenllPng{0};
Texture2D Assets::tileSplitGreenlPng{0};
Texture2D Assets::tileSplitGreenrPng{0};
Texture2D Assets::tileSplitGreenrrPng{0};

Texture2D Assets::tileSplitYellowllPng{0};
Texture2D Assets::tileSplitYellowlPng{0};
Texture2D Assets::tileSplitYellowrPng{0};
Texture2D Assets::tileSplitYellowrrPng{0};

Texture2D Assets::tileSplitRedllPng{0};
Texture2D Assets::tileSplitRedlPng{0};
Texture2D Assets::tileSplitRedrPng{0};
Texture2D Assets::tileSplitRedrrPng{0};

void Assets::Load()
{
    tileBlankPng = LoadTexture("assets/tiles/tile1.png");

    tileNormalPng = LoadTexture("assets/tiles/tile44.png");

    tileStartPng = LoadTexture("assets/tiles/tile11.png");

    tileEndAllPng = LoadTexture("assets/tiles/tile12.png");
    tileEndVioletPng = LoadTexture("assets/tiles/tile17.png");
    tileEndBluePng = LoadTexture("assets/tiles/tile16.png");
    tileEndGreenPng = LoadTexture("assets/tiles/tile15.png");
    tileEndYellowPng = LoadTexture("assets/tiles/tile14.png");
    tileEndRedPng = LoadTexture("assets/tiles/tile13.png");

    tileAssignAllPng = LoadTexture("assets/tiles/tile18.png");
    tileAssignVioletPng = LoadTexture("assets/tiles/tile23.png");
    tileAssignBluePng = LoadTexture("assets/tiles/tile22.png");
    tileAssignGreenPng = LoadTexture("assets/tiles/tile21.png");
    tileAssignYellowPng = LoadTexture("assets/tiles/tile20.png");
    tileAssignRedPng = LoadTexture("assets/tiles/tile19.png");

    tileIncrementPng = LoadTexture("assets/tiles/tile5.png");
    tileDecrementPng = LoadTexture("assets/tiles/tile4.png");

    tileLockPng = LoadTexture("assets/tiles/tile3.png");
    tileKeyPng = LoadTexture("assets/tiles/tile2.png");

    tileSplitVioletllPng = LoadTexture("assets/tiles/tile24.png");
    tileSplitVioletlPng = LoadTexture("assets/tiles/tile33.png");
    tileSplitVioletrPng = LoadTexture("assets/tiles/tile43.png");
    tileSplitVioletrrPng = LoadTexture("assets/tiles/tile34.png");

    tileSplitBluellPng = LoadTexture("assets/tiles/tile25.png");
    tileSplitBluelPng = LoadTexture("assets/tiles/tile32.png");
    tileSplitBluerPng = LoadTexture("assets/tiles/tile42.png");
    tileSplitBluerrPng = LoadTexture("assets/tiles/tile35.png");

    tileSplitGreenllPng = LoadTexture("assets/tiles/tile26.png");
    tileSplitGreenlPng = LoadTexture("assets/tiles/tile31.png");
    tileSplitGreenrPng = LoadTexture("assets/tiles/tile41.png");
    tileSplitGreenrrPng = LoadTexture("assets/tiles/tile36.png");

    tileSplitYellowllPng = LoadTexture("assets/tiles/tile27.png");
    tileSplitYellowlPng = LoadTexture("assets/tiles/tile30.png");
    tileSplitYellowrPng = LoadTexture("assets/tiles/tile40.png");
    tileSplitYellowrrPng = LoadTexture("assets/tiles/tile37.png");

    tileSplitRedllPng = LoadTexture("assets/tiles/tile28.png");
    tileSplitRedlPng = LoadTexture("assets/tiles/tile29.png");
    tileSplitRedrPng = LoadTexture("assets/tiles/tile39.png");
    tileSplitRedrrPng = LoadTexture("assets/tiles/tile38.png");
}