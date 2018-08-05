//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MnoDel.h"
#include "Mnodel2.h"
#include <stdlib.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int a1, a2;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
if ( ( Edit1->Text.Length() ) == 0 )
	{
	  Application->MessageBoxA("¬ведите максимальное число", " ", MB_ICONWARNING);
	  Edit1->SetFocus();
	  return;
	}
Application->CreateForm(__classid(TForm2), &Form2);
Form1->Hide();
Form2->Show();
randomize();
a1 = random( StrToInt(Edit1->Text) ) + 1 ;
a2 = random( StrToInt(Edit1->Text) ) + 1 ;
Form2->Label1->Caption = IntToStr(a1);
Form2->Label5->Left = Form2->Label1->Left  + Form2->Label1->Width + 10;
Form2->Label5->Caption = "x";
Form2->Label6->Left = Form2->Label5->Left + Form2->Label5->Width + 10;
Form2->Label6->Caption = IntToStr(a2);
Form2->Label7->Left = Form2->Label6->Left + Form2->Label6->Width + 10;
Form2->Label7->Caption = "=";
Form2->Edit1->Width = Form2->Label1->Width + Form2->Label6->Width;
Form2->Edit1->Left = Form2->Label7->Left + Form2->Label7->Width + 10;
Form2->Width = Form2->Edit1->Left + Form2->Edit1->Width + 30;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
if ( ( Edit1->Text.Length() ) == 0 )
	{
	  Application->MessageBoxA("¬ведите максимальное число", " ", MB_ICONWARNING);
	  Edit1->SetFocus();
	  return;
	}
Application->CreateForm(__classid(TForm2), &Form2);
Form1->Hide();
Form2->Show();
Form2->Caption = "ƒеление";
randomize();
a1 = random( StrToInt(Edit1->Text) ) + 1 ;
a2 = random( StrToInt(Edit1->Text) ) + 1;
a1*=a2;
if (a2 == 0) a2++;
Form2->Label1->Caption = IntToStr(a1);
Form2->Label5->Left = Form2->Label1->Left  + Form2->Label1->Width + 10;
Form2->Label5->Caption = "/";
Form2->Label6->Left = Form2->Label5->Left + Form2->Label5->Width + 10;
Form2->Label6->Caption = IntToStr(a2);
Form2->Label7->Left = Form2->Label6->Left + Form2->Label6->Width + 10;
Form2->Label7->Caption = "=";
Form2->Edit1->Width = Form2->Label1->Width + Form2->Label6->Width;
Form2->Edit1->Left = Form2->Label7->Left + Form2->Label7->Width + 10;
Form2->Width = Form2->Edit1->Left + Form2->Edit1->Width + 30;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{
if ( (Key >= '0') && (Key <= '9' ) )
	return;
if ( Key == VK_BACK)
	return;
if ( Key == VK_RETURN )
	{
	  Button1->SetFocus();
	  return;
	}
Key = 0;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormActivate(TObject *Sender)
{
Edit1->SetFocus();
}
//---------------------------------------------------------------------------

