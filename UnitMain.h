//---------------------------------------------------------------------------

#ifndef UnitMainH
#define UnitMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ActnList.hpp>
#include <Menus.hpp>

#include <ExtCtrls.hpp>


#include "UnitClass.h"
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *N1;
        TMenuItem *N2;
        TMenuItem *N3;
        TActionList *ActionList1;
        TAction *ActionCircle;
        TAction *ActionRect;
        TAction *ActionSquare;
        TMenuItem *Action11;
        TMenuItem *Action21;
        TMenuItem *Action31;
        TAction *ActionExit;
        TAction *ActionChange;
        TAction *ActionMove;
        TAction *ActionRotate;
        TMenuItem *N4;
        TMenuItem *N5;
        TMenuItem *N6;
        TImage *pic;
        TAction *ActionDraw;
        TMenuItem *N7;
        TMenuItem *N8;
        TMenuItem *N9;
        void __fastcall ActionCircleExecute(TObject *Sender);
        void __fastcall ActionRectExecute(TObject *Sender);
        void __fastcall ActionSquareExecute(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ActionExitExecute(TObject *Sender);
        void __fastcall ActionChangeExecute(TObject *Sender);
        void __fastcall ActionMoveExecute(TObject *Sender);
        void __fastcall ActionRotateExecute(TObject *Sender);
        void __fastcall ActionDrawExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormMain(TComponent* Owner);


};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
