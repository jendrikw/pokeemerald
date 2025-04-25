#include "main.h"
#include "title_screen.h"
#include "malloc.h"
#include "load_save.h"
#include "save.h"
#include "new_game.h"
#include "m4a.h"

void CB2_InitCopyrightScreenAfterBootup(void)
{
    if (gMain.state == 0)
    {
        SetSaveBlocksPointers(GetSaveBlocksPointersBaseOffset());
        ResetMenuAndMonGlobals();
        Save_ResetSaveCounters();
        LoadGameSave(SAVE_NORMAL);
        if (gSaveFileStatus == SAVE_STATUS_EMPTY || gSaveFileStatus == SAVE_STATUS_CORRUPT)
            Sav2_ClearSetDefault();
        SetPokemonCryStereo(gSaveBlock2Ptr->optionsSound);
        InitHeap(gHeap, HEAP_SIZE);
    }
    CB2_InitTitleScreen();
}
