//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdHTTP.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <Mask.hpp>
#include <IdAntiFreeze.hpp>
#include <IdAntiFreezeBase.hpp>
#include <IdIntercept.hpp>
#include <IdSSLIntercept.hpp>
#include <IdSSLOpenSSL.hpp>
#include <IdFTP.hpp>
#include <IdIPWatch.hpp>
// #include "c:\tproctimer\TProcTimer.h"
//---------------------------------------------------------------------------
class TF1 : public TForm
{
__published:	// IDE-managed Components
        TStatusBar *SB;
        TLabel *Label_Data;
        TLabel *Label_Set;
        TStringGrid *SG_Data;
        TStringGrid *SG_Instruction;
        TMemo *M1;
        TBitBtn *BitBtn_Run;
        TBitBtn *BitBtn_Stop;
        TMainMenu *Main_Menu;
        TOpenDialog *OD_1;
        TMenuItem *Files;
        TMenuItem *N1;
        TMenuItem *N2;
        TMenuItem *Work;
        TMenuItem *N3;
        TMenuItem *N4;
        TMenuItem *N7;
        TMenuItem *N8;
        TMenuItem *Info;
        TMenuItem *N46;
        TMenuItem *N15;
        TMenuItem *N16;
        TMenuItem *N17;
        TMenuItem *N18;
        TMenuItem *N12;
        TMenuItem *N19;
        TMenuItem *N20;
        TMenuItem *Edit;
        TMenuItem *N22;
        TMenuItem *N24;
        TMenuItem *N25;
        TMenuItem *N23;
        TLabel *Label_Buffer;
        TStringGrid *SG_Buffer;
        TMenuItem *N26;
        TProgressBar *PB_1;
        TMenuItem *N27;
        TMenuItem *Wonderful;
        TLabel *Label1;
        TPopupMenu *SG_PopUpMenu;
        TMenuItem *RO_1;
        TMenuItem *OR_1;
        TMenuItem *N29;
        TTimer *Master_Timer;
        TMenuItem *Analize;
        TMenuItem *N31;
        TMenuItem *N32;
        TMenuItem *N33;
        TMenuItem *N34;
        TMenuItem *N35;
        TMenuItem *SaveIGA;
        TMenuItem *N44;
        TMenuItem *N11;
        TMenuItem *N45;
        TMenuItem *N21;
        TMenuItem *N28;
        TMenuItem *N30;
        TLabel *Label_AIU;
        TEdit *E_AIU;
        TMenuItem *N37;
        TMenuItem *SelectColors_Test;
        TMenuItem *N39;
        TMenuItem *SelecColors_Execute;
        TMenuItem *clOperandOperation;
        TMenuItem *clNonExecuted;
        TMenuItem *clNonUsedResult;
        TMenuItem *clNonDefOperands;
        TMenuItem *clReadyOperand;
        TMenuItem *clTruePredictor;
        TMenuItem *clExecInstruction;
        TColorDialog *CD_1;
        TMenuItem *N5;
        TMenuItem *N36;
        TMenuItem *N38;
        TMenuItem *SelectColor_Graph;
        TMenuItem *N40;
        TMenuItem *N41;
        TPopupMenu *M1_PopUpMenu;
        TMenuItem *N42;
        TMenuItem *N43;
        TMenuItem *ClipBoard1;
        TMenuItem *NotePad1;
        TMenuItem *ExtendedSave_IGA;
        TMenuItem *N10;
        TMenuItem *N13;
        TIdFTP *FTP_Post;
        TIdFTP *FTP_Get;
        TIdAntiFreeze *IdAntiFreeze1;
        TIdIPWatch *IPWatch;
        TMenuItem *N6;
        TMenuItem *N47;
        TMenuItem *N9;
        TMenuItem *N48;
        
        void __fastcall Main_Form_OnCreate(TObject *Sender);
        void __fastcall OnClose_F1(TObject *Sender, TCloseAction &Action);
        void __fastcall Stop_Calculations(TObject *Sender);
        void __fastcall Run_Calculations(TObject *Sender);
        void __fastcall SG_Instruction_DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect, TGridDrawState State);
        void __fastcall Save_All_Protocols(TObject *Sender);
        void __fastcall Load_Sets(TObject *Sender);
        void __fastcall On_Close_Main_Form(TObject *Sender);
         void __fastcall SG_Data_TopLeftChanged(TObject *Sender);
         void __fastcall SG_Buffer_TopLeftChanged(TObject *Sender);
        void __fastcall Rewrite_Files(TObject *Sender);
        void __fastcall Show_Chema(TObject *Sender);
        void __fastcall N12Click(TObject *Sender);
        void __fastcall SG_Instruction_Edit(TObject *Sender);
        void __fastcall INI_Edit(TObject *Sender);
        void __fastcall Most_Wonderful(TObject *Sender);
//
        void __fastcall On_Master_Timer(TObject *Sender);
        void __fastcall SG_SetSelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
        void __fastcall Result_toOperands(TObject *Sender);
        void __fastcall Operand_toResult(TObject *Sender);
        void __fastcall OnPopup_Determine_Links(TObject *Sender);
        void __fastcall DrawNotExecuteSets(TObject *Sender);
        void __fastcall DrawNotUsedResults(TObject *Sender);
        void __fastcall DrawNotDetermineOperands(TObject *Sender);
        void __fastcall OnShow_F1(TObject *Sender);
        void __fastcall Save_IGA_Click(TObject *Sender);
        void __fastcall OnResize_F1(TObject *Sender);
        void __fastcall FTP_Get_Connected(TObject *Sender);
        void __fastcall FTP_Get_Disconnected(TObject *Sender);
        void __fastcall FTP_Get_OnStatus(TObject *axSender,
                        const TIdStatus axStatus, const AnsiString asStatusText);
        void __fastcall FTP_Get_OnWork(TObject *Sender, TWorkMode AWorkMode,
                        const int AWorkCount);
        void __fastcall FTP_Get_OnWorkBegin(TObject *Sender, TWorkMode AWorkMode,
                        const int AWorkCountMax);
        void __fastcall FTP_Get_OnWorkEnd(TObject *Sender,
                        TWorkMode AWorkMode);
        void __fastcall GetInstall(TObject *Sender);
        void __fastcall EndedUploadFile(TObject *Sender);
        void __fastcall Show_Graph(TObject *Sender);
        void __fastcall OnKeyPress_F1(TObject *Sender, char &Key);
        void __fastcall SelectColors(TObject *Sender);
        void __fastcall CD_1_Show(TObject *Sender);
        void __fastcall OnKeyUp_F1(TObject *Sender, WORD &Key, TShiftState Shift);
        void __fastcall Save_Data(TObject *Sender);
        void __fastcall M1_ClearAll(TObject *Sender);
        void __fastcall M1_CopyAll(TObject *Sender);
        void __fastcall M1_CopyToNotepad(TObject *Sender);
        void __fastcall ExtendedSave_IGA_Click(TObject *Sender);
        void __fastcall Show_AIU(TObject *Sender);
        void __fastcall SG_MouseUp(TObject *Sender, TMouseButton Button,
                        TShiftState Shift, int X, int Y);
        void __fastcall SG_Data_Info(TObject *Sender);
        void __fastcall About_Common(TObject *Sender);
//
private:	// User declarations
public:		// User declarations
        __fastcall TF1(TComponent* Owner);
//
TStringList *Tpr, // ����� ����� ��� ������� ������������� ���
            *PM;  // ����� ����� ��� ������� �������� (�������� ������)
};
//---------------------------------------------------------------------------
extern PACKAGE TF1 *F1;
//---------------------------------------------------------------------------
#endif
