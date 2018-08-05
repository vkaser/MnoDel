//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Mnodel2.h"
#include "MnoDel.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#define TR 180   // время отведенное на решение

TForm2 *Form2;
int T;   //  количество примеров
int Err = 0;  //  количество ошибок
int a1, a2;   //  значение операндов

int rem = TR;  // остаток времени

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
Label3->Caption = IntToStr(TR);
ProgressBar1->Min = 0;
ProgressBar1->Max = TR;
ProgressBar1->Position = TR;
ProgressBar1->Step = 1;
ProgressBar1->Smooth = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
Form2->Release();
Form1->Show();
rem = TR;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Edit1KeyPress(TObject *Sender, char &Key)
{
int rez; //  результат операции
int k = StrToInt(Label1->Caption);  //  первый операнд
int l = StrToInt(Label6->Caption);  //  второй операнд
if ( ((Key >= '0') && (Key <= '9')) )
	return;
if (( Key == VK_BACK))
	return;
if ( Key == VK_RETURN )
	{
	if ( ( Edit1->Text.Length() ) == 0 )
	{
	  Application->MessageBoxA("Введите число", " ", MB_ICONWARNING);
	  return;
	}
		if ( Label5->Caption == "x")
			rez = k * l ;
		else
			rez = k/l;
	   if ( StrToInt(Edit1->Text) == rez)
		  {
			T++;
			Edit1->Clear();
			if (Label5->Caption == "x")
				{
				  a1 = random( StrToInt(Form1->Edit1->Text)  ) + 1;
				  a2 = random( StrToInt(Form1->Edit1->Text) ) + 1;
				}
			else
				{
				  a1 = random( StrToInt(Form1->Edit1->Text) ) + 1 ;
				  a2 = random( StrToInt(Form1->Edit1->Text) ) + 1;
				  a1*=a2;
				  if (a2 == 0)  a2++;
				}
			Label1->Caption = IntToStr(a1);
			Label5->Left = Label1->Left  + Label1->Width + 10;
			Label6->Left = Form2->Label5->Left + Label5->Width + 10;
			Form2->Label6->Caption = IntToStr(a2);
			Form2->Label7->Left = Form2->Label6->Left + Form2->Label6->Width + 10;
			Form2->Label7->Caption = "=";
			Edit1->Width = Label1->Width + Label6->Width;
			Form2->Edit1->Left = Form2->Label7->Left + Form2->Label7->Width + 10;
			Form2->Width = Edit1->Left + Edit1->Width + 30;
		  }
	   else
			{
			  Application->MessageBoxA("Неправильно !", "Ошибка", MB_ICONSTOP);
			  Err++;
			}
	   return;
	}
Key = 0;
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Timer1Timer(TObject *Sender)
{
rem--;
int bal;
ProgressBar1->Position--;
Label3->Caption = IntToStr(rem);
if (rem == 0)
	{
	 if (Label5->Caption == "x")
		bal =  50*T*StrToInt(Form1->Edit1->Text) - 100*Err;
	 else
		bal = 100*T - 100*Err + StrToInt(Form1->Edit1->Text);
	  AnsiString s = "Правильных ответов: " + IntToStr(T) +
	  "\nНеправильных ответов: " + IntToStr(Err) + "\nРезультат:  "
	  + IntToStr(bal) + " очков";
	  Timer1->Enabled = false;
	  Label1->Enabled = false;
	  Label5->Enabled = false;
	  Label6->Enabled = false;
	  Label7->Enabled = false;
	  Edit1->Enabled = false;
	  Application->MessageBoxA(s.c_str(), "Разультат", MB_ICONINFORMATION);
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm2::FormCreate(TObject *Sender)
{
T = 0;
Err = 0;
}
//---------------------------------------------------------------------------

