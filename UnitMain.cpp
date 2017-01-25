//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitMain.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"


TFormMain *FormMain;

shape* my=NULL;

//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TFormMain::ActionCircleExecute(TObject *Sender)
{
  if (my) delete (my);
  my=new circle();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::ActionRectExecute(TObject *Sender)
{
  if (my) delete (my);
  my=new rect();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::ActionSquareExecute(TObject *Sender)
{
  if (my) delete (my);
  my=new square();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::FormClose(TObject *Sender, TCloseAction &Action)
{
  if (my) delete (my);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::ActionExitExecute(TObject *Sender)
{
  Close();        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::ActionChangeExecute(TObject *Sender)
{
   if (!my)
   {
      ShowMessage("Фигура не выбрана");
   }
   else
   {
        my->change(pic);
   };
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::ActionMoveExecute(TObject *Sender)
{
   if (!my)
   {
      ShowMessage("Фигура не выбрана");
   }
   else
   {
        my->move(pic);
   };
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::ActionRotateExecute(TObject *Sender)
{
      if (!my)
   {
      ShowMessage("Фигура не выбрана");
   }
   else
   {
        my->rotation(pic);
   };
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::ActionDrawExecute(TObject *Sender)
{
       if (!my)
   {
      ShowMessage("Фигура не выбрана");
   }
   else
   {
        my->draw(pic);
   };
}
//---------------------------------------------------------------------------
